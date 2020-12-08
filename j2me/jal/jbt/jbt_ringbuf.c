/***************************************************************************
 *
 * File:
 *     $Workfile:ring.c$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *      This file contains a collection of utilities to manage ring- or
 *      circular buffers.
 *
 * Copyright 1999-2005 Extended Systems, Inc.
 * Portions copyright 2005 iAnywhere Solutions, Inc.
 * All rights reserved. All unpublished rights reserved.
 *
 * Unpublished Confidential Information of iAnywhere Solutions, Inc.  
 * Do Not Disclose.
 *
 * No part of this work may be used or reproduced in any form or by any 
 * means, or stored in a database or retrieval system, without prior written 
 * permission of iAnywhere Solutions, Inc.
 * 
 * Use of this work is governed by a license granted by iAnywhere Solutions, 
 * Inc.  This work contains confidential and proprietary information of 
 * iAnywhere Solutions, Inc. which is protected by copyright, trade secret, 
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/
#ifdef __SUPPORT_JBT__
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"       /* message and module IDs */
#include "stack_msgs.h" /* enum for message IDs */
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"     /* type of system module components */
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "uart_sw.h"
#include "bluetooth_struct.h"
#include "bluetooth_bm_struct.h"
#include "mmiapi_bt_struct.h"
#include "j2me_trace.h"
#include "jbt_interface.h"
#include "jbt_internal.h"

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif 
#ifndef __USE_BT_RING_BUF_API__
static kal_int16 JBTRING_ContigDataLen(JBTRingBuf *ring);

/*---------------------------------------------------------------------------
 * Initialize a ring buffer structure.
 *
 * Context: 
 *    Args: ring - pointer to RingBuf struct
 *             buf  - allocated buffer which will become the ring buffer
 *             len  - length of buf
 *  Return: 
 */


/*****************************************************************************
 * FUNCTION
 *  JBTRING_BufInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ring        [IN]        
 *  buf         [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void JBTRING_BufInit(JBTRingBuf *ring, char buf[], kal_int16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ring->pStart = (kal_uint8*) buf;
    ring->pEnd = (kal_uint8*) buf + len;    /* 'end' is 1 beyond of the buffer */
    JBTRING_BufFlush(ring);
}

/*---------------------------------------------------------------------------
 * JBTRING_BufFlush() 
 *      Clear data from a ring buffer.
 *
 * Requires:
 *     
 * Parameters:
 *      Pointer to RingBuf struct.
 *
 * Returns:
 */


/*****************************************************************************
 * FUNCTION
 *  JBTRING_BufFlush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ring        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void JBTRING_BufFlush(JBTRingBuf *ring)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ring->pRead = ring->pStart;
    ring->pWrite = ring->pStart;

}

/*---------------------------------------------------------------------------
 * Copy data into the ring buffer from caller's buffer.
 * Does NOT overwrite data already in the buffer.
 *
 * Context: 
 *    Args: ring - pointer to RingBuf struct
 *             buf  - caller's destination buffer
 *             wanted_to_write_len  - max amount to copy
 *  Return: actual amount copied to buf
 */


/*****************************************************************************
 * FUNCTION
 *  JBTRING_WriteData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ring                    [OUT]       
 *  buf                     [IN]        
 *  wanted_to_write_len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 JBTRING_WriteData(JBTRingBuf *ring, char *buf, kal_int16 wanted_to_write_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 actual_written_len = 0, freespace = 0;
    kal_uint8 *pPrevWrite = ring->pWrite;
    kal_uint8 *pPrevRead = ring->pRead;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wanted_to_write_len < 0)
    {
        /* MAX signed 16bits value = POWER(2,15)-1 = 32767 */  
        wanted_to_write_len = 32767;
    }

    kal_trace(TRACE_JBT_GROUP, FUNC_JBT_RING_WRITE_DATA_INFO, ring->pStart, ring->pEnd, pPrevRead, pPrevWrite);

    /* Directly using the following codes to compute the freespace instead of the function RING_FreeSpace() */
    if (pPrevWrite >= pPrevRead)
    {
        /* case 1: pWrite >= pRead */
        /* pWrite == pRead: It means that the buffer is empty */

        /*
         * Because the context switch may happens before updating pWrite
         * So copy data to ring buffer must be one action, not use one byte by one byte 
         * If the wrapper case happens, just copy first segment data into ring buffer, not do twice pWrite pointer's update
         * --> This will increase the complexity of context switch problem
         */

        /*
         * case 1 
         *      [             |*********|           ]
         *                 pRead        pWrite 
         */

        freespace = ring->pEnd - pPrevWrite;

        /*
         * [Important!]  Add by mtk01411: 2007-1016
         * Consider one scenario:
         * pPrevRead is at start position, pPrevWrite > pPrevRead:
         *  
         * [***********|           ]
         * pRead        pWrite      pEnd
         * pStart
         * 
         * Currently, some data is not sent by BT task as the above figure shown.
         * Now, do write action, if freespace = pEnd - pWrite, then wirtes data to fill with all freespace,
         * pWrite is wrapped to pStart
         * Context switch happens: pRead == pWrite: BT task misunstands no data is needed to send!!
         * Context switch happens: PWrite continous to write and overwrite the data not yet send!
         * --> This is why the sniffer log finds that some data lost !! 
         * Solution: If pPrevRead is at start positon, (freespace = freespace -1)
         */

        if (pPrevRead == ring->pStart)
        {
            /* 
             * [***********|           ]
             * pRead         pWrite      pEnd
             * pStart
             */

            freespace -= 1;
            if (freespace > wanted_to_write_len)
            {
                memcpy(pPrevWrite, buf, wanted_to_write_len);
                actual_written_len = wanted_to_write_len;
                pPrevWrite += actual_written_len;
            }
            else
            {
                /* freespace <= wanted_to_write_len */
                memcpy(pPrevWrite, buf, freespace);
                actual_written_len = freespace;
                /* pWrite pointer is wrapped to the start position of this Ring buffer */
                pPrevWrite += actual_written_len;
            }

        }
        else
        {
            /*
             * case 1 
             *      [             |*********|           ]
             *                 pRead        pWrite 
             */

            if (freespace >= wanted_to_write_len)
            {
                memcpy(pPrevWrite, buf, wanted_to_write_len);
                actual_written_len = wanted_to_write_len;
                pPrevWrite += actual_written_len;
                if (pPrevWrite == ring->pEnd)
                {
                    pPrevWrite = ring->pStart;
                }
            }
            else
            {
                /* Two memcpy is necessary */
                kal_int16 second_freespace = pPrevRead - ring->pStart - 1;
                kal_int16 second_wanted_write_len = 0;

                memcpy(pPrevWrite, buf, freespace);
                actual_written_len = freespace;
                pPrevWrite += actual_written_len;

                /* Wrap to start position anc continous to write data! */
                pPrevWrite = ring->pStart;
                second_wanted_write_len = wanted_to_write_len - actual_written_len;
                if (second_freespace >= second_wanted_write_len)
                {
                    memcpy(pPrevWrite, buf + actual_written_len, second_wanted_write_len);
                    /* Add this time's written len */
                    actual_written_len += second_wanted_write_len;
                    pPrevWrite += second_wanted_write_len;
                }
                else
                {
                    memcpy(pPrevWrite, buf + actual_written_len, second_freespace);
                    /* Add this time's written len */
                    actual_written_len += second_freespace;
                    pPrevWrite += second_freespace;
                }

            }

        }

        ring->pWrite = pPrevWrite;

    }
    else
    {
        /* case 2: pWrite < pRead */
        /* If the pWrite+1 == pRead: It means that the buffer is full */

        /*
         *   Case 2:
         *     [********|                |******]
         *                 pWrite   |     pRead  
         *                          pReserve
         */

        freespace = pPrevRead - pPrevWrite - 1;

        if (freespace > wanted_to_write_len)
        {
            memcpy(pPrevWrite, buf, wanted_to_write_len);
            actual_written_len = wanted_to_write_len;
            pPrevWrite += actual_written_len;
        }
        else
        {
            memcpy(pPrevWrite, buf, freespace);
            actual_written_len = freespace;
            /* pWrite pointer is moved forward, in case2: it is not necessary to wrap to start position */
            pPrevWrite += actual_written_len;
        }
        ring->pWrite = pPrevWrite;
    }
    return actual_written_len;
}



/*****************************************************************************
 * FUNCTION
 *  JBTRING_ReadData
 * DESCRIPTION
 *  Move data from the ring buffer to caller's buffer
 *  Once the data is copied, the space in the ring buffer is considered free
 *  If the data is copied to the app's provided buffer, the pRead pointer must be updated here!
 *   
 * PARAMETERS
 *  ring                    [IN]  Pointer to RingBuf struct      
 *  buf                     [IN]  Caller's destination buffer      
 *  wanted_to_read_len      [IN]  Max amount to copy      
 * RETURNS
 *  actual amount copied to buf
 *****************************************************************************/
kal_int16 JBTRING_ReadData(JBTRingBuf *ring, char *buf, kal_int16 wanted_to_read_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 actual_read_len = 0;

    kal_uint8 *pPrevWrite = ring->pWrite;
    kal_uint8 *pPrevRead = ring->pRead;
    kal_int16 total_data_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wanted_to_read_len < 0)
    {
        /* MAX signed 16bits value = POWER(2,15)-1 = 32767 */
        wanted_to_read_len = 32767;
    }

    kal_trace(TRACE_JBT_GROUP, FUNC_JBT_RING_READ_DATA_INFO, ring->pStart, ring->pEnd, pPrevRead, pPrevWrite);

    if (pPrevWrite >= pPrevRead)
    {

        /*
         * case 1 
         *      [             |*********|           ]
         *                 pRead        pWrite   
         */
        kal_int16 readable_len = 0;

        readable_len = pPrevWrite - pPrevRead;

        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_RING_READ_DATA_CASE1, readable_len);

        if (readable_len > wanted_to_read_len)
        {
            memcpy(buf, pPrevRead, wanted_to_read_len);
            actual_read_len = wanted_to_read_len;
            pPrevRead += actual_read_len;
        }
        else
        {
            memcpy(buf, pPrevRead, readable_len);
            actual_read_len = readable_len;
            pPrevRead += actual_read_len;
        }
        ring->pRead = pPrevRead;
    }
    else
    {
        /*
         *   Case 2:
         *     [********|                |******]
         *                 pWrite        pRead  
         */

        /* In order to reduce the complex of context switch, the readable area is only pEnd - pRead */
        kal_int16 first_readable_len = 0;

        total_data_len = JBTRING_DataLen(ring);
        first_readable_len = ring->pEnd - pPrevRead;

        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_RING_READ_DATA_CASE2, first_readable_len, total_data_len);

        if (first_readable_len >= wanted_to_read_len)
        {
            memcpy(buf, pPrevRead, wanted_to_read_len);
            actual_read_len = wanted_to_read_len;
            pPrevRead += actual_read_len;

            if (pPrevRead == ring->pEnd)
            {
                pPrevRead = ring->pStart;
            }
        }
        else
        {
            kal_int16 left_wanted_to_read_len = 0, left_available_read_len = 0;

            memcpy(buf, pPrevRead, first_readable_len);
            actual_read_len = first_readable_len;
            pPrevRead = ring->pStart;

            kal_trace(
                TRACE_JBT_GROUP,
                FUNC_JBT_RING_READ_DATA_CASE2_INFO,
                ring->pStart,
                ring->pEnd,
                pPrevRead,
                pPrevWrite);

            left_wanted_to_read_len = wanted_to_read_len - first_readable_len;
            left_available_read_len = total_data_len - first_readable_len;

            kal_trace(
                TRACE_JBT_GROUP,
                FUNC_JBT_RING_READ_DATA_CASE2_LEFT_INFO,
                left_wanted_to_read_len,
                left_available_read_len,
                actual_read_len);

            if (left_available_read_len < left_wanted_to_read_len)
            {
                memcpy(buf + actual_read_len, pPrevRead, left_available_read_len);
                pPrevRead += left_available_read_len;
                actual_read_len += left_available_read_len;
            }
            else
            {
                memcpy(buf + actual_read_len, pPrevRead, left_wanted_to_read_len);
                pPrevRead += left_wanted_to_read_len;
                actual_read_len += left_wanted_to_read_len;
            }
            /* pPrevRead pointer will be wrapped to start position of this buffer */

        }
        ring->pRead = pPrevRead;
    }
    return actual_read_len;
}



/*****************************************************************************
 * FUNCTION
 *  JBTRING_GetDataPtr
 * DESCRIPTION
 *  This function is used by jbt_session_DevTX():
 *  It only points to the first readable data's position, and its readable length
 *  Because the 2nd parameter is BtPacket*, the pRead pointer will be updated after the BtPacket's pointer data copied to uart!
 *  Upon receipt RFEVENT_PACKET_HANDLED, the pRead pointer will be updated via the function JBTRING_BufDelete()
 * PARAMETERS
 *  ring        [IN]   Pointer to ring buffer structure     
 *  data        [IN]   Address of pointer to beginning of data     
 *  len         [OUT]  Pointer to number of bytes requested, not exceeding the available bytes     
 * RETURNS
 *  void
 *****************************************************************************/
void JBTRING_GetDataPtr(JBTRingBuf *ring, char **data, kal_int16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *data = (char*)ring->pRead;
    *len = min(*len, JBTRING_ContigDataLen(ring));

}

 
/*****************************************************************************
 * FUNCTION
 *  JBTRING_BufDelete
 * DESCRIPTION
 *  BT task will invokes the function jbt_session_ReturnBuf()
 *  Because the packet's data is already sent to uart, the corresponding data stored in ring buf can be removed
 *  Example: Java Application sends data to peer device
 *  the BT task will invoke this function, when the event RFEVENT_PACKET_HANDLED is reported in BTJSR82_L2capCallback or BTJSR82_RfCallbackFunc
 * PARAMETERS
 *  ring        [IN]  Pointer to ring buffer structure      
 *  len         [IN]  Bytes to delete:If len > existing bytes, existing bytes are removed     
 * RETURNS
 *  void
 *****************************************************************************/
void JBTRING_BufDelete(JBTRingBuf *ring, kal_int16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *pPrevRead = ring->pRead;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pPrevRead + len) == ring->pEnd)
        /* pPrevRead pointer will be wrapped to start position of this buffer */
    {
        pPrevRead = ring->pStart;
    }
    else
    {
        pPrevRead += len;
    }

    ring->pRead = pPrevRead;
}


/*****************************************************************************
 * FUNCTION
 *  JBTRING_FreeSpace
 * DESCRIPTION
 *  It will return the freespace size of this ring buffer
 * PARAMETERS
 *  ring        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 JBTRING_FreeSpace(JBTRingBuf *ring)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 freespace = 0;
    kal_uint8 *pPrevRead = ring->pRead;
    kal_uint8 *pPrevWrite = ring->pWrite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pPrevWrite >= pPrevRead)
    {
        freespace = (ring->pEnd - pPrevWrite) + (pPrevRead - ring->pStart) - 1;
    }
    else
    {
        freespace = pPrevRead - pPrevWrite - 1;
    }
    return freespace;
}



/*****************************************************************************
 * FUNCTION
 *  JBTRING_DataLen
 * DESCRIPTION
 *  This function will return the currently availabe data length of this ring buffer
 * PARAMETERS
 *  ring        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 JBTRING_DataLen(JBTRingBuf *ring)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 datalen = 0;
    kal_uint8 *pPrevRead = ring->pRead;
    kal_uint8 *pPrevWrite = ring->pWrite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pPrevWrite >= pPrevRead)
    {
        datalen = pPrevWrite - pPrevRead;
    }
    else
    {
        datalen = (ring->pEnd - pPrevRead) + (pPrevWrite - ring->pStart);
    }

    return datalen;

}


/*****************************************************************************
 * FUNCTION
 *  JBTRING_ContigDataLen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ring        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int16 JBTRING_ContigDataLen(JBTRingBuf *ring)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 readable_len = 0;
    kal_uint8 *pPrevRead = ring->pRead;
    kal_uint8 *pPrevWrite = ring->pWrite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pPrevWrite >= pPrevRead)
    {
        readable_len = pPrevWrite - pPrevRead;
    }
    else
    {
        readable_len = ring->pEnd - pPrevRead;
    }
    return readable_len;

}
#endif /* __USE_BT_RING_BUF_API__ */ 
#endif /* __SUPPORT_JBT__ */ 

