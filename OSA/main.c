
#include "stm8s.h"
#include "osa.h"

#define LED_GPIO_PORT  GPIOD
#define LED_GPIO_PINS  GPIO_PIN_3
#define TIM4_PERIOD       124

__IO uint32_t TimingDelay = 0;

void Delay(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
void CLK_Config(void);
void TIM4_Config(void);
void LED_TASK(void);


void main(void)
{
	CLK_Config();
  GPIO_Init(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
	TIM4_Config();
  OS_Init();
	OS_Task_Create(0, LED_TASK);
	OS_EI();
	OS_Run();

}
void LED_TASK(void)
{
	while (1)
  {
    GPIO_WriteReverse(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS);
    OS_Delay(500);
  }
}
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while (TimingDelay != 0);
}
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}
void TIM4_Config(void)
{
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, TIM4_PERIOD);
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  enableInterrupts();
  TIM4_Cmd(ENABLE);
}
void CLK_Config(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
}

#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{ 
  while (1)
  {
  }
}
#endif
