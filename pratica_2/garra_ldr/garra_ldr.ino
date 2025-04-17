# include <Servo.h>

const int PIN_GARRA = 8;
const int PIN_BUTTON = 9;
const int PIN_LDR = A0;
const int GARRA_CLOSED = 167;
const int GARRA_OPEN = 120;
const Servo garra;

int ponto_1 = 0;
int ponto_2 = 0;

bool press = false;


void setup() {
  Serial.begin(9600);

  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LDR, INPUT);
  garra.attach(PIN_GARRA);
  garra.write(GARRA_CLOSED);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == HIGH && !press) {
    press = true;

    garra.write(GARRA_OPEN);
    ponto_1 = millis();
    while (analogRead(PIN_LDR) > 130) {
      // Serial.println(analogRead(PIN_LDR));
    }
    ponto_2 = millis();
    Serial.print(ponto_2 - ponto_1);
    Serial.println(" ms");
    
    garra.write(GARRA_CLOSED);
  } else if (digitalRead(PIN_BUTTON) == LOW && press) {
    press = false;
  }
}
