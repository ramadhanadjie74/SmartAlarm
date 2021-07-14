<?php header("refresh: 3"); ?>
<!DOCTYPE html>
<head>
<title>Menampilkan data dari database</title>
   <?php include('desain.php'); ?>

</head>
<body>
<div align="center">
<table border="1" cellpadding="0" cellspacing="0">
<h1> Keamanan Pintu Masuk 1 </h1>
<tr>
<th>ID</th>
<th>HELM</th>
<th>JACKET</th>
<th>TIME</th>
<th>Lokasi Pelanggaran</th>
</tr>
<?php
include 'koneksi.php';
$query_mysql = mysqli_query($koneksi, "SELECT * FROM apd_new ORDER BY time desc")or die(mysql_error());
$no = 1;
while($data = mysqli_fetch_array($query_mysql))
{	?>
<tr>
<td><?php echo $data['id'];?></td>
<td><?php echo $data['helm_violation'];?></td>
<td><?php echo $data['jacket_violation'];?></td>
<td><?php echo $data['time'];?></td>
<td><?php echo $data['tempat'];?></td>
<td>
</td>
</tr>
<?php }?>
</table>
</br>
</body>
</html>