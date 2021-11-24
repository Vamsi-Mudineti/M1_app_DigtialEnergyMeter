#include <stdio.h>
#include <stdlib.h>
#include "./inc/Delay.h"
#include "./src/Delay.c"
//#include<REG52.h>
int delay();
int Charging_step1();
int Charging_step2();
int recall();
//sbit relay_pin = P2^0;
int tem,coin_status,i;
int main()
{
    printf("Welcome to EV charging station\n");
    printf("Please connect the connector to EV and enter 1\n");
    //scanf("%d",&tem); 
    tem=1;
    Charging_step1();
    Charging_step2();
    recall();
    return 0;
}

int Charging_step1()
{ if(tem==1)
    {
        printf("coin status\n");
       // scanf("%d",&coin_status);
        coin_status=1;
        printf("you enter %d rupee coin\n", coin_status);
        if(coin_status==1)
            printf("EV will Charge upto 10 seconds\n");
        else if(coin_status==2)
            printf("EV will Charge upto 20 seconds\n");
        else if(coin_status==5)
            printf("EV will Charge upto 50 seconds\n");
        else
            printf("EV will Charge upto 100 seconds\n");
    }
    return 0;
}

int Charging_step2()
{
    if(tem==1)
    {
        switch (coin_status)
        {case 1:
        {
            for (i = 0; i < 10; i++)
                {
                    // delay of one second
                    delay(1);
                    printf("%d seconds\n", i + 1);
                   // realy_pin=1;
                }
                break;
        }
        case 2:
        {
            for (i = 0; i < 20; i++)
                {
                    // delay of one second
                    delay(1);
                    printf("%d seconds\n", i + 1);
                   // realy_pin=1;
                }
                 break;
        }
        case 5:
        {
            for (i = 0; i < 50; i++)
                {
                    // delay of one second
                    delay(1);
                    printf("%d seconds\n", i + 1);
                   // realy_pin=1;
                }
                 break;
        }
        case 10:
        {
            for (i = 0; i < 100; i++)
                {
                    // delay of one second
                    delay(1);
                    printf("%d seconds\n", i + 1);
                    //realy_pin=1;
                }
                  break;
        }
    return 0;
    }
    }
    //relay_pin=0;
    //delay();
}

int recall()
{
    printf("EV Charging done for  %d ruppee\n",coin_status);
    printf("if you want to Charge Ev again enter 1 \nif you want to Stop enter 2 \n");
    //scanf("%d",&tem);
    tem=2;
    Charging_step1();
    Charging_step2();
    if(tem==1)
     recall();

     return 0;
}
