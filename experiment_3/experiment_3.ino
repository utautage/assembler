volatile byte a[10] = {1,2,3,4,5,6,7,8,9,10};
unsigned int a_ptr = a;
volatile byte al = lowByte(a_ptr);
volatile byte ah = highByte(a_ptr);
int i;

void setup() {
  Serial.begin(9600);
  for (i = 0; i < 10; i++) {
    Serial.print(" ");
    Serial.print(a[i]);
  }
  Serial.println();
  asm volatile(
    "lds r26, (al)\n"
    "lds r27, (ah)\n"
    "ldi r23, 10\n"
    "loop: ld r16, X\n"
    "add r16, r16\n"
    "st X+, r16\n"
    "dec r23\n"
    "brbc 1, loop\n"
    ::: "r16", "r23", "r26", "r27"
  );
  for (i = 0; i < 10; i++) {
    Serial.print(" ");
    Serial.print(a[i]);
  }
  Serial.println();
}

void loop() {}
