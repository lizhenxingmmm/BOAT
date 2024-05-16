/**
 * @Author: Li Zhenxing
 * @Date: 2024/5/16 15:08:57
 * @LastEditors: Li Zhenxing
 * @LastEditTime: 2024/5/16 15:08:57
 * Description: 
 * Copyright: Copyright (©)}) 2024 Li Zhenxing. All rights reserved.
 */

#include "mc6c.h"

/**
 * @return state 是否丢包
*/
mc6c_data_state MC6C_decode(uint8_t *rxBuf,mc6c_data* mc6c_t)
{
    if(rxBuf[0]!=0x0f)
    {
        return LOSE_PACK;
    }
    mc6c_t->ch1 = (rxBuf[0+1] | (rxBuf[1+1] << 8)) & 0x07ff;        
    mc6c_t->ch2 = (((rxBuf[1+1] >> 3)&0xff) | (rxBuf[2+1] << 5)) & 0x07ff; 
    mc6c_t->ch3 = (((rxBuf[2+1] >> 6)&0xff) | (rxBuf[3+1] << 2) |         
                         (rxBuf[4+1] << 10)) &0x07ff;
    mc6c_t->ch4 = (((rxBuf[4+1] >> 1)&0xff) | (rxBuf[5+1] << 7)) & 0x07ff; 
    mc6c_t->ch5 = ((rxBuf[5+1] >> 4) & 0x0003);                  
    mc6c_t->ch6 = ((rxBuf[5+1] >> 4) & 0x000C) >> 2;
    return ALL_IS_WELL;
}
