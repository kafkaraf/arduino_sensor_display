*Testing Arduino(Sensor-Display)*

Proyek Arduino untuk testing sensor JSN-HC04 (ultrasonik waterproof) dengan menampilkan data jarak secara real-time pada LCD I2C 2×16. Proyek ini sebagai persiapan Final Project sistem monitoring banjir untuk mengetahui tinggi air di lokasi rawan banjir.

**Flow :**
- Testing LCD 1 X 16 & DHT22
- Testing LCD 1 X 16, DHT22 & JSN-HC04

**Tools yang digunakan :**
- Arduino UNO
- DHT22
- Sensor Ultrasonik JSN-HC04
- LCD I2C 2×16
- Breadboard + Jumper (Male to Male / Male to Female)

DHT22
- (+) : 5V
- (-) : GND
- Data : Pin D13 (gunakan pull-up 10kΩ ke 5V)

Ultrasonic JSN-HC04
- VCC : 5V
- GND : GND
- Trig : Pin D6
- Echo : Pin D7

LCD I2C 2×16
- VCC : 5V
- GND : GND
- SDA : A4
- SCL : A5

Flow System :

Testing DHT : 
