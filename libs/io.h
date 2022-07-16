void outb(unsigned short port, unsigned char val){
    asm volatile ( "outb %1, %0"
                   :
                   : "a"(val),
                     "Nd"(port) );
}
unsigned char inb(unsigned short port) {
    unsigned char toReturn;

    asm volatile("inb %0, %1" 
    : "=a"(toReturn)
    : "Nd"(port));

    return toReturn;
}


