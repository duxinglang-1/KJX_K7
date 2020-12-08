/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_matv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  mATV Function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
#if defined(__ATV_SUPPORT__)
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "drv_comm.h"
#include "kal_non_specific_general_types.h"
#include "fctycomp_config.h"
#include "stack_config.h"
#include "string.h"
/*************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_matv.h"
#include "matvctrl.h"
/*************************************************************************
 * Custom header
 *************************************************************************/
#include "meta_customize.h"

static kal_bool matv_power_on = KAL_FALSE;
static kal_uint8 matv_progress = 0;
void dummy_autoscan_cb(void* cb_param, kal_uint8 percent,kal_uint8 ch,kal_uint8 chnum)
{
    matv_progress = percent;
}
void fullscan_progress_cb(void* cb_param, kal_uint8 percent,kal_uint32 freq,kal_uint32 freq_start,kal_uint32 freq_end)
{
    matv_progress = percent;
}
void fullscan_finish_cb(void* cb_param, kal_uint8 chnum)
{
    matv_progress = 101;
}
void dummy_audioformat_cb(void* cb_param, kal_uint32 format)
{
}

void FT_MATV_Operation(ilm_struct *ptrMsg)
{
    ilm_struct *ilm_ptr;
    FT_MATV_CNF *p_cnf;
    FT_MATV_REQ *p_req;
    peer_buff_struct *peer_buff_ret;
    kal_uint16 pdu_length;
    ilm_ptr = FT_ALLOC_MSG(sizeof(FT_MATV_CNF));
    p_cnf = (FT_MATV_CNF *)ilm_ptr->local_para_ptr;
    p_req = (FT_MATV_REQ *)ptrMsg->local_para_ptr;
    p_cnf->header.ft_msg_id = FT_MATV_CMD_CNF_ID;
    p_cnf->type = p_req->type;
    // if the feature option is off, confirm fail
    if(KAL_TRUE == Custom_META_ATV_Support_Option())
    {
        p_cnf->status = FT_CNF_OK;
    }
    else
    {
        p_cnf->status = FT_CNF_FAIL;
        FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
        return;
    }
    switch(p_req->type) 
    {
        case FT_MATV_OP_POWER_ON:
            if(matv_power_on == KAL_FALSE)
            {
                matv_power_on = Custom_META_matv_init();
                if(KAL_TRUE == matv_power_on)
                {
                    p_cnf->status = FT_CNF_OK;
                }
                else
                {
                    p_cnf->status = FT_CNF_FAIL;
                }
            }
            else
            {
                p_cnf->status = FT_CNF_OK;
            }
            break;
        case FT_MATV_OP_POWER_OFF:
            if(matv_power_on == KAL_TRUE)
            {
                matv_power_on = (Custom_META_matv_shutdown() == KAL_TRUE) ? KAL_FALSE : KAL_TRUE;
                p_cnf->status = FT_CNF_OK;
            }
            else
            {
                p_cnf->status = FT_CNF_FAIL;
            }
            break;
        case FT_MATV_OP_SET_REGION:
            Custom_META_matv_set_country(p_req->cmd.m_ucRegion);
            p_cnf->status = FT_CNF_OK;
            break;
        case FT_MATV_OP_SCAN:
            matv_progress = 0;
            Custom_META_matv_register_callback(NULL, (void*)dummy_autoscan_cb, (void*)fullscan_progress_cb, (void*)fullscan_finish_cb, (void*)dummy_audioformat_cb);
            Custom_META_matv_chscan(p_req->cmd.m_ucScanMode);
            p_cnf->status = FT_CNF_OK;
            break;
        case FT_MATV_OP_STOP_SCAN:
            Custom_META_matv_chscan_stop();
            p_cnf->status = FT_CNF_OK;
            break;
        case FT_MATV_OP_GET_CHANNEL_LIST:
        {
            p_cnf->result.m_ucProgress = matv_progress;
            if(matv_progress == 101)
            {
                kal_bool flag;
                kal_uint8 ch;
                // copy result to peer buffe
                FT_MATV_GET_CHANNEL_LIST_CNF_T *pdu_ptr = NULL;
                if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(FT_MATV_GET_CHANNEL_LIST_CNF_T), 0, 0, TD_CTRL)) )
                {
                    pdu_ptr = get_pdu_ptr( peer_buff_ret, &pdu_length );
                    peer_buff_ret->pdu_len = sizeof(FT_MATV_GET_CHANNEL_LIST_CNF_T);
                    // assign peer buffer
                    if( NULL != peer_buff_ret )
                    {
                        ilm_ptr->peer_buff_ptr = peer_buff_ret;
                    }
                }
                else
                {
                    ASSERT(0);
                }
                pdu_ptr->m_ucChannels = 0;
                for(ch=0;ch<70;ch++)
                {
                    memset(&(pdu_ptr->m_rmatv_ch_entry[ch]), 0x0, sizeof(matv_ch_entry));
                    flag = Custom_META_matv_get_chtable(ch, &(pdu_ptr->m_rmatv_ch_entry[ch]));
                    if(flag == KAL_FALSE)
                    {
                        // end of ch table
                        break;
                    }
                    if(pdu_ptr->m_rmatv_ch_entry[ch].flag == 1)
                    {
                        pdu_ptr->m_ucChannels++;
                    }
                }
            }
            p_cnf->status = FT_CNF_OK;
            break;
        }
        case FT_MATV_OP_CHANGE_CHANNEL:
            Custom_META_matv_change_channel(p_req->cmd.m_ucChannel);
            p_cnf->status = FT_CNF_OK;
            break;
        case FT_MATV_OP_SET_CHANNEL_PROPERTY:
        {
            kal_bool flag;
            flag = Custom_META_matv_set_chtable(p_req->cmd.m_rSetChannelProperty.m_ucChannel,
                    &(p_req->cmd.m_rSetChannelProperty.m_rmatv_ch_entry));
            if(flag == KAL_TRUE)
            {
                p_cnf->status = FT_CNF_OK;
            }
            else
            {
                p_cnf->status = FT_CNF_FAIL;
            }
            break;
        }
        case FT_MATV_OP_GET_CHANNEL_QUALITY:
        {
            p_cnf->result.m_i4QualityIndex = Custom_META_matv_get_chipdep(p_req->cmd.m_ucItem);
            p_cnf->status = FT_CNF_OK;
            break;
        }
        case FT_MATV_OP_GET_CHANNEL_QUALITY_ALL:
        {
            // copy result to peer buffer
            kal_uint8 i;
            FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T *pdu_ptr = NULL;
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T), 0, 0, TD_CTRL)) )
            {
                pdu_ptr = get_pdu_ptr( peer_buff_ret, &pdu_length );
                peer_buff_ret->pdu_len = sizeof(FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T);
                // assign peer buffer
                if( NULL != peer_buff_ret )
                {
                     ilm_ptr->peer_buff_ptr = peer_buff_ret;
                }
            }
            else
            {
                 ASSERT(0);
            }
            for(i=100;i<200;i++)
            {
                pdu_ptr->m_i4QualityIndex[i-100] = Custom_META_matv_get_chipdep(i);
            }
            p_cnf->status = FT_CNF_OK;
            break;
        }
        default:
            break;
    }
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
}
#endif // #if defined(__ATV_SUPPORT__)
