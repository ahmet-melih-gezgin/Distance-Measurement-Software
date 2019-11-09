
#define in1  5
#define in2  6
#define en1  7
#define echoPin 11
#define trigPin 10



long zaman;
long uzaklik;




void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
   pinMode(en1, OUTPUT);
Serial.begin(9600); 


}

void loop() {

  digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

zaman = pulseIn(echoPin, HIGH);
delay(10);

uzaklik= zaman*0.034/2;

Serial.print("uzaklık cm: ");
Serial.println(uzaklik);






if(uzaklik>15 ){

  motorileri1(130);

 
}
if(uzaklik<15)
{
 motorgeri1(130);
 
}
if(uzaklik>=13 && uzaklik<=17)
{
  durdur();
 
}





 

}



void motorileri1(int en1_val){
  analogWrite(en1 , en1_val);

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
}

void motorgeri1(int en1_val){

 
  analogWrite(en1 ,en1_val );

digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
  
}

void durdur(){

  analogWrite(en1 ,0);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);



}
