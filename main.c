
#include "stm32l1xx.h"

int main(void)
{
	RCC->AHBENR |=1           ;   //valide horloge port A
	RCC->AHBENR |=4           ;   //valide horloge port C
	RCC->AHBENR |=2           ;   //valide horloge port B


	GPIOA->MODER = 0x55555555                   ;   //bits 0 à 15 sorties
	GPIOA->OSPEEDR =0x00040000                  ;  //Low speed
	GPIOA->OTYPER = 0x0000000                  ;   //  sorties push pull

	GPIOC->MODER = 0x55555555                   ;   //bits 0 à 15 entrées
	GPIOC->PUPDR = 0                   ;   //  pas de pull up pas de pull down

	GPIOB->MODER = 0x55555555          ;
	GPIOB->PUPDR = 0                   ;   //  pas de pull up pas de pull down

  while (1)
  {
  if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)!= 0); // Utilisation du PIN_13

    {
	  GPIO_SetBits(GPIOB, GPIO_Pin_8)        ;           //Mise à 0 bit 5 sans changer les autres bits
    }      
  else
  {
	  GPIO_ResetBits(GPIOB, GPIO_Pin_8)   ;
  }		//Mise à 1 bit 5 sans modifier les autres
   }
  }
