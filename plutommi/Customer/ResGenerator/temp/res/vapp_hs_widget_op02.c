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
 *  vapp_hs_widget_op02.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the OP02 specific widget APP resources.
 *
 * Author:
 * -------
 *  Guoyi Zhao (mtk80128)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 04 2011 guoyi.zhao
 * [MAUI_02965828] [CU][Feedback] It should access CU home page automatically after launch Opera.
 * .
 *
 * 07 04 2011 guoyi.zhao
 * [MAUI_02965828] [CU][Feedback] It should access CU home page automatically after launch Opera.
 * .
 *
 * 07 01 2011 guoyi.zhao
 * [MAUI_02965828] [CU][Feedback] It should access CU home page automatically after launch Opera.
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"

#ifdef __PLUTO_MMI_PACKAGE__
<?xml version="1.0" encoding="UTF-8"?>

<!--Wo store widget-->
<APP id="APP_VENUS_HOMESCREEN_WG_WO_STORE">
#ifdef __MMI_VUI_HOMESCREEN_WO_STORE__
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_WO_STORE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_WO_STORE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Widgeticon_WoStore.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_WO_STORE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\WoStore\\\\WoStore.png"</IMAGE>

#endif /* __MMI_VUI_HOMESCREEN_WO_STORE__ */
</APP>


<!--Mobile internet widget-->
<APP id="APP_VENUS_HOMESCREEN_WG_MOBILE_INTERNET">
#ifdef __MMI_VUI_HOMESCREEN_MOBILE_INTERNET__
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
#ifdef __MMI_OP02_WO_PORTAL__
    <STRING id="VAPP_HS_STR_WG_WO_3G"/>
#else
    <STRING id="VAPP_HS_STR_WG_MOBILE_INTERNET"/>
#endif /* __MMI_OP02_WO_PORTAL__ */

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#ifdef __MMI_OP02_WO_PORTAL__
    <IMAGE id="VAPP_HS_IMG_WG_ICON_MOBILE_INTERNET">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Widgeticon_Wo3G.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_MOBILE_INTERNET">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Wo3G\\\\Wo3G.png"</IMAGE>
#else    
    <IMAGE id="VAPP_HS_IMG_WG_ICON_MOBILE_INTERNET">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Widgeticon_MobileInternet.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_MOBILE_INTERNET">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Wo3G\\\\MobileInternet.png"</IMAGE>
#endif /* __MMI_OP02_WO_PORTAL__ */
#endif /* __MMI_VUI_HOMESCREEN_MOBILE_INTERNET__ */
</APP>

#endif /* __PLUTO_MMI_PACKAGE__ */
