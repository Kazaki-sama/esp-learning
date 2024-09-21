#include <WiFi.h>
#include "esp_wifi.h"
#include <sdkconfig.h>
const char* ssid = "apar";
const char* password = NULL;
const int channel = 10;
IPAddress local_ip(192,168,0,1);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

void display_connected_devices(){
   wifi_sta_list_t wifi_sta_list;
    tcpip_adapter_sta_list_t adapter_sta_list;
    esp_wifi_ap_get_sta_list(&wifi_sta_list);
    tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list);

  if(wifi_sta_list.num>0){
    Serial.println("....");
    for(uint8_t i =0; i<adapter_sta_list.num; i++){
      tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];
      Serial.print((String)" | Device " + i + "| Mac:");
      Serial.printf("%02X:%02X:%02X:%02X:%02X:%02X",station.mac[0], station.mac[1], station.mac[2], station.mac[3], station.mac[4], station.mac[5]);
      Serial.println((String) " | IP " + ip4addr_ntoa(&(station.ip)));
    }
  }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\n Creating AP");

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig( local_ip,  gateway,  subnet);
  WiFi.softAP(ssid,password);

  Serial.print(" AP created \n");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  display_connected_devices();
  delay(10000);
}
