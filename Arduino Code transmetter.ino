//Project created by Mhamdi Ghaith 
//facebook page: HardSoftRoboticsMh: https://www.facebook.com/profile.php?id=61574058525266
//Github: ghaithmhamd: https://github.com/ghaithmhamd
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define Buzz 10
#define jB1 1  // Joystick button 1
#define jB2 0  // Joystick button 2
#define t1 7   // Toggle switch 1
#define t2 4   // Toggle switch 2
#define b1 8   // Button 1
#define b2 9   // Button 2
#define b3 2   // Button 3
#define b4 3   // Button 4

RF24 radio(5, 6);   // nRF24L01 (CE, CSN)
const byte address[6] = "00001"; 
// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
  byte j1PotX;
  byte j1PotY;
  byte j1Button;
  byte j2PotX;
  byte j2PotY;
  byte j2Button;
  byte pot1;
  byte pot2;
  byte tSwitch1;
  byte tSwitch2;
  byte button1;
  byte button2;
  byte button3;
  byte button4;
};
Data_Package data; 
void setup() {
  radio.begin();
  tone(Buzz, 262, 255);
  delay(331);
  tone(Buzz, 196, 127);
  delay(165);
  tone(Buzz, 196, 127);
  delay(165);
  tone(Buzz, 220, 255);
  delay(331);
  tone(Buzz, 196, 255);
  delay(331);
  tone(Buzz, 0  , 255);
  delay(331);
  tone(Buzz, 247, 255);
  delay(331);
  tone(Buzz, 262, 255);
  delay(331);
  noTone(Buzz);
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  radio.stopListening();
  radio.openWritingPipe(address);

  pinMode(jB1, INPUT_PULLUP);
  pinMode(jB2, INPUT_PULLUP);
  pinMode(t1, INPUT_PULLUP);
  pinMode(t2, INPUT_PULLUP);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
  
  data.j1PotX = 127; // Values from 0 to 255. When Joystick is in resting position, the value is in the middle, or 127. We actually map the pot value from 0 to 1023 to 0 to 255 because that's one BYTE value
  data.j1PotY = 127;
  data.j2PotX = 127;
  data.j2PotY = 127;
  data.j1Button = 1;
  data.j2Button = 1;
  data.pot1 = 1;
  data.pot2 = 1;
  data.tSwitch1 = 1;
  data.tSwitch2 = 1;
  data.button1 = 1;
  data.button2 = 1;
  data.button3 = 1;
  data.button4 = 1;
}
void loop() {
  data.j1PotX = map(analogRead(A1), 0, 1023, 0, 255); 
  data.j1PotY = map(analogRead(A0), 0, 1023, 0, 255);
  data.j2PotX = map(analogRead(A2), 0, 1023, 0, 255);
  data.j2PotY = map(analogRead(A3), 0, 1023, 0, 255);
  data.pot1 = map(analogRead(A7), 0, 1023, 0, 255);
  data.pot2 = map(analogRead(A6), 0, 1023, 0, 255);

  data.j1Button = digitalRead(jB1);
  data.j2Button = digitalRead(jB2);
  data.tSwitch2 = digitalRead(t2);
  data.button1 = digitalRead(b1);
  data.button2 = digitalRead(b2);
  data.button3 = digitalRead(b3);
  data.button4 = digitalRead(b4);

  radio.write(&data, sizeof(Data_Package));
}
