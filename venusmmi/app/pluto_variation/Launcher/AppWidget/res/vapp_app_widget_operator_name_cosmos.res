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
 *  vapp_app_widget_operator_name_cosmos.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the cosmos style operator name widget resources.
 *
 * Author:
 * -------
 *  Weilun Liu (mtk02772)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 09 2012 weilun.liu
 * [MAUI_03143458] [FTE2.0][Dynamic_SIM_DYNAMIC_UI_and_SIM_name]New feature check in
 * check  in operator name widget which support dynamic sim ui
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_APP_WIDGET_OPERATOR_NAME_COSMOS">

    <!-- Common Resource Area -------------------------------------------------->


    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS"/>
    <STRING id="STR_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_TITLE"/>


    <!-- Image Resource Area--------------------------------------------------->

    #define OPN_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Widget\\\\OperatorNameCosmos\\\\"

    <IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON">OPN_IMG_PATH"Widgeticon_OperatorName.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_BG">OPN_IMG_PATH"BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_BG_TITLE">OPN_IMG_PATH"Title.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_SEPERATE_LINE">OPN_IMG_PATH"Line.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON_SIM1">OPN_IMG_PATH"Sim1.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON_SIM2">OPN_IMG_PATH"Sim2.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON_SIM3">OPN_IMG_PATH"Sim3.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON_SIM4">OPN_IMG_PATH"Sim4.png"</IMAGE>

#if (MMI_MAX_SIM_NUM == 2)
    //<IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_BG">OPN_IMG_PATH"OperatorName_BG02.9slice.png"</IMAGE>
#else
    //<IMAGE id="IMG_ID_VAPP_WIDGET_OPERATOR_NAME_BG">OPN_IMG_PATH"OperatorName_BG01.9slice.png"</IMAGE>
#endif


    <!-- Event Area--------------------------------------------------->


</APP>

