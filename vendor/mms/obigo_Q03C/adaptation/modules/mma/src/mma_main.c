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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares JTA modules thread related structures and definitions
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
#ifndef _MMA_MAIN_C
#define _MMA_MAIN_C

#if defined(MMS_SUPPORT)

#include "MMI_features.h"
#include "MMIDataType.h" 

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "mma_api.h"
#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"

#include "custom_wap_config.h"
#include "mmsadp.h"
#include "conversions.h"

/* FS */
#include "fs_type.h"
#include "fs_func.h"

/* PlutoMMI */
#ifdef __MMI_MMS_IN_UM__
//#include "UMGProt.h"
#include "UmSrvGprot.h"
#endif 
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif 

#include "EngineerModeInetAppGprot.h" /* Added for Engineer Mode */

/* APPLIB */
#include "app_str.h"
#include "app_mine.h"

/* MSF */
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_cmmn.h"   /* MSF: MSF common functions, e.g. string handling */
#include "msf_pipe.h"   /* MSF: Pipe handling */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_url.h"    /* MSF: URL API */
#include "msm.h"

/* STK */
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "stk_if.h"     /* STK: WSP/HTTP Stack signals and types */
#else
#include "nts_if.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


/* MMS */
#include "mms_cfg.h"    /* MMS: Configuration definitions */
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_if.h"     /* MMS: Exported signal interface */
#include "mmsl_if.h"
#include "mconfig.h"
#include "msig.h"
#include "mmem.h"
#include "mmsrec.h"
#include "fldmgr.h" /* for MMS_FOLDER */

/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"

/* MMA */
#include "mma_def.h"
#include "mma_env.h"
#include "mma_main.h"
#include "mma_setting.h"
#include "mma_msgmgr.h"
#include "mma_interface.h"
#include "mma_utilities.h"
#include "mma_msg_struct.h"
#include "mma_sendrecv.h"
#include "mma_mime.h"
#include "mma_create.h"
#include "mma_parse.h"
#include "mma_drmsrv.h"
#include "mmi_rp_srv_mms_def.h"

/************************************************************
 * Constants
 ************************************************************/
static mma_main_context_struct g_mma_main_cntx = {0};
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
static mma_main_assign_bit_struct g_mma_main_assigned_bit_array[MMA_MAIN_NUM_MEM_CARD_SUPPORTED] = {{0X80000000, 0}};
#endif



/**********************************************************************
 * Type definitions
 **********************************************************************/

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_main_remove_pending_mem_card_sig
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  card_drv       [IN]
 *  sig            [IN]
 * RETURNS
 *  mma_signal_struct
 *****************************************************************************/
mma_signal_struct* mma_main_remove_pending_mem_card_sig(mma_int_sig_type_enum sig, mma_msg_storage_type_enum card_drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_signal_struct *tmp_list_p = NULL;
    mma_signal_struct *prev_p = NULL;    
    mma_signal_struct **queue_list = &(g_mma_main_cntx.pending_req_list);


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (queue_list == NULL || *queue_list == NULL)
    {
        return NULL;
    }

    tmp_list_p = *queue_list;
    prev_p = NULL;

    while (tmp_list_p != NULL)
    {
        if (tmp_list_p->type == sig)
        {
            mms_mem_card_plug_in_out_struct *card_info_struct = (mms_mem_card_plug_in_out_struct*)tmp_list_p->p_param;

            if (card_info_struct->drv_list[0] == card_drv)
            {
                if (tmp_list_p == *queue_list)
                {
                    *queue_list = (*queue_list)->next;
                }
                else
                {
                    prev_p->next = tmp_list_p->next;
                }
                return tmp_list_p;
            }            
        }
        prev_p = tmp_list_p;
        tmp_list_p = tmp_list_p->next;
    }

    return NULL;
}
/*****************************************************************************
 * FUNCTION
 *  mma_main_get_free_bit_for_card
 * DESCRIPTION
 *  This function is used to get free MSB bit for assigining to card.
 * PARAMETERS
 *  void
 * RETURNS
 *  index
 *****************************************************************************/

kal_uint8 mma_main_get_free_bit_for_card()
{
    kal_uint8 index = 0;

    for(index=0; index < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index++)
    {
        if (g_mma_main_assigned_bit_array[index].status == FALSE)
        {
            g_mma_main_assigned_bit_array[index].status = TRUE;
            break;
        }
    }

    ASSERT(index < MMA_MAIN_NUM_MEM_CARD_SUPPORTED);

    return index;
}
/*****************************************************************************
 * FUNCTION
 *  mma_main_free_assigned_bit
 * DESCRIPTION
 *  This function is used free assigned bit.
 * PARAMETERS
 *  index    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_free_assigned_bit(kal_uint8 index)
{
    ASSERT(index <= MMA_MAIN_NUM_MEM_CARD_SUPPORTED);
     
    g_mma_main_assigned_bit_array[index].status = FALSE;

}

#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mma_main_send_int_notify_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_send_int_notify_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_main_cntx.is_notify_sent == FALSE)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_NOTIFY);     /* Process pending request */
        g_mma_main_cntx.is_notify_sent = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_is_in_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL mma_main_is_in_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_main_cntx.in_usb_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_is_in_terminate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL mma_main_is_in_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_main_cntx.in_terminating;
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_enter_terminate_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_enter_terminate_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_MAIN_ENTER_TERMINATE_MODE, "MMAEnterTerminateMode"));
    g_mma_main_cntx.in_terminating = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_exit_terminate_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_exit_terminate_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_MAIN_EXIT_TERMINATE_MODE, "MMAExitTerminateMode"));
    g_mma_main_cntx.in_terminating = FALSE;
}

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mma_main_handle_mem_card_plug_out_hdlr
 * DESCRIPTION
 *  This function is used to handle the card plug-out indication
 * PARAMETERS
 *  source                      [IN]        
 *  card_info_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_handle_mem_card_plug_out_hdlr(module_type source, mms_mem_card_plug_in_out_struct* card_info_p)
{  
    
    int index_1 = 0;
    int index_2 = 0;
    
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_CARD_PLUG_OUT_HDLR, "(mma_main.c)mma_main_handle_mem_card_plug_out_hdlr()"));

    
    if (msm_get_module_status(MSF_MODID_MSM) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
    {
        MMAif_MemCradPlugOutRes(MMA_RESULT_OK, (mma_msg_storage_type_enum)card_info_p->drv_list[0]);
        MMA_FREE(card_info_p);
        return;
    } 
#ifdef __USB_IN_NORMAL_MODE__
    /* TODO::Rahul:- Check in IT */
    if ((srv_usb_is_in_mass_storage_mode() || mma_main_is_in_usb_mode()))
    {
        /*Assuming only one memory card*/
        mma_signal_struct *pending_sig = mma_main_remove_pending_mem_card_sig(MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND, (mma_msg_storage_type_enum)card_info_p->drv_list[0]);
        if (pending_sig != NULL)
        {
            MMA_FREE(pending_sig->p_param);
            MMA_FREE(pending_sig);
            MMA_FREE(card_info_p);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /*Reset the memory card which are plug out*/
    for(index_1 = 0; index_1 < card_info_p->drv_count; index_1++)
    {   
        
        if (card_info_p->drv_list[index_1] != MMA_MSG_STORAGE_NONE)
        {

            for (index_2 = 0; index_2 < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index_2++)
            {
                if (g_mma_main_cntx.memory_card_plug_in[index_2].card_present == card_info_p->drv_list[index_1])
                {
                    /*TODO::Rahul->Remember to use Lock also if passed by MMI*/

                    if (g_mma_main_cntx.memory_card_plug_in[index_2].card_state == MMA_MAIN_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING)
                    {
                        /* Remove Pending Plug-in from the queue */
                        mma_signal_struct *pending_sig = mma_main_remove_pending_mem_card_sig(MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND, (mma_msg_storage_type_enum)card_info_p->drv_list[index_1]);

                        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_REMOVE_PENDING_PLUG_IN_SIG,"(mma_main.c)MMA_MAIN_REMOVE_PENDING_PLUG_IN_SIG"));

                        MMA_FREE(pending_sig->p_param);
                        MMA_FREE(pending_sig);
                        /* Change state again to PLUG_OUT_PROCESS */
                        g_mma_main_cntx.memory_card_plug_in[index_2].card_state = MMA_MAIN_MEM_CARD_STATE_PLUG_OUT_PROCESS;
                        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_CHANGE_STATE_TO_CARD_PLUG_OUT_PROCESS, "MMA_MAIN_CHANGE_STATE_TO_CARD_PLUG_OUT_PROCESS"));

                    }                    
                    else
                    {
                        mms_mem_card_plug_in_out_struct *temp_card_info = (mms_mem_card_plug_in_out_struct*) MMA_CALLOC(sizeof(mms_mem_card_plug_in_out_struct));
                        temp_card_info->drv_count = 1;
                        temp_card_info->drv_list[0] = card_info_p->drv_list[index_1];
                        /* Handle the plug out with no delay */
                        g_mma_main_cntx.memory_card_plug_in[index_2].card_state = MMA_MAIN_MEM_CARD_STATE_PLUG_OUT_PROCESS;
                        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_IND, 0, temp_card_info);
                        
                        /* Call Create callback */
                        mma_create_memory_card_plug_out_callback(temp_card_info->drv_list[0]);
                        /* Call Parse callback */
                        mma_parse_memory_card_plug_out_callback(temp_card_info->drv_list[0]);
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
                        /* Call drmsrv callback */
                        mma_drmsrv_memory_card_plug_out_callback(temp_card_info->drv_list[0]);
#endif
                        mma_sendrecv_memory_card_plug_out_callback(temp_card_info->drv_list[0]);

                        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_FIRST_PLUG_OUT, "(mma_main.c)MMA_MAIN_FIRST_PLUG_OUT"));

                    }
                    break;
                }
            }
        }
    }

    MMA_FREE(card_info_p);

}


/*****************************************************************************
 * FUNCTION
 *  mma_main_handle_mem_card_plug_in_hdlr
 * DESCRIPTION
 *  This function is used to handle card plug-in indication
 * PARAMETERS
 *  source                      [IN]        
 *  card_info_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_handle_mem_card_plug_in_hdlr(module_type source, mms_mem_card_plug_in_out_struct* card_info_p, kal_uint8 is_pending)
{  
    
    int index_1 = 0;
    int index_2 = 0;
    mms_mem_card_plug_in_out_struct *temp_card_info = NULL;

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_CARD_PLUG_IN_HDLR, "(mma_main.c)mma_main_handle_mem_card_plug_in_hdlr()"));


    /*Rahul::TODO will check in IT if this code is needed or not */
    
    if (msm_get_module_status(MSF_MODID_MSM) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
    {
  
        MMAif_MemCradPlugInRes(MMA_RESULT_OK, (mma_msg_storage_type_enum)card_info_p->drv_list[0] );
        MMA_FREE(card_info_p);
        return;
    }

    /*If in USB Mode and card plug-in*/
#ifdef __USB_IN_NORMAL_MODE__
    if (!is_pending && (srv_usb_is_in_mass_storage_mode() || mma_main_is_in_usb_mode()))
    {
       
        /*Put the signal in pending queue*/
        
        mma_send_int_sig(&(g_mma_main_cntx.pending_req_list),
                            MMA_SUBMODULE_MSG_MAIN,
                            MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND,
                            source,
                            0,
                            0,
                            0,
                            card_info_p);
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_PLUG_IN_SIG_PENDING, "(mma_main.c)MMA_MAIN_PLUG_IN_SIG_PENDING"));
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 


    /*Reset the memory card which are plug out*/

    
    for(index_1 = 0; index_1 < card_info_p->drv_count; index_1++)
    {   
        
        if (card_info_p->drv_list[index_1] != MMA_MSG_STORAGE_NONE)
        {
            for (index_2 = 0; index_2 < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index_2++)
            {
         
                if (g_mma_main_cntx.memory_card_plug_in[index_2].card_present == card_info_p->drv_list[index_1])
                {
                    
                    if (g_mma_main_cntx.memory_card_plug_in[index_2].card_state == MMA_MAIN_MEM_CARD_STATE_PLUG_OUT_PROCESS)
                    {
                        temp_card_info = (mms_mem_card_plug_in_out_struct*) MMA_CALLOC(sizeof(mms_mem_card_plug_in_out_struct));
                        temp_card_info->drv_count = 1;
                        temp_card_info->drv_list[0] = card_info_p->drv_list[index_1];

                        mma_send_int_sig(
                            &(g_mma_main_cntx.pending_req_list),
                            MMA_SUBMODULE_MSG_MAIN,
                            MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND,
                            source,
                            0,
                            0,
                            0,
                            temp_card_info);

                        g_mma_main_cntx.memory_card_plug_in[index_2].card_state = MMA_MAIN_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING;

                        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_PLUG_OUT_PROCESS_PLUG_IN_PENDING,"(mma_main.c)MMA_MAIN_PLUG_OUT_PROCESS_PLUG_IN_PENDING"));

                    }
                    else 
                    {
                        /* We got a plug-in on plug-in*/
                        /*Just Ignore it*/
                        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_PLUG_IN_PLUG_IN_IGNORED,"(mma_main.c)MMA_MAIN_PLUG_IN_PLUG_IN_IGNORED"));
                        //ASSERT(0);
                        
                    }                 
                    break;
                }
            }

            if(index_2 == MMA_MAIN_NUM_MEM_CARD_SUPPORTED)
            {
                /* No entry found , get a free slot */
                MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_FIRST_PLUG_IN, "(mma_main.c)MMA_MAIN_FIRST_PLUG_IN"));
                for (index_2 = 0; index_2 < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index_2++)
                {
                    if (g_mma_main_cntx.memory_card_plug_in[index_2].card_present == MMA_MSG_STORAGE_NONE)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_FREE_SLOT_FOR_CARD_FOUND, "(mma_main.c)MMA_MAIN_FREE_SLOT_FOR_CARD_FOUND: %d", index_2));

                        temp_card_info = (mms_mem_card_plug_in_out_struct*) MMA_CALLOC(sizeof(mms_mem_card_plug_in_out_struct));
                        temp_card_info->drv_count = 1;
                        temp_card_info->drv_list[0] = card_info_p->drv_list[index_1];

                        g_mma_main_cntx.memory_card_plug_in[index_2].card_present = card_info_p->drv_list[index_1];
                        g_mma_main_cntx.memory_card_plug_in[index_2].card_state =  MMA_MAIN_MEM_CARD_STATE_PLUG_IN_PROCESS;
                        g_mma_main_cntx.memory_card_plug_in[index_2].assigned_MSB_index = mma_main_get_free_bit_for_card();
                        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND, 0, temp_card_info);
                    }

                }
            }
        }
    }

    MMA_FREE(card_info_p);

}

/*****************************************************************************
 * FUNCTION
 *  mma_main_handle_mem_card_plug_out_rsp_hdlr
 * DESCRIPTION
 *  This function is used to handle plug out rsp from msgmgr
 * PARAMETERS
 *  card_enum                      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void mma_main_handle_mem_card_plug_out_rsp_hdlr(mma_msg_storage_type_enum card_enum)
{
    mma_signal_struct *pending_sig = NULL;
    kal_uint8 index = 0;

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_CARD_PLUG_OUT_RSP, "(mma_main.c)mma_main_handle_mem_card_plug_out_rsp_hdlr()"));

    pending_sig = mma_main_remove_pending_mem_card_sig(MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND, card_enum);

    /* Update main context */
    for (index = 0; index < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index++)
    {
        if (g_mma_main_cntx.memory_card_plug_in[index].card_present == card_enum)
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_RESETTING_CARD_INFO_CONTEXT, "(mma_main.c)MMA_MAIN_RESETTING_CARD_INFO_CONTEXT"));

            g_mma_main_cntx.memory_card_plug_in[index].card_present = MMA_MSG_STORAGE_NONE;
            g_mma_main_cntx.memory_card_plug_in[index].card_state = MMA_MAIN_MEM_CARD_STATE_NONE;
            mma_main_free_assigned_bit(g_mma_main_cntx.memory_card_plug_in[index].assigned_MSB_index);
            g_mma_main_cntx.memory_card_plug_in[index].assigned_MSB_index = 0XFF;
            break;
        }
    }
    if (pending_sig != NULL)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_PROCESS_PENDING_PLUG_IN, "(mma_main.c)MMA_MAIN_PROCESS_PENDING_PLUG_IN"));
        mma_main_handle_mem_card_plug_in_hdlr((module_type)pending_sig->i_param, (mms_mem_card_plug_in_out_struct*)pending_sig->p_param, FALSE);
    }

    /*Send Plug out response to MMS APP
    Currently we are assuming that there is no way that error can happen.
    Will do the error handling if we meet such scenerio*/

    MMAif_MemCradPlugOutRes(MMA_RESULT_OK, card_enum);
    mma_delete_int_sig(pending_sig);
}

/*****************************************************************************
 * FUNCTION
 *  mma_main_handle_mem_card_plug_in_rsp_hdlr
 * DESCRIPTION
 *  This function is used to handle plug in rsp from msgmgr
 * PARAMETERS
 *  card_enum                      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void mma_main_handle_mem_card_plug_in_rsp_hdlr(mma_msg_storage_type_enum card_enum)
{
    kal_uint8 index = 0;

    /* Update main context */
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_CARD_PLUG_IN_RSP, "(mma_main.c)mma_main_handle_mem_card_plug_in_rsp_hdlr()"));

    for (index = 0; index < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index++)
    {
        if (g_mma_main_cntx.memory_card_plug_in[index].card_present == card_enum)
        {
          
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_SET_PLUG_IN_CARD_CONTEXT, "(mma_main.c)MMA_MAIN_SET_PLUG_IN_CARD_CONTEXT"));
            g_mma_main_cntx.memory_card_plug_in[index].card_state = MMA_MAIN_MEM_CARD_STATE_PLUG_IN;
            break;
        }
    }
      /*Send Plug out response to MMS APP
    Currently we are assuming that there is no way that error can happen.
    Will do the error handling if we meet such scenerio*/


    MMAif_MemCradPlugInRes(MMA_RESULT_OK, card_enum);
}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */



/*****************************************************************************
 * FUNCTION
 *  mma_main_get_mem_status_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_mem_status_req      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_get_mem_status_req_hdlr(module_type source, wap_mma_get_mem_status_req_struct *get_mem_status_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 freebytes = 0;
    kal_uint32 usedbytes = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_mem_status_req);

    if (msm_get_module_status(MSF_MODID_MSM) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        mms_mma_send_get_mem_status_rsp(
            source,
            get_mem_status_req->app_id,
            get_mem_status_req->req_id,
            MMA_RESULT_FAIL_NOT_READY,
            0,
            0);
        MMA_FREE(get_mem_status_req);
        return;
    }
#ifdef __USB_IN_NORMAL_MODE__
    if ((srv_usb_is_in_mass_storage_mode() || mma_main_is_in_usb_mode()) && mma_is_storage_exported_to_pc())
    {
        mms_mma_send_get_mem_status_rsp(
            source,
            get_mem_status_req->app_id,
            get_mem_status_req->req_id,
            MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE,
            (kal_uint32) usedbytes,
            (kal_uint32) freebytes);
        MMA_FREE(get_mem_status_req);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* For upgradation in MMA */
    if (mma_check_fs_is_busy() == TRUE)
    {
        mms_mma_send_get_mem_status_rsp(
            source,
            get_mem_status_req->app_id,
            get_mem_status_req->req_id,
            MMA_RESULT_FAIL_BUSY,
            0,
            0);
        MMA_FREE(get_mem_status_req);
        return;
    }
    freebytes = mma_get_mms_avaliable_file_space(&usedbytes, get_mem_status_req->storage);

    mms_mma_send_get_mem_status_rsp(
        source,
        get_mem_status_req->app_id,
        get_mem_status_req->req_id,
        MMA_RESULT_OK,
        (kal_uint32) usedbytes,
        (kal_uint64) freebytes);
    MMA_FREE(get_mem_status_req);
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_get_gmt_time
 * DESCRIPTION
 *  This function is used to get GMT time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MSF_UINT32 mma_main_get_gmt_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_UINT32) (MSF_TIME_GET_CURRENT() - (MSF_TIME_GET_TIME_ZONE() * 60));
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_enter_usb_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_enter_usb_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_main_is_in_usb_mode() == TRUE)
    {
        return;
    }
    g_mma_main_cntx.in_usb_mode = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_exit_usb_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_exit_usb_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    mma_signal_struct *pending_sig = NULL;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_main_is_in_usb_mode() == FALSE)
    {
        mms_mma_send_exit_usb_rsp(MOD_MMI);
        return;
    }
     
    g_mma_main_cntx.in_usb_mode = FALSE;
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    pending_sig = mma_main_remove_pending_mem_card_sig(MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND, MMA_MSG_STORAGE_CARD1);
    if (pending_sig != NULL)
        {
        mma_main_handle_mem_card_plug_in_hdlr((module_type)pending_sig->i_param, (mms_mem_card_plug_in_out_struct*)pending_sig->p_param, TRUE);
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    g_mma_main_cntx.in_usb_mode = FALSE;
    /*To check for the folder existence */
    MMSlib_createFolder(MSF_MMS_STORAGE_PHONE);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    MMSlib_createFolder(MSF_MMS_STORAGE_MEM_CARD_1);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    mms_mma_send_exit_usb_rsp(MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_execute_pending_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_main_execute_pending_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_signal_struct *sig_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_main_cntx.is_notify_sent = FALSE;
    sig_p = mma_get_int_sig(&(g_mma_main_cntx.pending_req_list));
    if (sig_p != NULL)
    {
        mma_main_process_int_sig(sig_p);
        mma_delete_int_sig(sig_p);
    }
    if (g_mma_main_cntx.pending_req_list != NULL)
    {
        mma_main_send_int_notify_ind();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_send_ready_ind_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_main_send_ready_ind_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_setting_set_registry_10_rr_all_string_res();
    mms_mma_send_um_ready_ind(MOD_MMI, KAL_TRUE);
    mms_mma_send_ilm(NULL, NULL, MSG_ID_WAP_MMA_READY_IND, MOD_MMI);

    if (g_mma_main_cntx.pending_req_list != NULL)
    {
        mma_main_send_int_notify_ind();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_process_int_sig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_process_int_sig(mma_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sig);
    switch (sig->type)
    {
        case MMA_INT_SIG_TYPE_MSG_GET_MEM_STATUS_REQ:
            mma_main_get_mem_status_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_get_mem_status_req_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ:
            mma_main_enter_usb_req_hdlr();
            break;
        case MMA_INT_SIG_TYPE_MSG_EXIT_USB_REQ:
            mma_main_exit_usb_req_hdlr();
            break;
        case MMA_INT_SIG_TYPE_NOTIFY:
            mma_main_execute_pending_req_hdlr();
            break;
        case MMA_INT_SIG_TYPE_MSG_SEND_READY_IND_REQ:
            mma_main_send_ready_ind_req_hdlr();
            break;
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        case MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_IND:
            mma_main_handle_mem_card_plug_out_hdlr((module_type) sig->i_param, (mms_mem_card_plug_in_out_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND:
            mma_main_handle_mem_card_plug_in_hdlr((module_type) sig->i_param, (mms_mem_card_plug_in_out_struct*) sig->p_param, FALSE);
            break;
        case MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_RES:
            mma_main_handle_mem_card_plug_out_rsp_hdlr((mma_msg_storage_type_enum) sig->i_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_RES:
            mma_main_handle_mem_card_plug_in_rsp_hdlr((mma_msg_storage_type_enum) sig->i_param);
            break;
#endif  /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
        default:
            break;
    }
}





/*****************************************************************************
 * FUNCTION
 *  mma_main_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_main_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset some MMS registries */
    if (msm_get_module_status(MSF_MODID_MSM) == MODULE_STATUS_ACTIVE &&
        msm_get_module_status(MSF_MODID_MMS) == MODULE_STATUS_ACTIVE)
    {

		MSF_FILE_MKDIR_EXT(MMA_FOLDER, MSF_MMS_STORAGE_PHONE);

        
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__         
        /* For setting the plug-in memory card context */
        {
            int index = 0;

            /* Fill the list for plugged in memory card */
            for (index = 0; index < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index++)
            {
                /* TODO:: Rahul-> Need to use MSF api to know about the card plugged in */
                if (MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1))
                {
                    g_mma_main_cntx.memory_card_plug_in[index].card_present = MMA_MSG_STORAGE_CARD1;
                    g_mma_main_cntx.memory_card_plug_in[index].card_state = MMA_MAIN_MEM_CARD_STATE_PLUG_IN;
                    g_mma_main_cntx.memory_card_plug_in[index].assigned_MSB_index = mma_main_get_free_bit_for_card(); 
                }
            
            }
        }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    }
    else
    {
        return KAL_FALSE;
    }
    //Intialize the MMA mime type context.
    mma_mime_init_context();
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_main_terminate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_main_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    for (index = 0; index < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index++)
    {
            g_mma_main_cntx.memory_card_plug_in[index].card_present = MMA_MSG_STORAGE_NONE;
            g_mma_main_cntx.memory_card_plug_in[index].card_state = MMA_MAIN_MEM_CARD_STATE_NONE;
			if (g_mma_main_cntx.memory_card_plug_in[index].assigned_MSB_index != 0XFF)
			{
				mma_main_free_assigned_bit(g_mma_main_cntx.memory_card_plug_in[index].assigned_MSB_index);
			}
			g_mma_main_cntx.memory_card_plug_in[index].assigned_MSB_index = 0XFF;
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
    memset(&g_mma_main_cntx, 0x00, sizeof(mma_main_context_struct));
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_main_is_storage_type_present
 * DESCRIPTION
 *  This function is use to check if particular storage is present or not
 * PARAMETERS
 *  mem_card     [IN]
 * RETURNS
 *  TRUE         If storage present
 *  FALSE        If storage not present  
 *****************************************************************************/
kal_bool mma_main_is_storage_type_present(mma_msg_storage_type_enum storage_type)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__    
   int index = 0;

    if (storage_type == MMA_MSG_STORAGE_PHONE)
    {
        /* Phone memory will always present*/
        return KAL_TRUE;
    }

    for(index = 0; index <  MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index++)
    {
        if (g_mma_main_cntx.memory_card_plug_in[index].card_present == storage_type &&
            g_mma_main_cntx.memory_card_plug_in[index].card_state == MMA_MAIN_MEM_CARD_STATE_PLUG_IN)
        {
            return KAL_TRUE;            
        }
    }
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_message_storage
 * DESCRIPTION
 *  This function is used to get the storage type from message id
 * PARAMETERS
 *  msgid     [IN]
 * RETURNS
 *  Storage type  
 *****************************************************************************/
mma_msg_storage_type_enum mma_get_message_storage(kal_uint32 msgid)
{

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__  
    kal_uint8 index = 0;

    for(index = 0; index < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index++)
    {
        if (g_mma_main_cntx.memory_card_plug_in[index].card_present != MMA_MSG_STORAGE_NONE)
        {
            if (msgid & g_mma_main_assigned_bit_array[g_mma_main_cntx.memory_card_plug_in[index].assigned_MSB_index].Assigned_BIT)
            {
                return (mma_msg_storage_type_enum)g_mma_main_cntx.memory_card_plug_in[index].card_present;
            }
        }
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

    return MMA_MSG_STORAGE_PHONE;
}



/*****************************************************************************
 * FUNCTION
 *  mma_get_message_storage
 * DESCRIPTION
 *  This function is used to get the storage type from message id
 * PARAMETERS
 *  msgid     [IN]
 * RETURNS
 *  Storage type  
 *****************************************************************************/
msf_mms_storage_enum mma_get_mms_type_message_storage(kal_uint32 msgid)
{
	return translate_mma_storage_to_mms_storage_enum(mma_get_message_storage(msgid));
}


/*****************************************************************************
 * FUNCTION
 *  mma_main_encode_msg_id
 * DESCRIPTION
 *  This function is used to encode the message id depending upon the storage
 *   type.
 * PARAMETERS
 *  o_msgId     [IN]
 *  storage     [IN]
 * RETURNS
 *  Encoded message type  
 *****************************************************************************/
kal_uint32 mma_main_encode_msg_id(kal_uint8 storage, kal_uint32 o_msgId)
{
	if (storage == MMA_MSG_STORAGE_PHONE)
	{
		return o_msgId;
	}
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	else
	{
    kal_uint8 index = 0;

    for (index = 0; index < MMA_MAIN_NUM_MEM_CARD_SUPPORTED; index++)
    {
        if (g_mma_main_cntx.memory_card_plug_in[index].card_present == storage)
        {
            return (o_msgId | g_mma_main_assigned_bit_array[g_mma_main_cntx.memory_card_plug_in[index].assigned_MSB_index].Assigned_BIT);            
        }
    }
	}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

    /* No match found return same message id */
    return o_msgId;
}


#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_MAIN_C */ 

