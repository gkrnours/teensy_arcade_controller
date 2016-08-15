#include <Bounce2.h>

/* Pushbutton with Pullup, Teensyduino Tutorial #3
   http://www.pjrc.com/teensy/tutorial3.html

   This example code is in the public domain.
*/

struct tbutton {
  byte  pin;
  int  key;
  Bounce debouncer;
};

const int ledPin = 13;
struct tbutton btns[] = {
  {0, KEY_UP_ARROW,   Bounce()},    // up
  {1, KEY_RIGHT_ARROW, Bounce()}, // right
  {2, KEY_DOWN_ARROW, Bounce()},  // down
  {3, KEY_LEFT_ARROW, Bounce()},  // left
  {4, KEY_X, Bounce()},   // A
  {5, KEY_Z, Bounce()},   // B
  {6, KEY_S, Bounce()},   // X
  {7, KEY_A, Bounce()},   // Y
  {8, KEY_Q, Bounce()},   // L
  {9, KEY_W, Bounce()},   // R
  {10, KEY_RETURN, Bounce()},      // start
  {11, KEY_RIGHT_SHIFT, Bounce()}, // select
  {0, (char)0, Bounce()}, // End of array
};

void setup() {
  struct tbutton *btn;

  for (btn = btns; btn->key; ++btn) {
    pinMode(btn->pin, INPUT_PULLUP);
    btn->debouncer.attach(btn->pin);
    btn->debouncer.interval(5);
  }
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  struct tbutton *btn;

  for (btn = btns; btn->key; ++btn) {
    
    if (btn->debouncer.update()) {
      
      if (btn->debouncer.fell()) {
        Keyboard.press(btn->key);
        digitalWrite(ledPin, HIGH);
        
      } else if (btn->debouncer.rose()) {
        Keyboard.release(btn->key); \
        digitalWrite(ledPin, LOW);
      }
    }
    
  }
}

