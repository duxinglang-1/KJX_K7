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
*    Imm.c
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   Source file for IMM module (Input Method Management)
* Author:
* -------
 * -------
*
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
dear yong,
mmi_imm_get_next_writing_mode is now in macro , so available for all laods , vk or no vk .__MMI_IME_V3__ , please use p4 file , to call this api and fix the issue
Thanks


[sikun]
dear manik,
because of new UE, Qwerty keypad need same function which named get_next_input_writing_mode, It shoulde be macro by __MMI_IME_V3__ instead of  "__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__" please help to revise it. you can discuss with yong for new UE for keypad. he need call this api also, thank you.

[yong]
Dear sikun,
the root cause of this problem is that you only add the macro "__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__" for Function"mmi_imm_get_next_mode". In imev3 key only load, it can not change the input mode like it is in IMEV3 VK load! Please hlep to check it! Any proble, you can discuss with me!



[Joy]
Dear yong,
please follow the spec. short press IME key, we need to switch all the input modes. 

[Manik]
Dear Joy,
as per discussion with JF , the behaviour iin code is the right one  , we need to update the specs to close this issue.
Please help to do the needful
Thanks

[Xianghe]
Dear Manik,
I think any project with IMEv3 should be designed following the IMEv3 UE SPEC, and they should have consistent design without exception.
Thanks~

[Manik]
dear XIanghe,

builds like this dont have vk , i dont think it can follow ime v3 style as that would mean user cannot go to different cases of the language,
 i suggest to keep the current design , to change amongst wlang , user can go to option and selelct different wlang(this is being imnplemented already for a different bug  03166982), and use # key to move across cases of the langauge.

please comment


[Gaurav]
Dear Manik,
Please check this input mode issue,
thanks.

[sikun]
dear gaurav,
please take care of this problem, I think this is because of you replace the mmi_imm_get_next_mode of mmi_imm_get_next_writing_mode, when key change mode comes, it's UE is like vkv2's, if any problem, you can discuss it with yong. thank you

[rong]
dear sikun, the issue will not happen on other project  like FTE QVGA NVK
dear rong,
please help to check this problem is happens on other IMEv3 project or not, thank you.

[Load Path]
\\mtksdd01.gslb.mediatek.inc\high_priority\sw_releases\W12.17\11B\official

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
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


/*****************************************************************************
*  Include
*****************************************************************************/
#include "MMI_features.h"


#include "mmi_include.h"

#ifdef __MMI_HANDWRITING_MEMORY_CARD_SUPPORT__
#include "ime_lib_config.h"
#include "FileMgrSrvGprot.h"
#include "fs_gprot.h"
#endif

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#include "ImeQwertyProt.h"
#endif
#include "ImmProt.h"
#include "IMERes.h"
#include "Imc.h"
#include "Imc_key.h"
#include "Imc_pen.h"
#include "Handwriting_engine.h"
#include "Imc_pen.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_srv_editor_def.h"

#if defined(__MMI_IME_FTE_ENHANCE__)
#if defined(__MMI_VIRTUAL_KEYBOARD__)
#include "gui_virtual_keyboard_misc_res.h"
#endif
#endif

/* RHR ADD */
#include "ImeGprot.h"
#include "MMIDataType.h"
#include "gui_virtual_keyboard_language_type.h"
#include "FontRes.h"
#include "kal_non_specific_general_types.h"
#include "mmi_rp_app_uiframework_def.h"
#include "gui_data_types.h"
#include "wgui_categories_inputs.h"
#include "string.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "mmi_rp_srv_editor_def.h"
#include "GlobalResDef.h"
#include "ProfilesSrvGprot.h"


#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
#include "Lang_interface.h"
#include "ime_lib_config.h"
#endif

#ifdef __MMI_IME_PLUG_IN__
#include "ImeSDKGprot.h"
#endif

/*****************************************************************************
*  Define
*****************************************************************************/
#define MMI_IMM_MAX_INPUT_MODE_NUM_IN_ONE_LANG (7)
#define MMI_IMM_MAX_INPUT_MODE_SWITCH_RULE_NUM (10)
#define MMI_IMM_MAX_INPUT_MODE_SWITCH_RULE_ITEM_NUM (10)

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#if defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__) \
    || defined(__MMI_LANG_FRENCH__) ||defined(__MMI_LANG_CA_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__) \
    || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_TURKISH__) \
    || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__) \
    || defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_DANISH__) \
    || defined(__MMI_LANG_HUNGARIAN__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_ROMANIAN__) \
    || defined(__MMI_LANG_GREEK__) || defined(__MMI_LANG_BULGARIAN__) || defined(__MMI_LANG_MOLDOVAN__)|| defined(__MMI_LANG_CATALAN__) \
    || defined(__MMI_LANG_AZERBAIJANI__)|| defined(__MMI_LANG_HAUSA__)|| defined(__MMI_LANG_ICELANDIC__)|| defined(__MMI_LANG_YORUBA__)

#define  __MMI_IMM_EUROPEAN_LANGUAGE_DEAD_KEY_TABLE__

#endif /* European languages */

#define MMI_IMM_MAX_DEADKEY_INPUT (2)

#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
#define IS_FILTER_CAPS    (MMI_FALSE)
#else
#define IS_FILTER_CAPS    (!mmi_imm_is_auto_capitalization_enabled())
#endif


/*****************************************************************************
*  Typedef
*****************************************************************************/
typedef struct _mmi_imm_input_mode_item
{
    mmi_imm_input_mode_enum mode_id;
    S32 index;
}mmi_imm_input_mode_item;

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
typedef struct
{
    S16 input_len;
    UI_character_type input_char[MMI_IMM_MAX_DEADKEY_INPUT];
    UI_character_type output_char;
}mmi_imm_dead_key_symbol_struct, *mmi_imm_dead_key_symbol_struct_p;

typedef struct
{
    mmi_imm_support_writing_lang_enum lang_id;
    mmi_imm_dead_key_symbol_struct_p table_ptr;
}mmi_imm_dead_key_lang_talbe_struct, *mmmi_imm_dead_key_lang_talbe_struct_p;

#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */

/*****************************************************************************
* Global variables
*****************************************************************************/
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_V3__)
UI_character_type g_mmi_imm_cur_lang_group_letter_table[MMI_IMM_QWERTY_MAX_LETTER_GROUPS][MMI_IMM_QWERTY_MAX_GROUP_LETTER_NUM];
UI_character_type g_mmi_imm_group_letter_set[MMI_IMM_MAX_GROUP_LETTER_SET];
#if defined(__MMI_IME_VK_TYPE_QWERTY__)
UI_character_type g_mmi_imm_group_letter_set_for_vk[MMI_IMM_MAX_GROUP_LETTER_SET];
#endif
#endif
extern const sIMEModeDetails *gIMEModeArray;
extern S16 MMI_current_input_ext_type;
/* For maintaining the higher 8 bit of the input type flag
* to be used only by category
*/ 
static U32 g_mmi_imm_input_special_ext_type = 0;
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
extern gui_virtual_keyboard_language_enum g_wgui_virtual_keyboard_lang_type;
#endif

/* This is for making writing language map with phone language */
extern U16 gCurrLangIndex;
mmi_imm_input_mode_enum  MMI_all_prefered_input_mode_set[IMM_INPUT_MODE_MAX_NUM] = {IMM_INPUT_MODE_NONE};

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_IME_V3__)
const U8 mmi_imm_hinglish_language_name[] =  {(char)0x48,(char)0x0,(char)0x69,(char)0x0,(char)0x6E,(char)0x0,(char)0x67,(char)0x0,(char)0x6C,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0,(char)0x00,(char)0x00};
U16 g_mmi_imm_enabled_writing_language ;  /*Flag which keeps writing language phone settings status */
ime_writing_lang_struct g_ime_writing_lang_array[MAX_WRITING_LANG]; 
extern U16 gMaxDeployedLangs;
extern sLanguageDetails *gLanguageArray;
S32 g_enabled_wlang[20];
S32 g_enabled_wlang_count =0; /* Count of writing languages */
mmi_imm_support_writing_lang_enum g_current_handwriting_lang_id = IME_WRITING_LANG_ABC;
#endif

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
BOOL g_is_init_with_memory_card = MMI_FALSE;
BOOL g_need_to_disable_hw = MMI_TRUE;
#endif

#if defined(__MMI_IME_V3__)
    mmi_imm_input_mode_enum g_mmi_imm_default_handwriting_input_mode = IMM_INPUT_MODE_NONE;
#endif

#if defined (__MMI_IME_FUZZY_PINYIN__)
    #if defined __MMI_GUOBI__
     const char* g_fuzzy_pinyin_menu_item[] = {"H_F", "N_L", "NG_N", "XH_X", "K_G", "R_L","\0"};
      mmi_imm_fuzzy_pinyin_enum fuzzy_pinyin_enum_array[] = 
    {   
            IME_FUZZY_PINYIN_H_F ,
            IME_FUZZY_PINYIN_N_L ,
            IME_FUZZY_PINYIN_NG_N,
            IME_FUZZY_PINYIN_XH_X,
            IME_FUZZY_PINYIN_K_G ,
            IME_FUZZY_PINYIN_R_L ,
            IME_FUZZY_PINYIN_MAX ,

    };
    #else
    const char* g_fuzzy_pinyin_menu_item[] = {"Z_ZH", "C_CH", "S_SH", "H_F", "N_L", "IN_ING", "EN_ENG", "AN_ANG", "IAN_IANG", "UAN_UANG","\0"};
    mmi_imm_fuzzy_pinyin_enum fuzzy_pinyin_enum_array[] = 
    {   
        IME_FUZZY_PINYIN_Z_ZH,
        IME_FUZZY_PINYIN_C_CH,
        IME_FUZZY_PINYIN_S_SH,
        IME_FUZZY_PINYIN_H_F,
        IME_FUZZY_PINYIN_N_L,
        IME_FUZZY_PINYIN_IN_ING,
        IME_FUZZY_PINYIN_EN_ENG,
        IME_FUZZY_PINYIN_AN_ANG,
        IME_FUZZY_PINYIN_IAN_IANG,
        IME_FUZZY_PINYIN_UAN_UANG,
        IME_FUZZY_PINYIN_MAX,
    };
   
#endif
    ime_fuzzy_pinyin_struct g_ime_fuzzy_pinyin_array[MAX_FUZZY_PINYIN];
    U32 g_mmi_imm_enabled_fuzzy_pinyin = 0;  /*Flag which keeps fuzzy pinyin phone settings status */
    U8 g_fuzzy_pinyin_state[MAX_FUZZY_PINYIN-1] ;
#endif

const mmi_imm_input_mode_enum MMI_implement_input_mode_set[] = 
{
    IMM_INPUT_MODE_123,
    IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO,
    IMM_INPUT_MODE_QUICK_SEARCH_PINYIN,
    IMM_INPUT_MODE_KEYPAD_NUMERIC,
    IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE,
    IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE,
    IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE,    
    IMM_INPUT_MODE_SIGNED_123,
    IMM_INPUT_MODE_FLOAT_123,
    IMM_INPUT_MODE_PHONE_NUMBER,
    IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR,
    IMM_INPUT_MODE_SIM_NUMERIC,
    IMM_INPUT_MODE_SIGNED_FLOAT_123,
    IMM_INPUT_MODE_123_SYMBOLS,
#if defined(__MMI_IME_MAGIC_ONE__)
    IMM_INPUT_MODE_MAGIC_NUMBER,
#endif
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC,
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

#if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) 
    IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
#endif 
#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)
    IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
#endif 
#if defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
    IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
#endif 


#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
    IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
#endif 
#if defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)
    IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
#endif 
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
    IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
#endif 
#endif


#if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)
    IMM_INPUT_MODE_TR_STROKE,
#endif 
#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)
    IMM_INPUT_MODE_SM_STROKE,
#endif 
#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__)
    IMM_INPUT_MODE_TR_STROKE,
#endif 
#if defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__)
    IMM_INPUT_MODE_SM_STROKE,
#endif
#if defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__)
    IMM_INPUT_MODE_TR_STROKE,
#endif 
#if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__)|| defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_STROKE_INPUT__)
    IMM_INPUT_MODE_SM_STROKE,
#endif     


#if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)
    IMM_INPUT_MODE_TR_BOPOMO,
#endif 
#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)
    IMM_INPUT_MODE_SM_PINYIN,
#endif 


#if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)
    IMM_INPUT_MODE_SM_PINYIN,
#endif 

#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__)
    IMM_INPUT_MODE_TR_BOPOMO,
#endif 
#if defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__)
    IMM_INPUT_MODE_SM_PINYIN,
#endif 

#if defined(__MMI_ZI_HK_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__)
    IMM_INPUT_MODE_HK_STROKE,
#endif 
#if defined(__MMI_T9_HK_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)
    IMM_INPUT_MODE_HK_STROKE,
#endif 


#if defined(__MMI_ZI_PRC_ENGLISH__) || defined(__MMI_ZI_UK_ENGLISH__)
    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
    IMM_INPUT_MODE_SMART_LOWERCASE_ABC,
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,
#endif
#endif /* defined(__MMI_ZI_PRC_ENGLISH__) || defined(__MMI_ZI_UK_ENGLISH__) */ 


    /*Afrikaans*/ 
#if defined(__MMI_MULTITAP_AFRIKAANS__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AFRIKAANS, 
#endif
#endif

#if defined(__MMI_IME_AFRIKAANS__)
    IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS, 
    IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AFRIKAANS,
#endif
#endif
    /*Albanian*/ 
#if defined(__MMI_MULTITAP_ALBANIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ALBANIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ALBANIAN, 
#endif
#endif

#if defined(__MMI_IME_ALBANIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_ALBANIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ALBANIAN,
#endif
#endif
    /*ARMENIAN*/ 
#if defined(__MMI_MULTITAP_ARMENIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ARMENIAN, 
#endif
#endif

#if defined(__MMI_IME_ARMENIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ARMENIAN,
#endif
#endif
    /*Azerbaijani*/ 
#if defined(__MMI_MULTITAP_AZERBAIJANI__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_AZERBAIJANI,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AZERBAIJANI, 
#endif
#endif

#if defined(__MMI_IME_AZERBAIJANI__)
    IMM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI, 
    IMM_INPUT_MODE_SMART_UPPERCASE_AZERBAIJANI, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AZERBAIJANI,
#endif
#endif
    /*Basque*/ 
#if defined(__MMI_MULTITAP_BASQUE__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BASQUE, 
#endif
#endif

#if defined(__MMI_IME_BASQUE__)
    IMM_INPUT_MODE_SMART_LOWERCASE_BASQUE, 
    IMM_INPUT_MODE_SMART_UPPERCASE_BASQUE, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BASQUE,
#endif
#endif
    /*Bulgarian*/ 
#if defined(__MMI_MULTITAP_BULGARIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BULGARIAN, 
#endif
#endif

#if defined(__MMI_IME_BULGARIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BULGARIAN,
#endif
#endif
    /*Catalan*/ 
#if defined(__MMI_MULTITAP_CATALAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CATALAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CATALAN, 
#endif
#endif

#if defined(__MMI_IME_CATALAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_CATALAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_CATALAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CATALAN,
#endif
#endif
    /*Croatian*/ 
#if defined(__MMI_MULTITAP_CROATIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CROATIAN, 
#endif
#endif

#if defined(__MMI_IME_CROATIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CROATIAN,
#endif
#endif
    /*Czech*/ 
#if defined(__MMI_MULTITAP_CZECH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CZECH, 
#endif
#endif

#if defined(__MMI_IME_CZECH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_CZECH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_CZECH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CZECH,
#endif
#endif
    /*Danish*/ 
#if defined(__MMI_MULTITAP_DANISH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DANISH, 
#endif
#endif

#if defined(__MMI_IME_DANISH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_DANISH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_DANISH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DANISH,
#endif
#endif
    /*Dutch*/ 
#if defined(__MMI_MULTITAP_DUTCH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DUTCH, 
#endif
#endif

#if defined(__MMI_IME_DUTCH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DUTCH,
#endif
#endif
    /*ABC*/ 
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC, 
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC,

    IMM_INPUT_MODE_SMART_LOWERCASE_ABC, 
    IMM_INPUT_MODE_SMART_UPPERCASE_ABC, 
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,
    /*Estonian*/ 
#if defined(__MMI_MULTITAP_ESTONIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ESTONIAN, 
#endif
#endif

#if defined(__MMI_IME_ESTONIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ESTONIAN,
#endif
#endif
    /*Filipino*/ 
#if defined(__MMI_MULTITAP_FILIPINO__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FILIPINO,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FILIPINO, 
#endif
#endif

#if defined(__MMI_IME_FILIPINO__)
    IMM_INPUT_MODE_SMART_LOWERCASE_FILIPINO, 
    IMM_INPUT_MODE_SMART_UPPERCASE_FILIPINO, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FILIPINO,
#endif
#endif
    /*Finnish*/ 
#if defined(__MMI_MULTITAP_FINNISH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FINNISH, 
#endif
#endif

#if defined(__MMI_IME_FINNISH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FINNISH,
#endif
#endif
    /*French*/ 
#if defined(__MMI_MULTITAP_FRENCH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FRENCH, 
#endif
#endif

#if defined(__MMI_IME_FRENCH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH,
#endif
#endif
    /*Galician*/ 
#if defined(__MMI_MULTITAP_GALICIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GALICIAN, 
#endif
#endif

#if defined(__MMI_IME_GALICIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_GALICIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_GALICIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GALICIAN,
#endif
#endif
    /*German*/ 
#if defined(__MMI_MULTITAP_GERMAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GERMAN, 
#endif
#endif

#if defined(__MMI_IME_GERMAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GERMAN,
#endif
#endif
    /*Greek*/ 
#if defined(__MMI_MULTITAP_GREEK__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GREEK, 
#endif
#endif

#if defined(__MMI_IME_GREEK__)
    IMM_INPUT_MODE_SMART_LOWERCASE_GREEK, 
    IMM_INPUT_MODE_SMART_UPPERCASE_GREEK, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GREEK,
#endif
#endif
    /*Hausa*/ 
#if defined(__MMI_MULTITAP_HAUSA__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HAUSA,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HAUSA, 
#endif
#endif

#if defined(__MMI_IME_HAUSA__)
    IMM_INPUT_MODE_SMART_LOWERCASE_HAUSA, 
    IMM_INPUT_MODE_SMART_UPPERCASE_HAUSA, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HAUSA,
#endif
#endif
    /*Hungarian*/ 
#if defined(__MMI_MULTITAP_HUNGARIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HUNGARIAN, 
#endif
#endif

#if defined(__MMI_IME_HUNGARIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HUNGARIAN,
#endif
#endif
    /*Icelandic*/ 
#if defined(__MMI_MULTITAP_ICELANDIC__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ICELANDIC,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ICELANDIC, 
#endif
#endif

#if defined(__MMI_IME_ICELANDIC__)
    IMM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC, 
    IMM_INPUT_MODE_SMART_UPPERCASE_ICELANDIC, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ICELANDIC,
#endif
#endif
    /*Igbo*/ 
#if defined(__MMI_MULTITAP_IGBO__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IGBO, 
#endif
#endif

#if defined(__MMI_IME_IGBO__)
    IMM_INPUT_MODE_SMART_LOWERCASE_IGBO, 
    IMM_INPUT_MODE_SMART_UPPERCASE_IGBO, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_IGBO,
#endif
#endif
    /*Indonesian*/ 
#if defined(__MMI_MULTITAP_INDONESIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN, 
#endif
#endif

#if defined(__MMI_IME_INDONESIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN,
#endif
#endif
    /*Irish*/ 
#if defined(__MMI_MULTITAP_IRISH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IRISH, 
#endif
#endif

#if defined(__MMI_IME_IRISH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_IRISH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_IRISH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_IRISH,
#endif
#endif
    /*Italian*/ 
#if defined(__MMI_MULTITAP_ITALIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ITALIAN, 
#endif
#endif

#if defined(__MMI_IME_ITALIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ITALIAN,
#endif
#endif
    /*Kazakh*/ 
#if defined(__MMI_MULTITAP_KAZAKH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_KAZAKH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_KAZAKH, 
#endif
#endif

#if defined(__MMI_IME_KAZAKH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_KAZAKH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_KAZAKH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_KAZAKH,
#endif
#endif
#if defined(__MMI_MULTITAP_KOREAN__)
    IMM_INPUT_MODE_MULTITAP_KOREAN,    
#endif
    /*Latvian*/ 
#if defined(__MMI_MULTITAP_LATVIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LATVIAN, 
#endif
#endif

#if defined(__MMI_IME_LATVIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_LATVIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LATVIAN,
#endif
#endif
    /*Lithuanian*/ 
#if defined(__MMI_MULTITAP_LITHUANIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LITHUANIAN, 
#endif
#endif

#if defined(__MMI_IME_LITHUANIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LITHUANIAN,
#endif
#endif
    /*Macedonian*/ 
#if defined(__MMI_MULTITAP_MACEDONIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MACEDONIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MACEDONIAN, 
#endif
#endif

#if defined(__MMI_IME_MACEDONIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_MACEDONIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MACEDONIAN,
#endif
#endif
    /*Malay*/ 
#if defined(__MMI_MULTITAP_MALAY__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY, 
#endif
#endif

#if defined(__MMI_IME_MALAY__)
    IMM_INPUT_MODE_SMART_LOWERCASE_MALAY, 
    IMM_INPUT_MODE_SMART_UPPERCASE_MALAY, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY,
#endif
#endif
    /*Moldovan*/ 
#if defined(__MMI_MULTITAP_MOLDOVAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MOLDOVAN, 
#endif
#endif

#if defined(__MMI_IME_MOLDOVAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MOLDOVAN,
#endif
#endif
    /*Norwegian*/ 
#if defined(__MMI_MULTITAP_NORWEGIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_NORWEGIAN, 
#endif
#endif

#if defined(__MMI_IME_NORWEGIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_NORWEGIAN,
#endif
#endif
    /*Polish*/ 
#if defined(__MMI_MULTITAP_POLISH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_POLISH, 
#endif
#endif

#if defined(__MMI_IME_POLISH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_POLISH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_POLISH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_POLISH,
#endif
#endif
    /*Portuguese*/ 
#if defined(__MMI_MULTITAP_PORTUGUESE__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE, 
#endif
#endif

#if defined(__MMI_IME_PORTUGUESE__)
    IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE, 
    IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE,
#endif
#endif

#if defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_GB_SA_PORTUGUESE__)
    IMM_INPUT_MODE_SMART_UPPERCASE_SA_PORTUGUESE,
    IMM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE,
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_PORTUGUESE,
#endif
#endif /* defined(__MMI_ZI_SA_PORTUGUESE__) */ 

    /*Romanian*/ 
#if defined(__MMI_MULTITAP_ROMANIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ROMANIAN, 
#endif
#endif

#if defined(__MMI_IME_ROMANIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ROMANIAN,
#endif
#endif
    /*Russian*/ 
#if defined(__MMI_MULTITAP_RUSSIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN, 
#endif
#endif

#if defined(__MMI_IME_RUSSIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN,
#endif
#endif
    /*Serbian*/ 
#if defined(__MMI_MULTITAP_SERBIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SERBIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SERBIAN, 
#endif
#endif

#if defined(__MMI_IME_SERBIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_SERBIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_SERBIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SERBIAN,
#endif
#endif
    /*Sesotho*/ 
#if defined(__MMI_MULTITAP_SESOTHO__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SESOTHO,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SESOTHO, 
#endif
#endif

#if defined(__MMI_IME_SESOTHO__)
    IMM_INPUT_MODE_SMART_LOWERCASE_SESOTHO, 
    IMM_INPUT_MODE_SMART_UPPERCASE_SESOTHO, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SESOTHO,
#endif
#endif
    /*Slovak*/ 
#if defined(__MMI_MULTITAP_SLOVAK__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVAK, 
#endif
#endif

#if defined(__MMI_IME_SLOVAK__)
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK, 
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVAK,
#endif
#endif
    /*Slovenian*/ 
#if defined(__MMI_MULTITAP_SLOVENIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVENIAN, 
#endif
#endif

#if defined(__MMI_IME_SLOVENIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVENIAN,
#endif
#endif
    /*Spanish*/ 
#if defined(__MMI_MULTITAP_SPANISH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH, 
#endif
#endif

#if defined(__MMI_IME_SPANISH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH,
#endif
#endif

#if defined(__MMI_ZI_SA_SPANISH__)||defined(__MMI_GB_SA_SPANISH__)
    IMM_INPUT_MODE_SMART_UPPERCASE_SA_SPANISH,
    IMM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH,
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_SPANISH,
#endif
#endif /* defined(__MMI_ZI_SA_SPANISH__)*/ 
#if defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__)
    IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH,
    IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH,
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH,
#endif
#endif /* defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__) */ 

    /*Swahili*/ 
#if defined(__MMI_MULTITAP_SWAHILI__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWAHILI, 
#endif
#endif

#if defined(__MMI_IME_SWAHILI__)
    IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI, 
    IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWAHILI,
#endif
#endif
    /*Swedish*/ 
#if defined(__MMI_MULTITAP_SWEDISH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWEDISH, 
#endif
#endif

#if defined(__MMI_IME_SWEDISH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWEDISH,
#endif
#endif
    /*Tagalog*/ 
#if defined(__MMI_MULTITAP_TAGALOG__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TAGALOG,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TAGALOG, 
#endif
#endif

#if defined(__MMI_IME_TAGALOG__)
    IMM_INPUT_MODE_SMART_LOWERCASE_TAGALOG, 
    IMM_INPUT_MODE_SMART_UPPERCASE_TAGALOG, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TAGALOG,
#endif
#endif
    /*Turkish*/ 
#if defined(__MMI_MULTITAP_TURKISH__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH, 
#endif
#endif

#if defined(__MMI_IME_TURKISH__)
    IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH, 
    IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH,
#endif
#endif
    /*Ukrainian*/ 
#if defined(__MMI_MULTITAP_UKRAINIAN__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_UKRAINIAN, 
#endif
#endif

#if defined(__MMI_IME_UKRAINIAN__)
    IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN, 
    IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UKRAINIAN,
#endif
#endif
    /*Vietnamese*/ 
#if defined(__MMI_MULTITAP_VIETNAMESE__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_VIETNAMESE, 
#endif
#endif

#if defined(__MMI_IME_VIETNAMESE__)
    IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE, 
    IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE,
#endif
#endif
    /*Xhosa*/ 
#if defined(__MMI_MULTITAP_XHOSA__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_XHOSA, 
#endif
#endif

#if defined(__MMI_IME_XHOSA__)
    IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA, 
    IMM_INPUT_MODE_SMART_UPPERCASE_XHOSA, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_XHOSA,
#endif
#endif
    /*Yoruba*/ 
#if defined(__MMI_MULTITAP_YORUBA__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_YORUBA,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_YORUBA, 
#endif
#endif

#if defined(__MMI_IME_YORUBA__)
    IMM_INPUT_MODE_SMART_LOWERCASE_YORUBA, 
    IMM_INPUT_MODE_SMART_UPPERCASE_YORUBA, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_YORUBA,
#endif
#endif
    /*Zulu*/ 
#if defined(__MMI_MULTITAP_ZULU__)
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU,    
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU,
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ZULU, 
#endif
#endif

#if defined(__MMI_IME_ZULU__)
    IMM_INPUT_MODE_SMART_LOWERCASE_ZULU, 
    IMM_INPUT_MODE_SMART_UPPERCASE_ZULU, 
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ZULU,
#endif
#endif

    /*Arabic*/
#if defined(__MMI_MULTITAP_ARABIC__)
    IMM_INPUT_MODE_MULTITAP_ARABIC, 
    IMM_INPUT_MODE_ARABIC_NUMERIC,
#endif   
#if defined(__MMI_IME_ARABIC__)
    IMM_INPUT_MODE_SMART_ARABIC,
#endif
    /*Assamese*/
#if defined(__MMI_MULTITAP_ASSAMESE__)
    IMM_INPUT_MODE_MULTITAP_ASSAMESE, 
#endif   
#if defined(__MMI_IME_ASSAMESE__)
    IMM_INPUT_MODE_SMART_ASSAMESE,
#endif
    /*Bengali*/
#if defined(__MMI_MULTITAP_BENGALI__)
    IMM_INPUT_MODE_MULTITAP_BENGALI, 
#endif   
#if defined(__MMI_IME_BENGALI__)
    IMM_INPUT_MODE_SMART_BENGALI,
#endif
    /*Georgian*/
#if defined(__MMI_MULTITAP_GEORGIAN__)
    IMM_INPUT_MODE_MULTITAP_GEORGIAN, 
#endif   
#if defined(__MMI_IME_GEORGIAN__)
    IMM_INPUT_MODE_SMART_GEORGIAN,
#endif
    /*Gujarati*/
#if defined(__MMI_MULTITAP_GUJARATI__)
    IMM_INPUT_MODE_MULTITAP_GUJARATI, 
#endif   
#if defined(__MMI_IME_GUJARATI__)
    IMM_INPUT_MODE_SMART_GUJARATI,
#endif
    /*Hebrew*/
#if defined(__MMI_MULTITAP_HEBREW__)
    IMM_INPUT_MODE_MULTITAP_HEBREW, 
#endif   
#if defined(__MMI_IME_HEBREW__)
    IMM_INPUT_MODE_SMART_HEBREW,
#endif
    /*Hindi*/
#if defined(__MMI_MULTITAP_HINDI__)
    IMM_INPUT_MODE_MULTITAP_HINDI, 
#endif   
#if defined(__MMI_IME_HINDI__)
    IMM_INPUT_MODE_SMART_HINDI,
#endif
    /*Kannada*/
#if defined(__MMI_MULTITAP_KANNADA__)
    IMM_INPUT_MODE_MULTITAP_KANNADA, 
#endif   
#if defined(__MMI_IME_KANNADA__)
    IMM_INPUT_MODE_SMART_KANNADA,
#endif
    /*Persian*/
#if defined(__MMI_MULTITAP_PERSIAN__)
    IMM_INPUT_MODE_MULTITAP_PERSIAN, 
#endif   
#if defined(__MMI_IME_PERSIAN__)
    IMM_INPUT_MODE_SMART_PERSIAN,
#endif
    /*Punjabi*/
#if defined(__MMI_MULTITAP_PUNJABI__)
    IMM_INPUT_MODE_MULTITAP_PUNJABI, 
#endif   
#if defined(__MMI_IME_PUNJABI__)
    IMM_INPUT_MODE_SMART_PUNJABI,
#endif
    /*Tamil*/
#if defined(__MMI_MULTITAP_TAMIL__)
    IMM_INPUT_MODE_MULTITAP_TAMIL, 
#endif   
#if defined(__MMI_IME_TAMIL__)
    IMM_INPUT_MODE_SMART_TAMIL,
#endif
    /*Telugu*/
#if defined(__MMI_MULTITAP_TELUGU__)
    IMM_INPUT_MODE_MULTITAP_TELUGU, 
#endif   
#if defined(__MMI_IME_TELUGU__)
    IMM_INPUT_MODE_SMART_TELUGU,
#endif
    /*Thai*/
#if defined(__MMI_MULTITAP_THAI__)
    IMM_INPUT_MODE_MULTITAP_THAI, 
#endif   
#if defined(__MMI_IME_THAI__)
    IMM_INPUT_MODE_SMART_THAI,
#endif
    /*Oriya*/
#if defined(__MMI_MULTITAP_ORIYA__)
    IMM_INPUT_MODE_MULTITAP_ORIYA, 
#endif   
#if defined(__MMI_IME_ORIYA__)
    IMM_INPUT_MODE_SMART_ORIYA,
#endif
    /*Malayalam*/
#if defined(__MMI_MULTITAP_MALAYALAM__)
    IMM_INPUT_MODE_MULTITAP_MALAYALAM, 
#endif   
#if defined(__MMI_MULTITAP_LAO__)
    IMM_INPUT_MODE_MULTITAP_LAO, 
#endif 
#if defined(__MMI_MULTITAP_KHMER__)
    IMM_INPUT_MODE_MULTITAP_KHMER, 
#endif 
#if defined(__MMI_IME_KHMER__) 
    IMM_INPUT_MODE_SMART_KHMER,
#endif
#if defined(__MMI_MULTITAP_MYANMAR__)
    IMM_INPUT_MODE_MULTITAP_MYANMAR, 
#endif 
#if defined(__MMI_IME_MYANMAR__)
    IMM_INPUT_MODE_SMART_MYANMAR, 
#endif 
#if defined(__MMI_IME_MALAYALAM__)
    IMM_INPUT_MODE_SMART_MALAYALAM,
#endif
    /*Marathi*/
#if defined(__MMI_MULTITAP_MARATHI__)
    IMM_INPUT_MODE_MULTITAP_MARATHI, 
#endif   
#if defined(__MMI_IME_MARATHI__)
    IMM_INPUT_MODE_SMART_MARATHI,
#endif
    /*Urdu*/
#if defined(__MMI_MULTITAP_URDU__)
    IMM_INPUT_MODE_MULTITAP_URDU, 
#endif   
#if defined(__MMI_IME_URDU__)
    IMM_INPUT_MODE_SMART_URDU,
#endif
#if defined(__MMI_ZI_UK_ENGLISH__)
    IMM_INPUT_MODE_SMART_UPPERCASE_UK_ABC,
    IMM_INPUT_MODE_SMART_LOWERCASE_UK_ABC,
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UK_ABC,
#endif
#endif /* defined(__MMI_ZI_UK_ENGLISH__)*/ 

#if defined(__MMI_ZI_CA_FRENCH__)
    IMM_INPUT_MODE_SMART_UPPERCASE_CA_FRENCH,
    IMM_INPUT_MODE_SMART_LOWERCASE_CA_FRENCH,
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CA_FRENCH,
#endif
#endif /* defined(__MMI_ZI_CA_FRENCH__)*/ 


#if defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__)
    IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,
    IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH,
#endif
#endif /* defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) */ 

    IMM_INPUT_MODE_MAX_NUM
};

/*****************************************************************************
* Global functions
*****************************************************************************/
extern kal_bool applib_is_valid_url_wchar(kal_wchar ch);

/*****************************************************************************
* Local variables
*****************************************************************************/
/* The current input mode. */
static mmi_imm_input_mode_enum g_mmi_imm_current_input_mode = IMM_INPUT_MODE_NONE;
/* The current input type. */     
static mmi_imm_input_type_enum g_mmi_imm_current_input_type = IMM_INPUT_TYPE_NONE;

static mmi_imm_input_mode_enum *g_mmi_imm_user_specific_input_mode_list = NULL;

static mmi_ime_editor_type_enum g_mmi_imm_editor_type = MMI_IME_EDITOR_TYPE_UNKNOWN;

/* The prefer input mode set by user. */
static mmi_imm_input_mode_enum g_mmi_imm_prefer_input_mode = IMM_INPUT_MODE_MAX_NUM;
/* The default input mode set by AP. Usage: when AP change editor content and discard gui buffer but AP hope the input mode could be recorded. */
static mmi_imm_input_mode_enum g_mmi_imm_default_input_mode = IMM_INPUT_MODE_NONE;
/* The input mode changed by user in Input method option menu. */
static mmi_imm_input_mode_enum g_mmi_imm_user_desired_input_mode = IMM_INPUT_MODE_NONE;

/* The input mode changed by app when app cleared input mode from history. */
static mmi_imm_input_mode_enum g_mmi_imm_app_desired_input_mode = IMM_INPUT_MODE_NONE;

static mmi_imm_input_mode_enum g_mmi_imm_history_input_mode = IMM_INPUT_MODE_NONE;
static const sIMEModeDetails *g_mmi_imm_initial_mode_detail = NULL;

/* The array to record the index of the input mode allowed in current input type. */
/* end with IMM_INPUT_MODE_NONE */
static mmi_imm_input_mode_item g_mmi_imm_curr_allowed_input_mode[IMM_INPUT_MODE_MAX_NUM];
// TODO: should the array size be limited by another define? IMM_INPUT_MODE_MAX_NUM would be increased by langauge porting

static MMI_BOOL g_mmi_imm_is_change_input_mode_enabled = MMI_TRUE;

static MMI_BOOL g_mmi_imm_is_default_init_input_mode_overide = MMI_FALSE;

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
static MMI_BOOL g_mmi_imm_is_smart_alphabetic_input_modes_enalbed = MMI_TRUE;
#endif

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
static mmi_imm_support_writing_lang_enum g_mmi_imm_curr_allowed_writing_lang[IME_WRITING_LANG_TOTAL + 1];
static mmi_imm_support_writing_lang_enum g_mmi_imm_user_desired_writing_lang = IME_WRITING_LANG_NONE;
static mmi_imm_support_writing_lang_enum g_mmi_imm_curr_writing_lang = IME_WRITING_LANG_NONE;
static mmi_imm_support_writing_lang_enum g_mmi_imm_history_writing_lang = IME_WRITING_LANG_NONE;
#endif

#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
static const U16 g_mmi_imm_input_mode_switch_rule_table[MMI_IMM_MAX_INPUT_MODE_SWITCH_RULE_NUM][MMI_IMM_MAX_INPUT_MODE_SWITCH_RULE_ITEM_NUM] = 
{
    {IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_TITLECASE, IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_LOWERCASE, 
    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_UPPERCASE, IME_MODE_ATTR_SMART | IME_MODE_ATTR_TITLECASE,
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_LOWERCASE,    IME_MODE_ATTR_SMART | IME_MODE_ATTR_UPPERCASE, 
    IME_MODE_ATTR_DIRECT, 0},

    {IME_MODE_ATTR_SMART | IME_MODE_ATTR_TITLECASE,    IME_MODE_ATTR_SMART | IME_MODE_ATTR_LOWERCASE, 
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_UPPERCASE,    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_TITLECASE,
    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_LOWERCASE, IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_UPPERCASE, 
    IME_MODE_ATTR_DIRECT, 0},

    {IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_LOWERCASE, IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_TITLECASE, 
    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_UPPERCASE, IME_MODE_ATTR_SMART | IME_MODE_ATTR_LOWERCASE,
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_TITLECASE,    IME_MODE_ATTR_SMART | IME_MODE_ATTR_UPPERCASE, 
    IME_MODE_ATTR_DIRECT, 0},

    {IME_MODE_ATTR_SMART | IME_MODE_ATTR_LOWERCASE,    IME_MODE_ATTR_SMART | IME_MODE_ATTR_TITLECASE, 
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_UPPERCASE,    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_LOWERCASE,
    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_TITLECASE, IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_UPPERCASE, 
    IME_MODE_ATTR_DIRECT, 0},

    {IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_UPPERCASE, IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_LOWERCASE, 
    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_TITLECASE, IME_MODE_ATTR_SMART | IME_MODE_ATTR_UPPERCASE,
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_LOWERCASE,    IME_MODE_ATTR_SMART | IME_MODE_ATTR_TITLECASE, 
    IME_MODE_ATTR_DIRECT, 0},

    {IME_MODE_ATTR_SMART | IME_MODE_ATTR_UPPERCASE,    IME_MODE_ATTR_SMART | IME_MODE_ATTR_LOWERCASE, 
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_TITLECASE,    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_UPPERCASE,
    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_LOWERCASE, IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_TITLECASE, 
    IME_MODE_ATTR_DIRECT, 0},

    {IME_MODE_ATTR_DIRECT,                             IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_LOWERCASE, 
    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_TITLECASE, IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_UPPERCASE, 
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_LOWERCASE,    IME_MODE_ATTR_SMART | IME_MODE_ATTR_TITLECASE,    
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_UPPERCASE,    0},

    {IME_MODE_ATTR_DIRECT,                             IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_LOWERCASE, 
    IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_TITLECASE, IME_MODE_ATTR_MULTITAP | IME_MODE_ATTR_UPPERCASE, 
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_LOWERCASE,    IME_MODE_ATTR_SMART | IME_MODE_ATTR_TITLECASE,    
    IME_MODE_ATTR_SMART | IME_MODE_ATTR_UPPERCASE,    0},

    {0}
};
#endif /* #if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__) */

#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
static mmi_imm_input_mode_enum g_mmi_imm_last_input_mode = IMM_INPUT_MODE_NONE;
#endif


#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
static mmi_imm_support_writing_lang_enum g_mmi_imm_main_writing_lang = IME_WRITING_LANG_ABC;
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */


#if defined(__MMI_MIXED_LANG_SUPPORT__)
static mmi_imm_support_writing_lang_enum g_mmi_imm_sub_writing_lang = IME_WRITING_LANG_NONE;
#endif


#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
mmi_imm_hand_writing_category_info_struct g_mmi_imm_hw_category_table[] =
{
    {IME_WRITING_LANG_ABC, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#if defined(__MMI_LANG_SM_CHINESE__) 
    {IME_WRITING_LANG_ZHCN, IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_ABC_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_TR_CHINESE__)
    {IME_WRITING_LANG_ZHTW, IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_ABC_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_THAI__) 
    {IME_WRITING_LANG_TH, IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_ABC_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_HINDI__) 
    {IME_WRITING_LANG_HI, IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_ABC_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_ARABIC__) 
    {IME_WRITING_LANG_AR, IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_ABC_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_BENGALI__) 
    {IME_WRITING_LANG_BE, IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_ABC_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_SPANISH__) 
    {IME_WRITING_LANG_ES, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_SA_SPANISH__) 
    {IME_WRITING_LANG_ESSA, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_MALAY__) 
    {IME_WRITING_LANG_MS, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_PORTUGUESE__) 
    {IME_WRITING_LANG_PT, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_SA_PORTUGUESE__) 
    {IME_WRITING_LANG_PTBZ, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_RUSSIAN__) 
    {IME_WRITING_LANG_RU, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_TURKISH__) 
    {IME_WRITING_LANG_TR, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_VIETNAMESE__) 
    {IME_WRITING_LANG_VI, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
#if defined(__MMI_LANG_INDONESIAN__) 
    {IME_WRITING_LANG_ID, IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL},
#endif
    {IME_WRITING_LANG_123, IMM_HANDWRITING_TYPE_PUNCTUATION, IMG_ID_VKBD_CUSTOM_ICON_HW_IND_SYMBOL},
    {IME_WRITING_LANG_NONE, 0}
};

#endif/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__*/
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

#if defined(__MMI_IME_USER_DATABASE__)
mmi_imm_new_word_string_mapping_struct g_mmi_imm_new_word_string_mapping_table[] = 
{
    {IME_WRITING_LANG_ABC, {'N', 'e', 'w', ' ', 'w', 'o', 'r', 'd', '\0'}},
#ifdef __MMI_LANG_FRENCH__
    {IME_WRITING_LANG_FR, {0x004E, 0x006F, 0x0075, 0x0076, 0x0065, 0x0061, 0x0075, 0x0020, 0x004D, 0x006F, 0x0074, '\0'}},
#endif
#ifdef __MMI_LANG_SPANISH__
    {IME_WRITING_LANG_ES, {0x0050, 0x0061, 0x006C, 0x0061, 0x0062, 0x0072, 0x0061, 0x0020, 0x004E, 0x0075, 0x0065, 0x0076, 0x0061, '\0'}},
#endif
#ifdef __MMI_LANG_DANISH__
    {IME_WRITING_LANG_DA, {0x004E, 0x0079, 0x0020, 0x004F, 0x0072, 0x0064, '\0'}},
#endif
#ifdef __MMI_LANG_POLISH__
    {IME_WRITING_LANG_PL, {0x004E, 0x006F, 0x0077, 0x0065, 0x0020, 0x0073, 0x0142, 0x006F, 0x0077, 0x006F, '\0'}},
#endif
#ifdef __MMI_LANG_PORTUGUESE__
    {IME_WRITING_LANG_PT, {0x004E, 0x006F, 0x0076, 0x0061, 0x0020, 0x0050, 0x0061, 0x006C, 0x0061, 0x0076, 0x0072, 0x0061, '\0'}},
#endif
#ifdef __MMI_LANG_ITALIAN__
    {IME_WRITING_LANG_IT, {0x0050, 0x0061, 0x0072, 0x006F, 0x006C, 0x0061, 0x0020, 0x004E, 0x0075, 0x006F, 0x0076, 0x0061, '\0'}},
#endif
#ifdef __MMI_LANG_GERMAN__
    {IME_WRITING_LANG_DE, {0x004E, 0x0065, 0x0075, 0x0065, 0x0073, 0x0020, 0x0057, 0x006F, 0x0072, 0x0074, '\0'}},
#endif

#ifdef __MMI_LANG_KOREAN__
    {IME_WRITING_LANG_KR, {0xC0C8, 0xB9D0, '\0'}},
#endif
#ifdef __MMI_LANG_DUTCH__
    {IME_WRITING_LANG_NL, {0x004E, 0x0069, 0x0065, 0x0075, 0x0077, 0x0065, 0x0020, 0x0077, 0x006F, 0x006F, 0x0072, 0x0064, '\0'}},
#endif
#ifdef __MMI_LANG_HUNGARIAN__
    {IME_WRITING_LANG_HU, {0x00DA, 0x006A, 0x0020, 0x0073, 0x007A, 0x00F3, '\0'}},
#endif
#ifdef __MMI_LANG_FINNISH__
    {IME_WRITING_LANG_FI, {0x0055, 0x0075, 0x0073, 0x0069, 0x0020, 0x0073, 0x0061, 0x006E, 0x0061, '\0'}},
#endif
#ifdef __MMI_LANG_GREEK__
    {IME_WRITING_LANG_EL, {0x039D, 0x03AD, 0x03B1, 0x0020, 0x03BB, 0x03AD, 0x03BE, 0x03B7, '\0'}},
#endif 
#ifdef __MMI_LANG_SWAHILI__
    {IME_WRITING_LANG_SW, {'N', 'e', 'n', 'o', ' ', 'm', 'p', 'y', 'a', '\0'}},
#endif 
#ifdef __MMI_LANG_MOLDOVAN__
    {IME_WRITING_LANG_MO, {0x004E, 0x006F, 0x0075, 0x0020, 0x0043, 0x0075, 0x0076, 0x00EE, 0x006E, 0x0074, '\0'}},
#endif 
#ifdef __MMI_LANG_SLOVENIAN__
    {IME_WRITING_LANG_SL, {'N', 'o', 'v', 'a', ' ', 'b', 'e', 's', 'e', 'd', 'a', '\0'}},
#endif 
#ifdef __MMI_LANG_LITHUANIAN__
    {IME_WRITING_LANG_LT, {'N', 'e', 'w', ' ', 'W', 'o', 'r', 'd', '\0'}},
#endif 
#ifdef __MMI_LANG_VIETNAMESE__    
    {IME_WRITING_LANG_VI, {0x0054, 0x1EEB, 0x0020, 0x004D, 0x001EDB, 0x0069, 0x000D, 0x000A, '\0'}},
#endif
#ifdef __MMI_LANG_INDONESIAN__    
    {IME_WRITING_LANG_ID, {0x0042, 0x0061, 0x0072, 0x0075, 0x0020, 0x006B, 0x0061, 0x0074,0x0061, '\0'}},
#endif
#ifdef __MMI_LANG_THAI__       
    {IME_WRITING_LANG_TH, {0x0E04, 0x0E33, 0x0E43, 0x0E2B, 0x0E21, 0x0E48, '\0'}},
#endif
#ifdef __MMI_LANG_MALAY__         
    {IME_WRITING_LANG_MS, {0x0050, 0x0065, 0x0072, 0x006B, 0x0061, 0x0074, 0x0061, 0x0061,0x006E,00020,0x0042,0x0061,0x0072,0X0075, '\0'}},
#endif
#ifdef __MMI_LANG_PERSIAN__         
    {IME_WRITING_LANG_PS, {0x06A9, 0x0644, 0x0645, 0x0647, 0x0020, 0x062C, 0x062F,0x06CC,0x062F, '\0'}},
#endif
#ifdef __MMI_LANG_ARABIC__         
    {IME_WRITING_LANG_AR, {0xFEFF, 0x0643, 0x0644, 0x0645, 0x0629, 0x0020, 0x062C, 0x062F,0x064A,0x062F,0x0629 ,'\0'}},
#endif
#ifdef __MMI_LANG_TURKISH__         
    {IME_WRITING_LANG_TR, {0x0059, 0x0065, 0x006E, 0x0069, 0x0020, 0x006B, 0x0065, 0x006C,0x0069, 0x006D , 0x0065, '\0'}},
#endif
#ifdef __MMI_LANG_RUSSIAN__     
    {IME_WRITING_LANG_RU, {0x041D, 0x043E, 0x0432, 0x043E, 0x0435, 0x0020, 0x0421, 0x043B,0x043E,0x0432,0x043E, '\0'}},
#endif

#ifdef __MMI_LANG_BENGALI__     
    {IME_WRITING_LANG_BE, { 0x09A8, 0x09A4, 0x09C1, 0x09A8, 0x0020, 0x09B6, 0x09AC, 0x09CD, 0x09A6, '\0'}},
#endif

#ifdef __MMI_LANG_BULGARIAN__     
    {IME_WRITING_LANG_BG, { 0x041D, 0x0432, 0x0020, 0x0434, 0x0443, 0x043C, 0x0430, '\0'}},
#endif

#ifdef __MMI_LANG_CZECH__     
    {IME_WRITING_LANG_CS, { 0x004E, 0x006F, 0x0076, 0x00E9, 0x0020, 0x0073, 0x006C, 0x006F, 0x0076, 0x006F, '\0'}},
#endif

#ifdef __MMI_LANG_HEBREW__     
    {IME_WRITING_LANG_HE, { 0x05DE, 0x05D9, 0x05DC, 0x05D4, 0x0020, 0x05D7, 0x05D3, 0x05E9, 0x05D4, '\0'}},
#endif

#ifdef __MMI_LANG_HINDI__     
    {IME_WRITING_LANG_HI, { 0x0928, 0x092F, 0x093E, 0x0020, 0x0936, 0x092C, 0x094D, 0x0926, '\0'}},
#endif

#ifdef __MMI_LANG_ROMANIAN__     
    {IME_WRITING_LANG_RO, { 0x004E, 0x006F, 0x0075, 0x0020, 0x0043, 0x0075, 0x0076, 0x00EE, 0x006E, 0x0074, '\0'}},
#endif

#ifdef __MMI_LANG_SLOVAK__     
    {IME_WRITING_LANG_SK, { 0x004E, 0x006F, 0x0076, 0x00E9, 0x0020, 0x0073, 0x006C, 0x006F, 0x0076, 0x006F, '\0'}},
#endif

#ifdef __MMI_LANG_SWEDISH__     
    {IME_WRITING_LANG_SV, { 0x004E, 0x0079, 0x0074, 0x0074, 0x0020, 0x004F, 0x0072, 0x0064, '\0'}},
#endif

#ifdef __MMI_LANG_UKRAINIAN__     
    {IME_WRITING_LANG_UK, { 0x041D, 0x043E, 0x0432, 0x0435, 0x0020, 0x0421, 0x043B, 0x043E, 0x0432, 0x043E, '\0'}},
#endif
#ifdef __MMI_LANG_SA_SPANISH__
    {IME_WRITING_LANG_ESSA, {0x0050, 0x0061, 0x006C, 0x0061, 0x0062, 0x0072, 0x0061, 0x0020, 0x004E, 0x0075, 0x0065, 0x0076, 0x0061, '\0'}},
#endif
#ifdef __MMI_LANG_SA_PORTUGUESE__
    {IME_WRITING_LANG_PTBZ, {0x004E, 0x006F, 0x0076, 0x0061, 0x0020, 0x0050, 0x0061, 0x006C, 0x0061, 0x0076, 0x0072, 0x0061, '\0'}},
#endif
#ifdef __MMI_LANG_MYANMAR__
{IME_WRITING_LANG_MY, {0x1005 ,0x1000 ,0x102C ,0x1038 ,0x101C ,0x1036 ,0x102F ,0x1038 ,0x1005 ,0x102C ,0x101C ,0x1036 ,0x102F ,0x1038 ,0x1031 ,0x1015 ,0x102B ,0x1004 , '\0'}},
#endif
    {IME_WRITING_LANG_NONE, {'\0'}}
};
#endif

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_numeric[] =
{
#if defined(__MMI_MAINLCD_96X64__)
        {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_CATEGORY_123_IMAGE_ID},
#else
        {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_123_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_NUM},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_LANG_UK_ENGLISH__)

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_uk_abc[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_UK_ABC_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ABC},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_uk_abc[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_uk_abc_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ABC_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_Abc_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_ABC},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_uk_abc[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_UK_Abc_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ABC},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif
#if defined(__MMI_LANG_ENGLISH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_abc[] =
{
#if defined(__MMI_MAINLCD_96X64__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_CATEGORY_ABC_IMAGE_ID},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ABC_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ABC},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_abc[] =
{
#if defined(__MMI_MAINLCD_96X64__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_IMAGE, WGUI_CATEGORY_abc_IMAGE_ID},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_abc_STRING_ID},
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ABC_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_Abc_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_ABC},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_abc[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_Abc_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ABC},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_ENGLISH__ */

#ifdef __MMI_ZI__

#if defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_multitap_pinyin[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_PINYIN},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_ZI_EZITEXT_PINYIN_LOGO},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_PINYIN},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_multitap_bpmf[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_BPMF},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_ZI_EZITEXT_BPMF_LOGO},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_BOPOMO},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_smart_pinyin[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_PINYIN},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_ZI_EZITEXT_PINYIN_LOGO},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_PINYIN},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__) */

#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_smart_bpmf[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_BPMF},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_ZI_EZITEXT_BPMF_LOGO},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_BOPOMO},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__) */

#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__) 
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_tr_stroke[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_TR_STROKE},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_ZI_EZITEXT_TR_STROKE_LOGO},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_TR_STROKE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)  */

#if (defined(__MMI_ZI_HK_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__) ) || (defined(__MMI_T9_HK_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__))
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_hk_stroke[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_TR_STROKE},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_ZI_EZITEXT_HK_STROKE_LOGO},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_HK_STROKE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)  */


#if defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__) 
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_sm_stroke[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_SM_STROKE},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_ZI_EZITEXT_SM_STROKE_LOGO},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_SM_STROKE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)  */


#elif defined(__MMI_T9__) || defined(__MMI_CSTAR__)  || defined(__MMI_GUOBI__)

#if defined(__MMI_T9_HK_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__) 
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_hk_stroke[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_TR_STROKE},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_IME_TR_STROKE_IMG},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_HK_STROKE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_T9_HK_CHINESE__) && defined(__MMI_HK_STROKE_INPUT__)  */

#if (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__))|| (defined(__MMI_GB_SM_CHINESE__))
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_multitap_pinyin[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_PINYIN},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_IME_MULTITAP_PINYIN_IMG},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_PINYIN},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* #if (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__)) */

#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__))|| (defined(__MMI_GB_TR_CHINESE__) && defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__))
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_multitap_bpmf[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_BPMF},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_IME_MULTITAP_BPMF_IMG},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_BOPOMO},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* #if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)) */

#if (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__))|| (defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_SMART_PHONETIC_INPUT__))
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_smart_pinyin[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_PINYIN},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_IME_SMART_PINYIN_IMG},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_PINYIN},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* #if (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)) */


#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)) || (defined(__MMI_GB_TR_CHINESE__) && defined(__MMI_GB_SMART_PHONETIC_INPUT__))
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_smart_bpmf[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_BPMF},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_IME_SMART_BPMF_IMG},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_BOPOMO},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* #if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)) */


#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__)) || (defined(__MMI_GB_TR_CHINESE__) && defined(__MMI_GB_STROKE_INPUT__))
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_tr_stroke[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_TR_STROKE},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_IME_TR_STROKE_IMG},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_TR_STROKE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* #if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__)) */

#if (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__))|| (defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_STROKE_INPUT__))
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_sm_stroke[] =
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, IMG_ID_IME_INDICATOR_SM_STROKE},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_IME_SM_STROKE_IMG},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_SM_STROKE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* #if (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__)) */

#endif

#if defined(__MMI_LANG_ARABIC__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_arabic[] =
{
#if defined(__MMI_MAINLCD_96X64__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_CATEGORY_ARABIC_IMAGE_ID},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ARABIC_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_AR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_arabic_123[] =
{
#if defined(__MMI_MAINLCD_96X64__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_CATEGORY_ARABIC_NUMERIC_IMAGE_ID},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ARABIC_NUMERIC_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_AR_NUM},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_ARABIC__ */

#if defined(__MMI_LANG_BENGALI__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_bengali[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_BENGALI_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_BE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_BENGALI__ */
#if defined(__MMI_LANG_ASSAMESE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_assamese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ASSAMESE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_AS},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_ASSAMESE__ */
#if defined(__MMI_LANG_BULGARIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_bulgarian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_BULGARIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_BG},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_bulgarian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_bulgarian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_BULGARIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_BULGARIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_BG},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_bulgarian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_BULGARIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_BG},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_BULGARIAN__ */

#if defined(__MMI_LANG_CROATIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_croatian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_CROATIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_croatian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_croatian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_CROATIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_CROATIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_croatian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_CROATIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_CROATIAN__ */

#if defined(__MMI_LANG_CZECH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_czech[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_CZECH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_czech[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_czech_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_CZECH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_CZECH_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_czech[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_CZECH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_CZECH__ */

#if defined(__MMI_LANG_DANISH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_danish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_DANISH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_danish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_danish_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_DANISH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_DANISH_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_danish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_DANISH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_DANISH__ */

#if defined(__MMI_MULTITAP_AZERBAIJANI__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_azerbaijani[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_AZERBAIJANI_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_AZ},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_azerbaijani[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_azerbaijani_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_AZERBAIJANI_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_AZERBAIJANI_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_AZ},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_azerbaijani[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_AZERBAIJANI_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_AZ},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_AZERBAIJANI__ */


#if defined(__MMI_MULTITAP_CATALAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_catalan[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_CATALAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_CA},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_catalan[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_catalan_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_CATALAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_CATALAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CA},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},

};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_catalan[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_CATALAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_CA},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_CATALAN__ */


#if defined(__MMI_MULTITAP_KAZAKH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_kazakh[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_KAZAKH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_KK},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_kazakh[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_kazakh_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_KAZAKH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_KAZAKH_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_KK},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_kazakh[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_KAZAKH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_KK},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_KAZAKH__ */

#if defined(__MMI_MULTITAP_HAUSA__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_hausa[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_HAUSA_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_HA},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_hausa[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_hausa_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_HAUSA_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_HAUSA_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_HA},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_hausa[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_HAUSA_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_HA},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_HAUSA__ */

#if defined(__MMI_MULTITAP_GALICIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_galician[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_GALICIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_GL},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_galician[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_galician_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_GALICIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_GALICIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_GL},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_galician[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_GALICIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_GL},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_GALICIAN__ */

#if defined(__MMI_MULTITAP_BASQUE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_basque[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_BASQUE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_EU},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_basque[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_BASQUE_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_BASQUE_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_BASQUE_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_EU},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_basque[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_BASQUE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_EU},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_BASQUE__ */

#if defined(__MMI_MULTITAP_IGBO__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_igbo[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_IGBO_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_IG},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_igbo[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_igbo_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_IGBO_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_IGBO_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_IG},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_igbo[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_IGBO_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_IG},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_IGBO__ */

#if defined(__MMI_MULTITAP_FILIPINO__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_filipino[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FILIPINO_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_FIL},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_filipino[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_filipino_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FILIPINO_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_FILIPINO_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_FIL},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_filipino[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_FILIPINO_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_FIL},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_FILIPINO__ */

#if defined(__MMI_MULTITAP_IRISH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_irish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_IRISH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_IR},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_irish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_irish_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_IRISH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_IRISH_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_IR},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_irish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_IRISH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_IR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_IRISH__ */



#if defined(__MMI_MULTITAP_MACEDONIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_macedonian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_MACEDONIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_MK},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_macedonian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_macedonian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_MACEDONIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_MACEDONIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_MK},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_macedonian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_MACEDONIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_MK},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_MACEDONIAN__ */

#if defined(__MMI_MULTITAP_SESOTHO__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_sesotho[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SESOTHO_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ST},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_sesotho[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_sesotho_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SESOTHO_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SESOTHO_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_ST},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_sesotho[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SESOTHO_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_CA},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_SESOTHO__ */

#if defined(__MMI_MULTITAP_ICELANDIC__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_icelandic[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ICELANDIC_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_IS},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_icelandic[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_icelandic_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ICELANDIC_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ICELANDIC_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_IS},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_icelandic[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ICELANDIC_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_IS},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_ICELANDIC__ */

#if defined(__MMI_MULTITAP_YORUBA__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_yoruba[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_YORUBA_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_YO},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_yoruba[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_yoruba_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_YORUBA_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_YORUBA_STRING_ID},    
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_YO},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_yoruba[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_YORUBA_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_YO},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_YORUBA__ */

#if defined(__MMI_MULTITAP_SERBIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_serbian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SERBIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_SR},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_serbian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_serbian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SERBIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SERBIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_SR},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_serbian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SERBIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_SR},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_SERBIAN__ */

#if defined(__MMI_MULTITAP_TAGALOG__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_tagalog[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_TAGALOG_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_TL},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_tagalog[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_tagalog_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_TAGALOG_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_TAGALOG_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_TL},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},


};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_tagalog[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_TAGALOG_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_TL},
#endif

    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif
#endif /* __MMI_LANG_TAGALOG__ */



#if defined(__MMI_LANG_DUTCH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_dutch[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_DUTCH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_dutch[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_dutch_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_DUTCH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_DUTCH_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_dutch[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_DUTCH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_DUTCH__ */

#if defined(__MMI_LANG_FINNISH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_finnish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FINNISH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_finnish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_finnish_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FINNISH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_FINNISH_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_finnish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_FINNISH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_FINNISH__ */

#if defined(__MMI_MULTITAP_THAI__) || defined(__MMI_ZI_THAI__)  ||  defined (__MMI_T9_THAI__) || defined (__MMI_CSTAR_THAI__) || defined(__MMI_GB_THAI__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_thai[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_thai_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_TH},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_THAI__ */

#if (defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__))&&!defined(__KJX_FUN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_french[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FRENCH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_FR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_french[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_french_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FRENCH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_FRENCH_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_FR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_french[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_FRENCH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_FR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_FRENCH__ */

#if defined(__MMI_LANG_GERMAN__)&&!defined(__KJX_FUN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_german[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_GERMAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_DE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_german[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_german_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_GERMAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_GERMAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_DE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_german[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_GERMAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_DE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_GERMAN__ */

#if defined(__MMI_LANG_KOREAN__)&&(defined(__MMI_MULTITAP_KOREAN__)||defined(__MMI_IME_KOREAN__))&&!defined(__KJX_FUN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_korean[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_KOREAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};


#endif /* __MMI_LANG_KOREAN__ */
#if defined(__MMI_LANG_GREEK__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_greek[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_GREEK_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_greek[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_greek_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_GREEK_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_GREEK_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_greek[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_GREEK_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_GREEK__ */

#if defined(__MMI_LANG_HEBREW__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_hebrew[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_HEBREW_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_HEBREW__ */

#if defined(__MMI_LANG_HINDI__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_hindi[] =
{
#if defined(__MMI_MAINLCD_96X64__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_IMAGE, WGUI_CATEGORY_HINDI_IMAGE_ID},
#else
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_HINDI_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_HI},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_HINDI__ */

#if defined(__MMI_LANG_KANNADA__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_kannada[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_KANNADA_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_KN},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_KANNADA__ */

#if defined(__MMI_LANG_MALAYALAM__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_malayalam[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_MALAYALAM_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_MALAYALAM},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_MALAYALAM__ */

#if defined(__MMI_LANG_LAO__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lao[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_LAO_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_LAO},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_LAO__ */

#if defined(__MMI_LANG_KHMER__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_khmer[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_KHMER_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_KHMER},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_KHMER__ */

#if defined(__MMI_LANG_MYANMAR__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_myanmar[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_MYANMAR_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_MYANMAR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_MYANMAR__ */

#if defined(__MMI_LANG_ORIYA__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_oriya[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ORIYA_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_OR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_ORIYA__ */

#if defined(__MMI_LANG_GUJARATI__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_gujarati[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_GUJARATI_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_GU},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_GUJARATI__ */

#if defined(__MMI_LANG_HUNGARIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_hungarian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_HUNGARIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_hungarian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_hungarian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_HUNGARIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_HUNGARIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_hungarian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_HUNGARIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_HUNGARIAN__ */

#if defined(__MMI_CSTAR_HINGLISH__) || defined(__MMI_GB_HINGLISH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_hinglish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_HINGLISH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_hinglish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_hinglish_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* defined(__MMI_CSTAR_HINGLISH__) || defined(__MMI_GB_HINGLISH__) */

#if defined(__MMI_LANG_INDONESIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_indonesian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_INDONESIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_indonesian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_indonesian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_INDONESIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_INDONESIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_indonesian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_INDONESIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_INDONESIAN__ */

#if defined(__MMI_LANG_ITALIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_italian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ITALIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_IT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_italian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_italian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ITALIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ITALIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_IT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_italian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ITALIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_IT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_ITALIAN__ */

#if defined(__MMI_LANG_MALAY__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_malay[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_MALAY_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ML},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_malay[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_malay_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_MALAY_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_MALAY_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_ML},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_malay[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_MALAY_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ML},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_MALAY__ */

#if defined(__MMI_LANG_MARATHI__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_marathi[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_MARATHI_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_MA},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_MARATHI__ */

#if defined(__MMI_LANG_NORWEGIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_norwegian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_NORWEGIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_norwegian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_norwegian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_NORWEGIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_NORWEGIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_norwegian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_NORWEGIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_NORWEGIAN__ */

#if defined(__MMI_LANG_PERSIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_persian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_PERSIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_PERSIAN__ */

#if defined(__MMI_LANG_POLISH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_polish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_POLISH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_PO},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_polish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_polish_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_POLISH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_POLISH_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_PO},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_polish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_POLISH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_PO},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_POLISH__ */

#if (defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__))&&!defined(__KJX_FUN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_portuguese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_PORTUGUESE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_PT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_portuguese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_portuguese_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_PORTUGUESE_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_PORTUGUESE_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_PT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_portuguese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_PORTUGUESE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_PT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_PORTUGUESE__ */

#if defined(__MMI_LANG_SA_PORTUGUESE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_sa_portuguese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SA_PORTUGUESE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_PT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_sa_portuguese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SA_portuguese_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SA_PORTUGUESE_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SA_PORTUGUESE_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_PT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_sa_portuguese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SA_PORTUGUESE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_PT},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_SA_PORTUGUESE__ */

#if defined(__MMI_LANG_PUNJABI__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_punjabi[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_PUNJABI_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_PU},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_PUNJABI__ */

#if defined(__MMI_LANG_ROMANIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_romanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ROMANIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_romanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_romanian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_ROMANIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ROMANIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_romanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ROMANIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_ROMANIAN__ */

#if defined(__MMI_LANG_RUSSIAN__)&&!defined(__KJX_FUN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_russian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_RUSSIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_RU},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_russian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_russian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_RUSSIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_RUSSIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_RU},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_russian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_RUSSIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_RU},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_RUSSIAN__ */

#if defined(__MMI_LANG_SLOVAK__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_slovak[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SLOVAK_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_slovak[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_slovak_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SLOVAK_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SLOVAK_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_slovak[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SLOVAK_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_SLOVAK__ */

#if defined(__MMI_LANG_SLOVENIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_slovenian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SLOVENIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_slovenian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_slovenian_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SLOVENIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SLOVENIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_slovenian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SLOVENIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_SLOVENIAN__ */

#if (defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__))&&!defined(__KJX_FUN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_spanish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SPANISH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ES},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_spanish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_spanish_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SPANISH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SPANISH_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_ES},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_spanish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SPANISH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_ES},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_SPANISH__ */

#if defined(__MMI_LANG_SWEDISH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_swedish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SWEDISH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_swedish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_swedish_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_SWEDISH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SWEDISH_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_swedish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SWEDISH_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_SWEDISH__ */

#if defined(__MMI_LANG_TAMIL__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_tamil[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_TAMIL_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_TA},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_TAMIL__*/

#if defined(__MMI_LANG_TELUGU__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_telugu[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_TELUGU_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_TE},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_TELUGU__*/

#if defined(__MMI_LANG_TURKISH__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_turkish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_TURKISH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_TR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_turkish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_turkish_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_TURKISH_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_TURKISH_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_TR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_turkish[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_TURKISH_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_TR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_TURKISH__ */

#if defined(__MMI_LANG_UKRAINIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_ukrainian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_UKRAINIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_UK},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_ukrainian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_UKRAINIAN_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_UKRAINIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_UKRAINIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_UK},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_ukrainian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_UKRAINIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_UK},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_UKRAINIAN__ */

#if defined(__MMI_LANG_URDU__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_urdu[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_URDU_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_UR},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_URDU__*/

#if defined(__MMI_LANG_VIETNAMESE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_vietnamese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_VIETNAMESE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_VI},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_vietnamese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_vietnamese_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_VIETNAMESE_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_VIETNAMESE_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_VI},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_vietnamese[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_VIETNAMESE_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && defined(__MMI_MAINLCD_320X480__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_VI},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_VIETNAMESE__ */

#if defined(__MMI_LANG_XHOSA__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_xhosa[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_XHOSA_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_xhosa[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_XHOSA_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_XHOSA_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_XHOSA_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_xhosa[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_XHOSA_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_XHOSA__ */

#if defined(__MMI_LANG_SWAHILI__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_swahili[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_SWAHILI_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_swahili[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_SWAHILI_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_SWAHILI_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SWAHILI_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_swahili[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_SWAHILI_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_SWAHILI__ */

#if defined(__MMI_LANG_AFRIKAANS__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_afrikaans[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_AFRIKAANS_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_afrikaans[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_AFRIKAANS_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_AFRIKAANS_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_AFRIKAANS_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_afrikaans[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_AFRIKAANS_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_AFRIKAANS__ */

#if defined(__MMI_LANG_ZULU__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_zulu[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_ZULU_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_zulu[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_ZULU_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_ZULU_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ZULU_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_zulu[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ZULU_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_ZULU__ */

#if defined(__MMI_LANG_LITHUANIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_lithuanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_LITHUANIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_lithuanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_LITHUANIAN_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_LITHUANIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_LITHUANIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_lithuanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_LITHUANIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_LITHUANIAN__ */

#if defined(__MMI_LANG_LATVIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_latvian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_LATVIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_latvian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_LATVIAN_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_LATVIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_LATVIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_latvian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_LATVIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_LATVIAN__ */

#if defined(__MMI_LANG_ESTONIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_estonian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_ESTONIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_estonian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_ESTONIAN_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_ESTONIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ESTONIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_estonian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ESTONIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_ESTONIAN__ */
#if defined(__MMI_LANG_ALBANIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_albanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_ALBANIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)        
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_SQ},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_albanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_ALBANIAN_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_ALBANIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ALBANIAN_STRING_ID},
#endif
#if defined(__MMI_TOUCH_SCREEN__)  && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)        
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_SQ},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_albanian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ALBANIAN_STRING_ID},
#if defined(__MMI_TOUCH_SCREEN__)  && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)       
    {MMI_IME_HINT_FLAG_VK_ICON, MMI_IME_HINT_TYPE_IMAGE, IMG_VKBD_CUSTOM_IM_ICON_CAP_SQ},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_ALBANIAN__ */

#if defined(__MMI_LANG_ARMENIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_armenian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_ARMENIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_armenian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_ARMENIAN_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_ARMENIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ARMENIAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_armenian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_ARMENIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_ARMENIAN__ */

#if defined(__MMI_LANG_GEORGIAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_georgian[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_GEORGIAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif /* __MMI_LANG_GEORGIAN__ */

#if defined(__MMI_LANG_MOLDOVAN__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_uppercase_moldovan[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_MOLDOVAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

static mmi_imm_input_mode_hint_item_struct g_mmi_imm_lowercase_moldovan[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_LOWER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_L_MOLDOVAN_STRING_ID},
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_U_MOLDOVAN_STRING_ID},
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK | MMI_IME_HINT_FLAG_FIRST_UPPER_CASE, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_MOLDOVAN_STRING_ID},
#endif
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static mmi_imm_input_mode_hint_item_struct g_mmi_imm_first_uppercase_moldovan[] =
{
    {MMI_IME_HINT_FLAG_INFO_BAR | MMI_IME_HINT_FLAG_CSK, MMI_IME_HINT_TYPE_STRING, WGUI_CATEGORY_FIRST_U_MOLDOVAN_STRING_ID},
    {MMI_IME_HINT_FLAG_NONE, MMI_IME_HINT_TYPE_MAX, 0},
};
#endif

#endif /* __MMI_LANG_MOLDOVAN__ */

//TODO: Add compile options
static mmi_imm_input_mode_info_struct g_mmi_imm_hint_info[] =
{
    {IMM_INPUT_MODE_123, g_mmi_imm_numeric},

    {IMM_INPUT_MODE_123_SYMBOLS, g_mmi_imm_numeric},

    {IMM_INPUT_MODE_SIGNED_123, g_mmi_imm_numeric},

    {IMM_INPUT_MODE_FLOAT_123, g_mmi_imm_numeric},

    {IMM_INPUT_MODE_PHONE_NUMBER, g_mmi_imm_numeric},

    {IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR, g_mmi_imm_numeric},

    {IMM_INPUT_MODE_SIM_NUMERIC, g_mmi_imm_numeric},

    {IMM_INPUT_MODE_SIGNED_FLOAT_123, g_mmi_imm_numeric},

    {IMM_INPUT_MODE_KEYPAD_NUMERIC, g_mmi_imm_numeric},

#if defined(__MMI_LANG_ENGLISH__) || defined(__MMI_LANG_UK_ENGLISH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC, g_mmi_imm_uppercase_abc},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC, g_mmi_imm_lowercase_abc},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC, g_mmi_imm_first_uppercase_abc},
#endif

#if defined(__MMI_IME_ENGLISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_ABC, g_mmi_imm_uppercase_abc},
    {IMM_INPUT_MODE_SMART_LOWERCASE_ABC, g_mmi_imm_lowercase_abc},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC, g_mmi_imm_first_uppercase_abc},
#endif
#endif /* defined(__MMI_ZI_PRC_ENGLISH__) || defined(__MMI_T9_ENGLISH__) || defined(__MMI_CSTAR_ENGLISH__) */

#if defined(__MMI_LANG_UK_ENGLISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_UK_ABC, g_mmi_imm_uppercase_uk_abc},
    {IMM_INPUT_MODE_SMART_LOWERCASE_UK_ABC, g_mmi_imm_lowercase_uk_abc},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UK_ABC, g_mmi_imm_first_uppercase_uk_abc},
#endif
#endif /* defined(__MMI_ZI_PRC_ENGLISH__) || defined(__MMI_T9_ENGLISH__) || defined(__MMI_CSTAR_ENGLISH__) */


#endif /* defined(__MMI_LANG_ENGLISH__) || defined(__MMI_LANG_UK_ENGLISH__) */

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) && defined(__MMI_LANG_ENGLISH__) || defined(__MMI_LANG_UK_ENGLISH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC, g_mmi_imm_uppercase_abc},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC, g_mmi_imm_lowercase_abc},
#endif

#if (defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__)) 
    {IMM_INPUT_MODE_SM_MULTITAP_PINYIN, g_mmi_imm_multitap_pinyin},
#endif

#if defined(__MMI_T9_SM_CHINESE__) ||defined(__MMI_ZI_SM_CHINESE__) ||defined(__MMI_ITAP_SM_CHINESE__) ||defined(__MMI_CSTAR_SM_CHINESE__)||defined(__MMI_GB_SM_CHINESE__)
    {IMM_INPUT_MODE_QUICK_SEARCH_PINYIN, g_mmi_imm_multitap_pinyin},
#endif

#if (defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_GB_TR_CHINESE__) && defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__))
    {IMM_INPUT_MODE_TR_MULTITAP_BOPOMO, g_mmi_imm_multitap_bpmf},
    {IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO, g_mmi_imm_multitap_bpmf},
#endif

#if (defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__)) || (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)) || (defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_SMART_PHONETIC_INPUT__))
    {IMM_INPUT_MODE_SM_PINYIN, g_mmi_imm_smart_pinyin},
#endif

#if (defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__)) || (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)) || (defined(__MMI_GB_TR_CHINESE__) && defined(__MMI_GB_SMART_PHONETIC_INPUT__))
    {IMM_INPUT_MODE_TR_BOPOMO, g_mmi_imm_smart_bpmf},
#endif

#if (defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__)) || (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__)) || (defined(__MMI_GB_TR_CHINESE__) && defined(__MMI_GB_STROKE_INPUT__))
    {IMM_INPUT_MODE_TR_STROKE, g_mmi_imm_tr_stroke},
    {IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE, g_mmi_imm_tr_stroke},
#endif

#if (defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__)) || (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__))|| (defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_STROKE_INPUT__))
    {IMM_INPUT_MODE_SM_STROKE, g_mmi_imm_sm_stroke},
    {IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE, g_mmi_imm_sm_stroke},
#endif

#if defined(__MMI_ZI_HK_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__)
    {IMM_INPUT_MODE_HK_STROKE, g_mmi_imm_hk_stroke},
    {IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE, g_mmi_imm_hk_stroke},
#endif

#if defined(__MMI_T9_HK_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)
    {IMM_INPUT_MODE_HK_STROKE, g_mmi_imm_hk_stroke},
    {IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE, g_mmi_imm_hk_stroke},
#endif


#if defined(__MMI_LANG_ARABIC__)
    {IMM_INPUT_MODE_MULTITAP_ARABIC, g_mmi_imm_arabic},

#if defined(__MMI_IME_ARABIC__)
    {IMM_INPUT_MODE_SMART_ARABIC, g_mmi_imm_arabic},
#endif /* #if defined(__MMI_ZI_ARABIC__) || defined(__MMI_T9_ARABIC__) || defined (__MMI_CSTAR_ARABIC__)  */

    {IMM_INPUT_MODE_ARABIC_NUMERIC, g_mmi_imm_arabic_123},

#endif /* #if defined(__MMI_LANG_ARABIC__) */

#if defined(__MMI_LANG_BENGALI__)
    {IMM_INPUT_MODE_MULTITAP_BENGALI, g_mmi_imm_bengali},

#if defined(__MMI_IME_BENGALI__)
    {IMM_INPUT_MODE_SMART_BENGALI, g_mmi_imm_bengali},
#endif /* #if defined(__MMI_ZI_ARABIC__) || defined(__MMI_T9_ARABIC__) || defined (__MMI_CSTAR_ARABIC__)  */

#endif /* #if defined(__MMI_LANG_BENGALI__) */
#if defined(__MMI_LANG_ASSAMESE__)
    {IMM_INPUT_MODE_MULTITAP_ASSAMESE, g_mmi_imm_assamese},

#if defined(__MMI_IME_ASSAMESE__)
    {IMM_INPUT_MODE_SMART_ASSAMESE, g_mmi_imm_assamese},
#endif 

#endif /* #if defined(__MMI_LANG_ASSAMESE__) */
#if defined(__MMI_LANG_BULGARIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN, g_mmi_imm_uppercase_bulgarian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN, g_mmi_imm_lowercase_bulgarian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BULGARIAN, g_mmi_imm_first_uppercase_bulgarian},
#endif

#if defined(__MMI_IME_BULGARIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN, g_mmi_imm_uppercase_bulgarian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN, g_mmi_imm_lowercase_bulgarian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BULGARIAN, g_mmi_imm_first_uppercase_bulgarian},
#endif
#endif /* defined(__MMI_ZI_BULGARIAN__) || defined(__MMI_T9_BULGARIAN__) || defined(__MMI_CSTAR_BULGARIAN__) */

#endif /* #if defined(__MMI_LANG_BULGARIAN__) */

#if defined(__MMI_LANG_CROATIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN, g_mmi_imm_uppercase_croatian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN, g_mmi_imm_lowercase_croatian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CROATIAN, g_mmi_imm_first_uppercase_croatian},
#endif

#if defined(__MMI_IME_CROATIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN, g_mmi_imm_uppercase_croatian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN, g_mmi_imm_lowercase_croatian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CROATIAN, g_mmi_imm_first_uppercase_croatian},
#endif
#endif /* defined(__MMI_ZI_CROATIAN__) || defined(__MMI_T9_CROATIAN__) || defined(__MMI_CSTAR_CROATIAN__) */

#endif /* #if defined(__MMI_LANG_CROATIAN__) */

#if defined(__MMI_LANG_CZECH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH, g_mmi_imm_uppercase_czech},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH, g_mmi_imm_lowercase_czech},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CZECH, g_mmi_imm_first_uppercase_czech},
#endif

#if defined(__MMI_IME_CZECH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_CZECH, g_mmi_imm_uppercase_czech},
    {IMM_INPUT_MODE_SMART_LOWERCASE_CZECH, g_mmi_imm_lowercase_czech},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CZECH, g_mmi_imm_first_uppercase_czech},
#endif
#endif /* defined(__MMI_ZI_CZECH__) || defined(__MMI_T9_CZECH__) || defined(__MMI_CSTAR_CZECH__) */

#endif /* #if defined(__MMI_LANG_CZECH__) */

#if defined(__MMI_MULTITAP_AZERBAIJANI__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_AZERBAIJANI, g_mmi_imm_uppercase_azerbaijani},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI, g_mmi_imm_lowercase_azerbaijani},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AZERBAIJANI, g_mmi_imm_first_uppercase_azerbaijani},
#endif
#endif

#if defined(__MMI_IME_AZERBAIJANI__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_AZERBAIJANI, g_mmi_imm_uppercase_azerbaijani},
    {IMM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI, g_mmi_imm_lowercase_azerbaijani},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AZERBAIJANI, g_mmi_imm_first_uppercase_azerbaijani},
#endif
#endif /* defined(__MMI_ZI_AZERBAIJANI__) || defined(__MMI_T9_AZERBAIJANI__) || defined(__MMI_CSTAR_AZERBAIJANI__) */

#if defined(__MMI_MULTITAP_CATALAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_CATALAN, g_mmi_imm_uppercase_catalan},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN, g_mmi_imm_lowercase_catalan},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CATALAN, g_mmi_imm_first_uppercase_catalan},
#endif
#endif

#if defined(__MMI_IME_CATALAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_CATALAN, g_mmi_imm_uppercase_catalan},
    {IMM_INPUT_MODE_SMART_LOWERCASE_CATALAN, g_mmi_imm_lowercase_catalan},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CATALAN, g_mmi_imm_first_uppercase_catalan},
#endif
#endif /* defined(__MMI_ZI_CATALAN__) || defined(__MMI_T9_CATALAN__) || defined(__MMI_CSTAR_CATALAN__) */

#if defined(__MMI_MULTITAP_HAUSA__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_HAUSA, g_mmi_imm_uppercase_hausa},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA, g_mmi_imm_lowercase_hausa},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HAUSA, g_mmi_imm_first_uppercase_hausa},
#endif
#endif

#if defined(__MMI_IME_HAUSA__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_HAUSA, g_mmi_imm_uppercase_hausa},
    {IMM_INPUT_MODE_SMART_LOWERCASE_HAUSA, g_mmi_imm_lowercase_hausa},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HAUSA, g_mmi_imm_first_uppercase_hausa},
#endif
#endif /* defined(__MMI_ZI_HAUSA__) || defined(__MMI_T9_HAUSA__) || defined(__MMI_CSTAR_HAUSA__) */
#if defined(__MMI_MULTITAP_GALICIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN, g_mmi_imm_uppercase_galician},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN, g_mmi_imm_lowercase_galician},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GALICIAN, g_mmi_imm_first_uppercase_galician},
#endif
#endif

#if defined(__MMI_IME_GALICIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_GALICIAN, g_mmi_imm_uppercase_galician},
    {IMM_INPUT_MODE_SMART_LOWERCASE_GALICIAN, g_mmi_imm_lowercase_galician},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GALICIAN, g_mmi_imm_first_uppercase_galician},
#endif
#endif /* defined(__MMI_ZI_GALICIAN__) || defined(__MMI_T9_GALICIAN__) || defined(__MMI_CSTAR_GALICIAN__) */
#if defined(__MMI_MULTITAP_BASQUE__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE, g_mmi_imm_uppercase_basque},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE, g_mmi_imm_lowercase_basque},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BASQUE, g_mmi_imm_first_uppercase_basque},
#endif
#endif

#if defined(__MMI_IME_BASQUE__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_BASQUE, g_mmi_imm_uppercase_basque},
    {IMM_INPUT_MODE_SMART_LOWERCASE_BASQUE, g_mmi_imm_lowercase_basque},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BASQUE, g_mmi_imm_first_uppercase_basque},
#endif
#endif /* defined(__MMI_ZI_BASQUE__) || defined(__MMI_T9_BASQUE__) || defined(__MMI_CSTAR_BASQUE__) */
#if defined(__MMI_MULTITAP_IGBO__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO, g_mmi_imm_uppercase_igbo},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO, g_mmi_imm_lowercase_igbo},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IGBO, g_mmi_imm_first_uppercase_igbo},
#endif
#endif

#if defined(__MMI_IME_IGBO__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_IGBO, g_mmi_imm_uppercase_igbo},
    {IMM_INPUT_MODE_SMART_LOWERCASE_IGBO, g_mmi_imm_lowercase_igbo},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_IGBO, g_mmi_imm_first_uppercase_igbo},
#endif
#endif /* defined(__MMI_ZI_IGBO__) || defined(__MMI_T9_IGBO__) || defined(__MMI_CSTAR_IGBO__) */
#if defined(__MMI_MULTITAP_FILIPINO__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_FILIPINO, g_mmi_imm_uppercase_filipino},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO, g_mmi_imm_lowercase_filipino},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FILIPINO, g_mmi_imm_first_uppercase_filipino},
#endif
#endif

#if defined(__MMI_IME_FILIPINO__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_FILIPINO, g_mmi_imm_uppercase_filipino},
    {IMM_INPUT_MODE_SMART_LOWERCASE_FILIPINO, g_mmi_imm_lowercase_filipino},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FILIPINO, g_mmi_imm_first_uppercase_filipino},
#endif
#endif /* defined(__MMI_ZI_FILIPINO__) || defined(__MMI_T9_FILIPINO__) || defined(__MMI_CSTAR_FILIPINO__) */
#if defined(__MMI_MULTITAP_IRISH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH, g_mmi_imm_uppercase_irish},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH, g_mmi_imm_lowercase_irish},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IRISH, g_mmi_imm_first_uppercase_irish},
#endif
#endif

#if defined(__MMI_IME_IRISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_IRISH, g_mmi_imm_uppercase_irish},
    {IMM_INPUT_MODE_SMART_LOWERCASE_IRISH, g_mmi_imm_lowercase_irish},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_IRISH, g_mmi_imm_first_uppercase_irish},
#endif
#endif /* defined(__MMI_ZI_IRISH__) || defined(__MMI_T9_IRISH__) || defined(__MMI_CSTAR_IRISH__) */


#if defined(__MMI_MULTITAP_KAZAKH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_KAZAKH, g_mmi_imm_uppercase_kazakh},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH, g_mmi_imm_lowercase_kazakh},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_KAZAKH, g_mmi_imm_first_uppercase_kazakh},
#endif
#endif

#if defined(__MMI_IME_KAZAKH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_KAZAKH, g_mmi_imm_uppercase_kazakh},
    {IMM_INPUT_MODE_SMART_LOWERCASE_KAZAKH, g_mmi_imm_lowercase_kazakh},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_KAZAKH, g_mmi_imm_first_uppercase_kazakh},
#endif
#endif /* defined(__MMI_ZI_KAZAKH__) || defined(__MMI_T9_KAZAKH__) || defined(__MMI_CSTAR_KAZAKH__) */



#if defined(__MMI_MULTITAP_MACEDONIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_MACEDONIAN, g_mmi_imm_uppercase_macedonian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN, g_mmi_imm_lowercase_macedonian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MACEDONIAN, g_mmi_imm_first_uppercase_macedonian},
#endif
#endif

#if defined(__MMI_IME_MACEDONIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_MACEDONIAN, g_mmi_imm_uppercase_macedonian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN, g_mmi_imm_lowercase_macedonian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MACEDONIAN, g_mmi_imm_first_uppercase_macedonian},
#endif
#endif /* defined(__MMI_ZI_MACEDONIAN__) || defined(__MMI_T9_MACEDONIAN__) || defined(__MMI_CSTAR_MACEDONIAN__) */

#if defined(__MMI_MULTITAP_SESOTHO__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_SESOTHO, g_mmi_imm_uppercase_sesotho},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO, g_mmi_imm_lowercase_sesotho},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SESOTHO, g_mmi_imm_first_uppercase_sesotho},
#endif
#endif

#if defined(__MMI_IME_SESOTHO__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SESOTHO, g_mmi_imm_uppercase_sesotho},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SESOTHO, g_mmi_imm_lowercase_sesotho},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SESOTHO, g_mmi_imm_first_uppercase_sesotho},
#endif
#endif /* defined(__MMI_ZI_SESOTHO__) || defined(__MMI_T9_SESOTHO__) || defined(__MMI_CSTAR_SESOTHO__) */

#if defined(__MMI_MULTITAP_TAGALOG__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_TAGALOG, g_mmi_imm_uppercase_tagalog},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG, g_mmi_imm_lowercase_tagalog},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TAGALOG, g_mmi_imm_first_uppercase_tagalog},
#endif
#endif

#if defined(__MMI_IME_TAGALOG__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_TAGALOG, g_mmi_imm_uppercase_tagalog},
    {IMM_INPUT_MODE_SMART_LOWERCASE_TAGALOG, g_mmi_imm_lowercase_tagalog},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TAGALOG, g_mmi_imm_first_uppercase_tagalog},
#endif
#endif /* defined(__MMI_ZI_TAGALOG__) || defined(__MMI_T9_TAGALOG__) || defined(__MMI_CSTAR_TAGALOG__) */

#if defined(__MMI_MULTITAP_ICELANDIC__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ICELANDIC, g_mmi_imm_uppercase_icelandic},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC, g_mmi_imm_lowercase_icelandic},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ICELANDIC, g_mmi_imm_first_uppercase_icelandic},
#endif
#endif

#if defined(__MMI_IME_ICELANDIC__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_ICELANDIC, g_mmi_imm_uppercase_icelandic},
    {IMM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC, g_mmi_imm_lowercase_icelandic},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ICELANDIC, g_mmi_imm_first_uppercase_icelandic},
#endif
#endif /* defined(__MMI_ZI_ICELANDIC__) || defined(__MMI_T9_ICELANDIC__) || defined(__MMI_CSTAR_ICELANDIC__) */

#if defined(__MMI_MULTITAP_SERBIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_SERBIAN, g_mmi_imm_uppercase_serbian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN, g_mmi_imm_lowercase_serbian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SERBIAN, g_mmi_imm_first_uppercase_serbian},
#endif
#endif

#if defined(__MMI_IME_SERBIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SERBIAN, g_mmi_imm_uppercase_serbian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SERBIAN, g_mmi_imm_lowercase_serbian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SERBIAN, g_mmi_imm_first_uppercase_serbian},
#endif
#endif /* defined(__MMI_ZI_SERBIAN__) || defined(__MMI_T9_SERBIAN__) || defined(__MMI_CSTAR_SERBIAN__) */


#if defined(__MMI_MULTITAP_YORUBA__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_YORUBA, g_mmi_imm_uppercase_yoruba},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA, g_mmi_imm_lowercase_yoruba},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_YORUBA, g_mmi_imm_first_uppercase_yoruba},
#endif
#endif

#if defined(__MMI_IME_YORUBA__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_YORUBA, g_mmi_imm_uppercase_yoruba},
    {IMM_INPUT_MODE_SMART_LOWERCASE_YORUBA, g_mmi_imm_lowercase_yoruba},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_YORUBA, g_mmi_imm_first_uppercase_yoruba},
#endif
#endif /* defined(__MMI_ZI_YORUBA__) || defined(__MMI_T9_YORUBA__) || defined(__MMI_CSTAR_YORUBA__) */


#if defined(__MMI_LANG_DANISH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH, g_mmi_imm_uppercase_danish},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH, g_mmi_imm_lowercase_danish},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DANISH, g_mmi_imm_first_uppercase_danish},
#endif

#if defined(__MMI_IME_DANISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_DANISH, g_mmi_imm_uppercase_danish},
    {IMM_INPUT_MODE_SMART_LOWERCASE_DANISH, g_mmi_imm_lowercase_danish},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DANISH, g_mmi_imm_first_uppercase_danish},
#endif
#endif /* defined(__MMI_ZI_DANISH__) || defined(__MMI_T9_DANISH__) || defined(__MMI_CSTAR_DANISH__) */

#endif /* #if defined(__MMI_LANG_DANISH__) */

#if defined(__MMI_LANG_DUTCH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH, g_mmi_imm_uppercase_dutch},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH, g_mmi_imm_lowercase_dutch},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DUTCH, g_mmi_imm_first_uppercase_dutch},
#endif

#if defined(__MMI_IME_DUTCH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH, g_mmi_imm_uppercase_dutch},
    {IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH, g_mmi_imm_lowercase_dutch},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DUTCH, g_mmi_imm_first_uppercase_dutch},
#endif
#endif /* defined(__MMI_ZI_DUTCH__) || defined(__MMI_T9_DUTCH__) || defined(__MMI_CSTAR_DUTCH__) */

#endif /* #if defined(__MMI_LANG_DUTCH__) */

#if defined(__MMI_LANG_FINNISH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH, g_mmi_imm_uppercase_finnish},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH, g_mmi_imm_lowercase_finnish},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FINNISH, g_mmi_imm_first_uppercase_finnish},
#endif

#if defined(__MMI_IME_FINNISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH, g_mmi_imm_uppercase_finnish},
    {IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH, g_mmi_imm_lowercase_finnish},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FINNISH, g_mmi_imm_first_uppercase_finnish},
#endif
#endif /* defined(__MMI_ZI_FINNISH__) || defined(__MMI_T9_FINNISH__) || defined(__MMI_CSTAR_FINNISH__) */

#endif /* #if defined(__MMI_LANG_FINNISH__) */

#if defined(__MMI_MULTITAP_THAI__) || defined(__MMI_ZI_THAI__)  ||  defined (__MMI_T9_THAI__) || defined (__MMI_CSTAR_THAI__) || defined(__MMI_GB_THAI__)
    {IMM_INPUT_MODE_MULTITAP_THAI, g_mmi_imm_thai},

#if defined(__MMI_IME_THAI__)
    {IMM_INPUT_MODE_SMART_THAI, g_mmi_imm_thai},
#endif /* defined(__MMI_ZI_THAI__) || defined(__MMI_T9_THAI__) || defined(__MMI_CSTAR_THAI__) */

#endif /* #if defined(__MMI_LANG_THAI__) */

#if (defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__))&&!defined(__KJX_FUN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH, g_mmi_imm_uppercase_french},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH, g_mmi_imm_lowercase_french},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FRENCH, g_mmi_imm_first_uppercase_french},
#endif

#if defined(__MMI_IME_FRENCH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH, g_mmi_imm_uppercase_french},
    {IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH, g_mmi_imm_lowercase_french},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH, g_mmi_imm_first_uppercase_french},
#endif
#endif /* defined(__MMI_ZI_EU_FRENCH__) || defined(__MMI_T9_FRENCH__) || defined(__MMI_CSTAR_FRENCH__) */

#if defined(__MMI_ZI_CA_FRENCH__) 
    {IMM_INPUT_MODE_SMART_UPPERCASE_CA_FRENCH, g_mmi_imm_uppercase_french},
    {IMM_INPUT_MODE_SMART_LOWERCASE_CA_FRENCH, g_mmi_imm_lowercase_french},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CA_FRENCH, g_mmi_imm_first_uppercase_french},
#endif
#endif /* defined(__MMI_ZI_CA_FRENCH__) */


#endif /* #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__) */

#if defined(__MMI_LANG_GERMAN__)&&!defined(__KJX_FUN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN, g_mmi_imm_uppercase_german},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN, g_mmi_imm_lowercase_german},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GERMAN, g_mmi_imm_first_uppercase_german},
#endif

#if defined(__MMI_LANG_KOREAN__)&&(defined(__MMI_MULTITAP_KOREAN__)||defined(__MMI_IME_KOREAN__))
    {IMM_INPUT_MODE_MULTITAP_KOREAN, g_mmi_imm_korean},

#endif /* #if defined(__MMI_LANG_KOREAN__) */
#if defined(__MMI_IME_GERMAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN, g_mmi_imm_uppercase_german},
    {IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN, g_mmi_imm_lowercase_german},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GERMAN, g_mmi_imm_first_uppercase_german},
#endif
#endif /* defined(__MMI_ZI_GERMAN__) || defined(__MMI_T9_GERMAN__) || defined(__MMI_CSTAR_GERMAN__) */

#endif /* #if defined(__MMI_LANG_GERMAN__) */

#if defined(__MMI_LANG_GREEK__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK, g_mmi_imm_uppercase_greek},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK, g_mmi_imm_lowercase_greek},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GREEK, g_mmi_imm_first_uppercase_greek},
#endif

#if defined(__MMI_IME_GREEK__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_GREEK, g_mmi_imm_uppercase_greek},
    {IMM_INPUT_MODE_SMART_LOWERCASE_GREEK, g_mmi_imm_lowercase_greek},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GREEK, g_mmi_imm_first_uppercase_greek},
#endif
#endif /* defined(__MMI_ZI_GREEK__) || defined(__MMI_T9_GREEK__) || defined(__MMI_CSTAR_GREEK__) */

#endif /* #if defined(__MMI_LANG_GREEK__) */

#if defined(__MMI_LANG_HEBREW__)
    {IMM_INPUT_MODE_MULTITAP_HEBREW, g_mmi_imm_hebrew},

#if defined(__MMI_IME_HEBREW__)
    {IMM_INPUT_MODE_SMART_HEBREW, g_mmi_imm_hebrew},
#endif /* defined(__MMI_ZI_HEBREW__) || defined(__MMI_T9_HEBREW__) || defined(__MMI_CSTAR_HEBREW__) */

#endif /* #if defined(__MMI_LANG_HEBREW__) */

#if defined(__MMI_LANG_HINDI__)
    {IMM_INPUT_MODE_MULTITAP_HINDI, g_mmi_imm_hindi},

#if defined(__MMI_IME_HINDI__)
    {IMM_INPUT_MODE_SMART_HINDI, g_mmi_imm_hindi},
#endif /* defined(__MMI_ZI_HINDI__) || defined(__MMI_T9_HINDI__) || defined(__MMI_CSTAR_HINDI__) */

#endif /* #if defined(__MMI_LANG_HINDI__) */

#if defined(__MMI_CSTAR_HINGLISH__) || defined(__MMI_GB_HINGLISH__)
    {IMM_INPUT_MODE_SMART_LOWERCASE_HINGLISH, g_mmi_imm_lowercase_hinglish},
    {IMM_INPUT_MODE_SMART_UPPERCASE_HINGLISH, g_mmi_imm_uppercase_hinglish},
#endif/* #if defined(__MMI_CSTAR_HINGLISH__) || defined(__MMI_GB_HINGLISH__) */

#if defined(__MMI_LANG_KANNADA__)
    {IMM_INPUT_MODE_MULTITAP_KANNADA, g_mmi_imm_kannada},

#if defined(__MMI_IME_KANNADA__)
    {IMM_INPUT_MODE_SMART_KANNADA, g_mmi_imm_kannada},
#endif /* defined(__MMI_ZI_KANNADA__) || defined(__MMI_T9_KANNADA__) || defined(__MMI_CSTAR_KANNADA__) */

#endif /* defined(__MMI_LANG_KANNADA__) */

#if defined(__MMI_LANG_MALAYALAM__)
    {IMM_INPUT_MODE_MULTITAP_MALAYALAM, g_mmi_imm_malayalam},

#if defined(__MMI_IME_MALAYALAM__)
    {IMM_INPUT_MODE_SMART_MALAYALAM, g_mmi_imm_malayalam},
#endif /* defined(__MMI_ZI_MALAYALAM__) || defined(__MMI_T9_MALAYALAM__) || defined(__MMI_CSTAR_MALAYALAM__) */

#endif /* #if defined(__MMI_LANG_MALAYALAM__) */
#if defined(__MMI_LANG_LAO__)
    {IMM_INPUT_MODE_MULTITAP_LAO, g_mmi_imm_lao},

#if defined(__MMI_IME_LAO__)
    {IMM_INPUT_MODE_SMART_LAO, g_mmi_imm_lao},
#endif /* defined(__MMI_ZI_LAO__) || defined(__MMI_T9_LAO__) || defined(__MMI_CSTAR_LAO__) */

#endif /* #if defined(__MMI_LANG_LAO__) */
#if defined(__MMI_LANG_KHMER__)
    {IMM_INPUT_MODE_MULTITAP_KHMER, g_mmi_imm_khmer},

#if defined(__MMI_IME_KHMER__)
    {IMM_INPUT_MODE_SMART_KHMER, g_mmi_imm_khmer},
#endif /* defined(__MMI_ZI_KHMER__) || defined(__MMI_T9_KHMER__) || defined(__MMI_CSTAR_KHMER__) */

#endif /* #if defined(__MMI_LANG_KHMER__) */
#if defined(__MMI_LANG_MYANMAR__)
    {IMM_INPUT_MODE_MULTITAP_MYANMAR, g_mmi_imm_myanmar},

#if defined(__MMI_IME_MYANMAR__)
    {IMM_INPUT_MODE_SMART_MYANMAR, g_mmi_imm_myanmar},
#endif /* defined(__MMI_ZI_MYANMAR__) || defined(__MMI_T9_MYANMAR__) || defined(__MMI_CSTAR_MYANMAR__) */

#endif /* #if defined(__MMI_LANG_MYANMAR__) */
#if defined(__MMI_LANG_ORIYA__)
    {IMM_INPUT_MODE_MULTITAP_ORIYA, g_mmi_imm_oriya},

#if defined(__MMI_IME_ORIYA__)
    {IMM_INPUT_MODE_SMART_ORIYA, g_mmi_imm_oriya},
#endif /* defined(__MMI_ZI_ORIYA__) || defined(__MMI_T9_ORIYA__) || defined(__MMI_CSTAR_ORIYA__) */

#endif /* #if defined(__MMI_LANG_ORIYA__) */

#if defined(__MMI_LANG_GUJARATI__)
    {IMM_INPUT_MODE_MULTITAP_GUJARATI, g_mmi_imm_gujarati},

#if defined(__MMI_IME_GUJARATI__)
    {IMM_INPUT_MODE_SMART_GUJARATI, g_mmi_imm_gujarati},
#endif /* defined(__MMI_ZI_GUJARATI__) || defined(__MMI_T9_GUJARATI__) || defined(__MMI_CSTAR_GUJARATI__) */

#endif /* #if defined(__MMI_LANG_GUJARATI__) */

#if defined(__MMI_LANG_HUNGARIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN, g_mmi_imm_uppercase_hungarian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN, g_mmi_imm_lowercase_hungarian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HUNGARIAN, g_mmi_imm_first_uppercase_hungarian},
#endif

#if defined(__MMI_IME_HUNGARIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN, g_mmi_imm_uppercase_hungarian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN, g_mmi_imm_lowercase_hungarian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HUNGARIAN, g_mmi_imm_first_uppercase_hungarian},
#endif
#endif /* defined(__MMI_ZI_HUNGARIAN__) || defined(__MMI_T9_HUNGARIAN__) || defined(__MMI_CSTAR_HUNGARIAN__) */

#endif /* #if defined(__MMI_LANG_HUNGARIAN__) */

#if defined(__MMI_LANG_INDONESIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN, g_mmi_imm_uppercase_indonesian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN, g_mmi_imm_lowercase_indonesian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN, g_mmi_imm_first_uppercase_indonesian},
#endif

#if defined(__MMI_IME_INDONESIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN, g_mmi_imm_uppercase_indonesian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN, g_mmi_imm_lowercase_indonesian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN, g_mmi_imm_first_uppercase_indonesian},
#endif
#endif /* defined(__MMI_ZI_INDONESIAN__) || defined(__MMI_T9_INDONESIAN__) || defined(__MMI_CSTAR_INDONESIAN__) */

#endif /* #if defined(__MMI_LANG_INDONESIAN__) */

#if defined(__MMI_LANG_ITALIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN, g_mmi_imm_uppercase_italian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN, g_mmi_imm_lowercase_italian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ITALIAN, g_mmi_imm_first_uppercase_italian},
#endif

#if defined(__MMI_IME_ITALIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN, g_mmi_imm_uppercase_italian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN, g_mmi_imm_lowercase_italian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ITALIAN, g_mmi_imm_first_uppercase_italian},
#endif
#endif /* defined(__MMI_ZI_ITALIAN__) || defined(__MMI_T9_ITALIAN__) || defined(__MMI_CSTAR_ITALIAN__) */

#endif /* #if defined(__MMI_LANG_ITALIAN__) */

#if defined(__MMI_LANG_MALAY__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY, g_mmi_imm_uppercase_malay},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY, g_mmi_imm_lowercase_malay},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY, g_mmi_imm_first_uppercase_malay},
#endif

#if defined(__MMI_IME_MALAY__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_MALAY, g_mmi_imm_uppercase_malay},
    {IMM_INPUT_MODE_SMART_LOWERCASE_MALAY, g_mmi_imm_lowercase_malay},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY, g_mmi_imm_first_uppercase_malay},
#endif
#endif /* defined(__MMI_ZI_MALAY__) || defined(__MMI_T9_MALAY__) || defined(__MMI_CSTAR_MALAY__) */

#endif /* #if defined(__MMI_LANG_MALAY__) */

#if defined(__MMI_LANG_MARATHI__)
    {IMM_INPUT_MODE_MULTITAP_MARATHI, g_mmi_imm_marathi},

#if defined(__MMI_IME_MARATHI__)
    {IMM_INPUT_MODE_SMART_MARATHI, g_mmi_imm_marathi},
#endif /* defined(__MMI_ZI_MARATHI__) || defined(__MMI_T9_MARATHI__) || defined(__MMI_CSTAR_MARATHI__) */

#endif /* #if defined(__MMI_LANG_MARATHI__) */

#if defined(__MMI_LANG_NORWEGIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN, g_mmi_imm_uppercase_norwegian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN, g_mmi_imm_lowercase_norwegian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_NORWEGIAN, g_mmi_imm_first_uppercase_norwegian},
#endif

#if defined(__MMI_IME_NORWEGIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN, g_mmi_imm_uppercase_norwegian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN, g_mmi_imm_lowercase_norwegian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_NORWEGIAN, g_mmi_imm_first_uppercase_norwegian},
#endif
#endif /* defined(__MMI_ZI_NORWEGIAN__) || defined(__MMI_T9_NORWEGIAN__) || defined(__MMI_CSTAR_NORWEGIANY__) */

#endif /* #if defined(__MMI_LANG_NORWEGIAN__) */

#if defined(__MMI_LANG_PERSIAN__)
    {IMM_INPUT_MODE_MULTITAP_PERSIAN, g_mmi_imm_persian},

#if defined(__MMI_IME_PERSIAN__)
    {IMM_INPUT_MODE_SMART_PERSIAN, g_mmi_imm_persian},
#endif /* defined(__MMI_ZI_PERSIAN__) || defined(__MMI_T9_PERSIAN__) || defined(__MMI_CSTAR_PERSIAN__) */

#endif /* #if defined(__MMI_LANG_PERSIAN__) */

#if defined(__MMI_LANG_POLISH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH, g_mmi_imm_uppercase_polish},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH, g_mmi_imm_lowercase_polish},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_POLISH, g_mmi_imm_first_uppercase_polish},
#endif

#if defined(__MMI_IME_POLISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_POLISH, g_mmi_imm_uppercase_polish},
    {IMM_INPUT_MODE_SMART_LOWERCASE_POLISH, g_mmi_imm_lowercase_polish},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_POLISH, g_mmi_imm_first_uppercase_polish},
#endif
#endif /* defined(__MMI_ZI_POLISH__) || defined(__MMI_T9_POLISH__) || defined(__MMI_CSTAR_POLISH__) */

#endif /* #if defined(__MMI_LANG_POLISH__) */

#if (defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__))&&!defined(__KJX_FUN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE, g_mmi_imm_uppercase_portuguese},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE, g_mmi_imm_lowercase_portuguese},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE, g_mmi_imm_first_uppercase_portuguese},
#endif

#if defined(__MMI_IME_PORTUGUESE__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE, g_mmi_imm_uppercase_portuguese},
    {IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE, g_mmi_imm_lowercase_portuguese},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE, g_mmi_imm_first_uppercase_portuguese},
#endif
#endif /* defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_T9_PORTUGUESE__) || defined(__MMI_CSTAR_PORTUGUESE__) */

#if defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_GB_SA_PORTUGUESE__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SA_PORTUGUESE, g_mmi_imm_uppercase_sa_portuguese},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE, g_mmi_imm_lowercase_sa_portuguese},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_PORTUGUESE, g_mmi_imm_first_uppercase_sa_portuguese},
#endif
#endif /* defined(__MMI_ZI_SA_PORTUGUESE__) */

#endif /* #if defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__) */

#if defined(__MMI_LANG_PUNJABI__)
    {IMM_INPUT_MODE_MULTITAP_PUNJABI, g_mmi_imm_punjabi},

#if defined(__MMI_IME_PUNJABI__)
    {IMM_INPUT_MODE_SMART_PUNJABI, g_mmi_imm_punjabi},
#endif /* defined(__MMI_ZI_PUNJABI__) || defined(__MMI_T9_PUNJABI__) || defined(__MMI_CSTAR_PUNJABI__) */

#endif /* #if defined(__MMI_LANG_PUNJABI__) */

#if defined(__MMI_LANG_ROMANIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN, g_mmi_imm_uppercase_romanian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN, g_mmi_imm_lowercase_romanian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ROMANIAN, g_mmi_imm_first_uppercase_romanian},
#endif

#if defined(__MMI_IME_ROMANIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN, g_mmi_imm_uppercase_romanian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN, g_mmi_imm_lowercase_romanian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ROMANIAN, g_mmi_imm_first_uppercase_romanian},
#endif
#endif /* defined(__MMI_ZI_ROMANIAN__) || defined(__MMI_T9_ROMANIAN__) || defined(__MMI_CSTAR_ROMANIAN__) */

#endif /* #if defined(__MMI_LANG_ROMANIAN__) */

#if defined(__MMI_LANG_RUSSIAN__)&&!defined(__KJX_FUN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN, g_mmi_imm_uppercase_russian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN, g_mmi_imm_lowercase_russian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN, g_mmi_imm_first_uppercase_russian},
#endif

#if defined(__MMI_IME_RUSSIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN, g_mmi_imm_uppercase_russian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN, g_mmi_imm_lowercase_russian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN, g_mmi_imm_first_uppercase_russian},
#endif
#endif /* defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_T9_RUSSIAN__) || defined(__MMI_CSTAR_RUSSIAN__) */

#endif /* #if defined(__MMI_LANG_RUSSIAN__) */

#if defined(__MMI_LANG_SLOVAK__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK, g_mmi_imm_uppercase_slovak},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK, g_mmi_imm_lowercase_slovak},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVAK, g_mmi_imm_first_uppercase_slovak},
#endif

#if defined(__MMI_IME_SLOVAK__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK, g_mmi_imm_uppercase_slovak},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK, g_mmi_imm_lowercase_slovak},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVAK, g_mmi_imm_first_uppercase_slovak},
#endif
#endif /* defined(__MMI_ZI_SLOVAK__) || defined(__MMI_T9_SLOVAK__) || defined(__MMI_CSTAR_SLOVAK__) */

#endif /* #if defined(__MMI_LANG_SLOVAK__) */

#if defined(__MMI_LANG_SLOVENIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN, g_mmi_imm_uppercase_slovenian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN, g_mmi_imm_lowercase_slovenian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVENIAN, g_mmi_imm_first_uppercase_slovenian},
#endif

#if defined(__MMI_IME_SLOVENIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN, g_mmi_imm_uppercase_slovenian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN, g_mmi_imm_lowercase_slovenian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVENIAN, g_mmi_imm_first_uppercase_slovenian},
#endif
#endif /* defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_T9_SLOVENIAN__) || defined(__MMI_CSTAR_SLOVENIAN__) */

#endif /* #if defined(__MMI_LANG_SLOVENIAN__) */

#if (defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__))&&!defined(__KJX_FUN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH, g_mmi_imm_uppercase_spanish},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH, g_mmi_imm_lowercase_spanish},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH, g_mmi_imm_first_uppercase_spanish},
#endif

#if defined(__MMI_IME_SPANISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH, g_mmi_imm_uppercase_spanish},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH, g_mmi_imm_lowercase_spanish},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH, g_mmi_imm_first_uppercase_spanish},
#endif
#endif /* defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_T9_SPANISH__) || defined(__MMI_CSTAR_SPANISH__) */

#if defined(__MMI_ZI_SA_SPANISH__) || defined(__MMI_T9_SPANISH__) || defined(__MMI_CSTAR_SPANISH__)||defined(__MMI_GB_SA_SPANISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SA_SPANISH, g_mmi_imm_uppercase_spanish},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH, g_mmi_imm_lowercase_spanish},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_SPANISH, g_mmi_imm_first_uppercase_spanish},
#endif
#endif /* defined(__MMI_ZI_SA_SPANISH__) || defined(__MMI_T9_SPANISH__) || defined(__MMI_CSTAR_SPANISH__) */

#endif /* #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__) */

#if defined(__MMI_LANG_SWEDISH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH, g_mmi_imm_uppercase_swedish},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH, g_mmi_imm_lowercase_swedish},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWEDISH, g_mmi_imm_first_uppercase_swedish},
#endif

#if defined(__MMI_IME_SWEDISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH, g_mmi_imm_uppercase_swedish},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH, g_mmi_imm_lowercase_swedish},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWEDISH, g_mmi_imm_first_uppercase_swedish},
#endif
#endif /* defined(__MMI_ZI_SWEDISH__) || defined(__MMI_T9_SWEDISH__) || defined(__MMI_CSTAR_SWEDISH__) */

#endif /* #if defined(__MMI_LANG_SWEDISH__) */

#if defined(__MMI_LANG_TAMIL__)
    {IMM_INPUT_MODE_MULTITAP_TAMIL, g_mmi_imm_tamil},

#if defined(__MMI_IME_TAMIL__)
    {IMM_INPUT_MODE_SMART_TAMIL, g_mmi_imm_tamil},
#endif /* defined(__MMI_ZI_TAMIL__) || defined(__MMI_T9_TAMIL__) || defined(__MMI_CSTAR_TAMIL__) */

#endif /* #if defined(__MMI_LANG_TAMIL__) */

#if defined(__MMI_LANG_TELUGU__)
    {IMM_INPUT_MODE_MULTITAP_TELUGU, g_mmi_imm_telugu},

#if defined(__MMI_IME_TELUGU__)
    {IMM_INPUT_MODE_SMART_TELUGU, g_mmi_imm_telugu},
#endif /* defined(__MMI_ZI_TELUGU__) || defined(__MMI_T9_TELUGU__) || defined(__MMI_CSTAR_TELUGUL__) */

#endif /* #if defined(__MMI_LANG_TELUGU__) */

#if defined(__MMI_LANG_TURKISH__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH, g_mmi_imm_uppercase_turkish},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH, g_mmi_imm_lowercase_turkish},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH, g_mmi_imm_first_uppercase_turkish},
#endif

#if defined(__MMI_IME_TURKISH__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH, g_mmi_imm_uppercase_turkish},
    {IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH, g_mmi_imm_lowercase_turkish},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH, g_mmi_imm_first_uppercase_turkish},
#endif
#endif /* defined(__MMI_ZI_TURKISH__) || defined(__MMI_T9_TURKISH__) || defined(__MMI_CSTAR_TURKISH__) */

#endif /* #if defined(__MMI_LANG_TURKISH__) */

#if defined(__MMI_LANG_UKRAINIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN, g_mmi_imm_uppercase_ukrainian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN, g_mmi_imm_lowercase_ukrainian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_UKRAINIAN, g_mmi_imm_first_uppercase_ukrainian},
#endif

#if defined(__MMI_IME_UKRAINIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN, g_mmi_imm_uppercase_ukrainian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN, g_mmi_imm_lowercase_ukrainian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UKRAINIAN, g_mmi_imm_first_uppercase_ukrainian},
#endif
#endif /* defined(__MMI_ZI_UKRAINIAN__) || defined(__MMI_T9_UKRAINIAN__) || defined(__MMI_CSTAR_UKRAINIAN__) */

#endif /* #if defined(__MMI_LANG_UKRAINIAN__) */

#if defined(__MMI_LANG_URDU__)
    {IMM_INPUT_MODE_MULTITAP_URDU, g_mmi_imm_urdu},

#if defined(__MMI_IME_URDU__)
    {IMM_INPUT_MODE_SMART_URDU, g_mmi_imm_urdu},
#endif /* defined(__MMI_ZI_URDU__) || defined(__MMI_T9_URDU__) || defined(__MMI_CSTAR_URDU__) */

#endif /* #if defined(__MMI_LANG_URDU__) */

#if defined(__MMI_LANG_VIETNAMESE__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE, g_mmi_imm_uppercase_vietnamese},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE, g_mmi_imm_lowercase_vietnamese},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_VIETNAMESE, g_mmi_imm_first_uppercase_vietnamese},
#endif

#if defined(__MMI_IME_VIETNAMESE__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE, g_mmi_imm_uppercase_vietnamese},
    {IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE, g_mmi_imm_lowercase_vietnamese},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE, g_mmi_imm_first_uppercase_vietnamese},
#endif
#endif /* defined(__MMI_ZI_VIETNAMESE__) || defined(__MMI_T9_VIETNAMESE__) || defined(__MMI_CSTAR_VIETNAMESE__) */

#endif /* #if defined(__MMI_LANG_VIETNAMESE__) */

#if defined(__MMI_LANG_XHOSA__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA, g_mmi_imm_uppercase_xhosa},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA, g_mmi_imm_lowercase_xhosa},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_XHOSA, g_mmi_imm_first_uppercase_xhosa},
#endif

#if defined(__MMI_IME_XHOSA__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_XHOSA, g_mmi_imm_uppercase_xhosa},
    {IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA, g_mmi_imm_lowercase_xhosa},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_XHOSA, g_mmi_imm_first_uppercase_xhosa},
#endif
#endif /* defined(__MMI_ZI_XHOSA__) || defined(__MMI_T9_XHOSA__) || defined(__MMI_CSTAR_XHOSA__) */

#endif /* #if defined(__MMI_LANG_XHOSA__) */

#if defined(__MMI_LANG_SWAHILI__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI, g_mmi_imm_uppercase_swahili},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI, g_mmi_imm_lowercase_swahili},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWAHILI, g_mmi_imm_first_uppercase_swahili},
#endif

#if defined(__MMI_IME_SWAHILI__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI, g_mmi_imm_uppercase_swahili},
    {IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI, g_mmi_imm_lowercase_swahili},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWAHILI, g_mmi_imm_first_uppercase_swahili},
#endif
#endif /* defined(__MMI_ZI_SWAHILI__) || defined(__MMI_T9_SWAHILI__) || defined(__MMI_CSTAR_SWAHILI__) */

#endif /* #if defined(__MMI_LANG_SWAHILI__) */

#if defined(__MMI_LANG_AFRIKAANS__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS, g_mmi_imm_uppercase_afrikaans},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS, g_mmi_imm_lowercase_afrikaans},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AFRIKAANS, g_mmi_imm_first_uppercase_afrikaans},
#endif

#if defined(__MMI_IME_AFRIKAANS__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS, g_mmi_imm_uppercase_afrikaans},
    {IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS, g_mmi_imm_lowercase_afrikaans},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AFRIKAANS, g_mmi_imm_first_uppercase_afrikaans},
#endif
#endif /* defined(__MMI_ZI_AFRIKAANS__) || defined(__MMI_T9_AFRIKAANS__) || defined(__MMI_CSTAR_AFRIKAANS__) */

#endif /* #if defined(__MMI_LANG_AFRIKAANS__) */

#if defined(__MMI_LANG_ZULU__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU, g_mmi_imm_uppercase_zulu},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU, g_mmi_imm_lowercase_zulu},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ZULU, g_mmi_imm_first_uppercase_zulu},
#endif

#if defined(__MMI_IME_ZULU__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_ZULU, g_mmi_imm_uppercase_zulu},
    {IMM_INPUT_MODE_SMART_LOWERCASE_ZULU, g_mmi_imm_lowercase_zulu},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ZULU, g_mmi_imm_first_uppercase_zulu},
#endif
#endif /* defined(__MMI_ZI_ZULU__) || defined(__MMI_T9_ZULU__) || defined(__MMI_CSTAR_ZULU__) */

#endif /* #if defined(__MMI_LANG_ZULU__) */

#if defined(__MMI_LANG_LITHUANIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN, g_mmi_imm_uppercase_lithuanian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN, g_mmi_imm_lowercase_lithuanian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LITHUANIAN, g_mmi_imm_first_uppercase_lithuanian},
#endif

#if defined(__MMI_IME_LITHUANIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN, g_mmi_imm_uppercase_lithuanian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN, g_mmi_imm_lowercase_lithuanian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LITHUANIAN, g_mmi_imm_first_uppercase_lithuanian},
#endif
#endif /* defined(__MMI_ZI_LITHUANIAN__) || defined(__MMI_T9_LITHUANIAN__) || defined(__MMI_CSTAR_LITHUANIAN__) */

#endif /* #if defined(__MMI_LANG_LITHUANIAN__) */

#if defined(__MMI_LANG_LATVIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN, g_mmi_imm_uppercase_latvian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN, g_mmi_imm_lowercase_latvian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LATVIAN, g_mmi_imm_first_uppercase_latvian},
#endif

#if defined(__MMI_IME_LATVIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_LATVIAN, g_mmi_imm_uppercase_latvian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN, g_mmi_imm_lowercase_latvian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LATVIAN, g_mmi_imm_first_uppercase_latvian},
#endif
#endif /* defined(__MMI_ZI_LATVIAN__) || defined(__MMI_T9_LATVIAN__) || defined(__MMI_CSTAR_LATVIAN__) */

#endif /* #if defined(__MMI_LANG_LATVIAN__) */

#if defined(__MMI_LANG_ESTONIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN, g_mmi_imm_uppercase_estonian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN, g_mmi_imm_lowercase_estonian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ESTONIAN, g_mmi_imm_first_uppercase_estonian},
#endif

#if defined(__MMI_IME_ESTONIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN, g_mmi_imm_uppercase_estonian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN, g_mmi_imm_lowercase_estonian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ESTONIAN, g_mmi_imm_first_uppercase_estonian},
#endif
#endif /* defined(__MMI_ZI_ESTONIAN__) || defined(__MMI_T9_ESTONIAN__) || defined(__MMI_CSTAR_ESTONIAN__) */

#endif /* #if defined(__MMI_LANG_ESTONIAN__) */

#if defined(__MMI_LANG_ALBANIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ALBANIAN, g_mmi_imm_uppercase_albanian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN, g_mmi_imm_lowercase_albanian},          
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ALBANIAN, g_mmi_imm_first_uppercase_albanian},
#endif

#if defined(__MMI_IME_ALBANIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_ALBANIAN, g_mmi_imm_uppercase_albanian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN, g_mmi_imm_lowercase_albanian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ALBANIAN, g_mmi_imm_first_uppercase_albanian},
#endif
#endif /* defined(__MMI_ZI_ALBANIAN__) || defined(__MMI_T9_ALBANIAN__) || defined(__MMI_CSTAR_ALBANIAN__) */

#endif /* #if defined(__MMI_LANG_ALBANIAN__) */

#if defined(__MMI_LANG_ARMENIAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN, g_mmi_imm_uppercase_armenian},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN, g_mmi_imm_lowercase_armenian},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ARMENIAN, g_mmi_imm_first_uppercase_armenian},
#endif


#if defined(__MMI_IME_ARMENIAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN, g_mmi_imm_uppercase_armenian},
    {IMM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN, g_mmi_imm_lowercase_armenian},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ARMENIAN, g_mmi_imm_first_uppercase_armenian},
#endif
#endif /* defined(__MMI_ZI_ARMENIAN__) || defined(__MMI_T9_ARMENIAN__) || defined(__MMI_CSTAR_ARMENIAN__) */

#endif /* #if defined(__MMI_LANG_ARMENIAN__) */

#if defined(__MMI_LANG_GEORGIAN__)
    {IMM_INPUT_MODE_MULTITAP_GEORGIAN, g_mmi_imm_georgian},

#if defined(__MMI_IME_GEORGIAN__)
    {IMM_INPUT_MODE_SMART_GEORGIAN, g_mmi_imm_georgian},
#endif /* defined(__MMI_ZI_GEORGIAN__) || defined(__MMI_T9_GEORGIAN__) || defined(__MMI_CSTAR_GEORGIAN__) */

#endif /* #if defined(__MMI_LANG_GEORGIAN__) */

#if defined(__MMI_LANG_MOLDOVAN__)
    {IMM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN, g_mmi_imm_uppercase_moldovan},
    {IMM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN, g_mmi_imm_lowercase_moldovan},

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MOLDOVAN, g_mmi_imm_first_uppercase_moldovan},
#endif

#if defined(__MMI_IME_MOLDOVAN__)
    {IMM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN, g_mmi_imm_uppercase_moldovan},
    {IMM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN, g_mmi_imm_lowercase_moldovan},

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    {IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MOLDOVAN, g_mmi_imm_first_uppercase_moldovan},
#endif
#endif /* defined(__MMI_ZI_MOLDOVAN__) || defined(__MMI_T9_MOLDOVAN__) || defined(__MMI_CSTAR_MOLDOVAN__) */

#endif /* #if defined(__MMI_LANG_MOLDOVAN__) */

    {IMM_INPUT_MODE_MAX_NUM, NULL}
};

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#ifdef __MMI_IMM_EUROPEAN_LANGUAGE_DEAD_KEY_TABLE__
static const mmi_imm_dead_key_symbol_struct g_mmi_imm_european_dead_key_table[] = 
{
    /****Grave Accent***/
    {2, {0x60, 0x61}, 0xE0},
    {2, {0x60, 0x65}, 0xE8},
    {2, {0x60, 0x69}, 0xEC},
    {2, {0x60, 0x6F}, 0xF2},
    {2, {0x60, 0x75}, 0xF9},

    {2, {0x60, 0x41}, 0xC0},
    {2, {0x60, 0x45}, 0xC8},
    {2, {0x60, 0x49}, 0xCC},
    {2, {0x60, 0x4F}, 0xD2},
    {2, {0x60, 0x55}, 0xD9},

    /***Acute Accent***/
    {2, {0xB4, 0x61}, 0xE1},
    {2, {0xB4, 0x65}, 0xE9},
    {2, {0xB4, 0x69}, 0xED},
    {2, {0xB4, 0x6F}, 0xF3},
    {2, {0xB4, 0x75}, 0xFA},
    {2, {0xB4, 0x79}, 0xFD},

    {2, {0xB4, 0x41}, 0xC1},
    {2, {0xB4, 0x45}, 0xC9},
    {2, {0xB4, 0x49}, 0xCD},
    {2, {0xB4, 0x4F}, 0xD3},
    {2, {0xB4, 0x55}, 0xDA},
    {2, {0xB4, 0x59}, 0xDD},
    {2, {0xB4, 0x4c}, 0x0139}, 
    {2, {0xB4, 0x6c}, 0x013A}, 
    {2, {0xB4, 0x52}, 0x0154}, 
    {2, {0xB4, 0x72}, 0x0155}, 

    /***circumflex accent***/
    {2, {0x5E, 0x61}, 0xE2},
    {2, {0x5E, 0x65}, 0xEA},
    {2, {0x5E, 0x69}, 0xEE},
    {2, {0x5E, 0x6F}, 0xF4},
    {2, {0x5E, 0x75}, 0xFB},

    {2, {0x5E, 0x41}, 0xC2},
    {2, {0x5E, 0x45}, 0xCA},
    {2, {0x5E, 0x49}, 0xCE},
    {2, {0x5E, 0x4F}, 0xD4},
    {2, {0x5E, 0x55}, 0xDB},

    /***Diaeresis***/
    {2, {0xA8, 0x61}, 0xE4},
    {2, {0xA8, 0x65}, 0xEB},
    {2, {0xA8, 0x69}, 0xEF},
    {2, {0xA8, 0x6F}, 0xF6},
    {2, {0xA8, 0x75}, 0xFC},
    {2, {0xA8, 0x79}, 0xFF},

    {2, {0xA8, 0x41}, 0xC4},
    {2, {0xA8, 0x45}, 0xCB},
    {2, {0xA8, 0x49}, 0xCF},
    {2, {0xA8, 0x4F}, 0xD6},
    {2, {0xA8, 0x55}, 0xDC},

    /***Tilde***/
    {2, {0x7E, 0x61}, 0xE3},
    {2, {0x7E, 0x6F}, 0xF5},
    {2, {0x7E, 0x6E}, 0xF1},
    {2, {0x7E, 0x41}, 0xC3},
    {2, {0x7E, 0x4F}, 0xD5},
    {2, {0x7E, 0x4E}, 0xD1},

    /***Hacek***/
    {2, {0x02C7, 0x63}, 0x10D},     
    {2, {0x02C7, 0x64}, 0x10F},
    {2, {0x02C7, 0x43}, 0x10C},     
    {2, {0x02C7, 0x44}, 0x10E},
    {2, {0x02C7, 0x45}, 0x11A},     
    {2, {0x02C7, 0x65}, 0x11B},
    {2, {0x02C7, 0x4E}, 0x147},     
    {2, {0x02C7, 0x6E}, 0x148},
    {2, {0x02C7, 0x52}, 0x158},
    {2, {0x02C7, 0x72}, 0x159},     
    {2, {0x02C7, 0x53}, 0x160},
    {2, {0x02C7, 0x73}, 0x161},
    {2, {0x02C7, 0x54}, 0x164},     
    {2, {0x02C7, 0x74}, 0x165},
    {2, {0x02C7, 0x5A}, 0x17D},
    {2, {0x02C7, 0x7A}, 0x17E},
    {2, {0x02C7, 0x6C}, 0x13E},
    {2, {0x02C7, 0x4C}, 0x13D},

    /***Cedilla***/
    {2, {0x00B8, 0x53}, 0x15E},
    {2, {0x00B8, 0x73}, 0x15F},
    {2, {0x00B8, 0x43}, 0xC7},
    {2, {0x00B8, 0x63}, 0xE7},

    /***Ogonek***/
    {2, {0x02DB, 0x41}, 0x0104},
    {2, {0x02DB, 0x45}, 0x0118},
    {2, {0x02DB, 0x61}, 0x0105},
    {2, {0x02DB, 0x65}, 0x0119},  

    {2, {0x00B0, 'a'}, 0x00e5},
    {2, {0x00B0, 'e'}, 0x0117},
    {2, {0x00B0, 'g'}, 0x0121},
    {2, {0x00B0, 'z'}, 0x017c},
    {2, {0x00B0, 'o'}, 0x00f5},
    {2, {0x00B0, 'A'}, 0x00C5},
    {2, {0x00B0, 'E'}, 0x0116},
    {2, {0x00B0, 'G'}, 0x0120},
    {2, {0x00B0, 'Z'}, 0x017b},
    {2, {0x00B0, 'O'}, 0x00d5},

    {0, {0, 0}, 0}
};
#endif /* __MMI_IMM_EUROPEAN_LANGUAGE_DEAD_KEY_TABLE__ */ 

#if defined(__MMI_LANG_TURKISH__)
static const mmi_imm_dead_key_symbol_struct g_mmi_imm_turkish_dead_key_table[] = 
{
    /****Grave Accent***/
    {2, {0x60, 0x61}, 0xE0},
    {2, {0x60, 0x65}, 0xE8},
    {2, {0x60, 0x69}, 0xEC},
    {2, {0x60, 0x131}, 0xEC},
    {2, {0x60, 0x6F}, 0xF2},
    {2, {0x60, 0x75}, 0xF9},

    {2, {0x60, 0x41}, 0xC0},
    {2, {0x60, 0x45}, 0xC8},
    {2, {0x60, 0x49}, 0xCC},
    {2, {0x60, 0x130}, 0xCC},
    {2, {0x60, 0x4F}, 0xD2},
    {2, {0x60, 0x55}, 0xD9},

    /***Acute Accent***/
    {2, {0xB4, 0x61}, 0xE1},
    {2, {0xB4, 0x65}, 0xE9},
    {2, {0xB4, 0x69}, 0xED},
    {2, {0xB4, 0x131}, 0xED},
    {2, {0xB4, 0x6F}, 0xF3},
    {2, {0xB4, 0x75}, 0xFA},

    {2, {0xB4, 0x41}, 0xC1},
    {2, {0xB4, 0x45}, 0xC9},
    {2, {0xB4, 0x49}, 0xCD},
    {2, {0xB4, 0x130}, 0xCD},
    {2, {0xB4, 0x4F}, 0xD3},
    {2, {0xB4, 0x55}, 0xDA},

    /***circumflex accent***/
    {2, {0x5E, 0x61}, 0xE2},
    {2, {0x5E, 0x65}, 0xEA},
    {2, {0x5E, 0x69}, 0xEE},
    {2, {0x5E, 0x131}, 0xEE},
    {2, {0x5E, 0x6F}, 0xF4},
    {2, {0x5E, 0x75}, 0xFB},

    {2, {0x5E, 0x41}, 0xC2},
    {2, {0x5E, 0x45}, 0xCA},
    {2, {0x5E, 0x49}, 0xCE},
    {2, {0x5E, 0x130}, 0xCE},
    {2, {0x5E, 0x4F}, 0xD4},
    {2, {0x5E, 0x55}, 0xDB},

    /***Diaeresis***/
    {2, {0xA8, 0x61}, 0xE4},
    {2, {0xA8, 0x65}, 0xEB},
    {2, {0xA8, 0x69}, 0xEF},
    {2, {0xA8, 0x131}, 0xEF},
    {2, {0xA8, 0x6F}, 0xF6},
    {2, {0xA8, 0x75}, 0xFC},
    {2, {0xA8, 0x79}, 0xFF},

    {2, {0xA8, 0x41}, 0xC4},
    {2, {0xA8, 0x45}, 0xCB},
    {2, {0xA8, 0x49}, 0xCF},
    {2, {0xA8, 0x130}, 0xCF},
    {2, {0xA8, 0x4F}, 0xD6},
    {2, {0xA8, 0x55}, 0xDC},

    /***Tilde***/
    {2, {0x7E, 0x61}, 0xE3},
    {2, {0x7E, 0x6F}, 0xF5},
    {2, {0x7E, 0x6E}, 0xF1},

    {2, {0x7E, 0x41}, 0xC3},
    {2, {0x7E, 0x4F}, 0xD5},
    {2, {0x7E, 0x4E}, 0xD1},

    {0, {0, 0}, 0}
};
#endif /* #if defined(__MMI_LANG_TURKISH__) */

#if defined(__MMI_LANG_LATVIAN__)
static const mmi_imm_dead_key_symbol_struct g_mmi_imm_latvian_dead_key_table[] = 
{
    {2, {0x00B0, 'a'}, 0x00e5},
    {2, {0x00B0, 'e'}, 0x0117},
    {2, {0x00B0, 'g'}, 0x0121},
    {2, {0x00B0, 'z'}, 0x017c},
    {2, {0x00B0, 'o'}, 0x00f5},
    {2, {0x00B0, 'A'}, 0x00C5},
    {2, {0x00B0, 'E'}, 0x0116},
    {2, {0x00B0, 'G'}, 0x0120},
    {2, {0x00B0, 'Z'}, 0x017b},
    {2, {0x00B0, 'O'}, 0x00d5},

    {2, {0x7E, 0x61}, 0xE3},
    {2, {0x7E, 0x6F}, 0xF5},
    {2, {0x7E, 0x6E}, 0xF1},
    {2, {0x7E, 0x41}, 0xC3},
    {2, {0x7E, 0x4F}, 0xD5},
    {2, {0x7E, 0x4E}, 0xD1},

    {0, {0, 0}, 0}
};
#endif /* #if defined(__MMI_LANG_LATVIAN__) */

#if defined(__MMI_LANG_ESTONIAN__)
static const mmi_imm_dead_key_symbol_struct g_mmi_imm_estonian_dead_key_table[] = 
{
    {2, {0x0301, 0x0065}, 0x00e9},
    {2, {0x0301, 0x006f}, 0x00f3},
    {2, {0x0301, 0x0073}, 0x015b},
    {2, {0x0301, 0x007a}, 0x017a},
    {2, {0x0301, 0x0063}, 0x0107},
    {2, {0x0301, 0x006e}, 0x0144},
    {2, {0x030c, 0x0073}, 0x0161},
    {2, {0x030c, 0x007a}, 0x017e},
    {2, {0x030c, 0x0063}, 0x010d},
    {2, {0x0303, 0x006f}, 0x00f5},
    {2, {0x0300, 0x0065}, 0x00e8},
    {2, {0x0300, 0x0075}, 0x00f9},
    {2, {0x0300, 0x006f}, 0x00f2},
    {2, {0x0300, 0x0061}, 0x00e0},
    /* uppercase */
    {2, {0x0301, 'E'}, 0x00c9},
    {2, {0x0301, 'O'}, 0x00d3},
    {2, {0x0301, 'S'}, 0x015a},
    {2, {0x0301, 'Z'}, 0x0179},
    {2, {0x0301, 'C'}, 0x0106},
    {2, {0x0301, 'N'}, 0x0143},
    {2, {0x030c, 'S'}, 0x0160},
    {2, {0x030c, 'Z'}, 0x017d},
    {2, {0x030c, 'C'}, 0x010c},
    {2, {0x0303, 'O'}, 0x00d5},
    {2, {0x0300, 'E'}, 0x00c8},
    {2, {0x0300, 'U'}, 0x00d9},
    {2, {0x0300, 'O'}, 0x00d2},
    {2, {0x0300, 'A'}, 0x00c0},

    {2, {0xB4, 0x61}, 0xE1},
    {2, {0xB4, 0x65}, 0xE9},
    {2, {0xB4, 0x69}, 0xED},
    {2, {0xB4, 0x6F}, 0xF3},
    {2, {0xB4, 0x75}, 0xFA},
    {2, {0xB4, 0x79}, 0xFD},

    {2, {0xB4, 0x41}, 0xC1},
    {2, {0xB4, 0x45}, 0xC9},
    {2, {0xB4, 0x49}, 0xCD},
    {2, {0xB4, 0x4F}, 0xD3},
    {2, {0xB4, 0x55}, 0xDA},
    {2, {0xB4, 0x59}, 0xDD},
    {2, {0xB4, 0x4c}, 0x0139}, 
    {2, {0xB4, 0x6c}, 0x013A}, 
    {2, {0xB4, 0x52}, 0x0154}, 
    {2, {0xB4, 0x72}, 0x0155}, 

    {2, {0x60, 0x61}, 0xE0},
    {2, {0x60, 0x65}, 0xE8},
    {2, {0x60, 0x69}, 0xEC},
    {2, {0x60, 0x6F}, 0xF2},
    {2, {0x60, 0x75}, 0xF9},

    {2, {0x60, 0x41}, 0xC0},
    {2, {0x60, 0x45}, 0xC8},
    {2, {0x60, 0x49}, 0xCC},
    {2, {0x60, 0x4F}, 0xD2},
    {2, {0x60, 0x55}, 0xD9},

    {2, {0x7E, 0x61}, 0xE3},
    {2, {0x7E, 0x6F}, 0xF5},
    {2, {0x7E, 0x6E}, 0xF1},
    {2, {0x7E, 0x41}, 0xC3},
    {2, {0x7E, 0x4F}, 0xD5},
    {2, {0x7E, 0x4E}, 0xD1},

    {2, {0x02C7, 0x63}, 0x10D},     
    {2, {0x02C7, 0x64}, 0x10F},
    {2, {0x02C7, 0x43}, 0x10C},     
    {2, {0x02C7, 0x44}, 0x10E},
    {2, {0x02C7, 0x45}, 0x11A},     
    {2, {0x02C7, 0x65}, 0x11B},
    {2, {0x02C7, 0x4E}, 0x147},     
    {2, {0x02C7, 0x6E}, 0x148},
    {2, {0x02C7, 0x52}, 0x158},
    {2, {0x02C7, 0x72}, 0x159},     
    {2, {0x02C7, 0x53}, 0x160},
    {2, {0x02C7, 0x73}, 0x161},
    {2, {0x02C7, 0x54}, 0x164},     
    {2, {0x02C7, 0x74}, 0x165},
    {2, {0x02C7, 0x5A}, 0x17D},
    {2, {0x02C7, 0x7A}, 0x17E},
    {2, {0x02C7, 0x6C}, 0x13E},
    {2, {0x02C7, 0x4C}, 0x13D},

    {0, {0, 0}, 0}
};
#endif /* #if defined(__MMI_LANG_ESTONIAN__) */

#if defined(__MMI_LANG_GREEK__)
static const mmi_imm_dead_key_symbol_struct g_mmi_imm_greek_dead_key_table[] = 
{
    /*Dialytika*/
    {2, {0x0385, 0x03B9}, 0x0390},
    {2, {0x0385, 0x03C5}, 0x03B0},
    /*Greek_acute*/
    {2, {0x0384, 0x0391}, 0x0386},
    {2, {0x0384, 0x0395}, 0x0388},
    {2, {0x0384, 0x0397}, 0x0389},
    {2, {0x0384, 0x0399}, 0x038A},
    {2, {0x0384, 0x039F}, 0x038C},
    {2, {0x0384, 0x03A5}, 0x038E},
    {2, {0x0384, 0x03A9}, 0x038F},
    {2, {0x0384, 0x03B1}, 0x03AC},
    {2, {0x0384, 0x03B5}, 0x03AD},
    {2, {0x0384, 0x03B7}, 0x03AE},
    {2, {0x0384, 0x03B9}, 0x03AF},
    {2, {0x0384, 0x03BF}, 0x03CC},
    {2, {0x0384, 0x03C5}, 0x03CD},
    {2, {0x0384, 0x03C9}, 0x03CE},
    /*Diaeresis*/
    {2, {0x00A8, 0x0399}, 0x03AA},
    {2, {0x00A8, 0x03A5}, 0x03AB},
    {2, {0x00A8, 0x03B9}, 0x03CA},
    {2, {0x00A8, 0x03C5}, 0x03CB},

    {0, {0, 0}, 0}
};

#endif /* #if defined(__MMI_LANG_GREEK__) */ 

static const mmi_imm_dead_key_lang_talbe_struct g_mmi_imm_dead_key_lang_talbe[] =
{
#if defined(__MMI_LANG_TURKISH__)
    {IME_WRITING_LANG_TR, (mmi_imm_dead_key_symbol_struct_p)&g_mmi_imm_turkish_dead_key_table[0]}, 
#endif

#if defined(__MMI_LANG_LATVIAN__)
    {IME_WRITING_LANG_LV, (mmi_imm_dead_key_symbol_struct_p)&g_mmi_imm_latvian_dead_key_table[0]}, 
#endif


#if defined(__MMI_LANG_ESTONIAN__)
    {IME_WRITING_LANG_ET, (mmi_imm_dead_key_symbol_struct_p)&g_mmi_imm_estonian_dead_key_table[0]}, 
#endif

#if defined(__MMI_LANG_GREEK__)
    {IME_WRITING_LANG_EL, (mmi_imm_dead_key_symbol_struct_p)&g_mmi_imm_greek_dead_key_table[0]}, 
#endif

    {IME_WRITING_LANG_NONE, NULL}
};

static mmi_imm_dead_key_symbol_struct_p g_mmi_imm_current_dead_key_table = NULL;

#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */

/* The valid characters for IMM_INPUT_TYPE_PHONE_NUMBER */
static const UI_character_type g_mmi_imm_phone_number_valid_characters[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', 'p', 'w', '#', '*', '\0' };

/* The valid characters for IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR */
static const UI_character_type g_mmi_imm_phone_number_wildchar_valid_characters[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', 'p', '?', '#', '*', '\0' };


/* The valid characters for IMM_INPUT_TYPE_KEYPAD_NUMERIC */
static const UI_character_type g_mmi_imm_keypad_numberic_valid_characters[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '#', '*', '\0' };


/* The valid characters for INPUT_TYPE_EXT_SIM_NUMERIC */
static const UI_character_type g_mmi_imm_phone_number_sim_valid_characters[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '#', '*', '\0' };


/* The valid characters for IMM_INPUT_TYPE_DECIMAL_NUMERIC */
static const UI_character_type g_mmi_imm_decimal_numeric_valid_characters[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '\0' };


/* The valid characters for IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC */
static const UI_character_type g_mmi_imm_signed_decimal_numeric_valid_characters[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '-', '\0' };

/* The valid characters for IMM_INPUT_TYPE_SIGNED_NUMERIC */
static const UI_character_type g_mmi_imm_signed_numeric_valid_characters[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '\0' };


#if defined(__MMI_IME_FTE_ENHANCE__)
static const UI_character_type g_mmi_imm_numeric_valid_characters[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0' };
#endif

/* The invalid characters array */
const UI_character_type g_mmi_imm_phone_number_invalid_characters[] = { '(', ')', '-', ' ', '\0' };

const UI_character_type g_mmi_imm_keypad_numberic_invalid_characters[] = { '(', ')', 'p', 'w', '+', '-', ' ', '\0' };

const UI_character_type g_mmi_imm_phone_number_sim_invalid_characters[] = { '(', ')', 'p', 'w', '-', ' ', '\0' };

/*  For IMM_INPUT_TYPE_SIGNED_NUMERIC and IMM_INPUT_TYPE_SIGNED_NUMERIC_PASSWORD */
const UI_character_type g_mmi_imm_signed_numberic_invalid_characters[] = { '*', '/',  '+', '%', '$', '=', '.', ' ', '\0' };

/*  For   IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC, IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD  */
const UI_character_type g_mmi_imm_signed_decimal_numberic_invalid_characters[] = { '*', '/',  '+', '%', '$', '=', ' ', '\0' };


#if defined(__MMI_IME_FTE_ENHANCE__)

static const UI_character_type g_mmi_imm_numeric_invalid_characters[] = {'.', '-', '\0'};

const UI_character_type g_mmi_imm_decimal_numberic_invalid_characters[] = {'-', '\0' };

const UI_character_type g_mmi_imm_no_number_invalid_characters[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0' };


#endif

const UI_character_type g_mmi_imm_ucs2_invalid_characters[] = {0x20ac, '\0' };

/* Should be sync with applib_is_valid_url_wchar() */
const UI_character_type g_mmi_imm_url_allowed_characters[] = L":;/\\\\.,#?$+@&=%-_()[]{}<>`~!^*|\"\\A-Za-z0-9";

const UI_character_type g_mmi_imm_email_allowed[] = L"\'+\\\\_\\-.@!#$%&*/=?^`{|}~A-Za-z0-9";

const  UI_character_type g_mmi_imm_ascii_allowed[] = L" -~";

const UI_character_type g_mmi_imm_voip_number_allowed[] = L"_\\-.!~*\\\\'()&=+$,;?/%@:A-Za-z0-9";

const UI_character_type g_mmi_imm_new_word_invalid_characters[] = {0x20, '\0'};

static MMI_BOOL g_mmi_imm_set_input_rule_by_ap = MMI_FALSE;
#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL g_mmi_imm_set_input_rule_by_ap_vk = MMI_FALSE;
#endif
static UI_character_type g_mmi_imm_allowed_characters[MMI_IMM_MAX_ALLOWED_CHARACTER_NUM] = {0};

static UI_character_type g_mmi_imm_disabled_characters[MMI_IMM_MAX_DISABLE_CHARACTER_NUM] = {0};

static UI_character_type g_mmi_imm_default_allowed_characters[MMI_IMM_MAX_ALLOWED_CHARACTER_NUM] = {0};

static UI_character_type g_mmi_imm_default_disabled_characters[MMI_IMM_MAX_DISABLE_CHARACTER_NUM] = {0};

#ifdef __MMI_TOUCH_SCREEN__
static gui_virtual_keyboard_pen_enum g_mmi_imm_allowed_events[MMI_IMM_MAX_ALLOWED_CHARACTER_NUM] = {GUI_VKBD_PEN_NONE};

static gui_virtual_keyboard_pen_enum g_mmi_imm_disabled_events[MMI_IMM_MAX_DISABLE_CHARACTER_NUM] = {GUI_VKBD_PEN_NONE};

//static gui_virtual_keyboard_pen_enum g_mmi_imm_default_allowed_events[MMI_IMM_MAX_ALLOWED_CHARACTER_NUM] = {GUI_VKBD_PEN_NONE};

static gui_virtual_keyboard_pen_enum g_mmi_imm_default_disabled_events[MMI_IMM_MAX_DISABLE_CHARACTER_NUM] = {GUI_VKBD_PEN_NONE};
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__  

#define IMM_MAX_STROKE_COLOR_NUM	(8)
#define IMM_MAX_STROKE_WIDTH 		(255)
#define IMM_MIN_STROKE_WIDTH		(1)

MMI_BOOL g_is_handwriting_setting_on = MMI_TRUE;
MMI_BOOL g_is_handwriting_follow_vk_lang = MMI_FALSE;

U8 g_current_stroke_color_index = 0;
U8 g_current_stroke_width = 0;
color g_current_handwritng_stroke_color = {0, 255, 255, 0};

static const color g_imm_hw_color_list[IMM_MAX_STROKE_COLOR_NUM] = 
{
   {0, 255, 255},
   {255, 0, 0},
   {0, 255, 0},
   {255, 255, 0},
   {255, 0, 255},
   {255, 128, 0},
   {0, 0, 128},
   {0, 0, 0}
};

#endif //__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
static U16 g_mmi_imm_special_key_icon = 0;
static mmi_ime_hint_flag_enum g_mmi_imm_current_input_case = MMI_IME_HINT_FLAG_LOWER_CASE;
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
static MMI_BOOL g_mmi_imm_is_first_uppercase_modes_enalbled = MMI_TRUE;
#endif

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
static mmi_imm_pen_speed_enum g_mmi_imm_pen_speed = MMI_IMM_PEN_SPEED_MEDIUM;
#endif

/*****************************************************************************
* Global functions
*****************************************************************************/



/*****************************************************************************
* Local functions
*****************************************************************************/
static void mmi_imm_set_default_allowed_and_disabled_chars(void);       
void mmi_imm_read_prefered_writing_lang_from_nvram();
void mmi_imm_update_prefer_writing_language(mmi_imm_support_writing_lang_enum writing_lang);     
void mmi_imm_read_prefered_input_method_from_nvram();
#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL mmi_imm_test_caps_switch(mmi_imm_input_mode_enum input_mode, mmi_imm_input_mode_item *mode_array);
#endif
static MMI_BOOL mmi_imm_check_allowed_character(UI_character_type ch, const UI_character_type *pch);
static MMI_BOOL mmi_imm_check_disabled_character(UI_character_type ch, const UI_character_type *pch);
static void mmi_imm_init_prefered_input_mode(void);

#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
static mmi_imm_input_mode_enum mmi_imm_search_prefer_for_quick_search(void);
static void mmi_imm_init_writing_lang();
void mmi_imm_read_prefered_writing_sub_lang_from_nvram();
#endif

#if defined(__MMI_IME_FUZZY_PINYIN__)
static void mmi_imm_init_fuzzy_pinyin_setting();
#endif

#if defined __MMI_IME_PHONETIC_PREDICTION_SETTING__
MMI_BOOL g_mmi_imm_is_chinese_word_prediction_enabled;
#endif
#if defined(__MMI_IME_V3__)
//Auto space
MMI_BOOL g_mmi_imm_is_auto_space_enabled = MMI_TRUE;
//vibration
MMI_BOOL g_mmi_imm_is_vibration_enabled = MMI_TRUE;
//touch feedback
MMI_BOOL g_mmi_imm_is_sound_feedback_enabled;
#endif
#if defined __MMI_IME_ALPHABETIC_PREDICTION_SETTING__
MMI_BOOL g_mmi_imm_is_alphabetic_word_prediction_enabled;
#endif
#if defined(__MMI_IME_AUTO_COMPLETION_SETTING__)
MMI_BOOL g_mmi_imm_is_auto_completion_enabled;
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
MMI_BOOL g_mmi_imm_is_auto_capitalization_enabled;
MMI_BOOL g_imm_is_auto_capitalization_setting_changed;
#endif

U8 g_mmi_imm_keypad_type;


MMI_BOOL g_mmi_imm_get_handwriting_setting = MMI_TRUE;

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
MMI_BOOL g_mmi_imm_is_auto_capitalization_valid = MMI_TRUE;
#endif

#if  defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
static void mmi_imm_set_curr_allowed_writing_lang_by_curr_allowed_modes(void);
void mmi_imm_set_curr_writing_lang_by_curr_mode(void);
static S32  mmi_imm_get_index_in_system_writing_language(mmi_imm_support_writing_lang_enum writing_lang);
mmi_imm_input_mode_enum mmi_imm_get_first_allowed_input_mode_of_lang(mmi_imm_support_writing_lang_enum writing_lang);
static mmi_imm_input_mode_enum mmi_imm_get_first_allowed_input_mode_of_lang_by_mode_attr(mmi_imm_support_writing_lang_enum writing_lang, U16 mode_attibut);
#endif

static MMI_BOOL mmi_imm_is_chinese_input_mode_valid(void);
static void mmi_imm_set_initial_input_mode_by_last(void);

#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
static MMI_BOOL mmi_imm_check_same_mode_special_attribute_rule(U16 src_attrib, U16 target_attrib);
#endif

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
static MMI_BOOL mmi_imm_is_valid_uppercase_input_mode(mmi_imm_input_mode_enum input_mode, mmi_imm_input_mode_enum *mode_array);
#endif

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
static void mmi_imm_handwriting_memory_card_init(void);
#endif

#if defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
MMI_BOOL mmi_imm_memory_card_is_input_mode_supported(mmi_imm_input_mode_enum input_mode);
#endif
/*****************************************************************************
* FUNCTION
*  mmi_imm_set_editor_type
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_editor_type(mmi_ime_editor_type_enum editor_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imm_editor_type = editor_type;

    if (editor_type == MMI_IME_EDITOR_TYPE_MULTILINE)
    {
        MMI_current_input_ext_type &= ~INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }
    else if (editor_type == MMI_IME_EDITOR_TYPE_SINGLELINE)
    {
        MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_special_ext_input_type
* DESCRIPTION
* PARAMETERS
*  void
* RETURNS
*	U32
*****************************************************************************/
U32 mmi_imm_get_special_ext_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_imm_input_special_ext_type;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_required_mode_list
* DESCRIPTION
* PARAMETERS
*  Input_type: the input type assigned by AP.
* Input[]: the input mode array assigned by AP.
* History_input_mode: the input mode extraced from history if necessary.
* RETURNS
*****************************************************************************/
mmi_imm_message_id_enum mmi_imm_set_required_mode_list(
    U32 input_type,
    mmi_imm_input_mode_enum *input_mode_array,
    mmi_imm_input_mode_enum default_input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j =0, p = 0, k=0;
    U32 input_type_int = input_type & (~IMM_INPUT_TYPE_MASK);
    MMI_BOOL multitap_type = MMI_FALSE, enable_uppercase_abc = MMI_FALSE;
#if defined(__MMI_IME_V3__)
    MMI_BOOL need_reset = MMI_TRUE;
#endif
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
	U32 hw_unsupport_mode_count = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Error Handling */
    if (input_type_int == IMM_INPUT_TYPE_USER_SPECIFIC && input_mode_array == NULL)
        return IMM_MESSAGE_ID_ERROR;

    if ((input_type & IMM_INPUT_TYPE_EXT_PASSWORD))
    {
        multitap_type = MMI_TRUE;
        MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }
    if ((input_type & IMM_INPUT_TYPE_EXT_MULTITAP))
    {
        multitap_type = MMI_TRUE;
    }

	  if (input_type & IMM_INPUT_TYPE_EMAIL)
	  {
		    multitap_type = MMI_TRUE;
	  }
	  
    if ((input_type & IMM_INPUT_TYPE_EXT_ENGLISH_UPPERCASE)
        || (input_type & IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE))
    {
        enable_uppercase_abc = MMI_TRUE;
    }

    if ((input_type & IMM_INPUT_TYPE_SPECIAL_EXT_SHOW_DIALER_VK))
    {
        g_mmi_imm_input_special_ext_type |= IMM_INPUT_TYPE_SPECIAL_EXT_SHOW_DIALER_VK;
    }
    else
    {
        g_mmi_imm_input_special_ext_type = 0;
    }

    /* reset data. */
    memset(&g_mmi_imm_curr_allowed_input_mode, 0 , sizeof(mmi_imm_input_mode_item) * IMM_INPUT_MODE_MAX_NUM);

    /* Set input type */
    g_mmi_imm_current_input_type = (mmi_imm_input_type_enum)input_type;

    g_mmi_imm_user_specific_input_mode_list = input_mode_array;


    /* prepare input mode array */
    if (input_type_int == IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        for (i = 0; input_mode_array[i] != IMM_INPUT_MODE_NONE; i++)
        {
            if ((p = mmi_imm_is_system_supported_input_mode(input_mode_array[i])) != -1)
            {
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
                if (!g_mmi_imm_is_smart_alphabetic_input_modes_enalbed 
                    && (gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                    && ((gIMEModeArray[p].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                    || (gIMEModeArray[p].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)))
                {
                    continue; /* If smart input method is turned off, skip the input modes*/
                }
#endif
          #if defined __MMI_QWERTY_KEYPAD_SUPPORT__ 

            #if defined __MMI_COSMOS_KEYPAD_SLIDER__
                if(mmi_imc_get_slider_status() == OPEN)
            #endif
                {
                if ((gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                    && !enable_uppercase_abc)
                {
                    if (!mmi_imm_is_valid_uppercase_input_mode(input_mode_array[i], input_mode_array))
                    {
                        continue;
                    }
                }
                }
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                if (IS_FILTER_CAPS)
                {
                    if (gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                    {
                        continue;
                    }
                }
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                if (!g_mmi_imm_is_first_uppercase_modes_enalbled)
                {
                    if (gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                    {
                        continue;
                    }
                }
#endif

#if defined(__MMI_IME_PLUG_IN__)
                if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)(input_mode_array[i]), 0))
                {
                    continue;
                }
#endif

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
			    //check if hw vendor support
			    if(!mmi_ime_hand_writing_memory_card_is_lang_support(gIMEModeArray[p].lang_id))
				{
					hw_unsupport_mode_count++;
				}
#endif
                if(input_type & IMM_INPUT_TYPE_EXT_PASSWORD)
                {
                    if (gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                    {
                        continue;
                    }
                }

                g_mmi_imm_curr_allowed_input_mode[j].mode_id = input_mode_array[i];
                g_mmi_imm_curr_allowed_input_mode[j].index = p;
                j ++;
            }
        }
		
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
		if(!g_is_init_with_memory_card || !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) || (hw_unsupport_mode_count != 0 && hw_unsupport_mode_count >= j))
		{
		    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMM_SET_REQUIRED_MODE_LIST, hw_unsupport_mode_count, j);
		    mmi_imc_disable_handwriting();
		    mmi_imm_config_handwriting_setting(MMI_FALSE);
		}
#endif
        g_mmi_imm_curr_allowed_input_mode[j].mode_id = IMM_INPUT_MODE_NONE;
        g_mmi_imm_curr_allowed_input_mode[j].index = -1;

        /* No item in the input_mode_array is supported by the system.  */
        if (j == 0)
        {
            return IMM_MESSAGE_ID_ERROR;
        }

        /* set default input method as the first item of the user specified array. */
        g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[0].mode_id;

    }
#if defined(__MMI_IME_FTE_ENHANCE__)
    else if ((input_type_int & IMM_INPUT_TYPE_URL) || 
        (input_type_int == IMM_INPUT_TYPE_EMAIL))
    {
#if defined(__MMI_IME_PLUG_IN__)
        i = 0;
        if (!mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC, 0))
        {
            g_mmi_imm_curr_allowed_input_mode[i].mode_id = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
            g_mmi_imm_curr_allowed_input_mode[i].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);
            i++;
        }
        if (!mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC, 0))
        {
            g_mmi_imm_curr_allowed_input_mode[i].mode_id = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC;
            g_mmi_imm_curr_allowed_input_mode[i].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC);
            i++;
        }
        if (!mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)IMM_INPUT_MODE_123_SYMBOLS, 0))
        {
            g_mmi_imm_curr_allowed_input_mode[i].mode_id = IMM_INPUT_MODE_123_SYMBOLS;
            g_mmi_imm_curr_allowed_input_mode[i].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_123_SYMBOLS);
            i++;
        }
        if (i == 0)
        {
            return IMM_MESSAGE_ID_ERROR;
        }

        g_mmi_imm_curr_allowed_input_mode[i].mode_id = IMM_INPUT_MODE_NONE;
#else
        g_mmi_imm_curr_allowed_input_mode[k].mode_id = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
        g_mmi_imm_curr_allowed_input_mode[k++].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_V3__)  
        g_mmi_imm_curr_allowed_input_mode[k].mode_id = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC;
        g_mmi_imm_curr_allowed_input_mode[k++].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC);
#endif
		g_mmi_imm_curr_allowed_input_mode[k].mode_id = IMM_INPUT_MODE_123_SYMBOLS;
        g_mmi_imm_curr_allowed_input_mode[k++].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_123_SYMBOLS);
        g_mmi_imm_curr_allowed_input_mode[k].mode_id = IMM_INPUT_MODE_NONE;
#endif
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
		if (!g_is_init_with_memory_card || !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
		{
		    mmi_imc_disable_handwriting();
		    mmi_imm_config_handwriting_setting(MMI_FALSE);
		}
#endif
    }
#endif
    else
    {
        for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
        {
            if (mmi_imm_is_system_supported_input_mode(gIMEModeArray[i].imm_mode_id) == -1)
            { 
                continue;  
            }

            if ((gIMEModeArray[i].supported_input_type_flag & input_type_int))
            {            
                if (multitap_type)
                {
                    if (((gIMEModeArray[i].Mode_Special_Attrib) & (IME_MODE_ATTR_SMART)))
                    {
                    }
                    else
                    {
#if   defined __MMI_QWERTY_KEYPAD_SUPPORT__ 

#if defined __MMI_COSMOS_KEYPAD_SLIDER__
                        if(mmi_imc_get_slider_status() == OPEN)
#endif
                        {

                        if ((gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                            && !enable_uppercase_abc)
                        {
                            continue;
                        }
                        }
#endif

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                        if (IS_FILTER_CAPS)
                        {
                            if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                            {
                                continue;
                            }
                        }
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                        if (!g_mmi_imm_is_first_uppercase_modes_enalbled)
                        {
                            if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                            {
                                continue;
                            }
                        }
#endif

#if defined(__MMI_IME_PLUG_IN__)
                        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)(gIMEModeArray[i].imm_mode_id), 0))
                        {
                            continue;
                        }
#endif

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
			            //check if hw vendor support
			            if(!mmi_ime_hand_writing_memory_card_is_lang_support(gIMEModeArray[i].lang_id))
				        {
					        hw_unsupport_mode_count++;
				        }
#endif

                        if(input_type & IMM_INPUT_TYPE_EXT_PASSWORD)
                        {
                            if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                            {
                                continue;
                            }
                        }
                        g_mmi_imm_curr_allowed_input_mode[j].mode_id = gIMEModeArray[i].imm_mode_id;
                        g_mmi_imm_curr_allowed_input_mode[j].index = i;
                        j++;
                    }
                }
                else
                {
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
                    if (!g_mmi_imm_is_smart_alphabetic_input_modes_enalbed 
                        && (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                        && ((gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                        || (gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)))
                    {
                        continue; /* If smart input method is turned off, skip the input modes*/
                    }
#endif
          #if   defined (__MMI_QWERTY_KEYPAD_SUPPORT__) && !defined(__MMI_IME_V3__) 

                #if defined __MMI_COSMOS_KEYPAD_SLIDER__
                    if(mmi_imc_get_slider_status() == OPEN)
                #endif
                    {
					#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
						const sIMEModeDetails * mode_details_ptr = NULL;
						mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_last_input_mode);
					#endif

						if ((gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
							&& !enable_uppercase_abc
						#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
                                                        && (mode_details_ptr != NULL
                                                        && !(mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE))
						#endif
							)
						{
							continue;
						}
                    }
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    if (IS_FILTER_CAPS)
                    {
                        if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                        {
                            continue;
                        }
                    }
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                    if (!g_mmi_imm_is_first_uppercase_modes_enalbled)
                    {
                        if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                        {
                            continue;
                        }
                    }
#endif

#if defined(__MMI_IME_PLUG_IN__)
                    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)(gIMEModeArray[i].imm_mode_id), 0))
                    {
                        continue;
                    }
#endif
                    if(input_type & IMM_INPUT_TYPE_EXT_PASSWORD)
                    {
                        if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                        {
                            continue;
                        }
                    }

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
			        //check if hw vendor support
			        if(!mmi_ime_hand_writing_memory_card_is_lang_support(gIMEModeArray[i].lang_id))
				    {
					    hw_unsupport_mode_count++;
				    }
#endif
                    g_mmi_imm_curr_allowed_input_mode[j].mode_id = gIMEModeArray[i].imm_mode_id;
                    g_mmi_imm_curr_allowed_input_mode[j].index = i;
                    j++;
                }
            }
        }
		
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
		if(!g_is_init_with_memory_card || !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) || (hw_unsupport_mode_count != 0 && hw_unsupport_mode_count >= j))
		{
		    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMM_SET_REQUIRED_MODE_LIST, hw_unsupport_mode_count, j);
		    mmi_imc_disable_handwriting();
		    mmi_imm_config_handwriting_setting(MMI_FALSE);
		}
#endif
        g_mmi_imm_curr_allowed_input_mode[j].mode_id = IMM_INPUT_MODE_NONE;
        g_mmi_imm_curr_allowed_input_mode[j].index = -1;

        /* No input method is supported by the system.  */
        if (j == 0)
        {
            return IMM_MESSAGE_ID_ERROR;
        }

        /* set default input method */
        g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[0].mode_id;

        if ( input_type_int & IMM_INPUT_TYPE_EMAIL)
        {
            g_mmi_imm_current_input_mode= IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
        }

    }

    if ((input_type & IMM_INPUT_TYPE_URL) || 
        input_type == IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE ||
        (input_type & IMM_INPUT_TYPE_EMAIL))
    {
#if defined(__MMI_IME_PLUG_IN__)
        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC, 0))
        {
            MMI_ASSERT(0);
        }
#endif
        g_mmi_imm_current_input_mode = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
    }
    else if (input_type == IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE)
    {
#if defined(__MMI_IME_PLUG_IN__)
        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC, 0))
        {
            MMI_ASSERT(0);
        }
#endif
        g_mmi_imm_current_input_mode = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC;
    }
    /* check prefer input method */
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    else if (g_mmi_imm_prefer_input_mode != IMM_INPUT_MODE_NONE)
    {
        if (input_type_int != IMM_INPUT_TYPE_QUICK_SEARCH)
        {
            if (mmi_imm_is_curr_allow_input_mode(g_mmi_imm_prefer_input_mode))
            {
                g_mmi_imm_current_input_mode = g_mmi_imm_prefer_input_mode;
            }
            else if (g_mmi_imm_prefer_input_mode != IMM_INPUT_MODE_NONE)
            {
                const sIMEModeDetails *mode_details_ptr = NULL;

                mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_prefer_input_mode);
                #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
                if (!mmi_imm_is_smart_alphabetic_input_modes_enabled())
                {
                    mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, mode_details_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK);
                    if (mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
                    {
                        g_mmi_imm_current_input_mode = mode_details_ptr->imm_mode_id;
                    }
                }
                else
                #endif
                if (mode_details_ptr)
                {
                    for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
                    {
                        if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id == mode_details_ptr->lang_id)
                        {
                            break;
                        }
                    }

                    if (g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE)
                    {
                        g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                    }
                }
            }	
        }
        else
        {
            mmi_imm_input_mode_enum quick_search_mode = mmi_imm_search_prefer_for_quick_search();
            if (quick_search_mode != IMM_INPUT_MODE_NONE)
                g_mmi_imm_current_input_mode = quick_search_mode;
        }
    }
#endif

    mmi_imm_set_initial_input_mode_by_last();

    g_mmi_imm_is_default_init_input_mode_overide = MMI_FALSE;
#if defined(__MMI_IME_V3__)
    if (g_mmi_imm_default_input_mode == IMM_INPUT_MODE_123_SYMBOLS && g_mmi_imm_app_desired_input_mode != IMM_INPUT_MODE_123_SYMBOLS)
    {
        need_reset = MMI_FALSE;
    }
#endif
    /* check the default input method. It might be the input method stored in history or the default set by AP. */
    if (default_input_mode != IMM_INPUT_MODE_NONE)
    {
        if (mmi_imm_is_curr_allow_input_mode(default_input_mode))
        {
            g_mmi_imm_current_input_mode = default_input_mode;
            g_mmi_imm_history_input_mode = default_input_mode;
            g_mmi_imm_is_default_init_input_mode_overide = MMI_TRUE;
        }	
        else /* Get a input mode whose language is same with the language of the invalid default input mode */
        {
            const sIMEModeDetails *mode_details_ptr = NULL;

            mode_details_ptr = mmi_imm_get_input_mode_array_item(default_input_mode);

            if (mode_details_ptr)
            {
                for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
                {
                    if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id == mode_details_ptr->lang_id)
                    {
                        break;
                    }
                }

                if (g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE)
                {
                    g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                    g_mmi_imm_history_input_mode = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                    g_mmi_imm_is_default_init_input_mode_overide = MMI_TRUE;
                }
            }
        }	
    }
    else if (g_mmi_imm_default_input_mode != IMM_INPUT_MODE_NONE )
    {
        if (mmi_imm_is_curr_allow_input_mode(g_mmi_imm_default_input_mode))
        {
            g_mmi_imm_current_input_mode = g_mmi_imm_default_input_mode;
            g_mmi_imm_is_default_init_input_mode_overide = MMI_TRUE;
        }
        else /* Get a input mode whose language is same with the language of the invalid default input mode */
        {
            const sIMEModeDetails *mode_details_ptr = NULL;

            mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_default_input_mode);

            #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            if (!mmi_imm_is_smart_alphabetic_input_modes_enabled())
            {
                mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, mode_details_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK);
                if (mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
                {
                    g_mmi_imm_current_input_mode = mode_details_ptr->imm_mode_id;
                }
            }
            else
            #endif

            if (mode_details_ptr)
            {
                for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
                {
                    if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id == mode_details_ptr->lang_id)
                    {
                        break;
                    }
                }

                if (g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE)
                {
                    g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                    g_mmi_imm_is_default_init_input_mode_overide = MMI_TRUE;
                }
            }
        }	

        g_mmi_imm_default_input_mode = IMM_INPUT_MODE_NONE;
    }

    /* check the input method set by user through option-> input method screen */

    /* in case exit from sub lang screen we need to check on editors like input address */
    if (mmi_imm_is_curr_allow_input_mode(g_mmi_imm_user_desired_input_mode))
    {
        if (g_mmi_imm_user_desired_input_mode != IMM_INPUT_MODE_NONE && !mmi_is_redrawing_bk_screens())
        {
            if (mmi_imm_is_curr_allow_input_mode(g_mmi_imm_user_desired_input_mode))
            {
                g_mmi_imm_current_input_mode = g_mmi_imm_user_desired_input_mode;
                g_mmi_imm_is_default_init_input_mode_overide = MMI_TRUE;
            }
            /* g_mmi_imm_user_desired_input_mode would be reset when mmi_imm_connect */
        }
    }
    else
    {
        g_mmi_imm_user_desired_input_mode = IMM_INPUT_MODE_NONE ;
    }


    if (g_mmi_imm_app_desired_input_mode != IMM_INPUT_MODE_NONE && !mmi_is_redrawing_bk_screens())
    {
        if (mmi_imm_is_curr_allow_input_mode(g_mmi_imm_app_desired_input_mode))
        {
            g_mmi_imm_current_input_mode = g_mmi_imm_app_desired_input_mode;
            g_mmi_imm_is_default_init_input_mode_overide = MMI_TRUE;
        }

        g_mmi_imm_app_desired_input_mode = IMM_INPUT_MODE_NONE;
    }

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)

    mmi_imm_set_curr_allowed_writing_lang_by_curr_allowed_modes();
    if (g_mmi_imm_history_writing_lang != IME_WRITING_LANG_NONE) /* Resume writing language which from history */
    {
        g_mmi_imm_curr_writing_lang = g_mmi_imm_history_writing_lang;
        g_mmi_imm_history_writing_lang = IME_WRITING_LANG_NONE;
    }
#endif
#if defined(__MMI_IME_V3__)
    if (g_mmi_imm_current_input_mode == IMM_INPUT_MODE_123_SYMBOLS && need_reset)
    {    
        for(i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i++)
        {
            if (g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_123
                && g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_ABC)
            {
#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
                if (g_mmi_imm_last_input_mode != IMM_INPUT_MODE_NONE)
                {
                    if (mmi_imm_is_curr_allow_input_mode(g_mmi_imm_last_input_mode))
                    {
                        g_mmi_imm_current_input_mode = g_mmi_imm_last_input_mode;
                    }
                }
                else
#endif

                if (g_mmi_imm_curr_allowed_input_mode[0].mode_id != IMM_INPUT_MODE_123_SYMBOLS)
                {
                    g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[0].mode_id;
                }
                else
                {
                    g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[1].mode_id;
                }
            }
        }
    }
#endif
    g_mmi_imm_initial_mode_detail = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);

#if defined(__MMI_IME_V3__)
    mmi_imc_initial_selection_mode_list();
    #if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
    mmi_imm_set_handwriting_default_input_mode(IMM_INPUT_MODE_SM_PINYIN);
    #endif
#endif


    return IMM_MESSAGE_ID_NONE;


}


#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_is_valid_uppercase_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imm_is_valid_uppercase_input_mode(mmi_imm_input_mode_enum input_mode, mmi_imm_input_mode_enum *mode_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (input_mode == IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC)
    {
        for (i = 0; mode_array[i] != IMM_INPUT_MODE_NONE; i++)
        {
            if (mode_array[i] == IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC)
            {
                return MMI_FALSE;
            }
        }

        return MMI_TRUE;
    }
    else if (input_mode == IMM_INPUT_MODE_SMART_UPPERCASE_ABC)
    {
        for (i = 0; mode_array[i] != IMM_INPUT_MODE_NONE; i++)
        {
            if (mode_array[i] == IMM_INPUT_MODE_SMART_LOWERCASE_ABC)
            {
                return MMI_FALSE;
            }
        }

        return MMI_TRUE;
    }
    else if (input_mode == IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC)
    {
        for (i = 0; mode_array[i] != IMM_INPUT_MODE_NONE; i++)
        {
            if (mode_array[i] == IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC)
            {
                return MMI_FALSE;
            }
        }

        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_input_mode_array_item
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
const sIMEModeDetails * mmi_imm_get_input_mode_array_item(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
    {
        if (gIMEModeArray[i].imm_mode_id == input_mode)
        {
            return &gIMEModeArray[i];
        }
        i++;
    }

    return NULL;

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_corresponding_multitap_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
const sIMEModeDetails * mmi_imm_get_corresponding_multitap_mode(mmi_imm_input_mode_enum input_mode, U16 mode_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    const sIMEModeDetails * mode_details_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);

    if (mode_details_ptr == NULL)
    {
        return NULL;
    }
	if(mode_details_ptr->lang_id == IME_WRITING_LANG_123)
	{
		return mode_details_ptr;
	}
    while (gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
    {
        if(mode_details_ptr->lang_id == IME_WRITING_LANG_HABC)
	{
            if (gIMEModeArray[i].lang_id == mode_details_ptr->lang_id&& (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP))
                return &gIMEModeArray[i];
	}
       else if (gIMEModeArray[i].lang_id == mode_details_ptr->lang_id
            && (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP))
        {
            if (mode_case)
            {
                if (gIMEModeArray[i].Mode_Special_Attrib & mode_case)
                {
                    return &gIMEModeArray[i];
                }
            }
            else 
            {
                if (!(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE )
                    && !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                    && !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE))
                {
                    return &gIMEModeArray[i];
                }
                else if ((gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)
                    && (mode_details_ptr->Mode_Special_Attrib & IME_LANG_ATTR_PHONETIC))
                {
                    return &gIMEModeArray[i];
                }
            }
        }
        i++;
    }

    return NULL;


}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_corresponding_smart_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
const sIMEModeDetails * mmi_imm_get_corresponding_smart_mode(mmi_imm_input_mode_enum input_mode, U16 mode_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    const sIMEModeDetails * mode_details_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);

    if (mode_details_ptr == NULL)
    {
        return NULL;
    }

    while (gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
    {
        if (gIMEModeArray[i].lang_id == mode_details_ptr->lang_id
            && (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART))
        {
            if (mode_case)
            {
                if (gIMEModeArray[i].Mode_Special_Attrib & mode_case)
                {
                    return &gIMEModeArray[i];
                }
            }
            else 
            {
                if (!(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE )
                    && !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                    && !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE))
                {
                    return &gIMEModeArray[i];
                }
                else if ((gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)
                    && (mode_details_ptr->Mode_Special_Attrib & IME_LANG_ATTR_PHONETIC))
                {
                    return &gIMEModeArray[i];
                }
            }
        }
        i++;
    }

    return NULL;

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_corresponding_smart_lower_case_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
const sIMEModeDetails * mmi_imm_get_corresponding_smart_lower_case_mode(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    const sIMEModeDetails * mode_details_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (input_mode == IMM_INPUT_MODE_SMART_THAI
        || input_mode == IMM_INPUT_MODE_MULTITAP_THAI)
    {
        mode_details_ptr = mmi_imm_get_input_mode_array_item(IMM_INPUT_MODE_SMART_THAI);

        if (mode_details_ptr)
        {
            return mode_details_ptr;
        }
        else
        {
            return NULL;
        }
    }

    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);

    if (mode_details_ptr == NULL)
    {
        return NULL;
    }

    while (gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
    {
        if (gIMEModeArray[i].lang_id == mode_details_ptr->lang_id 
            && (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
            && (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART))
        {
            return &gIMEModeArray[i];
        }
        else if (gIMEModeArray[i].lang_id == mode_details_ptr->lang_id 
            && !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
            && !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
            && !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
            && (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART))
        {
            return &gIMEModeArray[i];
        }
        i++;
    }

    return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_multitap_input_mode_by_writing_language
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_multitap_input_mode_by_writing_language(mmi_imm_input_mode_enum *input_mode_table, mmi_imm_support_writing_lang_enum lang_id, S32 max_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
    {
        if (gIMEModeArray[i].lang_id == lang_id
            && (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
            && (gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
            && (gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_SENTENCE))
        {
            input_mode_table[j++] = gIMEModeArray[i].imm_mode_id;
        }

        if (j >= max_size)
        {
            break;
        }

        i++;
    }

    return j;

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_create_input_method_list
* DESCRIPTION
*  Prepare allowed input mode list for input method list in option menu
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_message_id_enum mmi_imm_create_input_method_list(U32 input_type, mmi_imm_input_mode_enum input_mode_array[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j =0, p = 0;
    U32 input_type_int = input_type & (~IMM_INPUT_TYPE_MASK);
    MMI_BOOL password_type = MMI_FALSE, enable_uppercase_abc = MMI_FALSE;
    mmi_imm_support_writing_lang_enum old_writing_lang = IME_WRITING_LANG_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Error Handling */
    if (input_type_int == IMM_INPUT_TYPE_USER_SPECIFIC && input_mode_array == NULL)
        return IMM_MESSAGE_ID_ERROR;

    if ((input_type & IMM_INPUT_TYPE_EXT_PASSWORD))
        password_type = MMI_TRUE;

    if ((input_type & IMM_INPUT_TYPE_EXT_ENGLISH_UPPERCASE)
        || (input_type & IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE))
    {
        enable_uppercase_abc = MMI_TRUE;
    }

    /* reset data. */
    memset(&g_mmi_imm_curr_allowed_input_mode, 0 , sizeof(mmi_imm_input_mode_item) * IMM_INPUT_MODE_MAX_NUM);

    g_mmi_imm_current_input_type = (mmi_imm_input_type_enum)input_type;

    g_mmi_imm_user_specific_input_mode_list = input_mode_array;

    if (input_type_int == IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE ||
        input_type_int == IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE )
        input_type_int = IMM_INPUT_TYPE_ENGLISH_SENTENCE;


    /* prepare input mode array */
    if (input_type_int == IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        for (i = 0; input_mode_array[i] != IMM_INPUT_MODE_NONE; i++)
        {
            if ((p = mmi_imm_is_system_supported_input_mode(input_mode_array[i])) != -1)
            {
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
                if (!g_mmi_imm_is_smart_alphabetic_input_modes_enalbed 
                    && (gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                    && ((gIMEModeArray[p].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                    || (gIMEModeArray[p].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)))
                {
                    continue; /* If smart input method is turned off, skip the input modes*/
                }
#endif
          #if   defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
            #if defined __MMI_COSMOS_KEYPAD_SLIDER__
                if(mmi_imc_get_slider_status() == OPEN)
            #endif
                {
                if ((gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                    && !enable_uppercase_abc)
                {
                    if (!mmi_imm_is_valid_uppercase_input_mode(input_mode_array[i], input_mode_array))
                    {
                        continue;
                    }
                }
                }
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                if (IS_FILTER_CAPS)
                {
                    if (gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                    {
                        continue;
                    }
                }
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                if (!g_mmi_imm_is_first_uppercase_modes_enalbled)
                {
                    if (gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                    {
                        continue;
                    }
                }
#endif

#if defined(__MMI_IME_PLUG_IN__)
                if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)(input_mode_array[i]), 0))
                {
                    continue;
                }
#endif

                g_mmi_imm_curr_allowed_input_mode[j].mode_id = input_mode_array[i];
                g_mmi_imm_curr_allowed_input_mode[j].index = p;
                j ++;
            }
        }

        g_mmi_imm_curr_allowed_input_mode[j].mode_id = IMM_INPUT_MODE_NONE;
        g_mmi_imm_curr_allowed_input_mode[j].index = -1;

        /* No item in the input_mode_array is supported by the system.  */
        if (j == 0)
        {
            return IMM_MESSAGE_ID_ERROR;
        }
    }
#if defined(__MMI_IME_FTE_ENHANCE__)
    else if ((input_type_int & IMM_INPUT_TYPE_URL) || 
        (input_type_int & IMM_INPUT_TYPE_EMAIL))
    {
#if defined(__MMI_IME_PLUG_IN__)
        i = 0;
        if (!mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC, 0))
        {
            g_mmi_imm_curr_allowed_input_mode[i].mode_id = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
            g_mmi_imm_curr_allowed_input_mode[i].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);
            i++;
        }
        if (!mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC, 0))
        {
            g_mmi_imm_curr_allowed_input_mode[i].mode_id = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC;
            g_mmi_imm_curr_allowed_input_mode[i].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC);
            i++;
        }
        if (!mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)IMM_INPUT_MODE_123_SYMBOLS, 0))
        {
            g_mmi_imm_curr_allowed_input_mode[i].mode_id = IMM_INPUT_MODE_123_SYMBOLS;
            g_mmi_imm_curr_allowed_input_mode[i].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_123_SYMBOLS);
            i++;
        }
        if (i == 0)
        {
            return IMM_MESSAGE_ID_ERROR;
        }

        g_mmi_imm_curr_allowed_input_mode[i].mode_id = IMM_INPUT_MODE_NONE;
#else
        g_mmi_imm_curr_allowed_input_mode[0].mode_id = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
        g_mmi_imm_curr_allowed_input_mode[0].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);
        g_mmi_imm_curr_allowed_input_mode[1].mode_id = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC;
        g_mmi_imm_curr_allowed_input_mode[1].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC);
        g_mmi_imm_curr_allowed_input_mode[2].mode_id = IMM_INPUT_MODE_123_SYMBOLS;
        g_mmi_imm_curr_allowed_input_mode[2].index = mmi_imm_is_system_supported_input_mode(IMM_INPUT_MODE_123_SYMBOLS);
        g_mmi_imm_curr_allowed_input_mode[3].mode_id = IMM_INPUT_MODE_NONE;
#endif
    }
#endif
    else
    {
        for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
        {
            if (mmi_imm_is_system_supported_input_mode(gIMEModeArray[i].imm_mode_id) == -1)
            { 
                continue;  
            }

            if ((gIMEModeArray[i].supported_input_type_flag & input_type_int))
            {            
                if (password_type)
                {
                    if (((gIMEModeArray[i].Mode_Special_Attrib) & (IME_MODE_ATTR_SMART)))
                    {
                    }
                    else
                    {
          #if   defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
                    #if defined __MMI_COSMOS_KEYPAD_SLIDER__
                        if(mmi_imc_get_slider_status() == OPEN)
                    #endif
                        {
                        if ((gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                            && !enable_uppercase_abc)
                        {
                            continue;
                        }
                        }
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                        if (IS_FILTER_CAPS)
                        {
                            if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                            {
                                continue;
                            }
                        }
#endif
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                        if (!g_mmi_imm_is_first_uppercase_modes_enalbled)
                        {
                            if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                            {
                                continue;
                            }
                        }
#endif
#if defined(__MMI_IME_PLUG_IN__)
                        if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)(gIMEModeArray[i].imm_mode_id), 0))
                        {
                            continue;
                        }
#endif

                        g_mmi_imm_curr_allowed_input_mode[j].mode_id = gIMEModeArray[i].imm_mode_id;
                        g_mmi_imm_curr_allowed_input_mode[j].index = i;
                        j++;
                    }
                }
                else
                {
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
                    if (!g_mmi_imm_is_smart_alphabetic_input_modes_enalbed 
                        && (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                        && ((gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                        || (gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)))
                    {
                        continue; /* If smart input method is turned off, skip the input modes*/
                    }
#endif
          #if   defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
                    #if defined __MMI_COSMOS_KEYPAD_SLIDER__
                    if(mmi_imc_get_slider_status() == OPEN)
                    #endif
                    {
                    if ((gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                        && !enable_uppercase_abc)
                    {
                        continue;
                    }
                    }
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    if (IS_FILTER_CAPS)
                    {
                        if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                        {
                            continue;
                        }
                    }
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                    if (!g_mmi_imm_is_first_uppercase_modes_enalbled)
                    {
                        if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                        {
                            continue;
                        }
                    }
#endif

#if defined(__MMI_IME_PLUG_IN__)
                    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE, (U32)(gIMEModeArray[i].imm_mode_id), 0))
                    {
                        continue;
                    }
#endif

                    g_mmi_imm_curr_allowed_input_mode[j].mode_id = gIMEModeArray[i].imm_mode_id;
                    g_mmi_imm_curr_allowed_input_mode[j].index = i;
                    j++;
                }
            }
        }
        g_mmi_imm_curr_allowed_input_mode[j].mode_id = IMM_INPUT_MODE_NONE;
        g_mmi_imm_curr_allowed_input_mode[j].index = -1;

        /* No input method is supported by the system.  */
        if (j == 0)
        {
            return IMM_MESSAGE_ID_ERROR;
        }
    }

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    old_writing_lang = g_mmi_imm_curr_writing_lang;
    mmi_imm_set_curr_allowed_writing_lang_by_curr_allowed_modes();
    g_mmi_imm_curr_writing_lang = old_writing_lang;
#endif

    return IMM_MESSAGE_ID_NONE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_init
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
    ReadValue(NVRAM_IME_SMART_MODE_CONFIG, &data, DS_BYTE, &error);

    if (data == 0xFF)
    {
        g_mmi_imm_is_smart_alphabetic_input_modes_enalbed = MMI_TRUE;
    }
    else
    {
        g_mmi_imm_is_smart_alphabetic_input_modes_enalbed = (MMI_BOOL)data;
    }
#endif

#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)

    ReadValue(NVRAM_IME_AUTO_CAPITALIZATION_FLAG, &data, DS_BYTE, &error);
    if (data == 0xFF)
    {
        g_mmi_imm_is_auto_capitalization_enabled = MMI_TRUE;
    }
    else
    {
        g_mmi_imm_is_auto_capitalization_enabled = (MMI_BOOL)data;
    }
#endif

#if defined(__MMI_IME_AUTO_COMPLETION_SETTING__)

    ReadValue(NVRAM_IME_AUTO_COMPLETION_FLAG, &data, DS_BYTE, &error);
    if (data == 0xFF)
    {
        g_mmi_imm_is_auto_completion_enabled = MMI_TRUE;
    }
    else
    {
        g_mmi_imm_is_auto_completion_enabled = (MMI_BOOL)data;
    }
#endif

#if defined(__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
    ReadValue(NVRAM_IME_ALPHABETIC_WORD_PREDICTION_FLAG, &data, DS_BYTE, &error);
    if (data == 0xFF)
    {
        g_mmi_imm_is_alphabetic_word_prediction_enabled = MMI_TRUE;
    }
    else
    {
        g_mmi_imm_is_alphabetic_word_prediction_enabled = (MMI_BOOL)data;
    }
#endif

#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
    ReadValue(NVRAM_IME_CHINESE_WORD_PREDICTION_FLAG, &data, DS_BYTE, &error);
    if (data == 0xFF)
    {
        g_mmi_imm_is_chinese_word_prediction_enabled = MMI_TRUE;
    }
    else
    {
        g_mmi_imm_is_chinese_word_prediction_enabled = (MMI_BOOL)data;
    }
#endif
#if  defined(__MMI_IME_V3__)

	//Auto Space
    ReadValue(NVRAM_IME_AUTO_SPACE_FLAG, &data, DS_BYTE, &error);
    if (data == 0xFF)
    {
        g_mmi_imm_is_auto_space_enabled = MMI_TRUE;
    }
    else
    {
        g_mmi_imm_is_auto_space_enabled = (MMI_BOOL)data;
    }
	

	//Vibration
	ReadValue(NVRAM_IME_VIBRATION_FLAG, &data, DS_BYTE, &error);
    if (data == 0xFF)
    {
        g_mmi_imm_is_vibration_enabled = MMI_TRUE;
    }
    else
    {
        g_mmi_imm_is_vibration_enabled = (MMI_BOOL)data;
    }


	//Touch feedback
	ReadValue(NVRAM_IME_SOUND_FEEDBACK_FLAG, &data, DS_BYTE, &error);
    if (data == 0xFF)
    {
        g_mmi_imm_is_sound_feedback_enabled = MMI_TRUE;
    }
    else
    {
        g_mmi_imm_is_sound_feedback_enabled = (MMI_BOOL)data;
    }
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)

	// language follow vk
	ReadValue(NVRAM_SETTING_LANGUAGE_FOLLOW_VK, &data, DS_BYTE, &error);
	g_current_handwriting_lang_id = (mmi_imm_support_writing_lang_enum)data;

	
	// handwriting on/off
	ReadValue(NVRAM_SETTING_HANDWRITING_ON, &data, DS_BYTE, &error);
	g_is_handwriting_setting_on = (MMI_BOOL)data;
	
	// stroke color index
	ReadValue(NVRAM_SETTING_STROKE_COLOR_INDEX, &data, DS_BYTE, &error);
#if 0
/* under construction !*/
/* under construction !*/
#endif	
	if (data >= IMM_MAX_STROKE_COLOR_NUM)
		data = IMM_MAX_STROKE_COLOR_NUM - 1;
	g_current_stroke_color_index = data;	

	//handwriting trace width
	ReadValue(NVRAM_SETTING_PEN_WIDTH, &data, DS_BYTE, &error);
	
	if (data >= IMM_MAX_STROKE_WIDTH || data < IMM_MIN_STROKE_WIDTH)
		data = IMM_MIN_STROKE_WIDTH;
	g_current_stroke_width = data;
	
#endif //defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)

#endif

#if defined __MMI_IME_INPUT_PATTERN_SETTING__

    ReadValue(NVRAM_IME_INPUT_PATTERN, &data, DS_BYTE, &error);
    if (data == 0xFF)
    {
        /* Set default 
        240x320                         240x400                   320x480     
        Normal keypad                Qwerty                          Qwerty                    Qwerty     
        Reduce keypad            Alphanumeric keypad                 Alphanumeric keypad       Qwerty  */

#if defined(__MMI_REDUCED_KEYPAD__) && !defined (__MMI_MAINLCD_320X480__)
#if defined (__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
        g_mmi_imm_keypad_type = IMM_KEYPAD_ALPHANUMERIC;
#else
        g_mmi_imm_keypad_type = IMM_KEYPAD_QWERTY;
#endif
#else
        g_mmi_imm_keypad_type = IMM_KEYPAD_QWERTY;
#endif 
    }
    else
    {
        g_mmi_imm_keypad_type = data;
    }

#endif

    mmi_imm_init_prefered_input_mode();

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    mmi_imm_init_writing_lang();
#endif

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
    mmi_imm_handwriting_memory_card_init();
#endif

#if defined(__MMI_IME_FUZZY_PINYIN__)
    mmi_imm_init_fuzzy_pinyin_setting();
#endif

#if defined (__MMI_PREFER_INPUT_METHOD__)
#ifndef __COSMOS_MMI_PACKAGE__
    mmi_imesettings_init_prefered_inputmethod_list();
#endif 
#endif 

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
    mmi_imm_init_pen_speed();
#endif

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_connect
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct imc_msg;
    UI_character_type allowed_numbers[] = L"0-9";
	  const sIMEModeDetails * mode_details_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_imm_user_desired_input_mode != IMM_INPUT_MODE_NONE && !mmi_is_redrawing_bk_screens())
    {
        if (mmi_imm_is_curr_allow_input_mode(g_mmi_imm_user_desired_input_mode))
        {
            g_mmi_imm_current_input_mode = g_mmi_imm_user_desired_input_mode;
            g_mmi_imm_is_default_init_input_mode_overide = MMI_TRUE;
        }

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        
			  mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);
			  g_mmi_imm_curr_writing_lang = mode_details_ptr->lang_id;
        if (g_mmi_imm_user_desired_writing_lang != IME_WRITING_LANG_NONE)
        {
            g_mmi_imm_curr_writing_lang = g_mmi_imm_user_desired_writing_lang;
            g_mmi_imm_user_desired_writing_lang = IME_WRITING_LANG_NONE;
            g_mmi_imm_is_default_init_input_mode_overide = MMI_FALSE;
        }
#endif
		g_mmi_imm_user_desired_input_mode = IMM_INPUT_MODE_NONE;
        imc_msg.message_id = MMI_IMC_MESSAGE_MODE_CHANGED;
        mmi_imc_send_message(&imc_msg);
    }    

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    if (mmi_imc_is_editor_ready_when_connecting())
    {
        mmi_imm_set_initial_input_mode_by_auto_capitalization();
    }
#endif

#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
    mmi_imm_config_auto_capitalization_setting_changed(MMI_FALSE);
#endif

    if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_QUICK_SEARCH)
    {
        MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }
    if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_EMAIL)
    {
        MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
        mmi_imm_set_characters(MMI_TRUE, g_mmi_imm_email_allowed);
    }
    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_URL)
    {
        MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
        mmi_imm_set_characters(MMI_TRUE, g_mmi_imm_url_allowed_characters);
    }

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_NUMERIC
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        || g_mmi_imm_current_input_type & IMM_INPUT_TYPE_PHONE_NUMBER
        || g_mmi_imm_current_input_type & IMM_INPUT_TYPE_DECIMAL_NUMERIC
        || g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_NUMERIC
        || g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC
        || g_mmi_imm_current_input_type & IMM_INPUT_TYPE_KEYPAD_NUMERIC
        || g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIM_NUMERIC
        || g_mmi_imm_current_input_type & IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR
#endif    
        )
    {
        mmi_imc_disable_symbol_picker();
    }

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_NUMERIC)
    {
        mmi_imm_set_characters(MMI_TRUE, allowed_numbers);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_disconnect
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
    if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_SENTENCE
        || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ASCII_CHAR
        || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ENGLISH_SENTENCE
        || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        if (g_mmi_imm_current_input_mode != IMM_INPUT_MODE_123_SYMBOLS
            && g_mmi_imm_current_input_mode != IMM_INPUT_MODE_PHONE_NUMBER
            && g_mmi_imm_current_input_mode != IMM_INPUT_MODE_ARABIC_NUMERIC)
        {
            g_mmi_imm_last_input_mode = g_mmi_imm_current_input_mode;
        }
    }
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    g_mmi_imm_is_first_uppercase_modes_enalbled = MMI_TRUE;
#endif

    g_mmi_imm_editor_type = MMI_IME_EDITOR_TYPE_UNKNOWN;

    g_mmi_imm_is_default_init_input_mode_overide = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_default_allowed_and_disabled_chars
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imm_set_default_allowed_and_disabled_chars(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const UI_character_type *str_allowed = NULL, *str_disabled = NULL;
    S32 i = 0;
#ifdef __MMI_TOUCH_SCREEN__
    gui_virtual_keyboard_pen_enum disabled_events[MMI_IMM_MAX_DISABLE_CHARACTER_NUM];
    mmi_imc_message_struct imc_msg = {0};
#endif /* __MMI_TOUCH_SCREEN__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(g_mmi_imm_default_allowed_characters, 0, sizeof(UI_character_type) * (MMI_IMM_MAX_ALLOWED_CHARACTER_NUM));
    memset(g_mmi_imm_default_disabled_characters, 0, sizeof(UI_character_type) * (MMI_IMM_MAX_DISABLE_CHARACTER_NUM));

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status() == CLOSE) 
#endif     
    {	
    for (i = 0; i < MMI_IMM_MAX_DISABLE_CHARACTER_NUM; i++)
    {
        g_mmi_imm_default_disabled_events[i] = GUI_VKBD_PEN_NONE;
    }	
    }
#endif /* __MMI_TOUCH_SCREEN__ */

    i = 0;

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EXT_PASSWORD)
    {
        MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }
    else if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EMAIL) || 
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_URL))
    {
        MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }


    if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIM_NUMERIC) ||
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_PHONE_NUMBER))
    {
        if ((MMI_current_input_ext_type & INPUT_TYPE_EXT_SIM_NUMERIC) || 
            (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIM_NUMERIC))
        {
            str_allowed = g_mmi_imm_phone_number_sim_valid_characters;
            str_disabled = g_mmi_imm_phone_number_sim_invalid_characters;
        }
        else
        {
            str_allowed = g_mmi_imm_phone_number_valid_characters;
            str_disabled = g_mmi_imm_phone_number_invalid_characters;
        }
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE) 
#endif        
        {	
#if !defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_HIDE;
#endif
        disabled_events[i++] = GUI_VKBD_PEN_SPACE;
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) 
        disabled_events[i++] = GUI_VKBD_PEN_SYMBPICKER;
#endif
        }
#endif /* __MMI_TOUCH_SCREEN__ */
    }
    else if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR)
    {
        str_allowed = g_mmi_imm_phone_number_wildchar_valid_characters;
        str_disabled = g_mmi_imm_phone_number_invalid_characters;
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE) 
#endif 
        {	
#if !defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_HIDE;
#endif
        disabled_events[i++] = GUI_VKBD_PEN_SPACE;
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) 
        disabled_events[i++] = GUI_VKBD_PEN_SYMBPICKER;
#endif
        }
#endif /* __MMI_TOUCH_SCREEN__ */
    }
    else if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_DECIMAL_NUMERIC)
    {
        str_allowed = g_mmi_imm_decimal_numeric_valid_characters;
#if defined(__MMI_IME_FTE_ENHANCE__)
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE) 
#endif 
        {	
        str_disabled = g_mmi_imm_decimal_numberic_invalid_characters;
        }
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        else
        {
            str_disabled = g_mmi_imm_signed_decimal_numberic_invalid_characters;
        }
#endif 
#else
        str_disabled = g_mmi_imm_signed_decimal_numberic_invalid_characters;
#endif
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE) 
#endif 
        {	
#if !defined(__MMI_IME_FTE_ENHANCE__)   
        disabled_events[i++] = GUI_VKBD_PEN_HIDE;
#endif
        disabled_events[i++] = GUI_VKBD_PEN_SPACE;
        }
#endif /* __MMI_TOUCH_SCREEN__ */

    }
#if defined(__MMI_IME_FTE_ENHANCE__)
    else if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_NUMERIC)
    {
        str_allowed = g_mmi_imm_numeric_valid_characters;
        str_disabled = g_mmi_imm_numeric_invalid_characters;
    }
#endif
    else if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_NUMERIC)    
    {
        str_allowed = g_mmi_imm_signed_numeric_valid_characters;
        str_disabled = g_mmi_imm_signed_numberic_invalid_characters;

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE) 
#endif 
        {	
#if !defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_HIDE;
#endif
        disabled_events[i++] = GUI_VKBD_PEN_SPACE;
        disabled_events[i++] = GUI_VKBD_PEN_SYMBPICKER;
        }
#endif /* __MMI_TOUCH_SCREEN__ */
    }
    else if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)   
    {
        str_allowed = g_mmi_imm_signed_decimal_numeric_valid_characters;
        str_disabled = g_mmi_imm_signed_decimal_numberic_invalid_characters;
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE) 
#endif 
        {	
#if !defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_HIDE;
#endif
        disabled_events[i++] = GUI_VKBD_PEN_SPACE;
        disabled_events[i++] = GUI_VKBD_PEN_SYMBPICKER;
        }    
#endif /* __MMI_TOUCH_SCREEN__ */
    }
    else if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_KEYPAD_NUMERIC)   
    {
        str_allowed = g_mmi_imm_keypad_numberic_valid_characters;
        str_disabled = g_mmi_imm_keypad_numberic_invalid_characters;

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE) 
#endif 
        {	
#if !defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_HIDE;
#endif
        disabled_events[i++] = GUI_VKBD_PEN_SPACE;
        disabled_events[i++] = GUI_VKBD_PEN_SYMBPICKER;
        }   
#endif /* __MMI_TOUCH_SCREEN__ */

    }
    else if  (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_ASCII_CHAR)
    {
        str_allowed = g_mmi_imm_ascii_allowed;
    }
    else if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_QUICK_SEARCH)   
    {

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE)  
#endif 
        {	
        disabled_events[i++] = GUI_VKBD_PEN_NEWLINE;
#if defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE;
        disabled_events[i++] = GUI_VKBD_PEN_STROKE_DEPART;   
        disabled_events[i++] = GUI_VKBD_PEN_ZI_STROKE_9;
#endif
        }
#endif /* __MMI_TOUCH_SCREEN__ */

    }

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_ADD_NEW_WORD)
    {
        str_disabled = g_mmi_imm_new_word_invalid_characters;
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status() == CLOSE) 
#endif 
        {	
            disabled_events[i++] = GUI_VKBD_PEN_SPACE;
#if defined(__MMI_IME_V3__)
            disabled_events[i++] = GUI_VKBD_PEN_CHANGE_MODE;
#endif
        }
#endif /* __MMI_TOUCH_SCREEN__ */  
    }

    switch(mmi_imm_get_curr_input_mode())
    {

#if !defined(__MMI_IME_FTE_ENHANCE__)
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:        
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:	
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:	        
#ifdef __MMI_TOUCH_SCREEN__ 
#if !defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_SYMBPICKER;
#endif
#endif /* __MMI_TOUCH_SCREEN__ */
        break;
#endif /* !defined(__MMI_IME_FTE_ENHANCE__) */

#if defined(__MMI_IME_FTE_ENHANCE__) && defined (__MMI_TOUCH_SCREEN__)
    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC:
    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC:
        if (str_disabled == NULL)
        {
            str_disabled = g_mmi_imm_no_number_invalid_characters;
        }
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM;
        break;
    case IMM_INPUT_MODE_123:
        str_allowed = g_mmi_imm_numeric_valid_characters;
        str_disabled = g_mmi_imm_numeric_invalid_characters;
        break;
#endif


    case IMM_INPUT_MODE_MULTITAP_HEBREW:
#ifdef __MMI_TOUCH_SCREEN__
        disabled_events[i++] = GUI_VKBD_PEN_CAPSLOCK;
#endif /* __MMI_TOUCH_SCREEN__ */        
        break;

    default:
        break;
    }

#if defined(__MMI_MAINLCD_320X480__) && defined(__MMI_TOUCH_SCREEN__)
    if (mmi_imm_get_current_allowed_input_mode_num() <= 1)
    {
        disabled_events[i++] = GUI_VKBD_PEN_DISPLAY_CALLBACK;
    }
#endif


#ifdef __MMI_TOUCH_SCREEN__
    if (!mmi_imm_test_caps_switch(mmi_imm_get_curr_input_mode(), g_mmi_imm_curr_allowed_input_mode))
    {
        disabled_events[i++] = GUI_VKBD_PEN_CAPSLOCK;
#if defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK;
        disabled_events[i++] = GUI_VKBD_PEN_CAPSLOCK;
#endif
    }
    else if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_QUICK_SEARCH
        && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_MULTITAP_THAI && mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SMART_THAI))
    {
        disabled_events[i++] = GUI_VKBD_PEN_CAPSLOCK;
#if defined(__MMI_IME_FTE_ENHANCE__)
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK;
        disabled_events[i++] = GUI_VKBD_PEN_CAPSLOCK;
#endif
    }

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_URL)
    {
        disabled_events[i++] = GUI_VKBD_PEN_SPACE;
    }

    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL)
    {
        disabled_events[i++] = GUI_VKBD_PEN_NEWLINE;
#if defined(__MMI_IME_FTE_ENHANCE__)    
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE;
#endif
    }
    {

        const sIMEModeDetails * mode_details_ptr;
        mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());

        if (!mode_details_ptr)
        {
            MMI_ASSERT(0);
        }
#if !defined(__NO_HANDWRITING__) && !defined(__MMI_IME_FTE_ENHANCE__)
        if (!mmi_ime_hand_writing_hw_type_query((mmi_imc_pen_handwriting_type_enum)(U8)(mode_details_ptr->Handwriting_Attrib)) &&
            (mmi_imc_pen_get_handwriting_style() == MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK))
        {
            disabled_events[i++] = GUI_VKBD_PEN_HIDE;
        }
#endif
    }

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__    
    if(mmi_imc_get_slider_status() == CLOSE)
#endif  
    {
    if (g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1 || 
        g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1 ||
        g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE)
    {
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_SYM_PREV_PAGE;
    }
    else if (g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_4 || 
        g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4 ||
        g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE)
    {
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_SYM_NEXT_PAGE;
    }
    else if ((g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_3 || 
        g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_3) &&
        !(g_mmi_imm_current_input_type == IMM_INPUT_TYPE_SENTENCE))
    {
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_SYM_NEXT_PAGE;
    }
    }
#endif

    imc_msg.message_id = MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED;
    if (mmi_imc_send_message(&imc_msg))
    {
        disabled_events[i++] = GUI_VKBD_PEN_BAKSPACE;
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__    
    if(mmi_imc_get_slider_status() == CLOSE) 
#endif     
    {
    if (mmi_imc_pen_get_input_style_list(NULL, NULL, 0, NULL) == 1)
    {
        disabled_events[i++] = GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING;
        disabled_events[i++] = GUI_VKBD_PEN_HANDWRITING;
    }
    }
#endif

    if (str_allowed)
    {
        MMI_ASSERT(MMI_IMM_MAX_ALLOWED_CHARACTER_NUM >= (mmi_ucs2strlen((const CHAR *)str_allowed) + 1));
        memcpy(g_mmi_imm_default_allowed_characters, str_allowed, sizeof(UI_character_type) * (mmi_ucs2strlen((const CHAR *)str_allowed) + 1));
    }


    if (str_disabled)
    {
        MMI_ASSERT(MMI_IMM_MAX_DISABLE_CHARACTER_NUM >= (mmi_ucs2strlen((const CHAR *)str_disabled) + 1));
        memcpy(g_mmi_imm_default_disabled_characters, str_disabled, sizeof(UI_character_type) * (mmi_ucs2strlen((const CHAR *)str_disabled) + 1));
    }
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD)
    {
        disabled_events[i++] = GUI_VKBD_PEN_CHANGE_MODE;
    }
    else if (g_mmi_imm_current_input_mode == IMM_INPUT_MODE_123_SYMBOLS)
    {
        if (!mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC))
        {
            disabled_events[i++] = GUI_VKBD_PEN_V3_123SYM;
        }
    }
#endif

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status() == CLOSE) 
#endif 
    {	
    if (i > 0)
    {   
        i--;
        MMI_ASSERT(i < MMI_IMM_MAX_DISABLE_CHARACTER_NUM);
        for (; i >= 0; i-- )
        {
            g_mmi_imm_default_disabled_events[i] = disabled_events[i];
        }
    }
    }
#endif /* __MMI_TOUCH_SCREEN__ */  

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_characters
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_message_id_enum mmi_imm_set_characters(MMI_BOOL is_allowed, const UI_character_type *characters_lsit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_imm_set_input_rule_by_ap = MMI_TRUE;

    if (is_allowed)
    {
        g_mmi_imm_disabled_characters[0] = 0;

        for (i = 0; characters_lsit[i]; i++)
        {
            g_mmi_imm_allowed_characters[i] = characters_lsit[i];
        }
        g_mmi_imm_allowed_characters[i] = characters_lsit[i];
    }
    else
    {
        g_mmi_imm_allowed_characters[0] = 0;

        for (i = 0; characters_lsit[i]; i++)
        {
            g_mmi_imm_disabled_characters[i] = characters_lsit[i];
        }
        g_mmi_imm_disabled_characters[i] = characters_lsit[i];
    }

    return IMM_MESSAGE_ID_NONE;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_allowed_or_disabled_characters
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_get_allowed_or_disabled_characters(MMI_BOOL * is_allowed, UI_string_type characters_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imm_set_default_allowed_and_disabled_chars();

    characters_list[0] = 0;

    if (g_mmi_imm_allowed_characters[0] != 0)
    {
        *is_allowed = MMI_TRUE;

        for (i = 0; g_mmi_imm_allowed_characters[i]; i++, j++)
        {
            characters_list[j] = g_mmi_imm_allowed_characters[i];
        }

        characters_list[j] = 0;

        ret = MMI_TRUE;
    }
    else if (g_mmi_imm_default_allowed_characters[0] != 0)
    {
        *is_allowed = MMI_TRUE;

        for (i = 0; g_mmi_imm_default_allowed_characters[i]; i++, j++)
        {
            characters_list[j] = g_mmi_imm_default_allowed_characters[i];
        }

        characters_list[j] = 0;

        ret = MMI_TRUE;
    }


    if (g_mmi_imm_disabled_characters[0] != 0 || g_mmi_imm_default_disabled_characters[0] != 0)
    {
        if (ret == MMI_TRUE && *is_allowed == MMI_TRUE)
        {
            S32 str_len = mmi_ucs2strlen((const CHAR*)characters_list);
            UI_string_type str_ptr = &characters_list[0];

            for (i = 0; i < str_len && characters_list[i]!= 0; i++)
            {
                if (characters_list[i+1] && characters_list[i+2])
                {
                    if (characters_list[i+1] == (UI_character_type) '-' && 
                        characters_list[i] != (UI_character_type) '\\' && 
                        characters_list[i+2] > characters_list[i])
                    {
                        /* for the special case of A-Z, a-z, 0-9 */
                        *str_ptr = characters_list[i++];
                        str_ptr++;

                        *str_ptr = characters_list[i++];
                        str_ptr++;

                        *str_ptr = characters_list[i];
                        str_ptr++;

                        continue;
                    }
                }

                if (!mmi_ucs2chr((const CHAR *)&g_mmi_imm_disabled_characters[0], characters_list[i]) &&
                    !mmi_ucs2chr((const CHAR *)&g_mmi_imm_default_disabled_characters[0], characters_list[i]))
                {
                    *str_ptr = characters_list[i];
                    str_ptr++;
                }
            }

            *str_ptr = 0;

            MMI_ASSERT(characters_list[0]);

            ret = MMI_TRUE;
        }
        else
        {
            *is_allowed = MMI_FALSE;

            for (i = 0; g_mmi_imm_disabled_characters[i]; i++, j++)
            {
                characters_list[j] = g_mmi_imm_disabled_characters[i];
            }

            for (i = 0; g_mmi_imm_default_disabled_characters[i]; i++, j++)
            {
                characters_list[j] = g_mmi_imm_default_disabled_characters[i];
            }
            characters_list[j] = 0;

            ret = MMI_TRUE;
        }
    }

    return ret;

}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_imm_set_events
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_message_id_enum mmi_imm_set_events(MMI_BOOL is_allowed, const gui_virtual_keyboard_pen_enum *disable_event_keys_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imm_set_input_rule_by_ap_vk = MMI_TRUE;

    if (is_allowed)
    {
        g_mmi_imm_disabled_characters[0] = 0;
        g_mmi_imm_disabled_events[0] = GUI_VKBD_PEN_NONE;

        for (i = 0; disable_event_keys_list[i] != GUI_VKBD_PEN_NONE; i++)
        {
            g_mmi_imm_allowed_events[i] = disable_event_keys_list[i];
        }
        g_mmi_imm_allowed_events[i] = disable_event_keys_list[i];
    }
    else
    {
        g_mmi_imm_allowed_characters[0] = 0;
        g_mmi_imm_allowed_events[0] = GUI_VKBD_PEN_NONE;

        for (i = 0; disable_event_keys_list[i] != GUI_VKBD_PEN_NONE; i++)
        {
#if defined(__MMI_IME_FTE_ENHANCE__)
            if (disable_event_keys_list[i] == GUI_VKBD_PEN_NEWLINE)
            {
                g_mmi_imm_disabled_events[j++] = GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE;
            }
            else if (disable_event_keys_list[i] == GUI_VKBD_PEN_SYMBPICKER)
            {
                g_mmi_imm_disabled_events[j++] = GUI_VKBD_PEN_ALPHANUMERIC_SYMBPICKER;
            }
            else if (disable_event_keys_list[i] == GUI_VKBD_PEN_CAPSLOCK)
            {
                g_mmi_imm_disabled_events[j++] = GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK;
                g_mmi_imm_disabled_events[j++] = GUI_VKBD_PEN_CAPSLOCK;

            }
#endif
            g_mmi_imm_disabled_events[j++] = disable_event_keys_list[i];
        }
        g_mmi_imm_disabled_events[j] = disable_event_keys_list[i];
    }

    return IMM_MESSAGE_ID_NONE;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_allowed_or_disabled_events
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_get_allowed_or_disabled_events(MMI_BOOL * is_allowed, gui_virtual_keyboard_pen_enum  * events_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imm_set_default_allowed_and_disabled_chars();

    if (g_mmi_imm_allowed_events[0] != GUI_VKBD_PEN_NONE)
    {
        *is_allowed = MMI_TRUE;

        for (i = 0; g_mmi_imm_allowed_events[i]!=GUI_VKBD_PEN_NONE; i++, j++)
        {
            events_list[j] = g_mmi_imm_allowed_events[i];
        }

        events_list[j] = GUI_VKBD_PEN_NONE;

        return MMI_TRUE;
    }
    else if (g_mmi_imm_disabled_events[0] != GUI_VKBD_PEN_NONE || g_mmi_imm_default_disabled_events[0] != GUI_VKBD_PEN_NONE)
    {
        *is_allowed = MMI_FALSE;

        for (i = 0; g_mmi_imm_disabled_events[i]!=GUI_VKBD_PEN_NONE; i++, j++)
        {
            events_list[j] = g_mmi_imm_disabled_events[i];
        }

        for (i = 0; g_mmi_imm_default_disabled_events[i]!=GUI_VKBD_PEN_NONE; i++, j++)
        {
            events_list[j] = g_mmi_imm_default_disabled_events[i];
        }
        events_list[j] = GUI_VKBD_PEN_NONE;

        return MMI_TRUE;
    }
    else
    {
        events_list[0] = GUI_VKBD_PEN_NONE;
        return MMI_FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_test_caps_switch
* DESCRIPTION
*  test if it is possible to switch to captical case
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_imm_test_caps_switch(mmi_imm_input_mode_enum input_mode, mmi_imm_input_mode_item *mode_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32  temp_input_mode;
    S32 i = 0;
    const sIMEModeDetails * mode_details;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_details = mmi_imm_get_input_mode_array_item(input_mode);

    if (mode_details == NULL)
    {
        return MMI_FALSE;
    }
    temp_input_mode = ((mode_details->Handwriting_Attrib)<<4);
    temp_input_mode = ((temp_input_mode)>>20);

#if !defined(__MMI_IME_V3__)
#if defined(__MMI_MULTITAP_THAI__) || defined(__MMI_ZI_THAI__)  ||  defined (__MMI_T9_THAI__) || defined (__MMI_CSTAR_THAI__)
    if (input_mode == IMM_INPUT_MODE_MULTITAP_THAI 
        || input_mode == IMM_INPUT_MODE_SMART_THAI)
    {   
        /* Thai don't have upper case input method, but its vk use caps lock to 
        * switch its string case and symbol case */
        return MMI_TRUE;
    }
    else
#endif /* __MMI_LANG_THAI__ */
#endif
        if (temp_input_mode == IME_HAN_WRITING_INVALID_INPUT_MODE)
        {
            return MMI_FALSE;
        }
        else
        {
            while (mode_array[i].mode_id != IMM_INPUT_MODE_NONE)
            {
                if ((U32)mode_array[i].mode_id == temp_input_mode)
                    return MMI_TRUE;
                i ++;
            }
        }
        return MMI_FALSE;

}

#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
* FUNCTION
*  mmi_imm_reset_allowed_and_disabled_list
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_reset_allowed_and_disabled_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_imm_allowed_characters, 0, sizeof(UI_character_type) * (MMI_IMM_MAX_ALLOWED_CHARACTER_NUM));
    memset(g_mmi_imm_disabled_characters, 0, sizeof(UI_character_type) * (MMI_IMM_MAX_DISABLE_CHARACTER_NUM));
    UI_UNUSED_PARAMETER(i);
}
#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_imm_reset_allowed_and_disabled_list_vk
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_reset_allowed_and_disabled_list_vk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_IMM_MAX_ALLOWED_CHARACTER_NUM; i++)
    {
        g_mmi_imm_allowed_events[i] = GUI_VKBD_PEN_NONE;
    }	

    for (i = 0; i < MMI_IMM_MAX_DISABLE_CHARACTER_NUM; i++)
    {
        g_mmi_imm_disabled_events[i] = GUI_VKBD_PEN_NONE;
    }	
    UI_UNUSED_PARAMETER(i);
}

#endif
#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_imm_test_reset_allowed_and_disabled_list_for_vk
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_test_reset_allowed_and_disabled_list_vk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (MMI_BOOL)(!g_mmi_imm_set_input_rule_by_ap_vk);
}
#endif
MMI_BOOL mmi_imm_test_reset_allowed_and_disabled_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (MMI_BOOL)(!g_mmi_imm_set_input_rule_by_ap);
}
#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_imm_set_allowed_and_disabled_list_vk
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_allowed_and_disabled_list_vk(MMI_BOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imm_set_input_rule_by_ap_vk = value;
}
#endif
/*****************************************************************************
* FUNCTION
*  mmi_imm_set_allowed_and_disabled_list
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_allowed_and_disabled_list(MMI_BOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imm_set_input_rule_by_ap = value;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_test_input
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_test_input(UI_string_type cand, S32 cand_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    MMI_BOOL is_valid = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imm_test_input_ext(cand, cand_len, &is_valid, &len);

    return is_valid;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_test_input
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_test_input_ext(UI_string_type cand, S32 cand_len, MMI_BOOL *is_valid, S32 *valid_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imm_set_default_allowed_and_disabled_chars();

    *is_valid = MMI_TRUE;
    *valid_len = cand_len;

    if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_URL)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if (!applib_is_valid_url_wchar((kal_wchar)cand[i]))
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_ASCII_CHAR)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if (cand[i] > 0xFF)
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

    if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_NUMERIC) ||
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC))
    {
        mmi_imc_message_struct imc_msg;
        UI_character_type first_char;

        imc_msg.message_id    = MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION;
        imc_msg.param_0       = 0;
        imc_msg.param_1       = 0;

        first_char = (UI_character_type)mmi_imc_send_message( &imc_msg);

        if (first_char == (UI_character_type) '-')
        {
            imc_msg.message_id    = MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR;
            imc_msg.param_0       = (U32)&first_char;
            imc_msg.param_1       = 0;

            if(!mmi_imc_send_message(&imc_msg))
            {
                *is_valid = MMI_FALSE;
                *valid_len = 0;
                return;
            }

            for (i = 0; i < cand_len; i ++)
            {
                if (cand[i] == (UI_character_type) '-')
                {
                    *is_valid = MMI_FALSE;
                    *valid_len = i;
                    return;
                }
            }
        }
    }

    if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_DECIMAL_NUMERIC) ||
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC))
    {
        mmi_imc_message_struct imc_msg;

        imc_msg.message_id    = MMI_IMC_MESSAGE_CHECK_FLOAT;
        imc_msg.param_0       = 0;
        imc_msg.param_1       = 0;

        if (mmi_imc_send_message( &imc_msg))
        {
            for (i = 0; i < cand_len; i ++)
            {
                if (cand[i] == (UI_character_type) '.')
                {
                    *is_valid = MMI_FALSE;
                    *valid_len = i;
                    return;
                }
            }
        }
    }

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_ENGLISH_SENTENCE)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if ((cand[i] > 0x024F)&&(cand[i] != 0x20ac)) /* Unicode 0-024F: Basic Latin - Latin Extended-B */
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if (cand[i] == 0xD || cand[i] == 0xA || cand[i] == 0x85)
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

#if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)
    if (!mmi_imm_is_chinese_input_mode_valid())
#else
    if (!(g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SENTENCE))
#endif
    {
        for (i = 0; i < cand_len; i ++)
        {
            if ((cand[i] >= 0xFF00 && cand[i] <= 0xFFEF) || (cand[i] >= 0x2E80 && cand[i] <= 0x9FAF))
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

    if (g_mmi_imm_current_input_mode == IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC
        || g_mmi_imm_current_input_mode == IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if (cand[i] >= L'0' && cand[i] <= L'9')
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

    if (g_mmi_imm_default_allowed_characters[0] != 0)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if (!mmi_imm_check_allowed_character(cand[i], g_mmi_imm_default_allowed_characters))
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

    if (g_mmi_imm_default_disabled_characters[0] != 0)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if (mmi_imm_check_disabled_character(cand[i], g_mmi_imm_default_disabled_characters))
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

    if (g_mmi_imm_allowed_characters[0] != 0)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if (!mmi_imm_check_allowed_character(cand[i], g_mmi_imm_allowed_characters))
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }

    if (g_mmi_imm_disabled_characters[0] != 0)
    {
        for (i = 0; i < cand_len; i ++)
        {
            if (mmi_imm_check_disabled_character(cand[i], g_mmi_imm_disabled_characters))
            {
                *is_valid = MMI_FALSE;
                *valid_len = i;
                return;
            }
        }
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_test_paste
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_test_paste(UI_string_type cand, S32 cand_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    mmi_imc_message_struct imc_msg;
    UI_character_type first_char;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imc_is_connected())
    {
        ret = mmi_imm_test_input(cand, cand_len);

        if (ret)
        {
            if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_NUMERIC) ||
                (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC))
            {
                imc_msg.message_id    = MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR;
                imc_msg.param_0       = (U32)&first_char;
                imc_msg.param_1       = 0;

                if(mmi_imc_send_message(&imc_msg))
                {
                    for (i = 0; i < cand_len; i ++)
                    {
                        if (cand[i] == (UI_character_type) '-')
                        {
                            ret = MMI_FALSE;
                            break;
                        }    
                    }
                }
                else
                {
                    for (i = 0; i < cand_len; i ++)
                    {
                        if (cand[i] == (UI_character_type) '-' && i > 0)
                        {
                            ret = MMI_FALSE;
                            break;
                        }    
                    }
                }    
            }
        }
    }



    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_check_allowed_character
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imm_check_allowed_character(UI_character_type ch, const UI_character_type *pch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    MMI_BOOL allow = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (idx = 0; pch[idx]; idx++)
    {
        UI_character_type tmp = pch[idx];

        if (tmp == (UI_character_type) '-' && idx > 0 && pch[idx + 1])
        {
            if (ch >= pch[idx - 1] && ch <= pch[idx + 1])
            {
                allow = MMI_TRUE;
                break;
            }
            idx++;
        }
        else
        {
            if (tmp == (UI_character_type) '\\' && pch[idx + 1])
            {
                tmp = pch[++idx];
            }

            if (tmp == ch)
            {
                allow = MMI_TRUE;
                break;
            }
        }
    }

    return allow;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_check_disabled_character
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imm_check_disabled_character(UI_character_type ch, const UI_character_type *pch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    S32 len = mmi_ucs2strlen((const CHAR*)pch);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i ++)
    {
        if (ch == pch[i])
            return MMI_TRUE;
    }
    return MMI_FALSE;
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_curr_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_imm_current_input_mode;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_change_input_mode_for_wcss
* DESCRIPTION
*  special case for wcss input to change current input method dynamically.
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_change_input_mode_for_wcss(mmi_imm_input_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE; 
    mmi_imc_message_struct imc_msg = {0};
    mmi_imm_input_mode_enum old_mode = g_mmi_imm_current_input_mode;
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    const sIMEModeDetails *mode_details_ptr = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset multitap state for skip multitap state restore. */

    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

    g_mmi_imm_history_input_mode = IMM_INPUT_MODE_NONE;

    g_mmi_imm_current_input_mode = mode;

    if (old_mode != mode)
    {
#if !defined(__NO_HANDWRITING__)
#if defined(__MMI_HANDWRITING_MULTI_BLOCK__) /* Don't reserve multi-block status in WCSS */
        mmi_imc_pen_disable_multiblock_handwriting();
#endif
#if defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_VIRTUAL_KEYBOARD__)
        mmi_imc_pen_stop_singleblock_handwriting();
#endif /* defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_VIRTUAL_KEYBOARD__) */
#endif /* !defined(__NO_HANDWRITING__) */
    }

    ret = mmi_imc_change_input_mode(mode, 0);

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    if (ret)
    {
        mmi_frm_qwerty_reset_key_status();

        mode_details_ptr = mmi_imm_get_input_mode_array_item(mode);

        if (mode_details_ptr)
        {
            mmi_imm_config_special_key_validation(mode_details_ptr);
        }
    }
#endif

    mmi_imc_key_set_csk();

    if (ret)
    {

#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) 
        mmi_imm_set_curr_writing_lang_by_curr_mode();
#endif

        imc_msg.message_id = MMI_IMC_MESSAGE_MODE_CHANGED;
        mmi_imc_send_message(&imc_msg);            
    }
    else
    {
        g_mmi_imm_current_input_mode = old_mode; 
    }
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_input_type
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_type_enum mmi_imm_get_curr_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_imm_current_input_type;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_input_mode_hint_info
* DESCRIPTION
*  To query if the desired input mode is allowed in current setting or not.
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_info_struct_p mmi_imm_get_curr_input_mode_hint_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        
    S32 index = 0;
    mmi_imm_input_mode_enum hint_mode = g_mmi_imm_current_input_mode;
    mmi_imc_global_data_struct_p global_data_ptr = mmi_imc_get_global_data();
    const sIMEModeDetails *mode_details_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    if (!mmi_imm_is_curr_capital_state_of_curr_input_mode())
    {
        mode_details_ptr = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(g_mmi_imm_current_input_mode, global_data_ptr->capital_state);

        if (mode_details_ptr)
        {
            if (mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
            {
                hint_mode = mode_details_ptr->imm_mode_id;
            }
        }
    }
#endif

    while (g_mmi_imm_hint_info[index].mode_id != IMM_INPUT_MODE_MAX_NUM)
    {
        if (g_mmi_imm_hint_info[index].mode_id == hint_mode)
            break;
        index ++;
    }


    if (g_mmi_imm_hint_info[index].mode_id == IMM_INPUT_MODE_MAX_NUM)
        return NULL;
    else
        return (mmi_imm_input_mode_info_struct_p)&g_mmi_imm_hint_info[index];
}


/*****************************************************************************
* FUNCTION
*  ime_is_curr_supported_input_mode
* DESCRIPTION
*  To query if the desired input mode is allowed in current setting or not.
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_curr_allow_input_mode(mmi_imm_input_mode_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0; 
    S32 mode_id = IMM_INPUT_MODE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; (mode_id = g_mmi_imm_curr_allowed_input_mode[i].mode_id) != IMM_INPUT_MODE_NONE; i ++)
    {
        if (mode_id == target)
            return MMI_TRUE;
    }
    return MMI_FALSE;
}

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
mmi_imm_input_mode_enum mmi_imm_vk_get_input_mode_according_smart_and_multitap(void)
{
    mmi_imm_input_mode_enum curr_input_mode = g_mmi_imm_current_input_mode;
    const sIMEModeDetails * mode_detail = mmi_imm_get_input_mode_array_item(curr_input_mode); 
    const sIMEModeDetails * ret_mode_detail = NULL;

	if(!mmi_imm_is_smart_alphabetic_input_mode_available())
		return g_mmi_imm_current_input_mode;
    MMI_ASSERT(mode_detail != NULL);
    if(mode_detail->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
        {
            ret_mode_detail = mmi_imm_get_corresponding_multitap_mode(g_mmi_imm_current_input_mode, mode_detail->Mode_Special_Attrib & IME_MODE_CASE_MASK);
        }
    else if(mode_detail->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
        {
            ret_mode_detail = mmi_imm_get_corresponding_smart_mode(g_mmi_imm_current_input_mode, mode_detail->Mode_Special_Attrib & IME_MODE_CASE_MASK);
        }
    else
        {
            MMI_ASSERT(0);
        }
    if(ret_mode_detail == NULL)
        {
            return curr_input_mode;
        }
    return ret_mode_detail->imm_mode_id;
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_imm_is_curr_capital_state_of_curr_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_curr_capital_state_of_curr_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails * mode_details_ptr;
    mmi_ime_word_capital_state_enum capital_state = MMI_IME_WORD_CAPITAL_STATE_NONE;
    mmi_imc_global_data_struct_p global_data_ptr = mmi_imc_get_global_data();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EXT_PASSWORD )
        return MMI_TRUE;

    mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);

    if (mode_details_ptr == NULL)
    {
        return MMI_FALSE;
    }

    capital_state = mmi_imc_get_input_mode_caps(mode_details_ptr);

    if (capital_state == MMI_IME_WORD_CAPITAL_STATE_NONE)
    {
        if (mode_details_ptr->Lang_Special_Attrib& IME_LANG_ATTR_ALPHABETIC)
        {
            if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_CASE_MASK)
            {
                return MMI_FALSE;
            }
            else
            {
                return MMI_TRUE;
            } 
        }
        else
        {
            if (global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_NONE)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    }
    else
    {
        if (capital_state != global_data_ptr->capital_state)
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_corresponding_mode_by_mode_and_capital_state
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
const sIMEModeDetails *mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_input_mode_enum input_mode, mmi_ime_word_capital_state_enum cap_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails *mode_details_ptr, *ret_ptr = NULL;
    U16 mode_case;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);

    if (mode_details_ptr == NULL)
    {
        return NULL;
    }

    switch(cap_state)
    {
    case MMI_IME_WORD_CAPITAL_STATE_UPPER:
        mode_case = IME_MODE_ATTR_UPPERCASE;
        break;

    case MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER:
        mode_case = IME_MODE_ATTR_TITLECASE;
        break;

    case MMI_IME_WORD_CAPITAL_STATE_LOWER:
        mode_case = IME_MODE_ATTR_LOWERCASE;
        break;

    default:
        break;
    }

    if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
    {
        ret_ptr = mmi_imm_get_corresponding_smart_mode(input_mode, mode_case);
    }
    else if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
    {
        ret_ptr = mmi_imm_get_corresponding_multitap_mode(input_mode, mode_case);
    }

    return ret_ptr;

}


#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_search_prefer_for_quick_search
* DESCRIPTION
*  To search prefer input mode for quick search
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imm_input_mode_enum mmi_imm_search_prefer_for_quick_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0; 
    S32 index = 0;
    S32 prefer_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (gIMEModeArray[prefer_index].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
    {
        if(gIMEModeArray[prefer_index].imm_mode_id == g_mmi_imm_prefer_input_mode)
            break;
        prefer_index ++;
    }

    for (i = 0; (index = g_mmi_imm_curr_allowed_input_mode[i].index) != IMM_INPUT_MODE_NONE; i ++)
    {
        if ((gIMEModeArray[index].lang_id == gIMEModeArray[prefer_index].lang_id) &&
            (gIMEModeArray[index].supported_input_type_flag & IMM_INPUT_TYPE_QUICK_SEARCH))
        {
            /* there are some special case for SM Chinese, TR Chinese, Arabic. */
            switch (gIMEModeArray[index].lang_id)
            {
#if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)
                case IME_WRITING_LANG_ZHCN:
                case IME_WRITING_LANG_ZHTW:
                case IME_WRITING_LANG_ZHHK:
                    if ( (gIMEModeArray[prefer_index].Lang_Special_Attrib & IME_LANG_ATTR_STROKE))
                    {
                        if ((gIMEModeArray[prefer_index].Lang_Special_Attrib == 
                            gIMEModeArray[index].Lang_Special_Attrib))
                        {
                            return gIMEModeArray[index].imm_mode_id;
                        }
                    }
                    else
                    {
                        return gIMEModeArray[index].imm_mode_id;                    
                    }
                    break;
#endif
#if defined(__MMI_LANG_ARABIC__)
                case IME_WRITING_LANG_AR:
                    if (gIMEModeArray[prefer_index].Lang_Special_Attrib == gIMEModeArray[index].Lang_Special_Attrib)
                    {
                        return gIMEModeArray[index].imm_mode_id;
                    }
                    break;
#endif
                default:
                    return gIMEModeArray[index].imm_mode_id;
            }
        }
    }
    return IMM_INPUT_MODE_NONE;

}
#endif /* #if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */

#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
/*****************************************************************************
* FUNCTION
*  ime_is_sys_supported_input_mode
* DESCRIPTION
*  To query if the desired input mode is allowed in current setting or not.
* PARAMETERS
* RETURNS
*   S32 [OUT] the index to the system input mode array if the target input mode is avaiable.
*                  Otherwise, -1 is return.
*****************************************************************************/
MMI_BOOL mmi_imm_memory_card_is_input_mode_supported(mmi_imm_input_mode_enum input_mode)
{
	/*----------------------------------------------------------------*/
	/* Local Variables																		   */
	/*----------------------------------------------------------------*/
	U16 i;
	const sIMEModeDetails * mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);
	/*----------------------------------------------------------------*/
	/* Code Body																			   */
	/*----------------------------------------------------------------*/
	if(mode_details_ptr == NULL)
	{
		return MMI_FALSE;
	}
	if(mode_details_ptr->lang_id == IME_WRITING_LANG_123)
	{
		return MMI_TRUE;
	}
	if (!mmi_imc_memory_card_is_language_supported(mode_details_ptr,0))
	{
		return MMI_FALSE;
	}		
	if((mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP 
		&& mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
		|| mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_DIRECT)
	{
		return MMI_TRUE;
	}

	for (i = 0; g_ime_ldb_storage_infor_tbl[i].lang_id != IME_WRITING_LANG_NONE; i++)
	{
		if(g_ime_ldb_storage_infor_tbl[i].lang_id == mode_details_ptr->lang_id)
		{
			if((g_ime_ldb_storage_infor_tbl[i].ime_storage_mode & MMI_IME_LDB_STORAGE_IN_ROM))
			{
				return MMI_TRUE;
			}
			else if((g_ime_ldb_storage_infor_tbl[i].ime_storage_mode & MMI_IME_LDB_STORAGE_IN_CARD))
			{
				if(srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) && mmi_ime_check_ldb_support_info(mode_details_ptr->lang_id) == MMI_TRUE)
				{
					return MMI_TRUE;
				}
			}
			return MMI_FALSE;
		}
	}
	return MMI_FALSE;
}

#endif

/*****************************************************************************
* FUNCTION
*  ime_is_sys_supported_input_mode
* DESCRIPTION
*  To query if the desired input mode is allowed in current setting or not.
* PARAMETERS
* RETURNS
*   S32 [OUT] the index to the system input mode array if the target input mode is avaiable.
*                  Otherwise, -1 is return.
*****************************************************************************/
S32 mmi_imm_is_system_supported_input_mode(mmi_imm_input_mode_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 mode_id = IMM_INPUT_MODE_NONE;
    S32 lang_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__  
	if(mmi_imm_memory_card_is_input_mode_supported(target))
	{
#endif
    for (i = 0; (mode_id = gIMEModeArray[i].imm_mode_id) < IMM_INPUT_MODE_MAX_NUM; i ++)
    {
        if (mode_id == target)
        {
            if(mmi_imm_is_enabled_wlang(gIMEModeArray[i].lang_id))
				{
                return i;
        }
    }
    }
#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__  //add by ctt
	}
#endif
    return -1;
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_get_all_input_mode_list
* DESCRIPTION
*  To get the supporting input mode list. Filled the array passed by AP with string id and mode.
*   Used Preferred Input Method setup to get all input mode.
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_system_support_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;    
    mmi_imm_input_mode_enum mode_id = IMM_INPUT_MODE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    for (i = 0; (mode_id = gIMEModeArray[i].imm_mode_id) < IMM_INPUT_MODE_MAX_NUM; i++)
    {
        if((gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_USER_SPECIFIC))
        {
            mode_array[j] = mode_id;
            j ++;
            ASSERT(j < max);
        }
    }
    mode_array[j] = IMM_INPUT_MODE_NONE/*0xffff*/;
    return j;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_all_input_mode_list
* DESCRIPTION
*  To get the supporting input mode list. Filled the array passed by AP with string id and mode.
*   Used Preferred Input Method setup to get all input mode.
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_system_support_input_mode_string_list(U8 **strarray, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;    
    mmi_imm_input_mode_enum mode_id = IMM_INPUT_MODE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    for (i = 0; (mode_id = gIMEModeArray[i].imm_mode_id) < IMM_INPUT_MODE_MAX_NUM; i++)
    {
        if((gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_USER_SPECIFIC))
        {
            strarray[j] = (U8*)GetString(gIMEModeArray[i].menuitem_string_id);
            j ++;
            ASSERT(j < max);
        }
    }
    return j;
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_get_prefer_input_mode_list
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_prefer_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;    
    mmi_imm_input_mode_enum mode_id = IMM_INPUT_MODE_NONE;

    U32 qwerty_check = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    for (i = 0; (mode_id = gIMEModeArray[i].imm_mode_id) < IMM_INPUT_MODE_MAX_NUM; i++)
    {

      #if   defined __MMI_QWERTY_KEYPAD_SUPPORT__  
            #if defined __MMI_COSMOS_KEYPAD_SLIDER__
            if(mmi_imc_get_slider_status() == OPEN)
            #endif
              qwerty_check = !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE);
      #endif
        if((gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_USER_SPECIFIC)&& qwerty_check)
        {
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
            if (!g_mmi_imm_is_auto_capitalization_enabled)
            {
                if(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                    continue;
            }
#endif

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            if(!g_mmi_imm_is_smart_alphabetic_input_modes_enalbed)
            {
                if(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                    continue;
            }
#endif
/*#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
			//check if hw vendor support
			if(!mmi_ime_hand_writing_memory_card_is_lang_support(gIMEModeArray[i].lang_id))
			{
				continue;
			}
#endif*/

#if defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
			//check if ime vendor support
			if(mmi_imm_memory_card_is_input_mode_supported(gIMEModeArray[i].imm_mode_id) == MMI_FALSE)
			{
				continue;
			}
#endif

            mode_array[j] = mode_id;
            j ++;
            ASSERT(j < max);
        }
    }
    mode_array[j] = IMM_INPUT_MODE_NONE/*0xffff*/;
    return j;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_prefer_input_mode_string_list
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_prefer_input_mode_string_list(U8 **strarray, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;    
    mmi_imm_input_mode_enum mode_id = IMM_INPUT_MODE_NONE;

    U32 qwerty_check = 1;


 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    for (i = 0; (mode_id = gIMEModeArray[i].imm_mode_id) < IMM_INPUT_MODE_MAX_NUM; i++)
    {
         #if   defined __MMI_QWERTY_KEYPAD_SUPPORT__  
            #if defined __MMI_COSMOS_KEYPAD_SLIDER__
            if(mmi_imc_get_slider_status() == OPEN)
            #endif
              qwerty_check = !(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE);
 #endif
        if((gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_USER_SPECIFIC) && qwerty_check )
        {
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
            if (!g_mmi_imm_is_auto_capitalization_enabled)
            {
                if(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                    continue;
            }
#endif

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            if(!g_mmi_imm_is_smart_alphabetic_input_modes_enalbed)
            {
                if(gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                    continue;
            }
#endif

#if defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
			//check if ime vendor support
			if(mmi_imm_memory_card_is_input_mode_supported(gIMEModeArray[i].imm_mode_id) == MMI_FALSE)
			{
				continue;
			}
#endif

            strarray[j] = (U8*)GetString(gIMEModeArray[i].menuitem_string_id);
            j ++;
            ASSERT(j < max);
        }
    }
    return j;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_input_mode_list
* DESCRIPTION
*  To get the supporting input mode list. Filled the array passed by AP with string id and mode.
*   Used in input method selection.
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_curr_allow_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    while (g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE)
    {
		ASSERT(index < max);
        mode_array[index] = g_mmi_imm_curr_allowed_input_mode[index].mode_id;
        index ++;
    }
    return index;
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_input_mode_list
* DESCRIPTION
*  To get the supporting input mode list. Filled the array passed by AP with string id and mode.
*   Used in input method selection.
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_curr_allow_input_mode_string_list(U16 *strarray, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i ++)
    {
        strarray[j] =gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].menuitem_string_id;
        j++;
        ASSERT(j < max);
    }
    return j;
}

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_not_used_desired_writing_language_from_history
* DESCRIPTION
*  Get not used desired writing language which is from history
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_support_writing_lang_enum mmi_imm_get_not_used_desired_writing_language_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_mmi_imm_history_writing_lang;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_set_writing_language_from_history
* DESCRIPTION
*  Set desired writing language which is from history
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_writing_language_from_history(mmi_imm_support_writing_lang_enum writing_lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imm_history_writing_lang = writing_lang;
}




/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_input_mode_list
* DESCRIPTION
*  To get the supporting input mode list. Filled the array passed by AP with string id and mode.
*   Used in input method selection.
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_curr_allow_writing_language_string_list(UI_string_type *strarray, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, index;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    for (i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i ++)
    {
        /* This check is to make sure writing language 123 comes in stiuations like   MMS receipient and not at other places */
        if ( (g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_123) &&  (i != 0))
        {
            break;
        }
        index = mmi_imm_get_index_in_system_writing_language(g_mmi_imm_curr_allowed_writing_lang[i]);
        MMI_ASSERT(index >= 0);
        strarray[j] =g_ime_writing_lang_array[index].lang_str_ptr;
        j++;
        ASSERT(j < max);
    }
    return j;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_allow_sub_language_string_list
* DESCRIPTION
*  To get the strings of currently allowed sub languages
*   Used in input method selection.
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_curr_allow_sub_language_string_list(UI_string_type *strarray, S32 max)
{
#if defined(__MMI_MIXED_LANG_SUPPORT__) 

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, index;    
    S32 main_lang_id;
    MMI_BOOL is_main_lang_allowed = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);
    /* In case main language does not support mixed language NONE will be shown in sub lang */

    /* But Check whether main language is not present in allowed language as if that is the case ,english
    is going to be the main language , thus sub language list is to be generated */
    main_lang_id = mmi_imm_get_main_lang();

    for (i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i ++)
    {       
        if ( g_mmi_imm_curr_allowed_writing_lang[i] == main_lang_id)
        {
            is_main_lang_allowed = MMI_TRUE;
            break;
        }
    }
    /* if main language is allowed , we will check if this deserves and sub language or not */
    if ( is_main_lang_allowed)
    {
        for ( i =0 ;  g_ime_writing_lang_array[i].lang_id != main_lang_id ;i++)
        {
        }
        if (g_ime_writing_lang_array[i].mixed_lang_support == MMI_FALSE)
        {
            /* Main Language like Chinese , donot have ang mixed language support */
            strarray[0] = (UI_string_type)GetString(STR_GLOBAL_NONE);
            return 1;
        }
    }
    else
    {
        /* Main Language like Chinese , donot have ang mixed language support */
        strarray[0] = (UI_string_type)GetString(STR_GLOBAL_NONE);
        return 1;
    }
    /* List of all the allowed sub languages */
    for (i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i ++)
    {
        index = mmi_imm_get_index_in_system_writing_language(g_mmi_imm_curr_allowed_writing_lang[i]);
        MMI_ASSERT(index >= 0);
        if (g_ime_writing_lang_array[index].mixed_lang_support)
        {
            strarray[j] =g_ime_writing_lang_array[index].lang_str_ptr;
            j++;
            ASSERT(j < max);
        }
    }
    strarray[j]  = (UI_string_type)GetString(STR_GLOBAL_NONE);
    return j +1; /* add one for None */
#else
    return NULL;
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_writing_language_index
* DESCRIPTION
*  To get the supporting input mode list. Filled the array passed by AP with string id and mode.
*   Used in input method selection.
* PARAMETERS
* RETURNS
*****************************************************************************/
U16 mmi_imm_get_curr_writing_language_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i ++)
    {
        if (g_mmi_imm_curr_allowed_writing_lang[i] == g_mmi_imm_curr_writing_lang)
        {
            return i;
        }
    }
    MMI_ASSERT(0);
    return 0;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_is_curr_allowed_wlang
* DESCRIPTION
*   Used in input method selection.
* PARAMETERS
* RETURNS
*****************************************************************************/
U16 mmi_imm_is_curr_allowed_wlang(S32 wlang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i ++)
    {
        if (g_mmi_imm_curr_allowed_writing_lang[i] == wlang)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_writing_language_num
* DESCRIPTION
*  Get current number of all writing language
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_writing_language_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i ++);
    return i;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_current_writing_language
* DESCRIPTION
*  Get current writing language
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_support_writing_lang_enum mmi_imm_get_current_writing_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_mmi_imm_curr_writing_lang;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_set_current_writing_lang
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_current_writing_lang(mmi_imm_support_writing_lang_enum lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imm_curr_writing_lang = lang;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang
* DESCRIPTION
*  To get the supporting input mode list of current writing language. Filled the 
*  array passed by AP with string id and mode. Used in input method selection.
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang(mmi_imm_input_mode_enum *mode_array, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0, i = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(max >= 1);

    while (g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE)
    {
        if ((gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id == g_mmi_imm_curr_writing_lang)
            || (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == IMM_INPUT_MODE_123_SYMBOLS)
            || (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == IMM_INPUT_MODE_PHONE_NUMBER)
            || mmi_imm_IsInputTypeNumber()
#if defined(__MMI_IME_PLUG_IN__) && defined(__MMI_KOMOXO__)
            /* special case for komoxo, relativate CR is MAUI_02656194*/
            || (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == IMM_INPUT_MODE_PHONE_NUMBER)
            || (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == IMM_INPUT_MODE_123)
#endif
            )
        {
            mode_array[index++] = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
        }
        i++;
        MMI_ASSERT(index < max);
    }
    return index;
}

#if defined(__MMI_IME_V3__)
mmi_imm_input_mode_enum mmi_imm_get_corresponding_input_mode(mmi_imm_input_mode_enum input_mode)
{
    const sIMEModeDetails* mode_detail;
    int i,j;
    if(mmi_imm_is_curr_allow_input_mode(input_mode))
        {
            return input_mode;
        }
    mode_detail = mmi_imm_get_input_mode_array_item(input_mode);

    for(i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
        {
            if(mode_detail->lang_id == gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id
                && mode_detail->lang_id != IME_WRITING_LANG_ZHCN
                && mode_detail->lang_id != IME_WRITING_LANG_ZHHK
                && mode_detail->lang_id != IME_WRITING_LANG_ZHTW)
                {
                    return g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                }
        }
	return input_mode;
}


static MMI_BOOL mmi_imm_is_input_mode_can_be_shown_in_list(mmi_imm_input_mode_enum input_mode)
{
    S32 index = 0,j=0;
    S32 temp_ind = 0, current_lang_mode_index[8] = {0};
    const sIMEModeDetails * temp_mode_detail;

    
    while (g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE)
    {
        if (input_mode == g_mmi_imm_curr_allowed_input_mode[index].mode_id)
        {
            break;
        }
        index ++;
    }
    if(g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE)
        {

/*
            while (g_mmi_imm_curr_allowed_input_mode[temp_ind].mode_id != IMM_INPUT_MODE_NONE)
            {
                temp_mode_detail = &gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[temp_ind].index];
                if (temp_mode_detail->lang_id == gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index].lang_id
                    && temp_mode_detail->Lang_Special_Attrib == gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index].Lang_Special_Attrib)
                {
                    current_lang_mode_index[j] = temp_ind;
                }
                temp_ind ++;
            }
*/
            temp_mode_detail = &gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index];
            if(temp_mode_detail->supported_input_type_flag & g_mmi_imm_current_input_type)
            {
                return MMI_FALSE;
            }
            if(g_mmi_imm_current_input_type != IMM_INPUT_TYPE_SENTENCE
                || g_mmi_imm_current_input_type != IMM_INPUT_TYPE_ENGLISH_SENTENCE
                || g_mmi_imm_current_input_type != IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE
                || g_mmi_imm_current_input_type != IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE
                || g_mmi_imm_current_input_type != IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE)
                {
                    if(temp_mode_detail->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
                    {
                        return MMI_TRUE;
                    }
                }
            if(temp_mode_detail->Mode_Special_Attrib & IME_MODE_ATTR_SMART
               && temp_mode_detail->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
            {
                return MMI_TRUE;
            }
        }
	return MMI_FALSE;
}

S32 mmi_imm_get_curr_allow_input_mode_list_of_imev3(mmi_imm_input_mode_enum *mode_array, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, index;    
    const sIMEModeDetails * tmp_mode_detail;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    if(g_mmi_imm_current_input_type == IMM_INPUT_TYPE_QUICK_SEARCH)
    {
        for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE 
            && g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_123
            && g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_123_SYMBOLS; i ++)
        {
            if(gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].supported_input_type_flag & IMM_INPUT_TYPE_QUICK_SEARCH)
            {
                mode_array[j] = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
            }
                
            j++;
            ASSERT(j < max);
        }        
        mode_array[j] = IMM_INPUT_MODE_NONE;
        return j;
    }

    for (i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i ++)
    {
        /* This check is to make sure writing language 123 comes in stiuations like   MMS receipient and not at other places */
        if ( (g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_123) &&  (i != 0))
        {
            break;
        }
        if ( g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_ZHCN
            || g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_ZHTW
            || g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_ZHHK)
        {
            continue;
        }
        index = mmi_imm_get_index_in_system_writing_language(g_mmi_imm_curr_allowed_writing_lang[i]);
        if(index < 0)
			continue;

		tmp_mode_detail = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_get_corresponding_input_mode(g_ime_writing_lang_array[index].default_input_mode), MMI_IME_WORD_CAPITAL_STATE_LOWER);
		if(tmp_mode_detail)
		{
			mode_array[j] = tmp_mode_detail->imm_mode_id; 
		}
		else
		{
			mode_array[j] = mmi_imm_get_corresponding_input_mode(g_ime_writing_lang_array[index].default_input_mode);
		}	
        j++;
        ASSERT(j < max);
    }
    
    for(i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
    {
        if(mmi_imm_is_chinese_input_method(g_mmi_imm_curr_allowed_input_mode[i].mode_id))
        {
            if(gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP
                && !(gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Lang_Special_Attrib & IME_LANG_ATTR_STROKE))
            {
                tmp_mode_detail = mmi_imm_get_corresponding_smart_mode(g_mmi_imm_curr_allowed_input_mode[i].mode_id, 0);
                if(tmp_mode_detail)
                {
                    if(mmi_imm_is_curr_allow_input_mode(tmp_mode_detail->imm_mode_id));
                    {
                        continue;
                    }
                }
            }

            mode_array[j] = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
            j++;
            ASSERT(j < max);
        }
    }
    mode_array[j] = IMM_INPUT_MODE_NONE;
    return j;

}
#endif
/*****************************************************************************
* FUNCTION
*  mmi_imm_reset_user_desired_writing_language
* DESCRIPTION
*  Set user desired language to NONE for dialler search
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_reset_user_desired_writing_language()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imm_user_desired_writing_lang = IME_WRITING_LANG_NONE;
    g_mmi_imm_user_desired_input_mode = IMM_INPUT_MODE_NONE;
    return;
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_set_user_desired_writing_language
* DESCRIPTION
*  Set current writing language by index of g_ime_writing_lang_array
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_user_desired_writing_language(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imm_input_mode_enum desired_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    i = mmi_imm_get_index_in_system_writing_language(g_mmi_imm_curr_allowed_writing_lang[index]);

    MMI_ASSERT(i >= 0);

    desired_mode = mmi_imm_get_first_allowed_input_mode_of_lang(g_ime_writing_lang_array[i].lang_id);

    if (desired_mode == IMM_INPUT_MODE_NONE)
    {
        if (mmi_imm_is_curr_allow_input_mode(g_ime_writing_lang_array[i].default_input_mode))
        {
            desired_mode = g_ime_writing_lang_array[i].default_input_mode;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    MMI_ASSERT(desired_mode != IMM_INPUT_MODE_NONE);

    mmi_imm_set_user_desired_input_mode(desired_mode);

    g_mmi_imm_user_desired_writing_lang = g_mmi_imm_curr_allowed_writing_lang[index];
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_user_desired_writing_language
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_support_writing_lang_enum mmi_imm_get_user_desired_writing_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_mmi_imm_user_desired_writing_lang;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_current_allowed_writing_language_num
* DESCRIPTION
*  Get current allowed writing language number
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_current_allowed_writing_language_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE)
    {
        i++;
    }

    return i;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_input_mode_num_in_current_writing_language
* DESCRIPTION
*  Get current input mode number in current writing language
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_input_mode_num_in_current_writing_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0, num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE)
    {
        if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index].lang_id == g_mmi_imm_curr_writing_lang
            || g_mmi_imm_curr_allowed_input_mode[index].mode_id == IMM_INPUT_MODE_123_SYMBOLS)
        {
            num++;
        }
        index++;
    }

    return num;
}




/*****************************************************************************
* FUNCTION
*  mmi_imm_get_index_in_system_writing_language
* DESCRIPTION
*  Get index in system supported writing language array
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32  mmi_imm_get_index_in_system_writing_language(mmi_imm_support_writing_lang_enum writing_lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_ime_writing_lang_array[i].lang_id!= IME_WRITING_LANG_NONE; i++)
    {
        if (g_ime_writing_lang_array[i].lang_id == writing_lang && g_ime_writing_lang_array[i].enabled)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_first_allowed_input_mode_of_lang
* DESCRIPTION
*  Get the first allowed input mode of the specified writing language
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_first_allowed_input_mode_of_lang(mmi_imm_support_writing_lang_enum writing_lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imm_input_mode_enum valid_mode_id = IMM_INPUT_MODE_NONE;
    U16 prefer_mode_attr = IME_MODE_ATTR_MULTITAP;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* special process for url and email input mode.
    the lowercase abc should be the first input mode for english language.
    */
#if defined(__MMI_IME_FTE_ENHANCE__)
    if (((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_URL) ||
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EMAIL)) &&
        writing_lang == IME_WRITING_LANG_ABC)
    {
        valid_mode_id = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
    }
    else
#endif
        if (valid_mode_id == IMM_INPUT_MODE_NONE)
        {
            valid_mode_id = mmi_imm_get_first_allowed_input_mode_of_lang_by_mode_attr(writing_lang, IME_MODE_ATTR_MULTITAP);
        }

        return valid_mode_id;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_first_allowed_input_mode_of_lang_by_mode_attr
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imm_input_mode_enum mmi_imm_get_first_allowed_input_mode_of_lang_by_mode_attr(mmi_imm_support_writing_lang_enum writing_lang, U16 mode_attibut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imm_input_mode_enum valid_mode_id = IMM_INPUT_MODE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i ++)
    {
        if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id == writing_lang)
        {
#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)	
            if ((gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                && (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].supported_input_type_flag & IMM_INPUT_TYPE_SENTENCE))
            {
                if ((gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Mode_Special_Attrib & mode_attibut))
                {
                    /* The logic should be same with the logic in mmi_imm_set_initial_input_mode_by_last() */
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                    if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                    {
                        return g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                    }
                    else
#else
                    if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
                    {
                        return g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                    }
                    else
#endif
                    {
                        valid_mode_id = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                    }	

                }
                else
                {
                    valid_mode_id = g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                }	
            }
            else
#endif	
            {	
                if (valid_mode_id != IMM_INPUT_MODE_NONE)
                {
                    return valid_mode_id;
                }
                else
                {
                    return g_mmi_imm_curr_allowed_input_mode[i].mode_id;
                }	
            }
        }
    }

    return valid_mode_id;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_allow_input_mode_string_list_of_curr_writing_lang
* DESCRIPTION
*  Get the allowed input mode string list of the current writing language
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_curr_allow_input_mode_string_list_of_curr_writing_lang(U16 *strarray, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i ++)
    {
        if ((gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id == g_mmi_imm_curr_writing_lang)
            || (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == IMM_INPUT_MODE_123_SYMBOLS)
            || (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == IMM_INPUT_MODE_PHONE_NUMBER)
            ||  mmi_imm_IsInputTypeNumber()
#if defined(__MMI_IME_PLUG_IN__) && defined(__MMI_KOMOXO__)
            /* special case for komoxo, relativate CR is MAUI_02656593*/
            || (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == IMM_INPUT_MODE_PHONE_NUMBER)
            || (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == IMM_INPUT_MODE_123)
#endif
            )

        {
            strarray[j++] =gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].menuitem_string_id;
        }
        MMI_ASSERT(j < max);
    }
    return j;
}

#if defined(__MMI_IME_V3__)
S32 mmi_imm_get_curr_allow_input_mode_string_list_of_imev3(U16* strarray, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, index;    
    const sIMEModeDetails * tmp_mode_detail;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(max >= 1);

    if(g_mmi_imm_current_input_type == IMM_INPUT_TYPE_QUICK_SEARCH)
    {
        for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE 
            && g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_123
            && g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_123_SYMBOLS; i ++)
        {
            if(gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].supported_input_type_flag & IMM_INPUT_TYPE_QUICK_SEARCH)
            {
                strarray[j] = gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].menuitem_string_id;
            }
            j++;
            ASSERT(j < max);
        }        
        strarray[j] = 0;
        return j;
    }

    for (i = 0; g_mmi_imm_curr_allowed_writing_lang[i] != IME_WRITING_LANG_NONE; i ++)
    {
        /* This check is to make sure writing language 123 comes in stiuations like   MMS receipient and not at other places */
        if ( (g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_123) &&  (i != 0))
        {
            break;
        }
        if ( g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_ZHCN
            || g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_ZHTW
            || g_mmi_imm_curr_allowed_writing_lang[i] == IME_WRITING_LANG_ZHHK)
        {
            continue;
        }
        index = mmi_imm_get_index_in_system_writing_language(g_mmi_imm_curr_allowed_writing_lang[i]);
        MMI_ASSERT(index >= 0);
        
        tmp_mode_detail = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_get_corresponding_input_mode(g_ime_writing_lang_array[index].default_input_mode),MMI_IME_WORD_CAPITAL_STATE_LOWER); 
		if(tmp_mode_detail)
		{
			strarray[j] = mmi_imm_get_input_mode_array_item(tmp_mode_detail->imm_mode_id)->menuitem_string_id;
		}
		else
		{
			strarray[j] = mmi_imm_get_input_mode_array_item(mmi_imm_get_corresponding_input_mode(g_ime_writing_lang_array[index].default_input_mode))->menuitem_string_id;
		}
            
        j++;
        ASSERT(j < max);
    }
    for(i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
    {
        if(mmi_imm_is_chinese_input_method(g_mmi_imm_curr_allowed_input_mode[i].mode_id))
        {
            if(gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP
                && !(gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Lang_Special_Attrib & IME_LANG_ATTR_STROKE))
            {
                tmp_mode_detail = mmi_imm_get_corresponding_smart_mode(g_mmi_imm_curr_allowed_input_mode[i].mode_id, 0);
                if(tmp_mode_detail)
                {
                    if(mmi_imm_is_curr_allow_input_mode(tmp_mode_detail->imm_mode_id));
                    {
                        continue;
                    }
                }
            }
            strarray[j] = gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].menuitem_string_id;
            j++;
            ASSERT(j < max);
        }
    }
    return j;
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_imm_set_curr_allowed_writing_lang_by_curr_allowed_modes
* DESCRIPTION
*  To get the supporting writing language list. Filled the array passed by AP with string id and mode.
*   Used in writing language selection.
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imm_set_curr_allowed_writing_lang_by_curr_allowed_modes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, k = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)

    mmi_imm_support_writing_lang_enum old_writing_lang = g_mmi_imm_curr_writing_lang;

#endif
    memset(g_mmi_imm_curr_allowed_writing_lang, IME_WRITING_LANG_NONE, sizeof(mmi_imm_support_writing_lang_enum) * (IME_WRITING_LANG_TOTAL + 1));

    for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i ++)
    {
        for (j = 0; g_mmi_imm_curr_allowed_writing_lang[j] != IME_WRITING_LANG_NONE; j++)
        {
            if (g_mmi_imm_curr_allowed_writing_lang[j] == gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id)
            {
                break;
            }
        }

        if (g_mmi_imm_curr_allowed_input_mode[i].mode_id == g_mmi_imm_current_input_mode)
        {
            g_mmi_imm_curr_writing_lang = gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id;
        }

        if (g_mmi_imm_curr_allowed_writing_lang[j] == IME_WRITING_LANG_NONE)
        {
            g_mmi_imm_curr_allowed_writing_lang[k++] = gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id;
        }
    }
    g_mmi_imm_curr_allowed_writing_lang[k] = IME_WRITING_LANG_NONE;
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    /* hack for the case where wlang becomes numeric so input modes shown are only numeric */
    if ( g_mmi_imm_curr_writing_lang ==IME_WRITING_LANG_123)
    {
        if (mmi_imm_is_curr_allowed_wlang(old_writing_lang))
        {
            g_mmi_imm_curr_writing_lang =  old_writing_lang ;
        }
        else
        {
            g_mmi_imm_curr_writing_lang = IME_WRITING_LANG_ABC;
        }
    }
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_curr_writing_lang_by_curr_mode
* DESCRIPTION
*  Set current writing language by current input mode
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_curr_writing_lang_by_curr_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i ++)
    {
        if (g_mmi_imm_curr_allowed_input_mode[i].mode_id == g_mmi_imm_current_input_mode)
        {
            g_mmi_imm_curr_writing_lang = gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id;
        }
    }

}

#endif


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_initial_input_mode_by_last
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imm_set_initial_input_mode_by_last(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
    const sIMEModeDetails *mode_detail_ptr = NULL;
    S32 i = 0;
    const sIMEModeDetails *mode_detail_ptr1 = NULL, *mode_detail_ptr2 = NULL;
    mmi_imm_input_mode_enum valid_mode = IMM_INPUT_MODE_NONE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
    if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_SENTENCE
        || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ASCII_CHAR
        || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ENGLISH_SENTENCE
        || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        mode_detail_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);

        if (!mode_detail_ptr)
        {
            return;
        }

        i = 0;

        while (gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
        {

            if (gIMEModeArray[i].lang_id == mode_detail_ptr->lang_id
                && ((gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
                || (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART))
                && !(gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)
                && !(gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_STROKE))
            {
                /* The logic should be same with the logic in mmi_imm_get_first_allowed_input_mode_of_lang() */
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__) 
                if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
#else
                if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
#endif
                {
                    if (mmi_imm_is_curr_allow_input_mode(gIMEModeArray[i].imm_mode_id))
                    {
                        g_mmi_imm_current_input_mode = gIMEModeArray[i].imm_mode_id;
                        valid_mode = IMM_INPUT_MODE_NONE;
                        break;
                    }
                }
                else
                {
                    if (mmi_imm_is_curr_allow_input_mode(gIMEModeArray[i].imm_mode_id))
                    {
                        valid_mode = gIMEModeArray[i].imm_mode_id;
                    }
                }
            }

            i++;
        }

        if (valid_mode != IMM_INPUT_MODE_NONE)
        {
            g_mmi_imm_current_input_mode = valid_mode;
        }
    }
    else
#endif
        if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EMAIL)
            || (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_URL)
            || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD
            || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ASCII_PASSWORD)
        {
            g_mmi_imm_current_input_mode = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
        }

#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
        if (( g_mmi_imm_current_input_type == IMM_INPUT_TYPE_SENTENCE 
            || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ASCII_CHAR 
            || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_ENGLISH_SENTENCE
            || g_mmi_imm_current_input_type == IMM_INPUT_TYPE_USER_SPECIFIC)
            && g_mmi_imm_last_input_mode != IMM_INPUT_MODE_NONE)
        {
            if (mmi_imm_is_curr_allow_input_mode(g_mmi_imm_last_input_mode))
            {
			#if defined(__MMI_IME_V3__)
				g_mmi_imm_current_input_mode = g_mmi_imm_last_input_mode;
			#else
                mode_detail_ptr1 = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);

                mode_detail_ptr2 = mmi_imm_get_input_mode_array_item(g_mmi_imm_last_input_mode);

                if (!mode_detail_ptr1 || !mode_detail_ptr2)
                {
                    return;
                }

                if (mode_detail_ptr1->lang_id == mode_detail_ptr2->lang_id)
                {
                    g_mmi_imm_current_input_mode = g_mmi_imm_last_input_mode;
                }
			#endif
            }
        }
#endif

}



#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_set_initial_input_mode_by_auto_capitalization
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_initial_input_mode_by_auto_capitalization(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails *mode_details_ptr = NULL;
    mmi_ime_word_capital_state_enum  capital_state = MMI_IME_WORD_CAPITAL_STATE_NONE;
    mmi_ime_word_capital_state_enum  new_state = MMI_IME_WORD_CAPITAL_STATE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if title case is not allowed , no need to change */
    if(mmi_imm_does_current_type_support_titlecase() )
    {
        if (g_mmi_imm_is_default_init_input_mode_overide)
        {
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
            if (mmi_imm_is_auto_capitalization_setting_changed())
            {
                mmi_imm_config_auto_capitalization_setting_changed(MMI_FALSE);
            }
            else
#endif
            {
                return;
            }
        }

        if (!mmi_imm_is_auto_capitalization_valid())
        {
            return;
        }

        mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);

        MMI_ASSERT(mode_details_ptr);

        if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE )
        {
            capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
        }
        else if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE )
        {
            capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
        }
        else if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE )
        {
            capital_state = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
        }

        if (capital_state != MMI_IME_WORD_CAPITAL_STATE_NONE)
        {
            new_state = mmi_imc_get_candidate_case_before_cursor();

            if (capital_state != new_state)
            {
                mode_details_ptr = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(g_mmi_imm_current_input_mode, new_state);

                if (mode_details_ptr)
                {
                    if (mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
                    {
                        g_mmi_imm_current_input_mode = mode_details_ptr->imm_mode_id;
                    }
                }
            }
        }
    }
}
#endif /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_current_allowed_input_mode_num
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_get_current_allowed_input_mode_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE)
    {
        i++;
    }

    return i;

}

/*****************************************************************************
* FUNCTION
*  mmi_imm_set_current_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_set_current_input_mode(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imm_is_curr_allow_input_mode(input_mode))
    {
        g_mmi_imm_current_input_mode = input_mode;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_user_specific_input_mode_list
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum * mmi_imm_get_curr_user_specific_input_mode_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_mmi_imm_user_specific_input_mode_list;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_default_input_mode
* DESCRIPTION
*  To set default input mode.
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_message_id_enum mmi_imm_set_default_input_mode(mmi_imm_input_mode_enum default_input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_mmi_imm_default_input_mode = default_input_mode;
    return IMM_MESSAGE_ID_NONE;

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_default_input_mode
* DESCRIPTION
*  To get default input mode.
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_default_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return g_mmi_imm_default_input_mode;
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_set_history_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_history_input_mode(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    g_mmi_imm_history_input_mode = input_mode;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_history_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_history_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    return g_mmi_imm_history_input_mode;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_user_desired_input_mode
* DESCRIPTION
*  To set user desired input mode. Used in Input Method list of option of editor.
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_message_id_enum mmi_imm_set_user_desired_input_mode(mmi_imm_input_mode_enum desired_input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_mmi_imm_user_desired_input_mode = desired_input_mode;
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    mmi_imc_pen_open_symbol_lock();
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
    return IMM_MESSAGE_ID_NONE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_user_desired_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_user_desired_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return g_mmi_imm_user_desired_input_mode;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_app_desired_input_mode
* DESCRIPTION
*  To set app desired input mode. Used when resume input mode which had been
*  deleted when clearing history by app.
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_message_id_enum mmi_imm_set_app_desired_input_mode(mmi_imm_input_mode_enum desired_input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_mmi_imm_app_desired_input_mode = desired_input_mode;
    return IMM_MESSAGE_ID_NONE;
}

#if defined(__MMI_IME_V3__)

mmi_imm_input_mode_enum mmi_imm_get_next_writing_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;    
    mmi_imm_input_mode_enum mode_id = IMM_INPUT_MODE_NONE;
    mmi_imm_support_writing_lang_enum lang_id;
    mmi_imc_global_data_struct_p global_data_ptr = mmi_imc_get_global_data();
    const sIMEModeDetails *mode_details_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (!g_mmi_imm_is_change_input_mode_enabled) /* Change input mode is disabled */
    {
        return g_mmi_imm_current_input_mode;
    }

    if (!mmi_imm_is_curr_capital_state_of_curr_input_mode())
    {
        mode_details_ptr = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(g_mmi_imm_current_input_mode, global_data_ptr->capital_state);

        if (mode_details_ptr)
        {
            if (mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
            {
                g_mmi_imm_current_input_mode = mode_details_ptr->imm_mode_id;
            }
        }
    }

    /* invalid input type */
    if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_NONE)
        ASSERT(0);

    /* check the array to find the index of current input mode */
    while ((mode_id = g_mmi_imm_curr_allowed_input_mode[index].mode_id) != IMM_INPUT_MODE_NONE)
    {
        if (mode_id == g_mmi_imm_current_input_mode)
        {
            break;
        }
        index ++;
    }

    MMI_ASSERT(g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE);
    
    g_mmi_imm_current_input_mode = mmi_imc_get_next_input_mode_from_list();

    return g_mmi_imm_current_input_mode;
}

#endif
/*****************************************************************************
* FUNCTION
*  mmi_imm_get_next_mode
* DESCRIPTION
*  Return next input mode in mode array. 
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_next_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;    
    mmi_imm_input_mode_enum mode_id = IMM_INPUT_MODE_NONE;
#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) 
    mmi_imc_message_struct imc_msg;
#endif

#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
    const sIMEModeDetails *cur_mode_detail = NULL;
    const sIMEModeDetails *input_mode_table[MMI_IMM_MAX_INPUT_MODE_NUM_IN_ONE_LANG];
    S32 i = 0, j = 0, k, mode_count = 0;
    MMI_BOOL check_flag = MMI_FALSE;
#endif
    mmi_imm_support_writing_lang_enum lang_id;
    mmi_imc_global_data_struct_p global_data_ptr = mmi_imc_get_global_data();
    const sIMEModeDetails *mode_details_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (!g_mmi_imm_is_change_input_mode_enabled) /* Change input mode is disabled */
    {
        return g_mmi_imm_current_input_mode;
    }

    if (!mmi_imm_is_curr_capital_state_of_curr_input_mode())
    {
        mode_details_ptr = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(g_mmi_imm_current_input_mode, global_data_ptr->capital_state);

        if (mode_details_ptr)
        {
            if (mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
            {
                g_mmi_imm_current_input_mode = mode_details_ptr->imm_mode_id;
            }
        }
    }

    /* invalid input type */
    if (g_mmi_imm_current_input_type == IMM_INPUT_TYPE_NONE)
        ASSERT(0);

    /* check the array to find the index of current input mode */
    while ((mode_id = g_mmi_imm_curr_allowed_input_mode[index].mode_id) != IMM_INPUT_MODE_NONE)
    {
        if (mode_id == g_mmi_imm_current_input_mode)
        {
            break;
        }
        index ++;
    }

    /* there is no match. */
    if (mode_id == IMM_INPUT_MODE_NONE)
        ASSERT(0);

#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) 

    imc_msg.message_id = MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED; /* The screen should be disabled in WCSS */
    mmi_imc_send_message(&imc_msg);



    if (!mmi_imc_send_message(&imc_msg))
    {
#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
        /* for the case that arabic numberic as well as 123 should toggle */
        if(g_mmi_imm_curr_writing_lang == IME_WRITING_LANG_AR)
        {
            lang_id = gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index].lang_id;
        }
        else if (g_mmi_imm_curr_writing_lang != IME_WRITING_LANG_ZHTW
            && g_mmi_imm_curr_writing_lang != IME_WRITING_LANG_ZHCN
            && g_mmi_imm_curr_writing_lang != IME_WRITING_LANG_ZHHK)
        {
            cur_mode_detail = &gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index];

            for (i = 0, mode_count = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
            {
                if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id == g_mmi_imm_curr_writing_lang
                    || g_mmi_imm_curr_allowed_input_mode[i].mode_id == IMM_INPUT_MODE_123_SYMBOLS)
                {
                    input_mode_table[mode_count++] = &gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index];
                    MMI_ASSERT(mode_count <= MMI_IMM_MAX_INPUT_MODE_NUM_IN_ONE_LANG);
                }
            }

            for (i = 0; g_mmi_imm_input_mode_switch_rule_table[i][0] != 0; i++)
            {
                for (j = 0; g_mmi_imm_input_mode_switch_rule_table[i][j] != 0; j++)
                {
                    if (mmi_imm_check_same_mode_special_attribute_rule(cur_mode_detail->Mode_Special_Attrib, g_mmi_imm_input_mode_switch_rule_table[i][j])
                        && mmi_imm_check_same_mode_special_attribute_rule(g_mmi_imm_initial_mode_detail->Mode_Special_Attrib, g_mmi_imm_input_mode_switch_rule_table[i][0]))
                    {
                        check_flag = MMI_TRUE;
                        break;
                    }
                }

                if (check_flag)
                {
                    break;
                }
            }
        }

        if (check_flag)
        {
            j++;

            for (; g_mmi_imm_input_mode_switch_rule_table[i][j] != 0; j++)
            {
                for (k = 0; k < mode_count; k++)
                {
                    if (mmi_imm_check_same_mode_special_attribute_rule(input_mode_table[k]->Mode_Special_Attrib, g_mmi_imm_input_mode_switch_rule_table[i][j])
                        && g_mmi_imm_current_input_mode != input_mode_table[k]->imm_mode_id)
                    {
                        g_mmi_imm_current_input_mode = input_mode_table[k]->imm_mode_id;
                        return g_mmi_imm_current_input_mode;
                    }
                }
            }

            for (j = 0; g_mmi_imm_input_mode_switch_rule_table[i][j] != cur_mode_detail->Mode_Special_Attrib; j++)
            {
                for (k = 0; k < mode_count; k++)
                {
                    if (mmi_imm_check_same_mode_special_attribute_rule(input_mode_table[k]->Mode_Special_Attrib, g_mmi_imm_input_mode_switch_rule_table[i][j])
                        && g_mmi_imm_current_input_mode != input_mode_table[k]->imm_mode_id)
                    {
                        g_mmi_imm_current_input_mode = input_mode_table[k]->imm_mode_id;
                        return g_mmi_imm_current_input_mode;
                    }
                }
            }
        }
        else
#else

        lang_id = gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index].lang_id;

#endif /* defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__) */
        {	
            index ++;

            while (g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE)
            {
                if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index].lang_id == g_mmi_imm_curr_writing_lang
                    || g_mmi_imm_curr_allowed_input_mode[index].mode_id == IMM_INPUT_MODE_123_SYMBOLS)
                {
                    break;
                }
                index++;
            }

            if (g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE)
            {
                g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[index].mode_id;
            }
            else
            {
                index = 0;

                while (g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE)
                {
                    if (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[index].index].lang_id == g_mmi_imm_curr_writing_lang
                        || g_mmi_imm_curr_allowed_input_mode[index].mode_id == IMM_INPUT_MODE_123_SYMBOLS
                        || g_mmi_imm_curr_allowed_input_mode[index].mode_id == IMM_INPUT_MODE_PHONE_NUMBER)
                    {
                        break;
                    }
                    index++;
                }

                if (g_mmi_imm_curr_allowed_input_mode[index].mode_id != IMM_INPUT_MODE_NONE
                    && g_mmi_imm_curr_allowed_input_mode[index].mode_id != g_mmi_imm_current_input_mode)
                {
                    g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[index].mode_id;
                }
                else
                {
                    return g_mmi_imm_current_input_mode;
                }

            }

        }
    }
    else
#endif
    {
        /* return the next item */
        mode_id = g_mmi_imm_current_input_mode;

        if (g_mmi_imm_curr_allowed_input_mode[index + 1].mode_id != IMM_INPUT_MODE_NONE)
        {
            g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[index + 1].mode_id;
        }
        else
        {
            g_mmi_imm_current_input_mode = g_mmi_imm_curr_allowed_input_mode[0].mode_id;
        }

#if defined(__MMI_IMC_CAPITAL_SWITCH__)|| defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) 
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        if (mode_id != g_mmi_imm_current_input_mode)
        {
            mmi_imm_set_curr_writing_lang_by_curr_mode();
        }
#endif
#endif
    }


    return g_mmi_imm_current_input_mode;
}


#if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_check_same_mode_special_attribute_rule
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imm_check_same_mode_special_attribute_rule(U16 src_attrib, U16 target_attrib)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if ((src_attrib & IME_MODE_ATTR_UPPERCASE)
        || (src_attrib & IME_MODE_ATTR_LOWERCASE)
        || (src_attrib & IME_MODE_ATTR_TITLECASE))
    {
        if (src_attrib == target_attrib)
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
        if ((src_attrib & IME_MODE_ATTR_SMART)
            && (target_attrib & IME_MODE_ATTR_SMART))
        {
            return MMI_TRUE;
        }
        else if ((src_attrib & IME_MODE_ATTR_MULTITAP)
            && (target_attrib & IME_MODE_ATTR_MULTITAP))
        {
            return MMI_TRUE;
        }
        else if ((src_attrib & IME_MODE_ATTR_DIRECT)
            && (target_attrib & IME_MODE_ATTR_DIRECT))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
}
#endif /* #if defined(__MMI_IMM_INPUT_MODE_CHANGE_RULES__) */

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && (__MMI_CSTAR__)
#if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
void mmi_imm_get_group_letters_from_vk()
{
    mmi_imc_pen_get_group_letters_from_vk(g_mmi_imm_group_letter_set_for_vk, MMI_IMM_MAX_GROUP_LETTER_SET);
}
#endif
#endif

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_next_mode
* DESCRIPTION
*  Return next input mode in mode array. 
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_check_mixed_lang_support(mmi_imm_input_mode_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    U16 lang_attr = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    index = mmi_imm_is_system_supported_input_mode(target);
    if (index != -1)
    {
        lang_attr = gIMEModeArray[index].Lang_Special_Attrib;
        if (((lang_attr) & (IME_LANG_ATTR_MIXED_LANG_SUPPORT)))
            return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_next_mode
* DESCRIPTION
*  Return next input mode in mode array. 
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_smart_input_method(mmi_imm_input_mode_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    U16 input_attr = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    index = mmi_imm_is_system_supported_input_mode(target);
    if (index != -1)
    {
        input_attr = gIMEModeArray[index].Mode_Special_Attrib;
        if (((input_attr) & (IME_MODE_ATTR_SMART)))
            return MMI_TRUE;
    }
    return MMI_FALSE;

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_next_mode
* DESCRIPTION
*  Return next input mode in mode array. 
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_chinese_input_method(mmi_imm_input_mode_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    mmi_imm_support_writing_lang_enum wlang = IME_WRITING_LANG_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    index = mmi_imm_is_system_supported_input_mode(target);
    if (index != -1)
    {
        wlang = gIMEModeArray[index].lang_id;
        if ((wlang ==IME_WRITING_LANG_ZHTW) || 
            (wlang == IME_WRITING_LANG_ZHCN) ||
            (wlang == IME_WRITING_LANG_ZHHK))
            return MMI_TRUE;
    }
    return MMI_FALSE;

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_change_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_change_input_mode(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    const sIMEModeDetails *mode_details_ptr = NULL;
    U32 old_flag;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (mmi_imc_is_connected())
    {
        g_mmi_imm_is_change_input_mode_enabled = is_enabled;
    }
#if   defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
                if(mmi_imc_get_slider_status() == OPEN)
#endif
{

    if (mmi_imc_is_connected())
    {
        mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);

        if (!mode_details_ptr)
        {
            return;
        }

        if ((mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
            && (!g_mmi_imm_is_change_input_mode_enabled || mmi_imm_get_current_allowed_input_mode_num() <= 1))
        {
            old_flag = mmi_frm_qwerty_get_invalid_customized_special_key();

            old_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;

            mmi_frm_qwerty_set_invalid_customized_special_key(old_flag);
        }
    }
}
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_is_change_input_mode_enabled
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_change_input_mode_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    return g_mmi_imm_is_change_input_mode_enabled;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_test_r2l_input
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_test_r2l_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_imm_current_input_mode)
    {
    case IMM_INPUT_MODE_ARABIC_NUMERIC:
    case IMM_INPUT_MODE_SMART_ARABIC:
    case IMM_INPUT_MODE_SMART_HEBREW:
    case IMM_INPUT_MODE_SMART_PERSIAN:
    case IMM_INPUT_MODE_SMART_URDU:
    case IMM_INPUT_MODE_MULTITAP_ARABIC:
    case IMM_INPUT_MODE_MULTITAP_URDU:
    case IMM_INPUT_MODE_MULTITAP_HEBREW:
    case IMM_INPUT_MODE_MULTITAP_PERSIAN:
        return MMI_TRUE;
    default:
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_is_chinese_input_mode_valid
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imm_is_chinese_input_mode_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, p;
    U32 input_type_int = g_mmi_imm_current_input_type & (~IMM_INPUT_TYPE_MASK);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (input_type_int == IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE ||
        input_type_int == IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE)
    {
        return MMI_FALSE;
    }

    if (input_type_int == IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        MMI_ASSERT(g_mmi_imm_user_specific_input_mode_list);

        for (i = 0; g_mmi_imm_user_specific_input_mode_list[i] != IMM_INPUT_MODE_NONE; i++)
        {
            if ((p = mmi_imm_is_system_supported_input_mode(g_mmi_imm_user_specific_input_mode_list[i])) != -1)
            {
                if (gIMEModeArray[p].lang_id == IME_WRITING_LANG_ZHTW ||
                    gIMEModeArray[p].lang_id == IME_WRITING_LANG_ZHCN ||
                    gIMEModeArray[p].lang_id == IME_WRITING_LANG_ZHHK)
                {
                    return MMI_TRUE; 
                }
            }
        }
    }
    else
    {
        for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
        {
            if ((gIMEModeArray[i].supported_input_type_flag & input_type_int))
            { 
                if (gIMEModeArray[i].lang_id == IME_WRITING_LANG_ZHTW ||
                    gIMEModeArray[i].lang_id == IME_WRITING_LANG_ZHCN ||
                    gIMEModeArray[i].lang_id == IME_WRITING_LANG_ZHHK)
                {
                    return MMI_TRUE; 
                }
            }
        }

    }

    return MMI_FALSE;
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_is_smart_alphabetic_input_mode_available
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
MMI_BOOL mmi_imm_is_smart_alphabetic_input_mode_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
    S32 i = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
    for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
    {
        if ((gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
            && (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_allowed_email_address_characters
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
 UI_string_type mmi_imm_get_allowed_email_address_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    return ( UI_string_type)&g_mmi_imm_email_allowed[0];
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_allowed_voip_number_characters
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
 UI_string_type mmi_imm_get_allowed_voip_number_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    return ( UI_string_type)&g_mmi_imm_voip_number_allowed[0];
}


#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_config_smart_alphabetic_input_modes
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_smart_alphabetic_input_modes(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    g_mmi_imm_is_smart_alphabetic_input_modes_enalbed = is_enabled;

    data = g_mmi_imm_is_smart_alphabetic_input_modes_enalbed;

    WriteValue(NVRAM_IME_SMART_MODE_CONFIG, &data, DS_BYTE, &error);
	 #ifdef __MMI_PREFER_INPUT_METHOD__
    mmi_imm_get_prefer_input_mode_list(MMI_all_prefered_input_mode_set, IMM_INPUT_MODE_MAX_NUM);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_is_smart_alphabetic_input_modes_enabled
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_smart_alphabetic_input_modes_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return g_mmi_imm_is_smart_alphabetic_input_modes_enalbed;
}
#endif /* #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__) */


#if defined(__MMI_IME_USER_DATABASE__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_get_new_word_string_by_language
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
UI_string_type mmi_imm_get_new_word_string_by_language(mmi_imm_support_writing_lang_enum lang_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CSTAR__)
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_CSTAR__)
    for (i = 0; g_mmi_imm_new_word_string_mapping_table[i].lang_id != IME_WRITING_LANG_NONE; i++)
    {
        if (lang_id == g_mmi_imm_new_word_string_mapping_table[i].lang_id)
        {
            return &(g_mmi_imm_new_word_string_mapping_table[i].new_word[0]);
        }
    }

    return NULL;
#else
    return (UI_string_type)get_string(STR_INPUT_METHOD_SPELL_WORD);
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_does_current_lang_support_add_new_word
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_does_current_lang_support_add_new_word(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    for (i = 0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
    {
        if (
#if defined(__MMI_IMC_CAPITAL_SWITCH__)|| defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) 
            gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id == g_mmi_imm_curr_writing_lang
#else
            gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].imm_mode_id == g_mmi_imm_current_input_mode
#endif
            && (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
            && (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

#endif /* #if defined(__MMI_IME_USER_DATABASE__) */

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_disabled_and_allowed_character_list
* DESCRIPTION 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_get_disabled_and_allowed_character_list(mmi_imm_allowed_character_list_struct_p list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    memcpy(list->allowed_characters, g_mmi_imm_allowed_characters, sizeof(UI_character_type) * (MMI_IMM_MAX_ALLOWED_CHARACTER_NUM));
    memcpy(list->disabled_characters, g_mmi_imm_disabled_characters, sizeof(UI_character_type) * (MMI_IMM_MAX_DISABLE_CHARACTER_NUM));

#if defined(__MMI_TOUCH_SCREEN__)
    memcpy(list->allowed_events, g_mmi_imm_allowed_events, sizeof(gui_virtual_keyboard_pen_enum) * (MMI_IMM_MAX_ALLOWED_CHARACTER_NUM));
    memcpy(list->disabled_events, g_mmi_imm_disabled_events, sizeof(gui_virtual_keyboard_pen_enum) * (MMI_IMM_MAX_DISABLE_CHARACTER_NUM));
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_disabled_and_allowed_character_list
* DESCRIPTION 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_disabled_and_allowed_character_list(mmi_imm_allowed_character_list_struct_p list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    memcpy(g_mmi_imm_allowed_characters, list->allowed_characters, sizeof(UI_character_type) * (MMI_IMM_MAX_ALLOWED_CHARACTER_NUM));
    memcpy(g_mmi_imm_disabled_characters, list->disabled_characters, sizeof(UI_character_type) * (MMI_IMM_MAX_DISABLE_CHARACTER_NUM));

#if defined(__MMI_TOUCH_SCREEN__)
    memcpy(g_mmi_imm_allowed_events, list->allowed_events, sizeof(gui_virtual_keyboard_pen_enum) * (MMI_IMM_MAX_ALLOWED_CHARACTER_NUM));
    memcpy(g_mmi_imm_disabled_events, list->disabled_events, sizeof(gui_virtual_keyboard_pen_enum) * (MMI_IMM_MAX_DISABLE_CHARACTER_NUM));
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_is_smart_input_mode_valid
* DESCRIPTION 
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_smart_input_mode_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, p;
    U32 input_type_int = g_mmi_imm_current_input_type & (~IMM_INPUT_TYPE_MASK);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

#if defined(__MMI_IME_FTE_ENHANCE__)
    if ((input_type_int & IMM_INPUT_TYPE_URL) || 
        (input_type_int & IMM_INPUT_TYPE_EMAIL))
    {
        return MMI_FALSE;    
    }
#endif

    if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EXT_PASSWORD))
    {
        return MMI_FALSE;
    }

    if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EXT_MULTITAP))
    {
        return MMI_FALSE;
    }

    if (input_type_int == IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE ||
        input_type_int == IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE)
        input_type_int = IMM_INPUT_TYPE_ENGLISH_SENTENCE;

    if (input_type_int == IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        MMI_ASSERT(g_mmi_imm_user_specific_input_mode_list);

        for (i = 0; g_mmi_imm_user_specific_input_mode_list[i] != IMM_INPUT_MODE_NONE; i++)
        {
            if ((p = mmi_imm_is_system_supported_input_mode(g_mmi_imm_user_specific_input_mode_list[i])) != -1)
            {
                if ((gIMEModeArray[p].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                    && ((gIMEModeArray[p].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                    || (gIMEModeArray[p].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)))
                {
                    return MMI_TRUE; 
                }
            }
        }
    }
    else
    {
        for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
        {
            if ((gIMEModeArray[i].supported_input_type_flag & input_type_int))
            { 
                if ((gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                    && ((gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                    || (gIMEModeArray[i].Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)))
                {
                    return MMI_TRUE; 
                }
            }
        }

    }

    return MMI_FALSE;
}


#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__) 

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_hw_category
* DESCRIPTION 
* PARAMETERS
* RETURNS
*****************************************************************************/

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
mmi_imm_hand_writing_category_info_struct_p mmi_imm_get_hand_writing_category(mmi_imm_support_writing_lang_enum lang_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    while (g_mmi_imm_hw_category_table[i].lang_id != IME_WRITING_LANG_NONE)
    {
        if (g_mmi_imm_hw_category_table[i].lang_id == lang_id)
            break;
        i ++;
    }
    return &g_mmi_imm_hw_category_table[i];
}
#elif defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
mmi_imm_hand_writing_category_info_struct_p mmi_imm_get_hand_writing_category(mmi_imm_support_writing_lang_enum lang_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}
#endif

#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__)  */

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_set_switch_icon
* DESCRIPTION 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_special_key_icon(U32 special_key_flag, U32 special_key_lock_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (special_key_lock_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
    {
        g_mmi_imm_special_key_icon = IMG_IME_QWERTY_SHIFT_LOCK;
        g_mmi_imm_current_input_case = MMI_IME_HINT_FLAG_UPPER_CASE;
    }
    else if (special_key_lock_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
    {
        g_mmi_imm_special_key_icon = IMG_IME_QWERTY_FN_LOCK;
    }
    else if (special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
    {
        g_mmi_imm_special_key_icon = IMG_IME_QWERTY_SHIFT;
        g_mmi_imm_current_input_case = MMI_IME_HINT_FLAG_FIRST_UPPER_CASE;
    }
    else if (special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
    {
        g_mmi_imm_special_key_icon = IMG_IME_QWERTY_FN;
    }
    else 
    {
        g_mmi_imm_current_input_case = MMI_IME_HINT_FLAG_LOWER_CASE;
        g_mmi_imm_special_key_icon = 0;
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_get_switch_icon
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U16 mmi_imm_get_special_key_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    return g_mmi_imm_special_key_icon;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_switch_icon
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_ime_hint_flag_enum mmi_imm_get_current_input_case(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    return g_mmi_imm_current_input_case;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_special_key_validation
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_special_key_validation(const sIMEModeDetails * mode_details_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 invalid_flag = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    mmi_frm_qwerty_set_invalid_customized_special_key(0);

    switch(mode_details_ptr->imm_mode_id)
    {
    case IMM_INPUT_MODE_123:
    case IMM_INPUT_MODE_SIGNED_123:
    case IMM_INPUT_MODE_FLOAT_123:
    case IMM_INPUT_MODE_SIM_NUMERIC:
    case IMM_INPUT_MODE_SIGNED_FLOAT_123:
    case IMM_INPUT_MODE_KEYPAD_NUMERIC:
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK;
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        break;

    case IMM_INPUT_MODE_PHONE_NUMBER:
        if (mmi_imm_get_current_allowed_input_mode_num() == 1) /* For the special case of entering recipient*/
        {
            invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK;
        }

        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        break;

    case IMM_INPUT_MODE_123_SYMBOLS:
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK;
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        break;

    case IMM_INPUT_MODE_ARABIC_NUMERIC:
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        break;

    case IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR:
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK;
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        break;

    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC:
    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC:
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK;
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        break;

    case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
    case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:
#if !defined(__MMI_IME_V3__)
    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC:
    case IMM_INPUT_MODE_SMART_UPPERCASE_ABC:
#endif
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        break;

    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:		
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        break;

    default:
        break;
    }

    if (mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)
    {
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
    }

    if (!mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_123_SYMBOLS))
    {
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK;
    }

    if (!mmi_imm_qwerty_is_valid_special_key_of_current_lang(MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT))
    {
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
    }

    if ((mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
        && (!mmi_imm_is_change_input_mode_enabled() || mmi_imm_get_current_allowed_input_mode_num() <= 1))
    {
        invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
    }
    else if (mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC
        && (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_USER_SPECIFIC)
        && !mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC))
    {
        mmi_imc_message_struct imc_msg;

        imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;

        if (mmi_imc_send_message(&imc_msg))
        {
            invalid_flag |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        }
    }

#ifdef __MMI_IME_PLUG_IN__
    invalid_flag = mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_GET_INVALID_QWERTY_SPECIAL_KEY, invalid_flag, 0);
#endif

    mmi_frm_qwerty_set_invalid_customized_special_key(invalid_flag);
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_is_dead_character_of_current_lang
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_dead_character_of_current_lang(UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	const sIMEModeDetails *mode_details_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);
	if(mode_details_ptr->lang_id == IME_WRITING_LANG_ABC)
	{
		return MMI_FALSE;
	}
    if (g_mmi_imm_current_dead_key_table)
    {
        for (i = 0; g_mmi_imm_current_dead_key_table[i].input_len > 0; i++ )
        {
            if (g_mmi_imm_current_dead_key_table[i].input_char[0] == char_code)
            {
                return MMI_TRUE;
            }
        }

        if (g_mmi_imm_current_dead_key_table[i].input_len <= 0)
        {
            return MMI_FALSE;
        }
    } 

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_merged_character_of_current_lang
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
UI_character_type mmi_imm_get_merged_character_of_current_lang(UI_character_type dead_char, UI_character_type original_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (g_mmi_imm_current_dead_key_table)
    {
        for (i = 0; g_mmi_imm_current_dead_key_table[i].input_len > 0; i++ )
        {
            if (g_mmi_imm_current_dead_key_table[i].input_char[0] == dead_char
                && g_mmi_imm_current_dead_key_table[i].input_char[1] == original_char)
            {
                return g_mmi_imm_current_dead_key_table[i].output_char;
            }
        }

        if (g_mmi_imm_current_dead_key_table[i].input_len <= 0)
        {
            return 0;
        }
    }

    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_change_dead_character_lang_table
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_change_dead_character_lang_table(mmi_imm_support_writing_lang_enum lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    for (i = 0; g_mmi_imm_dead_key_lang_talbe[i].lang_id != IME_WRITING_LANG_NONE; i++)
    {
        if (g_mmi_imm_dead_key_lang_talbe[i].lang_id == lang)
        {
            g_mmi_imm_current_dead_key_table = (mmi_imm_dead_key_symbol_struct_p)g_mmi_imm_dead_key_lang_talbe[i].table_ptr;
            break;
        }
    }

    if (g_mmi_imm_dead_key_lang_talbe[i].lang_id == IME_WRITING_LANG_NONE)
    {
#ifdef __MMI_IMM_EUROPEAN_LANGUAGE_DEAD_KEY_TABLE__
        g_mmi_imm_current_dead_key_table = (mmi_imm_dead_key_symbol_struct_p)&g_mmi_imm_european_dead_key_table[0];
#else
        g_mmi_imm_current_dead_key_table = NULL;
#endif
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_is_strict_morphology_language
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_strict_morphology_language(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails *mode_details_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);

    if (!mode_details_ptr)
    {
        return MMI_FALSE;
    }

    switch(mode_details_ptr->lang_id)
    {
    case IME_WRITING_LANG_VI:
    case IME_WRITING_LANG_AR:
    case IME_WRITING_LANG_UR:
    case IME_WRITING_LANG_PS:
    case IME_WRITING_LANG_HE:
    case IME_WRITING_LANG_TH:
    case IME_WRITING_LANG_HI:
    case IME_WRITING_LANG_MR:
    case IME_WRITING_LANG_TA:
    case IME_WRITING_LANG_BE:
    case IME_WRITING_LANG_AS:
    case IME_WRITING_LANG_PA:
    case IME_WRITING_LANG_TE:
    case IME_WRITING_LANG_KN:
    case IME_WRITING_LANG_GU:
    case IME_WRITING_LANG_ML:
    case IME_WRITING_LANG_OR:
        return MMI_TRUE;
    default:
        break;
    }

    return MMI_FALSE;

}
#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */


#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_is_auto_capitalization_valid
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_auto_capitalization_validation(MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_mmi_imm_is_auto_capitalization_valid = is_valid;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_is_auto_capitalization_valid
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_auto_capitalization_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct imc_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (!g_mmi_imm_is_auto_capitalization_valid)
    {
        return MMI_FALSE;
    }

#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_clipboard_state())
    {
        return MMI_FALSE;
    }
#endif

    if (!mmi_imm_is_auto_capitalization_enabled())
    {
        return MMI_FALSE;
    }

    if(!mmi_imm_does_current_type_support_titlecase())
        return MMI_FALSE;

    imc_msg.message_id = MMI_IMC_MESSAGE_WCSS_CHECK;

    if (mmi_imc_send_message(&imc_msg))
    {
        return MMI_FALSE;
    }

    if (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        U32 i = 0, j, k;
        U8 index_check_bits[IMM_INPUT_MODE_MAX_NUM / 8];
        ime_mode_attr_enum mode_type;

        memset(index_check_bits, 0, IMM_INPUT_MODE_MAX_NUM / 8);

        while (g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE)
        {
            k = 0;

            while (k < 2)
            {
                if (k == 0)
                {
                    mode_type = IME_MODE_ATTR_SMART;
                }
                else
                {
                    mode_type = IME_MODE_ATTR_MULTITAP;
                }

                if ((gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Mode_Special_Attrib & mode_type)
                    && (gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                    && !(index_check_bits[i / 8] & (1 << (i % 8))))
                {
                    mmi_imm_support_writing_lang_enum lang_id = gIMEModeArray[g_mmi_imm_curr_allowed_input_mode[i].index].lang_id;
                    S32 index;
                    MMI_BOOL lowercase = MMI_FALSE, uppercase = MMI_FALSE, titlecase = MMI_FALSE;

                    for (j = 0; g_mmi_imm_curr_allowed_input_mode[j].mode_id != IMM_INPUT_MODE_NONE; j++)
                    {
                        index = g_mmi_imm_curr_allowed_input_mode[j].index;

                        if (gIMEModeArray[index].lang_id == lang_id &&
                            (gIMEModeArray[index].Mode_Special_Attrib & mode_type) && 
                            (gIMEModeArray[index].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC) &&
                            (gIMEModeArray[index].Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE))
                        {
                            index_check_bits[index / 8] |= (1 << (index % 8));

                            lowercase = MMI_TRUE;
                        }
                        else if (gIMEModeArray[index].lang_id == lang_id &&
                            (gIMEModeArray[index].Mode_Special_Attrib & mode_type) && 
                            (gIMEModeArray[index].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC) &&
                            (gIMEModeArray[index].Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE))
                        {
                            index_check_bits[index / 8] |= (1 << (index % 8));

                            uppercase = MMI_TRUE;
                        }
                        else if (gIMEModeArray[index].lang_id == lang_id &&
                            (gIMEModeArray[index].Mode_Special_Attrib & mode_type) && 
                            (gIMEModeArray[index].Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC) &&
                            (gIMEModeArray[index].Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE))
                        {
                            index_check_bits[index / 8] |= (1 << (index % 8));

                            titlecase = MMI_TRUE;
                        }

                        if (lowercase && uppercase && titlecase)
                        {
                            break;
                        }
                    }

                    if (!(lowercase && uppercase && titlecase) && /* Lost a case */
                        !(!lowercase && !uppercase && !titlecase) /* Don't have cases */
                        )
                    {
                        return MMI_FALSE;
                    }
                }

                k++;
            }
            i++;
        }
    }

    return MMI_TRUE;
}
#endif /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */

/*****************************************************************************
* FUNCTION
* mmi_imm_read_prefered_writing_lang_from_nvram
* DESCRIPTION
* Get prefered mode from NVRAM
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_read_prefered_writing_lang_from_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    ReadValue(NVRAM_SETTING_WRITING_LANG, &g_mmi_imm_main_writing_lang, DS_SHORT, &error);
#endif
}

/*****************************************************************************
* FUNCTION
* mmi_imm_write_prefered_writing_lang_to_nvram
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_write_prefered_writing_lang_to_nvram()
{

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    WriteValue(NVRAM_SETTING_WRITING_LANG, &g_mmi_imm_main_writing_lang, DS_SHORT, &error);
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_set_main_lang
* DESCRIPTION
*  to set main language. 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_main_lang(mmi_imm_support_writing_lang_enum main_lang)
{

#if defined(__MMI_PREFER_WRITING_LANG__) || defined (__MMI_MIXED_LANG_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*  fix for botup issue */
    if ( main_lang == 0xFFFF || main_lang == 0xFF)
        g_mmi_imm_main_writing_lang =IME_WRITING_LANG_ABC;
    else
        g_mmi_imm_main_writing_lang = main_lang;

#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_main_lang
* DESCRIPTION
*  to set main language. 
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_support_writing_lang_enum mmi_imm_get_main_lang(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_PREFER_WRITING_LANG__) || defined (__MMI_MIXED_LANG_SUPPORT__)

    return g_mmi_imm_main_writing_lang;
#else
    return 0;
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_update_prefer_writing_language
* DESCRIPTION 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_update_prefer_writing_language(mmi_imm_support_writing_lang_enum writing_lang)
{
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) 

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 value;
    S16 error;
    S32 i = 0;
#if defined(__MMI_MIXED_LANG_SUPPORT__)  

    S32 index =0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(writing_lang == IME_WRITING_LANG_123)
        return;

    value = writing_lang;
    mmi_imm_set_main_lang((mmi_imm_support_writing_lang_enum)value);
    WriteValue(NVRAM_SETTING_WRITING_LANG, &value, DS_SHORT, &error);

#if defined(__MMI_MIXED_LANG_SUPPORT__)  
    while  (g_ime_writing_lang_array[index].lang_id != writing_lang)
    {
        index++;
    }

    /* if main language doesnot support mix language */
    if (!g_ime_writing_lang_array[index].mixed_lang_support)
    {
        mmi_imm_set_sub_lang(IME_WRITING_LANG_NONE);
    }
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 



    /* we need to calculate input mode */
    while (g_ime_writing_lang_array[i].lang_id != writing_lang)
    {
        i++;
    }
    value = g_ime_writing_lang_array[i].default_input_mode;
    mmi_imm_set_prefer_input_mode((mmi_imm_input_mode_enum)value);
    WriteValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &value, DS_SHORT, &error);

#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_phone_language_change_handler
* DESCRIPTION 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_phone_language_change_handler(void)
{

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
    /* to make sure on bootup NVRAM value and not the MMI lang determines wlang*/
    static MMI_BOOL is_bootup = MMI_TRUE ; 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
   U8 *ssc = NULL;
   S16 j = 0;
#endif
    if (!is_bootup)
    {
        while (gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
        {
 #ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
		mmi_li_get_ssc_by_lcc(gIMEModeArray[i].aLangCountryCode,&ssc);//ctt 
		j = mmi_lang_support((kal_char *)ssc);
		if (j >= 0)	
        	{
             	    break;
        	}
#else
            if (app_stricmp((kal_char *)gIMEModeArray[i].aLangCountryCode, (kal_char *)gLanguageArray[gCurrLangIndex].aLangCountryCode) == 0)
            {
                break;
            }
		#endif
            i++;
        }

        if (gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM)
        {
            i = mmi_imm_get_index_in_system_writing_language(gIMEModeArray[i].lang_id);
            if (i >= 0)
            {
                mmi_imm_update_prefer_writing_language(g_ime_writing_lang_array[i].lang_id);
            }
        }
    }
    else
    {
        is_bootup = MMI_FALSE;
    }
#endif 
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_read_prefered_writing_sub_lang_from_nvram()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_MIXED_LANG_SUPPORT__) 
    ReadValue(NVRAM_SETTING_WRITING_LANG_SUB, &value, DS_SHORT, &error);
    mmi_imm_set_sub_lang(((value == 0xFFFF) ? IME_WRITING_LANG_NONE : (S16)value));
#endif
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_write_prefered_sub_writing_lang_to_nvram()
{

#if defined(__MMI_MIXED_LANG_SUPPORT__) 

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    WriteValue(NVRAM_SETTING_WRITING_LANG_SUB, &g_mmi_imm_sub_writing_lang, DS_SHORT, &error);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_sub_lang
* DESCRIPTION
*  to set sub language. 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_sub_lang(mmi_imm_support_writing_lang_enum sub_lang)
{
#if defined(__MMI_MIXED_LANG_SUPPORT__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if ( sub_lang == 0xFFFF)
        g_mmi_imm_sub_writing_lang =IME_WRITING_LANG_NONE;
    else
        g_mmi_imm_sub_writing_lang = sub_lang;

    WriteValue(NVRAM_SETTING_WRITING_LANG_SUB, &g_mmi_imm_sub_writing_lang, DS_SHORT, &error);

#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_sub_lang
* DESCRIPTION
*  to set sub language. 
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_support_writing_lang_enum mmi_imm_get_sub_lang(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_MIXED_LANG_SUPPORT__) 
    return g_mmi_imm_sub_writing_lang;
#else
    return IME_WRITING_LANG_NONE;
#endif

}


/*****************************************************************************
* FUNCTION
*  ime_init_get_writing_lang_str
* DESCRIPTION
*  To init  
* PARAMETERS
*  void
* RETURNS
*  UI_string_type
*****************************************************************************/
UI_string_type mmi_imm_init_writing_lang_str(UI_string_type lang_country_code)
{
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                               */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
   U8 *ssc = NULL;
   mmi_li_get_ssc_by_lcc((U8 *)lang_country_code,&ssc);
   i = mmi_lang_support((CHAR*)ssc);
   if (i >= 0)//ctt change to ssc
   {
         return (UI_string_type)gLanguageArray[i].aName;
   }
    return NULL;
#else 
   for (i = 0; i < gMaxDeployedLangs; i++)
    {
        if (strcmp((CHAR*)lang_country_code, (CHAR*)gLanguageArray[i].aLangCountryCode) == 0)
        {
            return (UI_string_type)gLanguageArray[i].aName;
        }
    }
    return NULL;
#endif
#else
    return NULL;
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_is_enabled_wlang
* DESCRIPTION
*  To check whether a wlang is enabled or not  in Phone settings
* PARAMETERS
*  void
* RETURNS
*  UI_string_type
*****************************************************************************/
MMI_BOOL mmi_imm_is_enabled_wlang(S32 wlang)
{
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                               */
    /*----------------------------------------------------------------*/
    S32 i=0;     
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                                      */
    /*----------------------------------------------------------------*/

    while(g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_NONE && g_ime_writing_lang_array[i].lang_id != wlang) 
        i++;

    return  g_ime_writing_lang_array[i].enabled;
#else
    return MMI_TRUE;
#endif

}


/*****************************************************************************
* FUNCTION
*  ime_init_support_lang
* DESCRIPTION
*  To init  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_imm_init_writing_lang()
{
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */      
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j = 0;
    S32 total = 0;
    S16 error;
    U16 value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                              */        
    /*----------------------------------------------------------------*/

    ReadValue(NVRAM_SETTING_ENABLED_WRITING_LANGUAGE, &g_mmi_imm_enabled_writing_language, DS_SHORT, &error);
    while(IMM_INPUT_MODE_MAX_NUM > gIMEModeArray[i].imm_mode_id)
    {
        /* Search g_ime_writing_lang_array to check if the input method belong to a new lang */
        for( j = 0; j < total; j++)
        {
            if (g_ime_writing_lang_array[j].lang_id == gIMEModeArray[i].lang_id) 
                break; 
        }
        if (j < total)
        {
            /* the input method belong to a existed lang in g_ime_writing_lang_array */
#ifdef __MMI_MIXED_LANG_SUPPORT__
            if (IME_IS_MIXED_LANG_SUPPORT(gIMEModeArray[i].Lang_Special_Attrib))
            {
                g_ime_writing_lang_array[j].mixed_lang_support = MMI_TRUE; 
            }            
#endif
        }
        else
        {
            if (gIMEModeArray[i].lang_id != IME_WRITING_LANG_NONE 
                && gIMEModeArray[i].lang_id != IME_WRITING_LANG_123
                && (gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_SENTENCE)
#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
                && mmi_imc_memory_card_is_language_supported(&gIMEModeArray[i],j))
#else
				)
#endif
  
            {
                /* the input method belong to a new lang to g_ime_writing_lang_array */
                g_ime_writing_lang_array[j].default_input_mode = gIMEModeArray[i].imm_mode_id;
                g_ime_writing_lang_array[j].lang_id = gIMEModeArray[i].lang_id;
                g_ime_writing_lang_array[j].lang_str_ptr = mmi_imm_init_writing_lang_str((UI_string_type)gIMEModeArray[i].aLangCountryCode);
				if( g_ime_writing_lang_array[j].lang_id == IME_WRITING_LANG_HABC) 
				{
					g_ime_writing_lang_array[j].lang_str_ptr = (UI_string_type)mmi_imm_hinglish_language_name;
				}


                /* Checking whther the writing language is enabled in writing language settings or not */
                if(0x1 & (g_mmi_imm_enabled_writing_language >> (15 - j)))
                {
                    g_ime_writing_lang_array[j].enabled = MMI_TRUE;
                    g_enabled_wlang_count++;
                }
                else
                {
                    g_ime_writing_lang_array[j].enabled = MMI_FALSE;
                    g_enabled_wlang_count++;
                }
#ifdef __MMI_MIXED_LANG_SUPPORT__    
                g_ime_writing_lang_array[j].mixed_lang_support = MMI_FALSE;

                if (IME_IS_MIXED_LANG_SUPPORT(gIMEModeArray[i].Lang_Special_Attrib))
                {
                    g_ime_writing_lang_array[j].mixed_lang_support = MMI_TRUE; 
                }
#endif   

                total++;
            }
        }
        i++;

        MMI_ASSERT(total <= (MAX_WRITING_LANG - 2));
    }
    /* 123... */
    g_ime_writing_lang_array[total].default_input_mode = IMM_INPUT_MODE_123_SYMBOLS;
    g_ime_writing_lang_array[total].lang_id = IME_WRITING_LANG_123;
    g_ime_writing_lang_array[total].lang_str_ptr = (UI_string_type)GetString(STR_ID_IME_WRITING_LANGUAGE_123);
    g_enabled_wlang_count ++;
    g_ime_writing_lang_array[total].enabled = MMI_TRUE;
#ifdef __MMI_MIXED_LANG_SUPPORT__     
    g_ime_writing_lang_array[total].mixed_lang_support = MMI_FALSE;
#endif
    total++;
    /* None */
    g_ime_writing_lang_array[total].default_input_mode = IMM_INPUT_MODE_MAX_NUM;
    g_ime_writing_lang_array[total].lang_id = IME_WRITING_LANG_NONE;
#ifdef __MMI_MIXED_LANG_SUPPORT__ 
    g_ime_writing_lang_array[total].mixed_lang_support = MMI_TRUE;
#endif
    g_ime_writing_lang_array[total].lang_str_ptr = (UI_string_type)GetString(STR_GLOBAL_NONE);

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    ReadValue(NVRAM_SETTING_WRITING_LANG, &value, DS_SHORT, &error);
    mmi_imm_set_main_lang((mmi_imm_support_writing_lang_enum)value);
#endif

#if defined(__MMI_MIXED_LANG_SUPPORT__)
    mmi_imm_read_prefered_writing_sub_lang_from_nvram();
#endif

    i = 0;
    while(IMM_INPUT_MODE_MAX_NUM > gIMEModeArray[i].imm_mode_id)
    {
        if (gIMEModeArray[i].lang_id == mmi_imm_get_main_lang()
            && (gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_SENTENCE))
            break;
        i ++;
    }
    /* To check if the MMI_prefered_input_type read from NVRAM is supported or not */
    if ((mmi_imm_is_system_supported_input_mode(g_mmi_imm_prefer_input_mode) != -1) ||
        (g_mmi_imm_prefer_input_mode != gIMEModeArray[i].imm_mode_id))
    {
        mmi_imm_set_prefer_input_mode(gIMEModeArray[i].imm_mode_id);
    }
#endif    
}


#if defined(__MMI_IME_V3__)
U32 mmi_imm_get_all_writing_language_and_mode_num_for_list()
{
    U32 i = 0, ret = 0;

    for(i = 0; g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_123 ; i++)
        {
            if(g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_ZHCN
                ||g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_ZHTW)
                {
                    ret++;
                }
        }
    ret = i - ret;

    for(i = 0; gIMEModeArray[i].lang_id != IME_WRITING_LANG_NONE 
                && gIMEModeArray[i].lang_id != IME_WRITING_LANG_123
                && (gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_SENTENCE); i++)
        {
            if(gIMEModeArray[i].lang_id == IME_WRITING_LANG_ZHCN
                ||gIMEModeArray[i].lang_id == IME_WRITING_LANG_ZHTW)
                {
                    if(gIMEModeArray[i].imm_mode_id == IMM_INPUT_MODE_SM_PINYIN
                        || gIMEModeArray[i].imm_mode_id == IMM_INPUT_MODE_SM_STROKE
                        || gIMEModeArray[i].imm_mode_id == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO
                        || gIMEModeArray[i].imm_mode_id == IMM_INPUT_MODE_TR_STROKE)
                        {
                            ret++;
                        }
                }
        }
    return ret;
}

U32 mmi_imm_get_all_writing_language_and_mode_item_for_list(UI_string_type* str_list)
{
    U32 i = 0, ret = 0, j=0;

    for(i = 0; g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_123 ; i++)
        {
            if(g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_ZHCN
                ||g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_ZHTW)
                {
                    ret++;
                    continue;
                }
            str_list[j] = g_ime_writing_lang_array[i].lang_str_ptr;
            j++;
        }
    ret = i - ret;

    for(i = 0; gIMEModeArray[i].lang_id != IME_WRITING_LANG_NONE 
            && gIMEModeArray[i].lang_id != IME_WRITING_LANG_123
            && (gIMEModeArray[i].supported_input_type_flag & IMM_INPUT_TYPE_SENTENCE); i++)
    {
        if(gIMEModeArray[i].lang_id == IME_WRITING_LANG_ZHCN
            ||gIMEModeArray[i].lang_id == IME_WRITING_LANG_ZHTW)
            {
                if(gIMEModeArray[i].imm_mode_id == IMM_INPUT_MODE_SM_PINYIN
                    || gIMEModeArray[i].imm_mode_id == IMM_INPUT_MODE_SM_STROKE
                    || gIMEModeArray[i].imm_mode_id == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO
                    || gIMEModeArray[i].imm_mode_id == IMM_INPUT_MODE_TR_STROKE)
                    {
                        str_list[j] = (UI_string_type)GetString(gIMEModeArray[i].menuitem_string_id);
                    }
            }
    }
    return ret;
}

U32 mmi_imm_set_writing_language_and_mode_setting_for_list(MMI_BOOL* Index, U16 num)
{
    U32 i = 0,data;
    S16 error;
    for(i = 0; i < num; i++)
        {
            if(Index[i])
                {
                    //g_mmi_imm_language_setting |= (1 << i);
                    g_mmi_imm_enabled_writing_language |= (1 << i);
                }
            else
                {
                    //g_mmi_imm_language_setting &= ~(1 <<i );
                    g_mmi_imm_enabled_writing_language &= ~(1 <<i );
                }
        }
    data = g_mmi_imm_enabled_writing_language;
    WriteValue(NVRAM_SETTING_ENABLED_WRITING_LANGUAGE, &data, DS_SHORT, &error);
}

U32 mmi_imm_get_writing_language_and_mode_setting_for_list(MMI_BOOL* Index, U16 num)
{
    U32 i = 0;
    MMI_ASSERT(num < 16);
    for(i = 0; i < num; i++)
        {
            //Index[i] = g_mmi_imm_language_setting & (1 << i);
            Index[i] = g_mmi_imm_enabled_writing_language & (1 << i);
        }
}

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)

void mmi_imm_set_handwriting_default_input_mode(mmi_imm_input_mode_enum input_mode)
{
    if(!mmi_imm_is_curr_allow_input_mode(input_mode))
        input_mode = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
    g_mmi_imm_default_handwriting_input_mode = input_mode;
}


mmi_imm_input_mode_enum mmi_imm_get_handwriting_default_input_mode(void)
{
    mmi_imm_input_mode_enum input_mode;
    if(mmi_imm_handwriting_is_follow_vk())
        {
            input_mode = g_mmi_imm_current_input_mode;
        }
    else
        {
            input_mode = g_ime_writing_lang_array[g_current_handwriting_lang_id].default_input_mode;
        }
    if(!mmi_imm_is_curr_allow_input_mode(input_mode))
    {
        if(mmi_imm_is_curr_allow_input_mode(g_mmi_imm_default_handwriting_input_mode))
        {
            input_mode = g_mmi_imm_default_handwriting_input_mode;
        }
        else
        {
            input_mode = g_mmi_imm_curr_allowed_input_mode[0].mode_id;
        }
    }
    return input_mode;
}
#endif
#endif

#endif

#if defined(__MMI_IME_FUZZY_PINYIN__)

/*****************************************************************************
* FUNCTION
*  mmi_imm_init_fuzzy_pinyin_setting
* DESCRIPTION
*  To init  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_imm_init_fuzzy_pinyin_setting()
{
    U16 i; 
    U16 data;
    S16 error;
    for(i=0; i < IME_FUZZY_PINYIN_MAX; i++)
    {
        g_ime_fuzzy_pinyin_array[i].fuzzy_id = fuzzy_pinyin_enum_array[i];
        g_ime_fuzzy_pinyin_array[i].fuzzy_str_ptr = g_fuzzy_pinyin_menu_item[i];
    }
    // read from NVRAM
    ReadValue((U16)NVRAM_SETTING_ENABLED_FUZZY_PINYIN, (void*)&data, (U8)DS_SHORT, (S16*)&error);
	g_mmi_imm_enabled_fuzzy_pinyin = data;

}

#endif

/*****************************************************************************
* FUNCTION
*  mmi_imm_map_wlang_logical_index_ui_index
* DESCRIPTION
* Gives writing lang index 
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_map_wlang_logical_index_ui_index(S32 lang_id)
{
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32  i =0;
    S32  j =0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0  ; g_ime_writing_lang_array[i].lang_id!= IME_WRITING_LANG_NONE; i++)
    {
        if (g_ime_writing_lang_array[i].lang_id == lang_id )
        {
            return j;
        }
        if ( g_ime_writing_lang_array[i].enabled)
        {
            j++;
        }

    }

    return 0;
#else
    return 0;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_map_wlang_logical_index_ui_index
* DESCRIPTION
* Gives writing lang index 
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_map_wlang_logical_index_ui_index_for_sub(S32 lang_id)
{
#if  defined(__MMI_MIXED_LANG_SUPPORT__)

    S32  i =0;
    S32  j =0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; g_ime_writing_lang_array[i].lang_id!= IME_WRITING_LANG_NONE; i++)
    {
        if (g_ime_writing_lang_array[i].lang_id == lang_id )
        {
            return j;
        }
        if ( g_ime_writing_lang_array[i].enabled && g_ime_writing_lang_array[i].mixed_lang_support)
        {
            j++;
        }
    }
    if( g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_NONE)
        return j;
#else
    return 0;
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_map_wlang_logical_index_ui_index
* DESCRIPTION
* Gives writing lang index 
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imm_map_wlang_ui_index_sub_lang(S32 index)
{
#if  defined(__MMI_MIXED_LANG_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  i = 0;
    S32  j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; g_ime_writing_lang_array[i].lang_id!= IME_WRITING_LANG_NONE; i++)
    {
        if (j == index  && g_ime_writing_lang_array[i].mixed_lang_support && g_ime_writing_lang_array[i].enabled)
        {
            return g_ime_writing_lang_array[i].lang_id;
        }
        if ( g_ime_writing_lang_array[i].enabled && g_ime_writing_lang_array[i].mixed_lang_support)
        {
            j++;
        }
    }

    return 0;
#else
    return 0;
#endif
}
/*****************************************************************************
* FUNCTION
*  mmi_imm_wlang_change_handler
* DESCRIPTION
*  for setting wlang from editors option menu
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_wlang_change_handler(S32 index)

{

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i,j;
    mmi_imm_input_mode_enum desired_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    i = mmi_imm_get_index_in_system_writing_language(g_mmi_imm_curr_allowed_writing_lang[index]);
    MMI_ASSERT(i >= 0);
    desired_mode = mmi_imm_get_first_allowed_input_mode_of_lang(g_ime_writing_lang_array[i].lang_id);
    if (desired_mode == IMM_INPUT_MODE_NONE)
    {
        if (mmi_imm_is_curr_allow_input_mode(g_ime_writing_lang_array[i].default_input_mode))
        {
            desired_mode = g_ime_writing_lang_array[i].default_input_mode;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    mmi_imm_set_prefer_input_mode(desired_mode);
    MMI_ASSERT(desired_mode != IMM_INPUT_MODE_NONE);
    mmi_imm_set_user_desired_input_mode(desired_mode);
    g_mmi_imm_user_desired_writing_lang = g_mmi_imm_curr_allowed_writing_lang[index];
    mmi_imm_set_main_lang(g_mmi_imm_curr_allowed_writing_lang[index]);
    mmi_imm_write_prefered_writing_lang_to_nvram();
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    mmi_imc_pen_open_symbol_lock();
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
#if defined(__MMI_MIXED_LANG_SUPPORT__)
    /* if main language doesnot support mix language */
    if (!g_ime_writing_lang_array[mmi_imm_get_index_in_system_writing_language(g_mmi_imm_curr_allowed_writing_lang[index])].mixed_lang_support)
    {
        mmi_imm_set_sub_lang(IME_WRITING_LANG_NONE);
    }
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */ 
#endif
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_read_prefered_input_method_from_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    ReadValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &g_mmi_imm_prefer_input_mode, DS_SHORT, &error);
#endif
}

/*****************************************************************************
* FUNCTION
* mmi_imm_write_prefered_input_method_to_nvram
* DESCRIPTION
* write prefered input method to NVRAM 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_write_prefered_input_method_to_nvram(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    WriteValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &input_mode, DS_SHORT, &error);
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_prefer_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    return g_mmi_imm_prefer_input_mode;
#else
    return 0 ;
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_curr_input_mode_list
* DESCRIPTION
*  To set prefer input mode. Used in Preferred Input Method setup to set prefer input mode.
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_message_id_enum mmi_imm_set_prefer_input_mode(mmi_imm_input_mode_enum desired_input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    g_mmi_imm_prefer_input_mode = desired_input_mode;
#endif
    return IMM_MESSAGE_ID_NONE;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_set_inputmethod
* DESCRIPTION
*  Set input method
* NA
*  
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_imm_set_inputmethod(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    if (index < IMM_INPUT_MODE_MAX_NUM)
    {
        mmi_imm_set_prefer_input_mode(MMI_all_prefered_input_mode_set[index]);
    }
    else
    {
        mmi_imm_set_prefer_input_mode(IMM_INPUT_MODE_123);
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_init_prefered_input_mode
* DESCRIPTION
*  Retrive input method type from nvram and set.
* NA
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_imm_init_prefered_input_mode(void)
{
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data = 0;
    U8 i;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive input method type from nvram */
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    ReadValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &data, DS_SHORT, &error);
#endif
    if (data == 0xFF )
    {
        mmi_imm_write_prefered_input_method_to_nvram((mmi_imm_input_mode_enum)IMM_INPUT_TYPE_SENTENCE);
    }
    /* check the input type */
    i = 0;
    while (MMI_all_prefered_input_mode_set[i] != data)
    {
        if (MMI_all_prefered_input_mode_set[i] == IMM_INPUT_MODE_NONE/*0xffff*/)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }

    }

    /* set input method with current input method */
    mmi_imm_set_inputmethod(i);
#endif
}




/*****************************************************************************
* FUNCTION
*  mmi_imm_config_enabled_writing_languages
* DESCRIPTION
* Configure writing language enable flag
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_enabled_writing_languages(S32 lang_index , MMI_BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U32 data = 0;
    U32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) 
    if ( g_ime_writing_lang_array[lang_index].lang_id == IME_WRITING_LANG_ABC || g_ime_writing_lang_array[lang_index].lang_id == IME_WRITING_LANG_123)
        return ;
    if (state)
        g_mmi_imm_enabled_writing_language |=  1<<(15-lang_index);
    else
        g_mmi_imm_enabled_writing_language &= ~(1<<(15-lang_index));

    data = g_mmi_imm_enabled_writing_language;
    WriteValue(NVRAM_SETTING_ENABLED_WRITING_LANGUAGE, &data, DS_SHORT, &error);
    /* regenerate The enum for current allowed writing languages */

    for( i =0 ; i< g_enabled_wlang_count ; i++)
    {
        g_ime_writing_lang_array[i].enabled =  (MMI_BOOL)(g_mmi_imm_enabled_writing_language >> ( 15 -i)) & 0x1;;
    }

#endif
    return ;

}

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_enabled_writing_languages
* DESCRIPTION
* returns Enabled writing language flag
* PARAMETERS
* RETURNS
*****************************************************************************/
U16 mmi_imm_get_enabled_writing_languages()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PREFER_WRITING_LANG__) ||  defined(__MMI_MIXED_LANG_SUPPORT__) 
    return g_mmi_imm_enabled_writing_language;
#else
    return 0;
#endif

}


/* IME SETTINGS QUERY AND CONFIGURATION APIS */

/*****************************************************************************

* FUNCTION
*  mmi_imm_is_auto_capitalization_enabled
* DESCRIPTION
* To check if auto-capitalization is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_auto_capitalization_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
	if (!mmi_imm_memory_card_is_auto_capitalization_enabled())
	{
		return MMI_FALSE;
	}
    return g_mmi_imm_is_auto_capitalization_enabled;
#else
    return MMI_TRUE;
#endif
}

/*****************************************************************************

* FUNCTION
*  mmi_imm_memory_card_is_auto_capitalization_enabled
* DESCRIPTION
* To check if auto-capitalization is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_memory_card_is_auto_capitalization_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		U32 i;
		const sIMEModeDetails * mode_detail = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
		for(i=0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
		{
				mode_detail = mmi_imm_get_input_mode_array_item(g_mmi_imm_curr_allowed_input_mode[i].mode_id);
				if(mode_detail->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC && mode_detail->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
				{
				    return MMI_TRUE;	
				}	
		}
    return MMI_FALSE;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_auto_capitalization
* DESCRIPTION
* Configure Auto capitalization 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_auto_capitalization(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
    /* In case while saving new there was a change ..needed by IME */
    if ( (g_mmi_imm_is_auto_capitalization_enabled) ^ (is_enabled))
    {
        mmi_imm_config_auto_capitalization_setting_changed(MMI_TRUE);
    }
    g_mmi_imm_is_auto_capitalization_enabled= is_enabled;
    data = g_mmi_imm_is_auto_capitalization_enabled;
    WriteValue(NVRAM_IME_AUTO_CAPITALIZATION_FLAG,&data, DS_BYTE, &error);
#endif
  #ifdef __MMI_PREFER_INPUT_METHOD__
    mmi_imm_get_prefer_input_mode_list(MMI_all_prefered_input_mode_set, IMM_INPUT_MODE_MAX_NUM);
#endif
    return;

}

#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_config_auto_capitalization_setting_changed
* DESCRIPTION
* Configure Auto capitalization 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_auto_capitalization_setting_changed(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_imm_is_auto_capitalization_setting_changed = is_enabled;
}

/*****************************************************************************

* FUNCTION
*  mmi_imm_is_auto_capitalization_setting_changed
* DESCRIPTION
* To check if auto-capitalization setting was changed
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_auto_capitalization_setting_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imm_is_auto_capitalization_setting_changed;
}
#endif



/*****************************************************************************

* FUNCTION
* mmi_imm_is_auto_completion_enabled
* DESCRIPTION
* To check if auto-capitalization is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_auto_completion_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_COMPLETION_SETTING__)
    return g_mmi_imm_is_auto_completion_enabled;
#else
    return MMI_TRUE;
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_auto_completion
* DESCRIPTION
* Configure auto completion 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_auto_completion(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_COMPLETION_SETTING__)
    g_mmi_imm_is_auto_completion_enabled= is_enabled;
    data = g_mmi_imm_is_auto_completion_enabled;
    WriteValue(NVRAM_IME_AUTO_COMPLETION_FLAG,&data, DS_BYTE, &error);
#endif
    return ;

}



/*****************************************************************************

* FUNCTION
* mmi_imm_is_alphabetic_word_prediction_enabled
* DESCRIPTION
* To check if auto-capitalization is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_alphabetic_word_prediction_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
    return g_mmi_imm_is_alphabetic_word_prediction_enabled;
#else
    return MMI_TRUE;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_alphabetic_word_prediction
* DESCRIPTION
* Configure  Alphabeticword prediction
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_alphabetic_word_prediction(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
    g_mmi_imm_is_alphabetic_word_prediction_enabled= is_enabled;
    data = g_mmi_imm_is_alphabetic_word_prediction_enabled;
    WriteValue(NVRAM_IME_ALPHABETIC_WORD_PREDICTION_FLAG,&data, DS_BYTE, &error);
#endif
    return ;
}


/*****************************************************************************

* FUNCTION
* To check if chinese word prediction is enabled
* DESCRIPTION
* To check if chinese word prediction is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_chinese_word_prediction_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
    return g_mmi_imm_is_chinese_word_prediction_enabled;
#else
    return MMI_TRUE;
#endif

}

#if  defined(__MMI_IME_V3__)
/*****************************************************************************

* FUNCTION
*  mmi_imm_memory_card_is_auto_space_enabled
* DESCRIPTION
* To check if auto-capitalization is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_memory_card_is_auto_space_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		U32 i;
		const sIMEModeDetails * mode_detail = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		for(i=0; g_mmi_imm_curr_allowed_input_mode[i].mode_id != IMM_INPUT_MODE_NONE; i++)
		{
				mode_detail = mmi_imm_get_input_mode_array_item(g_mmi_imm_curr_allowed_input_mode[i].mode_id);
				if(mode_detail->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC && mode_detail->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
				{
				    return MMI_TRUE;	
				}	
		}
    return MMI_FALSE;
}

/*****************************************************************************

* FUNCTION
* mmi_imm_is_auto_space_enabled
* DESCRIPTION
* To check if chinese word prediction is enabled
* PARAMETERS
* RETURNS MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_imm_is_auto_space_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  if(mmi_imm_memory_card_is_auto_space_enabled())
  {
  	  return g_mmi_imm_is_auto_space_enabled; 
  }
  else
  {
      return MMI_FALSE;	
  }
}

/*****************************************************************************

* FUNCTION
* To check if chinese word prediction is enabled
* DESCRIPTION
* To check if chinese word prediction is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_vibration_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_mmi_imm_is_vibration_enabled;

}

/*****************************************************************************

* FUNCTION
* To check if chinese word prediction is enabled
* DESCRIPTION
* To check if chinese word prediction is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_sound_feedback_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_mmi_imm_is_sound_feedback_enabled; 

}

/*****************************************************************************

* FUNCTION
* To check if chinese word prediction is enabled
* DESCRIPTION
* To check if chinese word prediction is enabled
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_sound_feedback_enabled_for_ime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret ret = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMCO_SILENT_MODE_SUPPORT__
    ret = srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE);
    MMI_ASSERT(ret != -1);
    if(ret == 0)
        return MMI_FALSE; 
    else
#endif
    return g_mmi_imm_is_sound_feedback_enabled;
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_config_chinese_word_prediction
* DESCRIPTION
* Set Chinese word prediction 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_auto_space(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_imm_is_auto_space_enabled= is_enabled;
    data = g_mmi_imm_is_auto_space_enabled;
    WriteValue(NVRAM_IME_AUTO_SPACE_FLAG,&data, DS_BYTE, &error);

    return;

}

/*****************************************************************************
* FUNCTION
*  mmi_imm_config_chinese_word_prediction
* DESCRIPTION
* Set Chinese word prediction 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_vibration(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_imm_is_vibration_enabled = is_enabled;
    data = g_mmi_imm_is_vibration_enabled;
    WriteValue(NVRAM_IME_VIBRATION_FLAG, &data, DS_BYTE, &error);

    return;

}

/*****************************************************************************
* FUNCTION
*  mmi_imm_config_chinese_word_prediction
* DESCRIPTION
* Set Chinese word prediction 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_sound_feedback(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_imm_is_sound_feedback_enabled = is_enabled;
    data = g_mmi_imm_is_sound_feedback_enabled;
    WriteValue(NVRAM_IME_SOUND_FEEDBACK_FLAG, &data, DS_BYTE, &error);

    return;

}

#endif
/*****************************************************************************
* FUNCTION
*  mmi_imm_config_chinese_word_prediction
* DESCRIPTION
* Set Chinese word prediction 
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_chinese_word_prediction(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
    g_mmi_imm_is_chinese_word_prediction_enabled= is_enabled;
    data = g_mmi_imm_is_chinese_word_prediction_enabled;
    WriteValue(NVRAM_IME_CHINESE_WORD_PREDICTION_FLAG,&data, DS_BYTE, &error);
#endif
    return;
  #ifdef __MMI_PREFER_INPUT_METHOD__
    mmi_imm_get_prefer_input_mode_list(MMI_all_prefered_input_mode_set, IMM_INPUT_MODE_MAX_NUM);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_keyboard_type
* DESCRIPTION
* get Keyboard type
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_keypadtype_enum mmi_imm_get_keyboard_type()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_COSMOS_KEYPAD_BAR__ || (defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__))
    return IMM_KEYPAD_HANDWRITING;
#else

#if defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && !defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    return IMM_KEYPAD_ALPHANUMERIC;
#endif

#if !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && !defined(__MMI_IME_VK_TYPE_HANDWRITING__) && defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    return IMM_KEYPAD_QWERTY;
#endif

    if (mmi_imc_is_rotated() == MMI_TRUE)
    {
    #if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        if (g_mmi_imm_keypad_type == IMM_KEYPAD_ALPHANUMERIC)
        {
            return IMM_KEYPAD_QWERTY;
        }
    #endif
        return g_mmi_imm_keypad_type;
    }
    else
    {
        return g_mmi_imm_keypad_type ;
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_keyboard_type
* DESCRIPTION
* Set keyboard type
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_keyboard_type(mmi_imm_keypadtype_enum keyboard_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (mmi_imc_is_rotated() == MMI_TRUE)
    {
        if (((keyboard_type == IMM_KEYPAD_QWERTY) || (keyboard_type == IMM_KEYPAD_ALPHANUMERIC)) &&
            ((g_mmi_imm_keypad_type == IMM_KEYPAD_QWERTY) || (g_mmi_imm_keypad_type == IMM_KEYPAD_ALPHANUMERIC)))
        {
            return;
        }

        g_mmi_imm_keypad_type = keyboard_type;
    }
    else
#endif
    {
        g_mmi_imm_keypad_type = keyboard_type;
    }

#if defined __MMI_IME_INPUT_PATTERN_SETTING__
    data = g_mmi_imm_keypad_type;
    WriteValue(NVRAM_IME_INPUT_PATTERN,&data, DS_BYTE, &error);
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    mmi_imc_pen_open_symbol_lock();
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
#endif
    return;
}



/*****************************************************************************
* FUNCTION
*  mmi_imm_get_handwriting_setting
* DESCRIPTION
* get whetehr or not hwsetting to be displayed
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_get_handwriting_setting()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    return g_mmi_imm_get_handwriting_setting ;
#else
    return 0;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_keyboard_type
* DESCRIPTION
* Set whetehr or not hwsetting to be displayed
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_handwriting_setting( MMI_BOOL is_available)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    g_mmi_imm_get_handwriting_setting = is_available;
#endif
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMM_CONFIG_HANDWRITING_SETTING, g_mmi_imm_get_handwriting_setting);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_config_first_uppercase_input_modes
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_config_first_uppercase_input_modes(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    g_mmi_imm_is_first_uppercase_modes_enalbled = is_enabled;
#endif
  #ifdef __MMI_PREFER_INPUT_METHOD__
    mmi_imm_get_prefer_input_mode_list(MMI_all_prefered_input_mode_set, IMM_INPUT_MODE_MAX_NUM);
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_is_current_mode_smart
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_is_current_mode_smart(void)
{

    const sIMEModeDetails * mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);


    if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
    {
        return MMI_TRUE;
    }
    else if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
    {
        return MMI_FALSE;
    }

    return MMI_FALSE;

}


/*****************************************************************************
* FUNCTION
*  IsInputTypeNumber
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL 
*****************************************************************************/
MMI_BOOL mmi_imm_IsInputTypeNumber()
{
    mmi_imm_input_type_enum input_type;

    input_type = mmi_imm_get_curr_input_type();
    /* elementary input types */
    if(
        (input_type  & IMM_INPUT_TYPE_NUMERIC)||
        (input_type  & IMM_INPUT_TYPE_PHONE_NUMBER) ||
        (input_type  & IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR) ||
        (input_type  & IMM_INPUT_TYPE_DECIMAL_NUMERIC) ||
        (input_type  & IMM_INPUT_TYPE_SIGNED_NUMERIC) ||
        (input_type  & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC) ||
        (input_type  & IMM_INPUT_TYPE_KEYPAD_NUMERIC) ||
        (input_type  & IMM_INPUT_TYPE_SIM_NUMERIC)

        )
    {
        return MMI_TRUE;
    }
    /* compount input types */
    if(   
        (input_type  == IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD) ||
        (input_type  == IMM_INPUT_TYPE_NUMERIC_PASSWORD) ||
        (input_type  == IMM_INPUT_TYPE_SIGNED_NUMERIC_PASSWORD) ||
        (input_type  == IMM_INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD) ||
        (input_type  ==  IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD)
        )
    {
        return MMI_TRUE;
    }

    else
    {
        return MMI_FALSE;
    }

}


#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_get_wlang_by_index
* DESCRIPTION
* get wlnag from index 
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_support_writing_lang_enum mmi_imm_get_wlang_by_index(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0;
    U32 j =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* search allowed wlang array and add when enabled one occurs as user can disable some wlang from settings  */
    for (i = 0; g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_NONE; i++)
    {
        if ((j == index) && g_ime_writing_lang_array[i].enabled)
        {
            return g_ime_writing_lang_array[i].lang_id;
        }
        if (g_ime_writing_lang_array[i].enabled)
        {
            j++;
        }
    }

    MMI_ASSERT(0);
	return IME_WRITING_LANG_NONE;
}

#endif

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_get_pen_speed
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_pen_speed_enum mmi_imm_get_pen_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_imm_pen_speed;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_set_pen_speed
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_set_pen_speed(mmi_imm_pen_speed_enum speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (speed < MMI_IMM_PEN_SPEED_MAX)
    {
        g_mmi_imm_pen_speed = speed;
        WriteValue(NVRAM_SETTING_PEN_SPEED, &g_mmi_imm_pen_speed, DS_BYTE, &error);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_imm_init_pen_speed
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imm_init_pen_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_PEN_SPEED, &g_mmi_imm_pen_speed, DS_BYTE, &error);
    if ((error == -1) || (g_mmi_imm_pen_speed >= MMI_IMM_PEN_SPEED_MAX))
    {
        g_mmi_imm_pen_speed = MMI_IMM_PEN_SPEED_MEDIUM;
        mmi_imm_set_pen_speed(MMI_IMM_PEN_SPEED_MEDIUM);
    }
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_required_mode_list_count
* DESCRIPTION : JAVA needed this 
* PARAMETERS
* RETURNS
*****************************************************************************/
U32 mmi_imm_get_required_mode_list_count(U32 input_type)
{
    U32 count =0;
    U32 i=0;
    U32 input_type_int = input_type & (~IMM_INPUT_TYPE_MASK);

    for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
    {        
        if ((gIMEModeArray[i].supported_input_type_flag & input_type_int))
        { 		   
            count++;
        }
    }
    return count;
}



MMI_BOOL mmi_imm_does_current_type_support_titlecase(void)
{
	if(g_mmi_imm_current_input_type == (IMM_INPUT_TYPE_EMAIL | IMM_INPUT_TYPE_SENTENCE))
		  return MMI_TRUE;
    if ((g_mmi_imm_current_input_type & IMM_INPUT_TYPE_QUICK_SEARCH) ||
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_URL) ||
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EMAIL) ||
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_EXT_ENGLISH_UPPERCASE)||
        (g_mmi_imm_current_input_type & IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE)||
        (g_mmi_imm_current_input_type &IMM_INPUT_TYPE_EXT_PASSWORD ))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;

}


#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)



/*****************************************************************************
* FUNCTION
*  mmi_imm_config_handwriting_language
* DESCRIPTION
*  Set current handwritingwriting language
* PARAMETERS
* RETURNS
*****************************************************************************/

void mmi_imm_config_handwriting_language(UI_string_type string)
    {    
    U16 j = 0 ;

    for ( j =0 ; g_ime_writing_lang_array[j].lang_id != IME_WRITING_LANG_NONE; j++)
    {    

        if (mmi_ucs2cmp((char*)string, (char*)g_ime_writing_lang_array[j].lang_str_ptr) == 0)
        {
			U8 temp;
			S16 error;
            g_current_handwriting_lang_id = g_ime_writing_lang_array[j].lang_id;
			temp = (U8) g_current_handwriting_lang_id;
			WriteValue(NVRAM_SETTING_LANGUAGE_FOLLOW_VK, &temp, DS_BYTE, &error);
            return;
        }
    }
//btw we need to send to NVRAM too
            return;
        }

/*****************************************************************************
* FUNCTION
*  mmi_imm_get_handwriting_language
* DESCRIPTION
*  Get current handwritingwriting language
* PARAMETERS
* RETURNS
*****************************************************************************/

UI_string_type mmi_imm_get_handwriting_language(void)
{
	U16 j = 0 ;
    for ( j =0 ; g_ime_writing_lang_array[j].lang_id != IME_WRITING_LANG_NONE; j++)
    {    
        if (g_current_handwriting_lang_id == g_ime_writing_lang_array[j].lang_id && g_ime_writing_lang_array[j].enabled)
        {
            return g_ime_writing_lang_array[j].lang_str_ptr;
        }
    }
    g_current_handwriting_lang_id = g_ime_writing_lang_array[0].lang_id;
    return g_ime_writing_lang_array[0].lang_str_ptr;

}



/*****************************************************************************
* FUNCTION
*  mmi_imm_get_handwriting_language_strings
* DESCRIPTION
*  Get current handwritingwriting language strings
* PARAMETERS
* RETURNS
*****************************************************************************/
U32 mmi_imm_get_handwriting_language_strings(UI_string_type strarray[] )
{
    U32 count = 0;
    U32 i =0;
    U32 j =0;
    MMI_BOOL is_new = MMI_TRUE;
    mmi_imm_support_writing_lang_enum wlang_array[15]; 
    mmi_imc_pen_handwriting_type_enum hw_type;
    /* get lang ids who do support handwriitng*/
    
    for (i = 0; i< 15; i++)
    {
        wlang_array[i] = IME_WRITING_LANG_NONE;
    }	
    
    for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
    {
    	hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(gIMEModeArray[i].Handwriting_Attrib);
        if(gIMEModeArray[i].lang_id == IME_WRITING_LANG_123)
        {
            continue;
        }
    	if(mmi_ime_hand_writing_hw_type_query(hw_type))
        { 
            /* to make sure only take lang id once*/
            for ( j = 0 ; j<15 ; j++)
            {
                if(wlang_array[j] == gIMEModeArray[i].lang_id)
                {
                    is_new = MMI_FALSE;
                    break;
                }
                else
                {
                    is_new = MMI_TRUE;
                }
            }
            if (is_new)
            {
            /* test allowed or not */
                for (j = 0 ;j<15;j++)
                {
                    if(g_ime_writing_lang_array[j].lang_id== gIMEModeArray[i].lang_id)
                        break;
                }
                if(g_ime_writing_lang_array[j].enabled)
                {
                   wlang_array[count] = gIMEModeArray[i].lang_id; 
                   count++;
                }
            }
        }
    }
    /* get strings of these qualifying language ids */
    i=0;
    for ( j =0 ; g_ime_writing_lang_array[j].lang_id != IME_WRITING_LANG_NONE; j++)
    {
        if(g_ime_writing_lang_array[j].lang_id == wlang_array[i])
        {
            strarray[i] = g_ime_writing_lang_array[j].lang_str_ptr;
            i++;
        }
    }
    return count;
}



void mmi_imm_handwriting_enable(MMI_BOOL bOn)
{
	s16 error;
	g_is_handwriting_setting_on = bOn;
	WriteValue(NVRAM_SETTING_HANDWRITING_ON, &g_is_handwriting_setting_on, DS_BYTE, &error);
}

MMI_BOOL mmi_imm_handwriting_is_enable(void)
{
	return g_is_handwriting_setting_on;
}


U8	mmi_imm_handwriting_get_color_number(void)
{

	return IMM_MAX_STROKE_COLOR_NUM-1;
}

color mmi_imm_handwriting_get_current_stroke_color(void)
{
	if (g_current_stroke_color_index >= IMM_MAX_STROKE_COLOR_NUM)
		g_current_stroke_color_index = 0;
	return g_imm_hw_color_list[g_current_stroke_color_index];
}

const color* mmi_imm_handwriting_get_color_list(void)
{
	return g_imm_hw_color_list;
}

U8  mmi_imm_handwriting_get_current_color_id(void)
{
	return g_current_stroke_color_index;
}

MMI_BOOL mmi_imm_handwriting_set_current_stroke_color( U8 uIndex )
{
	s16 error;
	S32 ret_value;
	
	if (uIndex >= IMM_MAX_STROKE_COLOR_NUM)
		return MMI_FALSE;
	
	g_current_stroke_color_index = uIndex;
	g_current_handwritng_stroke_color = g_imm_hw_color_list[uIndex];

	ret_value = WriteValue(NVRAM_SETTING_STROKE_COLOR_INDEX, &g_current_stroke_color_index, DS_BYTE, &error);

	if (ret_value == -1)
		return MMI_FALSE;
	return MMI_TRUE;
}

U32 mmi_imm_handwriting_get_current_color_index(void)
{
    return g_current_stroke_color_index;
}

U8 mmi_imm_handwriting_get_stroke_width(void)
{
	return g_current_stroke_width;
}

void mmi_imm_handwriting_set_width(U8 width)
{
	s16 error;
	g_current_stroke_width = width;
	WriteValue(NVRAM_SETTING_PEN_WIDTH, &g_current_stroke_width, DS_BYTE, &error);
}


MMI_BOOL mmi_imm_handwriting_is_follow_vk(void)
{
	return g_is_handwriting_follow_vk_lang;
}

void mmi_imm_handwriting_set_follow_vk_lang(MMI_BOOL bFollow)
{
	s16 error;
	
	g_is_handwriting_follow_vk_lang = bFollow;
	
	WriteValue(NVRAM_SETTING_LANGUAGE_FOLLOW_VK, &g_is_handwriting_follow_vk_lang, DS_BYTE, &error);
}

U16 mmi_imm_handwriting_get_lang_number()
{
	return g_enabled_wlang_count;
}

UI_character_type* mmi_imm_handwriting_get_language_string(U16 uIndex)
{
	if (uIndex >= MAX_WRITING_LANG )
	{
		return NULL;
	}
	return g_ime_writing_lang_array[uIndex].lang_str_ptr;
}

void mmi_imm_handwriting_set_language(U16 uIndex)
{
	g_current_handwriting_lang_id = (mmi_imm_support_writing_lang_enum)uIndex;
}

U16 mmi_imm_handwriting_get_current_lang(void)
{
	return g_current_handwriting_lang_id;
}

mmi_imm_input_mode_enum  mmi_imm_handwriting_get_current_mode(void)
{
    mmi_imm_input_mode_enum input_mode;
    int j;
    const sIMEModeDetails * mode_detail = NULL;

    mode_detail = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);
	if(mode_detail &&  mode_detail->lang_id == g_current_handwriting_lang_id)
	{
		input_mode = g_mmi_imm_current_input_mode;
	}
	else
	{
		for (j =0; g_ime_writing_lang_array[j].lang_id != IME_WRITING_LANG_NONE; j++)
		{
			if (g_ime_writing_lang_array[j].lang_id == g_current_handwriting_lang_id)
			{
				break;
			}
      
		}
		input_mode = g_ime_writing_lang_array[j].default_input_mode;
	}

    if(!mmi_imm_is_curr_allow_input_mode(input_mode))
    {
        if(mmi_imm_is_curr_allow_input_mode(g_mmi_imm_default_handwriting_input_mode))
        {
            input_mode = g_mmi_imm_default_handwriting_input_mode;
        }
        else
        {
            input_mode = g_mmi_imm_curr_allowed_input_mode[0].mode_id;
        }
    }

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
	//check if T-card support
	mode_detail = mmi_imm_get_input_mode_array_item(input_mode);
	if(mode_detail && !mmi_ime_hand_writing_memory_card_is_lang_support(mode_detail->lang_id))
	{
		S32 index = 0;
		mmi_imm_support_writing_lang_enum lang;
		while(1)
		{
			S32 k = 0;
			lang = mmi_ime_hand_writing_memory_card_get_lang_by_index(index);
			if(IME_WRITING_LANG_NONE == lang)
			{
				break;
			}
				
			//get the default input mode of hw lang
			while(g_ime_writing_lang_array[k].lang_id != lang)
			{
				k++;
			}
			input_mode = g_ime_writing_lang_array[k].default_input_mode;

			if(mmi_imm_is_curr_allow_input_mode(input_mode))
			{
				break;
			}
			index++;
		}
		if(IME_WRITING_LANG_NONE == lang)
		{
			input_mode = IMM_INPUT_MODE_NONE;
			MMI_ASSERT(0);//assert here to handle the situation if input_mode is IMM_INPUT_MODE_NONE or IMM_INPUT_MODE_MAX_NUM
		}

	}
#endif
    return input_mode;
}
#endif // defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
#endif //__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
/*****************************************************************************
* FUNCTION
*  mmi_imm_get_current_input_mode
* DESCRIPTION
*  Get current mode
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_current_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_imm_current_input_mode;
}
/*****************************************************************************
* FUNCTION
*  mmi_imm_get_is_smart_input_mode_of_writing_language
* DESCRIPTION
*  Get current writing language
* PARAMETERS
* RETURNS
*****************************************************************************/


MMI_BOOL mmi_imm_get_is_smart_input_mode_of_writing_language(void)
{
	const sIMEModeDetails *mode_details_ptr = NULL;
	S32 i = 0;
	mmi_imm_support_writing_lang_enum wlang;
	mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);
	wlang = mode_details_ptr->lang_id;
	for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
	{
		if ( (gIMEModeArray[i].lang_id == wlang ))
		{
			if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART)
				return MMI_TRUE;
		}
	}
	return MMI_FALSE;
	
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_default_input_mode_of_curr_writing_language
* DESCRIPTION
*  Get current writing language
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imm_input_mode_enum mmi_imm_get_default_input_mode_of_curr_writing_language(void)
{
#if defined(__MMI_IME_V3__)
    S32 index;
    const sIMEModeDetails *mode_details_ptr, *default_mode_detail;

    index = mmi_imm_get_index_in_system_writing_language(mmi_imm_get_current_writing_language());
    if(index != -1)
    {
		default_mode_detail = mmi_imm_get_input_mode_array_item(g_ime_writing_lang_array[index].default_input_mode);
		mode_details_ptr = mmi_imm_get_corresponding_smart_mode(default_mode_detail->imm_mode_id,default_mode_detail->Mode_Special_Attrib & IME_MODE_CASE_MASK);
		if(mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
		{
			return mode_details_ptr->imm_mode_id;
		}
		else
		{
			mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(default_mode_detail->imm_mode_id,default_mode_detail->Mode_Special_Attrib & IME_MODE_CASE_MASK);
			if(mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
			{
				return mode_details_ptr->imm_mode_id;
			}
		}
		ASSERT(0);
    }
#endif
	return IMM_INPUT_MODE_NONE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imm_get_is_smart_input_mode_allowed_of_curr_writing_language
* DESCRIPTION
*  Get current writing language
* PARAMETERS
* RETURNS
*****************************************************************************/


MMI_BOOL mmi_imm_get_is_smart_input_mode_allowed_of_curr_writing_language(void)
{
	const sIMEModeDetails *mode_details_ptr = NULL;
	S32 i = 0;
	mmi_imm_support_writing_lang_enum wlang;
	mode_details_ptr = mmi_imm_get_input_mode_array_item(g_mmi_imm_current_input_mode);
	wlang = mode_details_ptr->lang_id;
	for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
	{
		if ( (gIMEModeArray[i].lang_id == wlang ))
		{
            if (!mmi_imm_is_curr_allow_input_mode(gIMEModeArray[i].imm_mode_id))
                continue;
			if (gIMEModeArray[i].Mode_Special_Attrib & IME_MODE_ATTR_SMART && wlang != IME_WRITING_LANG_HABC)
				return MMI_TRUE;
		}
	}
	return MMI_FALSE;
	
}


#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
/*****************************************************************************
* FUNCTION
*  mmi_imm_current_handwriting_is_enable
* DESCRIPTION
*  check current writing language is valid or not.
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imm_current_handwriting_is_enable()
{
    mmi_imm_input_mode_enum input_mode;
    const sIMEModeDetails * mode_detail = NULL;
    mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;

    if(mmi_imc_is_handwriting_disabled())
    {
        return MMI_FALSE;
    }
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
    input_mode = mmi_imm_get_current_input_mode();
#else
    input_mode = mmi_imm_handwriting_get_current_mode();
#endif
    
    mode_detail = mmi_imm_get_input_mode_array_item(input_mode); 
    if(!mode_detail)
    {
        return MMI_FALSE;
    }
    if (mode_detail->lang_id == IME_WRITING_LANG_123)
    {
        return MMI_FALSE;
    }
    hw_type = (mmi_imc_pen_handwriting_type_enum)(IME_HAND_WRITING_GET_HW_TYPE(mode_detail->Handwriting_Attrib));
    if(mmi_ime_hand_writing_hw_type_query(hw_type))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif
/*****************************************************************************
* FUNCTION
*  mmi_imm_is_seemless_switching_enable
* DESCRIPTION
*  check current writing language is valid or not.
* PARAMETERS
* RETURNS
*****************************************************************************/
extern MMI_BOOL mmi_imm_is_seemless_switching_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_GB_ENGLISH__) && defined(__MMI_GB_SMART_PHONETIC_INPUT__)
    for (i = 0; gIMEModeArray[i].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; i++)
	{
if(gIMEModeArray[i].lang_id == IME_WRITING_LANG_ABC || gIMEModeArray[i].lang_id == IME_WRITING_LANG_ZHCN ||  gIMEModeArray[i].lang_id == IME_WRITING_LANG_123)
       continue;
else 
    return MMI_FALSE;
    }
#else
    return MMI_FALSE ;
#endif
    return MMI_TRUE;
}


#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_IME_V3__)

/*****************************************************************************
* FUNCTION
*  mmi_imm_memory_card_check_hw_lang_support
* DESCRIPTION
*  To query if the hw_lang is supported by the font/ime/vendor
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_imm_handwriting_memory_card_check_lang_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMM_HANDWRITING_MEMORY_CARD_CHECK_LANG_SUPPORT);

    //the default value of g_current_handwriting_lang_id in NVRAM might be 0
    if (IME_WRITING_LANG_NONE == g_current_handwriting_lang_id)
    {
		g_need_to_disable_hw = MMI_FALSE;
        return;
    }

    //check if font/ime support
    for (i = 0; g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_NONE; i++)
    {
        if(g_ime_writing_lang_array[i].lang_id == g_current_handwriting_lang_id)
        {
			break;
        }
    }

    if (g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_NONE)
    {
        //hw vendor in memory card don't support
        if (!mmi_ime_hand_writing_memory_card_is_lang_support(g_current_handwriting_lang_id))
        {
			S16 error;
			U8 temp;
			
			g_current_handwriting_lang_id = mmi_ime_hand_writing_memory_card_get_lang_by_index(0);
			temp = (U8) g_current_handwriting_lang_id;
			WriteValue(NVRAM_SETTING_LANGUAGE_FOLLOW_VK, &temp, DS_BYTE, &error);
        }
		
		if (IME_WRITING_LANG_NONE != g_current_handwriting_lang_id)
		{
		    g_need_to_disable_hw = MMI_FALSE;			
		}
    }
	else
    {
        g_need_to_disable_hw = MMI_FALSE;
    }
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMM_HANDWRITING_MEMORY_CARD_CHECK_LANG_SUPPORT_STATE, g_need_to_disable_hw);

}
#endif /*#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_IME_V3__)*/

/*****************************************************************************
* FUNCTION
*  mmi_imm_handwriting_memory_card_check_folder_hidden
* DESCRIPTION
*  check if the hw data folder is hidden
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_imm_handwriting_memory_card_check_folder_hidden(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dataFilePath[MAX_HANDWRITING_DATA_FILE_PATH];
    FS_HANDLE dataFilePathHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMM_HANDWRITING_MEMORY_CARD_CHECK_FOLDER_HIDDEN);
	
	kal_wsprintf(dataFilePath, "%c%s", SRV_FMGR_CARD_DRV, HANDWRITING_DATA_FILE_PATH);

    dataFilePathHandle = FS_Open(dataFilePath, FS_OPEN_DIR | FS_READ_ONLY);

	if (dataFilePathHandle > 0)
	{
		S32 folderAttributes = FS_GetAttributes(dataFilePath);
		if (!(folderAttributes & FS_ATTR_DIR) || !(folderAttributes & FS_ATTR_HIDDEN))
		{
			FS_SetAttributes(dataFilePath, FS_ATTR_DIR | FS_ATTR_HIDDEN);
		}
		FS_Close(dataFilePathHandle);
	}

}

/*****************************************************************************
* FUNCTION
*  mmi_imm_handwriting_memory_card_init
* DESCRIPTION
*  check hw relative info (must call after mmi_imm_init_writing_lang())
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_imm_handwriting_memory_card_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMM_HANDWRITING_MEMORY_CARD_INIT);

    if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        g_is_init_with_memory_card = MMI_TRUE;
		mmi_imm_handwriting_memory_card_check_folder_hidden();

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_IME_V3__)          
        mmi_imm_handwriting_memory_card_check_lang_support();
#else
        g_need_to_disable_hw = MMI_FALSE;
#endif
    }
    if (g_need_to_disable_hw)
    {
        mmi_imc_disable_handwriting();
        mmi_imm_config_handwriting_setting(MMI_FALSE);
    }
}
#endif /*#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)*/
