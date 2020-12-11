
const int stepPinSpind = 12; 
const int dirPinSpind = 13; 

const int stepPinWrap =9; 
const int dirPinWrap =8;

const int buttonPin = 2;
int buttonState = 0; 
const int buttonPin2 = 3;
int buttonState2 = 0; 
bool WrapDir;

int wrapCounter = 0;
int wrapStart = 0;
int spindCounter = 0;
int spindStart = 0;


bool wrapAction = false;
bool spindAction = false;

const int spindSpeed = 50;
const int wrapSpeed = 100;
 
int genCounter = 0;
bool wrapFlag;
bool spindFlag;
 
void setup() {


  pinMode(stepPinWrap,OUTPUT); 
  pinMode(dirPinWrap,OUTPUT);
  //Serial.begin(9600);
  pinMode(stepPinSpind,OUTPUT); 
  pinMode(dirPinSpind,OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {

  genCounter+=1;
  digitalWrite(dirPinSpind,LOW); 
  digitalWrite(dirPinWrap,HIGH);

    if (wrapAction == false) //Check if the wrap action is not in motion
    {
       buttonState = digitalRead(buttonPin); 
          if (buttonState == 1) //check for button input - set the wrap motion in action
        {
          wrapAction = true;
          wrapCounter = 0;
          wrapStart = genCounter;
        }
    }   
    else if(wrapAction==true && wrapCounter >600)
    {
      wrapCounter = 0;
      wrapAction = false;
    }


     if (wrapAction == true && (genCounter-wrapStart)%wrapSpeed==0)
    {   

      if (wrapFlag == true)
      {
        digitalWrite(stepPinWrap,HIGH);
        wrapFlag = false;
        wrapCounter+=1;
      }
      else if (wrapFlag == false)
      {
        digitalWrite(stepPinWrap,LOW);
        wrapFlag = true;
        wrapCounter+=1;
   }
      
     }
/////

    if (spindAction == false) //Check if the wrap action is not in motion
    {
          buttonState2 = digitalRead(buttonPin2); 
          if (buttonState2 == 1) //check for button input - set the wrap motion in action
        {
          Serial.print ("NOW");
          spindAction = true;
          spindCounter = 0;
          spindStart = genCounter;
        }
    }   
    else if(spindAction==true && spindCounter >600)
    {
      spindCounter = 0;
      spindAction = false;
    }

  Serial.print(spindAction);
       
     if (spindAction == true && (genCounter-spindStart)%spindSpeed==1)
    {   

      if (spindFlag == true)
      {
        //Serial.print("spindHIGH\n");
        digitalWrite(stepPinSpind,HIGH);
        spindFlag = false;
        spindCounter+=1;

      }
      else if (spindFlag == false)
      {
        //Serial.print("spindLow\n");
        digitalWrite(stepPinSpind,LOW);
        spindFlag = true;
        spindCounter+=1;
      }
    } 

    }
    
