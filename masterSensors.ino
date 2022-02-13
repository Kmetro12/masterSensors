
/*
 * MASTER SENSOR LIST 
 */

 
//-------------SERIAL PORT HUMIDITY AND TEMPEATURE SENSOR----------------------------------

#include <dht.h> //includes the dht library, for sensors  
#include <LiquidCrystal.h>//includes the liquid crystal libray for LCD display 

//uncommet code for analog and seril monitor display 
//#define dht_apin A0 // what analog pin the sensor is connected to, can use analog pin  
#define DHT11_PIN 7 //defines the connected pin 

dht DHT; 
float tempC;
float tempFaren; 

void setup() {

  Serial.begin(9600); //starts serial communication with 9600b/s parameter 
  delay(500); //delay to let system boot 
  Serial.println("DHT Sensor, Temp and Humidity Sensor"); 
  delay(1000); // wait before accessing sensor 

}

void loop() {

  int chk = DHT.read11(DHT11_PIN); //reads the siganl pin placed at analog 0 on arduino 
  
  //Serial.print("Humidity: "); 
  //Serial.print(DHT.humidity); //prints the humidity to the computer
  //Serial.print("% ");
   
  tempC = DHT.temperature; // get the temperature reading in C
  tempFaren = (tempC*9/5)+32; //Converting C to F
  Serial.print("Temperature (F): ");
  Serial.print(tempFaren); 
  Serial.println("F°");   
  //Serial.print("Temperature (C): "); 
  //Serial.print(DHT.temperature); 
  //Serial.println("C "); 
  tempC = 0;
  tempFaren = 0;
  delay(3000); //waits 3 seconds before accessing the sensor 
}

//-------------END SERIAL PORT HUMIDITY AND TEMPEATURE SENSOR-----------------------------

//-------------MOTION PIR SENSOR WITH LED-----------------------------------------------------
/*
 //Arduino with a motion PIR sensor to turn an LED light on when motion is detected 

int ledPin = 13;                // LED 
int pirPin = 10;                 // PIR Out pin 
int pirStat = 0;                   // PIR status
void setup() {
 pinMode(ledPin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}

void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            // if motion detected
   digitalWrite(ledPin, HIGH);  // turn LED ON
   Serial.println("Motion Detected in Sector 4!!");//prints to the serial monitor 
 } 
 else {
   digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
 }
} 
 */
//-------------END MOTION PIR SENSOR WITH LED--------------------------------------------------- 
//-------------SERIAL MONITOR PIR WITH MOTION SENSOR--------------------------------------------
/*
//Motion sensor Serial monitor 
//can change delay time and sensativity on the sensor itself via the 2 screws on the sensor 
//define pin statues and outpin pin 
int pirPin = 10; 
int pirStat = 0; 


void setup() {
  pinMode(pirPin, INPUT); //pinmode configues the pin to input or output 
  Serial.begin(9600); //starts the serial monitor    
}//end setup 

void loop() {
  pirStat = digitalRead(pirPin); 
  if (pirStat == HIGH){
    Serial.println("Motion Detected @SensorLocation");
    delay(3000);
    }
    else{
      Serial.println("All Clear");
      delay(3000); 
      }
}//end loop 
 */
//-------------END SERIAL MONITION PIR WITH MOTION SENSOR---------------------------------------
//-------------HUMIDITY AND TEMPEATURE SENSOR WITH LCD SCREEN------------------------------- 
/*

#include <dht.h> //includes the dht library, for sensors  
#include <LiquidCrystal.h>//includes the liquid crystal libray for LCD display 

//uncommet code for analog and seril monitor display 
//#define dht_apin A0 // what analog pin the sensor is connected to, can use analog pin  
#define DHT11_PIN 7 //defines the connected pin 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT; 
float tempC; //float to hold Cel value 
float tempFaren; //float to hold Faren value

void setup() {

  lcd.begin(16,2); 

}

void loop() {

  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0);//sets the cursor to 0,0 on tyhe LCD 
  lcd.print("Temp: ");
  tempC = DHT.temperature; //getting the temperature in C
  //converting the temperature from C to F
  tempFaren = (tempC*9/5)+32;
  lcd.print(tempFaren);//prints the temp to the lcd
  lcd.print("F°"); // printing the degrees symbol 
  lcd.setCursor(0,1); //sets the cursor to the next row down to display humidity 
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);//prints the humidity to the lcd
  delay(5000); //sensor updates every 5 seconds, to show a solid number on the 

}

*/
//-----------END HUMIDITY AND TEMPEATURE SENSOR WITH LCD SCREEN ----------------------------------
//-----------SOUND SENSOR DISTANCE MEASUREMENTS SERIAL MONITOR------------------------------------
/*
Ultrasonic sound sensor, 40000Hz 
https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/ reference 
//define what pins are being used
const int trigPin = 9; //the trig pin sends out the sound wave 
const int echoPin = 10; //recieves the sound wave 

//define the variables needed 
long duration; //travel time from the sensor 
int distance; 

void setup() {
  pinMode(trigPin, OUTPUT); //sets the trig pin as output, on sensor device  
  pinMode(echoPin, INPUT); //sets the echoPin as input, on sensor device 
  Serial.begin(9600); //Starts serial communication, 9600 is the speed parameter, data rate is 9600 bits per second.  
}

void loop() {
  //Clear the trigPin
  digitalWrite(trigPin, LOW); //sets the pin to a low state 
  delayMicroseconds(2); //delays by two microseconds 

  digitalWrite(trigPin, HIGH); //sets the trigPin to a high state for 10 microseconds 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH); //reads the echoPin and returns the sound wave travel time, 
  //in microseconds, pulse in function will wait for the echo pin to go high  

  distance = duration*0.034/2; //calculating the distance in cm 

  //prints the distance on the serial monitor 
  Serial.print("Distance (cm): "); 
  Serial.println(distance); 
}
 */
//-----------END SOUND SENSOR SERIAL MONITOR DISTANCE MEASURMENTS---------------------------------
//-----------TOUCH SENSOR-------------------------------------------------------------------------
/*
//Touch Sensor 

int signalPin = A1; //sets the input pin for the touch sensor 
int signalVal = 0; // Stores the value coming from the sensor 

void setup() {
  Serial.begin(9600); //start serial communication with the computer 
 
}

void loop() {
  signalVal = analogRead(signalPin);// reads the value from the sensor 
  
  if (signalVal > 0){ //if statement to detect movement, if sensor is triggered above 0 
    Serial.println("Movement in sector 3, Front Window!!"); 
    delay(2000);//deplays the program by 2 seconds 
    }
  else {
    Serial.println("All is clear");
    delay(2000); // delays the program by 2 seonds 
    }
}
 */
//-----------END TOUCH SENSOR---------------------------------------------------------------------
//-----------LCD Message practice-----------------------------------------------------------------

/*
//https://www.arduino.cc/en/Reference/LiquidCrystalConstructor reference 

#include <LiquidCrystal.h>//includes the liquid crystal libray for LCD display 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//creates a display 
    //variable using a 4 or 8 pin dataset 

void setup() {
   lcd.begin(16,2); //initiaizes the interface to the LCD screen 

}

void loop() {

  lcd.noBlink();//stops blinking LCD cursor 
  lcd.setCursor(0,0); //sets the LCD cursor to 0,0 
  lcd.print("Warning! Warning! ");
  lcd.print("Warning! Warning! ");
  lcd.setCursor(0,1); 
  lcd.print("Volcano Alert! "); 
  lcd.print("Volcano Alert! "); 
  lcd.scrollDisplayLeft();
  delay(2000); //delays the sensor by 5 seconds 

} 
 */
//-----------BLINKING LCD SILLY---------------------------------------------------------------------
//-----------BLINKING LED---------------------------------------------------------------------
/*
#define LED 13 //says led is connected to pin 13  

void setup() {
  // put your setup code here, to run once:
 pinMode(LED, OUTPUT); // sets the digital output pin as output 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH); //turns led on
  delay(1000); //waits a second
  digitalWrite(LED,LOW);//turns the led off
  delay(1000); //waiots a second

}
 */
//-----------END BLINKING LED----------------------------------------------------------------------------
