#include <Esplora.h>
#include <Keyboard.h>

// 

boolean enabled = 0;
int sequence = 0;

void setup() {
  Keyboard.begin();
  randomSeed(analogRead(0));
}

void loop() {  
  boolean button = Esplora.readButton(SWITCH_RIGHT);
  if (button == PRESSED)
  {
    enabled = !enabled;
    Esplora.writeRGB(255, 255, 255);
    delay(1000);
  }
  Esplora.writeRGB(0, 0, 0);
  int slider = Esplora.readSlider();
  if (enabled)
  {
    if (sequence == 0)
    {    
      Keyboard.press('A');
      Keyboard.releaseAll();
      Esplora.writeRGB(255, 0, 0);
      sequence = 1;
    }
    else if (sequence == 1)
    {
      Keyboard.press('B');
      Keyboard.releaseAll();
      Esplora.writeRGB(255, 192, 0);
      sequence = 2;
    }
    else if (sequence == 2)
    {    
      Keyboard.press('C');
      Keyboard.releaseAll();
      Esplora.writeRGB(0, 255, 0);
      sequence = 3;
    }
    else if (sequence == 3)
    {    
      Keyboard.press('D');
      Keyboard.releaseAll();
      Esplora.writeRGB(0, 0, 255);
      sequence = 4;
    }
    else if (sequence == 4)
    {    
      Keyboard.press('E');
      Keyboard.releaseAll();
      Esplora.writeRGB(128, 0, 255);
      sequence = 0;
      delay(slider);
    }
  }
  delay(random(0, 500));
  delay(100 + slider * 4);
}
