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
 *  vapp_bootup_ani.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Bootup animation of Venus MMI
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
#ifndef __VAPP_SHUTDOWN_H__
#define __VAPP_SHUTDOWN_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#include "GlobalResDef.h"

extern "C"
{
#include "ProcedureGprot.h"
#include "ProfilesSrvGprot.h" /* srv_prof_ret */
}

#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_main_scr.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SHUTDOWN_TRC_GROUP MMI_COMMON_TRC_G3_SHUTDOWN


/***************************************************************************** 
 * VappShutdownApp
 *****************************************************************************/
class VappAniPage;
class VappShutdownApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappShutdownApp);
	
// Interface
public:

	VappShutdownApp() :
		m_callbackProc(NULL),
		m_callbackUserData(NULL),
		m_mainScr(NULL)
	{
	}

	void playAnimation(mmi_proc_func proc, void *userData);

	void showMainScr()
	{
		if (m_mainScr != NULL && !m_mainScr->isShown())
		{
			m_mainScr->show();
		}
	}

	enum event_enum
	{
		EVT_ID_ANI_COMPLETED,
		EVT_ID_END_OF_ENUM
	};

	typedef struct
	{
		MMI_EVT_PARAM_HEADER
	} ani_completed_evt_struct;

// Override
protected:
    virtual void onInit();
	virtual void onRun(void * args, VfxU32 argSize);
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption option);

// Implement
private:
    void onAniPlayCompleted(VappAniPage *aniPage);
	VfxBool isPlayTone(void);
	void playTone(VappAniPage *aniPage);
	void onSetAniComplete(VappAniPage *obj, VfxS32 result);
	VappAniPage *ceateAniPage(void);
	VfxResId getDefaultAni(void);

private:
    enum PageEnum
    {
        PAGE_ANIMATION,
        PAGE_END_OF_ENUM
    };

    mmi_proc_func m_callbackProc;
    void *m_callbackUserData;
   
    VfxMainScr *m_mainScr;

};


/***************************************************************************** 
 * Interface
 *****************************************************************************/
mmi_frm_proc_result_enum vapp_shutdown_play_animation(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);
    
#endif /* __VAPP_SHUTDOWN_H__ */

