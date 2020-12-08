/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * vmuart.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#include "vmuart.h"
#include "dcl.h"

VMINT32 vm_uart_get_handle(vm_port port)
{
    VMINT32 handle = 0;
    handle = DclSerialPort_Open(port, 0);
    
    return handle;
}

VMINT32 vm_uart_open(vm_port port)
{
    UART_CTRL_OPEN_T data;
    VMINT32 handle = 0;
    VMINT32 result = 0;
    handle = vm_uart_get_handle(port);
    data.u4OwenrId = MOD_MMI;
    result = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) &data);
    if(result != 0)
    {
        handle = 0;
    }
    return handle;
}

VMUINT16 vm_read_from_uart(VMINT32 handle, VMUINT8 *buffer, VMUINT16 length)
{
    UART_CTRL_GET_BYTES_T data;
    data.u2Length = length;
    data.u4OwenrId = MOD_MMI;
    data.puBuffaddr = buffer;
    DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*) &data);
    
    return data.u2RetSize;
}

VMUINT16 vm_write_to_uart(VMINT32 handle, VMUINT8 *buffer, VMUINT16 length)
{
    UART_CTRL_PUT_BYTES_T data;
    data.u2Length = length;
    data.u4OwenrId = MOD_MMI;
    data.puBuffaddr = buffer;
    DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) &data);
    
    return data.u2RetSize;
}

VMINT32 vm_uart_close(VMINT32 handle)
{
    UART_CTRL_CLOSE_T data;
    VMINT32 status = 0;
    data.u4OwenrId = MOD_MMI;
    status = DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*) &data);
    
    return ((status == 0)?(TRUE):(FALSE));
}
