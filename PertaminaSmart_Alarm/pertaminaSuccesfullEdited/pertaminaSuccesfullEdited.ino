#include <Ethernet.h>
#include <SPI.h>
#define STATUS_CONNECTED 1
#define STATUS_DISCONNECTED 0
#define LEDPIN 2
#define BUZZPIN 3
char namaServer[] = "172.20.26.8";
byte IP_eth[] = {172,20,26,9};
byte MAC_eth[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress dnsIp(10,1,32,10);
IPAddress getaway(172,20,26,1);
IPAddress subnet(255,255,255,128);
int counter = 0;
boolean startRead = false;
char inString[32];
char charFromWeb[9];
EthernetClient myEthernet;
int iterasi = 0;

void setup(){
  pinMode(LEDPIN,OUTPUT);
  pinMode(BUZZPIN,OUTPUT);
  Serial.begin(9600);
  Serial.println("--------------------------------------------------");
  Serial.println("Setting Perangkat");
  Serial.println("Mohon menunggu . . . ");
  Serial.println("Setting Ethernet MAC Address dan IP Address");
  Serial.println("Mohon menunggu . . . ");
  if (Ethernet.begin(MAC_eth) == 0) {
  Serial.println("Failed to configure Ethernet using DHCP");
  Ethernet.begin(MAC_eth,IP_eth,subnet,getaway,dnsIp);
  }
  // Ethernet.begin(MAC_eth,IP_eth);
  Serial.println("Setting Perangkat selesai!");
  Serial.println("--------------------------------------------------");
}
void loop() {
  iterasi++;
  Serial.print("Iterasi ke : ");
  Serial.println(iterasi);
  int resultBukaKoneksi = bukaKoneksi();
  if(resultBukaKoneksi==1){
    kirimData("?request=arduino");
    Serial.println();

  }
  delay(500);
  Serial.println("--------------------------------------------------");

}

int bukaKoneksi(){
  Serial.print("Mencoba sambungan ke server http://");
  Serial.println(namaServer);
  Serial.println("Mohon menunggu . . . ");
  if(myEthernet.connect(namaServer,80)){
    Serial.println("Sambungan ke server berhasil!");
    return STATUS_CONNECTED;
  }else{
    Serial.print("Sambungan ke server gagal!");
    Serial.println();
    return STATUS_DISCONNECTED;
  }
}

void kirimData(String a){
  Serial.println("Menjalankan perintah kirim data");
  String data = " Arduino";
  int ln = data.length();
  String uri_segment;
  uri_segment = "/apd/apdNov26.php" + a;
  // uri_segment = "/iot_server/index.php/device/post_data/" + a;
  myEthernet.print("GET ");
  myEthernet.print(uri_segment);
  Serial.print("Data yang dikirim di ke server : ");
  Serial.println(a);
  myEthernet.println(" HTTP/1.0");
  myEthernet.print( "Host: " );
  myEthernet.println("  172.20.26.8 \r\n");
  // myEthernet.println(" 192.168.0.102 \r\n");
  Serial.println("Host OK");
  myEthernet.println( "Content-Type: application/x-www-form-urlencoded \r\n" );
  Serial.println("Content type OK");
  myEthernet.print( "Content-Length: " );
  myEthernet.print(ln);
  myEthernet.print(" \r\n");
  myEthernet.println( "Connection: close" );
  myEthernet.println();
  String res;
  delay(5000);
  res = bacaWebText();
  Serial.println(res);
  if(res=="1" || res.equals("1")){
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(BUZZPIN, HIGH);
    delay(500);
    digitalWrite(BUZZPIN, LOW);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500);
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(BUZZPIN, HIGH);
    delay(500);
    digitalWrite(BUZZPIN, LOW);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500);
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(BUZZPIN, HIGH);
    delay(500);
    digitalWrite(BUZZPIN, LOW);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500);
  }else{
    digitalWrite(LEDPIN,LOW);
    digitalWrite(BUZZPIN, LOW);
  }
}

String bacaWebText(){
  unsigned int time;
  Serial.println("Baca respon dari server . . . ");
  Serial.println("Mohon menunggu . . . ");
  time = millis();
  Serial.print("Timer Millis () : ");
  Serial.println(time);
  int stringPos = 0;
  memset( &inString, 0, 32 );
  int unvailable_ctr = 0;
  while(true){
    if (myEthernet.available()) {
      char c = myEthernet.read();
      Serial.print(c);
      if (c == '#' ) {
        Serial.print("Menemukan start key # dengan isi : ");
        startRead = true;
      }else if(startRead){
        if(c != '^'){
          inString[stringPos] = c;
          stringPos ++;
        }else{
          startRead = false;
          Serial.println();
          Serial.println("Baca respon dari server selesai!");
          myEthernet.stop();
          myEthernet.flush();
          Serial.println("Sambungan diputuskan . . . ");
          return inString;
        }
      }
    }else{
      //Serial.println("ethernet unavailable");
      delay(50);
      unvailable_ctr++;
      if(unvailable_ctr == 25){
        myEthernet.stop();
        myEthernet.flush();
        Serial.println("Koneksi mengalami time out");
        Serial.println("Sambungan diputuskan . . . ");
        Serial.println("Reset...");
        return inString;
     }
    }
  }
}
