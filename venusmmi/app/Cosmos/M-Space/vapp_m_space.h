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
 * Vapp_app_manager.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __VAPP_M_SPACE_H__
#define __VAPP_M_SPACE_H__
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MRE_MSPACE__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_form.h"
#include "vcp_tabctrl_page.h"
#include "vcp_menu_popup.h"
#include "vcp_global_popup.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_app_manager.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "vrt_datatype.h"
#include "usbsrvgprot.h"
#include "MASSrvGprot.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MSPACE_MALLOC(ptr, size) \
        do\
        {\
            VFX_ALLOC_MEM(ptr,size,VappMSpaceApp::getMainScr());\
        }while(0)    
#define MSPACE_FREE(ptr) \
        do\
        {\
            VFX_FREE_MEM(ptr);\
        }while(0)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Enum
 *****************************************************************************/


/***************************************************************************** 
 * Classes 
 *****************************************************************************/
class VappMSpaceApp;
class VappMSpaceMainSrc : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappMSpaceMainSrc);
public:
    static void updatePage(VfxS32 index);
// Override
protected:
    virtual void on1stReady();

    friend class VappMSpaceApp;
};

class VappMSpaceApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappMSpaceApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize); 
    
    static VappMSpaceMainSrc* getMainScr()
    {
        if (m_pMainSrc.get())
        {
            return m_pMainSrc.get();
        }
        return NULL;
    };

    static void initApp();
    static VfxWeakPtr<VappMSpaceMainSrc>   m_pMainSrc;
    static mmi_id           m_mmiId;
protected:
    VfxBool                 m_bInited;        
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
};


class VappMSpaceItem : public VcpListMenuCellClientBaseFrame
{
public:
    VappMSpaceItem(VfxU32 index);    
    virtual void onCreateElements();
    virtual void onCloseElements();
    virtual void onLayoutElements();
    virtual void onUpdateElements();
    VfxU32 m_index;
    VfxU8* m_icon;
private:
    VfxTextFrame* m_pAppName;
    VfxTextFrame* m_pInstallTime;  
    VfxImageFrame* m_pStatusIcon;
};

extern "C" S32 vapp_m_space_list_num(void);

class VappMSpaceListMenuContentProvider : public VfxObject, public IVcpListMenuContentProvider
{
// Override
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
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
  
    virtual void closeItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType, 
        VfxImageSrc Image               
        ) {}

    virtual VfxU32 getCount() const
    {
        return vapp_m_space_list_num();  
    }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const { return VCP_LIST_MENU_ITEM_STATE_NONE;}

    
    virtual VfxBool swapItem(
        VfxU32 index1, 
        VfxU32 index2 
        ) 
    {
        
        return VFX_TRUE;
    }

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,
        VfxFrame *parentFrame
        )
    {
        VappMSpaceItem* pItem = NULL;

        VFX_OBJ_CREATE_EX(pItem, VappMSpaceItem, parentFrame,(index));
        return (VcpListMenuCellClientBaseFrame *)pItem;
    }

    virtual void closeItemCustomContentFrame(
        VfxU32 index,  
        VcpListMenuCellClientBaseFrame *cell 
        )
    {
        if (cell)
        {
            VappMSpaceItem* pItem = (VappMSpaceItem*)cell;
            VFX_OBJ_CLOSE(cell);
        }
    }

};

/*
class VappMSpaceListPage : public VfxPage
{
public:
    virtual void updatePage();
    VcpListMenu* m_pListMenu;
    void setListBounds(const VfxRect& rect);
    void eventHandler(VfxObject* pObj, VfxId id);
protected:
    virtual void onInit();    
    void onCancelUpdate(VfxObject* pObj, VfxId id);
    static void updateCallback(S32 hdl, void * para);

    VfxBool             m_bUpdated;
    U32                 m_handle;
    VcpIndicatorPopup*  m_pWaitingPopup;
    VfxTextFrame*       m_pText;
};


*/
class VappMSpacePage : public VfxPage
{
public:
    virtual void updatePage(VfxS32 index){};
};

class VappMSpaceMainPage : public VappMSpacePage
{
public:
    static VfxId m_pageId;

    VappMSpaceMainPage();
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    void    onTap(VcpListMenu* pMenu, VfxU32 index);
    void    onLongTap(VcpListMenu* pMenu, VfxU32 index);
    void    onTime(VfxTimer* pTime);
    void onCancelUpdate(VfxObject* pObj, VfxId id);
    static void updateCallback(S32 hdl, void * para);   
    virtual void updatePage(VfxS32 index);
    void eventHandler(VfxObject* pObj, VfxId id);
    void setBounds(const VfxRect &value);
    
    VfxBool             m_bUpdated;
    S32                 m_handle;
    VcpIndicatorPopup*  m_pWaitingPopup;
    VfxTextFrame*       m_pText;
private:
//    VappMSpaceListPage *m_pAmListpage;
    VcpListMenu* m_pListMenu;
    VfxBool         m_bFirstIn;
};

class VappMSpaceAppInfoPage : public VappMSpacePage
{
public:
    VappMSpaceAppInfoPage(VfxU32 index);
    virtual ~VappMSpaceAppInfoPage();
    void    showPage();
    void    updatePage(VfxS32 index);
    static VfxId m_pageId;
    
protected:
    virtual void onInit();
    void    eventHandler(VfxObject* pObj, VfxId id);
    
    void    updateInfo();
    void    onUpdateInfo();
    void    onUninstall(VfxS32 bRet);
    virtual mmi_ret onProc(mmi_event_struct *evt);

protected:
    VcpToolBar* m_pToolBar;
    VcpForm*    m_pForm;  
    VfxU32      m_index;
    VfxU8*      m_icon;
};


class VappMSpaceOperateHelper : public VfxObject
{
public:
    VappMSpaceOperateHelper():m_pWaitingPopup(NULL){};
    void install(VfxU32 index);
    void update(VfxU32 index);
    VfxU32 m_index;
    VcpIndicatorPopup*  m_pWaitingPopup;
protected:
    void onInstall(VfxObject* pObj, VfxId id);
    void onUpdate(VfxObject* pObj, VfxId id);
    static void installedCallback(S32 hdl, void * para);
    static void updateCallback(S32 hdl, void * para);
};


#endif //__COSMOS_MMI_PACKAGE__
#endif //__VAPP_M_SPACE_H__
