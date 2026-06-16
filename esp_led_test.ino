#define LED_PIN 2

#define AUX_PIN 4
#define M0_PIN 18
#define M1_PIN 5

HardwareSerial LoRaSerial(2);

unsigned long lastSend = 0;
bool receiverFound = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);   // LED ON when code starts

  Serial.begin(115200);

  pinMode(AUX_PIN, INPUT);
  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);

  digitalWrite(M0_PIN, LOW);
  digitalWrite(M1_PIN, LOW);

  delay(100);

  LoRaSerial.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("LoRa Test Started");
}

void loop() {

  if (millis() - lastSend > 3000) {
    lastSend = millis();

    receiverFound = false;

    Serial.println("Sending PING...");
    LoRaSerial.println("PING");
  }

  if (LoRaSerial.available()) {

    String msg = LoRaSerial.readStringUntil('\n');
    msg.trim();

    Serial.print("Received: ");
    Serial.println(msg);

    if (msg == "PING") {

      LoRaSerial.println("PONG");

      digitalWrite(LED_PIN, LOW);
      delay(100);
      digitalWrite(LED_PIN, HIGH);
    }

    if (msg == "PONG") {
      Serial.println("Receiver Found!");

      for (int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, LOW);
        delay(200);
        digitalWrite(LED_PIN, HIGH);
        delay(200);
      }
    }
  }
}