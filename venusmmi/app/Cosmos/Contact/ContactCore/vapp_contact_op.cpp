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
 *  vapp_contact_op.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "vapp_contact_task.h"
#include "vapp_contact_op.h"
#include "vapp_contact_storage.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class ContactOP
 *****************************************************************************/
void ContactOP::onDeinit()
{
    if (m_handle)
    {
        ContactTask *task = GET_CONTACT_TASK();
        task->task(m_task, CONTACT_FINISH, this);

        srv_phb_free_handle(m_handle);
        m_handle = NULL;
    }

    VfxObject::onDeinit();
}


CONTACT_STATE ContactOP::prepare(CONTACT_TASK task, CONTACT_STATE state)
{
    VFX_ASSERT(state == CONTACT_WANT);

    m_task = task;

    ContactTask *contactTask = GET_CONTACT_TASK();
    return contactTask->task(task, state, this);
}


void ContactOP::complete()
{
    ContactTask *task = GET_CONTACT_TASK();
    task->task(m_task, CONTACT_FINISH, this);

    // free handle
    if (m_handle)
    {
        srv_phb_free_handle(m_handle);
        m_handle = NULL;
    }
}


CONTACT_STATE ContactOP::onStateChanged(CONTACT_STATE state)
{
    if (state == CONTACT_FINISH || state == CONTACT_WAITING)
    {
        complete();
    }

    return CONTACT_FINISH;
}


/***************************************************************************** 
 * Class ContactAdd
 *****************************************************************************/
void ContactAdd::run()
{
    m_contactInstance = srv_phb_create_contact(NULL);
    m_contact->buildSrvContact(m_contactInstance, VFX_TRUE);

    srv_phb_add_req_struct req;
    req.record_index = MMI_PHB_INVALID_CONTACT_ID;
    req.storage = m_contact->getStorage();
    req.cb = ContactOP::handler;
    req.contact = m_contactInstance;
    req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
    req.user_data = this;

    m_handle = srv_phb_add_contact(&req);
}


void ContactAdd::complete()
{
    srv_phb_free_contact(m_contactInstance);

    ContactOP::complete();
}


/***************************************************************************** 
 * Class ContactEdit
 *****************************************************************************/
void ContactEdit::run()
{
    m_contactInstance = srv_phb_create_contact(NULL);
    m_contact->buildSrvContact(m_contactInstance, VFX_FALSE);

    srv_phb_update_req_struct req;
    req.id = m_contact->getId();
    req.cb = ContactOP::handler;
    req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
    req.contact = m_contactInstance;
    req.update_field = MMI_PHB_CONTACT_FIELD_ALL;
    req.user_data = this;

    m_handle = srv_phb_update_contact(&req);
}


void ContactEdit::complete()
{
    srv_phb_free_contact(m_contactInstance);

    ContactOP::complete();
}


/***************************************************************************** 
 * Class ContactCopy
 *****************************************************************************/
void ContactCopy::run()
{
    srv_phb_copy_req_struct req;
    req.id = m_id;
    req.dest_storage = m_storage;
    req.cb = ContactOP::handler;
    req.user_data = this;

    m_handle = srv_phb_copy_contact(&req);
}


/***************************************************************************** 
 * Class ContactDelete
 *****************************************************************************/
void ContactDelete::run()
{
    srv_phb_delete_req_struct req;
    req.id = m_id;
    req.cb = ContactOP::handler;
    req.user_data = this;

    m_handle = srv_phb_delete_contact(&req);
}


/***************************************************************************** 
 * Class ContactCopyAll
 *****************************************************************************/
void ContactCopyAll::run()
{
    srv_phb_copy_all_req_struct req;
    req.src_storage = m_srcStorage;
    req.dest_storage = m_desStorage;
    req.cb = ContactOP::handler;
    req.user_data = this;

    m_handle = srv_phb_copy_all_contact(&req);
}


/***************************************************************************** 
 * Class ContactDeleteAll
 *****************************************************************************/
void ContactDeleteAll::run()
{
    srv_phb_delete_all_req_struct req;
    req.storage = m_storage;
    req.cb = ContactOP::handler;
    req.user_data = this;

    m_handle = srv_phb_delete_all_contact(&req);
}


/***************************************************************************** 
 * Class ContactCopySeveral
 *****************************************************************************/
void ContactCopySeveral::run()
{
    srv_phb_multi_copy_req_struct req;
    req.contact_count = m_count;
    req.id_array = m_idArray;
    req.dest_storage = m_desStorage;
    req.cb = ContactOP::handler;
    req.user_data = this;

    m_handle = srv_phb_multi_copy_contact(&req);
}


void ContactCopySeveral::cancel()
{
    complete();
}


/***************************************************************************** 
 * Class ContactDeleteSeveral
 *****************************************************************************/
void ContactDeleteSeveral::run()
{
    srv_phb_multi_delete_req_struct req;
    req.contact_count = m_count;
    req.id_array = m_idArray;
    req.cb = ContactOP::handler;
    req.user_data = this;

    m_handle = srv_phb_multi_delete_contact(&req);
}


void ContactDeleteSeveral::cancel()
{
    complete();
}


#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
/***************************************************************************** 
 * Class ContactBackUp
 *****************************************************************************/
ContactBackUp::ContactBackUp()
{
#ifdef __VCARD_CLOUD_SUPPORT__
    m_mallocFunc = NULL;
    m_freeFunc = NULL;
#endif /* __VCARD_CLOUD_SUPPORT__ */
}


void ContactBackUp::run()
{
    srv_phb_backup_req_struct req;
    req.storage = PHB_STORAGE_NVRAM;
#ifdef __VCARD_CLOUD_SUPPORT__
    if (SRV_PHB_BACKUP_RESTORE_MODE_T_CARD == m_mode)
    {
        mmi_wcsncpy(req.path, m_path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
    }
#else
    mmi_wcsncpy(req.path, m_path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
#endif /* __VCARD_CLOUD_SUPPORT__ */

    req.cb = ContactOP::handler;
    req.user_data = this;
#ifdef __VCARD_CLOUD_SUPPORT__
    req.mode = m_mode;
    req.provider = m_providerId;
    req.account = m_accountId;
    req.malloc_func = m_mallocFunc;
    req.free_func = m_freeFunc;
#endif /* __VCARD_CLOUD_SUPPORT__ */

    m_handle = srv_phb_backup_contact(&req);
}


/***************************************************************************** 
 * Class ContactRestore
 *****************************************************************************/
ContactRestore::ContactRestore()
{
#ifdef __VCARD_CLOUD_SUPPORT__
    m_mallocFunc = NULL;
    m_freeFunc = NULL;
#endif /* __VCARD_CLOUD_SUPPORT__ */
}


void ContactRestore::run()
{
    srv_phb_restore_req_struct req;
#ifdef __VCARD_CLOUD_SUPPORT__
    if (SRV_PHB_BACKUP_RESTORE_MODE_T_CARD == m_mode)
    {
        mmi_wcsncpy(req.path, m_path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
    }
#else
    mmi_wcsncpy(req.path, m_path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
#endif /* __VCARD_CLOUD_SUPPORT__ */
    req.cb = ContactOP::handler;
    req.user_data = this;
#ifdef __VCARD_CLOUD_SUPPORT__
    req.mode = m_mode;
    req.provider = m_providerId;
    req.account = m_accountId;
    req.malloc_func = m_mallocFunc;
    req.free_func = m_freeFunc;
#endif /* __VCARD_CLOUD_SUPPORT__ */

    m_handle = srv_phb_restore_contact(&req);
}
#endif /* defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */

