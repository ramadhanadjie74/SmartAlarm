<?php
    $server = "localhost";
    $username = "root";
    $password = "";
    $database = "safety";

    $koneksi = mysqli_connect($server, $username, $password, $database);
    if($koneksi == TRUE){
        // echo "Terhubung";
    }else{
        echo "Tidak Terhubung";
    }
?>