#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "SerialPrint.h"

SerialPrint sp;

void setup()
{
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  sp.println("Setup done");
}

void loop()
{
  sp.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    sp.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      sp.print(i + 1);
      sp.print(": ");
      sp.print(WiFi.SSID(i));
      sp.print(" (");
      sp.print(WiFi.RSSI(i));
      sp.print(")");
      sp.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  sp.println("");

  // Wait a bit before scanning again
  delay(5000);
}