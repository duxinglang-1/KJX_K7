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
 *  vapp_search_widget_base_class.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SEARCH_WIDGET_BASE_CLASS_H__
#define __VAPP_SEARCH_WIDGET_BASE_CLASS_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
 #include "MMI_features.h" 

#if defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__) || defined (__MMI_VUI_WIDGET_GOOGLE__)
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_list_menu.h" 
#include "vapp_widget.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Pre-Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * 
 *****************************************************************************/
class VappWidgetSearchEditor : public VappWidget
{
	VFX_DECLARE_CLASS(VappWidgetSearchEditor);

protected:
	enum
		{
#ifdef __MMI_MAINLCD_480X800__
			IMAGE_HEIGHT		= 99,
			IMAGE_WIDTH 		= 449,
			TEXT_HEIGHT	    	= 38,
			TEXT_WIDTH 		    = 265,
			HINT_SIZE			= 32,
			HINT_POS_X			= 100,
			HINT_POS_Y			= 30,
			OFFSET_X			= 7,
			OFFSET_Y			= 15,

			GPLUS_SIZE           = 65,
			GPLUS_GAP           = 15,
            IMAGE1_HEIGHT        = 99,
            IMAGE1_WIDTH         = 347,
            IMAGE2_HEIGHT        = 99,
            IMAGE2_WIDTH         = 99,
            IMAGE2_GAP           = 3,
            TEXT1_WIDTH          = 223,
			
#elif __MMI_MAINLCD_320X480__
			IMAGE_HEIGHT		= 65,
			IMAGE_WIDTH 		= 290,
            TEXT_HEIGHT         = 25,
            TEXT_WIDTH          = 160,
			HINT_SIZE			= 20,
			HINT_POS_X			= 68,
			HINT_POS_Y			= 20,
			OFFSET_X			= 17,
			OFFSET_Y			= 15,

			GPLUS_SIZE			 = 38,
			GPLUS_GAP           = 12,
            IMAGE1_HEIGHT        = 65,
            IMAGE1_WIDTH         = 224,
            IMAGE2_HEIGHT        = 65,
            IMAGE2_WIDTH         = 65,
            IMAGE2_GAP           = 1,
            TEXT1_WIDTH          = 132,
			
#else // __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__
			IMAGE_HEIGHT		= 51,
			IMAGE_WIDTH 		= 226,
            TEXT_HEIGHT         = 23,
            TEXT_WIDTH          = 134,
			HINT_SIZE			= 18,
			HINT_POS_X			= 50,
			HINT_POS_Y			= 15,
			OFFSET_X			= 15,
			OFFSET_Y			= 12,

			GPLUS_SIZE			 = 35,
			GPLUS_GAP           = 6,
            IMAGE1_HEIGHT        = 50,
            IMAGE1_WIDTH         = 174,
            IMAGE2_HEIGHT        = 50,
            IMAGE2_WIDTH         = 50,
            IMAGE2_GAP           = 1,
            TEXT1_WIDTH          = 106
#endif
		};

public:

	VappWidgetSearchEditor();

// Override
protected:
	virtual void onCreateView();
	virtual void onReleaseView();

public:
	void onWidgetClick(VfxObject *obj, VfxId id);
    void onWidgetIconClick(VfxObject *obj, VfxId id);
	void setWidgetHint(VfxResId resId);
    void setWidgetImage(VfxResId resId);
    void setWidgetImage(VcpStateImage imagelist);
    void setWidgetIconImage(VfxResId resId);
    void setWidgetIconImage(VcpStateImage imagelist);
    void setWidgetIcon2Image(VcpStateImage imagelist);
    void onCreate2ndIcon(VfxBool setIcon);
    
//Override
	virtual void setOnWidgetClick()=0;
    virtual void setOnWidgetIconClick();
	virtual VfxPoint onGetEditButtonOffset();

private:
	VcpImageButton *m_button;
    VcpImageButton *m_icon;
    VcpImageButton *m_icon2;
	VfxTextFrame *m_text;

};


#endif /* defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__) || defined (__MMI_VUI_WIDGET_GOOGLE__) */

#endif /* __VAPP_SEARCH_WIDGET_BASE_CLASS_H__ */
