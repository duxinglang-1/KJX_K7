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
 *  Vapp_sat_base.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SAT Base Class header file.
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
 ****************************************************************************/

#ifndef __VAPP_SAT_BASE_H__
#define __VAPP_SAT_BASE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#ifdef __cplusplus
extern "C"{
#endif

#include "SatCoreProt.h"

#ifdef __cplusplus
}
#endif

#include "vfx_cpp_base.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vapp_sat.h"
#include "vapp_sat_gprot.h"
#include "vapp_sat_title_bar.h"
#include "vapp_sat_ncenter.h"
#include "mmi_rp_vapp_sat_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SAT_TITLE_ICON_MAX_WIDTH 20

/* SAT Timer unit is second */
#define VAPP_SAT_NO_RESPONSE_DURATION           60
#define VAPP_SAT_DISPLAY_TEXT_DELAY_DURATION    5
#define VAPP_SAT_POPUP_DURATION                 1
#define VAPP_SAT_REFRESH_REBOOT_DURATION        3
#define VAPP_SAT_INFINITE_DURATION              0xFFFF

#define VAPP_SAT_EDITOR_SHOW_HINT_INTERVAL_NUM  10
#define VAPP_SAT_PAGE_CP_MARGIN                 10

#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_SAT_TEXT_FONT_SIZE 30

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VAPP_SAT_TEXT_FONT_SIZE 18

#else // default 320X480
#define VAPP_SAT_TEXT_FONT_SIZE 18

#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    VAPP_SAT_RSP_OK     = 0,
    VAPP_SAT_RSP_HELP,
    VAPP_SAT_RSP_TERMINATED,
    VAPP_SAT_RSP_CANCEL,

    VAPP_SAT_RES_END
} VappSatResponseEnum;


/**************************************************************
 * Structure Declaration
 **************************************************************/
typedef struct
{
    MMI_BOOL calling_icon_available;
    CHAR *calling_icon_path;
} vapp_sat_context_struct;


/***************************************************************************** 
 * Function Defination
 *****************************************************************************/
#ifndef	__SAT_DISABLE_ICON_SUPPORT__

#ifdef __cplusplus
extern "C"{
#endif

extern vapp_sat_context_struct *SAT_CONTEXT(mmi_sim_enum sim_id);

#ifdef __cplusplus
}
#endif
#endif

/***************************************************************************** 
 * Class VappSatBasePage
 *****************************************************************************/

class VappSatBasePage : public VfxPage
{
   // VFX_DECLARE_CLASS(VappSatBasePage);

public:
    VappSatBasePage(){};
    VappSatBasePage(srv_sat_proactive_sim_struct *cmdInfo);
    VappSatBasePage(mmi_sim_enum simId, srv_sat_setup_menu_struct *mainmenu);
    virtual ~VappSatBasePage(){};

public:
    enum VappSatToolbarTypeEnum
    {
        TOOLBAR_NONE        = 0x00,
        TOOLBAR_OK          = 0x01,
        TOOLBAR_YES         = 0x02,
        TOOLBAR_HELP        = 0x04,
        TOOLBAR_TERMINATE   = 0x08,
        TOOLBAR_CANCEL      = 0x10,
        TOOLBAR_NO          = 0x20,

        TOOLBAR_END
    };

    #define VAPP_SAT_TOOLBAE_OK_CANCEL                  (VappSatToolbarTypeEnum)(TOOLBAR_OK | TOOLBAR_CANCEL)
    #define VAPP_SAT_TOOLBAE_OK_HELP_CANCEL             (VappSatToolbarTypeEnum)(TOOLBAR_OK | TOOLBAR_HELP | TOOLBAR_CANCEL)
    #define VAPP_SAT_TOOLBAE_OK_TERMINATE_CANCEL        (VappSatToolbarTypeEnum)(TOOLBAR_OK | TOOLBAR_TERMINATE | TOOLBAR_CANCEL)
    #define VAPP_SAT_TOOLBAE_YES_TERMINATE_NO           (VappSatToolbarTypeEnum)(TOOLBAR_YES | TOOLBAR_TERMINATE | TOOLBAR_NO)
    #define VAPP_SAT_TOOLBAE_OK_HELP_TERMINATE_CANCEL   (VappSatToolbarTypeEnum)(TOOLBAR_OK | TOOLBAR_HELP | TOOLBAR_TERMINATE | TOOLBAR_CANCEL)
    #define VAPP_SAT_TOOLBAE_YES_HELP_TERMINATE_NO      (VappSatToolbarTypeEnum)(TOOLBAR_YES | TOOLBAR_HELP | TOOLBAR_TERMINATE | TOOLBAR_NO)

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onBack();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);

    mmi_core_sat_rsp_enum convertBtnIdToRspId(VappSatToolbarTypeEnum BtnId);
    void onMeResponse(VfxObject *sender, VfxId index); 
    virtual VfxBool onResponse(VappSatToolbarTypeEnum BtnId);

    static void onTimerExpiry(srv_sat_callback_struct *callback_data);
    void addCmdTimer();
    void deleteCmdTimer();
    void cmdSessionEnd();

public:
    virtual void setTitleBar(const VfxImageSrc &imgScr = VFX_IMAGE_SRC_NULL, const VfxWString &string = VFX_WSTR_NULL);
    virtual void setToolBar();
    virtual void setFunctionBar(VcpFunctionBar *funcBar);

public:
    mmi_sim_enum getSimId() const ;
    void *getCmdData() const;
    srv_sat_cmd_enum getCmdType() const;
    VfxBool getIsWait();
    VfxBool getIsSent() const;

protected:
    VappSatToolbarTypeEnum getToolbarStyle();
    void setIsSent(VfxBool isTrue);
    void setHelpEnable(VfxBool isTrue);

    VfxBool isDontCareCmd(srv_sat_proactive_sim_struct *cmdInfo);

    //void processPopup(srv_sat_proactive_sim_struct *cmdInfo);
    void showPopup(VfxWString string);
    void hidePopup();
    //void showResetPopup(VfxWString string);
    //void hideResetPopup();
    //void resetHandset(VfxObject* obj, VfxId id);
    //VfxBool isPopup(srv_sat_cmd_enum cmdType);

    mmi_core_sat_timer_enum getTimerId() const;
    void setTimerId(mmi_core_sat_timer_enum timerId);
    VfxU16 getTimerDuration() const;
    void setTimerDuration(VfxU16 duration);

private:
    //void simRefreshProcess(srv_sat_proactive_sim_struct *cmdInfo);
    //void languageNotifyProcess(srv_sat_proactive_sim_struct *cmdInfo);

protected:
    mmi_sim_enum m_simId;
    srv_sat_cmd_enum   m_cmdType;
    srv_sat_proactive_sim_struct *m_cmdInfo;
    void    *m_cmdData;
    VfxBool m_bHelp;
    VfxBool m_bSent;
    VfxBool m_isWait;

    VappSatBaseTitleBar     *m_titleBar;
    VcpToolBar      *m_toolBar;
    VcpIndicatorPopup *m_popupInfo;
    VcpConfirmPopup   *m_resetPopup;

    mmi_core_sat_timer_enum m_timerId;
    VfxU16 m_duration;
};

#endif /* __VAPP_SAT_BASE_H__ */
