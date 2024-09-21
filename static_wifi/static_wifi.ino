#include <WiFi.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_Password";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(ssid,password);
  Serial.println("\n connecting");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(("."));
    delay(100);
  }
  Serial.println("\n Connected to WiFi");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  //i dont know what to write here

}
