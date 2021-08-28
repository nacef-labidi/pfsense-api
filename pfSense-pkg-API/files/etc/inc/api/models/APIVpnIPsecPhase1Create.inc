<?php
require_once("api/framework/APIModel.inc");
require_once("api/framework/APIResponse.inc");

class APIVpnIPsecPhase1Create extends APIModel {

    public function __construct() {
        parent::__construct();

        $this->privileges = ["page-all"];
    }

    public function validate_payload() {

    }

    public function action() {
        return APIResponse\get(0, ipsec_enabled());
    }
    
}