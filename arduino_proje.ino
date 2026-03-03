#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// LCD ekran tanımı
LiquidCrystal_I2C lcd(0x27,16,2);

// Keypad tanımı
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2,3,4,5};  // Keypad row pinleri
byte colPins[COLS] = {6,7,8,9};  // Keypad column pinleri

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Servo motor tanımı
Servo myServo;

// Sabitler ve pinler
const String correctPassword = "2580";
String enteredPassword = "";

const int greenLED = 10;
const int redLED = 11;
const int servoPin = 12;
const int buzzerPin = 13;

const int flameSensorPin = A0;      // Alev sensörü
const int vibrationSensorPin = A1;  // Titreşim sensörü

// Zamanlar
unsigned long lastFlameBuzzTime = 0;
unsigned long lastVibBuzzTime = 0;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Sifre Giriniz:");

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  myServo.attach(servoPin);
  myServo.write(0); // Servo başlangıç pozisyonu
}

void loop() {
  char key = keypad.getKey();

  // Keypad işlemleri
  if(key) {
    if(key >= '0' && key <= '9') {
      if(enteredPassword.length() < 4) {
        enteredPassword += key;
        lcd.setCursor(enteredPassword.length() - 1, 1);
        lcd.print("*");
      }
    } 
    else if(key == '#') {  // Şifre temizle
      enteredPassword = "";
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sifre Giriniz:");
    }
    else if(key == 'A') {  // Şifre onayla
      lcd.clear();
      if(enteredPassword == correctPassword) {
        lcd.print("Dogru Sifre!");
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        // Servo açma
        myServo.write(90);
        delay(3000);
        myServo.write(0);
        digitalWrite(greenLED, LOW);
      } else {
        lcd.print("Yanlis Sifre!");
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        delay(2000);
        digitalWrite(redLED, LOW);
      }
      enteredPassword = "";
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sifre Giriniz:");
    }
  }

  // Alev sensörü işlemi (LOW aktif)
  int flameState = digitalRead(flameSensorPin);
  unsigned long currentMillis = millis();
  if(flameState == LOW) {
    if(currentMillis - lastFlameBuzzTime > 500) {
      tone(buzzerPin, 1000, 200); // 1000 Hz 200 ms
      lastFlameBuzzTime = currentMillis;
    }
  }

  // Titreşim sensörü işlemi (HIGH aktif)
  int vibrationState = digitalRead(vibrationSensorPin);
  if(vibrationState == HIGH) {
    if(currentMillis - lastVibBuzzTime > 150) {
      tone(buzzerPin, 500, 100);  // 500 Hz 100 ms
      lastVibBuzzTime = currentMillis;
    }
  }

  // Eğer hiç sensör aktif değilse buzzer kapalı
  if(flameState == HIGH && vibrationState == LOW) {
    noTone(buzzerPin);
}
}
