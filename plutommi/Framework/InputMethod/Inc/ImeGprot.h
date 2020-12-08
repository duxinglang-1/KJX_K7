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
 *    ImeGprot.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
dear Sikun,
I have checked in code in input server for  calling correct toggle state , but because of wrong call sequencing in imc_pen , it gets removed.As discussed ,please help to check the flow in pen.you may need to make sure the call to setup and set active row id is made only once

Thanks

[Keyu 5/22]
Dear Manik,
UC will set the enter key style as "IME_VK_ENTER_KEY_STYLE_DONE" for this "To" editor, and the enter key will be enabled after user input a valid recipient. Please help to check the enter key behavier on VK , thanks!

[Load Path]
\\mtksdd01.gslb.mediatek.inc\high_priority\sw_releases\W12.20\11B\KHAN50_V11_DEMO_GPRS(12864_COSMOS_WQVGA_CN)

 * removed!
 *
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
Dear Sikun,
i have checked in parser in 11B , the enum will have _SHIFT added , please fix the issue , let me know if its ok , i will checkin in 20mp once u say its ok.

Thanks


[dear manik]
this is similar issue with previous one, please help to generate new enum for thai shift keyboard, and give me the enum for check in, thank you.

[Load Path]
\\Mtksdd01.gslb.mediatek.inc\high_priority\sw_releases\W12.18\11B\official

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!

I implement that api and checked in, you can get it form peforce thank you.


[Kuldeep 5/2]

Dear Sikun,

I have done my part and checkin done.

Please help to complete your part and let me know when you are done,

Thanks


[Manik]

dear Kuldeep,

Please help to take care of this issuein coomscreens.c


[Manik]

deart Kuldeep,


The issue  needs addition of a new function in commonscreens.c which would show in the context menu of editor , we cannot be calling imc_pen api here , as this one needs to attach to screen group .


here is how to go about it :

Make a new screen exaclt like wlanguage , now you need 3 things 

1) event handlers  3) menu stirngs 3) calls to event handler in mmi_imc_options_menu_handler


instead of tweaking the exisitng menus , i suggest add new one with new streing names , it will be much faster ,


on sikuns part , he will esxpose an api which would provide you the list and event handler to be called when an item is selected.



as this is commonscreens code , and not the imc_pen popup , 

another thing , this screen is not going to be same as the one shown from vk , this will be like other editor context screens , it will only have wlanguages + for chinese instead of wlang , the input mode and handwriting .


it will not show any switch vk style or settings button ( i think this is obvious , just writing to clarify )



feel free to discuss with me if any issue.


Thanks

















[Kuldeep 4/25]

Dear Sikun,

Please help to check this imc pen implementation issue.

thanks


[Manik]

dear kuldeep,

as discussed , we should be showing the list the same list which gets shown for change mode key ,please call the same api from coomnscreens to get the data for imev3.

Thanks



[Kuldeep 4/19]

Dear Sikun,

You have already implemented input method list on pluto and done all related handling so It would be better if you implement same list and releated handling on this menu item as you done previously.

thanks


[Xianghe]

Dear Kuldeep,

This is IMEv3 issue, please check it. Thanks~


[Raghav]

Dear Xianghe,

This behaviour (i.e. On selecting Message Editor-> Options -> Input method -> show Multi-language) was not expected and always input modes are displayed, but if this is the desired behaviour please help to change the class to change feature.

P.S. We already have Writing language screen on Message Editor-> Options -> Input method Options-> Writing language

Thanks.


[Xianghe]

Deaer Raghav,

There it should show the multi-languages, but not the input methods of a language.

About the UE behavior, I think you can contact Joy Wu.

Thanks~


[Raghav]

Dear Xianghe,

Please let me know the desired behaviour. As I think the behaviopur is as expected when __MMI_PREFER_WRITING_LANG__ is ON

Thanks.


[Kuldeep 4/18]

Dear Raghav,

Please help to check the strings passes by IMM.

If not related to imev3 modify the category.

Thanks


[sikun]

dear kuldeep,

please help to check this problem on setting side, thank you.


[Load Path]

\\mtksdd01.gslb.mediatek.inc\high_priority\sw_releases\W12.16\11B\temp\p9

 * removed!
 *
 * removed!
 * removed!
I implement that api and checked in, you can get it form peforce thank you.

[Kuldeep 5/2]
Dear Sikun,
I have done my part and checkin done.
Please help to complete your part and let me know when you are done,
Thanks

[Manik]
dear Kuldeep,
Please help to take care of this issuein coomscreens.c

[Manik]
deart Kuldeep,

The issue  needs addition of a new function in commonscreens.c which would show in the context menu of editor , we cannot be calling imc_pen api here , as this one needs to attach to screen group .

here is how to go about it :
Make a new screen exaclt like wlanguage , now you need 3 things 
1) event handlers  3) menu stirngs 3) calls to event handler in mmi_imc_options_menu_handler

instead of tweaking the exisitng menus , i suggest add new one with new streing names , it will be much faster ,

on sikuns part , he will esxpose an api which would provide you the list and event handler to be called when an item is selected.


as this is commonscreens code , and not the imc_pen popup , 
another thing , this screen is not going to be same as the one shown from vk , this will be like other editor context screens , it will only have wlanguages + for chinese instead of wlang , the input mode and handwriting .

it will not show any switch vk style or settings button ( i think this is obvious , just writing to clarify )


feel free to discuss with me if any issue.

Thanks
















[Kuldeep 4/25]
Dear Sikun,
Please help to check this imc pen implementation issue.
thanks

[Manik]
dear kuldeep,
as discussed , we should be showing the list the same list which gets shown for change mode key ,please call the same api from coomnscreens to get the data for imev3.
Thanks


[Kuldeep 4/19]
Dear Sikun,
You have already implemented input method list on pluto and done all related handling so It would be better if you implement same list and releated handling on this menu item as you done previously.
thanks

[Xianghe]
Dear Kuldeep,
This is IMEv3 issue, please check it. Thanks~

[Raghav]
Dear Xianghe,
This behaviour (i.e. On selecting Message Editor-> Options -> Input method -> show Multi-language) was not expected and always input modes are displayed, but if this is the desired behaviour please help to change the class to change feature.
P.S. We already have Writing language screen on Message Editor-> Options -> Input method Options-> Writing language
Thanks.

[Xianghe]
Deaer Raghav,
There it should show the multi-languages, but not the input methods of a language.
About the UE behavior, I think you can contact Joy Wu.
Thanks~

[Raghav]
Dear Xianghe,
Please let me know the desired behaviour. As I think the behaviopur is as expected when __MMI_PREFER_WRITING_LANG__ is ON
Thanks.

[Kuldeep 4/18]
Dear Raghav,
Please help to check the strings passes by IMM.
If not related to imev3 modify the category.
Thanks

[sikun]
dear kuldeep,
please help to check this problem on setting side, thank you.

[Load Path]
\\mtksdd01.gslb.mediatek.inc\high_priority\sw_releases\W12.16\11B\temp\p9

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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
//DOM-NOT_FOR_SDK-BEGIN

#ifndef __IMEGROT_H__
#define __IMEGROT_H__

#include "mmi_frm_gprot.h"

#include "gdi_datatype.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "gui_virtual_keyboard_language_type.h"
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_CLIPBOARD__
#include "ems.h"
#endif /* __MMI_CLIPBOARD__ */

#include "ImeGprotEnums.h"
#include "MenuCuiGprot.h"
/*****************************************************************************
 * Defines
 *****************************************************************************/

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& ( defined(__MMI_ZI__) || ( defined(__MMI_T9__)&& defined(__MMI_IME_USER_DATABASE__) ) )
       #ifndef  __MMI_IME_AUTO_COMPLETION_SETTING__
       #define  __MMI_IME_AUTO_COMPLETION_SETTING__
       #endif
#endif

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) && defined(__MMI_IME_AUTO_CAPITALIZATION__)
       #ifndef  __MMI_IME_AUTO_CAPITALIZATION_SETTING__
       #define  __MMI_IME_AUTO_CAPITALIZATION_SETTING__
       #endif
#endif

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) && defined(__MMI_SMART_PHONETIC_INPUT_METHODS__) &&  (defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)|| defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) || defined (__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__) )
       #ifndef  __MMI_IME_PHONETIC_PREDICTION_SETTING__
       #define  __MMI_IME_PHONETIC_PREDICTION_SETTING__
       #endif
#endif

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& ! defined (__MMI_CSTAR__) && defined (__MMI_ALPHABETIC_WORD_PREDICTION__)
       #ifndef  __MMI_IME_ALPHABETIC_PREDICTION_SETTING__
       #define  __MMI_IME_ALPHABETIC_PREDICTION_SETTING__
       #endif
#endif


#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) &&  defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__)
       #ifndef  __MMI_IME_INPUT_PATTERN_SETTING__
       #define  __MMI_IME_INPUT_PATTERN_SETTING__
       #endif
#endif

#if defined (__MMI_IME_PLUG_IN_SETTING__) || defined (__MMI_IME_AUTO_COMPLETION_SETTING__) || defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__) || defined (__MMI_IME_ALPHABETIC_PREDICTION_SETTING__) || defined (__MMI_IME_PHONETIC_PREDICTION_SETTING__)
       #ifndef __MMI_IME_INPUT_ADVANCED_SETTING__
       #define __MMI_IME_INPUT_ADVANCED_SETTING__
       #endif
#endif


#if !defined(__MMI_ZI__) && !defined(__MMI_T9__) && !defined(__MMI_CSTAR__)&& !defined(__MMI_GUOBI__)
#define __MMI_NO_IME_VENDOR__
#endif


#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) || defined(__MMI_SMART_ALPHABETIC_RESELECTION__)
#define __MMI_IME_CANDIDATE_FILTER__
#endif

#if defined(__MMI_CSTAR_USER_DICT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_IME_USER_DATABASE__)
#define __MMI_IME_USER_DATABASE__
#endif



#if defined(__MMI_IME_FTE_ENHANCE__) && \
     (((defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__) || defined(__MMI_ZI_SMART_PHONETIC_INPUT__)) && defined(__MMI_ZI_TR_CHINESE__)) || \
	 ((defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__) || defined(__MMI_GB_SMART_PHONETIC_INPUT__)) && defined(__MMI_GB_TR_CHINESE__)) || \
     ((defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) || defined(__MMI_T9_SMART_PHONETIC_INPUT__)) && defined(__MMI_T9_TR_CHINESE__)) || \
     ((defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__) || defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)) && defined(__MMI_CSTAR_TR_CHINESE__))) && \
     ((defined(__MMI_MAINLCD_240X320__)) || (defined(__MMI_MAINLCD_240X400__))||(defined(__MMI_MAINLCD_320X480__) && defined(__COSMOS_MMI_PACKAGE__)) || \
      (defined(__MMI_MAINLCD_480X800__)))

#define __MMI_IME_ZHUYIN_HALF_QWERTY_VK__
#endif

/*****************************************************************************
 * Global variables
 *****************************************************************************/


/*****************************************************************************
 * Enums
 *****************************************************************************/

typedef enum
{
    IMM_KEYPAD_ALPHANUMERIC,
    IMM_KEYPAD_QWERTY,
    IMM_KEYPAD_HANDWRITING,
    IMM_KEYPAD_END_OF_ENUM
}mmi_imm_keypadtype_enum;


typedef enum {
    MMI_IMC_MESSAGE_NONE             = 0x0,
    MMI_IMC_MESSAGE_INSERT_STRING,   
    MMI_IMC_MESSAGE_INSERT_CHAR,
    MMI_IMC_MESSAGE_INSERT_NEW_LINE,
    MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR,
    MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING,
    MMI_IMC_MESSAGE_DELETE_CHAR,
    MMI_IMC_MESSAGE_DELETE_STRING,
    MMI_IMC_MESSAGE_CLEAR_ALL,
    MMI_IMC_MESSAGE_CLEAR_HILIGHT,
    MMI_IMC_MESSAGE_MOVE_CURSOR,
    MMI_IMC_MESSAGE_HILIGHT_BFCURSOR,
    MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT,
    MMI_IMC_MESSAGE_GET_HANDWRITING_RECT,
    MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE,
    MMI_IMC_MESSAGE_RESET_MULTITAP_STATE,
    MMI_IMC_MESSAGE_RESIZE,
    MMI_IMC_MESSAGE_MOVE,
    MMI_IMC_MESSAGE_REDRAW,
    MMI_IMC_MESSAGE_UPDATE_SOFTKEY,
    MMI_IMC_MESSAGE_KEY_EVENT,
    MMI_IMC_MESSAGE_PEN_EVENT,
    MMI_IMC_MESSAGE_MODE_CHANGED,
    MMI_IMC_MESSAGE_CHANGE_TO_INITIAL,
    MMI_IMC_MESSAGE_GET_TEXT,
    MMI_IMC_MESSAGE_IS_EDITOR_EMPTY,
    MMI_IMC_MESSAGE_INSERT_SPELLING_DIRECTLY,
    MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR,
    MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE,
    MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX,
    MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION,
    MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION,
    MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION,
    MMI_IMC_MESSAGE_CHECK_FLOAT,
    MMI_IMC_MESSAGE_SET_KEY,
    MMI_IMC_MESSAGE_SET_MULTITAP_STATE,
    MMI_IMC_MESSAGE_SET_MASK,
    MMI_IMC_MESSAGE_DECIAML_CHECK,
    MMI_IMC_MESSAGE_DECIMAL_INPUT,
    MMI_IMC_MESSAGE_INSERT_DECIMAL_SYMBOL,
    MMI_IMC_MESSAGE_INSERT_SPACE,
    MMI_IMC_MESSAGE_DRAW_INFORMATION_BAR,
    MMI_IMC_MESSAGE_DRAW_IME_HINT,
    MMI_IMC_MESSAGE_IS_SOFTKEY_HIDE,
    MMI_IMC_MESSAGE_CHECK_CSK_ENABLE,
    MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL,
    MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE,
    MMI_IMC_MESSAGE_START_SMART_ALPHABETIC,
    MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC,
    MMI_IMC_MESSAGE_WCSS_CHECK,
    MMI_IMC_MESSAGE_IS_LAST_POSITION,
    MMI_IMC_MESSAGE_IS_OVERWRITE_MODE,
    MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CANDIDATE,
    MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED,
    MMI_IMC_MESSGAE_GET_EXT_INPUT_BOX_RECT,
    MMI_IMC_MESSAGE_IS_THERE_CURSOR,
    MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW,
    MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING,
    MMI_IMC_MESSAGE_CLIPBOARD_LOCATE_CURSOR_P_BY_POS,
    MMI_IMC_MESSAGE_CLIPBOARD_SET_START_CURSOR_P,
    MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT,
    MMI_IMC_MESSAGE_CLIPBOARD_SAVE_STATUS,
    MMI_IMC_MESSAGE_CLIPBOARD_RESTORE_STATUS,
    MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR,
    MMI_IMC_MESSAGE_CLIPBOARD_INSERT_STRING_WITH_LENGTH,
    MMI_IMC_MESSAGE_CLIPBOARD_IS_TEXT_HIGHLIGHT,
    MMI_IMC_MESSAGE_CLIPBOARD_GET_ALL_TEXT,
    MMI_IMC_MESSAGE_CLIPBOARD_GET_HIGHLIGHT_TEXT,
    MMI_IMC_MESSAGE_CLIPBOARD_IS_READ_ONLY_EDITOR,
    MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR,
    MMI_IMC_MESSAGE_CLIPBOARD_SET_HIGHLIGHT,
    MMI_IMC_MESSAGE_CLIPBOARD_GET_EDITOR_TYPE,
    MMI_IMC_MESSAGE_CLIPBOARD_CUT_HIGHLIGHT_STRING,
    MMI_IMC_MESSAGE_CLIPBOARD_CUT_ALL,
    MMI_IMC_MESSAGE_CLIPBOARD_ADJUST_VIEW,
    MMI_IMC_MESSAGE_CLIPBOARD_IS_DISABLE,
    MMI_IMC_MESSAGE_CLIPBOARD_GET_HILITE_RECT,
    MMI_IMC_MESSAGE_CLIPBOARD_IS_ALLOWED_CUT_ALL,
    MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD,
    MMI_IMC_MESSAGE_IS_LOCK_GDI_FRAME_BUFFER_DISABLED,
    MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS,
    MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED,
    MMI_IMC_MESSAGE_IS_AUTO_CLEAR_HIGHLIGHT_WORD_MODE,
    MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED,
    MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW,
    MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_START,
    MMI_IMC_MESSAGE_GET_EDITOR_SCROLL_BAR_WIDTH,
    MMI_IMC_MESSAGE_VK_HIDE,
    MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CURSOR,
    MMI_IMC_MESSAGE_HAS_SSP_ACTED,
    MMI_IMC_MESSAGE_GET_TEXT_LENGTH,
    MMI_IMC_MESSAGE_GET_CURSOR_RECT,
    MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE,
    MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION,
    MMI_IMC_MESSAGE_GET_STOP_CURSOR_CALLBACK_FUNCPTR,
    MMI_IMC_MESSAGE_GET_START_CURSOR_CALLBACK_FUNCPTR,
    MMI_IMC_MESSAGE_IS_SKIP_GENERAL_PEN_UP_EVENT,
    MMI_IMC_MESSAGE_BACKSPACE_KEY_EVENT,
    MMI_IMC_MESSAGE_ACTIVATE,
    MMI_IMC_MESSAGE_DEACTIVATE,
    MMI_IMC_MESSAGE_VK_STATUS,
	MMI_IMC_MESSAGE_REDRAW_FLOATING_AREA
}   mmi_imc_editor_message_id_enum;

/*
notification:   MMI_IMC_MESSAGE_INSERT_STRING
remark:         insert a character into editor
param_0:        [IN] (UI_string_type)    Ucs2 string pointer
param_1:        reserved
return:         reserved

notification:   MMI_IMC_MESSAGE_DELETE_CHAR
remark:         delete characters before cursor
param_0:        [IN] (U32)             string length
param_1:        reserved
return:         reserved

notification:   IMC_MESSAGE_MOVE_CURSOR
remark:         move cursor
param_0:        [IN] (U32)             start position
param_1:        [IN] (U32)             move step count,
                                        negative value indicates backward direction,
                                        positive value indicates forward direction
return:         reserved

notification:   IMC_MESSAGE_HILIGHT_BFCURSOR
remark:         highlight characters before cursor
param_0:        [IN] (U32)              highlight character count
param_1:        [IN] (MMI_BOOL)         whether move cursor at the same time
return:         reserved

notification:   IMC_MESSAGE_RESIZE
remark:         resize editor's height
param_0:        [IN] (U32)             width
param_1:        [IN] (U32)             height
return:         reserved

notification:   IMC_MESSAGE_REDRAW
remark:         redraw editor
param_0:        reserved
param_1:        reserved
return:         reserved

notification:   IMC_MESSAGE_UPDATE_SOFTKEY
remark:         change softkey caption and icon
param_0:        [IN] (U16)             High Part - string id
                [IN] (U16)             Low  Part - image id
param_1:        [IN] (WGUI_SOFTKEY_ENUM)    softkey type    (refference to wgui_softkeys.h)
return:         reserved

notification:   IMC_MESSAGE_KEY_EVENT
remark:         forwarding key event
param_0:        [IN] (U32)             key value
param_1:        [IN] (U32)             key type
return:         (MMI_BOOL)  indicates whether disposed?

notification:   MMI_IMC_MESSAGE_MODE_CHANGED
remark:         input mode changed
param_0:        input mode value
param_1:        input type value
return:         reserved

notification:   MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR
remark:         insert multitap character
param_0:        the candidate character
param_1:        NULL
return:         (MMI_BOOL)  indicates insertion success or fail

notification:   MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING
remark:         insert multitap string used for multigraph 
param_0:        the candidate string
param_1:        NULL
return:         (MMI_BOOL)  indicates insertion success or fail

notification:  MMI_IMC_MESSAGE_IS_EDITOR_EMPTY
remark:         to check if editor is empty or not
return:         (MMI_BOOL)  MMI_TRUE: editor is empty else empty is not empty.

notification:   MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE
remake:         to get string with its length being n before the candidate.
param_0:       the desired character count.
param_1:       the buffer to put the character. the size of the buffer should be large then the desired count.
return:          

*/

typedef enum {
    MMI_IMC_EDITOR_PEN_EVENT_NONE,
    MMI_IMC_EDITOR_PEN_EVENT_TEXT_DOWN,
    MMI_IMC_EDITOR_PEN_EVENT_TEXT_UP,
    MMI_IMC_EDITOR_PEN_EVENT_SCROLL_BAR,
    MMI_IMC_EDITOR_PEN_EVENT_CONTROL_AREA,
    MMI_IMC_EDITOR_PEN_EVENT_MAX
} mmi_imc_editor_pen_event_enum;

typedef enum
{
    MMI_IMC_EDITOR_CURSOR_UP,
    MMI_IMC_EDITOR_CURSOR_DOWN,
    MMI_IMC_EDITOR_CURSOR_LEFT,
    MMI_IMC_EDITOR_CURSOR_RIGHT
}mmi_imc_editor_cusor_move_direction_enum;


#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)

#define MMI_IMM_QWERTY_MAX_MMI_KEY_ON_ONE_DEVICE_KEY (2)

//#define MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM (4)
#if  defined __MMI_LANG_SA_PORTUGUESE__|| \
		 defined __MMI_LANG_PORTUGUESE__   
#define MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM (23)


#elif defined  __MMI_LANG_THAI__
#define MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM (17)

#elif  defined __MMI_LANG_FINNISH__      || \
		 defined __MMI_LANG_HUNGARIAN__    || \
		 defined __MMI_LANG_MACEDONIAN__   || \
		 defined __MMI_LANG_NORWEGIAN__    || \
		 defined __MMI_LANG_VIETNAMESE__   

                 #define MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM (16)
#elif  defined __MMI_LANG_ARMENIAN__     || \
						  defined __MMI_LANG_CA_FRENCH__	|| \
						  defined __MMI_LANG_CATALAN__		|| \
						  defined __MMI_LANG_CROATIAN__ 	|| \
						  defined __MMI_LANG_DUTCH__		|| \
						  defined __MMI_LANG_ESTONIAN__ 	|| \
						  defined __MMI_LANG_FRENCH__		|| \
						  defined __MMI_LANG_GERMAN__		|| \
						  defined __MMI_LANG_LITHUANIAN__	|| \
						  defined __MMI_LANG_ROMANIAN__ 	|| \
						  defined __MMI_LANG_ICELANDIC__	|| \
						  defined __MMI_LANG_SLOVAK__		|| \
						  defined __MMI_LANG_SLOVENIAN__	|| \
						  defined __MMI_LANG_POLISH__		|| \
						  defined __MMI_LANG_CZECH__		|| \
						  defined __MMI_LANG_SPANISH__		|| \
						  defined __MMI_LANG_SWEDISH__		
     #define MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM (14)

#elif defined __MMI_LANG_UKRAINIAN__
     #define MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM (13)

#elif  defined __MMI_LANG_ASSAMESE__     || \
		 defined __MMI_LANG_AZERBAIJANI__  || \
		 defined __MMI_LANG_BENGALI__      || \
		 defined __MMI_LANG_BULGARIAN__    || \
		 defined __MMI_LANG_GREEK__        || \
		 defined __MMI_LANG_GUJARATI__     || \
		 defined __MMI_LANG_HAUSA__        || \
		 defined __MMI_LANG_GALICIAN__     || \
		 defined __MMI_LANG_BASQUE__       || \
		 defined __MMI_LANG_IGBO__         || \
		 defined __MMI_LANG_FILIPINO__     || \
		 defined __MMI_LANG_IRISH__        || \
		 defined __MMI_LANG_HINDI__        || \
		 defined __MMI_LANG_ITALIAN__      || \
		 defined __MMI_LANG_KANNADA__      || \
		 defined __MMI_LANG_KAZAKH__       || \
		 defined __MMI_LANG_LATVIAN__      || \
		 defined __MMI_LANG_MALAYALAM__    || \
		 defined __MMI_LANG_MARATHI__      || \
		 defined __MMI_LANG_ORIYA__        || \
		 defined __MMI_LANG_PUNJABI__      || \
		 defined __MMI_LANG_SERBIAN__      || \
		 defined __MMI_LANG_TAMIL__        || \
		 defined __MMI_LANG_TELUGU__       || \
		 defined __MMI_LANG_TURKISH__      || \
		 defined __MMI_LANG_YORUBA__       

           #undef MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM
	   #define MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM (12)
#else
#define MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM (11) /*imev3 add output char flag*/

#endif

#define MMI_IMM_QWERTY_MAX_MULTITAP_CHAR_NUM (9)
#endif

#define MMI_IMM_MAX_DISABLE_CHARACTER_NUM      (20)
#define MMI_IMM_MAX_ALLOWED_CHARACTER_NUM      (100)

#define MMI_IMC_UI_STYLE_FLOAT_ON 0x01
#define MMI_IMC_UI_STYLE_VK_ON 0x02



typedef enum {
    IME_WRITING_LANG_NONE,
    IME_WRITING_LANG_123,
    IME_WRITING_LANG_ABC, /* English */
    IME_WRITING_LANG_HABC, /* HINGLISH */
    IME_WRITING_LANG_AF, /* Afrilaans */
    IME_WRITING_LANG_AR, /* ARABIC */
    IME_WRITING_LANG_AS, /* ASSAMESE */
    IME_WRITING_LANG_AZ, /* Azerbaijani */
    IME_WRITING_LANG_BE, /* Bengali */
    IME_WRITING_LANG_BG, /* BULGARIAN */
    IME_WRITING_LANG_CA, /* Catalan */
    IME_WRITING_LANG_CS, /* CZECH */
    IME_WRITING_LANG_DA, /* DANISH */
    IME_WRITING_LANG_DE, /* GERMAN */
    IME_WRITING_LANG_EL, /* GREEK */
    IME_WRITING_LANG_ENUK, /* UK English */
    IME_WRITING_LANG_ES, /* SPANISH */
    IME_WRITING_LANG_ESSA, /* LA SPANISH */
    IME_WRITING_LANG_ET, /* Estonian */
    IME_WRITING_LANG_EU, /* Basques*/
    IME_WRITING_LANG_FI, /* FINNISH */
    IME_WRITING_LANG_FIL, /* FILIPINO */
    IME_WRITING_LANG_FR, /* French */
    IME_WRITING_LANG_FRCA, /* CA French */
    IME_WRITING_LANG_GA, /* Galician*/
    IME_WRITING_LANG_GL, /* Irish */
    IME_WRITING_LANG_GU, /* Gujarati */
    IME_WRITING_LANG_HA, /* Hausa */
    IME_WRITING_LANG_HE, /* HEBREW */
    IME_WRITING_LANG_HI, /* HINDI */
    IME_WRITING_LANG_HU, /* HUNGARIAN */
    IME_WRITING_LANG_HY, /* Armenian */
    IME_WRITING_LANG_ID, /* INDONESIAN */
    IME_WRITING_LANG_IG, /* IGBO */
    IME_WRITING_LANG_IS, /* ICELANDIC */
    IME_WRITING_LANG_IT, /* ITALIAN */
    IME_WRITING_LANG_KA, /* Georgian */
    IME_WRITING_LANG_KK, /* Kazakh */
    IME_WRITING_LANG_KM, /* Khmer */
    IME_WRITING_LANG_KN, /* Kannada */
    IME_WRITING_LANG_KR,/*Korean*/
    IME_WRITING_LANG_LO, /* Lao */
    IME_WRITING_LANG_LT, /* Lithuanian */
    IME_WRITING_LANG_LV, /* Latvian */
    IME_WRITING_LANG_MK, /* Macedonian */
    IME_WRITING_LANG_ML, /* malayalam */
    IME_WRITING_LANG_MO, /* Moldovan */
    IME_WRITING_LANG_MR, /* MARATHI */
    IME_WRITING_LANG_MS, /* MALAY */
    IME_WRITING_LANG_MY, /* Myanmar */
    IME_WRITING_LANG_NL, /*DUTCH  */
    IME_WRITING_LANG_NO, /* NORWEGIAN */
    IME_WRITING_LANG_OR, /* oriya */
    IME_WRITING_LANG_PA, /* Punjabi */
    IME_WRITING_LANG_PL, /* POLISH */
    IME_WRITING_LANG_PS, /* PERSIAN */
    IME_WRITING_LANG_PT, /* PORTUGUESE */
    IME_WRITING_LANG_PTBZ, /* BZ PORTUGUESE */    
    IME_WRITING_LANG_RO, /* ROMANIAN */
    IME_WRITING_LANG_RU, /* RUSSIAN */
    IME_WRITING_LANG_SH, /* CROATIAN */
    IME_WRITING_LANG_SK, /*SLOVAK  */
    IME_WRITING_LANG_SL, /* SLOVENIAN */
    IME_WRITING_LANG_SQ, /* Albanian */
    IME_WRITING_LANG_SR, /* SERBIAN */
    IME_WRITING_LANG_ST, /* Sesotho */
    IME_WRITING_LANG_SV, /* SWEDISH */
    IME_WRITING_LANG_SW, /* Swahili */
    IME_WRITING_LANG_TA, /* Tamil */
    IME_WRITING_LANG_TE, /* Telugu */
    IME_WRITING_LANG_TH, /* Thai */
    IME_WRITING_LANG_TL, /* Tagalog */
    IME_WRITING_LANG_TR, /* TURKISH */
    IME_WRITING_LANG_UK, /* UKRAINIAN */
    IME_WRITING_LANG_UR, /* URDU */
    IME_WRITING_LANG_VI, /* VIETNAMESE */
    IME_WRITING_LANG_XH, /* Xhosa */
    IME_WRITING_LANG_YO, /* Yoruba */
    IME_WRITING_LANG_ZHCN, /* Simpled Chinese */
    IME_WRITING_LANG_ZHHK, /* HongKong (Cantonese) Chinese */
    IME_WRITING_LANG_ZHTW, /* Traditional Chinese */
    IME_WRITING_LANG_ZU, /* Zulu */
    IME_WRITING_LANG_TOTAL
}   mmi_imm_support_writing_lang_enum;


#if defined(__MMI_IME_FUZZY_PINYIN__)
#if defined __MMI_GUOBI__
typedef enum
{
    IME_FUZZY_PINYIN_H_F = 0x0001,
    IME_FUZZY_PINYIN_N_L = 0x0002,
    IME_FUZZY_PINYIN_NG_N = 0x0004,
    IME_FUZZY_PINYIN_XH_X = 0x0008,
    IME_FUZZY_PINYIN_K_G = 0x0010,
    IME_FUZZY_PINYIN_R_L = 0x0100,
    IME_FUZZY_PINYIN_MAX = 6
}mmi_imm_fuzzy_pinyin_enum;
 
#else
typedef enum
{
    IME_FUZZY_PINYIN_Z_ZH = 0x0001,
    IME_FUZZY_PINYIN_C_CH = 0x0002,
    IME_FUZZY_PINYIN_S_SH = 0x0004,
    IME_FUZZY_PINYIN_H_F = 0x0008,
    IME_FUZZY_PINYIN_N_L = 0x0010,
    IME_FUZZY_PINYIN_IN_ING = 0x0100,
    IME_FUZZY_PINYIN_EN_ENG = 0x0200,
    IME_FUZZY_PINYIN_AN_ANG = 0x0400,
    IME_FUZZY_PINYIN_IAN_IANG = 0x0800,
    IME_FUZZY_PINYIN_UAN_UANG = 0x1000,
    IME_FUZZY_PINYIN_MAX = 10
}mmi_imm_fuzzy_pinyin_enum;

#endif

#endif


typedef enum
{
    IMM_HANDWRITING_TYPE_NONE = 0,
    IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE,
    IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE,
    IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH,
    IMM_HANDWRITING_TYPE_UPPER_CASE_RUSSIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_RUSSIAN,
    IMM_HANDWRITING_TYPE_THAI,
    IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_SPANISH,
    IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_FRENCH,
    IMM_HANDWRITING_TYPE_UPPER_CASE_GERMAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_GERMAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_ITALIC,
    IMM_HANDWRITING_TYPE_LOWER_CASE_ITALIC,
    IMM_HANDWRITING_TYPE_ARABIC,
    IMM_HANDWRITING_TYPE_UPPER_CASE_TURKEY,
    IMM_HANDWRITING_TYPE_LOWER_CASE_TURKEY,
    IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE,
    IMM_HANDWRITING_TYPE_LOWER_CASE_PORTUGESE,
    IMM_HANDWRITING_TYPE_UPPER_CASE_BULGARIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_BULGARIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_DUTCH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_DUTCH,
    IMM_HANDWRITING_TYPE_UPPER_CASE_CZECH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_CZECH,
    IMM_HANDWRITING_TYPE_UPPER_CASE_DANISH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_DANISH,
    IMM_HANDWRITING_TYPE_UPPER_CASE_FINNISH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_FINNISH,
    IMM_HANDWRITING_TYPE_UPPER_CASE_GREEK,
    IMM_HANDWRITING_TYPE_LOWER_CASE_GREEK,
    IMM_HANDWRITING_TYPE_UPPER_CASE_HUNGARIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_HUNGARIAN, 
    IMM_HANDWRITING_TYPE_UPPER_CASE_INDONESIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_INDONESIAN, 
    IMM_HANDWRITING_TYPE_UPPER_CASE_MALAY,
    IMM_HANDWRITING_TYPE_LOWER_CASE_MALAY,
    IMM_HANDWRITING_TYPE_UPPER_CASE_CATALAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_CATALAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_SERBIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_SERBIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_TAGALOG,
    IMM_HANDWRITING_TYPE_LOWER_CASE_TAGALOG,
    IMM_HANDWRITING_TYPE_UPPER_CASE_AFRIKAANS,
    IMM_HANDWRITING_TYPE_LOWER_CASE_AFRIKAANS,
    IMM_HANDWRITING_TYPE_UPPER_CASE_CROATIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_CROATIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_ESTONIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_ESTONIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_LATVIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_LATVIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_LITHUANIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_LITHUANIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_MALDOVAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_MALDOVAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_NORWEGIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_NORWEGIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_POLISH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_POLISH,
    IMM_HANDWRITING_TYPE_UPPER_CASE_ROMANIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_ROMANIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVAKIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_SLOVAKIAN, 
    IMM_HANDWRITING_TYPE_UPPER_CASE_SLOVENIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_SLOVENIAN, 
    IMM_HANDWRITING_TYPE_UPPER_CASE_SWAHILI,
    IMM_HANDWRITING_TYPE_LOWER_CASE_SWAHILI, 
    IMM_HANDWRITING_TYPE_UPPER_CASE_SWEDISH,
    IMM_HANDWRITING_TYPE_LOWER_CASE_SWEDISH, 
    IMM_HANDWRITING_TYPE_UPPER_CASE_UKRANIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_UKRANIAN, 
    IMM_HANDWRITING_TYPE_UPPER_CASE_XHOSA,
    IMM_HANDWRITING_TYPE_LOWER_CASE_XHOSA, 
    IMM_HANDWRITING_TYPE_UPPER_CASE_ZULU,
    IMM_HANDWRITING_TYPE_LOWER_CASE_ZULU,
    IMM_HANDWRITING_TYPE_UPPER_CASE_BASQUE,
    IMM_HANDWRITING_TYPE_LOWER_CASE_BASQUE,
    IMM_HANDWRITING_TYPE_UPPER_CASE_GALICIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_GALICIAN,
    IMM_HANDWRITING_TYPE_UPPER_CASE_ALBANIAN,
    IMM_HANDWRITING_TYPE_LOWER_CASE_ALBANIAN,
    IMM_HANDWRITING_TYPE_PUNCTUATION,
    IMM_HANDWRITING_TYPE_NUMBER,
    IMM_HANDWRITING_TYPE_KOREAN,
    IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, /* pure english character. no number and symbol. */
    IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION /* English/number/symbol */
} mmi_imc_pen_handwriting_type_enum;


typedef enum
{
    IMM_MESSAGE_ID_NONE,
    IMM_MESSAGE_ID_ERROR,
    IMM_MESSAGE_ID_MAX
}mmi_imm_message_id_enum;

typedef enum
{
    MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN,
    MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK,
    MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK
} mmi_imc_pen_handwriting_style_enum;

#ifdef __MMI_CLIPBOARD__ 
typedef enum {
    MMI_IMC_CLIPBOARD_RET_NONE = 0,
    MMI_IMC_CLIPBOARD_RET_OK,
    MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH,
    MMI_IMC_CLIPBOARD_RET_MEMORY_ERROR,
    MMI_IMC_CLIPBOARD_RET_NO_TEXT,
    MMI_IMC_CLIPBOARD_RET_NO_TEXT_HIGHLIGH,
    MMI_IMC_CLIPBOARD_RET_COPY_FAIL,
    MMI_IMC_CLIPBOARD_RET_CUT_UNSUPPRT_CONTENT,
    MMI_IMC_CLIPBOARD_RET_END
} mmi_imc_clipboard_ret_enum;

typedef enum
{
    INPUTBOX_MULTILINE = 0,
    INPUTBOX_MULTILINE_EBOOK,
    INPUTBOX_MULTILINE_MMS_VIEWER,
    INPUTBOX_EMS,
    MMI_IMC_CLIPBOARD_INPUTBOX_END
} mmi_imc_clipboard_inputbox_enum;

typedef enum
{
    MARK_TEXT_BY_KEY = 0,
    MARK_TEXT_BY_PEN,
    MARK_TEXT_BY_END
} mmi_imc_clipboard_mark_text_enum;

#endif /* __MMI_CLIPBOARD__ */

typedef enum
{
    MMI_IMC_PEN_INPUT_STYLE_NONE, /* only key input */
    MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY,		
    MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC,
    MMI_IMC_PEN_INPUT_STYLE_HW,
    MMI_IMC_PEN_INPUT_STYLE_MAX
} mmi_imc_pen_input_style_enum;

typedef enum{
    MMI_IME_WORD_CAPITAL_STATE_NONE, /* don't care, follow the input mode case */
    MMI_IME_WORD_CAPITAL_STATE_LOWER,
    MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER,
    MMI_IME_WORD_CAPITAL_STATE_UPPER,
    MMI_IME_WORD_CAPITAL_STATE_MAX
} mmi_ime_word_capital_state_enum;


typedef enum
{
    MMI_IMC_VK_PRESENT_DEFAULT,
    MMI_IMC_VK_DEFAULT_HIDE,
    MMI_IMC_VK_DEFAULT_ENLARGE,
    MMI_IMC_VK_PRESENT_MAX
} mmi_imc_vk_present_enum;


typedef enum
{
    MMI_IME_EDITOR_TYPE_NONE,
    MMI_IME_EDITOR_TYPE_UNKNOWN,
    MMI_IME_EDITOR_TYPE_MULTILINE,
    MMI_IME_EDITOR_TYPE_SINGLELINE,    
    MMI_IME_EDITOR_TYPE_MAX
} mmi_ime_editor_type_enum;

typedef enum
{
    MMI_IMC_VK_DIALER_PEN_0,
    MMI_IMC_VK_DIALER_PEN_1,
    MMI_IMC_VK_DIALER_PEN_2,
    MMI_IMC_VK_DIALER_PEN_3,
    MMI_IMC_VK_DIALER_PEN_4,
    MMI_IMC_VK_DIALER_PEN_5,
    MMI_IMC_VK_DIALER_PEN_6,
    MMI_IMC_VK_DIALER_PEN_7,
    MMI_IMC_VK_DIALER_PEN_8,
    MMI_IMC_VK_DIALER_PEN_9,
    MMI_IMC_VK_DIALER_PEN_STAR,
    MMI_IMC_VK_DIALER_PEN_POUND,
    MMI_IMC_VK_DIALER_PEN_CALL1,
    MMI_IMC_VK_DIALER_PEN_CALL2,
    MMI_IMC_VK_DIALER_PEN_VIDEO_CALL,
	MMI_IMC_VK_DIALER_NORMAL_CALL,
	MMI_IMC_VK_DIALER_EMERGENCY_CALL,
    /* Add dialer pen code above this */
    MMI_IMC_VK_DIALER_PEN_MAX 
} mmi_imc_dialer_pen_code_enum;

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
typedef enum
{
    MMI_IMM_PEN_SPEED_FAST,
    MMI_IMM_PEN_SPEED_MEDIUM,
    MMI_IMM_PEN_SPEED_SLOW,
    MMI_IMM_PEN_SPEED_MAX,
} mmi_imm_pen_speed_enum;
#endif

/*****************************************************************************
 * Typedef
 *****************************************************************************/
/* typedef void (*FuncPtr) (void);  Needed to avoid conflict with mmidatatype.h */

typedef struct 
{
    U32 param_0;
    U32 param_1;
    U8  message_id;
}   mmi_imc_message_struct, *mmi_imc_message_struct_p;

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    mmi_pen_event_type_enum   mmi_pen_event;
    mmi_pen_point_struct      pos;
    mmi_imc_editor_pen_event_enum    editor_pen_event;
}mmi_imc_editor_pen_event_struct, *mmi_imc_editor_pen_event_struct_p;
#endif /* __MMI_TOUCH_SCREEN__ */

typedef U32 (*mmi_imc_message_funcptr)( void *, mmi_imc_message_struct_p );
typedef void (*mmi_imui_draw_back_ground_funcptr)(S32 x1, S32 y1, S32 x2, S32 y2);

typedef MMI_BOOL (*mmi_imc_stop_cursor_funcptr)(S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*mmi_imc_start_cursor_funcptr)(void);

typedef struct
{
    S32 x;
    S32 y;
    S32 width;
    S32 height;
} mmi_imc_rect, *mmi_imc_rect_p;

#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
typedef struct
{
    S16 s_x;
    S16 s_y;
    S16 e_x;
    S16 e_y;
} mmi_imc_clipboard_hilite_rect, *mmi_imc_clipboard_hilite_rect_p;
#endif

typedef struct
{
    U8 state;
    mmi_imm_input_mode_enum input_mode;
#ifdef __MMI_VIRTUAL_KEYBOARD__
    gui_virtual_keyboard_language_enum vk_type;
#endif
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    mmi_imm_support_writing_lang_enum writing_lang;
#endif
#if defined(__MMI_IME_FTE_ENHANCE__)
    MMI_BOOL is_vk_on;
    mmi_imc_pen_input_style_enum input_style;
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    MMI_BOOL skip_auto_cap_first_filter;
#endif
} mmi_imc_history, *mmi_imc_history_p;

typedef MMI_BOOL (*mmi_imc_pre_key_handler)(U16, U16);

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
typedef struct
{
    U32 translated_code;
    U32 switch_flags;
}mmi_imm_qwerty_key_attribute_struct, *mmi_imm_qwerty_key_attribute_struct_p;

typedef struct
{
    S16 mmi_key_code;
    mmi_imm_qwerty_key_attribute_struct attributes[MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM];
}mmi_imm_qwerty_key_struct, *mmi_imm_qwerty_key_struct_p;

typedef struct
{
    mmi_imm_support_writing_lang_enum lang;
    mmi_imm_qwerty_key_struct_p qwerty_table;
}mmi_imm_qwerty_lang_struct, *mmi_imm_qwerty_lang_struct_p;
#endif

#ifdef __MMI_CLIPBOARD__ 
typedef struct
{
    UI_buffer_type          ccp_start_cursor_p;
    UI_buffer_type          ccp_end_cursor_p;
    UI_buffer_type          pre_highlight_start_cursor_p;
    UI_buffer_type          pre_highlight_end_cursor_p;
    UI_buffer_type          visible_start_p;  /* For MMS view copy all visible text */
    UI_buffer_type          visible_end_p;    /* For MMS view copy all visible text */
#if defined(UI_EMS_SUPPORT)
    EMSPosition             ems_start_p;
    EMSPosition             ems_end_p;
    EMSPosition             ems_pre_highlight_start_p;
    EMSPosition             ems_pre_highlight_end_p;
#endif
    S32                     highlight_text_length; /* hightlight_end - highlight_start, maybe <0 */
    U32                     pre_flags;
    U8                      is_saved;
    U8                      close_flag;            /* Used when close editor option cascading menu and return to editor screen*/
} mmi_imc_clipboard_data_struct, *mmi_imc_clipboard_data_struct_p;

#endif /* __MMI_CLIPBOARD__ */

typedef struct
{
#ifdef __MMI_CLIPBOARD__
    MMI_BOOL         is_read_only;
    MMI_BOOL         is_empty;
    MMI_BOOL         is_paging;
    MMI_BOOL         is_wcss;
    MMI_BOOL         is_password;
    S32              editor_type;
    S32              editor_sub_type;
#endif /* __MMI_CLIPBOARD__ */
    U16              editor_screen_id;
    mmi_imm_input_type_enum input_type;
    S16              input_ext_type;
    mmi_imm_input_mode_enum *input_mode_list;
    mmi_imm_input_mode_enum input_mode;
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    mmi_imm_support_writing_lang_enum writing_lang;
#endif
#if defined(__MMI_IME_FTE_ENHANCE__)
    MMI_BOOL is_hw_disable : 1;
    MMI_BOOL is_vk_disable : 1;
#endif
	void (*ScreenCloseFunction) (void);
} mmi_imc_editor_menu_history_data_struct, *mmi_imc_editor_menu_history_data_struct_p;

typedef struct
{
    S32 imui_bottom;
    S32 imui_x;
    S32 imui_width;
    S32 imui_bottom_border;
    S32 imui_floating_x;
    S32 imui_floating_width;
    S32 imui_floating_bottom;
}mmi_imui_param_struct, *mmi_imui_param_struct_p;

typedef struct 
{
    U32 param_0;
    U32 param_1;
    U8  message_id;
}   mmi_imui_message_struct, *mmi_imui_message_struct_p;

typedef struct  
{
    UI_character_type allowed_characters[MMI_IMM_MAX_ALLOWED_CHARACTER_NUM];
    UI_character_type disabled_characters[MMI_IMM_MAX_DISABLE_CHARACTER_NUM];
#ifdef __MMI_TOUCH_SCREEN__
    gui_virtual_keyboard_pen_enum allowed_events[MMI_IMM_MAX_ALLOWED_CHARACTER_NUM];
    gui_virtual_keyboard_pen_enum disabled_events[MMI_IMM_MAX_DISABLE_CHARACTER_NUM];
#endif
}mmi_imm_allowed_character_list_struct, *mmi_imm_allowed_character_list_struct_p;

typedef struct 
{
    S32 x;
    S32 y;
}   mmi_imc_point, *mmi_imc_point_p;


typedef enum
{
    MMI_IME_LEFT_SOFTKEY,
    MMI_IME_RIGHT_SOFTKEY,
    MMI_IME_CENTER_SOFTKEY,
    MMI_IME_MAX_SOFTKEYS
} mmi_ime_softkey_enum;

/*****************************************************************************
*  Global Functions
*****************************************************************************/

/* imc functions */
extern void mmi_imc_post_process_handler(void);
	#if defined(__ATV_SMS_SUPPORT__)
		extern void (* matv_init_fptr_ime)();
		extern void (* matv_exit_fptr_ime)();
		void matv_set_func(void (*func1)(), void (*func2)());
		void matv_reset_func(void);
	#endif
extern MMI_BOOL mmi_imc_init_all( void );
extern void     mmi_imc_deinit_all( void );

#ifdef __MMI_PREFER_INPUT_METHOD__
extern void mmi_phnset_set_pref_input_mode_menu_hint(MMI_ID menucui_id);
#endif
extern MMI_BOOL mmi_imc_change_input_mode( mmi_imm_input_mode_enum input_mode, U32 reserved );
extern MMI_BOOL mmi_imc_is_connected( void );
extern U32      mmi_imc_send_message( mmi_imc_message_struct_p msg_ptr ); /* Send message to editor */
extern void     mmi_imc_draw_input_mode_infor(S32 x1, S32 y1, S32 x2, S32 y2);
extern U32      mmi_imc_get_ime_infor_width(void);
extern void     mmi_imc_draw_input_mode_hint(S32 x1, S32 y1, S32 x2, S32 y2);
extern U32      mmi_imc_get_input_mode_hint_width(void);
extern U32      mmi_imc_get_input_mode_hint_height(void);
extern void     mmi_imc_redraw_screen_by_state(void);
extern void     mmi_imc_redraw_whole_screen(void);
extern MMI_BOOL mmi_imc_redraw_screen_by_state_ext(void);
extern void     mmi_imc_disable_key_input(void);
extern void     mmi_imc_disable_symbol_picker(void);
extern void     mmi_imc_enable_symbol_picker(void);
extern MMI_BOOL mmi_imc_is_tone_character(UI_character_type code);
extern MMI_BOOL mmi_imc_is_ime_state(void);
extern void     mmi_imc_show_disabled_vk(void);
extern void     mmi_imc_set_fixed_input_box(void);
extern void     mmi_imc_key_setup_lsk_text(void);
extern void     mmi_imc_key_setup_rsk_text(void);
extern MMI_BOOL mmi_imc_key_is_current_symbol_key(S16 mmi_key_code);
extern void     mmi_imc_reset_ime_state(void);
extern void     mmi_imc_config_draw(MMI_BOOL draw);
extern MMI_BOOL mmi_imc_get_draw(void);
extern void     mmi_imc_redraw_floating_ui_controls(void);
extern MMI_BOOL mmi_imc_get_ui_style(U32 style_flag);

extern void     mmi_imc_key_setup_csk_text(void);
extern void     mmi_imc_key_setup_csk_icon(void);

extern UI_string_type mmi_imc_key_get_lsk_text(void);
extern UI_string_type mmi_imc_key_get_rsk_text(void);

extern UI_string_type mmi_imc_key_get_csk_text(void);

extern void     mmi_imc_key_set_pre_key_handler(mmi_imc_pre_key_handler key_handler);

extern mmi_imc_pre_key_handler mmi_imc_key_get_pre_key_handler(void);

extern MMI_BOOL mmi_imc_insert_char_by_symbol_picker(UI_character_type symbol);

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__) 
extern S32 mmi_imc_get_max_reselection_word_length(void);
#endif

/* This function can only be called by editor's get history function */
extern void     mmi_imc_get_input_method_history(mmi_imc_history_p history);
extern void     mmi_imc_set_input_method_history(mmi_imc_history_p history);

extern void     mmi_imc_key_setup_lsk_function(FuncPtr f);
extern void     mmi_imc_key_setup_rsk_function(FuncPtr f);

extern void     mmi_imc_key_setup_csk_function(FuncPtr f);

extern void     mmi_imc_key_register_ime_keys(void);
extern void     mmi_imc_exit_screen(void);

extern void     mmi_imc_scan_and_add_new_words(UI_string_type str);

extern U32      mmi_imc_get_max_candidate_width(void);

extern MMI_BOOL mmi_imc_is_multitap_state(U8 state);
extern S32      mmi_imc_get_current_imui_height(void);
extern S32      mmi_imc_get_current_imui_height_skip_fixed_editor(void);

extern MMI_BOOL mmi_imc_is_append_one_more_space_input_mode(mmi_imm_input_mode_enum input_mode);

#ifdef __MMI_TOUCH_SCREEN__
extern void     mmi_imc_disable_handwriting(void);
extern S32      mmi_imc_get_vk_area_height(void);
extern gui_virtual_keyboard_language_enum mmi_imc_get_current_vk_type(void);
extern void mmi_imc_set_desired_vk_type(gui_virtual_keyboard_language_enum vk_type);
extern void  mmi_imc_set_inline_editor_full_height(S32 height);
extern S32  mmi_imc_get_inline_editor_full_height(void);
#if defined(__MMI_VIRTUAL_KEYBOARD__)
extern MMI_BOOL mmi_imc_pen_vk_hide(void);
#endif
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_IME_USER_DATABASE__)
extern void mmi_imc_entry_add_new_word_screen(void);
#endif

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
extern void mmi_imc_entry_config_smart_input_method_screen(void);
extern void mmi_imc_exit_config_smart_input_method_screen(void);
#endif

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   
extern MMI_BOOL mmi_imc_is_reselection_input_mode(mmi_imm_input_mode_enum input_mode);
extern MMI_BOOL mmi_imc_is_valid_alphabetic_word_of_current_input_mode(U8 *str_ptr, S32 str_len);
extern void mmi_imc_key_highlight_alphabetic_word(void);
extern void mmi_imc_key_unhighlight_alphabetic_word(void);
extern void mmi_imc_config_smart_alphabetic_word_reselection(MMI_BOOL is_enalbed);
extern MMI_BOOL mmi_imc_is_smart_alphabetic_word_reselection_enabled(void);
#endif

extern void mmi_imc_set_softkey_background_filler(mmi_imui_draw_back_ground_funcptr funcptr);

extern void mmi_imc_redraw_softkey_background(void);

extern void mmi_imc_set_softkey_function(void (*f) (void), mmi_key_types_enum k, mmi_ime_softkey_enum key);

extern void mmi_imc_set_softkey_label(UI_string_type s, mmi_ime_softkey_enum key);

extern void mmi_imc_set_softkey_icon(PU8 icon, mmi_ime_softkey_enum key);

extern void mmi_imc_redraw_floating_ui_within_rect(mmi_imc_rect_p rect);

extern MMI_BOOL mmi_imc_get_current_floating_ui_rect(mmi_imc_rect_p rect);

extern MMI_BOOL mmi_imc_is_spell_word_state(void);

extern mmi_ret mmi_imc_editor_cursor_movement_handler(mmi_event_struct* param);
#if defined(__MMI_IME_V3__)
extern mmi_ret mmi_ime_menu_handler(mmi_event_struct *param);

extern mmi_ret mmi_imesettings_menu_handler_ext(cui_menu_event_struct *evt, MMI_ID parent_gid);
extern void EntryInputMethodSetting(void);
#endif
// DOM-NOT_FOR_SDK-END
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_set_required_mode_list
 * DESCRIPTION
 * This API is for editor to configure list of input modes thatw ill be available to the application .
 * PARAMETERS
 * U32 input_type A 32 bit flag which defines what modes will be required , see input_type section for details.
 * mmi_imm_input_mode_enum In case Application requires a list of modes which is not provided by input type , it 
    can explicitily set an array of modes . ( see Input Modes section fro avilable modes).
 * history_input_mode is used when the editor screen reenters and wants to have previous mode which it had before leaving 
    as the current mode.
 * RETURNS
 * mmi_imm_message_id_enum Success or error.
 *****************************************************************************/

extern mmi_imm_message_id_enum mmi_imm_set_required_mode_list(U32 input_type,
                                                              mmi_imm_input_mode_enum input_mode_array[],
                                                              mmi_imm_input_mode_enum history_input_mode);


extern MMI_BOOL mmi_imm_get_is_smart_input_mode_of_writing_language(void);

extern MMI_BOOL mmi_imm_get_is_smart_input_mode_allowed_of_curr_writing_language(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_connect
 * DESCRIPTION
 * This API allows an Editor to connect to IME service
 * PARAMETERS
 * Pointer of the editor object.
 * Callback to handle messages sent by IME to editor for exchange of information.
 * RETURNS
 *****************************************************************************/

extern MMI_BOOL mmi_imc_connect( void *handle, mmi_imc_message_funcptr msg_callback );




/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disconnect
 * DESCRIPTION
 * Once IME servicee is no longer required , Editor needs to call this.
 * PARAMETERS
 * NONE
 * RETURNS
 * NONE
 *****************************************************************************/
extern void     mmi_imc_disconnect( void );


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_char_info
 * DESCRIPTION
 * This is used to get information related to a chinese character , typical usage is pinyin search.
 * PARAMETERS
 * UI_character_type code of character of which information is required.
 * UI_string_type info_buffer a buffer where information is copied.
 * S32 size of buffer
 * mmi_imm_input_mode_enum mode input mode for which information is required.
 * RETURNS
 *****************************************************************************/

extern MMI_BOOL mmi_imc_get_char_info(UI_character_type code, UI_string_type info_buffer, S32 buffer_size, mmi_imm_input_mode_enum mode);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_phone_language_change_handler
 * DESCRIPTION
 * Callback to inform IME that phone language is being changed .Typical usage is that IME writing language will change 
    accordingly.
 * PARAMETERS
 * NONE
 * RETURNS
 * NONE
 *****************************************************************************/

extern void mmi_imm_phone_language_change_handler(void);





// DOM-NOT_FOR_SDK-BEGIN


extern mmi_imm_message_id_enum mmi_imm_create_input_method_list(U32 input_type, mmi_imm_input_mode_enum input_mode_array[]);

extern mmi_imm_input_mode_enum mmi_imm_get_next_mode(void);

#if defined(__MMI_IME_V3__)

extern mmi_imm_input_mode_enum mmi_imm_get_next_writing_mode(void);

#endif

extern mmi_imm_input_mode_enum mmi_imm_get_curr_input_mode(void);


extern mmi_imm_input_type_enum mmi_imm_get_curr_input_type(void);

extern MMI_BOOL mmi_imm_set_current_input_mode(mmi_imm_input_mode_enum input_mode);

extern mmi_imm_input_mode_enum * mmi_imm_get_curr_user_specific_input_mode_list(void);

extern MMI_BOOL mmi_imm_is_curr_allow_input_mode(mmi_imm_input_mode_enum target);

extern S32  mmi_imm_is_system_supported_input_mode(mmi_imm_input_mode_enum target);

extern S32 mmi_imm_get_system_support_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max);

extern S32 mmi_imm_get_curr_allow_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max);

extern S32 mmi_imm_get_system_support_input_mode_string_list(U8 **strarray, S32 max);

extern S32 mmi_imm_get_prefer_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max);

extern S32 mmi_imm_get_prefer_input_mode_string_list(U8 **strarray, S32 max);

extern S32 mmi_imm_get_curr_allow_input_mode_string_list(U16 *strarray, S32 max);

extern mmi_imm_input_mode_enum mmi_imm_get_user_desired_input_mode(void);

extern MMI_BOOL mmi_imm_check_mixed_lang_support(mmi_imm_input_mode_enum target);

extern MMI_BOOL mmi_imm_is_smart_input_method(mmi_imm_input_mode_enum target);

extern MMI_BOOL mmi_imm_is_chinese_input_method(mmi_imm_input_mode_enum target);

extern mmi_imm_message_id_enum mmi_imm_set_prefer_input_mode(mmi_imm_input_mode_enum desired_input_mode);

extern mmi_imm_input_mode_enum mmi_imm_get_prefer_input_mode(void);

extern mmi_imm_input_mode_enum mmi_imm_get_current_input_mode(void);

extern mmi_imm_message_id_enum mmi_imm_set_user_desired_input_mode(mmi_imm_input_mode_enum desired_input_mode);

extern mmi_imm_message_id_enum mmi_imm_set_app_desired_input_mode(mmi_imm_input_mode_enum desired_input_mode);

extern mmi_imm_message_id_enum mmi_imm_set_characters(
        MMI_BOOL is_allowed,
        const UI_character_type *characters_lsit);

extern mmi_imm_message_id_enum mmi_imm_set_default_input_mode(mmi_imm_input_mode_enum default_input_mode);

extern mmi_imm_input_mode_enum mmi_imm_get_default_input_mode(void);

extern S32 mmi_imm_get_current_allowed_input_mode_num(void);

extern MMI_BOOL mmi_imm_change_input_mode_for_wcss(mmi_imm_input_mode_enum mode);

extern void mmi_imm_config_change_input_mode(MMI_BOOL is_enabled);

extern void  mmi_imc_delete_all(void);
extern S32 mmi_imm_get_curr_allow_writing_language_string_list(UI_string_type *strarray, S32 max);

extern U16 mmi_imm_get_curr_writing_language_index(void);

extern mmi_imm_support_writing_lang_enum mmi_imm_get_current_writing_language(void);

extern void mmi_imm_set_user_desired_writing_language(S32 index);

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
extern void mmi_imm_reset_user_desired_writing_language(void);
#endif

extern mmi_imm_support_writing_lang_enum mmi_imm_get_user_desired_writing_language(void);

extern void mmi_imm_set_writing_language_from_history(mmi_imm_support_writing_lang_enum writing_lang);

extern S32 mmi_imm_get_curr_allow_input_mode_string_list_of_curr_writing_lang(U16 *strarray, S32 max);

extern S32 mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang(mmi_imm_input_mode_enum *mode_array, S32 max);

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
extern S32 mmi_imm_get_curr_allow_input_mode_list_of_imev3(mmi_imm_input_mode_enum *mode_array, S32 max);

extern S32 mmi_imm_get_curr_allow_input_mode_string_list_of_imev3(U16 *strarray, S32 max);
#endif

#if defined(__MMI_IME_V3__)

typedef void (* confirm_func_ptr)(S32 selected_item);

extern void mmi_imc_popup_common_screen_change_mode_callback(S32 selected_item);

extern void mmi_imc_get_input_mode_setting_data(S32* item_count, U16* select_item, U8** item_list,confirm_func_ptr* confirm_call_back);
#endif

#ifdef __MMI_TOUCH_SCREEN__
extern mmi_imm_message_id_enum mmi_imm_set_events(
        MMI_BOOL is_allowed,
        const gui_virtual_keyboard_pen_enum *disable_event_keys_list);

#endif /* __MMI_TOUCH_SCREEN__ */

extern MMI_BOOL mmi_imm_test_input(UI_string_type cand, S32 cand_len);

extern void mmi_imm_test_input_ext(UI_string_type cand, S32 cand_len, MMI_BOOL *is_valid, S32 *valid_len);

extern MMI_BOOL mmi_imm_test_paste(UI_string_type cand, S32 cand_len);

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
extern void mmi_imm_set_main_lang(mmi_imm_support_writing_lang_enum main_lang);
extern mmi_imm_support_writing_lang_enum mmi_imm_get_main_lang(void);
#endif

#if defined(__MMI_MIXED_LANG_SUPPORT__)
extern void mmi_imm_set_sub_lang(mmi_imm_support_writing_lang_enum sub_lang);
extern mmi_imm_support_writing_lang_enum mmi_imm_get_sub_lang(void);

#endif

extern MMI_BOOL mmi_imc_check_multitap_state(void);
extern void mmi_imc_disable_csk(void);

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
extern MMI_BOOL mmi_imm_is_smart_alphabetic_input_modes_enabled(void);
extern void mmi_imm_config_smart_alphabetic_input_modes(MMI_BOOL is_enabled);
#endif

extern void mmi_imm_set_editor_type(mmi_ime_editor_type_enum editor_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_is_auto_capitalization_enabled
 * DESCRIPTION
 * To check if auto-capitalization is enabled
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern MMI_BOOL mmi_imm_is_auto_capitalization_enabled(void);

 /*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_auto_capitalization
 * DESCRIPTION
 * Configure Auto completion Flag
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern void mmi_imm_config_auto_capitalization(MMI_BOOL is_enabled);


/*****************************************************************************

 * FUNCTION
 * mmi_imm_is_auto_completion_enabled
 * DESCRIPTION
 * To check if auto-capitalization is enabled
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern MMI_BOOL mmi_imm_is_auto_completion_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_auto_completion
 * DESCRIPTION
 * Configure auto completion 
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern void mmi_imm_config_auto_completion(MMI_BOOL is_enabled);


/*****************************************************************************

 * FUNCTION
 * mmi_imm_is_alphabetic_word_prediction_enabled
 * DESCRIPTION
 * To check if auto-capitalization is enabled
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern MMI_BOOL mmi_imm_is_alphabetic_word_prediction_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_alphabetic_word_prediction
 * DESCRIPTION
 * Configure  Alphabeticword prediction 
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern void mmi_imm_config_alphabetic_word_prediction(MMI_BOOL is_enabled);


/*****************************************************************************

 * FUNCTION
 * To check if chinese word prediction is enabled
 * DESCRIPTION
 * To check if chinese word prediction is enabled
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern MMI_BOOL mmi_imm_is_chinese_word_prediction_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_chinese_word_prediction
 * DESCRIPTION
 * Configure  Chinese word prediction config Flag
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern void mmi_imm_config_chinese_word_prediction(MMI_BOOL is_enabled);

#if defined(__MMI_IME_V3__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_chinese_word_prediction
 * DESCRIPTION
 * Configure  Chinese word prediction config Flag
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern MMI_BOOL mmi_imm_is_auto_space_enabled(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_chinese_word_prediction
 * DESCRIPTION
 * Configure  Chinese word prediction config Flag
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern MMI_BOOL mmi_imm_is_vibration_enabled(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_chinese_word_prediction
 * DESCRIPTION
 * Configure  Chinese word prediction config Flag
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern MMI_BOOL mmi_imm_is_sound_feedback_enabled(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_chinese_word_prediction
 * DESCRIPTION
 * Configure  Chinese word prediction config Flag
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern void mmi_imm_config_auto_space(MMI_BOOL is_enabled);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_chinese_word_prediction
 * DESCRIPTION
 * Configure  Chinese word prediction config Flag
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern void mmi_imm_config_vibration(MMI_BOOL is_enabled);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_chinese_word_prediction
 * DESCRIPTION
 * Configure  Chinese word prediction config Flag
 * PARAMETERS
 * MMI BOOL Enable/Disable 
 * RETURNS
 * NONE
 *****************************************************************************/
extern void mmi_imm_config_sound_feedback(MMI_BOOL is_enabled);

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_keyboard_type
 * DESCRIPTION
 * Set keypad type
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imm_config_keyboard_type(mmi_imm_keypadtype_enum keyboard_type);

extern void mmi_imm_config_enabled_writing_languages(S32 lang_index , MMI_BOOL state);
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_get_keyboard_type
 * DESCRIPTION
 * Get keypad type
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern mmi_imm_keypadtype_enum  mmi_imm_get_keyboard_type(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_map_wlang_ui_index_logical_index
 * DESCRIPTION
 * Gives writing lang index 
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

extern S32 mmi_imm_map_wlang_ui_index_logical_index(S32 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_map_wlang_logical_index_ui_index
 * DESCRIPTION
 * Gives writing lang index 
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern S32 mmi_imm_map_wlang_logical_index_ui_index(S32 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_map_wlang_logical_index_ui_index_for_sub
 * DESCRIPTION
 * Gives writing lang index  for sub lang
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern S32 mmi_imm_map_wlang_logical_index_ui_index_for_sub(S32 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_update_prefer_writing_language
 * DESCRIPTION 
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imm_update_prefer_writing_language(mmi_imm_support_writing_lang_enum writing_lang);


extern void mmi_imc_entry_edit_new_word_screen(void);
extern void mmi_imc_exit_edit_new_word_screen(void);

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
extern void mmi_imc_entry_config_smart_input_method_screen(void);
extern void mmi_imc_exit_config_smart_input_method_screen(void);
#endif


#if defined(__MMI_IME_USER_DATABASE__)
extern MMI_BOOL mmi_imm_does_current_lang_support_add_new_word(void);
#endif

extern UI_string_type mmi_imm_get_allowed_email_address_characters(void);

extern UI_string_type mmi_imm_get_allowed_voip_number_characters(void);

extern void mmi_imm_get_disabled_and_allowed_character_list(mmi_imm_allowed_character_list_struct_p list);

extern void mmi_imm_set_disabled_and_allowed_character_list(mmi_imm_allowed_character_list_struct_p list);

extern MMI_BOOL mmi_imm_is_smart_input_mode_valid(void);

extern void mmi_imm_config_first_uppercase_input_modes(MMI_BOOL is_enabled);

/* Multi-tap engine functions */
extern U16 mmi_ime_multitap_get_corresponding_key_code(mmi_imm_input_mode_enum input_mode, UI_character_type char_code);

extern U32 mmi_ime_multitap_get_alphabetic_keymap_table_size(void);

extern MMI_BOOL mmi_ime_multitap_create_alphabetic_keymap_table(U16 * buffer_ptr, U32 buffer_size);

extern U16 * mmi_ime_multitap_get_keymap(U16 * keymap_table, U16 key_code, U32 buffer_size);
extern void mmi_imc_set_backgroud_filler(mmi_imui_draw_back_ground_funcptr funcptr);

extern void mmi_imc_disable_virtual_keyboard(void);
extern mmi_imc_editor_menu_history_data_struct_p mmi_imc_get_editor_history_data(void);

#ifdef __MMI_CLIPBOARD__ 
extern mmi_imc_clipboard_data_struct g_imc_clipboard_data; 
extern void mmi_imc_clipboard_enter_locate_start_cursor_state(void);
extern void mmi_imc_clipboard_enter_mark_text_state(mmi_imc_clipboard_mark_text_enum mark);
extern void mmi_imc_clipboard_go_back_to_initial(void);
extern void mmi_imc_clipboard_show_hide_edit_option_menu(mmi_imc_editor_menu_history_data_struct_p history);
extern mmi_imc_clipboard_ret_enum mmi_imc_clipboard_copy(void);
extern mmi_imc_clipboard_ret_enum mmi_imc_clipboard_copy_all(void);
extern mmi_imc_clipboard_ret_enum mmi_imc_clipboard_cut(void);
extern mmi_imc_clipboard_ret_enum mmi_imc_clipboard_cut_all(void);
extern mmi_imc_clipboard_ret_enum mmi_imc_clipboard_paste(void);
extern MMI_BOOL mmi_imc_clipboard_is_show_edit_option(U8 *history_buffer);
extern MMI_BOOL mmi_imc_clipboard_is_editor_read_only(void);
extern void mmi_imc_clipboard_save_keys(void);
extern void mmi_imc_clipboard_restore_keys(void);

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_imc_clipboard_pen_event_down_handler(mmi_pen_point_struct pos);
extern void mmi_imc_clipboard_pen_event_up_handler(mmi_pen_point_struct pos);
extern void mmi_imc_clipboard_pen_event_repeat_handler(mmi_pen_point_struct pos);
extern void mmi_imc_clipboard_pen_event_move_handler(mmi_pen_point_struct pos);
extern void mmi_imc_clipboard_pen_event_abort_handler(mmi_pen_point_struct pos);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_connect
 * DESCRIPTION
 *  Connect IME for clipboard function. In Pluto, copy/cut/paste is bind with IME architecutre, so to support clipboard
 *  function, we need to connect IME.
 *  [Usage]: It should be called in category entry function.
 *  [WARNING]: Currently, we only support EMS/Multiline read only editor
 * PARAMETERS
 *  type                  [IN]        inputbox type.
 * RETURNS
 *  void 
 *****************************************************************************/
extern void mmi_imc_clipboard_connect(mmi_imc_clipboard_inputbox_enum editor_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_disconnect
 * DESCRIPTION
 *  Disconnect clipboard function. 
 *  [Usage]: It should be called in category exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
extern void mmi_imc_clipboard_disconnect(void);

#endif /* __MMI_CLIPBOARD__ */

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
extern MMI_BOOL mmi_imm_qwerty_change_lang(mmi_imm_support_writing_lang_enum lang);
#endif

extern MMI_BOOL mmi_imc_is_clipboard_state(void);

#ifdef __MMI_VIRTUAL_KEYBOARD__
extern void mmi_imc_config_redraw_vk(MMI_BOOL b_show);
#endif

/* Pluto APIs for Venus */
extern void mmi_imc_key_group_key_down( void );
extern void mmi_imc_key_group_key_up( void );
extern void mmi_imc_key_group_key_repeat( void );
extern void mmi_imc_key_group_key_long( void );

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
extern MMI_BOOL mmi_imc_key_qwerty_group_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
extern mmi_ret mmi_imc_key_qwerty_key_proc(mmi_event_struct *evt);
#endif

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
extern MMI_BOOL mmi_imc_key_routing_event_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
#endif

#if defined(__MMI_TOUCH_SCREEN__)
extern void mmi_imc_pen_event_command_handler(mmi_imui_message_struct_p msg_ptr);
#endif


extern void mmi_imc_create_imui_controls(void);

extern void mmi_imc_set_imui_parameters(mmi_imui_param_struct *param);

extern void mmi_imc_get_imui_parameters(mmi_imui_param_struct *param);

extern S32 mmi_imc_get_floating_imui_height(void);

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
extern MMI_BOOL mmi_imc_is_floating_candidate_box_enabled(void);
extern MMI_BOOL mmi_imui_get_floating_ui_position(mmi_imc_rect_p editor_rect, mmi_imc_rect_p cursor_rect, mmi_imc_point_p pos);
#if defined(__MMI_TOUCH_SCREEN__)
extern MMI_BOOL mmi_imc_check_floting_ui_contain_point(mmi_imc_point_p point);
#endif
#endif

extern U32 mmi_imc_get_current_floating_imui_control_set(void);

extern gdi_handle mmi_imc_get_extra_imui_layer_handler(void);

/* To check if an input mode is enabled in input mode list setting*/
extern MMI_BOOL mmi_imm_is_enabled_input_mode(mmi_imm_input_mode_enum input_mode) ;
/*To check if a writing language is enabled in writing language list setting*/
extern MMI_BOOL mmi_imm_is_enabled_writing_language(mmi_imm_input_mode_enum input_mode);
/* To check if smart input modes are enabled, replace mmi_imm_is_smart_alphabetic_input_modes_enalbed in imm.c*/
extern MMI_BOOL mmi_imm_is_smart_input_modes_enabled(void);

extern void mmi_imc_entry_edit_new_word_screen(void);
extern  void mmi_imc_exit_edit_new_word_screen(void);


#if defined(__MMI_VUI_ENGINE__)
/* for vadp input server */
extern void mmi_imc_pen_event_pen_longtap_in_editor(mmi_pen_point_struct pos);
extern void mmi_imc_pen_event_pen_down_in_editor(mmi_pen_point_struct pos);
extern void mmi_imc_pen_event_pen_up_in_editor(mmi_pen_point_struct pos);
extern void mmi_imc_pen_event_pen_move_in_editor(mmi_pen_point_struct pos);
extern void mmi_imc_pen_event_pen_abort_in_editor(mmi_pen_point_struct pos);
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
extern mmi_imc_vk_present_enum mmi_imc_get_vk_present(void);
extern void mmi_imc_set_vk_present(mmi_imc_vk_present_enum style);
#if defined(__MMI_VIRTUAL_KEYBOARD__)
extern void mmi_imc_pen_show_popup_list_int(
                    S32 x, 
                    S32 y, 
                    S32 number_of_items,
                    U16 *list_of_items,
                    S32 highlighted_item,
                    FuncPtr confirm_callback, 
                    FuncPtr cancel_callback);
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */

#if defined(__MMI_VUI_ENGINE__)
extern void mmi_imc_pen_event_pen_down_in_editor(mmi_pen_point_struct pos);
extern void mmi_imc_pen_event_pen_move_in_editor(mmi_pen_point_struct pos);
extern void mmi_imc_pen_event_pen_up_in_editor(mmi_pen_point_struct pos);
extern void mmi_imc_pen_event_pen_abort_in_editor(mmi_pen_point_struct pos);
#endif /* defined(__MMI_VUI_ENGINE__) */

#if defined(__MMI_TOUCH_SCREEN__)
extern mmi_imc_pen_handwriting_style_enum mmi_imc_pen_get_handwriting_style(void);

#if !defined(__NO_HANDWRITING__)
extern void mmi_imc_pen_stroke_down_handler(mmi_pen_point_struct pos);
extern void mmi_imc_pen_stroke_up_handler(mmi_pen_point_struct pos);
extern void mmi_imc_pen_stroke_move_handler(mmi_pen_point_struct pos);
#endif /* !defined(__NO_HANDWRITING__) */
#endif /* defined(__MMI_TOUCH_SCREEN__) */

extern void mmi_imc_set_dialer_callback(MMI_BOOL (*funcptr)(mmi_imc_dialer_pen_code_enum pen_code, mmi_pen_event_type_enum pen_event));
extern void mmi_imc_send_current_input_mode_indication(void);

extern void mmi_imc_config_keymap_auto_test(MMI_BOOL is_on);

extern void mmi_imc_update_input_mode_by_cursor_pos(void);

extern void mmi_imc_editor_is_not_ready_when_connecting(void);

extern MMI_BOOL mmi_imc_is_editor_ready_when_connecting(void);

extern void mmi_imc_config_update_input_mode_by_cursor_pos(MMI_BOOL is_enabled);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_auto_capitalization_setting_changed
 * DESCRIPTION
 * Configure Auto capitalization  is changed flag
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imm_config_auto_capitalization_setting_changed(MMI_BOOL is_enabled);
/*****************************************************************************

 * FUNCTION
 *  mmi_imm_is_auto_capitalization_setting_changed
 * DESCRIPTION
 * To check if auto-capitalization setting was changed
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imm_is_auto_capitalization_setting_changed(void);

extern mmi_ret mmi_imc_enter_spell_word_screen_handler(mmi_event_struct* param);
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_map_wlang_ui_index_sub_lang
 * DESCRIPTION
 * Gives sub writing lang from UI index 
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern S32 mmi_imm_map_wlang_ui_index_sub_lang(S32 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_wlang_change_handler
 * DESCRIPTION
 *  for setting wlang from editors option menu
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

extern void    mmi_imm_wlang_change_handler( S32 index);
extern MMI_BOOL mmi_imm_is_enabled_wlang(S32 wlang);
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_get_handwriting_setting
 * DESCRIPTION
 * Set whetehr or not hwsetting to be displayed
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern MMI_BOOL mmi_imm_get_handwriting_setting(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_ime_indicator
 * DESCRIPTION
 *  Redraw IME indicator, including information bar, input mode hint and IME 
 *  indicator on status icon bar
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imc_redraw_ime_indicator(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_skip_first_cursor_movement_event
 * DESCRIPTION
 * PARAMETERS
 *  is_skip
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_imc_skip_first_cursor_movement_event(MMI_BOOL is_skip);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_IsInputTypeNumber
 * DESCRIPTION
 * PARAMETERS
 *  is_skip
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_imm_IsInputTypeNumber(void);

extern U32 mmi_imm_get_required_mode_list_count(U32 input_type);

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_get_pen_speed
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern mmi_imm_pen_speed_enum mmi_imm_get_pen_speed(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_set_pen_speed
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imm_set_pen_speed(mmi_imm_pen_speed_enum speed);
#if defined( __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_handwriting_is_follow_vk
 * DESCRIPTION
 *	get current system is followed vk or not.
 * PARAMETERS
 *	void
 * RETURNS
 *		MMI_TRUE is follow vk
 *****************************************************************************/
extern MMI_BOOL mmi_imm_handwriting_is_follow_vk(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_handwriting_set_follow_vk_lang
 * DESCRIPTION
 *	set follow vk lang
 * PARAMETERS
 *	bFollow: True->follow 
 * RETURNS
 *	void
 *****************************************************************************/
extern void mmi_imm_handwriting_set_follow_vk_lang(MMI_BOOL bFollow);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_handwriting_get_current_color_index
 * DESCRIPTION
 *	get current color id
 * PARAMETERS
 *	NA
 * RETURNS
 *	color id
 *****************************************************************************/
extern U8  mmi_imm_handwriting_get_current_color_id(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_handwriting_set_width
 * DESCRIPTION
 *	set handwriting stroke width
 * PARAMETERS
 *	width: stroke pixel width
 * RETURNS
 *	void
 *****************************************************************************/
extern void mmi_imm_handwriting_set_width(U8 width);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_handwriting_get_stroke_width
 * DESCRIPTION
 *	get stroke width
 * PARAMETERS
 *	void
 * RETURNS
 *	stroke pixel width
 *****************************************************************************/
extern U8 mmi_imm_handwriting_get_stroke_width(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_handwriting_get_current_color_index
 * DESCRIPTION
 *	get stroke color index
 * PARAMETERS
 *	void
 * RETURNS
 *	stroke pixel width
 *****************************************************************************/
extern U32 mmi_imm_handwriting_get_current_color_index(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_imm_handwriting_set_current_stroke_color
 * DESCRIPTION
 *	set handwriting current stroke's color
 * PARAMETERS
 *	uIndex: color id
 * RETURNS
 *	True: set success
 *	False: set fail
 *****************************************************************************/
extern MMI_BOOL mmi_imm_handwriting_set_current_stroke_color( U8 uIndex );

/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_get_current_stroke_color
 * DESCRIPTION
 *	get current stroke color
 * PARAMETERS
 *	void
 * RETURNS
 *	current stroke color
 *	
 *****************************************************************************/
extern color mmi_imm_handwriting_get_current_stroke_color(void);

/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_get_color_list
 * DESCRIPTION
 *	get stroke color list
 * PARAMETERS
 *	NA
 * RETURNS
 *	 Pointer of color list(start address of the array)
 *	
 *****************************************************************************/
extern const color* mmi_imm_handwriting_get_color_list(void);

/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_get_color_number
 * DESCRIPTION
 *	get stroke color number
 * PARAMETERS
 *	NA
 * RETURNS
 *	 nunber of stroke color
 *	
 *****************************************************************************/
extern U8	mmi_imm_handwriting_get_color_number(void);

/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_enable
 * DESCRIPTION
 *	enable or disable handwriting
 * PARAMETERS
 *	bOn: True: enable handwriting
 *		 False: disable handwirting
 * RETURNS
 *	NA
 *	
 *****************************************************************************/
extern void mmi_imm_handwriting_enable(MMI_BOOL bOn);

/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_is_enable
 * DESCRIPTION
 *	get current handwriting state of on or off.
 * PARAMETERS
 *	NA
 * RETURNS
 *	TRUE:	handwriting is on
 *	FALSE:  handwriting is off
 *	
 *****************************************************************************/
extern MMI_BOOL mmi_imm_handwriting_is_enable(void);

/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_get_language_string
 * DESCRIPTION
 *	get handwriting language string.
 * PARAMETERS
 *	uIndex : language id
 * RETURNS
 *	string of language
 *	
 *****************************************************************************/
extern UI_character_type* mmi_imm_handwriting_get_language_string(U16 uIndex);


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_handwriting_language
* DESCRIPTION
*  Set current handwritingwriting language
* PARAMETERS
* RETURNS
*****************************************************************************/

extern void mmi_imm_config_handwriting_language(UI_string_type string);

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_handwriting_language
* DESCRIPTION
*  Get current handwritingwriting language
* PARAMETERS
* RETURNS
*****************************************************************************/

extern UI_string_type mmi_imm_get_handwriting_language(void);



/*****************************************************************************
* FUNCTION
*  mmi_imm_get_handwriting_language_strings
* DESCRIPTION
*  Get current handwritingwriting language strings
* PARAMETERS
* RETURNS
*****************************************************************************/
extern U32 mmi_imm_get_handwriting_language_strings(UI_string_type strarray[] );



/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_set_language
 * DESCRIPTION
 *	set current handwriting language.
 * PARAMETERS
 *	uIndex : language id
 * RETURNS
 *	NA
 *	
 *****************************************************************************/
extern void mmi_imm_handwriting_set_language(U16 uindex);
/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_get_current_lang
 * DESCRIPTION
 *	get current handwriting language id.
 * PARAMETERS
 *	NA
 * RETURNS
 *	language id
 *	
 *****************************************************************************/
extern U16 mmi_imm_handwriting_get_current_lang(void);
extern mmi_imm_input_mode_enum  mmi_imm_handwriting_get_current_mode(void);
/*****************************************************************************
 *
 * FUNCTION
 *  mmi_imm_handwriting_get_lang_number
 * DESCRIPTION
 *	get current handwriting language number.
 * PARAMETERS
 *	NA
 * RETURNS
 *  total num of handwriting language.
 *	
 *****************************************************************************/

extern U16 mmi_imm_handwriting_get_lang_number(void);
#endif

#endif

extern void mmi_imc_check_rotation(void);

extern void mmi_imm_write_prefered_input_method_to_nvram(mmi_imm_input_mode_enum input_mode);

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_is_java_special_symbol_enabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imc_set_is_java_special_symbol_enabled(MMI_BOOL is_enabled);

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_is_java_special_symbol_enabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern MMI_BOOL mmi_imc_get_is_java_special_symbol_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_is_dialer_special_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imc_set_is_disable_candidate_box(MMI_BOOL is_disabled);

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_is_dialer_special_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern MMI_BOOL mmi_imc_get_is_disable_candidate_box(void);

extern MMI_BOOL mmi_imc_process_key_input(U16 key_code, U16 key_type , U16 ucs2_value, U32 special_key_flag);

extern MMI_BOOL mmi_imc_process_pen_input(mmi_pen_point_struct pos , U16 event_type);

//Data Added for making Symbol picker Mechanism Generic on cosmos also
#define SYMBOL_TABLE_CUSTOMIZATION_FUNC_NUM  5
#define SYMBOL_PICKER_MAX_SYMBOLS            49
typedef S32 (*mmi_ime_symbol_table_callback)(U8*, S32, U8**, S32);
extern mmi_ime_symbol_table_callback g_mmi_ime_prepare_symbol_table[SYMBOL_TABLE_CUSTOMIZATION_FUNC_NUM];
extern S32 g_mmi_ime_symbol_table_stack_top ;
extern U8 g_mmi_ime_ap_desired_symbol[SYMBOL_PICKER_MAX_SYMBOLS* 2 * sizeof(UI_character_type)];
extern U8** g_mmi_ime_default_symbol_table[SYMBOL_TABLE_CUSTOMIZATION_FUNC_NUM];
extern S32 g_mmi_ime_default_symbol_table_max_num[SYMBOL_TABLE_CUSTOMIZATION_FUNC_NUM]; 

#endif /* __IMEGROT_H__ */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


