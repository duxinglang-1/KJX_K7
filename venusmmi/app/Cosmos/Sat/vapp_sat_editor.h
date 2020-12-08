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
 *  Vapp_sat_editor.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SAT Editor Class header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SAT_EDITOR_H__
#define __VAPP_SAT_EDITOR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vfx_cpp_base.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vfx_string.h"

#include "vapp_sat_gprot.h"
#include "vapp_sat_base.h"
#include "mmi_rp_vapp_sat_def.h"


/***************************************************************************** 
 * Class VappSatEditorPage
 *****************************************************************************/
class VappSatEditorPage : public VappSatBasePage
{
   // VFX_DECLARE_CLASS(VappSatEditorPage);

public:
    VappSatEditorPage(const VfxWString &text = VFX_WSTR_NULL, const VfxImageSrc &imgSrc = VFX_IMAGE_SRC_NULL);
    VappSatEditorPage(srv_sat_proactive_sim_struct *cmdInfo);
    virtual ~VappSatEditorPage();

private:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    void cmdParser();

private:
    virtual VfxBool onResponse(VappSatToolbarTypeEnum BtnId);

    void updateEditorPage();
	#ifndef __SAT_DISABLE_ICON_SUPPORT__
    void updateImageFrame();
	#endif 
    void updateTextFrame();
    void updateTextEditor();

    void showEditorHintCount();
    void onEditorTextChanged(VcpTextEditor *editor);
    void onOKBtnClicked(VfxObject* sender, VfxId id);

public:
    void setText(const VfxWString &text);
    VfxWString getText() const;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    void setIcon(const VfxImageSrc &imgSrc);
    VfxImageSrc getIcon() const;
#endif 
    void setMultiLines(VcpTextLineModeEnum mode);
    VcpTextLineModeEnum getLineMode() const;

    void setInputMethod();
    void setEditorBuffer(VfxWChar *txtBuffer, const VfxU8 &length);
    const VfxWChar *getEditorBuffer(void) const;
    VfxU8 getEditorHeight() const;

    void setMinNum(VfxU32 num);
    void setMaxNum(VfxU32 num);

private:
    VfxWString  m_text;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    VfxImageSrc m_icon;
#endif 

    VcpTextLineModeEnum m_multiMode;
    VfxU8 m_height;
    WCHAR *m_editBuf;
    VfxU16 m_minNum;
    VfxU16 m_maxNum;
    srv_sat_input_enum m_inputMethod;
    VfxBool m_echoMode;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    VfxImageFrame   *m_imageFrame;
#endif
    VfxTextFrame    *m_textFrame;
    VcpTextEditor   *m_textEditor;
    VcpFunctionBar  *m_funcBar;

    VcpForm     *m_form;
    VfxS32       m_formHeight;

private:
    const static VfxU32 VAPP_SAT_EDITOR_PAGE_ICON_MARGIN = 10;
    const static VfxU32 VAPP_SAT_EDITOR_PAGE_ICON_DOWN_MARGIN = 10;
};

#endif /* __VAPP_SAT_EDITOR_H__ */
