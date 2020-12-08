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
 *  vapp_XXX.cpp
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
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_wap_push_setting.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_wap_push_interface.h"
#include "Mmi_rp_srv_venus_component_list_menu_def.h"
#include "mmi_rp_vapp_wap_push_launch_viewer_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "App_addr.h"
#include "GlobalResDef.h"

#ifdef __cplusplus
}
#endif


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


VfxBool VappWapPushSettingPageContentProvider::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{    
    switch (index)
    {
        case SRV_WAP_PUSH_SETTING_ENABLE:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_ID_VAPP_PUSH_INBOX_ENABLE_PUSH);
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                text.loadFromRes(getEnablePushString());
            }
        }
        break;
        
        case SRV_WAP_PUSH_SETTING_ENABLE_SL:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_ID_VAPP_PUSH_ENABLE_SERVICE_LOADING);
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                text.loadFromRes(getSLSettingString());
            }
        }
        break;

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_WHITE_LIST:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_ID_VAPP_PUSH_ENABLE_WHITE_LIST);
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                text.loadFromRes(getEnableWLString());
            }
        }
        break;        
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_ID_VAPP_PUSH_ENABLE_BLACK_LIST);
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                text.loadFromRes(getEnableBLString());
            }
        }
        break;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_ID_VAPP_PUSH_WHITE_LIST);
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                return VFX_FALSE;
            }
        }
        break;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_ID_VAPP_PUSH_BLACK_LIST);
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                return VFX_FALSE;
            }
        }
        break;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

        default:
        break;
    }    
    return VFX_TRUE;
}

 VfxBool VappWapPushSettingPageContentProvider::getItemImage(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxImageSrc &image              
    ) 
{
    if (fieldType == VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
    }
    else
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
    }
    return VFX_TRUE;
}

void VappWapPushSettingPage::onInit()
{
    VfxPage::onInit(); // call base class

    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_INBOX_SETTING);
    setTopBar(titleBar); 

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    VFX_OBJ_CREATE(m_listMenuContentProvider, VappWapPushSettingPageContentProvider, this);

    m_listMenuContentProvider->selectedIndex = 0;
    m_menu->setContentProvider(m_listMenuContentProvider);
    m_menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_menu->m_signalItemTapped.connect(this, &VappWapPushSettingPage::onSettingPageItemTapped);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);

    VfxRect page_rect = this->getRect();
    m_menu->setRect(0, 0, page_rect.size.width, page_rect.size.height );
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    setFocused(VFX_TRUE);

}

void VappWapPushSettingPage:: onEnter(VfxBool isBackward)
{
    if(isBackward)
    {
        m_menu->updateAllItems();
    }
}

void VappWapPushSettingPage::onSettingPageItemTapped(VcpListMenu *listMenu, VfxU32  index)
{
    switch (index)
    {
        case SRV_WAP_PUSH_SETTING_ENABLE:
        case SRV_WAP_PUSH_SETTING_ENABLE_SL:
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_WHITE_LIST:
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST:
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
        {
            VappWapPushSettingOptionPage *page;
            VFX_OBJ_CREATE_EX(page, VappWapPushSettingOptionPage, getMainScr(), (index,srv_wap_push_get_setting_index(index)));
            (getMainScr())->pushPage(0, page);	
        }
        break;
        
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            VappWapPushTrustListPage *page;
            VFX_OBJ_CREATE_EX(page, VappWapPushTrustListPage, getMainScr(), (index));
            (getMainScr())->pushPage(0, page);	
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            VappWapPushTrustListPage *page;
            VFX_OBJ_CREATE_EX(page, VappWapPushTrustListPage, getMainScr(), (index));
            (getMainScr())->pushPage(0, page);	
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

        default:
        break;
    }
	
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_enable_push_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 string id for enable push setting setting.
 *****************************************************************************/
VfxU16 VappWapPushSettingPageContentProvider::getEnablePushString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_push_set_p->general_set.enable_push)
    {
        case WAP_PMG_RETR_ACCEPT_ALL:
            return STR_ID_VAPP_PUSH_ENABLE_SETTING_ACCEPT_ALL;
        
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case WAP_PMG_RETR_ACCEPT_AUTH_OR_TRUSTED:
            return STR_ID_VAPP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
        case WAP_PMG_RETR_DISABLED:
            return STR_ID_VAPP_PUSH_DISABLE;
        
        default:
            ASSERT(0);
        break;
    }
    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_sl_setting_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 string id for sl setting setting.
 *****************************************************************************/
VfxU16 VappWapPushSettingPageContentProvider::getSLSettingString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_push_set_p->general_set.sl_setting)
    {
        case SRV_WAP_PUSH_SL_SETTING_PROMPT:
            return STR_ID_VAPP_PUSH_SL_SETTING_PROMPT;
        
        case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
            return STR_ID_VAPP_PUSH_SL_SETTING_AUTO_LAUNCH;
        
        case SRV_WAP_PUSH_SL_SETTING_DISABLED:
            return STR_ID_VAPP_PUSH_DISABLE;
        
        default:
            ASSERT(0);
        break;
    }
    return 0;
}





#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_enable_wl_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 string id for enable white list setting.
 *****************************************************************************/
VfxU16 VappWapPushSettingPageContentProvider::getEnableWLString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_push_set_p->general_set.enable_white_list)
    {
        case WAP_PMG_WL_ACTION_DISCARD:
            return STR_ID_VAPP_PUSH_WL_SETTING_DISCARD;
        break;
        
        case WAP_PMG_WL_ACTION_NOTIFY:
            return STR_ID_VAPP_PUSH_WL_SETTING_NOTIFY;
        break;
        
        case WAP_PMG_WL_DISABLED:
            return STR_ID_VAPP_PUSH_DISABLE;
        break;
        
        default:
            ASSERT(0);
        break;
    }
    return 0;
}



#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


#ifdef __MMI_WAP_PUSH_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_enable_bl_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 string id for enable black list setting.
 *****************************************************************************/
VfxU16 VappWapPushSettingPageContentProvider::getEnableBLString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_push_set_p->general_set.enable_black_list)
    {
        case WAP_PMG_BL_ACTION_NOTIFY:
            return STR_ID_VAPP_PUSH_WL_SETTING_NOTIFY;
        break;
        
        case WAP_PMG_BL_DISABLED:
            return STR_ID_VAPP_PUSH_DISABLE;
        break;
        
        default:
            ASSERT(0);
        break;
    }
    return 0;
}



#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */


/******************************************************************************************************

                            WAP Push Setting Option Page Implementation

*******************************************************************************************************/

void VappWapPushSettingOptionPage::onInit()
{
    VfxPage::onInit(); // call base class

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    setTopBar(m_titleBar); 

    VFX_OBJ_CREATE(m_menuWLSetting, VcpListMenu, this);

    switch (m_pushSettingOption)
    {
        case SRV_WAP_PUSH_SETTING_ENABLE:
        {
            VFX_OBJ_CREATE(m_listMenuPushSettingContentProvider, VappPushSettingContentProvider, this); 
            m_listMenuPushSettingContentProvider->m_selectedIndex = srv_wap_push_get_setting_index(SRV_WAP_PUSH_SETTING_ENABLE);
            m_menuWLSetting->setContentProvider(m_listMenuPushSettingContentProvider);
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_INBOX_ENABLE_PUSH);
        }
        break;
        
        case SRV_WAP_PUSH_SETTING_ENABLE_SL:
        {
            VFX_OBJ_CREATE(m_listMenuSLSettingContentProvider, VappSLSettingContentProvider, this);       
            m_listMenuSLSettingContentProvider->m_selectedIndex = srv_wap_push_get_setting_index(SRV_WAP_PUSH_SETTING_ENABLE_SL);
            m_menuWLSetting->setContentProvider(m_listMenuSLSettingContentProvider);
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_ENABLE_SERVICE_LOADING);
        }
        break;
        
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_WHITE_LIST:
        {
            VFX_OBJ_CREATE(m_listMenuWLSettingContentProvider, VappWLSettingContentProvider, this);       
            m_listMenuWLSettingContentProvider->m_selectedIndex = srv_wap_push_get_setting_index(SRV_WAP_PUSH_SETTING_ENABLE_WHITE_LIST);
            m_menuWLSetting->setContentProvider(m_listMenuWLSettingContentProvider);
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_ENABLE_WHITE_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST:
        {
            VFX_OBJ_CREATE(m_listMenuBLSettingContentProvider, VappBLSettingContentProvider, this);       
            m_listMenuBLSettingContentProvider->m_selectedIndex = srv_wap_push_get_setting_index(SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST);
            m_menuWLSetting->setContentProvider(m_listMenuBLSettingContentProvider);
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_ENABLE_BLACK_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

        default:
        break;
    }


    m_menuWLSetting->m_signalItemTapped.connect(this, &VappWapPushSettingOptionPage::onSettingOptionPageItemTapped);

    m_menuWLSetting->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);        

    m_menuWLSetting->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);

    VfxRect page_rect = getRect();
    m_menuWLSetting->setRect(0, 0, page_rect.size.width, page_rect.size.height );

    m_menuWLSetting->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    setFocused(VFX_TRUE);

}

void VappWapPushSettingOptionPage::onSettingOptionPageItemTapped(VcpListMenu *listMenu, VfxU32  index)
{
    srv_wap_push_set_setting_index(m_pushSettingOption, index);
    (getMainScr())->popPage();	
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
VfxBool VappWLSettingContentProvider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    switch (index)
    {
        case SRV_WAP_PUSH_WL_SETTING_DISCARD:
            text.loadFromRes(STR_ID_VAPP_PUSH_WL_SETTING_DISCARD);
        break;
        
        case SRV_WAP_PUSH_WL_SETTING_NOTIFY:
            text.loadFromRes(STR_ID_VAPP_PUSH_WL_SETTING_NOTIFY);
        break;
        
        case SRV_WAP_PUSH_WL_SETTING_DISABLE:
            text.loadFromRes(STR_ID_VAPP_PUSH_DISABLE);
        break;
        
        default:
            ASSERT(0);
        break;
    }      
    return VFX_TRUE;
}
#endif /*__MMI_WAP_PUSH_WHITE_LIST__*/ 


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
VfxBool VappWLSettingContentProvider::getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
{    
    return VFX_TRUE;
}
#endif /*__MMI_WAP_PUSH_WHITE_LIST__*/ 

VfxBool VappPushSettingContentProvider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    switch (index)
    {
        case SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_ALL:
            text.loadFromRes(STR_ID_VAPP_PUSH_ENABLE_SETTING_ACCEPT_ALL);
        break;
        
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED:
            text.loadFromRes(STR_ID_VAPP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED);
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
        case SRV_WAP_PUSH_ENABLE_SETTING_DISABLE:
            text.loadFromRes(STR_ID_VAPP_PUSH_DISABLE);
        break;
        
        default:
            ASSERT(0);
        break;
    }      
    return VFX_TRUE;
}

VfxBool VappSLSettingContentProvider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    switch (index)
    {
        case SRV_WAP_PUSH_SL_SETTING_PROMPT:
            text.loadFromRes(STR_ID_VAPP_PUSH_SL_SETTING_PROMPT);
        break;
        
        case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
            text.loadFromRes(STR_ID_VAPP_PUSH_SL_SETTING_AUTO_LAUNCH);
        break;
        
        case SRV_WAP_PUSH_SL_SETTING_DISABLED:
            text.loadFromRes(STR_ID_VAPP_PUSH_DISABLE);
        break;
        
        default:
            ASSERT(0);
        break;
    }

    return VFX_TRUE;
}


#ifdef __MMI_WAP_PUSH_BLACK_LIST__
VfxBool VappBLSettingContentProvider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{

    switch (index)
    {
        case SRV_WAP_PUSH_BL_SETTING_NOTIFY:
            text.loadFromRes(STR_ID_VAPP_PUSH_WL_SETTING_NOTIFY);
        break;
        
        case SRV_WAP_PUSH_BL_SETTING_DISABLE:
            text.loadFromRes(STR_ID_VAPP_PUSH_DISABLE);
        break;
        
        default:
            ASSERT(0);
        break;
    }

    return VFX_TRUE;
}

#endif /* __MMI_WAP_PUSH_BLACK_LIST__*/

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
VfxBool VappBLSettingContentProvider::getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
{    
    return VFX_TRUE;
}
#endif
/**********************************************************************************************************

						*********START OF TRUSTLIST PAGE*************


***********************************************************************************************************/

//VFX_IMPLEMENT_CLASS("VappWapPushTrustListPage", VappWapPushTrustListPage, VfxPage);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
void VappWapPushTrustListPage::onInit()
{
    VfxU8 listCount = 0;
    VfxPage::onInit(); // call base class

    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_trustlistSettingScrActiveCallback.emit(VFX_TRUE);

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    setTopBar(m_titleBar); 
    VFX_OBJ_CREATE(m_tool_bar,VcpToolBar,this);
    m_tool_bar->m_signalButtonTap.connect(this, &VappWapPushTrustListPage::onWapPushTrustListTBClick);
    setBottomBar(m_tool_bar);
    m_tool_bar->addItem(TRUSTLIST_ADD, (VfxResId)STR_GLOBAL_ADD,VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    m_tool_bar->addItem(TRUSTLIST_DELETE, (VfxResId)STR_GLOBAL_DELETE,VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

    VFX_OBJ_CREATE(m_listMenuTrustList, VcpListMenu, this);

    switch (m_trustList)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            g_push_set_p->selected_list_type = SRV_WAP_PUSH_WHITE_LIST;
            VFX_OBJ_CREATE(m_listMenuWLContentProvider, VappWLContentProvider, this); 
            m_listMenuTrustList->setContentProvider(m_listMenuWLContentProvider);
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_WHITE_LIST);
            listCount = m_listMenuWLContentProvider->getCount();
            if (listCount && (listCount == srv_wap_push_get_max_white_list()))
            {
                m_tool_bar->setDisableItem(TRUSTLIST_ADD, VFX_TRUE);
            }
            if (!listCount)
            {
                m_tool_bar->setDisableItem(TRUSTLIST_DELETE, VFX_TRUE);
            }
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            g_push_set_p->selected_list_type = SRV_WAP_PUSH_BLACK_LIST;
            VFX_OBJ_CREATE(m_listMenuBLContentProvider, VappBLContentProvider, this); 
            m_listMenuTrustList->setContentProvider(m_listMenuBLContentProvider);
            listCount = m_listMenuBLContentProvider->getCount();
            if (listCount && (listCount == srv_wap_push_get_max_black_list()))
            {
                m_tool_bar->setDisableItem(TRUSTLIST_ADD, VFX_TRUE);
            }
            if (!listCount)
            {
                m_tool_bar->setDisableItem(TRUSTLIST_DELETE, VFX_TRUE);
            }
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_BLACK_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

        default:
        break;
    }

    m_listMenuTrustList->m_signalItemTapped.connect(this, &VappWapPushTrustListPage::onTrustListItemTapped);
    m_listMenuTrustList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_listMenuTrustList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    VfxRect page_rect = getRect();
    m_listMenuTrustList->setRect(0, 0, page_rect.size.width, page_rect.size.height );

    m_listMenuTrustList->setAlignParent(
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE);

    setFocused(VFX_TRUE);
}

void VappWapPushTrustListPage::onEnter(VfxBool isBackward)
{
    updateToolBar();
    if (isBackward)
    {
        m_listMenuTrustList->updateAllItems();
    }
}

void VappWapPushTrustListPage::updateToolBar()
{
    VfxU8 listCount = 0;

    switch (m_trustList)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            listCount = m_listMenuWLContentProvider->getCount();
            if (listCount && (listCount == srv_wap_push_get_max_white_list()))
            {
                m_tool_bar->setDisableItem(TRUSTLIST_ADD, VFX_TRUE);
            }
            else
            {
                m_tool_bar->setDisableItem(TRUSTLIST_ADD, VFX_FALSE);
            }
            if (!listCount)
            {
                m_tool_bar->setDisableItem(TRUSTLIST_DELETE, VFX_TRUE);
            }
            else
            m_tool_bar->setDisableItem(TRUSTLIST_DELETE, VFX_FALSE);
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            listCount = m_listMenuBLContentProvider->getCount();
            if (listCount && (listCount == srv_wap_push_get_max_black_list()))
            {
                m_tool_bar->setDisableItem(TRUSTLIST_ADD, VFX_TRUE);
            }
            else
            {
                m_tool_bar->setDisableItem(TRUSTLIST_ADD, VFX_FALSE);
            }
            if (!listCount)
            {
                m_tool_bar->setDisableItem(TRUSTLIST_DELETE, VFX_TRUE);
            }
            else
            {
                m_tool_bar->setDisableItem(TRUSTLIST_DELETE, VFX_FALSE);
            }            
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

        default:
        break;
    }

}


void VappWapPushTrustListPage::onTrustListItemTapped(VcpListMenu *listMenu, VfxU32  index)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    VfxWChar *senderAddressData(NULL);
    VfxWChar *SMSCAddressData(NULL);
    VfxWChar *IPAddressData(NULL);
    VfxS32	editType;
    VfxS32	titleStrID=0;
    if(m_trustList == SRV_WAP_PUSH_SETTING_WHITE_LIST )
    {
        titleStrID = STR_ID_VAPP_PUSH_EDIT_WHITE_LIST;
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        titleStrID = STR_ID_VAPP_PUSH_EDIT_BLACK_LIST;
    }
#endif /*__MMI_WAP_PUSH_BLACK_LIST__*/
    editType = srv_wap_push_prepare_trustlist_modify_data(&senderAddressData,&SMSCAddressData,&IPAddressData,index);
    VappWapPushTrustListEditPage *page;
    VFX_OBJ_CREATE_EX(page, VappWapPushTrustListEditPage, getMainScr(),(editType,titleStrID,senderAddressData,SMSCAddressData,IPAddressData));
    (getMainScr())->pushPage(0, page);
#endif /*__MMI_WAP_PUSH_WHITE_LIST__*/
}

void VappWapPushTrustListPage::onWapPushTrustListTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case TRUSTLIST_ADD:
        {
            VcpCommandPopup *m_commandPopup;
            VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
            m_commandPopup->setInfoType(VCP_POPUP_TYPE_INFO);
            m_commandPopup->setText((VfxResId)STR_ID_VAPP_PUSH_CHOOSE_THE_MODE);
        #ifdef __MMI_WAP_PUSH_WHITE_LIST__
            m_commandPopup->addItem(TRUSTLIST_ADD_PHONE_NUM, (VfxResId)STR_ID_VAPP_PUSH_INBOX_TRUST_LIST_PHONE_NUMBER);
            m_commandPopup->addItem(TRUSTLIST_ADD_IP_ADDRESS, (VfxResId)STR_ID_VAPP_PUSH_INBOX_TRUST_LIST_IP_ADDRESS);
        #endif /*__MMI_WAP_PUSH_WHITE_LIST__*/
            m_commandPopup->addItem(TRUSTLIST_ADD_CANCEL, (VfxResId)STR_GLOBAL_CANCEL,VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_commandPopup->setAutoDestory(VFX_TRUE);
            m_commandPopup->m_signalButtonClicked.connect(this, &VappWapPushTrustListPage::onTrustListAddCmdClick);
            m_commandPopup->show(VFX_TRUE);
        }            
        break;
        
        case TRUSTLIST_DELETE:
        {
            onWapPushTrustListDelete();
        }            
        break;
        
        default:
        break;
    }
}


void VappWapPushTrustListPage::onWapPushTrustListDelete(void)
{  
    VFX_OBJ_CREATE(m_multiOptionToolBar,VcpToolBar,this);
    m_listMenuTrustList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL);
    m_multiOptionToolBar->m_signalButtonTap.connect(this, &VappWapPushTrustListPage::onWapPushTrustListMultiOptionTBClick);
    setBottomBar(m_multiOptionToolBar);

    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_SELECT_ALL, (VfxResId)STR_GLOBAL_MARK_ALL,VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_DELETE, (VfxResId)STR_GLOBAL_DELETE,VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_CANCEL, (VfxResId)STR_GLOBAL_CANCEL,VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_multiOptionToolBar->setDisableItem(TRUSTLIST_MULTI_OPTION_DELETE, VFX_TRUE);

    switch (m_trustList)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            m_listMenuTrustList->m_signalItemSelectionStateChanged.connect(this, &VappWapPushTrustListPage::onSelectionChanged);
            VFX_ALLOC_MEM(m_listMenuWLContentProvider->m_selectedListInfo, m_listMenuWLContentProvider->getCount(), this);
            memset(m_listMenuWLContentProvider->m_selectedListInfo, 0, m_listMenuWLContentProvider->getCount());
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_DELETE_WHITE_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            m_listMenuTrustList->m_signalItemSelectionStateChanged.connect(this, &VappWapPushTrustListPage::onSelectionChanged);
            VFX_ALLOC_MEM(m_listMenuBLContentProvider->m_selectedListInfo, m_listMenuBLContentProvider->getCount(), this);
            memset(m_listMenuBLContentProvider->m_selectedListInfo, 0, m_listMenuBLContentProvider->getCount());
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_DELETE_BLACK_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    
        default:
        break;
    }

    m_listMenuTrustList->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION); 
    m_listMenuTrustList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenuTrustList->m_signalItemTapped.disconnect(this, &VappWapPushTrustListPage::onTrustListItemTapped);
}


void VappWapPushTrustListPage::onBack()
{
    if(m_multiOptionToolBar)
    { 
        wapPushTrustListMultiCancel();
    }
    else
    {
        VfxPage::onBack();
    }
}

void VappWapPushTrustListPage::onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VfxU32 selListCount = 0;
    VfxU32 totalListCount = 0;

    /*Its safe check, in case m_multiOptionToolBar be deleted and still we receive this signal then return*/
    if (!m_multiOptionToolBar)
    {
        return;
    }	
    switch (m_trustList)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            m_listMenuWLContentProvider->onSelectionChanged(menu, index, newState);
            totalListCount = m_listMenuWLContentProvider->getCount();
            for (VfxU8 loopCount = 0;loopCount<totalListCount;loopCount++)
            {
                if(m_listMenuWLContentProvider->m_selectedListInfo[loopCount] == 1)
                {
                    selListCount++;
                }
            }
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            m_listMenuBLContentProvider->onSelectionChanged(menu, index, newState);
            totalListCount = m_listMenuBLContentProvider->getCount();
            for (VfxU8 loopCount = 0;loopCount<totalListCount;loopCount++)
            {
                if(m_listMenuBLContentProvider->m_selectedListInfo[loopCount] == 1)
                {
                    selListCount++;
                }
            }
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

        default:
        break;
    }

    if (selListCount == totalListCount)
    {
        if (m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_SELECT_ALL))
        {
            m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_DELETE);
            m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_CANCEL);

            m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_UNSELECT_ALL, (VfxResId)STR_GLOBAL_UNMARK_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
            m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_CANCEL,  (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        }
    }
    else
    {
        if (m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_UNSELECT_ALL))
        {
            m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_DELETE);
            m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_CANCEL);

            m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_SELECT_ALL, (VfxResId)STR_GLOBAL_MARK_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
            m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_CANCEL,  (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        }
    }
    if(selListCount)
    {
        m_multiOptionToolBar->setDisableItem(TRUSTLIST_MULTI_OPTION_DELETE, VFX_FALSE);
    }    
    else
    {
        m_multiOptionToolBar->setDisableItem(TRUSTLIST_MULTI_OPTION_DELETE, VFX_TRUE);
    }
    
}	


void VappWapPushTrustListPage::onTrustListAddCmdClick(VfxObject* sender, VfxId id)
{

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    VfxS32	titleStrID=0;
    if(m_trustList == SRV_WAP_PUSH_SETTING_WHITE_LIST )
    {
        titleStrID = STR_ID_VAPP_PUSH_ADD_WHITE_LIST;
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        titleStrID = STR_ID_VAPP_PUSH_ADD_BLACK_LIST;
    }
#endif

    switch(id)
    {
        case TRUSTLIST_ADD_PHONE_NUM:
        {
        /*Need to move to service*/
            g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_ADD_NEW;
            memset(g_push_set_p->smsc_address, 0, sizeof(g_push_set_p->smsc_address));
            memset(g_push_set_p->sender_address, 0, sizeof(g_push_set_p->sender_address));

            VappWapPushTrustListEditPage *page;
            VFX_OBJ_CREATE_EX(page, VappWapPushTrustListEditPage, getMainScr(),(SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER,titleStrID,NULL,NULL,NULL));
            (getMainScr())->pushPage(0, page);
        }

        break;
        
        case TRUSTLIST_ADD_IP_ADDRESS:
        {
            g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_ADD_NEW;
            memset(g_push_set_p->ip_addr, 0, sizeof(g_push_set_p->ip_addr));

            VappWapPushTrustListEditPage *page;
            VFX_OBJ_CREATE_EX(page, VappWapPushTrustListEditPage, getMainScr(),(SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS,titleStrID,NULL,NULL,NULL));
            (getMainScr())->pushPage(0, page);
        }        		
        break;
        
        default:
        break;
    }
#endif /* __MMI_WAP_PUSH_WHITE_LIST__*/   
}

void VappWapPushTrustListPage::onWapPushTrustListActionDelete(VfxObject * obj, VfxId id)
{
    if (VCP_CONFIRM_POPUP_BUTTON_YES == id)
    {
        wapPushTrustListDelete();
    }
}


void VappWapPushTrustListPage::onWapPushTrustListMultiOptionTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case TRUSTLIST_MULTI_OPTION_SELECT_ALL:
        {
            wapPushTrustListMultiSelectAll();
        }            
        break;
        
        case TRUSTLIST_MULTI_OPTION_UNSELECT_ALL:
        {
            wapPushTrustListMultiUnSelectAll();
        }            
        break;
        
        case TRUSTLIST_MULTI_OPTION_DELETE:
        {
            VfxU32 listCount = 0;
            VfxU32 totalListCount;
        #ifdef __MMI_WAP_PUSH_WHITE_LIST__
            if (m_trustList == SRV_WAP_PUSH_SETTING_WHITE_LIST)
            {
                totalListCount = m_listMenuWLContentProvider->getCount();
                for (VfxU8 loopCount = 0;loopCount<totalListCount;loopCount++)
                {
                    if(m_listMenuWLContentProvider->m_selectedListInfo[loopCount] == 1)
                    {
                        listCount++;
                    }
                }
            }
        #ifdef __MMI_WAP_PUSH_BLACK_LIST__
            else
            {
                totalListCount = m_listMenuBLContentProvider->getCount();
                for (VfxU8 loopCount = 0;loopCount<totalListCount;loopCount++)
                {
                    if(m_listMenuBLContentProvider->m_selectedListInfo[loopCount] == 1)
                    {
                        listCount++;
                    }
                }
            }
        #endif /*__MMI_WAP_PUSH_BLACK_LIST__*/
        #endif /*__MMI_WAP_PUSH_WHITE_LIST__*/
            VcpConfirmPopup *confirm;
            VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);

            VfxWString text;
            text.loadFromRes(STR_ID_VAPP_PUSH_DELETE_SELECTED_ITEMS);
            text += VFX_WSTR_RES(STR_ID_VAPP_PUSH_LEFT_BRACE_CHAR);
            text += VfxWString().format("%d", listCount);
            text += VFX_WSTR_RES(STR_ID_VAPP_PUSH_RIGHT_BRACE_CHAR);
            text += VFX_WSTR_RES(STR_ID_VAPP_PUSH_QUESTION_MARK);
            confirm->setText(text);

            confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
            confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            confirm->setCustomButton(
                (VfxResId)STR_GLOBAL_DELETE, 
                (VfxResId)STR_GLOBAL_CANCEL, 
                VCP_POPUP_BUTTON_TYPE_WARNING, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            confirm->m_signalButtonClicked.connect(this, &VappWapPushTrustListPage::onWapPushTrustListActionDelete);
            confirm->show(VFX_TRUE);
        }
        break;
        
        case TRUSTLIST_MULTI_OPTION_CANCEL:
        {
            wapPushTrustListMultiCancel();					
        }			
        break;
        
        default:
        break;
    }
}

void VappWapPushTrustListPage::wapPushTrustListDelete()
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    VfxU8 totalListCount=0;
    VfxU8 totalDeleteCount = 0;
    VfxU8 *arrayIndex=NULL;

    switch (m_trustList)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            totalListCount = m_listMenuWLContentProvider->getCount();
            VFX_ALLOC_MEM(arrayIndex, totalListCount, this);
            for (VfxU8 loopCount = 0;loopCount<totalListCount;loopCount++)
            {
                if(m_listMenuWLContentProvider->m_selectedListInfo[loopCount] == 1)
                {
                    arrayIndex[totalDeleteCount] = loopCount;
                    totalDeleteCount++;
                }
            }
            m_listMenuWLContentProvider->m_selectedListCount = 0;				
            VFX_FREE_MEM(m_listMenuWLContentProvider->m_selectedListInfo);
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_WHITE_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            totalListCount = m_listMenuBLContentProvider->getCount();
            VFX_ALLOC_MEM(arrayIndex, totalListCount, this);
            for (VfxU8 loopCount = 0;loopCount<totalListCount;loopCount++)
            {
                if(m_listMenuBLContentProvider->m_selectedListInfo[loopCount] == 1)
                {
                    arrayIndex[totalDeleteCount] = loopCount;
                    totalDeleteCount++;
                }
            }
            m_listMenuBLContentProvider->m_selectedListCount = 0;
            VFX_FREE_MEM(m_listMenuBLContentProvider->m_selectedListInfo);
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_BLACK_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    
        default:
        break;
    }


    if (totalDeleteCount == totalListCount)
    srv_wap_push_setting_delete_all_list_entry();
    else
    srv_wap_push_delete_list_entry_ex(arrayIndex, totalDeleteCount);

    m_listMenuTrustList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_listMenuTrustList->m_signalItemSelectionStateChanged.disconnect(this, &VappWapPushTrustListPage::onSelectionChanged);
    m_listMenuTrustList->m_signalItemTapped.connect(this, &VappWapPushTrustListPage::onTrustListItemTapped);
    m_listMenuTrustList->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    VFX_OBJ_CLOSE(m_multiOptionToolBar);
    updateToolBar();
    setBottomBar(m_tool_bar);

    m_listMenuTrustList->updateAllItems();
    VFX_FREE_MEM(arrayIndex);
#endif /*__MMI_WAP_PUSH_WHITE_LIST__*/
}

void VappWapPushTrustListPage::wapPushTrustListMultiSelectAll()
{
    m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_SELECT_ALL);
    m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_DELETE);
    m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_CANCEL);

    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_UNSELECT_ALL, (VfxResId)STR_GLOBAL_UNMARK_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_CANCEL,  (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    m_multiOptionToolBar->setDisableItem(TRUSTLIST_MULTI_OPTION_DELETE, VFX_FALSE);

    switch (m_trustList)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            memset(m_listMenuWLContentProvider->m_selectedListInfo, 1, m_listMenuWLContentProvider->getCount());
            m_listMenuTrustList->updateAllItems();
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            memset(m_listMenuBLContentProvider->m_selectedListInfo, 1, m_listMenuBLContentProvider->getCount());
            m_listMenuTrustList->updateAllItems();
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

        default:
        break;
    }
}

void VappWapPushTrustListPage::wapPushTrustListMultiCancel()
{
    switch (m_trustList)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            VFX_FREE_MEM(m_listMenuWLContentProvider->m_selectedListInfo);
            m_listMenuWLContentProvider->m_selectedListCount = 0;
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_WHITE_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            VFX_FREE_MEM(m_listMenuBLContentProvider->m_selectedListInfo);
            m_listMenuBLContentProvider->m_selectedListCount = 0;
            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_BLACK_LIST);
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    
        default:
        break;
    }
    m_listMenuTrustList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_listMenuTrustList->m_signalItemSelectionStateChanged.disconnect(this, &VappWapPushTrustListPage::onSelectionChanged);
    m_listMenuTrustList->m_signalItemTapped.connect(this, &VappWapPushTrustListPage::onTrustListItemTapped);
    m_listMenuTrustList->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    VFX_OBJ_CLOSE(m_multiOptionToolBar);
    updateToolBar();
    setBottomBar(m_tool_bar);
}

void VappWapPushTrustListPage::wapPushTrustListMultiUnSelectAll()
{
    m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_UNSELECT_ALL);
    m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_DELETE);
    m_multiOptionToolBar->removeItem(TRUSTLIST_MULTI_OPTION_CANCEL);

    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_SELECT_ALL, (VfxResId)STR_GLOBAL_MARK_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_multiOptionToolBar->addItem(TRUSTLIST_MULTI_OPTION_CANCEL,  (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_multiOptionToolBar->setDisableItem(TRUSTLIST_MULTI_OPTION_DELETE, VFX_TRUE);

    switch (m_trustList)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SETTING_WHITE_LIST:
        {
            memset(m_listMenuWLContentProvider->m_selectedListInfo, 0, m_listMenuWLContentProvider->getCount());
            m_listMenuTrustList->updateAllItems();
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        case SRV_WAP_PUSH_SETTING_BLACK_LIST:
        {
            memset(m_listMenuBLContentProvider->m_selectedListInfo, 0, m_listMenuBLContentProvider->getCount());
            m_listMenuTrustList->updateAllItems();
        }
        break;
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

        default:
        break;
    }
}

void VappWapPushTrustListPage::onDeinit()
{
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_tool_bar);
    if(m_multiOptionToolBar)
    {
        VFX_OBJ_CLOSE(m_multiOptionToolBar);
    }    
    if(m_listMenuWLContentProvider)
    {
        VFX_OBJ_CLOSE(m_listMenuWLContentProvider);
    }    
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    if(m_listMenuBLContentProvider)
    {
        VFX_OBJ_CLOSE(m_listMenuBLContentProvider);
    }    
#endif
    if(m_listMenuTrustList)
    {
        VFX_OBJ_CLOSE(m_listMenuTrustList);
    }    
    if(m_listMenuWL)
    {
        VFX_OBJ_CLOSE(m_listMenuWL);
    }    
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_trustlistSettingScrActiveCallback.emit(VFX_FALSE);

    VfxPage::onDeinit();
}
#endif

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
VfxBool VappWLContentProvider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    VfxWChar *bufPtr = text.lockBuf(100);
    srv_wap_push_get_trustlist_item(index,bufPtr);
    text.unlockBuf();	
    return VFX_TRUE;
}


VfxBool VappWLContentProvider::getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
{

    if (fieldType == VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
    }
    else
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
    }

    return VFX_TRUE;
}
#endif

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
VfxBool VappBLContentProvider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    VfxWChar *bufPtr = text.lockBuf(100);
    srv_wap_push_get_trustlist_item(index,bufPtr);
    text.unlockBuf();	

    return VFX_TRUE;
}

VfxBool VappBLContentProvider::getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
{
    if (fieldType == VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
    }
    else
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
    }
    return VFX_TRUE;
}

#endif

/*************************************************************************************************

									VappWapPushTrustListEditPage

**************************************************************************************************/


//VFX_IMPLEMENT_CLASS("VappWapPushTrustListEditPage", VappWapPushTrustListEditPage, VfxPage);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
void VappWapPushTrustListEditPage::onInit()
{
    VfxPage::onInit(); // call base class

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle((VfxResId)m_titleStrID);
    setTopBar(m_titleBar); 

    VFX_OBJ_CREATE(m_tool_bar,VcpToolBar,this);
    m_tool_bar->m_signalButtonTap.connect(this, &VappWapPushTrustListEditPage::onWapPushTrustListEditTBClick);
    setBottomBar(m_tool_bar);
    m_tool_bar->addItem(TRUSTLIST_EDIT_SAVE, (VfxResId)STR_GLOBAL_SAVE,VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_tool_bar->addItem(TRUSTLIST_EDIT_CANCEL, (VfxResId)STR_GLOBAL_CANCEL,VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    VfxRect page_rect = getRect();
    m_form->setRect(0, 0, page_rect.size.width, page_rect.size.height );
    m_form->setAlignParent(
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE);

    switch (m_editType)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER:
        {
            VFX_OBJ_CREATE(m_senderAddress, VcpFormItemTextInput, m_form);
            m_senderAddress->setText(VFX_WSTR_STATIC(m_senderAddressData));
            m_senderAddress->setLabelText((VfxResId)STR_ID_VAPP_PUSH_SENDER_ADDRESS);
            (m_senderAddress->getTextBox())->setIME(IMM_INPUT_TYPE_PHONE_NUMBER);
            (m_senderAddress->getTextBox())->setId(TRUSTLIST_EDIT_SENDER_ADDRESS_EDITOR_ID);
            (m_senderAddress->getTextBox())->setMaxLength(MAX_PUSH_PHN_NUM_LEN-3);
            (m_senderAddress->getTextBox())->m_signalActivated.connect(this, &VappWapPushTrustListEditPage::onTextActivated);

            VFX_OBJ_CREATE(m_SMSCAddress, VcpFormItemTextInput, m_form);
            m_SMSCAddress->setText(VFX_WSTR_STATIC(m_SMSCAddressData));
            m_SMSCAddress->setLabelText((VfxResId)STR_ID_VAPP_PUSH_SMSC_ADDR);
            (m_SMSCAddress->getTextBox())->setIME(IMM_INPUT_TYPE_PHONE_NUMBER);
            (m_SMSCAddress->getTextBox())->setId(TRUSTLIST_EDIT_SMSC_ADDRESS_EDITOR_ID);
            (m_SMSCAddress->getTextBox())->setMaxLength(MAX_PUSH_PHN_NUM_LEN-3);
            (m_SMSCAddress->getTextBox())->m_signalActivated.connect(this, &VappWapPushTrustListEditPage::onTextActivated);

            m_form->addItem(m_senderAddress, TRUSTLIST_EDIT_SENDER_ADDRESS);
            m_form->addItem(m_SMSCAddress, TRUSTLIST_EDIT_SMSC_ADDRESS);

            VcpFunctionBar *functionBar;
            VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
            functionBar->addItem((VfxResId)(STR_ID_VAPP_PUSH_PREV), (VfxId)TRUSTLIST_EDIT_FUNCBAR_PREV_ID);
            functionBar->addItem((VfxResId)(STR_ID_VAPP_PUSH_NEXT), (VfxId)TRUSTLIST_EDIT_FUNCBAR_NEXT_ID);
            functionBar->addItem((VfxResId)(STR_GLOBAL_SAVE), (VfxId)TRUSTLIST_EDIT_FUNCBAR_SAVE_ID);
            functionBar->setItemSpecial(TRUSTLIST_EDIT_FUNCBAR_SAVE_ID);
            functionBar->m_signalButtonTap.connect(this, &VappWapPushTrustListEditPage::onFunctionBarClicked);

            functionBar->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

            (m_senderAddress->getTextBox())->setFunctionBar((VfxFrame*)functionBar, VFX_TRUE);
            (m_SMSCAddress->getTextBox())->setFunctionBar((VfxFrame*)functionBar, VFX_TRUE);
            (m_senderAddress->getTextBox())->activate();
        }
        break;
        
        case SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS:
        {
            VFX_OBJ_CREATE(m_IPAddress, VcpFormItemTextInput, m_form);

            if(m_IPAddressData==NULL)
            {
                m_IPAddress->setText(VFX_WSTR("0.0.0.0"));
                (m_IPAddress->getTextBox())->setCursorIndex(0);
            }
            else
            {
                m_IPAddress->setText(VFX_WSTR_STATIC(m_IPAddressData));
            }            
            m_IPAddress->setLabelText((VfxResId)(STR_ID_VAPP_PUSH_INBOX_TRUST_LIST_IP_ADDRESS));

            (m_IPAddress->getTextBox())->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC,IME_SKIP_DECIMAL_CHECK);
            (m_IPAddress->getTextBox())->setMaxLength(MAX_PUSH_IP_ADDR_NUM_LEN - 1);
            m_form->addItem(m_IPAddress, TRUSTLIST_EDIT_IP_ADDRESS);

            VcpFunctionBar *functionBar;
            VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
            functionBar->addItem((VfxResId)(STR_GLOBAL_SAVE), (VfxId)TRUSTLIST_EDIT_FUNCBAR_SAVE_ID);
            functionBar->setItemSpecial(TRUSTLIST_EDIT_FUNCBAR_SAVE_ID);
            functionBar->m_signalButtonTap.connect(this, &VappWapPushTrustListEditPage::onFunctionBarClicked);

            functionBar->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);


            (m_IPAddress->getTextBox())->setFunctionBar((VfxFrame*)functionBar, VFX_TRUE);
            (m_IPAddress->getTextBox())->activate();
        }
        break;
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    
        default:
        break;
    }        
}

void VappWapPushTrustListEditPage::onWapPushTrustListEditTBClick(VfxObject* sender, VfxId id)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    VfxU32 errorID = SRV_WAP_PUSH_TL_NO_ERROR;
    switch(id)
    {
        case TRUSTLIST_EDIT_SAVE:
        {
            switch (m_editType)
            {				
                case SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER:
                {
                    vfx_sys_wcscpy((VfxWChar *)g_push_set_p->sender_address,(m_senderAddress->getText()).getBuf());
                    vfx_sys_wcscpy((VfxWChar *)g_push_set_p->smsc_address,(m_SMSCAddress->getText()).getBuf());
                    errorID = srv_wap_push_modify_add_sender_smsc_address();
                }
                break;
                
                case SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS:
                {
                    VfxU8 ipv4_array[4] = {0,};
                    VfxChar ucs2_msg[MAX_PUSH_IP_ADDR_NUM_LEN + 2];
                    mmi_ucs2_to_asc((VfxChar*) ucs2_msg, (VfxChar*) (m_IPAddress->getText()).getBuf());
                    if(!strcmp("0.0.0.0", ucs2_msg))
                    {                             
                        errorID=SRV_WAP_PUSH_TL_NO_ERROR;
                        break;
                    }
                    errorID = SRV_WAP_PUSH_TL_INVALID_IP;
                    //applib_addr_string_2_ipv4 ((VfxChar *)ucs2_msg, (VfxU8 *)ipv4_array, 4);
                    if(VfxAppWapPushInterface::addrString2Ipv4 ((VfxChar *)ucs2_msg, (VfxU8 *)ipv4_array, 4))
                    {
                        VfxAppWapPushInterface::vappWapPushReturnThreeDigitString((VfxU8*) g_push_set_p->IP1, (VfxU8) ipv4_array[0]);
                        VfxAppWapPushInterface::vappWapPushReturnThreeDigitString((VfxU8*) g_push_set_p->IP2, (VfxU8) ipv4_array[1]);
                        VfxAppWapPushInterface::vappWapPushReturnThreeDigitString((VfxU8*) g_push_set_p->IP3, (VfxU8) ipv4_array[2]);
                        VfxAppWapPushInterface::vappWapPushReturnThreeDigitString((VfxU8*) g_push_set_p->IP4, (VfxU8) ipv4_array[3]);
                        errorID = srv_wap_push_add_modify_ip_address();
                    }
                }
                break;

                default:
                break;
            }
        }            
        break;
        
        case TRUSTLIST_EDIT_CANCEL:
        break;
        
        default:
        break;
    }
    if ((errorID !=SRV_WAP_PUSH_TL_NO_ERROR))
    {
        VfxAppWapPushInterface::displayPopup(VfxAppWapPushInterface::vappWapPushGetErrorStrID (errorID), SRV_WAP_PUSH_EVENT_PROPLEM);
    }
    else
    {
        (getMainScr())->popPage();
    }
#endif
}

void VappWapPushTrustListEditPage::onDeinit()
{
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_tool_bar);
    if(m_senderAddress)
    {
        VFX_OBJ_CLOSE(m_senderAddress);
    }    
    if(m_SMSCAddress)
    {
        VFX_OBJ_CLOSE(m_SMSCAddress);
    }    
    if(m_IPAddress)
    {
        VFX_OBJ_CLOSE(m_IPAddress);
    }    
    if(m_form)
    {
        VFX_OBJ_CLOSE(m_form);
        m_form = NULL;
    }

    VfxPage::onDeinit();
}

/**********************************************************************************************************

						*********** FUNCTION BAR IMPLEMENTATION ***********

***********************************************************************************************************/

void VappWapPushTrustListEditPage::onTextActivated(VcpTextEditor *sender, VfxBool  activated)
{
    VfxId currId = sender->getId();
    VcpFunctionBar *functionBar = (VcpFunctionBar *)sender->getFunctionBar();

    if (activated)
    {
        if (currId == TRUSTLIST_EDIT_SENDER_ADDRESS_EDITOR_ID)
        {
            functionBar->setDisableItem(TRUSTLIST_EDIT_FUNCBAR_PREV_ID, VFX_TRUE);
            functionBar->setDisableItem(TRUSTLIST_EDIT_FUNCBAR_NEXT_ID, VFX_FALSE);
        } 
        else if (currId == TRUSTLIST_EDIT_SMSC_ADDRESS_EDITOR_ID)
        {
            functionBar->setDisableItem(TRUSTLIST_EDIT_FUNCBAR_PREV_ID, VFX_FALSE);
            functionBar->setDisableItem(TRUSTLIST_EDIT_FUNCBAR_NEXT_ID, VFX_TRUE);
        }
        else
        {
            functionBar->setDisableItem(TRUSTLIST_EDIT_FUNCBAR_PREV_ID, VFX_TRUE);
            functionBar->setDisableItem(TRUSTLIST_EDIT_FUNCBAR_NEXT_ID, VFX_TRUE);
        }
    }
}


void VappWapPushTrustListEditPage::onSetTextEditorState(VfxId id,VfxBool activated)
{
    VcpTextEditor *textEdit;
    VcpFormItemTextInput *textInput = NULL;
    textInput = (VcpFormItemTextInput *)m_form->getItem(id);
    if (textInput)
    {
        textEdit = textInput->getTextBox();
        if (activated)
        {
            textEdit->activate();
        }
        else
        {
            textEdit->deactivate();
        }
    }
}

void VappWapPushTrustListEditPage::onFunctionBarClicked(VfxObject *sender, VfxId id)
{
    switch (id)
    {
        case TRUSTLIST_EDIT_FUNCBAR_PREV_ID:
            onSetTextEditorState(TRUSTLIST_EDIT_SENDER_ADDRESS, VFX_TRUE);
        break;
        
        case TRUSTLIST_EDIT_FUNCBAR_NEXT_ID:
            onSetTextEditorState(TRUSTLIST_EDIT_SMSC_ADDRESS, VFX_TRUE);
        break;
        
        case TRUSTLIST_EDIT_FUNCBAR_SAVE_ID:
            onWapPushTrustListEditTBClick(NULL, TRUSTLIST_EDIT_SAVE);
        break;
        
        default:
        break;
    }
}

#endif

/**********************************************************************************************************

						*********START OF OTA TRUSTLIST PAGE*************


***********************************************************************************************************/
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__

void VappWapPushOTAWhiteListPage::onInit()
{
    VfxPage::onInit(); 

    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_trustlistSettingScrActiveCallback.emit(VFX_TRUE);
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    setTopBar(m_titleBar); 

    VFX_OBJ_CREATE(m_listMenuTrustList, VcpListMenu, this);

    VFX_OBJ_CREATE(m_listMenuWLContentProvider, VappWLContentProvider, this); 
    m_listMenuTrustList->setContentProvider(m_listMenuWLContentProvider);
    m_titleBar->setTitle((VfxResId)STR_ID_VAPP_PUSH_WHITE_LIST);

    m_listMenuTrustList->m_signalItemTapped.connect(this, &VappWapPushOTAWhiteListPage::onTrustListItemTapped);
    //m_listMenuTrustList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_listMenuTrustList->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION);
    m_listMenuTrustList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    VfxRect page_rect = getRect();
    m_listMenuTrustList->setRect(0, 0, page_rect.size.width, page_rect.size.height );

    m_listMenuTrustList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    setFocused(VFX_TRUE);

}

void VappWapPushOTAWhiteListPage::onTrustListItemTapped(VcpListMenu *listMenu, VfxU32  index)
{
    g_push_set_p->selected_wl_entry = index;
    srv_wap_push_replace_selected_wl_addr();
}

void VappWapPushOTAWhiteListPage::onDeinit()
{
    VFX_OBJ_CLOSE(m_titleBar);
    if(m_listMenuTrustList)
    {
        VFX_OBJ_CLOSE(m_listMenuTrustList);
    }		
    if(m_listMenuWLContentProvider)
    {
        VFX_OBJ_CLOSE(m_listMenuWLContentProvider);
    }		

    memset(g_push_set_p->sender_address, '\0', sizeof(g_push_set_p->sender_address));
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_trustlistSettingScrActiveCallback.emit(VFX_FALSE);
    VfxPage::onDeinit();
}
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__*/
