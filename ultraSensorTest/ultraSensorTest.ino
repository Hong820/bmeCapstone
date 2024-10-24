void setup() {
  pinMode(3, OUTPUT);//define arduino pin
  pinMode(2, INPUT);//define arduino pin
  Serial.begin(9600);//enable serial monitor

}
void loop() {
  //pulse output
  digitalWrite(3, LOW);
  delayMicroseconds(4);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
  
  long t = pulseIn(2, HIGH);//input pulse and save it veriable
  
  long inches = t / 74 / 2; //time convert distance
  long cm = t / 29 / 2; //time convert distance
  String inch = " inches ";
  String CM = " cm";

  Serial.println(inches + inch);//print serial monitor inches
  Serial.println(cm + CM);//print serial monitor cm
  Serial.println();//print space
  delay(100);//delay
}
