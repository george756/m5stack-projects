#include <M5Stack.h>
#include <Wire.h>
#define SERVO_ADDR 0x53


void Servo_write_angle(uint8_t number, uint8_t angle);
void setup() {
    M5.begin();
   
    Serial.begin(115200);
    M5.Lcd.clear(BLACK);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(80, 0); 
    M5.Lcd.println("PIR example");
    Serial.println("PIR example: ");
    M5.Lcd.setCursor(65, 10);
    M5.Lcd.setTextColor(WHITE);    
    pinMode(36, INPUT);    
    
    Wire.begin(21, 22, 100000);
    Servo_write_angle(1, 0);
}

    void loop() {
      M5.Lcd.setCursor(0,25); M5.Lcd.print("Status: ");
      M5.Lcd.setCursor(0,45); M5.Lcd.print("Value: ");
  
      M5.Lcd.fillRect(95,25,200,25,BLACK);
      M5.Lcd.fillRect(95,45,200,25,BLACK);
    

    if(digitalRead(36)==0){
      M5.Lcd.setCursor(95, 25);M5.Lcd.print("Sensing");
      M5.Lcd.setCursor(95, 45);M5.Lcd.print("1");
      Serial.println("PIR Status: Sensing");
      Serial.println(" value: 1");
      Servo_write_angle(1, 90);
    }

    if(digitalRead(36)==1){
      M5.Lcd.setCursor(95, 25);M5.Lcd.print("Not Sensed");
      M5.Lcd.setCursor(95, 45);M5.Lcd.print("0");
      Serial.println("PIR Status: Not Sensed");
      Serial.println(" value: 0");
      Servo_write_angle(1, 0);
    }
    delay(500);
    M5.update();
  }
    

void Servo_write_angle(uint8_t number, uint8_t angle) {
    Wire.beginTransmission(SERVO_ADDR);
    Wire.write(0x10 | number);
    Wire.write(angle);
    Wire.endTransmission();
}
