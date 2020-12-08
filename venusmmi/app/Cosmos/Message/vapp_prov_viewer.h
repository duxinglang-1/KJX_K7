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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH¡ä?
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
 *  vapp_prov_viewer.h
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
 
#ifndef __VCP_PROV_VIEWER_H__
#define __VCP_PROV_VIEWER_H__
 
#include "ui_core\base\vfx_base.h"
#include "ui_core\pme\vfx_pme.h"
#include "vcp_include.h"
#include "vapp_msg_viewer.h"
#include "vapp_msg_contact_bar.h"

#ifdef __MMI_PROV_IN_UM__ 

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C"
#endif
{
#include "MMI_include.h"

#include "DateTimeGprot.h"

#include "wgui_categories_util.h"

#include "ProvBoxSrvGProt.h"

#include "Vapp_prov_util.h"
}

class VappProvMsgDataOp;

/*----------------------------------------------------------------------------*/
/* Extern Function Declaration                                                */
/*----------------------------------------------------------------------------*/
//extern vapp_prov_box_cntx_struct* vapp_prov_get_cntx(void);

extern void vapp_prov_install_ext(
                VfxU32 msg_id, 
                VAPP_PROV_CB_FUNC_P cb_func, 
                void* user_data, VfxS32 gid);

/*****************************************************************************
 * Class VappOperateCell
 *****************************************************************************/
class VappOperateCell
{
public:
    VappOperateCell() {}
    
    virtual ~VappOperateCell() {}
    
public:
    static VfxBool onGetCell(VappOperateCell **cell);
    static VfxBool onResetCell(void);
    static VfxBool onSetCell(VfxU32 msg_id, void * op_obj, VAPP_PROV_CB_FUNC_P cb_func);
    
public:
    static VfxU32 m_msgId;
    static void*  m_userData;
    static VAPP_PROV_CB_FUNC_P m_pCbFunc;
};

/*****************************************************************************
 * Class VappOperateCell end
 *****************************************************************************/


/*****************************************************************************
 * class VappProvViewerCp
 *****************************************************************************/
class VappProvViewerCp : public VappMsgViewerCp
{
    friend class VappProvDetailPage;
    // Constructor
public:
    VappProvViewerCp(VfxU32 type = VAPP_MSG_VIEWER_LITE, VfxU32 msgId = 0, VfxU32 msgType = 0);

    // Property
    // Method
    virtual void forceUpdate();
    virtual VfxU32 getTimestamp();
   
protected:
    //Overridable
    virtual void onInit();
    virtual void onDeinit();
          
private:
    void setInstallBtn();
    void setMsgTitleSizeTime(srv_provbox_msg_properties_struct *detail);
    void getMsgProperties();
    void RecvMsgPorperties(srv_provbox_msg_properties_struct* details);

    void onInstallMsg(VfxObject *obj, VfxId id);
    void onInstallMsgDone(VfxU32 result);

    void onNotifyReady(MMI_BOOL isRead);

    void onRefresh(VfxS32 frameWidth);

    /* common API to set text frame posation */
    void setTextShow(VfxTextFrame **text, 
        const VfxWString &value, 
        const VfxColor &color,
        const VfxFontDesc &fontDesc);
    
private:
    VfxU32 m_timeStamp;	
    VfxTextFrame *m_textMsgTime;
    VfxTextFrame *m_textMsgSize;
    VfxTextFrame *m_textMsgTitle;

    VappProvMsgDataOp * m_provMsgOp;

private:
   VfxSignal1<MMI_BOOL> m_syncNotify;
};

/*****************************************************************************
 * Class VappProvViewerCp end
 *****************************************************************************/


/*****************************************************************************
 * Class VappProvDetailPage
 *****************************************************************************/
#define VAPP_PROV_DETAIL_PAGE_UCS2_SPACE (L" ")


class VappProvDetailPage : public VfxPage
{

public:
// Constructor
    VappProvDetailPage(VfxU8 msgId = 16, VfxU32 msg_type = 1);
    
// Override
protected:
    virtual void onInit();
    virtual void onEntered();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
        //support all rotation
    }
    virtual void onRotate(const VfxScreenRotateParam & param);

private:
    void onTapToolBar(VfxObject* obj, VfxId barId);
    
    // Operate              
    void getMsgProperties();          
    void recvMsgProperties(srv_provbox_msg_properties_struct *detail);
    void deleteMsg(VfxObject * obj, VfxId barId);
    void intallDone(VfxU32 result);
    
private:
    VfxU32 m_msgType;
    VfxU8 m_msgId;
    
    VfxPoint m_origin;
    VappProvViewerCp *m_msgViewer;
    VappProvMsgDataOp *m_provMsgOp;
    VappMsgContactBar *m_msgContactBar;

private:
    enum
    {
        VAPP_PROV_MSG_BTN_INSTALL = 1,
        VAPP_PROV_MSG_BTN_DELETE,
        VAPP_PROV_MSG_BTN_TOTAL
    };
};
 
/*****************************************************************************
 * Class VappProvDetailPage end
 *****************************************************************************/
 
/*****************************************************************************
 * Class VappProvMsgDataOp
 *****************************************************************************/
class VappProvMsgDataOp : public VfxObject
{
    
    friend class VappProvDetailPage;
    friend class VappProvViewerCp;

public:
    /* constructer */
    VappProvMsgDataOp();

    /* operation */
    void    onRead(srv_provbox_msg_properties_struct *detail);
    VfxBool onDelete(VfxU32 msgId);
    void install(VfxU32 msgId);
    static U8 onInstallMsgHdlr(void *msg);

protected:
    virtual void onDeinit();
    
public:
    VfxSignal1<VfxU32> m_signalOp;
    
private:
    /* descripte the status. If MMI_TRUE, status is in operating.
       if MMI_FALSE, status is in Done. */
    VfxBool m_isOperating;
    VfxU32  m_msgId;
};
/*****************************************************************************
 * Class VappProvMsgDataOp end
 *****************************************************************************/
#endif /* __MMI_PROV_IN_UM__  */
#endif /*  __VCP_PROV_VIEWER_H__ */
