#include <M5StickC.h>  // Include M5StickC library
#include <FastLED.h>    // Include FastLED library

#define NUM_LEDS 10         // Adjust based on your LED strip length
#define LED_PIN 26          // Pin where LEDs are connected on M5StickC

CRGB leds[NUM_LEDS];        // LED array

int playerPos = 0;
int bombPos = NUM_LEDS / 2;
int wallPos = NUM_LEDS - 1;
int bombTimeLeft = 5;       // Countdown for bomb explosion

void startGame();
void movePlayer(int direction);
void moveBomb();
void moveWall();
void renderGame();

void setup() {
    M5.begin();             // Initialize M5StickC
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.clear();
    FastLED.show();
    
    Serial.begin(115200);   // Start serial monitor

    startGame();
}

void loop() {
    M5.update();  // Update button states

    // Move player with button presses
    if (M5.BtnA.wasPressed()) movePlayer(-1);  // Move left
    if (M5.BtnB.wasPressed()) movePlayer(1);   // Move right

    if (bombTimeLeft > 0) {
        moveBomb();
        moveWall();
        bombTimeLeft--;
    }

    renderGame();
}

void startGame() {
    playerPos = 0;
    bombPos = NUM_LEDS / 2;
    wallPos = NUM_LEDS - 1;
    bombTimeLeft = 5;
}

void movePlayer(int direction) {
    int newPos = playerPos + direction;
    if (newPos >= 0 && newPos < NUM_LEDS) {
        playerPos = newPos;
    }
}

void moveBomb() {
    if (bombTimeLeft == 0) return;
    bombPos--;
    if (bombPos < 0) bombPos = NUM_LEDS - 1;
}

void moveWall() {
    wallPos--;
    if (wallPos < 0) wallPos = NUM_LEDS - 1;
}

void renderGame() {
    FastLED.clear();
    
    leds[playerPos] = CRGB::Blue;     // Player color
    leds[bombPos] = CRGB::Red;        // Bomb color
    leds[wallPos] = CRGB::Green;      // Wall color
    
    FastLED.show();
}

