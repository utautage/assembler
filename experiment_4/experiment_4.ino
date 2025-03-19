volatile byte n = 10, result;

void setup() {
  Serial.begin(9600);
  asm volatile(
    "lds r16, (n)\n"
    "ldi r17, 1\n"
    "ldi r18, 1\n"
    "dec r16\n"
    "loop: dec r16\n"
    "brbs 1, end\n"
    "brbs 2, end\n"
    "push r18\n"
    "add r18, r17\n"
    "pop r17\n"
    "rjmp loop\n"
    "end: sts (result), r18\n"
    ::: "r16", "r17", "r18"
  );
  Serial.print(n);
  Serial.print("番目のフィボナッチ数は");
  Serial.println(result);
}

void loop() {}
