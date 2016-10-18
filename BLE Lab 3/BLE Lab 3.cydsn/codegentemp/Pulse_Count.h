/*******************************************************************************
* File Name: Pulse_Count.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Pulse_Count_H)
#define CY_ISR_Pulse_Count_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Pulse_Count_Start(void);
void Pulse_Count_StartEx(cyisraddress address);
void Pulse_Count_Stop(void);

CY_ISR_PROTO(Pulse_Count_Interrupt);

void Pulse_Count_SetVector(cyisraddress address);
cyisraddress Pulse_Count_GetVector(void);

void Pulse_Count_SetPriority(uint8 priority);
uint8 Pulse_Count_GetPriority(void);

void Pulse_Count_Enable(void);
uint8 Pulse_Count_GetState(void);
void Pulse_Count_Disable(void);

void Pulse_Count_SetPending(void);
void Pulse_Count_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Pulse_Count ISR. */
#define Pulse_Count_INTC_VECTOR            ((reg32 *) Pulse_Count__INTC_VECT)

/* Address of the Pulse_Count ISR priority. */
#define Pulse_Count_INTC_PRIOR             ((reg32 *) Pulse_Count__INTC_PRIOR_REG)

/* Priority of the Pulse_Count interrupt. */
#define Pulse_Count_INTC_PRIOR_NUMBER      Pulse_Count__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Pulse_Count interrupt. */
#define Pulse_Count_INTC_SET_EN            ((reg32 *) Pulse_Count__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Pulse_Count interrupt. */
#define Pulse_Count_INTC_CLR_EN            ((reg32 *) Pulse_Count__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Pulse_Count interrupt state to pending. */
#define Pulse_Count_INTC_SET_PD            ((reg32 *) Pulse_Count__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Pulse_Count interrupt. */
#define Pulse_Count_INTC_CLR_PD            ((reg32 *) Pulse_Count__INTC_CLR_PD_REG)



#endif /* CY_ISR_Pulse_Count_H */


/* [] END OF FILE */
