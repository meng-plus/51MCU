
#include <REGX52.H>

void main()
{
    ES = 1;                     //使能串口中断
    EA = 1;
RI=0;
	TI=0;
	RI=1;
	while(1)
	{

	}

}
/*----------------------------
UART 中断服务程序
-----------------------------*/
void Uart() interrupt 4
{
    if (RI)
    {
       // RI = 0;                 //清除RI位
        P0 = SBUF;              //P0显示串口数据
     }
    if (TI)
    {
        TI = 0;                 //清除TI位
    }
}