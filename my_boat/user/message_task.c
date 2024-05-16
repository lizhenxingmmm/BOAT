/**
 * @Author: Li Zhenxing
 * @Date: 2024/5/16 15:24:51
 * @LastEditors: Li Zhenxing
 * @LastEditTime: 2024/5/16 15:24:51
 * Description: 
 * Copyright: Copyright (©)}) 2024 Li Zhenxing. All rights reserved.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

#include "usart.h"
#include "dma.h"
#include "mc6c.h"
uint8_t uart2_rx_buf[30];
mc6c_data mc6c_data_pack;

void Message_Init(void);

void StartMessageTask(void const * argument)
{
    Message_Init();
    for(;;)
    {
        osDelay(10);
    }
}

void Message_Init(void)
{
    HAL_UARTEx_ReceiveToIdle_DMA(&huart2,uart2_rx_buf,25);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if(huart==&huart1)
    {

    }
    if(huart==&huart2)
    {
        if(MC6C_decode(uart2_rx_buf,&mc6c_data_pack))
        {
            ;
        }
        HAL_UARTEx_ReceiveToIdle_DMA(&huart2,uart2_rx_buf,25);
    }
    if(huart==&huart6)
    {
        
    }
}
