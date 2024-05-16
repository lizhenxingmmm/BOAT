/**
 * @Author: Li Zhenxing
 * @Date: 2024/5/16 16:18:01
 * @LastEditors: Li Zhenxing
 * @LastEditTime: 2024/5/16 16:18:01
 * Description: 
 * Copyright: Copyright (©)}) 2024 Li Zhenxing. All rights reserved.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

void StartInsTask(void const * argument)
{
    for(;;)
    {
        osDelay(1);
    }
}
