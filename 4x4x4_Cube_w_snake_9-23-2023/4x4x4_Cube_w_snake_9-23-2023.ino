#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <Adafruit_MCP23X17.h>
#include "Adafruit_TLC5947.h"
#include <SPI.h>
// How many boards do you have chained?
#define NUM_TLC5947 2
#define data   4
#define clock   5
#define latch   2//6
#define oe  -1  // set to -1 to not use the enable pin (its optional)

#define NUM_COL_CUBED 4
#define LAYER_0 0   // MCP23XXX pin used for layer
#define LAYER_1 1   // MCP23XXX pin used for layer
#define LAYER_2 2   // MCP23XXX pin used for layer
#define LAYER_3 3   // MCP23XXX pin used for layer
#define ADDR_3 0x24
#define ALL_LAYERS 0
#define L1_L2_L3 1
#define L0_L2_L3 2
#define L2_L3 3
#define L0_L1_L3 4
#define L1_L3 5
#define L0_L3 6
#define L3 7
#define L0_L1_L2 8
#define L1_L2 9
#define L0_L2 10
#define L2 11
#define L0_L1 12
#define L1 13
#define L0 14
#define NO_LAYERS 15

#define TFT_CS_1        0
#define TFT_RST_1        -1 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC_1         17
#define TFT_CS_2        15
#define TFT_RST_2        -1 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC_2         17

#define LEFT_BUTTON 0   // MCP23XXX pin used for interrupt
#define UP_BUTTON 1   // MCP23XXX pin used for interrupt
#define DOWN_BUTTON 2   // MCP23XXX pin used for interrupt
#define RIGHT_BUTTON 3   // MCP23XXX pin used for interrupt
#define A_BUTTON 4   // MCP23XXX pin used for interrupt
#define B_BUTTON 5   // MCP23XXX pin used for interrupt

#define LEFT_MASK 0x01
#define UP_MASK 0x02
#define DOWN_MASK 0x04
#define RIGHT_MASK 0x08
#define A_MASK 0x10
#define B_MASK 0x20

#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3
#define UP 4
#define DOWN 5
#define INIT_SNAKE_COUNTER 1000
#define MIN_SNAKE_COUNTER 250
#define SPEED_INCREASE 25
#define MAX_SNAKE_LENGTH 75
#define GREEN 0
#define RED 1

#define ADDR_1 0x20
#define ADDR_2 0x21

#define INT_1_PIN 35      // microcontroller pin attached to INTA/B
#define INT_2_PIN 34      // microcontroller pin attached to INTA/B

// OPTION 1 (recommended) is to use the HARDWARE SPI pins, which are unique
// to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// SCLK = pin 13. This is the fastest mode of operation and is required if
// using the breakout board's microSD card.

Adafruit_ST7789 tft_1 = Adafruit_ST7789(TFT_CS_1, TFT_DC_1, TFT_RST_1);
// Adafruit_ST7789 tft_2 = Adafruit_ST7789(TFT_CS_2, TFT_DC_2, TFT_RST_2);

Adafruit_MCP23X17 mcp_1;
// Adafruit_MCP23X17 mcp_2;

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);
Adafruit_MCP23X17 mcp_3;

struct ledObject {
  uint16_t r;
  uint16_t g;
  uint16_t b;
};

ledObject cube[NUM_COL_CUBED][NUM_COL_CUBED][NUM_COL_CUBED];

struct snakeObject {
  int x;
  int y;
  int z;
  int dir;
};

struct appleObject {
  int x2;
  int y2;
  int z2;
};

snakeObject snake = {0, 0, 0, RIGHT};
snakeObject tail[MAX_SNAKE_LENGTH];
int s_length = 0;
int s_speed = 1;
appleObject apple = {0, 0, 0};
volatile bool initSnake = true;
volatile bool playingSnake = false;
volatile int maxSnakeCounter = INIT_SNAKE_COUNTER;
volatile int snakeMovementCounter = 0;
volatile int randomCounter = 0;
volatile int appleBlinkCounter = 0;
volatile int lastButtonPressed = 8;
volatile uint8_t p1_score = 0;

void setup(void) {
  Serial.begin(9600);

  tlc.begin();
  if (oe >= 0) {
    pinMode(oe, OUTPUT);
    digitalWrite(oe, LOW);
  }
  
  if (!mcp_3.begin_I2C(ADDR_3)) {
  //if (!mcp.begin_SPI(CS_PIN)) {
    Serial.println("Error. with mcp");
    while (1);
  }

  // configure button pin for input with pull up
  mcp_3.pinMode(LAYER_0, OUTPUT);
  mcp_3.pinMode(LAYER_1, OUTPUT);
  mcp_3.pinMode(LAYER_2, OUTPUT);
  mcp_3.pinMode(LAYER_3, OUTPUT);

  Serial.println(F("Hello! ST77xx TFT Test"));
  // use this initializer (uncomment) if using a 2.0" 320x240 TFT:
  tft_1.init(240, 320);           // Init ST7789 320x240
  Serial.println("tft init successful");
  // tft_2.init(240, 320);
  // tft_1.setRotation(1);
  // tft_2.setRotation(1);

  // SPI speed defaults to SPI_DEFAULT_FREQ defined in the library, you can override it here
  // Note that speed allowable depends on chip and quality of wiring, if you go too fast, you
  // may end up with a black screen some times, or all the time.
  //tft.setSPISpeed(40000000);
  Serial.println(F("Initialized"));

  tft_1.fillScreen(ST77XX_GREEN);
  // tft_2.fillScreen(ST77XX_BLUE);
  // delay(1000);
  // updateScore(0, 0, 0, 0, &tft_1);
  // updateScore(0, 0, 0, 0, &tft_2);
  
  if (!mcp_1.begin_I2C(ADDR_1)) {
  //if (!mcp.begin_SPI(CS_PIN)) {
    Serial.println("Error. with mcp_1");
    while (1);
  }// uncomment appropriate mcp.begin
  // if (!mcp_2.begin_I2C(ADDR_2)) {
  // //if (!mcp.begin_SPI(CS_PIN)) {
  //   Serial.println("Error. with mcp_2");
  //   while (1);
  // }
  // configure MCU pin that will read INTA/B state
  pinMode(INT_1_PIN, INPUT);
  // pinMode(INT_2_PIN, INPUT);
  // mirror INTA/B so only one wire required
  // active drive so INTA/B will not be floating
  // INTA/B will be signaled with a LOW
  mcp_1.setupInterrupts(true, false, LOW);
  // mcp_2.setupInterrupts(true, false, LOW);

  // configure button pin for input with pull up
  mcp_1.pinMode(LEFT_BUTTON, INPUT_PULLUP);
  mcp_1.pinMode(UP_BUTTON, INPUT_PULLUP);
  mcp_1.pinMode(DOWN_BUTTON, INPUT_PULLUP);
  mcp_1.pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  mcp_1.pinMode(A_BUTTON, INPUT_PULLUP);
  mcp_1.pinMode(B_BUTTON, INPUT_PULLUP);
  
  // configure button pin for input with pull up
  // mcp_2.pinMode(LEFT_BUTTON, INPUT_PULLUP);
  // mcp_2.pinMode(UP_BUTTON, INPUT_PULLUP);
  // mcp_2.pinMode(DOWN_BUTTON, INPUT_PULLUP);
  // mcp_2.pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  // mcp_2.pinMode(A_BUTTON, INPUT_PULLUP);
  // mcp_2.pinMode(B_BUTTON, INPUT_PULLUP);

  // enable interrupt on button_pin
  mcp_1.setupInterruptPin(LEFT_BUTTON, CHANGE);
  mcp_1.setupInterruptPin(UP_BUTTON, CHANGE);
  mcp_1.setupInterruptPin(DOWN_BUTTON, CHANGE);
  mcp_1.setupInterruptPin(RIGHT_BUTTON, CHANGE);
  mcp_1.setupInterruptPin(A_BUTTON, CHANGE);
  mcp_1.setupInterruptPin(B_BUTTON, CHANGE);
  
  // mcp_2.setupInterruptPin(LEFT_BUTTON, CHANGE);
  // mcp_2.setupInterruptPin(UP_BUTTON, CHANGE);

  // upDown(4095, 0, 0, 100); // "Red" (depending on your LED wiring)
  // upDown(0, 4095, 0, 100); // "Green" (depending on your LED wiring)
  // upDown(0, 0, 4095, 100); // "Blue" (depending on your LED wiring)

  // rightLeft(4095, 0, 0, 100); // "Red" (depending on your LED wiring)
  // rightLeft(0, 4095, 0, 100); // "Green" (depending on your LED wiring)
  // rightLeft(0, 0, 4095, 100); // "Blue" (depending on your LED wiring)

  // backForth(4095, 0, 0, 100); // "Red" (depending on your LED wiring)
  // backForth(0, 4095, 0, 100); // "Green" (depending on your LED wiring)
  // backForth(0, 0, 4095, 100); // "Blue" (depending on your LED wiring)

  updateScore(p1_score, 0, 0, 0, &tft_1);
  mcp_3.digitalWrite(0, HIGH);
  mcp_3.digitalWrite(1, HIGH);
  mcp_3.digitalWrite(2, LOW);
  mcp_3.digitalWrite(3, HIGH);
  tlc.setLED(6, 255,255,255);
  tlc.write();
  delay(1000);
  clearCube();
  setLED(3,1,2,0,255,0);
  setLED(2,2,3,255,0,0);
  setLED(1,3,1,0,0,255);
  setLED(0,0,0,255,255,255);
  lightCube();
}

void loop() {
  renderCube();
  // if (initSnake) 
  // {
  //   initSnake = false;
  //   // Get rid of tail
  //   s_length = 0;
  //   // Set snake speed
  //   maxSnakeCounter = INIT_SNAKE_COUNTER;
  //   // Clear the cube
  //   clearCube();
  //   //Initial direction is RIGHT
  //   snake.dir = RIGHT;
  //   // Set random starting LED for snake
  //   snake.x = randomCounter % random(0,7);
  //   if (snake.x > 7) {snake.x = random(0,7);}
  //   randomCounter++;
  //   snake.y = randomCounter % random(0,7);
  //   if (snake.y > 7) {snake.y = random(0,7);}
  //   randomCounter++;
  //   snake.z = randomCounter % random(0,7);
  //   if (snake.z > 7) {snake.z = random(0,7);}
  //   // Set random LED for apple
  //   genNewApple();
  // }
  // updateApple();
  // if (digitalRead(INT_1_PIN) == LOW) {
  //   checkButtons(&mcp_1);
  // }
  // // if (digitalRead(INT_2_PIN) == LOW) {
  // //   checkButtons(&mcp_2);
  // // }  
  // updateSnake();
}