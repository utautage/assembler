// Arduinoの8番のピンにLEDのアノードを、7番のピンにカソードを接続する
// LEDのカソードには330Ωの抵抗を挟む

void setup() {
  asm volatile(
    "ldi r16, 255\n"
    "out 4, r16\n"
    "out 10, r16\n"
    "ldi r16, 255\n" // 0 または 255
    "out 5, r16\n"
    "ldi r16, 255\n" // 0 または 255
    "out 11, r16\n"
    ::: "r16"
  );
}

void loop() {}
