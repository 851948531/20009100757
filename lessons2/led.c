// C++ code
//

int SER1   = 12;
int RCLK1  = 11;
int SRCLK1 = 10;

int SER2   = 7;
int RCLK2  = 6;
int SRCLK2 = 5;

//ledÎ»Âë
unsigned char wei[]={
  0x00, //È«ÁÁ
  0xfe, //led1
  0xfd, //led2
  0xfb,
  0xf7,
  0xef,
  0xdf,
  0xbf,
  0x7f,
  0x7f,
  0xbf,
  0xdf,
  0xef,
  0xf7,
  0xfb,
  0xfd,
  0xfe, //led16
  0xff  //È«Ãð
};

void Hc595SendByte_1(unsigned char dat){
  char i;
  digitalWrite(RCLK1, LOW);
  digitalWrite(SRCLK1, LOW);

  for(i = 0; i < 8; i++){
    
    digitalWrite(SER1, dat>>7);
	dat <<= 1;

	digitalWrite(SRCLK1, HIGH);
	delayMicroseconds(3);
	digitalWrite(SRCLK1, LOW);
  }

	digitalWrite(RCLK1, HIGH);
	delayMicroseconds(3);
	digitalWrite(RCLK1, LOW);
}

void Hc595SendByte_2(unsigned char dat){
  char i;
  digitalWrite(RCLK2, LOW);
  digitalWrite(SRCLK2, LOW);

  for(i = 0; i < 8; i++){
    digitalWrite(SER2, dat>>7);
	dat <<= 1;

	digitalWrite(SRCLK2, HIGH);
	delayMicroseconds(3);
	digitalWrite(SRCLK2, LOW);
  }

	digitalWrite(RCLK2, HIGH);
	delayMicroseconds(3);
	digitalWrite(RCLK2, LOW);
}


void setup()
{
  pinMode(SER1, OUTPUT);
  pinMode(RCLK1, OUTPUT);
  pinMode(SRCLK1, OUTPUT);
  
  pinMode(SER2, OUTPUT);
  pinMode(RCLK2, OUTPUT);
  pinMode(SRCLK2, OUTPUT);
  
  Hc595SendByte_1(wei[17]);
  Hc595SendByte_2(wei[17]);
}


void loop()
{
  int i;
  for(i=1;i<=16;i++)
  {
    if(i>=9){
      Hc595SendByte_2(wei[i]);
      Hc595SendByte_1(wei[17]);
    }else{
      Hc595SendByte_1(wei[i]);
      Hc595SendByte_2(wei[17]);
    }
    delay(80);
  }
  
  Hc595SendByte_1(wei[0]);
  Hc595SendByte_2(wei[0]);
  delay(520);
  
  Hc595SendByte_1(wei[17]);
  Hc595SendByte_2(wei[17]);
}


