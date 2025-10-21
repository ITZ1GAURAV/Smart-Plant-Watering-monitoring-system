#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define SOIL_PIN 34
#define RELAY_PIN 26

// LCD setup (address 0x27, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);

// Blynk credentials (you can blur this in the screenshot)
char auth[] = "YourAuthToken";
char ssid[] = "YourWiFi";
char pass[] = "YourPassword";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);

  lcd.init();
  lcd.backlight();
  dht.begin();

  pinMode(SOIL_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pump off initially

  lcd.setCursor(0, 0);
  lcd.print("Smart Watering");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);
}

void loop() {
  Blynk.run();

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soil = analogRead(SOIL_PIN);

  // Convert soil value
  int moisturePercent = map(soil, 4095, 0, 0, 100);

  Serial.print("Soil: ");
  Serial.print(moisturePercent);
  Serial.print("%  Temp: ");
  Serial.print(temp);
  Serial.print("°C  Humidity: ");
  Serial.print(hum);
  Serial.println("%");

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C H:");
  lcd.print(hum);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Soil:");
  lcd.print(moisturePercent);
  lcd.print("%");

  // Auto watering
  if (moisturePercent < 40) {
    digitalWrite(RELAY_PIN, LOW); // Pump ON
    Blynk.virtualWrite(V1, 1);
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Pump OFF
    Blynk.virtualWrite(V1, 0);
  }

  delay(2000);
}
