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
 *  vtst_rt_cui.h
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  Venus Regression Test for CUI
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VTST_RT_CUI_H__
#define __VTST_RT_CUI_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_rt_main.h"

#include "vfx_datatype.h"
#include "MMIDataType.h"
#include "vfx_app_launcher.h"
#include "mmi_res_range_def.h"
#include "vfx_cui.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_timer.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

extern "C"
{

typedef struct {
    VtstRtApp *testcase;
    VfxU32 flag;
    VfxChar startPath[256];
} VtstCuiLaunchStruct;

// create/run cui
extern mmi_id cui_cui1_create(mmi_id parent_id, VtstCuiLaunchStruct *arg);
extern void cui_cui1_run(mmi_id cui_id);

// those methods only can be used when CUI is running
extern void cui_cui1_set_flag(mmi_id cui_gid, VfxU32 flag);
void cui_cui1_set_path(mmi_id cui_id, VfxChar *path, VfxU32 pathLen);
extern PS8 cui_cui1_get_result(mmi_id cui_id);

// close the CUI
extern void cui_cui1_close(mmi_id cui_gid);

} // extern "C"

typedef enum {
    EVT_ID_CUI_VTST_FINISHED = CUI1_BASE,
    EVT_ID_CUI_VTST_STARTED,
    EVT_ID_CUI_VTST_END
} cui_vtst_evt_enum;


/***************************************************************************** 
 * VtstCui
 *****************************************************************************/

class VtstCui : public VfxCui
{
    VFX_DECLARE_CLASS(VtstCui);

public:  
// Constructor / Destructor
    VtstCui() : m_testcase(NULL), m_flag(0)
    {
        m_startPath[0] = '\0';
    }

    virtual ~VtstCui() {}
    
// Override
    virtual void onRun(void *arg, VfxU32 argSize);

// Method
    void setFlag(VfxU32 flag);
    VfxU32 getFlag();
    void setPath(VfxChar *path, VfxU32 pathLen);
    void getPath(VfxChar *buff, VfxU32 buffSize);
    VfxChar *getResult();

// Implementation

    VtstRtApp *m_testcase;
    VfxU32 m_flag;
    VfxChar m_startPath[256];

private:
    void sendResultTimerCb(VfxTimer *timer);
    void cuiStartPostResultCb(mmi_group_event_struct *originalEvt, mmi_ret result);
};

#endif /* __VTST_RT_CUI_H__ */

