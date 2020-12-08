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
 *   event_flag.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is used to MMI event group service
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
 * removed!
 *
 *
 ------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/*****************************************************************************
* Include                                                                     
*****************************************************************************/ 
//#include "mmi_frm_gprot.h"
//#include "mmi_frm_prot.h"


//RHR Add
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "MMIDataType.h"
//#include "kal_release.h"

/*****************************************************************************
*  Local Variable                                                                    
*****************************************************************************/
static kal_eventgrpid  g_mmi_eg;

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_event_flag
 * DESCRIPTION
 *  This function is used to set the specificed event flag
 *  keypad handler.
 * PARAMETERS
 *    flag          : [IN]  the event flag that need to be set
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_event_flag_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_eg = kal_create_event_group("MMI EG");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_event_flag
 * DESCRIPTION
 *  This function is used to set the specificed event flag
 *  keypad handler.
 * PARAMETERS
 *    flag          : [IN]  the event flag that need to be set
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_frm_set_event_flag(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_set_eg_events(g_mmi_eg, flag, KAL_OR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_event_flag
 * DESCRIPTION
 *  This function is used to clear the corresponded event flag
 *  keypad handler.
 * PARAMETERS
 *    flag          : [IN]  the event flag that need to be cleared
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_event_flag(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_set_eg_events(g_mmi_eg, ~flag, KAL_AND);
}


/*****************************************************************************
 * FUNCTION
 *  retrive_mmi_event_flag
 * DESCRIPTION
 *  This function is used to retrive MMI task's event flag
 *  keypad handler.
 * PARAMETERS
 *  requested_flag       : [IN]  The flag that user want to get
 *  match_way            : [IN]  The way to match the requested flag, see enum mmi_event_flag_match_way_enum
 *  retrived_flag        : [OUT] The real retrived flag. 
 * RETURNS
 *  void
 *****************************************************************************/
void retrive_mmi_event_flag(U32 requested_flag, U8 match_way, U32 *retrived_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_retrieve_eg_events(g_mmi_eg, requested_flag, match_way, retrived_flag, KAL_SUSPEND);
}

