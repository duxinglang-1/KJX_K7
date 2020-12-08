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
 * vapp_dla_main.h
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
 * Vikas Lal Srivastava (MTK33036)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_DLAGENT_MAIN_H_
#define _VAPP_DLAGENT_MAIN_H_

#include "MMI_include.h"

/* Venus MMI related include files start */
#include "vfx_mc_include.h"
#include "vcp_form.h"
#include "vcp_include.h"

#include "vcp_tabctrl_page.h"

#include "vapp_dla_scr.h"
#include "vapp_dla_config.h"
/* Venus MMI related include files end */
#ifdef __MMI_DOWNLOAD_AGENT__

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
 /*TODO: Header file inclusion section */
#include "DLAgentSrvDef.h"
#include "DLAgentSrvGprot.h"
#include "DLAgentSrvIProt.h"
#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#include "mmi_rp_vapp_dlagent_def.h"
#endif
#include "DLAgentSrvWPS.h"
#include "DLAgentSrvProt.h"
#include "DLAgentSrvOMA.h"

#ifdef __cplusplus
}
#endif /* __CPLUSPLUS__ */

#include "vapp_dla_ncenter.h"


/************************************************************************************************************************************/
/*                                             Starting platform dependent macros                                                   */
/************************************************************************************************************************************/


#ifndef __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__
/*******************************************  Defiining Landscape mode macros  ***************************************************/
#define VAPP_DLA_LIST_ITEM_COMMON_DISTANCE                           5

#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_LENGTH                      (VfxS32)((68 * LCD_WIDTH) / 100)
#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH                       20


#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_LENGTH                        (VfxS32)((30 * LCD_WIDTH) / 100)
#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_WIDTH                         15

#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_LENGTH                          (VfxS32)((30 * LCD_WIDTH) / 100)
#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH                           15

#define VAPP_DLA_LIST_ITEM_TIME_EDIT_LENGTH                          (LCD_WIDTH - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN) 
#define VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH                           15

#define VAPP_DLA_LIST_ITEM_TOP_MARGIN                                2
#define VAPP_DLA_LIST_ITEM_LEFT_MARGIN                               5
#define VAPP_DLA_LIST_ITEM_RIGHT_MARGIN                              5
#define VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN                             1

#define VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH                              40
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH                             (VfxS32)((4687 * LCD_WIDTH) / 10000)
#define VAPP_DLA_LIST_ITEM_DISTANCE_BTW_BUTTONS                      (LCD_WIDTH - (2*VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH) - VAPP_DLA_LIST_ITEM_LEFT_MARGIN - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN)

#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH                        10
#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_LENGTH                       (LCD_WIDTH - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN)



/*******************************************  Defiining Landscape mode macros  ***************************************************/
#define VAPP_DLA_LIST_ITEM_COMMON_DISTANCE_LANDSCAPE                           5

#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_LENGTH_LANDSCAPE                      (VfxS32)((68 * LCD_HEIGHT) / 100)
#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH_LANDSCAPE                       (VfxS32)((417 * LCD_WIDTH)/10000)

#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_LENGTH_LANDSCAPE                        (VfxS32)((30 * LCD_HEIGHT) / 100)
#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_WIDTH_LANDSCAPE                         15

#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_LENGTH_LANDSCAPE                          (VfxS32)((30 * LCD_HEIGHT) / 100)
#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH_LANDSCAPE                           15

#define VAPP_DLA_LIST_ITEM_TIME_EDIT_LENGTH_LANDSCAPE                          (VfxS32)((30 * LCD_HEIGHT) / 100)
#define VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH_LANDSCAPE                           15

#define VAPP_DLA_LIST_ITEM_TOP_MARGIN_LANDSCAPE                                2
#define VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE                               5
#define VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE                              5
#define VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN_LANDSCAPE                             2

#define VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH_LANDSCAPE                              40
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE                             (VfxS32)((4687 * LCD_HEIGHT) / 10000)
#define VAPP_DLA_LIST_ITEM_DISTANCE_BTW_BUTTONS_LANDSCAPE                      (LCD_HEIGHT - (2*VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE) - VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE)

#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH_LANDSCAPE                        10
#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_LENGTH_LANDSCAPE                       (LCD_HEIGHT - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE - VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE)

#endif /* __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__ */

/************************************************************************************************************************************/
/*                                             Component height width calculation                                                   */
/************************************************************************************************************************************/
#define VAPP_DLA_DOWNLOAD_LIST_ITEM_FOLDED_HEIGHT                    VAPP_DLA_LIST_ITEM_TOP_MARGIN + VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN + \
                                                                     VAPP_DLA_LIST_ITEM_COMMON_DISTANCE + VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH +\
                                                                     VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH

#define VAPP_DLA_DOWNLOAD_LIST_ITEM_UNFOLDED_HEIGHT                  VAPP_DLA_DOWNLOAD_LIST_ITEM_FOLDED_HEIGHT + (3*VAPP_DLA_LIST_ITEM_COMMON_DISTANCE) + \
                                                                     VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH + VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH + VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH

#define VAPP_DLA_COMPLETED_LIST_ITEM_FOLDED_HEIGHT                   VAPP_DLA_DOWNLOAD_LIST_ITEM_FOLDED_HEIGHT
#define VAPP_DLA_COMPLETED_LIST_ITEM_UNFOLDED_HEIGHT                 VAPP_DLA_DOWNLOAD_LIST_ITEM_UNFOLDED_HEIGHT - VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH - VAPP_DLA_LIST_ITEM_COMMON_DISTANCE



/************************************************************************************************************************************/
/*                                                Starting  variable and common classes                                             */
/************************************************************************************************************************************/
extern VfxU16  m_DLAgentAppID;
typedef struct 
{
    U32  type;
    void *arg;
    U16  argSize; 
} vapp_da_app_launch_struct;

extern void createAndSetPopup(VcpConfirmPopup *&confirmPopup, VcpPopupTypeEnum popuptype,
	VcpConfirmPopupButtonSetEnum buttonSet, const VfxWString &popuptext, VfxObject *parent);


class VAppDLAgentInterface : public VfxObject
{
	VFX_OBJ_DECLARE_SINGLETON_CLASS(VAppDLAgentInterface);
public:
	 VfxSignal1<void *> m_dispatchCallback;
	 static void OnServiceCallback(void* rsp_data)
	 {
         ((VAppDLAgentInterface *)VFX_OBJ_GET_INSTANCE(VAppDLAgentInterface))->m_dispatchCallback.emit(rsp_data);
	 }
};




class VappDLAgentDownloadListControl : public VcpListMenuCellClientBaseFrame
{
public:
    enum
    {
        LIST_CONTROL_TEXT_FILENAME = 1,
        LIST_CONTROL_TEXT_SIZE,
        LIST_CONTROL_TEXT_TIME,
        LIST_CONTROL_TEXT_STATUS
    };

    typedef void (*button_handler_type) (void);

    VfxU32               m_curr_index; /* Index of the list menu, may be helpful for co-ordinate filling */
    VfxU32               m_listType;
	VfxBool              unfolded;
    VfxFrame             *m_frame;
    VfxS32               m_arg_id;  /* This is used to get the job id of this item */
    VfxTextFrame          *m_text_filename;
    VfxTextFrame          *m_text_size;
    VfxTextFrame          *m_text_time;
    VfxTextFrame          *m_text_status;
    VcpProgressIndicator  *progress_bar;

    VcpButton            *m_left_button;
    VcpButton            *m_right_button;
	VfxBool              isRotated;

	VappDLAgentDownloadListControl (VfxU32 index, VfxU32 listType):
		m_curr_index(index), 
		m_listType(listType), 
		unfolded(VFX_FALSE),
		m_frame(NULL), 
		m_arg_id(-1), 
		m_text_filename(NULL), 
		m_text_size(NULL), 
        m_text_time(NULL), 
        m_text_status(NULL), 
        progress_bar(NULL),
        m_left_button(NULL), 
        m_right_button(NULL), 
        isRotated(VFX_FALSE)
    {

    }

    void set_text (VfxWChar *text, VfxU16 field);    
 	void set_button_text(VcpButton *button, VfxWString &text);
	void set_button_enable(VcpButton *button, VfxBool enable);
    void set_progress (VfxFloat percentage);
    void setArgID (VfxS32 ID);
	void updateContentOfEachItem(void);
    void handleLeftButtonHandler (VfxObject *sender, VfxId id);
    void handleRightButtonHandler (VfxObject *sender, VfxId id);
    void onCancelConfirmation(VfxObject* obj, VfxId id);
    void resetPosition (void);
    virtual void onInit (void);
    virtual void onDeinit (void);
	virtual void onCreateElements(void){}
	virtual void onCloseElements(void){}
	virtual void onLayoutElements(void);
    virtual void onUpdateElements(void){}
    virtual void onUpdateEmphasisFocus(VfxBool isFocus);
    VfxS32 componentHeight(void);
    VfxS32 componentWidth(void);
    VfxS32 commonDistance(void);
    VfxS32 filenameLength(void);
    VfxS32 sizeDisplayLength(void);
    VfxS32 timeDisplayLength(void);
    VfxS32 statusDisplayLength(void);
    VfxS32 topMargin(void);
    VfxS32 bottomMargin(void);
    VfxS32 leftMargin(void);
    VfxS32 rightMargin(void);
    VfxS32 buttonWidth(void);
    VfxS32 buttonLength(void);
    VfxS32 buttonDistance(void);
    VfxS32 progressbarwidth(void);
    VfxS32 progressbarLength(void);
	VfxS32 getArgID (void);
	VfxBool isItemRotated (void);
};


class VappDLAgentScreen : public VfxMainScr
{
public:
    enum
    {
        DLA_PAGE_NEW_DOWNLOAD_PAGE = 1,
        DLA_PAGE_DOWNLOAD_LIST_PAGE,
        DLA_PAGE_COMPLETED_LIST_PAGE,
        DLA_PAGE_USER_AUTH_PAGE,
        DLA_PAGE_USER_CONF_PAGE,
        DLA_PAGE_JOB_DETAIL_PAGE,
        DLA_PAGE_END
    };
	VappDLAgentDownloadListPage                 *m_downloading_page;
    VappDLAgentNewDownloadPage                  *m_new_download_page;
    VappDLAgentMainPage                         *m_tabbedDownload_page;
    VcpIndicatorPopup                           *m_progress_popup;
    VappDLAgentUserAuthPage                     *m_userAuthPage;
    VappDLAgentJobDetailPage                    *m_jobDetail;
    void                                        *m_popupArg;
    vapp_da_app_launch_struct                   m_screenArg;

	VappDLAgentScreen(void *arg, VfxU16 size):
        m_downloading_page(NULL), 
		m_new_download_page(NULL), 
        m_tabbedDownload_page(NULL), 
        m_progress_popup(NULL),
		m_userAuthPage(NULL), 
		m_jobDetail(NULL), 
		m_popupArg(NULL)
    {
        if(((vapp_da_app_launch_struct *)arg)->type == SRV_DA_APP_LAUNCH_PROGRESSING ||
          ((vapp_da_app_launch_struct *)arg)->type == SRV_DA_APP_LAUNCH_DISPLAY_JOB_DETAIL)
        {
            setIsSmallScreen();
        }
    }

    void drawNewDownloadPage (void *arg);
	void drawDownloadListPage(void *arg);
    void drawProgressScreen (void *arg);
    void closeProgressScreen (void *arg);
    void displayPopup (void *param);
    void createPopup(VfxU16 balloonType, VfxU32 string_id);
    void drawUserAuthPage (void *arg);
    void showUserConfirm (void *arg);
    void showJobDetails (void *arg);
	void onServiceEventHandler(vapp_da_app_launch_struct *arg);
    void serviceEventHandler (void *param);
    void onProcessingCanceled (VfxObject* obj, VfxFloat curr_progress);
	virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onInit();
    virtual void on1stReady();
    virtual void onDeinit();
};


class VcpDLAgentNCenter;
class VappDLAgentApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappDLAgentApp);

public:
    VappDLAgentScreen *scr;

    VappDLAgentApp ():scr(NULL){}
	
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
};

extern void vapp_da_app_util_format_time(U16 *buffer, U32 total_secs);
extern MMI_BOOL vapp_da_job_on_use_file_selected(srv_da_job_struct *job);
#ifdef __MMI_OMA_DD_DOWNLOAD__
extern void vapp_da_oma_get_item_progress(const srv_da_job_struct* job, srv_da_item_progress_struct *info);
#endif

#endif /* __MMI_DOWNLOAD_AGENT__ */
#endif /* _VAPP_DLAGENT_MAIN_H_ */
