
#include <WiFi.h>
#include <HTTPClient.h>
  
const char* ssid = "iotseclab";
const char* password =  "qwerty1234";

void setup()
{
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to the WiFi network");
    delay(500);
}


void loop()
{

    if ((WiFi.status() == WL_CONNECTED)) {
  
    HTTPClient http;
  
    http.begin("http://jsonplaceholder.typicode.com/comments?id=10");
    int httpCode = http.GET();                                        
  
    if (httpCode > 0) { //Check for the returning code
  
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
  
    else {
      Serial.println("Error on HTTP request");
    }
  
    http.end(); 
  }
    delay(5000);
}
