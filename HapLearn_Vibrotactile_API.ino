int volt1=0;
int volt2=0;
int volti=0;

long timenow;
String  inString = ""; 
char inChar;
int first=1;
char fchar;
int val;
int ONnOFF=0;

long delayer1=1500;
long dura1=100;
long duraSweep=10;
int repeateri=1;

long delayerf=0;
long duraf=0;
long duraSweepF=100;
int repeaterF=0;

int lra = 9;
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(lra,OUTPUT);
}


void loop() {
  timenow=millis();
  
  while (Serial.available() > 0) 
    {    
      int onoff = Serial.parseInt(); 
      int inten1 = Serial.parseInt(); 
      int inten2 = Serial.parseInt(); 
      int sweeptime = Serial.parseInt(); 
      int repeatp = Serial.parseInt();
      int pulsee = Serial.parseInt();
      int delayy = Serial.parseInt(); 
     
      if (Serial.read() == '\n') {
           Serial.print("Test");
            volt1=inten1;
            volt2=inten2;
            volti=inten1;
            repeaterF=repeatp;
            repeateri=repeatp;
            duraSweep=sweeptime;
            dura1=pulsee;
            delayer1=delayy;
            ONnOFF=onoff;
            Serial.print(ONnOFF);
            Serial.print(" ");
            Serial.print(volt1);
            Serial.print(" ");
            Serial.print(volt2);
            Serial.print(" ");
            Serial.print(sweeptime);
            Serial.print(" ");
            Serial.print(repeatp);
            Serial.print(" ");
            Serial.print(pulsee);
            Serial.print(" ");
            Serial.print(delayer1);
        }
        else{ }
      }
      
if (ONnOFF==2)
  {
    digitalWrite(lra,HIGH);
    digitalWrite(led,HIGH);
  }
else if (ONnOFF==0)
  {
    digitalWrite(led,LOW);
    digitalWrite(lra,LOW);
  }
else
  {
    if (timenow<=duraf){
      analogWrite(lra,volt1);
      analogWrite(led,volt1);
      if (timenow>=duraSweepF){
       duraSweepF=timenow+duraSweep;
       if (volt1>volt2)
        volt1=volt1-1;
       else if (volt1<volt2)
        volt1=volt1+1;
       else {
        repeaterF= repeaterF - 1;
         if (repeaterF>0) {
          volt1=volti;
         }
       }
      }

    }  
    else if ((timenow>duraf)&&(timenow<=delayerf))
    {
      digitalWrite(lra,LOW);
      analogWrite(led,0);
      volt1=volti;
    }
    else
    {
      duraf=dura1+timenow;
      delayerf=delayer1+dura1+timenow;
      repeaterF = repeateri;
    }
  } 
}
