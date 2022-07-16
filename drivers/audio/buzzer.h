/*
    Buzzer aka On Board speaker driver
    LICENSE: MIT
*/

void speaker(){   
       outb(0x61, 0x00); outb(0x61, 0xFF); outb(0x61, 0x00);
}
void beep(uint8_t frequency, uint16_t duration){   
    outb(0x61, 0);
    outb(0x42, (uint8_t)1193180/frequency);

    outb(0x42, (uint8_t)(1193180/frequency * 3));
    

    
    outb(0x61, inb(0x61) | 3);
    outb(0x42, (uint8_t)1193180);

}

void silence() {
    outb(0x61, 0);
}
