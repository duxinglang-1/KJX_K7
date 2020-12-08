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
 *  vsrv_network.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "ui_core\base\vfx_base.h"
#include "ui_core\pme\vfx_pme.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vdat_network_info.h"


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VdatNetworkInfo);


/***************************************************************************** 
 * Global function
 *****************************************************************************/
VdatNetworkInfo::VdatNetworkInfo() :
    m_name(VFX_WSTR_NULL),
    m_status(VFX_WSTR_NULL),
    m_name2(VFX_WSTR_NULL),
    m_status2(VFX_WSTR_NULL),
    m_idleModeText(VFX_WSTR_NULL),
    m_iconPtr(NULL)
{
}
    

void VdatNetworkInfo::processNameChanged(const VfxWChar *name)
{
    m_name = VFX_WSTR_MEM(name);
    m_signalNameChanged.emit(this);
}


void VdatNetworkInfo::processStatusChanged(const VfxWChar *status)
{
    m_status = VFX_WSTR_MEM(status);
    m_signalStatusChanged.emit(this);
}


VfxWString VdatNetworkInfo::getName() const
{
    return m_name;
}


VfxWString VdatNetworkInfo::getStatus() const
{
    return m_status;
}


void VdatNetworkInfo::processNameChanged2(const VfxWChar *name)
{
    m_name2 = VFX_WSTR_MEM(name);
    m_signalNameChanged2.emit(this);
}


void VdatNetworkInfo::processStatusChanged2(const VfxWChar *status)
{
    m_status2 = VFX_WSTR_MEM(status);
    m_signalStatusChanged2.emit(this);
}


VfxWString VdatNetworkInfo::getName2() const
{
    return m_name2;
}


VfxWString VdatNetworkInfo::getStatus2() const
{
    return m_status2;
}


void VdatNetworkInfo::processIdleModeTextChanged(const VfxWChar *text)
{
    m_idleModeText = VFX_WSTR_MEM(text);
    m_signalIdleModeTextChanged.emit(this);
}


void VdatNetworkInfo::processIdleModeIconChanged(const VfxU8 *iconPtr)
{
    m_iconPtr = iconPtr;
    m_signalIdleModeIconChanged.emit(this);
}


VfxWString VdatNetworkInfo::getIdleModeText() const
{
    return m_idleModeText;
}


const VfxU8 *VdatNetworkInfo::getIdleModeIcon() const
{
    return m_iconPtr;
}

