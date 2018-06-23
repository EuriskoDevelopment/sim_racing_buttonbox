#include <ProTrinketKeyboardC.h>
#include <ProTrinketKeyboard.h>
#include <usbconfig.h>
#include <cmdline_defs.h>

#include <Boards.h>
#include <Firmata.h>

// Define input pin numbers on Arduino
#define ENCODER_L_A 9   // Blue wire. CLK on rotary encoder
#define ENCODER_R_A 12  // Blue wire. CLK on rotary encoder
#define ENCODER_L_B 10  // orange wire. DT on rotary encoder
#define ENCODER_R_B 11  // orange wire. DT on rotary encoder
#define BUTTON_R 3      // SW on rotary encoder
#define BUTTON_L 4      // SW on rotary encoder

// Define LED output useful for debugging
#define LED_BASE 13

int buttonState_R = 0;
int buttonState_L = 0;
int lastState_L_A = LOW;
int lastState_R_A = LOW;

// the setup you press reset or power the board
void setup() {
  pinMode(LED_BASE, OUTPUT);
  pinMode(BUTTON_R, INPUT_PULLUP);
  pinMode(BUTTON_L, INPUT_PULLUP);
  pinMode(ENCODER_R_A, INPUT);
  pinMode(ENCODER_R_B, INPUT);
  pinMode(ENCODER_L_A, INPUT);
  pinMode(ENCODER_L_B, INPUT);

  TrinketKeyboard.begin();
}

void loop() {
   TrinketKeyboard.poll();
   
   buttonState_R = checkButton(KEYCODE_A, BUTTON_R, buttonState_R);
   buttonState_L = checkButton(KEYCODE_S, BUTTON_L, buttonState_L);
   
   lastState_R_A = checkRotaryEncoder(ENCODER_R_A, ENCODER_R_B, lastState_R_A, 
      KEYCODE_Z, KEYCODE_X); 
   lastState_L_A = checkRotaryEncoder(ENCODER_L_A, ENCODER_L_B, lastState_L_A,
      KEYCODE_C, KEYCODE_V);
   
}

int checkButton(int keycode, int button, int lastState)
{
  // Pullup button. First read input and write keyco,de to keyboard
  int buttonState = digitalRead(button);
  if (buttonState != lastState)
  {
    if (buttonState == LOW)
    {
      digitalWrite(LED_BASE, LOW);
      TrinketKeyboard.pressKey(0, keycode);
      delay(5);
      TrinketKeyboard.pressKey(0, 0);
     }
  }
  return buttonState;
}

int checkRotaryEncoder(int encoder_a, int encoder_b,
   int lastStateA, int keycode_right, int keycode_left)
{
   int stateA = digitalRead(encoder_a);
   if (lastStateA != stateA)
   {
     if (lastStateA == LOW)
     { 
     int stateB = digitalRead(encoder_b);
     if (stateB != stateA)
       {
       TrinketKeyboard.pressKey(0, keycode_right);
       delay(5);
       TrinketKeyboard.pressKey(0, 0);      
     }
     else
     {
       TrinketKeyboard.pressKey(0, keycode_left);
       delay(5);
       TrinketKeyboard.pressKey(0, 0);
     }
     }
   lastStateA = stateA;
   }
}
     

