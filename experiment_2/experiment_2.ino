// volatile byte a = -1, b = 1;
// volatile byte a = -1, b = -2;
// volatile byte a = 1, b = 2;
volatile byte a = 127, b = 1;

void setup() {
  Serial.begin(9600);
  asm volatile(
    "push r23\n"
    "push r24\n"
    "lds r23, (a)\n"
    "lds r24, (b)\n"
    "add r23, r24\n"
    "sts (a), r23\n"
    "in r24, 0x3F\n"
    "sts (b), r24\n"
    "pop r24\n"
    "pop r23\n"
  );
  Serial.print("a = ");
  Serial.print(a);
  Serial.print(" b = ");
  Serial.println(b, BIN);
}

void loop() {}
