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
 *  CcaSrv.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA resource file.
 *
 * Author:
 * -------
 *  Jianhua Zhao (mtk80037)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 lifang.yu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * .
 *
 * 12 15 2010 kefeng.lian
 * [MAUI_02644286] [CCA] Code revise
 * .
 *
 * 11 24 2010 kefeng.lian
 * [MAUI_02641899] [CCA] Check in CCA Split stage 2
 * .
 *
 * 11 24 2010 kefeng.lian
 * [MAUI_02641838] [CCA] Check in CCA Split stage 1
 * .
 *
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



 /***************************************************************************** 
  * Include 
  *****************************************************************************/
  
/*!---- 20 char --!------------------------------ total 81 char ---------------

#include "mmi_features.h"


/* Add new compile option to MMI_Features.h */

//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__

#include "CustResDef.h"

<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "SRV_CCA">

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>


<!----------------- Event Id ----------------------------------------------->
    /* Event id for Provisioning APs */
    <SENDER id = "EVT_ID_SRV_CCA_CHECK_APP_CONFIG"  hfile = "CcaSrvGprot.h"/>

    /* Event id for CcaApp only */
/*
    <SENDER id = "EVT_ID_SRV_CCA_NOTIFY" hfile = "CcaSrvIprot.h"/>
    <SENDER id = "EVT_ID_SRV_CCA_RECV_INVALID_MSG" hfile = "CcaSrvIprot.h"/>
    <SENDER id = "EVT_ID_SRV_CCA_RECV_NEW_MSG" hfile = "CcaSrvIprot.h"/>
    <SENDER id = "EVT_ID_SRV_CCA_VERIFY_PIN" hfile = "CcaSrvIprot.h"/>
    <SENDER id = "EVT_ID_SRV_CCA_PRE_INSTALL" hfile = "CcaSrvIprot.h"/>
    <SENDER id = "EVT_ID_SRV_CCA_POST_INSTALL" hfile = "CcaSrvIprot.h"/>
    <SENDER id = "EVT_ID_SRV_CCA_INSTALL_FINISHED" hfile = "CcaSrvIprot.h"/>
*/

<!----------------- XML END --------------------------------------------------->

</APP>

#endif /* __CCA_SUPPORT__ */






