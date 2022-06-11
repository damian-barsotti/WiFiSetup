#ifndef WIFISETUP_H
#define WIFISETUP_H

class WiFiSetup {
    public:
    WiFiSetup(Stream &Serial);
    WiFiSetup(const char* ssid, const char *passphrase, Stream &Serial,
        IPAddress ip, IPAddress gateway, IPAddress subnet);
    bool begin(const char* ssid, const char *passphrase);
    // With fixed address:
    bool begin(const char* ssid, const char *passphrase, 
        IPAddress ip, IPAddress gateway, IPAddress subnet);
    bool disconnect();
    IPAddress localIP();
    private:
    const String ssid;
    const String passphrase;
    Stream &Serial;
};

#endif
