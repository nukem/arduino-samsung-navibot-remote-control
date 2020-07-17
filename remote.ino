#include <Keypad.h>
#include <IRremote.h>

unsigned long IRCodes[] = {
  0x00,
  0x818100FF, // Power
  0x8181807F, // Recharge
  0x818140BF, // Auto
  0x8181C03F, // Spot
  0x818120DF, // Repeated Cleaning
  0x818110EF, // Start/Stop
  0x8181A05F, // Forward
  0x8181609F, // Left
  0x8181E01F, // Right
  0x8181906F, // Manual
  0x8181D02F, // Turbo
  0x8181D02F, // Edge
  0x818130CF, // Schedule
  0x8181B04F, // Remote Off
  0x8181708F, // Prompt Mode
};
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
IRsend irsend;

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  unsigned long i = 0;
  char customKey = customKeypad.getKey();
  
  switch(customKey) {
    case 'C':
      Serial.println(F("Power"));
      i = 0x818100FF;
      break;
    case 'F':
      Serial.println(F("Charge"));
      i = 0x8181807F;
      break;
    case '8':
      Serial.println(F("Auto"));
      i = 0x818140BF;
      break;
    case 'E':
      Serial.println(F("Spot"));
      i = 0x8181C03F;
      break;
    case 'B':
      Serial.println(F("Repeated Cleaning"));
      i = 0x818120DF;
      break;
    case 'D':
      Serial.println(F("Forward"));
      i = 0x8181A05F;
      break;
    case '1':
      Serial.println(F("Left"));
      i = 0x8181609F;
      break;
    case '5':
      Serial.println(F("Start/Stop"));
      i = 0x818110EF;
      break;
    case '9':
      Serial.println(F("Right"));
      i = 0x8181E01F;
      break;
    case '4':
      Serial.println(F("Manual"));
      i = 0x8181906F;
      break;
    case 'A':
      Serial.println(F("Turbo"));
      i = 0x818150AF;
      break;
    case '7':
      Serial.println(F("Edge"));
      i = 0x8181D02F;
      break;
    case '0':
      Serial.println(F("Schedule"));
      i = 0x818130CF;
      break;
    case '6':
      Serial.println(F("Remote ON/OFF"));
      i = 0x8181B04F;
      break;
    case '3':
      Serial.println(F("Prompt Select"));
      i = 0x8181708F;
      break;
    default:
      i = 0;
  }

  if (i > 0)
  {
    //send the code 3 times
    for (int x = 0; x < 3; x++) {
      irsend.sendNEC(i , 32);
      delay(40);
    }
  }
  
}
