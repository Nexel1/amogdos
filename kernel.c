/*
 * mykernel/c/kernel.c
 *
 * Copyright (C) 2017 - 2021 bzt (bztsrc@gitlab)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This file is part of the BOOTBOOT Protocol package.
 * @brief A sample BOOTBOOT compatible kernel
 *
 */

/* function to display a string, see below */
int x,y,s, w, h;

/* we don't assume stdint.h exists */



#define BLACK 0x00000000
#define BLUE 0x00039DFC
#define GREEN 0x0003FCA1
#define CYAN 0x0003CFFC
#define RED 0x00FC0356
#define MAGENTA 0x00FC0384
#define BROWN 0x00FC9d03
#define LIGHTGRAY 0x00DEDEDE
#define DARKGRAY 0x00858585
#define YELLOW 0x00FFD000


#include "libs/stdint.h"
#include "bootboot.h"


/* imported virtual addresses, see linker script */
extern BOOTBOOT bootboot;               // see bootboot.h
extern unsigned char environment[4096]; // configuration, UTF-8 text key=value pairs
extern uint8_t fb;                      // linear framebuffer mapped

/******************************************
 * Entry point, called by BOOTBOOT Loader *
 ******************************************/
int timer = 1;
unsigned char getKeyPress();
typedef struct{
    bool allocated;
    unsigned char data;
} mem;
mem* malloc(size_t size);
void _start()
{
    /*** NOTE: this code runs on all cores in parallel ***/
    s=bootboot.fb_scanline, w=bootboot.fb_width, h=bootboot.fb_height;
    int midx = getmaxx()/2, midy = getmaxy()/2;
    InitializeIDT();
    unsigned char sus = getKeyPress();
    mem* demo = malloc(2);
    (demo+1)->data = 0xff;
    (demo+5)->data = 0xff;
    
    while(1){
        sus = getKeyPress();
        timer++;
        
        /*if(x < w)x++;
        if(y < h && x >= w-1){y++; x = 0;};
        if(s){
                *((uint32_t*)(&fb + s*(y) + (x)*4))= 0x00FFD000; 
            //}
        }*/
        if(x < w)x++;
        


        if(y < h && x >= w-1){y++; x = 0;};
        if(y > h-1 || x > w-1) {x = 0; y = 0;}
        setbkcolor(BLUE);

        if((demo+1)->data== 0xff) {
            setbkcolor(YELLOW);
        }
        
        cleardevice();

      
    }

}


#include "libs/graphics.h"
#include "libs/io.h"
#include "idt.h"
#include "core/memory.h"
#include "core/threading.h"
#include "drivers/ps2/keyboard.h"
#include "drivers/audio/buzzer.h"



extern volatile unsigned char _binary_font_psf_start;

