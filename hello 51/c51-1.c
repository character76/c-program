#include <uart.h>
#include <BoeBot.h>

int main(void)
{
	int a;
	uart_Init();
	while(1)
	{
		if(qti_right()&&qti_left())
		{
			forward();
		}
		else if(qti_right()==1&&qti_left()==0)
		{
			right();
		}
		else if(qti_right()==0&&qti_left()==1)
		{
			left();
		}
		else forward();
	};
	return 0;
}
int qti_right()
{
	return(P1&0x01)? 1:0;
}
int qti_left()
{
	return(P1&0x02)? 1:0;
}

int forward()
{
	P1_0=1;
	delay_nus(1300);
	P1_0=0;
	P1_1=1;
	delay_nus(1700);
	P1_1=0;
	delay_nms(20); 
}
int right()
{
	P1_0=1;
	delay_nus(1700);
	P1_0=0;
	P1_1=1;
	delay_nus(1700);
	P1_1=0;
	delay_nms(20); 
}

int left()
{
	P1_0=1;
	delay_nus(1300);
	P1_0=0;
	P1_1=1;
	delay_nus(1300);
	P1_1=0;
	delay_nms(20); 
}
