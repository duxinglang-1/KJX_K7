/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *
 * Filename:
 * ---------
 *   hdi_signal.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for signal handling adapter functions of Mobile Suite Framework
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "msf_def.h"
#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_mem.h"

#include "kal_public_api.h"        /* Basic data type */
#include "int_exec.h"

#define MAX_NO_SIGNALS        50        /* 25 */

static kal_mutexid hdi_signal_mutex = NULL;
typedef struct signal_data_st
{
    void *data;
    struct signal_data_st *next;
} signal_data_struct;

typedef struct signal_queue_st
{
    MSF_UINT8 modId;
    int sig_count;
    int state;
    signal_data_struct *head;
    signal_data_struct *tail;
} signal_queue_struct;

static signal_queue_struct signal_queues[MSF_NUMBER_OF_MODULES];


/*****************************************************************************
 * FUNCTION
 *  initSignal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void init_hdi_signal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(hdi_signal_mutex == NULL)
    {
        hdi_signal_mutex = kal_create_mutex("HDI Signal Mutex");
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  addSignalData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal_queue        [?]     
 *  signalData          [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static int addSignalData(signal_queue_struct *signal_queue, void *signalData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signal_data_struct *signal_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    signal_data = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(signal_data_struct));

    if (!signal_data)
    {
        return 0;
    }

    signal_data->data = signalData;
    signal_data->next = NULL;

    if (signal_queue->head == NULL)
    {
        signal_queue->head = signal_data;
        signal_queue->tail = signal_data;
    }
    else
    {
        signal_queue->tail->next = signal_data;
        signal_queue->tail = signal_data;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  getSignalData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal_queue        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void *getSignalData(signal_queue_struct *signal_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signal_data_struct *signal_data;
    void *signalData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (signal_queue->head == NULL)
    {
        return NULL;
    }
    else if (signal_queue->head == signal_queue->tail)
    {
        signalData = signal_queue->head->data;
        MSF_MEM_FREE(MSF_MODID_MSM, signal_queue->head);
        signal_queue->head = NULL;
        signal_queue->tail = NULL;
    }
    else
    {
        signalData = signal_queue->head->data;
        signal_data = signal_queue->head;
        signal_queue->head = signal_queue->head->next;

        MSF_MEM_FREE(MSF_MODID_MSM, signal_data);
    }
    return signalData;
}

/**********************************************************************
 * HDI signal functions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalRegisterQueue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_signalRegisterQueue(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signal_queue_struct *signal_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modId < MSF_NUMBER_OF_MODULES)
    {
        signal_queue = &signal_queues[modId];

        signal_queue->state = 1;    /* Registered */
        signal_queue->head = NULL;
        signal_queue->tail = NULL;
        signal_queue->sig_count = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalDeregisterQueue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_signalDeregisterQueue(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signal_queue_struct *signal_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modId < MSF_NUMBER_OF_MODULES)
    {
        signal_queue = &signal_queues[modId];

        signal_queue->state = 0;    /* Deregistered */
        signal_queue->head = NULL;
        signal_queue->tail = NULL;
        signal_queue->sig_count = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalAllocMemory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signalDataLength        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *gmms_HDIa_signalAllocMemory(MSF_UINT16 signalDataLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MSF_MEM_ALLOC(MSF_MODID_MSM, signalDataLength);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalFreeMemory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signalData      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_signalFreeMemory(void *signalData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(MSF_MODID_MSM, signalData);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalSend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId                   [IN]        
 *  signalData              [?]         
 *  signalDataLength        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
#ifdef MSF_SIGNAL_API_REVISED
int gmms_HDIa_signalSend(MSF_UINT8 modId, void *signalData)
#else
int gmms_HDIa_signalSend(MSF_UINT8 modId, void *signalData, MSF_UINT16 signalDataLength)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = HDI_SIGNAL_OK;

    signal_queue_struct *signal_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modId >= MSF_NUMBER_OF_MODULES)
    {
        //HDIa_signalFreeMemory(signalData);
        return HDI_SIGNAL_ERROR_QUEUE_UNKNOWN;
    }

    kal_take_mutex(hdi_signal_mutex);
    signal_queue = &signal_queues[modId];

    if (!signal_queue->state)
    {
        //HDIa_signalFreeMemory(signalData);
        ret = HDI_SIGNAL_ERROR_QUEUE_UNKNOWN;
        goto end;
    }

    if (signal_queue->sig_count == MAX_NO_SIGNALS)
    {
        ret = HDI_SIGNAL_ERROR_QUEUE_FULL;
        goto end;
    }

    if (!addSignalData(signal_queue, signalData))
    {
        ret = HDI_SIGNAL_ERROR_QUEUE_FULL;
        goto end;
    }
    signal_queue->sig_count++;

end:
    kal_give_mutex(hdi_signal_mutex);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalRetrieve
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destModId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *gmms_HDIa_signalRetrieve(MSF_UINT8 destModId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signal_queue_struct *signal_queue;
    void *signalData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (destModId >= MSF_NUMBER_OF_MODULES)
    {
        return NULL;
    }

    kal_take_mutex(hdi_signal_mutex);
    signal_queue = &signal_queues[destModId];

    if (!signal_queue->state || signal_queue->sig_count == 0)
    {
        goto end;
    }

    signalData = getSignalData(signal_queue);
    signal_queue->sig_count--;

  end:
    kal_give_mutex(hdi_signal_mutex);
    return signalData;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_signalQueueLength
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_signalQueueLength(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    signal_queue_struct *signal_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modId >= MSF_NUMBER_OF_MODULES)
    {
        return -1;
    }

    kal_take_mutex(hdi_signal_mutex);
    signal_queue = &signal_queues[modId];

    if (!signal_queue->state)
    {
        ret = -1;
        goto end;
    }

    ret = signal_queue->sig_count;

  end:
    kal_give_mutex(hdi_signal_mutex);
    return ret;
}


#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  isSignalPending
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id       [IN]        
 * RETURNS
 *  1 if there is any signal pending.
 *****************************************************************************/
int isSignalPending(module_type mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        for(i = 0; i < MSF_NUMBER_OF_MODULES; i++)
    {
        if (msf_modules[i].taskId == mod_id && msf_modules[i].pTaskWantsToRun && msf_modules[i].pTaskWantsToRun())
        {
            ret = 1;
            break;
        }
    }
    }
    return ret;
}
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
