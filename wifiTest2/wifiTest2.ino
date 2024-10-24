#include <SPI.h>
#include <WiFiNINA.h>
#include "secret.h"

IPAddress subnet(255, 255, 0, 0);
IPAddress gateway(192, 168, 1, 10);
IPAddress local_IP(192, 168, 1, 10);

//char ssid[] = SECRET_SSID;        // your network SSID (name)
//char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
//int keyIndex = 0;                 // your network key index number (needed only for WEP)

int status = WL_IDLE_STATUS;
unsigned int localPort = 4000;

WiFiServer server(80);

void setup() {
  Serial.begin(9600);

  while (!Serial) {
    // wait for the serial port to connect; necessary for native usb port
  }

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("Wifi shield not present");

    while(true);
  }

  WiFi.config(local_IP, gateway, subnet);

  while(status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println("Tien2.4");

    status = WiFi.begin(WIFI_SSID, WIFI_PASS);

    delay(10000);
  }

  server.begin();

  Serial.println("Connected");
}

void loop() {
  // put your main code here, to run repeatedly:

}
