 //PS/2 Keyboard Driver
 char* circularBuffer;
unsigned char getKeyPress(){   
    return inb(0x60);
}

unsigned char scanCodeToKey(unsigned char key) {
    
}