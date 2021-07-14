<?php

echo "#";
date_default_timezone_set('Asia/Jakarta');
$con = mysqli_connect("localhost","root","","safety");
$date = date('Y-m-d H:i:s');
if(!$con){
 die("Koneksi error harap cek server dan passwordnya");
}
$query = mysqli_query($con,"select * from apd_new order by time desc limit 1");
if(mysqli_num_rows($query) > 0){
  while($data = mysqli_fetch_array($query)){
  if($data["jacket_violation"] == "VIOLATION" && $data["helm_violation"] == "VIOLATION")
{     
	echo "1";
	$qry = mysqli_query($con, "INSERT INTO apd_new VALUES('reset_alarm','alarm_stop','alarm_stop','$date','Pintu masuk Brasley1')");
}
else if($data["jacket_violation"] == "OK" && $data["helm_violation"] == "VIOLATION")
{     
	echo "1";
	$qry = mysqli_query($con, "INSERT INTO apd_new VALUES('reset_alarm','alarm_stop','alarm_stop','$date','Pintu masuk Brasley1')");
}
else if($data["jacket_violation"] == "VIOLATION" && $data["helm_violation"] == "OK")
{     
	echo "1";
	$qry = mysqli_query($con, "INSERT INTO apd_new VALUES('reset_alarm','alarm_stop','alarm_stop','$date','Pintu masuk Brasley1')");
}
else if($data["jacket_violation"] == "OK" && $data["helm_violation"] == "OK")
{     
	echo "1";
	$qry = mysqli_query($con, "INSERT INTO apd_new VALUES('reset_alarm','alarm_stop','alarm_stop','$date','Pintu masuk Brasley1')");
}

else if($data["jacket_violation"] == "alarm_stop" && $data["helm_violation"] == "alarm_stop")
{     
	echo "0";
}
else
{
     	echo "0";
}

}
}
echo "^";