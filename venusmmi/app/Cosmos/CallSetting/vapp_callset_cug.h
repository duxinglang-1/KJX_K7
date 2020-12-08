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
 *  vapp_callset_cug.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Closed user group
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
#ifndef __VAPP_CALLSET_CUG_H__
#define __VAPP_CALLSET_CUG_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h" /* mmi_id */

#include "vfx_datatype.h"
#include "vfx_page.h"

#include "vcp_list_menu.h"

#include "vapp_callset.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VappCallSetPageCug
 *****************************************************************************/
class VappCallSetPageCug : public VappCallSetAsyncPage, public IVcpListMenuContentProvider
{

// Override IVcpListMenuContentProvider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemIsHighlightable(VfxU32 index) const;

// Override VappCallSetAsyncPage
    virtual void onResult(mmi_event_struct *info);

// Override VfxPage
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);

private:
    enum
    {
        STATE_ACT = STATE_NONE + 1,
        STATE_ABORT,
        STATE_INVALID
    };

    void onTapped(VcpListMenu* menu, VfxU32 index);
    void onToolBarTapped(VfxObject* sender, VfxId id);

    void updateList(void);

    VfxU32 m_activateIndex;
    VfxU32 m_count;
    VcpListMenu *m_list;
};


/***************************************************************************** 
 * Class VappCallSetPageCugEdit
 *****************************************************************************/
class VappCallSetPageCugEdit : public VfxPage, public IVcpListMenuContentProvider
{

// Override IVcpListMenuContentProvider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxU32 getCount() const;

// Override VfxPage
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);

private:
    void onTapped(VcpListMenu* menu, VfxU32 index);
    void updateList(void);

    VfxU32 m_count;
    VcpListMenu *m_list;
};


/***************************************************************************** 
 * Class VappCallSetPageCugNameEdit
 *****************************************************************************/
class VappCallSetPageCugNameEdit : public VappCallSetPageCommonInputAsync
{
// Override VappCallSetAsyncPage
    virtual void onResult(mmi_event_struct *info);

// Override
protected:
    virtual void onInit();
    virtual void onExit(VfxBool isBackward);
    virtual void onTextChanged(VcpTextEditor* editor);
    virtual void onFuncBtnClicked(VfxObject* sender, VfxId id);

private:
    enum
    {
        STATE_ACT = STATE_NONE + 1,
        STATE_ABORT,
        STATE_INVALID
    };

};

#endif /* __VAPP_CALLSET_CUG_H__ */

