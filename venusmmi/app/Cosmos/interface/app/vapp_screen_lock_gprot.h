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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH´Ë
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
 *  vapp_screen_lock_gprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SCREEN_LOCK_GPROT_H__
#define __VAPP_SCREEN_LOCK_GPROT_H__

#include "MMI_features.h"
#include "mmi_res_range_def.h" // For the base of app id.

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Event id
 *****************************************************************************/
typedef enum
{
    EVT_ID_VAPP_SCREEN_LOCK_BASE = VAPP_SCREEN_LOCK,

    /*
     * This event is emitted before launch screen lock
     *
     * Screen lock will not be launched if register callback return MMI_RET_ERR
     * else return MMI_RET_OK
     *
     * Structure: vapp_screen_lock_pre_lock_evt_struct
     */
    EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING,


    /*
     * This event is emitted after screen lock has been lunched
     *
     */
    EVT_ID_VAPP_SCREEN_LOCK_LOCKED_EVT,

    EVT_ID_END_OF_ENUM
} vapp_screen_lock_event_enum;


/***************************************************************************** 
 * Enum
 *****************************************************************************/
/*
 * DESCRIPTION
 *  Screen lock triggered type
 */
typedef enum
{
    VAPP_SCREEN_LOCK_MODE_BY_AUTO_LOCK,     /* screen lock triggered by auto backlight off */
    VAPP_SCREEN_LOCK_MODE_BY_POWER_KEY,     /* screen lock triggered by pressing power key */
    VAPP_SCREEN_LOCK_END_OF_ENUM
} vapp_screen_lock_mode_enum;
    

/***************************************************************************** 
 * Structure
 *****************************************************************************/
/* This is the structure for the EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK. */
typedef struct
{
    MMI_EVT_PARAM_HEADER
        
    /*
     * screen lock triggered type
     */ 
    vapp_screen_lock_mode_enum mode;
} vapp_screen_lock_pre_lock_evt_struct;


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_launch
 * DESCRIPTION
 *  This function is used to launch screen lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern mmi_id vapp_screen_lock_launch(void);


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_is_allowed_launch
 * DESCRIPTION
 *  This function is used to query if screen lock is allow to launch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL vapp_screen_lock_is_allowed_launch(void);


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_post_launch
 * DESCRIPTION
 *  This function is used to post launch screen lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  N/A
 *****************************************************************************/
extern void vapp_screen_lock_post_launch(void);


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_close
 * DESCRIPTION
 *  This function is used to close screen lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void vapp_screen_lock_close();


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_is_locked
 * DESCRIPTION
 *  This function check if the handset is locked by the screen lock.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL vapp_screen_lock_is_locked();


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_is_exist
 * DESCRIPTION
 *  This function check if screen lock is launched.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL vapp_screen_lock_is_exist();


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_disable_timer
 * DESCRIPTION
 *  This function disable backlight off timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern void vapp_screen_lock_disable_backlight_timer(MMI_BOOL disable);


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_get_group_id
 * DESCRIPTION
 *  This function get screen lock group id
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id
 * RETURN VALUES
 *  screen lock group id
 *****************************************************************************/
extern mmi_id vapp_screen_lock_get_group_id();


#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __cplusplus

#include "vcp_form.h"          // For VcpFormItemLauncherCell

/***************************************************************************** 
 * VappScreenLockSettingCell 
 *****************************************************************************/
class VappScreenLockSettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappScreenLockSettingCell);

// Constructor
public:
    VappScreenLockSettingCell();

// Override
protected:
    virtual void onInit();

// Methods
private:
    void onTap(VcpFormItemCell* sender, VfxId senderId);
    void updateCell() {setHintText(getHint());};
    void onContextUpdate(VfxS32 value) {m_storeValue = value; updateCell();};
    VfxWString getHint();

// Variables
private:
    VfxS32 m_storeValue;
};
#endif /* cplusplus */
#endif /* __VAPP_SCREEN_LOCK_GPROT_H__ */
