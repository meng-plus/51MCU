#include <REGX52.H>
#include "Time.h"

void main()
{
    unsigned int Delay=500;
    DelayTypedef DelayBlock;
    DelayBlock.DelayMs=1000;
    DelayBlock.State=Start;
    TimeInit(1000);
    T0_RUN(1);//¿ª¶¨Ê±Æ÷
    while(1)
    {
//        DelayBlocking(Delay);
//        P1_1=!P1_1;
        DelayNonBlocking(&DelayBlock);
        if(DelayBlock.State ==Ok)
        {
            DelayBlock.State=Start;
            P1_2=!P1_2;
        }
    }
}