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
 *  vapp_dla_ncenter.h
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
#ifndef __VAPP_DLA_NCENTER_H__
#define __VAPP_DLA_NCENTER_H__


#include "MMI_features.h" 
#include "vsrv_ncenter.h"
#include "vsrv_notification.h"
#include "vapp_ncenter.h"
#include "vapp_ncenter_base_cell.h"
#include "vapp_dla_main.h"
#include "mmi_rp_vapp_dlagent_def.h"

#define VAPP_DLAGENT_NCENTER_CELL_ICON_X (30)
#define VAPP_DLAGENT_NCENTER_CELL_COUNT (10)
#define VAPP_DLAGENT_NCENTER_CELL_FILE_NAME_LEN (15)

typedef enum
{
	EVT_ID_DLA_NCENTER_CANCEL_GLOBAL_POPUP = RESOURCE_BASE_VAPP_DLAGENT + 1,
	EVT_ID_DLA_END

}vapp_da_event_struct;


/***
   signal-slot mechanism, used to emit to update content of cells
***/

class VAppDLAgentNCenterInterface : public VfxObject
{
	VFX_OBJ_DECLARE_SINGLETON_CLASS(VAppDLAgentNCenterInterface);
public:

	 VfxSignal1<void *> m_ncenterCallback;
	 static void OnNCenterCallback(void *rsp_data)
	 {
         ((VAppDLAgentNCenterInterface *)VFX_OBJ_GET_INSTANCE(VAppDLAgentNCenterInterface))->m_ncenterCallback.emit(rsp_data);
	 }
};


/***
   interface for update of NCenter
***/
class VappDLAgentNCenterNew: public VfxObject
{
public:
	static void vapp_dla_update_ncenter(void *args, VfxU32 argSize);
	static void vapp_dla_remove_junk_item(VsrvNGroup *group);
	static void vapp_dla_update_ncenter_push_object();
	static void vapp_dla_update_statusbar(void);
    static void vapp_dla_update_statusbar_push_object();
	static void vapp_dla_show_push_notify (void *arg);
	static void vapp_dla_show_job_notify (void *arg);
};
/***
   actual cell for DLAgent, derived from VappNCenterOngoingCell, with a status button included
***/


class VappDLAgentonGoingCell: public VappNCenterOngoingCell
{
public:
	virtual void onInit();
	virtual void onDeinit();
	void onStatusButtonClick(VfxObject* sender, VfxId id);
	static void onConfirmButtonClick (VfxId id, void *userData);
	virtual void onButtonClick(VfxObject* sender, VfxId id);
	void setStatusButtonIcon(const VcpStateImage &imageList);
	VfxS32 getPopupID();
	void setStatusButtonEnabled(VfxBool enabled);

private: 
	VcpImageButton 	*m_status_button;
	VfxS32			m_popup_id;

public: 
	VappDLAgentonGoingCell():m_status_button(NULL), m_popup_id(-1){}
};

/*****
    custom cell for Notification at DLAgent App
*****/

class VappDLAgentNcenterBaseCell: public VsrvNCell 
{
	VFX_DECLARE_CLASS(VappDLAgentNcenterBaseCell);
public: 
	virtual void onCreateView(void * viewData,VfxU32 viewDataSize);
	//add detailed info of job to onGoingCell
	void fillNCenterCellData(void *args);
	void updateNCenterCellData(void *args);
	VappDLAgentonGoingCell 	*getOnGoingCell(void){return cell;}
	void setJobID(U32 job_id){m_dla_job_id = job_id;}
	U32 getJobID(void){return m_dla_job_id;}
protected:

private:
	VappDLAgentonGoingCell 	*cell;
	U32 m_dla_job_id;
	VfxBool need_update;

public: 
	VappDLAgentNcenterBaseCell():cell(NULL), m_dla_job_id(0), need_update(VFX_TRUE){}
};


#endif /* __VAPP_DLA_NCENTER_H__ */
