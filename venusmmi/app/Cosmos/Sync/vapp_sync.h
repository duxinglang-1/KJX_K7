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
 *  vapp_sync.h
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
#ifndef __VAPP_SYNC_H__
#define __VAPP_SYNC_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDatatype.h"
#include "syncml_common_customize.h"
#include "SyncSrvGprot.h"

#include "vfx_app.h"
#include "vfx_datatype.h"
#include "vfx_main_scr.h"

#include "vapp_sync_now.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SYNC_HINT_TEXT_COLOR  VfxColor(255, 50, 50, 50)

#define VAPP_SYNC_LOG0(sub_grp) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp)

#define VAPP_SYNC_LOG1(sub_grp, arg) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp, arg)
		
#define VAPP_SYNC_LOG2(sub_grp, arg1, arg2) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp, arg1, arg2)

#define VAPP_SYNC_LOG3(sub_grp, arg1, arg2, arg3) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp, arg1, arg2, arg3)
			
#define VAPP_SYNC_LOG4(sub_grp, arg1, arg2, arg3, arg4) \
				MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp, arg1, arg2, arg3, arg4)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define VAPP_SYNC_PAGE_ID(_x) VappSyncMainScr::VAPP_SYNC_PAGE_ID_##_x

#define VAPP_SYNC_GET_ID(_idx) (VappSyncApp::s_dbIdCode[_idx])
#define VAPP_SYNC_GET_DB_CHK_INVALID_RESID(_x) VappSyncApp::s_strDatabaseChkInvalid[VAPP_SYNC_GET_ID(_x)]
#define VAPP_SYNC_GET_DB_RESID(_x) VappSyncApp::s_strDatabaseName[VAPP_SYNC_GET_ID(_x)]
#define VAPP_SYNC_GET_DB_NAME(_x) VFX_WSTR_RES(VappSyncApp::s_strDatabaseName[VAPP_SYNC_GET_ID(_x)])
#define VAPP_SYNC_GET_DB_MASK(_x) (VappSyncApp::s_strDatabaseMask[VAPP_SYNC_GET_ID(_x)])
#define VAPP_SYNC_GET_DB_PKG_NAME(_x) (VappSyncApp::s_strDatabasePkgName[VAPP_SYNC_GET_ID(_x)])
#define VAPP_SYNC_GEN_DB_STR(_app) VappSyncApp::genDatabaseString(_app)
#define VAPP_SYNC_GEN_ERROR_STR(_x) (VappSyncApp::s_strErrorCode[_x])
#define VAPP_SYNC_GEN_PS_ERROR_STR(_err) (VappSyncApp::getPsErrorStr(_err))

#define VAPP_SYNC_MAX_PS_ERROR 16
#define VAPP_SYNC_TOTAL_DATABASE (VappSyncApp::VAPP_SYNC_DB_TOTAL)

typedef struct
{
	VfxU32 errCode;
	VfxResId resId;
}VappSyncPsErrorCode;


/***************************************************************************** 
 * Class VappSyncApp
 *****************************************************************************/
class VappSyncApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappSyncApp);

public:
	VappSyncApp() : m_syncScr(NULL), m_isNeedClose(VFX_FALSE), m_activeScrId(0) {};
	virtual ~VappSyncApp(){};

	void showSyncNow(const VfxU16 &sync, const VfxS32 &index, const void *data);
	
  void continueSyncClose(void) 
  { 
      m_isNeedClose = VFX_FALSE;
      continueClose(VFX_APP_CLOSE_ANSWER_YES);
  }
  
  VfxBool needClose(void) const { return m_isNeedClose; }
  VfxScreen *getCurrScr(void) { return getScreen(m_activeScrId); }
  
public:

	/*
	 *  To support dynamic database table, we need to transfer index to Database ID
	 */
	enum
	{
		VAPP_SYNC_DB_CON,
	#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
		VAPP_SYNC_DB_CAL,
	#endif
	#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
		VAPP_SYNC_DB_TASK,
	#endif
	#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
		VAPP_SYNC_DB_NOTE,
	#endif
		VAPP_SYNC_DB_TOTAL
	};
	
// Override
protected:
    void onRun(void* args, VfxU32 argSize);
    VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

private:
      
    VfxWeakPtr<VappSyncNowScr> m_syncScr;
    VfxBool m_isNeedClose;
    mmi_id m_activeScrId;

public:
	static VfxResId getPsErrorStr(const VfxU32 &errCode);
	static VfxWString genDatabaseString(const VfxU32 &app);
	static VfxBool isConnection(void){ return s_isConnection; }
	static void setConnecting(const VfxBool &conn){ s_isConnection = conn; }
	static VfxBool isSyncAvailable(VfxBool isShowPopup);
	
	static const VfxU16 s_dbIdCode[VAPP_SYNC_TOTAL_DATABASE];	
	static const VfxResId s_strDatabaseName[SYNCML_DB_ID_TOTAL];
	static const VfxResId s_strDatabaseChkInvalid[SYNCML_DB_ID_TOTAL];
	static const VfxId 	s_strDatabaseMask[SYNCML_DB_ID_TOTAL];
	static const VfxChar *s_strDatabasePkgName[SYNCML_DB_ID_TOTAL];
	static const VfxResId s_strErrorCode[SRV_SYNC_RET_TOAL];
	static const VappSyncPsErrorCode s_psErrorCode[VAPP_SYNC_MAX_PS_ERROR];
	static VfxBool s_isConnection;
};


/***************************************************************************** 
 * Class VappSyncMainScr
 *****************************************************************************/
class VappSyncMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappSyncMainScr);

// Override
public:
	VappSyncMainScr(){};
  ~VappSyncMainScr(){};

	enum
	{
		VAPP_SYNC_PAGE_ID_LIST = VFX_ID_NULL + 1,
		VAPP_SYNC_PAGE_ID_ADD_SERVER,
		VAPP_SYNC_PAGE_ID_ADD_SELDB,
		VAPP_SYNC_PAGE_ID_ADD_DBADDR,
		VAPP_SYNC_PAGE_ID_ACCNT_EDIT,
		VAPP_SYNC_PAGE_ID_ACCNT_EDIT_SERVER,
		VAPP_SYNC_PAGE_ID_ACCNT_EDIT_SELDB,
		VAPP_SYNC_PAGE_ID_ACCNT_EDIT_DBADDR,
		VAPP_SYNC_PAGE_ID_ACCNT_EDIT_REGULAR,
		VAPP_SYNC_PAGE_ID_LOG,
		VAPP_SYNC_PAGE_ID_TOTAL
	};
	
    void on1stReady();

	void showPage(VfxId pageId, VfxS32 data);
	
private:
	//
};

#endif /* __VAPP_SYNC_H__ */

