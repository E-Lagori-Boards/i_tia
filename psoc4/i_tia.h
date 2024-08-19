/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef I_TIA_H
#define  I_TIA_H

#include "DIGIPOT\digipot.h"

struct i_tia{
    float  maxR;
    struct digipot d;
};

void itia_init(struct i_tia *p, float maxR, int address);
void itia_setgain(struct i_tia *p, uint8_t channo,float gain);
float itia_presentgain(struct i_tia *p, uint8_t channo);

#endif
/* [] END OF FILE */
