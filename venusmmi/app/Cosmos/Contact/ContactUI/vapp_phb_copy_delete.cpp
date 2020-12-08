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
 *  vapp_phb_copy_delete.cpp
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
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

#include "vapp_phb_app.h"
#include "vapp_phb_copy_delete.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "SimCtrlSrvGprot.h"
#include "GpioSrvGprot.h"

#ifdef __MMI_SNS_CONTACTS__
#include "SnsSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappPhbCopy
 *****************************************************************************/
VappPhbCopy::VappPhbCopy(mmi_phb_contact_id id, VfxScreen *scr):
    m_id(id),
    m_parent(scr),
    m_progress(NULL)
{
    m_storage = ContactStorage::getStorage(m_id);
}


void VappPhbCopy::onInit()
{
    VfxObject::onInit();

    if (ContactSim::getTotal() > 1
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__   // notice: if there is just nvram and tcard, the cmdPopup just has one selector .
        || srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV)
#endif
        )
    {
        VcpCommandPopup *option;
        VFX_OBJ_CREATE(option, VcpCommandPopup, m_parent);

        VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_COPY);
        if (ContactEntry(m_id).getName().getString().isEmpty())
        {
            text += VFX_WSTR_RES(VAPP_PHB_STR_UNNAMED);
        }
        else
        {
            text += ContactEntry(m_id).getName().getString();
        }

        text += VFX_WSTR_RES(STR_ID_VAPP_PHB_FROM_LOW);
        text += ContactStorage::getName(m_storage);
        option->setText(text);

        if (m_storage != PHB_STORAGE_NVRAM)
        {
            text.loadFromRes(STR_ID_VAPP_PHB_TO);
            text += VFX_WSTR_RES(VAPP_PHB_STR_PHONE);
            option->addItem(PHB_STORAGE_NVRAM, text, VCP_POPUP_BUTTON_TYPE_NORMAL);
        }

        for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
        {
            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            phb_storage_enum storage = ContactSim::getStorage(sim);
            if (storage != m_storage)
            {
                text.loadFromRes(STR_ID_VAPP_PHB_TO);
                text += ContactStorage::getName(storage);
                if (srv_sim_ctrl_is_inserted(sim))
                {
                    option->addItem(storage, text, VCP_POPUP_BUTTON_TYPE_NORMAL);
                    if (!srv_sim_ctrl_is_available(sim))
                    {
                        option->disableItem(storage);
                    }
                }
            }
        }

    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) && m_storage != PHB_STORAGE_TCARD)
        {
            text.loadFromRes(STR_ID_VAPP_PHB_TO);
            text += ContactStorage::getName(PHB_STORAGE_TCARD);
            option->addItem(PHB_STORAGE_TCARD, text, VCP_POPUP_BUTTON_TYPE_NORMAL);
        }
    #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
        option->addItem(PHB_STORAGE_MAX, (VfxResId)STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);

        option->m_signalButtonClicked.connect(this, &VappPhbCopy::onOptionClicked);

        option->show(VFX_TRUE);
    }
    else
    {
        copy((m_storage == PHB_STORAGE_NVRAM) ? PHB_STORAGE_SIM : PHB_STORAGE_NVRAM);  // notice: case T-card
    }
}


void VappPhbCopy::finishOP()
{
    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
    }

    VfxObject* self = this;
    VFX_OBJ_CLOSE(self);
}


void VappPhbCopy::copy(phb_storage_enum storage)
{
    STORAGE_STATUS status = ContactStorage::getStatus(storage);
    VfxWString errorStr;

    if (status == STORAGE_NOT_ACCESSABLE)
    {
        errorStr = ContactStorage::getName(storage);
        errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_UNAVAILABLE);
    }
    else if (status == STORAGE_FULL)
    {
        errorStr = ContactStorage::getName(storage);
        errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_FULL);
    }
    else if (storage != PHB_STORAGE_NVRAM
        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            && storage != PHB_STORAGE_TCARD
        #endif
            )
    {
        ContactEntry entry(m_id);
        VfxU32 count = entry.getNumber();

        if (count > 0)
        {
            VappContactNumber number = entry.getNextNumber();
            if (checkNumberWithSpecialChar(number.getBuf(), L'w', number.getLength()))
            {
                errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_NO_COPY_WITH_W);
            }
            else if (checkNumberWithSpecialChar(number.getBuf(), L'?', number.getLength()))
            {
                errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_NO_COPY_WITH_Q);
            }
        }
    }

    if (!errorStr.isEmpty())
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, errorStr);
        finishOP(); // __MMI_CONTACTS_TCARD__ notice: lose call finishOP()? 
    }
    else
    {
        ContactCopy *copy;
        VFX_OBJ_CREATE_EX(copy, ContactCopy, this, (m_id, storage));

        if (copy->prepare(CONTACT_COPY, CONTACT_WANT) == CONTACT_RUN)
        {
            VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, m_parent);
            m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_progress->setText(STR_ID_VAPP_PHB_COPYING);
            m_progress->show(VFX_TRUE);

            // copy the contact
            copy->run();
            copy->m_signalOP.connect(this, &VappPhbCopy::onCopyDone);
        }
        else
        {
            finishOP();
        }
    }
}


void VappPhbCopy::onOptionClicked(VfxObject* object, VfxId id)
{
    phb_storage_enum storage = (phb_storage_enum)id;

    if (storage == PHB_STORAGE_MAX || id == VCP_POPUP_BUTTON_NO_PRESSED || id == VCP_CONFIRM_POPUP_BUTTON_CANCEL)
    {
        finishOP();
    }
    else
    {
        copy(storage);
    }
}


void VappPhbCopy::onCopyDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result)
{
    srv_phb_copy_cb_struct *copyResult = (srv_phb_copy_cb_struct*) result;

    op->complete();

    finishOP();

    vapp_phb_op_error_balloon(copyResult->result);
}


/***************************************************************************** 
 * Class VappPhbDelete
 *****************************************************************************/
VappPhbDelete::VappPhbDelete(mmi_phb_contact_id id, VfxScreen *scr):
    m_id(id),
    m_parent(scr),
    m_progress(NULL)
{
}


void VappPhbDelete::onInit()
{
    VfxObject::onInit();

    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, m_parent);

    VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_DELETE_THE_CONTACT);
    text += VFX_WSTR_RES(STR_ID_VAPP_PHB_QUESTION);

    confirm->setText(text);
    confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirm->setCustomButton(
                STR_GLOBAL_DELETE,
                STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirm->m_signalButtonClicked.connect(this, &VappPhbDelete::onButtonClicked);

    confirm->show(VFX_TRUE);
}


void VappPhbDelete::finishOP()
{
    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
    }

    VfxObject* self = this;
    VFX_OBJ_CLOSE(self);
}


void VappPhbDelete::onButtonClicked(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        ContactDelete *del;
        VFX_OBJ_CREATE_EX(del, ContactDelete, this, (m_id));

        if (del->prepare(CONTACT_DELETE, CONTACT_WANT) == CONTACT_RUN)
        {
            VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, m_parent);
            m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_progress->setText(STR_GLOBAL_DELETING);
            m_progress->show(VFX_TRUE);

            // delete the contact
            del->run();
            del->m_signalOP.connect(this, &VappPhbDelete::onDeleteDone);
        }
        else
        {
            finishOP();
        }
    }
    else
    {
        finishOP();
    }
}


void VappPhbDelete::onDeleteDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result)
{
    op->complete();

    finishOP();
}


/***************************************************************************** 
 * Class VappPhbCopySeveral
 *****************************************************************************/
VappPhbCopySeveral::VappPhbCopySeveral(phb_storage_enum storage, ContactMark *mark, VfxScreen *scr):
    m_storage(storage),
    m_mark(mark),
    m_parent(scr),
    m_progress(NULL),
    m_copy(NULL)
{
}


void VappPhbCopySeveral::onInit()
{
    VfxObject::onInit();

    copy();
}


void VappPhbCopySeveral::onDeinit()
{
    if (m_copy)
    {
        m_copy->cancel();
    }

    // operation done
    m_signalDone.postEmit();

    VfxObject::onDeinit();
}


void VappPhbCopySeveral::finishOP()
{
    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
        m_progress = NULL;
    }

    m_copy = NULL;

    VfxObject* self = this;
    VFX_OBJ_CLOSE(self);
}


void VappPhbCopySeveral::copy()
{
    VfxU32 count = m_mark->getCount();
    if (count == 0)
    {
        finishOP();
        return;
    }

    mmi_phb_contact_id *idArray;
    VFX_ALLOC_MEM(idArray, sizeof(mmi_phb_contact_id) * count, this);
    for (VfxU32 i = 0; i < count; i++)
    {
        idArray[i] = m_mark->getMarkKey(i).m_id;
    }

    VFX_OBJ_CREATE_EX(m_copy, ContactCopySeveral, this, (count, idArray, m_storage));

    if (m_copy->prepare(CONTACT_COPY, CONTACT_WANT) == CONTACT_RUN)
    {
        // show progress bar
        VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, m_parent);

        VfxWString text = (m_storage == PHB_STORAGE_NVRAM) ? STR_ID_VAPP_PHB_IMPORTING : STR_ID_VAPP_PHB_EXPORTING;
        text += VfxWString().format("0/%d", count);
        text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);

        m_progress->setText(text);
        m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
        m_progress->setProgress(0);
        m_progress->show(VFX_TRUE);

        m_progress->m_signalCanceled.connect(this, &VappPhbCopySeveral::onCancelClicked);
        m_progress->m_signalButtonClicked.connect(this, &VappPhbCopySeveral::onProgressClicked);

        // copy the contact
        m_copy->run();
        m_copy->m_signalOP.connect(this, &VappPhbCopySeveral::onCopyDone);

        VFX_FREE_MEM(idArray);
    }
    else
    {
        VFX_FREE_MEM(idArray);
        finishOP();
    }
}


void VappPhbCopySeveral::onProgressClicked(VfxObject* obj, VfxId id)
{
    if (id == VCP_POPUP_BUTTON_NO_PRESSED || id == VCP_CONFIRM_POPUP_BUTTON_CANCEL)
    {
        m_copy->cancel();
        finishOP();
    }
}


void VappPhbCopySeveral::onCancelClicked(VfxObject *obj, VfxFloat progress)
{
    m_copy->cancel();
    finishOP();
}


void VappPhbCopySeveral::onCopyDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result)
{
    if (result->type == SRV_PHB_OP_CB_TYPE_MULTI_COPY)
    {
        srv_phb_multi_copy_cb_struct *copyDone = (srv_phb_multi_copy_cb_struct *) result;
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_MULTI_COPY_DONE, copyDone->type, copyDone->finish_count,
                    copyDone->fail_count, copyDone->total_count, copyDone->user_data, copyDone->result);

        op->complete();
        finishOP();

        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

        srv_phb_multi_copy_cb_struct* evt = (srv_phb_multi_copy_cb_struct*) result;
        if (evt->fail_count > 0)
        {
            STORAGE_STATUS status = ContactStorage::getStatus(m_storage);
            if (status == STORAGE_FULL)
            {
                VfxWString errorStr = ContactStorage::getName(m_storage);
                errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_FULL);
                VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, errorStr);
            }
        }
    }
    else if (result->type == SRV_PHB_OP_CB_TYPE_UPDATE_STATUS)
    {
        srv_phb_multi_op_status_cb_struct* evt = (srv_phb_multi_op_status_cb_struct*) result;
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_MULTI_COPY_CB, evt->type, evt->finish_count,
                    evt->fail_count, evt->total_count, evt->user_data);

        VfxFloat percentage = (VfxFloat)evt->finish_count / evt->total_count;

        VfxWString text = (m_storage == PHB_STORAGE_NVRAM) ? (STR_ID_VAPP_PHB_IMPORTING) : (STR_ID_VAPP_PHB_EXPORTING);
        text += VfxWString().format("%d/%d", evt->finish_count, evt->total_count);
        text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);

        m_progress->setText(text);
        m_progress->setProgress(percentage);
    }
}


void VappPhbCopySeveral::cancel()
{
    m_copy->cancel();
}


/***************************************************************************** 
 * Class VappPhbDeleteSeveral
 *****************************************************************************/
VappPhbDeleteSeveral::VappPhbDeleteSeveral(ContactMark *mark, VfxScreen *scr):
    m_mark(mark),
    m_parent(scr),
    m_progress(NULL),
    m_delete(NULL)
{
}


void VappPhbDeleteSeveral::onInit()
{
    VfxObject::onInit();

    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, m_parent);

    VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_DELETE_SELECTED);
    if (m_mark->getCount() == 1)
    {
        text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACT_APPEND);
    }
    else
    {
        text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);
    }

    text += VFX_WSTR_RES(STR_ID_VAPP_PHB_LEFT_PARENTHESES);
    text += VfxWString().format("%d", m_mark->getCount());
    text += VFX_WSTR_RES(STR_ID_VAPP_PHB_RIGHT_PARENTHESES);
    text += VFX_WSTR_RES(STR_ID_VAPP_PHB_QUESTION);

    confirm->setText(text);
    confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirm->setCustomButton(
                STR_GLOBAL_DELETE,
                STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirm->m_signalButtonClicked.connect(this, &VappPhbDeleteSeveral::onButtonClicked);

    confirm->show(VFX_TRUE);
}


void VappPhbDeleteSeveral::onDeinit()
{
    if (m_delete)
    {
        m_delete->cancel();
    }

    // operation done
    m_signalDone.postEmit();

    VfxObject::onDeinit();
}


void VappPhbDeleteSeveral::finishOP()
{
    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
        m_progress = NULL;
    }

    m_delete = NULL;

    VfxObject* self = this;
    VFX_OBJ_CLOSE(self);
}


void VappPhbDeleteSeveral::onButtonClicked(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VfxU32 count = m_mark->getCount();
        if (count == 0)
        {
            finishOP();
            return;
        }

        mmi_phb_contact_id *idArray;
        VFX_ALLOC_MEM(idArray, sizeof(mmi_phb_contact_id) * count, this);
        for (VfxU32 i = 0; i < count; i++)
        {
            idArray[i] = m_mark->getMarkKey(i).m_id;
        }

        VFX_OBJ_CREATE_EX(m_delete, ContactDeleteSeveral, this, (count, idArray));

        if (m_delete->prepare(CONTACT_DELETE, CONTACT_WANT) == CONTACT_RUN)
        {
        #ifdef __MMI_SNS_CONTACTS__
            srv_sns_phb_start_multi_op();
        #endif

            // show progress bar
            VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, m_parent);

            VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_DELETING);
            text += VfxWString().format("0/%d", count);
            text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);

            m_progress->setText(text);
            m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
            m_progress->setProgress(0);
            m_progress->show(VFX_TRUE);

            m_progress->m_signalCanceled.connect(this, &VappPhbDeleteSeveral::onCancelClicked);
            m_progress->m_signalButtonClicked.connect(this, &VappPhbDeleteSeveral::onProgressClicked);

            // delete the contact
            m_delete->run();
            m_delete->m_signalOP.connect(this, &VappPhbDeleteSeveral::onDeleteDone);

            VFX_FREE_MEM(idArray);
        }
        else
        {
            VFX_FREE_MEM(idArray);
            finishOP();
        }
    }
}


void VappPhbDeleteSeveral::onProgressClicked(VfxObject* obj, VfxId id)
{
    if (id == VCP_POPUP_BUTTON_NO_PRESSED || id == VCP_CONFIRM_POPUP_BUTTON_CANCEL)
    {
        m_delete->cancel();
        finishOP();
    }
}


void VappPhbDeleteSeveral::onCancelClicked(VfxObject *obj, VfxFloat progress)
{
    m_delete->cancel();
    finishOP();
}


void VappPhbDeleteSeveral::onDeleteDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result)
{
    if (result->type == SRV_PHB_OP_CB_TYPE_MULTI_DELETE)
    {
        srv_phb_multi_delete_cb_struct *deleteDone = (srv_phb_multi_delete_cb_struct *) result;
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_MULTI_DELETE_DONE, deleteDone->type, deleteDone->finish_count,
                    deleteDone->fail_count, deleteDone->total_count, deleteDone->user_data, deleteDone->result);

        op->complete();
        finishOP();

        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }
    else if (result->type == SRV_PHB_OP_CB_TYPE_UPDATE_STATUS)
    {
        srv_phb_multi_op_status_cb_struct* evt = (srv_phb_multi_op_status_cb_struct*) result;
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_MULTI_DELETE_CB, evt->type, evt->finish_count,
                    evt->fail_count, evt->total_count, evt->user_data);

        VfxFloat percentage = (VfxFloat)evt->finish_count / evt->total_count;

        VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_DELETING);
        text += VfxWString().format("%d/%d", evt->finish_count, evt->total_count);
        text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);

        m_progress->setText(text);
        m_progress->setProgress(percentage);
    }
}


void VappPhbDeleteSeveral::cancel()
{
    m_delete->cancel();
}

