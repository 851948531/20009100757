// C++ code

int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;
int rec = 0; //接收数据

void SMG_display(int num);


void setup()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  if(Serial.available())
    rec = Serial.read();
  
  SMG_display(rec);
  
  delay(500);
}


void SMG_display(int num)
{
  switch(num){
    case '0':
    	digitalWrite(pin1,LOW);
        digitalWrite(pin2,LOW);
        digitalWrite(pin3,LOW);
        digitalWrite(pin4,LOW);
    	break;
    case '1':
    	digitalWrite(pin1,HIGH);
        digitalWrite(pin2,LOW);
        digitalWrite(pin3,LOW);
        digitalWrite(pin4,LOW);
    	break;  
    case '2':
    	digitalWrite(pin1,LOW);
        digitalWrite(pin2,HIGH);
        digitalWrite(pin3,LOW);
        digitalWrite(pin4,LOW);
    	break;    
    case '3':
    	digitalWrite(pin1,HIGH);
        digitalWrite(pin2,HIGH);
        digitalWrite(pin3,LOW);
        digitalWrite(pin4,LOW);
    	break;  
    case '4':
    	digitalWrite(pin1,LOW);
        digitalWrite(pin2,LOW);
        digitalWrite(pin3,HIGH);
        digitalWrite(pin4,LOW);
    	break;  
    case '5':
    	digitalWrite(pin1,HIGH);
        digitalWrite(pin2,LOW);
        digitalWrite(pin3,HIGH);
        digitalWrite(pin4,LOW);
    	break;    
    
    case '6':
    	digitalWrite(pin1,LOW);
        digitalWrite(pin2,HIGH);
        digitalWrite(pin3,HIGH);
        digitalWrite(pin4,LOW);
    	break;    
    case '7':
    	digitalWrite(pin1,HIGH);
        digitalWrite(pin2,HIGH);
        digitalWrite(pin3,HIGH);
        digitalWrite(pin4,LOW);
    	break;    
    case '8':
    	digitalWrite(pin1,LOW);
        digitalWrite(pin2,LOW);
        digitalWrite(pin3,LOW);
        digitalWrite(pin4,HIGH);
    	break;    
    case '9':
    	digitalWrite(pin1,HIGH);
        digitalWrite(pin2,LOW);
        digitalWrite(pin3,LOW);
        digitalWrite(pin4,HIGH);
    	break; 
    
    default:
    	return; 
  }
  
}


