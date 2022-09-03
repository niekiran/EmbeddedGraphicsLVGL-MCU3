/*
 * arm_cm7.h
 *
 *  Created on: Apr 22, 2022
 *      Author: nieki
 */

#ifndef ARM_CM4_H_
#define ARM_CM4_H_


#define		 REG(x) 		  				(*(volatile uint32_t*)(x))

//#define SHCSR 		  				REG(0xE000ED24U)
#define SHCSR_BIT_USGFAULTENA 		18U
#define SHCSR_BIT_BUSFAULTENA 		17U
#define SHCSR_BIT_MEMFAULTENA 		16U

/*NVIC*/
#define NVIC_ISER		    0xE000E100U
#define NVIC_ISER0 			REG(NVIC_ISER)
#define NVIC_ISER1 			REG(NVIC_ISER+4U)
#define NVIC_ISER2 			REG(NVIC_ISER+8U)
#define NVIC_ISER3 			REG(NVIC_ISER+CU)
#define NVIC_ISER4 			REG(NVIC_ISER+0x10U)

#define NVIC_ICER			0xE000E180U
#define NVIC_ICER0 			REG(NVIC_ICER)
#define NVIC_ICER1 			REG(NVIC_ICER+4U)
#define NVIC_ICER2 			REG(NVIC_ICER+8U)
#define NVIC_ICER3 			REG(NVIC_ICER+CU)
#define NVIC_ICER4 			REG(NVIC_ICER+0x10U)

#define NVIC_IPR			0xE000E400U
#define NVIC_IPR0           REG(NVIC_IPR+0U)
#define NVIC_IPR1 			REG(NVIC_IPR+4U)
#define NVIC_IPR2 			REG(NVIC_IPR+8U)
#define NVIC_IPR3 			REG(NVIC_IPR+CU)
#define NVIC_IPR4 			REG(NVIC_IPR+0x10U)

/*Application Interrupt and Reset Control Register, AIRCR*/
//#define AIRCR  					REG(0xE000ED0CU)
#define AIRCR_BIT_PRIGROUP_10_8  8u

/*Systic*/
//#define SCSR					REG(0xE000E010U)
//#define SRVR 					REG(0xE000E014U)
//#define SCVR					REG(0xE000E018U)

#define SysTick_CTRL_CLKSOURCE_Pos          2U                                            /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)

#define SysTick_CTRL_TICKINT_Pos            1U                                            /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */

#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL /*<< SysTick_CTRL_ENABLE_Pos*/)
#endif /* ARM_CM4_H_ */
