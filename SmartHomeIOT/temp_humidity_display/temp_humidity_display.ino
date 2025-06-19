#include "DHT.h"

#define DHTPIN D2      // Selecting the pin at which we have connected DHT11
#define DHTTYPE DHT11 
 
 DHT dht ( DHTPIN, DHTTYPE );

 
void setup() {
dht.begin();

Serial.begin(9600);
 Serial.println();
  Serial.println();
 Serial.println("Humidity and Temperature");
 
}


void loop() 
{ 
  
 float humidity = dht.readHumidity();
 float temprature = dht.readTemperature();

  Serial.print("current humidity=");
  Serial.print(humidity);
  Serial.print("%,");
  Serial.print("current temperature=");
  Serial.print(temprature);
  Serial.println("C");
    delay(4000);
}
