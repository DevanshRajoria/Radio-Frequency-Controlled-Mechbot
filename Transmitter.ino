#include<VirtualWire.h>

int forward = 4;
int backward = 5;
int moveLeft = 6;
int moveRight = 7;

void setup()
{
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3
    pinMode(forward,INPUT);
    digitalWrite(forward,LOW);
    pinMode(backward,INPUT);
    digitalWrite(backward,LOW);
    pinMode(moveLeft,INPUT);
    digitalWrite(moveLeft,LOW);
    pinMode(moveRight,INPUT);
    digitalWrite(moveRight,LOW);

}//close setup

void loop()
{
  char *msg2;
  
  if(digitalRead(forward) == HIGH)//if the forward button is pressed
  {
    Serial.println("aage badh");    
    char *msg2 = "1";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  if(digitalRead(backward) == HIGH)//if the forward button is pressed
  { 
    Serial.println("peeche ho le");    
    char *msg2 = "2";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }

  if(digitalRead(moveLeft) == HIGH)//if the forward button is pressed
  { 
    Serial.println("ghoom left");    
    char *msg2 = "3";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
    if(digitalRead(moveRight) == HIGH)//if the forward button is pressed
  { 
    Serial.println("ghoom right");    
    char *msg2 = "4";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
}
