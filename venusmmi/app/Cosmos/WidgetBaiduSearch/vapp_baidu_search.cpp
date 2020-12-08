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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_baidu_search.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#if defined(__MMI_BAIDU_SEARCH_COSMOS__)
#include "vapp_Baidu_Search.h"
#include "Mmi_rp_vapp_baidu_search_def.h"
#include "nvram_common_defs.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vcp_include.h"
extern "C"
{
#include "GlobalResDef.h"   
#include "browser_api.h"
#include "PhbSrvGprot.h" 
#include "SearchWebBaiduConfig.h"

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__) 
#include "dcmgr.h" // DCM
#endif
}



/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void vapp_baidu_search_launch(void)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
		DCM_Load(DYNAMIC_CODE_COMPRESS_BAIDUSEARCH, 0, 0);
#endif
    VfxAppLauncher::launch( 
        VAPP_BAIDU_SEARCH,
        VFX_OBJ_CLASS_INFO(VappBaiduSearchApp),
        GRP_ID_ROOT);
}

#pragma arm section code = "DYNAMIC_CODE_BAIDUSEARCH_ROCODE", rodata = "DYNAMIC_CODE_BAIDUSEARCH_RODATA"
VFX_IMPLEMENT_CLASS("VappBaiduSearchApp", VappBaiduSearchApp, VfxApp);
void VappBaiduSearchApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappBaiduSearchScreen *scr;
    VFX_OBJ_CREATE(scr, VappBaiduSearchScreen, this);
    scr->show();
}

mmi_ret VappBaiduSearchApp::onProc(mmi_event_struct *evt)
{
    return VfxApp::onProc(evt);
}

void VappBaiduSearchApp::onDeinit()
{
    VfxApp::onDeinit();

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_BAIDUSEARCH);
#endif
}

VFX_IMPLEMENT_CLASS("VappBaiduSearchScreen", VappBaiduSearchScreen, VfxMainScr);

void VappBaiduSearchScreen::on1stReady()
{
    VfxMainScr::on1stReady();
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // create and display first page
    VappBaiduSearchPage *page;
    VFX_OBJ_CREATE(page, VappBaiduSearchPage, this);
    pushPage(0, page);
}

VFX_IMPLEMENT_CLASS("VappBaiduSearchPage", VappBaiduSearchPage, VappSearchWidgetBasePage);
VappBaiduSearchPage::VappBaiduSearchPage()
	//m_app(NULL)
{
		

}

void VappBaiduSearchPage::onInit()
{
	VfxImageSrc iconImage((VfxResId) IMG_ID_VAPP_BAIDU_ICON);
	
	VappSearchWidgetBasePage::setIcon(iconImage);
	
	VappSearchWidgetBasePage::setSearchHistory(m_buffer);    
    
    VappSearchWidgetBasePage::setListSearchIconID((VfxResId) IMG_ID_VAPP_BAIDU_SEARCH_LIST_SEARCH_ICON);
    
    VappSearchWidgetBasePage::setSearchButtonNID((VfxResId) IMG_ID_VAPP_BAIDU_SEARCH_BUTTON_N);
    
    VappSearchWidgetBasePage::setSearchButtonPID((VfxResId) IMG_ID_VAPP_BAIDU_SEARCH_BUTTON_P);
    
    VappSearchWidgetBasePage::setTitleBGID((VfxResId) IMG_ID_VAPP_BAIDU_SEARCH_TITLE_BG);

    VappSearchWidgetBasePage::setSearchStringID(STR_ID_VAPP_BAIDU_SEARCH_SEARCH);

    VappSearchWidgetBasePage::onInit(); // call base class

	memset(m_fromValue,0,sizeof(m_fromValue));
}

void VappBaiduSearchPage::loadingSearchHistory(void)
{
	VfxS16 error;

	memset(m_buffer,0,sizeof(m_buffer));
	
	VfxS32 i;
	for(i=0;i<NVRAM_EF_BAIDU_SEARCH_TOTAL;i++)
	{
		ReadRecord(
			NVRAM_EF_BAIDU_SEARCH_LID, i+1, m_buffer + i * (NVRAM_EF_BAIDU_SEARCH_SIZE/2),
			NVRAM_EF_BAIDU_SEARCH_SIZE, &error);
	}

}

void VappBaiduSearchPage::writeSearchHistory(void)
{
	VfxS16 error;
	VfxS32 i;

	for(i=0;i<NVRAM_EF_BAIDU_SEARCH_TOTAL;i++)
	{
		WriteRecord(
			NVRAM_EF_BAIDU_SEARCH_LID, i+1, m_buffer + i * (NVRAM_EF_BAIDU_SEARCH_SIZE/2),
			NVRAM_EF_BAIDU_SEARCH_SIZE, &error);
	}

}

void VappBaiduSearchPage::launchBrowser(VfxWChar *inputText)
{
		VfxWChar text[200];
		VfxChar *fromValue;
		VfxWChar fromValeTemp[10];
		VfxS32 i;
		
		fromValue = generateFromValue();

		for(i=0;i<10;i++)
		{
			fromValeTemp[i] = (VfxWChar)fromValue[i];
		}
			
		mmi_wcscpy(text, (VfxWChar*)L"http://wap.baidu.com/s?vit=union&from=");//&word=");
		mmi_wcscat(text, fromValeTemp);
		mmi_wcscat(text, (VfxWChar*)L"&word=");
		mmi_wcscat(text, inputText);
		mmi_wcscat(text, (VfxWChar *)L"&uid=mtk_123&ua=");//mtk_width_height&bd_page_type=1");
		mmi_wcscat(text, (VfxWChar *)(MKT_WIDTH_HIGHT));
		mmi_wcscat(text, (VfxWChar *)L"&bd_page_type=1");
#ifdef BROWSER_SUPPORT
		wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)text);	
#endif
}

VfxChar * VappBaiduSearchPage::generateFromValue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU32 hash_value;
    const VfxChar *cu_p;
    VfxU32 result[4];
    VfxChar *from_value;
	
	from_value = m_fromValue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (m_fromValue[0] == '\0') /* Not initialized */
    {
       /*
             * Generate UID by Bai-hash algorithm, do not modify unless you
             * know what you are doing.
             */
            hash_value = 0;
        for (cu_p = MMI_SEARCH_WEB_BAIDU_CUSTOMER_ID; *cu_p; cu_p++)
        {
            hash_value += (*cu_p << 2) | (*cu_p >> 1);
        }
        hash_value = hash_value & 0xffff; /* Only reserve 16 bits */

        /* Shuffle */
        result[3] = (hash_value & 0xff);
        result[2] = (hash_value ^ (VfxU32)result[3]);
        result[1] = (hash_value ^ (VfxU32)result[3]) + (1 << 3);
        result[0] = (hash_value ^ (VfxU32)result[1]);
        result[1] ^= result[0] ^= result[1] ^= result[0];
        result[1] ^= hash_value;
        result[1] -= 3;
        /* Trim */
        result[0] &= 0xf;
        result[1] &= 0xf;
        result[2] &= 0xf;
        /* Check sum */
        result[3] = (result[0] + result[1] + result[2] - 1) & 0xf;

        from_value[0] = mmi_baidu_search_to_hex_char(result[0]);
        from_value[1] = mmi_baidu_search_to_hex_char(result[1]);
        from_value[2] = mmi_baidu_search_to_hex_char(result[2]);
        memcpy(from_value + 3, MMI_SEARCH_WEB_BAIDU_CUSTOMER_ID, 4);
        from_value[7] = (VfxWChar)(mmi_baidu_search_to_hex_char(result[3]) ^ ('a' ^ 'A'));
        from_value[8] = '\0';
    }

    return from_value;
}
#pragma arm section code, rodata
#endif /* __MMI_BAIDU_SEARCH_COSMOS__ */

