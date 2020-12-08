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
 *  vapp_search_page_base_class.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SEARCH_PAGE_BASE_CLASS_H__
#define __VAPP_SEARCH_PAGE_BASE_CLASS_H__

#include "MMI_features.h" 

#if defined(__MMI_BAIDU_SEARCH_COSMOS__) || defined (__MMI_GOOGLE_SEARCH_COSMOS__)

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_list_menu.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define KEY_WORD_MAX_LENGTH 101
#define HISTORY_MAX_COUNT   20
#define MAX_PINYIN_LEN      6

/*****************************************************************************
 * Pre-Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Baidu Search App 
 *****************************************************************************/

class VappSearchWidgetBasePage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSearchWidgetBasePage);
public:
    VappSearchWidgetBasePage();

	enum{
	#ifdef __MMI_MAINLCD_480X800__ 
		ICON_POS_X                 = 45,
		ICON_POS_Y                 = 44,
		ICON_SIZE                  = 60,
		TEXT_EDITOR_POS_X          = 90,
		TEXT_EDITOR_POS_Y          = 10,
		TEXT_EDITOR_POS_WIDTH      = 292,
		TEXT_EDITOR_POS_HEIGHT     = 70,
		TEXT_ZISE                  = 32,
		TEXT_EDITOR_LEFT_MARGIN    = 0,
		TEXT_EDITOR_TOP_MARGIN     = 0,
		TEXT_EDITOR_RIGHT_MARGIN   = 0,
		TEXT_EDITOR_BOTTOM_MARGIN  = 0,
		BUTTON_POS_X               = 429,
		BUTTON_POS_Y               = 44,
		BUTTON_POS_WIDTH           = 70,
		BUTTON_POS_HEIGHT          = 70,

    #elif defined __MMI_MAINLCD_320X480__
		ICON_POS_X			       = 25,
		ICON_POS_Y			       = 25,
		ICON_SIZE                  = 34,
		TEXT_EDITOR_POS_X	       = 50,
		TEXT_EDITOR_POS_Y	       = 6,
		TEXT_EDITOR_POS_WIDTH      = 214,
		TEXT_EDITOR_POS_HEIGHT     = 40,
		TEXT_ZISE                  = 20,
		TEXT_EDITOR_LEFT_MARGIN    = 4,
		TEXT_EDITOR_TOP_MARGIN     = 11,
		TEXT_EDITOR_RIGHT_MARGIN   = 0,
		TEXT_EDITOR_BOTTOM_MARGIN  = 0,
		BUTTON_POS_X		       = 291,
		BUTTON_POS_Y		       = 25,
		BUTTON_POS_WIDTH	       = 40,
		BUTTON_POS_HEIGHT	       = 40,

	#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
		ICON_POS_X			       = 20,
		ICON_POS_Y			       = 21,
		ICON_SIZE                  = 29,
		TEXT_EDITOR_POS_X	       = 39,
		TEXT_EDITOR_POS_Y	       = 4,
		TEXT_EDITOR_POS_WIDTH      = 155,
		TEXT_EDITOR_POS_HEIGHT     = 36,
		TEXT_ZISE                  = 18,
		TEXT_EDITOR_LEFT_MARGIN    = 4,
		TEXT_EDITOR_TOP_MARGIN     = 5,
		TEXT_EDITOR_RIGHT_MARGIN   = 0,
		TEXT_EDITOR_BOTTOM_MARGIN  = 0,
		BUTTON_POS_X		       = 216,
		BUTTON_POS_Y		       = 21,
		BUTTON_POS_WIDTH	       = 37,
		BUTTON_POS_HEIGHT	       = 36,

	#endif
		};
	
// Override
public:
	virtual void onInit();
	virtual void onDeinit();
	virtual mmi_ret onProc(mmi_event_struct *evt);
	virtual VfxBool onPenInput(VfxPenEvent & event);
	virtual void loadingSearchHistory(void)=0;
	virtual void writeSearchHistory(void)=0;
	virtual void launchBrowser(VfxWChar *inputText)=0;

	void setSearchHistory(VfxWChar buffer[2000]);
	void onSearchBntClicked(VfxObject *obj, VfxId id);
	void onSearchHistory(VcpTextEditor *editor);
	void onItemTap(VcpListMenu *listmenu, VfxU32 id);
	void onBBarClicked(VfxObject *obj, VfxId id);
	void setIcon(VfxImageSrc iconImage);    
    void setListSearchIconID(VfxResId resId);
    void setSearchButtonNID(VfxResId resId);
    void setSearchButtonPID(VfxResId resId);
    void setTitleBGID(VfxResId resId);
    void setSearchStringID(VfxResId resId);
	
protected:
	virtual VfxU32 getCount() const;
	
	virtual VfxBool getItemText(
		VfxU32 index, 
		VcpListMenuFieldEnum fieldType, 		 
		VfxWString &text,						 
		VcpListMenuTextColorEnum &color);
	
	virtual VfxBool getItemImage(
		VfxU32 index,					 
		VcpListMenuFieldEnum fieldType,  
		VfxImageSrc &image				
		);
		
private:
	VcpTextEditor *m_textEditor;
	VfxFrame *m_iconFrame;
	VfxWChar *m_strHistory[HISTORY_MAX_COUNT];
	VfxWChar *m_buffer;
	VcpListMenu *m_listmenu;
	VfxWChar *m_keyWord;
	VfxWChar *m_displayHistory[HISTORY_MAX_COUNT];
	VfxImageSrc m_iconImage;
	VfxS32 m_lastEditoLength;
	VfxU16 m_count;
	VfxS16 m_length;    
    VfxResId m_listSearchIconID;
    VfxResId m_searchButtonNID;
    VfxResId m_searchButtonPID;
    VfxResId m_titleBGID;
    VfxResId m_searchSTRID;
};
#endif /* defined(__MMI_BAIDU_SEARCH_COSMOS__) || defined (__MMI_GOOGLE_SEARCH_COSMOS__) */
#endif /* __VAPP_SEARCH_PAGE_BASE_CLASS_H__ */
