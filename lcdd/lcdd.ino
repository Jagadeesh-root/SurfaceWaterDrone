// include the library code:
#include <LiquidCrystal.h> // initialize the library with the numbers of the interface pins - The numbers
//are the pin connected in sequence from RS to DB7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 
void setup() 
{
    // set up the LCD's number of columns and rows:
   lcd.begin(16, 2);
   // Print a message to the LCD
   lcd.print("hello, world!");
   pinMode(9,OUTPUT);
pinMode(8,OUTPUT);   
 pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
    digitalWrite(8,HIGH);
   digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
}void loop() {
   
}
