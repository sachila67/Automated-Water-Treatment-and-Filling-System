#define start 23
#define ls_01 21
#define ls_02 5
#define s_1 18
#define s_2 19
#define s_3 22
#define pump_01 33
#define pump_02 14
#define minipump 27
#define conveyor 32
#define green 2
#define red 26
#define heater 25
int b = 1;
void setup() {
  pinMode(start, INPUT_PULLUP);
  pinMode(ls_01, INPUT_PULLUP);
  pinMode(ls_02, INPUT_PULLUP);
  pinMode(s_1, INPUT_PULLUP);
  pinMode(s_2, INPUT_PULLUP);
  pinMode(s_3, INPUT_PULLUP);

  pinMode(pump_01, OUTPUT);
  pinMode(pump_02, OUTPUT);
  pinMode(minipump, OUTPUT);
  pinMode(conveyor, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(heater, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (b == 1) {
    digitalWrite(pump_01, LOW);
    digitalWrite(pump_02, LOW);
    digitalWrite(minipump, LOW);
    digitalWrite(conveyor, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(heater, LOW);
    b = 2;
  }
  if (b == 2) {
    if (digitalRead(start) == 1) {
      b = 3;
    }
  }
  if (b == 3) {
    digitalWrite(pump_01, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    b = 4;
  }
  if (b == 4) {
    if (ls_02 == 0) {
      b = 5;
    }
  }
  if (b == 5) {
    digitalWrite(pump_01, LOW);
    digitalWrite(heater, HIGH);
    delay(5000);
    digitalWrite(heater, LOW);
    digitalWrite(pump_02, HIGH);
    b = 6;
  }
  if (b == 6) {
    if (ls_01 == 0) {
      b = 7;
    }
  }
  if (b == 7) {
    digitalWrite(pump_02, LOW);
    b = 8;
  }
  if (b == 8) {
    if (s_1 == 0 && s_3 == 1) {
      b = 9;
    }
  }
  if (b == 9) {
    delay(2000);
    digitalWrite(conveyor, HIGH);
    b = 10;
  }
  if (b == 10) {
    if (s_2 == 0) {
      b = 11;
    }
  }
  if (b == 11) {
    digitalWrite(conveyor, LOW);
    digitalWrite(minipump, HIGH);
    delay(5000);
    digitalWrite(minipump, LOW);
    digitalWrite(conveyor, HIGH);
    b = 12;
  }
  if (b == 12) {
    if (s_3 == 0) {
      b = 1;
    }
  }
}
