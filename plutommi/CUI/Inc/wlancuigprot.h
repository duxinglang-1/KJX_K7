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
 *   WlanCuiGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Data Account Common UI header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef CUI_WLAN_GPROT_H
#define CUI_WLAN_GPROT_H

/*******************************************************************************
* Include Header File
*******************************************************************************/

/*******************************************************************************
* Enum Define
*******************************************************************************/
/* Wlan CUI's event ID */
typedef enum
{
    /* After user choose to connect one AP, send this event, not to care about the connect result */
    CUI_WLAN_LIST_EVENT_RESULT_OK = DATA_ACCOUNT_BASE, 
    /* Cancel the AP selection procedure */ 
    /* Such as cancel scanning for network or press back/end key in AP reslection proc */
    CUI_WLAN_LIST_EVENT_RESULT_CANCEL,    
    /* If create WLAN CUI failed, send this event to notify caller */
    CUI_WLAN_LIST_EVENT_RESULT_FAILED,    
    /* If CUI's part screen closed abnormally not by user, send this event to notify caller */
    CUI_WLAN_LIST_EVENT_CLOSE,
    CUI_WLAN_LIST_EVENT_TOTAL
} cui_wlan_list_event_enum;

/* Wlan CUI's event ID */
typedef enum
{
    CUI_WLAN_AUTO_CONN_EVENT_TOTAL
} cui_wlan_auto_conn_event_enum;


/*******************************************************************************
* Structure Define
*******************************************************************************/
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER      /* Screen group standard header */
    U32 reserved;                   /* The reserved parameter */
} cui_wlan_list_event_struct;

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* Export API 
*******************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  cui_wlan_list_create
 * DESCRIPTION
 *  Create a wifi ap list CUI to use. Not to show ap list until call function
 *  cui_wlan_list_run
 * PARAMETERS
 *  parent_gid     [IN]    Parent's screen group ID
 *  parent_data    [IN]    For future extension 
 * RETURNS
 *  mmi_id         Screen group ID of create CUI
 *   - Create CUI failed if return GRP_ID_INVALID 
 *****************************************************************************/
extern mmi_id cui_wlan_list_create(mmi_id parent_gid, void* parent_data);

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_list_run
 * DESCRIPTION
 *  Start to excute CUI, show ap list screen
 * PARAMETERS
 *  cui_gid     [IN]      Created CUI's group ID  
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_wlan_list_run(mmi_id cui_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_wifi_ap_list_close
 * DESCRIPTION
 *  Close created CUI to release memory and resources
 *  Please call this api when receiving event EVT_CUI_AP_LIST_CANCEL or 
 *  EVT_CUI_AP_LIST_CLOSE
 * PARAMETERS
 *  cui_gid     [IN]      Created CUI's group ID  
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_wlan_list_close(mmi_id cui_gid);

#endif /* CUI_WLAN_GPROT_H */ 

