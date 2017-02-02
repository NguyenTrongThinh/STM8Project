#include "ic74hc595.h"

void HC595Init(void)
{
	GPIO_Init(HC595_PORT, (GPIO_Pin_TypeDef)HC595_DS_PIN, GPIO_MODE_OUT_PP_LOW_FAST);
	GPIO_Init(HC595_PORT, (GPIO_Pin_TypeDef)HC595_SH_PIN, GPIO_MODE_OUT_PP_LOW_FAST);
	GPIO_Init(HC595_PORT, (GPIO_Pin_TypeDef)HC595_ST_PIN, GPIO_MODE_OUT_PP_LOW_FAST);
}

void HC595WriteByte(unsigned char data)
{
	unsigned char i = 0;
	unsigned char tmp;
	GPIO_WriteLow(HC595_PORT, (GPIO_Pin_TypeDef)HC595_SH_PIN);
	GPIO_WriteLow(HC595_PORT, (GPIO_Pin_TypeDef)HC595_ST_PIN);
	for (i = 0; i < 8; i++)
	{
		tmp = data&0x80;
		if (tmp == 0x80)
			GPIO_WriteHigh(HC595_PORT, (GPIO_Pin_TypeDef)HC595_DS_PIN);
		else
			GPIO_WriteLow(HC595_PORT, (GPIO_Pin_TypeDef)HC595_DS_PIN);
		data <<= 1;
		GPIO_WriteHigh(HC595_PORT, (GPIO_Pin_TypeDef)HC595_SH_PIN);
		GPIO_WriteLow(HC595_PORT, (GPIO_Pin_TypeDef)HC595_SH_PIN);
	}
}
void HC595LockData(void)
{
		GPIO_WriteHigh(HC595_PORT, (GPIO_Pin_TypeDef)HC595_ST_PIN);
		GPIO_WriteLow(HC595_PORT, (GPIO_Pin_TypeDef)HC595_ST_PIN);
}
