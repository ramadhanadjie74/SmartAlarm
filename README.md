PROJEK SMART ALARM.
SmartAlarm ini terintegrasi dengan AI yang berfungsi sebagai indikator pemakaian APD para petugas sebelum memasuki area Kilang RU VI Balongan.
Perangkat ini akan segera aktif (output : suara dan indikator cahaya/Sirene) saat petugas tidak menggunakan APD sesuai dengan ketentuan keselamatan.
Projek dibagi menjadi 2 team. TEAM AI, DAN TEAM IOT
Saya bekerja dan mencalonkan diri sebagai penanggung jawab team IOT, yang terdiri 3 orang (temasuk saya).
Saya mengambil tugas programming, mulai dari middle-ware sampai hardware (ARDUINO).
.
Cara kerja perangkat:
1. AI akan mendeteksi (dengan kamera) adanya pelanggaran penggunaan APD/tidak, output berupa data text "violtion" / "ok" 
2. Data disimpan dalam database pemantauan.
4. Middleware akan membaca data "violation" yang terdapat dalam database, lalu menampilkan output text/echo : "#^1" atau "#^0" (1 : violation || 0 : OK/Alarm_Stop).
   Jika data violation/"#^1" terbaca, middleware akan segera mengupdate database dengan informasi "Alarm_Stop" untuk mereset hasil output menjadi "#^0"
6. Hasil keluaran middleware ini yang nantinya dibaca oleh Arduino, berupa 1 / 0 dengan startkey "#^". 1 = Aktifkan Buzzer dan Sirene selama 3 detik, 0 = Nonaktifkan Buzzer dan Sirene.
7. Program akan terus looping selama perangkat terkoneksi dengan Server.
.
BLOCK DIAGRAM :
[AKTIFKAN PERANGKAT (ARDUINO)] -> [KONEKSIKAN ARDUINO KE SERVER MENGGUNAKAN LAN] -> [MIDDLEWARE MEMBACA DATA "VIOLATION/OK/ALARM_STOP" PADA DATABASE] -> 
[ARDUINO MEMBACA OUTPUT 'ECHO:"#^1"/"#^0"' DARI MIDDLEWARE(PHP)] -> [AKTIF/NONAKTIFKAN BUZZER/ALARM].
.
