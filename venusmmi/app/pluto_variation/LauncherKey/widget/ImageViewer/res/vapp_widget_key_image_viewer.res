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
 *  vapp_widget_key_image_viewer.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * Yiping Xie (mtk80652)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 13 2012 yiping.xie
 * [MAUI_03137863] [Key Launcher]
 * .
 *
 * 02 21 2012 yiping.xie
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h" 

#ifdef __MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_VENUS_WIDGET_KEY_IMAGE_VIEWER">

/* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
<!--Include Area-->
<INCLUDE file="GlobalResDef.h"/>

#define WIDGET_KEY_IMGVIEW_PATH         CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Image\\\\"
#define WIDGET_KEY_IMGVIEW_COMMON_PATH  CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Common\\\\widget_common\\\\"

<!-- 
**************************************** String section ***************************************
-->

    <STRING id="STR_ID_WIDGET_KEY_IMAGE_VIEWER_NAME"/>
    
<!-- 
**************************************** Image section ****************************************
-->

    <IMAGE id="IMG_ID_WIDGET_KEY_IMAGE_VIEWER_ICON">WIDGET_KEY_IMGVIEW_COMMON_PATH"widget_image_view.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_KEY_IMAGE_VIEWER_BG">WIDGET_KEY_IMGVIEW_PATH"Image_glass.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_KEY_IMAGE_VIEWER_NONE">WIDGET_KEY_IMGVIEW_PATH"Image_none.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_KEY_IMAGE_VIEWER_DEFAULT">WIDGET_KEY_IMGVIEW_PATH"Image_default.png"</IMAGE>

    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetKeyImageViewerPublisher"/>

</APP>

#endif /* __MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__ */


