 // Inputs and outputs
 #define PWM  6           // Connected to the BJT base in the H-bridge  
 #define throttle  A0     // Throttle potentiometer (0-5v)
 #define on 7             // Power control
 #define brakeIn 8        // Brake input - represented by a button
 #define indicator 9      // Power indicator
 #define brakeLight 10    // Brake light
 
 int cont;
 bool power = false;
 
void setup() {
 pinMode(PWM,OUTPUT);
 pinMode(on,OUTPUT);
 pinMode(brakeLight,OUTPUT);
 pinMode(indicator,OUTPUT);
 pinMode(brakeIn,INPUT_PULLUP);

}

void loop() {
  if (digitalRead(brakeIn) == HIGH){
    power = true;
    digitalWrite(on, LOW);
    digitalWrite(indicator,HIGH);
    digitalWrite(brakeLight, LOW);
    cont = map(analogRead(throttle), 0, 1023, 0, 255);
    if(cont > 255){
      cont = 255;
    }
    else if(cont < 5){
      cont = 0;
    }
    analogWrite(PWM, cont);
  }
  else if(digitalRead(brakeIn) == LOW){
    brake();
  }
 

}

void brake(){
  digitalWrite(on,HIGH);
  power = false;
  digitalWrite(brakeLight,HIGH);
  digitalWrite(indicator, LOW);
}
