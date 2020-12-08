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
 *  nmc.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Nuance mobile care resource file.
 *
 * Author:
 * -------
 *  
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /***************************************************************************** 
  * Include 
  *****************************************************************************/

#include "mmi_features.h"
#include "custresdef.h"

#if defined(__NMC_SUPPORT__)


<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "APP_NMC">

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>

<!----------------- Common Area ----------------------------------------------->

<!-----------------------------------------------------String Resource Area------------------------------------------------------>
	  <STRING id = "STR_ID_NMC">nmc</STRING>    

<!-----------------------------------------------------Screen Resource Area------------------------------------------------------>
    <SCREEN id = "GRP_ID_NMC"/>
    <SCREEN id = "SCR_ID_NMC_MAIN"/>
    <SCREEN id = "SCR_ID_NMC_EDITBOX"/> 
<!-----------------------------------------------------Image Resource Area------------------------------------------------------>
  	<IMAGE id="IMG_ID_NMC">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\SB_NMC.pbm"</IMAGE>
    
<!----------------- Menu Id ------------------------------------------->             
    //<MENUITEM id="MENU_ID_NMC_ENTRY" str="STR_ID_NMC" img="IMG_ID_NMC" highlight="mmi_nmc_menu_entry_highlight"/>
    <MENU id="MENU_ID_NMC_ENTRY" str="STR_ID_NMC" img="IMG_ID_NMC" highlight="mmi_nmc_menu_entry_highlight"/>    
<!----------------- XML END --------------------------------------------------->

</APP>




#endif    /* __NMC_SUPPORT__ */



