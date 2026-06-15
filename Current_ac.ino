#define ACS_PIN 35

const float VREF = 3.3;
const int ADC_MAX = 4095;
const float SENSITIVITY = 0.066; // ACS712-30A

int offsetADC;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(ACS_PIN, ADC_11db);

  long sum = 0;

  Serial.println("Calibrating... Remove all load if possible");

  for (int i = 0; i < 10000; i++) {
    sum += analogRead(ACS_PIN);
    delayMicroseconds(100);
  }

  offsetADC = sum / 10000;

  Serial.print("Offset = ");
  Serial.println(offsetADC);
}

void loop() {

  double sumSq = 0;

  for (int i = 0; i < 4000; i++) {

    int adc = analogRead(ACS_PIN);

    float voltage = ((adc - offsetADC) * VREF) / ADC_MAX;

    sumSq += voltage * voltage;
  }

  float vrms = sqrt(sumSq / 4000.0);
  float current = vrms / SENSITIVITY;

  Serial.print("Current = ");
  Serial.print(current, 3);
  Serial.println(" A");

  delay(1000);
}