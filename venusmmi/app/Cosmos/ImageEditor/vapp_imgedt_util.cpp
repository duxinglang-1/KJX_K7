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
 *  vapp_imgedt_def.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /***************************************************************************** 
  * Typedef
  *****************************************************************************/
extern "C" 
{
    #include "MMI_features.h" 
}

#if (defined(__MMI_COSMOS_PHOTOEDITOR__) || defined(__MMI_COSMOS_IMAGECLIPPER__))
#include "vapp_imgedt_util.h"
#include "mmi_rp_vapp_imgedt_def.h"
#include "mmi_rp_vcui_imgclip_def.h"
extern "C"
{
#include "kal_public_api.h"
#include "FileMgrSrvGprot.h"
#include "App_str.h"
}

/***************************************************************************** 
 * Class VcpImgEdtNamingHelper
 *****************************************************************************/
VfxWString VcpImgEdtNamingHelper::getOrgFileName(const VfxWString &strFullPath)
{
    VfxBool allowSuffix = VFX_TRUE;
    if (strFullPath.getLength() >= SRV_FMGR_PATH_MAX_LEN - 1)
    {
        allowSuffix = VFX_FALSE;
    }
      
    VfxWChar* pFullPath = (VfxWChar *)strFullPath.getBuf();
    VfxWChar* pName = getFileNamePos(pFullPath);
    
    VfxS32 str_len = vfx_sys_wcslen(pName);
    if (str_len >= SRV_FMGR_PATH_MAX_FILE_NAME_LEN)
    {
        allowSuffix = VFX_FALSE;
    }
  
    VfxWChar *pDes;
    VFX_ALLOC_MEM(pDes, (str_len + 1)*2, this);
    vfx_sys_wcscpy(pDes, pName);
  
    VfxWChar* pExt = getFileExtPos(pDes);
    if (NULL != pExt)
    {
        *pExt = 0;
    }
      
    if (allowSuffix)
    {
        mmi_ucs2cat((CHAR*)pDes, (CHAR*)(L"_1"));
    }    
    VfxWString name = VFX_WSTR_MEM(pDes);
    VFX_FREE_MEM(pDes);

    return name; 
}
  
VfxWString VcpImgEdtNamingHelper::getNewPathByName(const VfxWString &strOrgPath, const VfxWString &strNewName)
{
    VfxWChar* pFullPath = (VfxWChar *)strOrgPath.getBuf();
    VfxWChar* pOldName = getFileNamePos(pFullPath);
    VfxWChar* pNewName = (VfxWChar *)strNewName.getBuf();
    VfxWChar* pExt = getFileExtPos(pOldName);
  
    VfxS32 fullpath_len = vfx_sys_wcslen(pFullPath);
    VfxS32 old_name_len = vfx_sys_wcslen(pOldName);
    VfxS32 new_name_len = vfx_sys_wcslen(pNewName);
    VfxS32 ext_len = vfx_sys_wcslen(pExt);

    if ((app_ucs2_unconditional_strcmp((kal_int8*)pExt, (kal_int8*)L".jpg")) &&
        (app_ucs2_unconditional_strcmp((kal_int8*)pExt, (kal_int8*)L".jpeg")))
    {
        ext_len = 4;
        vfx_sys_wcsncpy((VfxWChar*)pExt, (VfxWChar*)L".jpg", 4);
    }
  
    VfxS32 new_path_len = fullpath_len - old_name_len + ext_len + new_name_len;
    if (new_path_len < SRV_FMGR_PATH_MAX_LEN)
    {
        new_path_len = SRV_FMGR_PATH_MAX_LEN;
    }
  
    VfxWChar *pNewFullPath;
    VFX_ALLOC_MEM(pNewFullPath, (new_path_len + 1)*2, this);
    vfx_sys_wcsncpy(pNewFullPath, pFullPath, new_path_len);
    pNewFullPath[fullpath_len - old_name_len] = 0;
    mmi_ucs2ncat((CHAR*)pNewFullPath, (CHAR*)pNewName, new_path_len);
    mmi_ucs2ncat((CHAR*)pNewFullPath, (CHAR*)pExt, new_path_len);
      
    VfxWString strNewPath = VFX_WSTR_MEM(pNewFullPath);
    VFX_FREE_MEM(pNewFullPath);

    return strNewPath;
}

VfxWString VcpImgEdtNamingHelper::autoGenNewPath(const VfxWString &strFullPath)
{
    VfxWChar* pFullPath = (VfxWChar *)strFullPath.getBuf();
    VfxWChar* pOldName = getFileNamePos(pFullPath);
    VfxWChar* pExt = getFileExtPos(pOldName);
  
    VfxS32 fullpath_len = vfx_sys_wcslen(pFullPath);
    VfxS32 old_name_len = vfx_sys_wcslen(pOldName);
    VfxS32 ext_len = vfx_sys_wcslen(pExt);    

    if ((app_ucs2_unconditional_strcmp((kal_int8*)pExt, (kal_int8*)L".jpg")) &&
        (app_ucs2_unconditional_strcmp((kal_int8*)pExt, (kal_int8*)L".jpeg")))
    {
        //ext_len = 4;
        vfx_sys_wcsncpy((VfxWChar*)pExt, (VfxWChar*)L".jpg", 4);
    }
  
    VfxS32 new_path_len = fullpath_len + 2;
  
    VfxWChar *pNewFullPath;
    VFX_ALLOC_MEM(pNewFullPath, (new_path_len + 1)*2, this);
    vfx_sys_wcscpy(pNewFullPath, pFullPath);
    pNewFullPath[fullpath_len - ext_len] = 0;
    mmi_ucs2cat((CHAR*)pNewFullPath, (CHAR*)L"_1");
    mmi_ucs2cat((CHAR*)pNewFullPath, (CHAR*)pExt);
      
    VfxWString strNewPath = VFX_WSTR_MEM(pNewFullPath);
    VFX_FREE_MEM(pNewFullPath);
    return strNewPath;
}
  
  
VfxWChar *VcpImgEdtNamingHelper::getFileNamePos(const VfxWChar *fullpath)
{
    VfxWChar* pName = (VfxWChar*)fullpath;
    VfxWChar* pTmp = (kal_uint16*)mmi_ucs2chr((const CHAR*)(pName+1), L':');

    if (NULL != pTmp)
    {
        pName = pTmp+1;
    }
    else
    {
        pTmp = pName;
    }    
    while((pTmp = (kal_uint16*)mmi_ucs2chr((const CHAR*)(pTmp+1), L'\\')) 
         != NULL )
    {
        pName = pTmp+1;
    }
    return pName;
  }
  
VfxWChar *VcpImgEdtNamingHelper::getFileExtPos(const VfxWChar *filename)
{
    VfxWChar* pTmp = (VfxWChar*)filename;
    VfxWChar* pExt = pTmp;
    while((pTmp = (kal_uint16*)mmi_ucs2chr((const CHAR*)pTmp, L'.')) != NULL )
    {
        pExt = pTmp;
        pTmp++;
    }   
    
    return pExt;
}

/***************************************************************************** 
 * Class VcpImgEdtPopup
 *****************************************************************************/
void VcpImgEdtPopup::popup(VcpConfirmPopup * popup, VfxResId strId, VcpPopupTypeEnum type)
{
    popup->setInfoType(type);
    popup->setText(VFX_WSTR_RES(strId));
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->show(VFX_TRUE);
}

void VcpImgEdtPopup::popupDone(VcpConfirmPopup *popup)
{
    VcpImgEdtPopup::popup(popup, STR_GLOBAL_DONE, VCP_POPUP_TYPE_SUCCESS);
}

void VcpImgEdtPopup::popupError(VcpConfirmPopup *popup, VfxResId strId)
{
    VcpImgEdtPopup::popup(popup, strId, VCP_POPUP_TYPE_FAILURE);
}

/***************************************************************************** 
 * Class VcpImgEdtClipWindow
 *****************************************************************************/
VcpImgEdtClipWindow::VcpImgEdtClipWindow():
m_resetResizeInfo(VFX_TRUE),
m_btnHL(NULL),    
m_clipRect(0,0,0,0),
m_state(STATE_IDLE),
m_isFixed(MMI_FALSE),
m_curRatioW(1),
m_curRatioH(1),
m_imgRect(0,0,0,0),
m_detectRect(0,0,0,0)
{}

void VcpImgEdtClipWindow::onInit()
{
    VfxFrame::onInit();
    
    createTransFrame();    
    createLineFrame();
    createConerBtn();
    createMiddleBtn();

    VFX_OBJ_CREATE(m_btnHL, VfxFrame, this);
    m_btnHL->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BUTTON_HALO));
    m_btnHL->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_btnHL->setAnchor(0.5f, 0.5f);
    m_btnHL->setHidden(VFX_TRUE);
}

void VcpImgEdtClipWindow::setImgRect(VfxRect rect)
{
    m_imgRect = rect;
    updateLayout();
}

void VcpImgEdtClipWindow::setRatioFixed(VfxBool bFixed)
{
    m_isFixed = bFixed;
    updateLayout();
}

void VcpImgEdtClipWindow::setRatio(VfxS32 ratioW, VfxS32 ratioH)
{
    m_curRatioW = ratioW;
    m_curRatioH = ratioH;
    if (m_isFixed)
    {
        updateLayout();
    }   
}

void VcpImgEdtClipWindow::changeRatio(VfxS32 ratioW, VfxS32 ratioH, VfxBool bFixed)
{
    m_isFixed = bFixed;
    m_curRatioW = ratioW;
    m_curRatioH = ratioH;
    VfxSize size = m_initSize;
    if (m_curRatioW >= m_curRatioH)
    {
        VfxFloat ratio = (VfxFloat)m_curRatioW/(VfxFloat)m_curRatioH;
        size.width = m_initSize.height * ratio;
    }
    else
    {
        VfxFloat ratio = (VfxFloat)m_curRatioH/(VfxFloat)m_curRatioW;
        size.height = m_initSize.width * ratio;
    }
    m_clipRect = VfxRect((getBounds().getWidth() - size.width)/2, 
                         (getBounds().getHeight() - size.height)/2, 
                         size.width, 
                         size.height);    
    updateLayout();
}

void VcpImgEdtClipWindow::setDetectRect(VfxRect &rect)
{
    m_detectRect = rect;
}

void VcpImgEdtClipWindow::getClipRect(VfxRect *rect)
{
    *rect = m_clipRect;
}

void VcpImgEdtClipWindow::setFreeze(VfxBool is_freeze)
{
    m_isFreeze = is_freeze;
}

void VcpImgEdtClipWindow::show()
{
    if (0 == m_curRatioW)
    {
        m_curRatioW = m_initSize.width;
        m_curRatioH = m_initSize.height;
        if (m_imgRect.getWidth() > IMGEDT_CLIP_MIN_LENGHTH*2)
        {
            m_initSize.width = m_imgRect.getWidth()>>1;
        }
        else
        {
            m_initSize.width = IMGEDT_CLIP_MIN_LENGHTH;
        }
        if (m_imgRect.getHeight() > IMGEDT_CLIP_MIN_LENGHTH*2)
        {
            m_initSize.height = m_imgRect.getHeight()>>1;
        }
        else
        {
            m_initSize.height = IMGEDT_CLIP_MIN_LENGHTH;
        }
    }
    else
    {
        VFX_ASSERT((0 != m_curRatioH) && (0 != m_curRatioW));
        VfxFloat ratio_w_h = (VfxFloat)m_curRatioW/(VfxFloat)m_curRatioH;
        VfxFloat ratio_h_w = (VfxFloat)m_curRatioH/(VfxFloat)m_curRatioW;
        //compare clip ratio with image ratio
        VfxFloat img_ratio_w_h = (VfxFloat)m_imgRect.getWidth()/(VfxFloat)m_imgRect.getHeight();
        if (img_ratio_w_h >= ratio_w_h)
        {
            m_initSize.height = m_imgRect.getHeight();
            m_initSize.width = m_imgRect.getHeight() * ratio_w_h;
        }
        else
        {
            m_initSize.width = m_imgRect.getWidth();
            m_initSize.height = m_imgRect.getWidth() * ratio_h_w;
        }
        //if clipWindow too large, make it smaller
        if (ratio_w_h >= 1.0f)
        {
            if (m_initSize.height > IMGEDT_CLIP_MIN_LENGHTH*2)
            {
                m_initSize.width = m_initSize.width >> 1;
                m_initSize.height = m_initSize.height >> 1;
            }
        }
        else
        {
            if (m_initSize.height > IMGEDT_CLIP_MIN_LENGHTH*2)
            {
                m_initSize.width = m_initSize.width >> 1;
                m_initSize.height = m_initSize.height >> 1;
            }
        }
        
    }

    if (m_clipRect.isEmpty())
    {
        m_clipRect = VfxRect((getBounds().getWidth() - m_initSize.width)/2, 
                             (getBounds().getHeight() - m_initSize.height)/2, 
                             m_initSize.width, 
                             m_initSize.height);
    }    
    updateLayout();
}

void VcpImgEdtClipWindow::updateLayout()
{   
    if (m_isFixed)
    {
        setMiddleBtnHidden(VFX_TRUE);
    }
    else
    {
        setMiddleBtnHidden(VFX_FALSE);
    }
    //set new cilp window ratio
    VfxFloat ratio_w_h = (VfxFloat)m_curRatioW/(VfxFloat)m_curRatioH;
    VfxFloat ratio_h_w = (VfxFloat)m_curRatioH/(VfxFloat)m_curRatioW;

    //ensure clip region size inside image
    if (m_clipRect.getWidth() > m_imgRect.getWidth())
    {
        m_clipRect.size.width = m_imgRect.getWidth();
      
    }
    if (m_clipRect.getHeight() > m_imgRect.getHeight())
    {
        m_clipRect.size.height = m_imgRect.getHeight();
    }
    //reset clip window ratio    
    if (m_isFixed)
    {
        if (ratio_w_h >= 1.0f)
        {
            m_clipRect.size.height = m_clipRect.getWidth() * ratio_h_w;

			if(m_clipRect.size.height > m_imgRect.getHeight())
			{
				m_clipRect.size.height = m_imgRect.getHeight();
				m_clipRect.size.width = m_clipRect.getHeight() * ratio_w_h;
			}
        }
        else
        {
            m_clipRect.size.width = m_clipRect.getHeight() * ratio_w_h;
			
			if (m_clipRect.getWidth() > m_imgRect.getWidth())
		    {
				m_clipRect.size.width = m_imgRect.getWidth();
				m_clipRect.size.height = m_clipRect.getWidth() * ratio_h_w;
		    }
        }
    }    
    //move clip window into image area
    if (m_clipRect.getX() < m_imgRect.getX())
    {
        m_clipRect.origin.x = m_imgRect.getX();
    }
    if (m_clipRect.getY() < m_imgRect.getY())
    {
        m_clipRect.origin.y = m_imgRect.getY();
    }
    if (m_clipRect.getMaxX() > m_imgRect.getMaxX())
    {
        m_clipRect.origin.x -= m_clipRect.getMaxX() - m_imgRect.getMaxX();
    }
    if (m_clipRect.getMaxY() > m_imgRect.getMaxY())
    {
        m_clipRect.origin.y -= m_clipRect.getMaxY() - m_imgRect.getMaxY();
    }
   
    redrawClipwindow();

    //redrawTransFrame();
    //redrawLineFrame();
    //redrawConerBtn();
    //redrawMiddleBtn();    
}

VfxBool VcpImgEdtClipWindow::onPenDownCheck(VfxPenEvent &event)
{
    m_state = STATE_IDLE;
    for (VfxS32 i = CORNER_LEFT_UP; i < CORNER_TOTAL ; i++)
    {            
        if (m_cornerBtn[i]->getRect().contains(event.pos))
        {
            m_state = STATE_RESIZE_FIXED;
            m_focusBtnInx =  i;
            return VFX_TRUE;
        }
    }
    //in fixed resive mode, no middle button
    if (!m_isFixed)
    {
        for (VfxS32 i = DIRECT_UP; i < DIRECT_TOTAL ; i++)
        {
            if (m_middleBtn[i]->getRect().contains(event.pos))
            {
                m_state = STATE_RESIZE_FREE;
                m_focusBtnInx =  i;
                m_movePole = event.pos;
                return VFX_TRUE;
            }
        }
    }
    for (VfxS32 i = DIRECT_UP; i < DIRECT_TOTAL; i++)
    {
        //if (m_lineFrame[i]->getRect().contains(event.pos))
        if (m_clipRect.contains(event.pos))
        {
            m_movePole = event.pos;
            m_state = STATE_MOVE;
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


VfxBool VcpImgEdtClipWindow::onPenInput(VfxPenEvent &event)
{
    VfxBool bRet = VFX_FALSE;
    VfxPenEvent refPenEvent = event;

    if (m_isFreeze)
    {
        return VFX_FALSE;
    }

    if (m_detectRect.contains(event.pos))
    {
        m_signalDetectAreaTouched.emit();
    }

    if (refPenEvent.pos.x < m_imgRect.getX())
    {
        refPenEvent.pos.x = m_imgRect.getX();
    }
    if (refPenEvent.pos.y < m_imgRect.getY())
    {
        refPenEvent.pos.y = m_imgRect.getY();
    }
    if (refPenEvent.pos.x > m_imgRect.getMaxX()- 1)
    {
        refPenEvent.pos.x = m_imgRect.getMaxX() - 1;
    }
    if (refPenEvent.pos.y > m_imgRect.getMaxY() - 1)
    {
        refPenEvent.pos.y = m_imgRect.getMaxY() - 1;
    }

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        //VFX_ASSERT(STATE_IDLE == m_state);
        m_resetResizeInfo = VFX_TRUE;
        if (onPenDownCheck(event))
        {
            if (STATE_MOVE == m_state)
            {
                setLineFrameFocus(VFX_TRUE);
                bRet = VFX_TRUE;
            }
            else if (STATE_RESIZE_FIXED == m_state ||
                     STATE_RESIZE_FREE == m_state)
            {
                setBtnFocus(VFX_TRUE);
                bRet = VFX_TRUE;
            }
            else
            {
                bRet = getParentControl()->penInput(event);
            }            
        }
        break;
    case VFX_PEN_EVENT_TYPE_ABORT:
    case VFX_PEN_EVENT_TYPE_UP:
        if (STATE_MOVE == m_state)
        {
            setLineFrameFocus(VFX_FALSE);
            bRet = VFX_TRUE;
        }
        else if (STATE_RESIZE_FREE == m_state)
        {
            setBtnFocus(VFX_FALSE);
            if (!m_isFixed)
            {
                m_curRatioW = m_clipRect.getWidth();
                m_curRatioH = m_clipRect.getHeight();
            }
            bRet = VFX_TRUE;
        }
        else if (STATE_RESIZE_FIXED == m_state)
        {
            setBtnFocus(VFX_FALSE);
            bRet = VFX_TRUE;
        }
        else
        {
            bRet = getParentControl()->penInput(event);
        }
        m_state = STATE_IDLE;
        break;

    case VFX_PEN_EVENT_TYPE_MOVE:
        switch(m_state)
        {
        case STATE_MOVE:
            onClipWindowMove(refPenEvent);
            bRet = VFX_TRUE;
            break;
             
        case STATE_RESIZE_FREE:
            onClipWindowFreeResize(refPenEvent);
            bRet = VFX_TRUE;
            break;
            
        case STATE_RESIZE_FIXED:
            onClipWindowFixedResize(refPenEvent);
            bRet = VFX_TRUE;
            break;

        case STATE_IDLE:
        default:
            bRet = getParentControl()->penInput(event);;
            break;        
        }   
        break;
        
    default:
        break;
    }
   
    return bRet;
}


void VcpImgEdtClipWindow::onClipWindowMove(VfxPenEvent &event)
{
      
    //Check if clip windown will move beyond right the screen.
    VfxSize refPos;
    refPos.width = event.pos.x - m_movePole.x;
    refPos.height = event.pos.y - m_movePole.y;
    if (refPos.width > 0)
    {
        if (m_clipRect.getMaxX() + refPos.width > m_imgRect.getMaxX())
        {
            refPos.width = m_imgRect.getMaxX() - m_clipRect.getMaxX();
        }
    }
    else if (refPos.width < 0)
    {
        if (m_clipRect.getX() + refPos.width < m_imgRect.getX())
        {
            refPos.width = m_imgRect.getX() - m_clipRect.getX();
        }
    }

    if (refPos.height > 0)
    {
        if (m_clipRect.getMaxY() + refPos.height > m_imgRect.getMaxY())
        {
            refPos.height = m_imgRect.getMaxY() - m_clipRect.getMaxY();
        }
    }
    else if (refPos.height < 0)
    {
        if (m_clipRect.getY() + refPos.height < m_imgRect.getY())
        {
            refPos.height = m_imgRect.getY() - m_clipRect.getY();
        }
    }
    //redraw:
    if (refPos.width != 0)
    {
        m_clipRect.origin.x += refPos.width;
        m_movePole.x += refPos.width;
    }
    if (refPos.height != 0)
    {
        m_clipRect.origin.y += refPos.height;
        m_movePole.y +=refPos.height;
    }
	
	redrawClipwindow();
		
    //redrawTransFrame();
    //redrawLineFrame();
    //redrawConerBtn();
    //redrawMiddleBtn();  

}

void VcpImgEdtClipWindow::onClipWindowFreeResize(VfxPenEvent &event)
{
    VfxPoint realPos = event.pos;
    VfxS32   refMove = 0;
    
    switch(m_focusBtnInx)
    {
    case DIRECT_UP:
        if (m_clipRect.getMaxY() - event.pos.y < IMGEDT_CLIP_MIN_LENGHTH)
        {
            realPos.y = m_clipRect.getMaxY() - IMGEDT_CLIP_MIN_LENGHTH;
        }
        refMove = realPos.y- m_clipRect.getY();
        m_clipRect.origin.y += refMove;
        m_clipRect.size.height -=  refMove;
        break;

    case DIRECT_DOWN:
        if (event.pos.y - m_clipRect.getY() < IMGEDT_CLIP_MIN_LENGHTH)
        {
            realPos.y = m_clipRect.getY() + IMGEDT_CLIP_MIN_LENGHTH;
        }
        refMove = realPos.y - m_clipRect.getMaxY();
        m_clipRect.size.height += refMove;
        break;

    case DIRECT_LEFT:
        if (m_clipRect.getMaxX() - event.pos.x < IMGEDT_CLIP_MIN_LENGHTH)
        {
            realPos.x = m_clipRect.getMaxX() - IMGEDT_CLIP_MIN_LENGHTH;
        }
        refMove = realPos.x - m_clipRect.getX();
        m_clipRect.origin.x += refMove;
        m_clipRect.size.width -= refMove;
        break;

    case DIRECT_RIGHT:
        if (event.pos.x - m_clipRect.getX() < IMGEDT_CLIP_MIN_LENGHTH)
        {
            realPos.x = m_clipRect.getX() + IMGEDT_CLIP_MIN_LENGHTH;
        }
        refMove = realPos.x - m_clipRect.getMaxX();
        m_clipRect.size.width += refMove;
        break;

    default:
        VFX_ASSERT(0);
    }

    if (0 != refMove)
    {
    	redrawClipwindow();
		
        //redrawTransFrame();
        //redrawLineFrame();
        //redrawConerBtn();
        //redrawMiddleBtn();
    }       

}

VfxBool VcpImgEdtClipWindow::checkInputValid(VfxPoint pos)
{
    VfxBool bRet = VFX_TRUE;
    VfxSize refMove;
    
#if 1//!defined(__MMI_COSMOS_PHOTOEDITOR__)
	
    if((m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx==CORNER_LEFT_DOWN))
    {
		refMove.width = pos.x - m_clipRect.getX();
		
		if (pos.x >= m_clipRect.getMaxX())
			bRet = VFX_FALSE;
    }
	else
	{
		refMove.width = pos.x - m_clipRect.getMaxX();
		
		 if (pos.x <= m_clipRect.getX())
		 	bRet = VFX_FALSE;
	}
	
	if((m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx==CORNER_RIGHT_UP)) 
	{
		refMove.height = pos.y - m_clipRect.getY();
		
		if(pos.y >= m_clipRect.getMaxY())
			bRet = VFX_FALSE;
	}
	else
	{
		refMove.height = pos.y - m_clipRect.getMaxY();
		
		if(pos.y <= m_clipRect.getY())
			bRet = VFX_FALSE;
	}

	if((m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx==CORNER_RIGHT_DOWN))
	{
		if((refMove.width * refMove.height <= 0))
			bRet = VFX_FALSE;
	}
	else
	{
		if((refMove.width * refMove.height >= 0))
			bRet = VFX_FALSE;
	}
	
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return bRet;
}

void VcpImgEdtClipWindow::resetValidRect()
{
    VfxSize minSize, maxSize;
    VfxFloat ratio_w_h = (VfxFloat)m_curRatioW/(VfxFloat)m_curRatioH;
    VfxFloat ratio_h_w = (VfxFloat)m_curRatioH/(VfxFloat)m_curRatioW;
    VfxFloat tempRatio;
    VfxPoint start, end;

#if	1//!defined(__MMI_COSMOS_PHOTOEDITOR__)
	if((m_focusBtnInx==CORNER_LEFT_UP) ||(m_focusBtnInx==CORNER_LEFT_DOWN))
	{
		start.x = end.x = m_clipRect.getX();
		maxSize.width = m_clipRect.getX() - m_imgRect.getX();
	}
	else
	{
		start.x = end.x = m_clipRect.getMaxX();
		maxSize.width =  m_imgRect.getMaxX() - m_clipRect.getMaxX();
	}

	if((m_focusBtnInx==CORNER_LEFT_UP) ||(m_focusBtnInx==CORNER_RIGHT_UP)) 
	{
		start.y = end.y = m_clipRect.getY();
		maxSize.height = m_clipRect.getY() - m_imgRect.getY();
	}
	else
	{
		start.y = end.y = m_clipRect.getMaxY();
		maxSize.height = m_imgRect.getMaxY() - m_clipRect.getMaxY(); 
	}

	tempRatio = (VfxFloat)maxSize.width/(VfxFloat)maxSize.height;

	if ((maxSize.width >= 0) && (maxSize.height >= 0))
	{
		if(tempRatio >= ratio_w_h)
		{
			if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_RIGHT_UP) )
				start.y = m_imgRect.getY();
			else
				start.y = m_imgRect.getMaxY();
			
			if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_LEFT_DOWN) )
				start.x -= (maxSize.height * ratio_w_h);
			else
				start.x += (maxSize.height * ratio_w_h);
		}
		else
		{
			if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_LEFT_DOWN) )
				start.x = m_imgRect.getX();
			else
				start.x = m_imgRect.getMaxX();
			
			if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_RIGHT_UP) )
				start.y -= (maxSize.width * ratio_h_w);
			else
				start.y += (maxSize.width * ratio_h_w);
			
		}
	}

	minSize.width = m_clipRect.getMaxX() - IMGEDT_CLIP_MIN_LENGHTH - m_clipRect.getX();
	minSize.height = m_clipRect.getMaxY() - IMGEDT_CLIP_MIN_LENGHTH - m_clipRect.getY();
	tempRatio = (VfxFloat)minSize.width/(VfxFloat)minSize.height;

	if ((minSize.width >= 0) && (minSize.height >= 0))
	{
		if (tempRatio >= ratio_w_h)
		{
			if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_RIGHT_UP) )
				end.y = m_clipRect.getMaxY() - IMGEDT_CLIP_MIN_LENGHTH;
			else
				end.y = m_clipRect.getY() + IMGEDT_CLIP_MIN_LENGHTH;
			
			if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_LEFT_DOWN) )
				end.x += minSize.height * ratio_w_h;
			else
				end.x -= minSize.height * ratio_w_h;
		}
		else
		{
			if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_LEFT_DOWN) )
				end.x = m_clipRect.getMaxX() - IMGEDT_CLIP_MIN_LENGHTH;
			else
				end.x = m_clipRect.getX() + IMGEDT_CLIP_MIN_LENGHTH;
			
			if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_RIGHT_UP) )
				end.y += minSize.width * ratio_h_w;
			else
				end.y -= minSize.width * ratio_h_w;
		}
	}

	if(m_focusBtnInx==CORNER_LEFT_UP) 
		m_validResizeRect = VfxRect(start.x, start.y, end.x - start.x + 1, end.y - start.y + 1);
	else if(m_focusBtnInx==CORNER_LEFT_DOWN)	
		m_validResizeRect = VfxRect(start.x, end.y, end.x - start.x + 1, start.y - end.y + 1);
	else if(m_focusBtnInx==CORNER_RIGHT_UP)	
		m_validResizeRect = VfxRect(end.x, start.y, start.x - end.x + 1, end.y - start.y + 1);
	else if(m_focusBtnInx==CORNER_RIGHT_DOWN) 
		m_validResizeRect = VfxRect(end.x, end.y, start.x - end.x + 1, start.y - end.y + 1);

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return;
}

void VcpImgEdtClipWindow::ajustInputPos(VfxPoint &pos)
{
    if (pos.x < m_validResizeRect.getX())
    {
        pos.x = m_validResizeRect.getX();
    }
    if (pos.y < m_validResizeRect.getY())
    {
        pos.y = m_validResizeRect.getY();
    }
    if (pos.x > m_validResizeRect.getMaxX())
    {
        pos.x = m_validResizeRect.getMaxX();
    }
    if (pos.y > m_validResizeRect.getMaxY())
    {
        pos.y = m_validResizeRect.getMaxY();
    }
}

void VcpImgEdtClipWindow::onClipWindowFixedResize(VfxPenEvent &event)
{
    if (!checkInputValid(event.pos))
    {
        return;
    }
    if (m_resetResizeInfo)
    {
        resetValidRect();
        m_resetResizeInfo = VFX_FALSE;
    }

    VfxPoint validPos = event.pos;
    if (!m_validResizeRect.contains(validPos))
    {
        ajustInputPos(validPos);
    }    

    VfxFloat ratio_w_h = (VfxFloat)m_curRatioW/(VfxFloat)m_curRatioH;
    VfxFloat ratio_h_w = (VfxFloat)m_curRatioH/(VfxFloat)m_curRatioW;
    VfxSize  refMove;
    VfxS32 a;
	
#if	1//!defined(__MMI_COSMOS_PHOTOEDITOR__)
	if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_LEFT_DOWN) )
		refMove.width = validPos.x - m_clipRect.getX();
	else
		refMove.width = validPos.x - m_clipRect.getMaxX();
	
	if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_RIGHT_UP) )
		refMove.height = validPos.y - m_clipRect.getY();
	else
		refMove.height = validPos.y - m_clipRect.getMaxY();

    a = (refMove.width * refMove.height >= 0) ? 1 : -1;
	
    if (ratio_w_h >= 1)
        refMove.height = a * refMove.width * ratio_h_w;
    else
        refMove.width  = a * refMove.height * ratio_w_h;
	
	if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_LEFT_DOWN) )
	{
		m_clipRect.origin.x += refMove.width;
		m_clipRect.size.width -= refMove.width;
	}
	else
	{
		m_clipRect.size.width += refMove.width;
	}
	
	if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_RIGHT_UP) )
	{
		m_clipRect.origin.y += refMove.height;
		m_clipRect.size.height -= refMove.height;
	}
	else
	{
		m_clipRect.size.height += refMove.height;
	}
	
	if (ratio_w_h >= 1) //revise cumulative error
	{
		refMove.height = m_clipRect.size.height - 
			((VfxFloat)m_clipRect.size.width /m_curRatioW)* m_curRatioH;
		
		m_clipRect.size.height -= refMove.height;
		
		if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_RIGHT_UP) )
		{			
			m_clipRect.origin.y += refMove.height;
		}

	}
	else
	{
		refMove.width = m_clipRect.size.width - 
			((VfxFloat)m_clipRect.size.height /m_curRatioH)* m_curRatioW;

		m_clipRect.size.width -= refMove.width;
		
		if( (m_focusBtnInx==CORNER_LEFT_UP) || (m_focusBtnInx ==CORNER_LEFT_DOWN) )
		{			
			m_clipRect.origin.x += refMove.width;
		}
	}
	
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
           
   //sreen ratio, it hard to drag the clip window to full screen, revise it...
   if( (m_curRatioW==LCD_WIDTH && m_curRatioH == LCD_HEIGHT)&&
	   ((m_clipRect.size.width>=(LCD_WIDTH-2) || m_clipRect.size.height>=(LCD_HEIGHT-2))) )
   {
	   m_clipRect.origin.x = 0;
	   m_clipRect.origin.y = 0;
	   m_clipRect.size.width = LCD_WIDTH;
	   m_clipRect.size.height = LCD_HEIGHT;
   }
   else if((m_curRatioW==LCD_HEIGHT  && m_curRatioH == LCD_WIDTH) && 
	   ((m_clipRect.size.width>=(LCD_HEIGHT-2) || m_clipRect.size.height>=(LCD_WIDTH-2))))
   {
	   m_clipRect.origin.x = 0;
	   m_clipRect.origin.y = 0;
	   m_clipRect.size.width = LCD_HEIGHT;
	   m_clipRect.size.height = LCD_WIDTH;
   }

    if (!refMove.isZero())
    {
    	redrawClipwindow();
		
        //redrawTransFrame();
        //redrawLineFrame();
        //redrawConerBtn();
        //redrawMiddleBtn();
    }   

}

void VcpImgEdtClipWindow::createTransFrame()
{
    for (int i = DIRECT_UP; i < DIRECT_TOTAL; i++)
    {
        VFX_OBJ_CREATE(m_transFrame[i], VfxFrame, this);
        m_transFrame[i]->setOpacity(0.5f); 
        m_transFrame[i]->setBgColor(VRT_COLOR_BLACK);
        //m_transFrame[i]->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BLACK_BG));
        //m_transFrame[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_transFrame[i]->setAnchor(0, 0);
        m_transFrame[i]->setIsUnhittable(VFX_TRUE);
    }
}


void VcpImgEdtClipWindow::createLineFrame()
{
    //create and init Line
    VFX_OBJ_CREATE(m_lineFrame[DIRECT_UP], VfxFrame, this);    
    m_lineFrame[DIRECT_UP]->setAnchor(VfxFPoint(0.0, 0.5));
      
    VFX_OBJ_CREATE(m_lineFrame[DIRECT_DOWN], VfxFrame, this);    
    m_lineFrame[DIRECT_DOWN]->setAnchor(VfxFPoint(0.0, 0.5));
      
    VFX_OBJ_CREATE(m_lineFrame[DIRECT_LEFT], VfxFrame, this);    
    m_lineFrame[DIRECT_LEFT]->setAnchor(VfxFPoint(0.5, 0.0));
        
    VFX_OBJ_CREATE(m_lineFrame[DIRECT_RIGHT], VfxFrame, this);    
    m_lineFrame[DIRECT_RIGHT]->setAnchor(VfxFPoint(0.5, 0.0));

    VFX_OBJ_CREATE(m_borderFrame, VfxFrame, this);
    m_borderFrame->setAnchor(0.5f, 0.5f);
    m_borderFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    setLineFrameFocus(VFX_FALSE);
}

void VcpImgEdtClipWindow::setLineFrameFocus(VfxBool bFocus)
{
    if (bFocus)
    {
        m_borderFrame->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_RECT_FRAME_HL));
    }
    else
    {
        m_borderFrame->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_RECT_FRAME));
    }
}

void VcpImgEdtClipWindow::setBtnFocus(VfxBool bFocus)
{
    if (STATE_RESIZE_FIXED != m_state &&
        STATE_RESIZE_FREE != m_state)
    {
        return;
    }
    if (bFocus)
    {
        if (m_focusBtnInx < CORNER_TOTAL)
        {
            VfxFrame *btn = NULL;
            VfxSize iconSize, haloSize;
            if (STATE_RESIZE_FIXED == m_state)
            {
                btn = m_cornerBtn[m_focusBtnInx];
                iconSize = VfxImageSrc(IMG_ID_IMGEDT_BALL_LARGE).getSize();
            }
            else if (STATE_RESIZE_FREE == m_state)
            {
                btn = m_middleBtn[m_focusBtnInx];
                iconSize = VfxImageSrc(IMG_ID_IMGEDT_BALL_SMALL).getSize();
            }
            else
            {
                VFX_ASSERT(0);
            }
            VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
            m_btnHL->setSize(haloSize);
            m_btnHL->setPos(btn->getRect().getMidX(), btn->getRect().getMidY());
            m_btnHL->setHidden(VFX_FALSE);
       }
    }
    else
    {
        m_btnHL->setHidden(VFX_TRUE);
    }

}

void VcpImgEdtClipWindow::createConerBtn()
{
    for (int i = CORNER_LEFT_UP; i < CORNER_TOTAL; i++)
    {
        VFX_OBJ_CREATE(m_cornerBtn[i], VfxFrame, this); 
        m_cornerBtn[i]->setBgColor(VRT_COLOR_TRANSPARENT);
        m_cornerBtn[i]->setBounds(0, 0, IMGEDT_CLIP_BTN_SIZE, IMGEDT_CLIP_BTN_SIZE);
        m_cornerBtn[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
        m_cornerBtn[i]->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BALL_LARGE));
        m_cornerBtn[i]->setAnchor(VfxFPoint(0.5, 0.5));
    }
}

void VcpImgEdtClipWindow::createMiddleBtn()
{
    for (VfxS32 i = DIRECT_UP; i < DIRECT_TOTAL; i++)
    {
        VFX_OBJ_CREATE(m_middleBtn[i], VfxFrame, this);
        m_middleBtn[i]->setBgColor(VRT_COLOR_TRANSPARENT);
        m_middleBtn[i]->setBounds(0, 0, IMGEDT_CLIP_BTN_SIZE, IMGEDT_CLIP_BTN_SIZE);
        m_cornerBtn[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
        m_middleBtn[i]->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BALL_SMALL));
        m_middleBtn[i]->setAnchor(VfxFPoint(0.5, 0.5));
    }
}

void VcpImgEdtClipWindow::redrawClipwindow()
{
	redrawTransFrame();
    redrawLineFrame(); 
    redrawConerBtn();
    redrawMiddleBtn(); 
}

void VcpImgEdtClipWindow::redrawTransFrame()
{
    m_transFrame[DIRECT_UP]->setBounds(0, 0, getBounds().getWidth(), m_clipRect.getY());
    m_transFrame[DIRECT_UP]->setPos(0,0);

    m_transFrame[DIRECT_DOWN]->setBounds(0, 0, 
                                         getBounds().getWidth(), 
                                         getBounds().getHeight() - m_clipRect.getMaxY());
    m_transFrame[DIRECT_DOWN]->setPos(0,m_clipRect.getMaxY() + 1);
    
    m_transFrame[DIRECT_LEFT]->setBounds(0 , 0, 
                                         m_clipRect.getX(), m_clipRect.getHeight());
    m_transFrame[DIRECT_LEFT]->setPos(0,m_clipRect.getY());
    
    
    m_transFrame[DIRECT_RIGHT]->setBounds(0, 0,
                                          getBounds().getWidth() - m_clipRect.getMaxX(), 
                                          m_clipRect.getHeight());
    m_transFrame[DIRECT_RIGHT]->setPos(m_clipRect.getMaxX(), m_clipRect.getY());
    
}

void VcpImgEdtClipWindow::redrawLineFrame()
{
    m_lineFrame[DIRECT_UP]->setBounds(0, 0, m_clipRect.getWidth() , IMGEDT_CLIP_FRAME_WIDTH );
    m_lineFrame[DIRECT_UP]->setPos(m_clipRect.getX(), m_clipRect.getY());
    m_lineFrame[DIRECT_DOWN]->setBounds(0, 0, m_clipRect.getWidth(), IMGEDT_CLIP_FRAME_WIDTH);
    m_lineFrame[DIRECT_DOWN]->setPos(m_clipRect.getX(), m_clipRect.getMaxY());
    m_lineFrame[DIRECT_LEFT]->setBounds(0, 0 , IMGEDT_CLIP_FRAME_WIDTH , m_clipRect.getHeight());
    m_lineFrame[DIRECT_LEFT]->setPos(m_clipRect.getX(), m_clipRect.getY());
    m_lineFrame[DIRECT_RIGHT]->setBounds(0, 0 , IMGEDT_CLIP_FRAME_WIDTH , m_clipRect.getHeight());
    m_lineFrame[DIRECT_RIGHT]->setPos(m_clipRect.getMaxX(), m_clipRect.getY());

    m_borderFrame->setPos(m_clipRect.getMidPoint());
    m_borderFrame->setSize(m_clipRect.getWidth() + 4 , m_clipRect.getHeight() + 4);
}

void VcpImgEdtClipWindow::redrawConerBtn()
{
    m_cornerBtn[CORNER_LEFT_UP]->setPos(m_clipRect.getX(), m_clipRect.getY());
    m_cornerBtn[CORNER_RIGHT_UP]->setPos(m_clipRect.getMaxX(), m_clipRect.getY());
    m_cornerBtn[CORNER_LEFT_DOWN]->setPos(m_clipRect.getX(), m_clipRect.getMaxY());
    m_cornerBtn[CORNER_RIGHT_DOWN]->setPos(m_clipRect.getMaxX(), m_clipRect.getMaxY());
    if (STATE_RESIZE_FIXED == m_state)
    {
        m_btnHL->setPos(m_cornerBtn[m_focusBtnInx]->getRect().getMidX(), 
                        m_cornerBtn[m_focusBtnInx]->getRect().getMidY());
    }
}

void VcpImgEdtClipWindow::redrawMiddleBtn()
{
    m_middleBtn[DIRECT_UP]->setPos(m_clipRect.getX() + (m_clipRect.getWidth()/2) ,
                                   m_clipRect.getY());
    m_middleBtn[DIRECT_DOWN]->setPos(m_clipRect.getX() + (m_clipRect.getWidth()/2),
                                     m_clipRect.getMaxY());
    m_middleBtn[DIRECT_LEFT]->setPos(m_clipRect.getX(),
                                     m_clipRect.getY() + (m_clipRect.getHeight()/2));
    m_middleBtn[DIRECT_RIGHT]->setPos(m_clipRect.getMaxX() + 1,
                                      m_clipRect.getY() + (m_clipRect.getHeight()/2));
    if (STATE_RESIZE_FREE == m_state)
    {
        m_btnHL->setPos(m_middleBtn[m_focusBtnInx]->getRect().getMidX(), 
                        m_middleBtn[m_focusBtnInx]->getRect().getMidY());
    }
}

void VcpImgEdtClipWindow::setMiddleBtnHidden(VfxBool is_hidden)
{
    for (VfxS32 i = 0; i < CORNER_TOTAL; i++)
    {
        m_middleBtn[i]->setHidden(is_hidden);
    }
}

/***************************************************************************** 
 * class VcpImgEdtBottomBtn
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VcpImgEdtBottomBtn", VcpImgEdtBottomBtn, VfxFrame);

VcpImgEdtBottomBtn::VcpImgEdtBottomBtn(): 
m_bTabBtn(VFX_FALSE),
m_bDownState(VFX_FALSE)
{
}
        
void VcpImgEdtBottomBtn::onInit()
{
    VfxFrame::onInit();
    VfxFrame::setImgContent(VfxImageSrc(IMG_ID_IMGEDT_TITLE_BAR_VERT));
    VfxFrame::setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        
    VFX_OBJ_CREATE(m_button, VcpImageButton, this);
    m_button->setIsEffect(VFX_TRUE);
    //m_button->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_button->m_signalClicked.connect(this, &VcpImgEdtBottomBtn::onBtnClicked);
    m_button->setAnchor(0.5f, 0.5f);
    //m_button->setSize(40, 40);
}

void VcpImgEdtBottomBtn::updatePos()
{
    if (!m_bTabBtn)
    {
        VfxRect rect = m_button->getRect();
        m_button->setRect(rect);
    }
}

void VcpImgEdtBottomBtn::setTabBtn(VfxBool isTab)
{
    m_bTabBtn = isTab;
    if (m_bTabBtn)
    {
        m_button->setIsEffect(VFX_FALSE);
    }
    else
    {
        m_button->setIsEffect(VFX_TRUE);
    }
}

void VcpImgEdtBottomBtn::setId(VfxId id)
{
    m_button->setId(id);
}

VfxId VcpImgEdtBottomBtn::getId()
{
    return m_button->getId();
}


void VcpImgEdtBottomBtn::setImageId(VcpStateImage imgList)
{
    m_button->setImage(imgList);
}

void VcpImgEdtBottomBtn::setBtnSize(VfxSize size)
{
    //VfxFrame::setSize(size);
    //m_button->setPos(size.width/2, size.height/2);
    m_button->setSize(size);
}

void VcpImgEdtBottomBtn::setBgSize(VfxSize size)
{
    m_bgSize = size;
    VfxFrame::setSize(size);
    m_button->setPos(size.width/2, size.height/2);
    if (!m_bTabBtn)
    {
        m_button->setEffectSize(VfxSize(70, 70));
    }
}

void VcpImgEdtBottomBtn::setStateDown(VfxBool isDown)
{
    if (isDown == m_bDownState)
    {
        return;
    }

    if (!m_bTabBtn)
    {
        return;
    }

    m_bDownState = isDown;
    if (m_bDownState)
    {
        VfxFrame::setImgContent(VfxImageSrc(IMG_ID_IMGEDT_BOTTOM_HL));
        VfxFrame::setSize(m_bgSize.width, m_bgSize.height - 1);
    }
    else
    {
        VfxFrame::setImgContent(VfxImageSrc(IMG_ID_IMGEDT_TITLE_BAR_VERT));
        VfxFrame::setSize(m_bgSize.width, m_bgSize.height);
    }
}


void VcpImgEdtBottomBtn::setDisabled(VfxBool isDisabled)
{
    m_button->setIsDisabled(isDisabled);
}

void VcpImgEdtBottomBtn::onBtnClicked(VfxObject* obj, VfxId id)
{
    if (m_bTabBtn)
    {
        if (!m_bDownState)
        {
            setStateDown(VFX_TRUE);
            m_signalPressed.emit(obj, id);
        }
    }
    else
    {
        m_signalPressed.emit(obj, id);
    }
}
    

/***************************************************************************** 
 * Class VcpImgEdtBottomBar 
 *****************************************************************************/  
//VFX_IMPLEMENT_CLASS("VcpImgEdtBottomBar", VcpImgEdtBottomBar, VfxPageBar);

VcpImgEdtBottomBar::VcpImgEdtBottomBar():
m_btnNumL1(0),
m_btnNumL2(0),
m_bgSize(0,0),
m_btnL1Size(0,0),
m_btnL2Size(0,0)
{
}

void VcpImgEdtBottomBar::onInit()
{
    VfxPageBar::onInit();

    VFX_OBJ_CREATE(m_btnOK, VcpImageButton, this);
    VcpStateImage okImgList(IMG_ID_IMGEDT_BOTTOMBAR_OK,
                            IMG_ID_IMGEDT_BOTTOMBAR_OK,
                            IMG_ID_IMGEDT_BOTTOMBAR_OK,
                            IMG_ID_IMGEDT_BOTTOMBAR_OK);
    m_btnOK->setIsEffect(VFX_TRUE);
    m_btnOK->setImage(okImgList);
    m_btnOK->setSize(IMGEDT_BOTTOM_LRSK_SIZE, IMGEDT_BOTTOM_LRSK_SIZE);
    m_btnOK->setId(BOTTOM_BTN_TYPE_OK);
    m_btnOK->m_signalClicked.connect(this, &VcpImgEdtBottomBar::onBtnTaped);  

    VFX_OBJ_CREATE(m_btnBack, VcpImageButton, this);
    VcpStateImage cancelImgList(IMG_ID_IMGEDT_BOTTOMBAR_BACK,
                                IMG_ID_IMGEDT_BOTTOMBAR_BACK,
                                IMG_ID_IMGEDT_BOTTOMBAR_BACK,
                                IMG_ID_IMGEDT_BOTTOMBAR_BACK);
    m_btnBack->setIsEffect(VFX_TRUE);
    m_btnBack->setImage(cancelImgList);
    m_btnBack->setSize(IMGEDT_BOTTOM_LRSK_SIZE+1, IMGEDT_BOTTOM_LRSK_SIZE);
    m_btnBack->setId(BOTTOM_BTN_TYPE_CANCEL);
    m_btnBack->m_signalClicked.connect(this, &VcpImgEdtBottomBar::onBtnTaped);
}

void VcpImgEdtBottomBar::addItem(VfxId btn_id, 
                                 VfxResId button_icon,
                                 BottomBtnLevel level,
                                 VfxBool is_tab)
{
    VcpStateImage imgList(button_icon, button_icon, button_icon, button_icon);
    if (BOTTOM_BTN_L1 == level)
    {
        m_btnNumL1++;
        VFX_ASSERT(m_btnNumL1 <= IMGEDT_BOTTOM_L1_MAX_BTNS_COUNT);

        VFX_OBJ_CREATE(m_btnArrayL1[m_btnNumL1 - 1], VcpImgEdtBottomBtn, this);
        m_btnArrayL1[m_btnNumL1 - 1]->setTabBtn(is_tab);        
        m_btnArrayL1[m_btnNumL1 - 1]->setId(btn_id);
        m_btnArrayL1[m_btnNumL1 - 1]->setImageId(imgList);
        m_btnArrayL1[m_btnNumL1 - 1]->m_signalPressed.connect(this, &VcpImgEdtBottomBar::onBtnTaped);
    }
    else
    {
        m_btnNumL2++;
        VFX_ASSERT(m_btnNumL2 <= IMGEDT_BOTTOM_L2_MAX_BTNS_COUNT);
        VFX_OBJ_CREATE(m_btnArrayL2[m_btnNumL2 - 1], VcpImgEdtBottomBtn, this);
        m_btnArrayL2[m_btnNumL2 - 1]->setTabBtn(is_tab);
        m_btnArrayL2[m_btnNumL2 - 1]->setId(btn_id);
        m_btnArrayL2[m_btnNumL2 - 1]->setImageId(imgList);
        m_btnArrayL2[m_btnNumL2 - 1]->m_signalPressed.connect(this, &VcpImgEdtBottomBar::onBtnTaped);
    }
}

void VcpImgEdtBottomBar::resetItemImage(VfxS32 index, VfxResId button_icon, BottomBtnLevel level)
{
    VcpStateImage imgList(button_icon, button_icon, button_icon, button_icon);
    if (BOTTOM_BTN_L1 == level)
    {
        m_btnArrayL1[index]->setImageId(imgList);
    }
    else
    {
        m_btnArrayL2[index]->setImageId(imgList);
    }
}

void VcpImgEdtBottomBar::show()
{   
    VfxSize iconSize, haloSize;
    if (0 == m_btnNumL1)
    {
        VfxFrame *bg;
        VFX_OBJ_CREATE(bg, VfxFrame, this);
        bg->setPos(0, 0);
        bg->setBounds(0, 0, m_bgSize.width+1, m_btnL1Size.height);
        bg->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_TITLE_BAR_VERT));
        bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        m_btnL1Size.width = m_bgSize.width / 3;
        VfxPoint pos;
        pos.x = m_btnL1Size.width / 2;
        pos.y = m_btnL1Size.height / 2;
        m_btnOK->bringToFront();
        m_btnOK->setAnchor(0.5f, 0.5f);
        m_btnOK->setPos(pos); 
        iconSize = VfxImageSrc(IMG_ID_IMGEDT_BOTTOMBAR_OK).getSize();
        VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
        m_btnOK->setEffectSize(haloSize);  

        pos.x += m_btnL1Size.width * 2;

        m_btnBack->bringToFront();
        m_btnBack->setAnchor(0.5f, 0.5f);
        m_btnBack->setPos(pos);     
        iconSize = VfxImageSrc(IMG_ID_IMGEDT_BOTTOMBAR_BACK).getSize();
        VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
        m_btnBack->setEffectSize(haloSize);
    }
#if defined(__MMI_COSMOS_PHOTOEDITOR__)
    else
    {
        m_btnL1Size.width = m_bgSize.width / (m_btnNumL1 + 2);

        //Draw OK/back background
        VfxFrame *ok_bg;
        VFX_OBJ_CREATE(ok_bg, VfxFrame, this);
        ok_bg->setPos(0, 0);
        ok_bg->setBounds(0, 0, m_btnL1Size.width, m_btnL1Size.height);
        ok_bg->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_TITLE_BAR_VERT));
        ok_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        VfxFrame *back_bg;
        VFX_OBJ_CREATE(back_bg, VfxFrame, this);
        back_bg->setPos((m_btnNumL1+1)*m_btnL1Size.width, 0);
        back_bg->setBounds(0, 0, m_bgSize.width - (m_btnNumL1+1)*m_btnL1Size.width+1, m_btnL1Size.height);
        back_bg->setImgContent(VfxImageSrc(IMG_ID_IMGEDT_TITLE_BAR_VERT));
        back_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        
        VfxPoint pos;
        pos.x = m_btnL1Size.width / 2;
        pos.y = m_btnL1Size.height / 2;
        m_btnOK->bringToFront();
        m_btnOK->setAnchor(0.5f, 0.5f);
        m_btnOK->setPos(pos);
        iconSize = VfxImageSrc(IMG_ID_IMGEDT_BOTTOMBAR_OK).getSize();
        VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
        m_btnOK->setEffectSize(haloSize); 
    
        for (VfxS32 i = 0; i < m_btnNumL1; i++)
        {
            pos.x += m_btnL1Size.width;            
            m_btnArrayL1[i]->setAnchor(0.5f, 0.5f);
            m_btnArrayL1[i]->setPos(pos);
            m_btnArrayL1[i]->setBtnSize(m_btnL1Size);
            m_btnArrayL1[i]->setBgSize(VfxSize(m_btnL1Size.width, m_btnL1Size.height));
        }
        pos.x += m_btnL1Size.width;
        m_btnBack->bringToFront();
        m_btnBack->setAnchor(0.5f, 0.5f);
        m_btnBack->setPos(pos);       
        iconSize = VfxImageSrc(IMG_ID_IMGEDT_BOTTOMBAR_BACK).getSize();
        VappImgEdtBaseScr::getHaloSize(iconSize, haloSize);
        m_btnBack->setEffectSize(haloSize);
    }

    if (0 == m_btnNumL2)
    {
        return;
    }

    m_btnL2Size.width = m_bgSize.width / m_btnNumL2;
   // m_btnL2Size.height = 40;

    VfxPoint pos;
    pos.x = m_btnL2Size.width / 2;
    pos.y = m_btnL2Size.height / 2 + m_btnL1Size.height;

    for (VfxS32 i = 0; i < m_btnNumL2; i++)
    {
        m_btnArrayL2[i]->setAnchor(0.5f, 0.5f);
        m_btnArrayL2[i]->setPos(pos);
        m_btnArrayL2[i]->setBtnSize(m_btnL2Size);
        if(i==(m_btnNumL2-1))
                m_btnArrayL2[i]->setBgSize(VfxSize(m_btnL2Size.width+1, m_btnL2Size.height));
        else
                m_btnArrayL2[i]->setBgSize(VfxSize(m_btnL2Size.width, m_btnL2Size.height));
        //m_btnArrayL2[i]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);

        pos.x += m_btnL2Size.width;
    }
#endif
}

//void VcpImgEdtBottomBar::setHeight(VfxU32 height)
//{
//    m_height = height;
//    VfxFrame::setPos(VfxPoint(0, getParentFrame()->getSize().height - m_height));
//    VfxFrame::setBounds(VfxRect(0, 0, getParentFrame()->getSize().width, m_height));
//    VfxFrame::setAutoAnimate(VFX_TRUE);
//}

void VcpImgEdtBottomBar::setBgSize(VfxSize size)
{
    m_bgSize = size;
    VfxMainScr *scr = VfxMainScr::findMainScr(getParentFrame());
    VfxSize scrSize = scr->getSize();
    VfxFrame::setPos(VfxPoint(0, scrSize.height - m_bgSize.height + 1));
    VfxFrame::setBounds(VfxRect(0, 0, m_bgSize.width, m_bgSize.height));
    VfxFrame::setAutoAnimate(VFX_TRUE);
}

void VcpImgEdtBottomBar::setBtnHeight(VfxS32 height)
{
    m_btnL1Size.height = height;
#if defined(__MMI_COSMOS_PHOTOEDITOR__)
    m_btnL2Size.height = height;
#endif
}

void VcpImgEdtBottomBar::setVisibleMode(VfxBool if_full)
{
    VfxMainScr *scr = VfxMainScr::findMainScr(getParentFrame());
    VfxSize scrSize = scr->getSize();
    if (if_full)
    {
        VfxFrame::setPos(VfxPoint(0, scrSize.height - m_bgSize.height + 1));
    }
    else
    {
        VfxFrame::setPos(VfxPoint(0, scrSize.height - m_btnL1Size.height + 1));
    }

    for (VfxS32 i = 0; i < m_btnNumL1; i++)
    {
        m_btnArrayL1[i]->updatePos();
    }
    VfxRect rect = m_btnOK->getRect();
    m_btnOK->setRect(rect);
    rect = m_btnBack->getRect();
    m_btnBack->setRect(rect);
}

void VcpImgEdtBottomBar::setDisabled(VfxBool isDisabled)
{
    m_btnOK->setIsDisabled(isDisabled);
    m_btnBack->setIsDisabled(isDisabled);
    for (VfxS32 i = 0; i < m_btnNumL1 ; i++)
    {
        m_btnArrayL1[i]->setDisabled(isDisabled);
    }
    for (VfxS32 i = 0; i < m_btnNumL2 ; i++)
    {
        m_btnArrayL2[i]->setDisabled(isDisabled);
    }
}

void VcpImgEdtBottomBar::setDisabled(VfxS32 btnId, VfxBool isDisabled)
{
    if (BOTTOM_BTN_TYPE_OK == btnId)
    {
        m_btnOK->setIsDisabled(isDisabled);
    }
    else if (BOTTOM_BTN_TYPE_CANCEL == btnId)
    {
        m_btnBack->setIsDisabled(isDisabled);
    }
}

void VcpImgEdtBottomBar::setDownState(VfxBool isLevel1, VfxS32 btnId)
{
    if (isLevel1)
    {
        for (VfxS32 i = 0; i < m_btnNumL1 ; i++)
        {
            if (m_btnArrayL1[i]->getId() == btnId)
            {
                m_btnArrayL1[i]->setStateDown(VFX_TRUE);
            }
            else
            {
                m_btnArrayL1[i]->setStateDown(VFX_FALSE);
            }
        }
    }
    else
    {
        for (VfxS32 i = 0; i < m_btnNumL2 ; i++)
        {
            if (m_btnArrayL2[i]->getId() == btnId)
            {
                m_btnArrayL2[i]->setStateDown(VFX_TRUE);
            }
            else
            {
                m_btnArrayL2[i]->setStateDown(VFX_FALSE);
            }
        }
    }
}

void VcpImgEdtBottomBar::clearDownState(VfxBool isLevel1, VfxS32 exceptId)
{
    if (isLevel1)
    {
        for (VfxS32 i = 0; i < m_btnNumL1 ; i++)
        {
            if (m_btnArrayL1[i]->getId() != exceptId)
            {
                m_btnArrayL1[i]->setStateDown(VFX_FALSE);
            }
        }
    }
    else
    {
        for (VfxS32 i = 0; i < m_btnNumL2 ; i++)
        {
            if (m_btnArrayL2[i]->getId() != exceptId)
            {
                m_btnArrayL2[i]->setStateDown(VFX_FALSE);
            }
        }
    }
}

void VcpImgEdtBottomBar::onBtnTaped(VfxObject *obj, VfxId id)
{
    m_signalBtnTap.emit(obj, id);
}

void VcpImgEdtBottomBar::setBtnHilit(VfxS32 btn_id, VfxBool isHilit)
{
    if (getHidden())
    {
        return;
    }

    VcpImageButton *btn;
    if (BOTTOM_BTN_TYPE_OK == btn_id)
    {
        btn = m_btnOK;
    }
    else
    {
        btn = m_btnBack;
    }
    if (!btn->getIsDisabled())
    {
        if (isHilit)
        {
            btn->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
        }
        else
        {
            btn->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
        }
    }
}

VfxS32 VcpImgEdtBottomBar::getbtnNum(VfxS32 level)
{
	if((BottomBtnLevel)level==BOTTOM_BTN_L1)
	{
		return m_btnNumL1;
	}
	else 
	{
		return m_btnNumL2;
	}
}

VfxBool VcpImgEdtBottomBar::onPenInput(VfxPenEvent & event)
{
    //Don't pass pen input event to parent frame
    return VFX_TRUE;
}

/***************************************************************************** 
 * Class VappImgEdtBaseScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappImgEdtBaseScr", VappImgEdtBaseScr, VfxMainScr);

VappImgEdtBaseScr::VappImgEdtBaseScr()
{
    m_scrRotate = VFX_SCR_ROTATE_TYPE_0;
}

void VappImgEdtBaseScr::getHaloSize(const VfxSize &btnSize, VfxSize &haloSize)
{
    if (((18 == btnSize.width) && (18 == btnSize.height)) ||
        ((13 == btnSize.width) && (14 == btnSize.height)) ||
        ((20 == btnSize.width) && (21 == btnSize.height)))
    {
        haloSize = VfxSize(45, 45);
    }
    else if (((36 == btnSize.width) && (36 == btnSize.height)) ||
             ((34 == btnSize.width) && (34 == btnSize.height)) ||
             ((32 == btnSize.width) && (32 == btnSize.height)) ||
             ((27 == btnSize.width) && (27 == btnSize.height)) ||
             ((27 == btnSize.width) && (21 == btnSize.height)) ||
             ((21 == btnSize.width) && (27 == btnSize.height)) ||
             ((23 == btnSize.width) && (23 == btnSize.height)) ||
             ((28 == btnSize.width) && (28 == btnSize.height)))
    {
        haloSize = VfxSize(56, 56);
    }
    else if (((37 == btnSize.width) && (37 == btnSize.height)) ||
             ((40 == btnSize.width) && (40 == btnSize.height)))
    {
        haloSize = VfxSize(70, 70);
    }
    else if ((60 == btnSize.width) && (60 == btnSize.height))
    {
        haloSize = VfxSize(80, 80);    
    }
    else if ((48 == btnSize.width) && (48 == btnSize.height))
    {
        haloSize = VfxSize(76, 76);
    }
    else
    {
        haloSize = VfxSize(67, 67);
    }
}

VfxBool VappImgEdtBaseScr::checkVertMode()
{
    switch (m_scrRotate)
    {
    case VFX_SCR_ROTATE_TYPE_90:
    case VFX_SCR_ROTATE_TYPE_270:
        return VFX_FALSE;

    case VFX_SCR_ROTATE_TYPE_0:
    default:
        return VFX_TRUE;
    }
}

void VappImgEdtBaseScr::setScrRotate(VfxScrRotateTypeEnum rot)
{
    m_scrRotate = rot;
}

VfxScrRotateTypeEnum VappImgEdtBaseScr::getScrRotate()
{
    return m_scrRotate;
}

#endif /* defined(__MMI_COSMOS_PHOTOEDITOR__) || defined(__MMI_COSMOS_IMAGECLIPPER__) */

