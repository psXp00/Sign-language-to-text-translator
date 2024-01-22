/*
NAME OF THE PROJECT : SIGN LANGUAGE TRANSLATOR
MADE BY - Pranaya Sigdel

This project reads sensor values to interpret symbols generated from the American Sign Language (ASL) chart and 
displays the corresponding interpretations on a phone.

-------PIN CONFIGURATION----------------
A0-A6 : FLEX SENSOR
D4&D5 : FOR BLUETOOTH RX AND TX
A5&A6 : XPIN AND YPIN FOR ACCELROMETER
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(5,4);

char temp = '0';

//variable initializtion
int xpin = A5;
int xadc = 0;
int xmax = 0;
int xmin = 1023;

int ypin = A6;
int yadc = 0;
int ymax = 0;
int ymin = 1023;

int FLEX_PIN1 = A0; 
int flexADC1 = 0; 
int sensorMin1 = 1023; 
int sensorMax1 = 0;

int FLEX_PIN2 = A1; 
int flexADC2 = 0; 
int sensorMin2 = 1023; 
int sensorMax2 = 0;

int FLEX_PIN3 = A2; 
int flexADC3 = 0; 
int sensorMin3 = 1023; 
int sensorMax3 = 0;

int FLEX_PIN4 = A3; 
int flexADC4 = 0; 
int sensorMin4 = 1023; 
int sensorMax4 = 0;

int FLEX_PIN5 = A4; 
int flexADC5 = 0; 
int sensorMin5 = 1023; 
int sensorMax5 = 0;


void setup() 
{
mySerial.begin(9600);
Serial.begin(9600);
while (!Serial) 
{
; // wait for serial port to connect. Needed for native USB port only
}

/*
// callibrating the sensors for adaptivity with different bends
while(millis()<15000)
{
  Serial.println("Calibrating Sensor");
  Serial.println("Now close and open your hand");
//if(digitalRead(7)==HIGH)
//{
float flexADC1 = analogRead(FLEX_PIN1);
float flexADC2 = analogRead(FLEX_PIN2);
float flexADC3 = analogRead(FLEX_PIN3);
float flexADC4 = analogRead(FLEX_PIN4);
float flexADC5 = analogRead(FLEX_PIN5);

if(flexADC1<sensorMin1)
{
sensorMin1=flexADC1;
}
if(flexADC1>sensorMax1)
{
sensorMax1=flexADC1;
}

if(flexADC2<sensorMin2)
{
sensorMin2=flexADC2;
}
if(flexADC2>sensorMax2)
{
sensorMax2=flexADC2;
}

if(flexADC3<sensorMin3)
{
sensorMin3=flexADC3;
}
if(flexADC3>sensorMax3)
{
sensorMax4=flexADC4;
}

if(flexADC5<sensorMin5)
{
sensorMin5=flexADC5;
}
if(flexADC5>sensorMax5)
{
sensorMax5=flexADC5;
}

if(flexADC4<sensorMin4)
{
sensorMin4=flexADC4;
}
if(flexADC4>sensorMax4)
{
sensorMax4=flexADC4;
}
//}
}
Serial.println("Calibration Done");
*/
}


void printfun(char cp) //to avoid printing repeating symbols
{
if(cp!=temp)
{
mySerial.print(cp);
temp=cp;
}
}

void loop() 
{
// reading sensor value
int flexADC1 = analogRead(FLEX_PIN1);
int flexADC2 = analogRead(FLEX_PIN2);
int flexADC3 = analogRead(FLEX_PIN3);
int flexADC4 = analogRead(FLEX_PIN4);
int flexADC5 = analogRead(FLEX_PIN5);

/*
flexADC1 = constrain(flexADC1,sensorMin1, sensorMax1);
flexADC2 = constrain(flexADC2,sensorMin2, sensorMax2);
flexADC3 = constrain(flexADC3,sensorMin3, sensorMax3);
flexADC4 = constrain(flexADC4,sensorMin4, sensorMax4);
flexADC5 = constrain(flexADC5,sensorMin5, sensorMax5);


float angle1= map(flexADC1, sensorMin1, sensorMax1, 0, 90);
float angle2= map(flexADC2, sensorMin2, sensorMax2, 0, 90);
float angle3= map(flexADC3, sensorMin3, sensorMax3, 0, 90);
float angle4= map(flexADC4, sensorMin4, sensorMax4, 0, 90);
float angle5= map(flexADC5, sensorMin5, sensorMax5, 0, 90);
*/

Serial.print(flexADC1); Serial.print(" ");
Serial.print(flexADC2); Serial.print(" ");
Serial.print(flexADC3); Serial.print(" ");
Serial.print(flexADC4); Serial.print(" ");
Serial.print(flexADC5); Serial.print(" ");
//Serial.println();

xadc = analogRead(xpin);
yadc = analogRead(ypin);

Serial.print(xadc); Serial.print(" ");
Serial.print(yadc); Serial.print(" ");
Serial.println();


if(((flexADC1>=510)&&(flexADC1<=530))&&((flexADC2>=518)&&(flexADC2<=530))&&((flexADC3>=100)&&(flexADC3<=120))&&((flexADC4>=70)&&(flexADC4<=87))&&((flexADC5>=510)&&(flexADC5<=530)))
{
printfun('A');
Serial.print('A');
}

else if(((flexADC1>=510)&&(flexADC1<=530))&&((flexADC2>=510)&&(flexADC2<=525))&&((flexADC3>=200)&&(flexADC3<=230))&&((flexADC4>=200)&&(flexADC4<=230))&&((flexADC5>=510)&&(flexADC5<=538)))
{
printfun('B');
Serial.print('B');
}

else if(((flexADC1>=515)&&(flexADC1<=540))&&((flexADC2>=515)&&(flexADC2<=535))&&((flexADC3>=110)&&(flexADC3<=135))&&((flexADC4>=110)&&(flexADC4<=145))&&((flexADC5>=500)&&(flexADC5<=538)))
{
printfun('C');
Serial.print('C');
}

else if(((flexADC1>=525)&&(flexADC1<=545))&&((flexADC2>=525)&&(flexADC2<=545))&&((flexADC3>=100)&&(flexADC3<=115))&&((flexADC4>=100)&&(flexADC4<=115))&&((flexADC5>=520)&&(flexADC5<=545)))
{
printfun('D');
Serial.print('D');
}

else if(((flexADC1>=515)&&(flexADC1<=530))&&((flexADC2>=510)&&(flexADC2<=535))&&((flexADC3>=70)&&(flexADC3<=115))&&((flexADC4>=70)&&(flexADC4<=115))&&((flexADC5>=505)&&(flexADC5<=535)))
{
printfun('E');
Serial.print('E');
}

else if(((flexADC1>=510)&&(flexADC1<=535))&&((flexADC2>=525)&&(flexADC2<=545))&&((flexADC3>=235)&&(flexADC3<=255))&&((flexADC4>=235)&&(flexADC4<=255))&&((flexADC5>=510)&&(flexADC5<=535)))
{
printfun('F');
Serial.print('F');
}

else if(((flexADC1>=714)&&(flexADC1<=735))&&((flexADC2>=700)&&(flexADC2<=725))&&((flexADC3>=75)&&(flexADC3<=90))&&((flexADC4>=75)&&(flexADC4<=90))&&((flexADC5>=85)&&(flexADC5<=110)))
{
printfun('G');
Serial.print('G');
}

else if(((flexADC1>=715)&&(flexADC1<=735))&&((flexADC2>=710)&&(flexADC2<=730))&&((flexADC3>=145)&&(flexADC3<=165))&&((flexADC4>=148)&&(flexADC4<=165))&&((flexADC5>=1010)&&(flexADC5<=1035)))
{
printfun('H');
Serial.print('H');
}

else if(((flexADC1>=135)&&(flexADC1<=155))&&((flexADC2>=185)&&(flexADC2<=205))&&((flexADC3>=115)&&(flexADC3<=135))&&((flexADC4>=115)&&(flexADC4<=135))&&((flexADC5>=75)&&(flexADC5<=90)))
{
printfun('I');
Serial.print('I');
}

else if(((flexADC1>=605)&&(flexADC1<=625))&&((flexADC2>=600)&&(flexADC2<=630))&&((flexADC3>=90)&&(flexADC3<=120))&&((flexADC4>=90)&&(flexADC4<=120))&&((flexADC5>=600)&&(flexADC5<=630)))
{
printfun('J');
Serial.print('J');
}

else if(((flexADC1>=985)&&(flexADC1<=1010))&&((flexADC2>=950)&&(flexADC2<=980))&&((flexADC3>=135)&&(flexADC3<=155))&&((flexADC4>=135)&&(flexADC4<=155))&&((flexADC5>=1015)&&(flexADC5<=1035)))
{
printfun('K');
Serial.print('K');
}

else if(((flexADC1>=610)&&(flexADC1<=625))&&((flexADC2>=605)&&(flexADC2<=625))&&((flexADC3>=80)&&(flexADC3<=105))&&((flexADC4>=80)&&(flexADC4<=105))&&((flexADC5>=605)&&(flexADC5<=625)))
{
printfun('L');
Serial.print('L');
}

else if(((flexADC1>=620)&&(flexADC1<=645))&&((flexADC2>=615)&&(flexADC2<=635))&&((flexADC3>=95)&&(flexADC3<=120))&&((flexADC4>=95)&&(flexADC4<=125))&&((flexADC5>=535)&&(flexADC5<=555)))
{
printfun('M');
Serial.print('M');
}


else if(((flexADC1>=180)&&(flexADC1<=210))&&((flexADC2>=220)&&(flexADC2<=245))&&((flexADC3>=80)&&(flexADC3<=100))&&((flexADC4>=80)&&(flexADC4<=100))&&((flexADC5>=145)&&(flexADC5<=160)))
{
printfun('N');
Serial.print('N');
}

else if(((flexADC1>=585)&&(flexADC1<=615))&&((flexADC2>=95)&&(flexADC2<=120))&&((flexADC3>=85)&&(flexADC3<=110))&&((flexADC4>=85)&&(flexADC4<=110))&&((flexADC5>=595)&&(flexADC5<=620)))
{
printfun('O');
Serial.print('O');
}

else if(((flexADC1>=700)&&(flexADC1<=730))&&((flexADC2>=85)&&(flexADC2<=120))&&((flexADC3>=85)&&(flexADC3<=120))&&((flexADC4>=85)&&(flexADC4<=120))&&((flexADC5>=180)&&(flexADC5<=210)))
{
printfun('P');
Serial.print('P');
}

else if(((flexADC1>=710)&&(flexADC1<=735))&&((flexADC2>=100)&&(flexADC2<=145))&&((flexADC3>=90)&&(flexADC3<=110))&&((flexADC4>=90)&&(flexADC4<=110))&&((flexADC5>=180)&&(flexADC5<=210)))
{
printfun('Q');
Serial.print('Q');
}


else if(((flexADC1>=600)&&(flexADC1<=630))&&((flexADC2>=75)&&(flexADC2<=90))&&((flexADC3>=85)&&(flexADC3<=110))&&((flexADC4>=120)&&(flexADC4<=150))&&((flexADC5>=580)&&(flexADC5<=630)))
{
printfun('R');
Serial.print('R');
}

else if(((flexADC1>=595)&&(flexADC1<=620))&&((flexADC2>=65)&&(flexADC2<=99))&&((flexADC3>=65)&&(flexADC3<=99))&&((flexADC4>=65)&&(flexADC4<=85))&&((flexADC5>=595)&&(flexADC5<=620)))
{
printfun('S');
Serial.print('S');
}

else if(((flexADC1>=600)&&(flexADC1<=630))&&((flexADC2>=75)&&(flexADC2<=100))&&((flexADC3>=85)&&(flexADC3<=120))&&((flexADC4>=85)&&(flexADC4<=120))&&((flexADC5>=590)&&(flexADC5<=620)))
{
printfun('T');
Serial.print('T');
}

else if(((flexADC1>=700)&&(flexADC1<=730))&&((flexADC2>=85)&&(flexADC2<=120))&&((flexADC3>=145)&&(flexADC3<=170))&&((flexADC4>=145)&&(flexADC4<=170))&&((flexADC5>=145)&&(flexADC5<=170)))
{
printfun('U');
Serial.print('U');
}

else if(((flexADC1>=595)&&(flexADC1<=620))&&((flexADC2>=85)&&(flexADC2<=120))&&((flexADC3>=145)&&(flexADC3<=165))&&((flexADC4>=145)&&(flexADC4<=170))&&((flexADC5>=540)&&(flexADC5<=600)))
{
printfun('V');
Serial.print('V');
}

else if(((flexADC1>=600)&&(flexADC1<=635))&&((flexADC2>=65)&&(flexADC2<=95))&&((flexADC3>=230)&&(flexADC3<=250))&&((flexADC4>=230)&&(flexADC4<=250))&&((flexADC5>=600)&&(flexADC5<=630)))
{
printfun('W');
Serial.print('W');
}

else if(((flexADC1>=700)&&(flexADC1<=730))&&((flexADC2>=105)&&(flexADC2<=120))&&((flexADC3>=85)&&(flexADC3<=110))&&((flexADC4>=85)&&(flexADC4<=110))&&((flexADC5>=125)&&(flexADC5<=150)))
{
printfun('X');
Serial.print('X');
}

else if(((flexADC1>=600)&&(flexADC1<=630))&&((flexADC2>=170)&&(flexADC2<=190))&&((flexADC3>=80)&&(flexADC3<=115))&&((flexADC4>=75)&&(flexADC4<=110))&&((flexADC5>=600)&&(flexADC5<=625)))
{
printfun('Y');
Serial.print('Y');
}

else if(((flexADC1>=600)&&(flexADC1<=630))&&((flexADC2>=105)&&(flexADC2<=120))&&((flexADC3>=95)&&(flexADC3<=125))&&((flexADC4>=95)&&(flexADC4<=125))&&((flexADC5>=575)&&(flexADC5<=590)))
{
printfun('Z');
Serial.print('Z');
}


delay(500);

}
