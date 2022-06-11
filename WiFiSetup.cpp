#include <ESP8266WiFi.h>

#include "WiFiSetup.h"

const IPAddress empty_ip(0,0,0,0);


WiFiSetup::WiFiSetup(Stream &Serial)
: Serial(Serial)
{
    WiFi.mode(WIFI_STA);
    //  Enable light sleep
    wifi_set_sleep_type(LIGHT_SLEEP_T);
}

bool
WiFiSetup::begin(const char* ssid, const char *passphrase, 
    IPAddress ip, IPAddress gateway, IPAddress subnet)
{

    if (!WiFi.config(ip, gateway, subnet)){
        Serial.println("STA Failed to configure fixed IP");
        return false;    
    }

    return begin(ssid, passphrase);
}

bool
WiFiSetup::begin(const char* ssid, const char *passphrase)
{

    WiFi.begin(ssid, passphrase);
    
    static const int max_attempt = 100;
    int attempt = 0;
    while (attempt < max_attempt && WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        attempt++;
    }
    Serial.println("");

    return (attempt < max_attempt);

}

bool WiFiSetup::disconnect(){
    return WiFi.disconnect();
}

IPAddress WiFiSetup::localIP()
{
    return WiFi.localIP();
}
