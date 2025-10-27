#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Konfigurasi DHT22
#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Konfigurasi LCD I2C 2x16
#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

// Konfigurasi JSN-HC04
#define TRIG_PIN 10
#define ECHO_PIN 11

// Konfigurasi Buzzer
#define BUZZER_PIN 6

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // ---- Baca DHT22 ----
  float temp = dht.readTemperature(); // suhu °C
  float hum = dht.readHumidity();     // kelembaban %

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Gagal membaca sensor DHT22!");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sensor Error");
    delay(2000);
    return;
  }

  // ---- Baca JSN-HC04 ----
  long duration;
  float distance;
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // cm

  // ---- Logika Buzzer ----
  if (distance < 25) {
    digitalWrite(BUZZER_PIN, HIGH); // bunyikan buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);  // matikan buzzer
  }

  // ---- Tampilkan di LCD ----
  lcd.clear();

  // Baris 1: Suhu & Kelembaban
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temp,1);
  lcd.print("C ");
  lcd.print("H:");
  lcd.print(hum,1);
  lcd.print("%");

  // Baris 2: Jarak
  lcd.setCursor(0,1);
  lcd.print("Dist: ");
  lcd.print(distance,1);
  lcd.print("cm");

  delay(2000); // update setiap 2 detik
}
