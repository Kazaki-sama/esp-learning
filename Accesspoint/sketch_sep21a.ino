/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is based on the Arduino WiFi Shield library, but has significant changes as newer WiFi functions are supported.
 *  E.g. the return value of `encryptionType()` different because more modern encryption is supported.
 */
#include "WiFi.h"

const char* ssid = "gone";
const char* password = "426096@426096";

WiFiServer server(80);
void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected.
  
  Serial.print("setting AP (Access Point)...");

  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address:");
  Serial.println(IP);
  
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  
  if (client){

  Serial.println("Client start");

  // WiFi.scanNetworks will return the number of networks found.
  String currentLine = "";
  while (client.connected()){
    if(client.available()){
      char c= client.read();
      Serial.write(c);
      currentLine += c;
      if (c=='\n'){

        if (currentLine.length()==2){
          client.println("HTTP/1.1 200 OK");
          client.println("content-type:text/html");
          client.println("connection:close");
          client.println();

          client.println("<html><head></head></html>");
          client.println("<body>webpage</body>");

          client.println();

          break;
        }else{
          currentLine="";
        }
      }else if (c!='\r'){
        currentLine +=c;
      }
    }

  }
  client.stop();
  Serial.println("disconnect");
  Serial.println("\n");
  }
  
  
  
  }

  

