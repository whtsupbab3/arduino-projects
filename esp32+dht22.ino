#include <DHT.h>
#define DHT22_PIN 21  

DHT dht22(DHT22_PIN, DHT22);

void setup() {
  Serial.begin(9600);
  dht22.begin();  
}

void loop() {
  float humi = dht22.readHumidity();
  float tempC = dht22.readTemperature();
  float tempF = dht22.readTemperature(true);

  if (isnan(tempC) || isnan(tempF) || isnan(humi)) {
    Serial.println("Failed to read from DHT22 sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C  ~  ");
    Serial.print(tempF);
    Serial.println("°F");
  }

  delay(2000);
}
