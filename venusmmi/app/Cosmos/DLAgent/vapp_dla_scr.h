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
 *  vapp_dla_scr.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifndef _VAPP_DLAGENT_SCR_H_
#define _VAPP_DLAGENT_SCR_H_

#include "MMI_include.h"

#ifdef __MMI_DOWNLOAD_AGENT__
#include "vapp_dla_main.h"
#include "vcp_tabctrl_page.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "DLAgentSrvIProt.h"
#ifdef __cplusplus
}
#endif



#define VAPP_DA_AUTH_LEN_USERNAME 40
#define VAPP_DA_AUTH_LEN_PASSWORD 40

class VappDLAgentJobDetailPage : public VfxPage
{
public:
    void                                     *m_arg;
    VfxS32                                   m_argId;
    VcpIndicatorPopup                        *m_progressIndicator;

    VappDLAgentJobDetailPage (void *arg):
		m_arg(arg), m_argId(-1), m_progressIndicator(NULL)
    {
    }

    void onCancelClick(VfxObject* sender, VfxFloat curr_progress);
    void setProgress(VfxFloat value);
    void updateStatus (void *arg);
	virtual void onInit(void);
};



class VappDLAgentUserAuthPage : public VfxPage
{
public:
typedef enum
	{
		DLA_USER_AUTH_USERNAME = 1,
		DLA_USER_AUTH_PASSWORD,
        DLA_USER_AUTH_FUNCBAR,
        DLA_FUNCBAR_PREV,
        DLA_FUNCBAR_NEXT,
        DLA_USER_AUTH_END
	}VAPP_DLA_AUTH_BUTTON;

typedef enum
	{
		DLA_USERAUTH_SUBMIT = 1,
		DLA_USERAUTH_CANCEL,

		DLA_USERAUTH_END,
	}VAPP_DLA_AUTH_TOOL_BUTTON;

    VfxBool                                  m_isCalledBack; 
    VcpForm                                  *m_form;
    VcpFormItemTextInput                     *m_username;
    VcpFormItemTextInput                     *m_password;
    VcpTextEditor							 *m_nameEditor;
    VcpTextEditor               			 *m_pwEditor;
    VcpToolBar                               *m_toolbar;
    VcpFunctionBar                           *m_submitFuncBar;
    void                                     *m_arg;

    VappDLAgentUserAuthPage (void *arg, VfxU16 size):
		m_isCalledBack(VFX_FALSE), m_form(NULL), m_username(NULL), 
		m_password(NULL), m_nameEditor(NULL), m_pwEditor(NULL), 
		m_toolbar(NULL), m_submitFuncBar(NULL), m_arg(arg)
    {
    }

    void* getCallbackArgument(void){return m_arg;}
    void onUserAuthToolbarClick(VfxObject* sender, VfxId id);
	void onDLTextEditorActivated(VcpTextEditor *sender, VfxBool isActive);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onInit(void);
    virtual void onDeinit(void);
    virtual void onBack(void);
};





class VcpDLAgentNewDownloadFormItemViewerCell : public VcpFormItemBase 
{
public:
    VcpTextView *m_mainText;
    VfxFrame    *m_separator;
	VfxWChar    *m_bodyText;

	VcpDLAgentNewDownloadFormItemViewerCell():
		m_mainText(NULL), m_separator(NULL), m_bodyText(NULL)
	{
	}
	void setMainText(const VfxWString &text);
    virtual void onInit();
    virtual void onDeinit();  
};

class VappDLAgentNewDownloadPage : public VfxPageHandler
{
public:
typedef enum
	{
		DLA_NEW_DL_FILENAME = 1,
		DLA_NEW_DL_STORAGE,
        DLA_NEW_DL_STORAGE_BUTTON,
        DLA_NEW_DL_DETAIL_TEXT,
        DLA_NEW_DL_TB,
        DLA_NEW_DL_DOWNLOAD_FUNC_BAR,
		DLA_NEW_DL_TB_DOWNLOAD,
		DLA_NEW_DL_TB_CANCEL,

		DLA_NEW_DL_END,
	}VAPP_NEW_DLA_PAGE_ELEMENT;

typedef enum
	{
		DLA_DRIVE_PHONE = 1,
		DLA_DRIVE_MEMORY_CARD,

		DLA_DRIVE_END,
	}VAPP_DLA_MEMORY_CARD_BUTTON;

    typedef void (*downloadLSK) (void *arg, VfxU16 *filepath);
    typedef void (*downloadRSK) (void *arg);
    
    static VfxU16                            m_user_prefered_drive;
    VcpForm                                  *m_form;
    VcpSelectPopup                           *m_selectDrive;
    VfxU32                                   m_downloadSize;
    VcpConfirmPopup                          *m_confirmPopup;
    VcpFunctionBar                           *m_downloadFuncBar;
    VcpToolBar                               *m_toolbar;
    VcpFormItemTextInput                     *filename_edit;
    VcpFormItemBigButton                     *m_selectedDrive;
    VfxWString                               m_ext;
    void                                     *m_arg; /* New job pointer */
    U32                                      m_argSize;
    VfxBool                                  isCalledBack;
    downloadLSK                              m_downloadStart;
    downloadRSK                              m_downloadCancel;
    VcpDLAgentNewDownloadFormItemViewerCell  *m_information_text;

    VappDLAgentNewDownloadPage (void *arg, VfxU16 size):
		m_form(NULL), m_selectDrive(NULL), m_downloadSize(0), m_confirmPopup(NULL), 
		m_downloadFuncBar(NULL), m_toolbar(NULL), filename_edit(NULL), m_selectedDrive(NULL), 
		m_ext(VFX_WSTR("")), m_arg(arg), m_argSize(size), isCalledBack(VFX_FALSE), 
		m_downloadStart(NULL), m_downloadCancel(NULL), m_information_text(NULL)
    {
    }

    void set_default_location (VfxU32 drive);
    void set_default_filename (VfxU16 *str) {filename_edit->setText (VFX_WSTR_MEM (str));}
    void set_display_text (VfxU16 *text);
    void setDownloadSize(VfxU32 size);
    void setDownloadConfirmCallback (downloadLSK downloadStart) {m_downloadStart = downloadStart;}
    void setDownloadCancelCallback (downloadRSK downloadCancel) {m_downloadCancel = downloadCancel;}
    void startNewDownloadMemCheck(U16 *filepath);
#ifndef __COSMOS_NO_USER_DRIVE__
    void onStorageButtonClick(VfxBasePopup* popup, VfxBasePopupStateEnum state);
#endif
	void wcharTrim(const VfxWChar *str, VfxWChar *strout);
    void onNewDownloadToolbarClick(VfxObject* sender, VfxId id);
    void onRenameConfirmation(VfxObject* obj, VfxId id);
    void onOverwriteClick (void);
	void createDescription();
#ifdef __MMI_OMA_DD_DOWNLOAD__
	void omaConfirmFillMsgString(void *arg, VcpTextView *mainText);
#endif
	void pushConfirmFillMsgString (void *arg, VcpTextView *mainText);
	void httpConfirmFillMsgString(void *arg, VcpTextView *mainText);
	void mreConfirmFillMsgString(void *arg, VcpTextView *mainText);
    void FillConfirmPageItemString(VfxU32 strID, VfxWChar* srcStr1, VfxChar* srcStr2, VcpTextView *mainText);
	//void onInit(void);
	virtual void onPageInit(VfxPageEx *page);
    virtual void onPageDeinit(VfxPageEx * page);
    virtual void onPageBack(VfxPageEx * page);
    virtual void onPageRotate(VfxPageEx * page,const VfxScreenRotateParam & param);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	
};

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __COSMOS_NO_USER_DRIVE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OMA_DD_DOWNLOAD__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

class VappDLAgentDownloadListControl;
class VappDLAgentMainPageContentProvider : public VfxObject, public IVcpListMenuContentProvider
{

protected:
	using IVcpListMenuContentProvider::closeItemCustomContentFrame;

public:

    VfxU16                             m_list_type;
    VfxWeakPtr <VappDLAgentDownloadListControl> list[10];

    VappDLAgentMainPageContentProvider (VfxU16 list_type):
	    m_list_type(list_type)
    {
        for (int i = 0; i < 10; i++)
        {
            list[i] = NULL;
        }
    }

    VappDLAgentDownloadListControl* getCustomShellAtIndex (VfxS32 index);
    void fillCustomFieldData (VappDLAgentDownloadListControl *control, void *job, VfxBool isFolded);
	void fillStatusFieldToShell(srv_da_job_state_enum job_state, 	VfxS8 *file_curr_size, 
		VappDLAgentDownloadListControl *shell);
    void updateItemContent (void *arg);
    void UpdateDisplayedList (void);
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        ){return VFX_FALSE;}

	virtual VfxBool getItemImage(
        VfxU32 index,                   
        VcpListMenuFieldEnum fieldType, 
        VfxImageSrc &image              
        ){return VFX_FALSE;}

    virtual VfxU32 getCount() const ;
	virtual VfxBool getItemIsDisabled(
	VfxU32 index       // [IN] the index of item
	) const
    {
        return VFX_FALSE;
    }

	    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
		) const
	{
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    virtual void closeItemCustomContentFrame(
        VcpMenuPos pos,  
        VcpListMenuCellClientBaseFrame *cell 
        )
    {if (cell){VFX_OBJ_CLOSE(cell);}}

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
};


class VappDLAgentDownloadListPage : public VfxPage
{
public:
    typedef enum
    {
	    DLA_LIST_TYPE_DOWNLOADING_LIST = 1,
	    DLA_LIST_TYPE_COMPLETED_LIST,

	    DLA_LIST_TYPE_END,
    }VAPP_DLA_LIST;

    typedef enum
    {
	    DLA_MAIN_PAGE_TB_PAUSE_ALL = 1,
	    DLA_MAIN_PAGE_TB_RESUME_ALL,
        DLA_MAIN_PAGE_TB_REMOVE_ALL,

	    DLA_MAIN_PAGE_TB_ALL
    }VAPP_DLA_CONTROL_BUTTON;

	VfxU16                                   m_curr_list_type;
    VcpListMenu                              *m_download_list;
    VcpListMenu                              *m_completed_list;
    VfxTextFrame                             *m_downloading_text; /* Used to display empty list */
    VfxTextFrame                             *m_completed_text; /* Used to display empty list */
    VappDLAgentMainPageContentProvider       *m_downloading_list_cp;
    VappDLAgentMainPageContentProvider       *m_completed_list_cp;
    VfxS32                                   m_arg_id;
    VcpToolBar                               *m_completedToolbar;
    VcpToolBar                               *m_downloadToolbar;

	VappDLAgentDownloadListPage(void){}
    VappDLAgentDownloadListPage (VfxU16 list_type):
			m_curr_list_type(list_type), 
			m_download_list(NULL), 
			m_completed_list(NULL),
			m_downloading_text(NULL), 
			m_completed_text(NULL), 
			m_downloading_list_cp(NULL), 
			m_completed_list_cp(NULL), 
			m_arg_id(-1), 
			m_completedToolbar(NULL), 
		m_downloadToolbar(NULL)
    {
    }
	
    virtual void onInit();
    void onToolBarClick(VfxObject* sender, VfxId id);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    void updateToolBar (void);
	void createAndSetListMenu (VcpListMenu *&list_menu, U16 height, U16 emhasisHeight);
	void createAndSetContentProvider(VappDLAgentMainPageContentProvider *&contentProvider, VfxU8 dla_list_type);
    void createAndSetToolBar(VcpToolBar *&toolbar);

	 VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
		)
	{
	    return VFX_FALSE;
	}	
	
	VfxFrame *getContentFrame(
        VcpMenuPos pos        // [IN] index of the item
		)
	{
	    return NULL;
	}
};




class VappDLAgentMainPage : public VcpTabCtrlPage
{
public:
    typedef enum
    {
        VAPP_DLA_TAB_DOWNLOAD = 1,
        VAPP_DLA_TAB_COMPLETED,
        VAPP_DLA_TAB_TOTAL
    }dla_main_tab_enum;
	dla_main_tab_enum              m_selectedTab;
    VappDLAgentDownloadListPage    *m_downloadingPage;
    VappDLAgentDownloadListPage    *m_CompletedPage;
	VfxBool 					   isRotated;

    VappDLAgentMainPage(void){}
    VappDLAgentMainPage(VfxU16 selectedTab):
		m_selectedTab((dla_main_tab_enum) selectedTab), 
		m_downloadingPage(NULL), 
		m_CompletedPage(NULL), 
		isRotated(VFX_FALSE)		
    {
    }

   	virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onRotate(const VfxScreenRotateParam &param);
    virtual VfxPage *onCreateTabPage(VfxId tabId);
};

#endif /* __MMI_DOWNLOAD_AGENT__ */
#endif /* _VAPP_DLAGENT_SCR_H_ */
