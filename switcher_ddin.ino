#define INPUTS_COUNT 2
#define LAMP_PIN 12

int inputPins[INPUTS_COUNT] = {3, 13};
int inputDelay[INPUTS_COUNT] = {1000, 5000};
int currentDelay = 0;

void setup() {
  pinMode(LAMP_PIN, OUTPUT);
  for (int input = 0; input < INPUTS_COUNT; input++) {
    pinMode(inputPins[input], INPUT_PULLUP);
  }    
}

void loop() {
  // включаем лампу, если продолжительность свечения не нулевая
  if (currentDelay > 0) {
    digitalWrite(LAMP_PIN, HIGH);
  } else {
    digitalWrite(LAMP_PIN, LOW);
  }

  // опрашиваем входы
  for (int input = 0; input < INPUTS_COUNT; input++) {
    // если пришёл сигнал с пина № input...
    if (!digitalRead(inputPins[input])) {
      // ...продлеваем работу лампы до заданной для него продолжительности
      if (currentDelay < inputDelay[input]) {
        currentDelay = inputDelay[input];
      }
    }
  }
  
  // светим, пока не истечёт заданная продолжительность
  if (currentDelay > 0) {
    currentDelay--;
  }
  delay(1);
}
