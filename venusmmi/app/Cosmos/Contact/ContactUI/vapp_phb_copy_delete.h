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
 *  vapp_phb_copy_delete.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __PB_COPY_DELETE_H__
#define __PB_COPY_DELETE_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"

#include "vapp_contact_entry.h"
#include "vapp_contact_op.h"
#include "vapp_contact_util.h"
#include "vapp_contact_several.h"


/***************************************************************************** 
 * Class VappPhbCopy
 *****************************************************************************/ 
class VappPhbCopy: public VfxObject
{
public:
    VappPhbCopy(mmi_phb_contact_id id, VfxScreen *scr);

    void finishOP();

    void onOptionClicked(VfxObject* object, VfxId id);

    void onCopyDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result);

protected:
    virtual void onInit();

private:
    VappPhbCopy(){}

    void copy(phb_storage_enum storage);

private:
    mmi_phb_contact_id m_id;
    VfxScreen *m_parent;
    VcpIndicatorPopup *m_progress;
    phb_storage_enum m_storage;
};


/***************************************************************************** 
 * Class VappPhbDelete
 *****************************************************************************/ 
class VappPhbDelete: public VfxObject
{
public:
    VappPhbDelete(mmi_phb_contact_id id, VfxScreen *scr);

    void finishOP();

    void onButtonClicked(VfxObject* obj, VfxId id);

    void onDeleteDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result);

protected:
    virtual void onInit();

private:
    VappPhbDelete(){}

private:
    mmi_phb_contact_id m_id;
    VfxScreen *m_parent;
    VcpIndicatorPopup *m_progress;
};


/***************************************************************************** 
 * Class VappPhbCopySeveral
 *****************************************************************************/ 
class VappPhbCopySeveral: public VfxObject
{
public:
    VappPhbCopySeveral(phb_storage_enum storage, ContactMark *mark, VfxScreen *scr);

    void finishOP();

    void cancel();

    void onCopyDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result);

    void onCancelClicked(VfxObject *obj, VfxFloat progress);

    void onProgressClicked(VfxObject* obj, VfxId id);

    VfxSignal0 m_signalDone;

protected:
    virtual void onInit();

    virtual void onDeinit();

private:
    VappPhbCopySeveral(){}

    void copy();

private:
    phb_storage_enum m_storage;
    ContactMark *m_mark;
    VfxScreen *m_parent;
    VcpIndicatorPopup *m_progress;
    ContactCopySeveral *m_copy;
};


/***************************************************************************** 
 * Class VappPhbDeleteSeveral
 *****************************************************************************/ 
class VappPhbDeleteSeveral: public VfxObject
{
public:
    VappPhbDeleteSeveral(ContactMark *mark, VfxScreen *scr);

    void finishOP();

    void cancel();

    void onButtonClicked(VfxObject* obj, VfxId id);

    void onDeleteDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result);

    void onCancelClicked(VfxObject *obj, VfxFloat progress);

    void onProgressClicked(VfxObject* obj, VfxId id);

    VfxSignal0 m_signalDone;

protected:
    virtual void onInit();

    virtual void onDeinit();

private:
    VappPhbDeleteSeveral(){}

private:
    ContactMark *m_mark;
    VfxScreen *m_parent;
    VcpIndicatorPopup *m_progress;
    ContactDeleteSeveral *m_delete;
};

#endif /* __PB_COPY_DELETE_H__ */

