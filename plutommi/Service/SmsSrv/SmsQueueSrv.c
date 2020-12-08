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
 *  SmsQueueSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service queue Handler
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
 *============================================================================
 *****************************************************************************/
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "SmsQueueSrv.h"
#include "SmsUtilSrv.h"
#include "ProtocolEvents.h"


/**************************************************************
* MARCO
**************************************************************/

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    U16 action_id;
    void *user_data;
    SrvSmsqueueCallbackFunc callback;
    MMI_BOOL isActived;
} srv_sms_action_struct;

typedef struct
{
    srv_sms_action_struct action[SRV_SMS_ACTION_MAX];
    U8 max_actived_num;
    U8 cur_actived_num;
    U8 action_num;
} srv_sms_queue_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_sms_queue_id_enum queue_id;
    U8 action_id;
} srv_sms_read_queue_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/

/**************************************************************
* Extern Function Declaration
**************************************************************/

/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_queue_struct srv_sms_queue[SRV_SMS_QUEUE_MAX];
static U16 action_id;

/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_sms_queue_send_read_action_req(srv_sms_queue_id_enum queue_id, U8 action_id);
static void srv_sms_read_action(void *inMsg);


/*****************************************************************************
 * FUNCTION
 *  srv_sms_queue_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  queue_id         [IN]        
 *  action_num      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_queue_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_sms_queue, 0, (SRV_SMS_QUEUE_MAX * sizeof(srv_sms_queue_struct)));
    srv_sms_queue[SRV_SMS_QUEUE_BG].max_actived_num = SRV_SMS_BG_ACTIVE_NUM;
    srv_sms_queue[SRV_SMS_QUEUE_FG].max_actived_num = SRV_SMS_FG_ACTIVE_NUM;
    SetProtocolEventHandler(srv_sms_read_action, PTR_MSG_ID_SRV_SMS_READ_QUEUE_IND);
}

/**************************************************************
* Function Defination
**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_read_action(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_queue_struct *read_data = (srv_sms_read_queue_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (read_data->action_id < srv_sms_queue[read_data->queue_id].max_actived_num)
    {

        if ((srv_sms_queue[read_data->queue_id].action[read_data->action_id].isActived == MMI_FALSE)
            && (srv_sms_queue[read_data->queue_id].action[read_data->action_id].callback != NULL))
        {
            srv_sms_queue_data_struct action_data;

            action_data.action_id = srv_sms_queue[read_data->queue_id].action[read_data->action_id].action_id;
            action_data.queue_id = read_data->queue_id;
            action_data.user_data = srv_sms_queue[read_data->queue_id].action[read_data->action_id].user_data;
            srv_sms_queue[read_data->queue_id].action[read_data->action_id].isActived = MMI_TRUE;
            srv_sms_queue[read_data->queue_id].cur_actived_num++;
            srv_sms_queue[read_data->queue_id].action[read_data->action_id].callback(&action_data);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_queue_send_read_action_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  queue_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_queue_send_read_action_req(srv_sms_queue_id_enum queue_id, U8 action_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_queue_struct *read_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_queue[queue_id].cur_actived_num < srv_sms_queue[queue_id].max_actived_num)
    {
        read_data = (srv_sms_read_queue_struct*) OslConstructDataPtr(sizeof(srv_sms_read_queue_struct));
        read_data->queue_id = queue_id;
        read_data->action_id = action_id;

        SRV_SMS_SEND_ILM(MOD_MMI,  PTR_MSG_ID_SRV_SMS_READ_QUEUE_IND, read_data);  
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_queue_write_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  queue_id        [IN]        
 *  callback        [IN]        
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_queue_write_action(srv_sms_queue_id_enum queue_id, SrvSmsqueueCallbackFunc callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cur_action = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(queue_id < SRV_SMS_QUEUE_MAX);
    if (srv_sms_queue[queue_id].action_num == SRV_SMS_ACTION_MAX)
    {
        return SRV_SMS_ACTION_INVALID_ID;
    }
    srv_sms_queue[queue_id].action_num++;
    cur_action = srv_sms_queue[queue_id].action_num - 1;
    srv_sms_queue[queue_id].cur_actived_num = cur_action;
    srv_sms_queue[queue_id].action[cur_action].user_data = user_data;
    srv_sms_queue[queue_id].action[cur_action].callback = callback;
    srv_sms_queue[queue_id].action[cur_action].action_id = action_id++;
    srv_sms_queue[queue_id].action[cur_action].isActived = MMI_FALSE;
    srv_sms_queue_send_read_action_req(queue_id, cur_action);

    return srv_sms_queue[queue_id].action[cur_action].action_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_queue_delete_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  queue_id        [IN]        
 *  action_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_queue_delete_action(srv_sms_queue_id_enum queue_id, U16 action_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(queue_id < SRV_SMS_QUEUE_MAX);
    MMI_ASSERT(srv_sms_queue[queue_id].action_num <= SRV_SMS_ACTION_MAX);
    for (i = 0; i < srv_sms_queue[queue_id].action_num; i++)
    {
        if (srv_sms_queue[queue_id].action[i].action_id == action_id)
        {
            if (srv_sms_queue[queue_id].action[i].isActived == MMI_TRUE)
            {
                srv_sms_queue[queue_id].cur_actived_num--;
            }

            for (j = i; j < srv_sms_queue[queue_id].action_num; j++)
            {

                if (j == srv_sms_queue[queue_id].action_num - 1)
                {
                    memset(&srv_sms_queue[queue_id].action[j], 0, sizeof(srv_sms_action_struct));                  
                }
                else
                {
                    memcpy(
                        &srv_sms_queue[queue_id].action[j],
                        &srv_sms_queue[queue_id].action[j + 1],
                        sizeof(srv_sms_action_struct));
                }
            }
            srv_sms_queue[queue_id].action_num--;
            for (i = 0; i < srv_sms_queue[queue_id].action_num; i++)
            {
                if (srv_sms_queue[queue_id].action[i].isActived == MMI_FALSE 
                    && srv_sms_queue[queue_id].cur_actived_num < srv_sms_queue[queue_id].max_actived_num)
                {                    
                    srv_sms_queue_send_read_action_req(queue_id, i);
                }                
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  sms_srv_queue_check_action_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  queue_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 sms_srv_queue_check_action_num(srv_sms_queue_id_enum queue_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(queue_id < SRV_SMS_QUEUE_MAX);

    return srv_sms_queue[queue_id].action_num;
}


/*****************************************************************************
 * FUNCTION
 *  sms_srv_queue_check_actaived_action_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  queue_id        [IN]        
 *  action_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL sms_srv_queue_check_actaived_action_id(srv_sms_queue_id_enum queue_id, U16 action_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(queue_id < SRV_SMS_QUEUE_MAX);
    return srv_sms_queue[queue_id].action[action_id].isActived;
}
#endif /* __MOD_SMSAL__ */ 

