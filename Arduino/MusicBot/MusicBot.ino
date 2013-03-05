/*
PINS USED
 
 Shield Bot uses every pin.. I will name it Shieldbot Hitler because
 the pins I want to use is Poland...... *Grumpy cat*
 
 I used the tone example code and the Line follower example from the shield bot wiki!
 
 
 PINS FO REALZEEEEZ
 Switch - Pin 11
 Speaker - Pin 3
 LED(Red) - Pin 2
 LED(Blue) - Pin 4
 
 */

#include "pitches.h"
#include <Shieldbot.h>

Shieldbot sb = Shieldbot();
int S1,S2,S3,S4,S5, toneid;
int switchPin = 11;
#define speaker 3 //pin number

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
  //init shield bot
  Serial.begin(9600);
  sb.setMaxSpeed(50,50);
  pinMode(switchPin, INPUT);

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(speaker, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speaker);
  }
}

void loop() 
{

  while( digitalRead(switchPin) == HIGH) {
    //  while(false){
    //  while(true){  
    sb.drive(-125, -125);  

    //Print the status of each sensor to the Serial console
    Serial.print("S5: ");
    Serial.print(S5);
    Serial.print(" S4: ");
    Serial.print(S4);
    Serial.print(" S3: ");
    Serial.print(S3);
    Serial.print(" S2: ");
    Serial.print(S2);
    Serial.print(" S1: ");
    Serial.print(S1);
    Serial.println();

    toneid = GetToneID();
    Serial.print("ToneID: ");
    Serial.println(toneid);

    PlayTone(toneid);

  } //Close While
  sb.stop();
  noTone(speaker);
  Serial.println("I'm stopped");
}

int GetToneID()
{
  int x = 0;
  if(sb.readS5() == LOW){ 
    x = x + 16; 
  }
  if(sb.readS4() == LOW){
    x = x + 8; 
  }  
  if(sb.readS3() == LOW){
    x = x + 4; 
  }
  if(sb.readS2() == LOW){
    x = x + 2; 
  }
  if(sb.readS1() == LOW){
    x = x + 1; 
  }

  return x;
}

void PlayTone(int toneid)
{
  switch (toneid)
  { 
  case 1:
    tone(speaker, NOTE_C3);
    break;
  case 2:
    tone(speaker, NOTE_D3);
    break;
  case 3:
    tone(speaker, NOTE_E3);
    break;
  case 4:
    tone(speaker, NOTE_F3 );
  case 5:
    tone(speaker, NOTE_G3 );
    break;
  case 6:
    tone(speaker, NOTE_A3 );
    break;
  case 7:
    tone(speaker, NOTE_B3 );
    break;
  case 8:
    tone(speaker, NOTE_C4 );
    break;
  case 9:
    tone(speaker, NOTE_D4 );
    break;
  case 10:
    tone(speaker, NOTE_E4 );
    break;
  case 11:
    tone(speaker, NOTE_F4 );
    break;
  case 12:
    tone(speaker, NOTE_G4 );
    break;
  case 13:
    tone(speaker, NOTE_A4 );
    break;
  case 14:
    tone(speaker, NOTE_B4 );
    break;
  case 15:
    tone(speaker, NOTE_C5 );
    break;
  case 16:
    tone(speaker, NOTE_D5 );
    break;
  case 17:
    tone(speaker, NOTE_E5 );
    break;
  case 18:
    tone(speaker, NOTE_F5 );
    break;
  case 19:
    tone(speaker, NOTE_G5 );
    break;
  case 20:
    tone(speaker, NOTE_A5 );
    break;
  case 21:
    tone(speaker, NOTE_B5 );
    break;
  case 22:
    tone(speaker, NOTE_C6 );
    break;
  case 23:
    tone(speaker, NOTE_D6 );
    break;
  case 24:
    tone(speaker, NOTE_E6 );
    break;
  case 25:
    tone(speaker, NOTE_F6 );
    break;
  case 26:
    tone(speaker, NOTE_G6 );
    break;
  case 27:
    tone(speaker, NOTE_A7 );
    break;
  case 28:
    tone(speaker, NOTE_B7 );
    break;
  case 29:
    tone(speaker, NOTE_C7 );
    break;
  case 30:
    tone(speaker, NOTE_D7 );
    break;
  case 31:
    tone(speaker, NOTE_E7 );
    break;

  default:
    noTone(speaker);
    break;
  }  
}



