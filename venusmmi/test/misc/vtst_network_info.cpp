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
 *  vtst_network_info.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Network Service example for Venus UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_network_info.h"

#include "vfx_app_cat_scr.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vdat_network_info.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_signal.h"
#include "vfx_screen.h"


/***************************************************************************** 
 * Class VtstNetworkInfoScr
 *****************************************************************************/
 
VtstNetworkInfoScr::VtstNetworkInfoScr() :
    m_controlNetworkName(NULL),
    m_controlNetworkStatus(NULL)
{
}


void VtstNetworkInfoScr::onInit()
{
    VfxAppCatScr::onInit();

    /*
     * Setup the background color
     */
    setBgColor(VFX_COLOR_BLUE);

    /*
     * Get the network service
     */
    VdatNetworkInfo *networkSrv = VdatNetworkInfo::getInstance();

    /*
     * Add a text frames to screen
     */
    VFX_OBJ_CREATE(m_controlNetworkName, VfxTextFrame, this);
    m_controlNetworkName->setPos(VfxPoint(10, 10));
    m_controlNetworkName->setString(networkSrv->getName());
    
    VFX_OBJ_CREATE(m_controlNetworkStatus, VfxTextFrame, this);
    m_controlNetworkStatus->setPos(VfxPoint(10, 30));
    m_controlNetworkStatus->setString(networkSrv->getStatus());

    networkSrv->m_signalNameChanged.connect(this, &VtstNetworkInfoScr::onNetworkNameChanged);
    networkSrv->m_signalStatusChanged.connect(this, &VtstNetworkInfoScr::onNetworkStatusChanged);
}


void VtstNetworkInfoScr::onDeinit()
{
    // TODO: Remove these code after revise signal to auto disconnect
    VdatNetworkInfo *networkSrv = VdatNetworkInfo::getInstance();
    networkSrv->m_signalNameChanged.disconnect(this, &VtstNetworkInfoScr::onNetworkNameChanged);
    networkSrv->m_signalStatusChanged.disconnect(this, &VtstNetworkInfoScr::onNetworkStatusChanged);
    
    VfxScreen::onDeinit();
}


void VtstNetworkInfoScr::onNetworkNameChanged(VdatNetworkInfo *src)
{
    m_controlNetworkName->setString(src->getName());
}


void VtstNetworkInfoScr::onNetworkStatusChanged(VdatNetworkInfo *src)
{
    m_controlNetworkStatus->setString(src->getStatus());
}

