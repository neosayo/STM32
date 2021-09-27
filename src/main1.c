#include "stm32l1xx.h"

/* variables-----------------------------------------------------------------*/

/*structures------------------------------------------------------------------*/

int main(void)
{
//****************************************************
//Validation des horloges
//****************************************************
RCC->AHBENR  |= 1           ;   //valide horloge port A
RCC->APB1ENR |= 0x80000000 ; // Valide Horloge Comparateur


//****************************************************
//GPIOA->PIN 5 Sortie  LED verte
//****************************************************
GPIOA->MODER =0x55555555                    ;   //bits 0 à 15 sorties
GPIOA->OSPEEDR =0x55555555                  ;  //Low speed
GPIOA->OTYPER =0x00000000                   ;   //  sorties push pull

COMP->CSR = 0x00100000						; // atribution Vref
RI->ASCR2 = 0x00000010						; // atribution entrée + PB4

while(1)
{
	if ((COMP->CSR & 0x00002000 ) != 0)
	{GPIO_SetBits (GPIOA, 0x020) ;
	}
    else
 	{GPIOA->ODR &= 0xFFFFFFDF ;
 	}
  }
}
