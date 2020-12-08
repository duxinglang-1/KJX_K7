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
 *    Imc.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
dear gaurav,
this issue need some change in Imc_pen, when this two event comes,
GUI_VKBD_PEN_V3_SHIFT_UP_TO_LOW,
GUI_VKBD_PEN_V3_SHIFT_LOW_TO_UP,

you should take the other keyboard which is saved in HW atrribute. this api mmi_imc_pen_set_virtual_keyboard_by_capital_state
may can be used, thank you.

[manik}
dear sikun,
please add your part , i will checkin the vk in unicdeo_map.txt after you.
Also explain this to Gaurav for his changes .
feel free to discuss.
Thanks


[Joy]
Dear Manik,
I have added the shift xml for hindi/thai/bengali, and the key code for the shift key I discussed with Sikun are: GUI_VKBD_PEN_V3_SHIFT_UP_TO_LOW -101
GUI_VKBD_PEN_V3_SHIFT_LOW_TO_UP -102
Now may be you need to modify parser to parse _shift.xml, also add a new enum for them, e.x. GUI_VIRTUAL_KEYBOARD_HI_IN_SHIFT for hindi.
Besides, Sikun needs to add the keyboard enum, and Gaurav needs to handle the key code.

[yong]
Dear joy,
please reffer to manik's comments and discuss with sikun to fix this issue! thank you!

[Manik]
Dear Sikun,

AS discussed we need xml data for the second keyboard and put in different folder and , you need to add enum according to newly created folder , that should fix the issue.
Thanks


[sikun]
dear mainik,
I check the resource in xml, there is shift keyboard there, same as hindi, but now, we only have four keyboard layout in data, but the enum of this data is same, please help to check this, thank you.

[Manik]
Dear Sikun,
Same as hindi issue , Thai does nothave cases , please check

[Load Path]
       \\mtksdd01.gslb.mediatek.inc\sw_releases\W12.13\11B\official

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "mmi_include.h"
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
#include "GpioSrvGprot.h"
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#include "ImeQwertyProt.h"
#endif
#if defined(__COSMOS_MMI_PACKAGE__)
#include "vfx_adp_device.h"
#endif 
#include "IMERes.h"
#include"Kal_release.h"
#include"kal_trace.h"
#include "Imui.h"
#include "Imc.h"
#include "Imc_key.h"
#include "wgui_softkeys.h"

#if defined(__MMI_TOUCH_SCREEN__)
#include "Imc_pen.h"
#include "wgui_virtual_keyboard.h"
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */

#include "ImmProt.h"

#include "Multitap_engine.h"
#include "Word_engine.h"
#include "Handwriting_engine.h"

#include "IndicEngineGprot.h"

#include "CommonScreensResDef.h"

#if defined(__MMI_IME_USER_DATABASE__) || defined(__MMI_CLIPBOARD__) || !defined(__MMI_NO_IME_VENDOR__)
#include "CommonScreens.h"
#include "SettingProfileEnum.h"
#endif

#if defined(__MMI_CLIPBOARD__)
#include "wgui_ems.h"
#include "SmsGuiInterfaceProt.h"
#include "MessagesResourceData.h"
#include "gui_effect_oem.h"  /* Disable clipboard when SSP */
#include "mmi_rp_srv_editor_def.h"
#include "wgui_categories_enum.h"
#endif

#ifdef __MMI_VUI_ENGINE__
#include "framework\vadp_p2v_uc.h"
#include "ime\vadp_p2v_input_server_interface.h"
#endif

#include "Imc_msg_struct.h"

#include "MenuCuiGprot.h"
#include "mmi_rp_srv_editor_def.h"
#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
#include "FileMgrSrvGProt.h"
#endif




/* RHR ADD */

#include "MMIDataType.h"
#include "ImeGprot.h"
#include "kal_non_specific_general_types.h"
#include "Imc_config.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "MessagesMiscell.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_res.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "gui_inputs.h"
#include "wgui_include.h"
#include "wgui_inputs.h"
#include "wgui_touch_screen.h"
#include "gui.h"
#include "gdi_include.h"
#include "mmi_frm_input_gprot.h"
#include "gui_buttons.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "Unicodexdcl.h"
#include "Imc_symbol.h"
#include "wgui_categories_util.h"
#include "gui_virtual_keyboard.h"
#include "DebugInitDef_Int.h"
#include "MMI_fw_trc.h"
#include "gui_virtual_keyboard_language_type.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "CustDataRes.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "wgui_categories_inputs.h"
#include "mmi_rp_app_uiframework_def.h"
//#include "vmsys.h"
#include "gui_ems.h"
#include "CustMenuRes.h"
#include "gui_config.h"
#include "mmi_clipboard_gprot.h"
#include "stdlib.h"
#include "wgui.h"
#include "gdi_datatype.h"
#include "gdi_const.h"

#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
#include "Ime_lib_config.h"
#include "Lang_interface.h"
#endif

#ifdef __MMI_IME_PLUG_IN__
#include "ImeSDKGProt.h"
#include "ImeSDKProt.h"
#endif
#if defined (__MMI_LANG_THAI__)
#include "ThaiGProt.h"
#endif

#if defined(__IMEHW_DCM_SUPPORT__)
#include "dcmgr.h"
#endif//#if defined(__IMEHW_DCM_SUPPORT__)

/*****************************************************************************
 *  Define
 *****************************************************************************/

#if defined __MMI_XT9__
extern CANDIDATE_FLAG;
extern candidate_flag;
#endif 

/*****************************************************************************
 *  Typedef
 *****************************************************************************/

typedef struct
{
    mmi_imc_state_enum  curr_state;
    U32                 imui_set;
}   mmi_imc_fsm_struct, *mmi_imc_fsm_struct_p;

typedef struct
{
    mmi_imc_fsm_struct              fsm_object;
    mmi_imc_global_data_struct      global_data;
    void                            *editor_handle;
    mmi_imc_message_funcptr         message_proc;
    const sIMEModeDetails           *mode_details_ptr;
    mmi_imc_history                 history;
    MMI_BOOL                        is_inited;
}   mmi_imc_object_struct, *mmi_imc_object_struct_p;

#if defined(__MMI_IME_USER_DATABASE__)
typedef struct
{
    mmi_imm_input_mode_enum new_word_input_mode;
    UI_character_type       new_word_buffer[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
    mmi_imm_input_mode_enum new_word_input_mode_list[MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG];
}mmi_imc_edit_new_word_screen_history, *mmi_imc_edit_new_word_screen_history_p;
#endif

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
/* To avoid stack memory overflow, we create this structure to maintain tha temp buffers */
typedef struct
{
    mmi_imc_symbol_key_enum symbol_table[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE][MMI_IMM_QWERTY_MAX_MULTITAP_CHAR_NUM];
    UI_character_type char_table[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE][MMI_IMM_QWERTY_MAX_MULTITAP_CHAR_NUM];
    S32 symbol_count[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    S32 char_count[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    UI_character_type string_buffer[MMI_IMM_QWERTY_MAX_MULTITAP_CHAR_NUM * 2];
    U16 symb_buff[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    UI_character_type  temp_cand_buff[MMI_IMC_MAX_CANDIDATE_BUFFSIZE];
}mmi_imc_qwerty_smart_mode_temp_buf_struct, *mmi_imc_qwerty_smart_mode_temp_buf_struct_p;
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
static U16 g_imc_active_editor_screen_id = 0;
#endif
static void mmi_imc_input_method_screen_close_function(void);

/*****************************************************************************
 * Local functions
 *****************************************************************************/
#if defined(__MMI_CSTAR_PHRASE_INPUT__) && defined(__MMI_VIRTUAL_KEYBOARD__)
static UI_string_type mmi_imc_check_input_area_confirmed_length(UI_string_type input_string);
#endif
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
static void mmi_imc_hide_vk_on_slider_open(void);
#endif
static void mmi_imc_enable_vk_on_slider_close(void);
static void mmi_imc_vk_draw_override(MMI_BOOL flag);
static void mmi_imc_timer_handler(void);
static void mmi_imc_config_smart_input_method_hilight_hdlr(S32 index);
static  void mmi_imc_set_smart_input_method(void);
 void mmi_imc_entry_edit_new_word_screen_with_sg(mmi_id g_id);
 void mmi_imc_entry_add_new_word_screen_with_sg(mmi_id g_id);
#if defined(__MMI_IME_USER_DATABASE__) 
static U8 is_go_back = 0 ;
static void NewWordGoBackHistory(void); 
static void mmi_imc_save_new_word(void);
#endif /* #if defined(__MMI_IME_USER_DATABASE__) */

#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
static void mmi_imc_input_style_change_handle(void);
#endif


#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_V3__)
static void mmi_imc_get_smart_alphabetic_candidates_for_qwerty( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
static MMI_BOOL mmi_imc_is_duplicated_candidate(UI_string_type src, UI_string_type cand, S32 count);
#endif

static void mmi_imc_print_character_inserted_to_editor(UI_character_type char_code);

#if defined(__MMI_TOUCH_SCREEN__)
static U8 *mmi_imc_get_ime_screen_general_ui_control_set(void);
#endif

static void mmi_imc_softkey_hide_callback(WGUI_SOFTKEY_ENUM key);

static void mmi_imc_icon_bar_pause_interactive_ui_callback(void);


/*****************************************************************************
 * Global variables
 *****************************************************************************/

mmi_imc_post_process_data_struct g_ime_post_process_data;
#if defined(__MMI_IME_CANDIDATE_GRID__)
MMI_BOOL g_imc_is_change_from_grid = MMI_FALSE;
mmi_imc_state_enum g_imc_prev_state_grid;
MMI_BOOL g_imc_enter_grid_state = MMI_FALSE;
MMI_BOOL g_imc_prev_state_is_grid = MMI_FALSE;
#endif
MMI_BOOL g_imc_vk_override = MMI_FALSE;
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
mmi_imc_slider_status g_imc_slider_status = CLOSE;
#endif
#ifdef __ATV_SMS_SUPPORT__
 		void (* matv_init_fptr_ime)();
		void (* matv_exit_fptr_ime)();
#endif

#ifdef __ATV_SMS_SUPPORT__
 void matv_set_func(void (*func1)(), void (*func2)())
{
	   matv_init_fptr_ime = func1;
	   matv_exit_fptr_ime = func2;
}

void matv_reset_func(void)
{
	   matv_init_fptr_ime = NULL;
	   matv_exit_fptr_ime = NULL;
}

void mmi_imc_set_smart_input_method_matv_screen_close();
#endif
#ifdef __MMI_PREFER_INPUT_METHOD__
extern mmi_imm_input_mode_enum MMI_all_prefered_input_mode_set[IMM_INPUT_MODE_MAX_NUM];
#endif
 
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_V3__)
extern void mmi_ime_reset_group_letters(const sIMEModeDetails * mode_details_ptr);
#endif

extern void (*RedrawSpellingOrCandidateBoxesFunction) (void);

#if defined(UI_SMALL_CATEGORY_EDITOR)
extern BOOL g_small_editor_category_present;
#endif

#ifdef __MMI_CLIPBOARD__ 
mmi_imc_clipboard_data_struct g_imc_clipboard_data;
mmi_imc_pre_key_handler g_imc_app_pre_key_hander = NULL;
static FuncPtr g_imc_clipboard_key_handler[8];   /* Save App's navigation key handler */
static MMI_BOOL g_imc_clipboard_key_is_saved = MMI_FALSE;
#endif /* __MMI_CLIPBOARD__ */

static mmi_imc_editor_menu_history_data_struct g_editor_history_data;
MMI_ID g_ime_screens_group_id;

MMI_BOOL g_imc_show_venus_popup = MMI_FALSE;
#if defined(__ATV_SMS_SUPPORT__)
static MMI_BOOL g_is_in_atv_editor = MMI_FALSE;
static MMI_BOOL g_floating_state_configured_by_app = MMI_FALSE;
#endif /* defined(__ATV_SMS_SUPPORT__) */
/*****************************************************************************
 * Local variables
 *****************************************************************************/
static MMI_BOOL g_is_ime_connected = MMI_FALSE;
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
static MMI_BOOL g_is_ime_disconnecting = MMI_FALSE;
#endif
 static mmi_imc_state_enum g_pre_state = MMI_IMC_STATE_NONE;

static mmi_imc_object_struct    g_imc;

static FuncPtr g_active_timer_callback = NULL;

static FuncPtr g_timer_cancel_callback = NULL;

static S32 g_active_timer_count = 0;

static mmi_imui_draw_back_ground_funcptr g_imc_background_filler = NULL;

/* temp candidate used to get candidate from word engine. */
static UI_character_type g_mmi_imc_temp_cand[MMI_IMC_MAX_CANDIDATE_BUFFSIZE];

#if defined(__MMI_IME_MAGIC_ONE__)
static MMI_BOOL g_magic_key_down = MMI_FALSE;
static MMI_BOOL g_is_magic_state = MMI_FALSE;
static const sIMEModeDetails  *g_backup_mode_details_ptr;
static mmi_imm_input_mode_enum g_backup_input_mode = IMM_INPUT_MODE_NONE;
#endif

static MMI_BOOL g_imc_enable_csk = MMI_TRUE;
static MMI_BOOL g_imc_disable_draw = MMI_FALSE;

static MMI_BOOL g_is_fixed_input_box = MMI_FALSE;

#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL g_is_handwriting_disabled = MMI_FALSE;

static MMI_BOOL g_is_vk_disabled = MMI_FALSE;

static S32 g_inline_editor_full_height = 0;

static MMI_BOOL g_mmi_imc_is_invalid_hw_type = MMI_FALSE;

#endif /* defined(__MMI_TOUCH_SCREEN__) */

static MMI_BOOL g_is_key_disabled = MMI_FALSE;
static MMI_BOOL g_is_pen_disabled = MMI_FALSE;

static MMI_BOOL g_is_symbol_picker_disable = MMI_FALSE;

static MMI_BOOL g_has_entered_ime_screen = MMI_FALSE;

#if defined(__MMI_IME_USER_DATABASE__)
UI_character_type g_imc_new_word_buffer[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
mmi_imm_input_mode_enum g_imc_edit_new_word_input_mode_list[MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG];
mmi_imm_input_mode_enum g_imc_new_word_input_mode = IMM_INPUT_MODE_NONE;
#endif 

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
static mmi_imc_qwerty_smart_mode_temp_buf_struct g_imc_qwerty_smart_mode_temp_buffer;
#endif

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)
static MMI_BOOL g_imc_is_reselection_enabled = MMI_TRUE;
#endif

static MMI_BOOL g_imc_is_printing_character_trace_enabled = MMI_TRUE;

static MMI_BOOL g_imc_is_keymap_auto_test_on = MMI_FALSE;

static mmi_imc_ui_style_param_struct g_imc_ui_style;
#if defined(__MMI_IME_USER_DATABASE__)
static U32 is_edit_word_from_add_word = MMI_FALSE;
#endif

U16 g_imc_selection_list_str_array[MMI_IMC_SELECT_LIST_ITEM_NUM_MAX];
mmi_imm_input_mode_enum g_imc_selection_list_mode_array[MMI_IMC_SELECT_LIST_ITEM_NUM_MAX];
#if defined(__MMI_IME_V3__)
S32 g_imc_current_input_mode_in_list = 0;
static mmi_imm_input_mode_enum mode_before_123_symbol = IMM_INPUT_MODE_NONE;
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
static MMI_BOOL g_imc_single_block_hw_state = MMI_FALSE;
#if defined(__MMI_VIRTUAL_KEYBOARD__)
static mmi_imc_vk_present_enum g_imc_prefer_vk_present = MMI_IMC_VK_PRESENT_DEFAULT;
#endif
#endif

#if defined(__MMI_TOUCH_SCREEN__)
static U8 g_imc_ime_screen_general_ui_control_set[] = {
    1,
    DM_BUTTON_BAR1
};
#endif

static mmi_imui_draw_back_ground_funcptr g_imc_softkey_background_filler = NULL;

static WGUISoftkeyHideFuncPtr g_imc_backup_softkey_hide_fptr = NULL;

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
static mmi_frm_dial_key_tone_type_enum g_imc_backup_tone_mode = MMI_DIALER_KEY_TONE_NORMAL;
#endif

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
static MMI_BOOL g_imc_is_update_input_mode_by_cursor_pos_enabled = MMI_TRUE;
#endif

#define    MMI_IMC_KEY_MAX_ENDING_STRING_LENGTH    4
#define    MMI_IMC_KEY_MAX_ENDING_STRING_NUM       21  /* We can increase this macro and add some strings */

static const UI_character_type g_imc_sentence_ending_markers[MMI_IMC_KEY_MAX_ENDING_STRING_NUM + 1][MMI_IMC_KEY_MAX_ENDING_STRING_LENGTH] =
{
    {0x0020, '.', '\0'},
    {0x0020, '!', '\0'},
    {0x0020, '?', '\0'},
	{'!', '\0'},
	{'?', '\0'},
	{0x0020, 0x3002, '\0'},
	{0x0020, 0xff1f, '\0'},
	{0x0020, 0xff0e, '\0'},
	{0x0020, 0x2026, '\0'},
	{0x0020, 0xff01, '\0'},
	{0x3002, '\0'},
	{0xff1f, '\0'},
	{0xff0e, '\0'},
	{0x2026, '\0'},
	{0xff01, '\0'},
	{0x0020, 0x000A, 0x000D, '\0'},
	{0x000A, 0x000D, '\0'},
	{0x0020, 0x000A, '\0'},
	{0x000A, '\0'},
	{0x0020, 0x000D, '\0'},
	{0x000D, '\0'},
    {'\0'}
};
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
static MMI_BOOL g_imc_skip_first_cursor_movement_event = MMI_FALSE;
static MMI_BOOL g_imc_skip_auto_cap_first_filter = MMI_FALSE;
#endif
static MMI_BOOL g_imc_is_editor_ready_when_connecting = MMI_TRUE;

#ifdef __MMI_TOUCH_SCREEN__

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
/* vk presentation is decided by ui style not state. */
static mmi_imc_fsm_struct g_ime_state_set[] = 
{
    {MMI_IMC_STATE_INITIAL, 0},
    
    {MMI_IMC_STATE_PASSWORD_PREVIEW, 0},
    
    {MMI_IMC_STATE_WORD_HIGHLIGHTED, 0},
    
    {MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP, 0},
    
    {MMI_IMC_STATE_SPELL_INPUTING,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_CAND_SELECTING,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	{MMI_IMC_STATE_SPELL_INPUTING_GRID,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_GRID_AREA)},
	{MMI_IMC_STATE_CAND_SELECTING_GRID,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_GRID_AREA)},
	{MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_GRID_AREA)},
	{MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_GRID_AREA)},
	{MMI_IMC_STATE_ASSOC_SELECTING_GRID, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_GRID_AREA)},
	#endif
    {MMI_IMC_STATE_ASSOC_SELECTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_PREDICTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_MULTI_BLOCK_AREA)},

    {MMI_IMC_STATE_HAND_WRITING, 0},
    
    {MMI_IMC_STATE_HAND_WRITING_CAND, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_VK_CAND, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_VK_CAND_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_SMART_CANDIDATE, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_SPELL_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_NEW_WORD_INITIAL, MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},

    {MMI_IMC_STATE_NEW_WORD_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},
    
#ifdef __MMI_CLIPBOARD__
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT, 0},

#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU)},
#else
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN, 0},
#endif

    {MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS, 0},

    {MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU)},
#endif /* __MMI_CLIPBOARD__ */

#if defined(__MMI_CSTAR_PHRASE_INPUT__)
    {MMI_IMC_STATE_SPELL_WITH_INPUT, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},

    {MMI_IMC_STATE_CAND_SELECT_WITH_INPUT, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	{MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_GRID_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},
	#endif
        
#endif

    {MMI_IMC_STATE_NONE, 0}

};

#else /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

static mmi_imc_fsm_struct g_ime_state_set[] = 
{
    {MMI_IMC_STATE_INITIAL, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)},
    
    {MMI_IMC_STATE_WORD_HIGHLIGHTED, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)},
    
    {MMI_IMC_STATE_PASSWORD_PREVIEW, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)},

	{MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)},
    
    {MMI_IMC_STATE_SPELL_INPUTING,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_CAND_SELECTING,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_ASSOC_SELECTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_PREDICTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_MULTI_BLOCK_AREA)},

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    {MMI_IMC_STATE_HAND_WRITING, 0},
#else
    {MMI_IMC_STATE_HAND_WRITING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},
#endif

    {MMI_IMC_STATE_HAND_WRITING_CAND, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_VK_CAND, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_VK_CAND_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},


    {MMI_IMC_STATE_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},


#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
    {MMI_IMC_STATE_SMART_CANDIDATE, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},
#else
    {MMI_IMC_STATE_SMART_CANDIDATE, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},
#endif

    {MMI_IMC_STATE_SPELL_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_NEW_WORD_INITIAL, MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},

    {MMI_IMC_STATE_NEW_WORD_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},

#ifdef __MMI_CLIPBOARD__
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)},
#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU)},
#else
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)},
#endif
    {MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)},

    {MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU)},
#endif /* __MMI_CLIPBOARD__ */

    {MMI_IMC_STATE_NONE, 0}

};
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

#elif defined(__MMI_IME_SMART_WITH_INPUT_AREA__)

static mmi_imc_fsm_struct g_ime_state_set[] = 
{
    {MMI_IMC_STATE_INITIAL, 0},
    
	{MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP, 0},
    
    {MMI_IMC_STATE_SPELL_INPUTING,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_CAND_SELECTING,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_ASSOC_SELECTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_PRE_ASSOC_SELECTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_PREDICTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},


    {MMI_IMC_STATE_SMART_CANDIDATE, MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC, MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_PRE_SMART_CANDIDATE, MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_INPUT, MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)}, /* focus on input area */

    {MMI_IMC_STATE_SPELL_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_SPELL_WITH_INPUT, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},

    {MMI_IMC_STATE_CAND_SELECT_WITH_INPUT, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},

    {MMI_IMC_STATE_NEW_WORD_INITIAL, MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},
    
    {MMI_IMC_STATE_NEW_WORD_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},

#ifdef __MMI_CLIPBOARD__
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT, 0},
#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU)},
#else
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN, 0},
#endif
    {MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS, 0},

    {MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU)},
#endif /* __MMI_CLIPBOARD__ */

    {MMI_IMC_STATE_NONE, 0}
    
};

#else

static mmi_imc_fsm_struct g_ime_state_set[] = 
{
    {MMI_IMC_STATE_INITIAL, 0},
    
    {MMI_IMC_STATE_WORD_HIGHLIGHTED, 0},
    
	{MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP, 0},
    
    {MMI_IMC_STATE_SPELL_INPUTING,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_CAND_SELECTING,  MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_ASSOC_SELECTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_PREDICTING, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},


    {MMI_IMC_STATE_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},


    {MMI_IMC_STATE_SMART_CANDIDATE, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC, MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_SPELL_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)},

    {MMI_IMC_STATE_NEW_WORD_INITIAL, MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},
   
    {MMI_IMC_STATE_NEW_WORD_MULTITAP, MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)},

#ifdef __MMI_CLIPBOARD__
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT, 0},

#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU)},
#else
    {MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN, 0},
#endif
    {MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS, 0},

    {MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU, MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU)},
#endif /* __MMI_CLIPBOARD__ */

    {MMI_IMC_STATE_NONE, 0}
};

#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_CLIPBOARD__
static MMI_BOOL mmi_imc_clipboard_is_empty(void);
static MMI_BOOL mmi_imc_clipboard_is_text_highlight(void);
static MMI_BOOL mmi_imc_clipboard_is_editor_empty(void);
static MMI_BOOL mmi_imc_clipboard_is_editor_WCSS(void);
static MMI_BOOL mmi_imc_clipboard_is_editor_password(void);
static void mmi_imc_clipboard_close_cascading_option_menu(void);
#endif /* __MMI_CLIPBOARD__ */

static void mmi_imc_save_editor_history_data(void);

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
static MMI_BOOL mmi_imc_check_floating_ui_cover_ime_indicator(void);
#endif
#if 1
static MMI_BOOL mmi_imc_check_ui_cover_ime_indicator(void);
#endif
static MMI_BOOL g_mmi_imc_is_rotated = MMI_FALSE;

static MMI_BOOL g_mmi_imc_is_java_special_symbol_enabled = MMI_FALSE;

static MMI_BOOL g_mmi_imc_is_disable_candidate_box = MMI_FALSE;
static void mmi_imc_draw_vk_when_curser_movement(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_state
 * DESCRIPTION
 *  Get current stste
 * PARAMETERS
 *  void
 * RETURNS
 *  Current state
 *****************************************************************************/
mmi_imc_state_enum  mmi_imc_get_state( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( MMI_FALSE == g_imc.is_inited )
        return MMI_IMC_STATE_NONE;

    return g_imc.fsm_object.curr_state;
}
/*****************************************************************************
* FUNCTION
* mmi_imc_get_state_imui_set
* DESCRIPTION
*  Get current stste
* PARAMETERS
*  void
* RETURNS
*  Current state
*****************************************************************************/
U32 mmi_imc_get_state_imui_set(mmi_imc_state_enum state)
{
        S32 i = 0;
		while(g_ime_state_set[i].curr_state != MMI_IMC_STATE_NONE)
        {
                      if (g_ime_state_set[i].curr_state == state)
                      {
                             break;
                      }
                      i++;
         }
         return g_ime_state_set[i].imui_set;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_state
 * DESCRIPTION
 *  Set current stste
 * PARAMETERS
 *  state    [IN]    State
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_imc_set_state( mmi_imc_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct imc_msg;
    mmi_imc_state_enum pre_state;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_state_enum pre_custom_state;
    mmi_ime_sdk_state_enum current_custom_state;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_is_ime_connected)
    {
        return;
    }

    pre_state = g_imc.fsm_object.curr_state;
    g_pre_state = g_imc.fsm_object.curr_state;
	g_imc.fsm_object.curr_state = state;
#ifdef __MMI_IME_PLUG_IN__  
    if (pre_state == MMI_IMC_STATE_INITIAL)
    {
        pre_custom_state = MMI_IME_SDK_STATE_INITIAL;
    }
    else if (mmi_imc_is_in_custom_state(pre_state))
    {
        pre_custom_state = (mmi_ime_sdk_state_enum)pre_state;
    }
    else
    {
        pre_custom_state = MMI_IME_SDK_STATE_MTK;
    }

    if (state == MMI_IMC_STATE_INITIAL)
    {
        current_custom_state = MMI_IME_SDK_STATE_INITIAL;
    }
    else if (mmi_imc_is_in_custom_state(state))
    {
        current_custom_state = (mmi_ime_sdk_state_enum)state;
    }
    else
    {
        current_custom_state = MMI_IME_SDK_STATE_MTK;
    }
    
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_STATE_CHANGED, (U32)pre_custom_state, (U32)current_custom_state);
#endif
    /* set key handler by state */
    mmi_imc_key_set_softkey();
    
    if (pre_state != state && state == MMI_IMC_STATE_INITIAL)
    {
    #if defined(__MMI_IME_MAGIC_ONE__)
        if (g_is_magic_state)
            mmi_imc_back_from_magic_state();
    #endif
    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
    #endif

        if (!g_imc_disable_draw)
        {
            mmi_imc_reset_global_data();
        #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
            mmi_imc_reset_input_area();
            mmi_imc_reset_key_seq_data();
        #endif
        }
        imc_msg.message_id = MMI_IMC_MESSAGE_CHANGE_TO_INITIAL;
        mmi_imc_send_message(&imc_msg);

        if (pre_state == MMI_IMC_STATE_SMART_CANDIDATE
            || pre_state == MMI_IMC_STATE_HAND_WRITING_CAND
            || pre_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
            || pre_state == MMI_IMC_STATE_WORD_HIGHLIGHTED)
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
            mmi_imc_send_message(&imc_msg);
        }

    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        if (mmi_imm_is_auto_capitalization_valid())
        {
            if (!mmi_imm_is_curr_capital_state_of_curr_input_mode())
            {
                mmi_imc_change_input_mode_according_to_capital_state(g_imc.global_data.capital_state);
            #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                {
                    mmi_imui_message_struct imui_msg;
                    imui_msg.message_id = MMI_IMUI_MESSAGE_INVALIDATE_VK;
                    mmi_imui_send_message(&imui_msg, NULL);
                }
            #endif
            }
            else
            /* avoid cursor move hanlder been call two times when vk's caps key be pressed*/
#if defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
            if (!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
#endif
            {
                mmi_event_struct evt;

                MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);
                
                MMI_FRM_CB_EMIT_EVENT(&evt);
            }
        }
    #endif
    }
    else if (pre_state != state && (pre_state == MMI_IMC_STATE_SMART_CANDIDATE || pre_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC || pre_state == MMI_IMC_STATE_HAND_WRITING_CAND))
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
        mmi_imc_send_message(&imc_msg);
    }
#ifdef __MMI_CLIPBOARD__ 
    else if (mmi_imc_is_clipboard_state())
    {
        if (mmi_imc_key_get_pre_key_handler() != mmi_imc_key_clipboard_pre_key_handler)
        {
            g_imc_app_pre_key_hander = mmi_imc_key_get_pre_key_handler();
            mmi_imc_key_set_pre_key_handler(mmi_imc_key_clipboard_pre_key_handler);
        }
    }
#endif /* __MMI_CLIPBOARD__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_state_from_grid_to_initial
 * DESCRIPTION
 *  change state from grid to be initial, and show the vk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_change_state_from_grid_to_initial(void)
{
#if defined(__MMI_IME_CANDIDATE_GRID__)
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
	mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	mmi_imc_redraw_screen_by_state();
#endif
}

#if defined(__MMI_IME_CANDIDATE_GRID__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_state_acc_to_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_imc_set_state_acc_to_mode(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_VIRTUAL_KEYBOARD__)
	if(mmi_imc_pen_is_handwriting_vk())
	{
		mmi_imc_delete_timer();
		mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX);
		#if !defined(__NO_HANDWRITING__)

        if (mmi_imc_get_single_block_handwriting_state())
        {
            mmi_imc_pen_stop_singleblock_handwriting();
        }
		#endif /* !defined(__NO_HANDWRITING__) */
		return;
	}
	#endif

	 switch(mmi_imm_get_curr_input_mode())
	{
	case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
	case IMM_INPUT_MODE_SM_PINYIN:
		   if(g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING)
		   {
			   mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING_GRID);
		   }
		   else
		   {
			mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING_GRID);
		   }
			break;
	case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
	case IMM_INPUT_MODE_TR_BOPOMO:

			if(g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING)
		   {
			    mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING_GRID);
		   }
		   else
		   {
				mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID);
		   }
		break;
	case IMM_INPUT_MODE_SM_STROKE:
	case IMM_INPUT_MODE_TR_STROKE:
	case IMM_INPUT_MODE_HK_STROKE:
			if(g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING)
		   {
			    mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING_GRID);
		   }
		   else
		   {
				mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID);
		   }
		break;
	default:
		//alphabetic mode related to english and other languages
       mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC);
		break;
	}
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_init_all
 * DESCRIPTION
 *  Initialize IME when booting up
 * PARAMETERS
 *  void
 * RETURNS
 *  Successfully or not
 *****************************************************************************/
MMI_BOOL mmi_imc_init_all( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    ret_val;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ( MMI_FALSE != g_imc.is_inited )
        return MMI_TRUE;
    
#ifdef __MMI_PREFER_INPUT_METHOD__
    mmi_imm_get_prefer_input_mode_list(MMI_all_prefered_input_mode_set, IMM_INPUT_MODE_MAX_NUM);
#endif

    
    memset( &g_imc, 0x0, sizeof(mmi_imc_object_struct) );
    g_imc.fsm_object.curr_state      = MMI_IMC_STATE_NONE;

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)	
 
    ret_val = mmi_ime_multitap_init();
    if ( ret_val == MMI_FALSE )
    {
        /* add error */
        //goto WHEN_FAILED;
        ASSERT(0);
    }

#endif

    ret_val = mmi_ime_word_init();
    if ( ret_val == MMI_FALSE )
    {
        /* add error */
        //goto WHEN_FAILED;
        ASSERT(0);
    }
    
    ret_val = mmi_imm_init();
    if ( ret_val == MMI_FALSE )
    {
        /* add error */
        goto WHEN_FAILED;
    }
    #ifdef __MMI_PREFER_INPUT_METHOD__
    mmi_imm_get_prefer_input_mode_list(MMI_all_prefered_input_mode_set, IMM_INPUT_MODE_MAX_NUM);
#endif
    ret_val = mmi_imc_key_init();
    if ( ret_val == MMI_FALSE )
    {
        /* add error */
        goto WHEN_FAILED;
    }

#if defined(__MMI_TOUCH_SCREEN__)
    ret_val = mmi_imc_pen_init();
    if ( ret_val == MMI_FALSE )
    {
        /* add error */
        goto WHEN_FAILED;
    }
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */


#if defined(__MMI_IME_PLUG_IN__)
    ret_val = mmi_ime_sdk_init();
    if ( ret_val == MMI_FALSE )
    {
        /* add error */
        goto WHEN_FAILED;
    }
#endif /* defined(__MMI_IME_PLUG_IN__) */


    if ( ret_val == MMI_IMUI_RESULT_FALSE )
    {
        /* add error */
        goto WHEN_FAILED;
    }
    mmi_imm_set_required_mode_list(0, (mmi_imm_input_mode_enum)NULL, (mmi_imm_input_mode_enum)0 );
    
    g_imc.is_inited = MMI_TRUE;
#if defined(__MMI_IME_MAGIC_ONE__)
    g_magic_key_down = MMI_FALSE;
    g_is_magic_state = MMI_FALSE;
#endif
    return MMI_TRUE;

WHEN_FAILED:
#if defined(__MMI_IME_PLUG_IN__)
        mmi_ime_sdk_deinit();
#endif /* defined(__MMI_IME_PLUG_IN__) */

#if defined(__MMI_TOUCH_SCREEN__)
    mmi_imc_pen_deinit();
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */
    mmi_imc_key_deinit();
    mmi_ime_word_deinit();

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    mmi_ime_multitap_deinit();
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  InitIME
 * DESCRIPTION
 *  To Initialize IME,
 *  
 *  This is used to To Initialize IME,.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitIME(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_init_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_deinit_all
 * DESCRIPTION
 *  Deinit IME
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_deinit_all( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( MMI_FALSE != g_imc.is_inited )
    {
        //mmi_imm_set_required_mode_list( NULL, 0 );

#if defined(__MMI_TOUCH_SCREEN__)
        mmi_imc_pen_deinit();
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */

        mmi_imc_key_deinit();

        mmi_ime_word_deinit();
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) ||defined __MMI_COSMOS_KEYPAD_SLIDER__
        mmi_ime_multitap_deinit();
    #endif
    }
}

MMI_BOOL mmi_imc_get_draw(void)
{    
    return g_imc_disable_draw;
}

void mmi_imc_config_draw(MMI_BOOL draw)
{    
    g_imc_disable_draw = draw;
}


#if defined (__MMI_IME_V3__)
void mmi_imc_init_select_mode_list_index(void)
{
    mmi_imm_input_mode_enum     input_mode;
    const sIMEModeDetails       *input_mode_detail, *input_mode_in_list_detail;   
    U32                         i;

    input_mode = mmi_imm_get_current_input_mode();
    input_mode_detail = mmi_imm_get_input_mode_array_item(input_mode);

    if (mmi_imm_get_keyboard_type() == IMM_KEYPAD_HANDWRITING)
    {
        for (i = 0; i < MMI_IMC_SELECT_LIST_ITEM_NUM_MAX; i++)
        {
            if (g_imc_selection_list_mode_array[i] == IMM_INPUT_MODE_NONE)
            {
                g_imc_current_input_mode_in_list = i;
                return;
            }
        }
    }
    if (mmi_imm_is_chinese_input_method(input_mode))
    {
        for (i = 0; i < MMI_IMC_SELECT_LIST_ITEM_NUM_MAX; i++)
        {
            if( input_mode == g_imc_selection_list_mode_array[i])
            {
                g_imc_current_input_mode_in_list = i;
                return;
            }
        }
    }
    
    for (i = 0; i < MMI_IMC_SELECT_LIST_ITEM_NUM_MAX; i++)
    {
        input_mode_in_list_detail = mmi_imm_get_input_mode_array_item(g_imc_selection_list_mode_array[i]);
		if(input_mode_in_list_detail != NULL)
		{
			if (input_mode_in_list_detail->lang_id == input_mode_detail->lang_id)
			{
				g_imc_current_input_mode_in_list = i;
				return;
			}
		}
		else
		{
			g_imc_current_input_mode_in_list = 0;
		}
    }
    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_connect
 * DESCRIPTION
 *  Connect IME
 * PARAMETERS
 *  handle        [IN]    The handle of caller
 *  msg_callback  [IN]    Message call back function pointer
 * RETURNS
 *  Connect IME successfully or not
 *****************************************************************************/
MMI_BOOL mmi_imc_connect( void *handle, mmi_imc_message_funcptr msg_callback )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imc_message_struct imc_msg = {0};
    U32 sub_lang = IME_WRITING_LANG_NONE;
    gui_evt_inputs_cursor_changed_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMC_CONNECT);
#if defined(__IMEHW_DCM_SUPPORT__)
		if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_IME) == MMI_FALSE)
		{
				DCM_Load(DYNAMIC_CODE_COMPRESS_IME, NULL, NULL);
		}
		
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
    if(!DCM_Isloaded(DYNAMIC_CODE_COMPRESS_VKLAYOUT))
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_VKLAYOUT, NULL, NULL);
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMC_DCM_LOAD_VK_LAYOUT, keyBoardTable);
        wgui_virtual_keyboard_layout_list = keyBoardTable;
    }
#endif

#endif//#if defined(__IMEHW_DCM_SUPPORT__)
    g_imc_disable_draw = MMI_FALSE;

    g_imc_ui_style.force_style = 0;
    g_imc_ui_style.force_style_flag = 0;
    g_imc_ui_style.style = 0;
    g_imc_ui_style.is_clean_force_style_flag_allowed = MMI_TRUE;


    if ( MMI_FALSE == g_imc.is_inited )
        return MMI_FALSE;
    /* 
     * Because we can't make sure whether editor would post the cursor movement 
     * event to IME, to make sure there is always a event when entering a editor,
     * so we should always post a event by ourselves, and skip it by checking
     * g_imc_skip_first_cursor_movement_event, so this is a tricky way to make
     * the behavior consistent
     */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_GUI_INPUTS_CURSOR_CHANGED);
    evt.cursor_pos = 0;
    if (!mmi_frm_is_event_posted((mmi_event_struct*)&evt))
    {
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }
    


#if defined(__MMI_TOUCH_SCREEN__)
    g_mmi_imc_is_invalid_hw_type = MMI_FALSE;
#endif
    if (mmi_imm_test_reset_allowed_and_disabled_list())
        mmi_imm_reset_allowed_and_disabled_list();
#ifdef __MMI_TOUCH_SCREEN__
	if(mmi_imm_test_reset_allowed_and_disabled_list_vk())
		 mmi_imm_reset_allowed_and_disabled_list_vk();
#endif    
    if ( NULL != g_imc.editor_handle )
    {
        /* already connected to an editor*/
		mmi_imc_disconnect();/* May be discussed */
        //return MMI_FALSE;
    }

	g_is_ime_connected = MMI_TRUE;
    g_imc_background_filler = NULL;

    g_imc.editor_handle = handle;
    g_imc.message_proc  = msg_callback;

    memset( &(g_imc.global_data), 0x0, sizeof(mmi_imc_global_data_struct) );

    g_imc.fsm_object.curr_state = MMI_IMC_STATE_INITIAL;
    g_imc.fsm_object.imui_set = 0;
    
    mmi_imc_check_rotation();

#ifdef __MMI_CLIPBOARD__
    if (g_imc_clipboard_data.is_saved && g_imc_clipboard_data.close_flag)
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_RESTORE_STATUS;
        imc_msg.param_0 = (U32)&g_imc_clipboard_data;
        mmi_imc_send_message(&imc_msg);
        g_imc_clipboard_data.is_saved = 0;
        g_imc_clipboard_data.close_flag = 0;
    }
    else if (g_imc_clipboard_data.is_saved)
    {
        memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
    }
#endif /* __MMI_CLIPBOARD__ */


    mmi_imm_connect();
#if defined(__MMI_IME_V3__)
    mmi_imc_init_select_mode_list_index();
#endif
    imui_msg.message_id = MMI_IMUI_MESSAGE_INIT_UI;
    mmi_imui_send_message(&imui_msg, NULL);

#if defined(__MMI_VUI_ENGINE__)
    //if (!vadp_p2v_uc_is_in_venus())
#endif
    {
        mmi_imc_create_imui_controls();
    }

#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_EDITOR_CONNECTED, 0, 0);
#endif

#if defined(__MMI_MIXED_LANG_SUPPORT__)
    sub_lang = mmi_imm_get_sub_lang();
#endif

	g_imc.mode_details_ptr = NULL;
    #if defined(__MMI_VIRTUAL_KEYBOARD__) 
	mmi_imc_pen_set_vk_at_start();
    #endif
	mmi_imc_change_input_mode(mmi_imm_get_curr_input_mode(), sub_lang);   

    if (!g_is_key_disabled)
    {
        mmi_imc_key_activate();
    }

#if defined(__MMI_IME_FTE_ENHANCE__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (g_imc.history.is_vk_on)
    {
        mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
    }
#endif
#endif
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_imc_pen_activate();
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */
    
    wgui_icon_bar_register_pause_interactive_UI_callback(mmi_imc_icon_bar_pause_interactive_ui_callback);
    
#if defined(__MMI_TOUCH_SCREEN__)
    RedrawSpellingOrCandidateBoxesFunction = NULL;
#else
    RedrawSpellingOrCandidateBoxesFunction = mmi_imc_redraw_screen_by_state;
#endif
    if (wgui_register_multiline_inputbox_up_down_key_handler != NULL)
    {
        wgui_register_multiline_inputbox_up_down_key_handler();
    }

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    g_imc.global_data.dead_char = 0;
    g_imc_backup_tone_mode = mmi_frm_get_dial_key_tone_type();
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_NORMAL);
#endif

#if defined(__MMI_TOUCH_SCREEN__)
    /* for non-category screen pen event routing */
#if defined(__MMI_VUI_ENGINE__)
    if (!vadp_p2v_uc_is_in_venus())
#endif    
    {
    wgui_register_search_control_set_callback_function(mmi_imc_get_ime_screen_general_ui_control_set);
    }
#endif

	mmi_imm_set_history_input_mode(IMM_INPUT_MODE_NONE);

    g_imc_is_editor_ready_when_connecting = MMI_TRUE;
    //[MRE_Editor]send active message to editor when connected
    imc_msg.message_id = MMI_IMC_MESSAGE_ACTIVATE;
    mmi_imc_send_message(&imc_msg);    



    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_skip_first_cursor_movement_event
 * DESCRIPTION
 * PARAMETERS
 *  is_skip
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_skip_first_cursor_movement_event(MMI_BOOL is_skip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    g_imc_skip_first_cursor_movement_event = is_skip;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_icon_bar_pause_interactive_ui_callback
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imc_icon_bar_pause_interactive_ui_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    mmi_imc_message_struct imc_msg;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_reset_ime_state();

    /* 
     * Because icon bar require the interactive UIs (scrolling text, cursor) to be 
     * stopped, and after mmi_imc_reset_ime_state(), the interactive UIs maybe
     * restarted, so we should stopped the UIs once more
     */

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    imc_msg.message_id = MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION;
    mmi_imc_send_message(&imc_msg);
#endif

    UI_inputbox_stop_cursor(0, 0, UI_device_width - 1, UI_device_height -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_check_multitap_state
 * DESCRIPTION
 *  to resotre multitap state or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_imc_check_multitap_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disconnect
 * DESCRIPTION
 *  Disconnect IME and caller
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_disconnect( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imc_message_struct imc_msg;
	U16 current_key_code;
	U16 current_key_type;
    MMI_BOOL is_multitap = MMI_FALSE;
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__IMEHW_DCM_SUPPORT__)
		if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_IME))
		{
				DCM_Unload(DYNAMIC_CODE_COMPRESS_IME);
		}
		
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
	if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_VKLAYOUT))
	{
        DCM_Unload(DYNAMIC_CODE_COMPRESS_VKLAYOUT);
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMC_DCM_UNLOAD_VK_LAYOUT);
		
	}
	wgui_virtual_keyboard_layout_list = NULL;
#endif

#if defined(__MMI_GUOBI_HW__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
	if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_GUOBIHW))
	{
        DCM_Unload(DYNAMIC_CODE_COMPRESS_GUOBIHW);
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMC_DCM_UNLOAD_HW);
	}
#endif
#endif//#if defined(__IMEHW_DCM_SUPPORT__)

#ifdef __MMI_CLIPBOARD__ 
    g_imc_clipboard_key_is_saved = MMI_FALSE;
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    wgui_virtual_keyboard_clear_cache_on_imc_disconnect();
#endif 

    if (!g_is_ime_connected)
    {
        return;
    }
    #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    g_is_ime_disconnecting = MMI_TRUE;
    #endif

#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_EDITOR_DISCONNECTING, 0, 0);
#endif    

    mmi_imc_save_editor_history_data();

    if ( MMI_FALSE != g_imc.is_inited )
    {
        g_imc_enable_csk = MMI_TRUE;
        if ( (g_imc.fsm_object.curr_state == MMI_IMC_STATE_HAND_WRITING_CAND) || (g_imc.fsm_object.curr_state == MMI_IMC_STATE_HAND_WRITING) )
        {
            if (g_timer_cancel_callback != NULL) 
			{
				wgui_hide_left_softkey();
				mmi_imc_cancel_timer();
			}
			else
			{
					#ifdef __MMI_TOUCH_SCREEN__
				mmi_imc_pen_confirm_handwriting_selection();
					#endif 
			}
        }
        else if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_SMART_CANDIDATE
                    || g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
					|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC)
        {
            if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
            {
            mmi_imc_key_smart_alphabetic_confirm_candidate();
            imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
            mmi_imc_send_message(&imc_msg);
            }
        } 
        else if(g_imc.fsm_object.curr_state == MMI_IMC_STATE_PASSWORD_PREVIEW) 
        {
            if (g_timer_cancel_callback != NULL) 
	{
            mmi_imc_cancel_timer();
        }
}
        else
        { 
            mmi_imc_delete_timer();
        } 
        
    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        if (mmi_imm_is_auto_capitalization_valid())
        {
            if (!mmi_imm_is_curr_capital_state_of_curr_input_mode())
            {
                g_imc.global_data.capital_state = mmi_imc_get_candidate_case_before_cursor();
                mmi_imc_change_input_mode_according_to_capital_state(g_imc.global_data.capital_state);
            }
        }
    #endif    
        
        mmi_imc_key_deactivate();
    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_imc_pen_deactivate();
    #endif /* #if defined(__MMI_TOUCH_SCREEN__) */

    #if defined(__MMI_VIRTUAL_KEYBOARD__)
        g_imc.history.vk_type = mmi_imc_get_current_vk_type();
    #if defined(__MMI_IME_FTE_ENHANCE__) 
        g_imc.history.is_vk_on = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
    #endif /* defined(__MMI_IME_FTE_ENHANCE__)  */
    #endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */


        if (g_imc.fsm_object.curr_state != MMI_IMC_STATE_NONE)
        {
            mmi_imc_gdi_lcd_freeze(TRUE);
            
            imc_msg.message_id = MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE;
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                is_multitap = (MMI_BOOL)mmi_imc_send_message(&imc_msg);
                
                if (is_multitap)
                {
                    imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;

                    if (mmi_imc_send_message(&imc_msg))
                    {
                        is_multitap = MMI_FALSE;
                    }
                }
                
                if (!is_multitap)
                {
                    g_imc.fsm_object.curr_state = MMI_IMC_STATE_INITIAL;

                }
                imc_msg.message_id = MMI_IMC_MESSAGE_RESET_MULTITAP_STATE;
                mmi_imc_send_message(&imc_msg);
                mmi_imc_delete_timer();
            }
            else if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_SMART_CANDIDATE
                     || g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
                mmi_imc_send_message(&imc_msg);
            }     
            
            mmi_imc_gdi_lcd_freeze(gdi_freeze);; 


        #if defined(__MMI_IME_USER_DATABASE__)
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_NEW_WORD_MULTITAP)
            {
                mmi_imc_delete_timer();
            }
       #endif  

            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP)
            {
                GetkeyInfo(&current_key_code, &current_key_type);

                if (mmi_imc_key_get_last_imc_key_code() != current_key_code)
                {
                    g_imc.history.state = MMI_IMC_STATE_NONE;
                }
                else
                {
                    g_imc.history.state = g_imc.fsm_object.curr_state;     
                } 
            }
            else
            {
                g_imc.history.state = g_imc.fsm_object.curr_state;     
            }                
            g_imc.fsm_object.curr_state = MMI_IMC_STATE_NONE;
        }
        
        imc_msg.message_id = MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW;
        imc_msg.param_0 = MMI_TRUE;
        mmi_imc_send_message(&imc_msg);
        
        //[MRE_Editor]send deactive message to app when disconnected
        imc_msg.message_id = MMI_IMC_MESSAGE_DEACTIVATE;
        mmi_imc_send_message(&imc_msg);


//        imui_msg.message_id = MMI_IMUI_MESSAGE_EXIT;
     //   mmi_imui_send_message(&imui_msg, NULL);

        mmi_imc_delete_timer();

        g_imc.editor_handle         = NULL;
        g_imc.message_proc          = NULL;
        RedrawSpellingOrCandidateBoxesFunction = NULL;
    }

#if defined(__MMI_TOUCH_SCREEN__)
    mmi_imm_config_handwriting_setting((MMI_BOOL)!g_is_handwriting_disabled);
    g_is_handwriting_disabled = MMI_FALSE;
    g_is_vk_disabled = MMI_FALSE;
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */
#if defined(__MMI_IME_MAGIC_ONE__)
    g_magic_key_down = MMI_FALSE;
    g_is_magic_state = MMI_FALSE;
#endif
    g_is_fixed_input_box = MMI_FALSE;
#if defined(__MMI_IME_FTE_ENHANCE__)
    g_imc_single_block_hw_state = MMI_FALSE;
#endif
    g_is_key_disabled = MMI_FALSE;
    g_is_pen_disabled = MMI_FALSE;
    g_is_symbol_picker_disable = MMI_FALSE;
    mmi_imm_set_allowed_and_disabled_list(MMI_FALSE);
	#ifdef __MMI_TOUCH_SCREEN__
    mmi_imm_set_allowed_and_disabled_list_vk(MMI_FALSE);
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    g_imc.global_data.capital_lock = MMI_FALSE;
#endif

    mmi_imm_config_change_input_mode(MMI_TRUE);
    mmi_imm_disconnect();
    g_imc_disable_draw = MMI_FALSE;
    g_imc_background_filler = NULL;

#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_EDITOR_DISCONNECTED, 0, 0);
#endif

#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_search_control_set_callback_function(NULL);
#endif

    g_imc_softkey_background_filler = NULL;

    if (g_imc_backup_softkey_hide_fptr != NULL)
    {
        wgui_softkey_set_hide_func_ptr(g_imc_backup_softkey_hide_fptr);
        g_imc_backup_softkey_hide_fptr = NULL;
    }

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {

    mmi_frm_set_dial_key_tone_type(g_imc_backup_tone_mode);
    g_imc_backup_tone_mode = MMI_DIALER_KEY_TONE_NORMAL;
    }
#endif

	g_is_ime_connected = MMI_FALSE;
	#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    g_is_ime_disconnecting = MMI_FALSE;
    #endif
    imui_msg.message_id = MMI_IMUI_MESSAGE_EXIT;
    mmi_imui_send_message(&imui_msg, NULL);

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_LEFT_SOFTKEY);
    set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_RIGHT_SOFTKEY);
    enable_softkey_background();
    wgui_icon_bar_set_flags_off(GUI_ICON_BAR_FLAG_DISABLE_DISPLAY);
#endif

#if defined(__ATV_SMS_SUPPORT__)
    g_is_in_atv_editor = MMI_FALSE;
    g_floating_state_configured_by_app = MMI_FALSE;
#endif /* defined(__ATV_SMS_SUPPORT__) */
    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    g_imc_skip_first_cursor_movement_event = MMI_FALSE;
    #endif
    mmi_imc_set_is_rotated(MMI_FALSE);
	mmi_imc_set_is_disable_candidate_box(MMI_FALSE);
#if defined(__MMI_IME_CANDIDATE_GRID__)
    if(g_imc_is_change_from_grid == MMI_TRUE)
    {
        g_imc_is_change_from_grid = MMI_FALSE;	 
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_connected
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_imc_is_connected( void )
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_is_ime_connected;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_exit_screen
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* This function will be called when is exiting every screen   */
	/* So we must judge whether this screen is input method screen */
    if (g_has_entered_ime_screen)
    {
    #if defined(__MMI_IME_USER_DATABASE__)
    	mmi_ime_word_save_user_database();
    #endif

        mmi_imui_exit_screen();
    
        g_has_entered_ime_screen = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_draw_input_mode_infor
 * DESCRIPTION
 *  Draw input method information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void     mmi_imc_draw_input_mode_infor(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imc_rect infor_rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infor_rect.x = x1;
    infor_rect.y = y1;
    infor_rect.width = x2 - x1 + 1;
    infor_rect.height = y2 - y1 + 1;
    
    imui_msg.message_id = MMI_IMUI_MESSAGE_DRAW_INFORMATION_BAR;
    imui_msg.param_0 = (U32)&infor_rect;
    mmi_imui_send_message(&imui_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_ime_infor_width
 * DESCRIPTION
 *  Get input method information width
 * PARAMETERS
 *  void
 * RETURNS
 *  Input method information width
 *****************************************************************************/
U32  mmi_imc_get_ime_infor_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id = MMI_IMUI_MESSAGE_GET_IME_INFOR_WIDTH;
    
    return mmi_imui_send_message(&imui_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_draw_input_mode_hint
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_draw_input_mode_hint(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imc_rect hint_rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_imc_get_input_mode_hint_width() > 0)
    {
		hint_rect.x = x1;
		hint_rect.y = y1;
		hint_rect.width = x2 - x1 + 1;
		hint_rect.height = y2 - y1 + 1;
    
		imui_msg.message_id = MMI_IMUI_MESSAGE_DRAW_IME_HINT;
		imui_msg.param_0 = (U32)&hint_rect;
		mmi_imui_send_message(&imui_msg, NULL);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_input_mode_hint_height
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_imc_get_input_mode_hint_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imc_is_connected())
    {
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_GET_IME_HINT_HEIGHT;
    
            return mmi_imui_send_message(&imui_msg, NULL);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_input_mode_hint_width
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_imc_get_input_mode_hint_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imc_is_connected())
    {
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_GET_IME_HINT_WIDTH;
    
            return mmi_imui_send_message(&imui_msg, NULL);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_ime_indicator
 * DESCRIPTION
 *  Redraw IME indicator, including information bar, input mode hint and IME 
 *  indicator on status icon bar
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_redraw_ime_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
#if defined(__MMI_VUI_ENGINE__)
    if (!vadp_p2v_uc_is_in_venus())
#endif    
    {
        if (mmi_imc_check_floating_ui_cover_ime_indicator())
        {
            return;
        }
    }
#endif

    imui_msg.message_id = MMI_IMUI_MESSAGE_REDRAW;

    imui_msg.param_0 = (MMI_IMUI_CONTROL_MASK(MMI_IMUI_INFORMATION_BAR) | 
                        MMI_IMUI_CONTROL_MASK(MMI_IMUI_IME_INDICATOR_AREA) | 
                        MMI_IMUI_CONTROL_MASK(MMI_IMUI_IME_HINT_AREA));



    mmi_imui_send_message(&imui_msg, NULL);
}
    #if defined(__MMI_IME_USER_DATABASE__)
S32 mmi_imc_new_word_str_len()
{
	return g_imc.global_data.char_index;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_send_message
 * DESCRIPTION
 *  Send message to editor
 * PARAMETERS
 *  msg_ptr    [IN]    Message structure
 * RETURNS
 *  The return value
 *****************************************************************************/
U32 mmi_imc_send_message( mmi_imc_message_struct_p msg_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    UI_character_type char_code;
    mmi_imc_message_struct imc_msg;
    UI_character_type pre_char;
    S32 str_len;
    UI_buffer_type start_p = NULL, end_p = NULL;
    BOOL gdi_freeze = gdi_lcd_get_freeze();
#endif
    U32 cur_input_type = mmi_imm_get_curr_input_type();
    U32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( NULL == msg_ptr )
        return 0;

    if ( NULL == g_imc.editor_handle || NULL == g_imc.message_proc )
        return 0;
/* TO make sure while entering new word multitap is set according to content of new word window*/
    #if defined(__MMI_IME_USER_DATABASE__)
    if (msg_ptr->message_id == MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE && (g_imc.fsm_object.curr_state == MMI_IMC_STATE_NEW_WORD_INITIAL || g_imc.fsm_object.curr_state == MMI_IMC_STATE_NEW_WORD_MULTITAP))
    {
        UI_string_type buf = (UI_string_type)msg_ptr->param_1;
        
        if (g_imc.global_data.char_index < (U32)msg_ptr->param_0)
        {
            buf = NULL;
            return 0;
        }
        else
        {
            U32 i,j;
            for (i = (U32)msg_ptr->param_0,j =0 ; i != 0;i--,j++)
            {
                buf[j] = g_imc.global_data.new_word[g_imc.global_data.char_index- i];
            }
            return msg_ptr->param_0;
        }
    }
    #endif

    if ( msg_ptr->message_id == MMI_IMC_MESSAGE_INSERT_CHAR)
    {
        if ((msg_ptr->param_0 == (U32)'.') && 
            ((cur_input_type & IMM_INPUT_TYPE_DECIMAL_NUMERIC) || 
             (cur_input_type & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)))
        {
            msg_ptr->message_id = MMI_IMC_MESSAGE_INSERT_DECIMAL_SYMBOL;
            mmi_imc_print_string_inserted_to_editor((UI_string_type)L".", 1);
        }
        
    #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    #if defined(__MMI_VIRTUAL_KEYBOARD__)
     if(mmi_imc_pen_is_symbol_vk_type(mmi_imc_get_current_vk_type()) == MMI_FALSE) 
    #endif
     {
        if (mmi_imm_is_dead_character_of_current_lang((UI_character_type)msg_ptr->param_0))
        {
            g_imc.global_data.dead_char = (UI_character_type)msg_ptr->param_0;
            return MMI_TRUE;
        }
        else
        {
            if (g_imc.global_data.dead_char != 0)
            {
                char_code = mmi_imm_get_merged_character_of_current_lang(g_imc.global_data.dead_char, (UI_character_type)msg_ptr->param_0);

                if (char_code != 0)
                {
                    msg_ptr->param_0 = char_code;
                }

                g_imc.global_data.dead_char = 0;
            }
        }
    }
    #endif
    }
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    else if (msg_ptr->message_id == MMI_IMC_MESSAGE_INSERT_STRING)
    {
        if (mmi_ucs2strlen((const S8 *)msg_ptr->param_0) == 1)
        {
            if (g_imc.fsm_object.curr_state != MMI_IMC_STATE_HAND_WRITING
                && g_imc.fsm_object.curr_state != MMI_IMC_STATE_HAND_WRITING_CAND)
            {
                if (mmi_imm_is_dead_character_of_current_lang(*((UI_character_type *)msg_ptr->param_0)))
                {
                    g_imc.global_data.dead_char = *((UI_character_type *)msg_ptr->param_0);
                    return 1;
                }
                else if (g_imc.global_data.dead_char != 0)
                {
                    char_code = mmi_imm_get_merged_character_of_current_lang(g_imc.global_data.dead_char, *((UI_character_type *)msg_ptr->param_0));

                    if (char_code != 0)
                    {
                        *((UI_character_type *)msg_ptr->param_0) = char_code;
                    }
                }

                g_imc.global_data.dead_char = 0;
            }
        #if defined(__MMI_TOUCH_SCREEN__)
            else
            {
                if (g_imc.global_data.dead_char != 0)
                {
                    char_code = mmi_imm_get_merged_character_of_current_lang(g_imc.global_data.dead_char, *((UI_character_type *)msg_ptr->param_0));

                    if (char_code != 0)
                    {
                        imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_CHAR;
                        imc_msg.param_0 = char_code;
                        
                        if (g_imc.message_proc( g_imc.editor_handle, &imc_msg ))
                        {
                            mmi_imc_print_string_inserted_to_editor((UI_string_type)&char_code, 1);
                        }

                        return 1;
                    }
                }
            }
        #endif
        }
        else
        {
            g_imc.global_data.dead_char = 0;
        }    
    }
    else if (msg_ptr->message_id == MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        if (mmi_ucs2strlen((const S8 *)msg_ptr->param_1) == 1)
        {
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_HAND_WRITING
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_HAND_WRITING_CAND)
            {
                if (g_imc.global_data.dead_char != 0)
                {
                    char_code = mmi_imm_get_merged_character_of_current_lang(g_imc.global_data.dead_char, *((UI_character_type *)msg_ptr->param_1));
                    
                    if (char_code != 0)
                    {
                        UI_character_type temp_str[2];
                        
                        temp_str[0] = char_code;
                        temp_str[1] = 0;

                        imc_msg.message_id = MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING;
                        imc_msg.param_0 = msg_ptr->param_0;
                        imc_msg.param_1 = (U32)&temp_str[0];
                        
                        return g_imc.message_proc( g_imc.editor_handle, &imc_msg );
                    }
                }
            }
        }
        else
    #endif
        {
            g_imc.global_data.dead_char = 0;
        }    
    }
    else if (msg_ptr->message_id == MMI_IMC_MESSAGE_CLEAR_HILIGHT)
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD;
        imc_msg.param_0 = (U32)&start_p;
        imc_msg.param_1 = (U32)&end_p;

        str_len = (S32)g_imc.message_proc( g_imc.editor_handle, &imc_msg );

        if (str_len > 0)
        {
            char_code= (UI_character_type)((*start_p)|(*(start_p+1)<<8)); 

            if (str_len == 1 || (str_len == 2 && char_code ==0x1b))
            {
                if (char_code == 0x1b)
                {
                    char_code = (UI_character_type)((*(start_p + ENCODING_LENGTH))|(*(start_p + ENCODING_LENGTH + 1)<<8)); 
                }

                if (mmi_imm_is_dead_character_of_current_lang(char_code))
                {
                    g_imc.global_data.dead_char = char_code;
                    
                    imc_msg.message_id = MMI_IMC_MESSAGE_CLEAR_HILIGHT;

                    if (!g_is_ime_disconnecting)
                    {
                        mmi_imc_gdi_lcd_freeze(TRUE);
                        g_imc.message_proc( g_imc.editor_handle, &imc_msg );
                        mmi_imc_gdi_lcd_freeze(gdi_freeze);;
                        imc_msg.message_id = MMI_IMC_MESSAGE_DELETE_CHAR;
                        imc_msg.param_0 = 1;
                        
                        g_imc.message_proc( g_imc.editor_handle, &imc_msg );
                    }
                    else
                    {
                        g_imc.message_proc( g_imc.editor_handle, &imc_msg );
                    }    

                    return 0;
                }
                else
                {
                    g_imc.global_data.dead_char = 0;
                }
            }
            else
            {
                g_imc.global_data.dead_char = 0;
            }
        }
    }
    else if (msg_ptr->message_id == MMI_IMC_MESSAGE_RESET_MULTITAP_STATE)
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE;

        if (g_imc.message_proc( g_imc.editor_handle, &imc_msg ))
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR;
            imc_msg.param_0 = (U32)&pre_char;

            if (g_imc.message_proc( g_imc.editor_handle, &imc_msg ))
            {
                if (mmi_imm_is_dead_character_of_current_lang(pre_char))
                {
                    g_imc.global_data.dead_char = pre_char;
                    
                    imc_msg.message_id = MMI_IMC_MESSAGE_RESET_MULTITAP_STATE;
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
#endif
                    {
                        g_imc.message_proc( g_imc.editor_handle, &imc_msg );
                    }    
                    return 0;
                }
                else
                {
                    g_imc.global_data.dead_char = 0;
                }
            }
            else
            {
                g_imc.global_data.dead_char = 0;
            }
        }
        else if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP)
        {
            UI_string_type str = NULL;
            
            str = mmi_imc_get_candidate_by_index(&g_imc.global_data.cand_buff[0], g_imc.global_data.cand_select);
            
            if (str)
            {
                if (mmi_ucs2strlen((const S8 *)str) == 1 && mmi_imm_is_dead_character_of_current_lang(*str))
                {
                    g_imc.global_data.dead_char = *str;
                }
                else
                {
                    g_imc.global_data.dead_char = 0;
                }
            }
            else
            {
                g_imc.global_data.dead_char = 0;
            }
        }
        else
        {
            g_imc.global_data.dead_char = 0;
        }
    }
    else if (msg_ptr->message_id == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
    {
        if (g_imc.global_data.dead_char != 0)
        {
            char_code = mmi_imm_get_merged_character_of_current_lang(g_imc.global_data.dead_char, (UI_character_type)msg_ptr->param_0);

            if (char_code != 0)
            {
                msg_ptr->param_0 = char_code;
            }
        }
    }
    else if (msg_ptr->message_id == MMI_IMC_MESSAGE_INSERT_NEW_LINE)
    {
        g_imc.global_data.dead_char = 0;
    }
#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */

    ret = g_imc.message_proc( g_imc.editor_handle, msg_ptr );

    /* For input method keymap auto-test */
    if (msg_ptr->message_id == MMI_IMC_MESSAGE_MODE_CHANGED
        && g_imc_is_keymap_auto_test_on)
    {
        //MYQUEUE Message;

        mmi_ime_input_mode_change_ind_struct_p local_param_ptr = 
                (mmi_ime_input_mode_change_ind_struct_p)OslConstructDataPtr(sizeof(mmi_ime_input_mode_change_ind_struct));

        if (local_param_ptr)
        {
            local_param_ptr->input_mode = mmi_imm_get_curr_input_mode();
            /*Message.oslSrcId = MOD_MMI;
            Message.oslDestId = MOD_MMI;
            Message.oslMsgId = (msg_type)MSG_ID_MMI_IME_INPUT_MODE_CHANGE_IND;
            Message.oslDataPtr = (oslParaType*)local_param_ptr;
            Message.oslPeerBuffPtr = NULL;
            OslMsgSendExtQueue(&Message);*/
			mmi_frm_send_ilm(MOD_MMI,(msg_type)MSG_ID_MMI_IME_INPUT_MODE_CHANGE_IND,(oslParaType*)local_param_ptr,NULL);
        }
    }

    if (ret && msg_ptr->message_id == MMI_IMC_MESSAGE_INSERT_CHAR)
    {
        mmi_imc_print_string_inserted_to_editor((UI_string_type)&(msg_ptr->param_0), 1);
    }
    else if (ret && msg_ptr->message_id == MMI_IMC_MESSAGE_INSERT_STRING)
    {
        mmi_imc_print_string_inserted_to_editor((UI_string_type)msg_ptr->param_0, mmi_ucs2strlen((const S8 *)msg_ptr->param_0));
    }
    else if (msg_ptr->message_id == MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION)
    {
        mmi_imc_print_string_inserted_to_editor((UI_string_type)&(msg_ptr->param_1), 1);
    }

    if (msg_ptr->message_id == MMI_IMC_MESSAGE_RESET_MULTITAP_STATE)
    {
        mmi_event_struct evt;

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);
        
        MMI_FRM_CB_EMIT_EVENT(&evt);
    }
    else if (msg_ptr->message_id == MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING)
    {
        mmi_event_struct evt;
        
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);
        
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }

    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_send_current_input_mode_indication
 * DESCRIPTION
 *  For MoDIS keymap Auto test
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_send_current_input_mode_indication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // MYQUEUE Message;
    mmi_ime_input_mode_value_ind_struct_p local_param_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_imc_is_keymap_auto_test_on)
    {
        return;
    }
    
    local_param_ptr = (mmi_ime_input_mode_value_ind_struct_p)OslConstructDataPtr(sizeof(mmi_ime_input_mode_value_ind_struct));

    if (local_param_ptr)
    {
        local_param_ptr->input_mode = mmi_imm_get_curr_input_mode();
		/*
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_MMI;
        Message.oslMsgId = (msg_type)MSG_ID_MMI_IME_INPUT_MODE_VALUE_IND;
        Message.oslDataPtr = (oslParaType*)local_param_ptr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);*/
		mmi_frm_send_ilm(MOD_MMI,(msg_type)MSG_ID_MMI_IME_INPUT_MODE_VALUE_IND,(oslParaType*)local_param_ptr,NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_keymap_auto_test
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_config_keymap_auto_test(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_is_keymap_auto_test_on = is_on;
}

#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_memory_card_is_language_supported
 * DESCRIPTION
 *  to chenck writing language is supported by  font and vendor or not
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

MMI_BOOL mmi_imc_memory_card_is_language_supported(const sIMEModeDetails *mode_detail_ptr, S32 lang_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* ssc = NULL;
	S16 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//TODO: add language check here
#if defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
//ctt begin
	if(mode_detail_ptr->lang_id == IME_WRITING_LANG_123)
	{
		return MMI_TRUE;
	}
	mmi_li_get_ssc_by_lcc(mode_detail_ptr->aLangCountryCode,&ssc);//ctt 
//ctt end
	//if(mmi_lang_support(mode_detail_ptr->aLangCountryCode) >= 0)
	i = mmi_lang_support(ssc);
	if( i >= 0)//ctt
	{
		if(mmi_ime_memory_card_is_language_supported_by_vendor(mode_detail_ptr->lang_id))
		{
			return MMI_TRUE;
		}
		mode_detail_ptr = mmi_imm_get_corresponding_multitap_mode(mode_detail_ptr->imm_mode_id, mode_detail_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK);
		if(mmi_ime_memory_card_is_lang_supported_by_mtk(mode_detail_ptr->imm_mode_id))
		{
			return MMI_TRUE;
		}
	}
	return MMI_FALSE;
#else
	return MMI_TRUE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_input_mode_by_memory_card_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
const sIMEModeDetails * mmi_imc_memory_card_change_input_mode(const sIMEModeDetails *mode_details_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                						   */
    /*----------------------------------------------------------------*/
	U16 i;
	const sIMEModeDetails * current_mode_details_ptr = mode_details_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                     						   */
    /*----------------------------------------------------------------*/
	
	ASSERT(mode_details_ptr != NULL);
	if(current_mode_details_ptr->lang_id == IME_WRITING_LANG_123)
	{
		return current_mode_details_ptr;
	}
	
	for(i=0;g_ime_ldb_storage_infor_tbl[i].lang_id != IME_WRITING_LANG_NONE;i++)
	{
		if(g_ime_ldb_storage_infor_tbl[i].lang_id == current_mode_details_ptr->lang_id)
		{
			if(g_ime_ldb_storage_infor_tbl[i].ime_storage_mode & MMI_IME_LDB_STORAGE_IN_ROM)
			{
				mmi_ime_memory_card_config_loadldb_flag(MMI_FALSE);
				return current_mode_details_ptr;
			}

			if(g_ime_ldb_storage_infor_tbl[i].ime_storage_mode & MMI_IME_LDB_STORAGE_IN_CARD)
			{
				if(srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) && mmi_ime_check_ldb_support_info(current_mode_details_ptr->lang_id) == MMI_TRUE)
				{
					mmi_ime_memory_card_config_loadldb_flag(MMI_TRUE); //only load ldb when get canidates for performance
					mmi_ime_set_ldb_index(i);
					return current_mode_details_ptr;
				}
			}
			//change to multitap mode when no memory card and not storage ldb in ROM
			current_mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(current_mode_details_ptr->imm_mode_id, mode_details_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK);
			//#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)&&defined(__MMI_ALPHABETIC_FIRST_UPPERCASE_INPUT__)//ctt begin
			if (current_mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
			{
				current_mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(current_mode_details_ptr->imm_mode_id, IME_MODE_ATTR_LOWERCASE);
			}
			//#endif//ctt end
					
			if(current_mode_details_ptr == NULL || mmi_ime_memory_card_is_lang_supported_by_mtk(current_mode_details_ptr->imm_mode_id) == MMI_FALSE)
			{	
				//MMI_TRACE(MMI_FW_TRC_G5_IME,TRC_MMI_IME_MEMORY_CARD_CHANGE_MULTITAP_MODE_FAIL,mode_details_ptr->menuitem_string_id);
				ASSERT(0);
			}
		}
	}
	//change to multitap mode vendor not supported this language
	current_mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(current_mode_details_ptr->imm_mode_id, mode_details_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK);
					
	if(current_mode_details_ptr == NULL || mmi_ime_memory_card_is_lang_supported_by_mtk(current_mode_details_ptr->imm_mode_id) == MMI_FALSE)
	{	
		//MMI_TRACE(MMI_FW_TRC_G5_IME,TRC_MMI_IME_MEMORY_CARD_CHANGE_MULTITAP_MODE_FAIL,mode_details_ptr->menuitem_string_id);
		ASSERT(0);
	}
	return current_mode_details_ptr;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_input_mode
 * DESCRIPTION
 *  Set input mode, only change word engine and handwriting engine
 * PARAMETERS
 *  input_mode    [IN]   Input mode
 *  reserved      [IN]   Reserved variable
 * RETURNS
 *  Successfully or not
 *****************************************************************************/
MMI_BOOL mmi_imc_change_input_mode( mmi_imm_input_mode_enum input_mode, U32 reserved )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails * mode_details_ptr;
    MMI_BOOL ret_val = MMI_FALSE;
	mmi_imm_input_mode_enum saved_cur_input_mode = mmi_imm_get_curr_input_mode();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_V3__)
	if(input_mode != IMM_INPUT_MODE_123_SYMBOLS)
	{
		mode_before_123_symbol = input_mode;
	}

#endif
    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);
   
    if (mode_details_ptr == NULL)
    {
        return MMI_FALSE;
    }

#if defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
	mode_details_ptr = mmi_imc_memory_card_change_input_mode(mode_details_ptr);
	input_mode =  mode_details_ptr->imm_mode_id;
#endif

	if (g_imc.mode_details_ptr != NULL)
	{
		if (g_imc.mode_details_ptr->imm_mode_id == input_mode)
		{
			return MMI_TRUE;
		}
	}

    if (!mmi_imm_is_change_input_mode_enabled())
    {
        return MMI_FALSE;
    }
    
    mmi_imc_cancel_timer();
    
    mmi_ime_word_leave_current_mode();
    
	if (saved_cur_input_mode != mmi_imm_get_curr_input_mode() && input_mode == saved_cur_input_mode) /* Current input mode may be changed in canceling timer */
    {
		mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
        input_mode = mmi_imm_get_curr_input_mode();
        
		if (mode_details_ptr == NULL)
		{
			return MMI_FALSE;
		}
	}
    
    g_imc.mode_details_ptr = mode_details_ptr;

#if defined(__MMI_IME_PLUG_IN__)
    ret_val = mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHANGE_INPUT_MODE, (U32)input_mode, 0);
#endif

    mmi_imc_reset_global_data();
    
    ret_val = mmi_imc_key_change_mode(mode_details_ptr, reserved);

#ifdef __MMI_TOUCH_SCREEN__
    ret_val = mmi_imc_pen_change_mode(mode_details_ptr, reserved);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    if (g_imc_background_filler != NULL)
        wgui_virtual_keyboard_register_hide_callback(g_imc_background_filler);
#endif
#endif /* __MMI_TOUCH_SCREEN__ */

//#if defined(__MMI_IME_V3__)
/*
#if defined(__MMI_IME_V3__) && !((defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)))
	mmi_imm_set_curr_writing_lang_by_curr_mode();
#endif
*/

#if (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_VK_TYPE_QWERTY__)) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_CSTAR__) && defined(__MMI_IME_V3__)
    mmi_ime_reset_group_letters(mode_details_ptr);
#endif
#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
	#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
		mmi_imm_config_special_key_validation(mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode()));
	#endif
#endif



#if defined(__MMI_IME_MAGIC_ONE__)
    g_is_magic_state = MMI_FALSE;
    g_magic_key_down = MMI_FALSE;
#endif
    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_global_data
 * DESCRIPTION
 *  Get global data buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  Address of global data buffers
 *****************************************************************************/
mmi_imc_global_data_struct_p    mmi_imc_get_global_data( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return &g_imc.global_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_reset_global_data
 * DESCRIPTION
 *  Reset global data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_reset_global_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    mmi_ime_word_capital_state_enum new_state;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_clear_symbol_buffer();
    g_imc.global_data.cand_count = 0;
    g_imc.global_data.comp_count = 0;
    g_imc.global_data.cand_page = 0;
    g_imc.global_data.comp_page = 0;
    memset(g_imc.global_data.cand_first_index, 0, sizeof(U16) * MMI_IMC_MAX_CANDIDATE_PAGE);
    memset(g_imc.global_data.comp_first_index, 0, sizeof(U8) * MMI_IMC_MAX_COMPOSITION_PAGE);
    g_imc.global_data.comp_select = 0;
    g_imc.global_data.cand_select = 0;
    g_imc.global_data.pre_string[0] = 0;
    g_imc.global_data.key_element_length = 0;
    memset(g_imc.global_data.cand_buff, 0, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
    memset(g_imc.global_data.comp_buff, 0, sizeof(UI_character_type) * MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
    memset(g_imc.global_data.symb_buff, 0, sizeof(U16) * MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
    memset(g_imc.global_data.key_buffer, 0, sizeof(U16)* MMI_IMC_MAX_KEY_BUFFER_SIZE);
    g_imc.global_data.cand_check_cnt = 0;
    g_imc.global_data.cand_length = 0;
    g_imc.global_data.tone = MMI_IMC_SYMB_TONE_NONE;
    
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    if (mmi_imm_is_auto_capitalization_valid())
    {
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        if(!g_imc_pen_is_vk_caps_lock_down && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
#endif
        {
            new_state = mmi_imc_get_candidate_case_before_cursor();

            if (!g_imc.global_data.capital_lock && g_imc.global_data.capital_state > MMI_IME_WORD_CAPITAL_STATE_NONE
                && g_imc.global_data.capital_state < MMI_IME_WORD_CAPITAL_STATE_MAX)
            {
                g_imc.global_data.capital_lock = MMI_FALSE;
		        g_imc.global_data.capital_state = new_state;
	        }
            mmi_imc_set_caps_seq_by_cur_state(0);

        }
    }
    else
#endif
    {
	#if defined(__MMI_IME_V3__) && defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
		if(mmi_frm_qwerty_get_customized_special_key_flag() == 0)  //capital state controled by shift key in the qwerty keypad
		{
			g_imc.global_data.capital_state = mmi_imc_get_input_mode_caps(g_imc.mode_details_ptr);
		}
	#else
		g_imc.global_data.capital_state = mmi_imc_get_input_mode_caps(g_imc.mode_details_ptr);
	#endif

    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        mmi_imc_set_caps_seq_by_cur_state(0);
    #endif
    }

#if defined(__MMI_IME_CANDIDATE_FILTER__)
    g_imc.global_data.cand_filter = MMI_FALSE;
    g_imc.global_data.filter_page = 0xff;
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    memset(g_imc.global_data.special_key_flag_table, 0, sizeof(U32) * MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_create_imui_controls
 * DESCRIPTION
 *  Create all imui controls 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_create_imui_controls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
	#if !defined(__MMI_IME_FTE_ENHANCE__) || !defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__)
    mmi_imc_message_struct imc_msg;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    /* Create Clipboard floating menu controls */
    imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_CLIPBOARD_FLOATING_MENU;
    mmi_imui_send_message(&imui_msg, NULL); 
#endif

    /* The selection area style should be changed base on touch or non-touch and theme */
    imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_COMPOSITION_BOX;
    imui_msg.param_0 = MMI_IMC_COMPOSITION_BOX_STYLE;
    
    mmi_imui_send_message(&imui_msg, NULL);
    
    imui_msg.param_0 = MMI_IMC_CANDIDATE_BOX_STYLE;
    imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_CANDIDATE_BOX;
    mmi_imui_send_message(&imui_msg, NULL);
#if defined(__MMI_IME_CANDIDATE_GRID__)
	imui_msg.param_0 = MMI_IMC_CANDIDATE_BOX_GRID_STYLE;
    imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_CANDIDATE_BOX_GRID;
    mmi_imui_send_message(&imui_msg, NULL);
#endif


    /* Floating UIs must be before other UI elements in IMUI control set */

#if defined(__MMI_TOUCH_SCREEN__)
#if !defined(__NO_HANDWRITING__)
    mmi_imc_pen_set_handwriting_style();

    if (mmi_imc_pen_get_handwriting_style() == MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK)
    {
        imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_MULTI_BLOCK_AREA;
        mmi_imui_send_message(&imui_msg, NULL);
    }
#if defined(__MMI_IME_FTE_ENHANCE__)
    if (mmi_imc_pen_get_handwriting_style() == MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK)
    {
        imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_SINGLE_BLOCK_AREA;
        mmi_imui_send_message(&imui_msg, NULL);
    }    
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */
#endif /*  !defined(__NO_HANDWRITING__) */

    imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_VITUAL_KEYBOARD;
    mmi_imui_send_message(&imui_msg, NULL);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

#ifdef __MMI_CLIPBOARD__
    if (!mmi_imc_clipboard_is_editor_read_only())
#endif
    {
    #if defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__)
    #if defined(__MMI_IME_FTE_ENHANCE__)
        imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_IME_INDICATOR;
        mmi_imui_send_message(&imui_msg, NULL);
    #else
        #if defined(__MMI_VUI_ENGINE__)
            if (vadp_p2v_uc_is_in_venus() || vadp_p2v_is_venus_ime_connected())
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_IME_INDICATOR;
                mmi_imui_send_message(&imui_msg, NULL);
            }
            else    
        #endif
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL;
                if (mmi_imc_send_message(&imc_msg))
                {
                    imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_INFORMATION_BAR;
                    mmi_imui_send_message(&imui_msg, NULL);
                }
            }    
    #endif  
    #else
        imc_msg.message_id = MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL;
        if (mmi_imc_send_message(&imc_msg))
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_INFORMATION_BAR;
            mmi_imui_send_message(&imui_msg, NULL);
        }
    #endif /* #if defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__) */
    }    

#if defined(MMI_IMC_INPUT_BOX_STYLE)
    imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_INPUT_BOX;
    imui_msg.param_0 = MMI_IMC_INPUT_BOX_STYLE;
    mmi_imui_send_message(&imui_msg, NULL);
#endif

#if defined(MMI_IMC_TITLE_BOX_STYLE)
    imui_msg.message_id = MMI_IMUI_MESSAGE_CREATE_TITLE_BOX;
    imui_msg.param_0 = MMI_IMC_TITLE_BOX_STYLE;
    mmi_imui_send_message(&imui_msg, NULL);
#endif

#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_ADD_ALL_CONTROLS, 0, 0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_imui
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_redraw_imui(U32 imui_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    MMI_BOOL hide_candidate = MMI_FALSE;
    mmi_imc_message_struct  imc_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_disable_draw)
        return;

    if (imui_set == 0)
    {
        mmi_imc_redraw_screen_by_state();
    }
    else
    {

        if ( g_imc.mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC )
        {
            if ( g_imc.mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP )
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_SELECT_AREA_DISABLE_LABEL;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        }
    
        if (imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA))
        {
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_INPUTING
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_MULTITAP
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_VK_CAND_MULTITAP)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_COMPOSITION_SET_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
            else
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_COMPOSITION_CANCEL_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        }

        if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP)
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX;
            hide_candidate = (MMI_BOOL)mmi_imc_send_message(&imc_msg);
            
            imui_msg.message_id = MMI_IMUI_MESSAGE_SELECT_AREA_DISABLE_LABEL;
            mmi_imui_send_message(&imui_msg, NULL);
        }
        
        if (((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) || 
             (mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ASCII_PASSWORD))
            && (g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP ||
                g_imc.fsm_object.curr_state == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP))
        {
            if ((imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)) && 
                g_imc.global_data.cand_count == 1)
            {
                hide_candidate = MMI_TRUE;
            }
        }
        
        if ((imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)) && !hide_candidate)
        {
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_CAND_SELECTING
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_HAND_WRITING_CAND
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_VK_CAND
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_SMART_CANDIDATE
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_VK_CAND_MULTITAP)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_SET_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
            else
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_CANCEL_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        }
        if ((imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)))
        {
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_WITH_INPUT
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_INPUT
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_PRE_SMART_CANDIDATE
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_NEW_WORD_INITIAL
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_NEW_WORD_MULTITAP)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_INPUT_SET_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
            else if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_INPUTING
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_MULTITAP)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_INPUT_SET_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        #endif
            else
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_INPUT_CANCEL_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_INPUT_BOX;
            mmi_imui_send_message(&imui_msg, NULL);
        }

    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_REDRAW;
            imui_msg.param_0 = imui_set; 
            mmi_imui_send_message(&imui_msg, NULL);

            if ((imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_INFORMATION_BAR)) || 
                (imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_IME_INDICATOR_AREA)) || 
                (imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_IME_HINT_AREA)))
            {
                mmi_imc_redraw_ime_indicator();
            }
        }
        else
    #endif
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_REDRAW;
            imui_msg.param_0 = imui_set; 
            mmi_imui_send_message(&imui_msg, NULL);
        }
        mmi_imc_key_redraw_softkey();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_current_imui_height_skip_fixed_editor
 * DESCRIPTION
 *  Get current IMUI area height, don't care whether current editor is fixed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32  mmi_imc_get_current_imui_height_skip_fixed_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    S32 i = 0;
    mmi_imc_message_struct  imc_msg;
	U32 imui_set = 0;
#ifdef __MMI_IME_PLUG_IN__
    U32 temp_imui_set = 0;
    MMI_BOOL is_ime_sdk_handled = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (!g_is_ime_connected)
	{
        return 0;
	}

#ifdef __MMI_IME_PLUG_IN__
    if (mmi_imc_is_in_custom_state(mmi_imc_get_state()))
    {
        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_GET_CURRENT_FIXED_CONTROL_SET, (U32)&imui_set, 0) == 1)
        {
            is_ime_sdk_handled = MMI_TRUE;
        }
        else
        {
            /* 
             * the current state is in custom state,
             * but the handler doesn't process it
             */
            MMI_ASSERT(0);
        }
    }
    else if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
    {
        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_GET_CURRENT_FIXED_CONTROL_SET, (U32)&imui_set, 0) == 1)
        {
            is_ime_sdk_handled = MMI_TRUE;
        }
        else
        {
            is_ime_sdk_handled = MMI_FALSE;
        }
    }

    if (is_ime_sdk_handled == MMI_FALSE)
#endif
    {
	    while(g_ime_state_set[i].curr_state != MMI_IMC_STATE_NONE)
        {
            if (g_ime_state_set[i].curr_state == g_imc.fsm_object.curr_state)
            {
                break;
            }
            i++;
        }
	    
        if (g_ime_state_set[i].curr_state == MMI_IMC_STATE_NONE)
        {
            return 0;
        }
	    
    
	    imui_set = g_ime_state_set[i].imui_set;
	    
	    imc_msg.message_id = MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX;
	    
        if ((MMI_BOOL)mmi_imc_send_message(&imc_msg))
	    {
            imui_set &= ~(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
	    }
#ifdef __MMI_VIRTUAL_KEYBOARD__ 
        if (!mmi_imc_is_vk_disabled())
        {
            if ((imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)) || mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
            {
            #ifdef __MMI_IME_PLUG_IN__
                if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CONFIG_VK_IN_MTK_STATE, (U32)&temp_imui_set, 0) == 1)
                {
                    imui_set &= ~(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
                    imui_set |= temp_imui_set;
                }
                else
            #endif
                {
                    imui_set |= (MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
                }
            }
            else
            {
                imui_set &= ~(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
            }    
        }
        else
        {
            imui_set &= ~(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
        }  
    #endif
    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__)
        if ( !mmi_imc_is_handwriting_disabled())
        {
            if (g_imc_single_block_hw_state)
            {
                imui_set |= (MMI_IMUI_CONTROL_MASK(MMI_IMUI_SINGLE_BLOCK_AREA));
            }
            else
            {
                imui_set &= ~(MMI_IMUI_CONTROL_MASK(MMI_IMUI_SINGLE_BLOCK_AREA));
            }
        }
    #endif
    }
	
	imui_msg.message_id = MMI_IMUI_MESSAGE_FIXED_IMUI_HEIGHT;
	imui_msg.param_0 = (U32)imui_set;


    return (S32)mmi_imui_send_message(&imui_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_current_imui_height
 * DESCRIPTION
 *  Get current IMUI area height
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32  mmi_imc_get_current_imui_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (g_is_fixed_input_box)
	{
        return 0;
	}

	return mmi_imc_get_current_imui_height_skip_fixed_editor();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_vk_draw_override
 * DESCRIPTION
 * setting flag
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_vk_draw_override(MMI_BOOL flag)
{
        g_imc_vk_override = flag;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_whole_screen
 * DESCRIPTION
 *  Redraw screen according to state and always draw vk irrespective of state remaining same or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_imc_redraw_whole_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_vk_draw_override(MMI_TRUE);
    mmi_imc_redraw_screen_by_state_ext();
	mmi_imc_vk_draw_override(MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_screen_by_state
 * DESCRIPTION
 *  Redraw screen according to state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_imc_redraw_screen_by_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_redraw_screen_by_state_ext();
}

void  mmi_imc_repaint_screen(void)
{
#if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
#endif
        {
            gdi_lcd_repaint_all();
        }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_screen_by_state_ext
 * DESCRIPTION
 *  Redraw screen according to state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL  mmi_imc_redraw_screen_by_state_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    S32 i = 0;
    mmi_imc_message_struct  imc_msg;
    MMI_BOOL hide_candidate = MMI_FALSE;
    MMI_BOOL hide_composition = MMI_FALSE;
    MMI_BOOL hide_input = MMI_FALSE;
    static MMI_BOOL is_reentry = MMI_FALSE; 
#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    MMI_BOOL show_floating_menu = MMI_TRUE;
#endif
#ifdef __MMI_IME_PLUG_IN__
    U32 no_use = 0;
    MMI_BOOL is_ime_sdk_handled = MMI_FALSE;
#endif
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_disable_draw)
        return MMI_FALSE;

    if (is_reentry)
        return MMI_FALSE;
    
    is_reentry = MMI_TRUE;

#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    if (g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU))
    {
        imui_msg.message_id = MMI_IMUI_MESSAGE_IS_VISIBLE_CONTROL;
        imui_msg.param_0 = MMI_IMUI_CLIPBOARD_FLOATING_MENU;
        show_floating_menu = (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
    }
#endif

    imui_msg.message_id = MMI_IMUI_MESSAGE_HIDE_ALL;
    mmi_imui_send_message(&imui_msg, NULL);
    
#ifdef __MMI_IME_PLUG_IN__
    if (mmi_imc_is_in_custom_state(mmi_imc_get_state()))
    {
        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CONFIG_UI_CONTROLS_BY_IME_STATE, 0, 0) == 1)
        {
            is_ime_sdk_handled = MMI_TRUE;
        }
        else
        {
            /* 
             * the current state is in custom state,
             * but the handler doesn't process it
             */
            MMI_ASSERT(0);
        }
    }
    else if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
    {
        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CONFIG_UI_CONTROLS_BY_IME_STATE, 0, 0) == 1)
        {
            is_ime_sdk_handled = MMI_TRUE;
        }
        else
        {
            is_ime_sdk_handled = MMI_FALSE;
        }
    }

    if(is_ime_sdk_handled == MMI_TRUE)
    {
        g_has_entered_ime_screen = MMI_TRUE;
        mmi_imc_gdi_lcd_freeze(TRUE);
        g_imc.fsm_object.imui_set = 0;
    }
    else
#endif
    {
        while(g_ime_state_set[i].curr_state != MMI_IMC_STATE_NONE)
        {
            if (g_ime_state_set[i].curr_state == g_imc.fsm_object.curr_state)
            {
                break;
            }
            i++;
        }
    
        if (g_ime_state_set[i].curr_state == MMI_IMC_STATE_NONE)
        {
            is_reentry = MMI_FALSE;
            return MMI_FALSE;
        }
    
        g_has_entered_ime_screen = MMI_TRUE;
    
        mmi_imc_gdi_lcd_freeze(TRUE);
    
        if (g_ime_state_set[i].curr_state == MMI_IMC_STATE_MULTITAP)
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX;
            hide_candidate = (MMI_BOOL)mmi_imc_send_message(&imc_msg);
            imui_msg.message_id = MMI_IMUI_MESSAGE_SELECT_AREA_DISABLE_LABEL;
            mmi_imui_send_message(&imui_msg, NULL);
        }
    
    #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
        if (g_imc.mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_SM_PINYIN)
        {
            if (g_imc.global_data.comp_count <= 1 && !g_imc.global_data.comp_page)            
                hide_composition = MMI_TRUE;
        #if defined(__MMI_MAINLCD_128X128__)
            hide_composition = MMI_TRUE;
        #endif
            #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_CSTAR_PHRASE_INPUT__)
            if (g_imc.global_data.comp_count != 0)
                hide_composition = MMI_FALSE;
            if (g_imc.global_data.input_length == 0)
                hide_input = MMI_TRUE;
            #endif         
        }
        else if (g_imc.mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO)
        {
            #ifndef __MMI_CSTAR_PHRASE_INPUT__
            hide_composition = MMI_TRUE;
            #endif
        }
        else if (g_imc.mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_TR_STROKE || 
                    g_imc.mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_HK_STROKE ||
                   g_imc.mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_SM_STROKE)
        {
        #if defined(__MMI_IME_MAGIC_ONE__)
            if (!g_magic_key_down)
        #endif
            {
                hide_input = MMI_TRUE;
            }
        }
    #endif
    
        g_imc.fsm_object.imui_set = g_ime_state_set[i].imui_set;

        if (mmi_imc_get_is_disable_candidate_box())
        {
            /* disable the display of candidate box */
            g_imc.fsm_object.imui_set &= (~((U32)MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)));
        }
    
        /* We must get the info that whether there is information bar and multi-block */
    
    
    #ifdef __MMI_TOUCH_SCREEN__
	    
#ifdef __MMI_VIRTUAL_KEYBOARD__ 
        if (!mmi_imc_is_vk_disabled())
        {
            if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY)
            {
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#if !defined(__NO_HANDWRITING__) && defined(__MMI_IME_FTE_ENHANCE__)
                mmi_imc_pen_stop_singleblock_handwriting();
#endif
            }
            if ((g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD)) || mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
            {
            #ifdef __MMI_IME_PLUG_IN__
                if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CONFIG_VK_IN_MTK_STATE, (U32)&no_use, 0) == 1)
                {
                    imui_msg.message_id = MMI_IMUI_MESSAGE_HIDE_VIRTUAL_KEYBOARD;
                    mmi_imui_send_message(&imui_msg, NULL);
                }
                else
            #endif
                {
                    imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_VIRTUAL_KEYBOARD;
                    mmi_imui_send_message(&imui_msg, NULL);
                }
            }
            else
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_HIDE_VIRTUAL_KEYBOARD;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        }
    #endif
    #endif /* __MMI_TOUCH_SCREEN__ */
    }

#ifdef __MMI_TOUCH_SCREEN__
#if defined(__MMI_IME_FTE_ENHANCE__)
    if ( !mmi_imc_is_handwriting_disabled())
    {
        if (g_imc_single_block_hw_state)
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_SINGLE_BLOCK;
            mmi_imui_send_message(&imui_msg, NULL);
        }
        else
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_HIDE_SINGLE_BLOCK;
            mmi_imui_send_message(&imui_msg, NULL);
        }
    }
    else
#endif

#ifdef __MMI_IME_PLUG_IN__
    if(is_ime_sdk_handled == MMI_FALSE)
#endif
    {
        if (g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_MULTI_BLOCK_AREA) && !mmi_imc_is_handwriting_disabled())
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_MULTI_BLOCK;
            mmi_imui_send_message(&imui_msg, NULL);
        }
    }
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_IME_PLUG_IN__
    if(is_ime_sdk_handled == MMI_FALSE)
#endif
    {
        if ((g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA)) && !hide_composition)
        {
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_INPUTING
			    || g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_MULTITAP
			    || g_imc.fsm_object.curr_state == MMI_IMC_STATE_VK_CAND_MULTITAP)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_COMPOSITION_SET_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
            else
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_COMPOSITION_CANCEL_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
			#if defined(__MMI_IME_CANDIDATE_GRID__)
            if (mmi_imc_is_grid_state()
				|| mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON))
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_REMOVE_VERTICAL_FLAG;
                mmi_imui_send_message(&imui_msg, NULL);
            }
			#endif
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_COMPOSITION_BOX;
            mmi_imui_send_message(&imui_msg, NULL);
        }
    
        if ((g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA)) && !hide_input)
        {
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_WITH_INPUT
			    || g_imc.fsm_object.curr_state == MMI_IMC_STATE_INPUT
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_PRE_SMART_CANDIDATE
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_NEW_WORD_INITIAL
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_NEW_WORD_MULTITAP)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_INPUT_SET_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
            else if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_INPUTING
			    || g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_MULTITAP)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_INPUT_SET_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        #endif
            else
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_INPUT_CANCEL_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_INPUT_BOX;
            mmi_imui_send_message(&imui_msg, NULL);
        }
    
        if (g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_TITLE_AREA))
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_TITLE_BOX;
            mmi_imui_send_message(&imui_msg, NULL);
        }
		#if defined(__MMI_IME_CANDIDATE_GRID__)
        if (g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_GRID_AREA))
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_CANDIDATE_GRID_BOX;
            mmi_imui_send_message(&imui_msg, NULL);
        }
		#endif
        
        /* in some special input type, such as quick search, candidate box would be hided. */
        if (((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) || 
             (mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ASCII_PASSWORD))
            && (g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP ||
                g_imc.fsm_object.curr_state == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP))
        {
            if ((g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)) && 
                g_imc.global_data.cand_count == 1 && g_imc.global_data.cand_page == 0)
            {
                hide_candidate = MMI_TRUE;
            }
        }
    
        if ((g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA)) && !hide_candidate)
        {
			#if defined(__MMI_IME_V3__)
			if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
			{
				imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_CANCEL_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
			}
			else
			
			#endif
			{
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_CAND_SELECTING
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_HAND_WRITING_CAND
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_VK_CAND
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_SMART_CANDIDATE
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_VK_CAND_MULTITAP
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_SET_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
            else
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_CANCEL_FOCUS;
                mmi_imui_send_message(&imui_msg, NULL);
            }
			}
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_CANDIDATE_BOX;
            mmi_imui_send_message(&imui_msg, NULL);
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_HAND_WRITING)
            {
                imui_msg.message_id = MMI_IMUI_MESSAGE_RESERVE_CANDIDATE_AREA;
                mmi_imui_send_message(&imui_msg, NULL);
            }
        }
    }

#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    if (g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_CLIPBOARD_FLOATING_MENU) && show_floating_menu)
    {
        imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_CLIPBOARD_FLOATING_MENU;
        mmi_imui_send_message(&imui_msg, NULL);
    }
#endif

        mmi_imc_gdi_lcd_freeze(gdi_freeze);;


#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        //vadp_p2v_redraw_imui_controls(0);
        imui_msg.message_id = MMI_IMUI_MESSAGE_REDRAW;
        imui_msg.param_0 = 0; /* Redraw all imui controls */
        mmi_imui_send_message(&imui_msg, NULL);
        if(g_imc_show_venus_popup != MMI_TRUE)
		{
				//mmi_imc_redraw_ime_indicator();
        mmi_imc_key_redraw_softkey();
        
		}
        g_imc_show_venus_popup = MMI_FALSE;
    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        wgui_icon_bar_update();
    #endif
    }
    else
#endif
    {
        mmi_imc_gdi_lcd_freeze(TRUE);
        
		if((g_pre_state == g_imc.fsm_object.curr_state && g_pre_state!= MMI_IMC_STATE_INITIAL) \
			&& (hide_composition == MMI_FALSE && g_imc.fsm_object.curr_state == MMI_IMC_STATE_SPELL_WITH_INPUT))
		{
			imui_msg.message_id = MMI_IMUI_MESSAGE_VK_DRAW_DISABLE;//no need to draw vk in this case,if state remains same
			mmi_imui_send_message(&imui_msg, NULL);		//this is done for improving performance when state remains start, associate selecting etc
		}
		else
		{
		    imui_msg.message_id = MMI_IMUI_MESSAGE_VK_DRAW_ENABLE;//normal case, where vk needs to be drawn
			mmi_imui_send_message(&imui_msg, NULL);
		}
		/*override vk draw if this flag enable through redraw whole screen by 3rd party*/
		if(g_imc_vk_override)
		{
			imui_msg.message_id = MMI_IMUI_MESSAGE_VK_DRAW_ENABLE;
			mmi_imui_send_message(&imui_msg, NULL);
		}
		imui_msg.message_id = MMI_IMUI_MESSAGE_REDRAW;
		imui_msg.param_0 = 0;
        mmi_imui_send_message(&imui_msg, NULL);
		#if defined(__MMI_IME_CANDIDATE_GRID__)
		if(!mmi_imc_is_grid_state())
		#endif
		{

        mmi_imc_key_redraw_softkey();

    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        if (dm_get_scr_bg_layer() != GDI_ERROR_HANDLE)
        {
            wgui_icon_bar_set_abm_layer(dm_get_scr_bg_layer());
        }
        wgui_icon_bar_update();
    #endif
		}
        mmi_imc_gdi_lcd_freeze(gdi_freeze);;
        mmi_imc_repaint_screen();
    }

    UI_UNUSED_PARAMETER(hide_composition);

    is_reentry = MMI_FALSE;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_candidate_by_index
 * DESCRIPTION
 *  Get candidate by specified index
 * PARAMETERS
 *  void
 * RETURNS
 *  The candidate
 *****************************************************************************/
UI_string_type mmi_imc_get_candidate_by_index(UI_character_type * cand_buff, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_len;
    U8 i;
    UI_string_type  temp_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    temp_ptr = cand_buff;
    
    for (i = 0; i < index; i++)
    {
        cand_len = (S32)mmi_ucs2strlen((const S8 * )temp_ptr);
        temp_ptr += (cand_len + 1);
    }

    return temp_ptr;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clear_symbol_buffer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_clear_symbol_buffer(void)/* May be moved to imc.c */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    UI_character_type vk_display_area[MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN + 1];
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc.global_data.symb_count = 0;
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    if ((MMI_BOOL)((g_imc.mode_details_ptr->Handwriting_Attrib)>>28) == MMI_TRUE)
    {
        vk_display_area[0] = 0;
        #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
        wgui_set_virtual_keyboard_display_area((U8 *)vk_display_area, MMI_FALSE);
        #else
        wgui_virtual_keyboard_set_display_area((U8 *)vk_display_area, MMI_FALSE);
        #endif
    }
#endif
}

#define __MMI_IME_STROKE_INPUT_WITH_REDICALS__

#ifdef __MMI_CSTAR_PHRASE_INPUT__

S32 mmi_imc_change_highlighted_composition_from_composition_box_cstar_style(U8 index)
{    
    return mmi_imc_key_change_highlighted_composition_cstar_style(index);
}

MMI_BOOL mmi_imc_is_qwerty_smart_pinyin_input(void)
{
    if (mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY && mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN)
        return MMI_TRUE;
    return MMI_FALSE;
}

void mmi_imc_commit_input_box_content(void)
{
    mmi_imc_key_commit_input_box_content();
}

#endif
#if defined(__MMI_CSTAR_PHRASE_INPUT__) && defined(__MMI_VIRTUAL_KEYBOARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_check_input_area_confirmed_length
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static UI_string_type mmi_imc_check_input_area_confirmed_length(UI_string_type input_string)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 cand_len = 0;
	UI_string_type str = input_string;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_imc_is_qwerty_smart_pinyin_input())
        {
            cand_len = mmi_ucs2strlen((const S8*)str);
            /* concat cand */
            memcpy(g_imc.global_data.symb_buff + g_imc.global_data.input_confirm_length, str, cand_len * sizeof(UI_character_type));            
            /* concat left input symb */
            memcpy(g_imc.global_data.symb_buff + g_imc.global_data.input_confirm_length + cand_len, 
                   g_imc.global_data.symb_buff + g_imc.global_data.input_confirm_length + g_imc.global_data.cand_match_len[g_imc.global_data.cand_select], 
                   (g_imc.global_data.symb_count - g_imc.global_data.input_confirm_length - g_imc.global_data.cand_match_len[g_imc.global_data.cand_select]) * sizeof(UI_character_type));
                   
            g_imc.global_data.input_confirm_length += cand_len;
            g_imc.global_data.symb_count += cand_len - g_imc.global_data.cand_match_len[g_imc.global_data.cand_select];
            
            if (g_imc.global_data.symb_count == g_imc.global_data.input_confirm_length)
            {
                /* all input symb are confirmed, commit to editor! */                
                memcpy(g_imc.global_data.input_buff, g_imc.global_data.symb_buff, g_imc.global_data.symb_count * sizeof(UI_character_type));
                g_imc.global_data.input_buff[g_imc.global_data.symb_count] = 0;
                str = g_imc.global_data.input_buff;                
            }
            else
            {
                mmi_imc_pen_set_vk_candidate(); 
				if(mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID)
				{
					mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING_GRID);
				}
				return NULL;
            }
        }
	 return str;  
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_select_candidate_from_candidate_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_select_candidate_from_candidate_box(void)/* May be moved to imc.c */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
    mmi_ime_query_param_struct   query_param = {0};
    mmi_ime_query_result_struct  query_result = {0};
    UI_string_type str = NULL;
	#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
    S32 cand_count = 0;
    #endif
    S32 cand_len = 0;
    U32 inserted_char_num = 0;

    #if defined __MMI_XT9__
    candidate_flag = 1; //NEW_CANDIDATE
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_imc.global_data.cand_count == 0)
    {
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
		imc_msg.message_id = MMI_IMC_MESSAGE_CLEAR_HILIGHT;
        imc_msg.param_0 = MMI_TRUE;
        mmi_imc_send_message(&imc_msg);
        return;
    }
    
    str = mmi_imc_get_candidate_by_index(g_imc.global_data.cand_buff, g_imc.global_data.cand_select);

    MMI_ASSERT(str);

    /* Insert selected candidate or confirm highlighted character */
    switch (mmi_imc_get_state())
    {
    case MMI_IMC_STATE_MULTITAP:
        mmi_imc_delete_timer();
        mmi_imc_print_string_inserted_to_editor(str, mmi_ucs2strlen((const S8 *)str));
        imc_msg.message_id = MMI_IMC_MESSAGE_RESET_MULTITAP_STATE;
        mmi_imc_send_message(&imc_msg);
        break;
        
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    case MMI_IMC_STATE_INPUT:     
        /* insert input area into editor */
        if ((g_imc.mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC))
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
            imc_msg.param_0 = (U32)g_imc.global_data.input_buff;
            inserted_char_num = mmi_imc_send_message(&imc_msg);
        }
        else if ((g_imc.mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC))
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
            imc_msg.param_0 = (U32)str;
            inserted_char_num = mmi_imc_send_message(&imc_msg);
        }
        break;
#endif

    case MMI_IMC_STATE_SMART_CANDIDATE:
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
     
    #if defined(__MMI_IME_USER_DATABASE__)
        if (*str == MMI_IME_USER_DATABASE_NEW_WORD)
        {
        #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)
            mmi_imui_message_struct imui_msg;
            mmi_imui_update_input_area_struct title_area, input_area;

            if (g_imc.mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
            {
                g_imc.global_data.new_word_prompt = mmi_imm_get_new_word_string_by_language(g_imc.mode_details_ptr->lang_id);
            }
            else
            {
                g_imc.global_data.new_word_prompt = mmi_imm_get_new_word_string_by_language(IME_WRITING_LANG_ABC);
            }
            
            title_area.str_ptr = g_imc.global_data.new_word_prompt;
            title_area.highlight_num = 0;
            title_area.flags = 0;
            
			if (mmi_imm_test_r2l_input())
			{   
				title_area.flags |= MMI_IMUI_INPUT_AREA_FLAG_R2L;
			}

            imui_msg.message_id = MMI_IMUI_MESSAGE_UPDATE_TITLE_AREA;
            imui_msg.param_0 = (U32)(&title_area); 
            
            mmi_imui_send_message(&imui_msg, NULL);

            memcpy(g_imc.global_data.new_word, g_imc.global_data.first_candidate, sizeof(UI_character_type) * (MMI_IMC_MAX_KEY_BUFFER_SIZE + 1));

            input_area.str_ptr = g_imc.global_data.new_word;
            input_area.highlight_start_index =  0;
            input_area.highlight_num = 0;
            input_area.wave_start_index = 0;
            input_area.wave_num = 0;
            input_area.cursor_index = mmi_ucs2strlen((const S8 *)input_area.str_ptr);
			input_area.flags = 0;

            g_imc.global_data.char_index = input_area.cursor_index;
                
			if (mmi_imm_test_r2l_input())
			{   
				input_area.flags |= MMI_IMUI_INPUT_AREA_FLAG_R2L;
			}
                
            imui_msg.message_id = MMI_IMUI_MESSAGE_UPDATE_INPUT_AREA;
            imui_msg.param_0 = (U32)(&input_area);

            mmi_imui_send_message(&imui_msg, NULL);

			if (g_imc.mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
            {
                mmi_ime_multitap_change_mode(mmi_imm_get_corresponding_multitap_mode(g_imc.mode_details_ptr->imm_mode_id, g_imc.mode_details_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK), 0);
            }
			else
			{
                mmi_ime_multitap_change_mode(mmi_imm_get_input_mode_array_item(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC), 0);
			}
            
            mmi_imc_set_state(MMI_IMC_STATE_NEW_WORD_INITIAL);
            
            return;
        #else
            {
            #if defined(__MMI_VUI_ENGINE__)
                if (vadp_p2v_uc_is_in_venus())
                {
                    mmi_event_struct evt;

                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_INVOKE_SPELL_WORD_SCREEN);
            
                    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
                }
                else
            #endif
                {
                   mmi_imc_entry_spell_new_word_screen();
                }
            }
            return;
        #endif
        }
    #endif /* #if defined(__MMI_IME_USER_DATABASE__)  */
        
    #if !defined(__MMI_IME_SMART_WITH_INPUT_AREA__) || defined(__MMI_CSTAR_PHRASE_INPUT__)
        mmi_imc_delete_timer();
        mmi_imc_print_string_inserted_to_editor(str, mmi_ucs2strlen((const S8 *)str));
        imc_msg.message_id = MMI_IMC_MESSAGE_CLEAR_HILIGHT;
        imc_msg.param_0 = MMI_TRUE;
        mmi_imc_send_message(&imc_msg);
    #else
        /* insert input area into editor */
        imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
        imc_msg.param_0 = (U32)g_imc.global_data.input_buff;
        imc_msg.param_1 = MMI_FALSE;
        inserted_char_num = mmi_imc_send_message(&imc_msg);

        /* reset input area */
        mmi_imc_reset_input_area();

		g_imc.global_data.cand_filter = MMI_FALSE;
        g_imc.global_data.filter_page = 0xff;
    #endif
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
        {
            mmi_imc_pen_process_vk_state_after_confirm_candidate();
        }
#endif
        g_imc.global_data.cand_length = 0;
        break;
    case MMI_IMC_STATE_HAND_WRITING_CAND:
        mmi_imc_delete_timer();

        mmi_imc_print_string_inserted_to_editor(str, mmi_ucs2strlen((const S8 *)str));
        
	imc_msg.message_id = MMI_IMC_MESSAGE_IS_OVERWRITE_MODE;
        /* handwriting candidate is already in editor, hence, mark inserted_char_num > 0 to get associative candidate. */
        inserted_char_num = 1;
        if (mmi_imc_send_message(&imc_msg))
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_RESET_MULTITAP_STATE;
            mmi_imc_send_message(&imc_msg);
        }
        else
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_CLEAR_HILIGHT;
            imc_msg.param_0 = MMI_TRUE;
            mmi_imc_send_message(&imc_msg);
        #if defined(__MMI_IME_FTE_ENHANCE__)
            imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
            mmi_imc_send_message(&imc_msg);
            g_imc.global_data.cand_length = 0;
        #endif
        } 
        break;
    case MMI_IMC_STATE_CAND_SELECTING:
    case MMI_IMC_STATE_VK_CAND:
	case MMI_IMC_STATE_SPELL_INPUTING_GRID:
    #if defined(__MMI_IME_STROKE_INPUT_WITH_REDICALS__)
        if (g_imc.mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_STROKE)
        {
            if (mmi_ime_word_is_redicals(str[0]))
            {                
                mmi_imui_message_struct imui_msg;
                /* update symbol buffer. */
                memset(g_imc.global_data.symb_buff, 0, sizeof(U16)*MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
                g_imc.global_data.symb_buff[0] = str[0];
                g_imc.global_data.symb_count = 1;
                /* update composition buffer. */
                memset(g_imc.global_data.comp_buff, 0, sizeof(UI_character_type)*MMI_IMC_MAX_COMPOSITION_BUFFSIZE);                
                g_imc.global_data.comp_buff[0] = str[0];
                g_imc.global_data.comp_count = 1;
        
                /* update composition box */
            #if defined(__MMI_IME_FTE_ENHANCE__)
                mmi_imc_update_composition_box_by_query_result_ext(g_imc.global_data.symb_buff, 1, MMI_FALSE, MMI_TRUE);
            #else
                mmi_imc_update_composition_box_by_query_result(g_imc.global_data.symb_buff, 1, MMI_FALSE);
            #endif    
                /* reget candidate by new symbol sequence */
                memset(g_imc.global_data.cand_first_index, 0, sizeof(U16) * MMI_IMC_MAX_CANDIDATE_PAGE);
                g_imc.global_data.cand_page = 0;
                g_imc.global_data.cand_select = 0;
                mmi_imc_change_candidate_box_page();
            #if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
                g_imc.global_data.cand_select = (g_imc.global_data.cand_count - 1) / 2;
            #else
                g_imc.global_data.cand_select = 0;
            #endif
                imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX;
                imui_msg.param_0 = g_imc.global_data.cand_select;
                mmi_imui_send_message(&imui_msg, NULL);
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                return;
            }
        }
    #endif
    #if defined(__MMI_CSTAR_PHRASE_INPUT__) && defined(__MMI_VIRTUAL_KEYBOARD__)
       str =  mmi_imc_check_input_area_confirmed_length(str);
	   if(str == NULL)
	   {
			return;
	   }
    #endif
        mmi_imc_clear_symbol_buffer();
        imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
        imc_msg.param_0 = (U32)str;
        imc_msg.param_1 = MMI_FALSE;
        inserted_char_num = mmi_imc_send_message(&imc_msg);
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
        {
            mmi_imc_pen_process_vk_state_after_confirm_candidate();
        }
#endif
        break;
		#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMC_STATE_CAND_SELECTING_GRID:
	case MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX:
	case MMI_IMC_STATE_ASSOC_SELECTING_GRID:
	case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID:
	#if defined(__MMI_CSTAR_PHRASE_INPUT__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        if (mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID)
		{
			str = mmi_imc_check_input_area_confirmed_length(str);
			if(str == NULL)
			{
				return;
			}
		}
    #endif
        imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
        imc_msg.param_0 = (U32)str;
        imc_msg.param_1 = MMI_FALSE;
	    inserted_char_num = mmi_imc_send_message(&imc_msg);
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
        {
            mmi_imc_pen_process_vk_state_after_confirm_candidate();
        }
#endif
		break;
        
		case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
		#if defined(__MMI_IME_USER_DATABASE__)
        if (*str == MMI_IME_USER_DATABASE_NEW_WORD)
        {
        #if defined(__MMI_IME_CANDIDATE_GRID__)
			g_imc_is_change_from_grid = MMI_FALSE;
        #endif
			mmi_imc_entry_spell_new_word_screen();
		}
		else
		#endif
		{
            mmi_imc_delete_timer();
            imc_msg.message_id = MMI_IMC_MESSAGE_CLEAR_HILIGHT;
            imc_msg.param_0 = MMI_TRUE;
            mmi_imc_send_message(&imc_msg);
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
            if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
            {
                mmi_imc_pen_process_vk_state_after_confirm_candidate();
            }
#endif
		}
		break;
		#endif
	case MMI_IMC_STATE_VK_CAND_MULTITAP:
	case MMI_IMC_STATE_SPELL_MULTITAP:
        mmi_imc_cancel_timer();
		mmi_imc_clear_symbol_buffer();
        imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
        imc_msg.param_0 = (U32)str;
        imc_msg.param_1 = MMI_FALSE;
        inserted_char_num = mmi_imc_send_message(&imc_msg);
		break;
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
        if (g_imc.global_data.key_element_length == 0)
        {
            str = g_imc.global_data.input_buff;
            imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
            imc_msg.param_0 = (U32)str;
            imc_msg.param_1 = MMI_FALSE;
            inserted_char_num = mmi_imc_send_message(&imc_msg);
            break;
        }
        /* for other case, goto default case */
#endif
    default:
        imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
        imc_msg.param_0 = (U32)str;
        imc_msg.param_1 = MMI_FALSE;
        inserted_char_num = mmi_imc_send_message(&imc_msg);
    
        break;
    }
    
    /* to reset the global data */
    g_imc.global_data.cand_count = 0;
    g_imc.global_data.symb_count = 0;
    g_imc.global_data.cand_first_index[0] = 0;
    memset(g_imc.global_data.key_buffer, 0, sizeof(U16) * MMI_IMC_MAX_KEY_BUFFER_SIZE);
    memset(g_imc.global_data.comp_buff, 0, sizeof(UI_character_type) * MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
    g_imc.global_data.key_element_length = 0;
    #ifdef __MMI_CSTAR_PHRASE_INPUT__
    g_imc.global_data.key_buffer_cusor = 0;
    g_imc.global_data.input_confirm_length = 0;
    g_imc.global_data.comp_count = 0;
    #endif

#if defined(__MMI_IME_USER_DATABASE__)
    
    if (str != NULL)
    {
        mmi_ime_word_update_word_frequency(g_imc.mode_details_ptr->imm_mode_id, str);
    }
    
#endif

	#if defined __MMI_XT9__

		mmi_ime_word_reset_first_upper_flag();

	#endif

    
    /* Query and show associated candidates */
    cand_len = mmi_ucs2strlen((const S8*)str);

	if (mmi_imm_is_chinese_word_prediction_enabled() &&
        mmi_imm_is_chinese_input_method(mmi_imm_get_curr_input_mode()) && 
        cand_len > 0 &&
        inserted_char_num > 0 && 
        (str[cand_len - 1] >= 0x4e00 && str[cand_len - 1] <= 0x9fff) )
    { 
		MMI_ASSERT(cand_len <= MMI_IMC_MAX_PRE_STRING_LEN);

		memcpy(&g_imc.global_data.pre_string[0], str, sizeof(UI_character_type) * (cand_len));
    
		g_imc.global_data.pre_string[cand_len] = 0;
    
		query_param.pre_string = g_imc.global_data.pre_string;
		query_param.first_index = 0;
		query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
		query_result.result_buffer = g_imc.global_data.cand_buff;
    
    #if defined __MMI_XT9__
		if(mmi_imc_get_state()==MMI_IMC_STATE_HAND_WRITING_CAND)
		    mmi_ime_word_get_associates_chinese_when_tapped(&query_param, &query_result);
		else
		mmi_ime_word_get_associates(&query_param, &query_result);
    #else
                 mmi_ime_word_get_associates(&query_param, &query_result);
    #endif

		g_imc.global_data.cand_page = 0;
		g_imc.global_data.cand_first_index[0] = 0;
		g_imc.global_data.cand_select= 0;
        
		if (query_result.result_cnt > 0)
		{
        #if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__)
            /* the associative candidate bar for handwriting input should be put near the handwriting panel. */
            if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
            {
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            }
        #endif
			#if defined(__MMI_IME_CANDIDATE_GRID__)
			if(mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX )
			{
				mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
			}
			#endif
			#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)

			cand_count = mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
            #else
                mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
            #endif
		#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
			mmi_imui_message_struct imui_msg;
			g_imc.global_data.cand_select = (cand_count + (cand_count + 2) % 2) / 2 - 1;
			imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX;
			imui_msg.param_0 = (U32)g_imc.global_data.cand_select;
			mmi_imui_send_message(&imui_msg, NULL);
		#endif

        #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
            #if defined(__MMI_CSTAR_PHRASE_INPUT__)
                if(inserted_char_num < cand_len)
				{
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
				}
                else
				{
					mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
				}
            #else
                mmi_imc_set_state(MMI_IMC_STATE_PRE_ASSOC_SELECTING);
            #endif
            
        #else
			#if defined(__OP01__)
			mmi_imui_message_struct imui_msg;
			imui_msg.message_id = MMI_IMUI_MESSAGE_SELECT_AREA_DISABLE_LABEL;
            mmi_imui_send_message(&imui_msg, NULL);
			#endif
			mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
		#endif
		}
		else
		{
			mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
		}
	}
	else
	{
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    } 
}

/*****************************************************************************
 * FUNCTION
*  mmi_imc_get_select_string_from_candidate_box
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
UI_string_type mmi_imc_get_select_string_from_candidate_box(void)
{
       
		return mmi_imc_get_candidate_by_index(g_imc.global_data.cand_buff, g_imc.global_data.cand_select);
		
}
/*****************************************************************************
* FUNCTION
 *  mmi_imc_select_composition_from_composition_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_select_composition_from_composition_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    UI_character_type composition_string[MMI_IMC_MAX_COMPOSITION_BUFFSIZE];
    UI_string_type comp_ptr = mmi_imc_get_candidate_by_index(g_imc.global_data.comp_buff, g_imc.global_data.comp_select);
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset local variable */
//    memset(&composition_string, 0, sizeof(UI_character_type)*MMI_IMC_MAX_COMPOSITION_BUFFSIZE);

#if !(!defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && defined(__MMI_IME_CANDIDATE_GRID__))
    /* record old data */
    g_imc.global_data.old_comp_select = g_imc.global_data.comp_select;
    g_imc.global_data.old_comp_page = g_imc.global_data.comp_page;
    /* reset data */
   // g_imc.global_data.comp_select = 0;
   // g_imc.global_data.comp_page = 0;
#endif

    /* set symbol buffer */
    g_imc.global_data.symb_count = 0;
    for (i = 0; i < mmi_ucs2strlen((const S8*)comp_ptr); i ++)
    {
#if defined(__MMI_IME_CANDIDATE_GRID__) || defined(__MMI_IME_SLIM__)
		if(comp_ptr[i] >= '1' && comp_ptr[i] <= '9')
		{
			g_imc.global_data.symb_buff[i] = comp_ptr[i];//grid state, it will have number in composition
		}
		else
		{
			g_imc.global_data.symb_buff[i] = mmi_ime_word_code_to_symbol(comp_ptr[i]);
		}
#else
		g_imc.global_data.symb_buff[i] = mmi_ime_word_code_to_symbol(comp_ptr[i]);
#endif

		//g_imc.global_data.symb_buff[i] = comp_ptr[i];
        g_imc.global_data.symb_count ++;
    }

    /* update composition buffer. clear other composition. */
//    mmi_ucs2cpy((S8*)&composition_string, (S8*)comp_ptr);
#if !(!defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && defined(__MMI_IME_CANDIDATE_GRID__))
  //  mmi_ucs2cpy((S8*)g_imc.global_data.comp_buff, (S8*)comp_ptr);
    mmi_imc_update_composition_box_by_query_result(g_imc.global_data.comp_buff, g_imc.global_data.comp_count, MMI_FALSE);
#endif
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_highlighted_candidate_from_candidate_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_change_highlighted_candidate_from_candidate_box(U8 candidate_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
	mmi_imui_message_struct imui_msg;
    UI_string_type str;
    mmi_imc_state_enum state;
    S32 i = 0;
    S32 cand_len = 0;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (candidate_index == g_imc.global_data.cand_select)
	{
		return;
	}

    state = mmi_imc_get_state();

    switch(state)
    {
        case MMI_IMC_STATE_SMART_CANDIDATE:
        case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
			#if defined(__MMI_IME_CANDIDATE_GRID__)
		case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
			#endif
        mmi_imc_gdi_lcd_freeze(TRUE);
            mmi_imc_key_smart_alphabetic_insert_candidate(candidate_index);
			imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX;
            imui_msg.param_0 = candidate_index;
            mmi_imui_send_message(&imui_msg, NULL); 
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON))
            {
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
            }
        #endif     
        mmi_imc_gdi_lcd_freeze(gdi_freeze);; 

            mmi_imc_repaint_screen();
			mmi_imc_key_set_softkey();
            break;
    #if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)
        case MMI_IMC_STATE_HAND_WRITING_CAND:            
        mmi_imc_gdi_lcd_freeze(TRUE);                 
            imc_msg.message_id = MMI_IMC_MESSAGE_IS_OVERWRITE_MODE;
            mmi_imc_pen_restart_hw_timer();
            if (mmi_imc_send_message(&imc_msg))
            {
                str = mmi_imc_get_candidate_by_index(g_imc.global_data.cand_buff, candidate_index);
            #if defined (__MMI_MULTIGRAPH_SUPPORT__)
                if (mmi_ucs2strlen((const S8 *)str)>=2)
                {
                    imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING;
                    imc_msg.param_0 = (U32)str;
                }
                else
            #endif
                {
                    imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR;
                    imc_msg.param_0 = (U32)str[0];
                }
                mmi_imc_send_message(&imc_msg);
            }
            else
            {	
                str = mmi_imc_get_candidate_by_index(g_imc.global_data.cand_buff, candidate_index);
                imc_msg.message_id = MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING;
                imc_msg.param_0 = (U32)g_imc.global_data.cand_length;
                imc_msg.param_1 = (U32)str;
                cand_len = mmi_imc_send_message(&imc_msg);
                g_imc.global_data.cand_length = cand_len;
                if (!cand_len)
                {
                    imc_msg.message_id = MMI_IMC_MESSAGE_CLEAR_HILIGHT;
                    imc_msg.param_0 = 0;
                    imc_msg.param_1 = 0;
                    mmi_imc_send_message(&imc_msg);
                }    
            }
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON))
            {
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
            }
        #endif  
            mmi_imc_key_set_softkey();
            mmi_imc_gdi_lcd_freeze(gdi_freeze);
            mmi_imc_repaint_screen();

            break;
    #endif
    }
    UI_UNUSED_PARAMETER(i);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_highlighted_composition_from_composition_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_change_highlighted_composition_from_composition_box(U8 candidate_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0;
    UI_string_type comp = NULL;
    U16 symbol_buffer[MMI_IMC_MAX_COMPOSITION_BUFFSIZE];
    S32 i = 0;
    U32 k = 0;
	#if defined __MMI_XT9__
    S32 temp_var;
    #endif
    mmi_ime_query_param_struct param_ptr;
    mmi_ime_query_result_struct result_ptr;
    mmi_imui_message_struct imui_msg;
    S32 temp_count = 0;
    #if defined __MMI_XT9__
    U32 j = 0;
    candidate_flag = 1; //NEW_CANDIDATE
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset local variable */
    memset(symbol_buffer, 0, MMI_IMC_MAX_COMPOSITION_BUFFSIZE*sizeof(U8));
    memset(&param_ptr, 0, sizeof(param_ptr));   
    memset(&result_ptr, 0, sizeof(result_ptr));
    memset(&imui_msg, 0, sizeof(mmi_imui_message_struct));
    
    comp = mmi_imc_get_candidate_by_index(g_imc.global_data.comp_buff, g_imc.global_data.comp_select);
    if (comp == NULL)
        return 0;

    /* translate ucs2 code to query symbol. */
    while(comp[i] != '\0')
    {
        if (comp[i]==0x0019) //ET9CP_SEGMENT_DELIMITER xT9
        {
            i++;
            continue;
        }
        symbol_buffer[temp_count] = mmi_ime_word_code_to_symbol(comp[i]);
		if (symbol_buffer[temp_count] == 0xFF)
		{
			if (comp[i] >= '1' && comp[i] <= '9')
            {
                symbol_buffer[temp_count] = comp[i];
            }
            else
		{
			return 0;
		}
		}
        i ++;
        temp_count++;
    }
    if (i == 0)
        return 0;

    /* set parameter */
    
    /* find which candidate is to be hilited */
#if defined __MMI_XT9__
    /* macro can be removed after testing */

    temp_var = g_imc.global_data.comp_page-1;
    while( temp_var >=0)
    {
        
        k = k+ (g_imc.global_data.comp_first_index[j+1]);
        j++;
        temp_var--;
    }
    
#endif
    param_ptr.comp_selected = g_imc.global_data.comp_select+k  ;  
    param_ptr.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(mmi_imc_is_grid_state())
	{
            param_ptr.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
	}
	#endif
    param_ptr.elembuf_cnt = temp_count; // i , changed to check for the delimiter
    param_ptr.elembuf_ptr = symbol_buffer;
    param_ptr.first_index = candidate_index;
    param_ptr.tone_value = MMI_IMC_SYMB_TONE_NONE;
    result_ptr.result_buffer = g_imc.global_data.cand_buff;
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    result_ptr.match_length_table = g_imc.global_data.cand_match_len;
#endif

#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(mmi_imc_is_grid_state())
	{
		mmi_imc_get_candidates_from_word_engine(&param_ptr, &result_ptr);
	}
	else
#endif
	{
		mmi_ime_word_get_candidates(&param_ptr, &result_ptr);
	}
    cand_count = result_ptr.result_cnt;

    if (cand_count)
    {
        /* reset candidate page and index */
        g_imc.global_data.cand_page = 0;
        g_imc.global_data.cand_select = 0;

        cand_count = mmi_imc_update_candidate_box_by_query_result(
                                result_ptr.result_buffer, 
                                result_ptr.result_cnt, 
                                result_ptr.next_page);
    #if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
        g_imc.global_data.cand_select = (cand_count + (cand_count + 2) % 2) / 2 - 1;
        imui_msg.message_id = MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX;
        imui_msg.param_0 = (U32)g_imc.global_data.cand_select;
        mmi_imui_send_message(&imui_msg, NULL);
    #endif
    }

    return cand_count;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_candidate_index_mapping
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_candidate_index_mapping(S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = - 1;
    S32 byte_index = 0;
    S32 bit_index = 7;
    U8 one_byte = 0;
    S32 counter = 0;
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
    S32 max_cand_count_in_one_page = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN_VER;
#else
    S32 max_cand_count_in_one_page = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    one_byte = g_imc.global_data.cand_valid_flags[0];
    while ( counter < (*index) + 1 && (byte_index < ((MMI_IMC_MAX_CANDIDATE_PAGE*max_cand_count_in_one_page)/8 - 1)))
    {
        if (counter >= g_imc.global_data.cand_check_cnt)
            ASSERT(0);
        i ++;
        bit_index = 7 - (i % 8);
        if ((one_byte & (1 << bit_index)))
        {
            counter ++;
        }
        if (bit_index == 0)
        {
            byte_index ++;
            one_byte = g_imc.global_data.cand_valid_flags[byte_index];
        }
    }

    (*index) = i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_candidate_valid_flag
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_candidate_valid_flag(S32 index, S32 flags, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 byte_index = (index >> 3);
    S32 bit_index = 7 - (index % 8);
    S32 counter = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (counter = 0; counter < len; counter++)
    {
        byte_index = (index >> 3);
        bit_index = 7 - (index % 8);
        if (flags & (1 << (len-counter - 1)))
        {
            g_imc.global_data.cand_valid_flags[byte_index] |= (1 << bit_index);
        }
        else
        {
            g_imc.global_data.cand_valid_flags[byte_index] &= (~(1 << bit_index));
        }
        index ++;
    }
    g_imc.global_data.cand_check_cnt = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_reset_candidate_valid_flag
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_reset_candidate_valid_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc.global_data.cand_check_cnt = 0;

#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
    memset(g_imc.global_data.cand_valid_flags, 0, sizeof(U8)*((MMI_IMC_MAX_CANDIDATE_PAGE*MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN_VER)/8));
#else
    memset(g_imc.global_data.cand_valid_flags, 0, sizeof(U8)*((MMI_IMC_MAX_CANDIDATE_PAGE*MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN)/8));
#endif
}

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_V3__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_smart_alphabetic_candidates_for_qwerty
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_get_smart_alphabetic_candidates_for_qwerty( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    S16 key_code = 0;
    U16 search_index = 0, i;
    UI_character_type input_string[20];
	mmi_ime_query_param_struct query = {0};
	memcpy(&query, param_ptr, sizeof(mmi_ime_query_param_struct));
    #if defined __MMI_CSTAR__
    mmi_imm_qwerty_get_group_letters_for_cur_lang(g_imc.mode_details_ptr->lang_id);
    for (i = 0; i < query.elembuf_cnt; i++)
    {
        key_code = mmi_imc_key_get_mmi_key_code_of_symbol_key(param_ptr->elembuf_ptr[i]);
        
    
        search_index = key_code - KEY_A;
        input_string[i] = g_mmi_imm_cur_lang_group_letter_table[search_index][0];
    
   
     }
	query.elembuf_ptr = input_string;
     #endif
    mmi_ime_word_get_candidates(&query, result_ptr);

}
#endif
#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_duplicated_candidate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_imc_is_duplicated_candidate(UI_string_type src, UI_string_type cand, S32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, str_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < count; i++)
    {
        if (!mmi_ucs2cmp((const S8 *)src, (const S8 *)cand))
        {
            return MMI_TRUE;
        }
        else
        {
            str_len = (S32)mmi_ucs2strlen((const S8 *)src);
            src += (str_len + 1);
        }
    }

    return MMI_FALSE;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_candidates_from_word_engine
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_imc_get_candidates_from_word_engine( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL changed = MMI_FALSE;
    S32 count = 0, i = 0, j = 0;
    S32 first_index = 0;
    S32 cand_len = 0;
    mmi_ime_query_param_struct query = {0};
    mmi_ime_query_result_struct result = {0};
    S32 cand_len_total = 0;
    S32 flags = 0;
    U8 valid_flag = 0;
    MMI_BOOL check = MMI_FALSE;
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined __MMI_COSMOS_SLIDING_QWERTY__
    S32 temp_cand_count;
#endif
    UI_string_type cand_buff = result_ptr->result_buffer, temp_ptr;
    kal_uint32 time1, time2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (param_ptr->elembuf_cnt == 0)
    {
        result_ptr->result_cnt = 0;
        result_ptr->next_page = MMI_FALSE;
        return;
    }
    
    /* We should display more symbols in one page, but we can't enlarge MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN, */
	/* because it may result in performance problem */
	/* This is a very special solution for this case */
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
    if (param_ptr->desired_cnt > MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN_VER)
    {
        param_ptr->desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN_VER;
    }
#else
	if (param_ptr->elembuf_ptr[0] == MMI_IMC_SYMB_KEY_1 && param_ptr->elembuf_cnt <= 3)
	{
        param_ptr->desired_cnt = param_ptr->desired_cnt * 3 / param_ptr->elembuf_cnt;
	}
#endif


    memcpy(&query, param_ptr, sizeof(mmi_ime_query_param_struct));
    memcpy(&result, result_ptr, sizeof(mmi_ime_query_result_struct));

	if(!mmi_imm_is_chinese_input_method(mmi_imm_get_current_input_mode()))
	{
		if (g_imc.global_data.symb_count_backup != g_imc.global_data.symb_count)
		{
			changed = MMI_TRUE;
		}
		else if (memcmp (g_imc.global_data.symb_buff, g_imc.global_data.symb_buff_backup, g_imc.global_data.symb_count) != 0)
		{
			changed = MMI_TRUE;
		}
		else if (!g_imc.global_data.cand_check_cnt)
		{
			changed = MMI_TRUE;
		}
    
		if (changed && param_ptr->first_index)
		{
			ASSERT(0);
		}
	}
    count = param_ptr->desired_cnt;
    first_index = param_ptr->first_index;
    if (!changed && !mmi_imm_is_chinese_input_method(mmi_imm_get_current_input_mode())) 
    {
        /* first index mapping */
        mmi_imc_candidate_index_mapping(&first_index); //only used for latin languages       
    }
    query.desired_cnt = param_ptr->desired_cnt + 1;
    result.result_buffer = g_mmi_imc_temp_cand;
    query.first_index = first_index;

    while (i < count + 1) /* to get more one item to check the next page. */    
    {
        query.desired_cnt -= i;

		if (query.desired_cnt <= 0)
		{
			break;
		}
        kal_get_time(&time1);
/* if qwerty and xt9 bothe are enabld donot enter this code */
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && !defined (__MMI_XT9__)&& defined(__MMI_IME_V3__)
	#if defined __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == OPEN && !mmi_imm_is_chinese_input_method(mmi_imm_get_current_input_mode()))
        {        
			mmi_imc_get_smart_alphabetic_candidates_for_qwerty(&query, &result);
        }
        else
        {
            mmi_ime_word_get_candidates(&query, &result);
        }
    #else
		if(mmi_imm_is_chinese_input_method(mmi_imm_get_current_input_mode()))
		{
			mmi_ime_word_get_candidates(&query, &result);
		}
		else
		{
			mmi_imc_get_smart_alphabetic_candidates_for_qwerty(&query, &result);
		}
	#endif
#endif

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        {
        mmi_ime_word_get_candidates(&query, &result);
        }
    #endif
        kal_get_time(&time2);
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_FW_SMART_CANDIDATES_RECOGNITION_TIME, kal_ticks_to_milli_secs(time2 - time1));
        if (!result.result_cnt)
            break;

		temp_ptr = &g_mmi_imc_temp_cand[0];
		j = 0;

        while (j < result.result_cnt)
		{
			cand_len = mmi_ucs2strlen((const S8*)temp_ptr);

	#if defined(__MMI_IME_USER_DATABASE__)
			if (temp_ptr[0] == MMI_IME_USER_DATABASE_NEW_WORD && cand_len == 1)
			{ /* New word item is always valid */
				check = MMI_TRUE;
			}
			else
	#endif
			if (cand_len > MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE)
		    {
                check = MMI_FALSE;
		    }  
            else if (!changed && g_imc.global_data.symb_count != 0 && query.first_index + j < g_imc.global_data.cand_check_cnt)
			{
				/* get old data  */
				valid_flag = g_imc.global_data.cand_valid_flags[(query.first_index + j)/8];
				if ( (valid_flag & (1 << (7 - (query.first_index + j) % 8))))
				{
					check = MMI_TRUE;
				}
				else
				{
					check = MMI_FALSE;
				}
			}
			else
			{
				/* check for new candidate */
				if (mmi_imc_candidate_check(temp_ptr, cand_len))
				{
					check = MMI_TRUE;
				}
				else
				{
					check = MMI_FALSE;
				}
			}

			/* special case for Zi hint symbol ">" */
			if (query.elembuf_cnt == 1 && query.first_index + j == 0 && result.result_buffer[0] == MMI_IMC_HINT_CANDIDATE)
			{
            #if defined(__MMI_IME_CANDIDATE_FILTER__)
                if(g_imc.global_data.cand_filter)
				{
                    check = MMI_FALSE;
				}
				else
            #endif
				{
                    check = MMI_TRUE;
				}
			}

	#if defined(__MMI_IME_CANDIDATE_FILTER__)
			if (g_imc.global_data.cand_filter)
			{
				if (!mmi_imc_key_smart_alphabetic_filter_candidate(temp_ptr))
				{
					g_imc.global_data.filter_page = g_imc.global_data.cand_page;
					check = MMI_FALSE;
				}
			}
	#endif

			if (check || mmi_imm_is_chinese_input_method(mmi_imm_get_current_input_mode()))
			{
				if (cand_len_total + cand_len + 1 > MMI_IMC_MAX_CANDIDATE_BUFFSIZE)
				{
					break;
				}
				else
				{
					memcpy(cand_buff + cand_len_total, temp_ptr, sizeof(UI_character_type)*cand_len);
					cand_len_total+= (cand_len + 1);
					result_ptr->result_buffer[cand_len_total - 1] = '\0';
					flags = ((flags << 1) | 1);            
					i++;
				}
			}
			else
			{
				flags = (flags << 1);            
			}

			j++;
			temp_ptr += (cand_len + 1);
		}

        query.first_index += result.result_cnt;
        
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && !defined(__MMI_IME_V3__)
	#if defined __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status()== OPEN)
	#endif
        {
        if (!result.next_page)
            break;
        }
#endif
		#if defined(__MMI_IME_CANDIDATE_GRID__)
		if(mmi_imc_is_grid_state()) 
		{
			if(mmi_imm_is_chinese_input_method(mmi_imm_get_curr_input_mode()) && result.result_cnt < 9) //cstar only can return 9 candidate at one time
			{
				break; // chinese input mode doed not need to qury again to check the new word case
			}
		}
		#endif
    }
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
	if(mmi_imm_get_current_input_mode() == IMM_INPUT_MODE_SM_PINYIN)
	{			
		result_ptr->composition_result_cnt = result.composition_result_cnt;			
	}
#endif
    result_ptr->result_cnt = ((i > count)? count: i);

    if (i <= count)
    {
        result_ptr->next_page = MMI_FALSE;
    }
    else
    {
        result_ptr->next_page = MMI_TRUE;
    }

#if defined(__MMI_IME_USER_DATABASE__)
	if (result_ptr->result_cnt == 0 && !mmi_imm_is_chinese_input_method(mmi_imm_get_curr_input_mode()))
	{
		result_ptr->result_cnt = 1;
		result_ptr->next_page = MMI_FALSE;
		result_ptr->result_buffer[0] = MMI_IME_USER_DATABASE_NEW_WORD;
        result_ptr->result_buffer[1] = 0;
    }
#endif

#if defined(__MMI_ZI__) && !defined(__MMI_IME_VERTICAL_CAND_BOX__)
    /* special case for Zi hint symbol ">" */
    if (query.elembuf_cnt == 1 && 
        param_ptr->first_index == 0 && 
        result_ptr->result_buffer[0] == MMI_IMC_HINT_CANDIDATE &&
        i > 1)
    {
        result_ptr->next_page = MMI_TRUE;
        result_ptr->result_cnt = 1;
    }
#endif


    if (result_ptr->result_cnt != 0)
    {
    #if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
 
        if (g_imc.global_data.capital_state != MMI_IME_WORD_CAPITAL_STATE_NONE)
        {
            temp_cand_count = g_imc.global_data.cand_count;
            g_imc.global_data.cand_count = result_ptr->result_cnt;

        #if defined(__MMI_IME_CANDIDATE_FILTER__)
            if(g_imc.global_data.cand_filter)
			{
                g_imc.global_data.cand_count++;
			}
        #endif

        #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
            mmi_imc_change_candidate_list_by_caps_seq();
        #else
            mmi_imc_change_candidate_list_caps(g_imc.global_data.capital_state);
        #endif
        
            g_imc.global_data.cand_count = temp_cand_count;
        }
    #endif	
	#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_IME_SLIM__) && defined(__MMI_GUOBI__)
	#if defined __MMI_COSMOS_KEYPAD_SLIDER__
		if(mmi_imc_get_slider_status()== OPEN)
	#endif
		{
			g_imc.global_data.cand_count = result_ptr->result_cnt;
			if(mmi_imm_get_current_input_case() == MMI_IME_HINT_FLAG_FIRST_UPPER_CASE)
			{
				mmi_imc_change_candidate_list_caps(MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER);
				g_imc.global_data.capital_state = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
			}
			else if((mmi_imm_get_current_input_case() == MMI_IME_HINT_FLAG_UPPER_CASE))
			{
				mmi_imc_change_candidate_list_caps(MMI_IME_WORD_CAPITAL_STATE_UPPER);
				g_imc.global_data.capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
			}
		}
	#endif
        if (changed && !mmi_imm_is_chinese_input_method(mmi_imm_get_current_input_mode()))
        {
            mmi_imc_reset_candidate_valid_flag();
            memcpy(g_imc.global_data.symb_buff_backup, g_imc.global_data.symb_buff, sizeof(U16)*MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
            g_imc.global_data.symb_count_backup = g_imc.global_data.symb_count;
        }
    #if defined(__MMI_IME_USER_DATABASE__)
        if (!(result_ptr->result_cnt == 1 && result_ptr->result_buffer[0] == MMI_IME_USER_DATABASE_NEW_WORD) && !mmi_imm_is_chinese_input_method(mmi_imm_get_current_input_mode()))
    #endif
        {
            mmi_imc_set_candidate_valid_flag(first_index, flags, query.first_index - first_index);      
        }
    }
#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(mmi_imc_is_grid_state())
	{
		if(g_imc.global_data.cand_page + 1 >= MMI_IMC_MAX_GRID_CANDIDATE_PAGE)
		{
			result_ptr->next_page = MMI_FALSE;
		}
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_candidate_box_page
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_change_candidate_box_page(void)/* May be moved to imc.c */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    mmi_ime_query_param_struct   query_param = {0};
    mmi_ime_query_result_struct  query_result = {0};
    #if defined __MMI_XT9__
    candidate_flag = 0; //OLD_CANDIDATE
    #endif
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)    
    UI_character_type sym[MMI_IMC_MAX_KEY_NUM] = {0};
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_ASSOC_SELECTING:
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMC_STATE_ASSOC_SELECTING_GRID:
	#endif
        query_param.pre_string = g_imc.global_data.pre_string;
        query_param.first_index = g_imc.global_data.cand_first_index[g_imc.global_data.cand_page];
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
		#if defined(__MMI_IME_CANDIDATE_GRID__)
		if( mmi_imc_is_grid_state() )
		{
			 query_param.desired_cnt =MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
		}
		#endif
        query_result.result_buffer = g_imc.global_data.cand_buff;

        mmi_ime_word_get_associates(&query_param, &query_result);
        mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
        break;
        
#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
        query_param.pre_string = g_imc.global_data.pre_string;
        query_param.first_index = g_imc.global_data.cand_first_index[g_imc.global_data.cand_page];
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
        query_result.result_buffer = g_imc.global_data.cand_buff;
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        {
            mmi_event_struct evt;
            
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);
            
            MMI_FRM_CB_EMIT_EVENT(&evt);
        }
    #endif
    #endif

        mmi_imc_get_associates_from_word_engine(&query_param, &query_result);
        mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
        break;
#endif
		#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMC_STATE_CAND_SELECTING_GRID:
	case MMI_IMC_STATE_SPELL_INPUTING_GRID:
	case MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX:
	case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
		#endif
    case MMI_IMC_STATE_VK_CAND:
    case MMI_IMC_STATE_CAND_SELECTING:
        #ifdef __MMI_CSTAR_PHRASE_INPUT__
        if (mmi_imc_is_qwerty_smart_pinyin_input())
        {
            query_param.elembuf_cnt = g_imc.global_data.symb_count - g_imc.global_data.input_confirm_length;
            query_param.elembuf_ptr = g_imc.global_data.symb_buff + g_imc.global_data.input_confirm_length;
        }
        else
        {
            query_param.elembuf_ptr= g_imc.global_data.symb_buff;
            query_param.elembuf_cnt= g_imc.global_data.symb_count;
        }
        #else
        query_param.elembuf_ptr= g_imc.global_data.symb_buff;
        query_param.elembuf_cnt= g_imc.global_data.symb_count;
        #endif
        query_param.tone_value = (U8)g_imc.global_data.tone;
        query_param.first_index = g_imc.global_data.cand_first_index[g_imc.global_data.cand_page];
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
		
        query_result.result_buffer = g_imc.global_data.cand_buff;
        query_param.comp_selected = g_imc.global_data.old_comp_select ;

    #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
        query_result.match_length_table = g_imc.global_data.cand_match_len;
    #endif
	#if defined(__MMI_IME_CANDIDATE_GRID__)
		if(mmi_imc_is_grid_state())
		{
            query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
		#if defined(__MMI_CSTAR__)
			mmi_imc_get_candidates_from_word_engine(&query_param, &query_result);
		#else
			if(g_imc.fsm_object.curr_state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC)
			{
				mmi_imc_get_candidates_from_word_engine(&query_param, &query_result);
			}
			else
			{
			mmi_ime_word_get_candidates(&query_param, &query_result);
			}
		#endif
		}
		else
		{
			 mmi_ime_word_get_candidates(&query_param, &query_result);
		}
	#else
        mmi_ime_word_get_candidates(&query_param, &query_result);
	#endif
        mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
        break;
    case MMI_IMC_STATE_SMART_CANDIDATE:
        if (!mmi_imc_key_smart_alphabetic_get_candidate(g_imc.global_data.cand_first_index[g_imc.global_data.cand_page]))
        {
            ret = MMI_FALSE;
        }
        break;
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    #ifdef __MMI_CSTAR_PHRASE_INPUT__
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
    #endif
    case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT:
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID:
#endif
        query_param.elembuf_ptr = g_imc.global_data.key_buffer;
        query_param.elembuf_cnt = g_imc.global_data.key_element_length;
        query_param.first_index = g_imc.global_data.cand_first_index[g_imc.global_data.cand_page];
        query_param.composition_desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
        query_param.composition_first_index = g_imc.global_data.comp_first_index[g_imc.global_data.comp_page];
        if (g_imc.global_data.comp_select != 0xff)
        {
            query_param.composition_index = query_param.composition_first_index + g_imc.global_data.comp_select;
        }
        else
        {
            query_param.composition_index = g_imc.global_data.comp_select;
        }
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
		
		query_param.tone_value = MMI_IMC_SYMB_TONE_NONE;

        query_result.composition_buffer = g_imc.global_data.comp_buff;
        query_result.result_buffer = g_imc.global_data.cand_buff;
        query_result.symbol_string = sym;
        query_result.match_length_table = g_imc.global_data.cand_match_len;
        

     #if defined(__MMI_IME_CANDIDATE_GRID__)
		if( mmi_imc_is_grid_state() )
		{
			 query_param.desired_cnt =MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
			 mmi_imc_get_candidates_from_word_engine(&query_param, & query_result);
		}
		else
		{
			mmi_ime_word_get_candidates(&query_param, & query_result);
		}
	#else
		mmi_ime_word_get_candidates(&query_param, & query_result);
	#endif
        
        mmi_imc_update_candidate_box_by_query_result(
                                query_result.result_buffer, 
                                query_result.result_cnt, 
                                query_result.next_page);
        
        break;
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)      
    case MMI_IMC_STATE_HAND_WRITING_CAND:
        mmi_imc_pen_update_hw_cand_by_index(g_imc.global_data.cand_first_index[g_imc.global_data.cand_page]);
        break;
#endif        
    default:
        break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_composition_box_page
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_change_composition_box_page(void)/* May be moved to imc.c */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    mmi_ime_query_param_struct   query_param = {0};
    mmi_ime_query_result_struct  query_result = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_SPELL_INPUTING:
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMC_STATE_SPELL_INPUTING_GRID:
	#endif
        query_param.elembuf_ptr= g_imc.global_data.key_buffer;
        query_param.elembuf_cnt= g_imc.global_data.key_element_length;
        query_param.first_index = g_imc.global_data.comp_first_index[g_imc.global_data.comp_page];
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
        query_result.result_buffer = g_imc.global_data.comp_buff;

        mmi_ime_word_get_spellings(&query_param, &query_result);
        mmi_imc_update_composition_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
        break;
        
    default:
        break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_composition_box_by_query_result
 * DESCRIPTION
 *  To update composition box
 *  The content of result_buffer would not be copied. The content should be kept by caller.
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_update_composition_box_by_query_result(
        UI_string_type      result_buffer,
        U8                  result_cnt,
        MMI_BOOL            next_page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_update_composition_box_by_query_result_ext(result_buffer, result_cnt, next_page, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_composition_box_by_query_result_ext
 * DESCRIPTION
 *  To update composition box
 *  The content of result_buffer would not be copied. The content should be kept by caller.
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_update_composition_box_by_query_result_ext(
        UI_string_type      result_buffer,
        U8                  result_cnt,
        MMI_BOOL            next_page,
        MMI_BOOL            is_auto_resizable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imui_update_selection_area_struct  update_struct;
    S32 comp_insert = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (result_buffer == NULL)
        return 0;

    if (result_cnt > 0)
    {
        update_struct.count = result_cnt;
        update_struct.highlight_index = g_imc.global_data.comp_select;
        update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
		#ifdef __OP01_FWPBW__
		if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_STROKE)
		{
			/*no need to show arrow for cmcc phone in stroke input mode*/
              update_struct.flags &= ~MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
		}
        #endif
        if (next_page)
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_NEXT_PAGE;
        }

        if (g_imc.global_data.comp_page > 0)
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_PRE_PAGE;
        }
        
#if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
		
		if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN)
		{
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_SHOW_STAR;
		}
		
#endif
#if defined(__MMI_IME_SCROLLING_COMPOSITION__) && defined(__MMI_IME_CANDIDATE_GRID__)
        if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN  && !(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY) && g_imc.fsm_object.curr_state != MMI_IMC_STATE_CAND_SELECTING_GRID &&  g_imc.fsm_object.curr_state != MMI_IMC_STATE_SPELL_INPUTING_GRID)//also stroke mode
		{
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL;
		}

#endif
        
#if defined(__MMI_IME_SCROLLING_COMPOSITION__)
		if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN )//also stroke mode
	   {
  if(!(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY))
{

		   update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_SCROLLING_COMPOSITION_BOX;
	   }
	   }

#endif

    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
        if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON))
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_FLOATING;
        }
    #if defined(__MMI_IME_FTE_ENHANCE__)
        if (is_auto_resizable)
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE;
        }
    #endif
    #endif    
        
        update_struct.separator = 0;
        update_struct.str_ptr = result_buffer;
        g_imc.global_data.comp_count = result_cnt;
        
        imui_msg.message_id = MMI_IMUI_MESSAGE_UPDATE_COMPOSITION_BOX;
        imui_msg.param_0 = (U32)&(update_struct);
        
        comp_insert = mmi_imui_send_message(&imui_msg, NULL);

        /* get more composition but the composition buffer is not enough to insert those composition */
        if (g_imc.global_data.comp_page + 1 < MMI_IMC_MAX_COMPOSITION_PAGE)
        {
            if (comp_insert < g_imc.global_data.comp_count)
            {
                g_imc.global_data.comp_first_index[g_imc.global_data.comp_page + 1] = g_imc.global_data.comp_first_index[g_imc.global_data.comp_page] + comp_insert;
                g_imc.global_data.comp_count = comp_insert;
            }
            else if (comp_insert == g_imc.global_data.comp_count)
            {
                /* the composition buffer is big enough to insert all composition */
                if (next_page)
                {
                    g_imc.global_data.comp_first_index[g_imc.global_data.comp_page + 1] = g_imc.global_data.comp_first_index[g_imc.global_data.comp_page] + g_imc.global_data.comp_count;
                }
                else
                {
                    g_imc.global_data.comp_first_index[g_imc.global_data.comp_page + 1] = 0;
                }
            
            }
            else 
            {
                /* insert more composition then get */
                MMI_ASSERT(0);
            }
        }
    	else if (g_imc.global_data.comp_page < MMI_IMC_MAX_COMPOSITION_PAGE)
    	{
    	    if (comp_insert < g_imc.global_data.comp_count)
    	    {
    	        g_imc.global_data.comp_count = comp_insert;
    	    }

    	    g_imc.global_data.comp_first_index[g_imc.global_data.comp_page + 1] = 0;
    	}
        else
        {
            MMI_ASSERT(0);
        }
    }
    return g_imc.global_data.comp_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_candidate_box_by_query_result
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_update_candidate_box_by_query_result(
        UI_string_type      result_buffer,
        U8                  result_cnt,
        MMI_BOOL            next_page) /* May be moved to imc.c */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_update_candidate_box_by_query_result_ext(result_buffer, result_cnt, next_page, MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_candidate_box_by_query_result_ext
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_update_candidate_box_by_query_result_ext(
        UI_string_type      result_buffer,
        U8                  result_cnt,
        MMI_BOOL            next_page,
        MMI_BOOL            is_vertical) /* May be moved to imc.c */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imui_update_selection_area_struct  update_struct;
    S32 cand_insert = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if((g_imc.global_data.cand_page + 1) == MMI_IMC_MAX_CANDIDATE_PAGE)
	{
		next_page = MMI_FALSE;
	}
    if (result_buffer == NULL || result_cnt == 0)
        return 0;

    if (result_cnt > 0)
    {
        update_struct.count = result_cnt;
        update_struct.highlight_index = g_imc.global_data.cand_select;
        update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW /*| MMI_IMUI_SELECTION_AREA_FLAG_R2L */;
        if (next_page)
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_NEXT_PAGE;
        }

	if (g_imc.global_data.cand_page == MMI_IMC_MAX_CANDIDATE_PAGE - 1)
	{
	    update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_LAST_PAGE;
	}

        if (g_imc.global_data.cand_page > 0 && g_imc.global_data.cand_count)
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_PRE_PAGE;
        }
        
        if (mmi_imm_test_r2l_input())
        {   
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_R2L;
        }
#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
        if (mmi_imm_is_chinese_input_method(mmi_imm_get_curr_input_mode()) && mmi_imm_get_curr_input_type() != IMM_INPUT_TYPE_QUICK_SEARCH)
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_CENTER_INDEX;
        }
#endif
		if (g_imc.fsm_object.imui_set & MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA))
		{
            if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_CAND_SELECTING
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_HAND_WRITING_CAND
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_VK_CAND
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_SMART_CANDIDATE
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_MULTITAP
                || g_imc.fsm_object.curr_state == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT
				|| g_imc.fsm_object.curr_state == MMI_IMC_STATE_VK_CAND_MULTITAP)
            {
                update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_FOCUS;
            }
            else
            {
                update_struct.flags &= ~MMI_IMUI_SELECTION_AREA_FLAG_FOCUS;
            }
		}
	#if defined(__OP01__)
	if(g_imc.fsm_object.curr_state == MMI_IMC_STATE_ASSOC_SELECTING)
	{
			 update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_DISABLE_LABEL;
	}
	#endif
    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
    #if defined(__MMI_IME_VERTICAL_CAND_BOX__)
        if (is_vertical
        	#if defined(__ATV_SMS_SUPPORT__)
    		&& !mmi_imc_is_in_atv_editor()
    		#endif /* defined(__ATV_SMS_SUPPORT__)*/
    		)
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL;
        }
        else
    #endif
        if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON))
        {
            update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_FLOATING;
        }
    #endif        
	#if defined(__MMI_IME_CANDIDATE_GRID__)
		{
			const sIMEModeDetails * inputmode_detail = NULL;
			mmi_imm_input_mode_enum input_mode;
			inputmode_detail = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
			
		input_mode = mmi_imm_get_curr_input_mode();
			 if (((inputmode_detail->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
				  || input_mode == IMM_INPUT_MODE_TR_BOPOMO
                || input_mode == IMM_INPUT_MODE_SM_PINYIN
				|| input_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN
				  || input_mode == IMM_INPUT_MODE_SM_STROKE
				  || input_mode == IMM_INPUT_MODE_TR_STROKE
				  || input_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO) 
				  && !mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON)
				  && MMI_VIRTUAL_KEYBOARD_LANG != GUI_VIRTUAL_KEYBOARD_TRAY
				)
    
            {
        update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_SHOW_EXPAND_BUTTON;
		update_struct.flags &= ~MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
		  }
		}

		
	#endif
        update_struct.separator = 0;
        update_struct.str_ptr = g_imc.global_data.cand_buff;
        g_imc.global_data.cand_count = result_cnt;
        imui_msg.message_id = MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX;
        imui_msg.param_0 = (U32)&(update_struct);
        
    /* In capital switch, we should make sure the candidate box can include the same number of */
    /* candidates in different word case, so fisrtly we use upper case words to get the right  */
    /* amount of candidates can be included */
    #if (defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__)) && !defined(__MMI_IME_AUTO_CAPITALIZATION__)&& !defined __MMI_XT9__ && !defined(__MMI_IME_SLIM__)
		if (g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_LOWER
            || g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER 
            || g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_NONE)
		{
		#if defined(__MMI_IME_CANDIDATE_GRID__)
			if(!mmi_imc_is_grid_state())
		#endif
			{
				mmi_imc_change_candidate_list_caps(MMI_IME_WORD_CAPITAL_STATE_UPPER);
			}
		}
    #endif
        
        cand_insert = mmi_imui_send_message(&imui_msg, NULL);
		#if defined(__MMI_IME_CANDIDATE_GRID__)
        if(mmi_imc_is_grid_state())
		{
            imui_msg.message_id = MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX_GRID;
			imui_msg.param_0 = (U32)&(update_struct);
			 cand_insert = mmi_imui_send_message(&imui_msg, NULL);
		}
		#endif

    #if (defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__)) && !defined(__MMI_IME_AUTO_CAPITALIZATION__) && !defined __MMI_XT9__
		if (g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_LOWER
            || g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER 
            || g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_NONE)
		{
            if (g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_NONE)
            {
                mmi_imc_change_candidate_list_caps(MMI_IME_WORD_CAPITAL_STATE_LOWER);
            }
            else
            {    
			    mmi_imc_change_candidate_list_caps(g_imc.global_data.capital_state);
            }

			if (cand_insert < result_cnt)
			{
                update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_NEXT_PAGE;
			}
			
            update_struct.flags &= ~MMI_IMUI_SELECTION_AREA_FLAG_CENTER_INDEX;

			//update_struct.count = cand_insert;
			mmi_imui_send_message(&imui_msg, NULL);
		}
    #endif


        /* get more candidate but the candidate buffer is not enough to insert those candidate */
    	if (g_imc.global_data.cand_page + 1 < MMI_IMC_MAX_CANDIDATE_PAGE)
        {
            if (cand_insert < g_imc.global_data.cand_count)
    	    {
    	        g_imc.global_data.cand_first_index[g_imc.global_data.cand_page + 1] = g_imc.global_data.cand_first_index[g_imc.global_data.cand_page] + cand_insert;
    	        g_imc.global_data.cand_count = cand_insert;
    	    }
    	    else if (cand_insert == g_imc.global_data.cand_count)
    	    {
    	        /* the candidate buffer is big enough to insert all candidate */
    	        if (next_page)
    	        {
    	            g_imc.global_data.cand_first_index[g_imc.global_data.cand_page + 1] = g_imc.global_data.cand_first_index[g_imc.global_data.cand_page] + g_imc.global_data.cand_count;
    	        }
    	        else
    	        {
    	            g_imc.global_data.cand_first_index[g_imc.global_data.cand_page + 1] = 0;
    	        }
    	        
    	    }
    	    else 
    	    {
    	        /* insert more candidate then get */
    	        MMI_ASSERT(0);
    	    }
        }
    	else if (g_imc.global_data.cand_page < MMI_IMC_MAX_CANDIDATE_PAGE)
    	{
    	    if (cand_insert < g_imc.global_data.cand_count)
    	    {
    	        g_imc.global_data.cand_count = cand_insert;
    	    }

    	    g_imc.global_data.cand_first_index[g_imc.global_data.cand_page + 1] = 0;
    	}
        else
        {
            MMI_ASSERT(0);
        }
    }
    return g_imc.global_data.cand_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_common_arrow_key_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_common_arrow_key_handler(mmi_imc_key_custom_value key_code, U16 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_imc_key_common_arrow_key_handler(key_code, event_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_candidate_check
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_candidate_check(UI_string_type cand, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct imc_msg;
    UI_character_type string_buf[10]; ///TODO: define an value for the string length
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cand == NULL)
        ASSERT(0);
    
    memset(string_buf, 0, 10*sizeof(UI_character_type));
    
    /* get previous character but skip highlight and multitap. */
    imc_msg.message_id = MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE;
    imc_msg.param_0 = 1;
    imc_msg.param_1 = (U32)string_buf;

    mmi_imc_send_message(&imc_msg);

    /* do language check */
    #if defined(__MMI_INDIC_ALG__)
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(cand[0]))
    {
        if (!ire_IsValidInput_int(cand, 2, string_buf))
        {
            return MMI_FALSE;
        }
    }
    #endif
#if defined(__MMI_LANG_THAI__)
    if (THAI_CHARACTER_UCS2_RANGE(cand[0]))
    {
        if (!is_thai_valid_input_int(cand, 2, string_buf))
        {
            return MMI_FALSE;
        }
    }
    #endif
    /* check the rule set by ap */
    if (!mmi_imm_test_input(cand, len))
        return MMI_FALSE;
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_start_timer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_start_timer(S32 count, void (*callback) (void), void (*cancel_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_active_timer_callback != NULL && g_active_timer_count > 0)
    {
        mmi_imc_cancel_timer();
    }

    if (callback != NULL)
    {
        gui_start_timer(count, mmi_imc_timer_handler);

        g_active_timer_callback = callback;
        g_active_timer_count = count;
        g_timer_cancel_callback = cancel_callback;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_cancel_timer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_cancel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_active_timer_callback != NULL)
    {
        gui_cancel_timer(g_active_timer_callback);
        g_active_timer_callback = NULL;
        g_active_timer_count = 0;
            
        if (g_timer_cancel_callback != NULL)
        {
            g_timer_cancel_callback();
            g_timer_cancel_callback = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_restart_timer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_restart_timer(S32 count, void (*callback) (void), void (*cancel_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL && count > 0)
    {
        if (g_active_timer_callback == NULL || g_active_timer_callback == callback)
        {
            gui_cancel_timer(callback);
            gui_start_timer(count, mmi_imc_timer_handler);
            g_active_timer_callback = callback;
            g_active_timer_count = count;
            g_timer_cancel_callback = cancel_callback;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_timer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr temp_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_active_timer_callback != NULL)
    {
		temp_ptr = g_active_timer_callback;
		g_active_timer_callback = NULL;
        g_active_timer_count = 0;
        g_timer_cancel_callback = NULL;
        temp_ptr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_delete_timer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
FuncPtr mmi_imc_delete_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr ret = g_active_timer_callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_active_timer_callback != NULL)
    {
        gui_cancel_timer(g_active_timer_callback);
        g_active_timer_callback = NULL;
        g_active_timer_count = 0;
        g_timer_cancel_callback = NULL;
    }
    return ret;
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_inline_editor_full_height
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_imc_set_inline_editor_full_height(S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_inline_editor_full_height = height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_inline_editor_full_height
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32  mmi_imc_get_inline_editor_full_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_inline_editor_full_height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_handwriting
 * DESCRIPTION
 *  Only disable handwriting, not disable pen event
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_disable_handwriting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMC_DISABLE_HANDWRITING);
    g_is_handwriting_disabled = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_hw_type_valid
 * DESCRIPTION
 *  Set hw type invalid or not
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_hw_type_validity(MMI_BOOL v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_imc_is_invalid_hw_type = v;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_hw_type_validity
 * DESCRIPTION
 *  Get hw type validity
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_get_hw_type_validity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_imc_is_invalid_hw_type;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_handwriting_disabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_handwriting_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_handwriting_disabled;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_virtual_keyboard
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_disable_virtual_keyboard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_vk_disabled = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_vk_disabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_vk_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_vk_disabled;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_show_disabled_vk
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_show_disabled_vk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__) 
    mmi_imui_message_struct imui_msg;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__) 
    imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_DISABLED_VIRTUAL_KEYBOARD;
    mmi_imui_send_message(&imui_msg, NULL);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_vk_area_height
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_get_vk_area_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    mmi_imui_message_struct imui_msg;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__)    
    imui_msg.message_id = MMI_IMUI_MESSAGE_GET_VK_AREA_HEIGHT;
    
    return  (S32)mmi_imui_send_message(&imui_msg, NULL);
#else
	return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_current_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
gui_virtual_keyboard_language_enum mmi_imc_get_current_vk_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__) 
    mmi_imui_message_struct imui_msg;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__) 
    imui_msg.message_id = MMI_IMUI_MESSAGE_GET_VK_TYPE;
    
    return (gui_virtual_keyboard_language_enum)mmi_imui_send_message(&imui_msg, NULL);
#else
    return GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_desired_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_desired_vk_type(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__) 
    mmi_imc_pen_set_desired_vk_type(vk_type);
#endif
}

#else /* defined(__MMI_TOUCH_SCREEN__) */
void     mmi_imc_disable_handwriting(void)
{
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_symbol_picker_disable
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_symbol_picker_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_symbol_picker_disable;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_symbol_picker
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_disable_symbol_picker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_symbol_picker_disable = MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_enable_symbol_picker
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_enable_symbol_picker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_symbol_picker_disable = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_key_input
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_disable_key_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_key_disabled = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_key_input
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL     mmi_imc_is_key_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_key_disabled;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_key_input
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_disable_pen_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_pen_disabled = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_key_input
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL     mmi_imc_is_pen_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_pen_disabled;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_ime_handlers
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL     mmi_imc_disable_ime_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_disable_pen_input();
    mmi_imc_disable_key_input();
	return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_char_info
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_get_char_info(UI_character_type code, UI_string_type info_buffer, S32 buffer_size, mmi_imm_input_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ime_word_engine_get_char_info(code, info_buffer, buffer_size, mode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_tone_character
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_tone_character(UI_character_type code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_IMC_IS_SYMB_TONE(mmi_ime_word_code_to_symbol(code));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_string_to_title_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_string_to_title_case(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (string == NULL)
        return;

    string[0] = (UI_character_type)mmi_towupper((kal_wchar)string[0]);
    
    for (i = 1; string[i] != 0; i++)
    {
        string[i] = (UI_character_type)mmi_towlower((kal_wchar)string[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_string_to_lower_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_string_to_lower_case(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (string == NULL)
        return;
    
    for (i = 0; string[i] != 0; i++)
    {
        string[i] = (UI_character_type)mmi_towlower((kal_wchar)string[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_string_to_upper_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_string_to_upper_case(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (string == NULL)
        return;
    
    for (i = 0; string[i] != 0; i++)
    {
        string[i] = (UI_character_type)mmi_towupper((kal_wchar)string[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_ime_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_ime_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mmi_imc_get_state())
    {
    case MMI_IMC_STATE_INITIAL:
    case MMI_IMC_STATE_NONE:
        return MMI_FALSE;
    default:
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_clipboard_state
 * DESCRIPTION
 *  Check if current state is clipboard state
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE:  yes
 *  MMI_FALSE: NO
 *****************************************************************************/
MMI_BOOL mmi_imc_is_clipboard_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imc_get_state())
    {
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT:
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN:
    case MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS:
    case MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU:
        return MMI_TRUE;
    default:
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_fixed_input_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_fixed_input_box(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_is_fixed_input_box = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_disable_csk
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_disable_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_enable_csk = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_csk_config
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_get_csk_config(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_enable_csk;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_fixed_input_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_fixed_input_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_is_fixed_input_box;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_backgroud_filler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_backgroud_filler(mmi_imui_draw_back_ground_funcptr funcptr)
{


/* as opera calls  when venus is running somethimes*/
    #if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        return ;
    }
    #endif

    if (g_imc.is_inited && funcptr != NULL)
    {
        mmi_imui_message_struct imui_msg;
        imui_msg.message_id = MMI_IMUI_MESSAGE_SET_BACK_GROUND_REDRAW_FUNC;
        imui_msg.param_0 = (U32)funcptr;
        mmi_imui_send_message(&imui_msg, NULL);
        g_imc_background_filler = funcptr;
    #if defined(__MMI_VIRTUAL_KEYBOARD__)
        wgui_virtual_keyboard_register_hide_callback(funcptr);
    #endif

    #ifdef __MMI_IME_PLUG_IN__
        mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_IMUI_BG_FILLER_CHANGED, (U32)funcptr, 0);
    #endif
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_softkey_background_filler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_softkey_background_filler(mmi_imui_draw_back_ground_funcptr funcptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_default_hide_softkeys();

    g_imc_softkey_background_filler = funcptr;

    g_imc_backup_softkey_hide_fptr = wgui_softkey_get_hide_func_ptr();

    wgui_softkey_set_hide_func_ptr(mmi_imc_softkey_hide_callback);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_softkey_background
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_redraw_softkey_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    show_softkey_background();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_softkey_hide_callback
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_softkey_hide_callback(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_softkey_background_filler)
    {
        if (key == WGUI_MAX_SOFTKEYS)
        {
            g_imc_softkey_background_filler(
                0,
                UI_device_height - MMI_softkey_height,
                UI_device_width - 1,
                UI_device_height - 1);
        }
        else if (key == MMI_LEFT_SOFTKEY)
        {
            g_imc_softkey_background_filler(
                MMI_softkeys[MMI_LEFT_SOFTKEY].x,
                MMI_softkeys[MMI_LEFT_SOFTKEY].y,
                MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width - 1,
                MMI_softkeys[MMI_LEFT_SOFTKEY].y + MMI_softkeys[MMI_LEFT_SOFTKEY].height - 1);
        }
        else if (key == MMI_RIGHT_SOFTKEY)
        {
            g_imc_softkey_background_filler(
                MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
                MMI_softkeys[MMI_RIGHT_SOFTKEY].y,
                MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width - 1,
                MMI_softkeys[MMI_RIGHT_SOFTKEY].y + MMI_softkeys[MMI_RIGHT_SOFTKEY].height - 1);
        }    
        else if (key == MMI_CENTER_SOFTKEY)
        {
            g_imc_softkey_background_filler(
                MMI_softkeys[MMI_CENTER_SOFTKEY].x,
                MMI_softkeys[MMI_CENTER_SOFTKEY].y,
                MMI_softkeys[MMI_CENTER_SOFTKEY].x + MMI_softkeys[MMI_CENTER_SOFTKEY].width - 1,
                MMI_softkeys[MMI_CENTER_SOFTKEY].y + MMI_softkeys[MMI_CENTER_SOFTKEY].height - 1);
        }    
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_candidate_list_caps
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_change_candidate_list_caps(mmi_ime_word_capital_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    UI_string_type cand = NULL;
    S32 total_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i = 0; i < g_imc.global_data.cand_count; i++)
    {
        cand = g_imc.global_data.cand_buff + total_len;
        mmi_imc_change_alphabetic_candidate_case(cand, state);
        total_len += (mmi_ucs2strlen((const S8*)cand) + 1);
    }
}


#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_candidate_list_by_caps_seq
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_change_candidate_list_by_caps_seq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    UI_string_type cand = NULL;
    S32 total_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( mmi_imm_does_current_type_support_titlecase())
    {
    for (i = 0; i < g_imc.global_data.cand_count; i++)
    {
        cand = g_imc.global_data.cand_buff + total_len;
        mmi_imc_change_alphabetic_candidate_case_by_caps_seq(cand, g_imc.global_data.capital_state_seq);
        total_len += (mmi_ucs2strlen((const S8*)cand) + 1);
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_alphabetic_candidate_case_by_caps_seq
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_change_alphabetic_candidate_case_by_caps_seq(UI_string_type cand, mmi_ime_word_capital_state_enum *state_seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cand == NULL)
        return;

    len = mmi_ucs2strlen((const S8*) cand);

    for (index = 0; index < len; index++)
    {
        MMI_ASSERT(index <= MMI_IMC_MAX_KEY_BUFFER_SIZE);
        
        switch (state_seq[index])
        {
            case MMI_IME_WORD_CAPITAL_STATE_LOWER:
                cand[index] = mmi_towlower(cand[index]);
                break;
                
            case MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER:
            case MMI_IME_WORD_CAPITAL_STATE_UPPER:
                cand[index] = mmi_towupper(cand[index]);
                break;
                
            default:
                break;
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_caps_seq_by_cur_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_caps_seq_by_cur_state(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = index; i < MMI_IMC_MAX_KEY_BUFFER_SIZE + 1; i++)
    {
        if (g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
        {
            if (i == 0)
            {
                g_imc.global_data.capital_state_seq[i] = MMI_IME_WORD_CAPITAL_STATE_UPPER;
            }
            else
            {
                g_imc.global_data.capital_state_seq[i] = MMI_IME_WORD_CAPITAL_STATE_LOWER;
            }
        }
        else
        {
            g_imc.global_data.capital_state_seq[i] = g_imc.global_data.capital_state;
        }
    }
}

#endif /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_alphabetic_candidate_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_change_alphabetic_candidate_case(UI_string_type cand, mmi_ime_word_capital_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cand == NULL)
        return;

    len = mmi_ucs2strlen((const S8*) cand);
    switch (state)
    {
        case MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER:
            cand[0] = mmi_towupper(cand[0]);
            for (index = 1; index < len; index ++)
            {
                cand[index] = mmi_towlower(cand[index]);
            }            
            break;
        case MMI_IME_WORD_CAPITAL_STATE_LOWER:
            for (index = 0; index < len; index ++)
            {
                cand[index] = mmi_towlower(cand[index]);
            }
            break;
       case MMI_IME_WORD_CAPITAL_STATE_UPPER:
           for (index = 0; index < len; index ++)
           {
               cand[index] = mmi_towupper(cand[index]);
           }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_input_mode_caps
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ime_word_capital_state_enum mmi_imc_get_input_mode_caps(const sIMEModeDetails * mode_details_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mode_details_ptr)
    {
        return MMI_IME_WORD_CAPITAL_STATE_NONE;
    }

    if ( mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC )
    {
        if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE )
        {
            return MMI_IME_WORD_CAPITAL_STATE_UPPER;
        }
        else if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE )
        {
            return MMI_IME_WORD_CAPITAL_STATE_LOWER;
        }
        else if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE )
        {
            return MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
        }
    }

    return MMI_IME_WORD_CAPITAL_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_insert_char_by_symbol_picker
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL     mmi_imc_insert_char_by_symbol_picker(UI_character_type symbol)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_imc_message_struct imc_msg;
	MMI_BOOL ret = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (symbol != 0 && g_is_ime_connected)
    {
		if (mmi_imm_test_input(&symbol, 1))
		{
			if (((mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_SIGNED_NUMERIC) ||
                (mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)) &&
                symbol == (UI_character_type)('-'))
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION;
                imc_msg.param_0 = 0;
                imc_msg.param_1 = (UI_character_type)('-');
            }
            else if ((symbol == (UI_character_type)'.') && 
                     ((mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_DECIMAL_NUMERIC) || 
                      (mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)))
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_DECIMAL_SYMBOL;
                imc_msg.param_0 = 0;
                imc_msg.param_1 = 0;
            }
            else 
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_CHAR;
                imc_msg.param_0 = (U32)symbol;
                imc_msg.param_1 = 0;
            }
            
            /* Can not use mmi_imc_send_message, because it would filter the dead character */
            ret = (MMI_BOOL)g_imc.message_proc(g_imc.editor_handle, &imc_msg); 
            
            
            if (ret)
            {
                mmi_event_struct evt;
                mmi_imc_print_string_inserted_to_editor((UI_string_type)&symbol, 1);

                MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);
                
                MMI_FRM_CB_EMIT_EVENT(&evt);
                mmi_imc_redraw_screen_by_state();
            }
		}
        else
        {
            UI_editor_play_tone_cannot_insert();
        }    
    }

	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_post_process_handler
 * DESCRIPTION
 *  used for handling some post process in IME, such as insert symbol later
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/


void mmi_imc_post_process_handler(void)
{
	mmi_imc_message_struct imc_msg;
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    mmi_ime_word_capital_state_enum old_case;
#endif
	if(0 != g_ime_post_process_data.curr_data[0]) //special case for opera can not connect to ime in time when back to opera screen
	{
		switch(g_ime_post_process_data.curr_data_type)
		{
			case MMI_IMC_POST_SYMBOL_DATA:
				mmi_imc_insert_char_by_symbol_picker(g_ime_post_process_data.curr_data[0]);
				break;
			case MMI_IMC_POST_NEWWORD_DATA:	
			#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
				old_case = g_imc.global_data.capital_state;
    
				mmi_imc_key_change_candidate_case_by_previous_string();
        
				if ((g_imc.mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
				&& g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
				{
					g_ime_post_process_data.curr_data[0] = mmi_towupper(g_ime_post_process_data.curr_data[0]);
				}

				g_imc.global_data.capital_state = old_case;
			#endif /* #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) */
        
				imc_msg.message_id = MMI_IMC_MESSAGE_START_SMART_ALPHABETIC;
				mmi_imc_send_message(&imc_msg);

				imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
				imc_msg.param_0 = (U32)&g_ime_post_process_data.curr_data[0];
				imc_msg.param_1 = 0;

				mmi_imc_send_message(&imc_msg);
        
				imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
				mmi_imc_send_message(&imc_msg);
        
			#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
			{
				mmi_event_struct evt;
                
				MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);

				g_imc_skip_first_cursor_movement_event = MMI_FALSE;
                
				MMI_FRM_CB_EMIT_EVENT(&evt);
			}
			#endif
				break;
		}
		memset(&g_ime_post_process_data.curr_data[0], 0, sizeof(UI_character_type) * MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1);
		g_ime_post_process_data.curr_data_type = MMI_IMC_POST_DATA_NONE;
	}		
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_scan_and_add_new_words
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_scan_and_add_new_words(UI_string_type str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_USER_DATABASE__)
    mmi_ime_word_scan_and_add_new_words(str);
#else
    UI_UNUSED_PARAMETER(str);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_magic_key_down
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
U32 mmi_imc_get_max_candidate_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    imui_msg.message_id = MMI_IMUI_MESSAGE_GET_MAX_CANDIDATE_WIDTH;
    
    return  mmi_imui_send_message(&imui_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_reset_ime_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_reset_ime_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_is_ime_connected && mmi_imc_is_ime_state())
    {
        mmi_imc_gdi_lcd_freeze(TRUE);
        mmi_imc_key_reset_ime_state();
    
    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_imc_pen_reset_ime_state();
    #endif

    #ifdef __MMI_IME_PLUG_IN__
        mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_RESET, 0, 0);
    #endif
    
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

        mmi_imc_redraw_screen_by_state();
        mmi_imc_gdi_lcd_freeze(gdi_freeze);
        mmi_imc_repaint_screen();
    }
}


#if defined(__MMI_IME_MAGIC_ONE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_magic_key_down
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_magic_key_down(MMI_BOOL val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_magic_key_down = val;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_magic_key_down
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_get_magic_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_magic_key_down;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_to_magic_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_change_to_magic_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails * mode_details_ptr = NULL;
    MMI_BOOL ret_val = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_SMART_LOWERCASE_ABC))
    {
        mode_details_ptr = mmi_imm_get_input_mode_array_item(IMM_INPUT_MODE_MAGIC_NUMBER);
        
        if (!g_magic_key_down)
            ASSERT(0);

        /* change to smart lowercase English */
        
        g_backup_mode_details_ptr = g_imc.mode_details_ptr;
        g_backup_input_mode = mmi_imm_get_curr_input_mode();
        
        mmi_ime_word_leave_current_mode();
        mmi_imc_reset_global_data();
        g_imc.fsm_object.curr_state = MMI_IMC_STATE_INITIAL;
        mmi_imc_reset_global_data();
        ret_val = mmi_ime_word_change_mode(mode_details_ptr, 0);
        g_is_magic_state = MMI_TRUE;
    }
    else
    {
        ret_val = MMI_FALSE;
    }
    return ret_val;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_check_magic_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_check_magic_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_magic_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_back_from_magic_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_back_from_magic_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_magic_key_down = MMI_FALSE;
    g_is_magic_state = MMI_FALSE;
#if defined(__MMI_MIXED_LANG_SUPPORT__)
    sub_lang = mmi_imm_get_sub_lang();
#endif
    /* call word engine to leave current input mode */
    mmi_ime_word_leave_current_mode();
    /* reset global data */
    mmi_imc_reset_global_data();  
    /* change to original mode. */
    mmi_imc_key_change_mode(g_imc.mode_details_ptr, 0);

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_input_method_history
 * DESCRIPTION
 *  This function can only be called by editor's get history function
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_get_input_method_history(mmi_imc_history_p history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    gui_virtual_keyboard_language_enum vk_type;
#endif
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	MMI_BOOL is_grid_state = mmi_imc_is_grid_state();
#endif

    mmi_imc_message_struct imc_msg;
	U16 current_key_code, current_key_type;
    MMI_BOOL is_multitap = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    if (mmi_imc_is_connected() && mmi_imm_is_auto_capitalization_valid())
    {
        if (!mmi_imm_is_curr_capital_state_of_curr_input_mode())
        {
            g_imc.global_data.capital_state = mmi_imc_get_candidate_case_before_cursor();
            mmi_imc_change_input_mode_according_to_capital_state(g_imc.global_data.capital_state);
        }
    }

	history->skip_auto_cap_first_filter = MMI_FALSE;
#endif

#if defined(__MMI_VIRTUAL_KEYBOARD__)

    vk_type = mmi_imc_get_current_vk_type();

    if (vk_type == GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY || vk_type == GUI_VIRTUAL_KEYBOARD_MAX_LANG)
    {
        if (g_imc.history.vk_type == GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY || g_imc.history.vk_type == GUI_VIRTUAL_KEYBOARD_MAX_LANG)
        {
            history->vk_type = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
        }
        else
        {
            history->vk_type = g_imc.history.vk_type;
        }
    }
    else
    {
        history->vk_type = vk_type;
    }
    
#endif /* defined(__MMI_TOUCH_SCREEN__) */

    
    if (g_imc.fsm_object.curr_state == MMI_IMC_STATE_NONE)
    {
        if (g_imc.history.state == MMI_IMC_STATE_NONE)
        {
            history->state = MMI_IMC_STATE_NONE;
        }
        else
        {
            history->state = g_imc.history.state;
        }
            
    }
    else
    {
        history->state = g_imc.fsm_object.curr_state;
        if (history->state == MMI_IMC_STATE_MULTITAP)
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE;
            
            is_multitap = (MMI_BOOL)mmi_imc_send_message(&imc_msg);
                
            if (is_multitap)
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;

                if (mmi_imc_send_message(&imc_msg))
                {
                    is_multitap = MMI_FALSE;
                }
            }
            
            if (!is_multitap)
            {
                history->state = MMI_IMC_STATE_INITIAL;
            }
            else
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;
                if (mmi_imc_send_message(&imc_msg))
                {
                    history->state = MMI_IMC_STATE_INITIAL;
                }
                else
                {
                    GetkeyInfo((PU16)(&current_key_code), (PU16)(&current_key_type));
                    if (mmi_imc_key_get_last_imc_key_code() != current_key_code)
                    {
                        history->state = MMI_IMC_STATE_INITIAL;
                    }	
                }	
            }

        }
    }

    /* Clear ime history after editor has gotten it */
    g_imc.history.state = MMI_IMC_STATE_NONE; 
    
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    g_imc.history.vk_type = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
#if defined(__MMI_IME_FTE_ENHANCE__)
    g_imc.history.is_vk_on = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
    history->is_vk_on = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(is_grid_state)
	{
		// when in grid state, vk should be resumed after interrupt, as state will go to initial and grid state will not be there
		g_imc.history.is_vk_on = MMI_TRUE;
		history->is_vk_on = MMI_TRUE;
	}
	#endif
    history->input_style = mmi_imc_pen_get_curr_input_style();
#endif
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

    history->input_mode = mmi_imm_get_curr_input_mode();

#if defined(__MMI_IMC_CAPITAL_SWITCH__)

    /* If there is desired writing language which has not been used, we still use it as writing language in history */
    history->writing_lang = mmi_imm_get_not_used_desired_writing_language_from_history();

    if (history->writing_lang == IME_WRITING_LANG_NONE)
    {
        history->writing_lang = mmi_imm_get_current_writing_language();
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_input_method_history
 * DESCRIPTION
 *  This function can only be called by editor's set history function
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_input_method_history(mmi_imc_history_p history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    g_imc_skip_first_cursor_movement_event = MMI_TRUE;
    #endif
    mmi_imm_set_default_input_mode(history->input_mode);
    
    mmi_imm_set_history_input_mode(history->input_mode);
    
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    mmi_imc_set_desired_vk_type(history->vk_type);
#if defined(__MMI_IME_FTE_ENHANCE__)
    mmi_imc_pen_set_history_is_vk_enlarge(history->is_vk_on);
    mmi_imc_pen_set_history_input_style(history->input_style);
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */ 
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    mmi_imm_set_writing_language_from_history(history->writing_lang);
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
	g_imc_skip_auto_cap_first_filter = history->skip_auto_cap_first_filter;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_multitap_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_multitap_state(U8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (state == MMI_IMC_STATE_MULTITAP)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
static PU8 g_mmi_imc_list_items_string[2];
static S32 g_mmi_imc_hilight_index = 0;
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_smart_input_method_screen_rsk_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_config_smart_input_method_screen_rsk_handler(void)
{
    #ifdef __MMI_FRM_HISTORY__
    #if defined(__ATV_SMS_SUPPORT__)
   				if( dm_is_fixed_layer_mode_enabled() )
   				{
					GoBackHistory();
				}
				else
   #endif
   #endif 
				{
    mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
}
}

#if defined(__ATV_SMS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_smart_input_method_screen_exit_func
 * DESCRIPTION
 * Exit function needed only in case of matv screens 
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_config_smart_input_method_screen_exit_func()
{
		#ifdef __MMI_FRM_HISTORY__
			if( dm_is_fixed_layer_mode_enabled() )
			{
   				if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
			}
           #endif 
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_entry_config_smart_input_method_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_entry_config_smart_input_method_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_imc_entry_config_smart_input_method_screen_with_sg(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_entry_config_smart_input_method_screen_with_sg
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_entry_config_smart_input_method_screen_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 highlight_index = 0;
	UI_image_type title_image=NULL;
	/* mmi_id current_gid;  */ /* Needed for getting the title image */ 
        U8 *title_str_U8_ptr=NULL;
	#if defined(__ATV_SMS_SUPPORT__)
	   WCHAR* title_str_p;
	#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__
	U16 scr_id = 0;
    if (g_id == GRP_ID_INVALID)
    {
        if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_CONFIG_SMART_INPUT_METHOD);

           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }

		#if defined(__ATV_SMS_SUPPORT__)
			EntryNewScreen(scr_id, mmi_imc_config_smart_input_method_screen_exit_func, mmi_imc_entry_config_smart_input_method_screen, NULL);
		#else
			EntryNewScreen(scr_id, NULL, mmi_imc_entry_config_smart_input_method_screen, NULL);
		#endif
		#if defined(__ATV_SMS_SUPPORT__)
   				if( matv_init_fptr_ime != NULL )
   				{
						matv_init_fptr_ime();
   				}	
		#endif
        guiBuffer = GetCurrGuiBuffer(scr_id);
    }
    else
#endif 
    {
		   /*  current_gid = mmi_frm_group_get_active_id(); */ 
         /* cui_menu_get_default_title_image(current_gid, &title_image); The interface to get image from menucui is very prone to errors so commented for some time */ 
		 	title_image=NULL;
			g_ime_screens_group_id=g_id;
        if (mmi_frm_scrn_enter(g_id , SCR_CONFIG_SMART_INPUT_METHOD, NULL, mmi_imc_entry_config_smart_input_method_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        {
            return;
        }
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
    }

    if (!mmi_imm_is_smart_alphabetic_input_modes_enabled())
    {
        highlight_index = 1;
    }

    g_mmi_imc_list_items_string[0] = (PU8)GetString(STR_GLOBAL_ON);
    g_mmi_imc_list_items_string[1] = (PU8)GetString(STR_GLOBAL_OFF);

    RegisterHighlightHandler(mmi_imc_config_smart_input_method_hilight_hdlr);

	#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() )
   		{
   				/* Suggestion from category owner to avoid CS, call EnableCenterSoftkey(), before cagetory show API */
						EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
				#if defined(__MMI_ZI__)
		        title_str_p = (WCHAR*)GetString(STR_INPUT_METHOD_MENU_SET_ZI);
				#elif defined (__MMI_T9__)
				title_str_p = (WCHAR*)GetString(STR_INPUT_METHOD_MENU_SET_T9);
				#elif defined(__MMI_CSTAR__)
				title_str_p=(WCHAR*)GetString(STR_INPUT_METHOD_MENU_SET_CSTAR);
				#elif defined(__MMI_GUOBI__)
				title_str_p=(WCHAR*)GetString(STR_INPUT_METHOD_MENU_SET_GUOBI);
				#else
				title_str_p = 0;
				#endif
			wgui_cat1014_show(
				title_str_p,
                NULL,
                (WCHAR*)GetString(STR_GLOBAL_OK),
                NULL,
                (WCHAR*)GetString(STR_GLOBAL_BACK),
                NULL,
                2,
                 g_mmi_imc_list_items_string,
                highlight_index,
                guiBuffer);
		}
		else
		#endif
		{
#if defined(__MMI_ZI__)
                title_str_U8_ptr = (U8 *)GetString(STR_INPUT_METHOD_MENU_SET_ZI);
#elif defined(__MMI_T9__)
                title_str_U8_ptr = (U8 *)GetString(STR_INPUT_METHOD_MENU_SET_T9);
#elif defined(__MMI_CSTAR__)
                title_str_U8_ptr = (U8 *)GetString(STR_INPUT_METHOD_MENU_SET_CSTAR);
#elif defined(__MMI_GUOBI__)
				title_str_U8_ptr = (U8 *)GetString(STR_INPUT_METHOD_MENU_SET_GUOBI);
#else
                title_str_U8_ptr = 0;
#endif
    ShowCategory36Screen_ext(
        title_str_U8_ptr,
        (U8 *)title_image,
        (U8 *)GetString(STR_GLOBAL_OK),
        (U8 *)get_image(IMG_GLOBAL_OK),
        (U8 *)GetString(STR_GLOBAL_BACK),
        (U8 *)get_image(IMG_GLOBAL_BACK),
        2,
        g_mmi_imc_list_items_string,
        highlight_index,
        guiBuffer);
}

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_imc_set_smart_input_method, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(mmi_imc_config_smart_input_method_screen_rsk_handler, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imc_set_smart_input_method, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_exit_config_smart_input_method_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_exit_config_smart_input_method_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_smart_input_method_hilight_hdlr
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
 static void mmi_imc_config_smart_input_method_hilight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imc_hilight_index = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_smart_input_method
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static mmi_ret  mmi_imc_set_smart_input_method_popuphandler(mmi_event_struct *param)
{
    #ifdef __MMI_FRM_HISTORY__
#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() )
   		{
			GoBackHistory();
			
		}
		else
        #endif
#endif
         {
        	/* Earlier we were using screen close twice one for closing the screen belonging to popup and other 
	to close the screen SCR_CONFIG_SMART_INPUT_METHOD which was wrong. This is a important fix because using any
	screen id other than application will result in Assert while getting the title image from menu cui */
   	  return mmi_frm_scrn_close(g_ime_screens_group_id,SCR_CONFIG_SMART_INPUT_METHOD);
		}
}

#ifdef __ATV_SMS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_smart_input_method_matv_screen_close
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_smart_input_method_matv_screen_close()
{
	#ifdef __MMI_FRM_HISTORY__
		GoBacknHistory(1);
    #endif 
}
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_smart_input_method
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
 static void mmi_imc_set_smart_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /* U16 scr_di = 0; */
   /* mmi_id g_id = 0; */
  /*  mmi_id g_scr_id = 0; */ 
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    const sIMEModeDetails *mode_details_ptr = NULL, *target_mode_details_ptr = NULL;
#endif
    mmi_popup_property_struct callback_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());

    if (mode_details_ptr == NULL)
    {
        MMI_ASSERT(0);
    }
#endif

    if (g_mmi_imc_hilight_index == 0)
    {
        mmi_imm_config_smart_alphabetic_input_modes(MMI_TRUE);

    #if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
        target_mode_details_ptr = mmi_imm_get_corresponding_smart_mode(mode_details_ptr->imm_mode_id, mode_details_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK);
    #endif
    }
    else if (g_mmi_imc_hilight_index == 1)
    {
        mmi_imm_config_smart_alphabetic_input_modes(MMI_FALSE);

    #if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
        target_mode_details_ptr  = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, mode_details_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK);
    #endif
    }

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (target_mode_details_ptr)
    {
        mmi_imm_set_user_desired_input_mode(target_mode_details_ptr->imm_mode_id);
		mmi_imm_set_prefer_input_mode(target_mode_details_ptr->imm_mode_id);
    }
#endif

  /*  g_id = mmi_frm_group_get_active_id(); */

	/* if (g_id == GRP_ID_INVALID)
    {
        scr_di = GetActiveScreenId();
    }
    else
    {
        g_scr_id = mmi_frm_scrn_get_active_id();
    } */

    mmi_popup_property_init(&callback_popup);


    if (mmi_frm_group_get_active_id() != GRP_ID_INVALID)
    {
        callback_popup.parent_id = mmi_frm_group_get_active_id();
        callback_popup.callback = mmi_imc_set_smart_input_method_popuphandler;
    }

	#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() )
   		{
			   //  mmi_imc_set_smart_input_method_matv_screen_close();
			   GoBackHistory();
			mmi_mtv_ime_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
			 //mmi_display_popupcallback((UI_string_type)GetString(STR_GLOBAL_DONE),MMI_EVENT_SUCCESS, mmi_imc_set_smart_input_method_matv_screen_close);
		}
		else
		
#endif
        {
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);
		}
}
#endif /* #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__) */



#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_input_area
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_update_input_area(S32 highlight_start, S32 highlight_num, S32 wave_start, S32 wave_num, S32 cursor_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct uimsg;
    mmi_imui_update_input_area_struct input_area;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* set data of input area */
    input_area.str_ptr = g_imc.global_data.input_buff;
    input_area.highlight_start_index =  highlight_start;
    input_area.highlight_num = highlight_num;
    input_area.wave_start_index = wave_start;
    input_area.wave_num = wave_num;
    input_area.cursor_index = cursor_index;
	input_area.flags = 0;

    uimsg.message_id = MMI_IMUI_MESSAGE_UPDATE_INPUT_AREA;
    uimsg.param_0 = (U32)(&input_area);
    if (mmi_imm_test_r2l_input())
    {   
        input_area.flags |= MMI_IMUI_INPUT_AREA_FLAG_R2L;
    }
    mmi_imui_send_message(&uimsg, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_input_area_add_string
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_input_area_add_string(UI_string_type in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = mmi_ucs2strlen((const S8*)in);
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        if (g_imc.global_data.input_length + 1 < MMI_IMC_MAX_INPUT_BUFFSIZE)
        {
            g_imc.global_data.input_buff[g_imc.global_data.input_length++] = in[i];
        }
        else
        {
            break;
        }
    }
    /* add null in the end */
    g_imc.global_data.input_buff[g_imc.global_data.input_length] = '\0';

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_input_area_delete_string
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_input_area_delete_string(S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = len - 1; i >= 0; i--)
    {
        if (g_imc.global_data.input_length > 0)
        {
            g_imc.global_data.input_buff[--g_imc.global_data.input_length] = '\0';
        }
        else
        {
            return MMI_FALSE;
        }
    }
    
    if (g_imc.global_data.input_length < g_imc.global_data.input_confirm_length)
        g_imc.global_data.input_confirm_length = g_imc.global_data.input_length;
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_input_area_add_space
 * DESCRIPTION
 *  add space in the end of the input area
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_input_area_add_space(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc.global_data.input_length + 1 < MMI_IMC_MAX_INPUT_STRING_SIZE)
    {
        g_imc.global_data.input_buff[g_imc.global_data.input_length ++] = 0x20;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_reset_input_area
 * DESCRIPTION
 *  To reset input area data
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_reset_input_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc.global_data.input_confirm_length = 0;
    g_imc.global_data.input_length = 0;
    memset(g_imc.global_data.input_buff, '\0', MMI_IMC_MAX_INPUT_BUFFSIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_reset_key_seq_data
 * DESCRIPTION
 *  To key seq backup data
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_reset_key_seq_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc.global_data.key_buffer_cusor = 0;
    g_imc.global_data.key_seq_index = 0;
    g_imc.global_data.key_seq_num = 0;
    memset(g_imc.global_data.key_buffer_backup, 0, sizeof(U16)*(MMI_IMC_MAX_KEY_SEQUENCE_RECORD*MMI_IMC_MAX_KEY_BUFFER_SIZE));
    memset(g_imc.global_data.select_cand, 0, sizeof(UI_character_type)*(MMI_IMC_MAX_KEY_SEQUENCE_RECORD*(MMI_IMC_MAX_KEY_BUFFER_SIZE + 1)));
    memset(g_imc.global_data.key_len_backup, 0, sizeof(U16)*(MMI_IMC_MAX_KEY_SEQUENCE_RECORD));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_candidate_as_null
 * DESCRIPTION
 *  To update candidate area displayed as zero input
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_update_candidate_as_null(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imui_update_selection_area_struct  update_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_struct.count = 0;
    update_struct.highlight_index = 0;
//FTE2.0 MAUI_03131879
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
    {
        update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
    }
    else
    {
        update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW | MMI_IMUI_SELECTION_AREA_FLAG_FLOATING/*| MMI_IMUI_SELECTION_AREA_FLAG_R2L */;
    }
#else
    update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW ;
#endif
    update_struct.separator = 0;
    update_struct.str_ptr = g_imc.global_data.cand_buff;
    
    imui_msg.message_id = MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX;
    imui_msg.param_0 = (U32)&(update_struct);
    mmi_imui_send_message(&imui_msg, NULL);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_enter_spell_word_screen_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_enter_spell_word_screen_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_USER_DATABASE__)
    mmi_imc_entry_spell_new_word_screen();
#endif
return 0;
}


#if defined(__MMI_IME_USER_DATABASE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_word_frequency_for_string
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_update_word_frequency_for_string(UI_string_type str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type temp_str = NULL;
    mmi_imm_input_mode_enum input_mode = mmi_imm_get_curr_input_mode();
    S32 word_len;
    UI_character_type temp_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    temp_str = str_ptr;

    while(temp_str)
    {
        word_len = 0;
        
        while(*temp_str)
        {
            if (temp_str[word_len] != 0x20)
            {
                word_len++;
            }
            else
            {
                break;
            }
        }
        
        if (word_len)
        {
            temp_code = temp_str[word_len];

            temp_str[word_len] = 0;
            
            mmi_ime_word_update_word_frequency(input_mode, temp_str);

            temp_str[word_len] = temp_code;

            temp_str += word_len;

            if (temp_code == 0x20)
            {
                temp_str++;
            }
        }
        else
        {
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_smart_input_method_screen_rsk_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_edit_new_word_screen_rsk_handler(void)
{
	#ifdef __MMI_FRM_HISTORY__
	#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() )
   		{
			  	GoBackHistory();
		  }
		else
			#endif
    #endif
    {  
       mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_entry_edit_new_word_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
 void mmi_imc_entry_edit_new_word_screen(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_imc_entry_edit_new_word_screen_with_sg(g_id);


 }

 /*Hack for Back key handling On first back key VK hide so dont GoBackHistory*/
/*****************************************************************************
 * FUNCTION
 *  NewWordGoBackHistory
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void NewWordGoBackHistory(void)
{
	is_go_back++ ;
	if(is_go_back > 1)
	{
		is_go_back = 0 ;
		GoBackHistory();
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_entry_edit_new_word_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
 void mmi_imc_entry_edit_new_word_screen_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_imc_edit_new_word_screen_history_p input_buffer = NULL;
    U16 input_buffer_size = 0;
    U16 scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_FRM_HISTORY__
    if (g_id == GRP_ID_INVALID)
    {
        if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_EDIT_NEW_WORD);

           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
        EntryNewScreen(scr_id, mmi_imc_exit_edit_new_word_screen, NULL, NULL);
        #if defined(__ATV_SMS_SUPPORT__)
   				if( matv_init_fptr_ime != NULL )
   				{
						matv_init_fptr_ime();
   				}	
			#endif
        guiBuffer = GetCurrGuiBuffer(scr_id);
        input_buffer = (mmi_imc_edit_new_word_screen_history_p)GetCurrNInputBuffer(scr_id, &input_buffer_size);
    }
    else
    #endif 
    {
        /* Disable small screen for the limitation of screen group*/
        if (mmi_frm_scrn_enter(g_id , SCR_EDIT_NEW_WORD, mmi_imc_exit_edit_new_word_screen, mmi_imc_entry_edit_new_word_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
        {
            return;
        }
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
        input_buffer = (mmi_imc_edit_new_word_screen_history_p)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_imc_edit_new_word_screen_history);
    }

    if (input_buffer != NULL)
    {
        MMI_ASSERT(input_buffer_size == sizeof(mmi_imc_edit_new_word_screen_history));

        g_imc_edit_new_word_input_mode_list[0] = input_buffer->new_word_input_mode_list[0];
        g_imc_edit_new_word_input_mode_list[1] = input_buffer->new_word_input_mode_list[1];

        g_imc_new_word_input_mode = input_buffer->new_word_input_mode;

        memcpy(g_imc_new_word_buffer, input_buffer->new_word_buffer, sizeof(UI_character_type) * (MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1));
    }

    if (g_imc_edit_new_word_input_mode_list[0] == IMM_INPUT_MODE_NONE)
    {
        return;
    }

#if defined UI_SMALL_CATEGORY_EDITOR
    //enable_resized_small_screen();
	/* Disable small screen for the limitation of screen group*/
#endif 
    
    #if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
    	   wgui_cat9007_show(
        get_string(STR_INPUT_METHOD_SPELL_WORD),
        get_string(STR_GLOBAL_SAVE),
        0,
        get_string(STR_GLOBAL_BACK),
        0,
        IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_ADD_NEW_WORD,
        (PU8) g_imc_new_word_buffer,
        MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1,
        guiBuffer,
        UI_dummy_function,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        g_imc_edit_new_word_input_mode_list);
    }
    else
    #endif
    {
    ShowCategory5Screen_ext(
        STR_INPUT_METHOD_SPELL_WORD,
        0,
        STR_GLOBAL_SAVE,
        0,
        STR_GLOBAL_BACK,
        0,
        IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_ADD_NEW_WORD,
        (PU8) g_imc_new_word_buffer,
        MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1,
        guiBuffer,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        g_imc_edit_new_word_input_mode_list);
     }

    /* Disable clipboard in touch panel */
    wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);

    SetLeftSoftkeyFunction(mmi_imc_save_new_word, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imc_save_new_word, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  

    if ( is_edit_word_from_add_word)
    SetCategory5RightSoftkeyFunction(mmi_imc_edit_new_word_screen_rsk_handler, KEY_EVENT_UP);
    else
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __COSMOS_MMI_PACKAGE__
	is_go_back = 0 ;
	SetKeyHandler(NewWordGoBackHistory, KEY_BACK, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_save_new_word
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_save_new_word(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct imc_msg;
    MMI_BOOL has_forbidden_char = MMI_FALSE;
	S32 str_len = 0;
	S32 i, j;
    mmi_ime_word_add_new_word_ret_value_enum ret = MMI_IME_WORD_ADD_NEW_WORD_FAILED;
	UI_character_type temp_new_word_buffer[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    mmi_ime_word_capital_state_enum old_case;
#endif
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(g_imc_new_word_input_mode != IMM_INPUT_MODE_NONE);

    str_len = mmi_ucs2strlen((const S8 * )&g_imc_new_word_buffer[0]);

    if (mmi_ucs2chr((const S8 * )&g_imc_new_word_buffer[0], 0x20) != NULL 
        || mmi_ucs2chr((const S8 * )&g_imc_new_word_buffer[0], 0x30) != NULL) /* Space and zero are forbidden in new word */
    {
        has_forbidden_char = MMI_TRUE;
    }

    if (g_imc_new_word_buffer[0] != 0 && str_len > 1 && !has_forbidden_char)
    { 
        ret = mmi_ime_word_add_new_word(g_imc_new_word_input_mode, g_imc_new_word_buffer);
    }
    
    mmi_imc_gdi_lcd_freeze(TRUE);
    
    if (ret == MMI_IME_WORD_ADD_NEW_WORD_SUCCESS || ret == MMI_IME_WORD_ADD_NEW_WORD_DUPLICAT)
    {
        /* to return back to editor */
        #if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
        #ifdef __MMI_FRM_HISTORY__
        if(mmi_frm_group_get_active_id() == GRP_ID_INVALID)
        {
            if(is_edit_word_from_add_word)
            { 
				#if defined(__ATV_SMS_SUPPORT__)
   					if( dm_is_fixed_layer_mode_enabled() )
   					{
						GoBackHistory();
					}
					else
				#endif
					{
                GoBacknHistory(1);
                is_edit_word_from_add_word = MMI_FALSE;
					}
            }
            else
            {
                GoBackHistory();
            }
        }
        else
		#endif 
        {
                 mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
                is_edit_word_from_add_word = MMI_FALSE;
        }

        #else
            mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
        #endif

//special case for opera editor,opera will not connect ime in time,need to insert new word by post handle
		if(g_imc_new_word_buffer[0] != 0)
		{
			for (i = 0, j = 0; g_imc_new_word_buffer[i]; i++)
			{
				if (mmi_imm_test_input(&g_imc_new_word_buffer[i], 1))
				{
					g_ime_post_process_data.curr_data[j++] = g_imc_new_word_buffer[i];
				}
			}
			g_ime_post_process_data.curr_data_type = MMI_IMC_POST_NEWWORD_DATA;
		}


        if (g_imc_new_word_buffer[0] != 0 && g_is_ime_connected)
        {
        #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            old_case = g_imc.global_data.capital_state;
    
            mmi_imc_key_change_candidate_case_by_previous_string();
        
            if ((g_imc.mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                && g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
            {
                g_imc_new_word_buffer[0] = mmi_towupper(g_imc_new_word_buffer[0]);
            }

            g_imc.global_data.capital_state = old_case;
        #endif /* #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) */
        
		    for (i = 0, j = 0; g_imc_new_word_buffer[i]; i++)
		    {
			    if (mmi_imm_test_input(&g_imc_new_word_buffer[i], 1))
			    {
				    temp_new_word_buffer[j++] = g_imc_new_word_buffer[i];
			    }
		    }

		    temp_new_word_buffer[j] = 0;
        
            imc_msg.message_id = MMI_IMC_MESSAGE_START_SMART_ALPHABETIC;
		    mmi_imc_send_message(&imc_msg);

            imc_msg.message_id = MMI_IMC_MESSAGE_INSERT_STRING;
            imc_msg.param_0 = (U32)&temp_new_word_buffer[0];
            imc_msg.param_1 = 0;

            mmi_imc_send_message(&imc_msg);
        
		    imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
            mmi_imc_send_message(&imc_msg);
        
        #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
            {
                mmi_event_struct evt;
                
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);

                g_imc_skip_first_cursor_movement_event = MMI_FALSE;
                
                MMI_FRM_CB_EMIT_EVENT(&evt);
            }
        #endif    
        }
    }

    if (ret == MMI_IME_WORD_ADD_NEW_WORD_SUCCESS)
    {
		#if defined(__ATV_SMS_SUPPORT__)
   		    if( dm_is_fixed_layer_mode_enabled() )
   			{
				mmi_mtv_ime_display_popup(STR_GLOBAL_SAVED,MMI_EVENT_SUCCESS );
			}
			else
      #endif
			{
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);
    }
    }
    else if (ret == MMI_IME_WORD_ADD_NEW_WORD_DUPLICAT)
    {
		#if defined(__ATV_SMS_SUPPORT__)
   		    if( dm_is_fixed_layer_mode_enabled() )
   			{
				mmi_mtv_ime_display_popup(STR_INPUT_METHOD_WORD_ALREADY_EXISTS,MMI_EVENT_INFO );
			}
			else
      #endif
			{
        mmi_popup_display((WCHAR*)GetString(STR_INPUT_METHOD_WORD_ALREADY_EXISTS), MMI_EVENT_INFO, NULL);
    }
    }
    else
    {
		#if defined(__ATV_SMS_SUPPORT__)
   		    if( dm_is_fixed_layer_mode_enabled() )
   			{
				mmi_mtv_ime_display_popup(STR_GLOBAL_FAILED_TO_SAVE,MMI_EVENT_INFO );
			}
			else
      #endif
			{
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE, NULL);
    }
    }

	mmi_imc_gdi_lcd_freeze(gdi_freeze);
    mmi_imc_repaint_screen();

    g_imc_new_word_input_mode = IMM_INPUT_MODE_NONE;
    g_imc_new_word_buffer[0] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_exit_edit_new_word_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
 void mmi_imc_exit_edit_new_word_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    static mmi_imc_edit_new_word_screen_history scr_history;
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_history.new_word_input_mode = g_imc_new_word_input_mode;
    scr_history.new_word_input_mode_list[0] = g_imc_edit_new_word_input_mode_list[0];
    scr_history.new_word_input_mode_list[1] = g_imc_edit_new_word_input_mode_list[1];
    memcpy(scr_history.new_word_buffer, &g_imc_new_word_buffer[0], sizeof(UI_character_type) * (MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1));

    g_id = mmi_frm_group_get_active_id();
    #ifdef  __MMI_FRM_HISTORY__
    if (g_id == GRP_ID_INVALID)
    {
        h.scrnID = GetExitScrnID();
        h.entryFuncPtr = mmi_imc_entry_edit_new_word_screen;

        memcpy(h.inputBuffer, &scr_history, sizeof(mmi_imc_edit_new_word_screen_history));

        GetCategoryHistory(h.guiBuffer);

        AddNHistory(h, sizeof(mmi_imc_edit_new_word_screen_history));
    }
    else
    #endif
    {
        mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_imc_edit_new_word_screen_history));
        mmi_frm_scrn_set_active_input_buf_ptr((U16*)&scr_history);
    }
 #if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
	      matv_exit_fptr_ime();
   }
#endif
}

void mmi_imc_entry_add_new_word_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_imc_entry_add_new_word_screen_with_sg(g_id);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_entry_add_new_word_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_entry_add_new_word_screen_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    const sIMEModeDetails * mode_details_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    count = mmi_imm_get_multitap_input_mode_by_writing_language(g_imc_edit_new_word_input_mode_list, 
                                                                mmi_imm_get_current_writing_language(), 
                                                                MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);
#else
    if ((g_imc.mode_details_ptr)->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
    {
        count = mmi_imm_get_multitap_input_mode_by_writing_language(g_imc_edit_new_word_input_mode_list, 
                                                                    g_imc.mode_details_ptr->lang_id, 
                                                                    MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);
    }
#endif

    if (count == 0)
    {
        count = mmi_imm_get_multitap_input_mode_by_writing_language(g_imc_edit_new_word_input_mode_list, 
                                                            IME_WRITING_LANG_ABC, 
                                                            MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);
    }
    
    MMI_ASSERT(count > 0 && count <= MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);

	g_imc_edit_new_word_input_mode_list[count] = IMM_INPUT_MODE_123_SYMBOLS;
    g_imc_edit_new_word_input_mode_list[count + 1] = IMM_INPUT_MODE_NONE;
	if(mmi_imm_get_is_smart_input_mode_of_writing_language())
		mode_details_ptr = mmi_imm_get_corresponding_smart_lower_case_mode(g_imc_edit_new_word_input_mode_list[0]);
	else
	{
		 count = mmi_imm_get_multitap_input_mode_by_writing_language(g_imc_edit_new_word_input_mode_list, 
                                                            IME_WRITING_LANG_ABC, 
                                                            MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);
		 MMI_ASSERT(count > 0 && count <= MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);

		 g_imc_edit_new_word_input_mode_list[count] = IMM_INPUT_MODE_123_SYMBOLS;
		  g_imc_edit_new_word_input_mode_list[count + 1] = IMM_INPUT_MODE_NONE;
    mode_details_ptr = mmi_imm_get_corresponding_smart_lower_case_mode(g_imc_edit_new_word_input_mode_list[0]);
	}
    MMI_ASSERT(mode_details_ptr);
    
    g_imc_new_word_input_mode = mode_details_ptr->imm_mode_id;
        
    if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
    {
        mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, IME_MODE_ATTR_LOWERCASE);
    }
    else
    {
        mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, 0);
    }

    MMI_ASSERT(mode_details_ptr);

	mmi_imm_set_default_input_mode(mode_details_ptr->imm_mode_id);

    memset(&g_imc_new_word_buffer[0], 0, sizeof(UI_character_type) * MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1);

    is_edit_word_from_add_word = MMI_TRUE;
    mmi_imc_entry_edit_new_word_screen_with_sg(g_id);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_entry_spell_new_word_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_entry_spell_new_word_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails *mode_details_ptr;
    S32 count = 0;
	#if defined(__MMI_IME_LOW_TIER_UI__)
    mmi_imc_message_struct  imc_msg;
    #endif
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_V3__) && defined(__MMI_IMC_CAPITAL_SWITCH__) 
	mmi_imm_set_curr_writing_lang_by_curr_mode();
#endif
        
#if defined(__MMI_IMC_CAPITAL_SWITCH__) 
    count = mmi_imm_get_multitap_input_mode_by_writing_language(g_imc_edit_new_word_input_mode_list, 
                                                                mmi_imm_get_current_writing_language(), 
                                                                MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);
#else
    if ((g_imc.mode_details_ptr)->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
    {
        count = mmi_imm_get_multitap_input_mode_by_writing_language(g_imc_edit_new_word_input_mode_list, 
                                                                    g_imc.mode_details_ptr->lang_id, 
                                                                    MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);
    }
#endif
    
    if (count == 0)
    {
        count = mmi_imm_get_multitap_input_mode_by_writing_language(g_imc_edit_new_word_input_mode_list, 
                                                                    IME_WRITING_LANG_ABC, 
                                                                    MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);
    }
    
    MMI_ASSERT(count > 0 && count <= MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG - 2);
 
    g_imc_edit_new_word_input_mode_list[count] = IMM_INPUT_MODE_123_SYMBOLS;
    g_imc_edit_new_word_input_mode_list[count + 1] = IMM_INPUT_MODE_NONE;

    g_imc_new_word_input_mode = mmi_imm_get_curr_input_mode();

    mode_details_ptr = mmi_imm_get_corresponding_smart_lower_case_mode(g_imc_edit_new_word_input_mode_list[0]);

    if (mode_details_ptr)
    {
        if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
        {
            mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, IME_MODE_ATTR_LOWERCASE);
        }
        else
        {
            mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, 0);
        }
    }
    else
    {
        mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(g_imc_new_word_input_mode, 0);
    }

    MMI_ASSERT(mode_details_ptr);

	mmi_imm_set_default_input_mode(mode_details_ptr->imm_mode_id);

    memset(&g_imc_new_word_buffer[0], 0, sizeof(UI_character_type) * MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1);

#if defined(__MMI_VUI_ENGINE__)
    if (!vadp_p2v_uc_is_in_venus())
#endif
    {
        mmi_imc_gdi_lcd_freeze(TRUE);
    }

#if defined(__MMI_IME_LOW_TIER_UI__)
    {
        UI_buffer_type start_p = NULL, end_p = NULL;
        UI_character_type pre_char;
        S32 length = 0;

        imc_msg.message_id = MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD;
        imc_msg.param_0 = (U32)&start_p;
        imc_msg.param_1 = (U32)&end_p;

        length = (S32)mmi_imc_send_message(&imc_msg);

        MMI_ASSERT(start_p && end_p);

        MMI_ASSERT(length == g_imc.global_data.cand_length);

        imc_msg.message_id = MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR;
        imc_msg.param_0 = (U32)&pre_char;
        imc_msg.param_1 = 0;

        mmi_imc_send_message(&imc_msg);

        if (pre_char == (UI_character_type)'?')
        {
            /* Set the preset string of new word */
            memcpy(&g_imc_new_word_buffer[0], 
                   start_p, 
                   sizeof(UI_character_type) * (g_imc.global_data.cand_length - 1)); /* Reduce by 1 for filtering out '?' */
        }
        else
        {
            memcpy(&g_imc_new_word_buffer[0], 
                   start_p, 
                   sizeof(UI_character_type) * (g_imc.global_data.cand_length)); 
        }
        
        imc_msg.message_id = MMI_IMC_MESSAGE_DELETE_STRING;
        imc_msg.param_0 = (U32)g_imc.global_data.cand_length;
        imc_msg.param_1 = 0;
        mmi_imc_send_message(&imc_msg);
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    }
#endif /* #if defined(__MMI_IME_LOW_TIER_UI__) */

#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_show_new_word_editor();
    }
    else
#endif
    {
        mmi_imc_entry_edit_new_word_screen();
    
        mmi_imc_gdi_lcd_freeze(gdi_freeze);

        mmi_imc_repaint_screen();
    }
}
#endif /* defined(__MMI_IME_USER_DATABASE__) */

//#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_candidates_from_word_engine
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_imc_get_associates_from_word_engine( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL changed = MMI_FALSE;
    S32 count = 0, i = 0, j = 0;
    S32 first_index = 0;
    S32 cand_len = 0;
    mmi_ime_query_param_struct query = {0};
    mmi_ime_query_result_struct result = {0};
    S32 cand_len_total = 0;
    S32 flags = 0;
    U8 valid_flag = 0;
    MMI_BOOL check = MMI_FALSE;
//#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined __MMI_XT9__
    S32 temp_cand_count;
//#endif
    UI_string_type cand_buff = result_ptr->result_buffer, temp_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
    if (param_ptr->desired_cnt > MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN_VER)
    {
        param_ptr->desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN_VER;
    }
#endif
    
    memcpy(&query, param_ptr, sizeof(mmi_ime_query_param_struct));
    memcpy(&result, result_ptr, sizeof(mmi_ime_query_result_struct));

    if (!g_imc.global_data.cand_check_cnt)
    {
        changed = MMI_TRUE;
    }
    
    if (changed && param_ptr->first_index)
    {
        ASSERT(0);
    }
    
    count = param_ptr->desired_cnt;
    first_index = param_ptr->first_index;
    
    if (!changed)
    {
        /* first index mapping */
        mmi_imc_candidate_index_mapping(&first_index);        
    }
    
    query.desired_cnt = param_ptr->desired_cnt;
    result.result_buffer = g_mmi_imc_temp_cand;
    query.first_index = first_index;
    
    while (i < count + 1) /* to get more one item to check the next page. */    
    {
        mmi_ime_word_get_associates(&query, &result);
        if (!result.result_cnt)
            break;
    
        temp_ptr = &g_mmi_imc_temp_cand[0];
        j = 0;
    
        while (j < result.result_cnt)
        {
            cand_len = mmi_ucs2strlen((const S8*)temp_ptr);
    
            if (!changed && query.first_index + j < g_imc.global_data.cand_check_cnt)
            {
                /* get old data  */
                valid_flag = g_imc.global_data.cand_valid_flags[(query.first_index + j)/8];
                
                if ( (valid_flag & (1 << (7 - (query.first_index + j) % 8))))
                {
                    check = MMI_TRUE;
                }
                else
                {
                    check = MMI_FALSE;
                }
            }
            else
            {
                /* check for new candidate */
                if (mmi_imc_candidate_check(temp_ptr, cand_len))
                {
                    check = MMI_TRUE;
                }
                else
                {
                    check = MMI_FALSE;
                }
            }
    
            if (check)
            {
                if (cand_len_total + cand_len + 1 > MMI_IMC_MAX_CANDIDATE_BUFFSIZE)
                {
                    break;
                }
                else
                {
                    memcpy(cand_buff + cand_len_total, temp_ptr, sizeof(UI_character_type)*cand_len);
                    cand_len_total+= (cand_len + 1);
                    result_ptr->result_buffer[cand_len_total - 1] = '\0';
                    flags = ((flags << 1) | 1);            
                    i++;
                }
            }
            else
            {
                flags = (flags << 1);            
            }
    
            j++;
            temp_ptr += (cand_len + 1);
        }
    
        query.first_index += result.result_cnt;
        
    }
    
    result_ptr->result_cnt = ((i > count)? count: i);
    
    if (i <= count)
    {
        result_ptr->next_page = MMI_FALSE;
    }
    else
    {
        result_ptr->next_page = MMI_TRUE;
    }
    
    
    if (result_ptr->result_cnt != 0)
    {
        if (g_imc.global_data.capital_state != MMI_IME_WORD_CAPITAL_STATE_NONE)
        {
            temp_cand_count = g_imc.global_data.cand_count;
            g_imc.global_data.cand_count = result_ptr->result_cnt;
            mmi_imc_change_candidate_list_caps(g_imc.global_data.capital_state);
            g_imc.global_data.cand_count = temp_cand_count;
        }
        if (changed)
        {
            mmi_imc_reset_candidate_valid_flag();
        }
        mmi_imc_set_candidate_valid_flag(first_index, flags, query.first_index - first_index);        
    }
}
//#endif /* #if defined(__MMI_ALPHABETIC_WORD_PREDICTION__) */




#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_smart_alphabetic_word_reselection
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_config_smart_alphabetic_word_reselection(MMI_BOOL is_enalbed)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_imc_is_reselection_enabled = is_enalbed;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_smart_alphabetic_word_reselection_enabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_smart_alphabetic_word_reselection_enabled(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_imc_is_reselection_enabled;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_reselection_input_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_reselection_input_mode(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails *mode_details_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc.mode_details_ptr->imm_mode_id == input_mode)
    {
        if ((g_imc.mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
              && (g_imc.mode_details_ptr->Lang_Special_Attrib& IME_LANG_ATTR_ALPHABETIC))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);

        if (!mode_details_ptr)
        {
            return MMI_FALSE;
        }
        else
        {
            if ((mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                && (mode_details_ptr->Lang_Special_Attrib& IME_LANG_ATTR_ALPHABETIC))
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_valid_alphabetic_word_of_current_input_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_valid_alphabetic_word_of_current_input_mode(U8 *str_ptr, S32 str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    UI_character_type char_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_is_ime_connected)
    {
        return MMI_FALSE;
    }
    
    if (!((g_imc.mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
          && (g_imc.mode_details_ptr->Lang_Special_Attrib& IME_LANG_ATTR_ALPHABETIC)))
    {
        return MMI_FALSE;
    }
    
    for (i = 0; i < str_len; i++)
    {
        UI_STRING_GET_NEXT_CHARACTER(str_ptr, char_code);

        if (char_code == 0x1b) /* For the special case of ems extention char */
        {
            continue;
        }

        if (char_code == 0)
        {
            return MMI_FALSE;
        }
        else
        {
            if (mmi_ime_word_map_char_to_symbol(g_imc.mode_details_ptr->imm_mode_id, char_code) == MMI_IMC_SYMB_KEY_INVALID)
            {
                return MMI_FALSE;
            }
        }
    }

    return MMI_TRUE;
}
#endif /* #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)    */

/* Dummy functions for non-vendor case */

#if defined(__MMI_NO_IME_VENDOR__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_spellings
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_get_spellings( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_candidates
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_get_candidates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_associates
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_get_associates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_set_context
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_ime_word_set_context( U8 context )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_valid_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_valid_key( mmi_imm_input_mode_enum input_mode, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_symbol_to_code
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
UI_character_type mmi_ime_word_symbol_to_code(U16 symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_code_to_symbol
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
U16  mmi_ime_word_code_to_symbol(UI_character_type code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_symbol_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_symbol_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_redicals
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_redicals(UI_character_type key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_wildcard
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_is_wildcard(UI_character_type code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_add_separator_to_candidate_buffer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_ime_word_add_separator_to_candidate_buffer(UI_character_type * destination_buffer, UI_character_type * source_buffer, S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < num && source_buffer[i] != 0)
    {
        destination_buffer[j] = source_buffer[i];
        destination_buffer[j + 1] = 0; /* Default separator is '\0' */
        i++;
        j += 2;
    }
	
    destination_buffer[j] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_engine_get_char_info
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_engine_get_char_info(UI_character_type code, UI_string_type info_buffer, S32 buffer_size, mmi_imm_input_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_map_char_to_symbol
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
mmi_imc_symbol_key_enum mmi_ime_word_map_char_to_symbol(mmi_imm_input_mode_enum input_mode, UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_init( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_deinit
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_deinit( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_change_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_change_mode(const sIMEModeDetails * mode_details_ptr, U32 reserved )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_leave_current_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_ime_word_leave_current_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_change_word_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void   mmi_ime_word_change_word_case(mmi_ime_word_capital_state_enum capital_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#if defined(__MMI_IME_MAGIC_ONE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_magic_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_is_magic_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}
#endif

#endif /* #if defined(__MMI_NO_IME_VENDOR__) */


#ifdef __MMI_CLIPBOARD__ 

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_enter_locate_start_cursor_state
 * DESCRIPTION
 *  Enter locate cursor state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_enter_locate_start_cursor_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If editor content is empty, should return directly */
    if (mmi_imc_clipboard_is_editor_empty())
    {
        return;
    }
    
#ifdef __MMI_MESSAGES_EMS__
    EMS_disable_audio_playback();
    gui_EMS_input_box_disable_sound(MMI_TRUE);
#endif

    /* Because app's LNK/RNK will be override in mmi_imc_set_state so we should save here, not in MMI_IMC_MESSAGE_CLIPBOARD_SAVE_STATUS */
    mmi_imc_clipboard_save_keys();

    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_CLIPBOARD_CCP_ENTER_LOCATE_START_CURSOR_STATE);
    mmi_imc_set_state(MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS);

    memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_SAVE_STATUS;
    imc_msg.param_0 = (U32)&g_imc_clipboard_data;
    imc_msg.param_1 = 1;
    mmi_imc_send_message(&imc_msg);

    mmi_imc_clipboard_redraw_screen_by_state();
    if ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
        (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX))
    {
        wgui_inputs_ml_set_style(UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT, 0);
    }

#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_disable_sound(MMI_FALSE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_enter_mark_text_state
 * DESCRIPTION
 *  Enter mark text state
 * PARAMETERS
 *  mark          [IN]              MARK_TEXT_BY_KEY for key and MARK_TEXT_BY_PEN for pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_enter_mark_text_state(mmi_imc_clipboard_mark_text_enum mark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_disable_audio_playback();
    gui_EMS_input_box_disable_sound(MMI_TRUE);
#endif

    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_CLIPBOARD_CCP_ENTER_MARK_TEXT_STATE);
    if (!g_imc_clipboard_data.is_saved)
    {
        memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
        imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_SAVE_STATUS;
        imc_msg.param_0 = (U32)&g_imc_clipboard_data;
        imc_msg.param_1 = 0;
        mmi_imc_send_message(&imc_msg);
    }

    if (mark == MARK_TEXT_BY_KEY)
    {
        mmi_imc_set_state(MMI_IMC_STATE_CLIPBOARD_MARK_TEXT);
    }
    else
    {
        mmi_imc_set_state(MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN);
    }

#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_disable_sound(MMI_FALSE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_go_back_to_initial
 * DESCRIPTION
 *  Go back to inital state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_go_back_to_initial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_CLIPBOARD_CCP_GOBACK_INITIAL_STATE, g_imc_clipboard_data.is_saved);

    mmi_imc_key_set_pre_key_handler(g_imc_app_pre_key_hander);

    mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
    if (g_imc_clipboard_data.is_saved)
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_RESTORE_STATUS;
        imc_msg.param_0 = (U32)&g_imc_clipboard_data;
        mmi_imc_send_message(&imc_msg);
        memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
    }

#ifdef __MMI_MESSAGES_EMS__
    EMS_enable_audio_playback();
#endif
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    mmi_imc_redraw_screen_by_state();
    mmi_imc_gdi_lcd_freeze(lcd_freeze);
    mmi_imc_repaint_screen();
    mmi_imc_clipboard_restore_keys();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_show_hide_cascading_menu
 * DESCRIPTION
 *  Clipboard show hide cascading menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_show_hide_cascading_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_text_highlight, is_password, is_empty, is_read_only, is_clipboard_empty, is_wcss;
    MMI_BOOL is_allowed_cut_all;
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_text_highlight = mmi_imc_clipboard_is_text_highlight();
    is_password = mmi_imc_clipboard_is_editor_password();
    is_empty = mmi_imc_clipboard_is_editor_empty();
    is_read_only = mmi_imc_clipboard_is_editor_read_only();
    is_clipboard_empty = mmi_imc_clipboard_is_empty();
    is_wcss = mmi_imc_clipboard_is_editor_WCSS();

    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_IS_ALLOWED_CUT_ALL;
    is_allowed_cut_all = (MMI_BOOL)mmi_imc_send_message(&imc_msg);

    /* Menu item: Copy */
    if (is_text_highlight && !is_password)
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_OPTION_COPY);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_OPTION_COPY);
    }
    
    /* Menu item: Copy all */
    if (is_empty || is_password)
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL);
    }

    /* Menu item: Cut */
    if (is_text_highlight && !is_read_only && !is_password)
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_OPTION_CUT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_OPTION_CUT);
    }

    /* Menu item: Cut all */
    if ((is_empty || is_read_only || is_password) && !(is_allowed_cut_all && !is_text_highlight))
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL);
    }

    /* Menu item: paste */
    if (is_clipboard_empty || is_read_only || is_wcss || is_text_highlight)
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_show_hide_edit_option_menu
 * DESCRIPTION
 *  Clipboard show hide edit option menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_show_hide_edit_option_menu(mmi_imc_editor_menu_history_data_struct_p history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_empty, is_read_only, is_paging, is_wcss, is_password;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history == NULL)
    {
        is_empty = g_editor_history_data.is_empty;
        is_read_only = g_editor_history_data.is_read_only;
        is_paging = g_editor_history_data.is_paging;
        is_wcss = g_editor_history_data.is_wcss;
        is_password = g_editor_history_data.is_password;
    }
    else
    {
        is_empty = g_editor_history_data.is_empty = history->is_empty;
        is_read_only = g_editor_history_data.is_read_only = history->is_read_only;
        is_paging = g_editor_history_data.is_paging = history->is_paging;
        is_wcss = g_editor_history_data.is_wcss = history->is_wcss;
        is_password = g_editor_history_data.is_password = history->is_password;
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_REDUCED_KEYPAD__)
    /* Hide mark text option because in FTE, user can mark text using keypad */
    mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_MARK);
#else /* __MMI_FTE_SUPPORT__ */
    /* Menu item: Mark text */
    if (is_empty || is_password)
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_MARK);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_MARK);
    }
#endif /* __MMI_FTE_SUPPORT__ */

    /* Menu item: Copy all */
    if (is_empty || is_paging || is_password)
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL);
    }

    /* Menu item: Cut all */
    if (is_empty || is_read_only || is_password)
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL);
    }

    /* Menu item: paste */
    if (mmi_imc_clipboard_is_empty() || is_read_only || is_wcss)
    {
        mmi_frm_hide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE);
    }
}


#ifdef __MMI_CLIPBOARD_FLOATING_MENU__

extern S32 UI_cursor_x2;    /* cursor x1 postioon */
extern S32 UI_cursor_y2;    /* cursor y1 position */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_config_floating_menu
 * DESCRIPTION
 *  Config Clipboard floating menu
 * PARAMETERS
 *  menu             [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_imc_clipboard_config_floating_menu(mmi_imui_update_clipboard_floating_menu_struct_p menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 menu_cnt = 0;
    MMI_BOOL is_text_highlight, is_password, is_empty, is_read_only, is_clipboard_empty, is_wcss;
    MMI_BOOL is_allowed_cut_all;
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_text_highlight = mmi_imc_clipboard_is_text_highlight();
    is_password = mmi_imc_clipboard_is_editor_password();
    is_empty = mmi_imc_clipboard_is_editor_empty();
    is_read_only = mmi_imc_clipboard_is_editor_read_only();
    is_clipboard_empty = mmi_imc_clipboard_is_empty();
    is_wcss = mmi_imc_clipboard_is_editor_WCSS();

    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_IS_ALLOWED_CUT_ALL;
    is_allowed_cut_all = (MMI_BOOL)mmi_imc_send_message(&imc_msg);

    /* Menu item: Copy */
    if (is_text_highlight && !is_password)
    {
        menu->menu_item[menu_cnt].button_type = MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_COPY;
        menu_cnt++;
    }
    
    /* Menu item: Copy all */
    if (!(is_empty || is_password) && !is_text_highlight)
    {
        menu->menu_item[menu_cnt].button_type = MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_COPY_ALL;
        menu_cnt++;
    }

    /* Menu item: Cut */
    if (is_text_highlight && !is_read_only && !is_password)
    {
        menu->menu_item[menu_cnt].button_type = MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_CUT;
        menu_cnt++;
    }

    /* Menu item: Cut all */
    if ((!(is_empty || is_read_only || is_password) && !is_text_highlight) || (is_allowed_cut_all && !is_text_highlight))
    {
        menu->menu_item[menu_cnt].button_type = MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_CUT_ALL;
        menu_cnt++;
    }

    /* Menu item: paste */
    if (!(is_clipboard_empty || is_read_only || is_wcss || is_text_highlight))
    {
        menu->menu_item[menu_cnt].button_type = MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_PASTE;
        menu_cnt++;
    }

    MMI_ASSERT(menu_cnt <= MMI_IMUI_CLIPBOARD_FOLATING_MENU_NUM);

    menu->count = menu_cnt;
    return menu_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_show_option_floating_menu
 * DESCRIPTION
 *  Clipboard show copy/cut/paste floating menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_show_option_floating_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_update_clipboard_floating_menu_struct float_menu;
    U8 menu_cnt;
    mmi_imui_message_struct imui_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&float_menu, 0, sizeof(mmi_imui_update_clipboard_floating_menu_struct));

    menu_cnt = mmi_imc_clipboard_config_floating_menu(&float_menu);

    if (menu_cnt > 0)
    {
        mmi_imui_create_clipboard_floating_menu_item(&float_menu, float_menu.count, UI_cursor_x2, UI_cursor_y2 + 1);
        imui_msg.message_id = MMI_IMUI_MESSAGE_UPDATE_CLIPBOARD_FLOATING_MENU;
        imui_msg.param_0 = (U32)&(float_menu);
        mmi_imui_send_message(&imui_msg, NULL);
    }
    else
    {
        /* If no available menu item, go back initial state */
        mmi_imc_clipboard_go_back_to_initial();
    }
}

#endif /* __MMI_CLIPBOARD_FLOATING_MENU__ */


#if defined(__ATV_SMS_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_close_option_menu
 * DESCRIPTION
 *  Close option menu when in mark text state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_close_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_disable_audio_playback();
    gui_EMS_input_box_disable_sound(MMI_TRUE);
#endif

    g_imc_clipboard_data.close_flag = 1;
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif
    GoBackHistory();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif

    if (mmi_imc_is_connected())
    {
        /* If only can mark by pen, don't set highlight and restore states */
        if ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_SINGLE_LINE_INPU_BOX) ||
            ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
             (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_NORMAL_INPUT_BOX)) ||
            (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INPUT_BOX_READ_ONLY && !(wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_EMS_INPUT_BOX)) ||
            (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER) ||
            (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK) ||
            (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX))
        {
            mmi_imc_clipboard_save_keys();
            mmi_imc_clipboard_go_back_to_initial();
            mmi_imc_clipboard_restore_keys();
        }
        else
        {
            /* Set highlight and mark text state */
            imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_SET_HIGHLIGHT;
            imc_msg.param_0 = (U32)&g_imc_clipboard_data;
            mmi_imc_send_message(&imc_msg);

            mmi_imc_set_state(MMI_IMC_STATE_CLIPBOARD_MARK_TEXT);
            if ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
                (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX))
            {
            #if(UI_DOUBLE_BUFFER_SUPPORT)
                gui_lock_double_buffer();
            #endif    
                mmi_imc_redraw_screen_by_state();
            #if(UI_DOUBLE_BUFFER_SUPPORT)
                gui_unlock_double_buffer();
            #endif
                wgui_inputs_ml_set_style(UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT, 0);
                wgui_inputs_ml_show();
            }
            else
            {
                mmi_imc_clipboard_redraw_screen_by_state();
            }
        }
    }
    else
    {
#if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif    
        g_imc_clipboard_data.close_flag = 0;
    }

#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_disable_sound(MMI_FALSE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_clipboard_entry_option_menu
 * DESCRIPTION
 *  Entry fn for clipboard option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_clipboard_entry_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_string[MAX_SUB_MENUS];
    U16 list_num;
    U8  *gui_buffer;
    U8  *input_buffer;
    U16 input_buffer_size;
    U16 scr_id = 0;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();

	#ifdef __MMI_FRM_HISTORY__ 
    if (g_id == GRP_ID_INVALID)
    {
        if (CheckIsBackHistory())
        {
            scr_id = GetCurrScrnId();
        }
        else
        {
            scr_id = mmi_ime_gen_editor_common_scr_id(SCR_ID_CLIPBOARD_EDIT_OPTION);

            if (!scr_id)
            {
                MMI_ASSERT(0);
            }
        }

        EntryNewScreen(scr_id, ExitClipboardOptionScreen, NULL, NULL);
    #if defined(__ATV_SMS_SUPPORT__)
        if(matv_init_fptr_ime != NULL)
        {
            matv_init_fptr_ime();
        }
    #endif
        gui_buffer = GetCurrGuiBuffer(scr_id);
        input_buffer = GetCurrNInputBuffer(scr_id, &input_buffer_size);
    }
    else
  #endif 
    {
        if (mmi_frm_scrn_enter(g_id , SCR_ID_CLIPBOARD_EDIT_OPTION, NULL, mmi_ime_clipboard_entry_option_menu, 0) == MMI_FALSE)
        {
            return;
        }
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();	
    }

    /* Get menu resource */
    list_num = GetNumOfChild_Ext(MENU_ID_CLIPBOARD_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_CLIPBOARD_OPTION, list_string);
    SetParentHandler(MENU_ID_CLIPBOARD_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    RegisterInputMethodScreenCloseFunction(GoBackHistory);

    wgui_list_menu_enable_access_by_shortcut();
    wgui_cat1018_show(
        (WCHAR*)GetString(STR_ID_CLIPBOARD_EDIT_OPTION),
        NULL,
        (WCHAR*)GetString(STR_GLOBAL_OK),
        NULL,
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        NULL,
        list_num,
        list_string,
        (U16*)gIndexIconsImageList,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(mmi_imc_clipboard_close_option_menu, KEY_EVENT_UP);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_show_option_menu
 * DESCRIPTION
 *  Clipboard show copy/cut/paste cascading menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_show_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_clipboard_show_hide_cascading_menu();

    if (GetNumOfChild_Ext(MENU_ID_CLIPBOARD_OPTION) > 0)
    {
#if defined(__ATV_SMS_SUPPORT__)
        if( dm_is_fixed_layer_mode_enabled() )
        {
            mmi_ime_clipboard_entry_option_menu();
        }
        else
#endif
        {
            DisplayCascadingMenu(MENU_ID_CLIPBOARD_OPTION, mmi_imc_clipboard_option_handle);
            SetRightSoftkeyFunction(mmi_imc_clipboard_close_cascading_option_menu, KEY_EVENT_UP);
        }
    }
    else
    {
        /* If no available menu item, go back initial state */
        mmi_imc_clipboard_go_back_to_initial();
    }
}
#if defined(UI_EMS_SUPPORT)
extern UI_EMS_input_box MMI_EMS_inputbox;
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_close_cascading_option_menu
 * DESCRIPTION
 *  Redraw screen in editiable mode in clipboard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_redraw_screen_by_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(UI_EMS_SUPPORT)
	U32      old_flags = 0;
    if (wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_EMS_INPUT_BOX)
    {
        old_flags = MMI_EMS_inputbox.flags;
        MMI_EMS_inputbox.flags &= ~UI_EMS_INPUT_BOX_VIEW_MODE;
    #ifdef __MMI_MESSAGES_EMS__
        EMS_cancel_object_focus();
    #endif
    }
#endif
    mmi_imc_redraw_screen_by_state();
#if defined(UI_EMS_SUPPORT)
    if (wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_EMS_INPUT_BOX)
    {
        MMI_EMS_inputbox.flags = old_flags;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_close_cascading_option_menu
 * DESCRIPTION
 *  Clipboard show copy/cut/paste cascading menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_clipboard_close_cascading_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_disable_audio_playback();
    gui_EMS_input_box_disable_sound(MMI_TRUE);
#endif

    g_imc_clipboard_data.close_flag = 1;

    mmi_imc_gdi_lcd_freeze(TRUE);
    CloseCascadingMenu();
    mmi_imc_gdi_lcd_freeze(gdi_freeze);

    if (mmi_imc_is_connected())
    {
        /* If only can mark by pen, don't set highlight and restore states */
        if ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_SINGLE_LINE_INPU_BOX) ||
            ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
             (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_NORMAL_INPUT_BOX)) ||
            (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INPUT_BOX_READ_ONLY && !(wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_EMS_INPUT_BOX)) ||
            (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER) ||
            (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK) ||
            (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX))
        {
            mmi_imc_clipboard_save_keys();
            mmi_imc_clipboard_go_back_to_initial();
            mmi_imc_clipboard_restore_keys();
        }
        else
        {
            mmi_imc_clipboard_save_keys();

            /* Set highlight and mark text state */
            imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_SET_HIGHLIGHT;
            imc_msg.param_0 = (U32)&g_imc_clipboard_data;
            mmi_imc_send_message(&imc_msg);

            mmi_imc_set_state(MMI_IMC_STATE_CLIPBOARD_MARK_TEXT);
            if ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
                (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX))
            {
            #if(UI_DOUBLE_BUFFER_SUPPORT)
                gui_lock_double_buffer();
            #endif    
                mmi_imc_redraw_screen_by_state();
            #if(UI_DOUBLE_BUFFER_SUPPORT)
                gui_unlock_double_buffer();
            #endif
                wgui_inputs_ml_set_style(UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT, 0);
                wgui_inputs_ml_show();
            }
            else
            {
                mmi_imc_clipboard_redraw_screen_by_state();
            }
        }
    }
    else
    {
#if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif    
        g_imc_clipboard_data.close_flag = 0;
    }

#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_disable_sound(MMI_FALSE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_option_handle
 * DESCRIPTION
 *  Clipboard option menu handle
 * PARAMETERS
 *  menu_id     [IN]    Menu itme id
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_option_handle(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    mmi_imc_clipboard_ret_enum clipboard_ret;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_disable_audio_playback();
    gui_EMS_input_box_disable_sound(MMI_TRUE);
#endif

    g_imc_clipboard_data.close_flag = 1;
    /* Disable show function when go back history */
    #if defined(UI_EMS_SUPPORT)
    wgui_inputs_EMS_disalbe_show(MMI_TRUE);
    #endif
    mmi_imc_gdi_lcd_freeze(TRUE);

    GoBackHistory();
    #if defined(UI_EMS_SUPPORT)
    wgui_inputs_EMS_disalbe_show(MMI_FALSE);
    #endif
    if (!mmi_imc_is_connected())
    {
        mmi_imc_gdi_lcd_freeze(gdi_freeze);
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    #ifdef __MMI_MESSAGES_EMS__
        gui_EMS_input_box_disable_sound(MMI_FALSE);
    #endif
        g_imc_clipboard_data.close_flag = 0;
        return MMI_FALSE;
    }

    switch (menu_id)
    {
        case MENU_ID_CLIPBOARD_OPTION_COPY:
            clipboard_ret = mmi_imc_clipboard_copy();
            break;
    
        case MENU_ID_CLIPBOARD_OPTION_CUT:
            clipboard_ret = mmi_imc_clipboard_cut();
            break;

        case MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE:
            clipboard_ret = mmi_imc_clipboard_paste();
            break;
    
        case MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL:
            clipboard_ret = mmi_imc_clipboard_copy_all();
            break;
    
        case MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL:
            clipboard_ret = mmi_imc_clipboard_cut_all();
            break;
    
        default:
            clipboard_ret = MMI_IMC_CLIPBOARD_RET_NONE;
            break;
    }
	
	if (menu_id == MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE)
	{
	    mmi_imc_gdi_lcd_freeze(gdi_freeze);
	}
    mmi_imc_clipboard_go_back_to_initial();
#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_disable_sound(MMI_FALSE);
#endif
	if (menu_id != MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE)
	{
	    mmi_imc_gdi_lcd_freeze(gdi_freeze);
	}

    if ((clipboard_ret == MMI_IMC_CLIPBOARD_RET_OK) && (menu_id != MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE))
    {
        memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
        ret = MMI_TRUE;
    #if defined(__ATV_SMS_SUPPORT__)
        if(dm_is_fixed_layer_mode_enabled())
        {
            mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_COPY_SUCESS, MMI_EVENT_SUCCESS);
        }
        else
    #endif
        {
            mmi_popup_display((WCHAR*)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS, NULL);
        }
    }
    else if ((clipboard_ret == MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH) && (menu_id != MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE))
    {
        memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
        ret = MMI_TRUE;
    #if defined(__ATV_SMS_SUPPORT__)
        if(dm_is_fixed_layer_mode_enabled())
        {
            mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY, MMI_EVENT_INFO);
        }
        else
    #endif
        {
            mmi_popup_display((WCHAR*)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO, NULL);
        }
    }
    else if (clipboard_ret == MMI_IMC_CLIPBOARD_RET_CUT_UNSUPPRT_CONTENT)
    {
        memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
        ret = MMI_TRUE;
    #if defined(__ATV_SMS_SUPPORT__)
        if(dm_is_fixed_layer_mode_enabled())
        {
            mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT, MMI_EVENT_INFO);
        }
        else
    #endif
        {
            mmi_popup_display((WCHAR*)GetString(STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT), MMI_EVENT_INFO, NULL);
        }
    }
    else if ((clipboard_ret == MMI_IMC_CLIPBOARD_RET_OK) && (menu_id == MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE))
    {
        ret = MMI_TRUE;
    }
    else if (clipboard_ret == MMI_IMC_CLIPBOARD_RET_MEMORY_ERROR)
    {
        ret = MMI_FALSE;
    #if defined(__ATV_SMS_SUPPORT__)
        if(dm_is_fixed_layer_mode_enabled())
        {
            mmi_mtv_ime_display_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_FAILURE);
        }
        else
    #endif
        {
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE, NULL);
        }
    }
    else
    {
        ret = MMI_FALSE;
    #if defined(__ATV_SMS_SUPPORT__)
        if(dm_is_fixed_layer_mode_enabled())
        {
            mmi_mtv_ime_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
        }
        else
    #endif
        {
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
        }
    }

    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_CLIPBOARD_CCP_OPTION_HANDLE_END, clipboard_ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_copy
 * DESCRIPTION
 *  Clipboard copy
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_imc_clipboard_ret_enum
 *****************************************************************************/
mmi_imc_clipboard_ret_enum mmi_imc_clipboard_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *copy_str;
    mmi_clipboard_unicodetext_data_struct cb_data;
    mmi_clipboard_handle handle;
    mmi_imc_message_struct  imc_msg;
    U32 free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free space should subtract the cb_data.len size */
    free_space = WGUI_INPUTS_CLIPBOARD_MAX_SIZE;

    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_CLIPBOARD_CCP_COPY, free_space, g_imc_clipboard_data.highlight_text_length);
    
    if (mmi_imc_clipboard_is_text_highlight())
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_GET_HIGHLIGHT_TEXT;
        imc_msg.param_0 = (U32)&g_imc_clipboard_data;
        imc_msg.param_1 = (U32)&copy_str;
        mmi_imc_send_message(&imc_msg);
        cb_data.len = (abs(g_imc_clipboard_data.highlight_text_length) > (S32)(free_space / ENCODING_LENGTH)) ? (free_space / ENCODING_LENGTH) : abs(g_imc_clipboard_data.highlight_text_length);
        if (copy_str != NULL && cb_data.len > 0)
        {
            cb_data.data = copy_str;
            handle  = mmi_clipboard_set_data(MMI_CLIPBOARD_FORMAT_UNICODETEXT, (void*)&cb_data);
            if (handle)
            {
                if (abs(g_imc_clipboard_data.highlight_text_length) <= (S32)(free_space / ENCODING_LENGTH))
                {
                    return MMI_IMC_CLIPBOARD_RET_OK;
                }
                else
                {
                    return MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH;
                }
            }
            else
            {
                /* error handling */
                return MMI_IMC_CLIPBOARD_RET_MEMORY_ERROR;
            }
        }
        else
        {
            return MMI_IMC_CLIPBOARD_RET_NO_TEXT;
        }
    }
    else
    {
        /* error handling */
        return MMI_IMC_CLIPBOARD_RET_NO_TEXT_HIGHLIGH;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_copy_all
 * DESCRIPTION
 *  Clipboard copy all
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_imc_clipboard_ret_enum
 *****************************************************************************/
mmi_imc_clipboard_ret_enum mmi_imc_clipboard_copy_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *copy_str = NULL;
    U32 text_len = 0;
    mmi_clipboard_unicodetext_data_struct cb_data;
    mmi_clipboard_handle handle;
    mmi_imc_message_struct  imc_msg;
    U32 free_space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_GET_ALL_TEXT;
    imc_msg.param_0 = (U32)&copy_str;
    imc_msg.param_1 = (U32)&text_len;
    mmi_imc_send_message(&imc_msg);

    /* Free space should subtract the cb_data.len size */
    free_space = WGUI_INPUTS_CLIPBOARD_MAX_SIZE;

    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_CLIPBOARD_CCP_COPY_ALL, free_space, (text_len / ENCODING_LENGTH));

    if (copy_str != NULL && text_len > 0)
    {
        cb_data.data = copy_str;
        cb_data.len = ((text_len > free_space) ? free_space : text_len) / ENCODING_LENGTH;
        handle  = mmi_clipboard_set_data(MMI_CLIPBOARD_FORMAT_UNICODETEXT, (void*)&cb_data);
        if (handle)
        {
            if (text_len <= free_space)
            {
                return MMI_IMC_CLIPBOARD_RET_OK;
            }
            else
            {
                return MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH;
            }
        }
        else
        {
            /* error handling */
            return MMI_IMC_CLIPBOARD_RET_MEMORY_ERROR;
        }
    }
    else
    {
        return MMI_IMC_CLIPBOARD_RET_NO_TEXT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_cut
 * DESCRIPTION
 *  Clipboard cut
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_imc_clipboard_ret_enum
 *****************************************************************************/
mmi_imc_clipboard_ret_enum mmi_imc_clipboard_cut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
    mmi_imc_clipboard_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_imc_clipboard_copy();
    if ((ret == MMI_IMC_CLIPBOARD_RET_OK) || (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH))
    {
        if (!mmi_imc_clipboard_is_editor_read_only())
        {
            /* If text selection is backward (imc_msg.param_1 = 0), move the cursor to the ccp_start_cursor_p then delete cutted string */
            imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_CUT_HIGHLIGHT_STRING;
            imc_msg.param_0 = (U32)&g_imc_clipboard_data;
            if (g_imc_clipboard_data.highlight_text_length < 0)
            {
                if (ret == MMI_IMC_CLIPBOARD_RET_OK)
                {
                    imc_msg.param_1 = 1;
                }
                else
                {
                    imc_msg.param_1 = 3;
                }
            }
            else
            {
                if (ret == MMI_IMC_CLIPBOARD_RET_OK)
                {
                    imc_msg.param_1 = 0;
                }
                else
                {
                    imc_msg.param_1 = 2;
                }
            }
            if (mmi_imc_send_message(&imc_msg))
            {
                ret = MMI_IMC_CLIPBOARD_RET_CUT_UNSUPPRT_CONTENT;
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_cut_all
 * DESCRIPTION
 *  Clipboard cut all
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_imc_clipboard_ret_enum
 *****************************************************************************/
mmi_imc_clipboard_ret_enum mmi_imc_clipboard_cut_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
    mmi_imc_clipboard_ret_enum ret;
    MMI_BOOL is_allowed_cut_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_imc_clipboard_copy_all();
    if ((ret == MMI_IMC_CLIPBOARD_RET_OK) || (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH))
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_IS_ALLOWED_CUT_ALL;
        is_allowed_cut_all = (MMI_BOOL)mmi_imc_send_message(&imc_msg);
        if (!mmi_imc_clipboard_is_editor_read_only() || is_allowed_cut_all)
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_CUT_ALL;
            if (ret == MMI_IMC_CLIPBOARD_RET_OK)
            {
                imc_msg.param_0 = 0;
            }
            else
            {
                imc_msg.param_0 = 1;
            }
            if (mmi_imc_send_message(&imc_msg))
            {
                ret = MMI_IMC_CLIPBOARD_RET_CUT_UNSUPPRT_CONTENT;
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_copy
 * DESCRIPTION
 *  Clipboard copy
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_imc_clipboard_ret_enum
 *****************************************************************************/
mmi_imc_clipboard_ret_enum mmi_imc_clipboard_paste(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 * paste_str = NULL;
    mmi_clipboard_unicodetext_data_struct *cb_data;
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_CLIPBOARD_CCP_PASTE_BEGIN);

    /* get the text context from the clipboard */
    cb_data = (mmi_clipboard_unicodetext_data_struct*)mmi_clipboard_get_data_by_type(MMI_CLIPBOARD_FORMAT_UNICODETEXT);
    if (cb_data != NULL && cb_data->len > 0)
    {
        /* If there are text selected(highlighted), delete the highlight text then paste --> Replace */
        if (g_imc_clipboard_data.highlight_text_length != 0)
        {
            /* If text selection is backward (imc_msg.param_1 = 0), move the cursor to the ccp_start_cursor_p then delete cutted string */
            imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_CUT_HIGHLIGHT_STRING;
            imc_msg.param_0 = (U32)&g_imc_clipboard_data;
            if (g_imc_clipboard_data.highlight_text_length < 0)
            {
                imc_msg.param_1 = 1;
            }
            else
            {
                imc_msg.param_1 = 0;
            }
            mmi_imc_send_message(&imc_msg);
        }

        /* paste the text in the clipboard */
        paste_str = cb_data->data; /* get the text from the clipboard */
        imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_INSERT_STRING_WITH_LENGTH;
        imc_msg.param_0 = (U32)paste_str;
        imc_msg.param_1 = (U32)cb_data->len;
        mmi_imc_send_message(&imc_msg);

    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        g_imc_skip_first_cursor_movement_event = MMI_FALSE;
    #endif
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_CLIPBOARD_CCP_PASTE_END);
        return MMI_IMC_CLIPBOARD_RET_OK;
    }
    else
    {
        return MMI_IMC_CLIPBOARD_RET_NO_TEXT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_empty
 * DESCRIPTION
 *  Check if clipboard is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *      MMI_TRUE: Clipboard is empty
 *      MMI_FALSE: Clipboard is not empty
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clipboard_unicodetext_data_struct *cb_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the text context from the clipboard */
    cb_data = (mmi_clipboard_unicodetext_data_struct*)mmi_clipboard_get_data_by_type(MMI_CLIPBOARD_FORMAT_UNICODETEXT);
    if (cb_data != NULL && cb_data->len > 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_empty
 * DESCRIPTION
 *  Check if clipboard is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *      MMI_TRUE: text is highlight
 *      MMI_FALSE: text is not highlight
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_text_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_IS_TEXT_HIGHLIGHT;
    imc_msg.param_0 = (U32)&g_imc_clipboard_data;
    if (mmi_imc_send_message(&imc_msg))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_editor_empty
 * DESCRIPTION
 *  Check if editor is empty or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *      MMI_TRUE: editor is empty
 *      MMI_FALSE: editor is not empty
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_editor_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
    mmi_imc_editor_menu_history_data_struct editor_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_GET_EDITOR_TYPE;
    imc_msg.param_0 = (U32)&editor_type;
    mmi_imc_send_message(&imc_msg);

    if (editor_type.is_empty)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_editor_WCSS
 * DESCRIPTION
 *  Check if editor is WCSS or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *      MMI_TRUE: editor is empty
 *      MMI_FALSE: editor is not empty
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_editor_WCSS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;

    if (mmi_imc_send_message(&imc_msg))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_editor_password
 * DESCRIPTION
 *  Check if editor is used for input password or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *      MMI_TRUE: editor is empty
 *      MMI_FALSE: editor is not empty
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_editor_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR;

    if (mmi_imc_send_message(&imc_msg))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_editor_read_only
 * DESCRIPTION
 *  Check if editor is read only or not
 *  We'll check the saved flags instead of orignial flags because in read only editor
 *  we'll modify the flags for copy/cut/paste
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *      MMI_TRUE: editor is read only
 *      MMI_FALSE: editor is editable
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_editor_read_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_IS_READ_ONLY_EDITOR;
    imc_msg.param_0 = (U32)&g_imc_clipboard_data;

    if (mmi_imc_send_message(&imc_msg))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_disable
 * DESCRIPTION
 *  Check if editor clipboard is disable or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *      MMI_TRUE: clipboard is read only
 *      MMI_FALSE: clipboard is editable
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        /* Venus Clipboard using venus clipboard service instead of IME architecture */
        return MMI_TRUE;
    }
#endif

    /* disable clipboard when SSP */
    if (gui_screen_smooth_scrolling_moved_by_pen())
    {
        return MMI_TRUE;
    }

    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_IS_DISABLE;

    if (mmi_imc_send_message(&imc_msg))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_allow_to_enter_state
 * DESCRIPTION
 *  Check if can enter clipboard state.
 *  Case1: Clipboard and editor content are both empty, also it's a editable editor
 *  Case2: Editor content is empty and it's a read only editor
 *  Case3: Clipboard is empty and editor has content and it's a password editor
 *  Case4: Clipboard is not empty and content is empty and it's a WCSS editor
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *      MMI_TRUE: Can enter
 *      MMI_FALSE: Can't enter
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_allow_to_enter_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
    mmi_imc_editor_menu_history_data_struct editor_type;
    MMI_BOOL is_clipboard_empty;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&editor_type, 0, sizeof(mmi_imc_editor_menu_history_data_struct));

    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_GET_EDITOR_TYPE;
    imc_msg.param_0 = (U32)&editor_type;
    ret = (MMI_BOOL)mmi_imc_send_message(&imc_msg);

    /* Not support editor */
    if (!ret)
    {
        return MMI_FALSE;
    }

    is_clipboard_empty = mmi_imc_clipboard_is_empty();

    if ((editor_type.is_empty && is_clipboard_empty && !editor_type.is_read_only) ||
        (editor_type.is_empty && editor_type.is_read_only) ||
        (is_clipboard_empty && !editor_type.is_empty && editor_type.is_password) ||
        editor_type.is_wcss)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_is_show_edit_option
 * DESCRIPTION
 *  Check if show edit option menu item in the option list. In case of re-entry, we save the 
 *  Edit options index into history, when go back history, we'll use the history data to check
 *  if show or hide edit options menu item
 * PARAMETERS
 *  history_buffer              [IN]        History buffer, Gui buffer of current category screen.
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL mmi_imc_clipboard_is_show_edit_option(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_num;
    editor_list_menu_category_history *h = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer == NULL)
    {
        mmi_imc_clipboard_show_hide_edit_option_menu(NULL);
        list_num = GetNumOfChild_Ext(MENU_ID_EDITOR_OPT_EDIT_OPTIONS);
        if (list_num > 0)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        h = (editor_list_menu_category_history*)(history_buffer + (sizeof(list_menu_category_history) + sizeof(mmi_imc_editor_menu_history_data_struct)));

        if (h->edit_option_index >= 0)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_save_keys
 * DESCRIPTION
 *  Save app's key like LNK/RNK
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_clipboard_save_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imc_clipboard_key_is_saved)
    {
        g_imc_clipboard_key_handler[0] = GetKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        g_imc_clipboard_key_handler[1] = GetKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
        g_imc_clipboard_key_handler[2] = GetKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        g_imc_clipboard_key_handler[3] = GetKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
        g_imc_clipboard_key_handler[4] = GetKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
        g_imc_clipboard_key_handler[5] = GetKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
        g_imc_clipboard_key_handler[6] = GetKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        g_imc_clipboard_key_handler[7] = GetKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);

        g_imc_clipboard_key_is_saved = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_restore_keys
 * DESCRIPTION
 *  Restore App's key handler if saved
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_clipboard_restore_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_clipboard_key_is_saved)
    {
        SetKeyHandler(g_imc_clipboard_key_handler[0], KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(g_imc_clipboard_key_handler[1], KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(g_imc_clipboard_key_handler[2], KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(g_imc_clipboard_key_handler[3], KEY_RIGHT_ARROW, KEY_EVENT_UP);
	    SetKeyHandler(g_imc_clipboard_key_handler[4], KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(g_imc_clipboard_key_handler[5], KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(g_imc_clipboard_key_handler[6], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(g_imc_clipboard_key_handler[7], KEY_DOWN_ARROW, KEY_EVENT_UP);
    }
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_clipboard_pen_pre_hdlr
* DESCRIPTION
*  Pre-pen handler of clipboard.
* PARAMETERS
*  dm_control_id       [IN]    DM control ID
*  point               [IN]    pen point
*  pen_event           [IN]    pen event
* RETURNS
*  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
*****************************************************************************/
static MMI_BOOL mmi_imc_clipboard_pen_pre_hdlr(U16 dm_control_id, mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Add for MMS viewer category. In this category, general pen handler will be called when pen
       down out of text area, so we need to reset clipboard state in pre pen handler */
#ifdef __UI_MMS_VIEWER_CATEGORY__
    if (pen_event == MMI_PEN_EVENT_UP && 
        (dm_control_id != DM_CATEGORY_CONTROLLED_AREA) && (dm_control_id != DM_RSK) &&
        (g_dm_data.s32CatId == MMI_CATEGORY630_ID))
    {
        if (mmi_imc_is_clipboard_state())
        {
            mmi_imc_clipboard_go_back_to_initial();
        }
    }
#endif

    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */

extern mmi_editor_handler_struct g_mmi_editor_hanler;

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_connect
 * DESCRIPTION
 *  Connect IME for clipboard function. In Pluto, copy/cut/paste is bind with IME architecutre, so to support clipboard
 *  function, we need to connect IME.
 *  [Usage]: It should be called in category entry function.
 *  [WARNING]: Currently, we only support EMS/Multiline read only editor
 * PARAMETERS
 *  editor_type                  [IN]        inputbox type.
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_clipboard_connect(mmi_imc_clipboard_inputbox_enum editor_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum default_input_mode = IMM_INPUT_MODE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == g_imc.is_inited)
    {
        return;
    }

    mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_SENTENCE, NULL, default_input_mode);
    switch (editor_type)
    {
    case INPUTBOX_MULTILINE:
        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_INPUT_BOX_READ_ONLY;    
        g_mmi_editor_hanler.input_box_handler = &MMI_multiline_inputbox;
        break;
    case INPUTBOX_MULTILINE_EBOOK:
        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_INPUT_BOX_EBOOK;        
        g_mmi_editor_hanler.input_box_handler = &MMI_multiline_inputbox;
        break;
    case INPUTBOX_MULTILINE_MMS_VIEWER:
        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_INPUT_BOX_MMS_VIEWER;        
        g_mmi_editor_hanler.input_box_handler = &MMI_multiline_inputbox;
        break;
#if defined(UI_EMS_SUPPORT)
    case INPUTBOX_EMS:
        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_EMS_INPUT_BOX;
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_INPUT_BOX_READ_ONLY;    
        g_mmi_editor_hanler.input_box_handler = &MMI_EMS_inputbox;
        break;
#endif
    default:
        /* Current we only support multiline and EMS read only */
        MMI_ASSERT(0);
    }

#ifdef __MMI_TOUCH_SCREEN__
    mmi_imc_disable_handwriting();
#endif /* __MMI_TOUCH_SCREEN__ */

    switch (editor_type)
    {
    case INPUTBOX_MULTILINE_MMS_VIEWER:
    #if defined(__MMI_TOUCH_SCREEN__)
        wgui_pen_register_pre_hdlr(mmi_imc_clipboard_pen_pre_hdlr);
    #endif
    case INPUTBOX_MULTILINE:
    case INPUTBOX_MULTILINE_EBOOK:
        mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_multiline);
        break;
#if defined(UI_EMS_SUPPORT)
    case INPUTBOX_EMS:
        mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_ems);
        break;
#endif
    default:
        /* Current we only support multiline and EMS read only */
        MMI_ASSERT(0);
    }

    mmi_imc_disable_key_input();
    mmi_imc_key_deactivate();
#ifdef __MMI_TOUCH_SCREEN__
    mmi_imc_disable_virtual_keyboard();
#endif /* __MMI_TOUCH_SCREEN__ */

    /* CSK in IME is used for switch input method, if read only, should disable CSK */
    if (mmi_imc_clipboard_is_editor_read_only() || (editor_type == INPUTBOX_MULTILINE_MMS_VIEWER))
    {
        mmi_imc_disable_csk();
    }
}


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
void mmi_imc_clipboard_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_disconnect();

#if defined(__MMI_TOUCH_SCREEN__)
    wgui_pen_register_pre_hdlr(NULL);
#endif
}

#endif /* __MMI_CLIPBOARD__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_save_editor_history_data
 * DESCRIPTION
 *  Save current editor type. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_save_editor_history_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLIPBOARD__
    mmi_imc_message_struct  imc_msg;
#endif /* __MMI_CLIPBOARD__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLIPBOARD__
    imc_msg.message_id = MMI_IMC_MESSAGE_CLIPBOARD_GET_EDITOR_TYPE;
    imc_msg.param_0 = (U32)&g_editor_history_data;
    mmi_imc_send_message(&imc_msg);
    g_editor_history_data.editor_type = (S32)(wgui_inputs_get_editor_handler()->input_box_type);
    g_editor_history_data.editor_sub_type = (S32)(wgui_inputs_get_editor_handler()->input_box_sub_type);
#endif /* __MMI_CLIPBOARD__ */

	#ifdef __MMI_FRM_HISTORY__ 
    g_editor_history_data.editor_screen_id = GetCurrScrnId();
  #endif 
    g_editor_history_data.input_mode = mmi_imm_get_curr_input_mode();
    g_editor_history_data.input_mode_list = mmi_imm_get_curr_user_specific_input_mode_list();
    g_editor_history_data.input_type = mmi_imm_get_curr_input_type();
    g_editor_history_data.input_ext_type = MMI_current_input_ext_type;
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    g_editor_history_data.writing_lang = mmi_imm_get_current_writing_language();
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    g_editor_history_data.is_vk_disable = g_is_vk_disabled;
    g_editor_history_data.is_hw_disable = g_is_handwriting_disabled;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_editor_history_data
 * DESCRIPTION
 *  Get current clipboard editor history data
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
mmi_imc_editor_menu_history_data_struct_p mmi_imc_get_editor_history_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_editor_history_data;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_print_string_inserted_to_editor
 * DESCRIPTION
 *  Out put traces of the ucs2 value of the characters inserted to editor  
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_print_string_inserted_to_editor(UI_string_type str_ptr, S32 str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_imc_is_printing_character_trace_enabled)
    {
        return;
    }

    if (!str_ptr)
    {
        return;
    }
    
    for (i = 0; i < str_len; i++)
    {
        if (str_ptr[i] != 0)
        {
            mmi_imc_print_character_inserted_to_editor(str_ptr[i]);
        }
        else
        {
            break;
        }
    }

    /* For input method keymap auto-test */
    if (str_len && g_imc_is_keymap_auto_test_on)
    {
        if (str_len < MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE)
        {
           // MYQUEUE Message;
            mmi_ime_string_inserted_ind_struct_p local_param_ptr = 
                (mmi_ime_string_inserted_ind_struct_p)OslConstructDataPtr(sizeof(mmi_ime_string_inserted_ind_struct));

            if (!local_param_ptr)
            {
                return;
            }
            
            mmi_wcscpy(&local_param_ptr->string[0], str_ptr);

            local_param_ptr->string[str_len] = 0;
 
            /*Message.oslSrcId = MOD_MMI;
            Message.oslDestId = MOD_MMI;
            Message.oslMsgId = (msg_type)MSG_ID_MMI_IME_STRING_INSERTED_IND;
            Message.oslDataPtr = (oslParaType*)local_param_ptr;
            Message.oslPeerBuffPtr = NULL;
            OslMsgSendExtQueue(&Message);*/
			mmi_frm_send_ilm(MOD_MMI,(msg_type)MSG_ID_MMI_IME_STRING_INSERTED_IND,(oslParaType*)local_param_ptr,NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_print_character_inserted_to_editor
 * DESCRIPTION
 *  Out put traces of the ucs2 value of the character inserted to editor  
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_imc_print_character_inserted_to_editor(UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_imc_is_printing_character_trace_enabled)
    {
        return;
    }

    if (char_code != 0)
    {
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_FW_IME_INSERT_CHARACTER_TO_EDITOR, char_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_printing_character
 * DESCRIPTION
 *  Disable or enable printing character trace
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_config_printing_character(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_is_printing_character_trace_enabled = is_on;
}


#if defined(__MMI_VIRTUAL_KEYBOARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_redraw_vk
 * DESCRIPTION
 * PARAMETERS       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_config_redraw_vk(MMI_BOOL b_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    imui_msg.message_id = MMI_IMUI_MESSAGE_CONFIG_REDRAW_VK;
    imui_msg.param_0 = (U32)b_show;

    mmi_imui_send_message(&imui_msg, NULL);
}
#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_imui_parameters
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_set_imui_parameters(mmi_imui_param_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id = MMI_IMUI_MESSAGE_SET_IMUI_PARAMETERS;
    imui_msg.param_0 = (U32)param;
    mmi_imui_send_message(&imui_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_imui_parameters
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_get_imui_parameters(mmi_imui_param_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id = MMI_IMUI_MESSAGE_GET_IMUI_PARAMETERS;
    imui_msg.param_0 = (U32)param;
    mmi_imui_send_message(&imui_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_floating_imui_height
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
S32 mmi_imc_get_floating_imui_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id = MMI_IMUI_MESSAGE_FLOATING_IMUI_HEIGHT;
    
    return (S32)mmi_imui_send_message(&imui_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_floating_imui_control_set
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void  
 *****************************************************************************/
U32 mmi_imc_get_current_floating_imui_control_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id = MMI_IMUI_MESSAGE_GET_FLOATING_IMUI_SET;
    
    return mmi_imui_send_message(&imui_msg, NULL);
}

#if defined(__MMI_IME_FTE_ENHANCE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_vk_present
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_set_vk_present(mmi_imc_vk_present_enum style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__)    
    g_imc_prefer_vk_present = style;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_vk_present
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
mmi_imc_vk_present_enum mmi_imc_get_vk_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__)    
    return g_imc_prefer_vk_present;
#else
    return MMI_IMC_VK_PRESENT_DEFAULT;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_single_block_handwriting
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_config_single_block_handwriting_state(MMI_BOOL config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_single_block_hw_state = config;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_single_block_handwriting_state
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
MMI_BOOL mmi_imc_get_single_block_handwriting_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_single_block_hw_state;
}

#endif /* defined(__MMI_IME_FTE_ENHANCE__) */


#if defined(__MMI_IME_FLOATING_CAND_BOX__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_floating_candidate_box_enabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_floating_candidate_box_enabled(void)
{

/* vertical has been disabled for small TV editor */
    #if defined(__ATV_SMS_SUPPORT__)
    if( mmi_imc_is_in_atv_editor())
    {
       return MMI_FALSE;
    }
    else
    #endif /* defined(__ATV_SMS_SUPPORT__)*/	
    return mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_check_contain_point
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_check_floting_ui_contain_point(mmi_imc_point_p point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id = MMI_IMUI_MESSAGE_CHECK_FLOATING_UI_CONTAIN_POINT;
    imui_msg.param_0 = (U32)point;
    
    return (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
}
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */

#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_floating_candidate_box_enabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_get_ui_style(U32 style_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

//#if defined(__MMI_IME_FTE_ENHANCE__)
//    if ((mmi_imm_get_keyboard_type() == IMM_KEYPAD) && (style_flag == MMI_IMC_UI_STYLE_VK_ON))
//        return MMI_FALSE;
//#endif

    if ((g_imc_ui_style.force_style_flag & style_flag))
    {
        if ((g_imc_ui_style.force_style & style_flag) == style_flag)
        {
            return MMI_TRUE;
        }
    }
    else
    {
        if ((g_imc_ui_style.style & style_flag) == style_flag)
            return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_floating_state
 * DESCRIPTION
 *  To be used by application
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_config_floating_state(MMI_BOOL is_floating)
{
    #if defined(__ATV_SMS_SUPPORT__)
    g_floating_state_configured_by_app = is_floating;
    g_is_in_atv_editor = MMI_TRUE;
    /* If floating flag is set by the application,
     * then for mATV it should be always set
     */
    if (g_floating_state_configured_by_app)
    {
        g_imc_ui_style.style |= MMI_IMC_UI_STYLE_FLOAT_ON;
    }
    else
    {
        g_imc_ui_style.style &= (~MMI_IMC_UI_STYLE_FLOAT_ON);
    }
    #endif /* defined(__ATV_SMS_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_in_atv_editor
 * DESCRIPTION
 *  IS the current context in ATV editor
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_in_atv_editor(void)
{
    #if defined(__ATV_SMS_SUPPORT__)
    return g_is_in_atv_editor;
    #else
    return MMI_FALSE;
    #endif /* defined(__ATV_SMS_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_floating_candidate_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_config_ui_style(U32 ui_style, MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_param_struct ui_param;
    MMI_BOOL prev_style;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__ATV_SMS_SUPPORT__)
    /* If floating flag is set by the application,
     * then for mATV it cant be reset even forcefully
     */
    if (g_is_in_atv_editor)
    {
        if (ui_style == MMI_IMC_UI_STYLE_FLOAT_ON)
        {
            is_on = g_floating_state_configured_by_app;
        }
    }
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)    

    if (ui_style == MMI_IMC_UI_STYLE_VK_ON && is_on == MMI_TRUE && !mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON)
		#if defined(__MMI_IME_CANDIDATE_GRID__)
    && g_imc_is_change_from_grid == FALSE	 
#endif
	)
    {
		//need to put special check for candidate grid, because grid dimension just like vk but its not vk
        mmi_imc_get_imui_parameters(&g_imc_ui_style.backup_imui_param);
        memcpy(&ui_param, &g_imc_ui_style.backup_imui_param, sizeof(mmi_imui_param_struct));
        ui_param.imui_bottom = UI_device_height - 1;
        mmi_imc_set_imui_parameters(&ui_param);
        
    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_set_default_imui_parameters(&ui_param);
        }
    #endif
    }

    prev_style = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
#endif

#if defined(__MMI_IME_CANDIDATE_GRID__)
	  if (ui_style == MMI_IMC_UI_STYLE_VK_ON && is_on == MMI_TRUE && !mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))	 
	 {
		g_imc_is_change_from_grid = MMI_FALSE;
	 }
#endif
    if (is_on)
    {
        g_imc_ui_style.style |= ui_style;
    }
    else
    {
        g_imc_ui_style.style &= (~ui_style);
    }
    
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    if ((ui_style == MMI_IMC_UI_STYLE_VK_ON && is_on == MMI_FALSE) && 
          (prev_style == MMI_TRUE  && (!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON)))
	#if defined(__MMI_IME_CANDIDATE_GRID__)
		&& g_imc_is_change_from_grid == FALSE
	#endif
		)
    {
        mmi_imc_set_imui_parameters(&g_imc_ui_style.backup_imui_param);

    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_set_default_imui_parameters(&g_imc_ui_style.backup_imui_param);
        }
    #endif /* defined(__MMI_VUI_ENGINE__) */
#if !defined(__NO_HANDWRITING__)

        if (mmi_imc_get_single_block_handwriting_state())
        {
            mmi_imc_pen_stop_singleblock_handwriting();
        }
#endif /* !defined(__NO_HANDWRITING__) */
    }
#if defined(__MMI_COSMOS_KEYPAD_SLIDER__) && defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__) && defined(__MMI_IME_CANDIDATE_GRID__)
	else if(ui_style == MMI_IMC_UI_STYLE_VK_ON && is_on == MMI_FALSE && (prev_style == MMI_TRUE  && (!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON)))
		&& g_imc_is_change_from_grid == TRUE && mmi_imc_get_slider_status() == OPEN )
	{
		 mmi_imc_set_imui_parameters(&g_imc_ui_style.backup_imui_param);

    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_set_default_imui_parameters(&g_imc_ui_style.backup_imui_param);
        }
    #endif
		g_imc_is_change_from_grid = MMI_FALSE;
	}
#endif
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

    UI_UNUSED_PARAMETER(prev_style);
    UI_UNUSED_PARAMETER(ui_param);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_force_fixed_candidate_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_config_force_ui_style(U32 ui_style, MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_param_struct ui_param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_IME_FTE_ENHANCE__)    

//    if ((mmi_imm_get_keyboard_type() == IMM_KEYPAD) && (ui_style == MMI_IMC_UI_STYLE_VK_ON))
//        return;

    if (ui_style == MMI_IMC_UI_STYLE_VK_ON && is_on == MMI_TRUE && !mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) 
	#if defined(__MMI_IME_CANDIDATE_GRID__)
		&& g_imc_is_change_from_grid == FALSE	 
	#endif
		)
    {
        mmi_imc_get_imui_parameters(&g_imc_ui_style.backup_imui_param);
        memcpy(&ui_param, &g_imc_ui_style.backup_imui_param, sizeof(mmi_imui_param_struct));
        ui_param.imui_bottom = UI_device_height - 1;
        mmi_imc_set_imui_parameters(&ui_param);
        
    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_set_default_imui_parameters(&ui_param);
        }
    #endif
    }
    else if (ui_style == MMI_IMC_UI_STYLE_VK_ON && is_on == MMI_FALSE && (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON)
		 #if defined(__MMI_IME_CANDIDATE_GRID__)
		&& g_imc_is_change_from_grid == FALSE
		#endif
)
	)
    {
        mmi_imc_set_imui_parameters(&g_imc_ui_style.backup_imui_param);

    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_set_default_imui_parameters(&g_imc_ui_style.backup_imui_param);
        }
    #endif
    }
#if defined(__MMI_COSMOS_KEYPAD_SLIDER__) && defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__) && defined(__MMI_IME_CANDIDATE_GRID__)
	else if(ui_style == MMI_IMC_UI_STYLE_VK_ON && is_on == MMI_FALSE && !(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
		&& g_imc_is_change_from_grid == TRUE && mmi_imc_get_slider_status() == OPEN )
	{
		 mmi_imc_set_imui_parameters(&g_imc_ui_style.backup_imui_param);

    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_set_default_imui_parameters(&g_imc_ui_style.backup_imui_param);
        }
    #endif
		g_imc_is_change_from_grid = MMI_FALSE;
	}
#endif
#endif
#if defined(__MMI_IME_CANDIDATE_GRID__)
	  if (ui_style == MMI_IMC_UI_STYLE_VK_ON && is_on == MMI_TRUE && !mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))	 
	 {
		g_imc_is_change_from_grid = MMI_FALSE;
	 }
#endif
    g_imc_ui_style.force_style_flag |= ui_style;
    if (is_on)
    {
        g_imc_ui_style.force_style |= ui_style;
    }
    else
    {
        g_imc_ui_style.force_style &= (~ui_style);
    }
    UI_UNUSED_PARAMETER(ui_param);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_ui_style_param
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_get_ui_style_param(mmi_imc_ui_style_param_struct_p ui_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memcpy(ui_style, &g_imc_ui_style, sizeof(mmi_imc_ui_style_param_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_ui_style_param
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_ui_style_param(mmi_imc_ui_style_param_struct_p ui_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memcpy(&g_imc_ui_style, ui_style, sizeof(mmi_imc_ui_style_param_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_force_fixed_candidate_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_clean_force_ui_style(U32 ui_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL prev_style;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    #if defined(__ATV_SMS_SUPPORT__)
    /* If floating flag is set by the application,
     * then for mATV it cant be reset even forcefully
     */
    if (g_floating_state_configured_by_app && g_is_in_atv_editor)
    {
        if (ui_style == MMI_IMC_UI_STYLE_FLOAT_ON)
        {
            return;
        }
    }
     #endif

    if (!g_imc_ui_style.is_clean_force_style_flag_allowed)
    {
        return;
    }

#if defined(__MMI_IME_FTE_ENHANCE__)    
    prev_style = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
#endif

    g_imc_ui_style.force_style_flag &= (~ui_style);

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)   
    if (ui_style == MMI_IMC_UI_STYLE_VK_ON && 
          ((prev_style == MMI_TRUE) && (!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))))
    {
        mmi_imc_set_imui_parameters(&g_imc_ui_style.backup_imui_param);

    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_set_default_imui_parameters(&g_imc_ui_style.backup_imui_param);
        }
    #endif /* defined(__MMI_VUI_ENGINE__) */
#if !defined(__NO_HANDWRITING__)

        if (mmi_imc_get_single_block_handwriting_state())
        {
            mmi_imc_pen_stop_singleblock_handwriting();
        }
#endif /* !defined(__NO_HANDWRITING__) */
    }
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_clean_force_ui_style_valitation
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_config_clean_force_ui_style_valitation(MMI_BOOL allow_clean)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_ui_style.is_clean_force_style_flag_allowed = allow_clean;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_one_more_space_input_mode
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
MMI_BOOL mmi_imc_is_append_one_more_space_input_mode(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails *mode_details_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_imc_is_connected())
    {
        return MMI_FALSE;
    }
    
    if (mmi_imm_is_chinese_input_method(input_mode))
    {
        return MMI_FALSE;
    }
    
    if (g_imc.mode_details_ptr->imm_mode_id == input_mode)
    {
        if ((g_imc.mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC) &&
            mmi_imm_test_input((UI_string_type)L" ", 1))
        {
            return MMI_TRUE;
        } 
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);
    
        if (!mode_details_ptr)
        {
            return MMI_FALSE;
        }
        else
        {
            if ((mode_details_ptr->Lang_Special_Attrib& IME_LANG_ATTR_ALPHABETIC) &&
                mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    }

}



MMI_BOOL g_imc_override_autocap = MMI_FALSE;


void mmi_imc_config_auto_cap_flag(MMI_BOOL val)
{
    g_imc_override_autocap =val ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_editor_cursor_movement_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  mmi_event_struct *
 * RETURNS
 *  S32 
 *****************************************************************************/
mmi_ret mmi_imc_editor_cursor_movement_handler(mmi_event_struct* param)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    gui_virtual_keyboard_language_enum prevLang;
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__)  */
    mmi_ime_word_capital_state_enum old_state, new_state;
#endif
	#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    MMI_BOOL is_indicated_covered = MMI_FALSE;
    #endif
    mmi_imm_input_mode_enum prev_mode = mmi_imm_get_curr_input_mode();
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    if  (!mmi_imc_is_connected())
        return MMI_RET_OK;

    if (g_imc_override_autocap)
    {
        g_imc_override_autocap = MMI_FALSE;
        return MMI_RET_OK;
    }
#ifdef __MMI_IME_PLUG_IN__
    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_EDITOR_CURSOR_MOVED, 0, 0))
    {
        return MMI_RET_OK;
    }
#endif

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)

#if defined(__MMI_VIRTUAL_KEYBOARD__)
    prevLang = mmi_imc_get_current_vk_type();
#endif

    if (g_imc_skip_first_cursor_movement_event && !g_imc_skip_auto_cap_first_filter)
    {
        g_imc_skip_first_cursor_movement_event = MMI_FALSE;
        return MMI_RET_OK;
    }

	g_imc_skip_auto_cap_first_filter = MMI_FALSE;
   g_imc_skip_first_cursor_movement_event = MMI_FALSE; 


    if (!mmi_imm_is_auto_capitalization_valid())
    {
        return MMI_RET_OK;
    }

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (g_imc_pen_is_vk_caps_lock_down)
    {
        g_imc_pen_is_vk_caps_lock_down = MMI_FALSE;
        return MMI_RET_OK;
    }
#endif
    mmi_imc_gdi_lcd_freeze(TRUE);

    mmi_immc_config_softkeys_changeable(MMI_FALSE);

    old_state = g_imc.global_data.capital_state;

    if (g_imc.global_data.capital_state > MMI_IME_WORD_CAPITAL_STATE_NONE && 
        g_imc.global_data.capital_state < MMI_IME_WORD_CAPITAL_STATE_MAX)
    {
    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
    #if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
    #endif    
        {
            is_indicated_covered = mmi_imc_check_floating_ui_cover_ime_indicator();
        }
    #endif
    
        if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
        {
            new_state = mmi_imc_get_candidate_case_before_cursor();
            
            if (old_state != new_state && mmi_imc_key_get_last_translated_imc_key_code() != MMI_IMC_KEY_CHANGE_MODE &&
                (!g_imc.global_data.capital_lock || new_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
            {
            #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                if(mmi_imm_get_special_key_icon() != IMG_IME_QWERTY_FN_LOCK)
            #endif
                {
                    g_imc.global_data.capital_lock = MMI_FALSE;
                    g_imc.global_data.capital_state = new_state;
                    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                    {
                        mmi_imui_message_struct imui_msg;
                        imui_msg.message_id = MMI_IMUI_MESSAGE_INVALIDATE_VK;
                        mmi_imui_send_message(&imui_msg, NULL);
                    }
                    #endif
                    if (mmi_imc_change_input_mode_according_to_capital_state(new_state))
                    {                
    					#if (defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__))
    					wgui_virtual_keyboard_set_vk_changed(MMI_TRUE);//notify vk module if vk has changed
    					#endif
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        if (!is_indicated_covered)
                        {
                            mmi_imc_redraw_ime_indicator();
                        }
                    }
                }
            }
        }
        else if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
        {
            S32 timer_coumt = g_active_timer_count;
            FuncPtr timer_cancel_callback = g_timer_cancel_callback;
            FuncPtr timer_callback = mmi_imc_delete_timer();

            new_state = mmi_imc_get_candidate_case_before_cursor();
            
            if (old_state != new_state &&
                (!g_imc.global_data.capital_lock || new_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
            {
                g_imc.global_data.capital_lock = MMI_FALSE;
                g_imc.global_data.capital_state = new_state;
                
                if (mmi_imc_change_input_mode_according_to_capital_state(new_state))
                {                
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    if (!is_indicated_covered)
                    {
                        mmi_imc_redraw_ime_indicator();
                    }
                }
            }

            if (timer_callback && timer_coumt)
            {
                mmi_imc_start_timer(timer_coumt, timer_callback, timer_cancel_callback);
            }    
        }
        else 
        {                
            if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE)
            {
            #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                if(!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
            #endif
                {
                    new_state = mmi_imc_get_candidate_case_before_cursor();

                    if (old_state != new_state && !g_imc.global_data.capital_lock)
                    {
                        g_imc.global_data.capital_lock = MMI_FALSE;
                        g_imc.global_data.capital_state = new_state;
                        mmi_imc_set_caps_seq_by_cur_state(g_imc.global_data.symb_count);
                        if (!is_indicated_covered)
                        {
                            mmi_imc_redraw_ime_indicator();
                        }
                    }
                }
            }
            else 
            {
                mmi_imc_message_struct imc_msg;
                
                imc_msg.message_id = MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE;
                
                if ((mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP &&
                     mmi_imc_send_message(&imc_msg)) ||
                    mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
                    new_state = mmi_imc_get_candidate_case_before_candidate();
                
                    if (old_state != new_state && !g_imc.global_data.capital_lock)
                    {
                        g_imc.global_data.capital_lock = MMI_FALSE;
                        g_imc.global_data.capital_state = new_state;
                    
                        if (!is_indicated_covered)
                        {
                            mmi_imc_redraw_ime_indicator();
                        }
                    }
                }
                else
                {
                    new_state = mmi_imc_get_candidate_case_before_cursor();

                    if (old_state != new_state &&
                        (!g_imc.global_data.capital_lock || new_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
			        {
			            g_imc.global_data.capital_lock = MMI_FALSE;
			            g_imc.global_data.capital_state = new_state;
                    
                        if (!is_indicated_covered)
                        {
                            mmi_imc_redraw_ime_indicator();
                        }
                    }
                }
            }
	    }
    }

#if defined(__MMI_VIRTUAL_KEYBOARD__) 
    /* don't let vk changed by key process, check vk type here */
    mmi_imc_pen_cursor_move_handler(prevLang);
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__)  */
    
    mmi_immc_config_softkeys_changeable(MMI_TRUE);
    mmi_imc_gdi_lcd_freeze(gdi_freeze);;

    if (prev_mode != mmi_imm_get_curr_input_mode()
    #if defined(__MMI_VIRTUAL_KEYBOARD__)    
        || prevLang != MMI_VIRTUAL_KEYBOARD_LANG
    #endif    
        )
    {

            mmi_imc_repaint_screen();
    }
        

#endif /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */
#if defined(__MMI_IME_SLIM__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	mmi_imc_draw_vk_when_curser_movement();
#endif
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 * mmi_imc_draw_vk_when_curser_movement
 * DESCRIPTION
   This api is to draw vk when curser move in IRE languages
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_draw_vk_when_curser_movement(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const sIMEModeDetails * mode_details;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mode_details = mmi_imm_get_input_mode_array_item(mmi_imm_get_current_input_mode());
	if(mode_details->lang_id == IME_WRITING_LANG_LO \
	  || mode_details->lang_id == IME_WRITING_LANG_PA \
	  || mode_details->lang_id == IME_WRITING_LANG_AS \
	  || mode_details->lang_id == IME_WRITING_LANG_KN \
	  && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
	{
		mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
	}
}

#if 1
/*****************************************************************************
 * FUNCTION
 * mmi_imc_draw_indicator_floating
 * DESCRIPTION
   This api is to draw floating indicator along with cursor in editor
 * PARAMETERS
 * RETURNS
 *  S32 
 *****************************************************************************/

void mmi_imc_draw_indicator_floating(MMI_BOOL Background_redraw)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
	mmi_imc_message_struct imc_message;
	

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imc_message.message_id = MMI_IMC_MESSAGE_IS_THERE_CURSOR;
    imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_INDICATOR_FLOATING;
    imui_msg.param_0 = Background_redraw;
    mmi_imui_send_message(&imui_msg, NULL);

    if(!mmi_imc_send_message(&imc_message))
    {
        return ;
    }
    //we will update floationg ui paramter according to current cursor rect in this api
	 if (mmi_imc_check_ui_cover_ime_indicator())//need to check if any UI(vk, cand box etc) overlap
	{
            return;
	}
	 #if defined(__MMI_IME_FLOATING_CAND_BOX__)
	 if (mmi_imc_check_floating_ui_cover_ime_indicator())
     {
            return;
     }
	#endif

    imui_msg.message_id = MMI_IMUI_MESSAGE_REDRAW;
    imui_msg.param_0 = (MMI_IMUI_CONTROL_MASK(MMI_IMUI_IME_INDICATOR_AREA_FLOATING)) ;
    mmi_imui_send_message(&imui_msg, NULL);

}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_candidate_case_before_cursor
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  S32 
 *****************************************************************************/
mmi_ime_word_capital_state_enum mmi_imc_get_candidate_case_before_cursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_imc_message_struct imc_msg;
    U8 *text_start = NULL, *text_end = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imc_msg.message_id    = MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CURSOR;
    imc_msg.param_0       = (U32)&text_start;
    imc_msg.param_1       = (U32)&text_end;
    mmi_imc_send_message( &imc_msg );

    return mmi_imc_get_candidate_case_by_text_buffer(text_start, text_end);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_candidate_case_before_candidate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  S32 
 *****************************************************************************/
mmi_ime_word_capital_state_enum mmi_imc_get_candidate_case_before_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_imc_message_struct imc_msg;
    U8 *text_start = NULL, *text_end = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imc_msg.message_id    = MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CANDIDATE;
    imc_msg.param_0       = (U32)&text_start;
    imc_msg.param_1       = (U32)&text_end;
    mmi_imc_send_message( &imc_msg );

    return mmi_imc_get_candidate_case_by_text_buffer(text_start, text_end);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_candidate_case_by_text_buffer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
mmi_ime_word_capital_state_enum mmi_imc_get_candidate_case_by_text_buffer(U8 *text_start, U8 *text_end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *str_ptr, *temp_ptr; 
    S32 i, j;
    MMI_BOOL is_thers_space = MMI_FALSE;
	UI_character_type c;
    mmi_ime_word_capital_state_enum capital_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;

    if (text_start == NULL || text_end == NULL)
    {
        return capital_state;
    }

    str_ptr = text_end;

    if (str_ptr == text_start) /* Editor is empty */
    {
        return MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
    }
    else
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(str_ptr, c);
    }

    c=(UI_character_type)((*((str_ptr)+0))|((*((str_ptr)+1))<<8));

    while (c == 0x20 && str_ptr >= text_start)
    {
        is_thers_space = MMI_TRUE;
        UI_STRING_GET_PREVIOUS_CHARACTER(str_ptr, c);
    }

    if (str_ptr < text_start) /* Every character before cursor is sapce */
    {
        return MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
    }

    if (is_thers_space)
    {
        UI_STRING_GET_NEXT_CHARACTER(str_ptr, c);

        c=(UI_character_type)((*((str_ptr)+0))|((*((str_ptr)+1))<<8));

        MMI_ASSERT(c == 0x20);
    }

    i = 0;

    while (g_imc_sentence_ending_markers[i][0])
    {
        temp_ptr = str_ptr;

        j = 0;
        
        c=(UI_character_type)((*((temp_ptr)+0))|((*((temp_ptr)+1))<<8));
        
        while (temp_ptr >= text_start && g_imc_sentence_ending_markers[i][j])
        {
            if (g_imc_sentence_ending_markers[i][j] != c)
            {
                break;
            }
            j++;

            UI_STRING_GET_PREVIOUS_CHARACTER(temp_ptr, c);
        }

        if (g_imc_sentence_ending_markers[i][j] == 0)
        {
            return MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
        }

        i++;
    }

    return capital_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_change_input_mode_according_to_capital_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
MMI_BOOL mmi_imc_change_input_mode_according_to_capital_state(mmi_ime_word_capital_state_enum capital_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const sIMEModeDetails *mode_details_ptr = NULL;
    mmi_imc_message_struct imc_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_details_ptr = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_get_curr_input_mode(), capital_state);
	        
	if (mode_details_ptr)
	{
        if (mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
        {
            mmi_imm_set_current_input_mode(mode_details_ptr->imm_mode_id);
            
            if (mmi_imc_change_input_mode(mode_details_ptr->imm_mode_id, 0))
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_MODE_CHANGED;
                mmi_imc_send_message( &imc_msg );
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}


#if defined(__MMI_IME_FLOATING_CAND_BOX__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_check_floating_ui_cover_ime_indicator
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
static MMI_BOOL mmi_imc_check_floating_ui_cover_ime_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id = MMI_IMUI_DOES_FLOATING_UI_COVER_IME_INDICATOR;

    return (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
}
#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */
#if 1
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_check_ui_cover_ime_indicator
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
static MMI_BOOL mmi_imc_check_ui_cover_ime_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id = MMI_IMUI_DOES_UI_COVER_IME_INDICATOR;

    return (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_config_update_input_mode_by_cursor_pos
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_config_update_input_mode_by_cursor_pos(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    g_imc_is_update_input_mode_by_cursor_pos_enabled = is_enabled;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_input_mode_by_cursor_pos
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_update_input_mode_by_cursor_pos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    mmi_imm_input_mode_enum current_input_mode = mmi_imm_get_curr_input_mode();
    mmi_imc_message_struct imc_msg;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    if (!mmi_imc_is_connected() || mmi_imc_is_ime_state() || !g_imc_is_update_input_mode_by_cursor_pos_enabled)
    {
        return;
    }

    mmi_imm_set_initial_input_mode_by_auto_capitalization();

    if (current_input_mode != mmi_imm_get_curr_input_mode())
    {
        if (mmi_imc_change_input_mode(mmi_imm_get_curr_input_mode(), 0))
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_MODE_CHANGED;
            mmi_imc_send_message( &imc_msg );
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_editor_is_not_ready_when_connecting
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_editor_is_not_ready_when_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_is_editor_ready_when_connecting = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_editor_ready_when_connecting
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
MMI_BOOL mmi_imc_is_editor_ready_when_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_imc_is_editor_ready_when_connecting;
}

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_max_reselection_word_length
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
S32 mmi_imc_get_max_reselection_word_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE;
}
#endif /* #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_floating_ui_controls
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_redraw_floating_ui_controls(void)
{
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    imui_msg.message_id = MMI_IMUI_MESSAGE_REDRAW_FLOATING_CONTROLS;
        
    mmi_imui_send_message(&imui_msg, NULL);
#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_ime_screen_general_ui_control_set
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
static U8 *mmi_imc_get_ime_screen_general_ui_control_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_imc_ime_screen_general_ui_control_set;
}
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_right_softkey_function
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_set_softkey_function(void (*f) (void), mmi_key_types_enum k, mmi_ime_softkey_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(key)
    {
    case MMI_IME_LEFT_SOFTKEY:
        //set_softkey_function(f, (MMI_key_event_type)k, MMI_LEFT_SOFTKEY);
        SetLeftSoftkeyFunction(f, (MMI_key_event_type)k);
        break;
        
    case MMI_IME_RIGHT_SOFTKEY:
        //set_softkey_function(f, (MMI_key_event_type)k, MMI_RIGHT_SOFTKEY);
        SetRightSoftkeyFunction(f, (MMI_key_event_type)k);
        break;
        
    case MMI_IME_CENTER_SOFTKEY:
        //set_softkey_function(f, (MMI_key_event_type)k, MMI_CENTER_SOFTKEY);
        SetCenterSoftkeyFunction(f, (MMI_key_event_type)k);
        break;
        
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_right_softkey_label
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_set_softkey_label(UI_string_type s, mmi_ime_softkey_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key)
    {
    case MMI_IME_LEFT_SOFTKEY:
        set_softkey_label(s, MMI_LEFT_SOFTKEY);
        break;
        
    case MMI_IME_RIGHT_SOFTKEY:
        set_softkey_label(s, MMI_RIGHT_SOFTKEY);
        break;
        
    case MMI_IME_CENTER_SOFTKEY:
        set_softkey_label(s, MMI_CENTER_SOFTKEY);
        break;
        
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_softkey_icon
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_set_softkey_icon(PU8 icon, mmi_ime_softkey_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key)
    {
    case MMI_IME_LEFT_SOFTKEY:
        set_softkey_icon(icon, MMI_LEFT_SOFTKEY);
        break;
        
    case MMI_IME_RIGHT_SOFTKEY:
        set_softkey_icon(icon, MMI_RIGHT_SOFTKEY);
        break;
        
    case MMI_IME_CENTER_SOFTKEY:
        set_softkey_icon(icon, MMI_CENTER_SOFTKEY);
        break;
        
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_redraw_floating_ui_within_rect
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_redraw_floating_ui_within_rect(mmi_imc_rect_p rect)
{
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    MMI_BOOL need_redraw = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_is_ime_connected)
    {
        return;
    }    

    if (rect)
    {
        imui_msg.message_id = MMI_IMUI_CHECK_OVERLAP_WITH_CURRENT_FLOATING_UI;
        imui_msg.param_0 = (U32)rect;

        if (mmi_imui_send_message(&imui_msg, NULL))
        {
            need_redraw = MMI_TRUE;
        }
    }
    else
    {
        need_redraw = MMI_TRUE;
    }

    if (need_redraw)
    {
        imui_msg.message_id = MMI_IMUI_MESSAGE_REDRAW_FLOATING_CONTROLS;

        mmi_imui_send_message(&imui_msg, NULL);
    }

#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_current_floating_ui_rect
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
MMI_BOOL mmi_imc_get_current_floating_ui_rect(mmi_imc_rect_p rect)
{
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_is_ime_connected || !rect)
    {
        return MMI_FALSE;
    }    
    
    /* as opera calls  when venus is running somethimes*/
    #if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        return MMI_FALSE;
    }
    #endif
    
    imui_msg.message_id = MMI_IMUI_GET_FLOATING_UI_RECT;
    imui_msg.param_0 = (U32)rect;
    
    if (mmi_imui_send_message(&imui_msg, NULL))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }    
#else

    return MMI_FALSE;

#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__) */
}



/*****************************************************************************
 * mmi_imc_get_extra_imui_layer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
gdi_handle mmi_imc_get_extra_imui_layer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_is_ime_connected)
    {
        return GDI_NULL_HANDLE;
    }

    imui_msg.message_id = MMI_IMUI_MESSAGE_GET_EXTRA_IMUI_LAYER_HANDLER;
    
    return (gdi_handle)mmi_imui_send_message(&imui_msg, NULL);
}


/*****************************************************************************
 * mmi_imc_set_dialer_callback
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_set_dialer_callback(MMI_BOOL (*funcptr)(mmi_imc_dialer_pen_code_enum pen_code, mmi_pen_event_type_enum pen_event))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
	mmi_imc_pen_set_dialer_callback(funcptr);
	#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
}

/*****************************************************************************
 * mmi_imc_confirm_candidate_by_function_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_confirm_candidate_by_function_key()
{

    mmi_imc_message_struct imc_msg;

    mmi_imc_key_smart_alphabetic_confirm_candidate();
    imc_msg.message_id = MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC;
    mmi_imc_send_message(&imc_msg);
}


/*****************************************************************************
 * mmi_imc_is_spell_word_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
MMI_BOOL mmi_imc_is_spell_word_state(void)
{

#if defined(__MMI_IME_USER_DATABASE__)    

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type temp_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_imc_get_state() != MMI_IMC_STATE_SMART_CANDIDATE || !g_is_ime_connected)
	{
		return MMI_FALSE;
	}

	temp_ptr = mmi_imc_get_candidate_by_index(&g_imc.global_data.cand_buff[0], g_imc.global_data.cand_select);

	if (temp_ptr != NULL)
	{
		if (*temp_ptr == MMI_IME_USER_DATABASE_NEW_WORD)
		{
            return MMI_TRUE;
		}
	}
#endif

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_in_custom_state
 * DESCRIPTION
 *  It checks if the state is in custom state
 * PARAMETERS
 *  state       : [IN] the state to check
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :   state is in custom state
 *  MMI_FALSE   :   state is not in custom state
 *****************************************************************************/
MMI_BOOL mmi_imc_is_in_custom_state(mmi_imc_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state >= MMI_IMC_STATE_CUSTOM_BEGIN && state <= MMI_IMC_STATE_CUSTOM_END)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_inputmode
 * DESCRIPTION
 *  Changes input mode
 * PARAMETERS
 *  U32 inputmode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_set_inputmode(U32 inputmode_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* calculate enum from index*/
    #if defined(__MMI_IME_V3__)
    extern mmi_imm_input_mode_enum g_imc_selection_list_mode_array[MMI_IMC_SELECT_LIST_ITEM_NUM_MAX];
    mmi_imm_input_mode_enum inputmode =  g_imc_selection_list_mode_array[inputmode_index];
    #else
    mmi_imm_input_mode_enum inputmode =   (mmi_imm_input_mode_enum)GetInputModeByIndex(inputmode_index);
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change input mode to reset handlers and vk */
    mmi_imm_set_current_input_mode(inputmode);
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    
	 #if defined __MMI_COSMOS_KEYPAD_BAR__ || (defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__))
	; //do nothing
	#else
    #if !defined(__NO_HANDWRITING__)
    mmi_imc_pen_stop_singleblock_handwriting();
    mmi_imc_pen_change_vk_style_from_list();
    #endif

	#endif
    g_imc_current_input_mode_in_list = inputmode_index;
    #endif

    mmi_imc_change_input_mode(inputmode, 0);

    #if defined(__MMI_IME_V3__)
	mmi_imm_set_curr_writing_lang_by_curr_mode();
    #endif

    /* save setting to NVRAM */
    //mmi_imm_write_prefered_input_method_to_nvram(inputmode);
    /* set state*/
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
}


#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_wlang
 * DESCRIPTION
 *  Change writing language  being used .
 * PARAMETERS
 *  U32 enum wlang_index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_set_wlang(U32 wlang_index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* calculate enum from index*/
    mmi_imm_support_writing_lang_enum  wlang = (mmi_imm_support_writing_lang_enum)0;
    mmi_imm_input_mode_enum input_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* calculate from index which wlang is the user intrested in */
    wlang = mmi_imm_get_wlang_by_index(wlang_index);

    /* write selected value to NVRAM */     
    mmi_imm_update_prefer_writing_language(wlang);

    mmi_imm_set_current_writing_lang(wlang);

#if defined(__MMI_MIXED_LANG_SUPPORT__)
    //if (!g_ime_writing_lang_array[mmi_imm_get_index_in_system_writing_language(g_mmi_imm_curr_allowed_writing_lang[wlang_index])].mixed_lang_support)
   // {
     // mmi_imm_set_sub_lang(IME_WRITING_LANG_NONE);
   // }
#endif

    input_mode = mmi_imm_get_first_allowed_input_mode_of_lang(wlang);
    mmi_imm_set_current_input_mode(input_mode);
    mmi_imc_change_input_mode(input_mode, 0);
    
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_rotated
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_is_rotated(void)
{
    return g_mmi_imc_is_rotated;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_is_rotated
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_is_rotated(MMI_BOOL is_rotated)
{
    g_mmi_imc_is_rotated = is_rotated;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_check_rotation
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_check_rotation(void)
{
#if defined(__MMI_SCREEN_ROTATE__)
    if(mmi_frm_is_screen_width_height_swapped())
    {
        mmi_imc_set_is_rotated(MMI_TRUE);
    }
    else
    {
        mmi_imc_set_is_rotated(MMI_FALSE);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_is_java_special_symbol_enabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_is_java_special_symbol_enabled(MMI_BOOL is_enabled)
{
    g_mmi_imc_is_java_special_symbol_enabled = is_enabled;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_is_java_special_symbol_enabled
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_get_is_java_special_symbol_enabled(void)
{
    return g_mmi_imc_is_java_special_symbol_enabled;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_is_disable_candidate_box
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_set_is_disable_candidate_box(MMI_BOOL is_disabled)
{
    g_mmi_imc_is_disable_candidate_box = is_disabled;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_is_dialer_special_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_get_is_disable_candidate_box(void)
{
    return g_mmi_imc_is_disable_candidate_box;
}


#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
/*****************************************************************************
* FUNCTION
*  mmi_imc_get_slider_status
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
mmi_imc_slider_status mmi_imc_get_slider_status()
{
    return g_imc_slider_status;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_enable_vk_on_slider_close
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
static void mmi_imc_enable_vk_on_slider_close(void)
{
        #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
		mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_VK_ON);
        #endif
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
        #endif
		#if defined(__MMI_IME_FLOATING_CAND_BOX__)
		    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
        #endif
        #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
		     mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
        #endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_set_slider_status
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
void mmi_imc_set_slider_status(mmi_imc_slider_status status)
{
	g_imc_slider_status=status;
    if(g_imc_slider_status == OPEN)
    {
		/*we need to hide vk on slider open*/
		mmi_imc_hide_vk_on_slider_open();	
	}
#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
	if(g_imc_slider_status == CLOSE)
    {
		/*we need to show vk on slider close*/
		mmi_imc_enable_vk_on_slider_close();	
	}
#endif
}
/*****************************************************************************
* FUNCTION
*  mmi_imc_hide_vk_on_slider_open
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
static void mmi_imc_hide_vk_on_slider_open()
{
        #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
		mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_VK_ON);
        #endif
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
        #endif
		#if defined(__MMI_IME_FLOATING_CAND_BOX__)
		    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
        #endif
        #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
		     mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        #endif
}

#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
void  mmi_imc_process_simulated_slider_event(mmi_imc_slider_status status)
{
    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY 
        && mmi_imc_is_handwriting_disabled()
        && status == CLOSE)
    {
        return;
    }
    else
    {
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY && status == CLOSE)
        {
            if (!mmi_imm_current_handwriting_is_enable())
            {
                return ;
            }
        }
#else
#if defined(__MMI_NORMAL_KEYPAD__)
        if ((!((mmi_imm_is_curr_allowed_wlang(IME_WRITING_LANG_ABC)
            && mmi_imm_get_writing_language_num() == 2
            && mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_USER_SPECIFIC)
            || IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD == mmi_imm_get_curr_input_type()))
            && mmi_imm_get_current_input_mode() == IMM_INPUT_MODE_123_SYMBOLS
            && status == CLOSE)
        {
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
            mmi_imc_pen_handle_slider_close_on_123_input_mode();
#endif
        }
#endif
#endif
    }

    switch (status)
    {
    case OPEN:
        mmi_imc_set_slider_status(OPEN);
#ifdef __MMI_CLIPBOARD__ 
        if (mmi_imc_is_clipboard_state() && mmi_imc_get_state() != MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS)
        {
            mmi_imc_clipboard_go_back_to_initial();
        }
#endif /* __MMI_CLIPBOARD__ */
	#if defined(__MMI_IME_SLIM__)
		if(g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER || g_imc.global_data.capital_state == MMI_IME_WORD_CAPITAL_STATE_UPPER)
		{
			mmi_imc_change_input_mode_according_to_capital_state(MMI_IME_WORD_CAPITAL_STATE_LOWER);
		}
	#endif
        break;
    case CLOSE:
        mmi_imc_set_slider_status(CLOSE);
	#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_IME_SLIM__)
		if(mmi_imm_get_current_input_case() == MMI_IME_HINT_FLAG_FIRST_UPPER_CASE || mmi_imm_get_current_input_case() == MMI_IME_WORD_CAPITAL_STATE_UPPER)
		{
			mmi_imc_change_input_mode_according_to_capital_state(MMI_IME_WORD_CAPITAL_STATE_LOWER);
		}
		mmi_frm_qwerty_reset_key_status();
	#endif
        break;
    default:
        break;
    }


    if (mmi_imc_is_connected())
    {
        BOOL lcd_freeze = gdi_lcd_get_freeze();
        lcd_freeze = gdi_lcd_get_freeze();
        mmi_imc_gdi_lcd_freeze(MMI_TRUE);
    #ifdef __MMI_VUI_ENGINE__ 
        vadp_p2v_close_ime_popup();
    #endif

//#if defined(__COSMOS_MMI__)
        if (!g_is_key_disabled)
        {
            mmi_imc_key_register_ime_keys();
        }
//#endif

        mmi_imc_key_activate();
#if (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_VK_TYPE_QWERTY__)) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && (__MMI_CSTAR__)
        mmi_ime_reset_group_letters(mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode()));
#endif
        mmi_imc_pen_process_state_before_sliding();
        mmi_imc_redraw_screen_by_state();

        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        gdi_lcd_repaint_all();
    }	  
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_imc_process_slider_event
* DESCRIPTION
this will be called whenever slider key is pressed, this function is registered in inputmethod.res
* PARAMETERS
* RETURNS
****************************************************************************/
mmi_ret mmi_imc_process_slider_event(mmi_event_struct *event)
{
	
#if !defined(__MTK_TARGET__)
        
		switch (event->evt_id)
		{
			case EVT_ID_GPIO_CLAM_OPEN:
                  mmi_imc_set_slider_status(OPEN);
		          break;
			case EVT_ID_GPIO_CLAM_CLOSE:
				  mmi_imc_set_slider_status(CLOSE);
				  break;
			default:
				  break;
		}

        
        if (mmi_imc_is_connected())
        {
        BOOL lcd_freeze = gdi_lcd_get_freeze();
	    lcd_freeze = gdi_lcd_get_freeze();
	    mmi_imc_gdi_lcd_freeze(MMI_TRUE);
	    #ifdef __MMI_VUI_ENGINE__  
        vadp_p2v_close_ime_popup();
      #endif
        if (!g_is_key_disabled)
        {
           mmi_imc_key_register_ime_keys();
        }
	    mmi_imc_key_activate();
		mmi_imc_pen_process_state_before_sliding();
	    mmi_imc_redraw_screen_by_state();

		mmi_imc_gdi_lcd_freeze(lcd_freeze);
        gdi_lcd_repaint_all();
		}
#endif
		return MMI_RET_OK;
	  
}

#endif
/********************************************************************************************************************/
/* this code belongs to ime screens (like new word and set t9 on/off screen */
/* This has been taken out of Imc_pen.c where it was being used to show popups*/
/* but as for key input for cosmos has come , this should be in common area */
/********************************************************************************************************************/
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
extern ime_writing_lang_struct g_ime_writing_lang_array[MAX_WRITING_LANG];
#endif

mmi_imc_pen_input_style_enum g_imc_pen_selection_list_style_array[MMI_IMC_PEN_INPUT_STYLE_MAX];

#if defined(__MMI_IME_V3__)

static void mmi_imc_popup_change_mode_callback(S32 selected_item);

#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_imc_popup_change_mode_tap_confirm_callback(mmi_tap_type_enum tap_type,S32 selected_item);
#endif

static void mmi_imc_popup_change_mode_csk_confirm_callback(void);

MMI_BOOL mmi_imc_is_setting_button_can_be_shown(void)
{
    MMI_BOOL setting_button_show_flag = MMI_TRUE;
#if !defined(__MMI_TOUCH_SCREEN__)
    setting_button_show_flag = MMI_FALSE;
#endif
    return setting_button_show_flag;
}

MMI_BOOL mmi_imc_is_change_mode_button_can_be_shown(void)
{

    MMI_BOOL change_mode_button_show_flag;
#if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
    if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_HANDWRITING)
        {
        change_mode_button_show_flag = MMI_FALSE;
        }
    else
        {
        change_mode_button_show_flag = MMI_TRUE;
        }
#else
    change_mode_button_show_flag = MMI_FALSE;
#endif    
    return change_mode_button_show_flag;
}

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
void mmi_imc_enter_setting_form_vk()
{
    EntryInputMethodSetting();
}

static void mmi_imc_input_mode_selection_rsk_handler_for_vk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_imc_pen_set_user_desired_input_style(MMI_IMC_PEN_INPUT_STYLE_NONE);
    if (mmi_frm_group_get_active_id() == GRP_ID_INVALID)
    {
        GoBackHistory();
    }
    else
    {
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
    }
}

static void mmi_imc_input_mode_selection_lsk_handler_for_vk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    mmi_imm_input_mode_enum desired_mode = g_imc_selection_list_mode_array[index];
	#if defined(__MMI_COSMOS_KEYPAD_BAR__) || defined(__MMI_IME_VK_TYPE_HANDWRITING__)
	mmi_imm_input_mode_enum mode_array[MMI_IMM_MAX_INPUT_METHOD_NUM];
   mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
   S32 numofitem=0;
   #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (desired_mode != IMM_INPUT_MODE_NONE)
        mmi_imm_set_user_desired_input_mode(desired_mode);
    mmi_imc_pen_set_user_desired_input_style(MMI_IMC_PEN_INPUT_STYLE_MAX);
    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

#if defined(__MMI_VUI_ENGINE__)
    if (!vadp_p2v_uc_is_in_venus())
#endif
    {
    if (mmi_frm_group_get_active_id() == GRP_ID_INVALID)
    {
        GoBackHistory();
    }
    else
    {
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
    }
    }

    g_imc_current_input_mode_in_list = index;
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
#if !defined(__NO_HANDWRITING__)
    if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
    {
        mmi_imc_pen_vk_enable_single_block_hw();
    }

    numofitem = mmi_imm_get_curr_allow_input_mode_list_of_imev3(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);
    if(numofitem==index)
    {
        mmi_imc_pen_show_handwriting_vk();
    }
    else
#endif
#endif
        {
            mmi_imc_pen_stop_singleblock_handwriting();
            if (mmi_imm_get_curr_input_mode() != desired_mode &&
                mmi_imm_is_curr_allow_input_mode(desired_mode))
            {

                mmi_imm_set_current_input_mode(desired_mode);

                if (mmi_imc_change_input_mode(desired_mode, 0))
{
                    mmi_imc_redraw_screen_by_state();
                }
            }    
        }
    #if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
	#if !defined(__NO_HANDWRITING__)
	hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc.mode_details_ptr->Handwriting_Attrib);
    if(!mmi_ime_hand_writing_hw_type_query(hw_type))
	{
		if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
		{
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        }
    }
    mmi_imc_redraw_screen_by_state();
    #endif
    #endif
    mmi_imc_gdi_lcd_freeze(gdi_freeze);
    mmi_imc_repaint_screen();

#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vrt_canvas_resume();
    }
    #endif
}

static void mmi_imc_input_style_change_handle(void)
{
#if defined(__MMI_VUI_ENGINE__)
    if (!vadp_p2v_uc_is_in_venus())
#endif
    {
        if (mmi_frm_group_get_active_id() == GRP_ID_INVALID)
        {
            GoBackHistory();
        }
        else
        {
            mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
        }

    }
    mmi_imc_pen_change_vk_style();
}
#else
void mmi_imc_enter_setting_form_vk()
{
    EntryInputMethodSetting();
}

static void mmi_imc_input_mode_selection_rsk_handler_for_vk(void)
{
}

static void mmi_imc_input_mode_selection_lsk_handler_for_vk(void)
{
}

static void mmi_imc_input_style_change_handle(void)
{
    if (mmi_frm_group_get_active_id() == GRP_ID_INVALID)
    {
        GoBackHistory();
    }
    else
    {
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
    }
}
#endif /*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__*/

void mmi_imc_initial_selection_mode_list(void)
{
    memset(g_imc_selection_list_mode_array,0,sizeof(g_imc_selection_list_mode_array));
    mmi_imm_get_curr_allow_input_mode_list_of_imev3(g_imc_selection_list_mode_array,MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);
}

mmi_imm_input_mode_enum mmi_imc_get_next_input_mode_from_list(void)
{
    MMI_BOOL is_hw_in_the_list = MMI_FALSE;
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
	if(mmi_imm_current_handwriting_is_enable())
	{
		#if defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
		is_hw_in_the_list = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
		if((g_imc_selection_list_mode_array[g_imc_current_input_mode_in_list] != IMM_INPUT_MODE_NONE) && is_hw_in_the_list)
		{
			g_imc_current_input_mode_in_list++; //change mode from vk ime key
		}
		else
		#endif        
		if ((g_imc_selection_list_mode_array[g_imc_current_input_mode_in_list + 1] != IMM_INPUT_MODE_NONE) && (is_hw_in_the_list == MMI_FALSE))
		{
			g_imc_current_input_mode_in_list++;  //change mode from hardware key
		}
		else
		{
			 g_imc_current_input_mode_in_list = 0;
		}
	}
	else
	{
		if(g_imc_selection_list_mode_array[g_imc_current_input_mode_in_list + 1] != IMM_INPUT_MODE_NONE)
		{
			g_imc_current_input_mode_in_list++;
		}
		else
		{
			g_imc_current_input_mode_in_list = 0;
		}
	}
#else
    if(g_imc_selection_list_mode_array[g_imc_current_input_mode_in_list + 1] != IMM_INPUT_MODE_NONE)
	{
        g_imc_current_input_mode_in_list++;
    }
    else
    {
        g_imc_current_input_mode_in_list = 0;
    }
#endif
        
    return g_imc_selection_list_mode_array[g_imc_current_input_mode_in_list];
}


void mmi_imc_show_popup_list(
                   S32 x, 
                   S32 y, 
                   S32 number_of_items,
                   //UI_string_type* list_of_items,
                   U16* list_of_items,
                   S32 highlighted_item,
                   mmi_int_funcptr_type confirm_callback, 
                   FuncPtr cancel_callback)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = mmi_ime_gen_editor_common_scr_id(SCR_CONFIG_SMART_INPUT_METHOD);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MMI_current_menu_type = LIST_MENU;
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_show_popup_list(x, y, number_of_items, g_imc_selection_list_str_array, highlighted_item, confirm_callback, cancel_callback);
    }
    else
#endif
 #if defined(__ATV_SMS_SUPPORT__)
    if (mmi_imc_is_in_atv_editor())
    {
		U8 i;
        WCHAR *list_items[60];
        U8 *list_icons[60];
        mmi_id g_id;

       /* To make this screen a part of screen group*/
        g_id = mmi_frm_group_get_active_id();
       
        if (g_id == GRP_ID_INVALID)
        {
    	    EntryNewScreen(
    	    	SCR_ID_INPUT_METHOD_VK_POPUP_LIST, 
    	    	mmi_imc_pen_close_popup_list, 
    	    	NULL, 
    	    	NULL);
        }
        else
        {
            mmi_frm_scrn_enter(
            	g_id,
            	SCR_ID_INPUT_METHOD_VK_POPUP_LIST,
            	mmi_imc_pen_close_popup_list,
            	mmi_imc_pen_show_popup_list_int,
            	MMI_FRM_FG_ONLY_SCRN);
        }
    
        for(i =0; i<number_of_items; i++)
        {
            list_items[i] = (WCHAR *)get_string(list_of_items[i]);

            if (i == highlighted_item)
            {
                //list_icons[i] = get_image(IMG_ID_VKBD_ACTIVATE_ITEM);
                list_icons[i] = get_image(0);
            }
            else
            {
                list_icons[i] = NULL;
            }
        }
        // category 1010 to show the list
       wgui_cat1010_show( 
                (WCHAR *)get_string(STR_GLOBAL_INPUT_METHOD),
                NULL,
                (WCHAR *)get_string(STR_GLOBAL_OK),
		        0,
		        (WCHAR *)get_string(STR_GLOBAL_BACK),
		        0,
                number_of_items,
                (WCHAR**)list_of_items,
                list_icons,
                NULL,
                0,
                highlighted_item,
                NULL);

                
		SetLeftSoftkeyFunction(confirm_callback, KEY_EVENT_UP);
	    SetRightSoftkeyFunction(cancel_callback, KEY_EVENT_UP);
	    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	    SetCenterSoftkeyFunction(confirm_callback, KEY_EVENT_UP);
	    register_center_softkey_to_enter_key();
	    redraw_center_softkey();  
    }
    else
#endif /* defined(__ATV_SMS_SUPPORT__) */
    {
        U8* guiBuffer;
        UI_string_type string_setting = NULL;
        UI_string_type string_change_mode = NULL;
        PU8 img_setting = NULL;
        PU8 img_change_mode = NULL;
        U32 i = 0;
        U8* nStrItemList_p[MMI_IMM_MAX_INPUT_METHOD_NUM];
        mmi_id g_id;

        for(i =0; i<number_of_items; i++)
        {
            nStrItemList_p[i] = (U8*) get_string(list_of_items[i]);
        }

        if(mmi_imc_is_setting_button_can_be_shown())
            {
                img_setting = (PU8)GetImage(IMG_ID_IME_VK_CHANGE_SETTING);
            }
        if(mmi_imc_is_change_mode_button_can_be_shown())
            {
                img_change_mode = (PU8)GetImage(IMG_ID_IME_VK_CHANGE_MODE);
            }

       /* To make this screen a part of screen group*/
        g_id = mmi_frm_group_get_active_id();
#if defined(__MMI_TOUCH_SCREEN__)  
        if (g_id == GRP_ID_INVALID)
        {
        #if defined(__MMI_FRM_HISTORY__)
    	    EntryNewScreen(
    	    	SCR_ID_INPUT_METHOD_VK_POPUP_LIST, 
    	    	NULL, 
    	    	NULL, 
    	    	NULL);
        #else
        mmi_frm_scrn_enter(
            GRP_ID_ROOT,
            SCR_ID_INPUT_METHOD_VK_POPUP_LIST,
            NULL,
            wgui_cat1004_show,
            MMI_FRM_FG_ONLY_SCRN);

        #endif
        return ;
        }
        else
        {
            mmi_frm_scrn_enter(
            	g_id,
            	SCR_ID_INPUT_METHOD_VK_POPUP_LIST,
            	NULL,
            	wgui_cat1004_show,
            	MMI_FRM_FG_ONLY_SCRN);
        }
#else			
	if (g_id == GRP_ID_INVALID)
	{
        #if defined(__MMI_FRM_HISTORY__)
	    EntryNewScreen(
		SCR_ID_INPUT_METHOD_VK_POPUP_LIST, 
		NULL, 
		NULL, 
		NULL);
        #else
	    mmi_frm_scrn_enter(
		GRP_ID_ROOT,
		SCR_ID_INPUT_METHOD_VK_POPUP_LIST,
		NULL,
		ShowCategory36Screen,
		MMI_FRM_FG_ONLY_SCRN);
         #endif
	    return ;
	}
	mmi_frm_scrn_enter(
          	g_id,
            	SCR_ID_INPUT_METHOD_VK_POPUP_LIST,
            	NULL,
            	ShowCategory36Screen,
            	MMI_FRM_FG_ONLY_SCRN);
#endif
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
#ifdef __MMI_SCREEN_ROTATE__
        mmi_frm_screen_rotate(mmi_frm_get_previous_screen_rotate());
#endif
                    
#if defined(__MMI_TOUCH_SCREEN__)
        wgui_cat1004_show((WCHAR*)GetString(STR_GLOBAL_INPUT_METHOD),
                            NULL,
                            (WCHAR*)string_setting,
                            (PU8)img_setting,
                            (WCHAR*)string_change_mode,
                            (PU8)img_change_mode,
                            number_of_items,
                            (U8**)nStrItemList_p,
                            NULL,
                            0,
                            highlighted_item,
                            guiBuffer);

        wgui_register_tap_callback(mmi_imc_popup_change_mode_tap_confirm_callback);
        clear_left_softkey_handler();
        clear_right_softkey_handler();
        set_left_softkey_function(mmi_imc_enter_setting_form_vk, KEY_EVENT_UP);
        set_right_softkey_function(mmi_imc_input_style_change_handle, KEY_EVENT_UP);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_imc_popup_change_mode_csk_confirm_callback, KEY_EVENT_UP);

//    	SetLeftSoftkeyFunction(mmi_imc_enter_setting_form_vk, KEY_EVENT_UP);
//        SetRightSoftkeyFunction(mmi_imc_input_style_change_handle, KEY_EVENT_UP);
#else
	ShowCategory36Screen(
		STR_GLOBAL_INPUT_METHOD,
		0,
		STR_GLOBAL_OK,
		IMG_GLOBAL_OK,
		STR_GLOBAL_BACK,
		IMG_GLOBAL_BACK,
		number_of_items,
		(U8**)nStrItemList_p,
		0,
		guiBuffer);
        SetLeftSoftkeyFunction(mmi_imc_popup_change_mode_csk_confirm_callback, KEY_EVENT_UP);
        SetRightSoftkeyFunction(cancel_callback, KEY_EVENT_UP);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_imc_popup_change_mode_csk_confirm_callback, KEY_EVENT_UP);
        register_center_softkey_to_enter_key();
        redraw_center_softkey(); 
#endif

    }
}

static void mmi_imc_popup_change_mode_callback(S32 selected_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
   S32 numofitem=0;
   mmi_imm_input_mode_enum mode_array[MMI_IMM_MAX_INPUT_METHOD_NUM];
   #endif
  #if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && !defined(__MMI_IME_VK_TYPE_QWERTY__)
	#if !defined(__NO_HANDWRITING__)
	   mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
	#endif
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   #if defined(__MMI_VUI_ENGINE__)
    if (!vadp_p2v_uc_is_in_venus())
#endif
    {
        selected_item = GetHighlightedItem();
        mmi_imm_set_user_desired_input_mode(g_imc_selection_list_mode_array[selected_item]);
        if (mmi_frm_group_get_active_id() == GRP_ID_INVALID)
        {
            GoBackHistory();
        }
        else
        {
            mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
        }
    }
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
   #if !defined(__NO_HANDWRITING__)

    numofitem = mmi_imm_get_curr_allow_input_mode_list_of_imev3(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);

    if(numofitem==selected_item)
    {   
        mmi_imm_set_current_input_mode(mmi_imm_handwriting_get_current_mode());
	    mmi_imc_change_input_mode(mmi_imm_get_current_input_mode(), 0);
        mmi_imc_pen_show_handwriting_vk();
        g_imc_current_input_mode_in_list = selected_item;
    }
    else 
#endif 
#endif 
    {
        mmi_imc_set_inputmode((U32)selected_item);
        
    }
 #if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && !defined(__MMI_IME_VK_TYPE_QWERTY__)
	#if !defined(__NO_HANDWRITING__)
	hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc.mode_details_ptr->Handwriting_Attrib);
    if(!mmi_ime_hand_writing_hw_type_query(hw_type))
	{
		if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
		{
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        }
    }
    #endif
 #endif
	mmi_imc_redraw_screen_by_state();
}

#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_imc_popup_change_mode_tap_confirm_callback(mmi_tap_type_enum tap_type,S32 selected_item)
{
    mmi_imc_popup_change_mode_callback(selected_item);
}
#endif

static void mmi_imc_popup_change_mode_csk_confirm_callback(void)
{
    S32 selected_item;
    selected_item = GetHighlightedItem();

    mmi_imc_popup_change_mode_callback(selected_item);
}

typedef void (* confirm_func_ptr)(S32 selected_item);
void mmi_imc_popup_common_screen_change_mode_callback(S32 selected_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
   S32 numofitem=0;
   mmi_imm_input_mode_enum mode_array[MMI_IMM_MAX_INPUT_METHOD_NUM];
   #endif
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && !defined(__MMI_IME_VK_TYPE_QWERTY__)
#if !defined(__NO_HANDWRITING__)
	  mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
#endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
   #if !defined(__NO_HANDWRITING__)

    numofitem = mmi_imm_get_curr_allow_input_mode_list_of_imev3(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);

    if(numofitem==selected_item)
    {   
	   
        mmi_imc_pen_show_handwriting_vk();
        g_imc_current_input_mode_in_list = selected_item;
        mmi_imm_set_user_desired_input_mode(mmi_imm_handwriting_get_current_mode());
    }
    else 
#endif 
#endif 
    {
        mmi_imm_set_user_desired_input_mode(g_imc_selection_list_mode_array[selected_item]);
        mmi_imc_set_inputmode((U32)selected_item);
        
    }
 #if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && !defined(__MMI_IME_VK_TYPE_QWERTY__)
	#if !defined(__NO_HANDWRITING__)
	hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc.mode_details_ptr->Handwriting_Attrib);
    if(!mmi_ime_hand_writing_hw_type_query(hw_type))
	{
		if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
		{
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        }
    }
    #endif
 #endif
	mmi_imc_redraw_screen_by_state();
}

void mmi_imc_get_input_mode_setting_data(S32* item_count, U16* select_item, U8** item_list,confirm_func_ptr* confirm_call_back)
{
    S32 count,highlight,i;
    mmi_imm_input_mode_enum mode;
    count = mmi_imm_get_curr_allow_input_mode_string_list_of_imev3(g_imc_selection_list_str_array,MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);
    mmi_imm_get_curr_allow_input_mode_list_of_imev3(g_imc_selection_list_mode_array,MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);
    mode = mmi_imm_get_curr_input_mode();
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
    if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_HANDWRITING)
    {
       highlight = count - 1;
    }
    else
#endif
    {
        highlight = mmi_imc_get_high_light_item_in_list(mode, g_imc_selection_list_mode_array, count);
    }

    *item_count = count;
    *select_item = highlight;
    for(i = 0; i < count; i++)
    {
        *item_list = GetString(g_imc_selection_list_str_array[i]);
    }
    *confirm_call_back = mmi_imc_popup_common_screen_change_mode_callback;

}


S32 mmi_imc_get_high_light_item_in_list(mmi_imm_input_mode_enum input_mode,mmi_imm_input_mode_enum* mode_array, S32 mode_num)
{
    S32 i = 0;
    const sIMEModeDetails * mode_detail, *smart_mode_detail = NULL, *tmp_mode;

	if(input_mode == IMM_INPUT_MODE_123_SYMBOLS)
	{
		input_mode = mode_before_123_symbol;
	}

    mode_detail = mmi_imm_get_input_mode_array_item(input_mode);

    MMI_ASSERT(mode_detail != NULL);
    if(mode_detail->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
    {
        smart_mode_detail = mmi_imm_get_corresponding_smart_mode(input_mode, mode_detail->Mode_Special_Attrib & IME_MODE_CASE_MASK);
    }
    if(smart_mode_detail != NULL && mmi_imm_is_curr_allow_input_mode(smart_mode_detail->imm_mode_id))
    {
        mode_detail = smart_mode_detail;
    }

    if(mmi_imm_is_chinese_input_method(input_mode))
    {
        if (input_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO
            || input_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN)
        {
            input_mode = mode_detail->imm_mode_id;
        }
        i = 0;
        while (i < mode_num)
        {
            /* we need to check whether we need to show handwriting as highlighted */ 
            if (input_mode == mode_array[i])
            {
                return i;
            }
            i ++;
        }
    }
    else
    {
        i = 0;

        while(i < mode_num)
        {
            tmp_mode = mmi_imm_get_input_mode_array_item(mode_array[i]);
            if(mode_detail->lang_id == tmp_mode->lang_id)
            {
                return i;
            }
            i++;
        }
    }
    if( i >= mode_num )
    {
        i = 0;
    }

    return i;
}

void mmi_imc_show_inputmode_list(void)
{

    S32 highlight = 0; 

    mmi_imc_message_struct imc_msg;
    S32 count =0;
    mmi_imm_input_mode_enum mode;


    imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;
    if (mmi_imc_send_message(&imc_msg))
    {
        if (mmi_imm_get_current_allowed_writing_language_num() >= 1)
        {
            if (mmi_imc_change_input_mode(mmi_imm_get_next_writing_mode(), 0))
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_MODE_CHANGED;
                mmi_imc_send_message(&imc_msg);
            }

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
    }
    else if(mmi_imm_get_current_allowed_writing_language_num() >= 1)
    {

        count = mmi_imm_get_curr_allow_input_mode_string_list_of_imev3(g_imc_selection_list_str_array,MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);
        if (count < 1)
        {
            return ;
        }

#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
if(mmi_imm_current_handwriting_is_enable())
{
    g_imc_selection_list_str_array[count]=STR_IME_PEN_INPUT_STYLE_HW;
    g_imc_selection_list_mode_array[count]=IMM_INPUT_MODE_MAX_NUM;
    count++;
}
#endif
        mmi_imm_get_curr_allow_input_mode_list_of_imev3(g_imc_selection_list_mode_array,MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);

        mmi_imc_reset_ime_state();
        mode = mmi_imm_get_curr_input_mode();
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
		if(mmi_imm_current_handwriting_is_enable())
		{
#if defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
			if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_HANDWRITING)
			{
				highlight = count - 1;
			}
			else
#else
			if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
			{
				highlight = count - 1;
			}
			else
#endif
			{
				highlight = mmi_imc_get_high_light_item_in_list(mode, g_imc_selection_list_mode_array, count);
			}
		}
		else
#endif
        {
            highlight = mmi_imc_get_high_light_item_in_list(mode, g_imc_selection_list_mode_array, count);
        }


#if defined(__MMI_VUI_ENGINE__)
        /* show  venus popup */
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_show_ime_popup(
                STR_GLOBAL_INPUT_METHOD,
                g_imc_selection_list_str_array,
                count,
                highlight,// because of this popup list is start from 0, it should be same on both side, revise it later.
                mmi_imc_popup_change_mode_callback,
                mmi_imc_input_style_change_handle, mmi_imc_is_change_mode_button_can_be_shown());
        }

        else
#endif
        {
            mmi_imc_show_popup_list(
                0,
                /* to make sure when list is large its not cut The size of botton gap reduced form 1 key to half key */
                UI_device_height, 
                count, 
                g_imc_selection_list_str_array, 
                highlight, 
                mmi_imc_popup_change_mode_callback, 
                mmi_imc_input_style_change_handle);
        }
    } 
}
#endif    //__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__

#if defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_show_popup_list
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
 void mmi_imc_show_popup_list(
                    S32 x, 
                    S32 y, 
                    S32 number_of_items,
                    U16 *list_of_items,
                    S32 highlighted_item,
                    mmi_int_funcptr_type confirm_callback, 
                    FuncPtr cancel_callback,
					UI_string_ID_type title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = mmi_ime_gen_editor_common_scr_id(SCR_CONFIG_SMART_INPUT_METHOD);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MMI_current_menu_type = LIST_MENU;
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_show_popup_list(x, y, number_of_items, list_of_items, highlighted_item, confirm_callback, cancel_callback);
    }
    else
#endif
 #if defined(__ATV_SMS_SUPPORT__)
    if (mmi_imc_is_in_atv_editor())
    {
		U8 i;
        WCHAR *list_items[60];
        U8 *list_icons[60];
        mmi_id g_id;

       /* To make this screen a part of screen group*/
        g_id = mmi_frm_group_get_active_id();
       
        if (g_id == GRP_ID_INVALID)
        {
    	    EntryNewScreen(
    	    	SCR_ID_INPUT_METHOD_VK_POPUP_LIST, 
    	    	mmi_imc_pen_close_popup_list, 
    	    	NULL, 
    	    	NULL);
        }
        else
        {
            mmi_frm_scrn_enter(
            	g_id,
            	SCR_ID_INPUT_METHOD_VK_POPUP_LIST,
            	mmi_imc_pen_close_popup_list,
            	mmi_imc_pen_show_popup_list_int,
            	MMI_FRM_FG_ONLY_SCRN);
        }
    
        for(i =0; i<number_of_items; i++)
        {
            list_items[i] = (WCHAR *)get_string(list_of_items[i]);

            if (i == highlighted_item)
            {
                #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                list_icons[i] = get_image(0);
                #else
                list_icons[i] = get_image(IMG_ID_VKBD_ACTIVATE_ITEM);
                #endif
            }
            else
            {
                list_icons[i] = NULL;
            }
        }
        // category 1010 to show the list
       wgui_cat1010_show( 
                (WCHAR *)get_string(title),
                NULL,
                (WCHAR *)get_string(STR_GLOBAL_OK),
		        0,
		        (WCHAR *)get_string(STR_GLOBAL_BACK),
		        0,
                number_of_items,
                list_items,
                list_icons,
                NULL,
                0,
                highlighted_item,
                NULL);

                
		SetLeftSoftkeyFunction(confirm_callback, KEY_EVENT_UP);
	    SetRightSoftkeyFunction(cancel_callback, KEY_EVENT_UP);
	    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	    SetCenterSoftkeyFunction(confirm_callback, KEY_EVENT_UP);
	    register_center_softkey_to_enter_key();
	    redraw_center_softkey();  
    }
    else
#endif /* defined(__ATV_SMS_SUPPORT__) */
    {
        mmi_imc_pen_show_popup_list_int(x, y, number_of_items, list_of_items, highlighted_item, confirm_callback, cancel_callback);
    }
}


#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
#if defined(__MMI_VUI_ENGINE__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_popup_change_lang_callback
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
static void mmi_imc_popup_change_lang_callback(S32 selected_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_COSMOS_KEYPAD_BAR__)
        mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_COSMOS_KEYPAD_BAR__)
   #if !defined(__NO_HANDWRITING__)
   if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
    {
	   	mmi_imc_pen_vk_enable_single_block_hw();
    }
   #endif
   #endif
    mmi_imc_set_wlang((U32)selected_item);

	#if defined(__MMI_COSMOS_KEYPAD_BAR__)
	#if !defined(__NO_HANDWRITING__)
	hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc.mode_details_ptr->Handwriting_Attrib);
    if(!mmi_ime_hand_writing_hw_type_query(hw_type))
	{
		if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
		{
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        }
    }
    #endif
    #endif
    mmi_imc_redraw_screen_by_state();
}
#endif
#endif

/*****************************************************************************
* FUNCTION
*  mmi_imc_show_wlang_list
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
void mmi_imc_show_wlang_list()
{
	#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
    mmi_imc_message_struct imc_msg;
	#if defined(__MMI_VUI_ENGINE__)
    S32  highlight = 0; 
    U16 nNumofItem = 0;
    UI_string_type langList[IME_WRITING_LANG_TOTAL];
    #endif
    #endif
    
    
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
    imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;
    if (mmi_imc_send_message(&imc_msg))
    {
        return ;                 
    }
    else
    {
#if defined(__MMI_VUI_ENGINE__)
        /* venus screen */
        if (vadp_p2v_uc_is_in_venus())
        {
        nNumofItem = mmi_imm_get_curr_allow_writing_language_string_list(langList, IME_WRITING_LANG_TOTAL);

        if (nNumofItem <= 1)
        {
            return ;
        }
        highlight = mmi_imm_get_curr_writing_language_index();
        #if defined(__COSMOS_MMI_PACKAGE__)
	    //vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
        #endif
        vadp_p2v_show_ime_popup_by_mem(
            STR_INPUT_METHOD_WRITING_LANGUAGE,
            langList,
            nNumofItem,
            highlight,
            mmi_imc_popup_change_lang_callback,
			NULL, MMI_TRUE);
    }
        else
#endif
        /* plutoMMI wlang screen */
        {
            if (mmi_frm_group_get_active_id() != GRP_ID_INVALID)
            {
                g_imc_active_editor_screen_id = 0;
            }
            else
            {
                g_imc_active_editor_screen_id = GetActiveScreenId();
            }

            RegisterInputMethodScreenCloseFunction(mmi_imc_input_method_screen_close_function);

            EntryInputMethodScreen();    
        }
    }
#endif 

}
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_pen_input_type_selection_lsk_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_input_mode_selection_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    mmi_imm_input_mode_enum desired_mode = g_imc_selection_list_mode_array[index];
	#if defined(__MMI_COSMOS_KEYPAD_BAR__)
	mmi_imm_input_mode_enum mode_array[MMI_IMM_MAX_INPUT_METHOD_NUM];
   mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
   S32 numofitem=0;
   #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (desired_mode != IMM_INPUT_MODE_NONE)
        mmi_imm_set_user_desired_input_mode(desired_mode);
    mmi_imc_pen_set_user_desired_input_style(MMI_IMC_PEN_INPUT_STYLE_MAX);
    mmi_imc_gdi_lcd_freeze(TRUE);

    if (mmi_frm_group_get_active_id() == GRP_ID_INVALID)
    {
        GoBackHistory();
    }
    else
    {
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
    }
    #if defined(__MMI_COSMOS_KEYPAD_BAR__)
	   #if !defined(__NO_HANDWRITING__)
       if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
       {
		   	mmi_imc_pen_vk_enable_single_block_hw();
       }
       #if defined (__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
           numofitem = mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);
       #else
           numofitem = mmi_imm_get_curr_allow_input_mode_list(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);
       #endif
	   if(numofitem==index)
	   {
			mmi_imc_pen_show_handwriting_vk();
	   }
       else
      #endif
	  #endif
			{
    if (mmi_imm_get_curr_input_mode() != desired_mode &&
        mmi_imm_is_curr_allow_input_mode(desired_mode))
    {
        mmi_imm_set_current_input_mode(desired_mode);

        if (mmi_imc_change_input_mode(desired_mode, 0))
        {
            mmi_imc_redraw_screen_by_state();
        }
    }    
			}
	#if defined(__MMI_COSMOS_KEYPAD_BAR__)
	#if !defined(__NO_HANDWRITING__)
	hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc.mode_details_ptr->Handwriting_Attrib);
    if(!mmi_ime_hand_writing_hw_type_query(hw_type))
	{
		if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
		{
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        }
    }
    mmi_imc_redraw_screen_by_state();
    #endif
    #endif
    mmi_imc_gdi_lcd_freeze(gdi_freeze);
    mmi_imc_repaint_screen();

#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vrt_canvas_resume();
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_pen_input_type_selection_rsk_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_input_mode_selection_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_imc_pen_set_user_desired_input_style(MMI_IMC_PEN_INPUT_STYLE_NONE);
    if (mmi_frm_group_get_active_id() == GRP_ID_INVALID)
    {
        GoBackHistory();
    }
    else
    {
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
    }
}
/* to do to be removed after checking */
void mmi_imc_invoke_setting_handler()
{
	#if 0
/* under construction !*/
  #endif
}
#endif
/*****************************************************************************
* FUNCTION
*  mmi_imc_popup_change_mode_callback
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
static void mmi_imc_popup_change_mode_callback(S32 selected_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_COSMOS_KEYPAD_BAR__)
   S32 numofitem=0;
   mmi_imm_input_mode_enum mode_array[MMI_IMM_MAX_INPUT_METHOD_NUM];
   mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
   #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_COSMOS_KEYPAD_BAR__)
   #if !defined(__NO_HANDWRITING__)
   MMI_BOOL is_VK_ON  = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) ;
   if(is_VK_ON)
    {
	   	mmi_imc_pen_vk_enable_single_block_hw();
    }
  #if defined (__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    numofitem = mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);
  #else
    numofitem = mmi_imm_get_curr_allow_input_mode_list(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);
#endif
	if(numofitem==selected_item)
			mmi_imc_pen_show_handwriting_vk();
    else 
#endif 
#endif 
    {
        mmi_imc_set_inputmode((U32)selected_item);
        
    }
 #if defined(__MMI_COSMOS_KEYPAD_BAR__)
	#if !defined(__NO_HANDWRITING__)
	hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc.mode_details_ptr->Handwriting_Attrib);
    if(!mmi_ime_hand_writing_hw_type_query(hw_type))
	{
		if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
		{
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        }
    }
	else
	{
		if(is_VK_ON)
		{
			mmi_imc_pen_show_handwriting_vk();
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
        }
	}
 #endif
 #endif
	mmi_imc_redraw_screen_by_state();
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_show_inputmode_list
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
void mmi_imc_show_inputmode_list(void)
{

    S32 i = 0, highlight = 0; 
	#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
	mmi_imc_message_struct imc_msg;
	gui_virtual_keyboard_key_pos_info_struct key_info;
	S32 count =0;
    #else
	#if defined(__MMI_VUI_ENGINE__)
    U16 nNumofItem = 0;
	U16 modeStrIdList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    mmi_imm_input_mode_enum modeList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    #endif
    #endif
    mmi_imm_input_mode_enum mode;
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)

    imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;
    if (mmi_imc_send_message(&imc_msg))
    {
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            if (mmi_imc_change_input_mode(mmi_imm_get_next_mode(), 0))
            {
                imc_msg.message_id = MMI_IMC_MESSAGE_MODE_CHANGED;
                mmi_imc_send_message(&imc_msg);
            }

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
    }
    else if(mmi_imm_get_input_mode_num_in_current_writing_language() > 1)
    {
        count = mmi_imm_get_curr_allow_input_mode_string_list_of_curr_writing_lang(g_imc_selection_list_str_array, MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);

        if (count < 1)
        {
            return ;
        }
#if defined(__MMI_COSMOS_KEYPAD_BAR__) && !defined(__NO_HANDWRITING__)
        g_imc_selection_list_str_array[count]=STR_IME_PEN_INPUT_STYLE_HW;
	    g_imc_selection_list_mode_array[count]=IMM_INPUT_MODE_MAX_NUM;
        count++;
#endif
        mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang(g_imc_selection_list_mode_array, MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);
        mmi_imc_reset_ime_state();
        mode = mmi_imm_get_curr_input_mode();

        i = 0;

        while (i < count)
        {
            /* we need to check whether we need to show handwriting as highlighted */ 
            if (mode == g_imc_selection_list_mode_array[i])
            {
                highlight = i;
                break;
            }
            i ++;
        }
#if defined(__MMI_COSMOS_KEYPAD_BAR__) && !defined(__NO_HANDWRITING__)
		if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
		{
			i = count - 1;
			highlight = count - 1;
		}
#endif
#if defined(__MMI_VUI_ENGINE__)
/* show  venus popup */
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_show_ime_popup(
                STR_GLOBAL_INPUT_METHOD,
                g_imc_selection_list_str_array,
                count,
                highlight,
                mmi_imc_popup_change_mode_callback,
				NULL, MMI_TRUE);
		g_imc_show_venus_popup = MMI_TRUE;
        }
		#if defined(__COSMOS_MMI_PACKAGE__)
		else if (!vadp_p2v_uc_is_in_venus())
        {
			if (mmi_frm_group_get_active_id() != GRP_ID_INVALID)
            {
                g_imc_active_editor_screen_id = 0;
            }
            else
            {
                g_imc_active_editor_screen_id = GetActiveScreenId();
            }
            RegisterInputMethodScreenCloseFunction(mmi_imc_input_method_screen_close_function);
            EntryInputModeScreen();
        }
		#endif
        else
#endif
        {
			key_info = mmi_imc_pen_get_keyinfo();
            mmi_imc_show_popup_list(
                key_info.x,
                /* to make sure when list is large its not cut The size of botton gap reduced form 1 key to half key */
                UI_device_height - (key_info.height)/2, 
                count, 
                g_imc_selection_list_str_array, 
                highlight, 
                mmi_imc_input_mode_selection_lsk_handler, 
                mmi_imc_input_mode_selection_rsk_handler,
				STR_GLOBAL_INPUT_METHOD);
        }
}

#else



#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        nNumofItem = mmi_imm_get_curr_allow_input_mode_string_list(modeStrIdList, MMI_IMM_MAX_INPUT_METHOD_NUM);
        if (nNumofItem <= 1)
        {
            return ;
        }
        mmi_imm_get_curr_allow_input_mode_list(modeList, MMI_IMM_MAX_INPUT_METHOD_NUM);
       #if defined(__MMI_COSMOS_KEYPAD_BAR__) && !defined(__NO_HANDWRITING__)
       modeStrIdList[nNumofItem] =STR_IME_PEN_INPUT_STYLE_HW;   
	   modeList[nNumofItem]= IMM_INPUT_MODE_MAX_NUM;
	   nNumofItem++;
       #endif
        mmi_imc_reset_ime_state();
        mode = mmi_imm_get_curr_input_mode();
        i = 0;
        while (i < nNumofItem)
        {
            if (mode == modeList[i])
            {
                highlight = i;
                break;
            }
            i ++;
        }

        vadp_p2v_show_ime_popup(
            STR_GLOBAL_INPUT_METHOD,
            modeStrIdList,
            nNumofItem,
            highlight,
            mmi_imc_popup_change_mode_callback
            ,NULL, MMI_TRUE);
	g_imc_show_venus_popup =MMI_TRUE;
    }
        else
    #endif
        {
            if (mmi_frm_group_get_active_id() != GRP_ID_INVALID)
            {
                g_imc_active_editor_screen_id = 0;
            }
            else
            {
                g_imc_active_editor_screen_id = GetActiveScreenId();
            }
            RegisterInputMethodScreenCloseFunction(mmi_imc_input_method_screen_close_function);
            EntryInputMethodScreen();
        }

#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_input_method_screen_close_function
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
 void mmi_imc_input_method_screen_close_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_imc_active_editor_screen_id)
    {
        GoBackHistory();
    }
    else
    {
    #ifdef __MMI_FRM_HISTORY__
        GoBackToHistory(g_imc_active_editor_screen_id);
    #endif
        g_imc_active_editor_screen_id = 0;
    }
}



#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_gdi_lcd_freeze
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
 void mmi_imc_gdi_lcd_freeze(BOOL lcd_freeze)
{
    //we need not freeze lcd in venus, venus works through VRT
	#if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
    #endif
        {
            gdi_lcd_freeze(lcd_freeze);
        }
 }


/*****************************************************************************
* FUNCTION
*  mmi_imc_process_key_input
* DESCRIPTION
* according to event pass to up /down /long /repeat existing handlers 
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imc_process_key_input(U16 key_code, U16 key_type , U16 ucs2_value, U32 special_key_flag)   /* New Api */
{
	
/* last two input can be zero for non qwerty inputs */
	if (!mmi_imc_is_connected())
	{
		ASSERT(0); /* to check if any invalid call being madde during development */
		return MMI_FALSE;
	}

    //[MRE_Editor]
    /* when not in ime state, do not handle navigation keys */
    if (!mmi_imc_is_ime_state() && (key_code == KEY_LEFT_ARROW || key_code == KEY_RIGHT_ARROW || key_code == KEY_UP_ARROW || key_code == KEY_DOWN_ARROW))
    {
        return MMI_FALSE;
    }
		
		
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	mmi_imc_key_qwerty_group_key_handler(key_code, key_type, ucs2_value , special_key_flag);
#else
	switch(key_type)
	{
	    case KEY_EVENT_DOWN:
	 	    mmi_imc_key_group_key_down();
	 	    break;
	    case KEY_EVENT_UP:
			mmi_imc_key_group_key_up();
		    break;
	    case KEY_EVENT_LONG_PRESS :
			mmi_imc_key_group_key_long();
			break;
        case KEY_EVENT_REPEAT:
			mmi_imc_key_group_key_repeat();
			break;
	}
#endif
        return MMI_TRUE;


}
#if defined(__MMI_IME_CANDIDATE_GRID__)
 /*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_candidates_word_engine_grid
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
void mmi_imc_get_candidates_word_engine_grid(mmi_imc_state_enum pre_state)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   mmi_imc_state_enum curr_state = mmi_imc_get_state();
   mmi_ime_query_param_struct   query_param = {0};
    mmi_ime_query_result_struct  query_result = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
   //mmi_imm_get_curr_input_mode
#if defined(__MMI_VIRTUAL_KEYBOARD__)
	if(mmi_imc_pen_is_handwriting_vk())
	{
		return;
	}
#endif
	g_imc.global_data.cand_page = 0;
    switch(mmi_imm_get_curr_input_mode())
	{
	case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
	case IMM_INPUT_MODE_SM_PINYIN:
		#if defined(__MMI_CSTAR_PHRASE_INPUT__)
		
			if(pre_state == MMI_IMC_STATE_ASSOC_SELECTING)
			{
				 query_param.pre_string = g_imc.global_data.pre_string;
				 query_param.first_index = 0;
				 query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
				 query_result.result_buffer = g_imc.global_data.cand_buff;
				 mmi_ime_word_get_associates(&query_param, &query_result);
				 mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);

			}
			else
			{
				if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY)
				{
				mmi_imc_pen_get_candidates_qwerty_input_mode();
			}
				else
				{
						g_imc.global_data.cand_page = 0;
						mmi_imc_key_smart_phonetic_get_candidate(MMI_TRUE);
						mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID);
					
				}
			}
		


		#else
			if(pre_state == MMI_IMC_STATE_ASSOC_SELECTING)
			{
				query_param.pre_string = g_imc.global_data.pre_string;
				query_param.first_index = g_imc.global_data.cand_first_index[g_imc.global_data.cand_page];
				query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
				query_result.result_buffer = g_imc.global_data.cand_buff;
				mmi_imc_get_associates_from_word_engine(&query_param, &query_result);
				mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
			}
			else
			{
				 mmi_imc_change_highlighted_composition_from_composition_box(0);
			}
		#endif

		break;
	case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
	case IMM_INPUT_MODE_TR_BOPOMO:
		if(pre_state == MMI_IMC_STATE_ASSOC_SELECTING)
		{
			 query_param.pre_string = g_imc.global_data.pre_string;
			 query_param.first_index = 0;
			 query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
			 query_result.result_buffer = g_imc.global_data.cand_buff;
			 mmi_ime_word_get_associates(&query_param, &query_result);
			 mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);

		}
		else
		{
			mmi_imc_pen_set_vk_candidate();
			mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID);
			
		}
		break;
	case IMM_INPUT_MODE_SM_STROKE:
	case IMM_INPUT_MODE_TR_STROKE:
	case IMM_INPUT_MODE_HK_STROKE:
		//stroke api
	    if(pre_state == MMI_IMC_STATE_ASSOC_SELECTING)
		{
			query_param.pre_string = g_imc.global_data.pre_string;
			query_param.first_index = g_imc.global_data.cand_first_index[g_imc.global_data.cand_page];
			query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
			query_result.result_buffer = g_imc.global_data.cand_buff;
			mmi_imc_get_associates_from_word_engine(&query_param, &query_result);
			mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
		}
		else
		{
			 mmi_imc_key_stroke_get_candidate();
		}
		break;
	default:
		//alphabetic mode related to english and other languages
		if(pre_state == MMI_IMC_STATE_SMART_CANDIDATE || pre_state == MMI_IMC_STATE_VK_CAND)
		{
        	 mmi_imc_key_smart_alphabetic_get_candidate(0);
		}
		break;
	}
}
#endif

#if defined(__MMI_IME_CANDIDATE_GRID__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_is_grid_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
MMI_BOOL mmi_imc_is_grid_state(void)
{
	
			if(mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING_GRID || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_GRID || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX 
				#if defined(__MMI_CSTAR_PHRASE_INPUT__)
			|| mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID
				#endif
			)
			{
				return MMI_TRUE;
			}
			else
			{
				return MMI_FALSE;
			}
	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_update_smart_pinyin_composition
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
void mmi_imc_update_smart_pinyin_composition(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	    mmi_ime_query_param_struct   query_param = {0};
        mmi_ime_query_result_struct  query_result = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

		memset(&query_param, 0, sizeof(query_param));   
        memset(&query_result, 0, sizeof(query_result));
		g_imc.global_data.comp_select = 0;
		g_imc.global_data.comp_page = 0;

	    query_param.elembuf_ptr= g_imc.global_data.key_buffer;
        query_param.elembuf_cnt= g_imc.global_data.key_element_length;
        query_param.first_index = g_imc.global_data.comp_first_index[g_imc.global_data.comp_page];
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
        query_result.result_buffer = g_imc.global_data.comp_buff;

        mmi_ime_word_get_spellings(&query_param, &query_result);
        if (query_result.result_cnt)
		{
			mmi_imc_update_composition_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
		}
		
}
#endif
