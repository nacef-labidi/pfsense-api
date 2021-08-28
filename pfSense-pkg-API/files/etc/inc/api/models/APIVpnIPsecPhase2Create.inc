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
        return APIResponse\get(0, $this->validated_data);
    }
    
}