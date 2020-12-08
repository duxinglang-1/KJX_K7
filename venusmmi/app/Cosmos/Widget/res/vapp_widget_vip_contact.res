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
 *  vapp_widget_hello_world.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the hello world widget's resources.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_WIDGET_VIP_CONTACT__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_VIP_CONTACT" name="STR_ID_VAPP_WIDGET_VIP_CONTACT" type="venus">

    <MEMORY extra_base="100*1024" cui="VCUI_CONTACT_LIST" heap="100*1024"/>
    
    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_VIP_CONTACT"/>
    <STRING id="STR_ID_VAPP_WIDGET_VIP_CONTACT_ERR_CONTACT_NOT_FOUND"/>
    <STRING id="STR_ID_VAPP_WIDGET_VIP_CONTACT_SELECT_A_NUMBER"/>
    <STRING id="STR_ID_VAPP_WIDGET_VIP_CONTACT_SELECT_A_EMAIL"/>
    <STRING id="STR_ID_VAPP_WIDGET_VIP_CONTACT_SELECT_SIM"/>
    
    <!-- Image Resource Area--------------------------------------------------->
    <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_DEL_CONTACT">RES_IMG_ROOT"\\\\Common\\\\Button\\\\Delete.png"</IMAGE>
    
    #define VIP_CONTACT_PATH RES_IMG_ROOT"\\\\Widget\\\\VIPContact\\\\"
    <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_BG">VIP_CONTACT_PATH"VIP_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_TITLE_BG">VIP_CONTACT_PATH"Titlebar.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_POPUP_BG">VIP_CONTACT_PATH"Popup_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_DELETE_MODE">VIP_CONTACT_PATH"Delete.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_DELETE_DONE">VIP_CONTACT_PATH"Ok.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT">VIP_CONTACT_PATH"VIPContact.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_ADD">VIP_CONTACT_PATH"Avatar_02.png"</IMAGE>
    <THEME>
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_ADD_CONTACT" desc="the icon of empty contact item" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM1_N" desc="Normal icon of calling from SIM1" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM1_P" desc="Pressed icon of calling from SIM1" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM1_D" desc="Disable icon of calling from SIM1" />

        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM2_N" desc="Normal icon of calling from SIM2" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM2_P" desc="Pressed icon of calling from SIM2" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM2_D" desc="Disable icon of calling from SIM2" />

        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM3_N" desc="Normal icon of calling from SIM3" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM3_P" desc="Pressed icon of calling from SIM3" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM3_D" desc="Disable icon of calling from SIM3" />

        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM4_N" desc="Normal icon of calling from SIM4" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM4_P" desc="Pressed icon of calling from SIM4" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM4_D" desc="Disable icon of calling from SIM4" />

        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_N" desc="Normal icon of calling" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_P" desc="Pressed icon of calling" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_D" desc="Disable icon of calling" />

        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_EMAIL_N" desc="Normal icon of sending email" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_EMAIL_P" desc="Pressed icon of sending email" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_EMAIL_D" desc="Disable icon of sending email" />

        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_MSG_N" desc="Normal icon of sending message" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_MSG_P" desc="Pressed icon of sending message" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_MSG_D" desc="Disable icon of sending message" />

        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CANCEL_N" desc="Normal icon of cancel" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CANCEL_P" desc="Pressed icon of cancel" />
        <IMAGE id="IMG_ID_VAPP_WIDGET_VIP_CONTACT_CANCEL_D" desc="Disable icon of cancel" />
    </THEME>
    
    <!-- Event Area--------------------------------------------------->
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetVipContactPublisher"/>

    <!-- NVRAM related -->
    <CACHEDATA type="short" id="NVRAM_CONTACT_1" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 1</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CONTACT_2" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 2</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CONTACT_3" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 3</DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_CONTACT_4" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 4</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CONTACT_5" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 5</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CONTACT_6" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 6</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CONTACT_7" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 7</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CONTACT_8" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 8</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CONTACT_9" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>Contact 9</DESCRIPTION>
    </CACHEDATA>

</APP>

#endif /* __MMI_VUI_WIDGET_VIP_CONTACT__ */
