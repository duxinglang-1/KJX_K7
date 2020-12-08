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

#include "vapp_camco_slim_osd_mgr.h"
#include "vapp_camco_slim_app.h"
#include "MMI_include.h"

#ifdef __VAPP_CAMCO_SLIM__

#pragma arm section code = "DYNAMIC_CODE_CAMCO_ROCODE", rodata = "DYNAMIC_CODE_CAMCO_RODATA"

void CamcoOSDMgr::onInit(void)
{
    VfxControl::onInit();

    for(VfxU16 i = 0; i < VAPP_CAMCO_OSD_STATE_END; i++)
    {
        m_stateList[i] = NULL;
    }

    VFX_OBJ_CREATE(m_stateList[0], OSDHideState, this);
    VFX_OBJ_CREATE(m_stateList[1], OSDHinteState, this);
    VFX_OBJ_CREATE(m_stateList[2], OSDCamPreviewState, this);
    VFX_OBJ_CREATE(m_stateList[3], OSDRecPreviewState, this);
    VFX_OBJ_CREATE(m_stateList[4], OSDRecRecordingState, this);
    VFX_OBJ_CREATE(m_stateList[5], OSDRecPauseState, this);
    VFX_OBJ_CREATE(m_stateList[6], OSDQuickViewState, this);

    // enter hide state firstly, or it will get error wben enter the 1st state later
    m_CurrectState = m_stateList[0];
    vapp_camco_osd_hide_param_struct param;
    param.isCleanBG = VFX_TRUE;
    m_CurrectState->enterState(&param);
    m_CurrectState->setHidden(VFX_TRUE);
    setBgColor(VFX_COLOR_TRANSPARENT);
    setSize(1000, 1000);
    setPos(0, 0);
}

void CamcoOSDMgr::enterState(vapp_camco_osd_state_enum state, void* param, VappCamcoOSDEvtHdlr* evtHdlr)
{
    VfxS32 enterStateIdx = -1;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_OSD_ENTER_STATE, state);

    // exit all others state
    for(VfxU16 i = 0; i < VAPP_CAMCO_OSD_STATE_END; i++)
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
            m_stateList[i]->regEvtHdlr(NULL);
        }
    }
    // enter current state
    if(enterStateIdx >= 0)
    {
        m_CurrectState = m_stateList[enterStateIdx];

        // set evetn handlet should before enter state
        // it may need to send event in enter state funtcion
        if(evtHdlr != NULL)
            m_CurrectState->regEvtHdlr(evtHdlr);

        m_CurrectState->m_isOnEnter = VFX_TRUE;
        m_CurrectState->enterState(param);
        m_CurrectState->m_isOnEnter = VFX_FALSE;
    }

}

void CamcoOSDMgr::exitState(void)
{
    // it may starting App so not OSD state
    //ASSERT(m_CurrectState != NULL);

    if(m_CurrectState != NULL)
        m_CurrectState->exitState();

    m_CurrectState->regEvtHdlr(NULL);
    m_CurrectState = NULL;
}

void CamcoOSDMgr::drawBase(vapp_camco_osd_draw_image_struct param)
{
    m_CurrectState->drawBase(param);
}

void CamcoOSDMgr::setAutoExitTimer(VfxTimer* t)
{
    m_autoExitTimer = t;

    for(VfxU16 i = 0; i < VAPP_CAMCO_OSD_STATE_END; i++)
    {
        if(m_stateList[i])
        {
            m_stateList[i]->setAutoExitTimer(t);
        }
    }
}

void CamcoOSDMgr::setScreenParam(vapp_camco_osd_screen_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_OSD_SET_PARAM, param.type);

    switch(param.type)
    {
        case VAPP_CAMCO_OSD_SCR_PARAM_RECORDING_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_CAMCO_OSD_STATE_VIDEO_RECORDING)
            {
                ((OSDRecRecordingState*)m_CurrectState)->setRecParam(param.rec_time,param.rec_size);
            }
            break;
        }
        case VAPP_CAMCO_OSD_SCR_PARAM_ZOOM_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW)
            {
                ((OSDCamPreviewState*)m_CurrectState)->updateZoomParam(param.zoom_value);
            }
            break;
        }
        case VAPP_CAMCO_OSD_SCR_PARAM_REC_REMAIN_SIZE_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW)
            {
                ((OSDRecPreviewState*)m_CurrectState)->updateRemainSizeParam(param.remain_size);
            }
            break;
        }
        case VAPP_CAMCO_OSD_SCR_PARAM_CAM_THUMBNAIL_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW)
            {
                ((OSDCamPreviewState*)m_CurrectState)->updateThumbnail(param.previousFileName);
            }
            break;
        }
        case VAPP_CAMCO_OSD_SCR_PARAM_REC_THUMBNAIL_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW)
            {
                ((OSDRecPreviewState*)m_CurrectState)->updateThumbnail(param.previousFileName);
            }
            break;
        }
        case VAPP_CAMCO_OSD_SCR_PARAM_IND_MSG_UPDATE:
        {
            if(m_CurrectState->getStateName() == VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW)
            {
                ((OSDCamPreviewState*)m_CurrectState)->updateIndicatorMsg(param.indicator_string);
            }
            else if(m_CurrectState->getStateName() == VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW)
            {
                ((OSDRecPreviewState*)m_CurrectState)->updateIndicatorMsg(param.indicator_string);
            }
            break;
        }
        case VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY:
        {

            m_CurrectState->setStatus(param.isBusy, VAPP_CAMCO_OSD_STATE_STATUS_ISAPPBUSY);
            break;
        }
        case VAPP_CAMCO_OSD_SCR_PARAM_SET_ROT:
        {
            for(VfxU16 i = 0; i < VAPP_CAMCO_OSD_STATE_END; i++)
            {
                if(m_stateList[i] == NULL)
                    continue;

                m_stateList[i]->setHorz(param.isHorz, param.isMirror);
            }
            break;
        }
        default:
            ASSERT(0);
    }
}
#pragma arm section code, rodata

#endif /*__VAPP_CAMCO_SLIM__*/
