#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
DigitalOut btn_confirm(D13);
DigitalOut btn_down(D12);
DigitalOut btn_up(D11);

int main()
{
    // basic printf demo = 16 by 18 characters on screen
    uLCD.locate(0,0);
    uLCD.printf("Select Frequency\n"); //Default Green on black text



    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(2,1);
    uLCD.printf("200Hz");    

    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(2,3);
    uLCD.printf("400Hz");  

    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(2,5);
    uLCD.printf("600Hz");  

    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(2,7);
    uLCD.printf("900Hz");  

    int mode = 0;

    while (1) {
        if (btn_down) {
            if (mode < 3) mode++;
        }
        if (btn_up) {
            if (mode > 0) mode--;
        }
        if (mode == 0) {
            uLCD.line(20,12,102,12,RED);
            uLCD.line(20,12,20,32,RED);
            uLCD.line(102,12,102,32,RED);
            uLCD.line(20,32,102,32,RED);
            uLCD.line(20,45,102,45,BLACK);
            uLCD.line(20,45,20,65,BLACK);
            uLCD.line(102,45,102,65,BLACK);
            uLCD.line(20,65,102,65,BLACK); 
            uLCD.line(20,77,102,77,BLACK);
            uLCD.line(20,77,20,97,BLACK);
            uLCD.line(102,77,102,97,BLACK);
            uLCD.line(20,97,102,97,BLACK);
            uLCD.line(20,108,102,108,BLACK);
            uLCD.line(20,108,20,127,BLACK);
            uLCD.line(102,108,102,127,BLACK);                         
        }
        if (mode == 1) {
            uLCD.line(20,12,102,12,BLACK);
            uLCD.line(20,12,20,32,BLACK);
            uLCD.line(102,12,102,32,BLACK);
            uLCD.line(20,32,102,32,BLACK);
            uLCD.line(20,45,102,45,RED);
            uLCD.line(20,45,20,65,RED);
            uLCD.line(102,45,102,65,RED);
            uLCD.line(20,65,102,65,RED); 
            uLCD.line(20,77,102,77,BLACK);
            uLCD.line(20,77,20,97,BLACK);
            uLCD.line(102,77,102,97,BLACK);
            uLCD.line(20,97,102,97,BLACK);
            uLCD.line(20,108,102,108,BLACK);
            uLCD.line(20,108,20,127,BLACK);
            uLCD.line(102,108,102,127,BLACK);          
        }
        if (mode == 2) {
            uLCD.line(20,12,102,12,BLACK);
            uLCD.line(20,12,20,32,BLACK);
            uLCD.line(102,12,102,32,BLACK);
            uLCD.line(20,32,102,32,BLACK);
            uLCD.line(20,45,102,45,BLACK);
            uLCD.line(20,45,20,65,BLACK);
            uLCD.line(102,45,102,65,BLACK);
            uLCD.line(20,65,102,65,BLACK); 
            uLCD.line(20,77,102,77,RED);
            uLCD.line(20,77,20,97,RED);
            uLCD.line(102,77,102,97,RED);
            uLCD.line(20,97,102,97,RED);
            uLCD.line(20,108,102,108,BLACK);
            uLCD.line(20,108,20,127,BLACK);
            uLCD.line(102,108,102,127,BLACK);              
        }
        if (mode == 3) {
            uLCD.line(20,12,102,12,BLACK);
            uLCD.line(20,12,20,32,BLACK);
            uLCD.line(102,12,102,32,BLACK);
            uLCD.line(20,32,102,32,BLACK);
            uLCD.line(20,45,102,45,BLACK);
            uLCD.line(20,45,20,65,BLACK);
            uLCD.line(102,45,102,65,BLACK);
            uLCD.line(20,65,102,65,BLACK); 
            uLCD.line(20,77,102,77,BLACK);
            uLCD.line(20,77,20,97,BLACK);
            uLCD.line(102,77,102,97,BLACK);
            uLCD.line(20,97,102,97,BLACK);
            uLCD.line(20,108,102,108,RED);
            uLCD.line(20,108,20,127,RED);
            uLCD.line(102,108,102,127,RED);             
        }


        if (btn_confirm) break;

    }
    
}