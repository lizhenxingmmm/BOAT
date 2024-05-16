/**
 * @Author: Li Zhenxing
 * @Date: 2024/5/16 15:09:05
 * @LastEditors: Li Zhenxing
 * @LastEditTime: 2024/5/16 15:09:05
 * Description: 
 * Copyright: Copyright (©)}) 2024 Li Zhenxing. All rights reserved.
 */

#ifndef MC6C_H
#define MC6C_H

typedef short int16_t;
typedef unsigned char uint8_t;
typedef enum 
{
    LOSE_PACK =0,
    ALL_IS_WELL=1
}mc6c_data_state;

typedef struct mc6c
{
    int16_t ch1;
    int16_t ch2;
    int16_t ch3;
    int16_t ch4;
    int16_t ch5;
    int16_t ch6;
}mc6c_data;
mc6c_data_state MC6C_decode(uint8_t *rxBuf,mc6c_data* mc6c_t);


#endif
