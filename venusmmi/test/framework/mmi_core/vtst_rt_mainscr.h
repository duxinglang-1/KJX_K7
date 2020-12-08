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
 *  vtst_hello.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Hello World example for Venus UI
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
#ifndef __VTST_RT_MAINSCR_H__
#define __VTST_RT_MAINSCR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
// by RHR //#include "vfx_mc_include.h"
// by RHR //#include "vfx_uc_include.h"
// by RHR //#include "vcp_include.h"
#include "vtst_rt_main.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_page_bar.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vcp_switch.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vcp_command_title.h"
#include "vfx_signal.h"
#include "vcp_segment_button.h"
#include "vfx_archive.h"

/***************************************************************************** 
 * Class 
 *****************************************************************************/
#if defined(__COSMOS_MMI__)
#define VTST_MS_MAX_LINES   14
#else
#define VTST_MS_MAX_LINES   12
#endif

class VtstMSApp : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstMSApp);

protected:
    virtual void onInit();

// Method
public:
    void writeLine(const VfxWString &str);
    void getLines(VfxWString &str) const;
    void clearLines();

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);

public:
    typedef struct {
        VfxS32 type;
    } TstParams;

    VfxWString m_lines[VTST_MS_MAX_LINES];
    VfxS32 m_start;
    VfxS32 m_count;

};

class VtstMSAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstMSAppScr);

// Method
public:
    void delayPushPage(const VfxClassInfo *info, VfxMsec delay = 0);

// Override
protected:
    virtual void on1stReady();

// Implementation
private:
    void _pushPage(const VfxClassInfo *info);
    void onTimer(VfxTimer* t);
};

class VtstMSAppBasePage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstMSAppBasePage);
public:
    VtstMSAppBasePage() : m_frame(NULL), m_tf(NULL) {}

    VfxPageBar *initTitlebar(const VfxWString &str);
    VfxPageBar *initToolbar(VfxResId id1, VfxResId id2 = 0, VfxResId id3 = 0);
    void init2WayButton();
    void setColor(const VfxColor &color);

    void setHint(const VfxWString &str);
    void addFunc(const VfxWString &str, VfxId id);
    void addSwitch(const VfxWString &str, VfxId id_on, VfxId id_off, VfxBool);

protected:
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
    virtual void onFunc(VfxId funcId) {}

    enum {
        FUNC_ID_PREV = 1,
        FUNC_ID_NEXT,
        FUNC_ID_END_OF_ENUM
    };
    void _onClicked(VfxObject *obj, VfxId id);
    void _onSwitch(VcpSwitch *obj, VfxBool isChecked);
    
private:
    VfxFrame        *m_frame;
    VfxTextFrame    *m_tf;
    VfxPoint        m_nextPos;
};

class VtstMSAppTitleBar : public VfxPageBar
{
    VFX_DECLARE_CLASS(VtstMSAppTitleBar);
public:
    VtstMSAppTitleBar() : m_title(NULL) {}
    
    void setTitle(const VfxWString &str) { m_title->setText(str); }
    void setButton(VfxU32 index, const VfxWString &str, VfxId id, VcpCommandTitleButtonCB handler);
protected:
    virtual void onInit();
    virtual void onSetTranslucent(VfxBool on);
    virtual void setBounds(const VfxRect &value);

private:
    VcpCommandTitle *m_title;
};

class VtstMSAppToolBar : public VfxPageBar
{
    VFX_DECLARE_CLASS(VtstMSAppToolBar);
protected:
    virtual void onInit();
    virtual void onSetTranslucent(VfxBool on);
private:    
    void onBoundChanged(VfxFrame *f, const VfxRect &r);
public:
    VcpSegmentButton *m_sb;
};


class VtstMSEventScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstMSEventScr);

public:
    VtstMSEventScr():m_id(0) {};

// Override
protected:
    virtual void on1stReady();

    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual VfxBool onSerialize(VfxArchive &ar);
    virtual void onRestore(VfxArchive &ar);

private:
    VtstMSApp* getMyApp() const { return VFX_OBJ_DYNAMIC_CAST(getApp(), VtstMSApp); }
    void print(const VfxChar *str);

public:
    VfxId m_id;
};

class VtstMSEventPage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstMSEventPage);

public:
    VtstMSEventPage():m_id(0),m_count(0) {};

// Method
public:
    void updateContent();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited();
    virtual VfxBool onSerialize(VfxArchive &ar);
    virtual void onRestore(VfxArchive &ar);
    virtual void onBack();

private:
    VtstMSApp* getMyApp() const { return VFX_OBJ_DYNAMIC_CAST(getApp(), VtstMSApp); }
    void print(const VfxChar *str);
    void onClicked(VfxObject *obj, VfxId id);

public:
    VfxTextFrame *m_tf;
    VfxTextFrame *m_tf1;
    VfxTextFrame *m_tf2;
    VfxId m_id;
private:
    VfxU32 m_count;
};



#endif /* __VTST_RT_MAINSCR_H__ */

