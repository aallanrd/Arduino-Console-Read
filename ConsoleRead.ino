/*
  Console Read example

 Read data coming from bridge using the Console.read() function
 and store it in a string.

 To see the Console, pick your Yún's name and IP address in the Port menu
 then open the Port Monitor. You can also see it by opening a terminal window
 and typing:
 ssh root@ yourYunsName.local 'telnet localhost 6571'
 then pressing enter. When prompted for the password, enter it.

 created 13 Jun 2013
 by Angelo Scialabba
 modified 16 June 2013
 by Tom Igoe

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/ConsoleRead

 */

#include <Console.h>

int led = 13; // LED connected to digital pin 13
int pts = 2;  // Powertail Switch 2 connected to digital pin 2
int recv = 0; // byte received on the serial port
 
void setup() {
  // initialize onboard LED (led), Powertail (pts) and serial port
  pinMode(led, OUTPUT);
  pinMode(pts, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  // if serial port is available, read incoming bytes
  if (Serial.available() > 0) {
    recv = Serial.read();
 
    // if 'y' (decimal 121) is received, turn LED/Powertail on
    // anything other than 121 is received, turn LED/Powertail off
    if (recv == 121){
      digitalWrite(led, HIGH);
      digitalWrite(pts,LOW);
    } else {
      digitalWrite(led, LOW);
      digitalWrite(pts,HIGH);
    }
     
    // confirm values received in serial monitor window
    Serial.print("--Arduino recibio: ");
    Serial.println(recv);
  }
}

