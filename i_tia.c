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
#include "i_tia.h"

/// @brief Initialise the TIA module
/// @param p Pointer to structure holding the data about the module
/// @param maxR Maximum gain of the TIA
/// @param address Address of the module
void itia_init(struct i_tia *p, float maxR, int address){
    p->maxR = maxR;
    digipot_init(&(p->d), address);
}

/// @brief Set gain of TIA
/// @param p Pointer to structure holding the data about the module
/// @param channo Channel no
/// @param gain Gain of the TIA
void itia_setgain(struct i_tia *p, uint8_t channo,float gain){
    float R = 0;
    R = gain;
    R = (R>p->maxR)?p->maxR:R;
    R = (R<0)?0:R;
    digipot_Write_RDAC(&(p->d),channo, 255-(int)(R/(p->maxR+3340)*256.0));
}

/// @brief Present gain of TIA
/// @param p Pointer to structure holding the data about the module
/// @param channo Channel no
/// @return Present gain setting
float itia_presentgain(struct i_tia *p, uint8_t channo){
    float R = 255 - digipot_Readback_RDAC(&(p->d),channo);
    if (R>=0) R = R/256.0*(p->maxR+3340);
    return(R);
}
/* [] END OF FILE */
