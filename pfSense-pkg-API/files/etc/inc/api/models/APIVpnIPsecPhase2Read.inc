<?php
require_once("api/framework/APIModel.inc");
require_once("api/framework/APIResponse.inc");

class APIVpnIPsecPhase2Read extends APIModel {

    public function __construct() {
        parent::__construct();

        $this->privileges = ["page-all"];
    }

    public function validate_payload() {

    }

    public function action() {
        // Check that we have a configuration
        if (!empty($this->config["ipsec"]["phase2"])) {
            $phase2_array = $this->config["ipsec"]["phase2"];
        } else {
            $phase2_array = [];
        }
        return APIResponse\get(0, $phase2_array);
    }
    
}