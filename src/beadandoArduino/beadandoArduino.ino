#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define btn1 2  //bal
#define btn2 3  //jobb
#define btn3 4  //fel
#define btn4 5  //le
#define btn5 6  //reset
#define pot 0

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int x = 0;
int y = 0;
int size = 0;
int delay_ = 20;

void setup() {
  Serial.begin(115200);

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(pot, INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.display();
}

void loop() {
  //Rajzolás balra
  while (digitalRead(btn1) == HIGH) {
    x--;
    size=analogRead(pot)/128+1; //Pixelméret potméterrel (0-1023)/128+1 , így min=1, max=8
    drawPixelMatrix(size);
    display.display();
    delay(delay_);

  }
  //Rajzolás jobbra
  while (digitalRead(btn2) == HIGH) {
    x++;
    size=analogRead(pot)/128+1;
    drawPixelMatrix(size);
    display.display();
    delay(delay_);

  }
  //Rajzolás fel
  while (digitalRead(btn3) == HIGH) {
    y--;
    size=analogRead(pot)/128+1;
    drawPixelMatrix(size);
    display.display();
    delay(delay_);
  }
  //Rajzolás le
  while (digitalRead(btn4) == HIGH) {
    y++;
    size=analogRead(pot)/128+1; 
    drawPixelMatrix(size);
    display.display();
    delay(delay_);
  }
  //Reset
  if(digitalRead(btn5) == HIGH){
    display.clearDisplay();
    display.display();
    x=0;
    y=0;
  }
}
void drawPixelMatrix(int size) {
  // Ellenőrizzük a méretet, ne lépjük túl a kijelző határait
  if (x + size > SCREEN_WIDTH) {
    x = SCREEN_WIDTH - size;
  }
  else if(y + size > SCREEN_HEIGHT){
    y = SCREEN_HEIGHT - size;
  }
  else if(y < 0){
    y = 0;
  }
  else if(x < 0){
    x = 0;
  }

  // Végigmegyünk a mátrixon és beállítjuk a pixel értékeket
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      display.drawPixel(x + i, y + j, WHITE);
    }
  }
}