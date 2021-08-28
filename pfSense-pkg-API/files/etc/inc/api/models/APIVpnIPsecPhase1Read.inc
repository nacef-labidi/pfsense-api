<?php
require_once("api/framework/APIModel.inc");
require_once("api/framework/APIResponse.inc");

class APIVpnIPsecPhase1Read extends APIModel {

    public function __construct() {
        parent::__construct();

        $this->privileges = ["page-all"];
    }

    public function validate_payload() {

    }

    public function action() {
        // Check that we have a configuration
        if (!empty($this->config["ipsec"]["phase1"])) {
            $phase1_array = $this->config["ipsec"]["phase1"];
        } else {
            $phase1_array = [];
        }
        return APIResponse\get(0, $phase1_array);
    }
    
}