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
 *  vdat_network_info.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Network Service
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
#ifndef __VDAT_NETWORK_INFO_H__
#define __VDAT_NETWORK_INFO_H__

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_signal.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * Network Service Class
 */
class VdatNetworkInfo : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VdatNetworkInfo);

public:
    /*
     * SIM 1 related
     */
    void processNameChanged(const VfxWChar *name);
    void processStatusChanged(const VfxWChar *status);
    
    /*
     * SIM 2 related
     */
    void processNameChanged2(const VfxWChar *name);
    void processStatusChanged2(const VfxWChar *status);

    /*
     * Idle mode text and icon
     */
    void processIdleModeTextChanged(const VfxWChar *text);
    void processIdleModeIconChanged(const VfxU8 *iconPtr);
     
public:
    VdatNetworkInfo();

    /*
     * SIM 1 related
     */
    VfxWString getName() const;
    VfxWString getStatus() const;

    VfxSignal1 <VdatNetworkInfo *> m_signalNameChanged;
    VfxSignal1 <VdatNetworkInfo *> m_signalStatusChanged;

    /*
     * SIM 2 related
     */
    VfxWString getName2() const;
    VfxWString getStatus2() const;
    
    VfxSignal1 <VdatNetworkInfo *> m_signalNameChanged2;
    VfxSignal1 <VdatNetworkInfo *> m_signalStatusChanged2;

    /*
     * Idle mode text and icon
     */
    VfxWString getIdleModeText() const;
    const VfxU8 *getIdleModeIcon() const;
    
    VfxSignal1 <VdatNetworkInfo *> m_signalIdleModeTextChanged;
    VfxSignal1 <VdatNetworkInfo *> m_signalIdleModeIconChanged;

private:
    /*
     * SIM 1 related
     */
    VfxWString      m_name;
    VfxWString      m_status;
    
    /*
     * SIM 2 related
     */
    VfxWString      m_name2;
    VfxWString      m_status2;

    /*
     * Idle mode text and icon
     */
    VfxWString      m_idleModeText;
    const VfxU8    *m_iconPtr;
};

#endif /* __VDAT_NETWORK_INFO_H__ */

