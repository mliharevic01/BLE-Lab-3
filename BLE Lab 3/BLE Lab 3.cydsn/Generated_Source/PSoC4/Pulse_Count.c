/*******************************************************************************
* File Name: Pulse_Count.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <Pulse_Count.h>

#if !defined(Pulse_Count__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START Pulse_Count_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: Pulse_Count_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_Start(void)
{
    /* For all we know the interrupt is active. */
    Pulse_Count_Disable();

    /* Set the ISR to point to the Pulse_Count Interrupt. */
    Pulse_Count_SetVector(&Pulse_Count_Interrupt);

    /* Set the priority. */
    Pulse_Count_SetPriority((uint8)Pulse_Count_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Pulse_Count_Enable();
}


/*******************************************************************************
* Function Name: Pulse_Count_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    Pulse_Count_Disable();

    /* Set the ISR to point to the Pulse_Count Interrupt. */
    Pulse_Count_SetVector(address);

    /* Set the priority. */
    Pulse_Count_SetPriority((uint8)Pulse_Count_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Pulse_Count_Enable();
}


/*******************************************************************************
* Function Name: Pulse_Count_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_Stop(void)
{
    /* Disable this interrupt. */
    Pulse_Count_Disable();

    /* Set the ISR to point to the passive one. */
    Pulse_Count_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: Pulse_Count_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for Pulse_Count.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(Pulse_Count_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START Pulse_Count_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: Pulse_Count_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling Pulse_Count_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use Pulse_Count_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + Pulse_Count__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: Pulse_Count_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress Pulse_Count_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + Pulse_Count__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: Pulse_Count_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling Pulse_Count_Start
*   or Pulse_Count_StartEx will override any effect this method would 
*   have had. This method should only be called after Pulse_Count_Start or 
*   Pulse_Count_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((Pulse_Count__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *Pulse_Count_INTC_PRIOR = (*Pulse_Count_INTC_PRIOR & (uint32)(~Pulse_Count__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Pulse_Count_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 Pulse_Count_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((Pulse_Count__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*Pulse_Count_INTC_PRIOR & Pulse_Count__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: Pulse_Count_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_Enable(void)
{
    /* Enable the general interrupt. */
    *Pulse_Count_INTC_SET_EN = Pulse_Count__INTC_MASK;
}


/*******************************************************************************
* Function Name: Pulse_Count_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 Pulse_Count_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*Pulse_Count_INTC_SET_EN & (uint32)Pulse_Count__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: Pulse_Count_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_Disable(void)
{
    /* Disable the general interrupt. */
    *Pulse_Count_INTC_CLR_EN = Pulse_Count__INTC_MASK;
}


/*******************************************************************************
* Function Name: Pulse_Count_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_SetPending(void)
{
    *Pulse_Count_INTC_SET_PD = Pulse_Count__INTC_MASK;
}


/*******************************************************************************
* Function Name: Pulse_Count_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Pulse_Count_ClearPending(void)
{
    *Pulse_Count_INTC_CLR_PD = Pulse_Count__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
