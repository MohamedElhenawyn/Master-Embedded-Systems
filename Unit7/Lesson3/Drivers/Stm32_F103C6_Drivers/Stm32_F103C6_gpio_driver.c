/*
 * Stm32_F103C6_gpio_driver.c
 *
 *  Created on: Apr 5, 2025
 *      Author: Mohamed Elhenawy
 */


#include "Stm32_F103C6_gpio_driver.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber){
	switch(PinNumber){
	case GPIO_PIN_0:
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_1:
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_2:
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_3:
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_4:
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_5:
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_6:
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_7:
	case GPIO_PIN_15:
		return 28;
		break;
	}
}

	/**================================================================
	 * @Fn			- MCAL_GPIO_Init
	 * @brief 		- Reset the GPIOx	PINy according to the specific parameters in the pinConfig
	 * @param[in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
	 * @retval		- none
	 * Note			- none
	 */
	void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinCfg)
	{
		//(GPIOx_CRL) configures pins from 0 till 7
		//(GPIOx_CRH) configures pins from 8 till 15
		volatile uint32_t * configRegister = NULL;
		uint8_t Pos = 0;
		uint8_t pinConfig = 0;
		configRegister = (PinCfg->GPIO_PinNumber < GPIO_PIN_8 )? &GPIOx->CRL:&GPIOx->CRH;
		Pos = Get_CRLH_Position(PinCfg->GPIO_PinNumber);
		// clear CNF0[1:0] MODE0[1:0] based on the pin position
		(*configRegister) &= ~(0xF << Pos);

		// if pin is output
		if((PinCfg->GPIO_MODE == GPIO_MODE_OUT_AF_OD) || (PinCfg->GPIO_MODE == GPIO_MODE_OUT_AF_PP)
				|| (PinCfg->GPIO_MODE == GPIO_MODE_OUT_OD) || (PinCfg->GPIO_MODE == GPIO_MODE_OUT_PP))
		{
			//CNF								//MODE
			pinConfig = (((PinCfg->GPIO_MODE - 4) << 2) | ((PinCfg->GPIO_OUTPUT_SPEED) & 0x0f));

		}else
		{
			// input
			if((PinCfg->GPIO_MODE == GPIO_MODE_Analog) || (PinCfg->GPIO_MODE == GPIO_MODE_IN_FLO))
			{
				pinConfig = (PinCfg->GPIO_MODE << 2 | 0x0) & 0x0f;
			}else if ((PinCfg->GPIO_MODE == GPIO_MODE_IN_AF))
			{
				pinConfig = (GPIO_MODE_IN_FLO << 2| 0x0) & 0x0f;
			}else // PU PD Input
			{
				pinConfig = (GPIO_MODE_IN_PU << 2| 0x0) & 0x0f;
				if(PinCfg->GPIO_MODE == GPIO_MODE_IN_PU)
				{
					GPIOx->ODR |=  PinCfg->GPIO_PinNumber;
				}else
				{
					GPIOx->ODR &= ~(PinCfg->GPIO_PinNumber);
				}
			}
		}
		(*configRegister) |= pinConfig << Pos;
	}
	/**================================================================
	 * @Fn			- MCAL_GPIO_DeInit
	 * @brief 		- deInitializes the GPIOx	PINy according to the specific parameters in the pinConfig
	 * @param[in] 	-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
	 * @param[in] 	-PinCfg: pointer to GPIO_PINConfig_t structure that contains
	 * 					the configuration information for specific GPIO peripheral
	 * @retval		-none
	 * Note			-A,B fully included, C,D Partial included  and E Not included in LQFP48 package
	 */
	void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx)
	{
		if(GPIOx == GPIOA)
		{
			RCC->APB2RSTR |= (1<<2);
			RCC->APB2RSTR &= ~(1<<2);
		}
		else if(GPIOx == GPIOB)
		{
			RCC->APB2RSTR |= (1<<3);
			RCC->APB2RSTR &= ~(1<<3);
		}
		else if(GPIOx == GPIOC)
		{
			RCC->APB2RSTR |= (1<<4);
			RCC->APB2RSTR &= ~(1<<4);
		}
		else if(GPIOx == GPIOD)
		{
			RCC->APB2RSTR |= (1<<5);
			RCC->APB2RSTR &= ~(1<<5);
		}
		else if(GPIOx == GPIOE)
		{
			RCC->APB2RSTR |= (1<<6);
			RCC->APB2RSTR &= ~(1<<6);
		}

	}


	/**================================================================
	 * @Fn			- MCAL_GPIO_ReadPin
	 * @brief 		- Read specific pin
	 * @param[in] 	-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
	 * @param[in] 	-PinNum: set pinNumber according @ref GPIO_PINS_define
	 * @retval		-the input pin value (two values based on  )
	 * Note			-none
	 */
	uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t PinNum)
	{
		uint8_t bitStatus;
		if(((GPIOx->IDR) &PinNum) != (uint32_t)GPIO_PIN_Reset)
		{
			bitStatus = GPIO_PIN_SET;
		}
		else
		{
			bitStatus = GPIO_PIN_Reset;
		}
		return bitStatus;
	}

	/**================================================================
	 * @Fn			- MCAL_GPIO_ReadPort
	 * @brief 		- Read the input port value
	 * @param[in] 	-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
	 * @param[in] 	-PinNum: set pinNumber according @ref GPIO_PINS_define
	 * @retval		-the input port value
	 * Note			-none
	 */
	uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
	{
		uint16_t portValue;
		portValue = (uint16_t)GPIOx->IDR;
		return portValue;
	}
	/**================================================================
	 * @Fn			- MCAL_GPIO_WritePin
	 * @brief 		- write the input port value
	 * @param[in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
	 * @param[in] 	- PinNum: set pinNumber according @ref GPIO_PINS_define
	 * @param[in] 	- Value: the pin value
	 * @retval		- none
	 * Note			- none
	 */
	void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t PinNum,uint8_t Value)
	{
		if(Value != GPIO_PIN_Reset)
		{
			//		GPIOx->ODR |= PinNum;
			//		or
			GPIOx->BSRR = (uint32_t)PinNum;
		}
		else
		{
			//		GPIOx->ODR &= ~PinNum;
			//		or
			GPIOx->BRR = (uint32_t)PinNum;

		}
	}
	/**================================================================
	 * @Fn			- MCAL_GPIO_WritePort
	 * @brief 		- write the input port value
	 * @param[in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
	 * @param[in] 	- Value: the port value
	 * @retval		- none
	 * Note			- none
	 */
	void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx, uint16_t Value)
	{
		GPIOx->ODR = (uint32_t)Value;
	}
	/**================================================================
	 * @Fn			- MCAL_GPIO_TogglePin
	 * @brief 		- toggle the input port value
	 * @param[in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
	 * @param[in] 	- PinNum: set pinNumber according @ref GPIO_PINS_define
	 * @retval		- none
	 * Note			- none
	 */
	void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t PinNum)
	{
		GPIOx->ODR ^= PinNum;
	}
	/**================================================================
	 * @Fn			- MCAL_GPIO_LockPin
	 * @brief 		- the locking mechanism allows the IO configurations to be frozen
	 * @param[in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
	 * @param[in] 	- PinNum: set pinNumber according @ref GPIO_PINS_define
	 * @retval		- Ok if pin config is locked or error if pin not locked (ok & error are defined @ref GPIO_RETURN_LOCK)
	 * Note			- none
	 */
	uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t PinNum)
	{
		volatile uint32_t tmp = 1 << 16;
		tmp |= PinNum;
		GPIOx->LCKR = tmp;
		GPIOx->LCKR = PinNum;
		GPIOx->LCKR = tmp;
		tmp = GPIOx->LCKR;
		if((uint32_t)(GPIOx->LCKR & 1 << 16))
		{
			return GPIO_RETURN_LOCK_ENABLED;
		}else
		{
			return GPIO_RETURN_LOCK_ERROR;
		}
	}


