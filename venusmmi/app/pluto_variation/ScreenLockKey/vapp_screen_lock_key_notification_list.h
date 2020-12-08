/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_screen_lock_key_notification_list.h
 *
 * Project:
 * --------
 *  MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_KEY_NOTIFICATION_LIST_H
#define VAPP_SCREEN_LOCK_KEY_NOTIFICATION_LIST_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_KEY__) && defined(__MMI_NCENTER_SUPPORT__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_screen_lock_key_notification_cell.h"

#include "vcp_var_height_menu.h"
#include "vfx_date_time.h"
#include "vsrv_notification.h"
#include "vsrv_ndeclaration.h"
#include "vsrv_ncenter.h"

/*****************************************************************************
 * Defines
 *****************************************************************************/



/*****************************************************************************
 * VappScreenLockKeyNotificationList
 *****************************************************************************/

class VappScreenLockKeyNotificationList : public VcpVarHeightMenu
{
    VFX_DECLARE_CLASS(VappScreenLockKeyNotificationList);
    
/*----------------------------------------------------------------*/
/* Functions                                                      */
/*----------------------------------------------------------------*/  

public:

    VappScreenLockKeyNotificationList();

public:
       
    typedef enum
    {
        ADD = 0,
        UPDATE,
        CLOSE,
        UNSUPPORT
    } ActionEnum;

    void checkNotifications();
    VappScreenLockKeyNotificationList::ActionEnum onNotify(VsrvNotification* notify, VsrvNStatusType status);

//override: VcpVarHeightMenu
public:

    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    
protected:

    virtual void onInit();
    virtual void onDeinit();

private:

    VfxS32 getIndex(VsrvNGroupId id);
    VfxS32 getIndexByGroupId(VsrvNGroupId id);
    VfxBool checkAvailable(VsrvNotification * notify);
    VfxBool checkSettingByGroupId(VsrvNGroupId id);    
    
/*----------------------------------------------------------------*/
/* Variables                                                      */
/*----------------------------------------------------------------*/
public:

    

private:

    VfxBool           m_isChecked;
    VsrvNCenter      *m_nCenter;    
    VfxImageFrame    *m_bg;
    
    static VfxDateTime m_createTime;

    static VfxBool     m_isInCall;
    static VfxBool     m_shallTraverse;
    
    static VappScreenLockKeyNotificationContex s_notiTbl[VAPP_SCREEN_LOCK_KEY_NOTIFICATION_TOTAL+1];
    
};


#endif
#endif

