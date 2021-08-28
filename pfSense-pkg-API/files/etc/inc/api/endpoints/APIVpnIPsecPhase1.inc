<?php
require_once("api/framework/APIEndpoint.inc");

class APIVpnIPsecPhase1 extends APIEndpoint {

    public function __construct() {
        parent::__construct();

        $this->url = "/api/v1/vpn/ipsec/phase1";
    }

    protected function get() {
        return (new APIVpnIPsecPhase1Create())->call();
    }
    
}