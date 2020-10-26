#include <ArduinoJson.h>
#include <AWS_IOT.h>
#include<WiFi.h>

#define WIFI_SSID "hbbgarden" // SSID WiFi
#define WIFI_PASSWD "prodigy123" // Password WiFi

#define CLIENT_ID "hello"// thing ID, harus unik/berbeda dari setiap thing yang terkoneksi ke AWS account
#define MQTT_TOPIC "$aws/things/hello/string" // topik untuk MQTT data
#define AWS_HOST "a1fif474smypl7-ats.iot.us-west-2.amazonaws.com"
AWS_IOT aws;
#define ECPin 35  
int val; 
#define interval 1000
unsigned long current_millis = 0;
unsigned long previous_millis = 0;
unsigned long detik;
unsigned long baca;
unsigned long publish;
int ecVol;
int ec;

int adcEC=0; 

void connectToWiFi()
{
  //WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWD);

  // Only try 15 times to connect to the WiFi
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 15){
    delay(500);
    Serial.print(".");
    retries++;
  }

  // If we still couldn't connect to the WiFi, go to deep sleep for a minute and try again.
  if(WiFi.status() != WL_CONNECTED){
    esp_sleep_enable_timer_wakeup(1 * 60L * 1000000L);
    esp_deep_sleep_start();
  }
}
void connectToAWS()
{
  Serial.println("\n  INISIALISASI KONEKSI KE AWS....");
  if (aws.connect(AWS_HOST, CLIENT_ID) == 0) { // MENGKONEKSIKAN KE HOST & returns 0 JIKA SUKSES TERKONEKSI
    Serial.println("  SUDAH TERKONEKSI KE AWS\n");
  }
  else {
    Serial.println("  GAGAL TERKONEKSI!\n PASTIKAN LAGI SUBSCRIPTION KE MQTT DI HALAMAN TEST (TEST PAGE)");
  }
  Serial.println("  READY");
}

void sendJsonToAWS()
{
  StaticJsonDocument<512> jsonDoc;
  JsonObject reportedObj = jsonDoc.createNestedObject("reported");
  
  // Write the temperature & humidity. Here you can use any C++ type (and you can refer to variables)
  reportedObj["WIFI"] = WIFI_SSID;
  reportedObj["EC"] = ec ;
  
  // Publish the message to AWS
  char jsonBuffer[512];
  serializeJson(jsonDoc, jsonBuffer);
  aws.publish(MQTT_TOPIC, jsonBuffer);
  serializeJson(jsonDoc, Serial);
}

void setup() {
  Serial.begin(115200);
  connectToWiFi();
  connectToAWS();
}

void loop() {
  current_millis = millis();
  if (current_millis - previous_millis > interval) {
    previous_millis = current_millis;
    detik++;
  }

  if (baca+1 == detik) {
    baca = detik; 
    adcEC = analogRead(ECPin);
    ecVol= adcEC *(3.3 / 4095.0);
    ec = (609.0 * ecVol) - 31.68;
   // Serial.println(ec);
  }
  if (publish+300 == detik) {
    detik = 0;
    baca = detik;
    publish = detik;
    Serial.println("Publishing:- ");
    sendJsonToAWS();
  }
//  client.loop();
//  String ec_ = "EC: ";
// 
//  
//  ec_ += String(ec);
//  ec_ += "ppm ";
//  
//  char payload[40];
//  ec_.toCharArray(payload, 40);
//
//  if (publish+300 == detik) {
//    detik = 0;
//    baca = detik;
//    publish = detik;
//    Serial.println("Publishing:- ");
//    Serial.println(payload);
//    if (aws.publish(MQTT_TOPIC, payload) == 0) { // MEM-PUBLISH payload DAN returns 0 JIKA SUKSES
//      Serial.println("SUKSES\n");
//    }
//    else {
//      Serial.println("GAGAL!\n");
//    }
  }
//}
