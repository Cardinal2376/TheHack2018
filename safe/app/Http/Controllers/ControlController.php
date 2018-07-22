<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class ControlController extends Controller
{
    //
    public function control()
    {
        $ip = 'http://192.168.43.230';
        $port = ':8000/?id=';
        return view('control', ['one'=> $ip.$port.'1', 'two'=>$ip.$port.'2', 'three'=>$ip.$port.'3']);
    }
}
