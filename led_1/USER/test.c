#include "sys.h"
#include "delay.h" 
#include "led.h"
//ALIENTEK ̽����STM32F407������ ʵ��1
//�����ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
  
int main(void)
{ 
	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz
	delay_init(168);		//��ʼ����ʱ����
	LED_Init();
	//��ʼ��LEDʱ��
	
		RCC->AHB1ENR |= 0x1 << 1; //ʹ��GPIOBʱ��
		GPIO_Set(GPIOB,PIN8|PIN9,GPIO_MODE_IN,0,0,GPIO_PUPD_PU); //PB4,PB5��������
	while(1)
	{

	if(PBin(8) ==  0&& PBin(9) == 0)
	{
		LED0=0;				//DS0��
		LED1=1;				//DS1��
		delay_ms(500);
		LED0=1;				//DS0��
		LED1=0;				//DS1��
		delay_ms(500);
	}
			//delay_ms(1000);
			//PBin(8) = 0;
			//PBin(9) = 0;
	}
}

















