/*
 * STM32F401RE_GPIO.c
 *
 *  Created on: 18-Aug-2026
 *      Author: ADMIN
 */

#include "STM32F401RE_GPIO.h"
#include "STM32F401RE.h"





void GPIO_Perclkcontrol(GPIO_RegDef_t *pGPIOx, uint8_t EnORDi)
{
 if (EnORDi == ENABLE)
 {
	 if (pGPIOx == GPIOA)
	 {
		 GPIOA_PCLK_EN();
	 }
	 else if (pGPIOx == GPIOB)
		 {
			 GPIOB_PCLK_EN();
		 }
	 else if (pGPIOx == GPIOC)
		 {
			 GPIOC_PCLK_EN();
		 }
	 else if (pGPIOx == GPIOD)
		 {
			 GPIOD_PCLK_EN();
		 }
	 else  if (pGPIOx == GPIOE)
		 {
			 GPIOE_PCLK_EN();
		 }
	 else  if (pGPIOx == GPIOH)
		 {
			 GPIOH_PCLK_EN();
		 }
 }
 else
 {

		 if (pGPIOx == GPIOA)
		 {
			 GPIOA_PCLK_DS();
		 }
		 else if (pGPIOx == GPIOB)
			 {
				 GPIOB_PCLK_DS();
			 }
		 else if (pGPIOx == GPIOC)
			 {
				 GPIOC_PCLK_DS();
			 }
		 else if (pGPIOx == GPIOD)
			 {
				 GPIOD_PCLK_DS();
			 }
		 else  if (pGPIOx == GPIOE)
			 {
				 GPIOE_PCLK_DS();
			 }
		 else  if (pGPIOx == GPIOH)
			 {
				 GPIOH_PCLK_DS();
			 }
	 }
 }

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    if (pGPIOHandle == 0 || pGPIOHandle->pGPIOx == 0 ||
        pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber > GPIO_PIN_NO_15)
    {
        return;
    }

    GPIO_PinConfig_t *config = &pGPIOHandle->GPIO_PinConfig;
    GPIO_RegDef_t *gpio = pGPIOHandle->pGPIOx;
    uint32_t pin = config->GPIO_PinNumber;
    uint32_t shift = 2U * pin;
    uint32_t pinMask = 1UL << pin;
    uint32_t fieldMask = 0x3UL << shift;

    if (config->GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
        gpio->MODER = (gpio->MODER & ~fieldMask) |
                      (((uint32_t)config->GPIO_PinMode << shift) & fieldMask);
    }
    else if (config->GPIO_PinMode >= GPIO_MODE_IT_FT &&
             config->GPIO_PinMode <= GPIO_MODE_IT_RFT)
    {
        /* EXTI pins must be configured as GPIO inputs (MODER = 00). */
        gpio->MODER &= ~fieldMask;

        if (config->GPIO_PinMode == GPIO_MODE_IT_FT || config->GPIO_PinMode == GPIO_MODE_IT_RFT)
            EXTI->FTSR |= pinMask;
        else
            EXTI->FTSR &= ~pinMask;

        if (config->GPIO_PinMode == GPIO_MODE_IT_RT || config->GPIO_PinMode == GPIO_MODE_IT_RFT)
            EXTI->RTSR |= pinMask;
        else
            EXTI->RTSR &= ~pinMask;

        uint32_t exticrIndex = pin / 4U;
        uint32_t exticrShift = 4U * (pin % 4U);
        uint32_t exticrMask = 0xFUL << exticrShift;
        uint32_t portCode = GPIO_BASEADDR_To_code(gpio);
        SYSCFG_PCLK_EN();
        SYSCFG->EXTICR[exticrIndex] =
            (SYSCFG->EXTICR[exticrIndex] & ~exticrMask) |
            ((portCode << exticrShift) & exticrMask);
        EXTI->IMR |= pinMask;
    }
    else
    {
        return;
    }

    gpio->OSPEEDR = (gpio->OSPEEDR & ~fieldMask) |
                    (((uint32_t)config->GPIO_PinSpeed << shift) & fieldMask);
    gpio->PUPDR = (gpio->PUPDR & ~fieldMask) |
                  (((uint32_t)config->GPIO_PinPuPdControl << shift) & fieldMask);
    gpio->OTYPER = (gpio->OTYPER & ~pinMask) |
                   (((uint32_t)config->GPIO_PinOPType << pin) & pinMask);

    if (config->GPIO_PinMode == GPIO_MODE_ALTFN)
    {
        uint32_t afrIndex = pin / 8U;
        uint32_t afrShift = 4U * (pin % 8U);
        uint32_t afrMask = 0xFUL << afrShift;
        gpio->AFR[afrIndex] = (gpio->AFR[afrIndex] & ~afrMask) |
                              (((uint32_t)config->GPIO_PinAltfunMode << afrShift) & afrMask);
    }

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if (pGPIOx == GPIOA)

		    {

		        GPIOA_REG_RESET();

		    }

		    else if (pGPIOx == GPIOB)

		    {

		        GPIOB_REG_RESET();

		    }

		    else if (pGPIOx == GPIOC)

		    {

		        GPIOC_REG_RESET();

		    }

		    else if (pGPIOx == GPIOD)

		    {

		        GPIOD_REG_RESET();

		    }

		    else if (pGPIOx == GPIOE)

		    {

		        GPIOE_REG_RESET();

		    }

		    else if (pGPIOx == GPIOH)

		    {

		        GPIOH_REG_RESET();
}
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber , uint8_t Value)
{
	{
		if(Value == GPIO_PIN_SET)
		{
			pGPIOx->ODR |= (1<<PinNumber);
		}
		else
		{
			pGPIOx->ODR &= ~(1<<PinNumber);
		}

	}
}
	void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
	{
		pGPIOx->ODR = Value;

	}
	void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
	{

		pGPIOx->ODR ^= (1<<PinNumber);

	}

	/* GPIO Read */
	uint16_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx , uint8_t PinNumber)
	{
		uint8_t value;
		value = ((uint8_t)(pGPIOx->IDR >> PinNumber)& 0x00000001);
		return value;

	}

	uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
	{
		uint16_t value;
		value = ((uint16_t)(pGPIOx->IDR));
		return value;


	}




/* GPIO Interrupt */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDi)
{
	if (IRQNumber >= 96)
		return;

	uint32_t bank = IRQNumber / 32U;
	uint32_t bit = 1UL << (IRQNumber % 32U);
	__vo uint32_t *nvicRegister;

	if (EnOrDi == ENABLE)
		nvicRegister = NVIC_ISER0 + bank;
	else
		nvicRegister = ((__vo uint32_t *)0xE000E180U) + bank;

	*nvicRegister = bit;
}


void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_section = IRQNumber % 4;
    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);

    *(NVIC_PR_BASE_ADDR + iprx) &= ~(0xFU << shift_amount);
    *(NVIC_PR_BASE_ADDR + iprx) |= (IRQPriority << shift_amount);

}

void  GPIO_IRQHandling(uint8_t PinNumber)
{
	// Check whether interrupt is actually pending
	    if(EXTI->PR & (1U << PinNumber))
	    {
	        // Clear the pending bit (Write 1 to Clear)
	        EXTI->PR = (1U << PinNumber);
	    }

}


