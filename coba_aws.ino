#include <ArduinoJson.h>
#include <AWS_IOT.h>
#include<WiFi.h>

#define WIFI_SSID "hbbgarden" // SSID WiFi
#define WIFI_PASSWD "prodigy123" // Password WiFi

#define CLIENT_ID "hello"// thing ID, harus unik/berbeda dari setiap thing yang terkoneksi ke AWS account
#define MQTT_TOPIC "$aws/things/hello/shadow/update" // topik untuk MQTT data
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
float ecVol;
float ec;
float adcEC;

int status = WL_IDLE_STATUS;
int tick=0,msgCount=0,msgReceived = 0;
char payload[512];
char rcvdPayload[512];

void mySubCallBackHandler (char *topicName, int payloadLen, char *payLoad)
{
    strncpy(rcvdPayload,payLoad,payloadLen);
    rcvdPayload[payloadLen] = 0;
    msgReceived = 1;
}

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
  if(aws.connect(AWS_HOST,CLIENT_ID)== 0)
    {
        Serial.println("Connected to AWS");
        delay(1000);

        if(0==aws.subscribe(MQTT_TOPIC,mySubCallBackHandler))
        {
            Serial.println("Subscribe Successfull");
        }
        else
        {
            Serial.println("Subscribe Failed, Check the Thing Name and Certificates");
            while(1);
        }
    }
    else
    {
        Serial.println("AWS connection failed, Check the HOST Address");
        while(1);
    }
}

void sendJsonToAWS()
{
  StaticJsonDocument<512> jsonDoc;
  JsonObject reportedObj = jsonDoc.createNestedObject("reported");
  
  // Write the temperature & humidity. Here you can use any C++ type (and you can refer to variables)
  reportedObj["WIFI"] = WIFI_SSID;
  reportedObj["EC"] = ec ;
  
  // Publish the message to AWS
  char payload[512];
  serializeJson(jsonDoc, payload);
  serializeJson(jsonDoc, Serial);
  if (aws.publish(MQTT_TOPIC, payload) == 0) { // MEM-PUBLISH payload DAN returns 0 JIKA SUKSES
      Serial.println("SUKSES\n");
    }
    else {
      Serial.println("GAGAL!\n");
    }
    Serial.println(payload);
}



void setup() {
  Serial.begin(115200);
  connectToWiFi();
  connectToAWS();
}

void loop() {
  if(msgReceived == 1)
    {
        msgReceived = 0;
        Serial.print("Received Message:");
        Serial.println(rcvdPayload);
    }
  
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
    Serial.println(ec);
  }
  if (publish+120 == detik) {
    detik = 0;
    baca = detik;
    publish = detik;
    Serial.println("Publishing:- ");
    sendJsonToAWS();
  }

}
