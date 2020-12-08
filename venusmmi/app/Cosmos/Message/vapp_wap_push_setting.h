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
 *  vapp_XXX.h
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
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WAP_PUSH_SETTING_H__
#define __VAPP_WAP_PUSH_SETTING_H__

#ifdef WAP_SUPPORT
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#ifdef __cplusplus
extern "C"
{
#endif

#include "WAPPushSrvProts.h"
#include "WAPPushSrvTypes.h"
#include "mmi_rp_vapp_wap_push_def.h"

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
 * Class 
 *****************************************************************************/

class VappWapPushSettingPageContentProvider :  public VfxObject , public IVcpListMenuContentProvider
{
// Override
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VcpRichTextFormat &format        
        ) 
    {
        return VFX_FALSE;
    } 
    
    virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        );
    virtual VfxU32 getCount() const {return SRV_WAP_PUSH_SETTING_TOTAL; }
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const 
    { 
        if (selectedIndex == index)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }    
    virtual VfxBool swapItem(
        VfxU32 index1, 
        VfxU32 index2 
        ) 
    {
        
        return VFX_TRUE;
    }

    VfxU16 getEnablePushString(void);
    VfxU16 getSLSettingString(void);
    VfxU16 getEnableWLString(void);
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    VfxU16 getEnableBLString(void);
#endif

public:

    VfxU32 selectedIndex;
    VcpListMenu *list;
};


/******************************************************************************************************

                            WAP Push Setting Option Page Implementation

*******************************************************************************************************/

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
class VappWLSettingContentProvider : public VfxObject , public IVcpListMenuContentProvider
{
// Override
public:

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VcpRichTextFormat &format        
        ) 
    {
        return VFX_FALSE;
    } 
    
    virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        );

    virtual VfxU32 getCount() const {
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    return SRV_WAP_PUSH_WL_SETTING_TOTAL; 
#else
    return 0;
#endif
	}

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const 
    { 
        if (m_selectedIndex == index)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
public:
   VfxU32 m_selectedIndex;
};
#endif


class VappPushSettingContentProvider : public VfxObject , public IVcpListMenuContentProvider
{
// Override
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VcpRichTextFormat &format        
        ) 
    {
        return VFX_FALSE;
    } 
    
    virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        )
    	{
    		return VFX_FALSE;
    	}

    virtual VfxU32 getCount() const {

		return SRV_WAP_PUSH_ENABLE_SETTING_TOTAL;
	}

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const 
    { 
        if (m_selectedIndex == index)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
public:

   VfxU32 m_selectedIndex;  
};

class VappSLSettingContentProvider : public VfxObject , public IVcpListMenuContentProvider
{
// Override
public:

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VcpRichTextFormat &format        
        ) 
    {
        return VFX_FALSE;
    } 
    
    virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        )
    	{
    		return VFX_TRUE;
    	}
    virtual VfxU32 getCount() const {return SRV_WAP_PUSH_SL_SETTING_END; }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const 
    { 
        if (m_selectedIndex == index)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
public:
   VfxU32 m_selectedIndex;
};

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
class VappBLSettingContentProvider : public VfxObject , public IVcpListMenuContentProvider
{
// Override
public:

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VcpRichTextFormat &format        
        ) 
    {
        return VFX_FALSE;
    }     
    virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        );

    virtual VfxU32 getCount() const {
	
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        return SRV_WAP_PUSH_BL_SETTING_TOTAL; 
    #else
        return 0;
    #endif
	}

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const 
    { 
        if (m_selectedIndex == index)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
public:
   VfxU32 m_selectedIndex;
};
#endif


class VappWapPushSettingOptionPage : public VfxPage
{
// Override
public:

    VfxS32 m_index;
    VfxS32 m_pushSettingOption;
    VfxS32 m_selectIndex;
    VcpTitleBar *m_titleBar;
    VcpListMenu *m_menuWLSetting;
#ifdef __MMI_WAP_PUSH_WHITE_LIST__    
    VappWLSettingContentProvider    *m_listMenuWLSettingContentProvider;
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    VappBLSettingContentProvider    *m_listMenuBLSettingContentProvider;
#endif
#endif
    VappSLSettingContentProvider    *m_listMenuSLSettingContentProvider;
    VappPushSettingContentProvider  *m_listMenuPushSettingContentProvider;

    VcpListMenuModeEnum m_mode;

    VappWapPushSettingOptionPage(){

    };
    VappWapPushSettingOptionPage(VfxS32 pushSettingOption, VfxS32 selectIndex) : 
        m_pushSettingOption(pushSettingOption), 
        m_selectIndex(selectIndex)
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        m_listMenuWLSettingContentProvider= NULL;
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        m_listMenuBLSettingContentProvider= NULL;
    #endif
    #endif
        m_listMenuSLSettingContentProvider= NULL;
        m_listMenuPushSettingContentProvider= NULL;
	};

    virtual void onInit();
    void onSettingOptionPageItemTapped(VcpListMenu *listMenu, VfxU32  index); 
    virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
        //support all rotation
    }

};

class VappWapPushSettingPage : public VfxPage
{
// Override
public:

    VcpTitleBar * titleBar;
    VcpListMenu *m_menu;
    VappWapPushSettingPageContentProvider *m_listMenuContentProvider;

    VcpListMenuModeEnum m_mode;

    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    void onSettingPageItemTapped(VcpListMenu *listMenu, VfxU32  index);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
        //support all rotation
    }
};


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
class VappWLContentProvider : public VfxObject , public IVcpListMenuContentProvider
{
// Override
public:

    VappWLContentProvider():m_selectedListInfo(NULL)
    {m_selectedListCount = 0;};

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VcpRichTextFormat &format        
        ) 
    {
        return VFX_FALSE;
    } 

    virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        );
    virtual VfxU32 getCount() const {return srv_wap_push_get_number_of_white_list(); }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const 
    { 
        if (!m_selectedListInfo) /*For OTA Push only*/
        {
            if (index == 0)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }            
            else
            {
                return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
            }            
        }

        if(m_selectedListInfo[index] == 0)
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
    }
    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
    {
        if (!m_selectedListInfo) /*For OTA Push only*/
        {
            return;
        }    

        if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            m_selectedListInfo[index] = 1;
            m_selectedListCount++;
        }
        else if(newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
            m_selectedListInfo[index] = 0;
            m_selectedListCount--;
        }
    }

    virtual void onDeinit()
    {
        if (m_selectedListInfo)
        {
            VFX_FREE_MEM(m_selectedListInfo);
            m_selectedListInfo = NULL;
        }
    }

    VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
    {
        text.loadFromRes(STR_ID_VAPP_PUSH_NO_WHITE_LISTS);
        return VFX_TRUE;
    }

public:

    VfxU8* m_selectedListInfo;
    VfxU8 m_selectedListCount;

};
#endif

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
class VappBLContentProvider : public VfxObject , public IVcpListMenuContentProvider
{
// Override
public:

    VappBLContentProvider():m_selectedListInfo(NULL)
    {
        m_selectedListCount = 0;
    };

    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );

    virtual VfxBool getItemTextFormat(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VcpRichTextFormat &format
        ) 
    {
        return VFX_FALSE;
    } 

    virtual VfxBool getItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image         
        );

    virtual VfxU32 getCount() const {return srv_wap_push_get_number_of_black_list();}

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const
    {
        if (!m_selectedListInfo)
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }    

        if(m_selectedListInfo[index] == 0)
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
    }

    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
    {
        if (!m_selectedListInfo)
        {
            return;
        }        

        if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            m_selectedListInfo[index] = 1;
            m_selectedListCount++;
        }
        else if(newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
            m_selectedListInfo[index] = 0;
            m_selectedListCount--;
        }
    }
    virtual void onDeinit()
    {
        if (m_selectedListInfo)
        {
            VFX_FREE_MEM(m_selectedListInfo);
            m_selectedListInfo = NULL;
        }
    }

    VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
    {
        text.loadFromRes(STR_ID_VAPP_PUSH_NO_BLACK_LISTS);
        return VFX_TRUE;
    }


public:

    VfxU8* m_selectedListInfo;
    VfxU8  m_selectedListCount;
};
#endif

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
class VappWapPushTrustListPage : public VfxPage
{
// Override
public:
    enum
    {
        TRUSTLIST_ADD,
        TRUSTLIST_DELETE,
    };
    enum
    {
        TRUSTLIST_ADD_PHONE_NUM,
        TRUSTLIST_ADD_IP_ADDRESS,
        TRUSTLIST_ADD_CANCEL,
    };

    enum
    {
        TRUSTLIST_MULTI_OPTION_SELECT_ALL,
        TRUSTLIST_MULTI_OPTION_UNSELECT_ALL,
        TRUSTLIST_MULTI_OPTION_DELETE,
        TRUSTLIST_MULTI_OPTION_CANCEL,
    };

    VfxS32 m_trustList;
    VcpToolBar *m_tool_bar;
    VcpToolBar *m_multiOptionToolBar;
    VcpTitleBar * m_titleBar;
    VcpListMenu *m_listMenuTrustList;
    VcpListMenu *m_listMenuWL;

    VappWLContentProvider    *m_listMenuWLContentProvider;

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    VappBLContentProvider    *m_listMenuBLContentProvider;
#endif

    VcpListMenuModeEnum m_mode;

    VappWapPushTrustListPage()
    {};
    VappWapPushTrustListPage(VfxS32 trustList) : 
        m_trustList(trustList),
        m_multiOptionToolBar(NULL),
        m_tool_bar(NULL),
        m_titleBar(NULL),
        m_listMenuTrustList(NULL),
        m_listMenuWL(NULL),		
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        m_listMenuBLContentProvider(NULL),
    #endif
        m_listMenuWLContentProvider(NULL)

    {};
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    void onTrustListItemTapped(VcpListMenu *listMenu, VfxU32  index);
    void onWapPushTrustListTBClick(VfxObject* sender, VfxId id); 
    void onTrustListAddCmdClick(VfxObject* sender, VfxId id); 
    void onWapPushTrustListMultiOptionTBClick(VfxObject* sender, VfxId id); 
    void wapPushTrustListMultiSelectAll();
    void wapPushTrustListMultiUnSelectAll();
    void wapPushTrustListMultiCancel();
    void wapPushTrustListDelete();
    void onWapPushTrustListDelete();
    void updateToolBar();
    virtual void onDeinit();
    void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
        //support all rotation
    }
    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onWapPushTrustListActionDelete(VfxObject * obj, VfxId id);
};
#endif

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
class VappWapPushTrustListEditPage : public VfxPage
{
public:
    enum
    {
        TRUSTLIST_EDIT_SAVE,
        TRUSTLIST_EDIT_CANCEL,
    };
    enum
    {
        TRUSTLIST_EDIT_SENDER_ADDRESS,
        TRUSTLIST_EDIT_SMSC_ADDRESS,
        TRUSTLIST_EDIT_IP_ADDRESS,
        TRUSTLIST_EDIT_SENDER_ADDRESS_EDITOR_ID,
        TRUSTLIST_EDIT_SMSC_ADDRESS_EDITOR_ID,
        TRUSTLIST_EDIT_IP_ADDRESS_EDITOR_ID,
        TRUSTLIST_EDIT_FUNCBAR_PREV_ID,
        TRUSTLIST_EDIT_FUNCBAR_NEXT_ID,
        TRUSTLIST_EDIT_FUNCBAR_SAVE_ID,
    };

    VcpToolBar *m_tool_bar;
    VcpTitleBar * m_titleBar;
    VcpForm *m_form;
    VcpFormItemTextInput *m_senderAddress;
    VcpFormItemTextInput *m_SMSCAddress;
    VcpFormItemTextInput *m_IPAddress;
    VfxS32 m_editType;
    VfxS32 m_titleStrID;
    VfxWChar *m_senderAddressData;
    VfxWChar *m_SMSCAddressData;
    VfxWChar *m_IPAddressData;

    void onWapPushTrustListEditTBClick(VfxObject* sender, VfxId id); 

    VappWapPushTrustListEditPage()
    {};
    VappWapPushTrustListEditPage(VfxS32 editType,VfxS32 titleStrID, VfxWChar *senderAddressData,VfxWChar *SMSCAddressData,VfxWChar *IPAddressData) : 
        m_editType(editType),m_titleStrID(titleStrID),m_senderAddressData(senderAddressData),m_SMSCAddressData(SMSCAddressData),m_IPAddressData(IPAddressData)
    {
        m_senderAddress = NULL;
        m_SMSCAddress = NULL;
        m_IPAddress = NULL;
    };


    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
        //support all rotation
    }
    virtual void onDeinit();
    void onTextActivated(VcpTextEditor *sender, VfxBool  activated);
    void onSetTextEditorState(VfxId id,VfxBool activated);
    void onFunctionBarClicked(VfxObject *sender, VfxId id);
};
#endif

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__

class VappWapPushOTAWhiteListPage : public VfxPage
{
// Override
public:
	
    VcpTitleBar * m_titleBar;
    VcpListMenu *m_listMenuTrustList;

    VappWLContentProvider    *m_listMenuWLContentProvider;

    VappWapPushOTAWhiteListPage()
    {};

    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
        //support all rotation
    }
    void onTrustListItemTapped(VcpListMenu *listMenu, VfxU32  index);
    virtual void onDeinit();	
};
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__*/

#endif

#endif /* __VAPP_WAP_PUSH_SETTING_H__ */

