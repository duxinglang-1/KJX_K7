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
*  vapp_cube_media_player.cpp
*
* Project:
* --------
*  Venus
*
* Description:
* ------------
*  Media Player Cube Screen
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
 #include "MMI_Features.h"

#ifdef __MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__

#include "vfx_uc_include.h"
#include "vapp_cube_res.h"
#include "vapp_cube_media_player.h"
#include "CubeApp\vadp_v2p_cube_media_player.h"

#include "MediaAppWidgetDef.h"
#include "interface\trc\vadp_app_trc.h"

#ifdef MMI_CUBE_LITE
#ifndef  MMI_CUBE_MEDPLY_LITE
#define MMI_CUBE_MEDPLY_LITE
#endif
#endif

/***************************************************************************** 
* Variable Definition
*****************************************************************************/
static cube_medply_plymode_layout_struct *g_plyt = &g_cube_medply_plymode_layout;
static cube_medply_navmode_layout_struct *g_nlyt = &g_cube_medply_navmode_layout;


/***************************************************************************** 
* Function Definition
*****************************************************************************/
VfxBool VappCubeMediaPlayerState::set(VfxU8 s)
{

    if (m_state < IDLE)
    {
        return  VFX_FALSE;
    }
    if (m_state > END_OF_STATE)
    {
        return  VFX_FALSE;
    }    
    m_state = s;
    
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_SET_STATE, m_state);    

    return VFX_TRUE;
}
/*****************************************************************************
* Class VappCubeMediaPlayerButton
*****************************************************************************/

VappCubeMediaPlayerButton::VappCubeMediaPlayerButton() : m_image(NULL), m_bgImage(NULL)
{ 
}


VappCubeMediaPlayerButton::~VappCubeMediaPlayerButton()
{
    
}

void VappCubeMediaPlayerButton::onInit(void)
{
    VfxControl::onInit();
    
    m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_bgImage, VfxImage, this);
}


void VappCubeMediaPlayerButton::onDeinit(void)
{
    VfxControl::onDeinit();
}


void VappCubeMediaPlayerButton::setImage(VfxS32 upImageId,VfxS32 downImageId)
{
    m_imageUpId= upImageId;
    m_imageDownId = downImageId;
    
    m_bgImage->setResId(upImageId);
    this->setContent(m_bgImage);
    invalidate();
    setIsCached(VFX_TRUE); 
    m_image->setResId(downImageId);
    m_image->setIsCached(VFX_TRUE);
    m_image->setHidden(VFX_TRUE);
    setBounds(m_image->getBounds());
}

void VappCubeMediaPlayerButton::getImage(VfxS32 *p_upImageId, VfxS32 *P_downImageId)
{
    *p_upImageId = m_imageUpId;
    *P_downImageId = m_imageDownId;
    
}

void VappCubeMediaPlayerButton::setDisplay(VfxBool isDisplay)
{
    if (isDisplay)
    {
        setHidden(VFX_FALSE);
    }
    else
    {
        setHidden(VFX_TRUE);
    }
}

void VappCubeMediaPlayerButton::setIsDisabled(VfxBool isDisabled)
{
    if (isDisabled)
    {
        setAutoAnimate(VFX_FALSE);
        setOpacity(0.5);    
    }
    else
    {     
        setAutoAnimate(VFX_TRUE);
        setOpacity(1.0);
    }

    VfxControl::setIsDisabled(isDisabled);
}

VfxBool VappCubeMediaPlayerButton::getIsDisabled()
{
    return VfxControl::getIsDisabled();
}


VfxBool VappCubeMediaPlayerButton::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos(event.getRelPos(this));
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;
        m_image->setHidden(VFX_FALSE);        
        m_eventPenDown.emit(event);
        
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
        
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;
        return VFX_FALSE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
		if (m_curr_pentype == VFX_PEN_EVENT_TYPE_DOWN)
		{
			m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
			m_image->setHidden(VFX_TRUE);       
			m_eventPenUp.emit(event);
			return VFX_TRUE;
		}

    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (containPoint(pos))
        {
            m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;
            m_image->setHidden(VFX_FALSE);  
        }
        else
        {
            m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
            m_image->setHidden(VFX_TRUE);
            
        }
        return VFX_TRUE;
    }
    m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
    return VfxControl::onPenInput(event);
}


VfxS32 VappCubeMediaPlayerButton::getPenType(void)
{
    return m_curr_pentype;
}


void VappCubeMediaPlayerButton::setPenType(VfxS32 PenType)
{
    m_curr_pentype = PenType;
    if (PenType == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_image->setHidden(VFX_FALSE); 
    }
    else
    {
        m_image->setHidden(VFX_TRUE); 
    }
}

/*****************************************************************************
* Class VappCubeMediaPlayerProgress
*****************************************************************************/


VappCubeMediaPlayerProgress::VappCubeMediaPlayerProgress() : m_ratio(0)
{
    
}


VappCubeMediaPlayerProgress::~VappCubeMediaPlayerProgress()
{
    
}


void VappCubeMediaPlayerProgress::onInit()
{
    VfxFrame::onInit();
    
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageFg, VfxImageFrame, this);
}


void VappCubeMediaPlayerProgress::onDeinit()
{   
    VfxFrame::onDeinit();
}


void VappCubeMediaPlayerProgress::onDraw(VfxDrawContext &dc)
{
    VfxRect size;
    VfxS32 progress_width;
    
    size = m_imageBg->getBounds();
    progress_width = (size.getWidth()* m_ratio)/1000;
    
    dc.setClip(VfxRect(0, 0, size.getWidth(), size.getHeight()));
    dc.drawImageFromMem(0, 0, (const void*)vrt_sys_res_image_lock(m_imageBgId));
    
    dc.setClip(VfxRect(0, 0,progress_width, size.getHeight()));
    dc.drawImageFromMem(0, 0, (const void*)vrt_sys_res_image_lock(m_imageFgId));
}


void VappCubeMediaPlayerProgress::setRatio(VfxS32 ratio)
{
    if (ratio > 1000)
    {
        ratio = 1000;
    }
    m_ratio = ratio;
    invalidate();
}


VfxS32 VappCubeMediaPlayerProgress::getRatio(void) const
{
    return m_ratio;
}


void VappCubeMediaPlayerProgress::setImage(VfxS32 bgImage,VfxS32 fgImage)
{
    m_imageFgId = fgImage;
    m_imageBgId = bgImage;
    
    m_imageFg->setResId(fgImage);
    m_imageBg->setResId(bgImage);
    
    setBounds(m_imageBg->getBounds()); 
}

/*****************************************************************************
* Class VappCubeMediaPlayerTime
*****************************************************************************/


VappCubeMediaPlayerTime::VappCubeMediaPlayerTime()
: m_hour(0),
m_min(0),
m_sec(0),
m_h1(NULL),
m_h2(NULL),
m_m1(NULL),
m_m2(NULL),
m_s1(NULL),
m_s2(NULL),
m_colon1(NULL),
m_colon2(NULL),
m_imageH1(NULL), 
m_imageH2(NULL),
m_imageM1(NULL), 
m_imageM2(NULL), 
m_imageS1(NULL), 
m_imageS2(NULL), 
m_imageColon(NULL),
m_isLayouted(VFX_FALSE)
{
    
}


VappCubeMediaPlayerTime::~VappCubeMediaPlayerTime()
{
    
}


void VappCubeMediaPlayerTime::onInit()
{
    VfxFrame::onInit(); 

    VFX_OBJ_CREATE(m_imageH1, VfxImage, this);
    VFX_OBJ_CREATE(m_imageH2, VfxImage, this);    
    VFX_OBJ_CREATE(m_imageM1, VfxImage, this);
    VFX_OBJ_CREATE(m_imageM2, VfxImage, this);
    VFX_OBJ_CREATE(m_imageColon, VfxImage, this);
    VFX_OBJ_CREATE(m_imageS1, VfxImage, this);    
    VFX_OBJ_CREATE(m_imageS2, VfxImage, this);
    
    m_imageColon->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_COLON);
    m_imageH1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0);
    m_imageH2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0);
    m_imageM1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0);
    m_imageM2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0);
    m_imageS1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0);
    m_imageS2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0);
    
}

void VappCubeMediaPlayerTime::onDeinit()
{
    VfxFrame::onDeinit();
}

void VappCubeMediaPlayerTime::setTime(VfxS32 hour, VfxS32 min, VfxS32 sec)
{
    VfxS32 h1 = 0;
    VfxS32 h2 = 0;
    VfxS32 m1 = 0;
    VfxS32 m2 = 0;
    VfxS32 s1 = 0;
    VfxS32 s2 = 0;
    

    
    if (m_hour != hour)
    {
        m_hour = hour;
        h1 = m_hour/10;
        h2 = m_hour%10;
        m_imageH1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + h1);
        m_imageH2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + h2); 
        m_h1->invalidate();
        m_h2->invalidate();       
    }
    
    if (m_min != min)
    {
        m_min = min;
        m1 = m_min/10;
        m2 = m_min%10;
        m_imageM1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + m1);
        m_imageM2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + m2); 
        m_m1->invalidate();
        m_m2->invalidate();       
    }
    
    if (m_sec != sec)
    {
        m_sec = sec;  
        s1 = m_sec/10;
        s2 = m_sec%10; 
        m_imageS1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + s1);
        m_imageS2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + s2); 
        m_s1->invalidate();
        m_s2->invalidate();        
    }
    
}

void VappCubeMediaPlayerTime::setTime(VfxS32 s)
{
    
    if (m_totalSec == s)
    {
        return;
    }
    
    VfxS32 hour;
    VfxS32 hour_remain;
    VfxS32 min;
    VfxS32 sec;
    VfxS32 h1 = 0;
    VfxS32 h2 = 0;
    VfxS32 m1 = 0;
    VfxS32 m2 = 0;
    VfxS32 s1 = 0;
    VfxS32 s2 = 0;
    
    m_totalSec = s;
    hour = (VfxS32)(m_totalSec / 3600);
    hour_remain = (VfxS32)(m_totalSec % 3600);
    min = hour_remain / 60;
    sec = hour_remain % 60; 
    
    if (m_hour != hour)
    {
        m_hour = hour;
        h1 = m_hour/10;
        h2 = m_hour%10;
        m_imageH1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + h1);
        m_imageH2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + h2); 
        m_h1->invalidate();
        m_h2->invalidate();       
    }
    
    if (m_min != min)
    {
        m_min = min;
        m1 = m_min/10;
        m2 = m_min%10;
        m_imageM1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + m1);
        m_imageM2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + m2); 
        m_m1->invalidate();
        m_m2->invalidate();       
    }
    
    if (m_sec != sec)
    {
        m_sec = sec;  
        s1 = m_sec/10;
        s2 = m_sec%10; 
        m_imageS1->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + s1);
        m_imageS2->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_NUM_0 + s2); 
        m_s1->invalidate();
        m_s2->invalidate();        
    }
}


void VappCubeMediaPlayerTime::getTime(VfxS32* hourP, VfxS32* minP, VfxS32* secP)
{
    *hourP = m_hour;
    *minP = m_min;
    *secP = m_sec;
}

void VappCubeMediaPlayerTime::getTime(VfxS32* p_total)
{
    *p_total = m_totalSec;
}

void VappCubeMediaPlayerTime::layout()
{
    VfxS32 offsetX;
    
    VfxPoint pst;
    VfxSize  sz;
    
    if (m_isLayouted)
    {
        return;
    }
    
    m_isLayouted = VFX_TRUE;
    
    pst = this->getPos();
    offsetX = 0;
    VFX_OBJ_CREATE(m_h1, VfxFrame, this);
    m_h1->setPos(VfxPoint(offsetX , 0));    
    sz = m_imageH1->getSize();
    offsetX += sz.width;
    m_h1->setBounds(VfxRect(0, 0, sz.width, sz.height));
    
    
    VFX_OBJ_CREATE(m_h2, VfxFrame, this);
    m_h2->setPos(VfxPoint(offsetX , 0));    
    sz = m_imageH2->getSize();
    offsetX += sz.width;
    m_h2->setBounds(VfxRect(0, 0, sz.width, sz.height));
    
    VFX_OBJ_CREATE(m_colon1, VfxFrame, this);
    m_colon1->setPos(VfxPoint(offsetX , 0));  
    sz = m_imageColon->getSize();   
    offsetX += sz.width;
    m_colon1->setBounds(VfxRect(0, 0, sz.width, sz.height));
        
    VFX_OBJ_CREATE(m_m1, VfxFrame, this);
    m_m1->setPos(VfxPoint(offsetX , 0));    
    sz = m_imageM1->getSize();
    offsetX += sz.width;
    m_m1->setBounds(VfxRect(0, 0, sz.width, sz.height));
    
    
    VFX_OBJ_CREATE(m_m2, VfxFrame, this);
    m_m2->setPos(VfxPoint(offsetX , 0));    
    sz = m_imageM2->getSize();
    offsetX += sz.width;
    m_m2->setBounds(VfxRect(0, 0, sz.width, sz.height));
    
    VFX_OBJ_CREATE(m_colon2, VfxFrame, this);
    m_colon2->setPos(VfxPoint(offsetX , 0));  
    sz = m_imageColon->getSize();   
    offsetX += sz.width;
    m_colon2->setBounds(VfxRect(0, 0, sz.width, sz.height));
    
    VFX_OBJ_CREATE(m_s1, VfxFrame, this);
    m_s1->setPos(VfxPoint(offsetX , 0));  
    sz = m_imageS1->getSize();
    offsetX += sz.width;
    m_s1->setBounds(VfxRect(0, 0, sz.width, sz.height));
    
    VFX_OBJ_CREATE(m_s2, VfxFrame, this);
    m_s2->setPos(VfxPoint(offsetX , 0));  
    sz = m_imageS2->getSize();
    offsetX += sz.width;
    m_s2->setBounds(VfxRect(0, 0, sz.width, sz.height)); 

    
    m_h1->setContent(m_imageH1);
    m_h2->setContent(m_imageH2);    
    m_m1->setContent(m_imageM1);
    m_m2->setContent(m_imageM2);
    m_s1->setContent(m_imageS1);
    m_s2->setContent(m_imageS2);
    m_colon1->setContent(m_imageColon);
    m_colon2->setContent(m_imageColon);
}

void VappCubeMediaPlayerTime::clear()
{
    if (!m_isLayouted)
    {
        return;
    }
    
    m_isLayouted = VFX_FALSE;
    
}

/*****************************************************************************
* Class VappCubeMediaPlayerAgent
*****************************************************************************/
VappCubeMediaPlayerAgent::VappCubeMediaPlayerAgent()
: m_state(0),
m_durationMsec(0),
m_currTimeMsec(0),
m_curPlayIndex(-1),
m_lastPlayIndex(-1),
m_shuffle(VFX_FALSE),
m_repeatOne(VFX_FALSE),
m_repeatAll(VFX_FALSE),
m_repeatOff(VFX_FALSE),
m_total(0),
m_isListEnd(VFX_FALSE),
m_isWaitState(VFX_FALSE),
m_isWaitPause(VFX_FALSE)
{
    
}

void VappCubeMediaPlayerAgent::playerCallback(void* userdata, VfxU32 type, void* resultP)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappCubeMediaPlayerAgent* this_ptr = (VappCubeMediaPlayerAgent*) userdata;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK)
    {
        this_ptr->onStatusChanged(resultP);
    }
    else if (type == MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK)
    {
        this_ptr->onMediaChanged(resultP);
    }
    else if (type == MMI_WIDGET_PLAYER_PLAY_END_CALLBACK)
    {
        this_ptr->onPlayEnd(resultP);
    }
    else if (type == MMI_WIDGET_PLAYER_LIST_END_CALLBACK)
    {
        this_ptr->onListEnd(resultP);    
    }
    else if (type == MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK)
    {
        this_ptr->onResetCurTime(resultP); 
    }
   
    
}

void VappCubeMediaPlayerAgent::onInit()
{   
    VfxS32 shuffle;
    VfxS32 repeatOne;
    VfxS32 repeatAll;
    VfxS32 repeatOff;
    
    VfxObject::onInit();    

    m_isTimerStart = VFX_FALSE;  
    
    m_total = vadp_v2p_cube_media_player_get_item_count(); 
    // get repeat and shuffle, and than set to list service
    vadp_v2p_cube_media_player_get_repeat(&repeatOne, &repeatAll, &repeatOff);
    vadp_v2p_cube_media_player_get_shuffle(&shuffle);
    
    m_repeatOne = (repeatOne? VFX_TRUE : VFX_FALSE);
    m_repeatAll = (repeatAll? VFX_TRUE : VFX_FALSE);
    m_repeatOff = (repeatOff? VFX_TRUE : VFX_FALSE);
    m_shuffle = (shuffle? VFX_TRUE : VFX_FALSE); 	
    //setRepeat(m_repeatOne, m_repeatAll, m_repeatOff);
    //setShuffle(m_shuffle);
    
    m_curPlayIndex = vadp_v2p_cube_media_player_get_active_index();
    m_lastPlayIndex = m_curPlayIndex;
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX, m_curPlayIndex);
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_DURATION, &m_durationMsec); 
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_CURR_TIME, &m_currTimeMsec);    
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_STATE, (void*)&m_state);  
    
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    if (m_state == STATE_INIT)
    {
        m_isListEnd = VFX_FALSE;
    }
    else
    {
        m_isListEnd = VFX_FALSE;
		if (m_state == STATE_PLAY)
		{
			if (m_timer)
			{
				startGetCurrtimeTimer();            
			}
		}
    }    
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_IS_LIST_END, m_isListEnd);    
    
    
    m_timer->m_signalTick.connect(this, &VappCubeMediaPlayerAgent::onTimerTick);
    vadp_v2p_cube_media_player_register_callback((void*)this, playerCallback);
}


void VappCubeMediaPlayerAgent::onDeinit()
{
    VfxObjWeakPtr this_ptr = this;
    if (this_ptr == NULL)
    {
        return;
    }    

    VfxS32 repeatOne = 0;
    VfxS32 repeatAll = 0;
    VfxS32 repeatOff = 0;
    VfxS32 shuf = 0;

    if (m_repeatOne)
    {
        repeatOne = 1;    
    }

    if (m_repeatAll)
    {
        repeatAll = 1;    
    }

    if (m_repeatOff)
    {
        repeatOff = 1;
    }

    if (m_shuffle)
    {
        shuf = 1;    
    }

    vadp_v2p_cube_media_player_store_repeat(repeatOne, repeatAll, repeatOff); 
    vadp_v2p_cube_media_player_store_shuffle(shuf);

    VappCubeMediaPlayerScr *p_scr = NULL;
    p_scr = (VappCubeMediaPlayerScr *)getParent();
    EXT_ASSERT(p_scr != NULL, 0, 0, 0);
    VfxU8 state = p_scr->m_state.get();

    if (state == ASKED_TO_PLAY)
    {
        vadp_v2p_cube_media_player_continue_play_after_exit();
    }

    vadp_v2p_cube_media_player_deregister_callback();
    if (m_timer->getIsEnabled())
    {
        if (m_timer)
        {
            m_timer->stop();    
        }
        
    }
    m_timer->m_signalTick.disconnect(this, &VappCubeMediaPlayerAgent::onTimerTick);
    VfxObject::onDeinit();
}

void VappCubeMediaPlayerAgent::OnShuffleOn(void)
{
    m_shuffle = VFX_TRUE;
    setShuffle(m_shuffle);
}

void VappCubeMediaPlayerAgent::OnShuffleOff(void)
{
    m_shuffle = VFX_FALSE;
    setShuffle(m_shuffle);
}

void VappCubeMediaPlayerAgent::OnRepeatOne(void)
{
    m_repeatOff = VFX_FALSE;
    m_repeatOne = VFX_TRUE;
    m_repeatAll = VFX_FALSE;
    setRepeat(m_repeatOne, m_repeatAll, m_repeatOff);
}

void VappCubeMediaPlayerAgent::OnRepeatAll(void)
{
    m_repeatOff = VFX_FALSE;
    m_repeatOne = VFX_FALSE;
    m_repeatAll =VFX_TRUE;
    setRepeat(m_repeatOne, m_repeatAll, m_repeatOff);
}

void VappCubeMediaPlayerAgent::OnRepeatOff(void)
{
    m_repeatOff = VFX_TRUE;
    m_repeatOne = VFX_FALSE;
    m_repeatAll =VFX_FALSE;
    setRepeat(m_repeatOne, m_repeatAll, m_repeatOff);
}

void VappCubeMediaPlayerAgent::onPlay(VfxPenEvent &event)
{
    VfxObjWeakPtr this_ptr = this;    
    
    VFX_UNUSED(event);    
    vadp_v2p_cube_media_player_button_process(VAPP_CUBE_MEDIA_PLAYER_BUTTON_PLAY, VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_DOWN);
    vadp_v2p_cube_media_player_button_process(VAPP_CUBE_MEDIA_PLAYER_BUTTON_PLAY, VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_UP);
    if (this_ptr != NULL)
    {
        m_eventPlay.emit();
    }
    //////kal_printf("\n[Guoming] onPlay()");
}



void VappCubeMediaPlayerAgent::onPause(VfxPenEvent &event)
{
    VfxObjWeakPtr this_ptr = this;
    
    VFX_UNUSED(event);
    vadp_v2p_cube_media_player_button_process(VAPP_CUBE_MEDIA_PLAYER_BUTTON_PAUSE, VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_DOWN);
    vadp_v2p_cube_media_player_button_process(VAPP_CUBE_MEDIA_PLAYER_BUTTON_PAUSE, VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_UP);
    //////kal_printf("\n[Guoming] onPause()");
    if (this_ptr != NULL)
    {
        m_isWaitPause = VFX_TRUE;
    }
 
}

void VappCubeMediaPlayerAgent::onStop(VfxPenEvent &event)
{
    
    VFX_UNUSED(event);
    
    vadp_v2p_cube_media_player_button_process(VAPP_CUBE_MEDIA_PLAYER_BUTTON_STOP, VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_DOWN);
    vadp_v2p_cube_media_player_button_process(VAPP_CUBE_MEDIA_PLAYER_BUTTON_STOP, VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_UP); 
    stopGetCurrtimeTimer();
    m_currTimeMsec = 0;
    m_eventStop.emit();

}

void VappCubeMediaPlayerAgent::onStatusChanged(void* resultP)
{    
    VFX_UNUSED(resultP);
   
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_STATE, (void*)&m_state); 
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_CURR_TIME, &m_currTimeMsec);
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_DURATION, &m_durationMsec);
    
    if (m_isListEnd && m_state != STATE_INIT)
    {
        m_isListEnd = VFX_FALSE;    
    }
    
    m_eventStatusChanged.emit(); 

    if (m_isWaitPause)
    {
        m_isWaitPause = VFX_FALSE;    
        if (m_state != STATE_PLAY)
        {
            m_eventPause.emit();
        }
       
    }    
    if (m_state == STATE_PLAY)
    {
        
        startGetCurrtimeTimer();        
    }
    else
    {
        stopGetCurrtimeTimer();   
    }    

}


void VappCubeMediaPlayerAgent::onMediaChanged(void* resultP)
{
    VFX_UNUSED(resultP);

    if (m_isListEnd == VFX_TRUE)
    {
        return;
    }
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_DURATION, &m_durationMsec);    
    VfxS32 total_time = (VfxS32)(m_durationMsec / 1000);
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME, total_time);

    m_lastPlayIndex = m_curPlayIndex;
    m_curPlayIndex = vadp_v2p_cube_media_player_get_active_index();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX, m_curPlayIndex);
 

    m_eventMediaChanged.emit();

}


void VappCubeMediaPlayerAgent::onPlayEnd(void* resultP)
{  
    m_currTimeMsec = m_durationMsec;  	
    m_eventPlayEnd.emit();
}

void VappCubeMediaPlayerAgent::onListEnd(void* resultP)
{  
    m_isListEnd = VFX_TRUE;
    
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_DURATION, &m_durationMsec);    
    VfxS32 total_time = (VfxS32)(m_durationMsec / 1000);
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME, total_time);

    m_lastPlayIndex = m_curPlayIndex;
    m_curPlayIndex = vadp_v2p_cube_media_player_get_active_index();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX, m_curPlayIndex); 

    m_eventMediaChanged.emit();
}

void VappCubeMediaPlayerAgent::onResetCurTime(void* resultP)
{
    m_currTimeMsec = 0;
    m_eventUpdate.emit();     
}

void VappCubeMediaPlayerAgent::startGetCurrtimeTimer(void)
{
    if (!m_isTimerStart)
    {
        m_timer->setStartDelay(100);
        m_timer->setDuration(200);
        m_timer->start();
        //////kal_printf("\n[Guoming]start play timer ");
        m_isTimerStart = VFX_TRUE;
    }
}
void VappCubeMediaPlayerAgent::stopGetCurrtimeTimer(void)
{
    if (m_isTimerStart)
    {
        m_timer->stop();
        //////kal_printf("\n[Guoming]stop play timer ");
        m_isTimerStart = VFX_FALSE;
    }
}


VfxU8 VappCubeMediaPlayerAgent::getState()
{    
    return m_state;
}

VfxU64 VappCubeMediaPlayerAgent::getDuration()
{    
    
    return m_durationMsec;
}


VfxU64 VappCubeMediaPlayerAgent::getCurrTime()
{    
    return m_currTimeMsec;
}


void VappCubeMediaPlayerAgent::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);  
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_CURR_TIME, &m_currTimeMsec);
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_DURATION, &m_durationMsec);
    m_eventUpdate.emit();  
}

void VappCubeMediaPlayerAgent::setCurPlayIndex(VfxS32 index)
{    
    VfxObjWeakPtr this_ptr = this;   
    m_curPlayIndex = -1;
    m_lastPlayIndex = -1;
    m_isListEnd = VFX_FALSE;
    //kal_printf("\n[Guoming] m_curPlayIndex = -1  index = %d", index);
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_SET_PLAY_INDEX, index);
    m_curPlayIndex = index;
    vadp_v2p_cube_media_player_apply(index); 
    if (this_ptr == NULL)
    {
        return;
    }

    
    vadp_v2p_cube_media_player_get_info(VAPP_CUBE_MEDIA_PLAYER_INFO_DURATION, &m_durationMsec);
    VfxS32 total_time = (VfxS32)(m_durationMsec / 1000);
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME, total_time);
    
}

VfxS32 VappCubeMediaPlayerAgent::getCurPlayIndex()
{
    return m_curPlayIndex;    
}

VfxS32 VappCubeMediaPlayerAgent::getLastPlayIndex()
{
    return m_lastPlayIndex; 
}

VfxS32 VappCubeMediaPlayerAgent::getTotalCount()
{    
    return m_total;
}

void VappCubeMediaPlayerAgent::setTotalCount(VfxS32 cnt)
{
    m_total = cnt;    
}

void VappCubeMediaPlayerAgent::getRepeat(VfxBool *p_one, VfxBool *p_all, VfxBool *p_off)
{
    *p_one = m_repeatOne;
    *p_all = m_repeatAll;
    *p_off = m_repeatOff;
}

void VappCubeMediaPlayerAgent::getShuffle(VfxBool *p_shuf)
{
    *p_shuf = m_shuffle;
}

void VappCubeMediaPlayerAgent::setRepeat(VfxBool one, VfxBool all, VfxBool off)
{
    VfxS32 repeatOne = 0;
    VfxS32 repeatAll = 0;
    VfxS32 repeatOff = 0;
    
    if (one)
    {
        repeatOne = 1; 
        m_repeatOne = VFX_TRUE;
        m_repeatAll = VFX_FALSE;
        m_repeatOff = VFX_FALSE;
    }
    else if (all)
    {
        repeatAll = 1;
        m_repeatAll = VFX_TRUE;
        m_repeatOne = VFX_FALSE;
        m_repeatOff = VFX_FALSE;
    }
    else if (off)
    {
        repeatOff = 1;
        m_repeatOff = VFX_TRUE;
        m_repeatOne = VFX_FALSE;
        m_repeatAll = VFX_FALSE;
    }
    
    vadp_v2p_cube_media_player_set_repeat(repeatOne, repeatAll, repeatOff);    
}

void VappCubeMediaPlayerAgent::setShuffle(VfxBool shuf)
{
    VfxS32 shuffle = 0;
    
    if (shuf)
    {
        shuffle = 1;
        m_shuffle = VFX_TRUE;
    }
    else
    {
        shuffle = 0;
        m_shuffle = VFX_FALSE;
    }
    vadp_v2p_cube_media_player_set_shuffle(shuffle);
}

VfxBool VappCubeMediaPlayerAgent::isListEnd()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_IS_LIST_END, m_isListEnd);
    return m_isListEnd; 
}

/*******************************************************************
Class VappCubeMediaPlayerRepeatPanel
*********************************************************************/

VappCubeMediaPlayerRepeatPanel::VappCubeMediaPlayerRepeatPanel() 
: m_repeatOneBtn(NULL),
m_repeatAllBtn(NULL),
m_repeatOffBtn(NULL),
m_shuffleOnBtn(NULL),
m_shuffleOffBtn(NULL),
m_shuffle(VFX_FALSE),
m_repeatOne(VFX_FALSE),
m_repeatAll(VFX_FALSE),
m_repeatOff(VFX_TRUE),
m_isLayouted(VFX_FALSE),
m_hasRepeat(VFX_FALSE),
m_hasShuffle(VFX_FALSE)
{
    
}


VappCubeMediaPlayerRepeatPanel::~VappCubeMediaPlayerRepeatPanel()
{
    
}


void VappCubeMediaPlayerRepeatPanel::onInit()
{
    VfxControl::onInit();
    
}

void VappCubeMediaPlayerRepeatPanel::layout()
{
    if (m_isLayouted)
    {
        return;        
    }
    VfxPoint      pst;
    VfxRect       rct;
    
    pst = this->getPos();
    rct = this->getBounds();
    
    m_isLayouted = VFX_TRUE;
    VFX_ASSERT(m_hasRepeat ||m_hasShuffle);
    
    if (m_hasShuffle)
    {
        VFX_ASSERT(!m_hasRepeat);
        VFX_OBJ_CREATE(m_shuffleOnBtn, VappCubeMediaPlayerButton, this);  
        m_shuffleOnBtn->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_SHUFFLE_ON_UP,
            VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);
        
        m_shuffleOnBtn->setPos(VFX_POINT_ZERO);
        m_shuffleOnBtn->setBounds(VfxRect(0, 0, g_plyt->shuffle_btn.width, g_plyt->shuffle_btn.height));    
        m_shuffleOnBtn->setDisplay(m_shuffle? VFX_TRUE : VFX_FALSE);
        m_shuffleOnBtn->m_eventPenUp.connect(this, &VappCubeMediaPlayerRepeatPanel::onShuffleOn);
        
        VFX_OBJ_CREATE(m_shuffleOffBtn, VappCubeMediaPlayerButton, this); 
        m_shuffleOffBtn->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_SHUFFLE_OFF_UP,
            VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);    
        
        m_shuffleOnBtn->setPos(VFX_POINT_ZERO);
        m_shuffleOffBtn->setBounds(VfxRect(0, 0, g_plyt->shuffle_btn.width, g_plyt->shuffle_btn.height));    
        m_shuffleOffBtn->setDisplay(m_shuffle? VFX_FALSE : VFX_TRUE);
        m_shuffleOffBtn->m_eventPenUp.connect(this, &VappCubeMediaPlayerRepeatPanel::onShuffleOff);
    }
    
    if (m_hasRepeat)
    {
        VFX_ASSERT(!m_hasShuffle);
        VFX_OBJ_CREATE(m_repeatOneBtn, VappCubeMediaPlayerButton, this);
        m_repeatOneBtn->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_REPEAT_ONE_UP,
            VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);    
        
        m_repeatOneBtn->setPos(VFX_POINT_ZERO);
        m_repeatOneBtn->setBounds(VfxRect(0, 0, g_plyt->repeat_btn.width, g_plyt->repeat_btn.height));    
        m_repeatOneBtn->setDisplay(m_repeatOne? VFX_TRUE : VFX_FALSE);
        m_repeatOneBtn->m_eventPenUp.connect(this, &VappCubeMediaPlayerRepeatPanel::onRepeatOne);
        
        VFX_OBJ_CREATE(m_repeatAllBtn, VappCubeMediaPlayerButton, this);    
        m_repeatAllBtn->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_REPEAT_ALL_UP,
            VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);    
        
        m_repeatOneBtn->setPos(VFX_POINT_ZERO);
        m_repeatAllBtn->setBounds(VfxRect(0, 0, g_plyt->repeat_btn.width, g_plyt->repeat_btn.height));            
        m_repeatAllBtn->setDisplay(m_repeatAll? VFX_TRUE : VFX_FALSE);
        m_repeatAllBtn->m_eventPenUp.connect(this, &VappCubeMediaPlayerRepeatPanel::onRepeatAll);
        
        VFX_OBJ_CREATE(m_repeatOffBtn, VappCubeMediaPlayerButton, this);
        m_repeatOffBtn->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_REPEAT_OFF_UP,
            VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);    
        
        m_repeatOneBtn->setPos(VFX_POINT_ZERO);
        m_repeatOffBtn->setBounds(VfxRect(0, 0, g_plyt->repeat_btn.width, g_plyt->repeat_btn.height));            
        m_repeatOffBtn->setDisplay(m_repeatOff? VFX_TRUE : VFX_FALSE);
        m_repeatOffBtn->m_eventPenUp.connect(this, &VappCubeMediaPlayerRepeatPanel::onRepeatOff);
    }
    
    
}
void VappCubeMediaPlayerRepeatPanel::clear(void)
{
    if (!m_isLayouted)
    {
        return;
    }
    if (m_hasShuffle)
    {
        m_shuffleOnBtn->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerRepeatPanel::onShuffleOn);
        m_shuffleOffBtn->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerRepeatPanel::onShuffleOff); 
    }
    if (m_hasRepeat)
    {
        m_repeatOneBtn->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerRepeatPanel::onRepeatOne);
        m_repeatAllBtn->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerRepeatPanel::onRepeatAll);
        m_repeatOffBtn->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerRepeatPanel::onRepeatOff);    
    }
    m_isLayouted = VFX_FALSE;
}

void VappCubeMediaPlayerRepeatPanel::onDeinit()
{   
    VfxControl::onDeinit();    
    
}

VfxBool VappCubeMediaPlayerRepeatPanel::getIsDisabled(void)
{
    return VfxControl::getIsDisabled();
}

void VappCubeMediaPlayerRepeatPanel::setIsDisabled(VfxBool b)
{
    if (m_hasShuffle)
    {
        m_shuffleOffBtn->setIsDisabled(b);
        m_shuffleOnBtn->setIsDisabled(b);
        return;
    }

    if (m_hasRepeat)
    {
        m_repeatOneBtn->setIsDisabled(b);
        m_repeatAllBtn->setIsDisabled(b);
        m_repeatOffBtn->setIsDisabled(b);
        return;
    }
}
    
VfxBool VappCubeMediaPlayerRepeatPanel::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos(event.getRelPos(this));
    
    return VfxControl::onPenInput(event);
}

void VappCubeMediaPlayerRepeatPanel::setRepeat(VfxBool one, VfxBool all, VfxBool off)
{
    m_hasRepeat = VFX_TRUE;
    m_repeatOne = one;
    m_repeatAll = all;
    m_repeatOff =  off;          
}

void VappCubeMediaPlayerRepeatPanel::getRepeat(VfxBool *p_one, VfxBool *p_all, VfxBool *p_off)
{
    *p_one = m_repeatOne;
    *p_all = m_repeatAll;
    *p_off = m_repeatOff;
}

void VappCubeMediaPlayerRepeatPanel::setShuffle(VfxBool shuf)
{    
    m_hasShuffle = VFX_TRUE;
    m_shuffle = shuf;    
}

void VappCubeMediaPlayerRepeatPanel::getShuffle(VfxBool *p_shuf)
{
    *p_shuf = m_shuffle;
}

void VappCubeMediaPlayerRepeatPanel::onShuffleOn(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    
    m_shuffle = VFX_FALSE;
    m_shuffleOnBtn->setDisplay(VFX_FALSE);
    m_shuffleOffBtn->setDisplay(VFX_TRUE);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    m_eventShuffleOff.emit();
    
}
void VappCubeMediaPlayerRepeatPanel::onShuffleOff(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    m_shuffle = VFX_TRUE;
    
    m_shuffleOffBtn->setDisplay(VFX_FALSE);
    m_shuffleOnBtn->setDisplay(VFX_TRUE);  
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    m_eventShuffleOn.emit();
    
}

void VappCubeMediaPlayerRepeatPanel::onRepeatOne(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    m_repeatOne = VFX_FALSE;
    m_repeatAll = VFX_TRUE;
    
    m_repeatOneBtn->setDisplay(VFX_FALSE);
    m_repeatAllBtn->setDisplay(VFX_TRUE);
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    m_eventRepeatAll.emit();    
}

void VappCubeMediaPlayerRepeatPanel::onRepeatAll(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    m_repeatAll = VFX_FALSE;
    m_repeatOff = VFX_TRUE;
    
    m_repeatAllBtn->setDisplay(VFX_FALSE);
    m_repeatOffBtn->setDisplay(VFX_TRUE);
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    m_eventRepeatOff.emit();     
}

void VappCubeMediaPlayerRepeatPanel::onRepeatOff(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    m_repeatOff = VFX_FALSE;
    m_repeatOne = VFX_TRUE;
    
    m_repeatOffBtn->setDisplay(VFX_FALSE);
    m_repeatOneBtn->setDisplay(VFX_TRUE);
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    m_eventRepeatOne.emit();    
}




/*****************************************************************************
* Class VappCubeMediaPlayerPlayPanel
*****************************************************************************/

VappCubeMediaPlayerPlayPanel::VappCubeMediaPlayerPlayPanel() 
: m_bgFrame(NULL),
m_cover(NULL),
m_image(NULL),
m_songName(NULL),
m_nameText(),
m_playButton(NULL), 
m_stopButton(NULL), 
m_pauseButton(NULL),
m_closeButton(NULL),
m_progress(NULL),
m_curTime(NULL),
m_totalTime(NULL),
m_isPlay(VFX_FALSE),
m_isScroll(VFX_FALSE),
m_curTimeValue(0),
m_totalTimeValue(0),
m_progressRatio(0),
m_isLayouted(VFX_FALSE),
m_curr_pentype(0),
m_penX(0),
m_penY(0),
m_shuffleButton(NULL),
m_repeatButton(NULL),
m_upArrow(NULL),
m_downArrow(NULL),
m_upArrowTimeline(NULL),
m_downArrowTimeline(NULL),
m_arrowAnim(NULL),
m_curIndex(0)
{
    
}


VappCubeMediaPlayerPlayPanel::~VappCubeMediaPlayerPlayPanel()
{
    
}

void VappCubeMediaPlayerPlayPanel::onInit(void)
{
    VfxControl::onInit();
    
    this->setPos(VfxPoint(g_plyt->play_panel.offset_x, g_plyt->play_panel.offset_y));
    //this->setAnchor(VfxFPoint(0.5, 0.5));
    this->setBounds(VfxRect(0, 0, g_plyt->play_panel.width, g_plyt->play_panel.height));
    
    
}


void VappCubeMediaPlayerPlayPanel::onDeinit()
{
    VfxControl::onDeinit();
}

void VappCubeMediaPlayerPlayPanel::onClickStop(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    
    m_isPlay = VFX_FALSE;
    m_curTimeValue = 0;
    m_progressRatio = 0;
    
    m_playButton->setDisplay(VFX_TRUE);
    m_pauseButton->setDisplay(VFX_FALSE);
    m_curTime->setTime(0);
    m_progress->setRatio(0);
}

void VappCubeMediaPlayerPlayPanel::onClickPlay(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    
    m_isPlay = VFX_TRUE;
    
    //m_playButton->setDisplay(VFX_FALSE);
    //m_pauseButton->setDisplay(VFX_TRUE);
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();        
}

void VappCubeMediaPlayerPlayPanel::onClickPause(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    
    m_isPlay = VFX_FALSE;
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();        
}

void VappCubeMediaPlayerPlayPanel::onClickClose(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();        
}

void VappCubeMediaPlayerPlayPanel::setIsPlay(VfxBool b)
{
    m_isPlay = b;
    if (m_isLayouted)
    {
        m_playButton->setDisplay(!b);  
        m_pauseButton->setDisplay(b);
    }    
}

void VappCubeMediaPlayerPlayPanel::getIsPlay(VfxBool *pb)
{
    *pb = m_isPlay;
}

void VappCubeMediaPlayerPlayPanel::getIsScroll(VfxBool *pb)
{
    *pb = m_isScroll;
    
}
void VappCubeMediaPlayerPlayPanel::setIsScroll(VfxBool b)
{
    if (m_isLayouted)
    {
        if (b)
        {
            m_songName->startScroll();
        }
        else
        {
            m_songName->stopScroll();
        }
    } 
    
    m_isScroll = b;
    return;    
}

void VappCubeMediaPlayerPlayPanel::setCurTime(VfxS32 sec)
{ 
    if (m_curTimeValue == sec)
    {
        return;
    }
    if (sec < 0)
    {
        sec = 0;
    }    
  
    m_curTimeValue = sec;
    
    
    if (m_isLayouted)
    {
        m_curTime->setTime(m_curTimeValue); 
    }    
}

void VappCubeMediaPlayerPlayPanel::getCurTime(VfxS32 *p_sec)
{
    *p_sec = m_curTimeValue;
}

void VappCubeMediaPlayerPlayPanel::setTotalTime(VfxS32 sec)
{
    if (m_totalTimeValue == sec)
    {
        return;
    }
    
    if (sec < 0)
    {
        sec = 0;
    }    

     m_totalTimeValue = sec;   
    
    if (m_isLayouted)
    {
        m_totalTime->setTime(m_totalTimeValue); 
    } 
    
}

void VappCubeMediaPlayerPlayPanel::getTotalTime(VfxS32 *p_sec)
{
    *p_sec = m_totalTimeValue;
}

void VappCubeMediaPlayerPlayPanel::setProgressRatio(VfxS32 r)
{
    if (m_progressRatio == r)
    {
        return;
    }
    
    if (r < 0)
    {
        r = 0;
    }
    
    m_progressRatio = r;
    if (m_isLayouted)
    {
        m_progress->setRatio(r);
    }
    
}
void VappCubeMediaPlayerPlayPanel::setProgressRatio(VfxU64 child, VfxU64 parent)
{    
    
    if (parent == 0)
    {
        m_progressRatio = 0;    
    }
    else if (child > parent)
    {
        m_progressRatio = 1000;
    }
    else if (parent < 1024)
    {
        m_progressRatio = (VfxS32) (child * 1000 /  parent);      
    }
    else
    {
         m_progressRatio = (VfxS32)((child >> 8) * 1000 / (parent >> 8));
    }

    if (m_isLayouted)
    {
        m_progress->setRatio(m_progressRatio);
    }  
    
}



void VappCubeMediaPlayerPlayPanel::getProgressRatio(VfxS32 *pr)
{
    *pr = m_progressRatio;
}

void VappCubeMediaPlayerPlayPanel::setRepeat(VfxBool one, VfxBool all, VfxBool off)
{
    m_repeatOne = one;
    m_repeatAll = all;
    m_repeatOff =  off;          
    
}

void VappCubeMediaPlayerPlayPanel::getRepeat(VfxBool *p_one, VfxBool *p_all, VfxBool *p_off)
{
    *p_one = m_repeatOne;
    *p_all = m_repeatAll;
    *p_off = m_repeatOff;
}

void VappCubeMediaPlayerPlayPanel::setShuffle(VfxBool shuf)
{    
    m_shuffle = shuf;    
}

void VappCubeMediaPlayerPlayPanel::getShuffle(VfxBool *p_shuf)
{
    *p_shuf = m_shuffle;
}

void VappCubeMediaPlayerPlayPanel::setPicture(VfxImage *p_image)
{ 
    m_image =  p_image;     
    
    if (m_isLayouted)
    {
        m_cover->setContent(m_image);
        m_cover->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_cover->invalidate();
    }
    
}

void VappCubeMediaPlayerPlayPanel::setSongName(VfxWChar *s)
{
    m_nameText.setNull();
    m_nameText.loadFromMem(s);    
    if (m_isLayouted)
    {
        m_songName->stopScroll();
        m_songName->clearMovableFrame();
        m_songName->setMovableFrame(m_nameText, g_vfxFontMedium);
        m_songName->invalidate();  
        if (m_isScroll)
        {
            m_songName->startScroll();
        }       
    }    
}
void VappCubeMediaPlayerPlayPanel::startProcessing()
{
    //@TODO:add loading animiton
}

void VappCubeMediaPlayerPlayPanel::stopProcessing()
{
    //@TODO:add loading animiton
}

void VappCubeMediaPlayerPlayPanel::setTotalTimeDisplay(VfxBool b)
{
    if (m_totalTime)
    {
        m_totalTime->setHidden(!b);     
    }
}
    
void VappCubeMediaPlayerPlayPanel::setCurTimeDisplay(VfxBool b)
{
    if (m_curTime)
    {
        m_curTime->setHidden(!b);      
    }

}

void VappCubeMediaPlayerPlayPanel::layout()
{
    if (m_isLayouted)
    {
        return;
    }
    m_isLayouted = VFX_TRUE; 
   

    
    VFX_OBJ_CREATE(m_bgFrame, VfxImageFrame, this); 
    m_bgFrame->setPos(VfxPoint(0, 0));
    m_bgFrame->setBounds(this->getBounds());
    m_bgFrame->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_PANEL_BG);
    //m_bgFrame->setIsOpaque(VFX_TRUE); //@TODO: if set, the frame will turn blue
    m_bgFrame->setIsCached(VFX_TRUE);


   
    VFX_OBJ_CREATE(m_cover, VfxFrame, this); 
    m_cover->setPos(VfxPoint(g_plyt->cover.offset_x - g_plyt->play_panel.offset_x, 
        g_plyt->cover.offset_y- g_plyt->play_panel.offset_y));
    m_cover->setBounds(VfxRect(0, 0, g_plyt->cover.width, g_plyt->cover.height)); 
    m_cover->setContent(m_image);
    m_cover->setIsOpaque(VFX_TRUE);
    m_cover->setIsCached(VFX_TRUE);   
    
    
    
    VFX_OBJ_CREATE(m_songName, VcpMarquee, this);
    m_songName->setPos(VfxPoint(g_plyt->song_name.offset_x - g_plyt->play_panel.offset_x, 
        g_plyt->song_name.offset_y- g_plyt->play_panel.offset_y));
    m_songName->setBounds(VfxRect(0, 0, g_plyt->song_name.width, g_plyt->song_name.height));      
    m_songName->setHalign(VcpMarquee::HALIGN_CENTER);
    m_songName->setValign(VcpMarquee::VALIGN_CENTER);
    m_songName->setSpeed(VcpMarquee::DEFAULT_SPEED / 15);
    m_songName->setStartDelay(VcpMarquee::DEFAULT_START_DELAY);
    m_songName->setMovableFrame(m_nameText, g_vfxFontMedium);
    m_songName->startScroll(); 
    
    
    VFX_OBJ_CREATE(m_progress, VappCubeMediaPlayerProgress, this);
    m_progress->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_PROGRESS_BG,
        VAPP_CUBE_MEDIA_PLAYER_IMG_PROGRESS_FG);
    m_progress->setPos(VfxPoint(g_plyt->progress.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->progress.offset_y - g_plyt->play_panel.offset_y));
    m_progress->setBounds(VfxRect(0, 0, g_plyt->progress.width, g_plyt->progress.height)); 
    m_progress->setRatio(m_progressRatio);
    
    
    
    VFX_OBJ_CREATE(m_curTime, VappCubeMediaPlayerTime, this);
    m_curTime->setPos(VfxPoint(g_plyt->cur_time.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->cur_time.offset_y - g_plyt->play_panel.offset_y));
    m_curTime->setBounds(VfxRect(0, 0, g_plyt->cur_time.width, g_plyt->cur_time.height)); 
    m_curTime->setTime(m_curTimeValue);
    m_curTime->layout();
    
    VFX_OBJ_CREATE(m_totalTime, VappCubeMediaPlayerTime, this);
    m_totalTime->setPos(VfxPoint(g_plyt->total_time.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->total_time.offset_y - g_plyt->play_panel.offset_y));
    m_totalTime->setBounds(VfxRect(0, 0, g_plyt->total_time.width, g_plyt->total_time.height));     
    m_totalTime->setTime(m_totalTimeValue);
    m_totalTime->layout();     
    
    VFX_OBJ_CREATE(m_playButton, VappCubeMediaPlayerButton, this);
    m_playButton->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_PLAY_UP,
        VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);
    m_playButton->setPos(VfxPoint(g_plyt->play_btn.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->play_btn.offset_y - g_plyt->play_panel.offset_y));
    m_playButton->setBounds(VfxRect(0, 0, g_plyt->play_btn.width, g_plyt->play_btn.height));
    
    VFX_OBJ_CREATE(m_stopButton, VappCubeMediaPlayerButton, this);
    m_stopButton->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_STOP_UP,
        VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);
    m_stopButton->setPos(VfxPoint(g_plyt->stop_btn.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->stop_btn.offset_y - g_plyt->play_panel.offset_y));
    m_stopButton->setBounds(VfxRect(0, 0, g_plyt->stop_btn.width, g_plyt->stop_btn.height));
    
    
    VFX_OBJ_CREATE(m_pauseButton, VappCubeMediaPlayerButton, this);
    m_pauseButton->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_PAUSE_UP,
        VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);
    m_pauseButton->setPos(VfxPoint(g_plyt->play_btn.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->play_btn.offset_y - g_plyt->play_panel.offset_y));
    m_pauseButton->setBounds(VfxRect(0, 0, g_plyt->play_btn.width, g_plyt->play_btn.height));
    
    
    VFX_OBJ_CREATE(m_closeButton, VappCubeMediaPlayerButton, this);
    m_closeButton->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_CLOSE_UP,
        VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);
    m_closeButton->setPos(VfxPoint(g_plyt->close_btn.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->close_btn.offset_y - g_plyt->play_panel.offset_y));
    m_closeButton->setBounds(VfxRect(0, 0, g_plyt->close_btn.width, g_plyt->close_btn.height));    
    
    m_stopButton->setDisplay(VFX_TRUE);
    m_closeButton->setDisplay(VFX_TRUE);
    m_pauseButton->setDisplay(m_isPlay? VFX_TRUE : VFX_FALSE);
    m_playButton->setDisplay(m_isPlay? VFX_FALSE : VFX_TRUE);
    
    VFX_OBJ_CREATE(m_shuffleButton, VappCubeMediaPlayerRepeatPanel, this);
    m_shuffleButton->setPos(VfxPoint(g_plyt->shuffle_btn.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->shuffle_btn.offset_y - g_plyt->play_panel.offset_y));
    m_shuffleButton->setBounds(VfxRect(0, 0, g_plyt->shuffle_btn.width, g_plyt->shuffle_btn.height));     
    m_shuffleButton->setShuffle(m_shuffle);
    m_shuffleButton->layout();       
    
    VFX_OBJ_CREATE(m_repeatButton, VappCubeMediaPlayerRepeatPanel, this);
    m_repeatButton->setPos(VfxPoint(g_plyt->repeat_btn.offset_x - g_plyt->play_panel.offset_x,
        g_plyt->repeat_btn.offset_y - g_plyt->play_panel.offset_y));
    m_repeatButton->setBounds(VfxRect(0, 0, g_plyt->repeat_btn.width, g_plyt->repeat_btn.height));     
    m_repeatButton->setRepeat(m_repeatOne, m_repeatAll, m_repeatOff);
    m_repeatButton->layout(); 
    
#if 0    //@TODO: Maybe need this later. Depend on artist's new design    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

    m_playButton->m_eventPenUp.connect(this, &VappCubeMediaPlayerPlayPanel::onClickPlay);
    m_pauseButton->m_eventPenUp.connect(this, &VappCubeMediaPlayerPlayPanel::onClickPause);       
    m_closeButton->m_eventPenUp.connect(this, &VappCubeMediaPlayerPlayPanel::onClickClose);  
    m_stopButton->m_eventPenUp.connect(this, &VappCubeMediaPlayerPlayPanel::onClickStop); 
    
}

void VappCubeMediaPlayerPlayPanel::clear()
{
    if (!m_isLayouted)
    {
        return;
    }
    m_playButton->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerPlayPanel::onClickPlay);
    m_pauseButton->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerPlayPanel::onClickPause);
    m_closeButton->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerPlayPanel::onClickClose);
    m_stopButton->m_eventPenUp.disconnect(this, &VappCubeMediaPlayerPlayPanel::onClickStop);
    
    m_totalTime->clear();
    m_curTime->clear();
    
    m_isLayouted = VFX_FALSE;
}
VfxBool VappCubeMediaPlayerPlayPanel::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos(event.getRelPos(this));
    
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {        
        m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;
        m_penX = pos.x;
        m_penY = pos.y;
        return VFX_TRUE;
    }
    
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        /* X movement is too large */
        if (pos.x - m_penX > 30 || m_penX - pos.x > 30 
            || m_curr_pentype == VFX_PEN_EVENT_TYPE_UP)
        {
            m_penX = 0;
            m_penY = 0;
            m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;        
            return VFX_TRUE;            
        }
        
        /* drag down, switch to previous  item */
        if (pos.y - m_penY > 60)
        {
            
            m_eventSwitch.emit(-1);       
        }
        
        /* drag up, switch to next  item */
        if (m_penY - pos.y > 60)
        {
            
            m_eventSwitch.emit(1);    
        }         
        
        m_penX = 0;
        m_penY = 0;
        m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;        
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (containPoint(pos))
        {
            m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;
        }
        else
        {
            m_penX = 0;
            m_penY = 0;
            m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
        }
        return VFX_TRUE;
    }
    m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
    
    return VfxControl::onPenInput(event);
}

/*****************************************************************************
* Class VappCubeMediaPlayerCell
*****************************************************************************/
VappCubeMediaPlayerCell::VappCubeMediaPlayerCell() : 
m_width(0),
m_height(0),
m_isHighlight(VFX_FALSE),
m_innerX(0),
m_innerY(0),
m_songName(NULL),
m_image(NULL),
m_pic(NULL),
m_isLayouted(VFX_FALSE),
m_hasPic(VFX_FALSE),
m_hasSongName(VFX_FALSE),
m_isScroll(VFX_FALSE),
m_nameText(),
m_cd(NULL),
m_cdHighlight(NULL)
{
    
}
void VappCubeMediaPlayerCell::setPicture(VfxImage *p_image)
{
    m_image =  p_image;     
    
    if (m_isLayouted)
    {
        m_pic->setContent(m_image);
        //m_pic->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_pic->invalidate();
    }
    
}

void VappCubeMediaPlayerCell::setSongName(VfxWChar *s)
{
    
    if (!m_hasSongName)
    {   
        m_hasSongName = VFX_TRUE; 
    }
    m_nameText.setNull();
    m_nameText.loadFromMem(s);
    if (m_isLayouted)
    {
        m_songName->stopScroll();
        m_songName->clearMovableFrame();
        m_songName->setMovableFrame(m_nameText, g_vfxFontMedium);
        m_songName->invalidate();        
    }    
}

void VappCubeMediaPlayerCell::setScroll(VfxBool b)
{
    if (!m_hasSongName)
    {
        return;
    }
    m_isScroll = b;
    
    if (!m_isLayouted)
    {        
        return;  
    }   
    
    if (m_isScroll)
    {
        m_songName->startScroll();   
    }
    else
    {
        m_songName->stopScroll();   
    }
    
}

void VappCubeMediaPlayerCell::layout(void)
{
    VfxPoint      pst;
    VfxRect       rct;
    VfxS32        offset_y;
    VfxS32        offset_x;
    
    pst = this->getPos();
    rct = this->getBounds();
    
    if (m_isLayouted)
    {
        return;
    }
    m_isLayouted = VFX_TRUE;   
    
    
    VFX_OBJ_CREATE(m_pic, VfxFrame, m_cd);
    
    m_pic->setPos(VfxPoint(g_nlyt->cover.offset_x, g_nlyt->cover.offset_y));
    m_pic->setBounds(VfxRect(0, 0, g_nlyt->cover.width, g_nlyt->cover.height));    
    m_pic->setContent(m_image);
    m_pic->setIsCached(VFX_TRUE); 
    
    m_cdHighlight->bringToFront();
    
    if (m_hasSongName)
    {
        VFX_OBJ_CREATE(m_songName, VcpMarquee, this);
        offset_y = (rct.size.height >> 1);
        offset_x = rct.size.height + 10;
        m_songName->setPos(VfxPoint(offset_x, offset_y));
        m_songName->setAnchor(VfxFPoint(0, 0.5));      
        // 6 is the offset when using frame effect
        m_songName->setBounds(VfxRect(0, 0, rct.size.width - offset_x - 6, rct.size.height));     
        
        m_songName->setHalign(VcpMarquee::HALIGN_LEFT);
        m_songName->setValign(VcpMarquee::VALIGN_CENTER);
        m_songName->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
        
        m_songName->setMovableFrame(m_nameText, g_vfxFontMedium);
        if (m_isScroll)
        {
            m_songName->startScroll();   
        }
        else
        {
            m_songName->stopScroll();   
        }        
    }
}

void VappCubeMediaPlayerCell::clear(void)
{
    if (!m_isLayouted)
    {
        return;
    }
    m_isLayouted = VFX_FALSE;
}

void VappCubeMediaPlayerCell::onInit()
{
    VfxControl::onInit();
    
    VfxS32        offset_y;
    VfxS32        offset_x;   
    
    
    VFX_OBJ_CREATE(m_cd, VfxImageFrame, this);
    offset_y = (g_nlyt->cd.height >> 1);
    offset_x = (g_nlyt->cd.width >> 1);
    m_cd->setPos(VfxPoint(offset_x , offset_y));
    m_cd->setAnchor(VfxFPoint(0.5, 0.5));
    m_cd->setBounds(VfxRect(0, 0, g_nlyt->cd.width, g_nlyt->cd.height));  
    m_cd->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_CD);
    m_cd->setIsCached(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_cdHighlight, VfxImageFrame, m_cd);    
    m_cdHighlight->setPos(VFX_POINT_ZERO);
    m_cdHighlight->setBounds(VfxRect(0, 0, g_nlyt->cd.width, g_nlyt->cd.height));
    m_cdHighlight->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_CD_HIGH_LIGHT);
    m_cdHighlight->setIsCached(VFX_TRUE);    
    m_cdHighlight->setHidden(VFX_TRUE);  
    
    
    m_isHighlight = VFX_FALSE;
}


void VappCubeMediaPlayerCell::onDeinit()
{
    VfxControl::onDeinit();
}


void VappCubeMediaPlayerCell::onHightLight()
{
    m_isHighlight = VFX_TRUE;
    //m_cdHighlight->setHidden(VFX_FALSE);

}


void VappCubeMediaPlayerCell::onDeHightLight()
{
    m_isHighlight = VFX_FALSE;
    //m_cdHighlight->setHidden(VFX_TRUE);
}


VfxBool VappCubeMediaPlayerCell::updateImage()
{
    return VFX_TRUE;
}

void VappCubeMediaPlayerCell::updatePos(const VfxRect& r, VfxBool animation)
{
    //setAutoAnimate(animation);
    setPos(r.origin);
    
    m_width = r.getWidth();
    m_height = r.getHeight();
}


void VappCubeMediaPlayerCell::enter(const VfxRect& r, VfxBool animation)
{
}


void VappCubeMediaPlayerCell::leave(const VfxRect& r)
{
}


/*****************************************************************************
* Class VappCubeMediaPlayerLayout
*****************************************************************************/
void VappCubeMediaPlayerLayout::onInit()
{
    VcpBaseMenuLayout::onInit();
    
    m_cellCount = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_cellOffsetX = 0;
    m_isNavDisabled = VFX_FALSE;
}


void VappCubeMediaPlayerLayout::onDeinit()
{
    m_cellCount = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_cellOffsetX = 0;
    VcpBaseMenuLayout::onDeinit();
}

VfxBool VappCubeMediaPlayerLayout::navDir(NavDirEnum dir)
{
    VcpMenuPos  p;      

    if (m_isNavDisabled)
    {
        return VFX_FALSE;    
    }
    
    if (NAV_DIR_DOWN == dir)
    {
        p = getFocusItem();
        if (p.pos < m_cellCount - 1)
        {
            p.pos++;
            setFocusItem(p, VFX_TRUE);
        } 
        return VFX_TRUE;
    }
    else if (NAV_DIR_UP == dir)
    {
        p = getFocusItem();
        if (p.pos > 0)
        {
            p.pos--;
            setFocusItem(p, VFX_TRUE);
        }   
        return VFX_TRUE;
    }

    return VFX_FALSE;

}

VfxS32 VappCubeMediaPlayerLayout::getContentLength()
{
    return (m_cellCount + 4)  * m_cellHeight ;	
}


VcpMenuRegion VappCubeMediaPlayerLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
        getCellByPos(r.origin),
        getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );	
}


VcpMenuPos VappCubeMediaPlayerLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;
    
    p.group = 0;
    
    VfxS32 row = pt.y / m_cellHeight ;
    
    p.pos = row -2;
   	if (p.pos < 0)
    {
        p.pos = 0;
   	}
    if (p.pos >= getCellCount(p.group))
   	{
        p.pos = getCellCount(p.group) - 1;
   	}
    return p;
}


VcpMenuPos VappCubeMediaPlayerLayout::queryPosByPt(const VfxPoint& pt)
{
    VcpMenuPos p;	
    
   	p.group = 0;
    
    VfxS32 row = pt.y / m_cellHeight;
    p.pos = row - 2;
    
    if (p.pos < 0)
    {
        p.invalid();
    }
    else if (p.pos >= getCellCount(p.group))
   	{
        p.invalid();
   	}
   	return p;
}


VfxRect VappCubeMediaPlayerLayout::queryCellRect(VcpMenuPos pos)
{
    if (pos.group < 0 || pos.pos < -1 || m_cellCount == 0)
       	return VfxRect(-1, -1, 0, 0);
    
   	if (pos.group >= 1 || pos.pos >= getCellCount(pos.group))
       	return VfxRect(-1, -1, 0, 0);
    
    VfxS32 y = (pos.pos + 2) * m_cellHeight;
    
    return VfxRect(m_cellOffsetX, y , m_cellWidth, m_cellHeight);	
}


void VappCubeMediaPlayerLayout::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[0] = 0;
   	margin[1] = m_cellHeight * 2;
    margin[2] = 0;
    margin[3] = margin[1];
}

void VappCubeMediaPlayerLayout::setFocusItem(VcpMenuPos focus,  VfxBool isMoveToVisible)
{
    VcpBaseMenuLayout:: setFocusItem(focus, isMoveToVisible);
    
}
void VappCubeMediaPlayerLayout::fixFocusIndex()
{
    VfxS32 center = getViewPos().y + getViewSize().height / 2;
    VfxS32 newFocus = 0;
    VfxS32 oldFocus = getFocusItem().pos;
    
    if (m_cellHeight <= 0 || center <= 0)
    {
        return;
    }
    
    newFocus = center / m_cellHeight - 2;
    if (newFocus < 0)
    {
        newFocus = 0;
    }
    
    if (newFocus >= m_cellCount)
    {
        newFocus = m_cellCount - 1;
    }
    
    if (newFocus != oldFocus)
    {
        setFocusItem(VcpMenuPos(0,newFocus), VFX_TRUE);
        //printf("\n[Guoming] onViewChanged() setFocusItem = %d\n", newFocus);
    }
    
}

/*****************************************************************************
* Class VappCubeMediaPlayerMenu
*****************************************************************************/
VappCubeMediaPlayerMenu::VappCubeMediaPlayerMenu() 
: m_playPanel(NULL),
m_imageFlowData(NULL),
m_bWaitingFocusCell(VFX_FALSE),
m_pState(NULL),
m_listLayout(NULL)
{
    
}


void VappCubeMediaPlayerMenu::onInit()
{
    VcpBaseMenu::onInit();
    
    m_isViewScrolling = VFX_FALSE;
    checkUpdate();
    enableVerticalScrollIndicator(VFX_FALSE);	
    m_state = Opening;	
    
    VFX_OBJ_CREATE(m_scrollTimer, VfxTimer, this);
    m_scrollTimer->setStartDelay(500);
    m_scrollTimer->setDuration(500);
    m_scrollTimer->m_signalTick.connect(this, &VappCubeMediaPlayerMenu::onScrollTimerTick);

    m_updateFocusIndex = -1;
    m_updateSeqNum = -3;
	VFX_OBJ_CREATE(m_updateTimer, VfxTimer, this);
    m_updateTimer->setStartDelay(500);
    m_updateTimer->setDuration(300);
    m_updateTimer->m_signalTick.connect(this, &VappCubeMediaPlayerMenu::onUpdateImageTick);
    
    VappCubeMediaPlayerScr *scr = (VappCubeMediaPlayerScr *)getScrPtr();
    if (scr->m_mode == EMPTY_MODE)
    {
        return;
    }
    VFX_OBJ_CREATE(m_imageFlowData, VappCubeMediaPlayerImageData, this);
    vadp_v2p_cube_media_player_register_cache_callback((void*)this, updateAll);
}

void VappCubeMediaPlayerMenu::onDeinit()
{
    
    if (m_scrollTimer)
    {
        m_scrollTimer->stop();    
    }
    
    
    VcpBaseMenu::onDeinit();
}

VfxBool VappCubeMediaPlayerMenu::getIsDisabled()
{
    return m_view->getIsDisabled();
}

// Set the control to disabled state.
void VappCubeMediaPlayerMenu::setIsDisabled(VfxBool isDisabled)
{
    m_view->setIsDisabled(isDisabled);  
	VappCubeMediaPlayerLayout *layout = (VappCubeMediaPlayerLayout *)m_layout;
	layout->setNavDisabled(isDisabled);
}
void VappCubeMediaPlayerMenu::setCacheNumber(VfxS32 number)
{        
    VappCubeMediaPlayerLayout *layout = (VappCubeMediaPlayerLayout *)m_layout;		
      m_cacheLen = number * layout->getCellHeight();

    
}
    
void VappCubeMediaPlayerMenu::updateAll(void* user_data, VfxS32 index)
{
    VfxImage* image;

    
    
    VappCubeMediaPlayerMenu* this_ptr = (VappCubeMediaPlayerMenu*) user_data;
	VcpMenuPos focus = this_ptr->m_layout->getFocusItem();  
    //kal_printf("\n[Guoming] updateAll() index = %d focus = %d", index, focus.pos);
    if (index < 0)
    {
        return;
    }
     VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)this_ptr->getCellIfPresent(0, index);
     if (cl)
     {
        this_ptr->m_imageFlowData->closeImageContent(index);
        image = this_ptr->m_imageFlowData->getSmallImageContent(index);
        this_ptr->updateCellPic(index, image);     
     }
    
    if (index >= 0)
    {        

        
        if (this_ptr->m_playPanel->getHidden() == VFX_FALSE)
        {

            VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)this_ptr->getCellIfPresent(focus.group, focus.pos);
            if (cl && (focus.pos == index))
            {
                image = this_ptr->m_imageFlowData->getBigImageContent(index);
                this_ptr->m_playPanel->setPicture(image);        
            }
            
        }
    }
    else
    {
#if 0   //@TODO:  if performance is good, need it to comfirm all the image have been updated
/* under construction !*/
/* under construction !*/
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
    }    
}
void VappCubeMediaPlayerMenu::updateCellPic(VfxS32 index, VfxImage *image)
{
    VappCubeMediaPlayerCell* item = (VappCubeMediaPlayerCell*)getCellIfPresent(0, index);
    if (item)
    {
        item->setPicture(image);
        //////kal_printf("updateCellPic(): update image index :%d", index); 
    }    
}

VcpBaseMenuLayout* VappCubeMediaPlayerMenu::createLayout()
{
    VappCubeMediaPlayerLayout *layout;
    VFX_OBJ_CREATE_EX(layout, VappCubeMediaPlayerLayout, this, (this));
    m_listLayout = layout;
    return layout;
}


VfxFrame* VappCubeMediaPlayerMenu::createCell(VfxS32 group, VfxS32 pos)
{
    VappCubeMediaPlayerCell *cell;
    
    VFX_OBJ_CREATE(
        cell,
        VappCubeMediaPlayerCell, 
        this);    /* constructor parameters */	
    
    VappCubeMediaPlayerLayout* layout = (VappCubeMediaPlayerLayout*)m_layout;
    cell->setCellInnerX(layout->getCellInnerX());
    cell->setCellInnerY(layout->getCellInnerY());
    
    if (m_bWaitingFocusCell)
    {
        
        VcpMenuPos focus = m_layout->getFocusItem();
        VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)getCellIfPresent(focus.group, focus.pos);
        if (cl)
        {
            vfxPostInvoke1(this, &VappCubeMediaPlayerMenu::checkFocusResume, cl);
            m_bWaitingFocusCell = VFX_FALSE;
        }	
        
        
    }
    
    return cell;
}


void VappCubeMediaPlayerMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VappCubeMediaPlayerCell *cell = (VappCubeMediaPlayerCell *)cellFrame;
    cell->setPicture(NULL);
    cell->clear();
    if (m_imageFlowData)
    {
        m_imageFlowData->closeImageContent(pos);
    }
    VFX_OBJ_CLOSE(cellFrame);
}

void VappCubeMediaPlayerMenu::onUpdateImageCell(VfxS32 index)
{
            
    VappCubeMediaPlayerCell* item = (VappCubeMediaPlayerCell*)getCellIfPresent(0, index);
    if (item)
    {
        VfxImage *p_img = m_imageFlowData->getSmallImageContent(index);
        item->setPicture(p_img);
    }

    
}

void VappCubeMediaPlayerMenu::onUpdateImageTick(VfxTimer *source)
{
    m_updateTimer->stop();
    
    VcpMenuPos focus = m_layout->getFocusItem();    
    if (m_updateFocusIndex == focus.pos)
    {
        if (m_updateSeqNum == -3)
        {
            m_imageFlowData->refreshImageContent(focus.pos);    
        }
        m_updateSeqNum++;  
    }
    else
    {
        m_imageFlowData->refreshImageContent(focus.pos);
        m_updateFocusIndex = focus.pos;
        m_updateSeqNum = -2;        
    }    
    
    if (m_updateSeqNum <= 2)
    {
        
        onUpdateImageCell(m_updateFocusIndex + m_updateSeqNum);
        m_updateTimer->start();    
    }
    else
    {
        m_updateSeqNum = -3;    
    }
}
void VappCubeMediaPlayerMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
	if (pos == 0)
	{
		pos = 0;
	}
    VfxTransform trans(VFX_TRANSFORM_TYPE_AFFINE);
    VappCubeMediaPlayerCell* item = (VappCubeMediaPlayerCell*) cell;
    
    if (!item->m_isLayouted)
    {
        item->setPos(VfxPoint(0, 0));
        item->setBounds(VfxRect(0, 0, rect.size.width, rect.size.height));
        //item->setPicture((void *)cubeimagehandle[pos]);
        VappCubeMediaPlayerScr *scr = (VappCubeMediaPlayerScr *)getScrPtr();
        if (scr->m_mode != EMPTY_MODE)
        {
            VfxImage *p_img = m_imageFlowData->getSmallImageContent(pos);
            item->setPicture(p_img);    
            {
                VfxU16 title[81];
                vadp_v2p_cube_media_player_get_song_title(pos, title);
                item->setSongName((VfxWChar *)&title);
            }
        }
        else
        {
            if (pos == 2)
            {
                item->setSongName((VfxWChar *)GetString(VAPP_CUBE_STR_MPLAYER_PLAYLIST_NOT_READY));  
            }
        }
        item->layout();
        //set transform
        {
            VFX_ASSERT(item->m_cd);
            
            trans.data.affine.sx = 0.63f;
    	       trans.data.affine.sy = 0.63f;
               
               item->m_cd->setTransform(trans);
               item->setOpacity(0.6f);
        }
    }	
    
    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {    
#if 1      //@TODO:  need this if  frame effect is done
        FramePropertyEffectData data;
        data.group = group;
        data.pos = pos;
        data.r = rect;
        
        item->setPropertyEffectCallback(
            m_view,
            &VappCubeMediaPlayerMenu::framePropertyEffectCallback, 
            &data,
            sizeof(data));
#endif               
        //item->setAutoAnimate(VFX_FALSE);
        item->setAutoAnimate(VFX_FALSE);
        item->m_cd->setAutoAnimate(VFX_FALSE);
        //((VcpImageFlowCell*)cell)->m_image->setAutoAnimate(VFX_FALSE);
    }        
    else
    {
        // item->setAutoAnimate(VFX_TRUE);
        //item->setAutoAnimate(VFX_TRUE);
        //item->m_cd->setAutoAnimate(VFX_TRUE);
        item->setAutoAnimate(VFX_FALSE);
        item->m_cd->setAutoAnimate(VFX_FALSE);        
        //((VcpImageFlowCell*)cell)->m_image->setAutoAnimate(VFX_TRUE);
    }   
    
    {
        VcpMenuPos focus = m_layout->getFocusItem();

        item->setAutoAnimate(VFX_TRUE);

        if (m_isViewScrolling)
        {
            trans.data.affine.sx = 0.63f;
            trans.data.affine.sy = 0.63f;
            
            item->m_cd->setTransform(trans);
            item->setOpacity(0.6f);                  
        }
        else if (focus.isValid())
        {
            if (focus.pos == pos)     
            {
                trans.data.affine.sx = 1.0f;
                trans.data.affine.sy = 1.0f;
                
                item->m_cd->setTransform(trans);     
                item->setOpacity(1.0f);
            }
            else if (pos + 1 == focus.pos || pos - 1 == focus.pos)
            {
                trans.data.affine.sx = 0.83f;
                trans.data.affine.sy = 0.83f;  
                
                item->m_cd->setTransform(trans);    
                item->setOpacity(0.6f);
            }    
            else if (pos + 2 == focus.pos || pos - 2 == focus.pos)
            {
                
                trans.data.affine.sx = 0.63f;
                trans.data.affine.sy = 0.63f;
                
                item->m_cd->setTransform(trans);
                item->setOpacity(0.6f);                  
            }
            else
            {
                // the same as pos+2, pos-2 currently
                trans.data.affine.sx = 0.63f;
                trans.data.affine.sy = 0.63f;
                
                item->m_cd->setTransform(trans);
                item->setOpacity(0.6f);              
            }

            
        }
        
    }
    /* important!!! if not, the cell can not be visualable */
    item->updatePos(rect, VFX_FALSE);          
   	if (flag & VCP_CELL_FLAG_FIRSTINIT)
   	{
        
        if (flag & VCP_CELL_FLAG_OPENING)
       	{
            item->updateImage();
            item->enter(rect, VFX_TRUE);
       	}
        else
        {
            item->updateImage();
            item->enter(rect, VFX_FALSE);
        }
   	}
    else if (flag & VCP_CELL_FLAG_CLOSING)
   	{
   	    item->setScroll(VFX_FALSE);
        item->leave(rect);
   	}
    else if (flag & VCP_CELL_FLAG_FORCESET)
    {
        item->setScroll(VFX_TRUE);	    
        item->updateImage();
        item->updatePos(rect, VFX_FALSE);
   	}
   	else
   	{
        item->updateImage();
        item->updatePos(rect, VFX_TRUE);
   	}
    
}

void VappCubeMediaPlayerMenu::onScrollStopPosFix(VfxPoint& pos)
{
    VfxS32 y1 = (pos.y / g_nlyt->cell.height) * g_nlyt->cell.height;
    VfxS32 y2 = ((pos.y + g_nlyt->cell.height - 1) / g_nlyt->cell.height) * g_nlyt->cell.height;

    if (VFX_ABS(pos.y - y1) < VFX_ABS(pos.y - y2))
    {
        pos.y = y1;
    }
    else
    {
        pos.y = y2;
    }
}

void VappCubeMediaPlayerMenu::onTouchCell(VcpMenuPos  cellPos, CellTouchTypeEnum   touchType, VfxPoint pt, VfxFrame *cell)
{

#if 0  //@TODO: May add high light in the future
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
}

void VappCubeMediaPlayerMenu::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{    
   	VappCubeMediaPlayerCell* item = (VappCubeMediaPlayerCell*) cell;
   	
	if (!m_pState)
	{
		return;
	}
    VcpMenuPos focus = m_layout->getFocusItem(); 
    VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)getCellIfPresent(focus.group, focus.pos);    
    if (cl)
    {                  
        cl->setScroll(VFX_FALSE);
        cl->onDeHightLight();
    }
    m_scrollTimer->stop();  
    
    if (focus.group == group && focus.pos == pos)
    {			
        if (cl)
        {            
            if (!getIsDisabled())
            {
                setIsDisabled(VFX_TRUE);            
            }
			
            VfxU8 state = m_pState->get();
            VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);
            switch (state)
            {
                case IDLE:
                    m_pState->set(TAP_TO_PREPARE);
                    break;

                case BG_PLAYING:
                    m_pState->set(TAP_TO_PLAY);
                    break;

                case BG_PAUSE:
                    m_pState->set(TAP_TO_PAUSE);
                    break;

                default:
                    EXT_ASSERT(0, state, pos, 0);
                    break;
            }
            VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_ON_TAP_FOCUS_CELL);
            m_eventTapCell.emit(pos, cell);	
            vadp_v2p_cube_media_player_set_focus_index(focus.pos);
        }	    
    }
    
}


void VappCubeMediaPlayerMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    VappCubeMediaPlayerCell* item = (VappCubeMediaPlayerCell*)getCellIfPresent(previousFocusItem.group, previousFocusItem.pos);
    
    
    
    if (item)
    {
        item->onDeHightLight();
        item->setScroll(VFX_FALSE);
        
    }	
    
    
    item = (VappCubeMediaPlayerCell*)getCellIfPresent(focusItem.group, focusItem.pos);	
    m_scrollTimer->stop();
    if (item)
    {
        item->setScroll(VFX_FALSE);
    }
    m_eventFocusChange.emit(focusItem.pos);
}



void VappCubeMediaPlayerMenu::onDragStart()
{   
    VcpMenuPos focus = m_layout->getFocusItem();
    VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)getCellIfPresent(focus.group, focus.pos);
    if (cl)
    {
        cl->setScroll(VFX_FALSE);	
    }
    
    m_scrollTimer->stop();
    vadp_v2p_cube_media_player_pause_cache();
    // printf("\n[Guoming] onDragStart()\n");
    VcpBaseMenu::onDragStart();
}


void VappCubeMediaPlayerMenu::onDragEnd()
{
    //VcpBaseMenu::onDragEnd();
#if 1 
    VappCubeMediaPlayerScr *scr = (VappCubeMediaPlayerScr *)getScrPtr();
    if (!m_isPageActReged)
    {
        scr->regDefaultPageAct(this);
        m_isPageActReged = VFX_TRUE;
    }
#endif
    m_scrollTimer->stop();
    m_scrollTimer->start();
    
    VcpBaseMenu::onDragEnd();
}

void VappCubeMediaPlayerMenu::onViewScrollStart()
{
    
    VcpMenuPos focus = m_layout->getFocusItem();
    VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)getCellIfPresent(focus.group, focus.pos);
    if (cl)
    {
        cl->setScroll(VFX_FALSE);	
    }
    vadp_v2p_cube_media_player_pause_cache();
    m_scrollTimer->stop();
    m_isViewScrolling = VFX_TRUE;
}

void VappCubeMediaPlayerMenu::checkFocusResume(VappCubeMediaPlayerCell* cl)
{
    ASSERT(cl != NULL);
    cl->setScroll(VFX_FALSE);		
    m_scrollTimer->stop();
    
    VcpMenuPos focus = m_layout->getFocusItem();
    vadp_v2p_cube_media_player_set_focus_index(focus.pos);
    
    m_eventTapCell.emit(focus.pos, cl);    
    
   // vadp_v2p_cube_media_player_resume_cache();
    
}

void VappCubeMediaPlayerMenu::onViewScrollEnd()
{
    VappCubeMediaPlayerScr *scr = (VappCubeMediaPlayerScr *)getScrPtr();
    m_isViewScrolling = VFX_FALSE;
    updateLayout();

    ((VappCubeMediaPlayerLayout*)getLayout())->fixFocusIndex();
     makeVisible(getLayout()->getFocusItem());


    if (scr->m_mode != EMPTY_MODE)
    {
        m_updateTimer->stop();
        m_updateTimer->start();            
        vadp_v2p_cube_media_player_resume_cache();
    }
    else
    {
        m_scrollTimer->stop();
        m_scrollTimer->start();     
        return;
    }
    
    if (scr->m_mode == NAVIGATION_MODE)
    {
        m_scrollTimer->stop();
        m_scrollTimer->start();  
    } 
    
    VcpMenuPos focus = m_layout->getFocusItem();    
    VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)getCellIfPresent(focus.group, focus.pos);
    
    if (!getIsDisabled())
    {
        return;   // if not disabled, do nothing  
    }  
    
    if (cl)
    {
        vfxPostInvoke1(this, &VappCubeMediaPlayerMenu::checkFocusResume, cl);
    }
    else
    {
        m_bWaitingFocusCell = VFX_TRUE;
    }
}

void VappCubeMediaPlayerMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VcpBaseMenu::onDrag(xoffset, yoffset);

    if (VFX_ABS(yoffset) > 3)
    {
        VappCubeMediaPlayerScr *scr = (VappCubeMediaPlayerScr *)getScrPtr();
        if (m_isPageActReged)
        {
            scr->deregDefaultPageAct(this);
            m_isPageActReged = VFX_FALSE;
        }
    }    
}

void VappCubeMediaPlayerMenu::onScrollTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    VcpMenuPos focus = m_layout->getFocusItem();
    VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)getCellIfPresent(focus.group, focus.pos);
    m_scrollTimer->stop();
    if (cl)
    {
        cl->setScroll(TRUE);
    }
    
    
    
}


VfxBool VappCubeMediaPlayerMenu::onContainPoint(const VfxPoint &point) const
{
	return VcpBaseMenu::onContainPoint(point);
}


void VappCubeMediaPlayerMenu::setCellWidth(VfxS32 value)
{
    VappCubeMediaPlayerLayout *layout = (VappCubeMediaPlayerLayout*)m_layout;
    if (layout)
    {
        layout->setCellWidth(value);
    }
}


void VappCubeMediaPlayerMenu::setCellHeight(VfxS32 value)
{
    VappCubeMediaPlayerLayout *layout = (VappCubeMediaPlayerLayout*)m_layout;
    
    if (layout)
    {
        layout->setCellHeight(value);
    }
    
}


void VappCubeMediaPlayerMenu::setCellCount(VfxS32 value)
{
    VappCubeMediaPlayerLayout *layout = (VappCubeMediaPlayerLayout*)m_layout;
    
    if (layout)
    {
        layout->setCellCount(value);
    }
}


void VappCubeMediaPlayerMenu::setCellInnerX(VfxS32 value)
{
    VappCubeMediaPlayerLayout *layout = (VappCubeMediaPlayerLayout*)m_layout;
    
    if (layout)
    {
        layout->setCellInnerX(value);
    }
}


void VappCubeMediaPlayerMenu::setCellInnerY(VfxS32 value)
{
    VappCubeMediaPlayerLayout *layout = (VappCubeMediaPlayerLayout*)m_layout;
    
    if (layout)
    {
        layout->setCellInnerY(value);
    }
}


void VappCubeMediaPlayerMenu::setHighLightIdx(VfxS32 value, VfxBool goToPlay)
{
    VcpMenuPos focus;
    focus.group = 0;
    focus.pos = value;
    
    m_layout->setFocusItem(focus, VFX_TRUE);
}


void VappCubeMediaPlayerMenu::setCellOffsetX(VfxS32 value)
{
    
    VappCubeMediaPlayerLayout *layout = (VappCubeMediaPlayerLayout*)m_layout;
    
    if (layout)
    {
        layout->setCellOffsetX(value);
        layout->update();
    }
}

/***************************************************************************** 
* VappCubeMediaPlayerImageData
*****************************************************************************/
void VappCubeMediaPlayerImageData::onInit()
{
    VfxObject::onInit();
    VfxS32 i = 0;
    
    while (i < VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM)
    {
        m_nBuff[i] = -1;
        i++;
    }      
    
    for (i = 0; i < VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM; i++)
    {
        VFX_OBJ_CREATE(m_Image[i], VfxImage, this);
        m_smallCover[i].ptr = (VfxU8 *)vapp_cube_medply_s_cover_buf[i];
        m_smallCover[i].pitchBytes = VAPP_CUBE_MEDPLY_S_COVER_W * 2;
        m_smallCover[i].width = VAPP_CUBE_MEDPLY_S_COVER_W;
        m_smallCover[i].height = VAPP_CUBE_MEDPLY_S_COVER_H;
        m_smallCover[i].colorFormat = VRT_COLOR_TYPE_RGB565;
    }
    
    m_bigImageIndex = -1;
    VFX_OBJ_CREATE(m_bigImage, VfxImage, this);
    m_largeCover.ptr = (VfxU8 *)vapp_cube_medply_l_cover_buf[0];
    m_largeCover.pitchBytes = VAPP_CUBE_MEDPLY_L_COVER_W * 2;
    m_largeCover.width = VAPP_CUBE_MEDPLY_L_COVER_W;
    m_largeCover.height = VAPP_CUBE_MEDPLY_L_COVER_H;
    m_largeCover.colorFormat = VRT_COLOR_TYPE_RGB565; 
    
    
}


void VappCubeMediaPlayerImageData::onDeinit()
{
    VfxS32 i;
    
    for (i = 0; i < VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM; i++)
    {
        
        m_smallCover[i].ptr = (VfxU8 *)NULL;
        m_smallCover[i].pitchBytes = VAPP_CUBE_MEDPLY_S_COVER_W * 2;
        m_smallCover[i].width = VAPP_CUBE_MEDPLY_S_COVER_W;
        m_smallCover[i].height = VAPP_CUBE_MEDPLY_S_COVER_H;
        m_smallCover[i].colorFormat = VRT_COLOR_TYPE_RGB565;
        VFX_OBJ_CLOSE(m_Image[i]);     
    }
    
    m_bigImageIndex = -1;
    m_largeCover.ptr = (VfxU8 *)NULL;
    m_largeCover.pitchBytes = VAPP_CUBE_MEDPLY_L_COVER_W * 2;
    m_largeCover.width = VAPP_CUBE_MEDPLY_L_COVER_W;
    m_largeCover.height = VAPP_CUBE_MEDPLY_L_COVER_H;
    m_largeCover.colorFormat = VRT_COLOR_TYPE_RGB565;
    VFX_OBJ_CLOSE(m_bigImage);
    
    VfxObject::onDeinit();
}

VfxImage* VappCubeMediaPlayerImageData::getSmallImageContent(VfxS32 index)
{
    VfxS32 i;
    VfxS32 ret = -1;
    VfxWString temp;
    
    if (index < 0)
    {
        return NULL;
    }
    for (i = 0; i< VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM ; i++ )
    {
        if (m_nBuff[i] == index)
        {
            return m_Image[i];        
        }
    }
    
    for (i = 0; i < VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM; i++)
    {
        if (m_nBuff[i] == -1)
        {
            ret = vadp_v2p_cube_media_player_get_cover(index, (U8 *)m_smallCover[i].ptr, 0);
            //	////kal_printf("\n[Guoming]getSmallImageContent() ret = %d", ret);
            if (ret == 1)
            {
                m_nBuff[i] = index; 
                m_Image[i]->setImageBuf(m_smallCover[i]); 
                return m_Image[i];   
            } 
            else
            {
                return NULL;
            }            
        }
    }    
    //////kal_printf("\n[Guoming] no m_nBuff for small image");    
    return NULL;
}

VfxImage* VappCubeMediaPlayerImageData::getBigImageContent(VfxS32 index)
{
    VfxS32 ret = -1;
    //kal_printf("\n[Guoming]getBigImageContent() index = %d", index);
    if (index < 0)
    {
        return NULL;
    }
    
    if (m_bigImageIndex == index)
    {
        return m_bigImage;
    }
    else
    {   
        ret = vadp_v2p_cube_media_player_get_cover(index, (U8 *)m_largeCover.ptr, 1);
        // ////kal_printf("\n[Guoming]getBigImageContent() ret = %d", ret);
        if (ret == 1)
        {
            m_bigImageIndex = index;
            m_bigImage->setImageBuf(m_largeCover);        
            return m_bigImage;
        }
        else
        {
            return NULL;
        }
    }
}

void VappCubeMediaPlayerImageData::closeImageContent(VfxS32 index)
{
    VfxS32 i;
    
    m_bigImageIndex = -1;
    for (i = 0; i < VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM; i++)
    {
        if (m_nBuff[i] == index)
        {
            m_nBuff[i] = -1; 
            return;
        }
    }   
}


void VappCubeMediaPlayerImageData::refreshImageContent(VfxS32 index)
{
    VfxS32 begin = index - VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM / 2;
    VfxS32 end = index + VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM / 2;
    VfxS32 i;
    
    if (begin < 0)
    {

        for (i = 0; i < VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM; i++)
        {
            if (m_nBuff[i] > end)
            {
                m_nBuff[i] = -1;
            }
        }
    }
    else
    {

        for (i = 0; i < VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM; i++)
        {
            if (m_nBuff[i] > end)
            {
                m_nBuff[i] = -1;
            }
            if (m_nBuff[i] < begin)
            {
                 m_nBuff[i] = -1;
            }
        }        
    }
}


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
extern float verti_factor;
extern float freerun_factor;

#ifdef __cplusplus
}   /* extern "C" */
#endif 

/*****************************************************************************
* Class VappMediaWallSrc
*****************************************************************************/
VappCubeMediaPlayerScr::VappCubeMediaPlayerScr(): m_state(), m_bgImage(NULL), m_curPlayBtn(NULL),m_playAgent(NULL)
{    
    m_cellWidth = g_nlyt->cell.width;
    m_cellHeight = g_nlyt->cell.height;
    m_cellInnerX = 0;
    m_cellInnerY = 0;
    m_isPageActReged = VFX_TRUE;
    m_uiStyle = EMPTY_UI;
    m_mode = STARTUP_MODE;   
    m_hasSetPlayIndex = VFX_FALSE;  
}

void VappCubeMediaPlayerScr::onInit()
{
    VappCubeScr::onInit();
    VfxS32 total = 0;      
    
    vadp_v2p_cube_media_player_init();
    total = vadp_v2p_cube_media_player_get_item_count();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX, total);
    m_highLightIdx = vadp_v2p_cube_media_player_get_active_index();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX, m_highLightIdx);

    /* determine mode */
    if (total <= 0 || m_highLightIdx == -1)
    {
        m_cellCount = 5;
        m_highLightIdx = 2;
        m_uiStyle = EMPTY_UI;
        m_mode = EMPTY_MODE;
    }
    else 
    {
        m_cellCount =  total;
        m_uiStyle = NAVIGATION_UI;
        m_mode = STARTUP_MODE;   
        
    }   
    
    if (m_mode != EMPTY_MODE)
    {
        vadp_v2p_cube_media_player_init_cache_srv(m_cellCount);
        vadp_v2p_cube_media_player_set_focus_index(m_highLightIdx);
    }
    
    /* draw bg */
    VFX_OBJ_CREATE(m_bgImage, VfxImageFrame, this);
    m_bgImage->setResId(VAPP_CUBE_MEDIA_PLAYER_IMG_BG);
    m_bgImage->setIsCached(VFX_TRUE);
    m_bgImage->setIsOpaque(VFX_TRUE);
    
    /* config menu layout */
    VFX_OBJ_CREATE(m_menu, VappCubeMediaPlayerMenu, this);
    m_menu->setCellCount(m_cellCount);
    m_menu->setCellWidth(m_cellWidth);
    m_menu->setCellHeight(m_cellHeight);
    m_menu->setCellInnerX(m_cellInnerX);
    m_menu->setCellInnerY(m_cellInnerY);
    m_menu->setCellOffsetX(10);
    m_menu->setCacheNumber(1);
    m_menu->setPos(VfxPoint(g_nlyt->menu.offset_x, g_nlyt->menu.offset_y));
    m_menu->setBounds(VfxRect(
        0, 
        0, 
        g_nlyt->cell.width, 
        g_nlyt->cell.height * 5));
    m_menu->setIsCached(VFX_TRUE);
    m_menu->setContentOffset(VfxPoint(0, g_nlyt->cell.height * m_highLightIdx));
    m_menu->setSlowFactor(0.1f, verti_factor, freerun_factor);

    
    /* at empty mode, no need more */
    if (m_mode == EMPTY_MODE)
    {
        return;
        
    }

    /* menu event and callback */
    m_menu->m_eventTapCell.connect(this, &VappCubeMediaPlayerScr::onEventTapCell);
    m_menu->m_eventFocusChange.connect(this, &VappCubeMediaPlayerScr::onEventFocusChange);
    m_menu->m_pState = &this->m_state;

    /* cur play button in navigation mode. if pressed, would back to current play item */
    VFX_OBJ_CREATE(m_curPlayBtn, VappCubeMediaPlayerButton, this);    
    m_curPlayBtn->setPos(VfxPoint(g_nlyt->cur_play.offset_x, g_nlyt->cur_play.offset_y));
    m_curPlayBtn->setBounds(VfxRect(0, 0, g_nlyt->cur_play.width, g_nlyt->cur_play.height));
    m_curPlayBtn->setImage(VAPP_CUBE_MEDIA_PLAYER_IMG_CUR_PLAY, VAPP_CUBE_MEDIA_PLAYER_IMG_HIGH_LIGHT);
    m_curPlayBtn->m_eventPenUp.connect(this, &VappCubeMediaPlayerScr::onEventUpCurPlay);
    m_curPlayBtn->setIsDisabled(VFX_TRUE);
    
    /* config play panel */
    VFX_OBJ_CREATE(m_playPanel, VappCubeMediaPlayerPlayPanel, this);
    m_menu->m_playPanel = m_playPanel;    

    
    /* create play agent */
    VFX_OBJ_CREATE(m_playAgent, VappCubeMediaPlayerAgent, this);  
    m_playAgent->m_eventUpdate.connect(this, &VappCubeMediaPlayerScr::onEventUpdate);
    m_playAgent->m_eventPlayEnd.connect(this, &VappCubeMediaPlayerScr::onEventPlayEnd);
    m_playAgent->m_eventMediaChanged.connect(this, &VappCubeMediaPlayerScr::onEventMediaChange);
    m_playAgent->m_eventStop.connect(this, &VappCubeMediaPlayerScr::onEventPlayStop);
    m_playAgent->m_eventPlay.connect(this, &VappCubeMediaPlayerScr::onEventPlaying);
    m_playAgent->m_eventPause.connect(this, &VappCubeMediaPlayerScr::onEventPlayPaused);
    m_playAgent->m_eventStatusChanged.connect(this, &VappCubeMediaPlayerScr::onEventStatusChange);
    
    /* config repeat and shuffle */
    {
        VfxBool repeatOne;
        VfxBool repeatAll;
        VfxBool repeatOff;
        VfxBool shuffle;
        
        m_playAgent->getRepeat(&repeatOne, &repeatAll, &repeatOff);
        m_playPanel->setRepeat(repeatOne, repeatAll, repeatOff);
        m_playAgent->getShuffle(&shuffle);
        m_playPanel->setShuffle(shuffle);
    }    

    /* play panel init state */
    m_playPanel->layout();
    m_playPanel->setHidden(VFX_TRUE); 
    m_playPanel->setIsDisabled(VFX_TRUE);
    m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE); 
    m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);
  
    m_playPanel->m_closeButton->m_eventPenUp.connect(this, &VappCubeMediaPlayerScr::onEventUpClose);
    m_playPanel->m_eventSwitch.connect(this, &VappCubeMediaPlayerScr::onSwitchPlay);
    m_playPanel->m_repeatButton->m_eventRepeatOne.connect(m_playAgent, &VappCubeMediaPlayerAgent::OnRepeatOne);
    m_playPanel->m_repeatButton->m_eventRepeatAll.connect(m_playAgent, &VappCubeMediaPlayerAgent::OnRepeatAll);
    m_playPanel->m_repeatButton->m_eventRepeatOff.connect(m_playAgent, &VappCubeMediaPlayerAgent::OnRepeatOff);
    m_playPanel->m_shuffleButton->m_eventShuffleOn.connect(m_playAgent, &VappCubeMediaPlayerAgent::OnShuffleOn);
    m_playPanel->m_shuffleButton->m_eventShuffleOff.connect(m_playAgent, &VappCubeMediaPlayerAgent::OnShuffleOff);
    m_playPanel->m_playButton->m_eventPenUp.connect(m_playAgent, &VappCubeMediaPlayerAgent::onPlay);
    m_playPanel->m_pauseButton->m_eventPenUp.connect(m_playAgent, &VappCubeMediaPlayerAgent::onPause);
    m_playPanel->m_stopButton->m_eventPenUp.connect(m_playAgent, &VappCubeMediaPlayerAgent::onStop);
    

    /*start startup timer, to decide the next mode */
    m_mode = STARTUP_MODE;
    disableNavigation();    
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);       
    m_timer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_timer->setDuration(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_timer->m_signalTick.connect(this, &VappCubeMediaPlayerScr::onTimerTick);
	m_timer->start();   
    
}

void VappCubeMediaPlayerScr::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    m_timer->stop();

        
    if (m_playAgent->getState() != VAPP_CUBE_MEDIA_PLAYER_STATE_INIT)
    {  
       /*  seems it as bg playing, tap to play */
        if (m_highLightIdx == m_playAgent->getCurPlayIndex())
        {
            m_state.set(TAP_TO_PLAY);        
            VfxFrame *cl = m_menu->getCellIfPresent(0, m_highLightIdx);  
            if (cl)
            {
                onEventTapCell(m_highLightIdx, cl);    
            }        
        }
        else
        {
            // media changed during startup. 
        }

    }
    else
    {    
        /* seems it as no bg playing, change to NAVIGATION_MODE */
        VfxU64 m_curTime = m_playAgent->getCurrTime();
        VfxU64 m_totalTime = m_playAgent->getDuration();
        if (m_curTime > 0 && m_curTime < m_totalTime)
        {
             m_state.set(BG_PAUSE);
        }
        else
        {
             m_state.set(IDLE);
        }
        enableNavigation();
        m_mode = NAVIGATION_MODE;
    }
}

void VappCubeMediaPlayerScr::onDeinit()
{   
    
    if (m_mode != EMPTY_MODE)
    {       
        vadp_v2p_cube_media_player_deinit_cache_srv();
        if (m_playPanel)
        {
            m_playPanel->clear();
            VFX_OBJ_CLOSE(m_playPanel);
            m_playPanel = NULL;
        }
        
        if (m_timer)
        {
            m_timer->stop();
            VFX_OBJ_CLOSE(m_timer);
            m_timer = NULL;
        }
      
        
        vadp_v2p_cube_media_player_unregister_cache_callback();  
    }
    
    vadp_v2p_cube_media_player_deinit();
    VappCubeScr::onDeinit();
}

void VappCubeMediaPlayerScr::regPageAct(VfxControl *obj)
{
    if (m_isPageActReged)
    {
        return;
    }
    if (obj)
    {
        m_isPageActReged = VFX_TRUE;
        regDefaultPageAct(obj);
    }
}

void VappCubeMediaPlayerScr::deregPageAct(VfxControl *obj)
{
    if (!m_isPageActReged)
    {
        return;
    }
    if (obj)
    {
        m_isPageActReged = VFX_FALSE;
        deregDefaultPageAct(obj);
    }    
}

void VappCubeMediaPlayerScr::onEventFocusChange(VfxS32 index)
{
    m_highLightIdx = index;    
    vadp_v2p_cube_media_player_set_focus_index(index);
}

void VappCubeMediaPlayerScr::onSwitchPlay(VfxS32   delta)
{
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_ON_SWITCH_PLAY); 
    
    VfxU8 state = m_state.get(); 
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);
    switch (state)
    {
        case PLAYING:   // user click close when playing
            m_state.set(SWIP_TO_PLAY);
            break;
            
        case PAUSE: // media change when playing
            m_state.set(SWIP_TO_PREPARE);
            break;

        case ASKED_TO_PREPARE:
        case PREPARED:        
            m_state.set(SWIP_TO_PREPARE);
            break;

        case ASKED_TO_PLAY:
            m_state.set(SWIP_TO_PLAY);
            break;
            
        default:
            EXT_ASSERT(0, state, m_highLightIdx, delta);
            break;        
    } 
    
    if (m_highLightIdx == 0 && delta < 0)
    {
        m_mode = PRE_NAVIGATION_MODE;
        m_state.set(SWIP_TO_IDLE);
    }
    
    if (m_highLightIdx == (m_cellCount - 1) && delta > 0)
    {
        m_mode = PRE_NAVIGATION_MODE;
        m_state.set(SWIP_TO_IDLE);
    }
    
  
    m_highLightIdx += delta;    
    if (m_highLightIdx < 0)    
    {
        m_highLightIdx = 0;    
    }
    else if (m_highLightIdx >= m_cellCount)
    {
        m_highLightIdx = m_cellCount - 1;   
    }  
    
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX, m_highLightIdx);    
    VfxPenEvent event;
    event.type = VFX_PEN_EVENT_TYPE_UNKNOWN;
    // should not postInvoke currently. If want to, please consider carefully
    onEventUpClose(event);
}

void VappCubeMediaPlayerScr::onBackEffectFinish(VfxFrame* cell, VfxBool  b)
{
    m_effectBack->m_signalFinished.disconnect(this, &VappCubeMediaPlayerScr::onBackEffectFinish);
    m_effectFront->m_signalFinished.disconnect(this, &VappCubeMediaPlayerScr::onFrontEffectFinish);
    VFX_OBJ_CLOSE(m_effectFront);
    VFX_OBJ_CLOSE(m_effectBack);     

    //kal_printf("\n[Guoming] onBackEffectFinish() ");
    /* from navigation ui to play ui */
    if (m_uiStyle == NAV_TO_PANEL_UI)
    {            
        m_playPanel->setIsScroll(VFX_TRUE);        
        vfxPostInvoke0(this, &VappCubeMediaPlayerScr::preparePlayPanel);         
        return;
    }
    else if (m_uiStyle == PANEL_TO_NAV_UI)
    {
        m_playPanel->setHidden(VFX_TRUE);
        vfxPostInvoke0(this, &VappCubeMediaPlayerScr::adjustFocusItem);       
    }
}

void VappCubeMediaPlayerScr::delayToPlay()
{
    VfxPenEvent event;
    m_playAgent->onPlay(event);
}

void VappCubeMediaPlayerScr::preparePlayPanel()
{
    VfxObjWeakPtr this_ptr = this;
        
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_PREPARE_PANEL);
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX, m_highLightIdx);
    VfxU8 state = m_state.get();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);
    
    switch (state)
    {
        case BG_PLAYING:
        case BG_PAUSE:
        case IDLE: 
            return;
        
        case TO_RESUME_PAUSE: {
			m_playPanel->setIsPlay(VFX_FALSE);
			VfxU64 total_time = m_playAgent->getDuration();
			VfxU64 cur_time = m_playAgent->getCurrTime();
			VfxS32 total_for_log = (VfxS32)(total_time / 1000);
            VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME, total_for_log);
			m_playPanel->setCurTime((VfxS32)(cur_time / 1000));
			m_playPanel->setTotalTime((VfxS32)(total_time / 1000));	
			m_playPanel->setProgressRatio(cur_time, total_time);
            m_playPanel->m_playButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_pauseButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_stopButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_closeButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_shuffleButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_repeatButton->setIsDisabled(VFX_FALSE);
            m_state.set(PAUSE);
            break;  
            }
            
        case TO_RESUME_PLAY: {
			m_playPanel->setIsPlay(VFX_TRUE);
			VfxU64 total_time = m_playAgent->getDuration();
			VfxS32 total_for_log = (VfxS32)(total_time / 1000);
            VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME, total_for_log);
			VfxU64 cur_time = m_playAgent->getCurrTime();
			m_playPanel->setCurTime((VfxS32)(cur_time / 1000));
			m_playPanel->setTotalTime((VfxS32)(total_time / 1000));
			m_playPanel->setProgressRatio(cur_time, total_time);
			m_playPanel->setCurTimeDisplay(VFX_TRUE);
            m_playPanel->setTotalTimeDisplay(VFX_TRUE);
            m_playPanel->m_playButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_pauseButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_stopButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_closeButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_shuffleButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_repeatButton->setIsDisabled(VFX_FALSE);
            m_state.set(PLAYING);
            break;
            }
            
        case TO_PLAY: {
            m_hasSetPlayIndex = VFX_TRUE;            
            m_playAgent->setCurPlayIndex(m_highLightIdx);
            if (this_ptr == NULL)
            {
                return;
            }
			VfxU64 total_time = m_playAgent->getDuration();
			VfxS32 total_for_log = (VfxS32)(total_time / 1000);
            VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME, total_for_log);
			m_playPanel->setCurTime(0);
			m_playPanel->setTotalTime((VfxS32)(total_time / 1000));	
			m_playPanel->setProgressRatio(0);
            m_playPanel->setCurTimeDisplay(VFX_TRUE);
            m_playPanel->setTotalTimeDisplay(VFX_TRUE); 
            vfxPostInvoke0(this, &VappCubeMediaPlayerScr::delayToPlay); 
            if (this_ptr == NULL)
            {
                return;
            }
            m_playPanel->m_playButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_pauseButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_stopButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_closeButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_shuffleButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_repeatButton->setIsDisabled(VFX_FALSE);
            m_state.set(PLAYING);            
            break;
            }
        case ASKED_TO_PLAY: {
			VfxU64 total_time = m_playAgent->getDuration();
			VfxS32 total_for_log = (VfxS32)(total_time / 1000);
            VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME, total_for_log);
			m_playPanel->setCurTime(0);			
			m_playPanel->setTotalTime((VfxS32)(total_time / 1000));
			m_playPanel->setProgressRatio(0);
            m_playPanel->setCurTimeDisplay(VFX_TRUE);
            m_playPanel->setTotalTimeDisplay(VFX_TRUE);  

                     
            
            m_playPanel->m_playButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_pauseButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_stopButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_closeButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_shuffleButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_repeatButton->setIsDisabled(VFX_FALSE);
            vfxPostInvoke0(this, &VappCubeMediaPlayerScr::delayToPlay); 
            if (this_ptr == NULL)
            {
                return;
            }
            m_state.set(PLAYING);  
			break;
        }
        
        case TO_PREPARE: {
            m_state.set(PREPARED);
            m_hasSetPlayIndex = VFX_TRUE;
            m_playAgent->setCurPlayIndex(m_highLightIdx);
            if (this_ptr == NULL)
            {
                return;
            }            
			VfxU64 total_time = m_playAgent->getDuration();
			VfxS32 total_for_log = (VfxS32)(total_time / 1000);
            VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_TOTAL_TIME, total_for_log);
			m_playPanel->setCurTime(0);			
			m_playPanel->setTotalTime((VfxS32)(total_time / 1000));	
			m_playPanel->setProgressRatio(0);
            m_playPanel->setCurTimeDisplay(VFX_TRUE);
            m_playPanel->setTotalTimeDisplay(VFX_TRUE);
            m_playPanel->m_playButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_pauseButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_stopButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_closeButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_shuffleButton->setIsDisabled(VFX_FALSE);
            m_playPanel->m_repeatButton->setIsDisabled(VFX_FALSE);
            
            break;
            }

        
        default:
            break;            
    }

     m_playPanel->setIsDisabled(VFX_FALSE);
     // should stay at the last line of this function
     m_uiStyle = PANEL_UI;  
}

void VappCubeMediaPlayerScr::enableNavigation()
{
    m_curPlayBtn->setIsDisabled(VFX_FALSE);

    if (!m_isPageActReged)
    {
        regDefaultPageAct(this);
        m_isPageActReged = VFX_TRUE;
    }         
    if (m_menu->getIsDisabled())
    {
        m_menu->setIsDisabled(VFX_FALSE);
    } 
    m_menu->m_scrollTimer->stop();
    m_menu->m_scrollTimer->start();          
  
}

void VappCubeMediaPlayerScr::directClosePanel()
{

    m_playPanel->setIsScroll(VFX_FALSE);
    m_playPanel->setIsDisabled(VFX_TRUE);
    m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE); 
    m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);
    m_playPanel->setHidden(VFX_TRUE);
    
    m_uiStyle = NAVIGATION_UI;     
    enableNavigation(); 

    // should stay at the last line of this function
    m_mode = NAVIGATION_MODE;
}

void VappCubeMediaPlayerScr::adjustFocusItem()
{
    VfxObjWeakPtr this_ptr = this;
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_ADJUST_ITEM);
    //kal_printf("\n[Guoming] adjustFocusItem() ");
    VfxS32 index = m_playAgent->getCurPlayIndex();
    VfxU8 play_state = m_playAgent->getState();
    VfxU64 cur_time = m_playAgent->getCurrTime();     
    VfxU8 state = m_state.get();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX, index);
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX, m_highLightIdx); 

    ASSERT(m_mode != NAVIGATION_MODE);
    
    switch (state)
    {
        case SWIP_TO_IDLE:
            if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
            {
                if (cur_time == 0)
                {
                    m_state.set(IDLE);        
                }
                else
                {
                    m_state.set(BG_PAUSE);
                }    
            } 
            else
            {
                m_state.set(BG_PLAYING);
            }
            break; 
            
        case ASKED_TO_PLAY:        
        case ASKED_TO_PREPARE:            
        
            if (m_playAgent->isListEnd())
            {
                if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    if (cur_time == 0)
                    {
                        m_state.set(IDLE);        
                    }
                    else
                    {
                        m_state.set(BG_PAUSE);
                    }    
                } 
                else
                {
                    m_state.set(BG_PLAYING);
                }
            }
            else
            {  
                if (m_highLightIdx == index)
                {
                    if (state == ASKED_TO_PLAY)
                    {
                        VfxPenEvent event;
                       m_playAgent->onPlay(event);
                       if (this_ptr == NULL)
                       {
                            return;
                       }
                    }
                    
                    if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                    {
                        if (cur_time == 0)
                        {
                            m_state.set(IDLE);        
                        }
                        else
                        {
                            m_state.set(BG_PAUSE);
                        }    
                    } 
                    else
                    {
                        m_state.set(BG_PLAYING);
                    }
                    m_mode = PRE_NAVIGATION_MODE;
                }
                else
                {
                    if (VFX_ABS(index - m_highLightIdx) >= 20)
                    {
                        vadp_v2p_cube_media_player_reset();    
                    }
                    m_highLightIdx = index;
                }                
            }
            break;

        case IDLE:
        case BG_PAUSE:
        case BG_PLAYING:
        case SWIP_TO_PLAY:
        case SWIP_TO_PREPARE:
            break;
            
        default:
            EXT_ASSERT(0, state, 0, 0);    
    }           

    state = m_state.get();
    if (state == IDLE || state == BG_PAUSE || state == BG_PLAYING)
    {        
        
        enableNavigation();
        m_mode = NAVIGATION_MODE;        
   
    }
    else if (m_mode == PRE_NAVIGATION_MODE)
    {
        enableNavigation();
        m_mode = NAVIGATION_MODE;
        
    }
    else
    {        
        m_menu->setHighLightIdx(m_highLightIdx, VFX_TRUE);  
        
    } 
    // should stay at the last line of this function
    m_uiStyle = NAVIGATION_UI;
}


void VappCubeMediaPlayerScr::onFrontEffectFinish(VfxFrame* cell, VfxBool  b)
{    
     
}


void VappCubeMediaPlayerScr::disableNavigation()
{    
    m_curPlayBtn->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_curPlayBtn->setIsDisabled(VFX_TRUE);

    if (m_isPageActReged)
    {
        deregDefaultPageAct(this);
        m_isPageActReged = VFX_FALSE;
    }    
    if (!m_menu->getIsDisabled())
    {
        m_menu->setIsDisabled(VFX_TRUE);        
    } 
}

void VappCubeMediaPlayerScr::onEventTapCell(VfxS32 index, VfxFrame* cell)
{
    VfxObjWeakPtr this_ptr = this;
    VappCubeMediaPlayerCell *cl = (VappCubeMediaPlayerCell *)cell;
    VfxS32 ret = 0;
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_EVENT_TAP_CELL);  
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX, m_highLightIdx);  
    VfxS32 play_index = m_playAgent->getCurPlayIndex();
    VfxU8 play_state = m_playAgent->getState();
    VfxU64 cur_time = m_playAgent->getCurrTime();    
    VfxU8 state = m_state.get();    
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state); 
    
    EXT_ASSERT(cell != NULL, index, m_highLightIdx, 0);
    
    
    if (m_mode == EMPTY_MODE)
    {
        return;
    }
    if (m_uiStyle != NAVIGATION_UI)
    {
        return;
    }
    
    // only handle to tap event of highlighted index
    if (index != m_highLightIdx)
    {
        return;
    }

   
    // if using avrcp to change song many times, may cause this case
    if (m_highLightIdx != play_index)
    {
        switch (state)
        {
            case TAP_TO_PREPARE:
            case TAP_TO_PLAY:
            case TAP_TO_PAUSE:
            case SWIP_TO_PREPARE:
            case SWIP_TO_PLAY:
                break;
                

            case ASKED_TO_PREPARE:
            case ASKED_TO_PLAY:
                if (state == ASKED_TO_PLAY)
                {
                    VfxPenEvent event;
                    m_playAgent->onPlay(event);
                    if (this_ptr == NULL)
                    {
                        return;
                    }
                }
                if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    if (cur_time == 0)
                    {
                        m_state.set(IDLE);        
                    }
                    else
                    {
                        m_state.set(BG_PAUSE);
                    }    
                } 
                else
                {
                    m_state.set(BG_PLAYING);
                }
                enableNavigation();    
                m_mode = NAVIGATION_MODE;
                return;
        }       
    }
    
    // should stay here of this function 
    m_uiStyle = NAV_TO_PANEL_UI;  
    m_mode = PLAY_MODE; 
    
    if (cl)
    {                  
        cl->setScroll(VFX_FALSE);
        cl->onDeHightLight();
    } 
    m_hasSetPlayIndex = VFX_FALSE; 
    
    // disable navigation ui    
    disableNavigation();
    m_timer->stop();    
    m_menu->m_scrollTimer->stop(); 
    
    vfxPostInvoke0(this, &VappCubeMediaPlayerScr::loadPlayPanel);        
}

void VappCubeMediaPlayerScr::keepInNavigation()
{
    VfxObjWeakPtr this_ptr = this;
    VfxPenEvent event;
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_LOAD_PANEL);
    VfxS32 index = m_playAgent->getCurPlayIndex();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX, index); 
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX, m_highLightIdx);    
    VfxU8 state = m_state.get();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);
    
    switch (state)
    {
        
        case ASKED_TO_PLAY: {
            m_state.set(BG_PLAYING);
            VfxPenEvent event;
            m_playAgent->onPlay(event);
            if (this_ptr == NULL)
            {
                return;
            }
            break;
        }
        case TAP_TO_PLAY:
            m_state.set(BG_PLAYING);
            break;
            
        case TAP_TO_PAUSE:
            m_state.set(BG_PAUSE);
            break;

        case SWIP_TO_PLAY:
        case SWIP_TO_PREPARE:
        case ASKED_TO_PREPARE:    
        case TAP_TO_PREPARE: 
            m_state.set(IDLE);
            break;
            
        default:
           EXT_ASSERT(0, state, index, m_highLightIdx);
           break;     
    }    
    enableNavigation();    
    m_mode = NAVIGATION_MODE; 

    // should stay at the last line of this function
    m_uiStyle = NAVIGATION_UI;   
    
}

void VappCubeMediaPlayerScr::loadPlayPanel()
{
    vadp_v2p_cube_media_player_set_back_light_on();       

    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_LOAD_PANEL);
    VfxS32 index = m_playAgent->getCurPlayIndex();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX, index); 
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX, m_highLightIdx);    
    VfxU8 state = m_state.get();
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);
    switch (state)
    {
        case ASKED_TO_PLAY:
            m_playPanel->setCurTimeDisplay(VFX_FALSE);
            m_playPanel->setTotalTimeDisplay(VFX_FALSE); 
            m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);
            m_state.set(ASKED_TO_PLAY);
            break;
            
        case SWIP_TO_PLAY:
            m_playPanel->setCurTimeDisplay(VFX_FALSE);
            m_playPanel->setTotalTimeDisplay(VFX_FALSE);
            m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);
            m_state.set(TO_PLAY);
            break;
            
        case ASKED_TO_PREPARE:    
        case TAP_TO_PREPARE:            
        case SWIP_TO_PREPARE:
            m_playPanel->setCurTimeDisplay(VFX_FALSE);
            m_playPanel->setTotalTimeDisplay(VFX_FALSE);
            m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
            m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);
            m_state.set(TO_PREPARE);
            break;
            
        case TAP_TO_PLAY:
            if (index == m_highLightIdx)
           {
                m_playPanel->setCurTimeDisplay(VFX_FALSE);
                m_playPanel->setTotalTimeDisplay(VFX_FALSE);
                m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);           
                m_state.set(TO_RESUME_PLAY);    
            }
            else
            {
                VfxPenEvent event;
                m_playAgent->onStop(event);                
                m_playPanel->setCurTimeDisplay(VFX_FALSE);
                m_playPanel->setTotalTimeDisplay(VFX_FALSE);
                m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);
                m_state.set(TO_PLAY);
            }
            break;   
   
            
        case TAP_TO_PAUSE:
            if (index == m_highLightIdx)
            {
                m_state.set(TO_RESUME_PAUSE);                 
            }
            else
            {
                VfxPenEvent event;
                m_playAgent->onStop(event);
                
                m_playPanel->setCurTimeDisplay(VFX_FALSE);
                m_playPanel->setTotalTimeDisplay(VFX_FALSE);
                m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
                m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);
                m_state.set(TO_PREPARE);               
            }
            break;           
        
        
        default:
           EXT_ASSERT(0, state, index, m_highLightIdx);
           break;            
    } 
    

    
    // set play panel song title and cover image
    {
        VfxU16 title[81];
        vadp_v2p_cube_media_player_get_song_title(m_highLightIdx, title);
        m_playPanel->setSongName((VfxWChar *)&title);
        VfxImage *img = m_menu->m_imageFlowData->getBigImageContent(m_highLightIdx);
        m_playPanel->setPicture(img);
    }     

    VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)m_menu->getCellIfPresent(0, m_highLightIdx);
    if (cl)
    {        
        m_playPanel->setHidden(VFX_FALSE); 
        m_playPanel->setIsDisabled(VFX_TRUE);
        m_curPlayBtn->setIsDisabled(VFX_TRUE);
        VFX_OBJ_CREATE(m_effectFront, VcpFrameEffect, this);
        VFX_OBJ_CREATE(m_effectBack, VcpFrameEffect, this);     
        m_effectBack->m_signalFinished.connect(this, &VappCubeMediaPlayerScr::onBackEffectFinish);
        m_effectFront->m_signalFinished.connect(this, &VappCubeMediaPlayerScr::onFrontEffectFinish);        
#ifdef MMI_CUBE_MEDPLY_LITE 
        m_effectBack->applyEffect(m_playPanel, VCP_EFFECT_FADE_IN, 600, VCP_EFFECT_DIRECTION_FROM_LEFT);
        m_effectFront->applyEffect(cl->m_cd, VCP_EFFECT_FADE_IN, 600, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_TRUE);	
#else
        m_effectBack->applyEffect(m_playPanel, VCP_EFFECT_FLIP, 600, VCP_EFFECT_DIRECTION_FROM_LEFT);
        m_effectFront->applyEffect(cl->m_cd, VCP_EFFECT_FLIP, 600, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_TRUE);	
#endif                  
    }
}


void VappCubeMediaPlayerScr::onEventUpClose(VfxPenEvent &event)
{  
    
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_EVENT_UP_CLOSE);
    VfxU8 state = m_state.get(); 
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);
    switch (state)
    {
        case PLAYING:   // user click close when playing
            m_state.set(BG_PLAYING);
            break;

        case PAUSE:
            m_state.set(BG_PAUSE);
            break;

        case PREPARED:
            m_state.set(IDLE);
            break;
            
        case ASKED_TO_PLAY: // media change when playing
            if (event.type == VFX_PEN_EVENT_TYPE_UP)
            {
                m_state.set(BG_PLAYING);    
            }
            break;
            

        case SWIP_TO_PLAY: {
            VfxPenEvent event;
            m_playAgent->onStop(event);
            break;
			}
        case SWIP_TO_IDLE: {
            VfxPenEvent event;
            m_playAgent->onStop(event);
            break;
			}
        case ASKED_TO_PREPARE:
        case SWIP_TO_PREPARE: {
            break;
			}
			
        default:
            EXT_ASSERT(0, state, m_highLightIdx, 0);
            break;        
    }     
     
    m_playPanel->setIsScroll(VFX_FALSE);
   
    
    
    if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_mode = PRE_NAVIGATION_MODE;         
    }
    
    VappCubeMediaPlayerCell* cl = (VappCubeMediaPlayerCell*)m_menu->getCellIfPresent(0, m_highLightIdx);
    ASSERT(cl != NULL);
    m_playPanel->setIsDisabled(VFX_TRUE);
    m_playPanel->m_playButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_pauseButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_stopButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_closeButton->setIsDisabled(VFX_TRUE); 
    m_playPanel->m_shuffleButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_repeatButton->setIsDisabled(VFX_TRUE);
    m_playPanel->m_playButton->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_playPanel->m_stopButton->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_playPanel->m_pauseButton->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_playPanel->m_closeButton->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_playPanel->m_shuffleButton->m_shuffleOnBtn->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_playPanel->m_shuffleButton->m_shuffleOffBtn->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_playPanel->m_repeatButton->m_repeatOneBtn->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_playPanel->m_repeatButton->m_repeatAllBtn->setPenType(VFX_PEN_EVENT_TYPE_UP);
    m_playPanel->m_repeatButton->m_repeatOffBtn->setPenType(VFX_PEN_EVENT_TYPE_UP);

    
     /* config event of frame effect */
    VFX_OBJ_CREATE(m_effectFront, VcpFrameEffect, this);
    VFX_OBJ_CREATE(m_effectBack, VcpFrameEffect, this);     
    m_effectBack->m_signalFinished.connect(this, &VappCubeMediaPlayerScr::onBackEffectFinish);
    m_effectFront->m_signalFinished.connect(this, &VappCubeMediaPlayerScr::onFrontEffectFinish);
#ifdef MMI_CUBE_MEDPLY_LITE 
    m_effectFront->applyEffect(m_playPanel, VCP_EFFECT_FADE_IN, 600, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_TRUE);
    m_effectBack->applyEffect(cl->m_cd, VCP_EFFECT_FADE_IN, 600, VCP_EFFECT_DIRECTION_FROM_LEFT);
#else
    m_effectFront->applyEffect(m_playPanel, VCP_EFFECT_FLIP, 600, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_TRUE);
    m_effectBack->applyEffect(cl->m_cd, VCP_EFFECT_FLIP, 600, VCP_EFFECT_DIRECTION_FROM_LEFT);
#endif 

    // should stay at the last line of this function
    m_uiStyle = PANEL_TO_NAV_UI; 
}

void VappCubeMediaPlayerScr::onEventUpCurPlay(VfxPenEvent &event)
{  
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    if (m_mode != NAVIGATION_MODE)
    {
        return;
    }

    if (m_mode != NAVIGATION_UI)
    {
        return;
    }
    
    VfxS32 play_index = m_playAgent->getCurPlayIndex();
    if (play_index == -1)
    {
        play_index = 0;
    }

    if (VFX_ABS(play_index - m_highLightIdx) >= 20)
    {
        vadp_v2p_cube_media_player_reset();    
    }

    m_highLightIdx = play_index;
   
    
    if (m_menu)
    {
        if (m_uiStyle == NAVIGATION_UI)
        {
            m_menu->setHighLightIdx(m_highLightIdx, VFX_TRUE);
            m_menu->m_scrollTimer->stop();
            m_menu->m_scrollTimer->start(); 
        }        
    }
}

void VappCubeMediaPlayerScr::onEventUpdate()
{ 
    VfxU64 cur_time = m_playAgent->getCurrTime(); 
    VfxU64 total_time = m_playAgent->getDuration();
    
    m_playPanel->setProgressRatio(cur_time, total_time);
    m_playPanel->setCurTime((VfxS32)(cur_time / 1000));
    m_playPanel->setTotalTime((VfxS32)(total_time / 1000));
}


void VappCubeMediaPlayerScr::onEventPlayEnd()
{
    VfxS32 sec;
    
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_EVENT_PLAY_END);
    VfxU8 state = m_state.get();
    if (state == PLAYING || state == BG_PLAYING)
    {
        m_playPanel->getTotalTime(&sec);
        m_playPanel->setCurTime(sec);   
        m_playPanel->setProgressRatio(1000);
    }

    if (state == PLAYING)
    {
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();        
    }
}

void VappCubeMediaPlayerScr::onEventStatusChange()
{
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_EVENT_STATE_CHANGE);   
    
    VfxU8 play_state = m_playAgent->getState();
    VfxU64 cur_time = m_playAgent->getCurrTime();
    m_playPanel->setIsPlay((play_state == VAPP_CUBE_MEDIA_PLAYER_STATE_PLAY)? VFX_TRUE : VFX_FALSE);        
    VfxU8 state = m_state.get(); 
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);
    
    if (m_mode == STARTUP_MODE)
    {
        return;
    }

    if (m_mode == NAVIGATION_MODE)
    {
        ASSERT(m_uiStyle == NAVIGATION_UI);
        
        switch (state)
        {
            case IDLE:
            case BG_PAUSE:
                if (m_playAgent->getState() != VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    m_state.set(BG_PLAYING);
                }            
                break;       
        
        
            case BG_PLAYING:
                if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    if (cur_time == 0)
                    {
                        m_state.set(IDLE);        
                    }
                    else
                    {
                        m_state.set(BG_PAUSE);
                    }    
                }            
                break;

            default:
               EXT_ASSERT(0, m_uiStyle, state, 0);
        } 
        
        return;
    } 

    // play mode or pre_navigation mode
    if (m_uiStyle == PANEL_UI)
    {
        /* Sadly. I am not able to consider this case fully. */
        switch (state)
        {
            case PREPARED:
            case PAUSE:
                if (m_playAgent->getState() != VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    m_state.set(PLAYING);
                }            
                break;       
        
        
            case PLAYING:
                if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    if (cur_time == 0)
                    {
                        m_state.set(PREPARED);        
                    }
                    else
                    {
                        m_state.set(PAUSE);
                    }    
                }            
                break;

        }   
        onEventUpdate();
    }
    else if (m_uiStyle == NAVIGATION_UI)
    {
        switch (state)
        {
            case BG_PAUSE:
            case IDLE:
                if (m_playAgent->getState() != VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    m_state.set(BG_PLAYING);
                }
                break;              

            
            case BG_PLAYING:
                if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    if (cur_time == 0)
                    {
                        m_state.set(IDLE);        
                    }
                    else
                    {
                        m_state.set(BG_PAUSE);
                    }    
                }
                break; 

            default:
               // just pass other case currently
               break;

        }
    }
    else if (m_uiStyle == NAV_TO_PANEL_UI)
    {
        /* Sadly. I am not able to consider this case fully. */
         switch (state)
         {
            // background play resumed just after tapped a cell
            case TAP_TO_PREPARE:
                if (m_playAgent->getState() != VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    m_state.set(TAP_TO_PLAY);
                }             
                break;

            //background play resumed just during the Frame Flip animation    
            case TO_PREPARE:
                if (m_playAgent->getState() != VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    m_state.set(TO_RESUME_PLAY);
                }                         
                break;                
        
        }
    }
    else if (m_uiStyle == PANEL_TO_NAV_UI) 
    {
         switch (state)
         {
            case IDLE:
            case BG_PAUSE:
            case SWIP_TO_IDLE:
                if (m_playAgent->getState() != VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    m_state.set(BG_PLAYING);
                }                
                break;
            
            case BG_PLAYING:            
                if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                {
                    if (cur_time == 0)
                    {
                        m_state.set(IDLE);        
                    }
                    else
                    {
                        m_state.set(BG_PAUSE);
                    }    
                }                
                break;                
            
            case SWIP_TO_PLAY:                
            case SWIP_TO_PREPARE:
                // if do avrcp opration at this case, ignore it 
                break;
            
            case ASKED_TO_PLAY:
            case ASKED_TO_PREPARE:            
                // if do avrcp opration at this case, ignore it 
                break;               
 

            default:
                EXT_ASSERT(0, m_uiStyle, state, 0);
        
        }    
    
    }
             
}

void VappCubeMediaPlayerScr::delayAskToPlay()
{
    m_state.set(ASKED_TO_PLAY); 
    VfxPenEvent event;
    m_playAgent->onStop(event);                               


    event.type = VFX_PEN_EVENT_TYPE_UNKNOWN;
    onEventUpClose(event); 
}

void VappCubeMediaPlayerScr::onEventMediaChange()
{ 
    VFX_LOG(VFX_FUNC, VAPP_CUBE_MEDPLY_FUNC_EVENT_MEDIA_CHANGE);
    VfxS32 play_index = m_playAgent->getCurPlayIndex();
    VfxS32 last_index = m_playAgent->getLastPlayIndex();  
    VfxU8 play_state = m_playAgent->getState();
    VfxU64 cur_time = m_playAgent->getCurrTime();
    
    if (m_mode == STARTUP_MODE)
    {
        if (m_highLightIdx != play_index)
        {
            if (play_state != VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
            {
                VfxPenEvent event;
                m_state.set(ASKED_TO_PLAY);
                m_playAgent->onStop(event);
                if (VFX_ABS(play_index - m_highLightIdx) >= 20)
                {
                    vadp_v2p_cube_media_player_reset();    
                }
                m_highLightIdx = play_index;
                m_mode = PLAY_MODE;
                
                m_menu->setHighLightIdx(m_highLightIdx, VFX_TRUE); 
                m_uiStyle = NAVIGATION_UI;
            }
            else
            {
                // do nothing currently    
            }
             
        }
        return;
    }

    if (m_mode == NAVIGATION_MODE)
    {
        ASSERT(m_uiStyle == NAVIGATION_UI);
        return;
    }
    
    // if apply a index at cube media player, ignore the media change callback
    if (m_hasSetPlayIndex)  // may replace with lastIndex
    {
        m_hasSetPlayIndex = VFX_FALSE;
        return;
    }
  
  
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_HIGHLIGHT_INDEX, m_highLightIdx);
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_PLAY_INDEX, play_index);
    
    m_playPanel->setCurTime(0);
    m_playPanel->setProgressRatio(0);
    VfxU64 total_time = m_playAgent->getDuration();
    m_playPanel->setTotalTime((VfxS32)(total_time / 1000)); 
    
    VfxU8 state = m_state.get(); 
    VFX_LOG(VFX_INFO, VAPP_CUBE_MEDPLY_INFO_STATE, state);

    if (m_uiStyle == NAVIGATION_UI)
    {
        // do nothing currently    
    }
    else if (m_uiStyle == NAV_TO_PANEL_UI)
    {
        if (state == ASKED_TO_PLAY)
        {
            VfxPenEvent event;
             //m_playAgent->onPlay(event); //guoming: actually,
              vfxPostInvoke0(this, &VappCubeMediaPlayerScr::delayToPlay);
        }
        m_state.set(IDLE);
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
        directClosePanel();                
    }
    else if (m_uiStyle == PANEL_UI)
    {
        switch (state)
        {
            case PREPARED:
            case PAUSE:{
                vadp_v2p_cube_media_player_set_back_light_on();               
                if (vadp_v2p_cube_media_player_is_back_light_on())
                {
                    if (m_playAgent->isListEnd())
                    { 
                        if (last_index != play_index)
                        {
                            m_state.set(SWIP_TO_IDLE);
                            VfxPenEvent event;
                            event.type = VFX_PEN_EVENT_TYPE_UNKNOWN;
                            onEventUpClose(event);                             
                        } 
                    }
                    else
                    {
                        if (last_index != play_index)
                        {
                            m_state.set(ASKED_TO_PREPARE);   
                            VfxPenEvent event;
                            event.type = VFX_PEN_EVENT_TYPE_UNKNOWN;
                            onEventUpClose(event);                        
                        }
                    }            
                }
                else
                {  
                    if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                    {
                        if (cur_time == 0)
                        {
                            m_state.set(IDLE);        
                        }
                        else
                        {
                            m_state.set(BG_PAUSE);
                        }    
                    } 
                    else
                    {
                        m_state.set(BG_PLAYING);
                    }               
                    directClosePanel();                 
                } 
                
                break;
                }
         
                
            case PLAYING: { 
                vadp_v2p_cube_media_player_set_back_light_on();                
                if (vadp_v2p_cube_media_player_is_back_light_on())
                {
                    if (m_playAgent->isListEnd())
                    {
                        if (last_index != play_index)
                        {
                            m_state.set(SWIP_TO_IDLE);
                            VfxPenEvent event;
                            event.type = VFX_PEN_EVENT_TYPE_UNKNOWN;
                            onEventUpClose(event);                             
                        }  
                    }
                    else
                    {
                        if (last_index != play_index)
                        {
                             vfxPostInvoke0(this, &VappCubeMediaPlayerScr::delayAskToPlay);
                        }                            
                    }            
                }
                else
                {
                    if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE)
                    {
                        if (cur_time == 0)
                        {
                            m_state.set(IDLE);        
                        }
                        else
                        {
                            m_state.set(BG_PAUSE);
                        }    
                    } 
                    else
                    {
                        m_state.set(BG_PLAYING);
                    }               
                    directClosePanel();             
                }  
                break;   
             }          

                     
         
            
        }                 
    }
    else  // PANEL_TO_NAV
    {
        // do nothing currently
    }
}

void VappCubeMediaPlayerScr::onEventPlayStop()
{ 
    //kal_printf("\n[Guoming] onEventPlayStop() ");    
    m_playPanel->setCurTime(0);
    m_playPanel->setProgressRatio(0);
    m_playPanel->setIsPlay(VFX_FALSE);
   
}

void VappCubeMediaPlayerScr::onEventPlayPaused()
{

}

void VappCubeMediaPlayerScr::onEventPlaying()
{
    //kal_printf("\n[Guoming] onEventPlaying() ");
    
    if (m_playAgent->getState() == VAPP_CUBE_MEDIA_PLAYER_STATE_INIT)
    {        
        m_playPanel->setIsPlay(VFX_FALSE);    
    }
    else
    {
        m_playPanel->setIsPlay(VFX_TRUE);
    }
    VfxU64 total_time = m_playAgent->getDuration();
    m_playPanel->setTotalTime((VfxS32)(total_time / 1000));   

}
#endif

