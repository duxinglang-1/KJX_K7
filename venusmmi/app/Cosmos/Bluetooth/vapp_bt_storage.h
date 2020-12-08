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
 *  vapp_bt_storage.h
 *
 * Project:
 * --------
 *  Cosmos
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BT_STORAGE_H__
#define __VAPP_BT_STORAGE_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C" {
#include "FileMgrType.h"
#include "FileMgrSrvGprot.h"
}
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vsrv_ncenter.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define TEMP_FOLDER     (VfxWChar *)L"@BTRecv\\"
#define DEFAULT_NAME    (VfxWChar *)L"BtRecv.obj"
#define DEFAULT_FOLDER  (VfxWChar *)FMGR_DEFAULT_FOLDER_RECEIVED
#define MIN_EXT_LEN     (6)
#define MAX_PATH_LEN    (259)
#define MAX_DUP_TIME    (511)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
enum VbtRecvResult {
    VBT_RECV_SUCC,
    VBT_RECV_FAIL,
    VBT_RECV_PENDING,
    VBT_RECV_USER_ABORT,
    VBT_RECV_MEMORY_FULL,
    VBT_RECV_MSDC_MISSED,
    VBT_RECV_BLOCKED
};

enum VbtRecvOption {
    VBT_RECV_OPT_BKGOUND = 0x01,   // Background receiving, this option is for future reserved.
    VBT_RECV_OPT_KEEP_NAME = 0x02  // Keep original name and avoid being truncated after stored.
};

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VbtStoragePage : public VfxPage, public IVcpListMenuContentProvider
{
 //  VFX_DECLARE_CLASS(VbtStoragePage);

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    void onListItemTabbed(VcpListMenu *list, VfxU32 index);
    
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color);
    virtual VfxBool getItemIsDisabled(VfxU32 index) const;
    static VbtStoragePage *getInstance()
    {
        return m_selfInstance;
    }
    mmi_ret invokeProc(mmi_event_struct *evt);

protected:
    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    SRV_FMGR_DRVLIST_HANDLE m_driveList;
    VcpListMenu *m_list;
    static VbtStoragePage *m_selfInstance;
};

class VbtStorage;

class VbtStorageSetting : public VfxBase
{

public:
    static void onInit(void *param);
    static void set(VfxChar drive);
    static VbtStorage & get();

private:
    static VbtStorage m_storage;
};

class VbtReceiver;

class VbtObject : public VfxBase
{
public:
    VbtObject() :
        m_name(NULL),
        m_size(0),
        m_type(NULL)
    {}
    VbtObject(VfxWChar *name, VfxU32 size = 0, VfxChar *type = NULL) : 
        m_name(name), 
        m_size(size),
        m_type(type) 
    {}

public:
    VfxWChar *m_name;
    VfxU32    m_size;
    VfxChar *m_type;
};

class VbtStorage : public VfxBase
{
public:
    VbtStorage() :
        m_drive(0),
        m_folder(NULL)
    {}
    VbtStorage(VfxChar drive, VfxWChar *folder = NULL) :
        m_drive(drive), 
        m_folder(folder)
    {}
public:
    VfxChar   m_drive;
    VfxWChar *m_folder;
};

class VbtRecvAgent : public VfxBase
{
    friend class VbtReceiver;
public:
    VbtRecvAgent() :
        m_storage(0, DEFAULT_FOLDER),
        m_result(VBT_RECV_SUCC)
    {}
public:
    void setObject(VfxWChar *name, VfxU32 size = 0, VfxChar *type = NULL);
    void setStorage(VfxChar drive, VfxWChar *folder = NULL);

    VbtReceiver * start(VfxObject *parent, VfxU32 option = 0);
    VbtRecvResult getResult() const
    {
        return m_result;
    }
    static void onInit(void *param);
    static void enable();
    static void disable();
    static VfxBool isOngoing();
    static VfxBool isDisabled();
private:
    VbtObject       m_object;
    VbtStorage      m_storage;
    VbtRecvResult   m_result;
    static VfxBool  m_disable;
    static VfxU32   m_instCount;
	
};

class VbtRecvStorage : public VfxBase
{
    friend class VbtRecvObject;
public:
    VbtRecvStorage() :
        m_drive(0),
        m_hidden(VFX_FALSE),            
        m_folder(VFX_WSTR_MEM(NULL)),
        m_path(VFX_WSTR_MEM(NULL))
    {}
    VbtRecvStorage(VfxChar drive, const VfxWChar *folder = NULL, VfxBool hidden = VFX_FALSE);

public:    
    VbtRecvResult create();
    const VfxWString &getPath() const
    {
        return m_path;
    }

private:
    VfxChar m_drive;
    VfxBool m_hidden;
    VfxWString m_folder;
    VfxWString m_path;
};

class VbtObjectName
{
public:
    VbtObjectName() :
        m_name(VFX_WSTR_MEM(NULL)),
        m_fixed(VFX_FALSE),
        m_truncate(VFX_FALSE),
        m_dupSeq(0)
    {}
    VbtObjectName(const VfxWChar *name, VfxBool temp, VfxBool fixed);

public:
    void truncate(VfxU32 maxLength);
    VfxBool duplicate();
    
    VfxBool valid(const VfxWChar *name) const;
    operator const VfxWChar *() const
    {
        return m_name.getBuf();
    }

private:
    VfxWString m_name;
    VfxBool m_fixed;
    VfxBool m_truncate;
    VfxU16  m_dupSeq;  
};

class VbtRecvObject : public VfxObject
{
 //   VFX_DECLARE_CLASS(VbtRecvObject);

public:
    VbtRecvObject() :
        m_size(0),
        m_type(NULL),
        m_path(VFX_WSTR_MEM(NULL))
    {}
    VbtRecvObject(const VbtRecvStorage &storage);
    virtual ~VbtRecvObject();

public:    
    void setInfo(const VbtObject &obj);
    void setName(const VfxWChar *name, VfxBool temp = VFX_FALSE, VfxBool fixed = VFX_FALSE);

    VfxChar getDrive() const
    {
        return m_storage.m_drive;
    }

    void release();
    VbtRecvResult finalize(VbtRecvObject &newObj);
    VbtRecvResult remapResult(VfxS32 retval);
    VfxBool update();
    const VfxWChar * getPath();

private:

private:
    VbtRecvStorage m_storage;
    VbtObjectName m_name;
    VfxU32 m_size;
    VfxChar * m_type;
    VfxWString m_path;
};

class VbtReceiver : public VfxObject
{
    friend class VbtRecvAgent;
//    VFX_DECLARE_CLASS(VbtReceiver);

public:
    VbtReceiver() : 
        m_tempObject(NULL), 
        m_finalObject(NULL),
        m_option(0)
        {}

public:
    void abort(VfxS32 reason = VBT_RECV_USER_ABORT);
    VbtRecvResult stop();
    const VfxWChar *getPath();
    void showResult(VfxS32 result);
    void updateNCenter();

/*---------------------------------------------------------------------------*
 * Function: notifyEventCallback()
 * Date:Mar/23/2012
 * Description: NCenter2.0 cell clicked callback function.
 *    
 * Parameters
 *    @noti: 
 *    @intent: 
 *    @userData: 
 *    @userDataSize: 
 *---------------------------------------------------------------------------*/
	static void notifyEventCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);

	static VfxS32 m_localRecvCount;
	static VfxS32 m_externalRecvCount;

public:
    VfxSignal2 <VfxObject*, VfxS32> m_signalBegin;
    VfxSignal2 <VfxObject*, VfxS32> m_signalEnd;

private:
    VbtRecvObject *m_tempObject;
    VbtRecvObject *m_finalObject;
    VfxU32 m_option;
};

class VbtFmgrLauncher : public VfxApp
{
    VFX_DECLARE_CLASS(VbtFmgrLauncher);
    
protected:
    virtual void onRun(void *args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    
public:
    static mmi_id m_appID;
};

#endif // __VAPP_BT_STORAGE_H__


