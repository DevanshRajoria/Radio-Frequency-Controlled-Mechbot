#include <VirtualWire.h>

int leftmotorforward =27;
int leftmotorbackward=26;
int rightmotorforward=28;
int rightmotorbackward=29;
void setup()
{
Serial.begin(9600); // Debugging only
Serial.println("setup");
pinMode(13,OUTPUT);
pinMode(leftmotorforward,OUTPUT);
pinMode(leftmotorbackward,OUTPUT);
pinMode(rightmotorforward,OUTPUT);
pinMode(rightmotorbackward,OUTPUT);
vw_set_rx_pin(2);
// Initialise the IO and ISR
vw_setup(2000); // Bits per sec
vw_rx_start(); // Start the receiver PLL running
}
void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;

        digitalWrite(13, true); // Flash a light to show received good message
  for (i = 0; i < buflen; i++)
  {
   Serial.print(buf[i]);//print received command
        if(buf[i] == '1')//if button 1 is pressed.... i.e.forward buton
      {
        forward();//go forward
        Serial.println(" = forward");
      }
        if(buf[i] == '2'){
          backward();
          Serial.println(" = backward");
        }
        if(buf[i] == '3'){
          moveLeft();
          Serial.println(" = move Left");
        }
        if(buf[i] == '4'){
          moveRight();
          Serial.println(" = moveRight");
        }
  }
  Serial.println("");
        digitalWrite(13, false);

   }//close if
}//close loop
void forward()
{
  digitalWrite(leftmotorforward,1);
  digitalWrite(leftmotorbackward,0);
  digitalWrite(rightmotorforward,1);
  digitalWrite(rightmotorbackward,0);
  delay(500);
 digitalWrite(leftmotorforward,0);
  digitalWrite(leftmotorbackward,0);
  digitalWrite(rightmotorforward,0);
  digitalWrite(rightmotorbackward,0); 
}
void backward(){
  digitalWrite(leftmotorforward,0);
  digitalWrite(leftmotorbackward,1);
  digitalWrite(rightmotorforward,0);
  digitalWrite(rightmotorbackward,1);
   delay(500);
 digitalWrite(leftmotorforward,0);
  digitalWrite(leftmotorbackward,0);
  digitalWrite(rightmotorforward,0);
  digitalWrite(rightmotorbackward,0);
} 

void moveLeft()
{
  digitalWrite(leftmotorforward,0);
  digitalWrite(leftmotorbackward,1);
  digitalWrite(rightmotorforward,1);
  digitalWrite(rightmotorbackward,0);
   delay(500);
 digitalWrite(leftmotorforward,0);
  digitalWrite(leftmotorbackward,0);
  digitalWrite(rightmotorforward,0);
  digitalWrite(rightmotorbackward,0);
}
void moveRight()
{
  digitalWrite(leftmotorforward,1);
  digitalWrite(leftmotorbackward,0);
  digitalWrite(rightmotorforward,0);
  digitalWrite(rightmotorbackward,1);
   delay(500);
 digitalWrite(leftmotorforward,0);
  digitalWrite(leftmotorbackward,0);
  digitalWrite(rightmotorforward,0);
  digitalWrite(rightmotorbackward,0);
}
