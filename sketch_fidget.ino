#define BTN1 D0
#define BTN2 D1
#define BTN3 D2
#define POTEN D3
#define LED1 D4
#define LED2 D5
#define LED3 D6
#define BUZZER D10

void setup() {
  pinMode(POTEN, INPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  bool btn1Read = digitalRead(BTN1);
  bool btn2Read = digitalRead(BTN2);
  bool btn3Read = digitalRead(BTN3);
  digitalWrite(LED1, btn1Read);
  digitalWrite(LED2, btn2Read);
  digitalWrite(LED3, btn3Read);

  if (btn1Read && btn2Read && btn3Read) {
    int potenRead = digitalRead(POTEN);
    double toneHz = map(potenRead, 0, 1023, 100, 3000);
    tone(BUZZER, (int)toneHz);
  } else {
    noTone(BUZZER);
  }
}
