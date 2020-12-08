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
 *  vapp_contact_op.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __CONTACT_OP_H__
#define __CONTACT_OP_H__

#include "vfx_uc_include.h"

#include "vapp_contact_storage.h"
#include "vapp_contact_task.h"
#include "vapp_contact_entry.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"
#include "custom_phb_config.h"

#ifdef __VCARD_CLOUD_SUPPORT__
#include "CloudSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class ContactOP
 *****************************************************************************/ 
class ContactOP : public VfxObject, public ContactTaskInterface
{
public:
    // default constructor
    ContactOP():
        m_handle(NULL),
        m_task(CONTACT_NONE){}

    // prepare
    virtual CONTACT_STATE prepare(CONTACT_TASK task, CONTACT_STATE state);

    // do the operation
    virtual void run(){};

    // cancel the operation
    virtual void cancel(){};

    // finish the operation
    virtual void complete();

    // on state changed
    virtual CONTACT_STATE onStateChanged(CONTACT_STATE state);

protected:
    virtual void onDeinit();

public:
    VfxSignal3<ContactOP*, CONTACT_STATE, srv_phb_async_op_cb_struct*> m_signalOP;

protected:
    virtual void onProc(srv_phb_async_op_cb_struct *result)
    {
        ContactOP *op = (ContactOP*) result->user_data;
        m_signalOP.emit(op, CONTACT_FINISH, result);
    }

    static void handler(srv_phb_async_op_cb_struct *result)
    {
        ContactOP *op = (ContactOP*) result->user_data;
        op->onProc(result);
    }

protected:
    srv_phb_handle m_handle;
    CONTACT_TASK m_task;
};


/***************************************************************************** 
 * Class ContactAdd
 *****************************************************************************/ 
class ContactAdd : public ContactOP
{
public:
    ContactAdd(){}

    ContactAdd(Contact *contact):
        m_contact(contact),
        m_contactInstance(NULL){}

    virtual void run();

    virtual void complete();

private:
    Contact *m_contact;
    srv_phb_contact m_contactInstance;
};


/***************************************************************************** 
 * Class ContactEdit
 *****************************************************************************/ 
class ContactEdit : public ContactOP
{
public:
    ContactEdit(){}

    ContactEdit(Contact* contact):
        m_contact(contact),
        m_contactInstance(NULL){}

    virtual void run();

    virtual void complete();

private:
    Contact *m_contact;
    srv_phb_contact m_contactInstance;
};


/***************************************************************************** 
 * Class ContactCopy
 *****************************************************************************/ 
class ContactCopy : public ContactOP
{
public:
    ContactCopy(){}

    ContactCopy(mmi_phb_contact_id id, phb_storage_enum storage):
        m_id(id),
        m_storage(storage){}

    virtual void run();

private:
    mmi_phb_contact_id m_id;
    phb_storage_enum m_storage;
};


/***************************************************************************** 
 * Class ContactDelete
 *****************************************************************************/ 
class ContactDelete : public ContactOP
{
public:
    ContactDelete(){}

    ContactDelete(VfxU32 id):
        m_id(id){}

    virtual void run();

private:
    VfxU32 m_id;
};


/***************************************************************************** 
 * Class ContactCopyAll
 *****************************************************************************/ 
class ContactCopyAll : public ContactOP
{
public:
    ContactCopyAll(){}

    ContactCopyAll(phb_storage_enum src, phb_storage_enum des):
        m_srcStorage(src),
        m_desStorage(des){}

    virtual void run();

private:
    phb_storage_enum m_srcStorage;
    phb_storage_enum m_desStorage;
};


/***************************************************************************** 
 * Class ContactDeleteAll
 *****************************************************************************/ 
class ContactDeleteAll : public ContactOP
{
public:
    typedef void (*funcPtr)(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* cb);

    ContactDeleteAll(){}

    ContactDeleteAll(phb_storage_enum storage):
        m_storage(storage){}

    virtual void run();

    void setStorage(phb_storage_enum storage){m_storage = storage;}

    void setUserData(void *buf){m_userData = buf;}

    void *getUserData(){return m_userData;}

    void setCB(funcPtr cb){m_cb = cb;}

    virtual void onProc(srv_phb_async_op_cb_struct *result)
    {
        ContactDeleteAll *op = (ContactDeleteAll*) result->user_data;
        op->m_cb(op, CONTACT_FINISH, result);
    }

private:
    phb_storage_enum  m_storage;
    void             *m_userData;
    funcPtr           m_cb;
};


/***************************************************************************** 
 * Class ContactCopySeveral
 *****************************************************************************/ 
class ContactCopySeveral : public ContactOP
{
public:
    ContactCopySeveral(){}

    ContactCopySeveral(VfxU32 count, mmi_phb_contact_id *array, phb_storage_enum storage):
        m_count(count),
        m_idArray(array),
        m_desStorage(storage){}

    virtual void run();

    virtual void cancel();

private:
    VfxU32 m_count;
    mmi_phb_contact_id *m_idArray;
    phb_storage_enum m_desStorage;
};


/***************************************************************************** 
 * Class ContactDeleteSeveral
 *****************************************************************************/ 
class ContactDeleteSeveral : public ContactOP
{
public:
    ContactDeleteSeveral(){}

    ContactDeleteSeveral(VfxU32 count, mmi_phb_contact_id *array):
        m_count(count),
        m_idArray(array){}

    virtual void run();

    virtual void cancel();

private:
    VfxU32 m_count;
    mmi_phb_contact_id *m_idArray;
};


#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
/***************************************************************************** 
 * Class ContactBackUp
 *****************************************************************************/ 
class ContactBackUp : public ContactOP
{
public:
    typedef void (*funcPtr)(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* cb);

    ContactBackUp();

    ContactBackUp(VfxWString path) : m_path(path)
    {
    #ifdef __VCARD_CLOUD_SUPPORT__
        m_mode = SRV_PHB_BACKUP_RESTORE_MODE_T_CARD;
        m_mallocFunc = NULL;
        m_freeFunc = NULL;
    #endif
    }

    virtual void run();

    void setPath(const VfxWString &path){m_path = path;}

    void setUserData(void *buf){m_userData = buf;}

    void *getUserData(){return m_userData;}

    void setCB(funcPtr cb){m_cb = cb;}

#ifdef __VCARD_CLOUD_SUPPORT__
    void setMode(srv_phb_backup_restore_mode_enum mode){m_mode = mode;}

    void setProvideId(VfxU32 providerId){m_providerId = providerId;}

    void setAccountId(VfxU8 accountId){m_accountId = accountId;}

    void setMallocFunc(srv_cloud_mem_alloc mallocFunc){m_mallocFunc = mallocFunc;}

    void setFreeFunc(srv_cloud_mem_free freeFunc){m_freeFunc = freeFunc;}
#endif /* __VCARD_CLOUD_SUPPORT__ */

    virtual void onProc(srv_phb_async_op_cb_struct *result)
    {
        ContactBackUp *op = (ContactBackUp*) result->user_data;
        op->m_cb(op, CONTACT_FINISH, result);
    }

private:
    VfxWString  m_path;
    void       *m_userData;
    funcPtr     m_cb;
#ifdef __VCARD_CLOUD_SUPPORT__
    srv_phb_backup_restore_mode_enum m_mode;
    VfxU32 m_providerId;
    VfxU8 m_accountId;
    srv_cloud_mem_alloc m_mallocFunc;
    srv_cloud_mem_free m_freeFunc;
#endif /* __VCARD_CLOUD_SUPPORT__ */
};


/***************************************************************************** 
 * Class ContactRestore
 *****************************************************************************/ 
class ContactRestore : public ContactOP
{
public:
    typedef void (*funcPtr)(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* cb);

    ContactRestore();

    ContactRestore(VfxWString path) : m_path(path)
    {
    #ifdef __VCARD_CLOUD_SUPPORT__
        m_mode = SRV_PHB_BACKUP_RESTORE_MODE_T_CARD;
        m_mallocFunc = NULL;
        m_freeFunc = NULL;
    #endif
    }

    virtual void run();

    void setPath(const VfxWString &path){m_path = path;}

    void setUserData(void *buf){m_userData = buf;}

    void *getUserData(){return m_userData;}

    void setCB(funcPtr cb){m_cb = cb;}

#ifdef __VCARD_CLOUD_SUPPORT__
    void setMode(srv_phb_backup_restore_mode_enum mode){m_mode = mode;}

    void setProvideId(VfxU32 providerId){m_providerId = providerId;}

    void setAccountId(VfxU8 accountId){m_accountId = accountId;}
    
    void setMallocFunc(srv_cloud_mem_alloc mallocFunc){m_mallocFunc = mallocFunc;}

    void setFreeFunc(srv_cloud_mem_free freeFunc){m_freeFunc = freeFunc;}
#endif /* __VCARD_CLOUD_SUPPORT__ */

    virtual void onProc(srv_phb_async_op_cb_struct *result)
    {
        ContactRestore *op = (ContactRestore*) result->user_data;
        op->m_cb(op, CONTACT_FINISH, result);
    }

public:
    VfxU16      m_totalCount;

private:
    VfxWString  m_path;
    void       *m_userData;
    funcPtr     m_cb;
#ifdef __VCARD_CLOUD_SUPPORT__
    srv_phb_backup_restore_mode_enum m_mode;
    VfxU32 m_providerId;
    VfxU8 m_accountId;
    srv_cloud_mem_alloc m_mallocFunc;
    srv_cloud_mem_free m_freeFunc;
#endif /* __VCARD_CLOUD_SUPPORT__ */
};
#endif /* defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */

#endif /* __CONTACT_OP_H__ */

