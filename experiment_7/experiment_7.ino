// |A5|A4| |13|12|11|10| 9| 8| | 7| 6| 5| 4| 3| 2| 1| 0| Arduinoのコネクタ
//  C1 C2   C3 C4 C5 C6 C7 C8   R1 R2 R3 R4 R5 R6 R7 R8
//  13  3    4 10  6 11 15 16    9 14  8 12  1  7  2  5  マトリックスLEDのピン
void setup() {
  asm volatile(
    "ldi r17, 63\n"
    "ldi r18, 48\n"
    "ldi r19, 255\n"
    "out 10, r19\n"
    "out 4, r17\n"
    "out 7, r18\n"
    "rjmp loop\n"
    "delay1: push r26\n"
    "ldi r26,0\n"
    "loop1: dec r26\n"
    "brne loop1\n"
    "pop r26\n"
    "ret\n"
    "loop: ldi r16, 0x00\n" //1列目
    "out 11, r16\n"
    "ldi r16, 0xff\n"
    "out 5, r16\n"
    "ldi r16, 0xdf\n"
    "out 8, r16\n"
    "rcall delay1\n"    
    "ldi r16, 0x03\n" //2列目
    "out 11, r16\n"
    "ldi r16, 0xef\n"
    "out 8, r16\n"
    "rcall delay1\n"
    "ldi r16, 0x1c\n" //3列目
    "out 11, r16\n"
    "ldi r16, 0xdf\n"
    "out 5, r16\n"
    "ldi r16, 0xff\n"
    "out 8, r16\n"
    "rcall delay1\n"
    "ldi r16, 0x64\n" //4列目
    "out 11, r16\n"
    "ldi r16, 0xef\n"
    "out 5, r16\n"
    "rcall delay1\n"
    "ldi r16, 0x84\n" //5列目
    "out 11, r16\n"
    "ldi r16, 0xf7\n"
    "out 5, r16\n"
    "rcall delay1\n"
    "ldi r16, 0x64\n" //6列目
    "out 11, r16\n"
    "ldi r16, 0xfb\n"
    "out 5, r16\n"
    "rcall delay1\n"
    "ldi r16, 0x1c\n" //7列目
    "out 11, r16\n"
    "ldi r16, 0xfd\n"
    "out 5, r16\n"
    "rcall delay1\n"
    "ldi r16, 0x03\n" //8列目
    "out 11, r16\n"
    "ldi r16, 0xfe\n"
    "out 5, r16\n"
    "rcall delay1\n"

    "rjmp loop\n"
    ::: "r16", "r17", "r18", "r19"
  );
}

void loop() {}
