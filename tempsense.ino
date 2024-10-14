#include <ESP8266WiFi.h>

#include <Adafruit_Sensor.h>

#include <DHT.h>

 

// Define DHT sensor type and GPIO pin

#define DHTTYPE DHT11 

#define DHTPIN D4          // GPIO pin connected to the DHT sensor

 

// Initialize DHT sensor

DHT dht(DHTPIN, DHTTYPE);

 

void setup() {

  // Start serial communication

  Serial.begin(115200);

  Serial.println("DHT Sensor Reading");

 

  // Initialize the DHT sensor

  dht.begin();

}

 

void loop() {


  delay(2000);

 

  // Reading temperature or humidity takes about 250 milliseconds

 

  float humidity = dht.readHumidity();

  float temperature = dht.readTemperature(); // Temperature in Celsius

  // float temperatureF = dht.readTemperature(true); // Temperature in Fahrenheit

 

  // Check if any reads failed and exit early (to try again)

  if (isnan(humidity) || isnan(temperature)) {

        Serial.println("Failed to read from DHT sensor!");

        return;

  }

 

  // Print results to the Serial Monitor

  Serial.print("Humidity: ");

  Serial.print(humidity);

  Serial.print(" %\t");

  Serial.print("Temperature: ");

  Serial.print(temperature);

  Serial.println(" °C");


}
