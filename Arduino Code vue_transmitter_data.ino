//Project Created by Ghaith Mhamdi
//Rappel: j1PotX et j2PotX de mon transmitter sont inversés "<--" non pas "-->"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(10, 9);// RF24 radio(8, 7);   // nRF24L01 (CE, CSN)
const byte address[6] = "00001";
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

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
Data_Package data; //Create a variable with the above structure
void setup() {
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening(); //  Set the module as receiver
  resetData();
  Serial.begin(9600);
  Serial.println("looking for transmitter");
  while(!radio.available()); 
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); 
    while (data.pot2>10) {
      delay(4);
      Serial.println("descendez pot2");
    }
  }

}
void loop() {
 
  // Check whether there is data to be received
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
  }
  
  Serial.print("\n");
  Serial.print("data.j1PotX = ");
  Serial.println(data.j1PotX);
  Serial.print("data.j1PotY = ");
  Serial.println(data.j1PotY);
  Serial.print("data.j2PotX = ");
  Serial.println(data.j2PotX);
  Serial.print("data.j2PotY= ");
  Serial.println(data.j2PotY);
  Serial.print("data.j1Button = ");
  Serial.println(data.j1Button);
  Serial.print("data.j2Button = ");
  Serial.println(data.j2Button);
  Serial.print("data.pot1 = ");
  Serial.println(data.pot1);
  Serial.print("data.pot2 = ");
  Serial.println(data.pot2);
  Serial.print("data.tSwitch1 = ");
  Serial.println(data.tSwitch1);
  Serial.print("data.tSwitch2 = ");
  Serial.println(data.tSwitch2);
  Serial.print("data.button1 = ");
  Serial.println(data.button1);
  Serial.print("data.button2 = ");
  Serial.println(data.button2);
  Serial.print("data.button3 = ");
  Serial.println(data.button3);
  Serial.print("data.button4 = ");
  Serial.println(data.button4);
  delay(1000);
}
void resetData() {
  // Reset the values when there is no radio connection - Set initial default values
  data.j1PotX = 127;
  data.j1PotY = 127;
  data.j2PotX = 127;
  data.j2PotY = 107;
  data.j1Button = 1;
  data.j2Button = 1;
  data.pot1 = 0;
  data.pot2 = 0;
  data.tSwitch1 = 1;
  data.tSwitch2 = 1;
  data.button1 = 1;
  data.button2 = 1;
  data.button3 = 1;
  data.button4 = 1;
}
