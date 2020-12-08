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
 *  vfx_cui.h
 *
 * Project:
 * --------
 *  Venus FW
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_CUI_H__
#define __VFX_CUI_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_app.h"

extern "C"
{
#include "MMIDataType.h"
}

#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_signal.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
typedef VfxCallback2<
            mmi_group_event_struct *,   // original event sent
            mmi_ret                     // post result
            > VfxCuiPostToParentCb;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
 * Class VfxCui
 *****************************************************************************/

/*
 * VfxCui. An Venus CUI is also an Pluto CUI and has own group id.
 * The only difference is an CUI has parent, while App has no parent.
 */
class VfxCui : public VfxApp
{
    VFX_DECLARE_CLASS(VfxCui);

    friend class VfxAppLauncher;

// Constructor / Destructor
public:
    VfxCui();
    virtual ~VfxCui();

// Method
public:
    // Send event to CUI parent
    // Note. In general case, CUI should send event to caller (via VfxApp::sendToCaller), not parent
    mmi_ret sendToParent(mmi_group_event_struct *pEvt);

    // post event to CUI parent w/ result sending back to you by VfxCuiPostToParentCb
    // Note. In general case, CUI should post event to caller (via VfxApp::postToCaller), not parent
    void postToParent(mmi_group_event_struct *pEvt, VfxCuiPostToParentCb cb = VFX_CALLBACK_NULL);  

    // get parent id
    mmi_id getParentId();

// override
protected:
    virtual void processGroupInactive(void);

/* DOM-NOT_FOR_SDK-BEGIN */
// Variable
private:

// Implementation
private:
    static void static_postToParentResultCb(mmi_post_result_event_struct *evt);
/* DOM-NOT_FOR_SDK-END */
};


/* DOM-NOT_FOR_SDK-BEGIN */
// Weak Pointer Type Define
typedef VfxWeakPtr <VfxCui> VfxCuiWeakPtr;
/* DOM-NOT_FOR_SDK-END */

#endif /* __VFX_CUI_H__ */

