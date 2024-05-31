// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Aman Murad, UET Lahore
// Date: 31.5.2024

#include <inttypes.h>
#include "gpio.h"



/**********************************************************************//**
 * Initialize GPIO module.
 **************************************************************************/

void Uetrv32_Gpio_Init(void){

}

/**********************************************************************//**
 * GPIO Set Direction to Pin. This is a blocking function.
 **************************************************************************/

void Uetrv32_Gpio_SetDirection(uint32_t pin, uint32_t direction) {
    if (direction) {
        // Set direction of the specific pin to output
        GPIO_Module.dir = GPIO_Module.dir | pin;
    } else {
        // Set direction of the specific pin to input
        GPIO_Module.dir = GPIO_Module.dir & ~pin;
    }
}

/**********************************************************************//**
 * GPIO Write Data to Pins. This is a blocking function.
 **************************************************************************/

void Uetrv32_Gpio_WriteData(uint32_t pin, uint32_t data) {
    if (data) {
        // Set the specific pin to high
        GPIO_Module.data = GPIO_Module.data | pin;
    } else {
        // Set the specific pin to low
        GPIO_Module.data = GPIO_Module.data & ~pin;
    }
}

/**********************************************************************//**
 * GPIO Read Data from Pin. This is a blocking function.
 **************************************************************************/

uint32_t Uetrv32_Gpio_ReadData(uint32_t pin) {
    // Return the state of the specific pin
    return GPIO_Module.data & pin;
}

/**********************************************************************//**
 * GPIO Interrupt Control. This is a blocking function.
 **************************************************************************/

// void Uetrv32_Gpio_Interrupt(void){
//     //GPIO Interupt enable
//     GPIO_Module.ie      = GPIO_Module.ie | GPIO_Int;
//     //GPIO Interupt Level Set
//     GPIO_Module.int_lvl = GPIO_Module.int_lvl | GPIO_Int_Lvl;
//     //GPIO Interupt Pending Cleared
//     GPIO_Module.ip      = GPIO_Module.ip & ~GPIO_Int;

//     // IRQ_CODE_GPIO       = 0x18;

//     // IRQ_CODE_M_EXTERNAL = 0x11;
// }