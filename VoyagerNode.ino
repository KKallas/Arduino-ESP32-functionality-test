
//WiFi setup and hostname
char* host = "esp32";
char* ssid = "ASUS";
char* password = "";
unsigned int UDPPort = 777;

void setup(void) {
    Serial.begin(115200);
    //setup WiFi, OTA, UDP
    xTaskCreate(WebTaskCode,"Web Task",10000,NULL,1);
    xTaskCreate(UDPTaskCode,"UDP Task",10000,NULL,2);
    //TODO xTaskCreateStatic (no dynamic memory allocation)
    //setup APA102
    xTaskCreate(LedUpdateTaskCode,"Led Update Task",10000,NULL);
}

void loop(void) {
  //nothing in the main loop sience we are using the scheduler tasks
  delay(100);
} 
