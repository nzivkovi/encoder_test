#include "Encoder.h"

unsigned int cpr = 930;
double last_angle_left = 0.0;
double last_angle_right = 0.0;

Encoder* enc_left = new Encoder(2, 3, cpr);
Encoder* enc_right = new Encoder(18, 19, cpr);

void enc_left_A()
{
  enc_left->A_interrupt();
}

void enc_left_B()
{
  enc_left->B_interrupt();
}

void enc_right_A()
{
  enc_right->A_interrupt();
}

void enc_right_B()
{
  enc_right->B_interrupt();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(enc_left->pinA), enc_left_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(enc_left->pinB), enc_left_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(enc_right->pinA), enc_right_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(enc_right->pinB), enc_right_B, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(enc_left->count != last_angle_left)
  {
    Serial.println(enc_left->count);
    last_angle_left = enc_left->count;
  }
  if(enc_right->count != last_angle_right)
  {
    Serial.println(enc_right->count);
    last_angle_right = enc_right->count;
  }
  
}
