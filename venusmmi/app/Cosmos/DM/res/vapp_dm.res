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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * vapp_tethering.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Tethering venusmmi resource.
 *
 * Author:
 * -------
 * Yixiong Zhao(mtk80274)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 13 2011 yixiong.zhao
 * [MAUI_03097129] [DM][Lawmo] App/Srv split and cosmos implement
 * .
 *
 * 06 13 2011 yixiong.zhao
 * [MAUI_02954526] [DM] App/Srv split check in
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#ifdef SYNCML_DM_SUPPORT
<APP id="VAPP_DM" name="STR_ID_VAPP_DM" type="venus">
    <INCLUDE file="GlobalResDef.h"/>
#ifdef __DM_LAWMO_SUPPORT__
    <MEMORY base="100*1024 + base(VCUI_DIALER_MAKE_CALL)" heap="100*1024"/>
#else
    <MEMORY base="100*1024" heap="100*1024"/>
#endif /* __DM_LAWMO_SUPPORT__ */

<!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_DM_LAWMO_LOCK_INFO"/>

#ifdef __DM_LAWMO_SUPPORT__
<RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="vappDmLawmoLockIndHdlr"/>
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_WIPE_EX_IND" proc="vappDmLawmoWipeIndHdlr"/>
#endif /* __DM_LAWMO_SUPPORT__ */
</APP>
#endif /* SYNCML_DM_SUPPORT */
