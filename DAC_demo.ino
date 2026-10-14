/*======================================================
                     DAC
========================================================
Description:
Where we convert digital to analog and to show how it
works inside the esp32.

Designer Engineer:
Ebio, Ann Clarise
Jaena, Elaiza B.

Date:
Oct. 14, 2026
======================================================*/

// GPIO pins
const byte POT = 36;     // 3102
const byte DAC_PIN = 25;  // 2.5V <- result calc

// variables
int adc_val;
float voltage_in = 0;

void setup() {
  // ADC pin
  pinMode(POT, INPUT);
  analogReadResolution(8); // because the DAC is 8-bit but the default is 12-bit

  //DAC pin
  pinMode(DAC_PIN, OUTPUT);

  Serial.begin(9600);  // baud rate bps
}

void loop() {
  // 8-bit ADC numerical value
  adc_val = analogRead(POT);
  Serial.printf("ADC Numerical Value: %d\n", adc_val); // %d\n a placeholder can print multiple and convert to one data type
  delay(500);

  // Convert 8-bit ADC to actual voltage 
  voltage_in = (adc_val/255.0)*3.3;
  Serial.printf("Input Voltage: %.2f\n", voltage_in);
  delay(500);

  // Use multimeter to verify the actual voltage
  dacWrite(DAC_PIN, adc_val);  // 1.8V
}
