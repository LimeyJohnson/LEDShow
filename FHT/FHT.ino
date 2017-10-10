//Modified version of readme code
#define LOG_OUT 1 // use the log output function
#define FHT_N 64 // set to 256 point fht

#include <FHT.h> // include the library
int micPin = A4;
void setup() {
	Serial.begin(115200); // use the serial port
	TIMSK0 = 0; // turn off timer0 for lower jitter
	ADCSRA = 0xe5; // set the adc to free running mode

	//DIDR0 = 0x01; // turn off the digital input for adc0
}

void loop() {
	while (1) { // reduces jitter
		  // UDRE interrupt slows this way down on arduino1.0
		for (int i = 0; i < FHT_N; i++) { fht_input[i] = 0; }
		for (int i = 0; i < FHT_N; i += 2) { // save 256 samples
			fht_input[i] = analogRead(micPin);
		}
		fht_window(); // window the data for better frequency response
		fht_reorder(); // reorder the data before doing the fht
		fht_run(); // process the data in the fht
		fht_mag_log(); // take the output of the fht
		
	
		for (int i = 0; i < FHT_N /2; i++) { Serial.println(i+": "+fht_log_out[i]); } // send out the data

	}

}
