#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ===== CONFIGURATION  =====
#define DHTPIN 2
#define DHTTYPE DHT11

#define PIR_PIN 6
#define INA 4
#define INB 5
#define LED_PIN 7

float temperatureThreshold = 28.0;

// ===== OBJECTS  =====
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);

  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  float temperature = dht.readTemperature();
  int pir = digitalRead(PIR_PIN);

  if (isnan(temperature)) return;

  // ===== LCD LINE 1 =====
  lcd.setCursor(0,0);
  lcd.print("Temp : ");
  lcd.print(temperature);
  lcd.print(" C  ");

  // ===== LCD LINE 2 =====
lcd.setCursor(0,1);
lcd.print("Person: ");
if (pir == HIGH) {
  lcd.print("YES ");
} else {
  lcd.print("NO  ");
}

  // ===== FAN LOGIC (DO NOT MODIFY) =====
  if (temperature >= temperatureThreshold && pir == HIGH) {
    digitalWrite(INA, HIGH);
    digitalWrite(INB, LOW);
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(INA, LOW);
    digitalWrite(INB, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  delay(2000);
}
