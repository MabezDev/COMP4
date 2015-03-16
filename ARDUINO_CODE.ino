int input;
int inputPin = A5;
long startTime;
long endTime;
boolean Done;
int i;
int FinalTime;
boolean sent;
int IN1 = A1;
int IN2 = A2;
int IN3 = A3;
int IN4 = A4;

//working

String Commands="";


void setup(){
 pinMode(inputPin,INPUT);
 Serial.begin(9600);
 Serial.println("READY");
}

void loop(){
 CaptureSingle();
 
 
 
}


void CaptureSingle(){

input = digitalRead(inputPin);
if(input==1){
   startTime = millis();
   Done = false;
   i=0;
   while(Done==false){
     while(input==1){
       input = digitalRead(inputPin);
     }
     delay(50);
     i +=1;
     input = digitalRead(inputPin);
     if(input==1){
       //nothing
     } else {
      endTime = (millis() - startTime);
      FinalTime = endTime + (i*50);
      Serial.println(FinalTime);
      //Serial.println(FinalTime);
      if(FinalTime < 1100 && FinalTime >900){
        Serial.write("s");
        Commands="";//start new
      }
      if(FinalTime < 7100 && FinalTime >6900){
        Serial.write("e");
        Go();
      }
      if(FinalTime < 3005 && FinalTime >2095){
        Serial.write("r");
        Commands+="r";
        
      }
      
      
      if(FinalTime < 2100 && FinalTime >1900){
        Serial.write("f");
        Commands+="f";
        
      }
      if(FinalTime < 4005 && FinalTime >3095){
        Serial.write("l");
        Commands+="l";
        
      }
      Done = true;
     //return Command; 
     }
   }
 } 
}

void Go(){
    Serial.println("In Go");
    char temp[Commands.length()];
    Commands.toCharArray(temp,Commands.length());
    for(int i =0;i<Commands.length();i++){
      char t = Commands[i];
      Serial.println("Char:"+t);
      if(t=='f'){
      goForward();
    }
    if(t=='r'){
      goRight();
    }
    if(t=='l'){
      goLeft();
   }
    }
    
 
}

void goLeft(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,HIGH);
  delay(1000);
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
}

void goRight(){
  digitalWrite(IN2,HIGH);
  digitalWrite(IN4,HIGH);
  delay(1000);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
}

void goForward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  delay(1000);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}

