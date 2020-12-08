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

/*****************************************************************************
 *
 * Filename:
 * ---------
 //kcui
 *   vcui_tone_selector.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Tone Selector CUI header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUI_TONE_SELECTOR_FTO_H__
#define __CUI_TONE_SELECTOR_FTO_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vcp_form.h"
#include "vcp_page_panel.h"
#include "vcp_tabctrl_page.h"

//kcui
#include "vcui_tone_selector_gprot.h"

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/

class VappToneSelector;
class VappToneSelectorScreen;
class VappToneSelectorPage;


/***************************************************************************** 
 * Class VappToneSelector
 *****************************************************************************/
class VappToneSelector : public VfxCui
{
    VFX_DECLARE_CLASS(VappToneSelector);

public:
    VfxU8  m_toneNum;
    VfxU8  m_toneBegin;
    VfxU8  m_toneEnd;
    
    VfxU8  m_ringNum;
    VfxU8  m_ringBegin;
    VfxU8  m_ringEnd;

    VfxU8  m_fileNum;
    VfxU8  m_fileBegin;
    VfxU8  m_fileEnd;

    VfxU16 m_filter;
    VfxS32 m_audioId;
    VfxS32 m_previewId;
    VfxS32 m_previewIndex;
    VfxResId m_strId;
    void*  m_userData;
    mmi_id m_cuiId;
    mmi_id m_fsCuiId;
    VappToneSelectorPage *m_mainpage;

    VappToneSelector();

protected:

    virtual void onInit(void);
    virtual void onDeinit(void);

    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *param);          
    virtual void onGroupTopActive(void);
    virtual void onGroupTopInactive(void);

public:
    VfxS8 countIndex(void);
    void postResultToParent(VfxBool is_default_sound);
    void exitRequest(void);

private:
    void fileSelected(void);

};

/***************************************************************************** 
 * Class VappToneSelectorScreen
 *****************************************************************************/
class VappToneSelectorScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappToneSelectorScreen);

// Override
public:
    virtual void on1stReady(void);
};

/***************************************************************************** 
 * Class VappToneSelectorPage
 *****************************************************************************/
class VappToneSelectorPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappToneSelectorPage);

private:
    enum
    {
        BUTTON_SAVE = 0,
        BUTTON_CANCEL
    };

    enum VappToneSelectorResTypeEnum
    {
        AUDIO_RES_FILE,           /* File*/  
        AUDIO_RES_TONE,           /* Tone */
        AUDIO_RES_RING            /* Ring */
    };

public:
    VappToneSelector *m_cui;
    VcpListMenu * m_toneList;


public:
    virtual void onInit(void);
    virtual void onExit(VfxBool isBackward);
    virtual void onBack(void);
    void previewToneStop(void);

    virtual VcpListMenuCellBaseControl* getItemCustomControl(
                                           VfxU32 index,                                    // [IN] index of the item
                                           VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
                                           VfxFrame *parentFrame                            // [IN] parent frame of the custom content frame
                                           );

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                        VfxU32 index,                    // [IN] the index of item
                        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                        VfxWString &text,                // [OUT] the text resource
                        VcpListMenuTextColorEnum &color  // [OUT] the text color
                        );

    // Get the item count of the lis menu
    virtual VfxU32 getCount(void) const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
                                        VfxU32 index   // [IN] index of the item
                                        ) const;

    virtual VfxBool getItemImage(
                        VfxU32 index,                    // [IN] the index of item
                        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                        VfxImageSrc &image               // [OUT] the image resource
                        );

private:
    void drawPage(void);
    void onItemSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onItemTapped(VcpListMenu *menu, VfxU32 index);
    void onCmdButtonClicked(VcpListMenu *menu, VfxU32 index);
    void onButtonTap(VfxObject* obj, VfxId id);
    VappToneSelectorResTypeEnum indexMapping(VfxU32 index, VfxU32 &offset)const;
    static void previewTonePlayCallback(mdi_result result, void *user_data);
    VfxBool previewTonePlay(VfxU32 index);
    void enterFileSelector(void);

};

#endif
