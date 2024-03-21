#include <Servo.h>
#include <LiquidCrystal.h> // Include the LCD library

int sensorValue = 0;
Servo myServo;
LiquidCrystal lcd(8, 9, 5, 4, 3, 2); // Define the LCD pins (RS, RW, Enable, D4, D5, D6, D7)

void setup() {
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT); // Buzzer connected to pin 7
  pinMode(13, OUTPUT); // Turn on LED at pin 13
  pinMode(12, OUTPUT);  // Turn off LED at pin 12
  pinMode(11, OUTPUT);  // Turn off LED at pin 11
  pinMode(10, OUTPUT);  // Turn off LED at pin 10
  
  myServo.attach(6);
  Serial.begin(9600);
  lcd.begin(8, 2); // Initialize the LCD with 8 columns and 2 rows
  lcd.print("Brightness:"); // Print a static text on the LCD
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  //int fade = map(sensorValue, 54, 974, 0, 255);
  lcd.setCursor(0, 1); // Set cursor to second line

  if (sensorValue > 256) {
    lcd.print("Bright      "); // Display brightness level on LCD
    digitalWrite(13, HIGH); // Turn on LED at pin 13
    digitalWrite(12, LOW);  // Turn off LED at pin 12
    digitalWrite(11, LOW);  // Turn off LED at pin 11
    digitalWrite(10, LOW);  // Turn off LED at pin 10
    digitalWrite(7, HIGH); // Turn on buzzer at pin 7
    myServo.write(90); // Move the servo to a neutral position (or any other desired position)
  } else if ((sensorValue >= 135) && (sensorValue < 256)) {
    lcd.print("Moderate    "); // Display brightness level on LCD
   digitalWrite(13, LOW);  // Turn off LED at pin 13
    digitalWrite(12, HIGH); // Turn on LED at pin 12
    digitalWrite(11, LOW);  // Turn off LED at pin 11
    digitalWrite(10, LOW);  // Turn off LED at pin 10
    digitalWrite(7, LOW); // Turn off buzzer at pin 7
    myServo.write(90); // Move the servo to a neutral position (or any other desired position)
  } else if ((sensorValue >= 14) && (sensorValue < 135)) {
    lcd.print("Low         "); // Display brightness level on LCD
    digitalWrite(13, LOW);  // Turn off LED at pin 13
    digitalWrite(12, LOW);  // Turn off LED at pin 12
    digitalWrite(11, HIGH); // Turn on LED at pin 11
    digitalWrite(10, LOW);  // Turn off LED at pin 10
    digitalWrite(7, LOW); // Turn off buzzer at pin 7
    myServo.write(90); // Move the servo to a neutral position (or any other desired position)
  } else if ((sensorValue >= 0) && (sensorValue < 14)) {
    lcd.print("Very Low    "); // Display brightness level on LCD
    digitalWrite(13, LOW);  // Turn off LED at pin 13
    digitalWrite(12, LOW);  // Turn off LED at pin 12
    digitalWrite(11, LOW);  // Turn off LED at pin 11
    digitalWrite(10, HIGH); // Turn on LED at pin 10
    digitalWrite(7, LOW); // Turn off buzzer at pin 7
    myServo.write(135); // Move the servo to position 135 (or any other desired position)
     
     for (int angle = 0; angle <= 180; angle += 5) {
      myServo.write(angle);
      delay(50);
    }
    for (int angle = 180; angle >= 0; angle -= 5) {
      myServo.write(angle);
      delay(50);
    }
  }
  
  delay(200);
}
