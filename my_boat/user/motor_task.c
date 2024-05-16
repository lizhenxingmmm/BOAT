/**
 * @Author: Li Zhenxing
 * @Date: 2024/5/16 16:18:58
 * @LastEditors: Li Zhenxing
 * @LastEditTime: 2024/5/16 16:18:58
 * Description: 
 * Copyright: Copyright (©)}) 2024 Li Zhenxing. All rights reserved.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"


void StartMotorTask(void const * argument)
{
    for(;;)
    {
        osDelay(5);
    }
}
