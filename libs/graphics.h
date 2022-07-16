//A re implemention of Borlands for this kernel graphics.h but it's free software instead
//LICENSE: MIT







int x = 0, y = 0, s = 0, w = 0, h = 0; //w = width, h = height
uint32_t currentColor = YELLOW; 
void cleardevice(){

    
    
 
    if(s && x < w && y<h){
        *((uint32_t*)(&fb + s*(y) + (x)*4))= currentColor; 

    }
}

void rectangle(int left,  int top, int right, int bottom){
    
    if(s && x > left && y > top && x < right && y < bottom) *((uint32_t*)(&fb + s*(y) + (x)*4))= currentColor; 
}

void setbkcolor(uint32_t color){
    currentColor = color;


}

int getmaxx(){
    return w;
}

int getmaxy(){
    return h;
}