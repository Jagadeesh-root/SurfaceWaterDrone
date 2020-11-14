#define joyX A0
#define joyY A1
#define a A2
 
void setup() {
  Serial.begin(9600);
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
int   xValue = analogRead(joyX);
 int     yValue = analogRead(joyY);
 int   A=analogRead(a);
  //print the values with to plot or view
  Serial.print(xValue);
  Serial.print("  ");
  Serial.println(yValue);
  Serial.println("  ");
  Serial.println(A);
  delay(500);

}

