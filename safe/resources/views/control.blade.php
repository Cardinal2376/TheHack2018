@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="panel panel-default">
                <div class="panel-heading">Control Center</div>
                <div class="panel-body">
                    <center>
                    <div id="container">
                    <center>
                        <button type="button" onclick="location.href='{{$one}}'" id="btn" type="submit" class="btn btn-danger" style="margin-top:140px">分散人群</button>
                    </center>
                    
                    <p></p> 
                    <p></p>
                    <center style="margin-top:40px">
                        <button type="success"  onclick="location.href='{{$two}}'"  type="submit" class="btn btn-success">向左移动</button>
                        &nbsp&nbsp&nbsp&nbsp
                        <button type="success"  onclick="location.href='{{$three}}'"  type="submit" class="btn btn-success">向右移动</button>
                    </center>
                    </div>
                    </center>
                    <center>
                    <button onclick="location.href='{{ url('/home') }}'" type="submit" class="btn btn-large btn-primary">
                         &nbsp&nbsp&nbsp监控&nbsp&nbsp&nbsp
                    </button>
                        &nbsp&nbsp&nbsp&nbsp
                        <button onclick="location.href='{{ url('/control') }}'" type="submit" class="btn btn-large btn-primary">
                         &nbsp&nbsp&nbsp控制&nbsp&nbsp&nbsp
                    </button>
                    </center>
                </div>
            </div>
        </div>
    </div>
</div>
@endsection