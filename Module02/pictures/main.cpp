#include <M5StickC.h>   // Include M5StickC library
#include <FastLED.h>    // Include FastLED library

#define NUM_LEDS 12
#define LED_PIN 26   // M5StickC GPIO26 for LED control
#define BOMB_TIMER 5000   // Initial bomb timer in milliseconds

struct Bomb {
  int pos;
  unsigned long startTime;
  int duration;
};

CRGB leds[NUM_LEDS];
Bomb bomb;
int score = 0;
int playerPos = 0;
int wallPos = 0;

void startGame();
void movePlayer(int direction);
void moveBomb();
void moveWall();
int getDistance(int p1, int p2);
CRGB getBombColor(int timeLeft);
void gameOver(int pos);
void setLed(int index, CRGB color);

void setup() {
    M5.begin();         
    M5.Lcd.begin();  
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("Bomb Defuse Game");

    Serial.begin(115200);
    random16_add_entropy(analogRead(0));

    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(160);
    
    startGame();
}

void loop() {
    M5.update();   // Update button state
    fill_solid(leds, NUM_LEDS, CRGB::Black);

    if (M5.BtnA.wasPressed()) movePlayer(-1);  // Move left
    if (M5.BtnB.wasPressed()) movePlayer(1);   // Move right

    unsigned long currentTime = millis();
    int bombTimeLeft = bomb.duration - (currentTime - bomb.startTime);

    if (bombTimeLeft <= 0) {
        gameOver(bomb.pos);
    } else if (playerPos == bomb.pos) {
        score++;
        moveBomb();
        moveWall();
    } else if (playerPos == wallPos) {
        gameOver(wallPos);
    }

    // Render elements
    setLed(playerPos, CRGB::Blue);  // Player color
    setLed(wallPos, CRGB::Red);     // Wall color
    setLed(bomb.pos, getBombColor(bombTimeLeft));

    // Display score on M5StickC
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.printf("Score: %d", score);
    
    FastLED.show();
    delay(100);
}

void startGame() {
    bomb = Bomb();
    score = 0;
    playerPos = 0;

    moveBomb();
    moveWall();
}

void movePlayer(int direction) {
    playerPos = (playerPos + direction + NUM_LEDS) % NUM_LEDS;
}

void moveBomb() {
    do {
        bomb.pos = random16(NUM_LEDS);
    } while (bomb.pos == playerPos);

    bomb.startTime = millis();
    bomb.duration = max(1500, BOMB_TIMER - (score * 100));
}

void moveWall() {
    do {
        wallPos = random16(NUM_LEDS);
    } while (getDistance(wallPos, bomb.pos) < 2 || getDistance(wallPos, playerPos) < 2);
}

int getDistance(int p1, int p2) {
    int distance = abs(p2 - p1);
    return min(distance, NUM_LEDS - distance);
}

CRGB getBombColor(int timeLeft) {
    int brightness = map(timeLeft, bomb.duration, 0, 0, 255);
    if (timeLeft < 1000) {
        brightness = beatsin8(240, 0, 255);
    }
    return CRGB(brightness, brightness, 0);
}

void gameOver(int pos) {
    M5.Lcd.fillScreen(RED);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("Game Over!");

    for (int i = 0; i < NUM_LEDS; i++) {
        setLed(pos - i, CRGB::Red);
        setLed(pos + i, CRGB::Red);
        FastLED.show();
        delay(30);
    }
    delay(500);

    for (int i = 255; i >= 0; i--) {
        fill_solid(leds, NUM_LEDS, CRGB(i, 0, 0));
        FastLED.show();
        delay(4);
    }

    delay(1000);
    startGame();
}

void setLed(int index, CRGB color) {
    if (index >= 0 && index < NUM_LEDS) {
        leds[index] = color;
    }
}
