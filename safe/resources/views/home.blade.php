@extends('layouts.app')

@section('content')
<div class="container">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="panel panel-default">
                <div class="panel-heading">Control Center</div>
                <div class="panel-body">
                    <center>
                  <div id="container"></div> 
                    </center>
                    <p></p> 
                    <p></p> 
                    <script type="text/javascript"> 
                        var map = new BMap.Map("container");
                        var point = new BMap.Point(121.5967321, 31.1783579);
                        map.centerAndZoom(point, 15);
                        var myGeo = new BMap.Geocoder();
                        myGeo.getPoint("华夏中路393号", function(point){
                        if (point) {
                            map.centerAndZoom(point, 16);
                            map.addOverlay(new BMap.Marker(point));
                        }else{
                            alert("您选择地址没有解析到结果!");
                        }
                        }, "上海市");
                    </script> 
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