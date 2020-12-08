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
 *  vapp_sync_notification_center.h
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
#ifndef __VAPP_SYNC_NCENTER_H__
#define __VAPP_SYNC_NCENTER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
	#include "MMIDataType.h"
}

#include "vfx_datatype.h"
#include "vsrv_ndeclaration.h"
#include "vfx_uc_include.h"
#include "vapp_ncenter.h"
#include "vcp_status_icon_bar.h"
#include "vapp_ncenter_system_cell.h"

#include "vfx_primitive_frame.h"
#include "vapp_launcher_gprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef enum 
{
  NOTIFY_TYPE_UNFINISHED,
  NOTIFY_TYPE_REGULAR,
  NOTIFY_TYPE_ONGOING,
  NOTIFY_TYPE_TOTAL
} noti_type_enum;



#define ID_NOTI_UNFINISHED 1
#define ID_NOTI_REGULAR 2
#define ID_NOTI_ONGOING 3

/*****************************************************************************
 * Class VappSyncNCenterMngr
 *****************************************************************************/
class VfxWString;
class VappSyncNCenterMngr
{
public:
	static mmi_ret onAccntOp(mmi_event_struct *evt);
	static mmi_ret onSyncFinish(mmi_event_struct *evt);
	static mmi_ret onSyncAsk(mmi_event_struct *evt);
	static void unfinishIntentCallback(
					vsrv_notification_handle nhandle,
					vsrv_nintent intent, 
					void* userData, 
					U32 userDataSize);
	static void askSyncIntentCallback(
					vsrv_notification_handle nhandle,
					vsrv_nintent intent, 
		            void* userData,
		            U32 userDataSize);
	static void closeCurrApp(void);		
	static void onConfirmCallback(VfxId id, void *userData);
	static void nextSync(void);
	static void reset(VfxU8 noti_type);
	static void startSync(void);
	static VfxBool isNotiExist(noti_type_enum type) { return m_noti_exist[type];}
	static void updateRegularSyncNoti(VsrvNotification *noti, mmi_event_struct *evt);
	static void updateUnfinishSyncNoti(VsrvNotification *noti, mmi_event_struct *evt);
	static void getAccntName(VfxWString &str, void *accnt, srv_sync_enum sync);
	
private:
	
	static VfxU16 m_regular; 
    static VfxU16 m_sync[NOTIFY_TYPE_TOTAL];		
    static VfxU8  m_accntIdx[NOTIFY_TYPE_TOTAL];
	static VfxBool m_noti_exist[NOTIFY_TYPE_TOTAL];
	static VfxU32 m_timeStamp[NOTIFY_TYPE_TOTAL];
    static VfxS32 m_popHdl;	
};

#endif /* __VAPP_SYNC_NCENTER_H__ */

