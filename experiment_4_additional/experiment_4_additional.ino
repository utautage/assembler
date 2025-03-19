volatile byte a[31] = {1, 1}; //整数0～30に対するフラグで、1は素数でないとわかったもの（0,1は素数でないので1）とする。
unsigned int a_ptr = a; //aのポインタ
volatile byte al = lowByte(a_ptr);
volatile byte ah = highByte(a_ptr);
int i;

void setup() {
  Serial.begin(9600);
  asm volatile(
    "ldi r16, 2\n"
    "ldi r17, 6\n"
    "ldi r18, 31\n"
    "cp r16, r17\n"
    "brbs 2, loop"
    "rjmp end\n"
    "loop:\n" // loop: if (a[r16] == 1) goto skip
    "lds r20, r16\n"
    "filter: add r20, r16\n"
    "\n" // a[r20] = 1
    "cp r20, r18\n"
    "brbs 2, filter"
    "inc r16\n"
    "rjmp loop\n"
    "end:\n" // end
    "\n" // 
    "\n" // 
    ::: ""
  );
  for (i = 0; i <= 30; i++) {
    Serial.print(a[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {}
