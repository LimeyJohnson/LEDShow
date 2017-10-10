#include <FastLED/FastLED.h>
#define NUM_LEDS 200
#define DATA_PIN 12
CRGB leds[NUM_LEDS];
CRGB colors[7];
int count = 0;
int micPin = A0;


void setup() {
	FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
	colors[0] = CRGB::Red;
	colors[1] = CRGB::Orange;
	colors[2] = CRGB::Yellow;
	colors[3] = CRGB::Green;
	colors[4] = CRGB::Blue;
	colors[5] = CRGB::Indigo;
	colors[6] = CRGB::Purple;
	colors[7] = CRGB::Fuchsia;
	//  colors[8] = CRGB::Snow;

}
void blinkRainbow()
{
	for (int z = 0; z < 100; z++) leds[z] = CRGB::Black;
	FastLED.show();
	delay(70);
	//int r = random(0, 7);
	CRGB current = colors[count++ % 9];
	//for(int z = 0; z< NUM_LEDS; z++) leds[z] = colors[r];
	for (int z = 0; z < 100; z++) leds[z] = current;
	FastLED.show();
}
void blinkSolid()
{

	int r = random(0, 7);
	for (int y = 0; y < NUM_LEDS; y++)
	{
		leds[y] = colors[r];

	}
	FastLED.show();

	for (int z = 0; z < NUM_LEDS; z++) leds[z] = CRGB::Black;

	FastLED.show();

}
void fadedBlink()
{

	delay(70);

	CRGB current = leds[1];
	for (int y = 0; y < NUM_LEDS; y++)
	{
		leds[y] = CRGB::Red;

	}
	FastLED.show();
	for (int y = 0; y < 255; y++)
	{
		for (int x = 0; x < NUM_LEDS; x++)
		{



			leds[x] += CRGB(0, 0, 1);
			leds[x] -= CRGB(1, 0, 0);

		}
		FastLED.show();
		current = leds[1];
		for (int z = 0; z < NUM_LEDS; z++) leds[z] = CRGB::Black;

		FastLED.show();
		for (int z = 0; z < NUM_LEDS; z++) leds[z] = current;

		delay(120);
	}
	for (int y = 0; y < 255; y++)
	{
		for (int x = 0; x < NUM_LEDS; x++)
		{

			leds[x] -= CRGB(0, 0, 1);
			leds[x] += CRGB(1, 0, 0);

		}
		FastLED.show();
		current = leds[1];
		for (int z = 0; z < NUM_LEDS; z++) leds[z] = CRGB::Black;

		FastLED.show();
		for (int z = 0; z < NUM_LEDS; z++) leds[z] = current;
		delay(120);
	}
	for (int y = 0; y < 255; y++)
	{
		for (int x = 0; x < NUM_LEDS; x++)
		{

			leds[x] -= CRGB(0, 0, 1);
			leds[x] += CRGB(0, 1, 0);

		}
		FastLED.show();
		current = leds[1];
		for (int z = 0; z < NUM_LEDS; z++) leds[z] = CRGB::Black;

		FastLED.show();
		for (int z = 0; z < NUM_LEDS; z++) leds[z] = current;
		delay(120);
	}
}
void randomFull()
{

	int x = random(0, NUM_LEDS);
	int r = random(0, 7);

	leds[x] = colors[r];
	FastLED.show();


}
void randomSparkles()
{

	int x = random(0, NUM_LEDS);
	int r = random(0, 7);

	leds[x] = colors[r];
	FastLED.show();
	leds[x] = CRGB::Black;

}
int height = 20;
int width = 10;

void heights(int line, int size)
{
		int extra = line % 2 == 0 ? 0 : (height-size);
		int base = (line*height) + extra;
		int end = base + size;
		for (; base < end; base++) {
			leds[base] = CRGB::Red;
		}
}

void loop() {
	int wave[14] = { 18,17,15,10,5,3,2,2,3,5,10,15,17,18 };
	for (int x = 0; x < width; x++) {
		heights(x, wave[((count+x) % 14)]);
	}
	count++;
	delay(50);
	FastLED.show();
	for (int x = 0; x < NUM_LEDS; x++)leds[x] = CRGB::Black;

	//blinkSolid();
	//blinkRainbow();
	//fadedBlink();
	//randomSparkles();

	/*
	int x = count++;
	int distance = 97;
	if(count > distance) count = 0;
	while(x<NUM_LEDS)
	{
	/*
	if(x<96)
	leds[x] = CRGB::Green;
	else if(x<196)
	{
	leds[x] = CRGB::Blue;
	}

	else
	leds[x] = CRGB::Red;

	leds[x] = ColorFromPalette( myPal, x);
	x += distance;
	}
	FastLED.show();
	//delay(10);
	for(int y = 0; y<NUM_LEDS; y++) {leds[y] = CRGB::Black;}
	//delay(400);
	*/

}