// Arduinoの13番のピンにLEDのアノード、GNDにカソードを接続する

void setup() {
  asm volatile(
    "rjmp start\n"
    "delay1: push r20\n"
    "push r21\n"
    "push r22\n"
    "ldi r22, 128\n"
    "loop1: ldi r21, 0\n"
    "loop2: ldi r20, 0\n"
    "loop3: dec r20\n"
    "brne loop3\n"
    "dec r21\n"
    "brne loop2\n"
    "dec r22\n"
    "brne loop1\n"
    "pop r22\n"
    "pop r21\n"
    "pop r20\n"
    "ret\n"
    "start: ldi r16, 255\n"
    "out 4, r16\n"
    "loop: ldi r16, 32\n"
    "out 5, r16\n"
    "rcall delay1\n"
    "ldi r16, 0\n"
    "out 5, r16\n"
    "rcall delay1\n"
    "rjmp loop\n"
    ::: "r16", "r26", "r27"
  );
}
void loop() {}
