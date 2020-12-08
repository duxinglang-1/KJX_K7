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
 *    Imc_pen.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


#ifdef __MMI_TOUCH_SCREEN__

#include "mmi_include.h"
#include "IMERes.h"

#include "PhoneSetupGprots.h"

#include "CommonScreens.h"
#include "Word_engine.h"

#include "Multitap_engine.h"
#include "Imc_symbol.h"
#include "Imui.h"
#include "Imc.h"
#include "ImmProt.h"
#include "Imc_key.h"
#include "Imc_pen.h"
#include "Handwriting_engine.h"

#include "gui_virtual_keyboard.h"

#include "wgui_virtual_keyboard.h"

#ifdef __MMI_VUI_ENGINE__
#include "framework\vadp_p2v_uc.h"
#include "ime\vadp_p2v_input_server_interface.h"
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
#include "CommonScreensResDef.h"
#if defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
#include "gui_virtual_keyboard_res.h"
#include "gui_virtual_keyboard_misc_res.h"
#endif
#endif
#include "gui_themes.h" /*Added after RHR build error*/
#include "gui_fixed_menus.h" /*Added after RHR build error*/
#include "gui_fixed_menuitems.h"/*Added after RHR build error*/
#include"wgui_include.h"/*Added after RHR build error*/
#include"mmi_rp_srv_editor_def.h"
#include "wgui_inputs.h"
#include "ImeGprot.h"
#include "MMIDataType.h"
#include "gui_virtual_keyboard_language_type.h"
#include "Imc_config.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"
//#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "string.h"
#include "wgui_touch_screen.h"
#include "gui_config.h"
#include "gui.h"
#include "gui_typedef.h"
#include "wgui_draw_manager.h"
#include "gdi_include.h"
#include "gui_switch.h"
#include "wgui.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalConstants.h"
//#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_uiframework_def.h"
#include "gui_inputs.h"
#include "MMI_fw_trc.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_editor_def.h"

#include "wgui_fixed_menus.h"
#include "wgui_fixed_menuitems.h"
#include "gui_touch_feedback.h"

#ifdef __MMI_IME_PLUG_IN__
#include "ImeSDKGprot.h"
#include "ImeSDKProt.h"
#endif

#if defined(__COSMOS_MMI__)
#include "mmi_rp_srv_input_method_def.h"
#endif

#if defined(__COSMOS_MMI_PACKAGE__)
#include "vfx_adp_device.h"
#endif 
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "DialerCuiGprot.h"
#endif
#include "mmi_frm_history_gprot.h"

#if defined(__IMEHW_DCM_SUPPORT__)
#include "dcmgr.h"
#endif
/*****************************************************************************
 *  Define
 *****************************************************************************/
#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
/* this is used to decide the timer's timeout for word prediction in editor */
#define WORD_PREDICTION_TIMEOUT 2000
#endif
#define PASSWORD_CHARACTER_TIMEOUT 500
#if defined(__MMI_VIRTUAL_KEYBOARD__)
#if defined(__MMI_MAINLCD_128X160__)
#define MMI_IMC_PEN_MAX_STRING_IN_DIPLAY_AREA_VK_ZHUYIN (3)
#define MMI_IMC_PEN_MAX_STRING_IN_DIPLAY_AREA_VK_PINYIN (MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN)
#else
#define MMI_IMC_PEN_MAX_STRING_IN_DIPLAY_AREA_VK_ZHUYIN (MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN)
#define MMI_IMC_PEN_MAX_STRING_IN_DIPLAY_AREA_VK_PINYIN (MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN)
#endif



#endif

#define MMI_IMC_PEN_COMPOSITION_DEPART_TOKEN 0x0027
#define MMI_IMC_PEN_MULTITAP_TIMER 500

extern mmi_editor_handler_struct g_mmi_editor_hanler;

extern fixed_icontext_list_menuitem MMI_fixed_icontext_list_menuitem;
#if defined(__MMI_IME_CANDIDATE_GRID__)
extern mmi_imc_state_enum g_imc_prev_state_grid;
#endif


void mmi_imc_pen_set_gui_state(U16 new_caps);


/*****************************************************************************
 *  Typedef
 *****************************************************************************/
typedef enum
{
    MMI_IMC_PEN_DOWN_UI_TYPE_NONE = 0, //should never be set
    MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR,
    MMI_IMC_PEN_DOWN_UI_TYPE_IMUI,
    MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL
}mmi_imc_pen_down_ui_type_enum;

typedef enum
{
    MMI_IMC_PEN_VK_CAPITAL_AUTO, /* the capital state would be changed automatically */
    MMI_IMC_PEN_VK_TEMP_CAPS_LOCK, /* the caps lock is turn on temporially */
    MMI_IMC_PEN_VK_CAPS_LOCK /* the capital case is locked */
} mmi_imc_pen_vk_capital_state_enum;
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__

typedef enum
{
    MMI_IMC_PEN_VK_SHIFT_LOWER = 0,     /* the capital state would be changed automatically */
    MMI_IMC_PEN_VK_SHIFT_UP_STABLE,     /* the capital case is locked */
    MMI_IMC_PEN_VK_SHIFT_UP_ONCE,       /* the caps lock is turn on temporially */
    MMI_IMC_PEN_VK_SHIFT_STATE_MAX
} mmi_imc_pen_vk_shift_key_state_enum;

#endif
typedef enum
{
	PORTRAIT,
	LANDSCAPE
}mmi_imc_pen_orientation_enum;
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
#if defined(NORMAL_KEYPAD)
#define MMI_IMC_PEN_DEFAULT_INPUT_STYLE MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY
#define MMI_IMC_PEN_DEFAULT_VK_STYLE MMI_VK_TYPE_QWERTY
#else
#define MMI_IMC_PEN_DEFAULT_INPUT_STYLE MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC
#define MMI_IMC_PEN_DEFAULT_VK_STYLE MMI_VK_TYPE_ALPHANUMERIC
#endif
#else
#define MMI_IMC_PEN_DEFAULT_INPUT_STYLE MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY
#define MMI_IMC_PEN_DEFAULT_VK_STYLE MMI_VK_TYPE_QWERTY
#endif

#elif defined(__MMI_MAINLCD_320X480__)
#define MMI_IMC_PEN_DEFAULT_INPUT_STYLE MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY
#define MMI_IMC_PEN_DEFAULT_VK_STYLE MMI_VK_TYPE_QWERTY
#elif defined(__MMI_MAINLCD_480X800__)
#define MMI_IMC_PEN_DEFAULT_INPUT_STYLE MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY
#define MMI_IMC_PEN_DEFAULT_VK_STYLE MMI_VK_TYPE_QWERTY
#elif defined(__MMI_MAINLCD_320X240__)
#define MMI_IMC_PEN_DEFAULT_INPUT_STYLE MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY
#define MMI_IMC_PEN_DEFAULT_VK_STYLE MMI_VK_TYPE_QWERTY

#else
#error "FTE is not supported in this resolution"
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
#if !defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
    #undef MMI_IMC_PEN_DEFAULT_VK_STYLE
    #define MMI_IMC_PEN_DEFAULT_VK_STYLE   MMI_VK_TYPE_ALPHANUMERIC
#elif defined(__MMI_IME_VK_TYPE_QWERTY__) && !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
	#undef MMI_IMC_PEN_DEFAULT_VK_STYLE
    #define MMI_IMC_PEN_DEFAULT_VK_STYLE  MMI_VK_TYPE_QWERTY
#elif !defined(__MMI_IME_VK_TYPE_QWERTY__) && !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && !defined(__MMI_NO_HANDWRITING__)
	#undef MMI_IMC_PEN_DEFAULT_VK_STYLE
    #define MMI_IMC_PEN_DEFAULT_VK_STYLE   MMI_VK_TYPE_ALPHANUMERIC
#endif
#endif /*defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)*/

#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

typedef struct
{
    mmi_imc_pen_handwriting_style_enum     handwriting_style;
    const sIMEModeDetails                  *curr_mode_details;
    MMI_BOOL                               is_enable;
    mmi_imc_state_enum                     state;
    mmi_imc_global_data_struct_p           global_data_ptr;
    mmi_imui_update_selection_area_struct  update_struct;
    mmi_imc_pen_down_ui_type_enum          pen_down_type;
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    gui_virtual_keyboard_language_enum     vk_type_before_tray;
    gui_virtual_keyboard_language_enum     vk_type_before_symbol;
    MMI_BOOL vk_longtap; /* to record the previous longtap event for vk */
    mmi_imc_pen_vk_capital_state_enum vk_cap_state;
    U8 vk_style;
    MMI_BOOL is_hide_by_vk;
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    U8 vk_style_before_handwriting;
#endif
#if defined(__MMI_IME_FTE_ENHANCE__)
    mmi_imc_pen_input_style_enum input_type;
    gui_virtual_keyboard_language_enum     vk_type_before_num; 
    mmi_imc_symb_tone_enum tone_mark;
    gui_virtual_keyboard_pen_enum zhuyin_vk_event;
    S16 zhuyin_vk_char_map_index;
//#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
    MMI_BOOL is_symbol_lock;
	MMI_BOOL backup_symbol_lock_state;
//#endif /* defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__) */
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */
    UI_character_type hw_cand_buf[MMI_IMC_PEN_MAX_CANDIDATE_NUM*2];
    U8 hw_cand_cnt;
}mmi_imc_pen_object_struct, *mmi_imc_pen_object_struct_p;


typedef struct
{
    MMI_EVT_PARAM_HEADER
} imc_pen_evt_entry_input_method;


#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
static MMI_BOOL g_pen_down_outside_the_list = MMI_TRUE;
static FuncPtr g_pen_popup_list_confirm_callback = NULL;
static FuncPtr g_pen_popup_list_cancel_callback = NULL;
#endif

#if (defined(__MMI_IME_V3__) && defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)) || defined(__MMI_XT9__)
    #define __MMI_IME_SMART_QWERTY_VK_INPUT__
#endif
#if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
 MMI_BOOL mmi_imc_pen_vk_smart_qwerty_event_handler(mmi_pen_event_type_enum pen_event, UI_character_type ch);
#endif

#if defined __MMI_XT9__
extern CANDIDATE_FLAG;
extern candidate_flag;
#endif 

/* Dialer callback */
static MMI_BOOL (*mmi_imc_pen_dialer_callback)(mmi_imc_dialer_pen_code_enum pen_code, mmi_pen_event_type_enum pen_event) = NULL;

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
static MMI_BOOL back_up_floating_ui_style = MMI_FALSE;
#endif

/* This is to backup the non imc pen handlers so that they can be restored later */
/*mmi_pen_hdlr  mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_TYPE_MAX];
mmi_imc_pen_down_ui_type_enum     g_imc_pen_down_type_backup;*/

mmi_imc_pen_orientation_enum g_pen_current_orientation = PORTRAIT;

/*****************************************************************************
 * Local functions
 *****************************************************************************/
static void mmi_imc_pen_reset_char_password_mode_callback(void);
static void mmi_imc_pen_show_preview_password_mode(U32 char_code);
#if defined __MMI_XT9__
extern void mmi_imc_word_add_qwerty_unicode_to_active_seq(UI_character_type ch , U32 index);
#endif
extern U32  mmi_imc_key_send_message( U8 msg_id, U32 param_0, U32 param_1 );

/* Pen event handlers */
static void mmi_imc_pen_event_pen_down_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_pen_up_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_pen_repeat_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_pen_move_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_pen_abort_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_pen_long_tap_handler(mmi_pen_point_struct pos);

static void mmi_imc_pen_event_pen_down_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info);
static void mmi_imc_pen_event_pen_up_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info);
static void mmi_imc_pen_event_pen_repeat_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info);
static void mmi_imc_pen_event_pen_move_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info);
static void mmi_imc_pen_event_pen_abort_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info);
static void mmi_imc_pen_event_pen_long_tap_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info);


#if defined(__MMI_VIRTUAL_KEYBOARD__)
static void mmi_imc_pen_setup_virtual_keyboard(const sIMEModeDetails * mode_detail_ptr);

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
static void mmi_imc_pen_vk_event_handler(mmi_pen_event_type_enum pen_event, UI_character_type ch, gui_virtual_keyboard_pen_enum vk_event);
#elif defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
static void mmi_imc_pen_vk_event_handler(mmi_pen_event_type_enum pen_event, mmi_imui_message_struct* msg_ptr);
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
void mmi_imc_pen_get_vk_area_rect(S32* x,S32* y,S32* width,S32* height,MMI_BOOL is_large);
static void mmi_imc_pen_switch_vk(void);
static MMI_BOOL mmi_imc_pen_is_depend_rule_input_mode(mmi_imm_input_mode_enum input_mode);
#endif

/* vk event handler for specified function */
static void mmi_imc_pen_vk_caps_lock(mmi_pen_event_type_enum pen_event);
static void mmi_imc_pen_vk_backspace(mmi_pen_event_type_enum pen_event);

#if defined (__MMI_INDIC_VK__)
static void mmi_imc_pen_indic_vk_event(gui_virtual_keyboard_pen_enum vk_event);
static MMI_BOOL mmi_imc_pen_is_indic_vk_type(gui_virtual_keyboard_language_enum vk_type);
#endif /* defined (__MMI_INDIC_VK__) */

/* vk utility function */
static gui_virtual_keyboard_language_enum mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_input_mode_enum input_mode);
static void mmi_imc_pen_get_vk_type(const sIMEModeDetails * input_mode_detail, gui_virtual_keyboard_language_enum * vk_type, MMI_BOOL * has_candidate_box);

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
static void mmi_imc_pen_vk_icon_display_callback(gui_vkbd_display_callback_type_enum *flag, PU8 *content);
#else /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) */
#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) */

#if defined(__MMI_IME_FTE_ENHANCE__)
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
static void mmi_imc_pen_set_virtual_keyboard_by_capital_state(ime_mode_attr_enum capital_state);
static const sIMEModeDetails*  mmi_imc_pen_get_mode_detail_by_capital_state(const sIMEModeDetails * mode_detail_ptr, ime_mode_attr_enum capital_state);
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
static void mmi_imc_pen_select_input_style(void);
#endif

static MMI_BOOL mmi_imc_pen_vk_back_to_lang(void);
static gui_virtual_keyboard_language_enum mmi_imc_pen_get_corresponding_num_symbol_vk_type(mmi_imm_input_mode_enum input_mode);
static MMI_BOOL mmi_imc_pen_vk_zhuyin_tone(mmi_imc_symb_tone_enum tone);
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */


#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

#if !defined(__NO_HANDWRITING__)
/* Stroke event handlers for full screen handwriting*/
static void mmi_imc_pen_event_full_screen_stroke_down_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_full_screen_stroke_up_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_full_screen_stroke_move_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_full_screen_stroke_up_timer_handler(void);
static void mmi_imc_pen_full_screen_stroke_up_cancel_timer_handler(void);

#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
/* Stroke event handlers for multiblock handwriting*/
static void mmi_imc_pen_event_multi_block_stroke_down_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_multi_block_stroke_up_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_multi_block_stroke_move_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_multi_block_stroke_up_timer_handler(void);

static S32  mmi_imc_pen_get_multi_block_number(mmi_pen_point_struct pos);
static void mmi_imc_pen_direct_input(void);
static void mmi_imc_pen_multi_block_stroke_up_cancel_timer_handler(void);
#endif /* #if defined(__MMI_HANDWRITING_MULTI_BLOCK__) */


#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_IME_FTE_ENHANCE__)
/* Stroke event handlers for full screen handwriting*/
static void mmi_imc_pen_event_single_block_stroke_down_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_single_block_stroke_up_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_single_block_stroke_move_handler(mmi_pen_point_struct pos);
static void mmi_imc_pen_event_single_block_stroke_up_timer_handler(void);
static void mmi_imc_pen_single_block_stroke_up_cancel_timer_handler(void);
#endif /*defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_IME_FTE_ENHANCE__) */
#endif /* !defined(__NO_HANDWRITING__) */

static void mmi_imc_pen_dummy_handler(mmi_pen_point_struct pos);

/* Utility functions */
#if !defined(__NO_HANDWRITING__)
static void mmi_imc_pen_init_handwriting_area(void);
#endif
static void mmi_imc_pen_start_capture_strokes(U32 buffer_size, mmi_pen_point_struct* stroke_buffer, U32 region_num, mmi_pen_handwriting_area_struct* region, mmi_pen_handwriting_area_struct* ext_region);
static void mmi_imc_pen_stop_capture_strokes(void);
static void mmi_imc_pen_end_strokes_of_character(void);
static void mmi_imc_pen_begin_strokes_of_character(void);
static void mmi_imc_pen_register_event_handlers(void);

static void mmi_imc_pen_resort_candidates(
        UI_character_type *candidates,
        S32 num,
        mmi_imc_pen_resort_type_enum SortRequirement);
static S32 mmi_imc_pen_get_candidates_from_hand_writing(void);
static void mmi_imc_pen_word_prediction(void);
static S32 mmi_imc_pen_word_prediction_get_cand(UI_string_type pre_string, S32 desired_cnt, S32 first_index, UI_string_type cand_buf, MMI_BOOL *next_page);

static MMI_BOOL mmi_imc_pen_start_waiting_for_confirm(void);

static U32 mmi_imc_pen_send_ui_message(U8 msg_id, U32 param_0, U32 param_1, mmi_imui_command_funcptr command_callback);

static U32 mmi_imc_pen_send_imc_message(U8 msg_id, U32 param_0, U32 param_1);

static void mmi_imc_pen_process_before_changing_input_mode(void);

/* Dialer keys handling for VK */
static MMI_BOOL mmi_imc_pen_vk_is_dialer_event(gui_virtual_keyboard_pen_enum vk_event);
static mmi_imc_dialer_pen_code_enum mmi_imc_pen_vk_get_dialer_pen_code(gui_virtual_keyboard_pen_enum vk_event);
static MMI_BOOL mmi_imc_pen_vk_alphanumeric_dialer_event_handler(
            mmi_pen_event_type_enum pen_event, 
            gui_virtual_keyboard_pen_enum vk_event);
static MMI_BOOL mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled(void);
void mmi_imc_pen_set_history_is_vk_enlarge(MMI_BOOL on);

/*****************************************************************************
 * Extern function
 *****************************************************************************/
extern S32 mmi_res_get_theme_color(U16 id);
extern kal_wchar app_ucs2_towupper(kal_wchar wc);


/*****************************************************************************
 * Local variables
 *****************************************************************************/
 
/* IMC pen object */
static mmi_imc_pen_object_struct g_imc_pen;
mmi_imm_keypadtype_enum last_keypad;
#if !defined(__NO_HANDWRITING__)
/* Handwriting speed */
static S32 g_imc_pen_HW_speed = MMI_IMM_PEN_SPEED_MEDIUM;
#ifdef __MMI_IME_V3__
static MMI_BOOL g_imc_pen_hw_full_screen = MMI_FALSE;
#endif
#endif
#ifdef __MMI_IME_V3__
MMI_BOOL g_imc_pen_is_vk_caps_lock_down = MMI_FALSE;
#endif
#if defined(__MMI_IME_CANDIDATE_GRID__)
static MMI_BOOL g_imc_pen_hw_enable_from_grid = MMI_FALSE;
#endif
#if defined(__MMI_VIRTUAL_KEYBOARD__)
static MMI_BOOL g_imc_enlarge_vk_at_start = MMI_FALSE;
static gui_virtual_keyboard_language_enum g_pen_desired_vk_type = GUI_VIRTUAL_KEYBOARD_MAX_LANG;

#if defined(__MMI_IME_FTE_ENHANCE__)
static const UI_string_type g_imc_pen_emotion_icon_array[] = 
{
    L"*^_^*",
    L"^o^",
    L"*^@^*",
    L"(*^~^*)",
    L"*_*",
    L"-_-",
    L"~_~",
    L"@_@",
    L">_<",
    L"Q_Q",
    L"T_T",
};


static const U16 g_imc_pen_ui_style_str_array[] = 
{
    STR_IME_PEN_INPUT_STYLE_VK_QWERTY,    
#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
    STR_IME_PEN_INPUT_STYLE_VK_ALPHANUMERIC,
#endif	
   /* always put handwriting in the last one  */
#if !defined(__NO_HANDWRITING__)
    STR_IME_PEN_INPUT_STYLE_HW,
#endif
    0
};	

static const mmi_imc_pen_input_style_enum g_imc_pen_input_style[] = 
{
    MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY,    
#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
    MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC,
#endif
   /* always put handwriting in the last one  */
#if !defined(__NO_HANDWRITING__)
    MMI_IMC_PEN_INPUT_STYLE_HW,
#endif
    MMI_IMC_PEN_INPUT_STYLE_MAX
};

static U16 g_imc_pen_selection_list_str_array[MMI_IMC_SELECT_LIST_ITEM_NUM_MAX];
static mmi_imm_input_mode_enum g_imc_pen_selection_list_mode_array[MMI_IMC_SELECT_LIST_ITEM_NUM_MAX];
static mmi_imc_pen_input_style_enum g_imc_pen_selection_list_style_array[MMI_IMC_PEN_INPUT_STYLE_MAX];
static mmi_imc_pen_input_style_enum g_pen_prefer_input_style = MMI_IMC_PEN_INPUT_STYLE_NONE;
static mmi_imc_pen_input_style_enum g_pen_history_input_style = MMI_IMC_PEN_INPUT_STYLE_NONE;
static MMI_BOOL g_imc_pen_is_down_in_extra_block = MMI_FALSE;
static S16 g_imc_pen_history_vk_on = -1;
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

#if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
static MMI_BOOL mmi_imc_pen_vk_smart_qwerty_event_handler_ext(UI_character_type char_code);
#endif
/* The buffer to store points of stroke */
static mmi_pen_point_struct g_imc_pen_stroke_buffer[MMI_IMC_PEN_STROKE_BUFFER_SIZE];

mmi_pen_handwriting_area_struct g_imc_stroke_area[2];

static mmi_pen_point_struct g_imc_pen_previous_point;

#if !defined(__NO_HANDWRITING__)
static S32 g_imc_pen_character_end_period;

static S32 g_imc_pen_confirm_period;

static const S32 g_imc_pen_HW_speed_set[3][2] = 
{
    {400, 2000},
    {550, 3000},
    {750, 4000}
};
#endif /* #if !defined(__NO_HANDWRITING__) */

#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
S32 g_active_block = 0;
static MMI_BOOL g_is_multi_block_enabled = MMI_FALSE;
#endif /* defined(__MMI_HANDWRITING_MULTI_BLOCK__) */

static FuncPtr g_pen_softkey_up_post_halr = NULL;

static U16 g_pen_general_pen_down_control = 0;
static FuncPtr g_pen_timer_callback = NULL;
static mmi_imc_state_enum g_pen_down_state = MMI_IMC_STATE_INITIAL;
static MMI_BOOL g_pen_down_in_editor_content_area = MMI_FALSE;
static MMI_BOOL g_pen_correct_vk_set = MMI_FALSE;

#ifdef __MMI_CLIPBOARD__
/* To handle full screen handwriting case, we start a timer when pen down to simulate the long press event */
#define HANDWRITING_LONG_PRESS_TIMEOUT 300
#define HANDWRITING_REPEAT_TIMEOUT     300
#define MARK_TEXT_TIMEOUT               50
#define PEN_MOVE_RSP_DISTANCE            5

static MMI_BOOL g_clipboard_pen_long_press = MMI_FALSE;
static mmi_imc_editor_pen_event_struct g_clipboard_pen_down_event;
static void mmi_imc_pen_clipboard_long_press_timer_handler(void);
static void mmi_imc_pen_clipboard_mark_text(void);

static MMI_BOOL g_clipboard_pen_is_first_move = MMI_TRUE;
static mmi_pen_point_struct g_clipboard_move_p1, g_clipboard_move_p2;
static void mmi_imc_pen_clipboard_repeat_timer_handler(void);

#endif /* __MMI_CLIPBAORD__ */

#define MMI_IMC_PEN_ZHUYIN_QWERTY_MULTITAP_CHAR_NUM 3

#if defined(__MMI_IME_ZHUYIN_HALF_QWERTY_VK__)
#define MMI_IMC_PEN_ZHUYIN_HALF_QWERTY_KEY_NUM GUI_VKBD_PEN_ZHUYIN_ER - GUI_VKBD_PEN_ZHUYIN_B_P + 1

static const UI_character_type g_imc_pen_zhuyin_half_qwert_keymap[MMI_IMC_PEN_ZHUYIN_HALF_QWERTY_KEY_NUM][MMI_IMC_PEN_ZHUYIN_QWERTY_MULTITAP_CHAR_NUM]=
{
    {0x3105, 0x3106, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_B_P */
    {0x3107, 0x3108, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_M_F */
    {0x3109, 0x310a, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_D_T */
    {0x310b, 0x310c, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_N_L */
    {0x310d, 0x3110, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_G_J */
    {0x310e, 0x3111, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_K_Q */
    {0x310f, 0x3112, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_H_X */
    {0x3113, 0x3114, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_ZH_CH */
    {0x3115, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_SH */
    {0x3116, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_R */
    {0x3117, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_Z */
    {0x3118, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_C */
    {0x3119, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_S */
    {0x3127, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_I */
    {0x3128, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_U */
    {0x3129, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_IU */
    {0x311a, 0x311b, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_A_O */
    {0x311c, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_E */
    {0x311d, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_EH */
    {0x311e, 0x311f, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_AI_EI */
    {0x3120, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_AU */
    {0x3121, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_OU */
    {0x3122, 0x3123, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_AN_EN */
    {0x3124, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_ANG */
    {0x3125, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_ENG */
    {0x3126, 0x0000}, /* GUI_VKBD_PEN_ZHUYIN_ER */
};

#endif /* defined(__MMI_IME_ZHUYIN_HALF_QWERTY_VK__) */

#if defined(__MMI_IME_FTE_ENHANCE__) && (defined(__MMI_MAINLCD_320X480__)|| defined(__MMI_MAINLCD_480X800__)) && defined(__MMI_LANG_TR_CHINESE__)
static const UI_character_type g_imc_pen_zhuyin_qwert_keymap[1][MMI_IMC_PEN_ZHUYIN_QWERTY_MULTITAP_CHAR_NUM] =
{
    {0xFF0C, 0x3002, 0x0000}
};
#endif

#ifdef __MMI_HANDWRITING_WORD_PREDICTION__
#ifdef __MMI_IME_PLUG_IN__
static MMI_BOOL g_mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled = MMI_FALSE;
#else
static MMI_BOOL g_mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled = MMI_TRUE;
#endif
#endif

/*****************************************************************************
 * Global variables
 *****************************************************************************/
#if defined(__MMI_VIRTUAL_KEYBOARD__)
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
extern virtual_keyboard MMI_virtual_keyboard;
#else
extern gui_virtual_keyboard_language_enum g_wgui_virtual_keyboard_lang_type;
extern gui_virtual_keyboard_struct g_wgui_virtual_keyboard;
#endif
#endif
extern U8 g_mmi_imm_keypad_type;


#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
extern ime_writing_lang_struct g_ime_writing_lang_array[MAX_WRITING_LANG];
#endif

extern U16 g_pen_to_control;

#if defined(__NO_HANDWRITING__)

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_hand_writing_initialize
 * DESCRIPTION
 *  Initialize handwriting module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_hand_writing_initialize(mmi_imc_pen_handwriting_type_enum hw_type)
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
*  mmi_ime_hand_writing_deinitialize
* DESCRIPTION
*  Deinitialize handwriting module
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_ime_hand_writing_deinitialize(void)
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
 *  mmi_ime_hand_writing_get_candidates
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  The number of the candidates
 *****************************************************************************/
S32 mmi_ime_hand_writing_get_candidates(
                    mmi_ime_hand_writing_query_param_p query_param,
                    mmi_ime_hand_writing_result_param_p result_param)
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
 *  mmi_ime_hand_writing_hw_type_query
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  The query if the h_w_type is supported by the vendor
 *****************************************************************************/
MMI_BOOL mmi_ime_hand_writing_hw_type_query(mmi_imc_pen_handwriting_type_enum h_w_type)
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
 *  mmi_ime_hand_writing_add_separator_to_candidate_buffer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_ime_hand_writing_add_separator_to_candidate_buffer(UI_character_type * destination_buffer, UI_character_type * source_buffer, S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

#if defined(__MMI_HANDWRITING_PHRASE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_hand_writing_get_candidates_by_phrase
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  The query if the h_w_type is supported by the vendor
 *****************************************************************************/
S32 mmi_ime_hand_writing_get_candidates_by_phrase(
    mmi_ime_hand_writing_phrase_query_param_p query, 
    mmi_ime_hand_writing_phrase_result_param_p result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result.result_cnt = 0;
    result.next_page = MMI_FALSE;
    return 0;

}
#endif


#endif /* defined(__NO_HANDWRITING__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_init( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset( &g_imc_pen, 0x0, sizeof(mmi_imc_pen_object_struct) );
    
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
    g_imc_pen.vk_type_before_tray = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
#if defined(__MMI_IME_FTE_ENHANCE__)
    g_imc_pen.is_hide_by_vk = MMI_TRUE;
#endif
        /* Configure VK */
#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
    g_imc_enlarge_vk_at_start = MMI_TRUE;
#endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */
#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */

    g_imc_pen.global_data_ptr = mmi_imc_get_global_data();

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_deinit
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_pen_deinit( void )
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
 *  mmi_imc_pen_change_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_change_mode(const sIMEModeDetails * mode_details_ptr, U32 reserved )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    gui_virtual_keyboard_language_enum vk_type, desired_vk_type = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
#endif
    MMI_BOOL has_candidate_box = MMI_FALSE, is_mode_changed = MMI_FALSE;    
    mmi_imc_pen_handwriting_type_enum hw_type;
    MMI_BOOL invalid_hw_type = MMI_FALSE;
	#if defined(__MMI_IME_FTE_ENHANCE__)
	#if defined(__MMI_VIRTUAL_KEYBOARD__)
	MMI_BOOL flag  = MMI_FALSE;
	#endif
	#endif
	g_pen_correct_vk_set = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    if (g_pen_desired_vk_type != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
    {
        desired_vk_type = g_pen_desired_vk_type;
        g_pen_desired_vk_type = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
    }
    
    
    mmi_imc_pen_get_vk_type(mode_details_ptr, &vk_type, &has_candidate_box);
#endif
    
	if (mmi_imm_get_history_input_mode() != IMM_INPUT_MODE_NONE)
    {
		if (mmi_imm_get_history_input_mode() != mode_details_ptr->imm_mode_id)
		{
            is_mode_changed = MMI_TRUE;
		}
	}	
	else if (g_imc_pen.curr_mode_details != mode_details_ptr)
    {
		is_mode_changed = MMI_TRUE;
    }

#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_IME_FTE_ENHANCE__)
    if (g_pen_prefer_input_style != MMI_IMC_PEN_INPUT_STYLE_NONE)
    {
        is_mode_changed = MMI_TRUE;
    }
#endif


#if defined(__MMI_VIRTUAL_KEYBOARD__)
	g_imc_pen.vk_type_before_symbol = vk_type;
    g_imc_pen.vk_type_before_tray = vk_type;
#if defined(__MMI_IME_FTE_ENHANCE__)
    g_imc_pen.vk_type_before_num = vk_type;
#endif
#endif
    
    g_imc_pen.curr_mode_details = mode_details_ptr;
    
    hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc_pen.curr_mode_details->Handwriting_Attrib);

    if (hw_type == IMM_HANDWRITING_TYPE_NONE || !mmi_ime_hand_writing_hw_type_query(hw_type))
    {
        invalid_hw_type = MMI_TRUE;
    }
    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    /* If we are resuming the locked VK from interrupt,
     * then the locked vk should be resumed 
     */
     if (g_imc_pen.is_symbol_lock)
     {
        if (desired_vk_type != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
        {
            mmi_imc_pen_set_desired_vk_type(desired_vk_type);
        }
        else
        {
            g_imc_pen.backup_symbol_lock_state = g_imc_pen.is_symbol_lock;
			g_imc_pen.is_symbol_lock = MMI_FALSE;
            mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK, 0, 0, NULL);
        }
     }
     #endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

#if defined(__MMI_VIRTUAL_KEYBOARD__)
    if (desired_vk_type != GUI_VIRTUAL_KEYBOARD_MAX_LANG && desired_vk_type != vk_type
        && (desired_vk_type == GUI_VIRTUAL_KEYBOARD_TRAY || mmi_imc_pen_is_symbol_vk_type(desired_vk_type)
        #if defined (__MMI_INDIC_VK__)
        || mmi_imc_pen_is_indic_vk_type(desired_vk_type)
        #endif
        ))
    {
        if (mmi_imc_pen_is_symbol_vk_type(desired_vk_type))
        {
            if (!is_mode_changed /*&& (mmi_imc_pen_get_corresponding_symbol_vk_type(mode_details_ptr->imm_mode_id) == desired_vk_type
        			#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__*/
                /* 
                    Because several language vk would also trigger European symbols vk. 
                    Hence, except basic symbol vk, the European symbol vk need to process directly.  
                */
								/*|| GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS == desired_vk_type
        			#endif*/
                /* If we are resuming the locked VK from interrupt,
                 * then the locked vk should be resumed 
                 */
							 /* defined(__MMI_IME_FTE_ENHANCE__)*/
			    //)
				)
            {
                mmi_imc_pen_set_virtual_keyboard(desired_vk_type, MMI_FALSE);
				     g_pen_correct_vk_set = MMI_TRUE;
				}
            else
            {
                    mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
                }
        }
        #if defined (__MMI_INDIC_VK__)
        else if (mmi_imc_pen_is_indic_vk_type(desired_vk_type))
        {
            if (!is_mode_changed)
            {
                mmi_imc_pen_set_virtual_keyboard(desired_vk_type, MMI_FALSE);
				     g_pen_correct_vk_set = MMI_TRUE;
            }
            else
            {
                if (g_imc_enlarge_vk_at_start)
                {
                    mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
                }
                else
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);
                }
            }
        }
        #endif
        else
        {
			if (is_mode_changed)
			{
                mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
			}
            else
			{
                mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);
            }
        }
    }
    
        else
        {	
        
		   if (mmi_imc_pen_is_handwriting_vk() && is_mode_changed && !invalid_hw_type)
            {
				
				if (mmi_imm_IsInputTypeNumber())
				{
                         mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
				}
				else
				{
				 #ifndef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
				 #if defined(__MMI_IME_FTE_ENHANCE__) &&  !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__)
				     mmi_imm_hand_writing_category_info_struct_p hw_info = NULL;
         #endif	
         #endif
         /* the previous vk is set to tray. after changeing input method, the vk should be kept as tray. */
    		     mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);                
				#ifndef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
			  #if defined(__MMI_IME_FTE_ENHANCE__) &&  !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__) 
					   hw_info = mmi_imm_get_hand_writing_category(g_imc_pen.curr_mode_details->lang_id);
             mmi_imc_pen_send_ui_message(MMI_IMUI_SET_HW_EXTRA_BLOCK_INDICATOR, (U32)hw_info->extra_block_ind_id, 0, NULL);
        #endif
        #endif
                }
            }
            else
            {
				#if defined(__MMI_IME_FTE_ENHANCE__)
				#if defined(__MMI_VIRTUAL_KEYBOARD__)
				if(invalid_hw_type && mmi_imc_pen_is_handwriting_vk())
				{
					//current input type is hw but its invalid, so set default vk as qwerty
					mmi_imm_config_keyboard_type(IMM_KEYPAD_QWERTY);
					g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
					g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
					flag = MMI_TRUE;
				}
				#endif
				#endif
		         mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
                 mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK,0,0,NULL);
				 #if defined(__MMI_IME_FTE_ENHANCE__)
				#if defined(__MMI_VIRTUAL_KEYBOARD__)
				if(flag)
				{
					mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, MMI_VK_TYPE_QWERTY, 0, NULL);
                }
				#endif
				#endif
            }

    }
#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */

	/* Since, the landscape mode only supports FULL SCREEN 
	 * HW in non FTE build, so we need to disable it
	 */
    if (invalid_hw_type 
    	#if defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)
    	|| mmi_imc_is_in_atv_editor()
    	#endif /* defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)*/
    	)
    {
        mmi_imc_set_hw_type_validity(MMI_FALSE);
    }
    else
    {
        mmi_imc_set_hw_type_validity(MMI_TRUE);
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc_pen.curr_mode_details->Handwriting_Attrib);
        mmi_ime_hand_writing_initialize(hw_type);
#endif
    }

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    g_imc_pen.tone_mark = MMI_IMC_SYMB_TONE_NONE;
    g_imc_pen.zhuyin_vk_char_map_index = -1;
    g_imc_pen.zhuyin_vk_event = GUI_VKBD_PEN_NONE;
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) && defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
    wgui_virtual_keyboard_set_get_string_func(get_multitap_string_func(g_imc_pen.curr_mode_details->imm_mode_id));
    #endif

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_activate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_pen_activate( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color temp_color;
	mmi_imc_pen_orientation_enum g_temp_orientation;

#if defined(__COSMOS_MMI__)
    S32 temp_color32;
#endif
    mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"mmi_imc_pen activate called");
    if(mmi_imc_is_rotated())
	{
		g_temp_orientation = LANDSCAPE;
	}
	else
	{
		g_temp_orientation = PORTRAIT;
	}
	if(g_temp_orientation != g_pen_current_orientation )
	{
		g_pen_correct_vk_set = MMI_FALSE; 
		g_pen_current_orientation = g_temp_orientation;
	}

#if !defined(__NO_HANDWRITING__)
    g_imc_pen_HW_speed = mmi_imm_get_pen_speed();

    g_imc_pen_character_end_period = g_imc_pen_HW_speed_set[g_imc_pen_HW_speed][0];
    
    g_imc_pen_confirm_period = g_imc_pen_HW_speed_set[g_imc_pen_HW_speed][1];

#ifndef __MMI_IME_V3__
#if defined(__COSMOS_MMI__)
    temp_color32 = mmi_res_get_theme_color(VADP_COL_IME_HAND_WRITING_STROKE);

    temp_color.alpha = ((U8) (temp_color32 >> 24));
    temp_color.r = ((U8) (temp_color32 >> 16));
    temp_color.g = ((U8) (temp_color32 >> 8));
    temp_color.b = ((U8) (temp_color32));
#else
    temp_color = PhnsetGetHandwritingColor();
#endif
#else
	//Need to modify from FTE IMEv3 Color
	#if defined(__COSMOS_MMI__)
	#if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
		{
    temp_color = mmi_imm_handwriting_get_current_stroke_color();
		}
		else
	#endif
		{
			temp_color = PhnsetGetHandwritingColor();
		}
	#else
		temp_color = PhnsetGetHandwritingColor();
	#endif
#endif
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_STROKE_COLOR, (U32)&temp_color, 0, NULL);
#endif

    g_imc_pen.global_data_ptr = mmi_imc_get_global_data();
	/* Default value should be MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL */
	g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL;

    /* Set handwriting style */
#if !defined(__NO_HANDWRITING__)
    mmi_imc_pen_init_handwriting_area();
#endif

#if defined(__MMI_VUI_ENGINE__)
    if (!vadp_p2v_uc_is_in_venus())
#endif
    {
	    mmi_imc_pen_register_event_handlers();
    }

    /* Get ready of handwriting */
    if (g_imc_pen.curr_mode_details != NULL)
    {
        hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc_pen.curr_mode_details->Handwriting_Attrib);
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
		if(mmi_ime_hand_writing_hw_type_query(hw_type))
		{
            mmi_ime_hand_writing_initialize(hw_type);
		}
#endif
    }

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    g_imc_pen.vk_style_before_handwriting = MMI_IMC_PEN_DEFAULT_VK_STYLE;
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)

#if defined(__MMI_VIRTUAL_KEYBOARD__)

#if defined(__COSMOS_MMI__)
	 mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
#endif

    /* vk capital state initial */
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    g_imc_pen.vk_cap_state = MMI_IMC_PEN_VK_CAPITAL_AUTO;
#endif
    /* vk type initial */
    {
        g_imc_pen.is_hide_by_vk = MMI_TRUE;
        /* default value */
        switch (mmi_imc_get_vk_present())
        {
        case MMI_IMC_VK_DEFAULT_HIDE:
            g_imc_pen.is_hide_by_vk = MMI_TRUE;
            break;
        case MMI_IMC_VK_DEFAULT_ENLARGE:
            g_imc_pen.is_hide_by_vk = MMI_FALSE;
            break;
        }
        MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8," imc_pen activate: g_imc_pen_history_vk_on=%d ",g_imc_pen_history_vk_on);
        /* history value */    
        if (g_imc_pen_history_vk_on != -1)
        {
            g_imc_pen.is_hide_by_vk = (MMI_BOOL)(!g_imc_pen_history_vk_on);
            g_imc_pen.input_type = g_pen_history_input_style;
        }

#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
    if(mmi_imc_get_vk_present() == MMI_IMC_VK_DEFAULT_ENLARGE)
	{
		if(mmi_imc_get_slider_status()== OPEN && g_imc_pen.is_hide_by_vk == MMI_FALSE)
		{
			mmi_imc_set_slider_status(CLOSE); 
		}
	}
#endif

#if !defined(__MMI_COSMOS_KEYPAD_BAR__)
#if !defined(__MMI_COSMOS_KEYPAD_SLIDER__) 
        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, (MMI_BOOL)(!g_imc_pen.is_hide_by_vk));
#else
        if(mmi_imc_get_slider_status()== CLOSE)
        {
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, (MMI_BOOL)(!g_imc_pen.is_hide_by_vk));
        }
        else
        {
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON,MMI_FALSE);
        }
#endif
#endif

#if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON,MMI_FALSE);
#endif
        switch (mmi_imm_get_keyboard_type())
        {
#if !defined(__MMI_NO_HANDWRITING__) 
            case IMM_KEYPAD_HANDWRITING:
#if defined( __MMI_IME_V3__)
                if (IMM_INPUT_MODE_123_SYMBOLS == mmi_imm_get_curr_input_mode() 
                    || IMM_INPUT_MODE_PHONE_NUMBER == mmi_imm_get_curr_input_mode()
                    || IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD == mmi_imm_get_curr_input_type())
                {
				#if defined(__MMI_IME_VK_TYPE_QWERTY__)
                    g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
                    g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
				#else
					g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
                    g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
				#endif
                    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL); 
                    break;
                }

                {
                    #if defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
                    mmi_imm_input_mode_enum current_input_mode = mmi_imm_handwriting_get_current_mode();
                    mmi_imm_set_current_input_mode(current_input_mode);
                    mmi_imc_change_input_mode(current_input_mode,0);
                    hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc_pen.curr_mode_details->Handwriting_Attrib);
                    mmi_imc_init_select_mode_list_index();
                    #endif
                }
#endif
                if (mmi_imc_is_handwriting_disabled()||(!mmi_ime_hand_writing_hw_type_query(hw_type)))
                {
                    /*Since if the handwriting for particular language is not supported or 
                    library is not available we will set the default type*/
                    g_imc_pen.vk_style = MMI_IMC_PEN_DEFAULT_VK_STYLE; 
                    g_imc_pen.input_type =  MMI_IMC_PEN_DEFAULT_INPUT_STYLE;
                    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);
                    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY)
                    {
                        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON,MMI_FALSE);
                    }
                }
                else
                {

                    if (mmi_imm_IsInputTypeNumber())
                    {
#if !defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                        if (mmi_imc_is_rotated())
                        {
                            g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
                            g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
#endif
                        }
                        else
                        {
                            g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
                            g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
#endif
                        }
                        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);                    
#else

                        g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
                        g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
                        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);  
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER, MMI_FALSE);

#endif
                    }
                    else
                    {
                        g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_HW;
#if defined(__MMI_IME_V3__)
                        g_imc_pen.vk_style = MMI_VK_TYPE_HW;
#else
                        g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
#endif
                        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);

                        if ((!g_imc_pen.is_hide_by_vk)
#if defined(__MMI_IME_V3__)
                            && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON)
#endif
                            )
                        {
                            MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8," imc_pen activate:imc_pen_vk_enable_single_block_hw  calling ");
                            mmi_imc_pen_vk_enable_single_block_hw();
                        }
                        else
                        {
                            mmi_imc_pen_stop_singleblock_handwriting();
                        }
                        /*this flag true means we are using the history,but setting handwriting vk means 
                        history will be cleared, so we need to reset this flag*/
                        g_pen_correct_vk_set = MMI_FALSE;
                    }
                }
                break;

#endif    //__MMI_NO_HANDWRITING__
#if defined (__MMI_IME_ALPHANUMERIC_VK_SUPPORT__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
            case IMM_KEYPAD_ALPHANUMERIC:
                g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
                g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
#if !defined(__COSMOS_MMI__)		
                if (g_imc_pen_history_vk_on == 1 && last_keypad == mmi_imm_get_keyboard_type())
                {
                    /* Do nothing, because the desired Vk is already being set by imc_pen_change mode */
                }
                else
#endif
                {
                    if(g_pen_correct_vk_set && g_pen_history_input_style == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC)
                    {
                        /*Do nothing, because the desired Vk is already being set by imc_pen_change mode*/
                        /* after using this value once, we need to reset it*/
                        g_pen_correct_vk_set = MMI_FALSE;
                    }
                    else
                    {
                        mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
                        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);
                    }
                }
                break;
#endif
#if defined(__MMI_IME_VK_TYPE_QWERTY__) || !defined(__MMI_IME_V3__)
            case IMM_KEYPAD_QWERTY:
                g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
                g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
#if !defined(__COSMOS_MMI__)       
                if (g_imc_pen_history_vk_on == 1 && last_keypad == mmi_imm_get_keyboard_type())
                {
                    /* Do nothing, because the desired Vk is already being set by imc_pen_change mode */
                }
                else
#endif
                {
                    if(g_pen_correct_vk_set && g_pen_history_input_style == MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY)
                    {
                        /*Do nothing, because the desired Vk is already being set by imc_pen_change mode*/
                        /* after using this value once, we need to reset it*/
                        g_pen_correct_vk_set = MMI_FALSE;
                    }
                    else
                    {
                        mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
                        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);
                    }
                }
                break;
#endif    //defined(__MMI_IME_VK_TYPE_QWERTY__) || !defined(__MMI_IME_V3__)
        }
    }

#if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_CSTAR__)
    mmi_ime_reset_group_letters(g_imc_pen.curr_mode_details);
#endif
    MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8," imc_pen activate:cofig_ui style is_hide_by_vk=%d ",g_imc_pen.is_hide_by_vk);

	#if defined(__MMI_COSMOS_KEYPAD_BAR__)
    if (g_pen_prefer_input_style != MMI_IMC_PEN_INPUT_STYLE_NONE || g_imc_pen_history_vk_on == 1)
    {
        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, (MMI_BOOL)(!g_imc_pen.is_hide_by_vk));
    }
	else
	{
		#if !defined(__NO_HANDWRITING__)
        if (mmi_imc_get_single_block_handwriting_state())
        {
            mmi_imc_pen_stop_singleblock_handwriting();
        }
        #endif
	}

    #endif

#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_start_capture_strokes
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_start_capture_strokes(U32 buffer_size, mmi_pen_point_struct* stroke_buffer, U32 region_num, mmi_pen_handwriting_area_struct* region, mmi_pen_handwriting_area_struct* ext_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__NO_HANDWRITING__)
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_start_capture_stroke(
            buffer_size,
            stroke_buffer,
            region_num,
            region,
            ext_region);
    }
    else
#endif
    {
        mmi_pen_start_capture_strokes(
            buffer_size,
            stroke_buffer,
            region_num,
            region,
            ext_region);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_stop_capture_strokes
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_stop_capture_strokes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__NO_HANDWRITING__)
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_stop_capture_stroke();
    }
    else
#endif
    {
        mmi_pen_stop_capture_strokes();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_start_strokes_of_character
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_begin_strokes_of_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__NO_HANDWRITING__)
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_begin_strokes_of_character();
    }
    else
#endif
    {
        mmi_pen_begin_strokes_of_character();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_end_strokes_of_character
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_end_strokes_of_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__NO_HANDWRITING__)
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_end_strokes_of_character();
    }
    else
#endif
    {
        mmi_pen_end_strokes_of_character();
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_handwriting_style
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_imc_pen_handwriting_style_enum mmi_imc_pen_get_handwriting_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_imc_pen.handwriting_style;
}


#if !defined(__NO_HANDWRITING__)
#if defined(__MMI_IME_FTE_ENHANCE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_update_hw_cand_by_index
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_update_hw_cand_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str_ptr = NULL;
    S32 num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_restart_timer(g_imc_pen_confirm_period, mmi_imc_pen_confirm_handwriting_selection, mmi_imc_pen_confirm_handwriting_selection);
    str_ptr = g_imc_pen.hw_cand_buf + index;
    num = g_imc_pen.hw_cand_cnt - index;


    
    if (num > 0)
    {
        
        mmi_ime_hand_writing_add_separator_to_candidate_buffer(g_imc_pen.global_data_ptr->cand_buff, str_ptr, num);
        g_imc_pen.global_data_ptr->cand_count = num;
        g_imc_pen.global_data_ptr->cand_select= 0;

        if (mmi_imc_pen_start_waiting_for_confirm() == MMI_TRUE)
        {
            g_imc_pen.update_struct.count = num;
            g_imc_pen.update_struct.highlight_index = 0;
            g_imc_pen.update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_FOCUS | MMI_IMUI_SELECTION_AREA_FLAG_FIX_GRID;
            g_imc_pen.update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
            if (g_imc_pen.global_data_ptr->cand_page > 0)
            {
                g_imc_pen.update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_PRE_PAGE;
            }
            g_imc_pen.update_struct.separator = 0;
            g_imc_pen.update_struct.str_ptr = g_imc_pen.global_data_ptr->cand_buff;
            
            g_imc_pen.global_data_ptr->cand_count = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX, (U32)&(g_imc_pen.update_struct), 0, NULL);

            if (g_imc_pen.global_data_ptr->cand_count >= num)
            {
                g_imc_pen.global_data_ptr->cand_first_index[g_imc_pen.global_data_ptr->cand_page + 1] =  0;
            }
            else
            {
                g_imc_pen.global_data_ptr->cand_first_index[g_imc_pen.global_data_ptr->cand_page + 1] =  g_imc_pen.global_data_ptr->cand_first_index[g_imc_pen.global_data_ptr->cand_page] + g_imc_pen.global_data_ptr->cand_count;
            }
            mmi_imc_set_state(MMI_IMC_STATE_HAND_WRITING_CAND);
        }
        else
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        }
    }

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_handwriting_style
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_set_handwriting_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_FTE_ENHANCE__)
    g_imc_pen.handwriting_style = MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK;
#else
    g_imc_pen.handwriting_style = (mmi_imc_pen_handwriting_style_enum)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE, 0, 0);
#endif
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_HAND_WRITING_STYLE, (U32)g_imc_pen.handwriting_style, 0, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_init_handwriting_area
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_init_handwriting_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_rect input_box_rect[2];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imc_is_handwriting_disabled())
        return;

    if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN)
	    {
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_GET_HANDWRITING_RECT, (U32)&input_box_rect[0], 0);
        
        g_imc_stroke_area[0].x1 = input_box_rect[0].x ;
        g_imc_stroke_area[0].y1 = input_box_rect[0].y;
        g_imc_stroke_area[0].x2 = input_box_rect[0].x + input_box_rect[0].width - 1;
        g_imc_stroke_area[0].y2 = input_box_rect[0].y + input_box_rect[0].height - 1;

        
        g_imc_stroke_area[1].x1 = 0;
        g_imc_stroke_area[1].y1 = 0;
        
        g_imc_stroke_area[1].x2 = UI_device_width;  
        g_imc_stroke_area[1].y2 = UI_device_height;
 
        mmi_imc_pen_start_capture_strokes(
				 MMI_IMC_PEN_STROKE_BUFFER_SIZE,
				 g_imc_pen_stroke_buffer,
				 1,
				 &g_imc_stroke_area[0],
				 &g_imc_stroke_area[1]);
        mmi_imc_pen_begin_strokes_of_character();
    #if defined(__MMI_VIRTUAL_KEYBOARD__) 
		wgui_virtual_keyboard_set_global_multi_block_mode(MMI_FALSE);
    #endif
    }
#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
     if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK)
	{
		mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_GET_MULTI_BLOCK_AREA, (U32)&input_box_rect[0], (U32)&input_box_rect[1], NULL);

        g_imc_stroke_area[0].x1 = input_box_rect[0].x;
        g_imc_stroke_area[0].y1 = input_box_rect[0].y;
        g_imc_stroke_area[0].x2 = input_box_rect[0].x + input_box_rect[0].width - 1;
        g_imc_stroke_area[0].y2 = input_box_rect[0].y + input_box_rect[0].height - 1;

        
        g_imc_stroke_area[1].x1 = input_box_rect[1].x;
        g_imc_stroke_area[1].y1 = input_box_rect[1].y;
        g_imc_stroke_area[1].x2 = input_box_rect[1].x + input_box_rect[1].width - 1;
        g_imc_stroke_area[1].y2 = input_box_rect[1].y + input_box_rect[1].height - 1;
        
 #if defined(__MMI_VIRTUAL_KEYBOARD__) 
        wgui_virtual_keyboard_set_global_multi_block_mode(MMI_TRUE);
 #endif
	}
#endif /* defined(__MMI_HANDWRITING_MULTI_BLOCK__) */
#if defined(__MMI_IME_FTE_ENHANCE__)
    else if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK)
	{
			mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_GET_SINGLE_BLOCK_AREA, (U32)&input_box_rect[0], (U32)&input_box_rect[1], NULL);
        g_imc_stroke_area[0].x1 = input_box_rect[0].x;
        g_imc_stroke_area[0].y1 = input_box_rect[0].y;
        g_imc_stroke_area[0].x2 = input_box_rect[0].x + input_box_rect[0].width - 1;
        g_imc_stroke_area[0].y2 = input_box_rect[0].y + input_box_rect[0].height - 1;

			
        g_imc_stroke_area[1].x1 = input_box_rect[0].x;
        g_imc_stroke_area[1].y1 = input_box_rect[0].y;
        g_imc_stroke_area[1].x2 = input_box_rect[0].x + input_box_rect[0].width - 1;
        g_imc_stroke_area[1].y2 = input_box_rect[0].y + input_box_rect[0].height - 1;

    }
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_register_event_handlers
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_register_event_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
    }
    else
#endif
    {
        /* backup old handlers */
        /*mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_DOWN] = mmi_pen_get_pen_handler(MMI_PEN_EVENT_DOWN);
        mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_LONG_TAP] = mmi_pen_get_pen_handler(MMI_PEN_EVENT_LONG_TAP);
        mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_REPEAT] = mmi_pen_get_pen_handler(MMI_PEN_EVENT_REPEAT);
        mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_MOVE] = mmi_pen_get_pen_handler(MMI_PEN_EVENT_MOVE);
        mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_UP] = mmi_pen_get_pen_handler(MMI_PEN_EVENT_UP);
        mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_ABORT] = mmi_pen_get_pen_handler(MMI_PEN_EVENT_ABORT);
        g_imc_pen.pen_down_type = g_imc_pen_down_type_backup ; */
    }

    /* Register stroke event handlers */
#if !defined(__NO_HANDWRITING__)	
    if (!mmi_imc_is_handwriting_disabled())
    {
        if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN)
        {
            mmi_pen_register_stroke_down_handler(mmi_imc_pen_event_full_screen_stroke_down_handler);
            mmi_pen_register_stroke_move_handler(mmi_imc_pen_event_full_screen_stroke_move_handler);
            mmi_pen_register_stroke_up_handler(mmi_imc_pen_event_full_screen_stroke_up_handler);
        }
    #if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_IME_FTE_ENHANCE__)
        else if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK)
        {
            mmi_pen_register_stroke_down_handler(mmi_imc_pen_event_single_block_stroke_down_handler);
            mmi_pen_register_stroke_move_handler(mmi_imc_pen_event_single_block_stroke_move_handler);
            mmi_pen_register_stroke_up_handler(mmi_imc_pen_event_single_block_stroke_up_handler);
        }        
    #endif
    #if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
        else if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK)
        {
            mmi_pen_register_stroke_down_handler(mmi_imc_pen_event_multi_block_stroke_down_handler);
            mmi_pen_register_stroke_move_handler(mmi_imc_pen_event_multi_block_stroke_move_handler);
            mmi_pen_register_stroke_up_handler(mmi_imc_pen_event_multi_block_stroke_up_handler);
        }
    #endif /* #if defined(__MMI_HANDWRITING_MULTI_BLOCK__) */
    }
#endif /* !defined(__NO_HANDWRITING__) */	
    /* Register pen event handlers */
    if (!mmi_imc_is_pen_disabled())
    {
    mmi_pen_register_abort_handler(mmi_imc_pen_event_pen_abort_handler);
    mmi_pen_register_down_handler(mmi_imc_pen_event_pen_down_handler);
    mmi_pen_register_long_tap_handler(mmi_imc_pen_event_pen_long_tap_handler);
    mmi_pen_register_move_handler(mmi_imc_pen_event_pen_move_handler);
    mmi_pen_register_up_handler(mmi_imc_pen_event_pen_up_handler);
    mmi_pen_register_repeat_handler(mmi_imc_pen_event_pen_repeat_handler);
}
}


#if defined(__MMI_VIRTUAL_KEYBOARD__)
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_IME_AUTO_CAPITALIZATION__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_vk_type_by_capital_state
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static const sIMEModeDetails*  mmi_imc_pen_get_mode_detail_by_capital_state(const sIMEModeDetails * mode_detail_ptr, ime_mode_attr_enum capital_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32  temp_mode;                    
    const sIMEModeDetails* lowercase_mode_detail;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (capital_state)
    {
        
        case IME_MODE_ATTR_LOWERCASE:
            if (mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
            {
                return mode_detail_ptr;
            }
            break;
        case IME_MODE_ATTR_TITLECASE:
        case IME_MODE_ATTR_UPPERCASE:
            if ((mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE) || (mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE))
            {
                return mode_detail_ptr;
            }
            break;
        default:
            return mode_detail_ptr;
    }

    /* mode enum has excedded 256 so 12 bits given to mode instead of 8*/
    temp_mode = IME_HAND_WRITING_GET_CAPS_LOCK_INPUT_MODE(mode_detail_ptr->Handwriting_Attrib);
    lowercase_mode_detail = mmi_imm_get_input_mode_array_item((mmi_imm_input_mode_enum)temp_mode);
    return lowercase_mode_detail;

}
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
static void mmi_imc_pen_set_vk_shift_state(toggle_state_id_mapping_enum shift_state)
{
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_ADD_TOGGLE_STATE_ID_VK,GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SHIFT,shift_state,NULL);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_setup_virtual_keyboard
 * DESCRIPTION
 *  To set virtual keyboard according to the input mode
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_setup_virtual_keyboard(const sIMEModeDetails * mode_detail_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_language_enum vk_type;
    MMI_BOOL has_candidate_box = MMI_FALSE;
    U16 mode_attr = mode_detail_ptr->Mode_Special_Attrib;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mode_detail_ptr == NULL)
    {
        return;
    }
    #if defined __MMI_COSMOS_KEYPAD_BAR__ || (defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__))
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
	if(!mmi_imm_IsInputTypeNumber())
#endif	
	{
	    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);
	    return;
	}
	#endif
#if defined(__MMI_IME_FTE_ENHANCE__)
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    if (mode_attr & IME_MODE_ATTR_TITLECASE)       
    {
        if (g_imc_pen.vk_cap_state == MMI_IMC_PEN_VK_CAPITAL_AUTO || g_imc_pen.vk_cap_state == MMI_IMC_PEN_VK_TEMP_CAPS_LOCK)
        {
            mmi_imc_key_change_candidate_case_by_previous_string();
            switch (g_imc_pen.global_data_ptr->capital_state)
            {
                case MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER:    
                case MMI_IME_WORD_CAPITAL_STATE_UPPER:
                    /* default capital case for first uppercase mode is uppercase, hence, no change is necessary. */
                    mmi_imc_pen_set_gui_state(g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_CASE_MASK);
                    break;
                case MMI_IME_WORD_CAPITAL_STATE_LOWER:
                    /* change to lowercase vk */ 
                    {
                        mode_detail_ptr = mmi_imc_pen_get_mode_detail_by_capital_state(mode_detail_ptr, IME_MODE_ATTR_LOWERCASE);
                    }
                    break;
                default:
                    ///TODO: for initial test, it should be checked for detail.    
                    MMI_ASSERT(0);
                    break;                
            }
        }
    }
#endif
#endif
#endif

    
    {
        mmi_imc_pen_get_vk_type(mode_detail_ptr, &vk_type, &has_candidate_box);
    
        #if defined(__MMI_IME_FTE_ENHANCE__)
        if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL))
        {
            if (vk_type == GUI_VIRTUAL_KEYBOARD_ENGLISH)
            {
                vk_type = GUI_VIRTUAL_KEYBOARD_INTERNET;
            }
            else if (vk_type == GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE)
            {
                vk_type = GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE;
            }
        }
        if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER)
        {
            if (mmi_imm_get_special_ext_input_type() & IMM_INPUT_TYPE_SPECIAL_EXT_SHOW_DIALER_VK)
	        {
				//FTE 2_0 Dialer Patch
		#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__COSMOS_MMI_PACKAGE__)
				//Check Normal VK or Emergency VK
				if(cui_dialer_is_emergency_call_only())
				{
					vk_type = GUI_VIRTUAL_KEYBOARD_DIALER_EMERGENCY_CALL;
				}
				else
				{
					vk_type = GUI_VIRTUAL_KEYBOARD_DIALER_NORMAL_CALL;
				}

		#else
	        	#if defined(__MMI_DUAL_SIM__)
					#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
						vk_type = GUI_VIRTUAL_KEYBOARD_VIDEO_DIALER_DUAL_SIM;
					#else
	        	vk_type = GUI_VIRTUAL_KEYBOARD_DIALER_DUAL_SIM;
					#endif
	        	#else /* defined(__MMI_DUAL_SIM__) */
					#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
						vk_type = GUI_VIRTUAL_KEYBOARD_VIDEO_DIALER_SINGLE_SIM;
					#else
	        	vk_type = GUI_VIRTUAL_KEYBOARD_DIALER_SINGLE_SIM;
					#endif
	        	#endif /* defined(__MMI_DUAL_SIM__) */	
		#endif
	        	#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)	
	        	g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
	        	#endif
	        }
	        else if (mmi_imm_get_current_allowed_input_mode_num() > 1)
	        {
            	vk_type = GUI_VIRTUAL_KEYBOARD_TEXT_PHONE_NUMBER;
            }
        }
		
        if ((mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR) && 
            mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            vk_type = GUI_VIRTUAL_KEYBOARD_TEXT_PHONE_NUMBER_WILDCHAR;
        }
        #if defined(__MMI_LANG_SM_CHINESE__)
        if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_QUICK_SEARCH_PINYIN)
        {
            vk_type = GUI_VIRTUAL_KEYBOARD_ENGLISH;
        }
        #endif /* defined(__MMI_LANG_SM_CHINESE__) */
    #endif
    }
    mmi_imc_pen_set_virtual_keyboard(vk_type, has_candidate_box);
    
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        mmi_imc_pen_set_vk_active_row(mmi_imm_get_curr_input_type());
#endif
            
    UI_UNUSED_PARAMETER(mode_attr);
}

#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_change_vk_by_captial_state
 * DESCRIPTION
 *  To change vk by capital state
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_change_vk_by_capital_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_IME_AUTO_CAPITALIZATION__)     
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    switch (g_imc_pen.curr_mode_details->imm_mode_id)
    {
        /* Multitap modes */
        case IMM_INPUT_MODE_MULTITAP_HINDI:
        case IMM_INPUT_MODE_MULTITAP_THAI:
        case IMM_INPUT_MODE_MULTITAP_ARABIC:
        case IMM_INPUT_MODE_MULTITAP_BENGALI:
        /* Smart modes */
        case IMM_INPUT_MODE_SMART_HINDI:
        case IMM_INPUT_MODE_SMART_THAI:
        case IMM_INPUT_MODE_SMART_ARABIC:
        case IMM_INPUT_MODE_SMART_BENGALI:
            return;
    }
    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (mmi_imc_pen_is_depend_rule_input_mode(g_imc_pen.curr_mode_details->imm_mode_id))
    {
        return;
    }
    #endif
  #endif
    if ((g_imc_pen.vk_cap_state != MMI_IMC_PEN_VK_CAPS_LOCK) && 
        (!mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG))
    #if !defined(__NO_HANDWRITING__)    
         && (!mmi_imc_get_single_block_handwriting_state())
    #endif    
        )
        {
            mmi_imc_pen_setup_virtual_keyboard(g_imc_pen.curr_mode_details);
        }
    
    if (g_imc_pen.vk_cap_state == MMI_IMC_PEN_VK_TEMP_CAPS_LOCK)
        g_imc_pen.vk_cap_state = MMI_IMC_PEN_VK_CAPITAL_AUTO;
#endif
}


#if defined(__MMI_VUI_ENGINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_down_in_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_event_pen_down_in_editor(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&pen_event, 0, sizeof(pen_event));

    pen_event.mmi_pen_event = MMI_PEN_EVENT_DOWN;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
    
    g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR;
    mmi_imc_pen_event_pen_down_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_up_in_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_event_pen_up_in_editor(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&pen_event, 0, sizeof(pen_event));

    pen_event.mmi_pen_event = MMI_PEN_EVENT_UP;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
    
    g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR;
    mmi_imc_pen_event_pen_up_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_move_in_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_event_pen_move_in_editor(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&pen_event, 0, sizeof(pen_event));

    pen_event.mmi_pen_event = MMI_PEN_EVENT_MOVE;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
    
    g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR;
    mmi_imc_pen_event_pen_move_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_longtap_in_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_event_pen_longtap_in_editor(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&pen_event, 0, sizeof(pen_event));

    pen_event.mmi_pen_event = MMI_PEN_EVENT_LONG_TAP;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
    
    g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR;
    mmi_imc_pen_event_pen_long_tap_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_repeat_in_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_event_pen_repeat_in_editor(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&pen_event, 0, sizeof(pen_event));

    pen_event.mmi_pen_event = MMI_PEN_EVENT_REPEAT;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
    
    g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR;
    mmi_imc_pen_event_pen_repeat_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_abort_in_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_event_pen_abort_in_editor(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&pen_event, 0, sizeof(pen_event));

    pen_event.mmi_pen_event = MMI_PEN_EVENT_ABORT;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
    
    g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR;
    mmi_imc_pen_event_pen_abort_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);

}

#endif /* defined(__MMI_VUI_ENGINE__) */



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_deactivate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_pen_deactivate( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
    }
    else
#endif
    {
        // [MRE_Editor] IME should not restore pen handler !!!!
        // should add API to set disable pen restore
        if (!mmi_imc_is_pen_disabled())
        {
        /* restore old handlers for general UI components*/
        /*mmi_pen_register_down_handler(mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_DOWN]);
        mmi_pen_register_long_tap_handler(mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_LONG_TAP]);
        mmi_pen_register_repeat_handler(mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_REPEAT]);
        mmi_pen_register_move_handler(mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_MOVE]);
        mmi_pen_register_up_handler(mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_UP]);
        mmi_pen_register_abort_handler(mmi_imc_pen_backup_pen_handlers[MMI_PEN_EVENT_ABORT]);
        g_imc_pen_down_type_backup  = g_imc_pen.pen_down_type; */
		
		/* Restore general handlers as a default case */
		mmi_pen_register_abort_handler(wgui_general_pen_abort_hdlr);
		mmi_pen_register_down_handler(wgui_general_pen_down_hdlr);
		mmi_pen_register_long_tap_handler(wgui_general_pen_long_tap_hdlr);
		mmi_pen_register_move_handler(wgui_general_pen_move_hdlr);
		mmi_pen_register_up_handler(wgui_general_pen_up_hdlr);
		mmi_pen_register_repeat_handler(wgui_general_pen_repeat_hdlr);
		g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL;
    }
    }

#if defined(__MMI_HANDWRITING_MULTI_BLOCK__) && defined(__MMI_VIRTUAL_KEYBOARD__)  
	g_is_multi_block_enabled = MMI_FALSE;
	wgui_virtual_keyboard_set_global_multi_block_mode(MMI_FALSE);
#endif

    mmi_imc_pen_stop_capture_strokes();
    
#if defined(__MMI_VUI_ENGINE__)
    if (!vadp_p2v_uc_is_in_venus())
#endif
    {
        mmi_pen_register_stroke_down_handler(mmi_imc_pen_dummy_handler);
        mmi_pen_register_stroke_move_handler(mmi_imc_pen_dummy_handler);
        mmi_pen_register_stroke_up_handler(mmi_imc_pen_dummy_handler);
    }

#if !defined(__MMI_IME_FTE_ENHANCE__) 
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);
#endif

    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_EXIT_HANDWRITING_ON_DISCONNECT, 0, 0, NULL);
    mmi_ime_hand_writing_deinitialize();
    g_pen_timer_callback = NULL;
    g_pen_down_state = MMI_IMC_STATE_INITIAL;
#if defined(__MMI_IME_CANDIDATE_GRID__)
		g_imc_prev_state_is_grid = MMI_FALSE;
#endif
#ifdef __MMI_CLIPBOARD__
    g_clipboard_pen_is_first_move = MMI_TRUE;
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    g_pen_prefer_input_style = MMI_IMC_PEN_INPUT_STYLE_NONE;
    g_imc_pen_history_vk_on = -1;
    g_pen_history_input_style = MMI_IMC_PEN_INPUT_STYLE_NONE;
#endif
last_keypad=(mmi_imm_keypadtype_enum)g_mmi_imm_keypad_type;

/* special case for handling the MAUI_02655194 */
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        last_keypad = IMM_KEYPAD_END_OF_ENUM;
    }
#endif

#ifdef __MMI_IME_PLUG_IN__
    mmi_imc_pen_config_chinese_word_prediction_by_pen_enabled(MMI_FALSE);
#else
    mmi_imc_pen_config_chinese_word_prediction_by_pen_enabled(MMI_TRUE);
#endif
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    wgui_virtual_keyboard_clear_cache_on_imc_disconnect();
    wgui_virtual_keyboard_clear_state_on_imc_disconnect();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_disable_handwriting
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_pen_disable_handwriting( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_pen.is_enable = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_enable_handwriting
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void     mmi_imc_pen_enable_handwriting( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_pen.is_enable = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_down_handler_int
 * DESCRIPTION
 *  the handler to process pen down event
 * PARAMETERS
 *  pen_event           [IN]   The pen event information
 *  pen_down_enum   [IN]  The category for the touched component. There are three kinds of componenet. 
 *                                      One is editor, one is IMUI and the other one is general component.
 *  comp_detail_info  [IN]   The detail information for the component.
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_down_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_rect input_box_rect = {0,0,0,0};
    mmi_imc_state_enum prev_state = MMI_IMC_STATE_INITIAL, cur_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_down_in_editor_content_area = MMI_FALSE;

    prev_state = mmi_imc_get_state();
#if defined(__MMI_IME_FLOATING_CAND_BOX__)  
    if (pen_down_enum == MMI_IMC_PEN_DOWN_UI_TYPE_IMUI)
    {
        if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN)
        {
            mmi_pen_disable_stroke_event();
        }
        
    #ifdef __MMI_CLIPBOARD__ 
        if (mmi_imc_is_clipboard_state() && MMI_IMUI_CLIPBOARD_FLOATING_MENU != comp_detail_info)
        {
            mmi_imc_clipboard_go_back_to_initial();
            mmi_pen_reset();
        }
    #endif /* __MMI_CLIPBOARD__ */
        if (comp_detail_info != MMI_IMUI_CANDIDATE_AREA)
        {
        #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)&& (defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)) /*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */
            if (comp_detail_info == MMI_IMUI_VIRTUAL_KEYBOARD && g_imc_pen.vk_style == MMI_VK_TYPE_ALPHANUMERIC)
            {
            /* for alphanumeric vk, do nothing */
            }
            else
        #endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
            {

	    /* the below code is to confirm the candidate everytime character is entered from 
		qwerty VK. So, need to skip this in case of xT9 */
                #if !defined __MMI_IME_SMART_QWERTY_VK_INPUT__
                
                if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE
                    || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                    gui_lock_double_buffer();
                    #endif

                    if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
                    {
                        mmi_imc_key_smart_alphabetic_confirm_candidate();
                    }
                    else
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }

                    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
                        wgui_virtual_keyboard_draw_from_cache();
                    #endif
                    mmi_imc_redraw_screen_by_state();
                    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
                        wgui_virtual_keyboard_recache();
                    #endif

                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                    gui_unlock_double_buffer();
                    #endif
                }
                #endif
            }
            
            if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
            {
                mmi_imc_delete_timer();
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }
         }
            
        g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_IMUI;

        return;
    }
#endif

    if (pen_down_enum == MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR)
    {   
        if (mmi_imc_get_state() == MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING)
        {
            mmi_imc_cancel_timer();
        }
        else if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
        {
            mmi_imc_delete_timer();
        }
        else
        {
			g_pen_down_state = mmi_imc_get_state();
            g_pen_timer_callback = mmi_imc_delete_timer();
        #if  defined(__MMI_HANDWRITING_WORD_PREDICTION__)
            if (g_pen_timer_callback == mmi_imc_pen_word_prediction)
            {
                g_pen_timer_callback = NULL;
            }
        #endif
        }
        if (comp_detail_info)
            g_pen_down_in_editor_content_area = MMI_TRUE;

        /* To respond editor pen event */
    #ifdef __MMI_CLIPBOARD__ 
        g_clipboard_pen_long_press = MMI_TRUE;
        g_clipboard_pen_down_event = pen_event;
        if (mmi_imc_is_clipboard_state())
        {
            mmi_imc_clipboard_go_back_to_initial();
        }
        if (comp_detail_info)
        {
            mmi_imc_start_timer(HANDWRITING_LONG_PRESS_TIMEOUT, mmi_imc_pen_clipboard_long_press_timer_handler, NULL);
        }
    #endif /* __MMI_CLIPBOARD__ */
    }    
    else if (pen_down_enum == MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL)
    {
    #ifdef __MMI_CLIPBOARD__ 
        if (mmi_imc_is_clipboard_state() &&
            !(g_pen_general_pen_down_control == DM_LSK || g_pen_general_pen_down_control == DM_RSK || g_pen_general_pen_down_control == DM_CSK))
        {
            mmi_imc_clipboard_go_back_to_initial();
        }
    #endif /* __MMI_CLIPBOARD__ */

        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT, (U32)&input_box_rect, 0);

        /* 
          *   in category57, even ime is disconnect due to change from editor to other component.
          *   Pen event handler is still controlled by IME because we have to forward the event to other UI component.
        */
        if (mmi_imc_is_connected())
        {
            cur_state = mmi_imc_get_state();
            if (PEN_CHECK_BOUND(pen_event.pos.x, pen_event.pos.y, input_box_rect.x, input_box_rect.y, input_box_rect.width, input_box_rect.height))
            {
                g_pen_down_state = cur_state;
                g_pen_timer_callback = mmi_imc_delete_timer();
            #if  defined(__MMI_HANDWRITING_WORD_PREDICTION__)
                if (g_pen_timer_callback == mmi_imc_pen_word_prediction)
                    g_pen_timer_callback = NULL;
            #endif

                prev_state = mmi_imc_get_state();

                if (prev_state == MMI_IMC_STATE_SMART_CANDIDATE
                || prev_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
					BOOL lcd_freeze = gdi_lcd_get_freeze();
					mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                    mmi_imc_key_smart_alphabetic_confirm_candidate();
                    mmi_imc_redraw_screen_by_state();
                    mmi_imc_gdi_lcd_freeze(lcd_freeze);
                    mmi_imc_repaint_screen();
                }
				else if (prev_state != MMI_IMC_STATE_INITIAL && 
                         /*prev_state != MMI_IMC_STATE_HAND_WRITING_CAND &&*/
                         prev_state != MMI_IMC_STATE_HAND_WRITING)
                {	
                    mmi_imc_cancel_timer();
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    
                    if (prev_state != MMI_IMC_STATE_HAND_WRITING_CAND)
                    {
                        mmi_imc_redraw_screen_by_state();
                    }
                } 
            }
            else if ((g_pen_general_pen_down_control == DM_LSK || g_pen_general_pen_down_control == DM_CSK) && 
                (cur_state == MMI_IMC_STATE_HAND_WRITING_CAND || cur_state == MMI_IMC_STATE_INITIAL))
            {
                mmi_imc_delete_timer();
            }
            else if (g_pen_general_pen_down_control == DM_RSK && cur_state == MMI_IMC_STATE_INITIAL)
            {
                mmi_imc_delete_timer();
            }
            else 
            {
				/* all other case except CSK */
				g_pen_down_state = mmi_imc_get_state();
                g_pen_timer_callback = mmi_imc_delete_timer();
                #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
				#if !defined(__NO_HANDWRITING__)
				if(g_pen_timer_callback ==mmi_imc_pen_event_single_block_stroke_up_timer_handler )
				{
					g_pen_timer_callback = NULL;
				}
                #endif
                #endif
            }
        }
    }
    else if (pen_down_enum == MMI_IMC_PEN_DOWN_UI_TYPE_IMUI)
    {
    #ifdef __MMI_CLIPBOARD__ 
        if (mmi_imc_is_clipboard_state())
        {
            mmi_imc_clipboard_go_back_to_initial();
        }
    #endif /* __MMI_CLIPBOARD__ */
    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && (defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__))/*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */
        if (comp_detail_info == MMI_IMUI_VIRTUAL_KEYBOARD && g_imc_pen.vk_style == MMI_VK_TYPE_ALPHANUMERIC)
        {
            /* for alphanumeric vk, do nothing */
        }
        else
    #endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
        if (comp_detail_info != MMI_IMUI_CANDIDATE_AREA)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE
                || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
            {
                if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
                {
                    mmi_imc_key_smart_alphabetic_confirm_candidate();
                }
                else
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }
            
                mmi_imc_redraw_screen_by_state();
            }
        }
        
        if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
        {
            mmi_imc_delete_timer();
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_up_handler_int
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_up_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct  imc_msg;
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    MMI_BOOL ret = MMI_FALSE;
    mmi_imc_state_enum state = mmi_imc_get_state();
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    MMI_BOOL is_enlarge_vk = MMI_FALSE;
#endif    
    U32 is_in_edit_area = 0;
    mmi_imui_message_struct imui_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(pen_down_enum)
    {
    case MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR:
    #ifdef __MMI_CLIPBOARD__
        if (g_clipboard_pen_long_press)
        {
            g_clipboard_pen_long_press = MMI_FALSE;
            mmi_imc_delete_timer();
        }
    #endif /* __MMI_CLIPBOARD__ */    

#ifdef __MMI_IME_PLUG_IN__
    if (g_pen_down_in_editor_content_area)
    {  
        mmi_ime_sdk_state_enum pen_down_custom_state;
        
        if (g_pen_down_state == MMI_IMC_STATE_INITIAL)
        {
            pen_down_custom_state = MMI_IME_SDK_STATE_INITIAL;
        }
        else if (mmi_imc_is_in_custom_state(g_pen_down_state))
        {
            pen_down_custom_state = (mmi_ime_sdk_state_enum)g_pen_down_state;
        }
        else
        {
            pen_down_custom_state = MMI_IME_SDK_STATE_MTK;
        }
        
        mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_PEN_CLICK_IN_EDITOR, (U32)pen_down_custom_state, 0);
    }
#endif    
        state = mmi_imc_get_state();
	#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
		if(mmi_imc_get_slider_status()== OPEN && !mmi_imc_is_clipboard_state())
		{
			mmi_imc_process_simulated_slider_event(CLOSE);
		}
	#endif

        /* 
           Because we move the process from pen down to pen up to enhance the performance.
           For the case, pen down in editor but release the pen in other component, 
           we still have to process the suspended process in pen up. 
        */
        if (state == MMI_IMC_STATE_SMART_CANDIDATE
            || state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
			#if defined(__MMI_IME_CANDIDATE_GRID__)
			|| state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC
			#endif
		)
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
            {
                mmi_imc_key_smart_alphabetic_confirm_candidate();
            }
            else
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }
			#if defined(__MMI_IME_CANDIDATE_GRID__)
			if(state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC)
			{
				mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
			}
			#endif
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        else if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            mmi_imc_delete_timer();
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        else if (g_pen_timer_callback != NULL)
        {   
            g_pen_timer_callback();
            g_pen_timer_callback = NULL;
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }   
        else if (g_pen_down_state != MMI_IMC_STATE_INITIAL &&
                   !(g_pen_down_state == MMI_IMC_STATE_SMART_CANDIDATE || 
                     g_pen_down_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC))
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            g_pen_down_state = MMI_IMC_STATE_INITIAL;
        }
    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        if (g_pen_down_state == MMI_IMC_STATE_INITIAL && !mmi_imc_is_clipboard_state() && g_pen_down_in_editor_content_area)
        {
            if ((!mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) ) && (!mmi_imc_is_vk_disabled()))
            {
                #if !defined(__MMI_COSMOS_KEYPAD_BAR__)
                #if defined(__MMI_COSMOS_KEYPAD_SLIDER__)
				if(mmi_imc_get_slider_status()== CLOSE)
				{
                #endif
                if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_HAS_SSP_ACTED, 0, 0))
                {
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
                    if(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY && (mmi_imc_is_handwriting_disabled() || !mmi_imm_current_handwriting_is_enable()))
                    {
                        //do nothing, no need to show handwriting vk when handwriting vk is not allowed.
                    }
                    else
#endif
                    {
                        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                        is_enlarge_vk = MMI_TRUE;

#if !defined(__NO_HANDWRITING__)
                        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY)
                        {
#if defined(__MMI_COSMOS_KEYPAD_SLIDER__)
                            mmi_imc_pen_stop_singleblock_handwriting();
#endif
                            mmi_imc_pen_vk_enable_single_block_hw();
                        }
#endif
                    }
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                }
                #if defined(__MMI_COSMOS_KEYPAD_SLIDER__)
				}
                #endif
                #endif
            }
        }
    #endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */      
        g_pen_timer_callback = NULL;
        g_pen_down_state = MMI_IMC_STATE_INITIAL;


    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        if (is_enlarge_vk)
        {
            mmi_imc_editor_pen_event_struct temp_pen_event;
            memcpy(&temp_pen_event, &pen_event, sizeof(mmi_imc_editor_pen_event_struct));
            temp_pen_event.mmi_pen_event = MMI_PEN_EVENT_ABORT;
            imc_msg.message_id = MMI_IMC_MESSAGE_PEN_EVENT;
            imc_msg.param_0 = (U32)&temp_pen_event;
            imc_msg.param_1 = (U32)&is_in_edit_area;
        }
        else
    #endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */      
        {
            imc_msg.message_id = MMI_IMC_MESSAGE_PEN_EVENT;
            imc_msg.param_0 = (U32)&pen_event;
            imc_msg.param_1 = (U32)&is_in_edit_area;
        }
    
#ifdef __MMI_CLIPBOARD__
        if (g_clipboard_pen_long_press)
        {
            g_clipboard_pen_long_press = MMI_FALSE;
            mmi_imc_cancel_timer();
        }

        /* To prevent cursor flash when pen up in mark state */
        if ((mmi_imc_get_state() == MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN)/* &&
            !mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR, 0, 0)*/)
        {
        #if defined(__MMI_VUI_ENGINE__)
            if (vadp_p2v_uc_is_in_venus())
            {
                ret = MMI_TRUE;
            }
            else
        #endif /* defined(__MMI_VUI_ENGINE__) */
            {
                BOOL lcd_freeze = gdi_lcd_get_freeze();
                mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
                ret = (MMI_BOOL)mmi_imc_send_message(&imc_msg);
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
            }
        }
        else
#endif /* __MMI_CLIPBOARD__ */
        {
        #if defined(__MMI_VUI_ENGINE__)
            if (vadp_p2v_uc_is_in_venus())
            {
                ret = MMI_TRUE;
            }
            else
        #endif /* defined(__MMI_VUI_ENGINE__) */
            {
                ret = (MMI_BOOL)mmi_imc_send_message(&imc_msg);
             }
        }

        if (ret)
        {
            /* To respond editor pen event */
#ifdef __MMI_CLIPBOARD__
            if (mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_READ_ONLY_EDITOR, 0, 0))
            {
                imc_msg.param_1 = 0;
            }
#endif /* __MMI_CLIPBOARD__ */

        #if  defined(__MMI_HANDWRITING_WORD_PREDICTION__)
            if ((imc_msg.param_1 == 1) && mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled())
            {
        #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                if (!is_enlarge_vk)
        #endif
                {
                    mmi_imc_start_timer(WORD_PREDICTION_TIMEOUT, mmi_imc_pen_word_prediction, NULL);
                }
            }
        #endif /* defined(__MMI_HANDWRITING_WORD_PREDICTION__) */
        }

#ifdef __MMI_CLIPBOARD__    
        if (mmi_imc_get_state() == MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN)
        {
        #ifdef __MMI_CLIPBOARD_FLOATING_MENU__
            BOOL lcd_freeze = gdi_lcd_get_freeze();
            mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            /* Don't mark text when editor type is password because we don't support copy password for security */
            if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR, 0, 0))
            {
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_LOCATE_CURSOR_P_BY_POS, (U32)&pen_event, (U32)&g_imc_clipboard_data);
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT, (U32)&g_imc_clipboard_data, 0);
            }
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_CLIPBOARD_FLOATING_MENU;
            mmi_imui_send_message(&imui_msg, NULL);
            mmi_imc_clipboard_show_option_floating_menu();
            mmi_imc_set_state(MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU);
            mmi_imc_redraw_screen_by_state();
        #else
            /* Don't mark text when editor type is password because we don't support copy password for security */
            if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR, 0, 0))
            {
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_LOCATE_CURSOR_P_BY_POS, (U32)&pen_event, (U32)&g_imc_clipboard_data);
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT, (U32)&g_imc_clipboard_data, 0);
            }
            mmi_imc_clipboard_show_option_menu();
        #endif

            mmi_imc_delete_timer();
        }
#endif /* __MMI_CLIPBOARD__ */  

        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL:

        if (mmi_imc_is_connected())
        {
            if (g_pen_down_state == MMI_IMC_STATE_WORD_HIGHLIGHTED 
    		&& (g_pen_general_pen_down_control == DM_LSK || g_pen_general_pen_down_control == DM_CSK || g_pen_general_pen_down_control == 0))
            {
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }
            else if ((state == MMI_IMC_STATE_SMART_CANDIDATE
                || state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) && g_pen_general_pen_down_control != DM_LSK
                 && g_pen_general_pen_down_control != DM_RSK && g_pen_general_pen_down_control != DM_CSK)
            {
                BOOL lcd_freeze = gdi_lcd_get_freeze();
				mmi_imc_gdi_lcd_freeze(MMI_TRUE); 

                if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
                {
                    mmi_imc_key_smart_alphabetic_confirm_candidate();
                }
                else
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
            else if (g_pen_timer_callback != NULL)
            {   
                g_pen_timer_callback();
                g_pen_timer_callback = NULL;
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }   
            else if (g_pen_down_state != MMI_IMC_STATE_INITIAL &&
                     !(g_pen_general_pen_down_control == DM_RSK || 
                       g_pen_general_pen_down_control == DM_LSK || g_pen_general_pen_down_control == DM_CSK))
             {
				 #if defined(__MMI_IME_CANDIDATE_GRID__)
				if(mmi_imc_is_grid_state())
				{
					mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
					mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				}
				#endif
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }
            g_pen_timer_callback = NULL;
            g_pen_down_state = MMI_IMC_STATE_INITIAL;
        }
        if (g_pen_general_pen_down_control == DM_RSK && g_pen_softkey_up_post_halr != NULL)
        {
            g_pen_softkey_up_post_halr();
        }

		/* 
		 * A message such as MESSAGE_SKIP_GENERAL_PEN_UP_EVENT has been added in IMC. 
		 * In multiline editor callback to check if sub type is MMS_VIEWER then return MMI_TRUE, 
		 * otherwise, don't return (Default is MMI_FALSE).
		 * The real aim is not get editor sub type, but get what you really want, like skip general pen up handler 
		 * in this case or not
  		 */
		if(!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_SKIP_GENERAL_PEN_UP_EVENT, 0, 0))
		{
			 wgui_general_pen_up_hdlr(pen_event.pos);
		}
		
        if ((g_pen_general_pen_down_control == DM_LSK || g_pen_general_pen_down_control == DM_CSK) && 
             mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
        {
            mmi_imc_pen_confirm_handwriting_selection();
        }
        g_pen_general_pen_down_control = 0;

        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_IMUI:
    #if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
    #endif /* defined(__MMI_VUI_ENGINE__) */
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_PEN_UP_EVENT, (U32)&pen_event.pos, (U32)&imui_type, mmi_imc_pen_event_command_handler);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        
    #if defined(__MMI_IME_FLOATING_CAND_BOX__) 
        if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN)
        {
            mmi_pen_enable_stroke_event();
        }
    #endif
        break;
    default:
        break;
    }
    
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    g_imc_pen.vk_longtap = MMI_FALSE;
#endif
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_repeat_handler_int
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_repeat_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    MMI_BOOL ret = MMI_FALSE;
    U32 is_in_edit_area = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(pen_down_enum)
    {
    case MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR:                
    #ifdef __MMI_CLIPBOARD__
        if (mmi_imc_get_state() == MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN &&
            !mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR, 0, 0))
        {
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_ADJUST_VIEW, (U32)&pen_event, (U32)&g_imc_clipboard_data);
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT, (U32)&g_imc_clipboard_data, 0);
        }
    #endif /* __MMI_CLIPBOARD__ */
    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            ret = MMI_TRUE;
        }
        else
    #endif /* defined(__MMI_VUI_ENGINE__) */
        {
            ret = (MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_PEN_EVENT, (U32)&pen_event, (U32)&is_in_edit_area);
        }
        if (ret)
        {
            /* To respond editor pen event */
        }
        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL:
        wgui_general_pen_repeat_hdlr(pen_event.pos);
        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_IMUI:        
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_PEN_REPEAT_EVENT, (U32)&pen_event.pos, (U32)&imui_type, mmi_imc_pen_event_command_handler);
        break;
    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_long_tap_handler_int
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_long_tap_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    MMI_BOOL ret = MMI_FALSE;
    U32  is_in_edit_area = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (pen_down_enum)
    {
    case MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR:
    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            ret = MMI_TRUE;
        }
        else
    #endif /* defined(__MMI_VUI_ENGINE__) */
        {
            ret = (MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_PEN_EVENT, (U32)&pen_event, (U32)&is_in_edit_area);
        }
    #ifdef __MMI_CLIPBOARD__
        if (g_clipboard_pen_long_press)
        {
            g_clipboard_pen_long_press = MMI_FALSE;
            mmi_imc_delete_timer();
        }
    #endif /* __MMI_CLIPBOARD__ */
        
        if (ret)
        {
            /* To respond editor pen event */
        #if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if(UI_DOUBLE_BUFFER_SUPPORT)
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
            #if(UI_DOUBLE_BUFFER_SUPPORT)
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
        #endif /* __MMI_CLIPBOARD__ */
        }
        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL:
        wgui_general_pen_long_tap_hdlr(pen_event.pos);
        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_IMUI:
        
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_PEN_LONG_TAP_EVENT, (U32)&pen_event.pos, (U32)&imui_type, mmi_imc_pen_event_command_handler);

        break;
    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_move_handler_int
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_move_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    MMI_BOOL ret = MMI_FALSE;
    mmi_imc_state_enum state;
    U32 is_in_edit_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(pen_down_enum)
    {
    case MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR:
                
    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            ret = MMI_TRUE;
        }
        else
    #endif /* defined(__MMI_VUI_ENGINE__) */
        {
            ret = (MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_PEN_EVENT, (U32)&pen_event, (U32)&is_in_edit_area);
        }
        state = mmi_imc_get_state();
        /* 
           Because we move the process from pen down to pen up to enhance the performance.
           For the case, pen down in editor but release the pen in other component, 
           we still have to process the suspended process in pen up. 
        */
        if (state == MMI_IMC_STATE_SMART_CANDIDATE
            || state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
#if defined(__MMI_IME_CANDIDATE_GRID__)
            || state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC
#endif
            )
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
            {
                mmi_imc_key_smart_alphabetic_confirm_candidate();
            }
            else
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        else if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            mmi_imc_delete_timer();
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        else if (g_pen_timer_callback != NULL && !mmi_imc_is_clipboard_state())
        {   
         #if(UI_DOUBLE_BUFFER_SUPPORT)
            gui_lock_double_buffer();
        #endif 
            g_pen_timer_callback();
            g_pen_timer_callback = NULL;
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        #if(UI_DOUBLE_BUFFER_SUPPORT)
            gui_unlock_double_buffer();
        #endif  
        }   
        else if (g_pen_down_state != MMI_IMC_STATE_INITIAL &&
                   !(g_pen_down_state == MMI_IMC_STATE_SMART_CANDIDATE || 
                     g_pen_down_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) &&
                   !mmi_imc_is_clipboard_state())
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            g_pen_down_state = MMI_IMC_STATE_INITIAL;
        }
        g_pen_timer_callback = NULL;
        g_pen_down_state = MMI_IMC_STATE_INITIAL;
        
    #ifdef __MMI_CLIPBOARD__
        /* Cancel mark text timer only when pen move certain distance PEN_MOVE_RSP_DISTANCE */
        if (g_clipboard_pen_long_press &&
            (MMI_FALSE == PEN_CHECK_BOUND(
            pen_event.pos.x, 
            pen_event.pos.y, 
            g_clipboard_pen_down_event.pos.x - PEN_MOVE_RSP_DISTANCE, 
            g_clipboard_pen_down_event.pos.y - PEN_MOVE_RSP_DISTANCE, 
            PEN_MOVE_RSP_DISTANCE << 1, 
            PEN_MOVE_RSP_DISTANCE << 1)))
        {
            g_clipboard_pen_long_press = MMI_FALSE;
            g_pen_timer_callback = mmi_imc_delete_timer();
			if(g_pen_timer_callback == mmi_imc_pen_clipboard_long_press_timer_handler)
			{
				/*we do not want to store this timer in case of smooth scrolling which first stores clipboard timer*/
                    g_pen_timer_callback = NULL;
			}
        }
    #endif /* __MMI_CLIPBOARD__ */

        if (ret)
        {
            /* To respond editor pen event */
        #ifdef __MMI_CLIPBOARD__
            if (mmi_imc_get_state() == MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN)
            {
                /* Don't mark text when editor type is password because we don't support copy password for security */
                if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR, 0, 0))
                {
                #ifdef __MMI_CLIPBOARD_FLOATING_MENU__
                    mmi_imui_message_struct imui_msg;
                    imui_msg.message_id = MMI_IMUI_MESSAGE_HIDE_CLIPBOARD_FLOATING_MENU;
                    mmi_imui_send_message(&imui_msg, NULL);
                #endif /* __MMI_CLIPBOARD_FLOATING_MENU__ */
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_LOCATE_CURSOR_P_BY_POS, (U32)&pen_event, (U32)&g_imc_clipboard_data);
                    mmi_imc_start_timer(MARK_TEXT_TIMEOUT, mmi_imc_pen_clipboard_mark_text, NULL);
                }
            }
        #endif /* __MMI_CLIPBOARD__ */
        }
        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL:
        /* 
           Because we move the process from pen down to pen up to enhance the performance.
           For the case, pen down in editor but release the pen in other component, 
           we still have to process the suspended process in pen up. 
        */
        state = mmi_imc_get_state();

        if (mmi_imc_is_connected())
        {
            if ( state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
            {
                BOOL lcd_freeze = gdi_lcd_get_freeze();
				mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
                if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
                {
                    mmi_imc_key_smart_alphabetic_confirm_candidate();
                }
                else
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
            else if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
            {
                BOOL lcd_freeze = gdi_lcd_get_freeze();
				mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
                mmi_imc_delete_timer();
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
            else if (g_pen_timer_callback != NULL)
            {   
                BOOL lcd_freeze = gdi_lcd_get_freeze();
				mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
                g_pen_timer_callback();
                g_pen_timer_callback = NULL;
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }   
            else if (g_pen_down_state != MMI_IMC_STATE_INITIAL &&
                     !(g_pen_general_pen_down_control == DM_RSK || 
				       g_pen_general_pen_down_control == DM_LSK || g_pen_general_pen_down_control == DM_CSK))
            {
                BOOL lcd_freeze = gdi_lcd_get_freeze();
				mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
                if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE)
                {
                   mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0); 
                }
			#if defined(__MMI_IME_CANDIDATE_GRID__)
				if(mmi_imc_is_grid_state())
				{
				#if defined(__MMI_IME_FLOATING_CAND_BOX__)
					mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
				#endif
				#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
					mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				#endif
					 mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0); 
				}
			#endif
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
			
            g_pen_timer_callback = NULL;
            g_pen_down_state = MMI_IMC_STATE_INITIAL;
        }
        wgui_general_pen_move_hdlr(pen_event.pos);
        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_IMUI:
        
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_PEN_MOVE_EVENT, (U32)&pen_event.pos, (U32)&imui_type, mmi_imc_pen_event_command_handler);

        break;
    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_abort_handler_int
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_abort_handler_int(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    MMI_BOOL ret = MMI_FALSE;
    U32 is_in_edit_area;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (pen_down_enum)
    {
    case MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR:
   #if !defined(__NO_HANDWRITING__)
   if (mmi_imc_pen_get_handwriting_style() != MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN)
   #endif
   {
		if(g_pen_timer_callback!=NULL)
		{
			g_pen_timer_callback();
			g_pen_timer_callback = NULL;
		}
         mmi_imc_cancel_timer();
		 mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            ret = MMI_TRUE;
        }
        else
    #endif /* defined(__MMI_VUI_ENGINE__) */
        {
            ret = (MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_PEN_EVENT, (U32)&pen_event, (U32)&is_in_edit_area);
        }
        if (ret)
        {
            /* To respond editor pen event */
			mmi_imc_redraw_screen_by_state();
        }
   }
        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL:
        wgui_general_pen_abort_hdlr(pen_event.pos);
        break;
    case MMI_IMC_PEN_DOWN_UI_TYPE_IMUI:
        
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_PEN_ABORT_EVENT, (U32)&pen_event.pos, (U32)&imui_type, mmi_imc_pen_event_command_handler);

        break;
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_down_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_down_general_pre_handler(mmi_imc_editor_pen_event_struct pen_event, mmi_imc_pen_down_ui_type_enum pen_down_enum, U16 comp_detail_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_rect input_box_rect;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_down_enum == MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL)
    {
        if (mmi_imc_get_state() == MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING)
        {
            mmi_imc_cancel_timer();
        }
        if  (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
        {
            mmi_imc_delete_timer();
        }

        if (mmi_imc_pen_send_imc_message(MMI_IMC_MESSGAE_GET_EXT_INPUT_BOX_RECT, (U32)&input_box_rect, 0)) /* Special case when pen down in list in dictionary */
        {
            if (PEN_CHECK_BOUND(pen_event.pos.x, pen_event.pos.y, input_box_rect.x, input_box_rect.y, input_box_rect.width, input_box_rect.height) && mmi_imc_is_connected())
            {
                if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND) 
                {
                    mmi_imc_cancel_timer();
                }    
                else
                {
                    mmi_imc_reset_ime_state();
                }    
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_down_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    mmi_imui_control_type_enum imui_type = MMI_IMUI_CONTROL_MAX;
    U32 is_in_edit_area = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (gui_screen_smooth_scrolling_in_freerun() &&
        !gui_ssp_pos_in_menu(pos.x, pos.y))
    {
        gui_ssp_pen_up_dummy();
        mmi_pen_reset();
        return;
    }
#endif

    memset(&pen_event, 0, sizeof(pen_event));

    pen_event.mmi_pen_event = MMI_PEN_EVENT_DOWN;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
    
#if defined(__MMI_IME_FLOATING_CAND_BOX__)  || defined(__MMI_IME_FTE_ENHANCE__)
    if (mmi_imc_get_current_floating_imui_control_set() &&
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_PEN_DOWN_EVENT, (U32)&pos, (U32)&imui_type, mmi_imc_pen_event_command_handler) == MMI_IMUI_RESULT_TRUE)
    {   
        g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_IMUI;
        mmi_imc_pen_event_pen_down_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);
        return;
    }
#endif /* #if defined(__MMI_IME_FLOATING_CAND_BOX__)  */

        
    if ((MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_PEN_EVENT, (U32)&pen_event, (U32)&is_in_edit_area))
    {
        g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR;
        mmi_imc_pen_event_pen_down_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)is_in_edit_area);
    }
    else if (mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_PEN_DOWN_EVENT, (U32)&pos, (U32)&imui_type, mmi_imc_pen_event_command_handler) == MMI_IMUI_RESULT_FALSE)
    {
        g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL;
        mmi_imc_pen_event_pen_down_general_pre_handler(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);
        if (mmi_imc_is_clipboard_state())
        {
            /* Incase the clipboard UI is not update at the same time on the screen */
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            if (pos.y > (UI_device_height - MMI_SOFTKEY_HEIGHT))
            {
                wgui_general_pen_down_hdlr(pos);
            }
            g_pen_general_pen_down_control = g_pen_to_control;
            mmi_imc_pen_event_pen_down_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);

            /* Need to repaint due to clipboard lock frame buffer, otherwise the component draw in wgui_general_pen_down_hdlr
               will show error, Ex. softkey will not show highlight when press */
            mmi_imc_repaint_screen();
        }
        else
        {
            wgui_general_pen_down_hdlr(pos);
            g_pen_general_pen_down_control = g_pen_to_control;
            mmi_imc_pen_event_pen_down_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);
        }
    }
    else
    {
        g_imc_pen.pen_down_type = MMI_IMC_PEN_DOWN_UI_TYPE_IMUI;
        mmi_imc_pen_event_pen_down_handler_int(pen_event, g_imc_pen.pen_down_type, (U16)imui_type);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_up_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    MMI_ID pre_gid, pre_sid, cur_gid, cur_sid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_event.mmi_pen_event = MMI_PEN_EVENT_UP;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;

    mmi_frm_get_active_scrn_id(&pre_gid, &pre_sid);
    mmi_imc_pen_event_pen_up_handler_int(pen_event,  g_imc_pen.pen_down_type, MMI_IMUI_CONTROL_MAX);
    mmi_frm_get_active_scrn_id(&cur_gid, &cur_sid);

    if (pre_gid == cur_gid && pre_sid == cur_sid)
    {
    #if defined(__MMI_IME_FTE_ENHANCE__)
        mmi_imc_pen_reset_pen_repeat_event();
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_repeat_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_repeat_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_event.mmi_pen_event = MMI_PEN_EVENT_REPEAT;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;

    switch(g_imc_pen.pen_down_type)
    {
    case MMI_IMC_PEN_DOWN_UI_TYPE_GENERAL:
    case MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR:
    case MMI_IMC_PEN_DOWN_UI_TYPE_IMUI:        
        mmi_imc_pen_event_pen_repeat_handler_int(pen_event, g_imc_pen.pen_down_type, MMI_IMUI_CONTROL_MAX);  
        break;
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_move_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_event.mmi_pen_event = MMI_PEN_EVENT_MOVE;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
        
    mmi_imc_pen_event_pen_move_handler_int(pen_event, g_imc_pen.pen_down_type, MMI_IMUI_CONTROL_MAX);
        
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_abort_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_abort_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_event.mmi_pen_event = MMI_PEN_EVENT_ABORT;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
        
    mmi_imc_pen_event_pen_abort_handler_int(pen_event, g_imc_pen.pen_down_type, MMI_IMUI_CONTROL_MAX);

#if defined(__MMI_IME_FTE_ENHANCE__)
    mmi_imc_pen_reset_pen_repeat_event();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_pen_long_tap_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_pen_long_tap_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_editor_pen_event_struct pen_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_event.mmi_pen_event = MMI_PEN_EVENT_LONG_TAP;
    pen_event.pos.x = pos.x;
    pen_event.pos.y = pos.y;
        
    mmi_imc_pen_event_pen_long_tap_handler_int(pen_event, g_imc_pen.pen_down_type, MMI_IMUI_CONTROL_MAX);
        
}


#ifdef __MMI_CLIPBOARD__
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_pen_event_down_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_clipboard_pen_event_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Providing the touch feedback for down event */
    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
				
    mmi_imc_pen_event_pen_down_handler(pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_pen_event_up_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_clipboard_pen_event_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    if (GUI_INPUT_BOX_SSP_STATE_UNFOCUS != gui_input_box_ssp_get_state())
    {
        /* If in ssp state, we should delete the long press timer which will trigger the clipboard state */
        mmi_imc_delete_timer();
    }
    else
#endif
    {
        mmi_imc_pen_event_pen_up_handler(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_pen_event_move_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_clipboard_pen_event_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    if (GUI_INPUT_BOX_SSP_STATE_UNFOCUS != gui_input_box_ssp_get_state())
    {
        /* If in ssp state, we should delete the long press timer which will trigger the clipboard state */
        mmi_imc_delete_timer();
    }
    else
#endif
    {
        mmi_imc_pen_event_pen_move_handler(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_pen_event_abort_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_clipboard_pen_event_abort_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_event_pen_abort_handler(pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_pen_event_long_tap_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_clipboard_pen_event_long_tap_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_event_pen_long_tap_handler(pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_clipboard_pen_event_repeat_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_clipboard_pen_event_repeat_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_event_pen_repeat_handler(pos);
}


#endif

#if  defined(__MMI_IME_V3__)

void mmi_imc_pen_play_touch_feed_back(void)
{
    
    if(mmi_imm_is_sound_feedback_enabled_for_ime())
        {
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN_TONE);
        }
    if(mmi_imm_is_vibration_enabled())
                {
                    //play vibration
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN_VIBRATE);
        }

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_command_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_event_command_handler(mmi_imui_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    mmi_imm_input_mode_enum old_mode;
    UI_character_type ch = 0x0;
	mmi_imc_message_struct imc_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CSTAR_PHRASE_INPUT__
    mmi_imui_set_active_control_by_ui_msg(msg_ptr);
#endif
    
    switch (msg_ptr->message_id)
    {
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMUI_MESSAGE_PEN_DOWN_IN_CANDIDATE_GRID_BOX:
         if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_GRID_PEN_TEXT)
        {
            /* Providing the touch feedback for down event */
            #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                mmi_imc_pen_play_touch_feed_back();
            #else
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            #endif
            
			index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_GRID_BOX_GET_INDEX, 0, 0, NULL);
			
			 switch(mmi_imc_get_state())
            {
				case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
					 mmi_imc_change_highlighted_candidate_from_candidate_box(index);
					 break;
				default:
					break;
			 }
			g_imc_pen.global_data_ptr->cand_select = index;
		}
		break;
	case MMI_IMUI_MESSAGE_PEN_MOVE_IN_CANDIDATE_GRID_BOX:
		if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_GRID_PEN_TEXT)
        {
           
			index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_GRID_BOX_GET_INDEX, 0, 0, NULL);
			
			 switch(mmi_imc_get_state())
            {
				case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
					 mmi_imc_change_highlighted_candidate_from_candidate_box(index);
					 break;
				default:
					break;
			 }
			g_imc_pen.global_data_ptr->cand_select = index;
			
		}
		break;
	case MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_GRID_BOX:
		if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_GRID_PEN_TEXT)
        {   /* Select a candidate by pen */
            BOOL lcd_freeze = gdi_lcd_get_freeze();
            UI_string_type str = NULL;
            UI_character_type temp_cand_buff[MMI_IMC_MAX_CANDIDATE_BUFFSIZE];

            mmi_imc_state_enum state = mmi_imc_get_state();
            str = mmi_imc_get_select_string_from_candidate_box();
            memset(temp_cand_buff, 0, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
            memcpy(&temp_cand_buff[0], str, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
			#if !defined(__NO_HANDWRITING__)  
			if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
			{
				 imc_msg.message_id = MMI_IMC_MESSAGE_DELETE_CHAR;
                 imc_msg.param_0 = 1;
				 mmi_imc_send_message(&imc_msg);
				 imc_msg.message_id = MMI_IMC_MESSAGE_CLEAR_HILIGHT;
				 mmi_imc_send_message(&imc_msg);

			}
			#endif
		#if defined(__MMI_CSTAR_PHRASE_INPUT__)
			if(mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID)
			{
				mmi_imc_key_smart_phonetic_candidate_select();
				if(g_imc_pen.global_data_ptr->key_element_length != 0)
				{
					mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID);
				}
			}
			else
			{
				mmi_imc_select_candidate_from_candidate_box();
			}

			if(mmi_imc_get_state() != MMI_IMC_STATE_SPELL_INPUTING_GRID && mmi_imc_get_state() != MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID)
			{
				#if defined(__MMI_IME_CANDIDATE_GRID__)		
				if(mmi_imc_is_grid_state() || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING)
				#endif
				{
				    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				}
			}
		#else
			#if defined(__MMI_IME_CANDIDATE_GRID__)		
				if(mmi_imc_is_grid_state() || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING)
			#endif
				{
				    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				}
			mmi_imc_select_candidate_from_candidate_box();
		#endif	
			
			#if !defined(__NO_HANDWRITING__)  
			if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
			{
				g_imc_pen_hw_enable_from_grid = MMI_TRUE;
				mmi_imc_pen_vk_enable_single_block_hw();
				g_imc_pen_hw_enable_from_grid = MMI_FALSE;
				mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
			}
			#endif
            
            if(state == MMI_IMC_STATE_SMART_CANDIDATE
                || state == MMI_IMC_STATE_VK_CAND
                || state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC)
            {
                #if defined(__MMI_IME_USER_DATABASE__)
                if (*temp_cand_buff != MMI_IME_USER_DATABASE_NEW_WORD)
                #endif
                {
				   //need to append space
                      if( (g_imc_pen.curr_mode_details->Lang_Special_Attrib & (IME_LANG_ATTR_ALPHABETIC | IME_LANG_ATTR_ENGLISH_ONLY)))
                       {       
                       #if defined(__MMI_IME_V3__)     
                           if(mmi_imm_is_auto_space_enabled())
                       #endif
                           {
                                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                           }
                       }
                    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    if(!mmi_imm_is_auto_capitalization_valid() && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
                    #endif
                    {
                    #if defined(__MMI_VIRTUAL_KEYBOARD__)
                        if(g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                        {
                            g_imc_pen.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                            mmi_imc_pen_set_gui_state(IME_MODE_ATTR_LOWERCASE);
                            mmi_imc_change_input_mode_according_to_capital_state(g_imc_pen.global_data_ptr->capital_state);
                            mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK,0,0,NULL);
                        }
                    #endif
                    }
                }
             }
		    mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
		}
		 else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_GRID_PEN_DELETE)
        {
		#if defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)
			if(mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX && mmi_imc_pen_is_handwriting_vk())
			{
				mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
				mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
				mmi_imc_change_state_from_grid_to_initial();
				mmi_imc_pen_vk_enable_single_block_hw();
			}
			else
		#endif
			{
				mmi_imc_key_group_key_down_int(KEY_RSK, KEY_EVENT_DOWN);
				mmi_imc_redraw_screen_by_state();
			}
        }
		 else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_GRID_PEN_NAVIGATION_UP)
        {
			if (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING_GRID)
            {
                mmi_imc_select_composition_from_composition_box();
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID);
            }
            mmi_imc_common_arrow_key_handler(MMI_IMC_KEY_PAGE_UP, KEY_EVENT_DOWN);
            mmi_imc_redraw_screen_by_state();
        }
		  else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_GRID_PEN_NAVIGATION_DOWN)
        {
			if (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING_GRID)
            {
				if(mmi_imm_get_keyboard_type() != IMM_KEYPAD_QWERTY)
				{
					mmi_imc_select_composition_from_composition_box();
				}
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID);
            }
            mmi_imc_common_arrow_key_handler(MMI_IMC_KEY_PAGE_DOWN, KEY_EVENT_DOWN);
            mmi_imc_redraw_screen_by_state();
        }
		  else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_GRID_PEN_BACK)
        {
			mmi_imui_message_struct imui_msg;
			UI_buffer_type start_p = NULL, end_p = NULL;
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
			mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
			if(mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN && !(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY))
			{
				//U8 index;
				//index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX, 0, 0, NULL);
				//mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, index, 0, NULL);
				mmi_imc_update_smart_pinyin_composition();
				mmi_imc_change_highlighted_composition_from_composition_box(0);
				imui_msg.message_id = MMI_IMUI_MESSAGE_ADD_VERTICAL_FLAG;
                mmi_imui_send_message(&imui_msg, NULL);
			}
if(mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_GRID) 
			{
				mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
				mmi_imc_update_candidate_box_by_query_result(g_imc_pen.global_data_ptr->cand_buff,g_imc_pen.global_data_ptr->cand_count,MMI_FALSE);
			}
			else
			{
				mmi_imc_set_state(g_imc_prev_state_grid);
			}
	 #if !defined(__NO_HANDWRITING__)     
			if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
			{
				mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_FALSE, 0); 
				mmi_imc_pen_vk_enable_single_block_hw();
			}
			#endif
			mmi_imc_redraw_screen_by_state();
        }

		break;
	
	case MMI_IMUI_MESSAGE_PEN_LONGTAP_IN_CANDIDATE_GRID_BOX:
		 if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_GRID_PEN_DELETE)
        {
            mmi_imc_key_group_key_long_int(KEY_RSK, KEY_EVENT_LONG_PRESS);
            mmi_imc_redraw_screen_by_state();
        }
		break;
	#endif
    case MMI_IMUI_MESSAGE_PEN_DOWN_IN_CANDIDATE_BOX:
        
        if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT)
        {
            /* Providing the touch feedback for down event */
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                mmi_imc_pen_play_touch_feed_back();
#else
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
#endif

			
            index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_GET_INDEX, 0, 0, NULL);
            
            switch(mmi_imc_get_state())
            {
            case MMI_IMC_STATE_SMART_CANDIDATE:
            case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
                
                 mmi_imc_change_highlighted_candidate_from_candidate_box(index);
                 
                 break;
                 
        #if !defined(__NO_HANDWRITING__)         
            case MMI_IMC_STATE_HAND_WRITING_CAND:
            
                 mmi_imc_change_highlighted_candidate_from_candidate_box(index);
                 
                 mmi_imc_restart_timer(g_imc_pen_confirm_period, mmi_imc_pen_confirm_handwriting_selection, mmi_imc_pen_confirm_handwriting_selection);

                 break;
        #endif
                 
            default:
                
                break;
            }

            g_imc_pen.global_data_ptr->cand_select = index;
            
        }
        else
        {
        #if defined(__MMI_IME_FTE_ENHANCE__)
            if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
            {
                //mmi_imc_delete_timer();
            }
            else
        #endif
            {
                mmi_imc_cancel_timer();
            }
        }
        
        break;
        
    case MMI_IMUI_MESSAGE_PEN_MOVE_IN_CANDIDATE_BOX:

        if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT)
        {
            index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_GET_INDEX, 0, 0, NULL);
            
            switch(mmi_imc_get_state())
            {
            case MMI_IMC_STATE_SMART_CANDIDATE:
            case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
                
                 mmi_imc_change_highlighted_candidate_from_candidate_box(index);
                 
                 break;
        #if !defined(__NO_HANDWRITING__)
            case MMI_IMC_STATE_HAND_WRITING_CAND:
            
                 mmi_imc_change_highlighted_candidate_from_candidate_box(index);
                 
                 mmi_imc_restart_timer(g_imc_pen_confirm_period, mmi_imc_pen_confirm_handwriting_selection, mmi_imc_pen_confirm_handwriting_selection);

                 break;
        #endif
                 
            default:
                
                break;
            }

            g_imc_pen.global_data_ptr->cand_select = index;
        }
        break;
        
    case MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_BOX:
        if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT)
        {   /* Select a candidate by pen */
			UI_string_type str = NULL;
			UI_character_type temp_cand_buff[MMI_IMC_MAX_CANDIDATE_BUFFSIZE];
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_state_enum state = mmi_imc_get_state();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
#if !defined(__NO_HANDWRITING__)
			if(g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN)
			{
				if (state == MMI_IMC_STATE_HAND_WRITING_CAND
					|| state == MMI_IMC_STATE_CAND_SELECTING
					|| state == MMI_IMC_STATE_ASSOC_SELECTING
					|| state == MMI_IMC_STATE_VK_CAND
					|| state == MMI_IMC_STATE_SMART_CANDIDATE
					|| state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
					|| state == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT
					|| state == MMI_IMC_STATE_VK_CAND_MULTITAP
					|| state == MMI_IMC_STATE_PREDICTING
					|| state == MMI_IMC_STATE_SPELL_INPUTING)
				{
            mmi_imc_select_candidate_from_candidate_box();
				}
			}
			else
#endif
			
			{
				str = mmi_imc_get_select_string_from_candidate_box();
				memset(temp_cand_buff, 0, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
				memcpy(&temp_cand_buff[0], str, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
#if defined (__MMI_CSTAR_PHRASE_INPUT__)
                if (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_WITH_INPUT || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT)
				{
				    mmi_imc_key_smart_phonetic_candidate_select();
				}
				else
                    mmi_imc_select_candidate_from_candidate_box();
#else
			    mmi_imc_select_candidate_from_candidate_box();
#endif
			}
			if(state == MMI_IMC_STATE_SMART_CANDIDATE
				|| state == MMI_IMC_STATE_VK_CAND)
			{
				#if defined(__MMI_IME_USER_DATABASE__)
			     if (*temp_cand_buff != MMI_IME_USER_DATABASE_NEW_WORD)
                #endif
                 {
                    //need to append space
                    if( (g_imc_pen.curr_mode_details->Lang_Special_Attrib & (IME_LANG_ATTR_ALPHABETIC | IME_LANG_ATTR_ENGLISH_ONLY)))
                    {       
                        #if defined(__MMI_IME_V3__)     
                        if(mmi_imm_is_auto_space_enabled())
			#endif
                        {
                            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                        }
                    }
                    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    if(!mmi_imm_is_auto_capitalization_valid() && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
                    #endif
                    {
                    #if defined(__MMI_VIRTUAL_KEYBOARD__)
                        if(g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                        {
                            g_imc_pen.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                            mmi_imc_pen_set_gui_state(IME_MODE_ATTR_LOWERCASE);
                            mmi_imc_change_input_mode_according_to_capital_state(g_imc_pen.global_data_ptr->capital_state);
                            mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK,0,0,NULL);
                        }
                    #endif
                    }
                }
            }
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_RIGHT_ARROW)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING)
            {
                mmi_imc_select_composition_from_composition_box();
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
            }

            mmi_imc_common_arrow_key_handler(MMI_IMC_KEY_PAGE_DOWN, KEY_EVENT_DOWN);
            mmi_imc_redraw_screen_by_state();
        }
		#if defined(__MMI_IME_CANDIDATE_GRID__)
		 else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_EXPAND)
        {
            g_imc_prev_state_grid = mmi_imc_get_state();
            mmi_imc_set_state_acc_to_mode();//new state for grid, where candidate box will convert to grid in place of vk,composition box will be horizontal from vertical
            g_imc_is_change_from_grid = MMI_TRUE;
			mmi_imc_get_candidates_word_engine_grid(g_imc_prev_state_grid);
			g_imc_enter_grid_state = MMI_TRUE;
			if(mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC)
			{
					
					if(g_imc_pen.global_data_ptr->cand_count != 1)
					{
						//cand count 1 means its spell word, so no need to copy
					S32 length;
					mmi_imc_message_struct  imc_msg;
					UI_buffer_type start_p = NULL, end_p = NULL;
					imc_msg.message_id = MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD;
					imc_msg.param_0 = (U32)&start_p;
					imc_msg.param_1 = (U32)&end_p;
					length = (S32)mmi_imc_send_message(&imc_msg);
					mmi_imc_key_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, (U32)g_imc_pen.global_data_ptr->cand_length, (U32)g_imc_pen.global_data_ptr->cand_buff);
			}
			}
			if(mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN && !(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY))
			{
				U8 index;
				index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX, 0, 0, NULL);
				mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, index, 0, NULL);
			}
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);// no vk show for this state
			mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
            mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_VK_ON);
			if(mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN && !(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY))
			{
				//U8 index;
				//index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX, 0, 0, NULL);
				//mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, index, 0, NULL);
				mmi_imc_update_smart_pinyin_composition();
				mmi_imc_change_highlighted_composition_from_composition_box(0);
			}
			g_imc_enter_grid_state= MMI_FALSE;
            mmi_imc_redraw_screen_by_state();
        }
		#endif
        else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_LEFT_ARROW)
        {   
            if (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING)
            {
                mmi_imc_select_composition_from_composition_box();
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
            }

            mmi_imc_common_arrow_key_handler(MMI_IMC_KEY_PAGE_UP, KEY_EVENT_DOWN);
            mmi_imc_redraw_screen_by_state();
        }
        break;
        
    case MMI_IMUI_MESSAGE_PEN_DOWN_IN_COMPOSITION_BOX:
    	if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT)
        {
            /* Providing the touch feedback for down event */
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                mmi_imc_pen_play_touch_feed_back();
#else
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
#endif

        }
    case MMI_IMUI_MESSAGE_PEN_MOVE_IN_COMPOSITION_BOX:

        mmi_imc_cancel_timer();
        
        if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT)
        {

        #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && (defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__))
            if (((mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_MULTITAP_PINYIN || 
                mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO) ||
                ((mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN || 
                mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_TR_BOPOMO) && 
                g_imc_pen.vk_style == MMI_VK_TYPE_QWERTY)) && 
				(mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND || mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING_GRID))
            {
                S32 i;
                UI_string_type cand_str;
                S32 count;
                UI_character_type comp_buff[MMI_IMC_MAX_COMPOSITION_BUFFSIZE];

                memcpy(&comp_buff[0], g_imc_pen.global_data_ptr->comp_buff, sizeof(UI_character_type) * MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
                
                cand_str = mmi_imc_get_candidate_by_index(&comp_buff[0], 0);

                if (cand_str)
                {
                    BOOL lcd_freeze = gdi_lcd_get_freeze();
					mmi_imc_gdi_lcd_freeze(MMI_TRUE); 

                    count =  mmi_ucs2strlen((const S8 *)cand_str);

                    for (i = 0; i < count; i++)
                    {
                       /* in case editor is already full we need not check further */ 
                       if(!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)cand_str[i], 0))
                          break;
                    }

                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                    mmi_imc_gdi_lcd_freeze(lcd_freeze);
                    mmi_imc_repaint_screen();
                }
            }
            else
        #endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */
            {
                index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX, 0, 0, NULL);
                
                switch(mmi_imc_get_state())
                {
                case MMI_IMC_STATE_SPELL_INPUTING:
                    
                     g_imc_pen.global_data_ptr->comp_select = index;
                     mmi_imc_change_highlighted_composition_from_composition_box(0);
                     mmi_imc_redraw_screen_by_state();
                     break;
                
                case MMI_IMC_STATE_CAND_SELECTING:
				#if (!defined(__MMI_IME_SMART_WITH_INPUT_AREA__) || (defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && defined(__MMI_CSTAR_PHRASE_INPUT__)))
                    mmi_imc_key_smart_phonetic_get_composition(0);
				#endif
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                    g_imc_pen.global_data_ptr->comp_page = g_imc_pen.global_data_ptr->old_comp_page;
                    mmi_imc_change_composition_box_page();
                    g_imc_pen.global_data_ptr->comp_select = index;
                    mmi_imc_change_highlighted_composition_from_composition_box(0);
                    break;

                default:
                    
                    break;
                }
            }

        }
        else
        {
            index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX, 0, 0, NULL);

            if (mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING)
            {
                #if (!defined(__MMI_IME_SMART_WITH_INPUT_AREA__) || (defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && defined(__MMI_CSTAR_PHRASE_INPUT__)))
                    mmi_imc_key_smart_phonetic_get_composition(0);
				#endif
                mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                g_imc_pen.global_data_ptr->comp_page = g_imc_pen.global_data_ptr->old_comp_page;
                mmi_imc_change_composition_box_page();
                g_imc_pen.global_data_ptr->comp_select = index;
                mmi_imc_change_highlighted_composition_from_composition_box(0);
            }
        }

        break;
        
    case MMI_IMUI_MESSAGE_PEN_UP_IN_COMPOSITION_BOX:
        if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT && mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING)
        {
			index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX, 0, 0, NULL);
			g_imc_pen.global_data_ptr->comp_select = index;
			mmi_imc_change_highlighted_composition_from_composition_box(0);
			mmi_imc_redraw_screen_by_state();
		

        }
        else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_RIGHT_ARROW)
        {   
			#if defined(__MMI_IME_SCROLLING_COMPOSITION__)
			if(mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN && !(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY))
			{
				if (mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID)
				{
					mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING_GRID);
				}
			}
			#endif
            mmi_imc_common_arrow_key_handler(MMI_IMC_KEY_PAGE_DOWN, KEY_EVENT_DOWN);
            mmi_imc_redraw_screen_by_state();
        }
        else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_LEFT_ARROW)
        {
			#if defined(__MMI_IME_SCROLLING_COMPOSITION__)
			if(mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN && !(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY))
			{
				if (mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID)
				{
					mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING_GRID);
				}
			}
			#endif
            mmi_imc_common_arrow_key_handler(MMI_IMC_KEY_PAGE_UP, KEY_EVENT_DOWN);
            mmi_imc_redraw_screen_by_state();
        }
        #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_CSTAR_PHRASE_INPUT__)
        else if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT)
		{
			mmi_imc_state_enum cur_state = mmi_imc_get_state();

			if(cur_state == MMI_IMC_STATE_SPELL_WITH_INPUT || \
				cur_state == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT || \
				cur_state == MMI_IMC_STATE_SPELL_INPUTING_GRID || \
				cur_state ==  MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID)
			{   
			
				index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX, 0, 0, NULL); //slanting
				mmi_imc_change_highlighted_composition_from_composition_box_cstar_style((U8)index);
			}
		}
        #endif
		#if defined(__MMI_IME_CANDIDATE_GRID__)
        else if(msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT && (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING_GRID || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID))
		{
			index = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX, 0, 0, NULL);
			g_imc_pen.global_data_ptr->comp_select = index;
            mmi_imc_change_highlighted_composition_from_composition_box(0);
			if(mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID)
			{
				mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING_GRID);
			}
            mmi_imc_redraw_screen_by_state();
		}
		#endif

        
        break;
        
    case MMI_IMUI_MESSAGE_PEN_DOWN_IN_INFORMATION_BAR:
    case MMI_IMUI_MESSAGE_PEN_DOWN_IN_IME_HINT:
       { BOOL lcd_freeze = gdi_lcd_get_freeze();
		mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
        old_mode = mmi_imm_get_curr_input_mode();
        mmi_imc_cancel_timer(); /* If need, we may treat with it by current state */

        /* In canceling timer, input mode may be changed by WCSS */
        if (old_mode != mmi_imm_get_curr_input_mode())
        {
            if (mmi_imm_set_current_input_mode(old_mode))
            {
                if (mmi_imc_change_input_mode(old_mode, 0))
                	mmi_imc_redraw_screen_by_state();
            }
        }

        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
    }
        break;
      
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    case MMI_IMUI_MESSAGE_PEN_DOWN_IN_VIRTUAL_KEYBOARD:
        #if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); 				
            if ((gui_virtual_keyboard_pen_enum)msg_ptr->param_0 == GUI_VKBD_PEN_CHAR_I)
            {
                ch = (UI_character_type)(((gui_pen_event_param_struct *)msg_ptr->param_1)->_u.i);
            }
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_DOWN, ch, (gui_virtual_keyboard_pen_enum)msg_ptr->param_0);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();

        }
        #else
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
            mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_DOWN, msg_ptr);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        #endif
        break;
        
    case MMI_IMUI_MESSAGE_PEN_UP_IN_VIRTUAL_KEYBOARD:
        #if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        {
            MMI_BOOL is_locked = (MMI_BOOL)!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_LOCK_GDI_FRAME_BUFFER_DISABLED, 0, 0);
            BOOL lcd_freeze = gdi_lcd_get_freeze();
            /* because vk would trigger screen change, hence, we could not lock frame buffer. We use lcd freeze instead. */
            if (is_locked)
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
            }
            if ((gui_virtual_keyboard_pen_enum)msg_ptr->param_0 == GUI_VKBD_PEN_CHAR_I)
            {
                ch = (UI_character_type)(((gui_pen_event_param_struct *)msg_ptr->param_1)->_u.i);
            }

            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_UP, ch, (gui_virtual_keyboard_pen_enum)msg_ptr->param_0);

            if (is_locked)
            {
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
        }
        #else
        {
            MMI_BOOL is_locked = (MMI_BOOL)!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_LOCK_GDI_FRAME_BUFFER_DISABLED, 0, 0);
            BOOL lcd_freeze = gdi_lcd_get_freeze();
            /* because vk would trigger screen change, hence, we could not lock frame buffer. We use lcd freeze instead. */
            if (is_locked)
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
            }

            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_UP, msg_ptr);

            if (is_locked)
            {
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
        }
        #endif
        break;

    case MMI_IMUI_MESSAGE_PEN_REPEAT_IN_VIRTUAL_KEYBOARD:
        #if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			gui_virtual_keyboard_pen_enum vk_event = (gui_virtual_keyboard_pen_enum)msg_ptr->param_0;
            if(!(vk_event == GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE || vk_event == GUI_VKBD_PEN_BAKSPACE))
			{
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
			}
            if ((gui_virtual_keyboard_pen_enum)msg_ptr->param_0 == GUI_VKBD_PEN_CHAR_I)
            {
                ch = (UI_character_type)(((gui_pen_event_param_struct *)msg_ptr->param_1)->_u.i);
            }
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_REPEAT, ch, (gui_virtual_keyboard_pen_enum)msg_ptr->param_0);
			if(!(vk_event == GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE || vk_event == GUI_VKBD_PEN_BAKSPACE))
			{
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        }
        #else
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();
			gui_virtual_keyboard_pen_enum vk_event = (gui_virtual_keyboard_pen_enum)msg_ptr->param_0;
            if(!(vk_event == GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE || vk_event == GUI_VKBD_PEN_BAKSPACE))
			{
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
			}
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_REPEAT, msg_ptr);
			if(!(vk_event == GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE || vk_event == GUI_VKBD_PEN_BAKSPACE))
			{
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        }
        #endif
        break;
    case MMI_IMUI_MESSAGE_PEN_MOVE_IN_VIRTUAL_KEYBOARD:
        #if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();

            mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
            if ((gui_virtual_keyboard_pen_enum)msg_ptr->param_0 == GUI_VKBD_PEN_CHAR_I)
            {
                ch = (UI_character_type)(((gui_pen_event_param_struct *)msg_ptr->param_1)->_u.i);
            }
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_MOVE, ch, (gui_virtual_keyboard_pen_enum)msg_ptr->param_0);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        #else
            {
            BOOL lcd_freeze = gdi_lcd_get_freeze();

            mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_MOVE, msg_ptr);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            }
        #endif
        break;
    case MMI_IMUI_MESSAGE_PEN_ABORT_IN_VIRTUAL_KEYBOARD:
        #if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();

            mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
            if ((gui_virtual_keyboard_pen_enum)msg_ptr->param_0 == GUI_VKBD_PEN_CHAR_I)
            {
                ch = (UI_character_type)(((gui_pen_event_param_struct *)msg_ptr->param_1)->_u.i);
            }
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_ABORT, ch, (gui_virtual_keyboard_pen_enum)msg_ptr->param_0);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        #else
            {
            BOOL lcd_freeze = gdi_lcd_get_freeze();

            mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_ABORT, msg_ptr);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            }
        #endif
        break;
    case MMI_IMUI_MESSAGE_PEN_LONGTAP_IN_VIRTUAL_KEYBOARD:
        #if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        {
            BOOL lcd_freeze = gdi_lcd_get_freeze();

            mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
            if ((gui_virtual_keyboard_pen_enum)msg_ptr->param_0 == GUI_VKBD_PEN_CHAR_I)
            {
                ch = (UI_character_type)(((gui_pen_event_param_struct *)msg_ptr->param_1)->_u.i);
            }
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_LONG_TAP, ch, (gui_virtual_keyboard_pen_enum)msg_ptr->param_0);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        #else
            {
            BOOL lcd_freeze = gdi_lcd_get_freeze();

            mmi_imc_gdi_lcd_freeze(MMI_TRUE);    
            mmi_imc_pen_vk_event_handler(MMI_PEN_EVENT_LONG_TAP, msg_ptr);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            }
        #endif
        break;
#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */
    case MMI_IMUI_MESSAGE_PEN_UP_IN_INFORMATION_BAR:
	case MMI_IMUI_MESSAGE_PEN_UP_IN_IME_HINT:	
    #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        if (mmi_imm_get_input_mode_num_in_current_writing_language() > 1 ||
			(mmi_imc_pen_send_imc_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0) &&
             mmi_imm_get_current_allowed_input_mode_num() > 1))
    #else
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    #endif
        {
            if (mmi_imc_change_input_mode(mmi_imm_get_next_mode(), 0))
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
			#if defined __MMI_XT9__
            if(mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
			{
				mmi_imc_key_smart_alphabetic_confirm_candidate();
			}
            #endif
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
        break;
#ifdef __MMI_CSTAR_PHRASE_INPUT__
    case MMI_IMUI_MESSAGE_PEN_UP_IN_INPUT_BOX:
        {
            if (msg_ptr->param_0 == MMI_IMUI_SELECTION_AREA_PEN_TEXT && 
                (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_WITH_INPUT || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT)
                )
            {
                mmi_imc_commit_input_box_content();
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }
        }
        break;
#endif        

    default:
        break;
    }
}

#if defined(__MMI_VIRTUAL_KEYBOARD__)

#if  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) || (defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) && defined(__MMI_IME_FTE_ENHANCE__))



#if defined(__MMI_MAINLCD_240X320__) 
#define IMC_PEN_UI_POPUP_WIDTH 180
#define IMC_PEN_UI_POPUP_CONTENT_TOP_GAP 13
#define IMC_PEN_UI_POPUP_CONTENT_BUTTOM_GAP 13
#define IMC_PEN_UI_POPUP_BORDER_SIZE 10
#elif defined(__MMI_MAINLCD_320X240__)
#define IMC_PEN_UI_POPUP_WIDTH 200
#define IMC_PEN_UI_POPUP_CONTENT_TOP_GAP 10
#define IMC_PEN_UI_POPUP_CONTENT_BUTTOM_GAP 10
#define IMC_PEN_UI_POPUP_BORDER_SIZE 10
#elif defined(__MMI_MAINLCD_240X400__)
#define IMC_PEN_UI_POPUP_WIDTH 180
#define IMC_PEN_UI_POPUP_CONTENT_TOP_GAP 15
#define IMC_PEN_UI_POPUP_CONTENT_BUTTOM_GAP 15
#define IMC_PEN_UI_POPUP_BORDER_SIZE 15
#elif defined(__MMI_MAINLCD_320X480__)
#define IMC_PEN_UI_POPUP_WIDTH 250
#define IMC_PEN_UI_POPUP_CONTENT_TOP_GAP 15
#define IMC_PEN_UI_POPUP_CONTENT_BUTTOM_GAP 15
#define IMC_PEN_UI_POPUP_BORDER_SIZE 15
#elif defined(__MMI_MAINLCD_480X800__)
#define IMC_PEN_UI_POPUP_WIDTH 320
#define IMC_PEN_UI_POPUP_CONTENT_TOP_GAP 20
#define IMC_PEN_UI_POPUP_CONTENT_BUTTOM_GAP 20
#define IMC_PEN_UI_POPUP_BORDER_SIZE 20
#else
#error "FTE is not supported in this resolution!"
#endif

extern U8 get_menu_item_height(void);
extern fixed_icontext_menuitem MMI_fixed_icontext_menuitem;
extern fixed_list_menu MMI_fixed_list_menu;


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_vk_area_rect
 * DESCRIPTION
 *output VK's position and width height
 * PARAMETERS
 *[out] x
 *[out] y
 *[out] width
 *[out] height
 * RETURNS
 ****************************************************************************/
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
void mmi_imc_pen_get_vk_area_rect(S32* x,S32* y,S32* width,S32* height,MMI_BOOL is_large)
{

    mmi_imui_message_struct imui_msg;
    gui_virtual_keyboard_rect_struct rect;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&rect,0,sizeof(rect));
    imui_msg.message_id = MMI_IMUI_MESSAGE_GET_VK_AREA_RECT;
    imui_msg.param_0 = (U32) (&rect);
    imui_msg.param_1 = is_large;
    
    mmi_imui_send_message(&imui_msg, NULL);

    *x = rect.x;
    *y = rect.y;
    *width = rect.width;
    *height = rect.height;

}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_popup_list_pen_event_down
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_imc_pen_popup_list_pen_event_down(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_list_pen_enum menu_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_fixed_list_menu_translate_pen_event(
        &MMI_fixed_list_menu,
        MMI_PEN_EVENT_DOWN,
        pos.x,
        pos.y,
        &menu_event);
    if (ret)
    {
        wgui_fixed_list_show_icontext_menu();
    }
    else
    {
        g_pen_down_outside_the_list = MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_popup_list_pen_event_up
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_imc_pen_popup_list_pen_event_up(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_list_pen_enum menu_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_down_outside_the_list )
    {
        if (!PEN_CHECK_BOUND(pos.x, pos.y, MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.width, MMI_fixed_list_menu.height))
        {
            g_pen_popup_list_cancel_callback();
        }

        g_pen_down_outside_the_list = MMI_FALSE;

    }
    else
    {
        ret = gui_fixed_list_menu_translate_pen_event(
            &MMI_fixed_list_menu,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &menu_event);
        if (ret)
        {
            wgui_fixed_list_show_icontext_menu();
            g_pen_popup_list_confirm_callback();
        }
        else
        {
            g_pen_popup_list_cancel_callback();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_popup_list_pen_event_move
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_imc_pen_popup_list_pen_event_move(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_list_pen_enum menu_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_down_outside_the_list )
    {
        /* do nothing */
    }
    else
    {
        ret = gui_fixed_list_menu_translate_pen_event(
            &MMI_fixed_list_menu,
            MMI_PEN_EVENT_MOVE,
            pos.x,
            pos.y,
            &menu_event);
        if (ret)
        {
            wgui_fixed_list_show_icontext_menu();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_popup_list_pen_event_longtap
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_imc_pen_popup_list_pen_event_longtap(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_list_pen_enum menu_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_down_outside_the_list )
    {
        /* do nothing */
    }
    else
    {
        ret = gui_fixed_list_menu_translate_pen_event(
            &MMI_fixed_list_menu,
            MMI_PEN_EVENT_LONG_TAP,
            pos.x,
            pos.y,
            &menu_event);
        if (ret)
        {
            wgui_fixed_list_show_icontext_menu();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_close_popup_list
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_imc_pen_close_popup_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL freeze;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    freeze = gdi_lcd_get_freeze();
    mmi_imc_gdi_lcd_freeze(MMI_FALSE);
    set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_LEFT_SOFTKEY);
    set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_RIGHT_SOFTKEY);
    enable_softkey_background();
    reset_fixed_list();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
    g_pen_down_outside_the_list = MMI_FALSE;
    g_pen_popup_list_confirm_callback = NULL;
    g_pen_popup_list_cancel_callback = NULL;
    mmi_imc_gdi_lcd_freeze(freeze);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_hide_popup_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_imc_pen_hide_popup_menu(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    
    gui_draw_filled_area(
        MMI_fixed_list_menu.x - IMC_PEN_UI_POPUP_BORDER_SIZE, 
        MMI_fixed_list_menu.y - IMC_PEN_UI_POPUP_CONTENT_TOP_GAP, 
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1 + IMC_PEN_UI_POPUP_BORDER_SIZE, 
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1 + IMC_PEN_UI_POPUP_CONTENT_BUTTOM_GAP,
        current_MMI_theme->cascade_menu_background_filler);
    gdi_layer_pop_clip();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_show_popup_list_int
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
void mmi_imc_pen_show_popup_list_int(
                    S32 x, 
                    S32 y, 
                    S32 number_of_items,
                    U16 *list_of_items,
                    S32 highlighted_item,
                    FuncPtr confirm_callback, 
                    FuncPtr cancel_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate_enum degree;
    #endif
    U16 scr_id = mmi_ime_gen_editor_common_scr_id(SCR_CONFIG_SMART_INPUT_METHOD);
    BOOL freeze;
    S32 menu_height;
    S32 menu_x = 0 ,menu_y = 0 ;
    S32 img_width, img_height;
    mmi_id g_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    freeze = gdi_lcd_get_freeze();
    mmi_imc_gdi_lcd_freeze(MMI_FALSE);

   /* To make this screen a part of screen group*/
	if(vm_frm_is_active())//in mre editor, screen should be in root group due to mre engine limitation
	{
		//In mre editor
		g_id = GRP_ID_ROOT;
	}
	else
	{
    g_id = mmi_frm_group_get_active_id();
	}
    if (g_id == GRP_ID_INVALID)
    {
    #ifdef __MMI_FRM_HISTORY__
	    EntryNewScreen(
	    	SCR_ID_INPUT_METHOD_VK_POPUP_LIST, 
	    	mmi_imc_pen_close_popup_list, 
	    	NULL, 
	    	NULL);
    #endif
    }
    else
    {
		//scrn_enter always reset the layer size, so we have to save it and then reset it
		#ifdef __MMI_SCREEN_ROTATE__
		degree = mmi_frm_get_screen_rotate();
        #endif
        mmi_frm_scrn_enter(
        	g_id,
        	SCR_ID_INPUT_METHOD_VK_POPUP_LIST,
        	mmi_imc_pen_close_popup_list,
        	(FuncPtr)mmi_imc_pen_show_popup_list_int,
        	MMI_FRM_FG_ONLY_SCRN);
        set_small_screen();
		#ifdef __MMI_SCREEN_ROTATE__
        mmi_frm_screen_rotate(degree);
        #endif
    }

    /* disable softkey */
    disable_softkey_background();
    set_softkey_flags_on(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_LEFT_SOFTKEY);
    set_softkey_flags_on(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_RIGHT_SOFTKEY);
    set_softkey_flags_on(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_CENTER_SOFTKEY);

    create_fixed_icontext_list_menuitems(1, 1);
    associate_fixed_icontext_list_list();

    /* setup theme */
    MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->cascade_menu_normal_text_color;
    MMI_fixed_icontext_list_menuitem.disabled_text_colors[0] = *current_MMI_theme->cascade_menu_disabled_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->cascade_menu_selected_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->cascade_menu_selected_text_color;
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

    wgui_fixed_list_register_hide_function(mmi_imc_pen_hide_popup_menu);

    register_fixed_list_keys();
    resize_fixed_icontext_list_menuitems(IMC_PEN_UI_POPUP_WIDTH - 1, MMI_MENUITEM_HEIGHT);
    register_fixed_list_highlight_handler(standard_list_highlight_handler);


    for (i = 0; i < number_of_items; i++)
    {       
        fixed_icontext_list_item_insert(i);

        if (i == highlighted_item)
        {
            add_fixed_icontext_list_item_text(i, 0, get_string(list_of_items[i]));
        #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
            add_fixed_icontext_list_item_icon(i, 0, get_image(0));
        #else
            add_fixed_icontext_list_item_icon(i, 0, get_image(IMG_ID_VKBD_ACTIVATE_ITEM));
        #endif
        }
        else
        {
            add_fixed_icontext_list_item_text(i, 0, get_string(list_of_items[i]));
        }
    }
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    //gui_measure_image(get_image(0), &img_width, &img_height); no need to call it for NULL image it will make width/height junk
	img_width = 0 ;
	img_height = 0 ;
#else
    gui_measure_image(get_image(IMG_ID_VKBD_ACTIVATE_ITEM), &img_width, &img_height);
#endif
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
/* the text width needs to be reduced to make sure it does not overlap the borders*/
    set_fixed_icontext_list_text_coordinates(0, IMC_PEN_UI_POPUP_BORDER_SIZE + img_width, 0, IMC_PEN_UI_POPUP_WIDTH - img_width - IMC_PEN_UI_POPUP_BORDER_SIZE - 5, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_icon_coordinates(0, IMC_PEN_UI_POPUP_BORDER_SIZE, 0, img_width, img_height);

    menu_height = number_of_items * get_menu_item_height() ;

    MMI_fixed_list_menu.highlighted_item = highlighted_item;

    /* change the fixed menu top offset */
    MMI_fixed_list_menu.top = IMC_PEN_UI_POPUP_CONTENT_TOP_GAP;   
    move_fixed_list(menu_x, menu_y);
    resize_fixed_list(IMC_PEN_UI_POPUP_WIDTH, menu_height); 
    fixed_list_goto_item_no_redraw(highlighted_item);
    menu_x = ((UI_device_width - IMC_PEN_UI_POPUP_WIDTH) >>1);
    menu_y = y - menu_height - IMC_PEN_UI_POPUP_CONTENT_BUTTOM_GAP;
    
    gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, MMI_BG_GREYSCALE_VALUE, MMI_BG_GREYSCALE_BLACK_VALUE);

    gui_draw_filled_area(
        menu_x - IMC_PEN_UI_POPUP_BORDER_SIZE, 
        menu_y - IMC_PEN_UI_POPUP_CONTENT_TOP_GAP, 
        menu_x + IMC_PEN_UI_POPUP_WIDTH + IMC_PEN_UI_POPUP_BORDER_SIZE, 
        menu_y + menu_height + IMC_PEN_UI_POPUP_CONTENT_BUTTOM_GAP,
        current_MMI_theme->cascade_menu_background_filler);


    move_fixed_list(menu_x, menu_y);
    wgui_fixed_list_show_icontext_menu();

    mmi_imc_gdi_lcd_freeze(freeze);
    mmi_imc_repaint_screen();


    g_pen_down_outside_the_list = MMI_FALSE;
    g_pen_popup_list_confirm_callback = confirm_callback;
    g_pen_popup_list_cancel_callback = cancel_callback;

    mmi_pen_register_down_handler(mmi_imc_pen_popup_list_pen_event_down);    
    mmi_pen_register_up_handler(mmi_imc_pen_popup_list_pen_event_up);    
    mmi_pen_register_move_handler(mmi_imc_pen_popup_list_pen_event_move);    
    mmi_pen_register_long_tap_handler(mmi_imc_pen_popup_list_pen_event_longtap);    
    
    /* Since we are setting the LSK and RSK function for 
     * pop-up, so there might be scenarios when we need to set
     * some functions to LSK and RSK even when the text on the
     * RSK or LSK is NULL, so we need to use SetKeyHandler() 
     * instead of SetLeftSoftkeyFunction/SetRightSoftkeyFunction
     */
    /*SetLeftSoftkeyFunction(confirm_callback, KEY_EVENT_UP);
    SetRightSoftkeyFunction(cancel_callback, KEY_EVENT_UP);*/
    SetKeyHandler(confirm_callback, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(cancel_callback, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(cancel_callback, KEY_BACK, KEY_EVENT_UP);
	SetKeyHandler(confirm_callback, KEY_CSK, KEY_EVENT_UP);
}





#if !defined(__NO_HANDWRITING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_enable_single_block_hw
 * DESCRIPTION
 *  To enable single block handwriting 
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
void mmi_imc_pen_vk_enable_single_block_hw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_hand_writing_category_info_struct_p hw_info = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_vk_enable_single_block_hw called ");
    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING && g_imc_pen_hw_enable_from_grid)
	{
		//do nothing
	}
	else
	#endif
	{
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	}
	if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK)
    {
#if !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
		hw_info = mmi_imm_get_hand_writing_category(g_imc_pen.curr_mode_details->lang_id);  
		mmi_imc_pen_send_ui_message(MMI_IMUI_SET_HW_EXTRA_BLOCK_INDICATOR, (U32)hw_info->extra_block_ind_id, 0, NULL);
#endif
        if (mmi_imc_get_single_block_handwriting_state() == MMI_FALSE)
        {
            mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
			
            mmi_imc_pen_start_singleblock_handwriting();
#if defined(__IMEHW_DCM_SUPPORT__)
#if defined(__MMI_GUOBI_HW__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
            if(!DCM_Isloaded(DYNAMIC_CODE_COMPRESS_GUOBIHW))
            {
                DCM_Load(DYNAMIC_CODE_COMPRESS_GUOBIHW, NULL, NULL);
                MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IMC_PEN_DCM_LOAD_HW);
            }
#endif
#endif//#if defined(__IMEHW_DCM_SUPPORT__)

            hw_type = (mmi_imc_pen_handwriting_type_enum)IME_HAND_WRITING_GET_HW_TYPE(g_imc_pen.curr_mode_details->Handwriting_Attrib);
            if(mmi_ime_hand_writing_hw_type_query(hw_type))
            {
                mmi_ime_hand_writing_initialize(hw_type);
            }
            mmi_imc_pen_start_capture_strokes(
                MMI_IMC_PEN_STROKE_BUFFER_SIZE,
                g_imc_pen_stroke_buffer,
                2,
                g_imc_stroke_area,
                NULL);
            mmi_imc_pen_begin_strokes_of_character();
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_enable_multiblock_handwriting
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_start_singleblock_handwriting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK)
    {
        if (mmi_imc_get_single_block_handwriting_state() == MMI_FALSE)
        {
            mmi_imc_pen_init_handwriting_area();            
            mmi_imc_config_single_block_handwriting_state(MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_disable_multiblock_handwriting
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_stop_singleblock_handwriting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK)
    {
        if (mmi_imc_get_single_block_handwriting_state() == MMI_TRUE)
        {
            mmi_imc_pen_stop_capture_strokes();

            mmi_imc_config_single_block_handwriting_state(MMI_FALSE);
            mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);                
        }
    }
}
#endif /* !defined(__NO_HANDWRITING__) */

//#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_back_to_lang
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_back_to_lang(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imc_pen.is_symbol_lock)
    {
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1 ||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_2 ||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_3 ||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_4 ||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE ||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_TWO||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1 ||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_2 ||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_3 ||
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4)
        {
                switch (g_imc_pen.vk_type_before_symbol)
                {
                        #if defined(__MMI_LANG_BENGALI__)
                        case GUI_VIRTUAL_KEYBOARD_BENGALI_LOWERCASE:
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_BENGALI;
                            break;
                        #endif
                        #if defined(__MMI_LANG_HINDI__)
                        case GUI_VIRTUAL_KEYBOARD_HINDI_LOWERCASE:
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_HINDI;
                            break;
                        #endif
                        #if defined(__MMI_LANG_THAI__)
                        case GUI_VIRTUAL_KEYBOARD_THAI_LOWERCASE:
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_THAI;
                            break;
                        #endif
                }

             if ( (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_MAX_LANG) &&
                 (g_imc_pen.vk_type_before_num != GUI_VIRTUAL_KEYBOARD_MAX_LANG))
            {
                 mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_num, MMI_FALSE);
                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG; 
            }
            else
            {
                mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);
                g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG; 
            }

            /* For performance, we assume the symbol vk has the same height as its lang vk.
                 But t9 smart bopomo keypad is an exception. We have to process it.
            */
        #if defined(__MMI_T9_DEFAULT_KEY_DEFINITION__)
            if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO)
            {
                mmi_imc_redraw_screen_by_state();
            }
            else
        #endif
            {
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
            }
            ret = MMI_TRUE;
        }
    }
    return ret;
}
//#endif /* defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_space
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_space(mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_event == MMI_PEN_EVENT_UP)
    {
        switch (mmi_imc_get_state())
        {

            case MMI_IMC_STATE_VK_CAND_MULTITAP:
                mmi_imc_delete_timer();
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_SPACE, 0, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
               break;

            /* to insert the space directly */
            case MMI_IMC_STATE_INITIAL:
            case MMI_IMC_STATE_ASSOC_SELECTING:
            case MMI_IMC_STATE_CAND_SELECTING:
            case MMI_IMC_STATE_VK_CAND:
				mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_SPACE, 0, 0);
                break;
            /* confirm the highlight candidate and insert space */    
            case MMI_IMC_STATE_SMART_CANDIDATE:
            case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
            case MMI_IMC_STATE_MULTITAP:
				mmi_imc_select_candidate_from_candidate_box(); 
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_SPACE, 0, 0);                        
                break;
            /* confirm the candidate, set to initial and insert space */
            case MMI_IMC_STATE_HAND_WRITING:
            case MMI_IMC_STATE_HAND_WRITING_CAND:
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_SPACE, 0, 0);                        
                break;
            /* do nothing */
            case MMI_IMC_STATE_NEW_WORD_INITIAL: /* space is an invalid input */
            case MMI_IMC_STATE_NEW_WORD_MULTITAP: /* space is an invalid input */
            case MMI_IMC_STATE_SPELL_INPUTING:
            case MMI_IMC_STATE_SPELL_MULTITAP:
                break;
            /* not final case */
            case MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING:
            case MMI_IMC_STATE_PREDICTING:
            case MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP:
            case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT:
            case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN:
            case MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS:
            case MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU:
            case MMI_IMC_STATE_WORD_HIGHLIGHTED:

                break;        
            /* should not happend when vk on */
            case MMI_IMC_STATE_PRE_SMART_CANDIDATE: /* cstar style is not supported in touch */
            case MMI_IMC_STATE_INPUT:  /* state for cstar input */
            case MMI_IMC_STATE_SPELL_WITH_INPUT: /* for cstar input */
            case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT: /* for cstar input */
            case MMI_IMC_STATE_PRE_ASSOC_SELECTING: /* for cstar input */
                MMI_ASSERT(0);
                break;
            /* all state has been listed. If a new state is added, the behavior should be defined */    
            default:
                MMI_DBG_ASSERT(0);
                break;
                
        }
        
    }
    else
    {
        /* currently, we don't support space in other pen event case. */
        return MMI_FALSE;
    }
    return ret;
}



#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
MMI_BOOL mmi_imc_pen_vk_event_change_mode(mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum input_mode;
    MMI_BOOL is_hand_writing_vk_need_to_draw = MMI_FALSE;
    
    if (pen_event == MMI_PEN_EVENT_LONG_TAP)
    {
#if defined(__COSMOS_MMI_PACKAGE__)
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
#else
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
#endif

        mmi_imc_show_inputmode_list();
    }

    if (pen_event == MMI_PEN_EVENT_UP && !g_imc_pen.vk_longtap)
    {    
        if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND)
        {
           mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_FALSE, 0); 
        }
        input_mode = mmi_imm_get_next_writing_mode();
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        if(mmi_imc_pen_is_handwriting_vk())
        {
            g_imc_pen.vk_style = g_imc_pen.vk_style_before_handwriting;
            switch(g_imc_pen.vk_style)
                {
                    case MMI_VK_TYPE_QWERTY:
						g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
						g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
            mmi_imm_config_keyboard_type(IMM_KEYPAD_QWERTY);
                        break;
                    case MMI_VK_TYPE_ALPHANUMERIC:
						g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
						g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
                        mmi_imm_config_keyboard_type(IMM_KEYPAD_ALPHANUMERIC);
                        break;
                }
            if(input_mode == g_imc_pen.curr_mode_details->imm_mode_id)
                is_hand_writing_vk_need_to_draw = MMI_TRUE;
        }
        else
        {
            g_imc_pen.vk_style_before_handwriting = g_imc_pen.vk_style;
        }
    
        #if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
        if(input_mode == IMM_INPUT_MODE_NONE)
        {
            if(mmi_imm_handwriting_is_follow_vk())
            {
                input_mode = g_imc_pen.curr_mode_details->imm_mode_id;
            }
            else
            {
                input_mode = mmi_imm_handwriting_get_current_mode();//IMM_INPUT_MODE_SM_PINYIN;///TODO: should to defined a default input mode for handwriting
            }
			/*
            if(input_mode == g_imc_pen.curr_mode_details->imm_mode_id)
            {
                is_hand_writing_vk_need_to_draw = MMI_TRUE;
            }
			*/
			is_hand_writing_vk_need_to_draw = MMI_TRUE;  //always need to draw handwriting vk here
            mmi_imm_set_current_input_mode(input_mode);
            mmi_imc_change_input_mode(input_mode, 0);
            g_imc_pen.vk_style = MMI_VK_TYPE_HW;
            mmi_imm_config_keyboard_type(IMM_KEYPAD_HANDWRITING);
        }
        #endif
        if(is_hand_writing_vk_need_to_draw && input_mode != IMM_INPUT_MODE_NONE)
		    {
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
						if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
            {
	             mmi_imc_pen_show_handwriting_vk();
		        }
            else
#endif
            {
                const sIMEModeDetails * mode_detail_ptr;
                mode_detail_ptr = mmi_imm_get_input_mode_array_item(input_mode);

                mmi_imc_pen_setup_virtual_keyboard(mode_detail_ptr);
                #if !defined(__NO_HANDWRITING__) 
                        mmi_imc_pen_stop_singleblock_handwriting();
                    #endif
            }
		    }
        else
        {
			#if !defined(__NO_HANDWRITING__) 
			if(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY)
			{
							mmi_imc_pen_stop_singleblock_handwriting();
			}
			#endif
            mmi_imc_change_input_mode(input_mode, 0);
        }
    }
	//mmi_imm_set_curr_writing_lang_by_curr_mode();
     return MMI_TRUE; 
}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_event_change_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_event_change_mode(mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0, i = 0, highlight = 0;	
    mmi_imm_input_mode_enum mode;
    imc_pen_evt_entry_input_method evt;
    mmi_imc_message_struct imc_msg;
    U16 nNumofItem = 0;
    UI_string_type langList[IME_WRITING_LANG_TOTAL];
	#if !(defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__))
    U16 modeStrIdList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    mmi_imm_input_mode_enum modeList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
    if (pen_event == MMI_PEN_EVENT_LONG_TAP)
    {
            mmi_imc_show_wlang_list();
        }
                #endif
            
    if (pen_event == MMI_PEN_EVENT_UP)
    {    
        mmi_imc_show_inputmode_list();
            }

     return MMI_TRUE; 
}
#endif


//#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)        
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_alphanumeric_event_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_vk_alphanumeric_event_handler(mmi_pen_event_type_enum pen_event, gui_virtual_keyboard_pen_enum vk_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_val = MMI_TRUE;
    mmi_imc_state_enum prev_state = mmi_imc_get_state();
    static MMI_BOOL delete_key_down_initial_state = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (mmi_imc_pen_vk_is_dialer_event(vk_event))
    {
        return mmi_imc_pen_vk_alphanumeric_dialer_event_handler(pen_event, vk_event);
    }

    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
				#if !defined(__MMI_IME_V3__)
                if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET ||
                    MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE)
                {
                    ret_val = MMI_FALSE;
                    break;
                }
				#endif
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
                if (!(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_LANG_NUMBER && g_imc_pen.vk_type_before_num!= GUI_VIRTUAL_KEYBOARD_MAX_LANG))
                {
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);

                    mmi_imc_config_clean_force_ui_style_valitation(MMI_FALSE);
                    mmi_imc_key_group_key_down_int((U16)(vk_event - GUI_VKBD_PEN_ALPHANUMERIC_KEY_0 + KEY_0), KEY_EVENT_DOWN);
                    mmi_imc_config_clean_force_ui_style_valitation(MMI_TRUE);
                }
                    ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            #endif
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                mmi_imc_key_group_key_down_int(KEY_STAR, KEY_EVENT_DOWN);
                ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            #endif
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                mmi_imc_key_group_key_down_int(KEY_POUND, KEY_EVENT_DOWN);
                ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
                if (mmi_imc_get_state() != MMI_IMC_STATE_INITIAL)
                {
                    delete_key_down_initial_state = MMI_TRUE;
                    mmi_imc_key_group_key_down_int(KEY_RSK, KEY_EVENT_DOWN);
                }
                else
                {
                    delete_key_down_initial_state = MMI_FALSE;
                }
                ret_val = MMI_FALSE;
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
                
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_SYMBPICKER:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
                switch (mmi_imc_get_state())
                {
                    case MMI_IMC_STATE_MULTITAP:
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
                        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                }
                break;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_UP)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
				#if !defined(__MMI_IME_V3__)
                if ((MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET || 
                      MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE) && 
                     !g_imc_pen.vk_longtap)
                {                    
                    if(mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
                    {
                        mmi_imc_select_candidate_from_candidate_box();
                    }
                    mmi_imc_pen_vk_insert_char(0x002e);                    
                    break;
                }
				#endif
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
                if (!(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_LANG_NUMBER && g_imc_pen.vk_type_before_num!= GUI_VIRTUAL_KEYBOARD_MAX_LANG))
                {

                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_up_int((U16)(vk_event - GUI_VKBD_PEN_ALPHANUMERIC_KEY_0 + KEY_0), KEY_EVENT_UP);
                    mmi_imc_pen_change_vk_by_capital_state();
                     //mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));	 
                }
                else
                {
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)((vk_event - GUI_VKBD_PEN_ALPHANUMERIC_KEY_0) + '0'), 0);
                }
                    ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:
                switch (mmi_imc_get_state())
                {
                    case MMI_IMC_STATE_SMART_CANDIDATE:
                        {
                            
                        #if defined(__MMI_IME_USER_DATABASE__)
                            UI_string_type str = NULL;
                            str = mmi_imc_get_candidate_by_index(g_imc_pen.global_data_ptr->cand_buff, g_imc_pen.global_data_ptr->cand_select);
                            if (*str == MMI_IME_USER_DATABASE_NEW_WORD)
                            {
                                /* don't select candidate */
                            }
                            else
                        #endif        
                            {
                                mmi_imc_select_candidate_from_candidate_box();
                            }
                        }
                        break;
                }
                ret_val = mmi_imc_pen_vk_event_change_mode(pen_event);
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_SYMBPICKER:
                switch (mmi_imc_get_state())
                {
                    case MMI_IMC_STATE_SMART_CANDIDATE:
                        {
                            
                        #if defined(__MMI_IME_USER_DATABASE__)
                            UI_string_type str = NULL;
                            str = mmi_imc_get_candidate_by_index(g_imc_pen.global_data_ptr->cand_buff, g_imc_pen.global_data_ptr->cand_select);
                            if (*str == MMI_IME_USER_DATABASE_NEW_WORD)
                            {
                                /* don't select candidate */
                            }
                            else
                        #endif        
                            {
                                mmi_imc_select_candidate_from_candidate_box();
                            }
                        }
                        break;
                }
                mmi_imc_pen_process_before_changing_input_mode();
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
				if (!mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG))
				{
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
				}
           #if (defined(__MMI_T9_SM_CHINESE__)||defined(__MMI_ZI_SM_CHINESE__)||defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)||defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__))    
                if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_PINYIN ||
                    MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO ||
                    MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TR_STROKE ||
                    MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_SM_STROKE)
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1, MMI_FALSE);
                }
		else if(g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_PINYIN ||
                        g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_BOPOMO ||
                        g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_TR_STROKE ||
                        g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_SM_STROKE)
		{
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1, MMI_FALSE);
		}
                #if defined(__MMI_LANG_SM_CHINESE__)
                else if ((mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_QUICK_SEARCH_PINYIN) &&
                         (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ENGLISH))
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1, MMI_FALSE);
                }
                #endif /* defined(__MMI_LANG_SM_CHINESE__) */
                else
            #endif     
                if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL))
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE, MMI_FALSE);
                }
                else
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1, MMI_FALSE);
                }
                g_imc_pen.is_symbol_lock = MMI_FALSE;
                mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK, 0, 0, NULL);
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            #endif
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                mmi_imc_key_group_key_up_int(KEY_STAR, KEY_EVENT_UP);
                ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            #endif
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                mmi_imc_key_group_key_up_int(KEY_POUND, KEY_EVENT_UP);
                ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
                if (delete_key_down_initial_state)
                {
                    mmi_imc_pen_change_vk_by_capital_state();
                    mmi_imc_key_group_key_up_int(KEY_RSK, KEY_EVENT_UP);
                    //ret_val = MMI_FALSE;
                }
                else
                {
                    mmi_imc_pen_vk_backspace(pen_event);
                }
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
				{
/*the below check has been introduced to stop from getting change in different case*/
					mmi_ime_word_capital_state_enum temp_capital_state = g_imc_pen.global_data_ptr->capital_state;

                switch (mmi_imc_get_state())
                {
                    case MMI_IMC_STATE_SMART_CANDIDATE:
                        {
                            
                        #if defined(__MMI_IME_USER_DATABASE__)
                            UI_string_type str = NULL;
                            str = mmi_imc_get_candidate_by_index(g_imc_pen.global_data_ptr->cand_buff, g_imc_pen.global_data_ptr->cand_select);
                            if (*str == MMI_IME_USER_DATABASE_NEW_WORD)
                            {
                                /* don't select candidate */
                            }
                            else
                        #endif        
                            {
                                mmi_imc_select_candidate_from_candidate_box();
                            }
                        }
                        break;
                }
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
/*the below check has been introduced to stop from getting change in different case*/
					if (temp_capital_state == g_imc_pen.global_data_ptr->capital_state)
					{
						mmi_imc_pen_vk_caps_lock(pen_event);
					}
					
				}
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
                mmi_imc_pen_process_before_changing_input_mode();
				if (!mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG))
				{
                g_imc_pen.vk_type_before_num = MMI_VIRTUAL_KEYBOARD_LANG;
				}
                mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_LANG_NUMBER, MMI_FALSE);                
                break;
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
                mmi_imc_pen_select_input_style();
                break;
#endif

            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
                mmi_imc_pen_vk_hide();
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
                mmi_imc_pen_vk_space(pen_event);
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_SYM_PREV_PAGE:
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            #if (defined(__MMI_T9_SM_CHINESE__)||defined(__MMI_ZI_SM_CHINESE__)||defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)||defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__))    
                 if (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_PINYIN ||
                     g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_BOPOMO ||
                     g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_SM_STROKE ||
		     g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_TR_STROKE ||
		     g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_PINYIN ||
                     g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_BOPOMO ||
                     g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_SM_STROKE ||
                     g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_TR_STROKE )
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG > GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1 && 
                        MMI_VIRTUAL_KEYBOARD_LANG <= GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4)
                    {
                        mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(MMI_VIRTUAL_KEYBOARD_LANG - 1), MMI_FALSE);
                    }
                }
                #if defined(__MMI_LANG_SM_CHINESE__)
                else if ((mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_QUICK_SEARCH_PINYIN) &&
                        (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_ENGLISH))
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG > GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1 && 
                        MMI_VIRTUAL_KEYBOARD_LANG <= GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4)
                    {
                        mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(MMI_VIRTUAL_KEYBOARD_LANG - 1), MMI_FALSE);
                    }
                }
                #endif /* defined(__MMI_LANG_SM_CHINESE__) */
                else
            #endif        
                if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL) &&
                    ((MMI_VIRTUAL_KEYBOARD_LANG > GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE) && (MMI_VIRTUAL_KEYBOARD_LANG <= GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE)))
                {
                    mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(MMI_VIRTUAL_KEYBOARD_LANG - 1), MMI_FALSE);
                }
                else
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG > GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1 && 
                        MMI_VIRTUAL_KEYBOARD_LANG <= GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_4)
                    {
                        mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(MMI_VIRTUAL_KEYBOARD_LANG - 1), MMI_FALSE);
                    }
                }
            
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_SYM_NEXT_PAGE:
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            #if (defined(__MMI_T9_SM_CHINESE__)||defined(__MMI_ZI_SM_CHINESE__)||defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)||defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__))    
                 if (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_PINYIN ||
                     g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_BOPOMO ||
                     g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_SM_STROKE ||
                     g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_TR_STROKE ||
	             g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_PINYIN ||
                     g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_BOPOMO ||
                     g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_SM_STROKE ||
                     g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_TR_STROKE )
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG >= GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1 && 
                        MMI_VIRTUAL_KEYBOARD_LANG < GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4)
                    {
                        mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(MMI_VIRTUAL_KEYBOARD_LANG + 1), MMI_FALSE);
                    }
                }
                #if defined(__MMI_LANG_SM_CHINESE__)
                else if ((mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_QUICK_SEARCH_PINYIN) &&
                        (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_ENGLISH))
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG >= GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1 && 
                        MMI_VIRTUAL_KEYBOARD_LANG < GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4)
                    {
                        mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(MMI_VIRTUAL_KEYBOARD_LANG + 1), MMI_FALSE);
                    }
                }
                #endif /* defined(__MMI_LANG_SM_CHINESE__) */
                else
            #endif        
                if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL) &&
                    ((MMI_VIRTUAL_KEYBOARD_LANG >= GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE) && (MMI_VIRTUAL_KEYBOARD_LANG < GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE)))
                {
                    mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(MMI_VIRTUAL_KEYBOARD_LANG + 1), MMI_FALSE);
                }
                else
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG >= GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1 && 
                        MMI_VIRTUAL_KEYBOARD_LANG < GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_4)
                    {
                        mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(MMI_VIRTUAL_KEYBOARD_LANG + 1), MMI_FALSE);
                    }
                }
            
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
                /* If we are moving back to langugae form symbol layout,
                 * then we should release the lock if it is existing
                 */
                if (g_imc_pen.is_symbol_lock)
                {
                    g_imc_pen.is_symbol_lock = MMI_FALSE;
                    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK, 0, 0, NULL);
                }
            if (mmi_imc_pen_is_only_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) && g_imc_pen.vk_type_before_symbol != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
                {
                    
                      mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                      switch (g_imc_pen.vk_type_before_symbol)
                      {
                            #if defined(__MMI_LANG_BENGALI__)
                            case GUI_VIRTUAL_KEYBOARD_BENGALI_LOWERCASE:
                                g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_BENGALI;
                                break;
                            #endif
                            #if defined(__MMI_LANG_HINDI__)
                            case GUI_VIRTUAL_KEYBOARD_HINDI_LOWERCASE:
                                g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_HINDI;
                                break;
                            #endif
                            #if defined(__MMI_LANG_THAI__)
                            case GUI_VIRTUAL_KEYBOARD_THAI_LOWERCASE:
                                g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_THAI;
                                break;
                            #endif
                      }
		      if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL))
                      {
                         if (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_ENGLISH)
                         {
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_INTERNET;
                         }
                         else if (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE)
                         {
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE;
                         }
                      }
                      mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);
                      g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;

                }
                else if (g_imc_pen.vk_type_before_num != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    
                    switch (g_imc_pen.vk_type_before_num)
                    {
                            #if defined(__MMI_LANG_BENGALI__)
                            case GUI_VIRTUAL_KEYBOARD_BENGALI_LOWERCASE:
                                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_BENGALI;
                                break;
                            #endif
                            #if defined(__MMI_LANG_HINDI__)
                            case GUI_VIRTUAL_KEYBOARD_HINDI_LOWERCASE:
                                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_HINDI;
                                break;
                            #endif
                            #if defined(__MMI_LANG_THAI__)
                            case GUI_VIRTUAL_KEYBOARD_THAI_LOWERCASE:
                                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_THAI;
                                break;
                            #endif
                    }
                    if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL))
                    {
                         if (g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_ENGLISH)
                         {
                            g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_INTERNET;
                         }
                         else if (g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE)
                         {
                            g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE;
                         }
                    }
                    mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_num, MMI_FALSE);                    
                    g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;

                }
                
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_SYM_LOCK:
                g_imc_pen.is_symbol_lock = (MMI_BOOL)(!g_imc_pen.is_symbol_lock);
                mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK, 0, 0, NULL);
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_10:
            case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_11:
                {
                    UI_string_type emotion_icon_p = g_imc_pen_emotion_icon_array[vk_event - GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_1];
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)emotion_icon_p, 0);
                    ret_val = mmi_imc_pen_vk_back_to_lang();
                }
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE:
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_NEW_LINE, 0, 0);
                /* for returning to the main layout when new line is inserted */
                ret_val = mmi_imc_pen_vk_back_to_lang();
                break;

        }
        delete_key_down_initial_state = MMI_FALSE;
    }
    else if (pen_event == MMI_PEN_EVENT_REPEAT)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
				#if !defined(__MMI_IME_V3__)
                if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET ||
                    MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE)
                {
                    break;
                }
				#endif
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
                if (!(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_LANG_NUMBER && g_imc_pen.vk_type_before_num!= GUI_VIRTUAL_KEYBOARD_MAX_LANG))
                {
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);            
                    mmi_imc_config_clean_force_ui_style_valitation(MMI_FALSE);
                    mmi_imc_key_group_key_repeat_int((U16)(vk_event - GUI_VKBD_PEN_ALPHANUMERIC_KEY_0 + KEY_0), KEY_EVENT_REPEAT);
                    mmi_imc_config_clean_force_ui_style_valitation(MMI_TRUE);
                }
                    ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            #endif
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                mmi_imc_key_group_key_repeat_int(KEY_STAR, KEY_EVENT_REPEAT);
                ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            #endif
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                mmi_imc_key_group_key_repeat_int(KEY_POUND, KEY_EVENT_REPEAT);
                ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:
                ret_val = mmi_imc_pen_vk_event_change_mode(pen_event);
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_SYMBPICKER:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
                if ((delete_key_down_initial_state) && ( MMI_IMC_STATE_INITIAL != prev_state))
                {
                    mmi_imc_key_group_key_repeat_int(KEY_RSK, KEY_EVENT_DOWN);
                    ret_val = MMI_FALSE;
                }
                else
                {
                    mmi_imc_pen_vk_backspace(pen_event);
					ret_val = MMI_FALSE;//no need of redraw
                }
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
                break;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_LONG_TAP)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
				#if !defined(__MMI_IME_V3__)
                if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET ||
                    MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE)
                {
                    mmi_imc_pen_vk_insert_char(0x0030);                    
                    break;
                }
				#else
				if(mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN)
				{
					mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x0030, 1);
					break;
				}
				#endif
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
                if (!(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_LANG_NUMBER && g_imc_pen.vk_type_before_num!= GUI_VIRTUAL_KEYBOARD_MAX_LANG))
                {            
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_long_int((U16)(vk_event - GUI_VKBD_PEN_ALPHANUMERIC_KEY_0 + KEY_0), KEY_LONG_PRESS);
                }
                    ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:                
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            #endif
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                mmi_imc_key_group_key_long_int(KEY_STAR, KEY_LONG_PRESS);
                ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
            #endif
                mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                mmi_imc_key_group_key_long_int(KEY_POUND, KEY_LONG_PRESS);
                ret_val = MMI_FALSE;
                break;                
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
                if ((delete_key_down_initial_state) && ( MMI_IMC_STATE_VK_CAND != prev_state))
                {
                    mmi_imc_key_group_key_long_int(KEY_RSK, KEY_EVENT_DOWN);
                    ret_val = MMI_FALSE;
                }
                else
                {
                    mmi_imc_pen_vk_backspace(pen_event);
                }
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
                //mmi_imc_pen_vk_caps_lock(pen_event);
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:
                ret_val = mmi_imc_pen_vk_event_change_mode(pen_event);
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_SYMBPICKER:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
                break;
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
                break;
        }
        g_imc_pen.vk_longtap = MMI_TRUE;
    }
    return ret_val;
}

//#endif /* defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */


#if (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)) && defined(__MMI_LANG_TR_CHINESE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_zhuyin_get_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  U16 the Zhuyin symbol
 *****************************************************************************/
static UI_character_type mmi_imc_pen_vk_zhuyin_get_symbol(gui_virtual_keyboard_pen_enum vk_event, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > MMI_IMC_PEN_ZHUYIN_QWERTY_MULTITAP_CHAR_NUM)
        index = 0;
    
    if (g_imc_pen_zhuyin_qwert_keymap[0][index] == 0x0000)
        index = 0;        
    g_imc_pen.zhuyin_vk_char_map_index = index;
    g_imc_pen.zhuyin_vk_event = vk_event;
    return (g_imc_pen_zhuyin_qwert_keymap[0][index]);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_zhuyin_confirm_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  U16 the Zhuyin symbol
 *****************************************************************************/
static void mmi_imc_pen_vk_zhuyin_confirm_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_pen.zhuyin_vk_char_map_index = -1;
    g_imc_pen.zhuyin_vk_event = GUI_VKBD_PEN_NONE;
}

#endif

#if defined(__MMI_IME_ZHUYIN_HALF_QWERTY_VK__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_half_zhuyin_get_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  U16 the Zhuyin symbol
 *****************************************************************************/
static UI_character_type mmi_imc_pen_vk_half_zhuyin_get_symbol(gui_virtual_keyboard_pen_enum vk_event, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > MMI_IMC_PEN_ZHUYIN_QWERTY_MULTITAP_CHAR_NUM)
        index = 0;
    if (vk_event < GUI_VKBD_PEN_ZHUYIN_B_P || vk_event > GUI_VKBD_PEN_ZHUYIN_ER)
        MMI_ASSERT(0);
    
    if (g_imc_pen_zhuyin_half_qwert_keymap[vk_event - GUI_VKBD_PEN_ZHUYIN_B_P][index] == 0x0000)
        index = 0;        
    g_imc_pen.zhuyin_vk_char_map_index = index;
    g_imc_pen.zhuyin_vk_event = vk_event;
    return (g_imc_pen_zhuyin_half_qwert_keymap[vk_event - GUI_VKBD_PEN_ZHUYIN_B_P][index]);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_half_zhuyin_confirm_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  U16 the Zhuyin symbol
 *****************************************************************************/
static void mmi_imc_pen_vk_half_zhuyin_confirm_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imc_get_state())
    {
        case MMI_IMC_STATE_VK_CAND_MULTITAP:
            mmi_imc_set_state(MMI_IMC_STATE_VK_CAND);
            break;
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            
			#if(UI_DOUBLE_BUFFER_SUPPORT)
            gui_lock_double_buffer();
            #endif
			mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
            mmi_imc_redraw_screen_by_state();
			#if(UI_DOUBLE_BUFFER_SUPPORT)
            gui_unlock_double_buffer();
            #endif
            break;
    }
    
    if (g_wgui_virtual_keyboard.popup_hint.popup_state != GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
    {
        g_imc_pen.zhuyin_vk_char_map_index = -1;
    }

    g_imc_pen.zhuyin_vk_event = GUI_VKBD_PEN_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_half_zhuyin_event_handler
 * DESCRIPTION
 *  vk handler for half zhuyin keyboard
 * PARAMETERS
 * RETURNS
 *  MMI_BOOL handle the event or not
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_half_zhuyin_event_handler(mmi_pen_event_type_enum pen_event, UI_character_type ch, gui_virtual_keyboard_pen_enum vk_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_val = MMI_FALSE;
    UI_character_type sym;
    mmi_imc_state_enum prev_state = MMI_IMC_STATE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (pen_event == MMI_PEN_EVENT_DOWN || pen_event == MMI_PEN_EVENT_REPEAT)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_ZHUYIN_B_P:
            case GUI_VKBD_PEN_ZHUYIN_M_F:
            case GUI_VKBD_PEN_ZHUYIN_D_T:
            case GUI_VKBD_PEN_ZHUYIN_N_L:
            case GUI_VKBD_PEN_ZHUYIN_G_J:
            case GUI_VKBD_PEN_ZHUYIN_K_Q:
            case GUI_VKBD_PEN_ZHUYIN_H_X:
            case GUI_VKBD_PEN_ZHUYIN_ZH_CH:
            case GUI_VKBD_PEN_ZHUYIN_SH:
            case GUI_VKBD_PEN_ZHUYIN_R:
            case GUI_VKBD_PEN_ZHUYIN_I:
            case GUI_VKBD_PEN_ZHUYIN_U:
            case GUI_VKBD_PEN_ZHUYIN_IU:
            case GUI_VKBD_PEN_ZHUYIN_Z:
            case GUI_VKBD_PEN_ZHUYIN_C:
            case GUI_VKBD_PEN_ZHUYIN_S:
            case GUI_VKBD_PEN_ZHUYIN_A_O:
            case GUI_VKBD_PEN_ZHUYIN_E:
            case GUI_VKBD_PEN_ZHUYIN_EH:
            case GUI_VKBD_PEN_ZHUYIN_AI_EI:
            case GUI_VKBD_PEN_ZHUYIN_AU:
            case GUI_VKBD_PEN_ZHUYIN_OU:
            case GUI_VKBD_PEN_ZHUYIN_AN_EN:
            case GUI_VKBD_PEN_ZHUYIN_ANG:
            case GUI_VKBD_PEN_ZHUYIN_ENG:
            case GUI_VKBD_PEN_ZHUYIN_ER:
                {
                    prev_state = mmi_imc_get_state();
                    switch (prev_state)
                    {
                        case MMI_IMC_STATE_VK_CAND_MULTITAP:
                            /* If PEN_EVENT_DOWN occurs on the key other than the 
                             * previous key, then the multitap timer should be confirmed,
                             * so we are not restarting the timer
                             */
                            if ((vk_event == g_imc_pen.zhuyin_vk_event) ||
                                (pen_event == MMI_PEN_EVENT_REPEAT))
                            {
                                mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_half_zhuyin_confirm_handler, mmi_imc_pen_vk_half_zhuyin_confirm_handler);
                                g_imc_pen.global_data_ptr->symb_count --;
                            }
                        case MMI_IMC_STATE_MULTITAP:
                            if (vk_event != g_imc_pen.zhuyin_vk_event)
                            {
                                mmi_imc_cancel_timer();
                                g_imc_pen.zhuyin_vk_char_map_index = -1;
                            }
                        case MMI_IMC_STATE_VK_CAND:
                            if ((pen_event == MMI_PEN_EVENT_REPEAT) &&
                                (prev_state == MMI_IMC_STATE_VK_CAND))
                            {
                                /* To avoid the entry of characters onto display area or composition box when the 
                                 * the buffer is already filled 
                                 */
                                if ((g_imc_pen.global_data_ptr->symb_count + 1 <= MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN) &&
            	                    (g_imc_pen.global_data_ptr->symb_count + 1 <= MMI_IMC_PEN_MAX_STRING_IN_DIPLAY_AREA_VK_ZHUYIN))
                                {
                                    mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_half_zhuyin_confirm_handler, mmi_imc_pen_vk_half_zhuyin_confirm_handler);
                                    g_imc_pen.global_data_ptr->symb_count --;
                                }
                            }
                        case MMI_IMC_STATE_INITIAL:
                        case MMI_IMC_STATE_ASSOC_SELECTING:
                            sym = mmi_imc_pen_vk_half_zhuyin_get_symbol(vk_event, g_imc_pen.zhuyin_vk_char_map_index + 1);
                            if (sym)
                            {
                                if ((MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_SPELLING_DIRECTLY, 0, 0) == MMI_FALSE)
                                {
                                    if (mmi_imc_pen_vk_insert_char(sym))
                                    {
                                        mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP);
                                        if ((prev_state == MMI_IMC_STATE_INITIAL) || 
                                            (prev_state == MMI_IMC_STATE_ASSOC_SELECTING) )
                                        {
                                            mmi_imc_redraw_screen_by_state();
                                        }
                                        else
                                        {
                                            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA));
                                            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
                                        }
                                    }
                                    else
                                    {
                                        sym = mmi_imc_pen_vk_half_zhuyin_get_symbol(vk_event, g_imc_pen.zhuyin_vk_char_map_index + 1);
                                        if (mmi_imc_pen_vk_insert_char(sym))
                                        {
                                            mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP);
                                            if (prev_state == MMI_IMC_STATE_INITIAL)
                                            {
                                                mmi_imc_redraw_screen_by_state();
                                            }
                                            else
                                            {
                                                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA));
                                                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);

                                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                                    gui_lock_double_buffer();
                                    #endif
                                    wgui_virtual_keyboard_draw_from_cache();
                                    g_imc_pen.global_data_ptr->cand_length = mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, sym, 0);
                                    wgui_virtual_keyboard_recache();

                                    mmi_imc_set_state(MMI_IMC_STATE_MULTITAP);                                       
                                    mmi_imc_redraw_screen_by_state();
                                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                                    gui_unlock_double_buffer();
                                    #endif
                                }                                
                            }
                            break;
                    }
                    ret_val = MMI_TRUE;
                }
                break;
            case GUI_VKBD_PEN_ZHUYIN_TONE:
                break;
            default:
                mmi_imc_pen_vk_half_zhuyin_confirm_handler();
                break;                
        }
    }
    else if (pen_event == MMI_PEN_EVENT_UP)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_ZHUYIN_B_P:
            case GUI_VKBD_PEN_ZHUYIN_M_F:
            case GUI_VKBD_PEN_ZHUYIN_D_T:
            case GUI_VKBD_PEN_ZHUYIN_N_L:
            case GUI_VKBD_PEN_ZHUYIN_G_J:
            case GUI_VKBD_PEN_ZHUYIN_K_Q:
            case GUI_VKBD_PEN_ZHUYIN_H_X:
            case GUI_VKBD_PEN_ZHUYIN_ZH_CH:
            case GUI_VKBD_PEN_ZHUYIN_A_O:
            case GUI_VKBD_PEN_ZHUYIN_AI_EI:
            case GUI_VKBD_PEN_ZHUYIN_AN_EN:
                if (mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
                {
                    mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_half_zhuyin_confirm_handler, mmi_imc_pen_vk_half_zhuyin_confirm_handler);
                }
                else
                {
                    mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_half_zhuyin_confirm_handler, mmi_imc_pen_vk_half_zhuyin_confirm_handler);
                    if (mmi_imc_get_state() != MMI_IMC_STATE_INITIAL)
                    {
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
                    }
                    ret_val = MMI_TRUE;
                }
                break;
            
            /* The multitap should be confirmed as only one charactre is 
             * mapped to the following keys 
             */
            case GUI_VKBD_PEN_ZHUYIN_SH:
            case GUI_VKBD_PEN_ZHUYIN_R:
            case GUI_VKBD_PEN_ZHUYIN_I:
            case GUI_VKBD_PEN_ZHUYIN_U:
            case GUI_VKBD_PEN_ZHUYIN_IU:
            case GUI_VKBD_PEN_ZHUYIN_Z:
            case GUI_VKBD_PEN_ZHUYIN_C:
            case GUI_VKBD_PEN_ZHUYIN_S:
            case GUI_VKBD_PEN_ZHUYIN_E:
            case GUI_VKBD_PEN_ZHUYIN_EH:
            case GUI_VKBD_PEN_ZHUYIN_AU:
            case GUI_VKBD_PEN_ZHUYIN_OU:
            case GUI_VKBD_PEN_ZHUYIN_ANG:
            case GUI_VKBD_PEN_ZHUYIN_ENG:
            case GUI_VKBD_PEN_ZHUYIN_ER:
                mmi_imc_pen_vk_half_zhuyin_confirm_handler();
                break;
            case GUI_VKBD_PEN_ZHUYIN_TONE:
                mmi_imc_delete_timer();
                if (g_imc_pen.global_data_ptr->symb_count )
                {
                    U16 input_tone = MMI_IMC_SYMB_TONE_1;
                    U16 symb = g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count - 1];
                    if (MMI_IMC_IS_SYMB_TONE(symb))
                    {
                        input_tone = ((symb+ 1 > MMI_IMC_SYMB_TONE_5) ? MMI_IMC_SYMB_TONE_1: symb + 1);
                    }
                    ret_val = mmi_imc_pen_vk_zhuyin_tone((mmi_imc_symb_tone_enum)input_tone);     
                    if (ret_val)
                    {
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
                    }
                }
                break;

            default :
                   mmi_imc_pen_vk_half_zhuyin_confirm_handler();
        }

    }
    else if (pen_event == MMI_PEN_EVENT_ABORT)
    {
        mmi_imc_cancel_timer();
    }
    
    return ret_val;
}
#endif


#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_half_zhuyin_get_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  U16 the Zhuyin symbol
 *****************************************************************************/
static UI_character_type mmi_imc_pen_vk_matrix_zhuyin_get_symbol(gui_virtual_keyboard_pen_enum vk_event, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type* label_string;
    U32 keycount,code;
    U32 i,loc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    keycount = wgui_virtual_keyboard_get_button_count();
    for(i = 0; i < keycount; i++)
    {
        code = wgui_virtual_keyboard_get_button_code(i, MMI_PEN_EVENT_DOWN);
        if(code == vk_event)
            break;
    }
    wgui_virtual_keyboard_get_button_label_aux(i,&label_string,&loc,&loc,&loc,&loc,GUI_VK_KEY_STATE_NORMAL);
    if(label_string == NULL)
    {
        wgui_virtual_keyboard_get_button_label(i,&label_string,&loc,&loc,&loc,&loc,GUI_VK_KEY_STATE_NORMAL);
    }
    if (index > MMI_IMC_PEN_ZHUYIN_QWERTY_MULTITAP_CHAR_NUM)
        index = 0;
    if (vk_event < GUI_VKBD_PEN_V3_KEY_BPMF_0 || vk_event > GUI_VKBD_PEN_V3_KEY_BPMF_10)
        MMI_ASSERT(0);
    MMI_ASSERT(label_string != 0);
    if(label_string[index] == 0)
        index = 0;        
    g_imc_pen.zhuyin_vk_char_map_index = index;
    g_imc_pen.zhuyin_vk_event = vk_event;
    return (label_string[index]);       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_matrix_zhuyin_confirm_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  U16 the Zhuyin symbol
 *****************************************************************************/
static void mmi_imc_pen_vk_matrix_zhuyin_confirm_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imc_get_state())
    {
        case MMI_IMC_STATE_VK_CAND_MULTITAP:
            mmi_imc_set_state(MMI_IMC_STATE_VK_CAND);
            break;
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            
			#if(UI_DOUBLE_BUFFER_SUPPORT)
            gui_lock_double_buffer();
            #endif
			mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
            mmi_imc_redraw_screen_by_state();
			#if(UI_DOUBLE_BUFFER_SUPPORT)
            gui_unlock_double_buffer();
            #endif
            break;
    }
    
    if (g_wgui_virtual_keyboard.popup_hint.popup_state != GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
    {
        g_imc_pen.zhuyin_vk_char_map_index = -1;
    }

    g_imc_pen.zhuyin_vk_event = GUI_VKBD_PEN_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_half_zhuyin_event_handler
 * DESCRIPTION
 *  vk handler for half zhuyin keyboard
 * PARAMETERS
 * RETURNS
 *  MMI_BOOL handle the event or not
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_matrix_zhuyin_event_handler(mmi_pen_event_type_enum pen_event, UI_character_type ch, gui_virtual_keyboard_pen_enum vk_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_val = MMI_FALSE;
    UI_character_type sym;
    mmi_imc_state_enum prev_state = MMI_IMC_STATE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (pen_event == MMI_PEN_EVENT_DOWN || pen_event == MMI_PEN_EVENT_REPEAT)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_V3_KEY_BPMF_0:
            case GUI_VKBD_PEN_V3_KEY_BPMF_1:
            case GUI_VKBD_PEN_V3_KEY_BPMF_2:
            case GUI_VKBD_PEN_V3_KEY_BPMF_3:
            case GUI_VKBD_PEN_V3_KEY_BPMF_4:
            case GUI_VKBD_PEN_V3_KEY_BPMF_5:
            case GUI_VKBD_PEN_V3_KEY_BPMF_6:
            case GUI_VKBD_PEN_V3_KEY_BPMF_7:
            case GUI_VKBD_PEN_V3_KEY_BPMF_8:
            case GUI_VKBD_PEN_V3_KEY_BPMF_9:
            case GUI_VKBD_PEN_V3_KEY_BPMF_10:
                {
                    prev_state = mmi_imc_get_state();
                    switch (prev_state)
                    {
                        case MMI_IMC_STATE_VK_CAND_MULTITAP:
                            /* If PEN_EVENT_DOWN occurs on the key other than the 
                             * previous key, then the multitap timer should be confirmed,
                             * so we are not restarting the timer
                             */
                            if ((vk_event == g_imc_pen.zhuyin_vk_event) ||
                                (pen_event == MMI_PEN_EVENT_REPEAT))
                            {
                                mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_matrix_zhuyin_confirm_handler, mmi_imc_pen_vk_matrix_zhuyin_confirm_handler);
                                g_imc_pen.global_data_ptr->symb_count --;
                            }
                        case MMI_IMC_STATE_MULTITAP:
                            if (vk_event != g_imc_pen.zhuyin_vk_event)
                            {
                                mmi_imc_cancel_timer();
                                g_imc_pen.zhuyin_vk_char_map_index = -1;
                            }
                        case MMI_IMC_STATE_VK_CAND:
                            if ((pen_event == MMI_PEN_EVENT_REPEAT) &&
                                (prev_state == MMI_IMC_STATE_VK_CAND))
                            {
                                /* To avoid the entry of characters onto display area or composition box when the 
                                 * the buffer is already filled 
                                 */
                                if ((g_imc_pen.global_data_ptr->symb_count + 1 <= MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN) &&
                                     (g_imc_pen.global_data_ptr->symb_count + 1 <= MMI_IMC_PEN_MAX_STRING_IN_DIPLAY_AREA_VK_ZHUYIN))
                                {
                                    mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_matrix_zhuyin_confirm_handler, mmi_imc_pen_vk_matrix_zhuyin_confirm_handler);
                                    g_imc_pen.global_data_ptr->symb_count --;
                                }
                            }
                        case MMI_IMC_STATE_INITIAL:
                        case MMI_IMC_STATE_ASSOC_SELECTING:
                            sym = mmi_imc_pen_vk_matrix_zhuyin_get_symbol(vk_event, g_imc_pen.zhuyin_vk_char_map_index + 1);
                            if (sym)
                            {
                                if ((MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_SPELLING_DIRECTLY, 0, 0) == MMI_FALSE)
                                {
                                    if (mmi_imc_pen_vk_insert_char(sym))
                                    {
                                        mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP);
                                        if ((prev_state == MMI_IMC_STATE_INITIAL) || 
                                            (prev_state == MMI_IMC_STATE_ASSOC_SELECTING) )
                                         ret_val = MMI_TRUE;
                                    }
                                    else
                                    {
                                        sym = mmi_imc_pen_vk_matrix_zhuyin_get_symbol(vk_event, g_imc_pen.zhuyin_vk_char_map_index + 1);
                                        if (mmi_imc_pen_vk_insert_char(sym))
                                        {
                                            mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP);
                                            ret_val = MMI_TRUE;
                                        }
                                    }
                                }
                                else
                                {
                                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);

                                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                                    gui_lock_double_buffer();
                                    #endif
                                    wgui_virtual_keyboard_draw_from_cache();
                                    g_imc_pen.global_data_ptr->cand_length = mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, sym, 0);
                                    wgui_virtual_keyboard_recache();

                                    mmi_imc_set_state(MMI_IMC_STATE_MULTITAP);                                       
                                    ret_val = MMI_TRUE;
                                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                                    gui_unlock_double_buffer();
                                    #endif
                                }                                
                            }
                            break;
                    }
                    ret_val = MMI_TRUE;
                }
                break;
            case GUI_VKBD_PEN_ZHUYIN_TONE:
                break;
            default:
                mmi_imc_pen_vk_matrix_zhuyin_confirm_handler();
                break;                
        }
    }
    else if (pen_event == MMI_PEN_EVENT_UP)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_V3_KEY_BPMF_0:
            case GUI_VKBD_PEN_V3_KEY_BPMF_1:
            case GUI_VKBD_PEN_V3_KEY_BPMF_2:
            case GUI_VKBD_PEN_V3_KEY_BPMF_3:
            case GUI_VKBD_PEN_V3_KEY_BPMF_4:
            case GUI_VKBD_PEN_V3_KEY_BPMF_5:
            case GUI_VKBD_PEN_V3_KEY_BPMF_6:
            case GUI_VKBD_PEN_V3_KEY_BPMF_7:
            case GUI_VKBD_PEN_V3_KEY_BPMF_8:
            case GUI_VKBD_PEN_V3_KEY_BPMF_9:
            case GUI_VKBD_PEN_V3_KEY_BPMF_10:

                if (mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
                {
                    mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_matrix_zhuyin_confirm_handler, mmi_imc_pen_vk_matrix_zhuyin_confirm_handler);
                }
                else
                {
                    mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_matrix_zhuyin_confirm_handler, mmi_imc_pen_vk_matrix_zhuyin_confirm_handler);
                    if (mmi_imc_get_state() != MMI_IMC_STATE_INITIAL)
                    {
                        ret_val = MMI_TRUE;
                    }
                    ret_val = MMI_TRUE;
                }
                break;
            
            case GUI_VKBD_PEN_ZHUYIN_TONE:
                mmi_imc_delete_timer();
                if (g_imc_pen.global_data_ptr->symb_count )
                {
                    U16 input_tone = MMI_IMC_SYMB_TONE_1;
                    U16 symb = g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count - 1];
                    if (MMI_IMC_IS_SYMB_TONE(symb))
                    {
                        input_tone = ((symb+ 1 > MMI_IMC_SYMB_TONE_5) ? MMI_IMC_SYMB_TONE_1: symb + 1);
                    }
                    ret_val = mmi_imc_pen_vk_zhuyin_tone((mmi_imc_symb_tone_enum)input_tone);     
                    if (ret_val)
                    {
                        ret_val = MMI_TRUE;
                    }
                }
                break;

            default :
                   mmi_imc_pen_vk_matrix_zhuyin_confirm_handler();
        }

    }
    else if (pen_event == MMI_PEN_EVENT_ABORT)
    {
        mmi_imc_cancel_timer();
    }
    if (ret_val)
    {
        mmi_imc_redraw_screen_by_state();
    }
    return ret_val;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_zhuyin_tone
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_zhuyin_tone(mmi_imc_symb_tone_enum tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U16 prev_tone;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_pen.global_data_ptr->symb_count)
    {
        prev_tone = g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count - 1];
        if (MMI_IMC_IS_SYMB_TONE(g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count - 1]))
        {
            g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count - 1] = tone;
        }
        else
        {
            g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count ++] = tone;
        }
        
        if (!mmi_imc_pen_set_vk_candidate())
        {
            if (MMI_IMC_IS_SYMB_TONE(prev_tone))
            {
                g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count - 1] = prev_tone;
                mmi_imc_pen_set_vk_candidate();
            }
            else
            {
                g_imc_pen.global_data_ptr->symb_count --;
            }
        }
        else
        {
            ret = MMI_TRUE;
        }
    }

    return ret;
}

#endif /* defined(__MMI_IME_FTE_ENHANCE__) */

#if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
void mmi_imc_pen_get_group_letters_from_vk(UI_character_type* character_array, S32 length)
{
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_GET_QWERTY_VK_KEY_MAPPING, (U32) character_array, length, NULL);
}
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)

void mmi_imc_pen_get_input_box_heigt(S32* x, S32* y, S32* width, S32* height)
{
	mmi_imc_rect input_box_rect = {0,0,0,0};

	mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT, (U32)&input_box_rect, 0);
	*x = input_box_rect.x;
	*y = input_box_rect.y;
	*width = input_box_rect.width;
	*height = input_box_rect.height;
}

void mmi_imc_pen_vk_change_input_mode_between_smart_and_multitap()
{
    const sIMEModeDetails * mode_details;
	U32  temp_input_mode;
	gui_virtual_keyboard_language_enum current_vk_type = MMI_VIRTUAL_KEYBOARD_LANG;
	mmi_imm_input_mode_enum curr_input_mode = mmi_imm_vk_get_input_mode_according_smart_and_multitap();
	mode_details = mmi_imm_get_input_mode_array_item(curr_input_mode);
	temp_input_mode = ((mode_details->Handwriting_Attrib)<<4);
    temp_input_mode = ((temp_input_mode)>>20);

    if(curr_input_mode == IMM_INPUT_MODE_NONE)
        return;
    if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND)
    {
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_FALSE, 0); 
    }
    mmi_imm_set_current_input_mode(curr_input_mode);
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    mmi_imc_change_input_mode(curr_input_mode,0);
	if(temp_input_mode == IME_HAN_WRITING_INVALID_INPUT_MODE)
	{
		mmi_imc_pen_set_virtual_keyboard(current_vk_type,MMI_FALSE);
	}
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK,0,0,NULL);
    mmi_imc_redraw_screen_by_state();
}

void mmi_imc_pen_set_vk_active_row(mmi_imm_input_type_enum input_type)
{
	toggle_state_id_mapping_enum togglestate[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_END] = {0};
    toggle_state_key_index_enum index;
    mmi_imui_message_struct msg;
    mmi_imm_input_mode_enum input_mode = mmi_imm_get_curr_input_mode();
    const sIMEModeDetails * mode_detail_ptr = NULL;
    
    msg.message_id = MMI_IMUI_MESSAGE_SET_ACTIVE_ROW_ID_VK;
    msg.param_0 = 1; //default value;

#if !defined(__MMI_LANG_HK_CHINESE__)  && !defined(__MMI_LANG_SM_CHINESE__) && !defined(__MMI_LANG_TR_CHINESE__)
    togglestate[GUI_VIRTUAL_KEYBOARD_SYMBOL_VK_MULTI_STYLE] = GUI_VIRTUAL_KEYBOARD_SYMBOL_VK_MULTI_STYLE_ALPHA_ONLY;
#endif
    
    mode_detail_ptr = mmi_imm_get_input_mode_array_item(input_mode);
    if ((mode_detail_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ENGLISH_ONLY
        || mode_detail_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
        && !mmi_imm_is_chinese_input_method(input_mode))
    {

        mmi_imc_pen_set_gui_state(g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_CASE_MASK);
        if(mmi_imm_get_is_smart_input_mode_allowed_of_curr_writing_language())
        {
            if(mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
            {
                togglestate[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SMART_MULTITAP] = GUI_VIRTUAL_KEYBOARD_SMART_ENABLE;
            }
            else
            {
                togglestate[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SMART_MULTITAP] = GUI_VIRTUAL_KEYBOARD_SMART_DISABLE;
            }
        }
        else
        {
            togglestate[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SMART_MULTITAP] = GUI_VIRTUAL_KEYBOARD_NO_SMART;
        }
    }
    else
    {
        // set pinyin as lower case.
        mmi_imc_pen_set_gui_state(IME_MODE_ATTR_LOWERCASE);
    }
    if(input_type == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD
        && MMI_VIRTUAL_KEYBOARD_LANG != GUI_VIRTUAL_KEYBOARD_TRAY)
    {
        msg.param_0 = 4;
        togglestate[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SYMBOL_PICKER] = GUI_VIRTUAL_KEYBOARD_SYMBOL_PICKER_STYLE_123SYM;
    }
    else if(input_type & IMM_INPUT_TYPE_URL)
    {
        if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY)
        {
            msg.param_0 = 3;
        }
        togglestate[GUI_VIRTUAL_KEYBOARD_MULTI_STYLE_KEY] = GUI_VIRTUAL_KEYBOARD_MULTI_STYLE_INTERNET;
        togglestate[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SMART_MULTITAP] = GUI_VIRTUAL_KEYBOARD_NO_SMART;
    }
    else if(input_type & IMM_INPUT_TYPE_EMAIL)
    {
        if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY)
        {
            msg.param_0 = 2;
        }
        togglestate[GUI_VIRTUAL_KEYBOARD_MULTI_STYLE_KEY] = GUI_VIRTUAL_KEYBOARD_MULTI_STYLE_EMAIL;
        togglestate[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SMART_MULTITAP] = GUI_VIRTUAL_KEYBOARD_NO_SMART;
    }
    else if (input_type == IMM_INPUT_TYPE_USER_SPECIFIC)
    {
        if (mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_123_SYMBOLS) && mmi_imm_is_curr_allowed_wlang(IME_WRITING_LANG_ABC))
        {
            if (mmi_imm_get_writing_language_num() == 2)
            {
                msg.param_0 = 4;
            }
        }
    }
    else if(input_type & (IMM_INPUT_TYPE_DECIMAL_NUMERIC 
        | IMM_INPUT_TYPE_SIGNED_NUMERIC 
        | IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC 
        | IMM_INPUT_TYPE_NUMERIC))
    {
        togglestate[GUI_VIRTUAL_KEYBOARD_PHONENUMBER_VK_MULTI_STYLE] = GUI_VIRTUAL_KEYBOARD_PHONENUMBER_VK_MULTI_STYLE_NUMBER_ONLY;
    }
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
#if !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) && !defined(__MMI_IME_VK_TYPE_QWERTY__)
    msg.param_0 = 2;
#endif
#endif
    if (mmi_imm_is_chinese_input_method(input_mode))
    {            
        togglestate[GUI_VIRTUAL_KEYBOARD_HANDWRITING_VK_SYMBOL_STYLE] = GUI_VIRTUAL_KEYBOARD_HANDWRITING_VK_SYMBOL_STYLE_CHINESE;
    }

    for(index = GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_START; index < GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_END; index ++)
    {
        /* skip set enter key's style, it already set properly by ap 
        *  Skip caps key toggle state since it has been properly set in mmi_imc_pen_set_gui_state() */
        if(index == GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_ENTER || index == GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SHIFT)
        {
            continue;
        }
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_ADD_TOGGLE_STATE_ID_VK,
            index,
            togglestate[index],
            NULL);
    }

    if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER)
    {
        if (mmi_imm_get_special_ext_input_type() & IMM_INPUT_TYPE_SPECIAL_EXT_SHOW_DIALER_VK)
        {
            //FTE 2_0 Dialer Patch
#if (defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)) && !defined(__COSMOS_MMI_PACKAGE__)
            //Check Normal VK or Emergency VK
            if(cui_dialer_is_emergency_call_only())
            {
                msg.param_0 = 5;
            }
            else
            {
                msg.param_0 = 6;
            }

#else
#if defined(__MMI_DUAL_SIM__)
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
            msg.param_0 = 4;
#else
            msg.param_0 = 3;
#endif
#else /* defined(__MMI_DUAL_SIM__) */
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
            msg.param_0 = 2;
#else
            msg.param_0 = 1;
#endif
#endif /* defined(__MMI_DUAL_SIM__) */	
#endif
        }
    }

    mmi_imui_send_message(&msg, NULL);
}


void mmi_imc_pen_change_vk_style(void)
{
    MMI_BOOL is_change_from_hw = MMI_FALSE;

    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    if(mmi_imc_pen_is_handwriting_vk())
    {
        is_change_from_hw = MMI_TRUE;
    }
    if(!is_change_from_hw)
    {
        if(g_imc_pen.vk_style == MMI_VK_TYPE_QWERTY)
        {
            g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
            g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
            mmi_imm_config_keyboard_type(IMM_KEYPAD_ALPHANUMERIC);
        }
        else if(g_imc_pen.vk_style == MMI_VK_TYPE_ALPHANUMERIC)
        {
            g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
            g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
            mmi_imm_config_keyboard_type(IMM_KEYPAD_QWERTY);
        }


        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);
        mmi_imc_pen_set_vk_active_row(mmi_imm_get_curr_input_type());

        mmi_imc_redraw_screen_by_state();
    }
}


static gui_virtual_keyboard_pen_enum mmi_imc_pen_translate_key_code_to_vk_event(U32 ch)
{
    if(mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG))
    {
        return GUI_VKBD_PEN_CHAR_I;
    }
    else
    {

        if(ch >= '0' && ch <= '9')
        {

            if(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER)
            {
                return (gui_virtual_keyboard_pen_enum)(ch - '0' + GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0);
            }
            else
            {
                return (gui_virtual_keyboard_pen_enum)(ch - '0' + GUI_VKBD_PEN_ALPHANUMERIC_KEY_0);
            }
        }

        return GUI_VKBD_PEN_CHAR_I;
    }
}


static gui_virtual_keyboard_pen_enum mmi_imc_pen_translate_v3_event_to_v2_event(gui_virtual_keyboard_pen_enum event)
{
    gui_virtual_keyboard_pen_enum ret_event = GUI_VKBD_PEN_NONE;

    switch(event)
    {            
    case GUI_VKBD_PEN_V3_SHIFT:
        ret_event = GUI_VKBD_PEN_CAPSLOCK;
        break;

    case GUI_VKBD_PEN_V3_SPACE:
        ret_event = GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE;
        break;

    case GUI_VKBD_PEN_V3_DELETE:
        ret_event = GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE;
        break;

    default:
        ret_event = event;
        break;

    }
    return ret_event;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_is_depend_rule_input_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_is_depend_rule_input_mode(mmi_imm_input_mode_enum input_mode)
{
    switch(input_mode)
    {
    case IMM_INPUT_MODE_MULTITAP_HINDI:
    case IMM_INPUT_MODE_MULTITAP_BENGALI: 
    case IMM_INPUT_MODE_MULTITAP_THAI:
    case IMM_INPUT_MODE_MULTITAP_PUNJABI:
	case IMM_INPUT_MODE_MULTITAP_MARATHI :
    case IMM_INPUT_MODE_MULTITAP_MALAYALAM:
    case IMM_INPUT_MODE_MULTITAP_GUJARATI:
    case IMM_INPUT_MODE_MULTITAP_LAO:
    case IMM_INPUT_MODE_MULTITAP_TAMIL:
    case IMM_INPUT_MODE_MULTITAP_ASSAMESE:
    case IMM_INPUT_MODE_MULTITAP_KANNADA:
    case IMM_INPUT_MODE_MULTITAP_TELUGU:

    case IMM_INPUT_MODE_SMART_HINDI:
    case IMM_INPUT_MODE_SMART_BENGALI:
    case IMM_INPUT_MODE_SMART_THAI:
    case IMM_INPUT_MODE_SMART_PUNJABI:
    case IMM_INPUT_MODE_SMART_MARATHI:
    case IMM_INPUT_MODE_SMART_MALAYALAM:
    case IMM_INPUT_MODE_SMART_GUJARATI:
    case IMM_INPUT_MODE_SMART_LAO:
    case IMM_INPUT_MODE_SMART_TAMIL:
    case IMM_INPUT_MODE_SMART_ASSAMESE:
    case IMM_INPUT_MODE_SMART_KANNADA:
    case IMM_INPUT_MODE_SMART_TELUGU:
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_event_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void  mmi_imc_pen_vk_event_handler(mmi_pen_event_type_enum pen_event, mmi_imui_message_struct* msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type ch = 0;
    UI_string_type str = NULL;
    gui_virtual_keyboard_pen_enum vk_event = (gui_virtual_keyboard_pen_enum)msg_ptr->param_0;
    U32 vk_type;
    MMI_BOOL has_candidate_box;
    MMI_BOOL ret_val = MMI_TRUE;
    mmi_imc_state_enum prev_state;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_vk_event_data_struct vk_event_data;
#endif
    U32 input_type = mmi_imm_get_curr_input_type();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((gui_virtual_keyboard_pen_enum)msg_ptr->param_0 == GUI_VKBD_PEN_V3_CHAR_I_CHAR)
    {
        ch = (UI_character_type)(((gui_pen_event_param_struct *)msg_ptr->param_1)->_u.i);
    }
    if ((gui_virtual_keyboard_pen_enum)msg_ptr->param_0 == GUI_VKBD_PEN_V3_CHAR_I_STRING)
    {
        str = (UI_string_type)(((gui_pen_event_param_struct *)msg_ptr->param_1)->_u.p);
    }

    
    
    if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
    {
        mmi_imc_delete_timer();
    }

#if defined(__MMI_TOUCH_SCREEN__)  && (defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__))
    /* special case for jave to show symbol */
    if (mmi_imc_get_is_java_special_symbol_enabled() && (mmi_imm_get_current_writing_language() == IME_WRITING_LANG_ABC))
    {
        ///TODO: add set toggle state code, move this code to enter java editor. and we need to define a toggle state for this and add resource.
        //
                }
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) && (defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)) */


        ///TODO: plug in need to change for string. or use vkv2's code
#ifdef __MMI_IME_PLUG_IN__
    vk_event_data.character = ch;
    vk_event_data.vk_event = vk_event;

    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_VK_EVENT, (U32)pen_event, (U32)&vk_event_data) == 1)
    {
        mmi_imc_redraw_screen_by_state();
        return;
    }
#endif

   if (pen_event != MMI_PEN_EVENT_MOVE)
   {
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO && (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC))
        {
            if (mmi_imc_pen_vk_matrix_zhuyin_event_handler(pen_event, ch, vk_event))
            {
                return;
            }
        }
   }
    
    
///TODO: verify this function was working fine.
if((g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC 
    || mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_STROKE
    || mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_TR_STROKE)
	&& mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_TR_MULTITAP_BOPOMO)
{
    if(vk_event == GUI_VKBD_PEN_CHAR_I)
    {
//        vk_event = mmi_imc_pen_translate_key_code_to_vk_event(ch);
    }
    else
    {
        vk_event = mmi_imc_pen_translate_v3_event_to_v2_event(vk_event);
    }
}

    if(vk_event == GUI_VKBD_PEN_SPACE)
        {
            ch = ' ';
            vk_event = GUI_VKBD_PEN_CHAR_I;
        }


/* here we can take event for smart vk and route accordingly*/
    
    if (pen_event == MMI_PEN_EVENT_DOWN)
    {    
        g_imc_pen_is_vk_caps_lock_down = MMI_FALSE;
        g_imc_pen.vk_longtap = MMI_FALSE;
		if(mmi_imc_get_state() == MMI_IMC_STATE_PASSWORD_PREVIEW || mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
	    {
            mmi_imc_cancel_timer();
	    }

        switch (vk_event)
        {
/* This is to take control from here to pass to xT9 */
#if defined(__MMI_IME_FTE_ENHANCE__)
	#if defined __MMI_XT9__
        case GUI_VKBD_PEN_CHAR_I:

  
            if( (mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode()!= IMM_INPUT_MODE_SM_PINYIN) &&  (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE))
                ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(pen_event,ch );
        
            break;
    #endif	
    #endif	


        #if defined(__MMI_IME_FTE_ENHANCE__) /*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
                ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
                break;
        #endif
        #if defined(__MMI_IME_FTE_ENHANCE__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)) && defined(__MMI_LANG_TR_CHINESE__)
            case GUI_VKBD_PEN_ZHUYIN_COMMA_DOT:
                if (vk_event == g_imc_pen.zhuyin_vk_event)
                {
                    mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_zhuyin_confirm_handler, mmi_imc_pen_vk_zhuyin_confirm_handler);                
                }
                ret_val = MMI_FALSE;
                break;
        #endif    
            default:
                /* For handling the issues in which the current mode is 
                 * multitap and the characters is in highlighted state
                 * and we press key on vk 
                 */
				ret_val = MMI_FALSE;
                    mmi_imc_cancel_timer(); /* If need, we may treat with it by current state */
                    
                break;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_UP)
    {
    switch (vk_event)
    {
    case GUI_VKBD_PEN_V3_123SYM:
        if(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ENGLISH)
        {
            if(mmi_imm_set_current_input_mode(IMM_INPUT_MODE_123_SYMBOLS))
            {
                mmi_imc_change_input_mode(IMM_INPUT_MODE_123_SYMBOLS, 0);
            }
            mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EN_123SYM_1, MMI_FALSE);
        }
        else
        {
            if(mmi_imm_set_current_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC))
            {
                mmi_imc_change_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC, 0);
            }
#if defined(__MMI_IME_VK_TYPE_QWERTY__)
            if (mmi_imm_get_keyboard_type() != IMM_KEYPAD_QWERTY)
            {
                g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
                mmi_imm_config_keyboard_type(IMM_KEYPAD_QWERTY);
            }
#endif 
            mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ENGLISH, MMI_FALSE);
            mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_ACTIVE_ROW_ID_VK, 4, 0, NULL);
        }
        ret_val = MMI_TRUE;
        break;
    case GUI_VKBD_PEN_V3_123SYM_PAGE1:
        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EN_123SYM_1, MMI_FALSE);
        ret_val = MMI_TRUE;
        break;
    case GUI_VKBD_PEN_V3_123SYM_PAGE2:
        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EN_123SYM_2, MMI_FALSE);
        ret_val = MMI_TRUE;
        break;
    case GUI_VKBD_PEN_V3_123SYM_SWITCH:
        if(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_EN_123SYM_1)
        {
            mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EN_123SYM_2, MMI_FALSE);
        }
        else
        {
            mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EN_123SYM_1, MMI_FALSE);
        }
        ret_val = MMI_TRUE;
        break;

	case GUI_VKBD_PEN_V3_SHIFT_LOW_TO_UP:
	case GUI_VKBD_PEN_V3_SHIFT_UP_TO_LOW:
		//needed in case we have 2 or more vk for a language
		mmi_imc_pen_switch_vk();
		ret_val = MMI_FALSE;
		break;

    case GUI_VKBD_PEN_BAKSPACE:
        if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
        {
            ret_val = MMI_FALSE;
        }
        else
        {
            ret_val = MMI_TRUE;
        }
        mmi_imc_pen_vk_backspace(pen_event);
        if (mmi_imc_pen_is_depend_rule_input_mode(mmi_imm_get_current_input_mode()))
        {
            mmi_imc_redraw_whole_screen();
            ret_val = MMI_FALSE;
        }
        break;
    case GUI_VKBD_PEN_BRACKET:
        {
        #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   
            mmi_imc_config_smart_alphabetic_word_reselection(MMI_FALSE);
        #endif
        /* below condition is so that the canddiate list disappears when putting bracket Manik need to check  */
        #if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
			mmi_imc_key_smart_alphabetic_confirm_candidate();
		 	mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	#endif
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS, (U32)L"()", 0);

        #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   
            mmi_imc_config_smart_alphabetic_word_reselection(MMI_TRUE);
        #endif
        }
		ret_val = MMI_TRUE;
        break;
    case GUI_VKBD_PEN_CAPSLOCK:
        g_imc_pen_is_vk_caps_lock_down = MMI_TRUE;
        if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE)
        {
            UI_string_type str = NULL;
            str = mmi_imc_get_select_string_from_candidate_box();
#if defined(__MMI_IME_USER_DATABASE__)
            if (str && *str != MMI_IME_USER_DATABASE_NEW_WORD)
#endif
            {
                mmi_imc_select_candidate_from_candidate_box();
            }
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        }

		mmi_imc_pen_vk_caps_lock(pen_event);
		ret_val = MMI_TRUE;
        break;
    case GUI_VKBD_PEN_SPACE:
    #if defined(__MMI_IME_FTE_ENHANCE__) && ( defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO &&
            mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND
            )
        {
            ret_val = mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_1);
            break;
        }
        else
    #endif                
        {
            ch = 0x20;    
        }
    break;
    case GUI_VKBD_PEN_V3_HANDWRITING_SWITCH:
#if 0
        #if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
/* under construction !*/
/* under construction !*/
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
#endif
        break;
    case GUI_VKBD_PEN_V3_CHAR_I_STRING:
        {
            MMI_ASSERT(str != NULL);
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32) str, 0);
            ret_val = MMI_FALSE;
        }
        break;
    case GUI_VKBD_PEN_CHAR_I:
        if(g_imc_pen.vk_longtap == 1)
        {
            break;
        }
		if ( (input_type == IMM_INPUT_TYPE_NUMERIC_PASSWORD) || (input_type == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) ||
        (input_type == IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD) || (input_type == IMM_INPUT_TYPE_ASCII_PASSWORD) )
        {
          if ((mmi_imm_get_keyboard_type() ==  IMM_KEYPAD_QWERTY) ||  (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_LANG_NUMBER)
             || (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_TRUE) || (MMI_VIRTUAL_KEYBOARD_LANG==GUI_VIRTUAL_KEYBOARD_NUMBER) || (MMI_VIRTUAL_KEYBOARD_LANG==GUI_VIRTUAL_KEYBOARD_SYMBOL_FOR_NUM) || (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY))
		  {
                           mmi_imc_cancel_timer();
			   mmi_imc_start_timer(PASSWORD_CHARACTER_TIMEOUT, mmi_imc_pen_reset_char_password_mode_callback, mmi_imc_pen_reset_char_password_mode_callback);
			   mmi_imc_set_state(MMI_IMC_STATE_PASSWORD_PREVIEW);
		  }
		  
	}
       
        
	#if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
        if( g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY 
             && (mmi_imm_is_current_mode_smart())   
             && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN) 
             && (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
             && MMI_VIRTUAL_KEYBOARD_LANG !=GUI_VIRTUAL_KEYBOARD_TRAY)
        {
/*As in case of VK1 all events should work as down events. */
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
            ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(MMI_PEN_EVENT_DOWN,ch );
#endif
            ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(pen_event,ch );
				
        }
		 else
	#endif

    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_MAINLCD_320X480__)
        /* use space to input the tone */
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO &&
            mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND && ch == 0x20
            )
        {
            ret_val = mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_1);
        }
        else
    #endif                
        {        
            prev_state = mmi_imc_get_state();
            if(prev_state == MMI_IMC_STATE_MULTITAP)
                {
                    mmi_imc_select_candidate_from_candidate_box();
                }
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            back_up_floating_ui_style = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
        #endif
            mmi_imc_pen_vk_insert_char(ch);
            if (prev_state == mmi_imc_get_state() && prev_state == MMI_IMC_STATE_INITIAL)
            {
	            ret_val = MMI_FALSE;
            }
            if (mmi_imc_pen_is_depend_rule_input_mode(mmi_imm_get_current_input_mode()))
            {
                mmi_imc_redraw_whole_screen();
                ret_val = MMI_FALSE;
            }
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            back_up_floating_ui_style = MMI_FALSE;
            #endif
        }
        
        /* Auto caps lock switch caps mode  */
        #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        if(!mmi_imm_is_auto_capitalization_valid())
        #endif
        {
            if(mmi_imc_get_state() != MMI_IMC_STATE_SMART_CANDIDATE
                && mmi_imc_get_state() != MMI_IMC_STATE_VK_CAND
                && g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
            {
                 //g_imc_pen_vk_shift_key_state = MMI_IMC_PEN_VK_SHIFT_LOWER;

                 g_imc_pen.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                 mmi_imc_pen_set_gui_state(IME_MODE_ATTR_LOWERCASE);
                 mmi_imc_change_input_mode_according_to_capital_state(g_imc_pen.global_data_ptr->capital_state);            
                 mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK,0,0,NULL);
                 ret_val = MMI_TRUE;
            }
        }
        if (mmi_imc_pen_is_depend_rule_input_mode(mmi_imm_get_current_input_mode()))
        {
            mmi_imc_redraw_whole_screen();
            ret_val = MMI_FALSE;
        }
        break;
    case GUI_VKBD_PEN_DISPLAY_AREA:
        break;
    case GUI_VKBD_PEN_HIDE:
            ret_val = mmi_imc_pen_vk_hide();
        break;
    case GUI_VKBD_PEN_V3_MOVE_LEFT:
		
        if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
        {
			if(mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE, 0, 0))
			{
				mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_FALSE, 0);
			}else
			{
				mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MOVE_CURSOR, MMI_IMC_EDITOR_CURSOR_LEFT, 1);
			}
        }
        break;

    case GUI_VKBD_PEN_V3_MOVE_RIGHT:
        if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
        {
			if(mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE, 0, 0))
			{
				mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_FALSE, 0);
			}else
			{
				mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MOVE_CURSOR, MMI_IMC_EDITOR_CURSOR_RIGHT, 1);
			}
        }
        break;

    case GUI_VKBD_PEN_V3_SYMBOL_FULL_HALF:
        {
            ///TODO: need define english and chinese at same time
            gui_virtual_keyboard_language_enum vk_type = MMI_VIRTUAL_KEYBOARD_LANG;
            if(vk_type >= GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_1 && vk_type <= GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_3)
            {
                vk_type += GUI_VIRTUAL_KEYBOARD_EN_US_SYMBOL_1 - GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_1;
            }
            else
            {
                vk_type += GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_1 - GUI_VIRTUAL_KEYBOARD_EN_US_SYMBOL_1;
            }
            mmi_imc_pen_set_virtual_keyboard(vk_type, MMI_FALSE);
            ret_val = MMI_TRUE;
        }
        break;
        
    case GUI_VKBD_PEN_DOT_COM:
        if (!g_imc_pen.vk_longtap)
        {
            switch (mmi_imc_get_state())
            {
                case MMI_IMC_STATE_MULTITAP:
                #if(UI_DOUBLE_BUFFER_SUPPORT)
                    gui_lock_double_buffer();
                #endif
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                    ret_val = MMI_TRUE;
                #if(UI_DOUBLE_BUFFER_SUPPORT)
                    gui_unlock_double_buffer();
                #endif
                    
                default:
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".com", 0);
            }
        }
            
        break;

    
    case GUI_VKBD_PEN_V3_DOT_NET:
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".net", 0);
        ret_val = MMI_FALSE;
        break;

    case GUI_VKBD_PEN_V3_DOT_EDU:
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".edu", 0);
        ret_val = MMI_FALSE;
        break;

    case GUI_VKBD_PEN_V3_DOT_ORG:
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".org", 0);
        ret_val = MMI_FALSE;
        break;
        
    case GUI_VKBD_PEN_NEWLINE:
        
		if(mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND
            || mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND_MULTITAP
            || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING
            || mmi_imc_get_state() == MMI_IMC_STATE_SPELL_WITH_INPUT
            || mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE)
        {
#if defined(__MMI_IME_USER_DATABASE__)
            UI_string_type str;
            str = mmi_imc_get_select_string_from_candidate_box();
            if (str && *str != MMI_IME_USER_DATABASE_NEW_WORD)
#endif
            {
#if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
                if(mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE)
                {
                    mmi_imc_key_smart_alphabetic_confirm_candidate();
                }
                else
#endif
                {
                    mmi_imc_select_candidate_from_candidate_box();
                }
            }
			mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        }
		mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_NEW_LINE, 0, 0);
		ret_val = MMI_TRUE;
        break;
        
    case GUI_VKBD_PEN_NONE:
        if(mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND_MULTITAP)
        {       
            //mmi_imc_cancel_timer();       
            mmi_imc_set_state(MMI_IMC_STATE_VK_CAND);         
            ret_val = MMI_TRUE;        
        }
		if(mmi_imc_pen_dialer_callback != NULL)
		{
			mmi_imc_pen_dialer_callback(MMI_IMC_VK_DIALER_PEN_MAX, MMI_PEN_EVENT_ABORT);
		}
        break;
        
    case GUI_VKBD_PEN_SHOW:
/*included confirm cand because in order to disable highlight select
candidates*/
		if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE)
		{
			mmi_imc_key_smart_alphabetic_confirm_candidate();
		}
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
        ret_val = MMI_TRUE;
    #ifndef __MMI_EDITOR_PEN_VK_UNFOLD__
        g_imc_enlarge_vk_at_start = MMI_TRUE;
    #endif
        break;                
    #if defined(__MMI_IME_FTE_ENHANCE__)

		case GUI_VKBD_PEN_STROKE_1:
           mmi_imc_pen_vk_insert_char(0xF004);
           break;
		case GUI_VKBD_PEN_STROKE_2:
		   mmi_imc_pen_vk_insert_char(0xF001);
		   break;
		case GUI_VKBD_PEN_STROKE_3:
		   mmi_imc_pen_vk_insert_char(0xF007);
		   break;
		case GUI_VKBD_PEN_STROKE_4:
		   mmi_imc_pen_vk_insert_char(0xF002);
		   break;
		case GUI_VKBD_PEN_STROKE_5:
		   mmi_imc_pen_vk_insert_char(0xF005);
		   break;
		case GUI_VKBD_PEN_STROKE_DEPART:
		   mmi_imc_pen_vk_insert_char(0xF000);
		   break;
           
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
        case GUI_VKBD_PEN_HANDWRITING:
            ///TODO: temp for testing
            mmi_imc_pen_select_input_style();
            break;
#endif

        case GUI_VKBD_PEN_NUM_AND_SYM:
            if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                /* change from language vk */ 
               /*Need both change as here symbol 
                and number both have to be changed*/
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
				g_imc_pen.vk_type_before_num =	MMI_VIRTUAL_KEYBOARD_LANG;/*Changed by Mufaddal*/
            }
/*Case added for T9 and xT9*/
			if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state()==MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
			{
			    mmi_imc_key_smart_alphabetic_confirm_candidate();
			}
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_pen_set_virtual_keyboard(mmi_imc_pen_get_corresponding_num_symbol_vk_type(mmi_imm_get_curr_input_mode()), MMI_FALSE); 
            ret_val = MMI_TRUE;
            break;
        case GUI_VKBD_PEN_SYMBPICKER:
            if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                /* change from language vk */
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
                #if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
                if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
                {
                    mmi_imc_pen_stop_singleblock_handwriting();
                }
                #endif
                if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state()==MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
                    #if defined(__MMI_IME_USER_DATABASE__)
                    UI_string_type str;
                    str = mmi_imc_get_select_string_from_candidate_box();
                    if (str && *str != MMI_IME_USER_DATABASE_NEW_WORD)
                    #endif
                    {
                        mmi_imc_select_candidate_from_candidate_box();
                    }
                }
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_pen_set_virtual_keyboard(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()), MMI_FALSE); 
                ret_val = MMI_TRUE;
            }
            else
            {
                if (g_imc_pen.vk_type_before_num != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
                {
                    if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL))
                    {
                         if (g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_ENGLISH)
                         {
                            g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_INTERNET;
                         }
                         else if (g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE)
                         {
                            g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE;
                         }
                    }
                    mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_num, MMI_FALSE);
                    g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;                    
                }
                else if (g_imc_pen.vk_type_before_symbol != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
                {
                    if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL))
                    {
                         if (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_ENGLISH)
                         {
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_INTERNET;
                         }
                         else if (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE)
                         {
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE;
                         }
                     }
                    mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);
                    g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
                }
                if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
                {
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
                    mmi_imc_pen_start_singleblock_handwriting();
                    mmi_imc_pen_show_handwriting_vk();
#endif
                }
            }
            break;
        case GUI_VKBD_PEN_V3_SYMBOL_PAGE1:
           if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                /* change from language vk */
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
                if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state()==MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
                    #if defined(__MMI_IME_USER_DATABASE__)
                    UI_string_type str;
                    str = mmi_imc_get_select_string_from_candidate_box();
                    if (str && *str != MMI_IME_USER_DATABASE_NEW_WORD)
                    #endif
                    {
                        mmi_imc_select_candidate_from_candidate_box();
                    }
                }
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_pen_set_virtual_keyboard(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()), MMI_FALSE); 
            #if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
                if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
                {
                    mmi_imc_pen_stop_singleblock_handwriting();
                }
            #endif
                ret_val = MMI_TRUE;
            }
            break;      
        case GUI_VKBD_PEN_V3_SYMBOL_PAGE2:
            if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                /* change from language vk */
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
                if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state()==MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
                    #if defined(__MMI_IME_USER_DATABASE__)
                    UI_string_type str;
                    str = mmi_imc_get_select_string_from_candidate_box();
                    if (str && *str != MMI_IME_USER_DATABASE_NEW_WORD)
                    #endif
                    {
                        mmi_imc_select_candidate_from_candidate_box();
                    }
                }
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()) + 1), MMI_FALSE); 
                #if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
                if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
                {
                    mmi_imc_pen_stop_singleblock_handwriting();
                }
                #endif
                ret_val = MMI_TRUE;
            }
            break;  
        case GUI_VKBD_PEN_V3_SYMBOL_PAGE3:
           if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                /* change from language vk */
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
                if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state()==MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
                    #if defined(__MMI_IME_USER_DATABASE__)
                    UI_string_type str;
                    str = mmi_imc_get_select_string_from_candidate_box();
                    if (str && *str != MMI_IME_USER_DATABASE_NEW_WORD)
                    #endif
                    {
                        mmi_imc_select_candidate_from_candidate_box();
                    }
                }
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()) + 2), MMI_FALSE); 
                #if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
                if(g_imc_pen.vk_style == MMI_VK_TYPE_HW)
                {
                    mmi_imc_pen_stop_singleblock_handwriting();
                }
                #endif
                ret_val = MMI_TRUE;
            }
            break;
        case GUI_VKBD_PEN_V3_SYMBOLE_SWITCH:
            {
                gui_virtual_keyboard_language_enum sym_page1;
                gui_virtual_keyboard_language_enum current_sym_page;
                sym_page1 = mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode());
                current_sym_page = MMI_VIRTUAL_KEYBOARD_LANG;
				if(current_sym_page - sym_page1 < 0 || current_sym_page - sym_page1 > 2)
				{
					if(sym_page1 == GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_1)
					{
						sym_page1 = GUI_VIRTUAL_KEYBOARD_EN_US_SYMBOL_1;
					}
					else
					{
						sym_page1 = GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_1;
					}
				}

                mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)((current_sym_page - sym_page1 +1)%3 + sym_page1),MMI_FALSE);
            }
            break;
        case GUI_VKBD_PEN_V3_CUSTOM_SYMBOLE_SWITCH:
            if(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_1)
            {
                mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_2, MMI_FALSE);
            }
            else if(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_2)
            {                
                mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_1, MMI_FALSE);
            }
            ret_val = MMI_TRUE;
            break;
        case GUI_VKBD_PEN_V3_CUSTOM_SYMBOL_PAGE1:
        case GUI_VKBD_PEN_V3_CUSTOM_SYMBOL_PAGE2:
            if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                S32 index = vk_event - GUI_VKBD_PEN_V3_CUSTOM_SYMBOL_PAGE1;
                /* change from language vk */
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
                mmi_imc_pen_set_virtual_keyboard((gui_virtual_keyboard_language_enum)(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()) + index), MMI_FALSE); 
                ret_val = MMI_TRUE;
            }
            break;
        case GUI_VKBD_PEN_CHANGE_MODE:
            ret_val = mmi_imc_pen_vk_event_change_mode(pen_event);
            break;
    
    #else /* defined(__MMI_IME_FTE_ENHANCE__) */
        case GUI_VKBD_PEN_SYMBPICKER:
            if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
                mmi_imc_pen_set_virtual_keyboard(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()), MMI_FALSE); 
            }
            else
            {
                mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);  
                #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
				if(MMI_VIRTUAL_KEYBOARD_LANG!=GUI_VIRTUAL_KEYBOARD_THAI)
				{
				g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
				}
				
				#else
				{
				g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
				}
				#endif
            }
    #if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
		     mmi_imc_key_smart_alphabetic_confirm_candidate();
    #endif
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            ret_val = MMI_TRUE;
            break;
    #endif /* defined(__MMI_IME_FTE_ENHANCE__) */
        case GUI_VKBD_PEN_EUROSYMB:
        
#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
            if (MMI_VIRTUAL_KEYBOARD_LANG != GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS)
        {
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
            mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS, MMI_FALSE);  
        }
        else
        {
            mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);  
            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
        }
        
        #if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
            #if defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
		    mmi_imc_key_smart_alphabetic_confirm_candidate();
            #endif
        #endif
        
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
		ret_val = MMI_TRUE;
#endif /* __MMI_VKBD_EUROPEAN_SUPPORT__ */        

        break;
    case GUI_VKBD_PEN_DISPLAY_CALLBACK:
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            if (mmi_imc_change_input_mode(mmi_imm_get_next_writing_mode(), 0))
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
        break;
#if defined (__MMI_INDIC_VK__)
    case GUI_VKBD_PEN_INDIC_SLIDE1_CAPSLOCK_ON:
    case GUI_VKBD_PEN_INDIC_SLIDE1_CAPSLOCK_OFF:
    case GUI_VKBD_PEN_INDIC_SLIDE2_CAPSLOCK_ON:
    case GUI_VKBD_PEN_INDIC_SLIDE2_CAPSLOCK_OFF:
    case GUI_VKBD_PEN_INDIC_SYMBPICKER:
    case GUI_VKBD_PEN_INDIC_SLIDE1:
    case GUI_VKBD_PEN_INDIC_SLIDE2:
        mmi_imc_pen_indic_vk_event(vk_event);
		ret_val = MMI_TRUE;
        break;
#endif /* defined (__MMI_INDIC_VK__) */ 
    #if defined(__MMI_IME_FTE_ENHANCE__)/* && defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)   */     
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
        case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
          ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
            break;
    #endif
    #if defined(__MMI_IME_FTE_ENHANCE__) && ( defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) )&& defined(__MMI_LANG_TR_CHINESE__)
        case GUI_VKBD_PEN_ZHUYIN_TONE_3:
            mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_3);
            break;
        case GUI_VKBD_PEN_ZHUYIN_TONE_4:
            mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_4);
            break;
        case GUI_VKBD_PEN_V3_KEY_ZHUNYIN_TONE_2:            
                ret_val = mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_2);
            break;
        case GUI_VKBD_PEN_V3_KEY_ZHUNYIN_TONE_5:
            ret_val = mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_5);
        case GUI_VKBD_PEN_ZHUYIN_COMMA_DOT:
            {
                UI_character_type sym = 0;
                if (vk_event == g_imc_pen.zhuyin_vk_event)
                {
                    sym = mmi_imc_pen_vk_zhuyin_get_symbol(vk_event, g_imc_pen.zhuyin_vk_char_map_index + 1);
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                }
                else
                {
                    g_imc_pen.zhuyin_vk_event = vk_event;
                    sym = mmi_imc_pen_vk_zhuyin_get_symbol(vk_event, g_imc_pen.zhuyin_vk_char_map_index + 1);
                }

                if (sym)
                {
                    if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)sym, 0))
                    {
                        mmi_imc_pen_vk_zhuyin_confirm_handler();
                    }
                }
                else
                {
                    mmi_imc_pen_vk_zhuyin_confirm_handler();
                }
                mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_zhuyin_confirm_handler, mmi_imc_pen_vk_zhuyin_confirm_handler);                
                ret_val = MMI_TRUE;
            }            
            break;
    #endif /*     #if defined(__MMI_IME_FTE_ENHANCE__) && ( defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) )&& defined(__MMI_LANG_TR_CHINESE__) */
        default:
            ret_val = MMI_FALSE;
            break;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_LONG_TAP)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_BAKSPACE:
                if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
                {
                    ret_val = MMI_FALSE;
                }
                else
                {
                    ret_val = MMI_TRUE;
                }
                mmi_imc_pen_vk_backspace(pen_event);
                break;

            case GUI_VKBD_PEN_CHAR_I:
		#if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
                if( (mmi_imm_is_current_mode_smart())   
                    && (g_imc_pen.curr_mode_details->Lang_Special_Attrib & (IME_LANG_ATTR_ENGLISH_ONLY | IME_LANG_ATTR_ALPHABETIC))
                    && !mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG)) 
                {
    					ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(pen_event,ch );
    					break;
                }
        #endif
                {
                    if ((mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) && g_imc_pen.input_type != MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY)
						|| (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET && ch == '0'))
                    {
                        g_imc_pen.vk_longtap = MMI_TRUE;
                        if (mmi_imm_test_input(&ch, 1))
                        {
                            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR,ch,NULL);
                        }
                    }
                    ret_val = MMI_FALSE;
                }
                break;
            
        
            /*BELOW MENTION CASE HAS BEEN COMMENTED DUE TO CERTAIN ISSUES*/
            /*case GUI_VKBD_PEN_CAPSLOCK:
				if(mmi_imc_get_state()!=MMI_IMC_STATE_SMART_CANDIDATE)
				{
				kal_prompt_trace(MOD_MMI,"GUI_VKBD_PEN_CAPSLOCK %d",mmi_imc_get_state());
                mmi_imc_pen_vk_caps_lock(pen_event);
				}
                break;*/
            case GUI_VKBD_PEN_V3_CHANGE_MODE_BETWEEN_SMART_AND_MULTITAP:
                mmi_imc_pen_vk_change_input_mode_between_smart_and_multitap();
                g_imc_pen.vk_longtap = MMI_TRUE;
                ret_val = MMI_TRUE;
                break;

        #if defined(__MMI_IME_FTE_ENHANCE__) /*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */      
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
            ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
                break;
        #endif
        #if defined(__MMI_IME_FTE_ENHANCE__)
            case GUI_VKBD_PEN_CHANGE_MODE:            
                 ret_val = mmi_imc_pen_vk_event_change_mode(pen_event);
                break;
        #endif
            default:
                ret_val = MMI_FALSE;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_MOVE)
    {
        ret_val = MMI_FALSE;
    }
    else if (pen_event == MMI_PEN_EVENT_REPEAT)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_BAKSPACE:
                mmi_imc_pen_vk_backspace(pen_event);
				ret_val =MMI_FALSE; // no need of redraw screen by state, editor draw it itself, for IMUI no need
                break;
			case GUI_VKBD_PEN_CHAR_I:
//performance
	/*#if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
            if( (mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN))
                 ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(pen_event,ch );
            else 
        #endif*/
            if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL && ch == 0x20)
            {
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                ret_val = MMI_FALSE;
            }
            break;
        case GUI_VKBD_PEN_V3_MOVE_LEFT:
            if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
            {
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MOVE_CURSOR, MMI_IMC_EDITOR_CURSOR_LEFT, 1);
            }
            break;

        case GUI_VKBD_PEN_V3_MOVE_RIGHT:
            if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
            {
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MOVE_CURSOR, MMI_IMC_EDITOR_CURSOR_RIGHT, 1);
            }
            break;

        #if defined(__MMI_IME_FTE_ENHANCE__) /*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
                ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
                break;
        #endif
            default:
                ret_val = MMI_FALSE;
        }

    }
    else if (pen_event == MMI_PEN_EVENT_ABORT)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_BAKSPACE:
                mmi_imc_pen_vk_backspace(pen_event);
                break;
#if defined(__MMI_IME_FTE_ENHANCE__) /*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
                ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
                break;
#endif

            default:
        ret_val = MMI_FALSE;    
    }
    }
    else
    {
        MMI_ASSERT(0);
    }

    
    if (ret_val)
    {
        mmi_imc_redraw_screen_by_state();
    }

}

void mmi_imc_pen_handle_slider_close_on_123_input_mode(void)
{
    mmi_imm_input_mode_enum input_mode;
    input_mode = mmi_imm_get_default_input_mode_of_curr_writing_language();
    mmi_imm_set_current_input_mode(input_mode);
    mmi_imc_change_input_mode(input_mode,0);

    /* change from language vk */
    g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
    g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;

    if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state()==MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
    {
#if defined(__MMI_IME_USER_DATABASE__)
        UI_string_type str;
        str = mmi_imc_get_select_string_from_candidate_box();
        if (str && *str != MMI_IME_USER_DATABASE_NEW_WORD)
#endif
        {
            mmi_imc_select_candidate_from_candidate_box();
        }
    }
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    mmi_imc_pen_set_virtual_keyboard(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()), MMI_FALSE); 
}


#else
static void mmi_imc_pen_vk_event_handler(mmi_pen_event_type_enum pen_event, UI_character_type ch, gui_virtual_keyboard_pen_enum vk_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_val = MMI_TRUE;
    mmi_imc_state_enum prev_state;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_vk_event_data_struct vk_event_data;
#endif
    U32 input_type = mmi_imm_get_curr_input_type();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
    {
        mmi_imc_delete_timer();
    }

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) && (defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__))
    /* special case for jave to show symbol */
    if (mmi_imc_get_is_java_special_symbol_enabled() && (mmi_imm_get_current_writing_language() == IME_WRITING_LANG_ABC))
    {
        if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY)
        {
            if (vk_event == GUI_VKBD_PEN_CHAR_I)
            {
                switch (ch)
                {
                    /* replace the 1/4 */
                    case 0xBC:
                        ch = (UI_character_type)0xA1;
                        break;
                    /* replace the 1/2 */
                    case 0xBD:
                        ch = (UI_character_type)0xA4;
                        break;
                    /* replace the 3/4 */
                    case 0xBE:
                        ch = (UI_character_type)0xBF;
                        break;
                }
            }
        }
        else if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC)
        {
            switch (vk_event)
            {
                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_1:
                    vk_event = GUI_VKBD_PEN_CHAR_I;
                    ch = (UI_character_type)0x5B;
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_2:
                    vk_event = GUI_VKBD_PEN_CHAR_I;
                    ch = (UI_character_type)0x5D;
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_3:
                    vk_event = GUI_VKBD_PEN_CHAR_I;
                    ch = (UI_character_type)0x5E;
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_4:
                    vk_event = GUI_VKBD_PEN_CHAR_I;
                    ch = (UI_character_type)0x60;
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_5:
                    vk_event = GUI_VKBD_PEN_CHAR_I;
                    ch = (UI_character_type)0xA1;
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_6:
                    vk_event = GUI_VKBD_PEN_CHAR_I;
                    ch = (UI_character_type)0xA4;
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_7:
                    vk_event = GUI_VKBD_PEN_CHAR_I;
                    ch = (UI_character_type)0xBF;
                    break;
            }
        }
    }
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) && (defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)) */

#ifdef __MMI_IME_PLUG_IN__
    vk_event_data.character = ch;
    vk_event_data.vk_event = vk_event;

    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_VK_EVENT, (U32)pen_event, (U32)&vk_event_data) == 1)
    {
        mmi_imc_redraw_screen_by_state();
        return;
    }
#endif

#if defined(__MMI_IME_ZHUYIN_HALF_QWERTY_VK__) 
   if (pen_event != MMI_PEN_EVENT_MOVE)
   {
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO && (g_imc_pen.input_type != MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC))
        {
            if (mmi_imc_pen_vk_half_zhuyin_event_handler(pen_event, ch, vk_event))
            {
                return;
            }
        }
   }
#endif
    



/* here we can take event for smart vk and route accordingly*/
    
    if (pen_event == MMI_PEN_EVENT_DOWN)
    {    
        g_imc_pen.vk_longtap = MMI_FALSE;
		if(mmi_imc_get_state() == MMI_IMC_STATE_PASSWORD_PREVIEW)
	    {
            mmi_imc_cancel_timer();
	    }

        switch (vk_event)
        {
/* This is to take control from here to pass to xT9 */
#if defined(__MMI_IME_FTE_ENHANCE__)
    #if defined __MMI_XT9__
        case GUI_VKBD_PEN_CHAR_I:
            if( (mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode()!= IMM_INPUT_MODE_SM_PINYIN) &&  (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE))
                ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(pen_event,ch );
            break;
    #endif	
#endif


        #if defined(__MMI_IME_FTE_ENHANCE__) /*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
			case GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
			case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
			case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
#endif
                ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
                break;
        #endif
        #if defined(__MMI_IME_FTE_ENHANCE__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)) && defined(__MMI_LANG_TR_CHINESE__)
            case GUI_VKBD_PEN_ZHUYIN_COMMA_DOT:
                if (vk_event == g_imc_pen.zhuyin_vk_event)
                {
                    mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_zhuyin_confirm_handler, mmi_imc_pen_vk_zhuyin_confirm_handler);                
                }
                ret_val = MMI_FALSE;
                break;
        #endif    
            default:
                /* For handling the issues in which the current mode is 
                 * multitap and the characters is in highlighted state
                 * and we press key on vk 
                 */
				ret_val = MMI_FALSE;
                #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
               
                
				if( mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
				{
					 mmi_imc_cancel_timer();
					 mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
					 ret_val = MMI_TRUE;
				}
                wgui_virtual_keyboard_draw_from_cache();
                #endif

                {
                    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
                    MMI_BOOL temp_draw = mmi_imc_get_draw();
                    mmi_imc_config_draw(MMI_TRUE);
                    #endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) */

                    mmi_imc_cancel_timer(); /* If need, we may treat with it by current state */
                    
                    #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
                    mmi_imc_config_draw(temp_draw);        
                    #endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) */
                }
        
                #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
                wgui_virtual_keyboard_recache();
                #endif
                
                break;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_UP)
    {
    switch (vk_event)
    {
    case GUI_VKBD_PEN_BAKSPACE:
            mmi_imc_pen_vk_backspace(pen_event);
            if (mmi_imm_get_current_input_mode() ==  IMM_INPUT_MODE_MULTITAP_HINDI 
                || mmi_imm_get_current_input_mode() ==  IMM_INPUT_MODE_MULTITAP_BENGALI
                || mmi_imm_get_current_input_mode() ==  IMM_INPUT_MODE_MULTITAP_THAI)            
            {
                mmi_imc_redraw_whole_screen();
                ret_val = MMI_FALSE;
            }

		ret_val = MMI_TRUE;
        break;
    case GUI_VKBD_PEN_BRACKET:
        {
        #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   
            mmi_imc_config_smart_alphabetic_word_reselection(MMI_FALSE);
        #endif
        /* below condition is so that the canddiate list disappears when putting bracket Manik need to check  */
        #if defined __MMI_XT9__
			mmi_imc_key_smart_alphabetic_confirm_candidate();
		 	mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	#endif
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS, (U32)L"()", 0);

        #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   
            mmi_imc_config_smart_alphabetic_word_reselection(MMI_TRUE);
        #endif
        }
		ret_val = MMI_TRUE;
        break;
    case GUI_VKBD_PEN_CAPSLOCK:
		if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE)
		{
		mmi_imc_key_smart_alphabetic_confirm_candidate();
		}
		mmi_imc_pen_vk_caps_lock(pen_event);
		ret_val = MMI_TRUE;
        break;
    case GUI_VKBD_PEN_SPACE:
    #if defined(__MMI_IME_FTE_ENHANCE__) && ( defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO &&
            mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND
            )
        {
            ret_val = mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_1);
            break;
        }
        else
    #endif                
        {
            ch = 0x20;    
        }
    case GUI_VKBD_PEN_CHAR_I:
		if ( (input_type == IMM_INPUT_TYPE_NUMERIC_PASSWORD) || (input_type == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) ||
        (input_type == IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD) || (input_type == IMM_INPUT_TYPE_ASCII_PASSWORD) )
        {
          if ((mmi_imm_get_keyboard_type() ==  IMM_KEYPAD_QWERTY) ||  (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_LANG_NUMBER)
             || (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_TRUE) || (MMI_VIRTUAL_KEYBOARD_LANG==GUI_VIRTUAL_KEYBOARD_NUMBER) || (MMI_VIRTUAL_KEYBOARD_LANG==GUI_VIRTUAL_KEYBOARD_SYMBOL_FOR_NUM) || (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY))
		  {
                           mmi_imc_cancel_timer();
			   mmi_imc_start_timer(PASSWORD_CHARACTER_TIMEOUT, mmi_imc_pen_reset_char_password_mode_callback, mmi_imc_pen_reset_char_password_mode_callback);
			   mmi_imc_set_state(MMI_IMC_STATE_PASSWORD_PREVIEW);
		  }
		  
	}
	#if defined __MMI_XT9__
            if( (mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN) &&  (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)&& MMI_VIRTUAL_KEYBOARD_LANG !=GUI_VIRTUAL_KEYBOARD_TRAY)
        {
/*As in case of VK1 all events should work as down events. */
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
            ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(MMI_PEN_EVENT_DOWN,ch );
#endif
            ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(pen_event,ch );
            break;
        }
		 else
	#endif


    #if defined(__MMI_IME_FTE_ENHANCE__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
        /* use space to input the tone */
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO &&
            mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND && ch == 0x20
            )
        {
            ret_val = mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_1);
        }
        else
    #endif                
        {        
            prev_state = mmi_imc_get_state();
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            back_up_floating_ui_style = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
        #endif
            mmi_imc_pen_vk_insert_char(ch);
            if (prev_state == mmi_imc_get_state() && prev_state == MMI_IMC_STATE_INITIAL)
            {
	            ret_val = MMI_FALSE;
            }
            if (mmi_imm_get_current_input_mode() ==  IMM_INPUT_MODE_MULTITAP_HINDI 
                || mmi_imm_get_current_input_mode() ==  IMM_INPUT_MODE_MULTITAP_BENGALI
                || mmi_imm_get_current_input_mode() ==  IMM_INPUT_MODE_MULTITAP_THAI)            
            {
                mmi_imc_redraw_whole_screen();
                ret_val = MMI_FALSE;
            }

            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            back_up_floating_ui_style = MMI_FALSE;
            #endif
        }
        break;
    case GUI_VKBD_PEN_DISPLAY_AREA:
        break;
    case GUI_VKBD_PEN_HIDE:
            ret_val = mmi_imc_pen_vk_hide();
        break;
        
    case GUI_VKBD_PEN_NEWLINE:
        
        #if defined __MMI_XT9__
							mmi_imc_key_smart_alphabetic_confirm_candidate();
		 					mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
		#endif
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_NEW_LINE, 0, 0);
		ret_val = MMI_TRUE;
        break;
        
    case GUI_VKBD_PEN_NONE:
        if(mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND_MULTITAP)
        {       
            //mmi_imc_cancel_timer();       
            mmi_imc_set_state(MMI_IMC_STATE_VK_CAND);         
            ret_val = MMI_TRUE;        
        }
        break;
        
    case GUI_VKBD_PEN_SHOW:
/*included confirm cand because in order to disable highlight select
candidates*/
		if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE)
		{
			mmi_imc_key_smart_alphabetic_confirm_candidate();
		}
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_pen_setup_virtual_keyboard((sIMEModeDetails *)g_imc_pen.curr_mode_details);
        ret_val = MMI_TRUE;
    #ifndef __MMI_EDITOR_PEN_VK_UNFOLD__
        g_imc_enlarge_vk_at_start = MMI_TRUE;
    #endif
        break;                
    #if defined(__MMI_IME_FTE_ENHANCE__)
        case GUI_VKBD_PEN_ZI_STROKE_1: /* new function */
            mmi_imc_pen_vk_insert_char(0xef04);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_2: /* new function */
            mmi_imc_pen_vk_insert_char(0xef01);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_3: /* new function */
            mmi_imc_pen_vk_insert_char(0xef07);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_4: /* new function */
            mmi_imc_pen_vk_insert_char(0xef02);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_5: /* new function */
            mmi_imc_pen_vk_insert_char(0xef05);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_6: /* new function */
            mmi_imc_pen_vk_insert_char(0xef03);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_7: /* new function */
            mmi_imc_pen_vk_insert_char(0xef06);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_8: /* new function */
            mmi_imc_pen_vk_insert_char(0xef08);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_9: /* new function */
            mmi_imc_pen_vk_insert_char(0xef00);
            break;
        case GUI_VKBD_PEN_ZI_STROKE_DEPART:
            mmi_imc_pen_vk_insert_char(0x0027);
            break;
		case GUI_VKBD_PEN_STROKE_1:
           mmi_imc_pen_vk_insert_char(0xF004);
           break;
		case GUI_VKBD_PEN_STROKE_2:
		   mmi_imc_pen_vk_insert_char(0xF001);
		   break;
		case GUI_VKBD_PEN_STROKE_3:
		   mmi_imc_pen_vk_insert_char(0xF007);
		   break;
		case GUI_VKBD_PEN_STROKE_4:
		   mmi_imc_pen_vk_insert_char(0xF002);
		   break;
		case GUI_VKBD_PEN_STROKE_5:
		   mmi_imc_pen_vk_insert_char(0xF005);
		   break;
		case GUI_VKBD_PEN_STROKE_DEPART:
		   mmi_imc_pen_vk_insert_char(0xF000);
		   break;
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
        case GUI_VKBD_PEN_HANDWRITING:
            ///TODO: temp for testing
            mmi_imc_pen_select_input_style();
            break;
#endif

        case GUI_VKBD_PEN_NUM_AND_SYM:
            if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                /* change from language vk */ 
               /*Need both change as here symbol 
                and number both have to be changed*/
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
				g_imc_pen.vk_type_before_num =	MMI_VIRTUAL_KEYBOARD_LANG;/*Changed by Mufaddal*/
            }
/*Case added for T9 and xT9*/
			if(mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state()==MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
			{
			mmi_imc_key_smart_alphabetic_confirm_candidate();
			}
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_pen_set_virtual_keyboard(mmi_imc_pen_get_corresponding_num_symbol_vk_type(mmi_imm_get_curr_input_mode()), MMI_FALSE); 
            ret_val = MMI_TRUE;
            break;
        case GUI_VKBD_PEN_SYMBPICKER:
            if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                /* change from language vk */
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
            }
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_pen_set_virtual_keyboard(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()), MMI_FALSE); 
            ret_val = MMI_TRUE;
            break;        
        case GUI_VKBD_PEN_BACK_TO_LANG:
            if (g_imc_pen.vk_type_before_num != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
            {
			    if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL))
                {
                         if (g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_ENGLISH)
                         {
                            g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_INTERNET;
                         }
                         else if (g_imc_pen.vk_type_before_num == GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE)
                         {
                            g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE;
                         }
                }
                mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_num, MMI_FALSE);
                g_imc_pen.vk_type_before_num = GUI_VIRTUAL_KEYBOARD_MAX_LANG;                    
            }
            else if (g_imc_pen.vk_type_before_symbol != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
            {
				if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_URL || mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EMAIL))
                {
                         if (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_ENGLISH)
                         {
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_INTERNET;
                         }
                         else if (g_imc_pen.vk_type_before_symbol == GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE)
                         {
                            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE;
                         }
                 }
                mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);
                g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
            }
            break;
        case GUI_VKBD_PEN_CHANGE_MODE:
            ret_val = mmi_imc_pen_vk_event_change_mode(pen_event);
            break;
        case GUI_VKBD_PEN_DOT_COM:
        case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            //if (!g_imc_pen.vk_longtap)
                
            switch (mmi_imc_get_state())
            {
                case MMI_IMC_STATE_MULTITAP:
                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                    gui_lock_double_buffer();
                    #endif
			        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                    mmi_imc_redraw_screen_by_state();
			        #if(UI_DOUBLE_BUFFER_SUPPORT)
                    gui_unlock_double_buffer();
                    #endif
                    
                default:
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".com", 0);
            }
                
            break;
        case GUI_VKBD_PEN_DOT_ORG:
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".org", 0);
            break;
        case GUI_VKBD_PEN_DOT_NET:
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".net", 0);
            break;
        case GUI_VKBD_PEN_DOT_GOV:
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".gov", 0);
            break;
        case GUI_VKBD_PEN_DOT_EDU:
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".edu", 0);
            break;
        case GUI_VKBD_PEN_DOT_MIL:
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)L".mil", 0);
            break;
    
    #else /* defined(__MMI_IME_FTE_ENHANCE__) */
        case GUI_VKBD_PEN_SYMBPICKER:
            if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_FALSE)
            {
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
                mmi_imc_pen_set_virtual_keyboard(mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_get_curr_input_mode()), MMI_FALSE); 
            }
            else
            {
                mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);  
                #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
				if(MMI_VIRTUAL_KEYBOARD_LANG!=GUI_VIRTUAL_KEYBOARD_THAI)
				{
				g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
				}
				
				#else
				{
				g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
				}
				#endif
            }
    #if defined __MMI_XT9__
		     mmi_imc_key_smart_alphabetic_confirm_candidate();
    #endif
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            ret_val = MMI_TRUE;
            break;
    #endif /* defined(__MMI_IME_FTE_ENHANCE__) */
        case GUI_VKBD_PEN_EUROSYMB:
        
#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
            if (MMI_VIRTUAL_KEYBOARD_LANG != GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS)
        {
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
            mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS, MMI_FALSE);  
        }
        else
        {
            mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);  
            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
        }
        
        #if defined __MMI_XT9__
            #if defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
		    mmi_imc_key_smart_alphabetic_confirm_candidate();
            #endif
        #endif
        
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
		ret_val = MMI_TRUE;
#endif /* __MMI_VKBD_EUROPEAN_SUPPORT__ */        

        break;
    case GUI_VKBD_PEN_DISPLAY_CALLBACK:
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            if (mmi_imc_change_input_mode(mmi_imm_get_next_mode(), 0))
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
        break;
#if defined (__MMI_INDIC_VK__)
    case GUI_VKBD_PEN_INDIC_SLIDE1_CAPSLOCK_ON:
    case GUI_VKBD_PEN_INDIC_SLIDE1_CAPSLOCK_OFF:
    case GUI_VKBD_PEN_INDIC_SLIDE2_CAPSLOCK_ON:
    case GUI_VKBD_PEN_INDIC_SLIDE2_CAPSLOCK_OFF:
    case GUI_VKBD_PEN_INDIC_SYMBPICKER:
    case GUI_VKBD_PEN_INDIC_SLIDE1:
    case GUI_VKBD_PEN_INDIC_SLIDE2:
        mmi_imc_pen_indic_vk_event(vk_event);
		ret_val = MMI_TRUE;
        break;
#endif /* defined (__MMI_INDIC_VK__) */ 
    #if defined(__MMI_IME_FTE_ENHANCE__)/* && defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)   */     
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
        case GUI_VKBD_PEN_ALPHANUMERIC_SYM_PREV_PAGE:
        case GUI_VKBD_PEN_ALPHANUMERIC_SYM_NEXT_PAGE:
        case GUI_VKBD_PEN_ALPHANUMERIC_SYM_LOCK:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_1:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_2:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_3:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_4:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_5:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_6:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_7:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_8:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_9:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_10:
        case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_11:
        case GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE:
        case GUI_VKBD_PEN_ALPHANUMERIC_SYMBPICKER:  
        case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:                
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
		case GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
#endif
            ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
            break;
    #endif
    #if defined(__MMI_IME_FTE_ENHANCE__) && ( defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) )&& defined(__MMI_LANG_TR_CHINESE__)
        case GUI_VKBD_PEN_ZHUYIN_TONE_3:
            mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_3);
            break;
        case GUI_VKBD_PEN_ZHUYIN_TONE_4:
            mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_4);
            break;
        case GUI_VKBD_PEN_ZHUYIN_TONE_2_5:            
            if (g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count - 1] == MMI_IMC_SYMB_TONE_2)
            {
                ret_val = mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_5);
            }
            else
            {
                ret_val = mmi_imc_pen_vk_zhuyin_tone(MMI_IMC_SYMB_TONE_2);
            }
            break;
        case GUI_VKBD_PEN_ZHUYIN_COMMA_DOT:
            {
                UI_character_type sym = 0;
                if (vk_event == g_imc_pen.zhuyin_vk_event)
                {
                    sym = mmi_imc_pen_vk_zhuyin_get_symbol(vk_event, g_imc_pen.zhuyin_vk_char_map_index + 1);
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                }
                else
                {
                    g_imc_pen.zhuyin_vk_event = vk_event;
                    sym = mmi_imc_pen_vk_zhuyin_get_symbol(vk_event, g_imc_pen.zhuyin_vk_char_map_index + 1);
                }

                if (sym)
                {
                    if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)sym, 0))
                    {
                        mmi_imc_pen_vk_zhuyin_confirm_handler();
                    }
                }
                else
                {
                    mmi_imc_pen_vk_zhuyin_confirm_handler();
                }
                mmi_imc_restart_timer(MMI_IMC_PEN_MULTITAP_TIMER, mmi_imc_pen_vk_zhuyin_confirm_handler, mmi_imc_pen_vk_zhuyin_confirm_handler);                
                ret_val = MMI_TRUE;
            }            
            break;
    #endif /*     #if defined(__MMI_IME_FTE_ENHANCE__) && ( defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) )&& defined(__MMI_LANG_TR_CHINESE__) */
        default:
            ret_val = MMI_FALSE;
            break;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_LONG_TAP)
    {
        /* longtap only for backspace event */
        switch (vk_event)
        {
            case GUI_VKBD_PEN_BAKSPACE:
                mmi_imc_pen_vk_backspace(pen_event);
                break;

		#if defined __MMI_XT9__
				case GUI_VKBD_PEN_CHAR_I:
            if( (mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN))
					ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(pen_event,ch );
					break;
		#endif
            /*BELOW MENTION CASE HAS BEEN COMMENTED DUE TO CERTAIN ISSUES*/
            /*case GUI_VKBD_PEN_CAPSLOCK:
				if(mmi_imc_get_state()!=MMI_IMC_STATE_SMART_CANDIDATE)
				{
				kal_prompt_trace(MOD_MMI,"GUI_VKBD_PEN_CAPSLOCK %d",mmi_imc_get_state());
                mmi_imc_pen_vk_caps_lock(pen_event);
				}
                break;*/

        #if defined(__MMI_IME_FTE_ENHANCE__) /*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */      
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
            ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
                break;
        #endif
        #if defined(__MMI_IME_FTE_ENHANCE__)
            case GUI_VKBD_PEN_CHANGE_MODE:            
                 ret_val = mmi_imc_pen_vk_event_change_mode(pen_event);
                break;
        #endif
            default:
                ret_val = MMI_FALSE;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_MOVE)
    {
        ret_val = MMI_FALSE;
    }
    else if (pen_event == MMI_PEN_EVENT_REPEAT)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_BAKSPACE:
                mmi_imc_pen_vk_backspace(pen_event);
				ret_val =MMI_FALSE; // no need of redraw screen by state, editor draw it itself, for IMUI no need
                break;
	#if defined __MMI_XT9__
			case GUI_VKBD_PEN_CHAR_I:
            if( (mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN))
				ret_val = mmi_imc_pen_vk_smart_qwerty_event_handler(pen_event,ch );
				break;
	#endif

        #if defined(__MMI_IME_FTE_ENHANCE__) /*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)  */
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
                ret_val = mmi_imc_pen_vk_alphanumeric_event_handler(pen_event, vk_event);
                break;
        #endif
            default:
                ret_val = MMI_FALSE;
        }

    }
    else if (pen_event == MMI_PEN_EVENT_ABORT)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_BAKSPACE:
                mmi_imc_pen_vk_backspace(pen_event);
                break;
            default:
        ret_val = MMI_FALSE;    
    }
    }
    else
    {
        MMI_ASSERT(0);
    }

    
    if (ret_val)
    {
        mmi_imc_redraw_screen_by_state();
    }

}
#endif


#if defined (__MMI_INDIC_VK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_indic_vk_event
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_indic_vk_event(gui_virtual_keyboard_pen_enum vk_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lang_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG))
    {
        mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);  
        g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
        return;
    }

    switch(mmi_imm_get_curr_input_mode())
    {
    #if defined (__MMI_INDIC_VK_HINDI__)
        case IMM_INPUT_MODE_MULTITAP_HINDI:
        case IMM_INPUT_MODE_SMART_HINDI:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_HINDI;
            break;
    #endif /* defined (__MMI_INDIC_VK_HINDI__) */ 
    #if defined (__MMI_INDIC_VK_TAMIL__)
        case IMM_INPUT_MODE_MULTITAP_TAMIL:
        case IMM_INPUT_MODE_SMART_TAMIL:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_TAMIL;
            break;
    #endif /* defined (__MMI_INDIC_VK_TAMIL__) */ 
    #if defined (__MMI_INDIC_VK_BENGALI__)
        case IMM_INPUT_MODE_MULTITAP_BENGALI:
        case IMM_INPUT_MODE_SMART_BENGALI:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_BENGALI;
            break;
    #endif /* defined (__MMI_INDIC_VK_BENGALI__) */ 
    #if defined (__MMI_INDIC_VK_ASSAMESE__)
        case IMM_INPUT_MODE_MULTITAP_ASSAMESE:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_ASSAMESE;
            break;
    #endif /* defined (__MMI_INDIC_VK_ASSAMESE__) */     
    #if defined (__MMI_INDIC_VK_PUNJABI__)
        case IMM_INPUT_MODE_MULTITAP_PUNJABI:
        case IMM_INPUT_MODE_SMART_PUNJABI:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_PUNJABI;
            break;
    #endif /* defined (__MMI_INDIC_VK_PUNJABI__) */ 
    #if defined (__MMI_INDIC_VK_MARATHI__)
        case IMM_INPUT_MODE_MULTITAP_MARATHI:
        case IMM_INPUT_MODE_SMART_MARATHI:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_MARATHI;
            break;
    #endif /* defined (__MMI_INDIC_VK_MARATHI__) */ 
     #if defined (__MMI_INDIC_VK_GUJARATI__)
        case IMM_INPUT_MODE_MULTITAP_GUJARATI:
        case IMM_INPUT_MODE_SMART_GUJARATI:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_GUJARATI;
            break;
    #endif /* defined (__MMI_INDIC_VK_GUJARATI__) */ 
     #if defined (__MMI_INDIC_VK_KANNADA__)
        case IMM_INPUT_MODE_MULTITAP_KANNADA:
        case IMM_INPUT_MODE_SMART_KANNADA:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_KANNADA;
            break;
    #endif /* defined (__MMI_INDIC_VK_KANNADA__) */ 
    #if defined (__MMI_INDIC_VK_ORIYA__)
        case IMM_INPUT_MODE_MULTITAP_ORIYA:
        case IMM_INPUT_MODE_SMART_ORIYA:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_ORIYA;
            break;
    #endif /* defined (__MMI_INDIC_VK_ORIYA__) */ 
    #if defined (__MMI_INDIC_VK_MALAYALAM__)
        case IMM_INPUT_MODE_MULTITAP_MALAYALAM:
        case IMM_INPUT_MODE_SMART_MALAYALAM:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_MALAYALAM;
            break;
    #endif /* defined (__MMI_INDIC_VK_MALAYALAM__) */ 
    #if defined (__MMI_INDIC_VK_TELUGU__)
        case IMM_INPUT_MODE_MULTITAP_TELUGU:
        case IMM_INPUT_MODE_SMART_TELUGU:
            lang_id = GUI_VIRTUAL_KEYBOARD_LANGUAGE_ID_TELUGU;
            break;
    #endif /* defined (__MMI_INDIC_VK_TELUGU__) */ 	
        default:
            lang_id = -1;
            break;
    }

    if (lang_id >= 0)
    {
        switch (vk_event)
        {
            case GUI_VKBD_PEN_INDIC_SLIDE1_CAPSLOCK_ON:
                mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].cons_matra2), MMI_FALSE);
                break;
            case GUI_VKBD_PEN_INDIC_SLIDE2_CAPSLOCK_ON:
                mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].cons_independentvowel2),MMI_FALSE);
                break;
            case GUI_VKBD_PEN_INDIC_SLIDE1_CAPSLOCK_OFF:
                mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].cons_matra1), MMI_FALSE);
                break;
            case GUI_VKBD_PEN_INDIC_SLIDE2_CAPSLOCK_OFF:
                mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].cons_independentvowel1),MMI_FALSE);
                break;
            case GUI_VKBD_PEN_INDIC_SYMBPICKER:
                g_imc_pen.vk_type_before_symbol = MMI_VIRTUAL_KEYBOARD_LANG;
                mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].symbols), MMI_FALSE);
                break;
            case GUI_VKBD_PEN_INDIC_SLIDE1:
                if (MMI_VIRTUAL_KEYBOARD_LANG == gui_vk_indic_toggle_table[lang_id].cons_matra1)
                {
                    mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].cons_independentvowel1),MMI_FALSE);

                }
                else
                {
                    mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].cons_independentvowel2),MMI_FALSE);

                }
                break;
            case GUI_VKBD_PEN_INDIC_SLIDE2:
                if (MMI_VIRTUAL_KEYBOARD_LANG == gui_vk_indic_toggle_table[lang_id].cons_independentvowel1)                
                {
                    mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].cons_matra1), MMI_FALSE);

                }
                else
                {
                    mmi_imc_pen_set_virtual_keyboard((gui_vk_indic_toggle_table[lang_id].cons_matra2), MMI_FALSE);

                }
                break;
            default:
                mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ENGLISH, MMI_FALSE);
                break;
        }
    }
    else
    {
        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ENGLISH, MMI_FALSE);
    }
}
#endif /* #if defined (__MMI_INDIC_VK__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_icon_display_callback
 * DESCRIPTION
 *  Assign the display content to vk for change mode icon
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
static void mmi_imc_pen_vk_icon_display_callback(gui_vkbd_display_callback_type_enum *flag, PU8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_info_struct_p hint_info = NULL;
    mmi_imm_input_mode_hint_item_struct_p hint_item = NULL;
    mmi_imm_input_mode_enum mode = IMM_INPUT_MODE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hint_info = (mmi_imm_input_mode_info_struct_p)mmi_imm_get_curr_input_mode_hint_info();
    
    if (hint_info == NULL)
    {
        return;
    }

    /* reset the content */
    *flag = GUI_VKBD_DISPLAY_CALLBACK_START;
    *content = NULL;
    
    hint_item = hint_info-> hint_item_ptr;
    while ((hint_item->display_flag != MMI_IME_HINT_FLAG_NONE))
    {
        if ((hint_item->display_flag & MMI_IME_HINT_FLAG_VK_ICON))
        {
            if (hint_item->hint_type == MMI_IME_HINT_TYPE_STRING)
            {
                *flag = GUI_VKBD_DISPLAY_CALLBACK_TEXT;
                *content = (PU8)get_string(hint_item->hint_id);
            }
        
            if (hint_item->hint_type == MMI_IME_HINT_TYPE_IMAGE)
            {
                *flag = GUI_VKBD_DISPLAY_CALLBACK_IMG;
                *content = get_image(hint_item->hint_id);
            }
        }
        hint_item ++;
    }

    /* add some special case for symbol vk */
    switch (MMI_virtual_keyboard.lang_type)
    {
        case GUI_VIRTUAL_KEYBOARD_SYMBOL:
        case GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS:
            *flag = GUI_VKBD_DISPLAY_CALLBACK_IMG;
        #if defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_480X800__)
            *content = get_image(IMG_VKBD_CUSTOM_IM_ICON_EN_SYM);            
        #endif        
            break;
        case GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL:
            #if defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)
            mode = mmi_imm_get_curr_input_mode();
            /* because the vk for stroke input is symbol vk, we have to handle it. */
            if ( mode != IMM_INPUT_MODE_TR_STROKE || mode!= IMM_INPUT_MODE_SM_STROKE || mode!= IMM_INPUT_MODE_HK_STROKE)
            {
                *flag = GUI_VKBD_DISPLAY_CALLBACK_IMG;
            #if defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_480X800__)
                *content = get_image(IMG_VKBD_CUSTOM_IM_ICON_CH_SYM);            
            #endif  
            }
            #endif /* defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__) */
            break;
        case GUI_VIRTUAL_KEYBOARD_NUMBER:
            /* no such vk support or hint message support */
            if (*flag == GUI_VKBD_DISPLAY_CALLBACK_START)
            {
                *flag = GUI_VKBD_DISPLAY_CALLBACK_IMG;
            #if defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_480X800__)
                *content = get_image(IMG_VKBD_CUSTOM_IM_ICON_NUM);            
            #endif          
            }
            break;
    }
}
#elif defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_icon_display_callback
 * DESCRIPTION
 *  Assign the display content to vk for change mode icon
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_vk_icon_display_callback(
              U32 pen_symbol,
              gui_virtual_keyboard_display_callback_type_enum *flag,
              PU8 *text,
              PU8 *image,
              gui_virtual_keyboard_key_state_enum key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) && (defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__))
    /* process the display icom for the special case of Java to show symbol */
    if (mmi_imc_get_is_java_special_symbol_enabled() && (mmi_imm_get_current_writing_language() == IME_WRITING_LANG_ABC))
    {
        if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY)
        {
            switch (pen_symbol)
            {
                /* replace the 1/4 */
                case 0x000000BC:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A1_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A1_H);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A1_D);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_POPUP)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A1_L);
                    }
                    break;
                /* replace the 1/2 */
                case 0x000000BD:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A4_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A4_H);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A4_D);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_POPUP)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A4_L);
                    }
                    break;
                /* replace the 3/4 */
                case 0x000000BE:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00BF_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00BF_H);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00BF_D);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_POPUP)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00BF_L);
                    }
                    break;
            }
        }
        else if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC)
        {
            switch (pen_symbol)
            {
                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_1:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005B_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005B_H);  
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005B_D);
                    }
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_2:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005D_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005D_H);  
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005D_D);
                    }
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_3:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005E_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005E_H);  
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005E_D);
                    }
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_4:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_0060_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_0060_H);  
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_0060_D);
                    }
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_5:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A1_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A1_H);  
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A1_D);
                    }
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_6:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A4_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A4_H);  
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A4_D);
                    }
                    break;

                case GUI_VKBD_PEN_ALPHANUMERIC_EMOTION_7:
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00BF_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00BF_H);  
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00BF_D);
                    }
                    break;
            }
        }
    }
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) && (defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)) */

    switch(pen_symbol)
    {
     //#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)   
        case GUI_VKBD_PEN_ALPHANUMERIC_SYM_LOCK:
            *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
            if (g_imc_pen.is_symbol_lock)
            {
                if (key_state == GUI_VK_KEY_STATE_NORMAL)
                {
                    *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_SYM_LOCK_N);
                }
                else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                {
                    *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_SYM_LOCK_H);                
                }
                else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                {
                    *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_SYM_LOCK_D);                
                }
            }
            else
            {
                if (key_state == GUI_VK_KEY_STATE_NORMAL)
                {
                    *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_SYM_UNLOCK_N);
                }
                else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                {
                    *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_SYM_UNLOCK_H);                
                }
                else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                {
                    *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_SYM_UNLOCK_D);                
                }
            }
            break;
     //#endif       
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
        case GUI_VKBD_PEN_HANDWRITING:
            *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
            if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY)
            {
                if (mmi_imc_pen_get_input_style_list(NULL, NULL, 0, NULL) == 1)
                {
                    /* there is only qwerty vk */
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_D);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_D);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_D);                
                    }
                }
                else if (mmi_imc_pen_get_input_style_list(NULL, NULL, 0, NULL) == 2)
                {
                #if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
                    if (!mmi_imc_is_rotated())
                    {
                        /* there are qwerty and alphanumeric vk */
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_MATRIX_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_MATRIX_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_MATRIX_D);                
                        }
                    }
                    else
                #endif
                    {
                    #if !defined(__NO_HANDWRITING__)
                        if (!mmi_imc_is_handwriting_disabled())
                        {
                            /* there are qwerty and handwriting vk */
                            if (key_state == GUI_VK_KEY_STATE_NORMAL)
                            {
                                *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_N);
                            }
                            else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                            {
                                *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_H);                
                            }
                            else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                            {
                                *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_D);                
                            }
                        }
                    #endif
                    }
                }
                else if (mmi_imc_pen_get_input_style_list(NULL, NULL, 0, NULL) == 3)
                {
                    /* there are qwerty, alphanumeric and handwriting vk */
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_OPTION_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_OPTION_H);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_OPTION_D);                
                    }
                }
            }
        #if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__) 
            else if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC)
            {
                if (mmi_imc_pen_get_input_style_list(NULL, NULL, 0, NULL) == 2)
                {
                    /* there are qwerty and alphanumeric vk */
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_QWERTY_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_QWERTY_H);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_QWERTY_D);                
                    }                
                }
                else if (mmi_imc_pen_get_input_style_list(NULL, NULL, 0, NULL) == 3)
                {
                    /* there are qwerty, alphanumeric and handwriting vk */
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_OPTION_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_OPTION_H);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_OPTION_D);                
                    }
                }
            }
        #endif
        #if !defined(__NO_HANDWRITING__)  
            else if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_HW)
            {
                if (mmi_imc_pen_get_input_style_list(NULL, NULL, 0, NULL) == 2)
                {
                    /* there are qwerty and handwriting vk */
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_QWERTY_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_QWERTY_H);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_QWERTY_D);                
                    }
                }
                else if (mmi_imc_pen_get_input_style_list(NULL, NULL, 0, NULL) == 3)
                {
                    /* there are qwerty, alphanumeric and handwriting vk */
                    if (key_state == GUI_VK_KEY_STATE_NORMAL)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_OPTION_N);
                    }
                    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_OPTION_H);                
                    }
                    else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                    {
                        *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_OPTION_D);                
                    }
                }
            }
        #endif
            break;
        case GUI_VKBD_PEN_BACK_TO_LANG:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:    
            *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG;
            /*if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY)*/
            {
                switch (mmi_imm_get_curr_input_mode())
                {
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_ABC:
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_UPPERCASE_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_UPPERCASE_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_UPPERCASE_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_FIRST_UPPERCASE_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_FIRST_UPPERCASE_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_FIRST_UPPERCASE_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_ABC:
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_123:
                    case IMM_INPUT_MODE_123_SYMBOLS:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_NUMBER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_NUMBER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_NUMBER_D);                
                        }
                        break;
                #if defined(__MMI_LANG_VIETNAMESE__)
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_UPPER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_LOWER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_LOWER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_LOWER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_VIETNAMESE:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_FIRST_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_FIRST_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_FIRST_UPPER_D);                
                        }
                        break;
                #endif /* defined(__MMI_LANG_VIETNAMESE__) */
               #if defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__)
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_SA_PORTUGUESE:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_UPPER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_LOWER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_LOWER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_LOWER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_PORTUGUESE:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_FIRST_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_FIRST_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_FIRST_UPPER_D);                
                        }
                        break;
                #endif /* defined(__MMI_LANG_PORTUGUESE__) */
               #if defined(__MMI_LANG_ARABIC__)
                    case IMM_INPUT_MODE_MULTITAP_ARABIC:
                    case IMM_INPUT_MODE_SMART_ARABIC:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_AR_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_AR_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_AR_UPPER_D);                
                        }
                        break;
              #endif /* defined(__MMI_LANG_ARABIC__) */
               #if defined(__MMI_LANG_THAI__)
                    case IMM_INPUT_MODE_MULTITAP_THAI:
                    case IMM_INPUT_MODE_SMART_THAI:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TH_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TH_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TH_UPPER_D);                
                        }
                        break;
              #endif /* defined(__MMI_LANG_THAI__) */
              #if defined(__MMI_LANG_HINDI__)
                    case IMM_INPUT_MODE_MULTITAP_HINDI:
                    case IMM_INPUT_MODE_SMART_HINDI:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_HI_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_HI_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_HI_UPPER_D);                
                        }
                        break;
              #endif /* defined(__MMI_LANG_HINDI__) */
              #if defined(__MMI_LANG_BENGALI__)
                    case IMM_INPUT_MODE_MULTITAP_BENGALI:
                    case IMM_INPUT_MODE_SMART_BENGALI:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_BN_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_BN_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_BN_UPPER_D);                
                        }
                        break;
              #endif /* defined(__MMI_LANG_BENGALI__) */
				#if defined(__MMI_LANG_MALAY__)
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_MALAY:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_UPPER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_MALAY:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_LOWER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_LOWER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_LOWER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_FIRST_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_FIRST_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_FIRST_UPPER_D);                
                        }
                        break;
                #endif /* defined(__MMI_LANG_MALAY__) */
                        #if defined(__MMI_LANG_RUSSIAN__)
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_UPPER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_LOWER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_LOWER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_LOWER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_FIRST_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_FIRST_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_FIRST_UPPER_D);                
                        }
                        break;
                #endif /* defined(__MMI_LANG_RUSSIAN__) */
                        	#if defined(__MMI_LANG_TURKISH__)
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_UPPER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_LOWER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_LOWER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_LOWER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_FIRST_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_FIRST_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_FIRST_UPPER_D);                
                        }
                        break;
                #endif /* defined(__MMI_LANG_TURKISH__) */

                                #if defined(__MMI_LANG_INDONESIAN__)
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_UPPER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_LOWER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_LOWER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_LOWER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_FIRST_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_FIRST_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_FIRST_UPPER_D);                
                        }
                        break;
                #endif /* defined(__MMI_LANG_INDONESIAN__) */
                                #if defined(__MMI_LANG_SPANISH__) || defined (__MMI_LANG_SA_SPANISH__)
                    case IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH:
                    case IMM_INPUT_MODE_SMART_UPPERCASE_SA_SPANISH:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_UPPER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH:
                    case IMM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_LOWER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_LOWER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_LOWER_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH:
                    case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_SPANISH:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_FIRST_UPPER_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_FIRST_UPPER_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_FIRST_UPPER_D);                
                        }
                        break;
                #endif /* defined(__MMI_LANG_SPANISH__) */
                #if defined(__MMI_LANG_SM_CHINESE__)
                    case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
                    case IMM_INPUT_MODE_SM_PINYIN:
                    case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:    
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PINYIN_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PINYIN_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PINYIN_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
                    case IMM_INPUT_MODE_SM_STROKE:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SM_STROKE_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SM_STROKE_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SM_STROKE_D);                
                        }
                        break;
                #endif
                #if defined(__MMI_LANG_TR_CHINESE__)
                    case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO :
                    case IMM_INPUT_MODE_TR_BOPOMO:
                    case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:    
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ZHUYIN_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ZHUYIN_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ZHUYIN_D);                
                        }
                        break;
                    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
                    case IMM_INPUT_MODE_TR_STROKE:
                        if (key_state == GUI_VK_KEY_STATE_NORMAL)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TR_STROKE_N);
                        }
                        else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TR_STROKE_H);                
                        }
                        else if (key_state == GUI_VK_KEY_STATE_DISABLE)
                        {
                            *image = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TR_STROKE_D);                
                        }
                        break;
                #endif
                }
            }
            //else if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC)
            //{

            //}
            break;
    }
}
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__ */

    
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__

void mmi_imc_pen_vk_icon_display_callback(
              U32 pen_symbol
              )
{
}

#endif
    
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_hide
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_vk_hide(void)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_pen_process_before_changing_input_mode();

    #if defined(__MMI_IME_FTE_ENHANCE__) || defined( __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__  )
    #if !defined(__NO_HANDWRITING__)    
        if (mmi_imc_get_single_block_handwriting_state())
        {
            mmi_imc_pen_stop_singleblock_handwriting();
        }
    #endif
        g_imc_pen.is_hide_by_vk = MMI_TRUE;
        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_VK_ON);		
    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
    #endif
        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_VK_HIDE, 0, 0);
    #else /* defined(__MMI_IME_FTE_ENHANCE__) */
        g_imc_pen.vk_type_before_tray = MMI_VIRTUAL_KEYBOARD_LANG;
        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);  /* TODO: Setup current tray type by user ? */
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    #ifndef __MMI_EDITOR_PEN_VK_UNFOLD__
        g_imc_enlarge_vk_at_start = MMI_FALSE;
    #endif

    #endif /* defined(__MMI_IME_FTE_ENHANCE__) */
    if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
    {
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
        redraw_right_softkey();
        mmi_imc_pen_softkey_up_post_hdlr(NULL);
    }
    return MMI_TRUE;
}

#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_switch_vk
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_switch_vk(void)
{

	switch(MMI_VIRTUAL_KEYBOARD_LANG)
	{
		case GUI_VIRTUAL_KEYBOARD_TH_TH:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TH_TH_SHIFT, MMI_FALSE); 
			break;
		case GUI_VIRTUAL_KEYBOARD_TH_TH_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TH_TH, MMI_FALSE); 
			break;
		case GUI_VIRTUAL_KEYBOARD_HI_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_HI_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_HI_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_HI, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_PA_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PA_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_PA_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PA_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_TE_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TE_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_TE_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TE_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_TA_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TA_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_TA_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TA_IN, MMI_FALSE);
			break;

		case GUI_VIRTUAL_KEYBOARD_BE_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_BE_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_BE_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_BE_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_MR_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_MR_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_MR_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_MR_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_UR_PK:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_UR_PK_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_UR_PK_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_UR_PK, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_MY_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_MY_IN_SHIFT, MMI_FALSE); 
			break;
		case GUI_VIRTUAL_KEYBOARD_MY_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_MY_IN, MMI_FALSE); 
			break;
		case GUI_VIRTUAL_KEYBOARD_KM_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_KM_IN_SHIFT, MMI_FALSE); 
			break;
		case GUI_VIRTUAL_KEYBOARD_KM_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_KM_IN, MMI_FALSE); 
			break;
		case GUI_VIRTUAL_KEYBOARD_AS_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_AS_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_AS_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_AS_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_KN_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_KN_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_KN_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_KN_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_ML_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ML_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_ML_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ML_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_GU_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_GU_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_GU_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_GU_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_LO_IN:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_LO_IN_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_LO_IN_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_LO_IN, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_HY_AM:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_HY_AM_SHIFT, MMI_FALSE);
			break;
		case GUI_VIRTUAL_KEYBOARD_HY_AM_SHIFT:
			mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_HY_AM, MMI_FALSE);
			break;
	}
    mmi_imc_redraw_whole_screen();
}

#endif

#if defined __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
static void mmi_imc_pen_set_gui_state(U16 new_caps_attr)
{
    toggle_state_id_mapping_enum    gui_vk_toggle_state = GUI_VIRTUAL_KEYBOARD_SHIFT_KEY_LOWER; 
    switch (new_caps_attr)
    {
    case IME_MODE_ATTR_UPPERCASE:
        g_imc_pen.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
        gui_vk_toggle_state = GUI_VIRTUAL_KEYBOARD_SHIFT_KEY_UP_STABLE;
        break;
    case IME_MODE_ATTR_TITLECASE:
        g_imc_pen.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
        gui_vk_toggle_state = GUI_VIRTUAL_KEYBOARD_SHIFT_KEY_UP_ONCE;
        break;
    case IME_MODE_ATTR_LOWERCASE:
        g_imc_pen.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
        gui_vk_toggle_state = GUI_VIRTUAL_KEYBOARD_SHIFT_KEY_LOWER;
        break;
    }
    mmi_imc_pen_set_vk_shift_state(gui_vk_toggle_state);
}

static void mmi_imc_pen_vk_caps_lock(mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 old_caps_attrib, new_caps_attrib = IME_MODE_ATTR_LOWERCASE;
    const sIMEModeDetails *mode_details_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (pen_event)
    {
    case MMI_PEN_EVENT_DOWN:
        break;
    case MMI_PEN_EVENT_UP:   
        /* move to next state of caps key */
        old_caps_attrib = g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_CASE_MASK;
        switch (old_caps_attrib)
        {
        case IME_MODE_ATTR_UPPERCASE:
            new_caps_attrib = IME_MODE_ATTR_LOWERCASE;                
            break;
        case IME_MODE_ATTR_LOWERCASE:
            new_caps_attrib = IME_MODE_ATTR_TITLECASE;                
            break;
        case IME_MODE_ATTR_TITLECASE:
            new_caps_attrib = IME_MODE_ATTR_UPPERCASE;
            break;
        default:
            MMI_ASSERT(FALSE);
            break;
        }
        /* skip auto caps for no title case*/
        if (new_caps_attrib == IME_MODE_ATTR_TITLECASE)
        {   
            if (mmi_imm_does_current_type_support_titlecase() == MMI_FALSE || g_imc_pen.curr_mode_details->lang_id == IME_WRITING_LANG_HABC)
            {
                new_caps_attrib = IME_MODE_ATTR_UPPERCASE;
            }
            else
            {
                mode_details_ptr = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_get_curr_input_mode(), MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER);
                if (!mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
                {
                    new_caps_attrib = IME_MODE_ATTR_UPPERCASE;
                }
            }
        }
        mmi_imc_pen_set_gui_state(new_caps_attrib);
        mmi_imc_change_input_mode_according_to_capital_state(g_imc_pen.global_data_ptr->capital_state);
		mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK, 0, 0, NULL);
        mmi_imc_redraw_screen_by_state();
        break;
    }
}

#else

static void mmi_imc_pen_set_gui_state(U16 new_caps_attr)
{
    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_caps_lock
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_vk_caps_lock(mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32  temp_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            break;
        case MMI_PEN_EVENT_UP:
        #if defined(__MMI_IME_FTE_ENHANCE__)    
        #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
            if (g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
            {
                temp_mode = IME_HAND_WRITING_GET_CAPS_LOCK_INPUT_MODE((g_imc_pen.curr_mode_details->Handwriting_Attrib));
                switch(g_imc_pen.vk_cap_state)
                {
                    case MMI_IMC_PEN_VK_CAPITAL_AUTO:
                        if (!g_imc_pen.vk_longtap)
                        {
                            g_imc_pen.vk_cap_state = MMI_IMC_PEN_VK_TEMP_CAPS_LOCK;
                            
                            if (g_imc_pen.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER ||
                                g_imc_pen.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_UPPER)
                            {
                                mmi_imc_pen_set_virtual_keyboard_by_capital_state(IME_MODE_ATTR_LOWERCASE);
                            }
                            else
                            {
                                mmi_imc_pen_set_virtual_keyboard_by_capital_state(IME_MODE_ATTR_UPPERCASE);
                            }
                        }
                        break;
                    case MMI_IMC_PEN_VK_CAPS_LOCK:
                        if (!g_imc_pen.vk_longtap)
                        {
                            g_imc_pen.vk_cap_state = MMI_IMC_PEN_VK_CAPITAL_AUTO;    
                            mmi_imc_pen_setup_virtual_keyboard(g_imc_pen.curr_mode_details);
                        }
                        break;
                    case MMI_IMC_PEN_VK_TEMP_CAPS_LOCK:
                        if (!g_imc_pen.vk_longtap)
                        {
                            g_imc_pen.vk_cap_state = MMI_IMC_PEN_VK_CAPITAL_AUTO;    
                            mmi_imc_pen_setup_virtual_keyboard(g_imc_pen.curr_mode_details);
                        }
                        break;
                    default:
                        MMI_ASSERT(0);
                }

                if (mmi_imm_is_change_input_mode_enabled())
				{
					if (mmi_imm_set_current_input_mode((mmi_imm_input_mode_enum)temp_mode))
					{

						if (mmi_imc_change_input_mode((mmi_imm_input_mode_enum)temp_mode, 0))
							mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
					}
                }
            }
            else         
        #endif
        #endif
            {
    /* TODO: Disable when Quick search editor */
                temp_mode = IME_HAND_WRITING_GET_CAPS_LOCK_INPUT_MODE((g_imc_pen.curr_mode_details->Handwriting_Attrib));

               #if defined(__MMI_LANG_HINDI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
                if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_MULTITAP_HINDI
                || mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SMART_HINDI)
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_HINDI)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_HINDI_LOWERCASE, MMI_FALSE);
                    }
                    else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_HINDI_LOWERCASE)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_HINDI, MMI_FALSE);
                    }
                }
                else
#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */
            #endif /* defined(__MMI_LANG_HINDI__) */	
		    #if defined(__MMI_LANG_BENGALI__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
                if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_MULTITAP_BENGALI
                || mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SMART_BENGALI)
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BENGALI)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_BENGALI_LOWERCASE, MMI_FALSE);
                    }
                    else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BENGALI_LOWERCASE)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_BENGALI, MMI_FALSE);
                    }
                }
                else
#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */

            #endif /* defined(__MMI_LANG_BENGALI__) */
            #if defined(__MMI_LANG_THAI__)
                if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_MULTITAP_THAI
                || mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SMART_THAI)
                {
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
                    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_THAI)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL, MMI_FALSE);
                    }
                    else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_THAI, MMI_FALSE);
                    }
#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) */
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
                    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_THAI)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_THAI_LOWERCASE, MMI_FALSE);
                    }
                    else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_THAI_LOWERCASE)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_THAI, MMI_FALSE);
                    }
#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */
                }
                else
            #endif /* defined(__MMI_LANG_THAI__) */	
                    #if defined(__MMI_LANG_ARABIC__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
                if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_MULTITAP_ARABIC
                || mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SMART_ARABIC)
                {
                    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ARABIC)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ARABIC_LOWERCASE, MMI_FALSE);
                    }
                    else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ARABIC_LOWERCASE)
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ARABIC, MMI_FALSE);
                    }
                }
                else
#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */
            #endif /* defined(__MMI_LANG_ARABIC__) */
                if (mmi_imm_is_change_input_mode_enabled())
				{
					if (mmi_imm_set_current_input_mode((mmi_imm_input_mode_enum)temp_mode))
					{
						if (mmi_imc_change_input_mode((mmi_imm_input_mode_enum)temp_mode, 0))
                                                #if defined __MMI_IME_SMART_QWERTY_VK_INPUT__
							mmi_imc_key_smart_alphabetic_confirm_candidate();
		 					mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
						#endif
							mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
					}
                }

            }
            
            break;
        case MMI_PEN_EVENT_LONG_TAP:
        #if defined(__MMI_IME_FTE_ENHANCE__)    
        #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
            if (g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
            {
                switch (g_imc_pen.vk_cap_state)
                {
                    case MMI_IMC_PEN_VK_CAPITAL_AUTO:
                        g_imc_pen.vk_cap_state = MMI_IMC_PEN_VK_CAPS_LOCK;                            
                        if (g_imc_pen.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER ||
                            g_imc_pen.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_UPPER)
                        {
                            mmi_imc_pen_set_virtual_keyboard_by_capital_state(IME_MODE_ATTR_LOWERCASE);
                        }
                        else
                        {
                            mmi_imc_pen_set_virtual_keyboard_by_capital_state(IME_MODE_ATTR_UPPERCASE);
                        }
                        break;
                    case MMI_IMC_PEN_VK_CAPS_LOCK:
                        g_imc_pen.vk_cap_state = MMI_IMC_PEN_VK_CAPITAL_AUTO;    
                        mmi_imc_pen_setup_virtual_keyboard(g_imc_pen.curr_mode_details);
                        break;
                    case MMI_IMC_PEN_VK_TEMP_CAPS_LOCK:
                        g_imc_pen.vk_cap_state = MMI_IMC_PEN_VK_CAPITAL_AUTO;
                        mmi_imc_pen_setup_virtual_keyboard(g_imc_pen.curr_mode_details);                            
                        break;
                    default:
                        MMI_ASSERT(0);
                }
                g_imc_pen.vk_longtap = MMI_TRUE;
            }
        #endif /* defined(__MMI_IME_AUTO_CAPITALIZATION__) */
        #endif /* defined(__MMI_IME_FTE_ENHANCE__)  */
        break;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_insert_char
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_vk_insert_char(UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum input_mode;
	#if !defined(__MMI_IME_FTE_ENHANCE__)
    gui_virtual_keyboard_language_enum vk_type;
    #endif
    MMI_BOOL has_candidate = MMI_FALSE;
    mmi_imc_message_struct imc_msg;
    UI_character_type first_char;
    MMI_BOOL ret_val = MMI_FALSE;        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    input_mode = mmi_imm_get_curr_input_mode();


    /* to make sure signed character works fine */
    if (input_mode == IMM_INPUT_MODE_SIGNED_123 || input_mode ==IMM_INPUT_MODE_SIGNED_FLOAT_123)
    {
        imc_msg.message_id    = MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION;
        imc_msg.param_0       = 0;
        imc_msg.param_1       = 0;
        
        first_char = (UI_character_type)mmi_imc_send_message( &imc_msg);
        
        if ( char_code == '-')
        {
            if (first_char == (UI_character_type) '-')
            {
                /* negative to positive */
                imc_msg.message_id =  MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION;
                mmi_imc_send_message( &imc_msg );
                return MMI_FALSE;
            }
            else
            {
                /*  positive  to negative */
                imc_msg.message_id    = MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION;
                imc_msg.param_1       =  (UI_character_type)('-');
                mmi_imc_send_message( &imc_msg  );
                return MMI_TRUE;
            }
        }
        else
	{	
            if (first_char == (UI_character_type) '-')
            /* return if insertion is for first place*/
            /* for non '-' characters ensures that they are not being inserted before - sign */
            {
                if(!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR, (U32)&first_char, 0))
                {
                    UI_editor_play_tone_cannot_insert();
                    return MMI_FALSE;
                }
            }
	}
    }

#if !defined(__MMI_IME_FTE_ENHANCE__)

    mmi_imc_pen_get_vk_type(g_imc_pen.curr_mode_details, &vk_type, &has_candidate);

    if (has_candidate && mmi_ime_word_code_to_symbol(char_code) != 0xFF)
    {
        if (MMI_VIRTUAL_KEYBOARD_LANG  != GUI_VIRTUAL_KEYBOARD_PINYIN 
             && MMI_VIRTUAL_KEYBOARD_LANG != GUI_VIRTUAL_KEYBOARD_BOPOMO)
        {
            mmi_imc_pen_set_virtual_keyboard(vk_type, has_candidate);
        }
        
        if ((MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_SPELLING_DIRECTLY, 0, 0) == MMI_FALSE)
        {
			if (g_imc_pen.global_data_ptr->symb_count + 1 <= MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN
            	&& ((MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_PINYIN && g_imc_pen.global_data_ptr->symb_count + 1 <= MMI_IMC_PEN_MAX_STRING_IN_DIPLAY_AREA_VK_PINYIN)
            	    ||(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO && g_imc_pen.global_data_ptr->symb_count + 1 <= MMI_IMC_PEN_MAX_STRING_IN_DIPLAY_AREA_VK_ZHUYIN)))
            {
				g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count++] = mmi_ime_word_code_to_symbol(char_code);

				if (mmi_imc_pen_set_vk_candidate() == MMI_FALSE)
				{   /* Resume previours candidate */
					if (--g_imc_pen.global_data_ptr->symb_count)
					{
						while (g_imc_pen.global_data_ptr->symb_count)
						{
							if (mmi_imc_pen_set_vk_candidate() == MMI_TRUE)
							{
								break;
							}	
							else
							{
								g_imc_pen.global_data_ptr->symb_count--;
							}	
						}
					}
					g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count] = 0;
					return MMI_FALSE;
				}
				else
				{
                    return MMI_TRUE;
				}	
			}
			else
			{
				return MMI_FALSE;
			}	
        }
        else
        {
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)char_code, 0);
            mmi_imc_clear_symbol_buffer();
            return MMI_FALSE;
        }
    }
    else
#else /* !defined(__MMI_IME_FTE_ENHANCE__) */ 
    if (  /*(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_PINYIN || 
        MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO ||
        MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TR_STROKE ||
        MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_SM_STROKE)*/
        mmi_imm_is_chinese_input_method(mmi_imm_get_curr_input_mode()) && 
        mmi_ime_word_code_to_symbol(char_code) != 0xFF)
    {
        if ((MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_SPELLING_DIRECTLY, 0, 0) == MMI_FALSE)
        {
            if (g_imc_pen.global_data_ptr->symb_count + 1 < MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE)
            {
                if (((char_code == MMI_IMC_PEN_COMPOSITION_DEPART_TOKEN) ||
                (char_code == 0x002D))
                #if  defined (__MMI_ZI_CHINESE_PHRASE_LEVEL_INPUTS__) || defined(__MMI_CSTAR_PHRASE_INPUT__)
                    && (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL || g_imc_pen.global_data_ptr->symb_count == 0)
                #endif
                    )
                {
                    /* the depart token in initial state is taken as a normal symbol. */
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)char_code, 0);
                    #if defined(__MMI_IME_FTE_ENHANCE__)
                    ret_val = mmi_imc_pen_vk_back_to_lang();
                    #endif /* defined(__MMI_IME_FTE_ENHANCE__) */
                    
                    return MMI_FALSE;
                }
                else
                {                
                    if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
                    {
                        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                    }
                    g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count++] = mmi_ime_word_code_to_symbol(char_code);
                                      
                  if (mmi_imc_pen_set_vk_candidate() == MMI_FALSE)
                      {   /* Resume previours candidate */
                          if (--g_imc_pen.global_data_ptr->symb_count)
                              {
                                  while (g_imc_pen.global_data_ptr->symb_count)
				  {
                                      if (mmi_imc_pen_set_vk_candidate() == MMI_TRUE)
                                      {
                                          break;
                                      }
                                       else
                                       {
                                           g_imc_pen.global_data_ptr->symb_count --;
                                       }	
                                   }
                        }
                        g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count] = 0;
                        return MMI_FALSE;
                        }
                        else
                        {
                            return MMI_TRUE;
                        }	                  
                }
            }
            else
            {
                return MMI_FALSE;
            }	
        }
        else
        {
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)char_code, 0);
            #if defined(__MMI_IME_FTE_ENHANCE__)
            ret_val = mmi_imc_pen_vk_back_to_lang();
            #endif /* defined(__MMI_IME_FTE_ENHANCE__) */
            mmi_imc_clear_symbol_buffer();
            return MMI_FALSE;
        }
    }
    else
#endif /* !defined(__MMI_IME_FTE_ENHANCE__) */       
    {
        if (mmi_imc_get_state() != MMI_IMC_STATE_INITIAL)
        {
            
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            if (has_candidate && back_up_floating_ui_style)
            {
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
            }
            #endif
        }

           

    
    {
        U32 input_type = mmi_imm_get_curr_input_type();

        if ((input_type == IMM_INPUT_TYPE_NUMERIC_PASSWORD) || (input_type == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) ||
        (input_type == IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD) || (input_type == IMM_INPUT_TYPE_ASCII_PASSWORD))
        {
			 if ((mmi_imm_get_keyboard_type() ==  IMM_KEYPAD_QWERTY) ||  (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_LANG_NUMBER)
             || (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG) == MMI_TRUE) || (MMI_VIRTUAL_KEYBOARD_LANG==GUI_VIRTUAL_KEYBOARD_NUMBER) || (MMI_VIRTUAL_KEYBOARD_LANG==GUI_VIRTUAL_KEYBOARD_SYMBOL_FOR_NUM) || (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY))
			 {
              /* for password input we want to show preview */
			  mmi_imc_pen_show_preview_password_mode(char_code);
			 }
			 else
			 {
                              mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)char_code, 0);
			 }
                
        }
        else
        {
			if(mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE)
			{
				mmi_imc_select_candidate_from_candidate_box(); 
			}
			else if(mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND && g_imc_pen.global_data_ptr->cand_count > 0)
			{
				mmi_imc_select_candidate_from_candidate_box();
			}
			mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)char_code, 0);
        }
    }

   


        #if defined(__MMI_IME_FTE_ENHANCE__)
        ret_val = mmi_imc_pen_vk_back_to_lang();
        #endif /* defined(__MMI_IME_FTE_ENHANCE__) */
        return ret_val;
    }

    //UI_UNUSED_PARAMETER(vk_type);
    //return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_backspace
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_vk_backspace(mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_event == MMI_PEN_EVENT_UP)
    {
        
        if (!g_imc_pen.vk_longtap)
        {
            
            if ((MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_PINYIN 
                 || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO
            #if defined(__MMI_IME_FTE_ENHANCE__)
                 || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TR_STROKE
                 || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_SM_STROKE
            #endif
                )&& g_imc_pen.global_data_ptr->symb_count > 0)
            {
                if (g_imc_pen.global_data_ptr->tone != MMI_IMC_SYMB_TONE_NONE)
                {
                    g_imc_pen.global_data_ptr->tone = MMI_IMC_SYMB_TONE_NONE;
                    if (mmi_imc_pen_set_vk_candidate() == MMI_FALSE)
                    {
                        mmi_imc_pen_update_display_area_by_sym_buffer();
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                }
                else
                {
                    g_imc_pen.global_data_ptr->symb_count--;                
                   if (g_imc_pen.global_data_ptr->symb_count > 0)
                    {
                        if (mmi_imc_pen_set_vk_candidate() == MMI_FALSE)
                        {
                            mmi_imc_pen_update_display_area_by_sym_buffer();
                            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        }
                        else
                        {

                        }
                    }
                    else
                    {
                        mmi_imc_clear_symbol_buffer();
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
						mmi_imc_redraw_screen_by_state();
                    }
                }
            }
            else


        #if defined __MMI_XT9__
            if( (mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN))
            {
                switch (mmi_imc_get_state())
                {
                    case MMI_IMC_STATE_INITIAL:
                        mmi_imc_delete_timer();
                        if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0))
                        {
                            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                        }
                        else
                        {
                            UI_editor_play_tone_cannot_change();
                        }    
                        break;
                default:
                    /* pass pen up as key down because ime process rsk on key down */
                    mmi_imc_key_group_key_down_int(KEY_RSK, KEY_EVENT_DOWN);
                    break;
                }
            }
            else
        #endif
        #if (defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
            if (g_imc_pen.vk_style == MMI_VK_TYPE_ALPHANUMERIC)
            {
                switch (mmi_imc_get_state())
                {
                    case MMI_IMC_STATE_INITIAL:
                        mmi_imc_delete_timer();
                        if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0))
                        {
                            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                        }
                        else
                        {
                            UI_editor_play_tone_cannot_change();
                        }    
                        break;
                default:
                    /* pass pen up as key down because ime process rsk on key down */
                    mmi_imc_key_group_key_down_int(KEY_RSK, KEY_EVENT_DOWN);
                    break;
                }
            }
            else
        #endif
            {

                if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
                {
                    if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0))
                    {
                        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                    }
                    else
                    {
                        UI_editor_play_tone_cannot_change();
                    }    
                }
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                else
                {
					if(g_imc_pen.global_data_ptr->symb_count > 0)
					{
                     g_imc_pen.global_data_ptr->symb_count --;   
					}
                     if(g_imc_pen.global_data_ptr->symb_count == 0)
								
                     {
						 if (g_imc_pen.global_data_ptr->cand_length)
						  {
								mmi_imc_key_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, g_imc_pen.global_data_ptr->cand_length, (U32)L"");
						  }

						 mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
                          mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
						  
                     }
                     else
                     {
                          mmi_imc_pen_set_vk_candidate();
						    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
							mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_pen.global_data_ptr->cand_select);
							mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                     }
                 }

#else
                mmi_imc_clear_symbol_buffer();
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
#endif
                mmi_imc_pen_change_vk_by_capital_state();
            }
        }
        else
        {
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_BACKSPACE_KEY_EVENT, (U32)pen_event, 0);
        }
    }
    else if (pen_event == MMI_PEN_EVENT_REPEAT  || pen_event == MMI_PEN_EVENT_ABORT)
    {
 	//performance no need for this in repeat			
        /*  #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        MMI_BOOL lcd_freeze;
        lcd_freeze = gdi_lcd_get_freeze();
    	mmi_imc_gdi_lcd_freeze(MMI_TRUE);
        if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) == MMI_TRUE)

            {
                wgui_virtual_keyboard_draw_from_cache();
            }
    #endif*/

        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_BACKSPACE_KEY_EVENT, (U32)pen_event, 0);
        
   /* #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
        if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) == MMI_TRUE)
            {
                wgui_virtual_keyboard_recache();
            }
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
    #endif*/
    }
    else if (pen_event == MMI_PEN_EVENT_LONG_TAP)
    {

#if defined __MMI_IME_SMART_QWERTY_VK_INPUT__

            if( (mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN))
        {
            switch (mmi_imc_get_state())
            {
                case MMI_IMC_STATE_INITIAL:
                    mmi_imc_delete_timer();
                    if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0))
                    {
			            #if defined(__COSMOS_MMI_PACKAGE__)
                            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
                        #endif 
                        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_ALL, 0, 0);
                    }
                    else
                    {
                        UI_editor_play_tone_cannot_change();
                    }    
                    break;
                default:
                    mmi_imc_key_group_key_long_int(KEY_RSK, KEY_EVENT_LONG_PRESS);
                    break;
            }


        }

        else        
    #endif


    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)/*&& defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)*/
        if (g_imc_pen.vk_style == MMI_VK_TYPE_ALPHANUMERIC)
        {
            switch (mmi_imc_get_state())
            {
                case MMI_IMC_STATE_INITIAL:
                    mmi_imc_delete_timer();
                    if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0))
                    {
			            #if defined(__COSMOS_MMI_PACKAGE__)
                            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
                        #endif 
                        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_ALL, 0, 0);
                    }
                    else
                    {
                        UI_editor_play_tone_cannot_change();
                    }    
                    break;
                default:
                    mmi_imc_key_group_key_long_int(KEY_RSK, KEY_EVENT_LONG_PRESS);
                    break;
            }
        }
        else
    #endif
        {        
            if ((MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_PINYIN 
                 || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO
            #if defined(__MMI_IME_FTE_ENHANCE__)
                 || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TR_STROKE
                 || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_SM_STROKE
            #endif
                )&& g_imc_pen.global_data_ptr->symb_count > 0)
            {
                mmi_imc_clear_symbol_buffer();
            }
            else
            {
                if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0))
                {
			            #if defined(__COSMOS_MMI_PACKAGE__)
                            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
                        #endif 
                    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_ALL, 0, 0);
                }
                else
                {
                    UI_editor_play_tone_cannot_change();
                }    
            }
        }
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        g_imc_pen.vk_longtap = MMI_TRUE;

    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_update_display_area_by_sym_buffer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_update_display_area_by_sym_buffer(void)
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imc_pen.global_data_ptr->symb_count)
    {
        g_imc_pen.global_data_ptr->comp_buff[0] = 0;
    }
    else
    {
#ifdef __MMI_CSTAR_PHRASE_INPUT__            
        if (mmi_imc_is_qwerty_smart_pinyin_input())
        {
            for (i = 0; i< g_imc_pen.global_data_ptr->symb_count; i++)
            {
                /* Preserve hanzi */
                if (g_imc_pen.global_data_ptr->symb_buff[i] >= 0x4E00 && g_imc_pen.global_data_ptr->symb_buff[i] <= 0x9fff)
                    g_imc_pen.global_data_ptr->comp_buff[i] = g_imc_pen.global_data_ptr->symb_buff[i];
                else
                    g_imc_pen.global_data_ptr->comp_buff[i] = mmi_ime_word_symbol_to_code(g_imc_pen.global_data_ptr->symb_buff[i]);                               
            }        
        }
        else
#endif
        for (i = 0; i< g_imc_pen.global_data_ptr->symb_count; i++)
        {
        #if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_CSTAR__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
            if(g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY 
                && (g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
                && (g_imc_pen.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC))
                {
                    g_imc_pen.global_data_ptr->comp_buff[i] = g_imc_pen.global_data_ptr->symb_buff[i];
                }
            else
        #endif
            {
            g_imc_pen.global_data_ptr->comp_buff[i] = mmi_ime_word_symbol_to_code(g_imc_pen.global_data_ptr->symb_buff[i]);
        }
        }
        g_imc_pen.global_data_ptr->comp_buff[i] = '\0';
        mmi_imc_update_composition_box_by_query_result_ext(g_imc_pen.global_data_ptr->comp_buff, g_imc_pen.global_data_ptr->symb_count, MMI_FALSE, MMI_TRUE);
    }
#else /* defined(__MMI_IME_FTE_ENHANCE__) */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type vk_display_area[MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN + 1];
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_imc_pen.global_data_ptr->symb_count)
    {
        vk_display_area[0] = 0;
    }
    else
    {
        for (i = 0; i< g_imc_pen.global_data_ptr->symb_count; i++)
        {
            vk_display_area[i] = mmi_ime_word_symbol_to_code(g_imc_pen.global_data_ptr->symb_buff[i]);
            /* KLOCwork issue */
            ASSERT(i <= MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN + 1);
        }
        vk_display_area[i] = '\0';
    }
    #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
    wgui_set_virtual_keyboard_display_area((U8 *)vk_display_area, MMI_TRUE);
    #else
    wgui_virtual_keyboard_set_display_area((U8 *)vk_display_area, MMI_FALSE);
    #endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_vk_candidate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_set_vk_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_query_param_struct query_param;
    mmi_ime_query_result_struct query_result;
    mmi_imui_update_selection_area_struct  update_struct;
 /*the below check is so that get_canddiates API knows a new candidate has to be generated or it is just 
    shifting between pages, In future this can be done by saving the alst character entered and  comparing that 
    with the current candidate in T9engine.c*/
    #if defined __MMI_XT9__
    candidate_flag = 1; //NEW_CANDIDATE
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_pen.global_data_ptr->cand_page = 0;
    memset(g_imc_pen.global_data_ptr->cand_first_index, 0, sizeof(U16) * (MMI_IMC_MAX_CANDIDATE_PAGE + 1));

    query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;

#ifdef __MMI_CSTAR_PHRASE_INPUT__
    if (mmi_imc_is_qwerty_smart_pinyin_input())
    {
        if (g_imc_pen.global_data_ptr->input_confirm_length > g_imc_pen.global_data_ptr->symb_count)
            /* due to delete input! or lift it to deletion handle process? */
            g_imc_pen.global_data_ptr->input_confirm_length = g_imc_pen.global_data_ptr->symb_count;
        query_param.elembuf_cnt = g_imc_pen.global_data_ptr->symb_count - g_imc_pen.global_data_ptr->input_confirm_length;
        query_param.elembuf_ptr = g_imc_pen.global_data_ptr->symb_buff + g_imc_pen.global_data_ptr->input_confirm_length;
    }
    else
    {
        query_param.elembuf_cnt = g_imc_pen.global_data_ptr->symb_count;
        query_param.elembuf_ptr = g_imc_pen.global_data_ptr->symb_buff;    
    }
#else
    query_param.elembuf_cnt = g_imc_pen.global_data_ptr->symb_count;
    query_param.elembuf_ptr = g_imc_pen.global_data_ptr->symb_buff;
#endif
    query_param.first_index = 0;
    query_param.tone_value = MMI_IMC_SYMB_TONE_NONE;
    query_param.comp_selected =  0xff;
    query_result.result_buffer = g_imc_pen.global_data_ptr->cand_buff;
#ifdef __MMI_CSTAR_PHRASE_INPUT__
    query_result.match_length_table = g_imc_pen.global_data_ptr->cand_match_len;
#endif

#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(mmi_imc_is_grid_state())
	{
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
		mmi_imc_get_candidates_from_word_engine(&query_param, &query_result);
	}
	else
	{
		//mmi_ime_word_get_candidates(&query_param, &query_result);
            if (mmi_imm_is_chinese_input_method(mmi_imm_get_curr_input_mode()))
            {
                mmi_ime_word_get_candidates(&query_param, &query_result);
            }
            else
            {
                mmi_imc_get_candidates_from_word_engine(&query_param, &query_result);
            }
	}
#else
    if (mmi_imm_is_chinese_input_method(mmi_imm_get_curr_input_mode()))
    {
        mmi_ime_word_get_candidates(&query_param, &query_result);
    }
    else
    {
        mmi_imc_get_candidates_from_word_engine(&query_param, &query_result);
    }
#endif


#if defined(__MMI_IME_FTE_ENHANCE__)
    if (mmi_imc_pen_is_symbol_vk_type(MMI_VIRTUAL_KEYBOARD_LANG))
    {
        if (g_imc_pen.vk_type_before_symbol != GUI_VIRTUAL_KEYBOARD_MAX_LANG)
        {
            mmi_imc_pen_set_virtual_keyboard(g_imc_pen.vk_type_before_symbol, MMI_FALSE);
            g_imc_pen.vk_type_before_symbol = GUI_VIRTUAL_KEYBOARD_MAX_LANG;
        }
    }

    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_PINYIN || 
        MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO ||
        mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_MULTITAP_PINYIN || 
        mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO ||
        mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN || 
        mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_TR_BOPOMO)
    {
        g_imc_pen.global_data_ptr->cand_select = 0;
        g_imc_pen.global_data_ptr->cand_count = query_result.result_cnt;
        if (query_result.result_cnt > 0)
        {
            mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
        }
        else
        {
            update_struct.count = 0;
            update_struct.highlight_index = 0;
            update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
			#if defined(__MMI_IME_CANDIDATE_GRID__)
			
					update_struct.flags &= ~MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
		   #endif
                        
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON))
            {
                update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_FLOATING;
            }
        #endif    
            
            update_struct.separator = 0;
            update_struct.str_ptr = g_imc_pen.global_data_ptr->cand_buff;
            
		#if defined(__MMI_IME_CANDIDATE_GRID__)
			mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX_GRID, (U32)&update_struct, 0, NULL);
		#endif

            if (mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX, (U32)&update_struct, 0, NULL))
                MMI_ASSERT(0);

        }
        mmi_imc_pen_update_display_area_by_sym_buffer();
		if((mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING_GRID) || (mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECTING_GRID))//MAUI_03198044
		{
			//mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID); 
		}
		else
		{
			mmi_imc_set_state(MMI_IMC_STATE_VK_CAND);
		}
        return MMI_TRUE;
    }
    else    
#endif
    if (query_result.result_cnt > 0)
    {
        g_imc_pen.global_data_ptr->cand_select= 0;
        mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);

    #if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
        g_imc_pen.global_data_ptr->cand_select = (g_imc_pen.global_data_ptr->cand_count - 1) / 2;
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_pen.global_data_ptr->cand_select, 0, NULL);      
    #endif
        
        mmi_imc_pen_update_display_area_by_sym_buffer();
    #if defined(__MMI_IME_FTE_ENHANCE__)
        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_SM_STROKE|| 
            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TR_STROKE)
        {
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
        }
        else    
    #endif
        {
			#if defined(__MMI_IME_FTE_ENHANCE__)
            mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
			#else
			mmi_imc_set_state(MMI_IMC_STATE_VK_CAND);
			#endif
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) && defined(__MMI_IME_FTE_ENHANCE__) 

#if defined(__MMI_VIRTUAL_KEYBOARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_set_keyboardtype
 * DESCRIPTION
 *  Change keyboard being used (QWERTY , Alphanumeric, Handwriting) 
 * PARAMETERS
 *  U32 keyboard_type_index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_pen_set_keyboardtype(U32 keyboard_type_index)   
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_input_style_enum keyboard_type = g_imc_pen_selection_list_style_array[keyboard_type_index];
    mmi_imm_keypadtype_enum keypad_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_INPUT_STYLE_CHANGED,(U32) keyboard_type, 0);
#endif
    
    /* map the type*/
    switch (keyboard_type)
    {
        case MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY:
            keypad_type = IMM_KEYPAD_QWERTY;
            break;
            
    #if defined (__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
        case MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC:
            keypad_type = IMM_KEYPAD_ALPHANUMERIC;
            break;
    #endif

    #if !defined(__MMI_NO_HANDWRITING__) 
        case MMI_IMC_PEN_INPUT_STYLE_HW:
            keypad_type = IMM_KEYPAD_HANDWRITING;
            break;
    #endif

        default:
            MMI_ASSERT(0);
			keypad_type = IMM_KEYPAD_ALPHANUMERIC;  //dummy value
            break;
    }

    /* do the stuff required to change vk */
    mmi_imm_config_keyboard_type(keypad_type);
    mmi_imc_pen_set_history_is_vk_enlarge(MMI_TRUE);
    /* set event handlers as per new keyboard */
    mmi_imc_pen_activate();
    /* set state*/
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_popup_change_vk_type_callback
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_imc_pen_popup_change_vk_type_callback(S32 selected_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_set_keyboardtype((U32)selected_item);
    mmi_imc_redraw_screen_by_state();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_input_type_selection_lsk_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_input_type_selection_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_pen_selection_list_style_array[index] != MMI_IMC_PEN_INPUT_STYLE_MAX)
        g_pen_prefer_input_style = g_imc_pen_selection_list_style_array[index];

#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_INPUT_STYLE_CHANGED,(U32) g_pen_prefer_input_style, 0);
#endif    

    switch (g_pen_prefer_input_style)
    {
        case MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY:
            mmi_imm_config_keyboard_type(IMM_KEYPAD_QWERTY);
            break;
    #if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
        case MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC:
            mmi_imm_config_keyboard_type(IMM_KEYPAD_ALPHANUMERIC);
            break;
    #endif
    #if !defined(__NO_HANDWRITING__)
        case MMI_IMC_PEN_INPUT_STYLE_HW:
            mmi_imm_config_keyboard_type(IMM_KEYPAD_HANDWRITING);
            break;
    #endif
        case  MMI_IMC_PEN_INPUT_STYLE_MAX:
            break;

    }
    GoBackHistory();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_input_type_selection_rsk_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_input_type_selection_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_prefer_input_style = MMI_IMC_PEN_INPUT_STYLE_NONE;
	reset_small_screen();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_input_style_list
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 mmi_imc_pen_get_input_style_list(mmi_imc_pen_input_style_enum* style_array, PU16 strid_array, S32 array_size, S32* highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_COSMOS_KEYPAD_BAR__)
	  return 0;
    #endif
    for (i = 0; i < sizeof(g_imc_pen_input_style)/sizeof(mmi_imc_pen_input_style_enum) - 1; i ++)
    {
    #if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
        if ((g_imc_pen_input_style[i] == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC) && mmi_imc_is_rotated())
        {
            /* if current state is rotated, there is no alphanumeric vk */
            continue;
        }
    #endif

    #if !defined(__NO_HANDWRITING__)
        if ((g_imc_pen_input_style[i] == MMI_IMC_PEN_INPUT_STYLE_HW))
        {
            mmi_imc_pen_handwriting_type_enum hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc_pen.curr_mode_details->Handwriting_Attrib);
            if (mmi_imc_is_handwriting_disabled() || hw_type == IMM_HANDWRITING_TYPE_NONE || !mmi_ime_hand_writing_hw_type_query(hw_type))
            {
                continue;
            }
        }
    #endif

        /* 0 is for number query */
        if (count >= array_size && array_size != 0)
            MMI_ASSERT(0);

        if (strid_array)
            strid_array[count] = g_imc_pen_ui_style_str_array[i];
        if (style_array)
            style_array[count] = g_imc_pen_input_style[i];

        if (g_imc_pen_input_style[i] == g_imc_pen.input_type && highlight)
        {
            *highlight = count;
        }
        count ++;
        
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_select_input_style
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
 #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
static void mmi_imc_pen_select_input_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;	
    S32 i = 0;	
    gui_virtual_keyboard_key_pos_info_struct key_info;
    S32 highlight = 0;
    mmi_imc_pen_input_style_enum new_input_style = MMI_IMC_PEN_INPUT_STYLE_MAX;
    
	#if defined (__MMI_IME_INPUT_PATTERN_SETTING__) || defined(__MMI_VUI_ENGINE__)
		UI_string_ID_type popup_title = STR_INPUT_METHOD_KEYBOARD_TYPE ;
	#else
		UI_string_ID_type popup_title = STR_GLOBAL_INPUT_METHOD ;
	#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	/* Adding to make sure hilighting disappers when toggling from qwerty to alphanumeric  */
	mmi_imc_pen_process_before_changing_input_mode();

    for (i = 0; i < sizeof(g_imc_pen_input_style)/sizeof(mmi_imc_pen_input_style_enum) - 1; i ++)
    {
    #if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
        if ((g_imc_pen_input_style[i] == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC) && mmi_imc_is_rotated())
        {
            /* if current state is rotated, there is no alphanumeric vk */
            continue;
        }
    #endif
    
    #if !defined(__NO_HANDWRITING__)
        if ((g_imc_pen_input_style[i] == MMI_IMC_PEN_INPUT_STYLE_HW))
        {
            mmi_imc_pen_handwriting_type_enum hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc_pen.curr_mode_details->Handwriting_Attrib);
			if (mmi_imc_is_handwriting_disabled() || hw_type == IMM_HANDWRITING_TYPE_NONE || !mmi_ime_hand_writing_hw_type_query(hw_type))
			{
             continue;
			}
        }
    #endif		
        g_imc_pen_selection_list_str_array[count] = g_imc_pen_ui_style_str_array[i];
        g_imc_pen_selection_list_style_array[count] = g_imc_pen_input_style[i];

        if (g_imc_pen_input_style[i] == g_imc_pen.input_type)
            highlight = count;

        count ++;			
    }

    if (count == 1)
    {
        /* no handle */
    }
    else if (count == 2)
    {
        BOOL lcd_freeze;
        /* there must be qwerty and alphanumeric vk or handwriting vk*/
        if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY)
        {
            /* the new vk style may be alphanumeric or handwriting vk */
        #if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
            if (!mmi_imc_is_rotated())
            {
                 new_input_style = MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
            }
            else
        #endif
            {
            #if !defined(__NO_HANDWRITING__)
                if (!mmi_imc_is_handwriting_disabled())
                {
                    new_input_style = MMI_IMC_PEN_INPUT_STYLE_HW;
                }
            #endif
            }
        }
        else
        {
            /* the new vk style must be qwerty vk */
            new_input_style = MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
        }
        
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_INPUT_STYLE_CHANGED,(U32) new_input_style, 0);
#endif        

        MMI_ASSERT(new_input_style != MMI_IMC_PEN_INPUT_STYLE_MAX);
        lcd_freeze = gdi_lcd_get_freeze();
        mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        switch (new_input_style)
        {
        #if !defined(__NO_HANDWRITING__)
            case MMI_IMC_PEN_INPUT_STYLE_HW:
                mmi_imm_config_keyboard_type(IMM_KEYPAD_HANDWRITING);
                g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_HW;
					mmi_imc_pen_vk_enable_single_block_hw();
                break;
        #endif
        #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
            case MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY:	
                mmi_imm_config_keyboard_type(IMM_KEYPAD_QWERTY);
                g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
                g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
            #if !defined(__NO_HANDWRITING__)    
                mmi_imc_pen_setup_virtual_keyboard(g_imc_pen.curr_mode_details);
                mmi_imc_pen_stop_singleblock_handwriting();
            #endif    
                if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_LANG_NUMBER)
                {
                    if (IME_IS_CHINESE_WRITING_LANG(g_imc_pen.curr_mode_details->lang_id))
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_AND_CH_SYMBOL, MMI_FALSE);
                    }
                    else
                    {
                        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_AND_SYMBOL, MMI_FALSE);
                    }
                }
                else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1 ||
                            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_2 ||
                            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_3 ||
                            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_4)
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_AND_SYMBOL, MMI_FALSE);
                }
                else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1 ||
                            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_2 ||
                            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_3 ||
                            MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4)
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_AND_CH_SYMBOL, MMI_FALSE);
                }
                mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, MMI_VK_TYPE_QWERTY, 0, NULL);
                break;
            #endif
            case MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC:
            #if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)    
                mmi_imm_config_keyboard_type(IMM_KEYPAD_ALPHANUMERIC);
                g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
                g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
            #if !defined(__NO_HANDWRITING__)    
                mmi_imc_pen_setup_virtual_keyboard(g_imc_pen.curr_mode_details);
                mmi_imc_pen_stop_singleblock_handwriting();
            #endif
				if (MMI_VIRTUAL_KEYBOARD_LANG ==  GUI_VIRTUAL_KEYBOARD_NUMBER_AND_CH_SYMBOL)
				{
					mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_LANG_NUMBER, MMI_FALSE);
				}
				else if ( MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL)
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1, MMI_FALSE);
                } 
				else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_NUMBER_AND_SYMBOL)
				{
					mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_LANG_NUMBER, MMI_FALSE);

				}
                else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_SYMBOL ||
                    MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_SYMBOL_FOR_NUM 
#if defined(__MMI_LANG_SPANISH__)
                    || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_SPANISH_SYMBOL
#endif
#if defined(__MMI_LANG_ARABIC__)
                    || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS
#endif
#if defined(__MMI_LANG_THAI__)
                    || MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL
#endif
                    )
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1, MMI_FALSE);
                }
#if defined(__MMI_LANG_BENGALI__)
                else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BENGALI_LOWERCASE)
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_BENGALI, MMI_FALSE);
                }
#endif
#if defined(__MMI_LANG_HINDI__)
                else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_HINDI_LOWERCASE)
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_HINDI, MMI_FALSE);
                }
#endif
#if defined(__MMI_LANG_THAI__)
                else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_THAI_LOWERCASE)
                {
                    mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_THAI, MMI_FALSE);
                }
#endif
                mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, MMI_VK_TYPE_ALPHANUMERIC, 0, NULL);
            #endif    
                break;
                
        }
        mmi_imc_redraw_screen_by_state();
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
    }
    else if (count == 3)
    {
        memset(&key_info, 0, sizeof(gui_virtual_keyboard_key_pos_info_struct));
        if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC)    
        {
            key_info.key_value = GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING;
        }
        else
        {
            key_info.key_value = GUI_VKBD_PEN_HANDWRITING;
        }
            
        mmi_imc_pen_send_ui_message(MMI_IMUI_GET_VK_KEY_POSITION, (U32)&key_info, 0, NULL);

#if defined(__MMI_VUI_ENGINE__)
        /* transfter position from pluto control coordinate set to screen coordinate set */
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_get_pos_from_fixed_control(&key_info.x, &key_info.y);
        }
#endif

        if (key_info.x > (UI_device_width >> 1))
        {
        #if defined(__MMI_VUI_ENGINE__)
            /* show popup */
            if (vadp_p2v_uc_is_in_venus())
            {
                vadp_p2v_show_ime_popup(
                    STR_INPUT_METHOD_KEYBOARD_TYPE,
                    g_imc_pen_selection_list_str_array,
                    count,
                    highlight,
                    mmi_imc_pen_popup_change_vk_type_callback,
                    NULL, MMI_TRUE);
            }
            else
        #endif
            {
                mmi_imc_show_popup_list(
                    key_info.x + key_info.width, 
                    key_info.y, 
                    count, 
                    g_imc_pen_selection_list_str_array, 
                    highlight, 
                    mmi_imc_pen_input_type_selection_lsk_handler, 
                    mmi_imc_pen_input_type_selection_rsk_handler,
					popup_title);
            }
        }
        else
        {
        #if defined(__MMI_VUI_ENGINE__)
            /* show popup */
            if (vadp_p2v_uc_is_in_venus())
            {
                vadp_p2v_show_ime_popup(
                    STR_INPUT_METHOD_KEYBOARD_TYPE,
                    g_imc_pen_selection_list_str_array,
                    count,
                    highlight,
                    mmi_imc_pen_popup_change_vk_type_callback,
                    NULL, MMI_TRUE);
            }
        else
         #endif
            {
                mmi_imc_show_popup_list(
                    key_info.x, 
                    key_info.y, 
                    count, 
                    g_imc_pen_selection_list_str_array, 
                    highlight, 
                    mmi_imc_pen_input_type_selection_lsk_handler, 
                    mmi_imc_pen_input_type_selection_rsk_handler,
					popup_title);
            }
        }
    }
}
#endif

#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

#if !defined(__NO_HANDWRITING__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_single_block_stroke_down_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_single_block_stroke_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum curr_state;
    MMI_BOOL need_redraw = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (gui_screen_smooth_scrolling_in_freerun() &&
        !gui_ssp_pos_in_menu(pos.x, pos.y))
    {
        gui_ssp_pen_up_dummy();
        mmi_pen_reset();
        return;
    }
    #endif
    MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"single block imc_pen_stroke_down_handler called %d %d",pos.x, pos.y);
    if (!mmi_imc_get_hw_type_validity() || mmi_imc_is_handwriting_disabled())
        return;

    curr_state = mmi_imc_get_state();
#if defined(__MMI_CLIPBOARD__) 
    if (mmi_imc_is_clipboard_state())
    {
        mmi_imc_clipboard_go_back_to_initial();
    }
    else
#endif /* __MMI_CLIPBOARD__ */
    if (curr_state == MMI_IMC_STATE_HAND_WRITING_CAND)
    {
        mmi_imc_cancel_timer();
    }
    else if (curr_state == MMI_IMC_STATE_ASSOC_SELECTING)
    {
        need_redraw = MMI_TRUE;
    }

#if defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    g_imc_pen_is_down_in_extra_block = 
        (MMI_BOOL)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_IS_STROKE_DOWN_IN_EXTRA_BLOCK, (U32)pos.x, (U32)pos.y, NULL);
    #endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

    if (mmi_imc_get_state() != MMI_IMC_STATE_HAND_WRITING)
    {
        mmi_imc_set_state(MMI_IMC_STATE_HAND_WRITING);
    }

    mmi_imc_delete_timer();

    if (need_redraw)
    {
        mmi_imc_redraw_screen_by_state();
    }

    g_imc_pen_previous_point.x = pos.x;
    g_imc_pen_previous_point.y = pos.y;
    MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"single block imc_pen_stroke_down_handler ended %d %d",pos.x, pos.y);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_single_block_stroke_move_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_single_block_stroke_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"single block imc_pen_stroke_move_handler called %d %d",pos.x, pos.y);
    if (!mmi_imc_get_hw_type_validity())
        return;

    
    if (mmi_imc_is_handwriting_disabled())
    {
        mmi_imc_pen_end_strokes_of_character();
        mmi_imc_pen_begin_strokes_of_character();
        return;
    }
    
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_DRAW_STROKE, (U32)&g_imc_pen_previous_point, (U32)&pos, NULL);
    
    
    g_imc_pen_previous_point.x = pos.x;
    g_imc_pen_previous_point.y = pos.y;
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"single block imc_pen_stroke_move_handler ended %d %d",pos.x, pos.y);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_single_block_stroke_up_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_single_block_stroke_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"single block imc_pen_stroke_up_handler called %d %d",pos.x, pos.y);
    if (!mmi_imc_get_hw_type_validity())
        return;

    if (mmi_imc_is_handwriting_disabled())
        return;
        
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_DRAW_STROKE, (U32)&g_imc_pen_previous_point, (U32)&pos, NULL);
    
    g_imc_pen_previous_point.x = -1;
    g_imc_pen_previous_point.y = -1;

    mmi_imc_restart_timer(g_imc_pen_character_end_period, mmi_imc_pen_event_single_block_stroke_up_timer_handler, mmi_imc_pen_single_block_stroke_up_cancel_timer_handler);
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"single block imc_pen_stroke_up_handler ended %d %d",pos.x,pos.y);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_single_block_stroke_up_timer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_single_block_stroke_up_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL has_unfinished_stroke = MMI_FALSE;
    S32 num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* we have wrapped this API with lock\unlock frame buffer
     *  to avoid BLTing happening more than once during its execution
     */
    BOOL lcd_freeze = gdi_lcd_get_freeze();
	mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
    MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_single_block_stroke_up_timer_handler called");               
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);
    
    mmi_pen_peek_stroke_state(&has_unfinished_stroke);
    

    if (has_unfinished_stroke)
    {
        mmi_imc_pen_end_strokes_of_character();
        mmi_imc_pen_begin_strokes_of_character();
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
        return;
    }

    mmi_imc_pen_end_strokes_of_character();

    num = mmi_imc_pen_get_candidates_from_hand_writing();

    if (num > 0)
    {
        
        g_imc_pen.global_data_ptr->cand_count = num;
        g_imc_pen.global_data_ptr->cand_select= 0;

        if (mmi_imc_pen_start_waiting_for_confirm() == MMI_TRUE)
        {
            g_imc_pen.update_struct.count = num;
            g_imc_pen.update_struct.highlight_index = 0;
            g_imc_pen.update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_FOCUS | MMI_IMUI_SELECTION_AREA_FLAG_FIX_GRID;
			#if defined(__MMI_IME_CANDIDATE_GRID__)
            g_imc_pen.update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_SHOW_EXPAND_BUTTON;
			g_imc_pen.update_struct.flags &= ~MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
			#else
            g_imc_pen.update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
			#endif
            g_imc_pen.update_struct.separator = 0;
            g_imc_pen.update_struct.str_ptr = g_imc_pen.global_data_ptr->cand_buff;
            
            g_imc_pen.global_data_ptr->cand_count = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX, (U32)&(g_imc_pen.update_struct), 0, NULL);
			#if defined(__MMI_IME_CANDIDATE_GRID__)
			g_imc_pen.global_data_ptr->cand_count = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX_GRID, (U32)&(g_imc_pen.update_struct), 0, NULL);
			#endif
            if (g_imc_pen.global_data_ptr->cand_count >= num)
            {
                g_imc_pen.global_data_ptr->cand_first_index[g_imc_pen.global_data_ptr->cand_page + 1]  = 0;
            }
            else
            {
                g_imc_pen.global_data_ptr->cand_first_index[g_imc_pen.global_data_ptr->cand_page + 1] =  g_imc_pen.global_data_ptr->cand_first_index[g_imc_pen.global_data_ptr->cand_page] + g_imc_pen.global_data_ptr->cand_count;
            }
            mmi_imc_set_state(MMI_IMC_STATE_HAND_WRITING_CAND);
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
    
    mmi_imc_pen_begin_strokes_of_character();
    mmi_imc_redraw_screen_by_state();
    mmi_imc_gdi_lcd_freeze(lcd_freeze);
	mmi_imc_repaint_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_single_block_stroke_up_cancel_timer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_single_block_stroke_up_cancel_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_single_block_stroke_up_cancel_timer_handler called");
    mmi_imc_pen_end_strokes_of_character();

    /* Maybe insert the first character directly */
    
    mmi_imc_pen_begin_strokes_of_character();
    
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);
    
    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_SINGLE_BLOCK_AREA));

}
#endif
#endif

#if !defined(__NO_HANDWRITING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_stroke_down_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_stroke_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imc_pen_get_handwriting_style())
    {
        case MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN:
            mmi_imc_pen_event_full_screen_stroke_down_handler(pos);
            break;
    #if defined(__MMI_HANDWRITING_MULTI_BLOCK__)            
        case MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK:
            mmi_imc_pen_event_multi_block_stroke_down_handler(pos);
            break;
    #endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    case MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK:
        mmi_imc_pen_event_single_block_stroke_down_handler(pos);
        break;
     #endif       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_stroke_up_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_stroke_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imc_pen_get_handwriting_style())
    {
        case MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN:
            mmi_imc_pen_event_full_screen_stroke_up_handler(pos);
            break;
    #if defined(__MMI_HANDWRITING_MULTI_BLOCK__)            
        case MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK:
            mmi_imc_pen_event_multi_block_stroke_up_handler(pos);
            break;
    #endif
    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        case MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK:
            mmi_imc_pen_event_single_block_stroke_up_handler(pos);
            break;
     #endif       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_stroke_move_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_stroke_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imc_pen_get_handwriting_style())
    {
        case MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN:
            mmi_imc_pen_event_full_screen_stroke_move_handler(pos);
            break;
    #if defined(__MMI_HANDWRITING_MULTI_BLOCK__)            
        case MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK:
            mmi_imc_pen_event_multi_block_stroke_move_handler(pos);
            break;
    #endif
    #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        case MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK:
            mmi_imc_pen_event_single_block_stroke_move_handler(pos);
            break;
     #endif       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_stroke_down_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_full_screen_stroke_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL should_repaint_all = MMI_FALSE;
    BOOL lcd_freeze = gdi_lcd_get_freeze();
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_HANDWRITING_FULL_SCREEN_PEN_DOWN_POSITION, pos.x, pos.y);
#if defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)
    	if (mmi_imc_is_in_atv_editor())
        {
            return;
        }
#endif /* defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)*/

#ifdef __MMI_CLIPBOARD__
    g_clipboard_pen_long_press = MMI_FALSE;
    if (mmi_imc_get_state() != MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN)
#endif /* __MMI_CLIPBOARD__ */
    {
        if (!mmi_imc_get_hw_type_validity())
            return;

        lcd_freeze = gdi_lcd_get_freeze();
        mmi_imc_gdi_lcd_freeze(MMI_TRUE); 

        if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE
            || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
        {
            if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
            {
                mmi_imc_key_smart_alphabetic_confirm_candidate();
            }
            else
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }
        }
 	    else if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
 	    {
 		    mmi_imc_delete_timer();
 		    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
 		    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
		    mmi_imc_redraw_screen_by_state();
 	    }
        else if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
        {
            //mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
            mmi_imc_cancel_timer();
            g_pen_timer_callback();
        }
        else if (g_pen_timer_callback != NULL)
        {
            if (mmi_imc_get_state() != MMI_IMC_STATE_HAND_WRITING)
            {
                MMI_BOOL temp_draw = mmi_imc_get_draw();
                mmi_imc_config_draw(MMI_TRUE);
                g_pen_timer_callback();
                mmi_imc_config_draw(temp_draw);        
                g_pen_timer_callback = NULL;
            }
        }
        else if (g_pen_down_state != MMI_IMC_STATE_INITIAL)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        }
    
        g_pen_timer_callback = NULL;
        g_pen_down_state = MMI_IMC_STATE_INITIAL;

        if (mmi_imc_is_handwriting_disabled())
        {
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            return;
        }

        mmi_imc_delete_timer();

        g_imc_pen_previous_point.x = pos.x;
        g_imc_pen_previous_point.y = pos.y;

        if (mmi_imc_get_state() != MMI_IMC_STATE_HAND_WRITING)
        {
			should_repaint_all = MMI_TRUE;
            mmi_imc_set_state(MMI_IMC_STATE_HAND_WRITING);
            g_pen_down_state = MMI_IMC_STATE_HAND_WRITING;
            mmi_imc_redraw_screen_by_state();
        }
        
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        
		
        if (should_repaint_all)
        {
            mmi_imc_repaint_screen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_stroke_move_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_full_screen_stroke_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_HANDWRITING_FULL_SCREEN_PEN_MOVE_POSITION, pos.x, pos.y);
#if defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)
    	if (mmi_imc_is_in_atv_editor())
        {
            return;
        }
#endif /* defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)*/
#ifdef __MMI_CLIPBOARD__
    g_clipboard_pen_long_press = MMI_FALSE;
    if (mmi_imc_get_state() == MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN)
    {
        mmi_imc_pen_event_pen_move_handler(pos);
    
        if (g_clipboard_pen_is_first_move)
        {
            g_clipboard_move_p1.x= pos.x;
            g_clipboard_move_p1.y= pos.y;
            g_clipboard_move_p2.x= pos.x;
            g_clipboard_move_p2.y= pos.y;
            
            mmi_imc_start_timer(HANDWRITING_REPEAT_TIMEOUT, mmi_imc_pen_clipboard_repeat_timer_handler, NULL);
            g_clipboard_pen_is_first_move = MMI_FALSE;
        }
        else
        {
            mmi_imc_start_timer(HANDWRITING_REPEAT_TIMEOUT, mmi_imc_pen_clipboard_repeat_timer_handler, NULL);
            g_clipboard_move_p2.x= pos.x;
            g_clipboard_move_p2.y= pos.y;
        }
    }
    else
#endif /* __MMI_CLIPBOARD__ */
    {
        if (!mmi_imc_get_hw_type_validity())
            return;

        if (mmi_imc_is_handwriting_disabled())
            return;

        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_DRAW_STROKE, (U32)&g_imc_pen_previous_point, (U32)&pos, NULL);
    
    
        g_imc_pen_previous_point.x = pos.x;
        g_imc_pen_previous_point.y = pos.y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_stroke_up_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_full_screen_stroke_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_HANDWRITING_FULL_SCREEN_PEN_UP_POSITION, pos.x, pos.y);
#if defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)
    	if (mmi_imc_is_in_atv_editor())
        {
            return;
        }
#endif /* defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)*/
#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_get_state() == MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN)
    {
        mmi_imc_pen_event_pen_up_handler(pos);
        g_clipboard_pen_is_first_move = MMI_TRUE;
        mmi_imc_delete_timer();
    }
    else
#endif /* __MMI_CLIPBOARD__ */
    {
        if (!mmi_imc_get_hw_type_validity() || mmi_imc_is_handwriting_disabled())
        {
            mmi_imc_pen_end_strokes_of_character();
            mmi_imc_pen_begin_strokes_of_character();
            return;
        }

        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_DRAW_STROKE, (U32)&g_imc_pen_previous_point, (U32)&pos, NULL);
    
        g_imc_pen_previous_point.x = -1;
        g_imc_pen_previous_point.y = -1;

        mmi_imc_restart_timer(g_imc_pen_character_end_period, mmi_imc_pen_event_full_screen_stroke_up_timer_handler, mmi_imc_pen_full_screen_stroke_up_cancel_timer_handler); 

#if defined(__MMI_VIRTUAL_KEYBOARD__)
        g_imc_pen.vk_longtap = MMI_FALSE;
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_stroke_up_timer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_full_screen_stroke_up_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL has_unfinished_stroke = MMI_FALSE;
    S32 num;
    BOOL lcd_freeze = gdi_lcd_get_freeze();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME,TRC_MMI_HANDWRITING_FULL_SCREEN_STROKE_UP_TIME_HANDLER);
#if defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)
    	if (mmi_imc_is_in_atv_editor())
        {
            return;
        }
#endif /* defined(__MMI_MAINLCD_320X240__) && defined(__ATV_SMS_SUPPORT__)*/

    mmi_pen_peek_stroke_state(&has_unfinished_stroke);
    
    if (has_unfinished_stroke)
    {
        mmi_imc_pen_end_strokes_of_character();

        mmi_imc_pen_begin_strokes_of_character();

        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
		
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);

		mmi_imc_repaint_screen();

        mmi_imc_redraw_screen_by_state();
        
        return;
    }

    mmi_imc_pen_end_strokes_of_character();

    lcd_freeze = gdi_lcd_get_freeze();
	mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);

    num = mmi_imc_pen_get_candidates_from_hand_writing();

    if (num > 0)
    {
        
        g_imc_pen.global_data_ptr->cand_count = num;
        g_imc_pen.global_data_ptr->cand_select= 0;
        
        if (mmi_imc_pen_start_waiting_for_confirm() == MMI_TRUE)
        {
            g_imc_pen.update_struct.count = num;
            g_imc_pen.update_struct.highlight_index = 0;
            g_imc_pen.update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_FOCUS | MMI_IMUI_SELECTION_AREA_FLAG_FIX_GRID;
        #if defined(__MMI_IME_FTE_ENHANCE__)
            g_imc_pen.update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
        #endif

        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
            g_imc_pen.update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_FLOATING;
        #endif
        
            g_imc_pen.update_struct.separator = 0;
            g_imc_pen.update_struct.str_ptr = g_imc_pen.global_data_ptr->cand_buff;
        
            g_imc_pen.global_data_ptr->cand_count = mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX, (U32)&(g_imc_pen.update_struct), 0, NULL);

            mmi_imc_set_state(MMI_IMC_STATE_HAND_WRITING_CAND);
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

    mmi_imc_pen_begin_strokes_of_character();
    mmi_imc_redraw_screen_by_state();
    
    mmi_imc_gdi_lcd_freeze(lcd_freeze);
    mmi_imc_repaint_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_full_screen_stroke_up_cancel_timer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_full_screen_stroke_up_cancel_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_full_screen_stroke_up_cancel_timer_handler called");	
    mmi_imc_pen_end_strokes_of_character();

    /* Maybe insert the first character directly */
    
    mmi_imc_pen_begin_strokes_of_character();
    
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);
    mmi_imc_redraw_screen_by_state();
}

#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_multi_block_stroke_down_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_multi_block_stroke_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 active_block;
    mmi_imc_state_enum curr_state;
    BOOL lcd_freeze = gdi_lcd_get_freeze();
	MMI_BOOL is_multiblock_changed = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_multi_block_stroke_down_handler called %d %d",pos.x, pos.y);	
    if (!mmi_imc_get_hw_type_validity())
        return;

#ifdef __MMI_CLIPBOARD__ 
    if (mmi_imc_is_clipboard_state())
    {
        mmi_imc_clipboard_go_back_to_initial();
    }
#endif /* __MMI_CLIPBOARD__ */

    curr_state = mmi_imc_get_state(); 

    lcd_freeze = gdi_lcd_get_freeze();
	mmi_imc_gdi_lcd_freeze(MMI_TRUE); 

	if (curr_state == MMI_IMC_STATE_SMART_CANDIDATE
        || curr_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
    {
        if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
        {
            mmi_imc_key_smart_alphabetic_confirm_candidate();
        }
        else
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        }
    }
 	else if (curr_state == MMI_IMC_STATE_WORD_HIGHLIGHTED)
 	{
 		mmi_imc_delete_timer();
 		mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
 		mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
 	}
	else if (curr_state == MMI_IMC_STATE_HAND_WRITING_CAND)
	{
		MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_multi_block_stroke_down_handler called timer cancelled %d %d",pos.x, pos.y);	
        mmi_imc_cancel_timer();
	}
    else if (curr_state == MMI_IMC_STATE_ASSOC_SELECTING)
    {
 		mmi_imc_set_state(MMI_IMC_STATE_INITIAL);            
    }
	else if (curr_state != MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING)
	{
        mmi_imc_cancel_timer();
	}
    
    if (mmi_imc_is_handwriting_disabled())
    {
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
        return;
    }

    active_block = mmi_imc_pen_get_multi_block_number(pos);
    MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_multi_block_stroke_down_handler called block=%d",active_block);	
    if (active_block && g_active_block != 0)
    {
        if (active_block != g_active_block)
        {
            is_multiblock_changed = MMI_TRUE;
            mmi_imc_pen_direct_input();
        }
    }

    g_active_block = active_block;

    mmi_imc_delete_timer();
    
    g_imc_pen_previous_point.x = pos.x;
    g_imc_pen_previous_point.y = pos.y;

    if ((mmi_imc_get_state() != MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING) ||
		(is_multiblock_changed))
    {
        mmi_imc_set_state(MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING);

        mmi_imc_redraw_screen_by_state();
    }
	#if(UI_BLINKING_CURSOR_SUPPORT)
    UI_inputbox_hide_cursor();
	#endif
    mmi_imc_gdi_lcd_freeze(lcd_freeze);
    
    if ((mmi_imc_get_state() != MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING)  ||
		(is_multiblock_changed))
    {
        mmi_imc_repaint_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_multi_blockn_stroke_up_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_multi_block_stroke_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_multi_block_stroke_up_handler called %d %d",pos.x, pos.y);	
    if (!mmi_imc_get_hw_type_validity())
        return;

    if (mmi_imc_is_handwriting_disabled())
        return;
        
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_DRAW_STROKE, (U32)&g_imc_pen_previous_point, (U32)&pos, NULL);
    
    g_imc_pen_previous_point.x = -1;
    g_imc_pen_previous_point.y = -1;

    mmi_imc_restart_timer(g_imc_pen_character_end_period, mmi_imc_pen_event_multi_block_stroke_up_timer_handler, mmi_imc_pen_multi_block_stroke_up_cancel_timer_handler);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_multi_block_stroke_move_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_multi_block_stroke_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_multi_block_stroke_move_handler called %d %d",pos.x, pos.y);	
    if (!mmi_imc_get_hw_type_validity())
        return;

    
    if (mmi_imc_is_handwriting_disabled())
    {
        mmi_imc_pen_end_strokes_of_character();
        mmi_imc_pen_begin_strokes_of_character();
        return;
    }
    
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_DRAW_STROKE, (U32)&g_imc_pen_previous_point, (U32)&pos, NULL);
    
    
    g_imc_pen_previous_point.x = pos.x;
    g_imc_pen_previous_point.y = pos.y;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_event_multi_block_stroke_up_timer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_event_multi_block_stroke_up_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL has_unfinished_stroke = MMI_FALSE;
    S32 num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_multi_block_stroke_up_timer_handler called ");	
	mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);
    
    mmi_pen_peek_stroke_state(&has_unfinished_stroke);
    

    if (has_unfinished_stroke)
    {
        mmi_imc_pen_end_strokes_of_character();
        mmi_imc_pen_begin_strokes_of_character();
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        return;
    }

    mmi_imc_pen_end_strokes_of_character();
    


    num = mmi_imc_pen_get_candidates_from_hand_writing();

    if (num > 0)
    {
        
        g_imc_pen.global_data_ptr->cand_count = num;
        g_imc_pen.global_data_ptr->cand_select= 0;

        if (mmi_imc_pen_start_waiting_for_confirm() == MMI_TRUE)
        {
            g_imc_pen.update_struct.count = num;
            g_imc_pen.update_struct.highlight_index = 0;
            g_imc_pen.update_struct.flags = MMI_IMUI_SELECTION_AREA_FLAG_FOCUS | MMI_IMUI_SELECTION_AREA_FLAG_FIX_GRID;
        #if defined(__MMI_IME_FTE_ENHANCE__)
            g_imc_pen.update_struct.flags |= MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW;
        #endif

        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
        #endif

            g_imc_pen.update_struct.separator = 0;
            g_imc_pen.update_struct.str_ptr = g_imc_pen.global_data_ptr->cand_buff;
            
            g_imc_pen.global_data_ptr->cand_count = (U8)mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX, (U32)&(g_imc_pen.update_struct), 0, NULL);
            
            mmi_imc_set_state(MMI_IMC_STATE_HAND_WRITING_CAND);
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

    g_active_block = 0;
    
    mmi_imc_pen_begin_strokes_of_character();
    mmi_imc_redraw_screen_by_state();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_multi_block_number
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static S32  mmi_imc_pen_get_multi_block_number(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_VUI_ENGINE__)
    /* transfter position from pluto control coordinate set to screen coordinate set */
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_get_pos_from_fixed_control(&pos.x, &pos.y);
    }
#endif

    if (pos.x >= g_imc_stroke_area[0].x1 && pos.x <= g_imc_stroke_area[0].x2
        && pos.y >= g_imc_stroke_area[0].y1 && pos.y <= g_imc_stroke_area[0].y2)
    {
        return 1;
    }
    else if (pos.x >= g_imc_stroke_area[1].x1 && pos.x <= g_imc_stroke_area[1].x2
        && pos.y >= g_imc_stroke_area[1].y1 && pos.y <= g_imc_stroke_area[1].y2)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_direct_input
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_direct_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_pen_end_strokes_of_character();
    
    num = mmi_imc_pen_get_candidates_from_hand_writing();

    if (num > 0)
    {
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)g_imc_pen.global_data_ptr->cand_buff, MMI_FALSE);
    }
    
    mmi_imc_pen_begin_strokes_of_character();

    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);
    
    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_MULTI_BLOCK_AREA));
        
    mmi_imc_redraw_screen_by_state();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_multi_block_stroke_up_cancel_timer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_multi_block_stroke_up_cancel_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"imc_pen_event_multi_block_stroke_up_cancel_timer_handler called");	
    mmi_imc_pen_end_strokes_of_character();

    /* Maybe insert the first character directly */
    
    mmi_imc_pen_begin_strokes_of_character();
    
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);
    
    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_MULTI_BLOCK_AREA));
}
#endif /* #if defined(__MMI_HANDWRITING_MULTI_BLOCK__) */
#endif /* !defined(__NO_HANDWRITING__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_dummy_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_dummy_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#if defined(__MMI_VIRTUAL_KEYBOARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_get_vk_type(const sIMEModeDetails * input_mode_detail, gui_virtual_keyboard_language_enum * vk_type, MMI_BOOL * has_candidate_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HW_ATTR hw_attr_value = input_mode_detail->Handwriting_Attrib;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *vk_type = (gui_virtual_keyboard_language_enum) IME_HAND_WRITING_GET_VK_TYPE(hw_attr_value);
    *has_candidate_box = (MMI_BOOL) IME_HAND_WRITING_GET_VK_HAS_CAND(hw_attr_value);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_resort_candidates
 * DESCRIPTION
 *  Resort the candidates according to SortRequirement
 * PARAMETERS
 *  candidates          [OUT]       The buffer of the candidates to resort
 *  num                 [IN]        The number of the candidates
 *  SortRequirement     [IN]        MMI_IMC_PEN_SORT_CAPITAL_FIRST : Capital characters are in the front of non-capital characters
 *                                  MMI_IMC_PEN_SORT_NON_CAPITAL_FIRST : Non-capital characters are in the front of capital characters
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imc_pen_resort_candidates(
        UI_character_type *candidates,
        S32 num,
        mmi_imc_pen_resort_type_enum SortRequirement)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num - 1; i++)
    {
        if (MMI_IMC_PEN_SORT_NON_CAPITAL_FIRST == SortRequirement)
        {
            /* Take care of all the ucs2 ranges */
            if (app_ucs2_towupper(candidates[i + 1]) == candidates[i])
            {
                candidates[i] = candidates[i + 1];
                candidates[i + 1] = app_ucs2_towupper(candidates[i]);
            }
        }
        else if (MMI_IMC_PEN_SORT_CAPITAL_FIRST == SortRequirement)
        {
            if (candidates[i + 1] == app_ucs2_towupper(candidates[i]))
            {
                candidates[i + 1] = candidates[i];
                candidates[i] = app_ucs2_towupper(candidates[i + 1]);
            }
        }
    }

    /* For '0' special case */
    if ('0' == candidates[0])
    {
        if (MMI_IMC_PEN_SORT_NON_CAPITAL_FIRST == SortRequirement)
        {
            if ('o' == candidates[1] && 'O' == candidates[2])
            {
                candidates[0] = 'o';
                candidates[1] = 'O';
                candidates[2] = '0';
            }
        }
        else if (MMI_IMC_PEN_SORT_CAPITAL_FIRST == SortRequirement)
        {
            if ('O' == candidates[1] && 'o' == candidates[2])
            {
                candidates[0] = 'O';
                candidates[1] = 'o';
                candidates[2] = '0';
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_candidates_from_hand_writing
 * DESCRIPTION
 *  Get and resort candidate
 * PARAMETERS
 * RETURNS
 *  The number of candidate
 *****************************************************************************/
static S32 mmi_imc_pen_get_candidates_from_hand_writing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num = 0;
    mmi_imc_pen_handwriting_type_enum hw_type;
    mmi_ime_hand_writing_query_param query_param;
    mmi_ime_hand_writing_result_param result_param;
    kal_uint32 time1, time2;
    UI_character_type first_char;
    mmi_imm_input_mode_enum input_mode;
    mmi_imc_message_struct imc_msg;
    UI_string_type candidate_buffer = g_imc_pen.hw_cand_buf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_pen.hw_cand_cnt = 0;
   
    input_mode = mmi_imm_get_curr_input_mode();
    /* to make sure signed character works fine no candidates produced*/
    if (input_mode == IMM_INPUT_MODE_SIGNED_123 || input_mode ==IMM_INPUT_MODE_SIGNED_FLOAT_123)
    {
        imc_msg.message_id    = MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION;
        imc_msg.param_0       = 0;
        imc_msg.param_1       = 0;
        first_char = (UI_character_type)mmi_imc_send_message( &imc_msg);
        if (first_char == (UI_character_type) '-')
            if(!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR, (U32)&first_char, 0))
                return 0;
    }

    
#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__)
#if !defined  (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if (g_imc_pen_is_down_in_extra_block)
    {
        mmi_imm_hand_writing_category_info_struct_p hw_info = mmi_imm_get_hand_writing_category(g_imc_pen.curr_mode_details->lang_id);
        hw_type = hw_info->extra_block;
        mmi_ime_hand_writing_initialize(hw_type);
    }
    else
    {
        hw_type = (mmi_imc_pen_handwriting_type_enum)(IME_HAND_WRITING_GET_HW_TYPE(g_imc_pen.curr_mode_details->Handwriting_Attrib));
    }
#else
    #if defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
	{
		hw_type = (mmi_imc_pen_handwriting_type_enum)(IME_HAND_WRITING_GET_HW_TYPE(g_imc_pen.curr_mode_details->Handwriting_Attrib));
	}
    #else
	{
		const sIMEModeDetails * mode_details_ptr;
		input_mode = mmi_imm_handwriting_get_current_mode(); //get input mode set in handwriting language setting
		mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);
		hw_type = (mmi_imc_pen_handwriting_type_enum)(IME_HAND_WRITING_GET_HW_TYPE(mode_details_ptr->Handwriting_Attrib));
	}
    #endif
#endif
#else
	hw_type = (mmi_imc_pen_handwriting_type_enum)(IME_HAND_WRITING_GET_HW_TYPE(g_imc_pen.curr_mode_details->Handwriting_Attrib));

#endif

    query_param.h_w_type = hw_type;
    query_param.stroke_buffer = g_imc_pen_stroke_buffer;
    query_param.desired_cnt = MMI_IMC_PEN_MAX_CANDIDATE_NUM;

    result_param.candidate_array = candidate_buffer;

    if (hw_type != IMM_HANDWRITING_TYPE_NONE)
    {
        //S32 num_from_hwengine = 0;

        kal_get_time(&time1);

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
		if(!mmi_ime_hand_writing_memory_card_is_db_ready())
		{
#if defined(__COSMOS_MMI_PACKAGE__)
            vadp_p2v_show_no_hw_data_popup();
#else
            mmi_popup_display((WCHAR*) ((UI_string_type) GetString(STR_INPUT_METHOD_NO_HW_DATA)), MMI_EVENT_INFO, NULL);
#endif
		}
		else
#endif
		{
			num = (S32)mmi_ime_hand_writing_get_candidates(&query_param, &result_param);
		}
        
        /* Hot Fix: Hanwang Engine was returning num = 9 and candidate buffer only 
         * contained one character in case we enter '.' (DOT).
         *-------------------------------------------------------------------------
         * Ref CR: MAUI_02159213
         */
        //num_from_hwengine =  mmi_ucs2strlen((const S8 *)candidate_buffer);
        
        /* In case of Decuma, num can be less that the actual no. of candidates 
         * in the candidate buffer so checking for only the value of num not to
         * be greater than the actual no. of candidates in the candidate buffer
         *------------------------------------------------------------------------
         * Ref CR: MAUI_02254545
         */
        /*if (num_from_hwengine < num)
        {
            num = num_from_hwengine;
        }*/

        /* The following piece of code has been added to restrict 
         *  the entry of disabled characters from handwriting mode
         */
        {
            S32 i = 0;

            for (i = 0; i < num; i++)
            {
               if (mmi_imm_test_input(&candidate_buffer[i], 1) == MMI_FALSE)
               {
                   memcpy(
                       candidate_buffer + i, 
                       candidate_buffer + i + 1, 
                       ((num - (i + 1)) * sizeof(UI_character_type))); 
               
                   /* Since we are overwriting the candidate content at
                    * position i so we again need to process the candidate
                    * at position i, so the value of 'i' needs to be decremented
                    */
                   i--;

                   /* Since the buffer has been memcpy'ed so we do not need 
                    * process the last canndidate again as it has been copied
                    * to last but one candidate and so the value of 'num' 
                    * should be decremented
                    */
                   num--;
               }
            }
            candidate_buffer[i] = '\0';
        }
        
        /* Hot Fix: Hanwang Engine are using SC, TC and English symbols and 
         * punctuation under one range only
         *-------------------------------------------------------------------------
         * Ref CR: MAUI_02161470
         */
        switch (hw_type)
        {
            case IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION:
            case IMM_HANDWRITING_TYPE_PUNCTUATION:
                {
                    S32 i = 0;

                    /* should only show ASCII characters */
                    for (i = 0; i < num; i++)
                    {
                       if (candidate_buffer[i] > 0xFF)
                       {
                           memcpy(
                               candidate_buffer + i, 
                               candidate_buffer + i + 1, 
                               ((num - (i + 1)) * sizeof(UI_character_type))); 
                           
                           /* Since we are overwriting the candidate content at
                            * position i so we again need to process the candidate
                            * at position i, so the value of 'i' needs to be decremented
                            */
                           i--;

                           /* Since the buffer has been memcpy'ed so we do not need 
                            * process the last canndidate again as it has been copied
                            * to last but one candidate and so the value of 'num' 
                            * should be decremented
                            */
                           num--;
                       }
                    }
                    candidate_buffer[i] = '\0';
                }
                break;
        }

        kal_get_time(&time2);
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_FW_HW_CANDIDATES_RECONGNITION_TIME, kal_ticks_to_milli_secs(time2 - time1));
        if (num > 0)
        {
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
#endif

            /* Candidates from HanWang are not separated by any separator, we must add separator ourselves*/
            mmi_ime_hand_writing_add_separator_to_candidate_buffer(g_imc_pen.global_data_ptr->cand_buff, candidate_buffer, num);
        }
    }

#ifndef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__) 
    if (g_imc_pen_is_down_in_extra_block)
    {
        mmi_ime_hand_writing_initialize((mmi_imc_pen_handwriting_type_enum)(IME_HAND_WRITING_GET_HW_TYPE(g_imc_pen.curr_mode_details->Handwriting_Attrib)));
        g_imc_pen_is_down_in_extra_block = MMI_FALSE;
    }
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__)  */
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && !defined(__NO_HANDWRITING__) && defined(__MMI_VIRTUAL_KEYBOARD__)  */

    if (num > MMI_IMC_PEN_MAX_CANDIDATE_NUM)
    {
        num = MMI_IMC_PEN_MAX_CANDIDATE_NUM;
    }

    g_imc_pen.hw_cand_cnt = num;
    return num;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_change_handwriting_area
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_imc_pen_change_handwriting_area( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_rect input_box_rect;
    mmi_imc_state_enum state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__NO_HANDWRITING__)
    state = mmi_imc_get_state();
    if (mmi_imc_pen_get_handwriting_style() == MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN
        && (state != MMI_IMC_STATE_HAND_WRITING))
    {
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_GET_HANDWRITING_RECT, (U32)&input_box_rect, 0);
        
        g_imc_stroke_area[0].x1 = input_box_rect.x;
        g_imc_stroke_area[0].y1 = input_box_rect.y;
        g_imc_stroke_area[0].x2 = input_box_rect.x + input_box_rect.width - 1;
        g_imc_stroke_area[0].y2 = input_box_rect.y + input_box_rect.height - 1;

#if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            if (state == MMI_IMC_STATE_HAND_WRITING_CAND)
            {
                
                vadp_p2v_change_handwriting_area_ex(1, &g_imc_stroke_area[0], &g_imc_stroke_area[1]);
            }
            else
            {
                vadp_p2v_change_handwriting_area(1, &g_imc_stroke_area[0], &g_imc_stroke_area[1]);
            }
        }
        else
#endif
        {
            if (state == MMI_IMC_STATE_HAND_WRITING_CAND)
            {
                
                mmi_pen_change_handwriting_area_ex(1, &g_imc_stroke_area[0], &g_imc_stroke_area[1]);
            }
            else
            {
                mmi_pen_change_handwriting_area(1, &g_imc_stroke_area[0], &g_imc_stroke_area[1]);
            }
        }
    }
#endif    
}


#if defined(__MMI_VIRTUAL_KEYBOARD__)

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_cursor_move_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_cursor_move_handler(gui_virtual_keyboard_language_enum prev_vk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_redraw_vk = MMI_FALSE;
    MMI_BOOL need_rollback = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check vk captical state after input */
    if (mmi_imc_pen_is_symbol_vk_type(prev_vk))
    {
        /* if vk is changed, change it back and redraw */
        if (prev_vk != MMI_VIRTUAL_KEYBOARD_LANG)
        {
            need_rollback = MMI_TRUE;
        }

    }       
#if defined(__MMI_IME_FTE_ENHANCE__)
    else if ((mmi_imc_get_state() == MMI_IMC_STATE_INITIAL) ||
             (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE))
    {
        if (g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE
            && g_imc_pen.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
        {
            prev_vk = MMI_VIRTUAL_KEYBOARD_LANG;
            mmi_imc_pen_change_vk_by_capital_state();
            if (prev_vk != MMI_VIRTUAL_KEYBOARD_LANG)
            {
                need_redraw_vk = MMI_TRUE;

                /* Auto Capitalization should not change the 
                 * vk layout when curren input type is
                 * handwriting
                 */
                #if !defined(__NO_HANDWRITING__)
                if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_HW)
                {
                    need_rollback = MMI_TRUE;
                }
                #endif /* !defined(__NO_HANDWRITING__) */
            }
        }
    }
    
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */

    if (need_rollback)
    {
        mmi_imc_pen_set_virtual_keyboard(prev_vk, MMI_FALSE);
		
		if (mmi_imc_pen_is_symbol_vk_type(prev_vk))
		{
			if (g_imc_pen.backup_symbol_lock_state)
			{
				g_imc_pen.is_symbol_lock = g_imc_pen.backup_symbol_lock_state;
                g_imc_pen.backup_symbol_lock_state = MMI_FALSE;
                mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK, 0, 0, NULL);
			}
		}

        need_redraw_vk = MMI_TRUE;
    }
    
    if (need_redraw_vk)
    {
        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));
    }

}

#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_corresponding_num_symbol_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static gui_virtual_keyboard_language_enum mmi_imc_pen_get_corresponding_num_symbol_vk_type(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_language_enum ret_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imm_is_chinese_input_method(input_mode))
    {
        ret_type = GUI_VIRTUAL_KEYBOARD_NUMBER_AND_CH_SYMBOL;
    }
    else
    {
    	ret_type = GUI_VIRTUAL_KEYBOARD_NUMBER_AND_SYMBOL;
    }
    return ret_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_curr_input_style
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_imc_pen_input_style_enum mmi_imc_pen_get_curr_input_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_pen.input_type;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_curr_input_style
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_set_curr_input_style(mmi_imc_pen_input_style_enum input_style)
{
    g_imc_pen.input_type = input_style;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_curr_input_style
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_set_user_desired_input_style(mmi_imc_pen_input_style_enum input_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_prefer_input_style = input_style;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_history_input_style
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_set_history_input_style(mmi_imc_pen_input_style_enum input_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_history_input_style = input_style;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_history_input_style
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_set_history_is_vk_enlarge(MMI_BOOL on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_pen_history_vk_on = on;
}

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_virtual_keyboard_by_cap_state
 * DESCRIPTION
 *  To set vk by desired capital state
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_set_virtual_keyboard_by_capital_state(ime_mode_attr_enum capital_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails * mode_detail_ptr = NULL;
    gui_virtual_keyboard_language_enum vk_type;
    MMI_BOOL has_candidate_box;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (capital_state)
    {
        case IME_MODE_ATTR_UPPERCASE:
            mode_detail_ptr = 
                mmi_imc_pen_get_mode_detail_by_capital_state(g_imc_pen.curr_mode_details, IME_MODE_ATTR_UPPERCASE);
            break;
        case IME_MODE_ATTR_LOWERCASE:
            mode_detail_ptr = 
                mmi_imc_pen_get_mode_detail_by_capital_state(g_imc_pen.curr_mode_details, IME_MODE_ATTR_LOWERCASE);
            break;
        default:
            MMI_ASSERT(0);
    }
    mmi_imc_pen_get_vk_type(mode_detail_ptr, &vk_type, &has_candidate_box);
    mmi_imc_pen_set_virtual_keyboard(vk_type, has_candidate_box);
    
}
#endif

#endif

#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_corresponding_symbol_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static gui_virtual_keyboard_language_enum mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_language_enum ret_type;
    U32 input_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_type = mmi_imm_get_curr_input_type();
    if(g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_HW)
    {
        ret_type = GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_1;
    }
    else if(((input_type & IMM_INPUT_TYPE_EMAIL)
        || (input_type & IMM_INPUT_TYPE_URL))
        && g_imc_pen.input_type != MMI_IMC_PEN_INPUT_STYLE_HW)
    {
        return GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_1;
    }
    else if (mmi_imm_is_chinese_input_method(input_mode))
    {
        ret_type = GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_1;
    }
    else
    {
        switch (input_mode)
        {
            case IMM_INPUT_MODE_123_SYMBOLS:
            case IMM_INPUT_MODE_123:
            case IMM_INPUT_MODE_PHONE_NUMBER:
            case IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR:
                ret_type = GUI_VIRTUAL_KEYBOARD_EN_PHONE_SYMBOL;
                break;
        
            default:
                ret_type = GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_1;
                break;
        }
    }

    return ret_type;
}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_corresponding_symbol_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static gui_virtual_keyboard_language_enum mmi_imc_pen_get_corresponding_symbol_vk_type(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_language_enum ret_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imm_is_chinese_input_method(input_mode))
    {
        ret_type = GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL;
    }
    else
    {
        switch (input_mode)
        {
        #if defined(__MMI_IME_FTE_ENHANCE__)
            case IMM_INPUT_MODE_123_SYMBOLS:
              ret_type = GUI_VIRTUAL_KEYBOARD_SYMBOL_FOR_NUM;
		break;
	 #endif	
        
        #ifdef __MMI_LANG_ARABIC__
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
            case IMM_INPUT_MODE_ARABIC_NUMERIC:
#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) */
            case IMM_INPUT_MODE_SMART_ARABIC:
            case IMM_INPUT_MODE_MULTITAP_ARABIC:
                ret_type = GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS;
                break;
        #endif /* __MMI_LANG_ARABIC__ */ 

        #ifdef __MMI_LANG_THAI__
             case IMM_INPUT_MODE_SMART_THAI:
            case IMM_INPUT_MODE_MULTITAP_THAI:
                ret_type = GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL;
                break;
        #endif /* __MMI_LANG_THAI__ */

        #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)

        #ifdef __MMI_LANG_PERSIAN__
            case IMM_INPUT_MODE_MULTITAP_PERSIAN:
            case IMM_INPUT_MODE_SMART_PERSIAN:
                ret_type = GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL;
                break;
        #endif /* __MMI_LANG_PERSIAN__ */ 
       
        #ifdef __MMI_LANG_URDU__
            case IMM_INPUT_MODE_SMART_URDU:
            case IMM_INPUT_MODE_MULTITAP_URDU:
                ret_type = GUI_VIRTUAL_KEYBOARD_URDU_SYMBOLS;
                break;
        #endif /* __MMI_LANG_URDU__ */		

        #ifdef __MMI_INDIC_VK_HINDI__
            case IMM_INPUT_MODE_MULTITAP_HINDI:
            case IMM_INPUT_MODE_SMART_HINDI:
                ret_type = GUI_VIRTUAL_KEYBOARD_HINDI_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_HINDI__ */ 
        #ifdef __MMI_INDIC_VK_TAMIL__
            case IMM_INPUT_MODE_MULTITAP_TAMIL:
            case IMM_INPUT_MODE_SMART_TAMIL:
                ret_type = GUI_VIRTUAL_KEYBOARD_TAMIL_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_TAMIL__ */ 
        #ifdef __MMI_INDIC_VK_BENGALI__
            case IMM_INPUT_MODE_MULTITAP_BENGALI:
            case IMM_INPUT_MODE_SMART_BENGALI:
                ret_type = GUI_VIRTUAL_KEYBOARD_BENGALI_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_BENGALI__ */ 
        #ifdef __MMI_INDIC_VK_ASSAMESE__
            case IMM_INPUT_MODE_MULTITAP_ASSAMESE:
                ret_type = GUI_VIRTUAL_KEYBOARD_ASSAMESE_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_ASSAMESE__ */         
        #ifdef __MMI_INDIC_VK_PUNJABI__
            case IMM_INPUT_MODE_MULTITAP_PUNJABI:
            case IMM_INPUT_MODE_SMART_PUNJABI:
                ret_type = GUI_VIRTUAL_KEYBOARD_PUNJABI_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_PUNJABI__ */ 
        #ifdef __MMI_INDIC_VK_MARATHI__
            case IMM_INPUT_MODE_MULTITAP_MARATHI:
            case IMM_INPUT_MODE_SMART_MARATHI:
                ret_type = GUI_VIRTUAL_KEYBOARD_MARATHI_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_MARATHI__ */ 
        #ifdef __MMI_INDIC_VK_GUJARATI__
            case IMM_INPUT_MODE_MULTITAP_GUJARATI:
            case IMM_INPUT_MODE_SMART_GUJARATI:
                ret_type = GUI_VIRTUAL_KEYBOARD_GUJARATI_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_GUJARATI__ */ 
        #ifdef __MMI_INDIC_VK_KANNADA__
            case IMM_INPUT_MODE_MULTITAP_KANNADA:
            case IMM_INPUT_MODE_SMART_KANNADA:
                ret_type = GUI_VIRTUAL_KEYBOARD_KANNADA_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_KANNADA__ */ 
        #ifdef __MMI_INDIC_VK_ORIYA__
            case IMM_INPUT_MODE_MULTITAP_ORIYA:
            case IMM_INPUT_MODE_SMART_ORIYA:
                ret_type = GUI_VIRTUAL_KEYBOARD_ORIYA_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_ORIYA__ */ 
        #ifdef __MMI_INDIC_VK_MALAYALAM__
            case IMM_INPUT_MODE_MULTITAP_MALAYALAM:
            case IMM_INPUT_MODE_SMART_MALAYALAM:
                ret_type = GUI_VIRTUAL_KEYBOARD_MALAYALAM_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_MALAYALAM__ */ 
        #ifdef __MMI_INDIC_VK_TELUGU__
            case IMM_INPUT_MODE_MULTITAP_TELUGU:
            case IMM_INPUT_MODE_SMART_TELUGU:
                ret_type = GUI_VIRTUAL_KEYBOARD_TELUGU_SYMBOLS;
                break;
        #endif /* __MMI_INDIC_VK_TELUGU__ */
        #endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) */
        #if defined(__MMI_LANG_SPANISH__) && defined(__MMI_IME_FTE_ENHANCE__)
            case IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH:
			case IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH:
			case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH:
			case IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH:
			case IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH: 
			case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH:
                ret_type = GUI_VIRTUAL_KEYBOARD_SPANISH_SYMBOL;
                break;
        #endif /* defined(__MMI_LANG_SPANISH__) && defined(__MMI_IME_FTE_ENHANCE__) */		
            default:
                ret_type = GUI_VIRTUAL_KEYBOARD_SYMBOL;
                break;
        }
    }

    return ret_type;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_is_only_symbol_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_is_only_symbol_vk_type(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (vk_type)
    {
        case GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL:
        case GUI_VIRTUAL_KEYBOARD_SYMBOL:
#if defined(__MMI_LANG_THAI__)
     case GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL:
#endif
    #if defined(__MMI_IME_FTE_ENHANCE__) 
	 case GUI_VIRTUAL_KEYBOARD_NUMBER_AND_CH_SYMBOL:
	
    #if defined(__MMI_LANG_SPANISH__)
     case GUI_VIRTUAL_KEYBOARD_SPANISH_SYMBOL:
    #endif
    //#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)         
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_2:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_3:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_4:
		case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE:
		case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_TWO:
		case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_2:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_3:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4:
    //#endif
    #endif
    #ifdef __MMI_LANG_PERSIAN__
        case GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL:
    #endif /* __MMI_LANG_PERSIAN__ */     

    #ifdef __MMI_LANG_ARABIC__
        case GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS:
    #endif /* __MMI_LANG_ARABIC__ */

    #ifdef __MMI_LANG_URDU__
        case GUI_VIRTUAL_KEYBOARD_URDU_SYMBOLS:
    #endif /* __MMI_LANG_URDU__ */
	
    #ifdef __MMI_INDIC_VK_HINDI__
        case GUI_VIRTUAL_KEYBOARD_HINDI_SYMBOLS :
    #endif /* __MMI_INDIC_VK_HINDI__ */

    #ifdef __MMI_INDIC_VK_TAMIL__
        case GUI_VIRTUAL_KEYBOARD_TAMIL_SYMBOLS:
    #endif /* __MMI_INDIC_VK_TAMIL__ */

    #ifdef __MMI_INDIC_VK_BENGALI__
        case GUI_VIRTUAL_KEYBOARD_BENGALI_SYMBOLS:
    #endif /* __MMI_INDIC_VK_BENGALI__ */
    #ifdef __MMI_INDIC_VK_ASSAMESE__
        case GUI_VIRTUAL_KEYBOARD_ASSAMESE_SYMBOLS:
    #endif /* __MMI_INDIC_VK_ASSAMESE__ */
    #ifdef __MMI_INDIC_VK_PUNJABI__
        case GUI_VIRTUAL_KEYBOARD_PUNJABI_SYMBOLS:
    #endif /* __MMI_INDIC_VK_PUNJABI__ */

    #ifdef __MMI_INDIC_VK_MARATHI__
        case GUI_VIRTUAL_KEYBOARD_MARATHI_SYMBOLS:
    #endif /* __MMI_INDIC_VK_MARATHI__ */

    #ifdef __MMI_INDIC_VK_GUJARATI__
        case GUI_VIRTUAL_KEYBOARD_GUJARATI_SYMBOLS:
    #endif /* __MMI_INDIC_VK_GUJARATI__ */
   
    #ifdef __MMI_INDIC_VK_KANNADA__
        case GUI_VIRTUAL_KEYBOARD_KANNADA_SYMBOLS:
    #endif /* __MMI_INDIC_VK_KANNADA__ */
   
    #ifdef __MMI_INDIC_VK_ORIYA__
        case GUI_VIRTUAL_KEYBOARD_ORIYA_SYMBOLS:
    #endif /* __MMI_INDIC_VK_ORIYA__ */
    
    #ifdef __MMI_INDIC_VK_MALAYALAM__
        case GUI_VIRTUAL_KEYBOARD_MALAYALAM_SYMBOLS:
    #endif /* __MMI_INDIC_VK_MALAYALAM__ */

    #ifdef __MMI_INDIC_VK_TELUGU__
        case GUI_VIRTUAL_KEYBOARD_TELUGU_SYMBOLS:
    #endif /* __MMI_INDIC_VK_TELUGU__ */
 
    #ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
        case GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS:
    #endif 
     /* below check is so that the control doesnot go to the xt9 in case of tray VK*/
		/*  #ifdef __MMI_IME_SMART_QWERTY_VK_INPUT__
        case GUI_VIRTUAL_KEYBOARD_TRAY:
    #endif*/
            ret = MMI_TRUE;
            break;
        default:
            ret = MMI_FALSE;
            break;
    }

    return ret;
}

#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_is_symbol_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_is_symbol_vk_type(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg.message_id = MMI_IMUI_MESSAGE_IS_SYMBOL_VK_TYPE;
    msg.param_0 = vk_type;
    return (MMI_BOOL)mmi_imui_send_message(&msg, NULL);

}
#else
MMI_BOOL mmi_imc_pen_is_symbol_vk_type(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (vk_type)
    {
        case GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL:
        case GUI_VIRTUAL_KEYBOARD_SYMBOL:
#if defined(__MMI_LANG_THAI__)
     case GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL:
#endif
    #if defined(__MMI_IME_FTE_ENHANCE__) 
	 case GUI_VIRTUAL_KEYBOARD_NUMBER_AND_CH_SYMBOL:
	 case GUI_VIRTUAL_KEYBOARD_NUMBER_AND_SYMBOL:
     case GUI_VIRTUAL_KEYBOARD_SYMBOL_FOR_NUM:
    #if defined(__MMI_LANG_SPANISH__)
     case GUI_VIRTUAL_KEYBOARD_SPANISH_SYMBOL:
    #endif
    //#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)         
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_2:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_3:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_4:
		case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE:
		case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_TWO:
		case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_2:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_3:
        case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4:
        case GUI_VIRTUAL_KEYBOARD_LANG_NUMBER:
    //#endif
    #endif
    #ifdef __MMI_LANG_PERSIAN__
        case GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL:
    #endif /* __MMI_LANG_PERSIAN__ */     

    #ifdef __MMI_LANG_ARABIC__
        case GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS:
    #endif /* __MMI_LANG_ARABIC__ */

    #ifdef __MMI_LANG_URDU__
        case GUI_VIRTUAL_KEYBOARD_URDU_SYMBOLS:
    #endif /* __MMI_LANG_URDU__ */
	
    #ifdef __MMI_INDIC_VK_HINDI__
        case GUI_VIRTUAL_KEYBOARD_HINDI_SYMBOLS :
    #endif /* __MMI_INDIC_VK_HINDI__ */

    #ifdef __MMI_INDIC_VK_TAMIL__
        case GUI_VIRTUAL_KEYBOARD_TAMIL_SYMBOLS:
    #endif /* __MMI_INDIC_VK_TAMIL__ */

    #ifdef __MMI_INDIC_VK_BENGALI__
        case GUI_VIRTUAL_KEYBOARD_BENGALI_SYMBOLS:
    #endif /* __MMI_INDIC_VK_BENGALI__ */
    #ifdef __MMI_INDIC_VK_ASSAMESE__
        case GUI_VIRTUAL_KEYBOARD_ASSAMESE_SYMBOLS:
    #endif /* __MMI_INDIC_VK_ASSAMESE__ */
    #ifdef __MMI_INDIC_VK_PUNJABI__
        case GUI_VIRTUAL_KEYBOARD_PUNJABI_SYMBOLS:
    #endif /* __MMI_INDIC_VK_PUNJABI__ */

    #ifdef __MMI_INDIC_VK_MARATHI__
        case GUI_VIRTUAL_KEYBOARD_MARATHI_SYMBOLS:
    #endif /* __MMI_INDIC_VK_MARATHI__ */

    #ifdef __MMI_INDIC_VK_GUJARATI__
        case GUI_VIRTUAL_KEYBOARD_GUJARATI_SYMBOLS:
    #endif /* __MMI_INDIC_VK_GUJARATI__ */
   
    #ifdef __MMI_INDIC_VK_KANNADA__
        case GUI_VIRTUAL_KEYBOARD_KANNADA_SYMBOLS:
    #endif /* __MMI_INDIC_VK_KANNADA__ */
   
    #ifdef __MMI_INDIC_VK_ORIYA__
        case GUI_VIRTUAL_KEYBOARD_ORIYA_SYMBOLS:
    #endif /* __MMI_INDIC_VK_ORIYA__ */
    
    #ifdef __MMI_INDIC_VK_MALAYALAM__
        case GUI_VIRTUAL_KEYBOARD_MALAYALAM_SYMBOLS:
    #endif /* __MMI_INDIC_VK_MALAYALAM__ */

    #ifdef __MMI_INDIC_VK_TELUGU__
        case GUI_VIRTUAL_KEYBOARD_TELUGU_SYMBOLS:
    #endif /* __MMI_INDIC_VK_TELUGU__ */
 
    #ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
        case GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS:
    #endif 
     /* below check is so that the control doesnot go to the xt9 in case of tray VK*/
  /*  #ifdef __MMI_XT9__
        case GUI_VIRTUAL_KEYBOARD_TRAY:
    #endif*/
            ret = MMI_TRUE;
            break;
        default:
            ret = MMI_FALSE;
            break;
    }

    return ret;
}

#endif

#if defined (__MMI_INDIC_VK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_is_symbol_vk_type
 * DESCRIPTION
 * Checks whether input Vk is Indic or not
 * PARAMETERS
 * vk_type	[IN]	Vk type to be checked for Indic
 * RETURNS
 * MMI_BOOL 
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_is_indic_vk_type(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (vk_type)
    {
    #ifdef __MMI_INDIC_VK_HINDI__
        case GUI_VIRTUAL_KEYBOARD_HINDI_CONS_MATRAS1:
        case GUI_VIRTUAL_KEYBOARD_HINDI_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_HINDI_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_HINDI_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_HINDI__ */  
    #ifdef __MMI_INDIC_VK_TAMIL__
        //case GUI_VIRTUAL_KEYBOARD_TAMIL_CONS_MATRAS1:
        //case GUI_VIRTUAL_KEYBOARD_TAMIL_CONS_INDEPEDENTVOWELS1:
          case GUI_VIRTUAL_KEYBOARD_TAMIL:
    #endif /* __MMI_INDIC_VK_TAMIL__ */ 
    #ifdef __MMI_INDIC_VK_BENGALI__
        case GUI_VIRTUAL_KEYBOARD_BENGALI_CONS_MATRAS1:
        case GUI_VIRTUAL_KEYBOARD_BENGALI_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_BENGALI_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_BENGALI_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_BENGALI__ */ 
    #ifdef __MMI_INDIC_VK_ASSAMESE__
        case GUI_VIRTUAL_KEYBOARD_ASSAMESE_CONS_MATRAS1:
        case GUI_VIRTUAL_KEYBOARD_ASSAMESE_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_ASSAMESE_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_ASSAMESE_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_ASSAMESE__ */ 
    #ifdef __MMI_INDIC_VK_PUNJABI__
        //case GUI_VIRTUAL_KEYBOARD_PUNJABI_CONS_MATRAS1:
        //case GUI_VIRTUAL_KEYBOARD_PUNJABI_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_PUNJABI :
        case GUI_VIRTUAL_KEYBOARD_PUNJABI_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_PUNJABI_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_PUNJABI__ */ 
    #ifdef __MMI_INDIC_VK_MARATHI__
        //case GUI_VIRTUAL_KEYBOARD_MARATHI_CONS_MATRAS1:
        //case GUI_VIRTUAL_KEYBOARD_MARATHI_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_MARATHI :
        case GUI_VIRTUAL_KEYBOARD_MARATHI_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_MARATHI_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_MARATHI__ */ 
    #ifdef __MMI_INDIC_VK_GUJARATI__
        case GUI_VIRTUAL_KEYBOARD_GUJARATI_CONS_MATRAS1:
        case GUI_VIRTUAL_KEYBOARD_GUJARATI_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_GUJARATI_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_GUJARATI_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_GUJARATI__ */ 
    #ifdef __MMI_INDIC_VK_KANNADA__
        case GUI_VIRTUAL_KEYBOARD_KANNADA_CONS_MATRAS1:
        case GUI_VIRTUAL_KEYBOARD_KANNADA_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_KANNADA_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_KANNADA_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_KANNADA__ */ 
    #ifdef __MMI_INDIC_VK_ORIYA__
        case GUI_VIRTUAL_KEYBOARD_ORIYA_CONS_MATRAS1:
        case GUI_VIRTUAL_KEYBOARD_ORIYA_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_ORIYA_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_ORIYA_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_ORIYA__ */ 
    #ifdef __MMI_INDIC_VK_MALAYALAM__
        case GUI_VIRTUAL_KEYBOARD_MALAYALAM_CONS_MATRAS1:
        case GUI_VIRTUAL_KEYBOARD_MALAYALAM_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_MALAYALAM_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_MALAYALAM_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_MALAYALAM__ */ 
     #ifdef __MMI_INDIC_VK_TELUGU__
        //case GUI_VIRTUAL_KEYBOARD_TELUGU_CONS_MATRAS1:
        //case GUI_VIRTUAL_KEYBOARD_TELUGU_CONS_MATRAS2:
        case GUI_VIRTUAL_KEYBOARD_TELUGU :
        case GUI_VIRTUAL_KEYBOARD_TELUGU_CONS_INDEPEDENTVOWELS1:
        case GUI_VIRTUAL_KEYBOARD_TELUGU_CONS_INDEPEDENTVOWELS2:
    #endif /* __MMI_INDIC_VK_TELUGU__ */ 
            return MMI_TRUE;
        default:
            return MMI_FALSE;
   }
}
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_event_callback
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
gui_virtual_keyboard_event_enum mmi_imc_pen_vk_event_callback(gui_virtual_keyboard_pen_enum key_event, S32 key_param, U32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_event_enum ret_val = GUI_VIRTUAL_KEYBOARD_EVENT_START;
    #ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_vk_event_callback_data_struct vk_event_callback_data;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_IME_PLUG_IN__
    vk_event_callback_data.vk_event    = key_event;
    vk_event_callback_data.key_param   = key_param;
    vk_event_callback_data.ret_ptr     = (U32*)ret;
    vk_event_callback_data.ret_val_ptr = &ret_val;

    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_VK_CALLBACK_EVENT, (U32)&vk_event_callback_data, 0) == 1)
    {
        return ret_val;
    }
#endif

#if defined(__MMI_LANG_TR_CHINESE__)
    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO)
    {
        switch (key_event)
        {
            case GUI_VKBD_PEN_ZHUYIN_B_P: /* for Zhuyin B & P */
            case GUI_VKBD_PEN_ZHUYIN_M_F: /* for Zhuyin M & F */
            case GUI_VKBD_PEN_ZHUYIN_D_T: /* for Zhuyin D & T */
            case GUI_VKBD_PEN_ZHUYIN_N_L: /* for Zhuyin N & L */
            case GUI_VKBD_PEN_ZHUYIN_G_J: /* for Zhuyin G & J */
            case GUI_VKBD_PEN_ZHUYIN_K_Q: /* for Zhuyin K & Q */
            case GUI_VKBD_PEN_ZHUYIN_H_X: /* for Zhuyin H & X */
            case GUI_VKBD_PEN_ZHUYIN_ZH_CH: /* for Zhuyin ZH & CH */
            case GUI_VKBD_PEN_ZHUYIN_A_O: /* for Zhuyin A & O */
            case GUI_VKBD_PEN_ZHUYIN_AI_EI: /* for Zhuyin AI & EI */
            case GUI_VKBD_PEN_ZHUYIN_AN_EN: /* for Zhuyin AI & EI */
            #if defined(__MMI_IME_ZHUYIN_HALF_QWERTY_VK__)

                ret_val = GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE;
				/*pop up gets shown before resetting map_index in event handler, so resetting before showing popup*/
				 if (key_event != g_imc_pen.zhuyin_vk_event)
                 {
                      g_imc_pen.zhuyin_vk_char_map_index = -1;
                 }
                if (g_imc_pen_zhuyin_half_qwert_keymap[key_event - GUI_VKBD_PEN_ZHUYIN_B_P][g_imc_pen.zhuyin_vk_char_map_index + 1] == 0x0000)
                {
                    *((U32*)ret) = 0;        
                }
                else
                {                
                    *((U32*)ret) = g_imc_pen.zhuyin_vk_char_map_index + 1;
                }
            #endif
                break;
            case GUI_VKBD_PEN_ZHUYIN_COMMA_DOT:
            #if defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_480X800__)
                ret_val = GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE;
                if (g_imc_pen_zhuyin_qwert_keymap[0][g_imc_pen.zhuyin_vk_char_map_index + 1] == 0x0000)
                {
                    *((U32*)ret) = 0;        
                }
                else
                {                
                    *((U32*)ret) = g_imc_pen.zhuyin_vk_char_map_index + 1;
                }
            #endif    
                break;
        }
            
    }
#endif    
    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET ||
        MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_UPPERCASE)
    {
        if (key_event == GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM)
            ret_val = GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE;
    }
    return ret_val;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_virtual_keyboard
 * DESCRIPTION
 *  To set desired vk type
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_set_virtual_keyboard(gui_virtual_keyboard_language_enum vk_type, MMI_BOOL has_cand_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VIRTUAL_KEYBOARD, (U32)vk_type, (U32)has_cand_box, NULL);
    wgui_virtual_keyboard_register_display_callback(mmi_imc_pen_vk_icon_display_callback);
#elif defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
    {        
        mmi_imui_virtual_keyboard_parameter vk_parameter =             
        {
            (gui_virtual_keyboard_language_enum)0,
            0,
            MMI_FALSE,
            mmi_imc_pen_vk_event_callback,
            mmi_imc_pen_vk_icon_display_callback
        };
        vk_parameter.vk_type = vk_type;
        vk_parameter.vk_style = g_imc_pen.vk_style;
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VIRTUAL_KEYBOARD, (U32)(&vk_parameter), 0, NULL);        
    }

	/* we need to change the page of KDb whenever vK is set*/
    #if defined __MMI_XT9__
        mmi_ime_change_page_of_kdb(vk_type);
    #endif


#elif defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    {        
        mmi_imui_virtual_keyboard_parameter vk_parameter =             
        {
            (gui_virtual_keyboard_language_enum)0,
            0,
            MMI_FALSE
        };
        vk_parameter.vk_type = vk_type;
        vk_parameter.vk_style = g_imc_pen.vk_style;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VIRTUAL_KEYBOARD, (U32)(&vk_parameter), 0, NULL);        
    }

    mmi_imc_pen_set_vk_active_row(mmi_imm_get_curr_input_type());
#endif
}


#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_enable_multiblock_handwriting
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_enable_multiblock_handwriting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
    if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK)
    {
        if (g_is_multi_block_enabled == MMI_FALSE)
        {
            mmi_imc_pen_start_capture_strokes(
				 MMI_IMC_PEN_STROKE_BUFFER_SIZE,
				 g_imc_pen_stroke_buffer,
				 2,
				 g_imc_stroke_area,
				 NULL);
            
            g_is_multi_block_enabled = MMI_TRUE;
            mmi_imc_pen_begin_strokes_of_character();
        }
    }
#endif /* #if defined(__MMI_HANDWRITING_MULTI_BLOCK__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_disable_multiblock_handwriting
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_disable_multiblock_handwriting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
    if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK)
    {
        if (g_is_multi_block_enabled == MMI_TRUE)
        {
            mmi_imc_pen_stop_capture_strokes();

            g_is_multi_block_enabled = MMI_FALSE;
        }
    }
#endif /* #if defined(__MMI_HANDWRITING_MULTI_BLOCK__) */
}


#if defined(__MMI_VIRTUAL_KEYBOARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_is_multiblock_handwriting_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_is_multiblock_handwriting_type(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_imc_get_hw_type_validity())
        return MMI_FALSE;
    
	if (vk_type == GUI_VIRTUAL_KEYBOARD_TRAY
		|| vk_type == GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY
		|| vk_type == GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY)
	{
            return MMI_TRUE;
	}
	else 
	{
		switch(mmi_imm_get_curr_input_type() & (~IMM_INPUT_TYPE_MASK))
		{
		case IMM_INPUT_TYPE_NUMERIC:
		case IMM_INPUT_TYPE_PHONE_NUMBER:
		case IMM_INPUT_TYPE_DECIMAL_NUMERIC:
		case IMM_INPUT_TYPE_SIGNED_NUMERIC:
		case IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC:
		case IMM_INPUT_TYPE_KEYPAD_NUMERIC:
		case IMM_INPUT_TYPE_SIM_NUMERIC:
		case IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR:
			return MMI_TRUE;
		default:
			return MMI_FALSE;
		}
	}	
}
#endif


#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_word_prediction_cand
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static S32 mmi_imc_pen_word_prediction_get_cand(UI_string_type pre_string, S32 first_index, S32 desired_cnt, UI_string_type cand_buf, MMI_BOOL *next_page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HANDWRITING_PHRASE__   
    mmi_ime_hand_writing_phrase_query_param query_param; 
    mmi_ime_hand_writing_phrase_result_param query_result;
#else
    mmi_ime_query_param_struct   query_param;
    mmi_ime_query_result_struct  query_result;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    query_param.pre_string = pre_string;
    query_param.first_index = first_index;
    query_param.desired_cnt = desired_cnt;
    query_result.result_buffer = cand_buf;

#ifdef __MMI_HANDWRITING_PHRASE__   
    mmi_ime_hand_writing_get_candidates_by_phrase(&query_param, &query_result);
#else
    #if defined __MMI_XT9__
	/* when tapped we need to provide xt9 with the last character entered to get 
	the predicted candidates*/
        mmi_ime_word_get_associates_chinese_when_tapped( &query_param, &query_result );
    #else
    mmi_ime_word_get_associates(&query_param, &query_result);
    #endif
#endif /* __MMI_HANDWRITING_PHRASE__ */

    *next_page = query_result.next_page;
    return query_result.result_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_word_prediction
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_pen_word_prediction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type char_code = 0;
    S32 count = 0;
    MMI_BOOL next_page = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled())
    {
        return;
    }

    if ((g_imc_pen.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)
		|| (g_imc_pen.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_STROKE))
    {
        if(mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR, (U32)&char_code, 0))
        {
            if (char_code >= 0x4e00 && char_code <= 0x9fff)
            {
                g_imc_pen.global_data_ptr->pre_string[0] = char_code;
                g_imc_pen.global_data_ptr->pre_string[1] = 0;
                

                count = mmi_imc_pen_word_prediction_get_cand(
                                g_imc_pen.global_data_ptr->pre_string, 
                                0, 
                                MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE, 
                                g_imc_pen.global_data_ptr->cand_buff, 
                                &next_page);            

                g_imc_pen.global_data_ptr->cand_page = 0;
                g_imc_pen.global_data_ptr->cand_first_index[0] = 0;
                g_imc_pen.global_data_ptr->cand_select= 0;
                    
                if (count > 0)
                {
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
                    {
                        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                    }
                    else
                    {
                        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
                    }
                #endif
                
                    mmi_imc_update_candidate_box_by_query_result(g_imc_pen.global_data_ptr->cand_buff, (U8)count, next_page);
                    
                #if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
                    g_imc_pen.global_data_ptr->cand_select = (g_imc_pen.global_data_ptr->cand_count - 1) / 2;
                #else
                    g_imc_pen.global_data_ptr->cand_select = 0;
                #endif

                    mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_pen.global_data_ptr->cand_select, 0, NULL);
                
                    mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
                    mmi_imc_redraw_screen_by_state();
                }
            }
        }
    }
}
#endif /* defined(__MMI_HANDWRITING_WORD_PREDICTION__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_start_waiting_for_confirm
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_start_waiting_for_confirm(void)
{
#if !defined(__NO_HANDWRITING__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str;
    MMI_BOOL ret =MMI_FALSE;
    BOOL lcd_freeze = gdi_lcd_get_freeze();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str = mmi_imc_get_candidate_by_index(g_imc_pen.global_data_ptr->cand_buff, g_imc_pen.global_data_ptr->cand_select);

    lcd_freeze = gdi_lcd_get_freeze();
	mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
    
    if (mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_OVERWRITE_MODE, 0, 0))
    {
        if (!mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE, 0, 0))
        {
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
        }

        #if defined (__MMI_MULTIGRAPH_SUPPORT__)
        if (mmi_ucs2strlen((const S8 *)str)>=2)
            ret = (MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING, (U32)str, 0);
        else
        #endif /* defined (__MMI_MULTIGRAPH_SUPPORT__) */

            ret = (MMI_BOOL)mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, (U32)str[0], 0);
        if (ret  || g_imc_pen.global_data_ptr->cand_page > 0)       
        {
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_restart_timer(g_imc_pen_confirm_period, mmi_imc_pen_confirm_handwriting_selection, mmi_imc_pen_confirm_handwriting_selection);
            return MMI_TRUE;
        }
        else
        {
		    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);

            if (!ret)
            {
                mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
            }

		    mmi_imc_gdi_lcd_freeze(lcd_freeze);   
		    return MMI_FALSE;
        }
    }
    else
    {	
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
        mmi_imc_config_printing_character(MMI_FALSE);

        g_imc_pen.global_data_ptr->cand_length = 
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, (U32)g_imc_pen.global_data_ptr->cand_length, (U32)str);
        if (! g_imc_pen.global_data_ptr->cand_length)
        {
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            mmi_imc_config_printing_character(MMI_FALSE);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            return MMI_FALSE;
        }
        else
        {
            mmi_imc_config_printing_character(MMI_TRUE);
            mmi_imc_restart_timer(g_imc_pen_confirm_period, mmi_imc_pen_confirm_handwriting_selection, mmi_imc_pen_confirm_handwriting_selection);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            return MMI_TRUE;
        }
    }
#endif /* #if !defined(__NO_HANDWRITING__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_confirm_handwriting_selection
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_confirm_handwriting_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str = NULL;
    BOOL lcd_freeze = gdi_lcd_get_freeze();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_delete_timer();
    
    str = mmi_imc_get_candidate_by_index(g_imc_pen.global_data_ptr->cand_buff, g_imc_pen.global_data_ptr->cand_select);

    mmi_imc_print_string_inserted_to_editor(str, mmi_ucs2strlen((const S8 *)str));
 
    lcd_freeze = gdi_lcd_get_freeze();
	mmi_imc_gdi_lcd_freeze(MMI_TRUE); 

    if (mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_IS_OVERWRITE_MODE, 0, 0))
    {
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
    }
    else
    {
		    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
	  }	
    g_imc_pen.global_data_ptr->cand_length = 0;
    
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    mmi_imc_redraw_screen_by_state();
    
    mmi_imc_gdi_lcd_freeze(lcd_freeze);
    #if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
		{
    mmi_imc_repaint_screen();
		}
    #else
        mmi_imc_repaint_screen();
    #endif

}

#if defined(__MMI_VIRTUAL_KEYBOARD__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_desired_vk_type
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_set_desired_vk_type(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_pen_desired_vk_type = vk_type;
}
#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__)  */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_send_ui_message
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static U32  mmi_imc_pen_send_ui_message( U8 msg_id, U32 param_0, U32 param_1, mmi_imui_command_funcptr command_callback )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imui_msg.message_id    = msg_id;
    imui_msg.param_0       = param_0;
    imui_msg.param_1       = param_1;
    
    return mmi_imui_send_message(&imui_msg, command_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_send_imc_message
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static U32 mmi_imc_pen_send_imc_message(U8 msg_id, U32 param_0, U32 param_1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct imc_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imc_msg.message_id    = msg_id;
    imc_msg.param_0       = param_0;
    imc_msg.param_1       = param_1;
    
    return mmi_imc_send_message(&imc_msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_softkey_up_post_hdlr
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_softkey_up_post_hdlr(FuncPtr f)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_pen_softkey_up_post_halr = f;
}


#ifdef __MMI_CLIPBOARD__
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_clipboard_long_press_timer_handler
 * DESCRIPTION
 *  Full screen handwriting clipboard mark text state entry function. We start a timer when pen down,
 *  When timeout we set the state to clipboard mark text state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_pen_clipboard_long_press_timer_handler(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum state;
    mmi_imui_message_struct imui_msg;
	#if defined(__UI_MMS_VIEWER_CATEGORY__) && defined(__MMI_CLIPBOARD_FLOATING_MENU__)
    gdi_handle vLayer = 0;
    gdi_handle src_layer_handle;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clipboard_pen_long_press && !mmi_imc_clipboard_is_disable() && mmi_imc_clipboard_is_allow_to_enter_state()/* &&
        ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_MULTILINE_INPUT_BOX) || 
         (wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_EMS_INPUT_BOX) ||
         ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
          (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX)))*/)
    {
        MMI_BOOL enter_mark_state = MMI_TRUE;
        state = mmi_imc_get_state();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
    #endif
        if (state == MMI_IMC_STATE_SMART_CANDIDATE 
            || state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC
            || state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC)
        {
            if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
            {
                mmi_imc_key_smart_alphabetic_confirm_candidate();
				#if !defined(__MMI_FTE_ENHANCE__) 
				mmi_pen_reset();
				enter_mark_state = MMI_FALSE;
				#endif /* !defined(__MMI_FTE_ENHANCE__)  */
                if (state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC)
                {
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                }
            }
            else
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }
            mmi_imc_redraw_screen_by_state();
        }
        else if ((g_pen_timer_callback != NULL) && (g_pen_timer_callback != mmi_imc_pen_clipboard_long_press_timer_handler))
        {   
            g_pen_timer_callback();
            g_pen_timer_callback = NULL;
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }   
        else if (g_pen_down_state != MMI_IMC_STATE_INITIAL)
        {
        #if defined(__MMI_IME_CANDIDATE_GRID__)
			if(mmi_imc_is_grid_state())
			{
				mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
				mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
			}
		#endif
			mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            g_pen_down_state = MMI_IMC_STATE_INITIAL;
        }

        if (enter_mark_state)
        {
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
                mmi_imc_pen_play_touch_feed_back();
#else
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
#endif

            mmi_imc_clipboard_enter_mark_text_state(MARK_TEXT_BY_PEN);

        #ifdef __MMI_CLIPBOARD_FLOATING_MENU__
            imui_msg.message_id = MMI_IMUI_MESSAGE_SHOW_CLIPBOARD_FLOATING_MENU;
            mmi_imui_send_message(&imui_msg, NULL);
            mmi_imc_clipboard_show_option_floating_menu();
        #endif
        }

    #if(UI_DOUBLE_BUFFER_SUPPORT)
		gui_unlock_double_buffer();
	#endif

        /* In case when in handwriting state, pen down to mark text */
        if (g_pen_down_state != MMI_IMC_STATE_INITIAL)
        {
            g_pen_down_state = MMI_IMC_STATE_INITIAL;
        }

        g_clipboard_pen_down_event.mmi_pen_event = MMI_PEN_EVENT_LONG_TAP;
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_LOCATE_CURSOR_P_BY_POS, (U32)&g_clipboard_pen_down_event, (U32)&g_imc_clipboard_data);

    #if defined(__UI_MMS_VIEWER_CATEGORY__) && defined(__MMI_CLIPBOARD_FLOATING_MENU__)
        vLayer = wgui_mv_get_video_layer();
        if (vLayer > 0)
        {
            gdi_get_alpha_blending_source_layer(&src_layer_handle);
            gdi_set_alpha_blending_source_layer(vLayer);
            gui_vertical_scrollbar_set_alpha_blend_layer(&MMI_multiline_inputbox.vbar, src_layer_handle);
            mmi_imc_clipboard_redraw_screen_by_state();
            gdi_set_alpha_blending_source_layer(src_layer_handle);
        }
        else
        {
            mmi_imc_clipboard_redraw_screen_by_state();
        }
        
    #else
        mmi_imc_clipboard_redraw_screen_by_state();
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_clipboard_mark_text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imc_pen_clipboard_mark_text(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT, (U32)&g_imc_clipboard_data, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_clipboard_repeat_timer_handler
 * DESCRIPTION
 *  Full screen handwriting clipboard repeat handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_pen_clipboard_repeat_timer_handler(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_clipboard_move_p1.x == g_clipboard_move_p2.x) && (g_clipboard_move_p1.y == g_clipboard_move_p2.y))
    {
        mmi_imc_pen_event_pen_repeat_handler(g_clipboard_move_p1);
    }
    mmi_imc_start_timer(HANDWRITING_REPEAT_TIMEOUT, mmi_imc_pen_clipboard_repeat_timer_handler, NULL);
    g_clipboard_move_p1.x=  g_clipboard_move_p2.x;
    g_clipboard_move_p1.y= g_clipboard_move_p2.y;
}

#endif /* __MMI_CLIPBOARD__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_reset_ime_state
 * DESCRIPTION
 * PARAMETERS    
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_imc_pen_reset_ime_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mmi_imc_get_state())
    {        
    case MMI_IMC_STATE_HAND_WRITING_CAND:

        mmi_imc_pen_confirm_handwriting_selection();
        break;
	
	case MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX:
		mmi_imc_pen_confirm_handwriting_selection();
		break;

    case MMI_IMC_STATE_HAND_WRITING:

        if (!mmi_imc_is_handwriting_disabled())
        {
            mmi_imc_pen_end_strokes_of_character();
        
            mmi_imc_pen_begin_strokes_of_character();
        
            mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);

            if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN )
            {
                mmi_imc_pen_stop_capture_strokes();
            
                mmi_imc_pen_start_capture_strokes(
                    MMI_IMC_PEN_STROKE_BUFFER_SIZE,
                    g_imc_pen_stroke_buffer,
                    1,
                    &g_imc_stroke_area[0],
		     &g_imc_stroke_area[1]);
            }
            else if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_SINGLE_BLOCK )
        
                {
                mmi_imc_pen_stop_capture_strokes();
                mmi_imc_pen_start_capture_strokes(
                         MMI_IMC_PEN_STROKE_BUFFER_SIZE,
                         g_imc_pen_stroke_buffer,
                         2,
                         g_imc_stroke_area,
                         NULL);

                }
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        
            mmi_imc_redraw_screen_by_state();
        }
        break;

#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
    case MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING:
    
        if (!mmi_imc_is_handwriting_disabled())
        {
            mmi_imc_pen_end_strokes_of_character();
            
            mmi_imc_pen_begin_strokes_of_character();
            
            mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0, NULL);

            if (g_imc_pen.handwriting_style == MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK
                && g_is_multi_block_enabled)
            {
                mmi_imc_pen_stop_capture_strokes();
                
                mmi_imc_pen_start_capture_strokes(
                    MMI_IMC_PEN_STROKE_BUFFER_SIZE,
                    g_imc_pen_stroke_buffer,
                    2,
                    g_imc_stroke_area,
                    NULL);
            }

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                
            mmi_imc_redraw_screen_by_state();
        }
        break;
#endif /* #if defined(__MMI_HANDWRITING_MULTI_BLOCK__) */

    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_change_hw_cand_index
 * DESCRIPTION
 * To change handwriting candidate highlight index
 * PARAMETERS    
 * RETURNS
 * Void
 *****************************************************************************/
void mmi_imc_pen_change_hw_cand_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__NO_HANDWRITING__)    
    if (mmi_imc_pen_start_waiting_for_confirm() == MMI_TRUE)
    {
        mmi_imc_set_state(MMI_IMC_STATE_HAND_WRITING_CAND);
    }
    else
    {
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    }
    mmi_imc_pen_restart_hw_timer();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_clear_pen_repeat_event
 * DESCRIPTION
 *  To clear pen repeat event 
 * PARAMETERS    
 * RETURNS
 * Void
 *****************************************************************************/
void mmi_imc_pen_clear_pen_repeat_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_register_repeat_handler(NULL);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_reset_pen_repeat_event
 * DESCRIPTION
 *  To reset pen repeat event 
 * PARAMETERS    
 * RETURNS
 * Void
 *****************************************************************************/
void mmi_imc_pen_reset_pen_repeat_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_register_repeat_handler(mmi_imc_pen_event_pen_repeat_handler);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_restart_hw_timer
 * DESCRIPTION
 * To restart handwriting timer
 * PARAMETERS    
 * RETURNS
 * Void
 *****************************************************************************/
void mmi_imc_pen_restart_hw_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__NO_HANDWRITING__)    
    mmi_imc_restart_timer(g_imc_pen_confirm_period, mmi_imc_pen_confirm_handwriting_selection, mmi_imc_pen_confirm_handwriting_selection);
#endif
}


#if defined(__MMI_VIRTUAL_KEYBOARD__) 

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_set_vk_at_start
 * DESCRIPTION
 * Sets vk according to folding options
 * PARAMETERS    
 * RETURNS
 * Void
 *****************************************************************************/

void mmi_imc_pen_set_vk_at_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

         
#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
    g_imc_enlarge_vk_at_start = MMI_TRUE;
#else
    switch(mmi_imm_get_curr_input_mode())
    {
        case IMM_INPUT_MODE_123:
        case IMM_INPUT_MODE_SIGNED_123:
        case IMM_INPUT_MODE_FLOAT_123:
        case IMM_INPUT_MODE_SIM_NUMERIC:
        case IMM_INPUT_MODE_SIGNED_FLOAT_123:
        case IMM_INPUT_MODE_KEYPAD_NUMERIC:
	case IMM_INPUT_MODE_ARABIC_NUMERIC:
	case IMM_INPUT_MODE_PHONE_NUMBER:
	case IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR:

            g_imc_enlarge_vk_at_start = MMI_TRUE;
        break;
        default:
            g_imc_enlarge_vk_at_start = MMI_FALSE;
    }
#endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_process_before_changing_input_mode
 * DESCRIPTION
 * PARAMETERS    
 * RETURNS
 * Void
 *****************************************************************************/
static void mmi_imc_pen_process_before_changing_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum old_mode;
    BOOL lcd_freeze = gdi_lcd_get_freeze();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    lcd_freeze = gdi_lcd_get_freeze();
	mmi_imc_gdi_lcd_freeze(MMI_TRUE); 

    mmi_imc_cancel_timer();
    old_mode = mmi_imm_get_curr_input_mode();
    /* In canceling timer, input mode may be changed by WCSS */
    if (old_mode != mmi_imm_get_curr_input_mode())
    {
        if (mmi_imm_set_current_input_mode(old_mode) == MMI_FALSE)
        {
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            return;
        }
        else
        {
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
        }    
    }
    else
    {
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
    }  
     
    switch (mmi_imc_get_state())
    {
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_key_multitap_alphabetic_input_confirm();
            break;
            
        case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
        case MMI_IMC_STATE_SMART_CANDIDATE:
            if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
            {
                mmi_imc_key_smart_alphabetic_confirm_candidate();
            }
            break;
        
        case MMI_IMC_STATE_WORD_HIGHLIGHTED:
            mmi_imc_delete_timer();
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
            break;

#if defined(__MMI_IME_USER_DATABASE__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        case MMI_IMC_STATE_NEW_WORD_MULTITAP:
            mmi_ime_multitap_confirm();
            break;
#endif
        default:
            break;
    }

    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
}

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_open_symbol_lock
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_open_symbol_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_pen.is_symbol_lock = MMI_FALSE;
}
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */


/*****************************************************************************
 * mmi_imc_pen_set_dialer_callback
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_imc_pen_set_dialer_callback(MMI_BOOL (*funcptr)(mmi_imc_dialer_pen_code_enum pen_code, mmi_pen_event_type_enum pen_event))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_imc_pen_dialer_callback = funcptr;
}



/*****************************************************************************
 * mmi_imc_pen_vk_is_dialer_event
 * DESCRIPTION
 *  To check if it is a dialer event
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_is_dialer_event(gui_virtual_keyboard_pen_enum vk_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(vk_event)
    {
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
		case GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL:
#if defined(__MMI_IME_V3__)
#if (defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)) && !defined(__COSMOS_MMI_PACKAGE__)
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
#endif
#else
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
#endif
#endif
            /* Is a dialer event */
            return MMI_TRUE;
        default: 
            /* Not a dialer event */
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * mmi_imc_pen_vk_get_dialer_pen_code
 * DESCRIPTION
 *  Returns the dialer pen code
 * PARAMETERS
 * RETURNS
 *  void 
 *****************************************************************************/
static mmi_imc_dialer_pen_code_enum mmi_imc_pen_vk_get_dialer_pen_code(gui_virtual_keyboard_pen_enum vk_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(vk_event)
    {
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            return MMI_IMC_VK_DIALER_PEN_0;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            return MMI_IMC_VK_DIALER_PEN_1;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            return MMI_IMC_VK_DIALER_PEN_2;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            return MMI_IMC_VK_DIALER_PEN_3;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            return MMI_IMC_VK_DIALER_PEN_4;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            return MMI_IMC_VK_DIALER_PEN_5;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            return MMI_IMC_VK_DIALER_PEN_6;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            return MMI_IMC_VK_DIALER_PEN_7;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            return MMI_IMC_VK_DIALER_PEN_8;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
            return MMI_IMC_VK_DIALER_PEN_9;
		case GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL:
			return MMI_IMC_VK_DIALER_PEN_VIDEO_CALL;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            return MMI_IMC_VK_DIALER_PEN_STAR;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            return MMI_IMC_VK_DIALER_PEN_POUND;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
            return MMI_IMC_VK_DIALER_PEN_CALL1;
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
            return MMI_IMC_VK_DIALER_PEN_CALL2;
#if defined(__MMI_IME_V3__)
#if (defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)) && !defined(__COSMOS_MMI_PACKAGE__)
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
			return MMI_IMC_VK_DIALER_NORMAL_CALL;
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
			return MMI_IMC_VK_DIALER_EMERGENCY_CALL;
#endif
#else
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
			return MMI_IMC_VK_DIALER_NORMAL_CALL;
		case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
			return MMI_IMC_VK_DIALER_EMERGENCY_CALL;
#endif
#endif
        default: 
            /* It should never be here */
            MMI_ASSERT(0);
			return  MMI_IMC_VK_DIALER_PEN_0;//dummy return value
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_alphanumeric_dialer_event_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_alphanumeric_dialer_event_handler(
            mmi_pen_event_type_enum pen_event, 
            gui_virtual_keyboard_pen_enum vk_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_val = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_imc_pen_dialer_callback != NULL);

    if (mmi_imc_pen_dialer_callback(mmi_imc_pen_vk_get_dialer_pen_code(vk_event), pen_event))
    {
        return MMI_FALSE;
    }
    else
    {
    
        if (pen_event == MMI_PEN_EVENT_DOWN)
        {
            switch (vk_event)
            {
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
                    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
#endif /* __MMI_TOUCH_SCREEN__ */
                        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);

                        mmi_imc_config_clean_force_ui_style_valitation(MMI_FALSE);
                        mmi_imc_key_group_key_down_int((U16)(vk_event - GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0 + KEY_0), KEY_EVENT_DOWN);
                        mmi_imc_config_clean_force_ui_style_valitation(MMI_TRUE);
                        ret_val = MMI_FALSE;
                    break;                
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_down_int(KEY_STAR, KEY_EVENT_DOWN);
                    ret_val = MMI_FALSE;
                    break;                
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_down_int(KEY_POUND, KEY_EVENT_DOWN);
                    ret_val = MMI_FALSE;
                    break;   
            }
        }
        else if (pen_event == MMI_PEN_EVENT_UP)
        {
            switch (vk_event)
            {
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
                    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                    #endif
                        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                        mmi_imc_key_group_key_up_int((U16)(vk_event - GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0 + KEY_0), KEY_EVENT_UP);
                        ret_val = MMI_FALSE;
                    break;                
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_up_int(KEY_STAR, KEY_EVENT_UP);
                    ret_val = MMI_FALSE;
                    break;                
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_up_int(KEY_POUND, KEY_EVENT_UP);
                    ret_val = MMI_FALSE;
                    break;  
            }
        }
        else if (pen_event == MMI_PEN_EVENT_REPEAT)
        {
            switch (vk_event)
            {
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
                    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                    #endif
                        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);            
                        mmi_imc_config_clean_force_ui_style_valitation(MMI_FALSE);
                        mmi_imc_key_group_key_repeat_int((U16)(vk_event - GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0 + KEY_0), KEY_EVENT_REPEAT);
                        mmi_imc_config_clean_force_ui_style_valitation(MMI_TRUE);
                        ret_val = MMI_FALSE;
                    break;                
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_repeat_int(KEY_STAR, KEY_EVENT_REPEAT);
                    ret_val = MMI_FALSE;
                    break;                
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_repeat_int(KEY_POUND, KEY_EVENT_REPEAT);
                    ret_val = MMI_FALSE;
                    break;                
            }
        }
        else if (pen_event == MMI_PEN_EVENT_LONG_TAP)
        {
            switch (vk_event)
            {
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
                    #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                    #endif
                        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                        mmi_imc_key_group_key_long_int((U16)(vk_event - GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0 + KEY_0), KEY_LONG_PRESS);
                        ret_val = MMI_FALSE;
                    break;                
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:                
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_long_int(KEY_STAR, KEY_LONG_PRESS);
                    ret_val = MMI_FALSE;
                    break;                
                case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
                #endif
                    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
                    mmi_imc_key_group_key_long_int(KEY_POUND, KEY_LONG_PRESS);
                    ret_val = MMI_FALSE;
                    break;                
            }
        }
    }
    return ret_val;
}

/*****************************************************************************
 * FUNCTION
 * mmi_imc_pen_reset_char_password_mode_callback
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_reset_char_password_mode_callback()
{
     /* to reset any old input of password  */
	 mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
	 mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
	 mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
}

/*****************************************************************************
 * FUNCTION
 * mmi_imc_pen_show_preview_password_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_imc_pen_show_preview_password_mode(U32 char_code)
{
     BOOL lcd_freeze;
     lcd_freeze = gdi_lcd_get_freeze();
     mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
     mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);    
     mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
     mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR , char_code , 0);	
	 mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
	 mmi_imc_gdi_lcd_freeze(lcd_freeze);
     mmi_imc_repaint_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_vk_smart_qwerty_event_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
 MMI_BOOL mmi_imc_pen_vk_smart_qwerty_event_handler(mmi_pen_event_type_enum pen_event, UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   U32 i =0;
   U16 vk_key = KEY_QWERTY;
   UI_character_type *temp_previous_word_buf;
    #if defined(__MMI_IME_USER_DATABASE__)
    UI_string_type temp_ptr = NULL;
    #endif
	MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 


/*process as a key event */
   /*Will be handling event ony on UP event to make it similar to the Normal QWERTY VK*/
    if (pen_event == MMI_PEN_EVENT_DOWN)
        {
        if (ch==0x20)
           return MMI_TRUE;
        else
           return MMI_FALSE;
        }
    else if (pen_event == MMI_PEN_EVENT_REPEAT)
        {
        if (ch==0x20)
		{
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
			if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
			{
               mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
			}
#endif
           return MMI_TRUE;
		}
        else
           return MMI_FALSE;
        }
    else if (pen_event == MMI_PEN_EVENT_LONG_TAP)
        {
        if (ch==0x20)
           return MMI_TRUE;
        else
           return MMI_FALSE;
        }
    else if (pen_event == MMI_PEN_EVENT_UP)
        {

            if (ch == 0x20)
    {
            /*The below switch case is to activate the alphabetic prediction*/
            switch(mmi_imc_get_state())
            {
                /*this is for the generating the preicted words*/
            case MMI_IMC_STATE_SMART_CANDIDATE:
                if (mmi_imm_test_input((UI_string_type)L" ", 1))
                {
					BOOL lcd_freeze;
                #if defined(__MMI_IME_USER_DATABASE__)
                    temp_ptr = mmi_imc_get_candidate_by_index(g_imc_pen.global_data_ptr->cand_buff, g_imc_pen.global_data_ptr->cand_select);

                    if (temp_ptr!= NULL)
                    {
                        if (*temp_ptr == MMI_IME_USER_DATABASE_NEW_WORD)
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                #endif
                
                #if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
                    temp_previous_word_buf = (UI_character_type *)mmi_imc_get_previous_word_buffer();
                    mmi_ucs2cpy((S8 *)&temp_previous_word_buf[0], (const S8 *)temp_ptr);
                #endif
                
                    lcd_freeze = gdi_lcd_get_freeze();
					mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                
                    mmi_imc_key_smart_alphabetic_confirm_candidate();
                    /* add space */
                   // mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);

                            
		#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
                #endif
            #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                 mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
                #endif

                    if (mmi_imc_key_smart_alphabetic_get_associated_words(&temp_previous_word_buf[0], 0) > 0)
                    {
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
        
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
        
                        mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_pen.global_data_ptr->cand_select);

                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);

                        mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC);
                    }
                    else
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                #else
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                #endif
                
                    mmi_imc_gdi_lcd_freeze(lcd_freeze);   
                
                    mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE; 
                    
              }
                break;
                /*the below case is to stop prediction at one level*/
            case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
                if (mmi_imm_test_input((UI_string_type)L" ", 1))
                {
                    if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
                    {
             mmi_imc_key_smart_alphabetic_confirm_candidate();
                    }
                    
		     mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
             mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
             return MMI_TRUE;
	        }
                break;
            default:
             mmi_imc_key_smart_alphabetic_confirm_candidate();
		     mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
             mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
             return MMI_TRUE;

	        }

        }

#if defined __MMI_XT9__
    /* check how many are already there */
          /* if this is first one confirm the candidate */
        /* else carry on adding */
        if (g_imc_pen.global_data_ptr->symb_count == 0)
            mmi_imc_word_add_qwerty_unicode_to_active_seq( ch , 0);
        else
        {
            for (i =0 ; i<g_imc_pen.global_data_ptr->symb_count;i++)
            {
                if(g_imc_pen.global_data_ptr->symb_buff[i] == MMI_IMC_KEY_SYM_QWERTY)
                    continue;
                else
                   { /* confirm candidate and start sequence*/
                        mmi_imc_key_smart_alphabetic_confirm_candidate();
                        mmi_imc_word_add_qwerty_unicode_to_active_seq( ch , 0);
                        break;

                    }
            }
            /* put at last of existing sequence */
            if (i == g_imc_pen.global_data_ptr->symb_count )
            mmi_imc_word_add_qwerty_unicode_to_active_seq( ch , g_imc_pen.global_data_ptr->symb_count);
        }
#endif
		


         #if defined(__MMI_IME_FLOATING_CAND_BOX__)
            mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_FALSE);
        #endif
            mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
            mmi_imc_config_clean_force_ui_style_valitation(MMI_FALSE);
#if defined __MMI_XT9__
            mmi_imc_key_group_key_down_int(vk_key, KEY_EVENT_DOWN);
           // #if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
             //   mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
             //   mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
          //  #endif
#endif

#if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
           ret = mmi_imc_pen_vk_smart_qwerty_event_handler_ext(ch);
		   //need to show character in highlighted state
		   if (ret)
		    {
    		   g_imc_pen.global_data_ptr->cand_select = 0;
               mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
               mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
               mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_pen.global_data_ptr->cand_select);
               mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
            }
#endif
                #if defined(__MMI_SMART_FIRST_UPPERCASE__)
                    #if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    {
                        mmi_event_struct evt;
                            
                        MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);
    
                        MMI_FRM_CB_EMIT_EVENT(&evt);
}
                    #else
                        mmi_imc_key_change_candidate_case_by_previous_string();
                    #endif
#endif


            mmi_imc_config_clean_force_ui_style_valitation(MMI_TRUE);
                mmi_imc_pen_change_vk_by_capital_state();
//perforamnce issue
                //mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_VIRTUAL_KEYBOARD));

		return ret;
     }
    return ret;
}



#if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)

static MMI_BOOL mmi_imc_pen_is_symbol_Key(UI_character_type char_code)
{
    MMI_BOOL ret = MMI_FALSE;
    const UI_character_type symbol_on_language_vk[] = {L'\xd73',L'\xd3d',L'\xc3d',L'\xae1',L'\xa8c',L'\xaf1',L'\xaf0','+','*', '-', ',','.','?','!',':',';','/','\'',L'\x964',L'\x965',L'\xa66',L'\xa67',L'\xa68',L'\xa69',L'\xa6a',L'\xa6b',L'\xa6c',L'\xa6d',L'\xa6e',L'\xa6f'};
    const num = sizeof(symbol_on_language_vk)/sizeof(UI_character_type);
    S32 i = 0;
    
    for(; i < num; i++)
        {
            if(symbol_on_language_vk[i] == char_code)
                ret = MMI_TRUE;
        }
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_pen_vk_smart_qwerty_event_handler_ext
*  we need to make this function common for all vendor!
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_pen_vk_smart_qwerty_event_handler_ext(UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum input_mode;
#if !defined(__MMI_IME_FTE_ENHANCE__)
    gui_virtual_keyboard_language_enum vk_type;
#endif
    MMI_BOOL has_candidate = MMI_FALSE;
    mmi_imc_message_struct imc_msg;
    UI_character_type first_char;
    MMI_BOOL ret_val = MMI_FALSE;        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_imc_pen_is_symbol_Key(char_code))//code here that we are in smart alphabetic
    {
        g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count++] = char_code;//mmi_ime_word_code_to_symbol(char_code);

        if (mmi_imc_pen_set_vk_candidate() == MMI_FALSE)
        {   /* Resume previours candidate */
            if (--g_imc_pen.global_data_ptr->symb_count)
            {
                while (g_imc_pen.global_data_ptr->symb_count)
                {
                    if (mmi_imc_pen_set_vk_candidate() == MMI_TRUE)
                    {
						ret_val = MMI_TRUE;
                        break;
                    }
                    else
                    {
                        g_imc_pen.global_data_ptr->symb_count --;
                    }    
                }
            }
            g_imc_pen.global_data_ptr->symb_buff[g_imc_pen.global_data_ptr->symb_count] = 0;
            return ret_val;
        }
        else
        {
            return MMI_TRUE;
        }   
    }
    else
    {
        if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE)
        {

            UI_string_type str = NULL;
            str = mmi_imc_get_select_string_from_candidate_box();
#if defined(__MMI_IME_USER_DATABASE__)
            if (str && *str != MMI_IME_USER_DATABASE_NEW_WORD)
#endif
            {
                mmi_imc_select_candidate_from_candidate_box();
            }
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
        mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)char_code, 0);
#if defined(__MMI_IME_FTE_ENHANCE__)
        ret_val = mmi_imc_pen_vk_back_to_lang();
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */
        mmi_imc_clear_symbol_buffer();
        return MMI_FALSE;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled
 * DESCRIPTION
 *  It tests if the chinese word prediction by pen is enabled
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  if the chinese word prediction by pen is enabled
 *****************************************************************************/
static MMI_BOOL mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HANDWRITING_WORD_PREDICTION__
    return g_mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_config_chinese_word_prediction_by_pen_enabled
 * DESCRIPTION
 *  It configs if the chinese word prediction by pen is enabled
 * PARAMETERS
 *  is_enabled  : [IN] If chinese word prediction by pen is enabled
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_pen_config_chinese_word_prediction_by_pen_enabled(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HANDWRITING_WORD_PREDICTION__
    g_mmi_imc_pen_is_chinese_word_prediction_by_pen_enabled = is_enabled;
#endif
}


#if defined(__MMI_IME_V3__) && defined(__MMI_IME_VK_TYPE_HANDWRITING__)
void mmi_imc_pen_change_vk_style_from_list(void)
{
    if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_HANDWRITING)
    {
        g_imc_pen.vk_style = g_imc_pen.vk_style_before_handwriting;
        if(g_imc_pen.vk_style == MMI_VK_TYPE_QWERTY)
        {
            g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
            g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY;
            mmi_imm_config_keyboard_type(IMM_KEYPAD_QWERTY);
        }
        else if(g_imc_pen.vk_style == MMI_VK_TYPE_ALPHANUMERIC)
{
            g_imc_pen.vk_style = MMI_VK_TYPE_ALPHANUMERIC;
            g_imc_pen.input_type = MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC;
            mmi_imm_config_keyboard_type(IMM_KEYPAD_ALPHANUMERIC);
        }
	// special case for change handwriting vk to normal, but input mode haven't be changed.
        if(g_imc_pen.curr_mode_details->imm_mode_id == mmi_imm_get_curr_input_mode())
        {
            const sIMEModeDetails * mode_detail_ptr;
            mode_detail_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
            mmi_imc_pen_setup_virtual_keyboard(mode_detail_ptr);
        }
    }
}


void mmi_imc_pen_show_handwriting_vk()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
    const sIMEModeDetails * mode_details_ptr;
    mmi_imm_input_mode_enum input_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    input_mode = mmi_imm_handwriting_get_current_mode(); //get input mode set in handwriting language setting
    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);
    hw_type = (mmi_imc_pen_handwriting_type_enum)(IME_HAND_WRITING_GET_HW_TYPE(mode_details_ptr->Handwriting_Attrib));

    if(!mmi_imm_IsInputTypeNumber() )
    {
        g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_HW;
		if(g_imc_pen.vk_style != MMI_VK_TYPE_HW)
		{
			g_imc_pen.vk_style_before_handwriting = g_imc_pen.vk_style;
			g_imc_pen.vk_style = MMI_VK_TYPE_HW;
		}
        mmi_imc_pen_stop_singleblock_handwriting();
        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);
        mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);
        mmi_imm_config_keyboard_type(IMM_KEYPAD_HANDWRITING);
        mmi_imc_pen_vk_enable_single_block_hw();
#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
        if(mmi_imc_get_slider_status()== OPEN)
        {
            mmi_imc_process_simulated_slider_event(CLOSE);
        }
        else
        {
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
        }
#else
        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
        mmi_imc_redraw_screen_by_state();
#endif
    }
}

#endif

#if defined(__MMI_COSMOS_KEYPAD_BAR__) && !defined(__NO_HANDWRITING__) &&  !defined(__MMI_IME_V3__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_show_handwriting_vk
 * DESCRIPTION
 *  shows handwriting vk for bar phone, in bar phone only handwriting works, no other vk
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_pen_show_handwriting_vk()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_handwriting_type_enum hw_type = IMM_HANDWRITING_TYPE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	hw_type = (mmi_imc_pen_handwriting_type_enum)(U8)(g_imc_pen.curr_mode_details->Handwriting_Attrib);
	if(mmi_ime_hand_writing_hw_type_query(hw_type) && !mmi_imm_IsInputTypeNumber())
	{
	   //mmi_ime_hand_writing_initialize(hw_type);
       g_imc_pen.input_type =  MMI_IMC_PEN_INPUT_STYLE_HW;
	   g_imc_pen.vk_style = MMI_VK_TYPE_QWERTY;
	   mmi_imc_pen_stop_singleblock_handwriting();
       mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_SET_VK_STYLE, g_imc_pen.vk_style, 0, NULL);
       mmi_imc_pen_set_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY, MMI_FALSE);
	   mmi_imm_config_keyboard_type(IMM_KEYPAD_HANDWRITING);
	   mmi_imc_pen_vk_enable_single_block_hw();
       mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
	   mmi_imc_redraw_screen_by_state();
	}
}
#endif
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_process_state_before_sliding
 * DESCRIPTION
 *  In slider phone, we need to process state on slide
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_pen_process_state_before_sliding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //BOOL lcd_freeze = gdi_lcd_get_freeze();   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //lcd_freeze = gdi_lcd_get_freeze();
	//gdi_lcd_freeze(MMI_TRUE); 
    //mmi_imc_cancel_timer();
#if !defined(__NO_HANDWRITING__)
	if(MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
	{
		mmi_imc_pen_vk_enable_single_block_hw();
	}
#endif
    switch (mmi_imc_get_state())
    {
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_key_multitap_alphabetic_input_confirm();
            break;
	#if defined(__MMI_CSTAR_PHRASE_INPUT__)
		case MMI_IMC_STATE_SPELL_WITH_INPUT:
            mmi_imc_key_smart_phonetic_candidate_select();
			break;
	#endif
        case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
        case MMI_IMC_STATE_SMART_CANDIDATE:
		case MMI_IMC_STATE_VK_CAND:
		case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC: 
            if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
            {
                mmi_imc_key_smart_alphabetic_confirm_candidate();
				mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0); //it will insert one space in the last api
            }
            break;
        
        case MMI_IMC_STATE_WORD_HIGHLIGHTED:
            mmi_imc_delete_timer();
            mmi_imc_pen_send_imc_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
            break;
		case MMI_IMC_STATE_HAND_WRITING:
            mmi_imc_delete_timer();
			break;
		case MMI_IMC_STATE_HAND_WRITING_CAND:
		case MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX:
			mmi_imc_pen_confirm_handwriting_selection();
			break;

#if defined(__MMI_IME_USER_DATABASE__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        case MMI_IMC_STATE_NEW_WORD_MULTITAP:
            mmi_ime_multitap_confirm();
            break;
#endif
        default:
			mmi_imc_delete_timer();
            break;
    }

#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
	if (mmi_imc_get_state() != MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS)
	{
		 mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	}
#else
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
#endif
}
#endif
#if defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_get_keyinfo
 * DESCRIPTION
 * Get Information of key from virtual keyboard and used for showing popup
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
gui_virtual_keyboard_key_pos_info_struct mmi_imc_pen_get_keyinfo(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_pos_info_struct key_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&key_info, 0, sizeof(gui_virtual_keyboard_key_pos_info_struct));
	if (g_imc_pen.input_type == MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC)
    {
            key_info.key_value = GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE;
    }
    else
    {
            key_info.key_value = GUI_VKBD_PEN_CHANGE_MODE;
    }
    mmi_imc_pen_send_ui_message(MMI_IMUI_GET_VK_KEY_POSITION, (U32)&key_info, 0, NULL);
	return key_info;
}
#endif


// [MRE_Editor] IME process pen through mmi_imc_process_pen_input !!!!
// return MMI_TRUE when pos in IMUI (VK, candidate box...) and Editor
// retrun MMI_FALSE when pos in other area like application's UI so application can handle the pen

/*****************************************************************************
* FUNCTION
*  mmi_imc_process_pen_input
* DESCRIPTION
* according to event pass to up /down /long /repeat existing handlers 
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imc_process_pen_input(mmi_pen_point_struct pos , U16 event_type)   /* New Api */
{
    MMI_BOOL ret;

	if (!mmi_imc_is_connected())
	{
		ASSERT(0); /* to check if any invalid call being madde during development */
		return MMI_FALSE;
	}

    switch (event_type)
    {
        case MMI_PEN_EVENT_DOWN :
            mmi_imc_pen_event_pen_down_handler(pos);
            break;
        case  MMI_PEN_EVENT_MOVE :          
            mmi_imc_pen_event_pen_move_handler(pos);
            break;
        case MMI_PEN_EVENT_UP:            
        {  
	if (g_imc_pen.pen_down_type == MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR || g_imc_pen.pen_down_type == MMI_IMC_PEN_DOWN_UI_TYPE_IMUI ||
        g_pen_general_pen_down_control == DM_LSK || g_pen_general_pen_down_control == DM_RSK || g_pen_general_pen_down_control == DM_CSK )
    {
        ret = MMI_TRUE;
    }
    else
    {
        ret = MMI_FALSE;
    }
            mmi_imc_pen_event_pen_up_handler(pos);//after calling this, the g_pen_general_pen_down_control is set to 0
            return ret;
        }
        case MMI_PEN_EVENT_ABORT:            
            mmi_imc_pen_event_pen_abort_handler(pos);
            break;
		case MMI_PEN_EVENT_REPEAT:
			mmi_imc_pen_event_pen_repeat_handler(pos);
			break;
		case MMI_PEN_EVENT_LONG_TAP:
			mmi_imc_pen_event_pen_long_tap_handler(pos);
			break;

    }

    /* return MMI_TRUE when pos in IMUI (VK, candidate box...), Editor and Softkey */
    /* retrun MMI_FALSE when pos in other area like application's UI so application can handle the pen */
	if (g_imc_pen.pen_down_type == MMI_IMC_PEN_DOWN_UI_TYPE_EDITOR || g_imc_pen.pen_down_type == MMI_IMC_PEN_DOWN_UI_TYPE_IMUI ||
        g_pen_general_pen_down_control == DM_LSK || g_pen_general_pen_down_control == DM_RSK || g_pen_general_pen_down_control == DM_CSK )
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}

#if defined(__MMI_IME_V3__)&& defined(__MMI_IME_VK_TYPE_HANDWRITING__)

void set_full_screen(void)
{
	g_imc_pen_hw_full_screen = (MMI_BOOL)!g_imc_pen_hw_full_screen;
}

MMI_BOOL get_is_full_screen(void)
{
	return g_imc_pen_hw_full_screen;
}
#endif //__MMI_IME_V3__

#if defined(__MMI_VIRTUAL_KEYBOARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_pen_is_handwriting_vk
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_imc_pen_is_handwriting_vk(void)
{
    #if defined(__MMI_IME_V3__)
	   if(g_imc_pen.vk_style == MMI_VK_TYPE_HW && MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY)
	   {
		   return MMI_TRUE;
	   }
	   else
	   {
		   return MMI_FALSE;
	   }
	#else
	if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_TRAY)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
	#endif
}
#endif

#if defined(__MMI_CSTAR_PHRASE_INPUT__) && defined(__MMI_IME_CANDIDATE_GRID__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_get_candidates_qwerty_input_mode
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imc_pen_get_candidates_qwerty_input_mode(void)
{

	mmi_ime_query_param_struct query_param;
    mmi_ime_query_result_struct query_result;

	g_imc_pen.global_data_ptr->cand_page = 0;
    memset(g_imc_pen.global_data_ptr->cand_first_index, 0, sizeof(U16) * (MMI_IMC_MAX_CANDIDATE_PAGE + 1));

	query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;

	if (mmi_imc_is_qwerty_smart_pinyin_input())
	{
		if (g_imc_pen.global_data_ptr->input_confirm_length > g_imc_pen.global_data_ptr->symb_count)
			/* due to delete input! or lift it to deletion handle process? */
			g_imc_pen.global_data_ptr->input_confirm_length = g_imc_pen.global_data_ptr->symb_count;
		query_param.elembuf_cnt = g_imc_pen.global_data_ptr->symb_count - g_imc_pen.global_data_ptr->input_confirm_length;
		query_param.elembuf_ptr = g_imc_pen.global_data_ptr->symb_buff + g_imc_pen.global_data_ptr->input_confirm_length;
	}
	else
	{
		query_param.elembuf_cnt = g_imc_pen.global_data_ptr->symb_count;
		query_param.elembuf_ptr = g_imc_pen.global_data_ptr->symb_buff;    
	}

	query_param.first_index = 0;
	query_param.tone_value = MMI_IMC_SYMB_TONE_NONE;
	query_param.comp_selected =  0xff;
	query_result.result_buffer = g_imc_pen.global_data_ptr->cand_buff;
	query_result.match_length_table = g_imc_pen.global_data_ptr->cand_match_len;
	//mmi_ime_word_get_candidates(&query_param, &query_result);
	mmi_imc_get_candidates_from_word_engine(&query_param, &query_result);
	mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
}
#endif


/*****************************************************************************
 * FUNCTION
 * mmi_imc_pen_process_vk_state_after_confirm_candidate
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
void mmi_imc_pen_process_vk_state_after_confirm_candidate(void)
{
	#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
	if(!mmi_imm_is_auto_capitalization_valid() && mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
	#endif
	{
	#if defined(__MMI_VIRTUAL_KEYBOARD__)
	    if(g_imc_pen.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
	    {
	        g_imc_pen.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
	        mmi_imc_pen_set_gui_state(IME_MODE_ATTR_LOWERCASE);
	        mmi_imc_change_input_mode_according_to_capital_state(g_imc_pen.global_data_ptr->capital_state);
	        mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK,0,0,NULL);
	    }
	#endif
	}
}
#endif
#endif /* __MMI_TOUCH_SCREEN__ */

