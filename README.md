# Testing Arduino(Sensor-Display)
Proyek Arduino untuk testing sensor JSN-HC04 (ultrasonik waterproof) dengan menampilkan data jarak secara real-time pada LCD I2C 2×16. Proyek ini sebagai persiapan Final Project sistem monitoring banjir untuk mengetahui tinggi air di lokasi rawan banjir.

**Flow :**
- Testing LCD 2 X 16 & DHT22 (arduino_dht22_lcd2x16_ver(1row))
- Testing LCD 2 X 16, DHT22 & JSN-HC04 (JSN-Display-DHT22.ino) 

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
<img width="3000" height="1903" alt="circuit_image" src="https://github.com/user-attachments/assets/65bce9ab-d85a-4c6b-91a1-66150c3da30d" />

Testing DHT22 - I2C 2x16 Display  : 
![TestingDHT22-Display](https://github.com/user-attachments/assets/d9865bc2-97c9-4da0-b22f-ccd48bf701c4)

Testing JSN-HC04-DHT22-I2C_Display :
![jsn-dht-display](https://github.com/user-attachments/assets/bc8b0815-08d9-4211-a032-ce5c0cf0137d)

Result Sensor :
![sensor-display](https://github.com/user-attachments/assets/b867fb13-c191-4185-8590-fe33761d3656)



