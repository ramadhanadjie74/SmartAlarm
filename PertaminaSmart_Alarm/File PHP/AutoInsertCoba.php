<?php

echo "#";
date_default_timezone_set('Asia/Jakarta');
$con = mysqli_connect("localhost","root","","safety");
$date = date('Y-m-d H:i:s');
if(!$con){
 die("Koneksi error harap cek server dan passwordnya");
}
	$qry = mysqli_query($con, "INSERT INTO apd_new VALUES('test','VIOLATION','VIOLATION','$date','Pintu masuk Brasley1')");
