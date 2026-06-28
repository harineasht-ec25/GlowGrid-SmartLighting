#define VOLTAGE_SENSOR_PIN 34
#define CURRENT_SENSOR_PIN 35

#define VOLTAGE_OFFSET 1.58f
#define CURRENT_OFFSET 1.57f

#define ACS712_SENSITIVITY 0.066f
#define SAMPLE_COUNT 1500
#define SAMPLE_DELAY_US 50

float VOLTAGE_SCALE = 140.0f;


// -------- VOLTAGE --------
float readRMSVoltage() {
  float sum = 0;

  for (int i = 0; i < SAMPLE_COUNT; i++) {
    float v = (analogRead(VOLTAGE_SENSOR_PIN) / 4095.0) * 3.3;
    float ac = (v - VOLTAGE_OFFSET) * VOLTAGE_SCALE;
    sum += ac * ac;
    delayMicroseconds(SAMPLE_DELAY_US);
  }

  float rms = sqrt(sum / SAMPLE_COUNT);

  if (rms < 10) return 0;
  return rms;
}


// -------- CURRENT (FIXED) --------
float readRMSCurrent() {
  float sum = 0;

  for (int i = 0; i < SAMPLE_COUNT; i++) {
    float v = (analogRead(CURRENT_SENSOR_PIN) / 4095.0) * 3.3;

    float delta = v - CURRENT_OFFSET;
    sum += delta * delta;

    delayMicroseconds(SAMPLE_DELAY_US);
  }

  float vRms = sqrt(sum / SAMPLE_COUNT);

  float current = vRms / ACS712_SENSITIVITY;

  if (current < 0.02) return 0;

  return current;
}


// -------- SETUP --------
void setup() {
  Serial.begin(115200);
  delay(2000);
  for (int i = 0; i < 20; i++) Serial.println();
}


// -------- LOOP --------
void loop() {

  float voltage = readRMSVoltage();
  float current = readRMSCurrent();

  Serial.print("V: ");
  Serial.print(voltage, 1);
  Serial.print(" V | ");

  Serial.print("I: ");
  Serial.print(current * 1000, 1);
  Serial.println(" mA");

  delay(1000);
}
