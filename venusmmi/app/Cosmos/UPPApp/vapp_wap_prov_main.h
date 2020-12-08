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
 * vapp_wap_prov_main.h
 *
 * Project:
 * --------
 *   MAUI
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_WAP_PROV_MAIN_H_
#define _VAPP_WAP_PROV_MAIN_H_

#include "MMI_include.h"
#include "MMIDataType.h"


//extern "C" S32 vapp_wap_prof_prov_app_prov_screen_hdlr(mmi_event_struct* param);
extern void vapp_wap_prov_app_create_display_info(U8 *out_buffer, S32 size);


class VappProvSettingPage : public VfxPage
{
// Override
public:
	enum
	{
		PROV_SETTING_VIEWER_INSTALL,
		PROV_SETTING_VIEWER_SKIP
	};

      enum {
#if defined(__MMI_MAINLCD_320X480__)
        LEFT_GAPS = 8,
        RIGHT_GAPS = 8,
        TOP_GAPS = 8,
        BOTTOM_GAPS = 8
#elif defined(__MMI_MAINLCD_480X800__)
        LEFT_GAPS = 14,
        RIGHT_GAPS = 14,
        TOP_GAPS = 14,
        BOTTOM_GAPS = 14
#else
        LEFT_GAPS = 5,
        RIGHT_GAPS = 5,
        TOP_GAPS = 5,
        BOTTOM_GAPS = 5
#endif
    } ;

	VcpToolBar *m_tool_bar;

	VfxWChar *m_bodyText;
	VcpTitleBar *m_titleBar;
    
    //VappWapPushViewerBody    *m_pushViewerBody;

 	VcpTextView *m_bodyTextView;


	VappProvSettingPage()
    {};

	virtual void onInit();
	//virtual VfxBool onKeyInput(VfxKeyEvent &event);
	void onProvSettingPageTBClick(VfxObject* sender, VfxId id); 
	//void setBodyText(pmg_detailed_msg_struct *msg, VfxS8 *url);
	virtual void onBack();
	void exitProvScrnHandler(VfxObject* obj, VfxId id);
	virtual void onDeinit();
    //VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
	virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
    	//support all rotation
    }

};

class VappProvSettingScr : public VfxMainScr
{

// constuctor / destructor
public:
    // default constructor just use for VFX_IMPLEMENT_CLASS
	VappProvSettingScr(){};
    //VappProvSettingScr(mmi_id cuiId);
    virtual ~VappProvSettingScr() {}

// override
public:
   virtual void on1stReady();
  
// method
public:
    mmi_id getCuiId() {return m_cuiId;}
    VappProvSettingPage *m_page;
	void redrawPage()
	{
        vapp_wap_prov_app_create_display_info((VfxU8*)(m_page->m_bodyText), 1024);
     // popPage();
    //VappProvSettingPage *m_page;
    //VFX_OBJ_CREATE(m_page, VappProvSettingPage, this);
	//pushPage(0, m_page);
        m_page->m_bodyTextView->setText(m_page->m_bodyText, NULL);
	}

private:
    mmi_id m_cuiId; // use this to record group id

};


class VappProvSettingDisplay : public VfxCui
{
    VFX_DECLARE_CLASS(VappProvSettingDisplay);

public:  
// Constructor / Destructor
    VappProvSettingDisplay(){}
    virtual ~VappProvSettingDisplay() {}
    
// Override
public:
    // initial parameter and entry main src
    virtual void onRun(
        void *arg,          // parameter
        VfxU32 argSize      // parameter size  
    ); 
    virtual mmi_ret onProc(
        mmi_event_struct * evt
    );


	//friend void cui_prov_setting_redisplay(mmi_id cui_id);

// Method
public:

// Implementation

//private:
    VappProvSettingScr *m_scr;
};



#endif /* _VAPP_WAP_PROV_MAIN_H_ */
