#define ZMPT_PIN 34

const float VREF = 3.3;
const int ADC_MAX = 4095;

int adcOffset = 0;

// Initial calibration factor
// Adjust later using a multimeter
float calibrationFactor = 695.0;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(ZMPT_PIN, ADC_11db);

  Serial.println("Calibrating offset...");

  long sum = 0;

  for (int i = 0; i < 5000; i++) {
    sum += analogRead(ZMPT_PIN);
    delayMicroseconds(200);
  }

  adcOffset = sum / 5000;

  Serial.print("ADC Offset = ");
  Serial.println(adcOffset);

  Serial.println("Calibration Complete");
}

float measureACVoltage() {

  const int samples = 2000;
  double sumSquares = 0;

  for (int i = 0; i < samples; i++) {

    int adc = analogRead(ZMPT_PIN);

    float sensorVoltage =
      ((adc - adcOffset) * VREF) / ADC_MAX;

    sumSquares += sensorVoltage * sensorVoltage;
  }

  float vrmsSensor = sqrt(sumSquares / samples);

  // Remove tiny noise
  if (vrmsSensor < 0.01)
    return 0.0;

  return vrmsSensor * calibrationFactor;
}

void loop() {

  float mainsVoltage = measureACVoltage();

  Serial.print("AC Voltage: ");
  Serial.print(mainsVoltage, 1);
  Serial.println(" V");

  delay(1000);
}