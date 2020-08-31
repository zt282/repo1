#include "sys.h"
#include "delay.h" 
#include "led.h"
//ALIENTEK 探索者STM32F407开发板 实验1
//跑马灯实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
  
int main(void)
{ 
	Stm32_Clock_Init(336,8,2,7);//设置时钟,168Mhz
	delay_init(168);		//初始化延时函数
	LED_Init();
	//初始化LED时钟
	
		RCC->AHB1ENR |= 0x1 << 1; //使能GPIOB时钟
		GPIO_Set(GPIOB,PIN8|PIN9,GPIO_MODE_IN,0,0,GPIO_PUPD_PU); //PB4,PB5上拉输入
	while(1)
	{

	if(PBin(8) ==  0&& PBin(9) == 0)
	{
		LED0=0;				//DS0亮
		LED1=1;				//DS1灭
		delay_ms(500);
		LED0=1;				//DS0灭
		LED1=0;				//DS1亮
		delay_ms(500);
	}
			//delay_ms(1000);
			//PBin(8) = 0;
			//PBin(9) = 0;
	}
}

















