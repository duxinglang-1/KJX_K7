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
 *  vapp_theme_evt_hdlr.h
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_THEME_EVT_HDLR_H__
#define __VAPP_THEME_EVT_HDLR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_weak_ptr.h"
#include "vfx_base_popup.h"
#include "vfx_cui.h"

#include "vapp_theme_dlt.h"

/***************************************************************************** 
 * define
 *****************************************************************************/
#define VAPP_THEME_RESTORE_TOTAL 	(VappThemeAndAppIconSwitchCui::RETORE_TYPE_TOTAL)
#define VAPP_THEME_RESTORE_THEME 	(VappThemeAndAppIconSwitchCui::RETORE_TYPE_THEME)
#define VAPP_THEME_RESTORE_APPICON 	(VappThemeAndAppIconSwitchCui::RETORE_TYPE_APPION)


/***************************************************************************** 
 * Class VappThemeAndAppIconSwitchCui
 *****************************************************************************/
class VappThemeAndAppIconSwitchCui : public VappThemeDltSwitchCui
{
	VFX_DECLARE_CLASS(VappThemeAndAppIconSwitchCui);	

// Overridable
protected:
	VfxBool active(void);
	VappThemeDltCntx *getCntx();
	VfxS32 checkValid(void) { return 0; }

private:
	enum
	{
		RETORE_TYPE_THEME,
		RETORE_TYPE_APPION,
		RETORE_TYPE_TOTAL
	};
	
	VfxBool restore(void);
	VfxBool reset(void);
	
private:
	VappThemeDltCntx *m_cntx;
	
	static VfxBool s_isNeedRestore[VAPP_THEME_RESTORE_TOTAL];

public:
	static VfxBool isNeedReset(void);
	static VfxBool isNeedRestore(void);
};

extern mmi_id vapp_theme_evt_init(mmi_event_struct *evt);

#endif /* __VAPP_THEME_EVT_HDLR_H__ */

