/*
   Melody
  
  Plays a melody 
 
  circuit:
  * 8-ohm speaker on digital pin 8
  
  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe 

This example code is in the public domain.
  
  http://arduino.cc/en/Tutorial/Tone
  
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
 
void loop() {
  
  while( digitalRead(switchPin) == HIGH) {
  //  while(false){
  sb.drive(-125, -125);  
    
  //Read all the sensors 
  S1 = sb.readS1();
  S2 = sb.readS2();
  S3 = sb.readS3();
  S4 = sb.readS4();// I made a change
  S5 = sb.readS5();
 
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
  
  
 if (S1 == LOW && S2 == HIGH && S3 == HIGH && S4 == HIGH && S5 == HIGH) //1
 {
toneid = 1;
 }
  else if (S1 == LOW && S2 == HIGH && S3 == LOW && S4 == LOW && S5 == LOW) //2
 { toneid = 2 ; }
 else if (S1 == LOW && S2 == LOW && S3 == HIGH && S4 == HIGH && S5 == HIGH) //3
 {toneid =3 ;}
 else if (S1 == HIGH && S2 == HIGH && S3 == LOW && S4 == HIGH && S5 == HIGH) //4
 {toneid = 4;}
 
 else if (S1 == LOW && S2 == HIGH && S3 == LOW && S4 == HIGH && S5 == HIGH) //5
 {toneid = 5;}
 
 else if (S1 == HIGH && S2 == LOW && S3 == LOW && S4 == HIGH && S5 == HIGH) //6
 {toneid = 6;}
 
 else if (S1 == LOW && S2 == LOW && S3 == LOW && S4 == HIGH && S5 == HIGH) //7
 {toneid = 7;}
 
 else if (S1 == HIGH && S2 == HIGH && S3 == HIGH && S4 == LOW && S5 == HIGH) //8
 {toneid = 8;}
 
 else if (S1 == LOW && S2 == HIGH && S3 == HIGH && S4 == LOW && S5 == HIGH) //9
 {toneid = 9;}
 
 else if (S1 == HIGH && S2 == LOW && S3 == HIGH && S4 == LOW && S5 == HIGH) //10
 {toneid = 10;}
 
 else if (S1 == LOW && S2 == LOW && S3 == HIGH && S4 == LOW && S5 == HIGH) //11
 {toneid = 11;}
 
 else if (S1 == HIGH && S2 == HIGH && S3 == LOW && S4 == LOW && S5 == HIGH) //12
 {toneid = 12;}
 
 else if (S1 == LOW && S2 == HIGH && S3 == LOW && S4 == LOW && S5 == HIGH) //13
 {toneid =13 ;}
 
 else if (S1 == HIGH && S2 == LOW && S3 == LOW && S4 == LOW && S5 == HIGH) //14
 {toneid = 14;}
 
 else if (S1 == LOW && S2 == LOW && S3 == LOW && S4 == LOW && S5 == HIGH) //15
 {toneid = 15;}
 
 else if (S1 == HIGH && S2 == HIGH && S3 == HIGH && S4 == HIGH && S5 == LOW) //16
 {toneid = 16;
 }
 else if (S1 == LOW && S2 == HIGH && S3 == HIGH && S4 == HIGH && S5 == LOW) //17
 {toneid = 17;
 }
  else if (S1 == HIGH && S2 == LOW && S3 == HIGH && S4 == HIGH && S5 == LOW) //18
 {toneid = 18;}
 else if (S1 == LOW && S2 == LOW && S3 == HIGH && S4 == HIGH && S5 == LOW) //19
 {toneid = 19;}
 else if (S1 == HIGH && S2 == HIGH && S3 == LOW && S4 == HIGH && S5 == LOW) //20
 {toneid = 20;}
 
 else if (S1 == LOW && S2 == HIGH && S3 == LOW && S4 == HIGH && S5 == LOW) //21
 {toneid = 21;}
 
 else if (S1 == HIGH && S2 == LOW && S3 == LOW && S4 == HIGH && S5 == LOW) //22
 {toneid = 22;}
 
 else if (S1 == LOW && S2 == LOW && S3 == LOW && S4 == HIGH && S5 == LOW) //23
 {toneid = 23;}
 
 else if (S1 == HIGH && S2 == HIGH && S3 == HIGH && S4 == LOW && S5 == LOW) //24
 {toneid = 24;}
 
 else if (S1 == LOW && S2 == HIGH && S3 == HIGH && S4 == LOW && S5 == LOW) //25
 {toneid = 25;}
 
 else if (S1 == HIGH && S2 == LOW && S3 == HIGH && S4 == LOW && S5 == LOW) //26
 {toneid = 26;}
 
 else if (S1 == LOW && S2 == LOW && S3 == HIGH && S4 == LOW && S5 == LOW) //27
 {toneid = 27;}
 
 else if (S1 == HIGH && S2 == HIGH && S3 == LOW && S4 == LOW && S5 == LOW) //28
 {toneid = 28;}
 
 else if (S1 == LOW && S2 == HIGH && S3 == LOW && S4 == LOW && S5 == LOW) //29
 {toneid = 29;}
 
 else if (S1 == HIGH && S2 == LOW && S3 == LOW && S4 == LOW && S5 == LOW) //30
 {toneid = 30;}
 
 else if (S1 == LOW && S2 == LOW && S3 == LOW && S4 == LOW && S5 == LOW) //31
 {toneid = 31;}
 
  else //0
 {
   toneid = 0;
 } 
  
 Serial.print("ToneID: ");
 Serial.println(toneid);
 
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


 } //Close While
 sb.stop();
 noTone(speaker);
 Serial.println("I'm stopped");
 }
 
