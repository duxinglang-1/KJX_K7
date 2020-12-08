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
 * SSOAPPGprot.h
 *
 * Project:
 * --------
 *	 MAUI
 *
 * Description:
 * ------------
 *	This file is intends for Yahoo service Settings Acconuts
 *
 * Author:
 * -------
 * Mengmeng Cao
 *
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 14 2012 mengmeng.cao
 * [MAUI_03198264] [Settinsg] "Log in successful" should be shown
 * .
 *
 * 06 06 2012 mengmeng.cao
 * [MAUI_03194937] [Block]can not find the setting item of SNS
 * .daily error
 *
 * 05 31 2012 mengmeng.cao
 * [MAUI_03194937] [Block]can not find the setting item of SNS
 * .MAUI_03194928 03194268 03195021 03199137
 *
 * 05 25 2012 mengmeng.cao
 * [MAUI_03191673] nss download bug
 * .
 *
 * 04 26 2012 mengmeng.cao
 * [MAUI_03168301] [Setting] SSOApp and SSOCUI
 * .
 *
 * 04 18 2012 mengmeng.cao
 * [MAUI_03168301] [Setting] SSOApp and SSOCUI
 * .
 *
 * 04 18 2012 mengmeng.cao
 * [MAUI_03168301] [Setting] SSOApp and SSOCUI
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "CUI_SSO">
    <INCLUDE file = "GlobalResDef.h"/> 
    
#if defined (__MMI_SSO__) || defined (__SOCIAL_NETWORK_SUPPORT__)
!----------------- XML Begin ------------------------------------------------->
    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h, mmi_rp_app_mainmenu_def.h"/>
    <!----------------- Screen Id ----------------------------------------->    
    /* log in */     
    <STRING id = "STR_ID_CUI_SSO_ID"/>
    <STRING id = "STR_ID_CUI_SSO_PW"/>
    <STRING id = "STR_ID_CUI_SSO_LOGIN_BLANK"/>
    <STRING id = "STR_ID_CUI_SSO_LOGIN"/>
    <STRING id = "STR_ID_CUI_SSO_SIGNUP"/>
    <STRING id = "STR_ID_CUI_SSO_LOGINGIN"/>
    <STRING id = "STR_ID_CUI_SSO_LOGIN_OK"/>
    

    <!----------------- Menu Id ------------------------------------------->                       
    <MENUITEM id="MENU_ID_MMI_SSOCUI_LOGIN" str="STR_ID_CUI_SSO_LOGIN"/>
    <MENUITEM id="MENU_ID_MMI_SSOCUI_SIGNUP" str="STR_ID_CUI_SSO_SIGNUP"/>
	  /* about log in */
    /* entry yahoo service log in screen the option with id or pw*/
    <MENU id="MENU_ID_SSOCUI_LOGIN_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">     
        <MENUITEM_ID>MENU_ID_MMI_SSOCUI_LOGIN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MMI_SSOCUI_SIGNUP</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>
<!----------------- XML END --------------------------------------------------->
#endif
</APP>
