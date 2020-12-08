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
 *  vapp_baidu_search.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BAIDU_SEARCH_H__
#define __VAPP_BAIDU_SEARCH_H__

#include "MMI_features.h" 

#ifdef __MMI_BAIDU_SEARCH_COSMOS__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_list_menu.h"
#include "vapp_search_page_base_class.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__ 
	#define MKT_WIDTH_HIGHT L"MTK_480_800"
#elif defined __MMI_MAINLCD_320X480__
	#define MKT_WIDTH_HIGHT L"MTK_320_480"
#elif defined __MMI_MAINLCD_240X320__
	#define MKT_WIDTH_HIGHT L"MTK_240_320"
#elif defined __MMI_MAINLCD_240X400__ 
	#define MKT_WIDTH_HIGHT L"MTK_240_400"
#endif

//#define SEARCH_WIDGET_BAIDU_CUSTOMER_ID            "0000"
#define mmi_baidu_search_to_hex_char(val) (VfxChar)((val) < 10 ? ('0' + (val)) : ('A' + ((val) - 10)))

/*****************************************************************************
 * Pre-Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Baidu Search App 
 *****************************************************************************/

extern "C" void vapp_baidu_search_launch(void);

class VappBaiduSearchApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappBaiduSearchApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onDeinit();
};

class VappBaiduSearchScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappBaiduSearchScreen);

// Override
public:
    virtual void on1stReady();
};

class VappBaiduSearchPage : public VappSearchWidgetBasePage
{
    VFX_DECLARE_CLASS(VappBaiduSearchPage);
public:
    VappBaiduSearchPage();
// Override
public:
    virtual void onInit();
	virtual void loadingSearchHistory(void);
	virtual void writeSearchHistory(void);
	virtual void launchBrowser(VfxWChar *inputText);
	VfxChar * generateFromValue(void);
	
private:
	//VappBaiduSearchApp *m_app;
	VfxWChar m_buffer[KEY_WORD_MAX_LENGTH*HISTORY_MAX_COUNT];
	//VfxImage *m_iconImage;
	VfxChar m_fromValue[10];
};

#endif /* __MMI_BAIDU_SEARCH_COSMOS__ */

#endif /* __VAPP_BAIDU_SEARCH_H__ */

