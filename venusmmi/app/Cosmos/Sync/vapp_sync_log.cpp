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
 *  vapp_sync_report.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Fancy alarm ap.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "GlobalResDef.h"
#include "common_nvram_editor_data_item.h"
#include "mmi2syncml_struct.h"

#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_app_cosmos_global_def.h"

#include "vfx_basic_type.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_form.h"

#include "vapp_sync.h"
#include "vapp_sync_log.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define ID_TOOLBAR_RESET	'RST'

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
/***************************************************************************** 
 * Class VappSyncLogPage
 *****************************************************************************/
VappSyncLogPage::VappSyncLogPage(const VfxS32 &index) 
	: m_buffer(NULL), 
	  m_form(NULL), 
	  m_index(index)
{
}

void VappSyncLogPage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_LOG));
	setTopBar(titleBar);

	VFX_ALLOC_MEM(m_buffer, NVRAM_EF_SYNCML_VIEW_LOG_SIZE, this);

	loadContent();
}

void VappSyncLogPage::onDeinit(void)
{
	VFX_FREE_MEM(m_buffer);
	
	VfxPage::onDeinit();
}

void VappSyncLogPage::loadContent(void)
{
	readLog();
	
	nvram_ef_syncml_view_log_struct *log = (nvram_ef_syncml_view_log_struct *)m_buffer;

	// No logs
	if (log->last_sync_time == 0)
	{
		VfxTextFrame *text;
		VFX_OBJ_CREATE(text, VfxTextFrame, this);
		text->setAnchor(0.5F, 0.5F);
		text->setPos(getSize().width >> 1, getSize().height >> 1);
#if defined(__MMI_VUI_COSMOS_CP__)
		text->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
		text->setFont(VFX_FONT_RES(FNT_COSMOS_TEXT_EMPTY));
#else /* defined(__MMI_VUI_COSMOS_CP__) */
		text->setColor(VFX_COLOR_GREY);
#endif /* defined(__MMI_VUI_COSMOS_CP__) */

		text->setString(VFX_WSTR_RES(STR_ID_VAPP_SYNC_NO_LOG));
		text->setAlignParent(
							VFX_FRAME_ALIGNER_MODE_SIDE,
							VFX_FRAME_ALIGNER_MODE_SIDE,
							VFX_FRAME_ALIGNER_MODE_SIDE,
							VFX_FRAME_ALIGNER_MODE_SIDE);
		return;
	}

	VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem(ID_TOOLBAR_RESET, VFX_WSTR_RES(STR_GLOBAL_RESET), VCP_IMG_TOOL_BAR_COMMON_ITEM_CLEAR);
	toolBar->m_signalButtonTap.connect(this, &VappSyncLogPage::onToolbarClick);
	setBottomBar(toolBar);
	
	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());
	m_form->setAlignParent(
						VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE);

	VcpFormItemCaption *accntCaption;
	VFX_OBJ_CREATE(accntCaption, VcpFormItemCaption, m_form);
	accntCaption->setText(getAccntName());
	m_form->addItem(accntCaption, ID_FORM_CAPTION_NAME);

	VfxResId resSyncFinish = ((SYNCML_GET_SYNC_STATUS(log->sync_result)) == SRV_SYNC_OK) ? STR_ID_VAPP_SYNC_FINISHED : STR_ID_VAPP_SYNC_UNFINISH;

	VcpFormItemLauncherCell *syncResult;
	VFX_OBJ_CREATE(syncResult, VcpFormItemLauncherCell, m_form);
	syncResult->setIsTappable(VFX_FALSE);
	syncResult->setMainText(VFX_WSTR_RES(resSyncFinish));

	applib_time_struct outTime;
	applib_dt_utc_sec_2_mytime(log->last_sync_time, &outTime, KAL_FALSE);
	VfxDateTime dateTime;
	dateTime.setDateTime(&outTime);

	syncResult->setHintText(dateTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK | 
													   VFX_DATE_TIME_TIME_HOUR |
													   VFX_DATE_TIME_TIME_MINUTE));	
	m_form->addItem(syncResult, ID_FORM_LAUNCH_TIME);
	
	VcpFormItemLauncherCell *serverAddr;
	VFX_OBJ_CREATE(serverAddr, VcpFormItemLauncherCell, m_form);
	serverAddr->setIsTappable(VFX_FALSE);
	serverAddr->setMainText(getRemoteHeader());
	serverAddr->setHintText(getRemoteName());	
	m_form->addItem(serverAddr, ID_FORM_LAUNCH_SERVER_ADDR);

	VfxU8 formIndex = ID_FORM_LAUNCH_SERVER_ADDR + 1;
	
	VcpFormItemCaption *localInfoCaption;
	VFX_OBJ_CREATE(localInfoCaption, VcpFormItemCaption, m_form);
	localInfoCaption->setText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_LOCAL_INFO));
	m_form->addItem(localInfoCaption, formIndex);
	++formIndex;

	VcpFormItemLauncherCell *cltCell;
	
	VfxWString mainStr;
	
	for (VfxU32 i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if (log->app_to_sync & VAPP_SYNC_GET_DB_MASK(i))
		{
			VFX_OBJ_CREATE(cltCell, VcpFormItemLauncherCell, m_form);
			cltCell->setIsTappable(VFX_FALSE);

			mainStr = VAPP_SYNC_GET_DB_NAME(i);
			// database sync fail
			if ((log->db_sync_result & VAPP_SYNC_GET_DB_MASK(i)) || 
				((SYNCML_GET_SYNC_STATUS(log->sync_result)) != SRV_SYNC_OK))
			{
				mainStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_LOG_DB_UNFINISH);
			}
			else
			{
				mainStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_LOG_DB_FINISH);
			cltCell->setHintText(makeDBString(VAPP_SYNC_GET_ID(i), CLT_LOG, log));	
			}
			
			cltCell->setMainText(mainStr);
			
			m_form->addItem(cltCell, formIndex);
			++formIndex;
		}
	}

	VcpFormItemCaption *srvInfoCaption;
	VFX_OBJ_CREATE(srvInfoCaption, VcpFormItemCaption, m_form);
	srvInfoCaption->setText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_SERVER_INFO));
	m_form->addItem(srvInfoCaption, formIndex);
	++formIndex;
	
	for (VfxU32 i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if (log->app_to_sync & VAPP_SYNC_GET_DB_MASK(i))
		{
			VFX_OBJ_CREATE(cltCell, VcpFormItemLauncherCell, m_form);
			cltCell->setIsTappable(VFX_FALSE);

			mainStr = VAPP_SYNC_GET_DB_NAME(i);
			// database sync fail
			if ((log->db_sync_result & VAPP_SYNC_GET_DB_MASK(i)) ||
				((SYNCML_GET_SYNC_STATUS(log->sync_result)) != SRV_SYNC_OK))
			{
				mainStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_LOG_DB_UNFINISH);
			}
			else
			{
				mainStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_LOG_DB_FINISH);
				cltCell->setHintText(makeDBString(VAPP_SYNC_GET_ID(i), SRV_LOG, log));	
			}
			cltCell->setMainText(mainStr);
			
			m_form->addItem(cltCell, formIndex);
			++formIndex;
		}
	}

}


VfxWString VappSyncLogPage::makeDBString(const VfxU8 &dbID, const VfxU8 &role, const void *log)
{
	nvram_ef_syncml_view_log_struct *vlog = (nvram_ef_syncml_view_log_struct *)log;

	VfxWString retStr, tmpStr;
	VfxU32 cnt = 0;

	retStr.loadFromRes(STR_GLOBAL_ADD);

	cnt  = (role == SRV_LOG) ? vlog->svr_ok_cnt[dbID][0] : vlog->clt_ok_cnt[dbID][0];	
	retStr += tmpStr.format(":%d", cnt);
	retStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_SPACE);
	retStr += VFX_WSTR_RES(STR_GLOBAL_REPLACE);
	cnt = (role == SRV_LOG) ? vlog->svr_ok_cnt[dbID][1] : vlog->clt_ok_cnt[dbID][1];
	retStr += tmpStr.format(":%d", cnt);
	retStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_SPACE);
	retStr += VFX_WSTR_RES(STR_GLOBAL_DELETE);
	cnt = (role == SRV_LOG) ? vlog->svr_ok_cnt[dbID][2] : vlog->clt_ok_cnt[dbID][2];
	retStr += tmpStr.format(":%d", cnt);
	retStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_SPACE);
	retStr += VFX_WSTR_RES(STR_GLOBAL_ERROR);
	cnt = (role== SRV_LOG) ? vlog->svr_ng_cnt[dbID] : vlog->clt_ng_cnt[dbID];
	retStr += tmpStr.format(":%d", cnt);

	return retStr;
}

void VappSyncLogPage::onToolbarClick(VfxObject* obj, VfxId id)
{
	if (id != ID_TOOLBAR_RESET)
	{
		return;
	}
	
	onReset();
}
void VappSyncLogPage::onReset(void)
{
	setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, NULL, VFX_TRUE);
	
	VFX_OBJ_CLOSE(m_form);
	
	loadContent();
}

