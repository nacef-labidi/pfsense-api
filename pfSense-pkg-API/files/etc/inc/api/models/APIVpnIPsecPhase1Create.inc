<?php
require_once("api/framework/APIModel.inc");
require_once("api/framework/APIResponse.inc");

class APIVpnIPsecPhase1Create extends APIModel {

    public function __construct() {
        parent::__construct();

        $this->privileges = ["page-all"];
    }

    public function validate_payload() {
        $this->validated_data = $this->initial_data;
        $this->validated_data["ikeid"] = ipsec_ikeid_next();
    }

    public function action() {
        $this->config["ipsec"]["phase1"][] = $this->validated_data;
        $this->write_config();
        return APIResponse\get(0, $this->validated_data);
    }
    
}