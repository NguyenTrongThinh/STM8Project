#include "stm8s.h"

#define HC595_PORT			GPIOD
#define HC595_DS_PIN		GPIO_PIN_4
#define HC595_SH_PIN		GPIO_PIN_5
#define HC595_ST_PIN		GPIO_PIN_6

void HC595Init(void);
void HC595WriteByte(unsigned char data);
void HC595LockData(void);