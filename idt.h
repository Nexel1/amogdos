#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA 0xA1

#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01

typedef struct{
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;   
    uint8_t types_attr;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t zero;

} IDT64; 
extern IDT64 _idt[256];
extern uint64_t isrl;

extern void LoadIDT();
//had to follow this tutorel because my code didnt work correctly qemu kept restarting because i caused adresses to shift accidiently grammar mistakes are intentional amogus :/ https://www.youtube.com/watch?v=QRhFo-CnpvQ
void InitializeIDT(){
    for(uint64_t i = 0; i < 256; i++) {
        _idt[i].zero = 0;
        _idt[i].offset_low = (uint16_t)((uint64_t)(  isrl & 0x000000000000FFFF));
        _idt[i].offset_mid = (uint16_t)((uint64_t)( isrl & 0x00000000FFFF0000) >> 16);
        _idt[i].offset_high = (uint32_t)((uint64_t)(  isrl & 0xFFFFFFFF00000000) >> 32);
        _idt[i].ist = 0;
        _idt[i].selector = 0x08;
        _idt[i].types_attr = 0x8e;



    }
	RemapPic();

	outb(0x21, 0xFB);
    outb(0xa1, 0xfc);
	LoadIDT();

}

void RemapPic(){
  uint8_t a1, a2;

  a1 = inb(PIC1_DATA);
  a2 = inb(PIC2_DATA);

  outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
  outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
  outb(PIC1_DATA, 0);
  outb(PIC2_DATA, 8);
  outb(PIC1_DATA, 4);
  outb(PIC2_DATA, 2);
  outb(PIC1_DATA, ICW4_8086);
  outb(PIC2_DATA, ICW4_8086);

  outb(PIC1_DATA, a1);
  outb(PIC2_DATA, a2);

}

void isrlHandler() {
    inb(0x60);
    outb(0x20, 0x20);
    outb(0xa0, 0x20);

}