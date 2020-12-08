/*  Copyright Statement:
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
 *  vapp_sns_utility.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_ncenter_base_cell.h"
#include "vsrv_notification.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvGprot.h"
#include "SnsSrvDefs.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* Ncenter cell notification id */
typedef enum {
    /* Send notification ncenter type begin */
    SNS_NCENTER_SEND_EVENT_BEGIN,           //Don't modify
    SNS_NCENTER_SEND_EVENT_SEND_MSG = SNS_NCENTER_SEND_EVENT_BEGIN,
    SNS_NCENTER_SEND_EVENT_UPLOAD,
    SNS_NCENTER_SEND_EVENT_POST,
    SNS_NCENTER_SEND_EVENT_ADD_COMMENT,
    SNS_NCENTER_SEND_EVENT_SHARE,
    SNS_NCENTER_SEND_EVENT_END,             //Don't modify
    /* Send notification ncenter type end */

    /* New notification ncenter type begin */
    SNS_NCENTER_NEW_EVENT_BEGIN,            //Don't modify
    SNS_NCENTER_NEW_EVENT_REQUESTS = SNS_NCENTER_NEW_EVENT_BEGIN,
    SNS_NCENTER_NEW_EVENT_NOTIFICATIONS,
    SNS_NCENTER_NEW_EVENT_MESSAGE,
    SNS_NCENTER_NEW_EVENT_END,              //Don't modify
    /* New notification ncenter type end */        
} VappSnsNCenterCellTypeEnum;

/* Customer Ncenter cell discard callback */
typedef void (*VappSnsUnsentFuncCb)(VappSnsNCenterCellTypeEnum type, VfxS32 *reqId);

/* Customer Ncenter cell data structure */
typedef struct vapp_sns_ncenter_info {
    VappSnsNCenterCellTypeEnum type;
    VfxResId stringId;
    VfxS32 *reqId;
    VappSnsUnsentFuncCb discardCb;
} vapp_sns_ncenter_info_struct; 


// VappSnsNCenterEventCell class declaration
class VappSnsNCenterEventCell : public VappNCenterEventCell
{
    VFX_DECLARE_CLASS(VappSnsNCenterEventCell);

public:
    VappSnsNCenterEventCell();
    virtual ~VappSnsNCenterEventCell();

protected:
    virtual void onInit();

public:    
    void createBaseCellWithButton(VfxWString mainText = VFX_WSTR_NULL);

    void onButtonTap(VfxObject *obj, VfxId id);

public:
    VfxSignal2 <VfxObject*, VfxId> m_signalBtnClick;

protected:
    VcpImageButton *m_button;

private:
    enum {
#if defined(__MMI_MAINLCD_480X800__)
        CELL_WIDTH = 480,
        
        BUTTON_W = 70,
        BUTTON_H = 70,
        BUTTON_T_GAP = (VAPP_NCENTER_EVENT_CELL_HEIGHT-BUTTON_H)/2,
        BUTTON_R_GAP = 14,
        BUTTON_LAND_R_GAP = 16,
        BUTTON_L_GAP = (VAPP_NCENTER_EVENT_CELL_WIDTH-BUTTON_R_GAP),

        MAIN_TEXT_W = (VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH-BUTTON_W-2),
        MAIN_TEXT_H = (VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE+2),
        SUB_TEXT_H = (VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE+2),
#elif __MMI_MAINLCD_320X480__
        CELL_WIDTH = 320,
        
        BUTTON_W = 40,
        BUTTON_H = 40,
        BUTTON_T_GAP = (VAPP_NCENTER_EVENT_CELL_HEIGHT-BUTTON_H)/2,
        BUTTON_R_GAP = 10,
        BUTTON_LAND_R_GAP = 10,
        BUTTON_L_GAP = (VAPP_NCENTER_EVENT_CELL_WIDTH-BUTTON_R_GAP),

        MAIN_TEXT_W = (VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH-BUTTON_W-2),
        MAIN_TEXT_H = (VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE+2),
        SUB_TEXT_H = (VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE+2),
#else
        CELL_WIDTH = 240,
        
        BUTTON_W = 36,
        BUTTON_H = 36,
        BUTTON_T_GAP = (VAPP_NCENTER_EVENT_CELL_HEIGHT-BUTTON_H)/2,
        BUTTON_R_GAP = 5,
        BUTTON_LAND_R_GAP = 5,
        BUTTON_L_GAP = (VAPP_NCENTER_EVENT_CELL_WIDTH-BUTTON_R_GAP),

        MAIN_TEXT_W = (VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH-BUTTON_W-2),
        MAIN_TEXT_H = (VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE+2),
        SUB_TEXT_H = (VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE+2),
#endif
    };    
};

// VappSnsNCenterUnsentCell class declaration
class VappSnsNCenterUnsentCell : public VsrvNCell
{
    VFX_DECLARE_CLASS(VappSnsNCenterUnsentCell);

public:
    VappSnsNCenterUnsentCell();
    virtual ~VappSnsNCenterUnsentCell();

protected:
    virtual void onCreateView(void *viewData, VfxU32 viewDataSize);
    virtual void onCloseView();

    void onButtonClicked(VfxObject *obj, VfxId id);

public:
    VfxSignal2 <void*, VfxU32> m_signalDiscardRequest;

protected:
    VappSnsNCenterEventCell *m_notification;
    vapp_sns_ncenter_info_struct m_info;
};

/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
extern mmi_ret vapp_sns_ncenter_post_handler(mmi_event_struct *param);
extern mmi_ret vapp_sns_ncenter_add_handler(mmi_event_struct *param);
extern mmi_ret vapp_sns_ncenter_new_notification_handler(mmi_event_struct *param);
extern mmi_ret vapp_sns_ncenter_new_request_handler(mmi_event_struct *param);
extern mmi_ret vapp_sns_ncenter_send_msg_handler(mmi_event_struct *param);
extern mmi_ret vapp_sns_ncenter_new_msg_handler(mmi_event_struct *param);
extern void vapp_sns_ncenter_new_msg_callback(
                                    VsrvNotification *noti, 
                                    VsrvNIntent intent, 
                                    void *userData, 
                                    VfxU32 userDataSize);
extern mmi_ret vapp_sns_ncenter_upload_handler(mmi_event_struct *param);


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function declaration
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_sns_bg_process_handler
 * DESCRIPTION
 * This function is used to create a dummy app for bg transmission.
 * PARAMETERS
 *  param           :[IN]
 * RETURNS
 *  VfxResId
 *****************************************************************************/ 
extern "C" mmi_ret vapp_sns_bg_process_handler(mmi_event_struct *param);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_account_logout_handler
 * DESCRIPTION
 * This function is used to handler logout event
 * PARAMETERS
 *  param           :[IN]
 * RETURNS
 *  VfxResId
 *****************************************************************************/ 
extern "C" mmi_ret vapp_sns_account_logout_handler(mmi_event_struct *param);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_ncenter_get_notification_obj
 * DESCRIPTION
 * This function is used to handler logout event
 * PARAMETERS
 *  param           :[IN]
 * RETURNS
 *  VfxResId
 *****************************************************************************/
VsrvNotification *vapp_sns_ncenter_get_notification_obj(VappSnsNCenterCellTypeEnum notificationId);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_send_event_handler
 * DESCRIPTION
 * This function is used to handler sending event
 * PARAMETERS
 *  param           :[IN]
 * RETURNS
 *  VfxResId
 *****************************************************************************/ 
extern "C" mmi_ret vapp_sns_send_event_handler(mmi_event_struct *param);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_counts_update_event_handler
 * DESCRIPTION
 * This function is used to handler counts update event
 * PARAMETERS
 *  param           :[IN]
 * RETURNS
 *  VfxResId
 *****************************************************************************/ 
extern "C" mmi_ret vapp_sns_counts_update_event_handler(mmi_event_struct *param);


#endif /* __SOCIAL_NETWORK_SUPPORT__ */

