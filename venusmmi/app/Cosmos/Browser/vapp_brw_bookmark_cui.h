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
 * vapp_brw_bookmark_cui.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_BRW_BOOKMARK_CUI_H_
#define _VAPP_BRW_BOOKMARK_CUI_H_

#include "MMI_include.h"
#include "MMIDataType.h"
#ifdef __MMI_BROWSER_2__

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"
#include "vapp_brw_main.h"

typedef struct
{
    VfxBool isBookmarkAddMode;
}vapp_brw_bookmark_launch_args;


class VappBrowserSelectBookmark : public VfxPage
{
public:
    VcpTitleBar *m_titleBar;
    VcpListMenu *m_bookmarksList;
    VappBrowserBookmarksDataProvider *m_bookmarksContentProvider;

    VappBrowserSelectBookmark(void):
        m_titleBar(NULL),
        m_bookmarksList(NULL),
        m_bookmarksContentProvider(NULL)
    {
    }

    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    void onItemTap(VcpListMenu *sender, VfxU32 index);
    void moveToParentFolder(void);
    //VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
};



class VappBrwBookmarkScr : public VfxMainScr
{
    //VFX_DECLARE_CLASS(VappBrwBookmarkScr);

// constuctor / destructor
public:
    typedef enum
    {
        CUI_MODE_ADD_BOOKMARK = 0,
        CUI_MODE_SELECT_BOOKMARK,
        CUI_MODE_END
    } cui_mode_enum;
    
    VappBrowserSelectBookmark *m_selectBookmarkPage;
    VappBrowserAddBookmark *m_addBookmarkPage;
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    VappBrowserSelectFolderPage *m_selectFolderPage;
    #endif
	VfxWString m_addBookmarkUrl;
    // default constructor just use for VFX_IMPLEMENT_CLASS
    VappBrwBookmarkScr(VfxWChar *addBookmarkUrl):
        m_selectBookmarkPage(NULL),
        m_addBookmarkPage(NULL),
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        m_selectFolderPage(NULL),
        #endif
        m_addBookmarkUrl(VFX_WSTR_MEM(addBookmarkUrl))
    {
    }

    VappBrwBookmarkScr(mmi_id cuiId)
    {
    }
    virtual ~VappBrwBookmarkScr() {}

// override
public:
    void setMode(cui_mode_enum mode)
    {
        m_bookmarkMode = mode;
    }
    cui_mode_enum getMode(void)
    {
        return m_bookmarkMode;
    }

    cui_mode_enum m_bookmarkMode;
    virtual void onDeinit();
    virtual void on1stReady(); // display list

// method
public:
    mmi_id getCuiId() 
    {
        return m_cuiId;
    }

private:
    mmi_id m_cuiId; // use this to record group id

};



class VappBrwBookmarkCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappBrwBookmarkCui);

public:  
// Constructor / Destructor
    VappBrwBookmarkCui():
      m_addBookmarkUrl(NULL)
    {
    }
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
    virtual void onDeinit();
// Method
public:
    VfxWChar *m_addBookmarkUrl;
    VappBrwBookmarkScr *m_bookmarkScr;
};


#endif /* __MMI_BROWSER_2__ */

#endif /* _VAPP_BRW_BOOKMARK_CUI_H_ */
