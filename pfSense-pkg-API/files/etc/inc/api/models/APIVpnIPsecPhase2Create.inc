<?php
require_once("api/framework/APIModel.inc");
require_once("api/framework/APIResponse.inc");

class APIVpnIPsecPhase2Create extends APIModel {

    public function __construct() {
        parent::__construct();

        $this->privileges = ["page-all"];
    }

    public function validate_payload() {
        $this->validated_data = $this->initial_data;
        $this->validated_data["uniqid"] = uniqid();
        $this->validated_data["reqid"] = ipsec_new_reqid();
    }

    public function action() {
        $this->config["ipsec"]["phase2"][] = $this->validated_data;
        $this->write_config();
        $this->apply();
        return APIResponse\get(0, $this->validated_data);
    }

    public function apply() {
        # Mark the firewall subsystem as changed, this will be cleared if applied
        mark_subsystem_dirty('ipsec');
        ipsec_configure();
        clear_subsystem_dirty('ipsec');
    }

    
}