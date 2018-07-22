<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/
$ip = '192.168.43.230';
$port = ':8000/?id=';
Route::get('/', function () {
    return view('welcome');
});

Route::get('/home','HomeController@home');
Route::get('/control','ControlController@control');
