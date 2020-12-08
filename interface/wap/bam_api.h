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
 *  bam_api.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Common BAM APIs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _BAM_API_H_
#define _BAM_API_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Constant
 *****************************************************************************/

/***************************************************************************** 
 * Macro
 *****************************************************************************/

/***************************************************************************** 
 * Enum
 *****************************************************************************/

/***************************************************************************** 
 * Structure
 *****************************************************************************/

/***************************************************************************** 
 * Type Definition
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  bam_register_keypad_handler
 * DESCRIPTION
 *  This function is used to register keypad handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void bam_register_keypad_handler(void);

/*****************************************************************************
 * FUNCTION
 *  bam_suspend_browser_rendering
 * DESCRIPTION
 *  This function is used to suspend page rendering.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void bam_suspend_browser_rendering(void);

/*****************************************************************************
 * FUNCTION
 *  bam_resume_browser_rendering
 * DESCRIPTION
 *  This function is used to resume page rendering.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void bam_resume_browser_rendering(void);

/*****************************************************************************
 * FUNCTION
 *  bam_notify_screen_info
 * DESCRIPTION
 *  This function is used to notify OWL of the current category screen information, including layer handle used and what area to draw.
 * PARAMETERS
 *  x:                      [IN]    The x-wise position where the paint box that is to hold rendered content should be placed.
 *  y:                      [IN]    The y-wise position where the paint box that is to hold rendered content should be placed.
 *  w:                      [IN]    The width to which the paint box should be set.
 *  h:                      [IN]    The height to which the paint box for content should be set.
 *  category_lyr_a_hndl:    [IN]    GDI Layer A (like, for top area) using by category screen.
 *  category_lyr_b_hndl:    [IN]    GDI Layer B (like, for bottom area) using by category screen.
 *  is_refresh:             [IN]    Refresh is needed or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void bam_notify_screen_info(
                unsigned int x,
                unsigned int y,
                unsigned int w,
                unsigned int h,
                int category_lyr_a_hndl,
                int category_lyr_b_hndl,
                int is_refresh);

/*****************************************************************************
 * FUNCTION
 *  bam_activate_browser_input
 * DESCRIPTION
 *  Notify OWL to handle form/link elements.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void bam_activate_browser_input(void);

/*****************************************************************************
 * FUNCTION
 *  bam_get_bits
 * DESCRIPTION
 *  Treat the input parameter "data" as an array of bits, most significant
 *  bit first, and return the indicated bit range as an integer. "numbits"
 *  must not be larger than 32.
 * PARAMETERS
 *  data:       [IN]    An unsigned array of bits.
 *  numbits:    [IN]    Number of bits; it must not be larger than 32.
 * RETURNS
 *  Return the indicated bit range as an integer.
 *****************************************************************************/
extern unsigned int bam_get_bits(char *data, int numbits);

#endif /* _BAM_API_H_ */
