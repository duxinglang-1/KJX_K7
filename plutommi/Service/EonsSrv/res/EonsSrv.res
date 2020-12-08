/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  EonsSrv.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the eons service.
 *
 * Author:
 * -------
 *  Weilun-Liu (mtk02772)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 10 2011 yan.liang
 * [MAUI_03077746] [MMI FRM]Fix callback manager spelling mistake
 * <saved by Perforce>
 *
 * 03 22 2011 weilun.liu
 * [MAUI_02899385] [Eons] add eons compile option
 * add compile option for slim project,
 * it will be turned off on LION52_V2_3232_GPRS(QQ)  and LION52_V2_3232_GPRS(QQ_RELEASE_KAL)
 *
 * 12 30 2010 weilun.liu
 * [MAUI_02646105] [Gemini+][BJ][CMCC]Sim3 shoule show Emergency when dial sos
 * initial sim if receive nw info changed event during bootup.
 *
 * 11 28 2010 weilun.liu
 * [MAUI_02842932] [Idle] Network name service revision and provide api for idle service indication string
 * revise network name service to support providing service indication string for specific sim.
 *
 * 11 02 2010 weilun.liu
 * [MAUI_02833901] [Idle] support SIM Refresh
 * .
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 09 30 2010 weilun.liu
 * [MAUI_02824995] [Idle, Scrsaver, ScrLocker, Eons, NwName] callback manager register revise
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_EONS_SRV__)
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_EONS">

    <!----- Include Area ------------------------------------------------------>


    <!----- String Resource Area ---------------------------------------------->


    <!----- Image Resource Area ----------------------------------------------->


    <!----- Screen Resource Area ---------------------------------------------->


    <!----- Menu Resource Area ------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->    

    /*
     * This event is emitted when the EONS service is updated.
     *
     * Structure: srv_eons_updated_evt_struct
     */
    <EVENT id="EVT_ID_SRV_EONS_UPDATED" type="SENDER"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_eons_main_evt_hdlr"/>

    <RECEIVER id="EVT_ID_SRV_NW_INFO_LOCATION_CHANGED" proc="srv_eons_main_evt_hdlr"/>

    <RECEIVER id="EVT_ID_SRV_NW_NAME_SIM_CHANGED_BY_SAT" proc="srv_eons_main_evt_hdlr"/>   
</APP>
#endif /* defined(__MMI_EONS_SRV__) */

