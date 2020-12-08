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
 *  vapp_mms_details_viewer.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MMS_H__
#define __VAPP_MMS_H__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_mms_data.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "Vfx_app.h"
#include "Vfx_screen.h"
#include "Vfx_main_scr.h"
#include "Vfx_page.h"
#include "vfx_basic_type.h"
#include "MMIDataType.h"
#include "vcp_popup.h"
#include "vcp_button.h"
#include "vcp_activity_indicator.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__

#define VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN 14
#define VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN 14
#define VAPP_MMS_DETAILS_STATUS_ICON_UPPER_MARGIN 106
#define VAPP_MMS_DETAILS_BUTTON_UPPER_MARGIN 89
#define VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN 14
#define VAPP_MMS_DATE_RIGHT_MARGIN VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN
#define VAPP_MMS_BUTTON_DATE_MARGIN 3
#define VAPP_MMS_BUTTON_STATUS_ICON_MARGIN 14
#define VAPP_MMS_DETAILS_TEXT_MARGIN 10
#define VAPP_MMS_DETAILS_BUTTON_HEIGHT 70
#define VAPP_MMS_DETAILS_BUTTON_WIDTH 175

#elif defined (__MMI_MAINLCD_320X480__)
#define VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN 8
#define VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN 10
#define VAPP_MMS_DETAILS_STATUS_ICON_UPPER_MARGIN 48
#define VAPP_MMS_DETAILS_BUTTON_UPPER_MARGIN 38
#define VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN 8
#define VAPP_MMS_DATE_RIGHT_MARGIN VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN
#define VAPP_MMS_BUTTON_DATE_MARGIN 6
#define VAPP_MMS_BUTTON_STATUS_ICON_MARGIN 7
#define VAPP_MMS_DETAILS_TEXT_MARGIN 4
#define VAPP_MMS_DETAILS_BUTTON_HEIGHT 40
#define VAPP_MMS_DETAILS_BUTTON_WIDTH 92

#elif defined (__MMI_MAINLCD_240X320__) 
#define VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN 5
#define VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN 5
#define VAPP_MMS_DETAILS_STATUS_ICON_UPPER_MARGIN 46
#define VAPP_MMS_DETAILS_BUTTON_UPPER_MARGIN 37
#define VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN 5
#define VAPP_MMS_DATE_RIGHT_MARGIN VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN
#define VAPP_MMS_BUTTON_DATE_MARGIN 2
#define VAPP_MMS_BUTTON_STATUS_ICON_MARGIN 5
#define VAPP_MMS_DETAILS_TEXT_MARGIN 1
#define VAPP_MMS_DETAILS_BUTTON_HEIGHT 38
#define VAPP_MMS_DETAILS_BUTTON_WIDTH 83

#elif defined (__MMI_MAINLCD_240X400__)
#define VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN 5
#define VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN 5
#define VAPP_MMS_DETAILS_STATUS_ICON_UPPER_MARGIN 46
#define VAPP_MMS_DETAILS_BUTTON_UPPER_MARGIN 37
#define VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN 5
#define VAPP_MMS_DATE_RIGHT_MARGIN VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN
#define VAPP_MMS_BUTTON_DATE_MARGIN 2
#define VAPP_MMS_BUTTON_STATUS_ICON_MARGIN 5
#define VAPP_MMS_DETAILS_TEXT_MARGIN 1
#define VAPP_MMS_DETAILS_BUTTON_HEIGHT 38
#define VAPP_MMS_DETAILS_BUTTON_WIDTH 83

#else
#define VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN 8
#define VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN 10
#define VAPP_MMS_DETAILS_STATUS_ICON_UPPER_MARGIN 48
#define VAPP_MMS_DETAILS_BUTTON_UPPER_MARGIN 38
#define VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN 8
#define VAPP_MMS_DATE_RIGHT_MARGIN VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN
#define VAPP_MMS_BUTTON_DATE_MARGIN 6
#define VAPP_MMS_BUTTON_STATUS_ICON_MARGIN 7
#define VAPP_MMS_DETAILS_TEXT_MARGIN 4
#define VAPP_MMS_DETAILS_BUTTON_HEIGHT 40
#define VAPP_MMS_DETAILS_BUTTON_WIDTH 92

#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

class VappMmsDetailsViewer : public VfxControl
{
	VFX_DECLARE_CLASS(VappMmsDetailsViewer);
public:
	void setData(VappMmsViewerData *data);
	VappMmsDetailsViewer(VfxU32 msg_id, VappMmsViewerData *data):m_msg_id(msg_id), m_data(data), m_download(NULL),m_indicator(NULL)
	{

	}
	VappMmsDetailsViewer()
	{
		m_msg_id = 0;
		//m_popup = NULL;
		m_data = NULL;	
		m_download = NULL;
		m_indicator = NULL;
	}
	virtual void setBounds(const VfxRect &value);

protected:
	virtual void onInit(void);
	
	virtual void onDeinit();
	
    private:
	VfxBool draw();
	void onClickDownload(VfxObject *obj, VfxId id);
    void onCnfPopCallback(VfxObject* sender, VfxId id);
	static mmi_ret listener(mmi_event_struct* param);

	
private:
	VfxU32 m_msg_id;
	//VcpAlertPopup *m_popup;
	VappMmsViewerData *m_data;	
	VcpButton *m_download;
	VcpActivityIndicator *m_indicator;
	
};

#else /*__MMI_MMS_2__*/

class VappMmsDetailsViewer : public VfxControl
{
	VFX_DECLARE_CLASS(VappMmsDetailsViewer);
    //empty class to avoid build error
};
VFX_IMPLEMENT_CLASS("VappMmsDetailsViewer", VappMmsDetailsViewer, VfxControl);
#endif /*__MMI_MMS_2__*/

#endif /* __VAPP_MMS_H__ */

