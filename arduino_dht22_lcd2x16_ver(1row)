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

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature(); // suhu °C
  float hum = dht.readHumidity();     // kelembaban %

  // Cek sensor valid
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Gagal membaca sensor DHT22!");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sensor Error");
    delay(2000);
    return;
  }

  // Tampilkan suhu dan kelembaban di baris pertama
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temp,1);
  lcd.print("C ");
  lcd.print("H:");
  lcd.print(hum,1);
  lcd.print("%");

  delay(2000); // update setiap 2 detik
}
