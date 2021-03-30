#include "mbed.h"
#include "uLCD_4DGL.h"
using namespace std::chrono;
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
DigitalOut btn_confirm(D13);
DigitalOut btn_down(D12);
DigitalOut btn_up(D11);
AnalogOut  aout(PA_4);
AnalogIn Ain(A0);

Timer t;

int main()
{

    
    // basic printf demo = 16 by 18 characters on screen
    uLCD.locate(0,0);
    uLCD.printf("Select Frequency\n"); //Default Green on black text



    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(2,1);
    uLCD.printf("100Hz");    

    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(2,3);
    uLCD.printf("200Hz");  

    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(2,5);
    uLCD.printf("400Hz");  

    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.locate(2,7);
    uLCD.printf("500Hz");  

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

    int delay_time = 0, cnt = 0, k = 0;

    if (mode == 0) delay_time = 85;
    if (mode == 1) delay_time = 33;
    if (mode == 2) delay_time = 10;
    if (mode == 3) delay_time = 6;


    float bound = 3/3.3f;
    float step1 = 3/3.3f/40;
    float step2 = 3/3.3f/60; 
    float launch_time = 0;

    if (mode < 2) launch_time = 1.0/(100*(mode+1))*2*1000000;
    if (mode >= 2) launch_time = 1.0/(100*(mode+2))*2*1000000;
    float ADCdata[200];

    while (1) {
      // change the voltage on the digital output pin by 0.1 * VCC
      //  and print what the measured voltage should be (assuming VCC = 3.3v)
        t.start();

        for (float i = 0.0f; i < bound; i += step1) {
            aout = i;
            if (cnt > 20 && cnt < 23 && k < 200) {
                ADCdata[k] = Ain;
                k++;
            } 
            
            wait_us(delay_time);
        }
//        t.stop();
//        auto us = t.elapsed_time().count();
//        printf ("Timer time: %llu us\n", us);
        for (float i = bound; i > 0.0f; i -= step2) {
            aout = i;
            if (cnt > 20 && cnt < 23 && k < 200) {
                ADCdata[k] = Ain;
                k++;
            }             
            wait_us(delay_time);
        }
        t.stop();
        if (cnt == 0) {
            auto us = t.elapsed_time().count();
//            printf ("Timer time: %llu us\n", us);
//            launch_time = float(us);
        }
        if (cnt == 22) {
            printf("%f\r\n", launch_time);
            printf("%f\r\n", launch_time);
            for (k = 0; k < 200; k++)
                printf("%f\r\n", ADCdata[k]);
        }
            
        
        cnt++;
    }

    
}