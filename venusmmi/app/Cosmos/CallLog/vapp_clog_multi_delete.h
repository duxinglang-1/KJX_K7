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
 *  vapp_clog_multi_delete.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifndef __VAPP_CLOG_MULTI_DELETE_H__
#define __VAPP_CLOG_MULTI_DELETE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_include.h"

#include "vapp_clog_data_provider.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/



/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Predefine Classes
class VappCLogList;

typedef enum
{
	CLOG_MULTI_CMD_SELECT,
	CLOG_MULTI_CMD_DELETE,
	CLOG_MULTI_CMD_CANCEL,
	CLOG_MULTI_CMD_TYPE_TOTAL
} VappCLogMultiCmdTypeEnum;
	
typedef enum
{
	VAPP_CLOG_MARK_CMD_NONE,
	VAPP_CLOG_MARK_CMD_DELETE,
	VAPP_CLOG_MARK_CMD_TYPE_TOTAL
} VappCLogMarkCmdTypeEnum;


/***************************************************************************** 
 * Class CLogMark
 *****************************************************************************/
class CLogMark : public VfxObject
{
public:
    // default constructor
    CLogMark(VfxId listId):
        m_listId(listId),
        m_clogDataSrv(NULL)
    {}

public:
    void setDataProvider(VappCLogDataProvider *clogDataSrv)
    {
        m_clogDataSrv = clogDataSrv;
    }
    
    void setMark(VfxU32 index)
    {
        VfxU32 id = m_clogDataSrv->getClogIDByIdx(index);

		VfxU32 slot_index = findFirstSlot();
        m_logIDs[slot_index] = id;
    }

	// reset mark
    void resetMark(VfxU32 index)
	{
	    VfxU32 i = find(index);

        if (m_logIDs[i])
        {
            m_logIDs[i] = 0;
        }
	}
	
	VfxBool checkMark(VfxU32 index)
    {
        VfxU32 return_index = find(index);
		if (return_index != SRV_CLOG_LOG_MAX_NUM)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }

    void changeMark(VfxU32 index)
    {
	    if (checkMark(index))
	    {
		    resetMark(index);
	    }
	    else
	    {
		    setMark(index);
	    }
    }
    
    void markAll()
    {
        unMarkAll();

        VfxU32 i = 0;
        for(i = 0; i < m_clogDataSrv->getClogCount(m_listId); i++)
        {
		    VfxU32 id = m_clogDataSrv->getClogIDByIdx(i);
            m_logIDs[i] = id;
        }
    }

    void unMarkAll()
    {
	    memset(m_logIDs, 0, SRV_CLOG_LOG_MAX_NUM * sizeof(SRV_CLOG_ID));

    }

    VfxBool checkMarkAll()
    {
        // efficiency
        if (getCount() < m_clogDataSrv->getClogCount(m_listId))
        {
            return VFX_FALSE;
        }
        else
        {
            return VFX_TRUE;
        }  
    }

    VfxU32 getCount()
    {
        VfxU32 i, marked_count = 0;

        for (i = 0; i < m_clogDataSrv->getClogCount(m_listId); i++)
        {
            if (checkMark(i))
                marked_count++;
        }

        return marked_count;
    }

    VfxU32 getClogCount()
    {
        VfxU32 count;
        count = m_clogDataSrv->getClogCount(m_listId);
        return count;
    }
    
    SRV_CLOG_ID getClogIDByIdx(VfxU32 index)
    {
        return m_clogDataSrv->getClogIDByIdx(index);
    }

protected:
    virtual void onInit()
    {
        VfxObject::onInit();

		memset(m_logIDs, 0, SRV_CLOG_LOG_MAX_NUM * sizeof(SRV_CLOG_ID));
    }

    virtual void onDeinit()
    {
        VfxObject::onDeinit();
		memset(m_logIDs, 0, SRV_CLOG_LOG_MAX_NUM * sizeof(SRV_CLOG_ID));
    }

private:
    // Use list item index to find  
    // the index in m_logIDs[]
	VfxU32 find(VfxU32 index)
	{
	    VfxU32 i;

        VfxU32 id = m_clogDataSrv->getClogIDByIdx(index);

        for (i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
        {
            if(m_logIDs[i] == id)
				return i;
        }	

        return SRV_CLOG_LOG_MAX_NUM;
	}

    VfxU32 findFirstSlot()
    {
        VfxU32 i = 0;

		while (m_logIDs[i])
		{
		    i++;
		}

		return i;
	}
	
private:
    VfxId                   m_listId;
    VappCLogDataProvider    *m_clogDataSrv;
	SRV_CLOG_ID             m_logIDs[SRV_CLOG_LOG_MAX_NUM];
};


/***************************************************************************** 
 * Class VappClogMultiDeleteObj
 *****************************************************************************/ 
class VappClogMultiDeleteObj : public VfxObject
{
    VFX_DECLARE_CLASS(VappClogMultiDeleteObj);

public:
    VappClogMultiDeleteObj(VappCLogList* list, VfxPage *page);

    void onToolBarClick(VfxObject* obj, VfxId id);

    void deleteDone();

    void closeSelf();

    void onStateChanged(
            VcpListMenu *list,
            VfxU32 index,
            VcpListMenuItemStateEnum state);

	void onListUpdated();

protected:
    virtual void onInit();

private:
    VfxPage         *m_page;
    VappCLogList    *m_list;
    VcpToolBar      *m_tool;
    CLogMark        *m_mark;

private:
    VappClogMultiDeleteObj(){}

    void configToolBar();
};


/***************************************************************************** 
 * Class VappClogDeleteSeveral
 *****************************************************************************/ 
class VappClogDeleteSeveral: public VfxObject
{
    VFX_DECLARE_CLASS(VappClogDeleteSeveral);

public:
    VappClogDeleteSeveral(CLogMark *mark, VfxScreen *scr);

    void closeSlef();

    void onButtonClicked(VfxObject* obj, VfxId id);

    VfxU32 multiDeleteClog(SRV_CLOG_BASE_CB cbk);
    
    static VfxS32 onMultiDeleteCbk(SRV_CLOG_HANDLE handle, S32 pid,
                                void *req_data, void *cnf_data, MMI_BOOL more, srv_clog_ret_enum ret);

    VfxSignal0 m_signalDone;

protected:
    virtual void onInit();

    virtual void onDeinit();

private:
    VappClogDeleteSeveral(){}

private:
    CLogMark            *m_mark;
    VfxScreen           *m_parent;
};


#endif /* __VAPP_CLOG_MULTI_DELETE_H__ */

