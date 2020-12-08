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
 *  vapp_oom.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Cosmos OOM Screen
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_COSMOS_OOM_H__
#define __VAPP_COSMOS_OOM_H__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_app_cat_scr.h"
#include "vcp_list_menu.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

class VcpConfirmPopup;
class VcpIndicatorPopup;
class VcpToolBar;
class VcpStatusIconBar;
class VcpTextView;

/*****************************************************************************
 * Class VappOomScr
 *****************************************************************************/

class VappOomScr : public VfxAppCatScr, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    VappOomScr(mmi_id asmManagerGid, mmi_id launchAppId);

// Method
public:
    void onStopFinished();
    void onAppClosed(void);
	void ShowIndicatorPopup();



// Override
public:
	virtual VfxU32 getCount() const;

    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );

	virtual VfxBool getItemTextFormat(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VcpRichText &format
        );

    virtual VfxBool getItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image
        );

    virtual VfxBool getItemIsHighlightable(
        VfxU32 index
        ) const;
            
// Override
protected:
    // on init
    virtual void onInit();
    // on deinit
    virtual void onDeinit();

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Variable
private:
    enum VappStopState
    {
        STOPPING,
        STOPPED,
		CANCEL
    };
    VappStopState m_appStopState;
    mmi_id m_launchAppId;
    mmi_id m_asmManagerGid;
    mmi_id m_appToStop;

    applib_mem_ap_usage_struct * m_appList;
    VfxU32 m_appCount;

    VcpListMenu *       m_list;
    VcpConfirmPopup *   m_confirmPopup;
    VcpIndicatorPopup * m_indicatorPopup;
    VcpToolBar *        m_toolbar;
    VcpStatusIconBar *  m_statusBar;
    VcpTextView *       m_text;
    VfxBool             m_popupConfirmed;

// Implementation
private:
    void initAppList();
    void deinitAppList();
    void reloadAppList();

    void onListTapped(VcpListMenu * sender, VfxU32 index);
    void onCmdButtonClicked(VcpListMenu * sender, VfxU32 index);

    void confirmPopupHandler(VfxObject* obj, VfxId id);
    void onToolbarClick(VfxObject* obj, VfxId id);

    VfxWString getAppTitle(VfxU32 index);

    void onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state);

};


#endif // __VAPP_COSMOS_OOM_H__

