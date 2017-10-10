#include <FHT.h>
int micPin = A4;
int max = 0;
int min = 1024;
const int buttonPin = 7;
int buttonState = 0;
void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(buttonPin, INPUT);
}

void loop() {
	// put your main code here, to run repeatedly:
	int analogValue = analogRead(micPin);
	Serial.print("Mic Pin: ");
	Serial.print(analogValue);
	if (analogValue > max) max = analogValue;
	if (analogValue < min) min = analogValue;
	Serial.print(" Min ");
	Serial.print(min);
	Serial.print(" Max ");
	Serial.print(max);
	Serial.print(" Range ");
	Serial.println(max - min);

	delay(100);
	buttonState = digitalRead(buttonPin);
	if (buttonState == HIGH) {
		max = 0;
		min = 1024;
	}

}