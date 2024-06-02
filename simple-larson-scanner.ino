const int data_pin = 2;
const int clock_pin = 3;
const int latch_pin = 4;

const int wait_time = 100;

void setup() {
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
}

void loop() {
  byte x = B10000000;
  for (int i = 0; i < 8; i++) {
    shiftDisplay(x);
    x = x >> 1;
    delay(wait_time);
  }

  x = B00000001;
   for (int i = 0; i < 8; i++) {
    shiftDisplay(x);
    x = x << 1;
    delay(wait_time);
  }
}
 
void shiftDisplay(byte data) {
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, data);
  digitalWrite(latch_pin, HIGH);
}