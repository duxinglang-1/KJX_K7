/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_cbm_wlan_prefer.h
 *
 * Project:
 * --------
 *  COSMOS CBM WLAN Prefer
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_CBM_WLAN_PREFER_H
#define VAPP_CBM_WLAN_PREFER_H

#include "MMI_features.h"

#ifdef __MMI_WLAN_FEATURES__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_confirm_popup.h"
#include "vcp_status_icon_bar.h"

typedef enum
{
    VAPP_CBM_RET_SUCC,
    VAPP_CBM_RET_FAIL,
    VAPP_CBM_RET_WOULDBLOCK,
    VAPP_CBM_RET_YES,
    VAPP_CBM_RET_NO,
    VAPP_CBM_RET_TOTAL
} VappCbmRetEnum;

enum CbmWlanPreferCommandEnum
{
    CBM_WLAN_PREFER_COMMAND_WLAN,
    CBM_WLAN_PREFER_COMMAND_CELLULAR,
    CBM_WLAN_PREFER_COMMAND_CANCEL,
    CBM_WLAN_PREFER_COMMAND_TOTAL
};

typedef void (*wlanPreferCallback)(CbmWlanPreferCommandEnum);

typedef struct
{
    srv_cbm_wlan_query_type_enum query_type;
    VfxBool auto_conn_wlan;
    VfxBool show_wlan_opt;
    VfxBool show_cellular_opt;
    VfxResId text_id;
    wlanPreferCallback callback;
#ifdef __MMI_OP01_WIFI__
    VfxBool show_ask_cellular;
    CbmWlanPreferCommandEnum callback_cmd;
#endif /* __MMI_OP01_WIFI__ */
    wlanPreferCallback reentry_callback;
} cbm_wlan_prefer_info_struct;

void cbm_wlan_prefer_show_command_sheet(cbm_wlan_prefer_info_struct *info);

class VappCbmApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappCbmApp);
public:
    virtual void onRun(void* args, VfxU32 argSize);

    virtual void onGroupActive();
    virtual void onGroupInactive();
};


class VappCbmMainScrn : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappCbmMainScrn);

public:
    VappCbmMainScrn();
    virtual ~VappCbmMainScrn();
    virtual void onInit();
    virtual void on1stReady();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered(VfxBool isBackward);
    void onCommandSheetClicked(VfxObject*, VfxId);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
        param.rotateTo = m_dir;
    };
    virtual void onRotate(const VfxScreenRotateParam &param);

private:
    VcpStatusIconBar *m_statusBar;
    VfxScrRotateTypeEnum m_dir;
    mmi_id m_wlanId;
};


class VappCbmConfirmPop: public VcpConfirmPopup
{
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


class VappCbmQuestionPop: public VcpQuestionPopup
{
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


#endif /* __MMI_WLAN_FEATURES__ */

#endif /* VAPP_CBM_WLAN_PREFER_H */

