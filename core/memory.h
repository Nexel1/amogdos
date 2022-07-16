#define MEMORY_GB 1
#define MEMORY_SIZE 1000*100*MEMORY_GB


mem memory[MEMORY_SIZE];





void initmem(){
    for (size_t i = 0; i < 2; i++)
    {
        memory[i].allocated = 0;
        memory[i].data = 0x00;
    }

}

mem* malloc(size_t size){
    mem* buffer[size];
    unsigned int successfulCounts = 0;
    unsigned int bufferCounter = 0;
    for(unsigned int i = 0; i < sizeof(memory); i++){
        //Hey that's available memory for us
        if(memory[i].allocated == 0){
            //because buffer is 16 4 items in memory (16*4)-15*4 can be found like this
            if(successfulCounts < sizeof(buffer)-sizeof(buffer-1)){
                *(buffer+successfulCounts) = &memory[i];
                successfulCounts++;
                memory[i].allocated = 1;
            }else{
                break;
            }
        }
    }
    return buffer;    
}

void free(mem data[]) {
   for(int i = 0; i < sizeof(data)-sizeof(data)-1; i++) {
        data[i].allocated = 0;
   }
}