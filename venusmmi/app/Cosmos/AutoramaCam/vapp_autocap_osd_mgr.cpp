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

#include "vapp_autocap_osd_mgr.h"
#include "vapp_autocap_app.h"
#include "MMI_include.h"

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))

void AutoCapOSDMgr::onInit(void)
{
    VfxControl::onInit();
    
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_OSD_STATE_END; i++)
    {
        m_stateList[i] = NULL;
    }

    VFX_OBJ_CREATE(m_stateList[0], AutoCapOSDHideState, this);
    VFX_OBJ_CREATE(m_stateList[1], AutoCapOSDHinteState, this);
    VFX_OBJ_CREATE(m_stateList[2], AutoCapOSDCamPreviewState, this);
    VFX_OBJ_CREATE(m_stateList[3], AutoCapOSDCamQuickViewState, this);
    VFX_OBJ_CREATE(m_stateList[4], AutoCapOSDCamPanoramaShotState, this);
    VFX_OBJ_CREATE(m_stateList[5], AutoCapOSDCamPanoramaClipState, this);

    // enter hide state
    m_CurrectState = m_stateList[0];
    vapp_autocap_osd_hide_param_struct param;
    param.isCleanBG = VFX_TRUE;
    m_CurrectState->enterState(&param);
    m_CurrectState->setHidden(VFX_TRUE); 
    setBgColor(VFX_COLOR_TRANSPARENT);
    setSize(1000, 1000);
    setPos(0, 0);    
    

}

void AutoCapOSDMgr::enterState(vapp_autocap_osd_state_enum state, void* param, VappAutoCapOSDEvtHdlr* evtHdlr)
{
    VfxS32 enterStateIdx = -1;
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_OSD_ENTER_STATE, state);

    for(VfxU16 i = 0; i < VAPP_AUTOCAP_OSD_STATE_END; i++)
    {
        if(m_stateList[i] == NULL)
            continue;
        
        if(m_stateList[i]->getStateName() == state)
        {
            enterStateIdx = i;
        }     
        else
        {
            m_stateList[i]->exitState();               
        }
    }
    if(enterStateIdx >= 0)
    {
        m_CurrectState = m_stateList[enterStateIdx];
        
        // set evetn handlet should before enter state
        // it may need to send event in enter state funtcion
        if(evtHdlr != NULL)
            m_CurrectState->regEvtHdlr(evtHdlr);
        
        m_CurrectState->enterState(param);    
    
    }

}

void AutoCapOSDMgr::exitState(void)
{
    // it may starting App so not OSD state
    //ASSERT(m_CurrectState != NULL);

    if(m_CurrectState != NULL)
        m_CurrectState->exitState();

    m_CurrectState = NULL;
}

void AutoCapOSDMgr::updateScreen(void)
{
    m_CurrectState->updateScreen();
}

void AutoCapOSDMgr::clean(void)
{
    m_CurrectState->clean(VRT_COLOR_TRANSPARENT);
}


void AutoCapOSDMgr::drawBase(vapp_autocap_osd_draw_image_struct param)
{
    m_CurrectState->drawBase(param);

}

void AutoCapOSDMgr::setAutoExitTimer(VfxTimer* t)
{
    m_autoExitTimer = t;
    
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_OSD_STATE_END; i++)
    {
        if(m_stateList[i])
        {
            m_stateList[i]->setAutoExitTimer(t);
        }
    }    
}

void AutoCapOSDMgr::setScreenParam(vapp_autocap_osd_screen_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_OSD_SET_PARAM, param.type);

    switch(param.type)
    {        
        case VAPP_AUTOCAP_OSD_SCR_PARAM_SET_FOCUS:
        {         
            if(m_CurrectState->getStateName() == VAPP_AUTOCAP_OSD_STATE_CAMERA_PREVIEW)
            {
                ((AutoCapOSDCamPreviewState*)m_CurrectState)->setFocus(param.index, param.focus);
            }
            break;
        }      
        case VAPP_AUTOCAP_OSD_SCR_PARAM_RESET_FOCUS:
        {
            if(m_CurrectState->getStateName() == VAPP_AUTOCAP_OSD_STATE_CAMERA_PREVIEW)
            {
                ((AutoCapOSDCamPreviewState*)m_CurrectState)->cleanFocus();
            }
            break;
        }
        case VAPP_AUTOCAP_OSD_SCR_PARAM_ZOOM_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_AUTOCAP_OSD_STATE_CAMERA_PREVIEW)    
            {
                ((AutoCapOSDCamPreviewState*)m_CurrectState)->updateZoomParam(param.zoom_value);
            }             
            break;
        }
        case VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_DIR_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT)    
            {
                ((AutoCapOSDCamPanoramaShotState*)m_CurrectState)->setDirection(param.direction);         
                
            }                   
            break;
        }            
        case VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_RATIO_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT)    
            {
                ((AutoCapOSDCamPanoramaShotState*)m_CurrectState)->setRatio(param.ratio);         
                
            }                   
            break;
        }             
        case VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_MV_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT)    
            {
                ((AutoCapOSDCamPanoramaShotState*)m_CurrectState)->setMotion(param.motionX, param.motionY);         
                
            }                   
            break;
        }             
        case VAPP_AUTOCAP_OSD_SCR_PARAM_SET_BUSY:
        {
            m_CurrectState->setisBusy(param.isBusy);
            break;            
        }
        default:
            ASSERT(0);
    }
}

#endif
