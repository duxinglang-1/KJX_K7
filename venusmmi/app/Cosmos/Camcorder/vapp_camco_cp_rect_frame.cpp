/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
#include "vapp_camco_cp_rect_frame.h"

#ifdef __VAPP_CAMCO__

void VappCamcoCpRect::onInit()
{
    VfxControl::onInit();
    
    VFX_OBJ_CREATE(m_leftTop, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_rightTop, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_leftToe, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_rightToe, VfxImageFrame, this);        
    
    m_leftTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL1_ICON);
    m_rightTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL2_ICON);
    m_leftToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL3_ICON);
    m_rightToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL4_ICON);         

    m_leftTop->setAnchor(0.5, 0.5);
    m_rightTop->setAnchor(0.5, 0.5);
    m_leftToe->setAnchor(0.5, 0.5);
    m_rightToe->setAnchor(0.5, 0.5);
    
}

void VappCamcoCpRect::setMode(vapp_camco_cp_rect_type_enum type, vapp_camco_cp_rect_mode_enum mode)
{
    m_mode = mode;
    m_type = type;    
    if(m_type == VAPP_CAMCO_CP_RECT_TYPE_FD)
    {
        if(mode == VAPP_CAMCO_CP_RECT_MODE_NORMAL)
        {
            m_leftTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL1_ICON);
            m_rightTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL2_ICON);
            m_leftToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL4_ICON);
            m_rightToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL3_ICON);   
        }
        else if(mode == VAPP_CAMCO_CP_RECT_MODE_SUCCESS)
        {
            m_leftTop->setResId(IMG_ID_VAPP_CAMCO_RECT_FD_SUCCESS1_ICON);
            m_rightTop->setResId(IMG_ID_VAPP_CAMCO_RECT_FD_SUCCESS2_ICON);
            m_leftToe->setResId(IMG_ID_VAPP_CAMCO_RECT_FD_SUCCESS4_ICON);
            m_rightToe->setResId(IMG_ID_VAPP_CAMCO_RECT_FD_SUCCESS3_ICON);               
        }
    }
    else if(m_type == VAPP_CAMCO_CP_RECT_TYPE_SD)
    {
        if(mode == VAPP_CAMCO_CP_RECT_MODE_NORMAL)
        {
            m_leftTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL1_ICON);
            m_rightTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL2_ICON);
            m_leftToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL4_ICON);
            m_rightToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL3_ICON);   
        }
        else if(mode == VAPP_CAMCO_CP_RECT_MODE_SUCCESS)
        {
            m_leftTop->setResId(IMG_ID_VAPP_CAMCO_RECT_SD_SUCCESS1_ICON);
            m_rightTop->setResId(IMG_ID_VAPP_CAMCO_RECT_SD_SUCCESS2_ICON);
            m_leftToe->setResId(IMG_ID_VAPP_CAMCO_RECT_SD_SUCCESS4_ICON);
            m_rightToe->setResId(IMG_ID_VAPP_CAMCO_RECT_SD_SUCCESS3_ICON);               
        }
    }
    else if(m_type == VAPP_CAMCO_CP_RECT_TYPE_AF)
    {
        if(mode == VAPP_CAMCO_CP_RECT_MODE_NORMAL)
        {
            m_leftTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL1_ICON);
            m_rightTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL2_ICON);
            m_leftToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL4_ICON);
            m_rightToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_NORMAL3_ICON);   
        }
        else if(mode == VAPP_CAMCO_CP_RECT_MODE_SUCCESS)
        {
            m_leftTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_SUCCESS1_ICON);
            m_rightTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_SUCCESS2_ICON);
            m_leftToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_SUCCESS4_ICON);
            m_rightToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_SUCCESS3_ICON);               
        }
        else if(mode == VAPP_CAMCO_CP_RECT_MODE_FAIL)
        {
            m_leftTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_FAIL1_ICON);
            m_rightTop->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_FAIL2_ICON);
            m_leftToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_FAIL4_ICON);
            m_rightToe->setResId(IMG_ID_VAPP_CAMCO_RECT_AF_FAIL3_ICON);               
        }        
    }    
}

void VappCamcoCpRect::setSize(VfxS32 width, VfxS32 height)
{
    VfxControl::setSize(width, height);    
    updateLayout();
}

void VappCamcoCpRect::updateLayout(void)
{
    VfxU32 x = getPos().x;
    VfxU32 y = getPos().y;
    VfxU32 w = getSize().width;
    VfxU32 h = getSize().height;        

    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_OSD_CP_RECT_UPDATE, x, y, w, h);
    
    m_leftTop->setPos(0.5*m_leftTop->getSize().width, 0.5*m_leftTop->getSize().height);
    m_rightTop->setPos(w - 0.5*m_rightTop->getSize().width, 0.5*m_rightTop->getSize().height);
    m_leftToe->setPos(0.5*m_leftToe->getSize().width, h - 0.5*m_leftToe->getSize().height);
    m_rightToe->setPos(w - 0.5*m_rightTop->getSize().width, h - 0.5*m_rightToe->getSize().height);
}

#endif