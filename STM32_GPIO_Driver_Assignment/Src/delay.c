/*
 * delay.c
 *
 *  Created on: 24-Sept-2026
 *      Author: ADMIN
 */
#include <DELAY.h>
#include <stdint.h>

void delay(uint32_t count)
{
    volatile uint32_t i;

    for(i = 0; i < count; i++);
}

