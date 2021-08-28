<?php
require_once("api/framework/APIEndpoint.inc");

class APIVpnIPsecPhase2 extends APIEndpoint {

    public function __construct() {
        parent::__construct();

        $this->url = "/api/v1/vpn/ipsec/phase2";
    }

    protected function get() {
        return (new APIVpnIPsecPhase2Read())->call();
    }

    protected function post() {
        return (new APIVpnIPsecPhase2Create())->call();
    }
    
}