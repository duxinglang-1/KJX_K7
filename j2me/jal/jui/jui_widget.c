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
 *   Jui_widget.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements GUI widget
 *
 * Author:
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include header files
 *************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*************************************************************************
 * MTK include header files
 *************************************************************************/
#include "kal_release.h"
////#include "lcd_sw.h"
#include "lcd_if.h"
#include "gui.h"
#include "wgui_categories.h"
#include "wgui_softkeys.h"
#include "wgui_categories_util.h"

#include "jam_msg_handler.h"
#include "settingprofile.h"
#include "statusiconres.h"
#include "jal.h"
#include "jui_internal.h"
#include "jvm_adaptor.h"
#include "jam_internal.h"
#include "jma_internal.h"
#include "mmi_frm_gprot.h"
#include "j2me_custom_option.h"
#include "Resource_audio.h"
#ifdef SUPPORT_MMAPI
#include "lcd_if.h"
#include "gdi_include.h"
#endif /* SUPPORT_MMAPI */ 
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_include.h"
#include "CommonScreens.h"
#include "mmu.h"
#include "cp15.h"
#include "cache_sw.h"
#include "FunAndGamesResDef.h"

#include "JavaAgencyUITextField.h"
#include "JavaAgencyUITextBox.h"
#include "JavaAgencyUIOptionMenu.h"
#include "JavaAgencyUIDateField.h"
#include "JavaAgencyUICommon.h"
#include "JavaAgencyDef.h"
#include "jvm_trace_interface.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#include "ImeGprot.h"
#endif
/*************************************************************************
 * Definition
 *************************************************************************/
#define BOTTOM_BAR_HEIGHT           MMI_button_bar_height
#define SOFTBUTTON_WIDTH            MMI_softkey_width
#define JUI_ICON_SPACE            2
#define JUI_SUPPORT_FULLSCREEN_ICON_NUMBER            14

/*************************************************************************
 * external Function
 *************************************************************************/

#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
extern void gui_title_oem_show_normal_ex(void);
#endif 

/*************************************************************************
 * External Variable
 *************************************************************************/
extern icontext_button MMI_softkeys[WGUI_MAX_SOFTKEYS];
extern gdi_layer_struct *gdi_act_layer;

extern kal_mutexid g_jam_lcd_mutex;
extern kal_mutexid g_jam_ime_mutex;

/*************************************************************************
 * Global Variable
 *************************************************************************/
/*only for slim support*/
kal_bool   jui_is_unregistered_lcd = KAL_TRUE;
kal_bool   jui_is_vm_drawing_lcd = KAL_FALSE;

jui_screen_data_struct g_jui_screen_data[JUI_MVM_SUPPORT_VM_NUM];

kal_int32 jui_widget_active_display_id = 0;
kal_int32 jui_widget_textbox_display_id = INVALIDE_VM_ID;
kal_uint8  *jui_lcd_total_buffer = NULL;
kal_uint16 *jui_icon_lcd_buffer = NULL;
kal_uint16 *jui_lcd_buffer_double = NULL;

kal_int32   jui_lcd_buffer_size             = 0;    //LCD_WIDTH * LCD_HEIGHT * 2                                          
kal_int32   jui_icon_layer_buffer_size      = 0;    //LCD_WIDTH* ICON_HEIGHT * 2

kal_bool    g_jui_resume_first_screen = KAL_FALSE;
gdi_handle jui_layer_handle = GDI_LAYER_EMPTY_HANDLE;
gdi_handle jui_icon_layer_handle = GDI_LAYER_EMPTY_HANDLE;
gdi_handle jui_icon_layer_blt_handle = GDI_LAYER_EMPTY_HANDLE;
gdi_handle jui_status_icon_layer_handle = GDI_LAYER_EMPTY_HANDLE;
gdi_handle jui_soft_button_layer_handle = GDI_LAYER_EMPTY_HANDLE;
gdi_handle jui_blt_handle = GDI_LAYER_EMPTY_HANDLE;
gdi_handle jui_hardware_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
extern kal_int32 jui_vk_display_id;
kal_uint16 *jui_vk_lcd_buffer = NULL;
kal_int32 jui_vk_lcd_buffer_size = 0;
gdi_handle jui_vk_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#ifndef __JUI_VK_SLIM__
static JVM_MEM_ID jui_vk_pool_id = NULL;
#endif

#endif

kal_uint32 jui_hardware_layer_blt_index = GDI_LAYER_ENABLE_LAYER_1;
kal_int32 jui_title_offset = 0;

kal_bool jui_set_blt_status_icon = KAL_FALSE;

kal_bool jui_double_buffer_activated = KAL_FALSE;

kal_bool jui_widget_is_layer_initialized = KAL_FALSE;

kal_int32 jui_ui_device_width = 0;
kal_int32 jui_ui_device_height = 0;
kal_int32 jui_ui_title_height = 0;
kal_int32 jui_ui_button_height = 0;
kal_int32 jui_ui_ticker_height = 0;
kal_int32 jui_icon_layer_x_position = 0;

kal_bool jui_is_set_jtwi_symbol = KAL_FALSE;
kal_bool jui_widget_register_lcd_done = KAL_FALSE;
kal_bool jui_icon_layer_need_clear = KAL_FALSE;

static kal_uint16 *jui_widget_textbox_temp_buffer = NULL;
static kal_bool jui_widget_draw_softkey_by_vm = KAL_FALSE;
static kal_bool jui_widget_auto_back_from_mmi = KAL_FALSE;
static kal_bool jui_widget_auto_sort_commands = KAL_FALSE;

static kal_bool jui_widget_full_screen_status_icon_status[JUI_SUPPORT_FULLSCREEN_ICON_NUMBER];

static jui_widget_event_listener_void_void_struct *jui_widget_event_listener_void_void;
static jui_widget_event_listener_void_bool_struct *jui_widget_event_listener_void_bool;
static jui_widget_event_listener_void_int_struct *jui_widget_event_listener_void_int;
static jui_widget_mvm_event_listener_void_int_struct *jui_widget_mvm_event_listener_void_int;
static jui_widget_mvm_event_listener_void_int_bool_struct *jui_widget_mvm_event_listener_void_int_bool;
static jui_widget_mvm_event_listener_void_int_int_struct *jui_widget_mvm_event_listener_void_int_int;


static kal_uint32 jui_widget_full_screen_status_icon_list[JUI_SUPPORT_FULLSCREEN_ICON_NUMBER] = 
{
#if !defined (__MMI_STATUS_ICONBAR_COSMOS_STYLE__) && defined (__MMI_MMS_2__)   
    STATUS_ICON_MMS_BUSY,    
#endif
    STATUS_ICON_SMS_SENDING,
    STATUS_ICON_GPRS_SERVICE,
    STATUS_ICON_EDGE,
#if (MMI_MAX_SIM_NUM >= 2) && !defined (__MMI_NW_INFO_DN_STATUS_SLIM__)
    STATUS_ICON_SLAVE_GPRS_SERVICE,
    STATUS_ICON_SLAVE_EDGE,
    MAX_STATUS_ICONS,
#else /* MMI_MAX_SIM_NUM >= 2 */ 
    MAX_STATUS_ICONS,
    MAX_STATUS_ICONS,
    MAX_STATUS_ICONS,
#endif /* MMI_MAX_SIM_NUM >= 2 */
#if (MMI_MAX_SIM_NUM >= 3) && !defined (__MMI_NW_INFO_DN_STATUS_SLIM__)
    STATUS_ICON_SIM3_GPRS_SERVICE,
    STATUS_ICON_SIM3_EDGE,
#else /* MMI_MAX_SIM_NUM >= 3 */ 
    MAX_STATUS_ICONS,
    MAX_STATUS_ICONS,
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4) && !defined (__MMI_NW_INFO_DN_STATUS_SLIM__)
    STATUS_ICON_SIM4_GPRS_SERVICE,
    STATUS_ICON_SIM4_EDGE,
#else /* MMI_MAX_SIM_NUM >= 4 */ 
    MAX_STATUS_ICONS,
    MAX_STATUS_ICONS,
#endif /* MMI_MAX_SIM_NUM >= 4 */
    STATUS_ICON_CSD,
#ifdef __MMI_CALL_INDICATOR__
    STATUS_ICON_CALL_INDICATOR,
#else 
    MAX_STATUS_ICONS,
#endif 
    MAX_STATUS_ICONS
};

static kal_uint32 jui_widget_full_screen_status_icon_bmp_id[JUI_SUPPORT_FULLSCREEN_ICON_NUMBER] = 
{
    IMG_ID_JAVA_FULLSCREEN_MMS_BUSY,
    IMG_ID_JAVA_FULLSCREEN_SMS_SENDING,
    IMG_ID_JAVA_FULLSCREEN_SIM1_GPRS_SERVICE,
    IMG_ID_JAVA_FULLSCREEN_SIM1_EDGE,
#if (MMI_MAX_SIM_NUM >= 2)
    IMG_ID_JAVA_FULLSCREEN_SIM2_GPRS_SERVICE,
    IMG_ID_JAVA_FULLSCREEN_SIM2_EDGE,
    MAX_STATUS_ICONS,
#else /* MMI_MAX_SIM_NUM >= 2 */ 
    MAX_STATUS_ICONS,
    MAX_STATUS_ICONS,
    MAX_STATUS_ICONS,
#endif /* MMI_MAX_SIM_NUM >= 2  */
#if (MMI_MAX_SIM_NUM >= 3)
    IMG_ID_JAVA_FULLSCREEN_SIM3_GPRS_SERVICE,
    IMG_ID_JAVA_FULLSCREEN_SIM3_EDGE,
#else /* MMI_MAX_SIM_NUM >= 3 */ 
    MAX_STATUS_ICONS,
    MAX_STATUS_ICONS,
#endif /* MMI_MAX_SIM_NUM >= 3  */
#if (MMI_MAX_SIM_NUM >= 4)
    IMG_ID_JAVA_FULLSCREEN_SIM4_GPRS_SERVICE,
    IMG_ID_JAVA_FULLSCREEN_SIM4_EDGE,
#else /* MMI_MAX_SIM_NUM >= 4 */ 
    MAX_STATUS_ICONS,
    MAX_STATUS_ICONS,
#endif /* MMI_MAX_SIM_NUM >= 4  */
    IMG_ID_JAVA_FULLSCREEN_CSD,
#ifdef __MMI_CALL_INDICATOR__
    IMG_ID_JAVA_FULLSCREEN_CALL_INDICATOR,
#else 
    MAX_STATUS_ICONS,
#endif 
    MAX_STATUS_ICONS
};

extern kal_bool jui_widget_fullscreen_staus_icons_update_data(kal_int32 * start_position);
extern void jui_widget_fullscreen_staus_icons_draw(kal_int32 start_position);

#if defined(__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_EM_MISC_JUI_DEBUG__) */ 

/*
 *  jui_mutex_lock is a mutex that can be re-enter.
 *  We afarid that VM would be suspend when it hold jui_lcd_mutex
 *  on second entering. That will cause dead lock.
 *  ( jvm_screen_owner true at first, but false at second )
 *
 *  Therefore, jvm_screen_owner must be protected by
 *  jui_lcd_mutex_lock also
 *
 *  => ( jvm_screen_owner true at first, can not change until
 *       java task release jui_lcd_mutex. )
 *
 */

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
#endif /* 0 */

#define JAL_MVM_LOCK_MUTEX(vm_id)           \
    jui_lcd_mutex_lock();                   \
    if(!jam_is_in_fg_screen(vm_id)){        \
        jui_lcd_mutex_unlock();             \
        return;                             \
    }

#define JAL_MVM_LOCK_MUTEX_FALSE(vm_id)           \
    jui_lcd_mutex_lock();                         \
    if(!jam_is_in_fg_screen(vm_id)){              \
        jui_lcd_mutex_unlock();                   \
        return KAL_FALSE;                         \
    }
#define JAL_MVM_UNLOCK_MUTEX \
    jui_lcd_mutex_unlock();

#define JUI_WIDGET_CHECK_DISPLAY_ID(id) ASSERT(id>=0 && id<JUI_MVM_SUPPORT_VM_NUM);

volatile int j2me_lcd_mutex_cnt = 0;
volatile module_type j2me_lcd_mutex_tid = MOD_NIL;

#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
static void jui_widget_title_oem_show_normal_ex(void);
#endif 

static void jui_widget_mvm_option_menu_show_callback(kal_int32 display_id);
static void jui_widget_mvm_option_menu_hide_callback(kal_int32 display_id);
static void jui_widget_mvm_option_menu_disppear_callback(kal_int32 display_id);
static void (* jui_widget_mvm_option_menu_disppear_callback_ptr)(kal_int32 display_id);

#ifdef __USE_JUI_POPUP__
static void jui_widget_mvm_popup_hide_callback(kal_int32 display_id);
static void jui_widget_mvm_popup_disppear_callback(kal_int32 display_id);
static void (* jui_widget_mvm_popup_disppear_callback_ptr)(kal_int32 display_id);
#endif

/*****************************************************************************
 * FUNCTION
 *  jui_lcd_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_lcd_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_get_active_module_id() != j2me_lcd_mutex_tid)
    {
        //while (j2me_lcd_mutex_cnt > 0)
            //kal_sleep_task(1);
        kal_take_mutex(g_jam_lcd_mutex);
        j2me_lcd_mutex_tid = kal_get_active_module_id();
    }
    ++j2me_lcd_mutex_cnt;

}


/*****************************************************************************
 * FUNCTION
 *  jui_lcd_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_lcd_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(j2me_lcd_mutex_tid == kal_get_active_module_id());

    --j2me_lcd_mutex_cnt;

    if (j2me_lcd_mutex_cnt == 0)
    {
        j2me_lcd_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jam_lcd_mutex);
    }
}


/*****************************************************************************
 * FUNCTION
 *  j2me_lcd_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_lcd_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_lcd_mutex_lock();
}


/*****************************************************************************
 * FUNCTION
 *  j2me_lcd_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_lcd_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_lcd_mutex_unlock();
}

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
#ifndef __JUI_VK_SLIM__
static void jui_widget_mvm_allocate_vk_buffer(void)
{

	void *vk_pointer = NULL;

	if (jui_vk_lcd_buffer != NULL)
	{
	    return;
	}

	vk_pointer = jvm_malloc(jui_vk_lcd_buffer_size + 1 * 1024); /* all additional 1k */

    jui_vk_pool_id = (JVM_MEM_ID)kal_adm_create(vk_pointer, jui_vk_lcd_buffer_size + 1 * 1024, NULL, KAL_TRUE);

	ASSERT(jui_vk_pool_id != NULL);

	jui_vk_lcd_buffer =  (kal_uint16 *)kal_adm_alloc_nc_align((KAL_ADM_ID) jui_vk_pool_id, jui_vk_lcd_buffer_size, 32);

    ASSERT(jui_vk_lcd_buffer != NULL);
        
}
static void jui_widget_mvm_free_vk_buffer(void)
{
	if(jui_vk_pool_id)
	{
	    kal_adm_delete((KAL_ADM_ID) jui_vk_pool_id);
		
		jvm_free((void *)jui_vk_pool_id);

		jui_vk_pool_id = NULL;

		jui_vk_lcd_buffer = NULL;
	}

}
#else
static void jui_widget_mvm_get_vk_buffer(kal_uint8 * lcd_buffer)
{
    int bytes_per_pix = 0;
    int offset = 0;
    ASSERT(lcd_buffer);

    if (jui_vk_lcd_buffer != NULL)
        return;

    bytes_per_pix = (gdi_layer_get_bit_per_pixel() >> 3);

    offset = (UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT) * jui_ui_device_width * bytes_per_pix;

    jui_vk_lcd_buffer = (kal_uint16 *) (lcd_buffer + offset);

}

static void jui_widget_mvm_release_vk_buffer(void)
{
    jui_vk_lcd_buffer = NULL;
}


#endif
#endif

#ifdef J2ME_SLIM_MEMORY_SUPPORT
/*----------------------------  lcd buffer patch begin ------------------------------------*/
GDI_HANDLE jui_temp_handle = GDI_LAYER_EMPTY_HANDLE;
/*****************************************************************************
 * FUNCTION
 *  jui_layer_get_buffer_pool_ptr
 * DESCRIPTION
 *  get buffer pointer of gdi_layer_buffer_pool .
 *  __align(32) static U32 gdi_layer_buffer_pool[GDI_ADM_HEADER_SIZE(2,16) + ((GDI_LAYER_BUFFER_SIZE) / 4) + 1];
 * PARAMETERS
 *  buf_pool_ptr     [IN/OUT]       
 * RETURNS
 *  buf_pool_ptr
 *****************************************************************************/
kal_int32 jui_get_gdi_temp_buffer_pool_ptr(void) /*J2ME_SLIM_MEM_GDI_LAYER_BUFFER_SUPPORT*/
{
    kal_int32 buf_size = 0;
    U8* main_base_layer_ptr= NULL;
    if(jui_lcd_buffer != NULL)
    {
        return jui_lcd_buffer_size;
    }
    gdi_layer_create(
        0,
        0,
        GDI_LCD_WIDTH,
        GDI_LCD_HEIGHT,
        &jui_temp_handle);
    gdi_layer_push_and_set_active(jui_temp_handle);
    gdi_layer_get_buffer_ptr(&main_base_layer_ptr);
    buf_size = GDI_LCD_WIDTH * GDI_LCD_HEIGHT*2;
    jui_lcd_buffer = (kal_uint16 *)main_base_layer_ptr;
    gdi_layer_pop_and_restore_active();
    //kal_prompt_trace(MOD_J2ME,"jui_lcd_buffer=%d , buffer SIZE:%d",jui_lcd_buffer, buf_size);
    return (buf_size);
}
void jui_free_gdi_temp_buffer_pool_ptr(void)
{
    if(jui_temp_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(jui_temp_handle);
    }
    jui_temp_handle = GDI_LAYER_EMPTY_HANDLE;
    jui_lcd_buffer = NULL;
}

#ifdef __JUI_SLIM_SAVE_LAYER__ 
#define jui_widget_save_layer_filename "z:\\@Java\\j2me_screen_vm0.bin"
void jui_widget_layer_delete_backup(void)
{
    kal_wchar* filepath = NULL;
    filepath = (kal_wchar*)OslMalloc((strlen(jui_widget_save_layer_filename)+1)<<1);
    kal_wsprintf(filepath, jui_widget_save_layer_filename);
    FS_Delete((const PU16)filepath);
    OslMfree(filepath);
}
/*May be need mutex to protect*/
kal_int32 jui_widget_layer_save(kal_int8* layer, kal_int32 length)
{
    kal_int32 return_len = -1;
    kal_int32 handle;
    kal_int32 ret=0;
    kal_wchar* filepath = NULL;
    kal_int32 startSaveTime,stopSaveTime;
    kal_get_time(&startSaveTime);
    //kal_prompt_trace(MOD_J2ME,"[jui_widget_layer_save] START SAVE TIME:%d ",startSaveTime);

    if(layer == NULL || length <= 0 )
    {
        //kal_prompt_trace(MOD_J2ME,"JUI_WIDGET_SAVE_LAYER_NO_DATA");
        return J2ME_NO_ERROR;
    }
    jui_widget_layer_delete_backup();
    filepath = (kal_wchar*)OslMalloc((strlen(jui_widget_save_layer_filename)+1)<<1);
    kal_wsprintf(filepath, jui_widget_save_layer_filename);
    handle = FS_Open(filepath, FS_CREATE_ALWAYS | FS_READ_WRITE);
    OslMfree(filepath);
    if (handle < 0)
    {
        jui_widget_layer_delete_backup();
        //kal_prompt_trace(MOD_J2ME,"JUI_WIDGET_SAVE_LAYER_OPEN_FILE_ERROR");
        return J2ME_NO_ERROR;
    }
    ret = FS_Write(handle, layer, length, &return_len);
    //kal_prompt_trace(MOD_J2ME,"[jui_widget_layer_save] FS_Write:length=%d,return_len=%d,ret=%d",length,return_len,ret);
    if(ret <0 || return_len != length)
    {
        FS_Close(handle);
        jui_widget_layer_delete_backup();
        //kal_prompt_trace(MOD_J2ME,"STORAGE_NOT_ENOUGH || ret<0 and ret =%d",ret);
        return J2ME_NO_ERROR;
    }
    FS_Close(handle);    
    kal_get_time(&stopSaveTime);
    //kal_prompt_trace(MOD_J2ME,"[jui_widget_layer_save] STOP SAVE TIME:%d ,span=%d ms",stopSaveTime,(stopSaveTime-startSaveTime)*1000/KAL_TICKS_1_SEC);
    return J2ME_NO_ERROR;
}
#endif
kal_bool jui_widget_is_saved_layer = KAL_FALSE;
#define LOGOIMAGE_WIDTH                    (120)
#define LOGOIMAGE_HEIGHT                (40)
void jui_widget_show_logo(void)
{
    kal_int32 width = jui_widget_get_display_width();
    kal_int32 height = jui_widget_get_display_height();
    kal_int32 logoWidth =0;
    kal_int32 ascent,descent,leading;
    short clip[4];

    kal_uint16 logo_string[10] = {'L','o','a','d','i','n','g','.','.','.'};
    kal_uint16 *lcd_buffer = NULL;
    #define STYLE_BOLD          1
    #define SIZE_LARGE         16
    #define FACE_PROPORTIONAL  64
    #define HCENTER             1
    #define VCENTER             2

    jui_widget_mvm_clear_screen(JUI_WIDGET_DEFAULT_DISPLAY_ID); 

    clip[0] = 0;
    clip[1] = 0;
    clip[2] = width;
    clip[3] = height;

    logoWidth = jui_string_get_width(FACE_PROPORTIONAL,STYLE_BOLD,SIZE_LARGE,(const kal_uint16 *) logo_string,sizeof(logo_string));
    jui_string_mvm_draw_string(0x00,clip,jui_widget_get_active_lcd_buffer(),width,height,width*height*2,
    0,FACE_PROPORTIONAL,STYLE_BOLD,SIZE_LARGE,width/2,height/2,HCENTER|VCENTER,(const kal_uint16 *)logo_string,sizeof(logo_string),0);
   
}

#ifdef __JUI_SLIM_SAVE_LAYER__
kal_int32 jui_widget_layer_restore(kal_int8* layer,kal_int32 length)
{
    kal_int32 return_len = -1;
    kal_int32 handle;
    kal_int32 ret=0;
    kal_wchar* filepath = NULL;
    kal_int32 startRestoreTime,stopRestoreTime;
    kal_get_time(&startRestoreTime);
    //kal_prompt_trace(MOD_J2ME,"[jui_widget_layer_restore] START RESTORE TIME:%d ",startRestoreTime);

    if(layer == NULL || length <= 0 || jui_widget_is_saved_layer == KAL_FALSE)
    {
        //kal_prompt_trace(MOD_J2ME,"JUI_WIDGET_SAVE_LAYER_BUFFER_NULL");
        return J2ME_NO_ERROR;
    }
    
    filepath = (kal_wchar*)OslMalloc((strlen(jui_widget_save_layer_filename)+1)<<1);
    kal_wsprintf(filepath, jui_widget_save_layer_filename);
    handle = FS_Open(filepath, FS_READ_ONLY);
    OslMfree(filepath);
    if (handle < 0)
    {
        //kal_prompt_trace(MOD_J2ME,"JUI_WIDGET_SAVE_LAYER_OPEN_FILE_ERROR");
        return DISK_OPERATION_FAIL;
    }
    ret = FS_Read(handle, layer, length, &return_len);
    //kal_prompt_trace(MOD_J2ME,"FS_Read:length=%d,return_len=%d, ret=%d ",length,return_len,ret);
    if(ret < 0)
    {
        FS_Close(handle);
        //kal_prompt_trace(MOD_J2ME,"retValue<0 and ret = %d",ret);
        return DISK_OPERATION_FAIL;
    }
    FS_Close(handle);
    kal_get_time(&stopRestoreTime);
   // kal_prompt_trace(MOD_J2ME,"[jui_widget_restore_layer] STOP RESTORE TIME:%d ,span=%d ms",stopRestoreTime,(stopRestoreTime-startRestoreTime)*1000/KAL_TICKS_1_SEC);    
    return J2ME_NO_ERROR;
}
#endif
/*----------------------------  lcd buffer patch end ------------------------------------*/

static JVM_MEM_ID gditempMemoryId = NULL;
static char *gditempMemoryStart = NULL;
static char *gditempMemoryEnd  = NULL; 
static long gditempSize = 0;

void jui_widget_mvm_gditempmemory_init()
{
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        U8 *buf_ptr = NULL;
        S32 byte_per_pixel = 0;
        
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_get_buffer_ptr(&buf_ptr);
        byte_per_pixel = (gdi_layer_get_bit_per_pixel() >> 3);
        gdi_layer_pop_and_restore_active();

        gditempMemoryStart = (char*)(buf_ptr + jui_ui_device_width * (MMI_title_height + jui_title_offset) * byte_per_pixel);

#ifndef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
        gditempMemoryEnd = (char*)(buf_ptr + (jui_ui_device_width * (UI_device_height - MMI_softkey_height) * byte_per_pixel));
#else
        gditempMemoryEnd = (char*)(buf_ptr + (jui_ui_device_width * (UI_device_height - MMI_softkey_height - JUI_VIRTUAL_KEYPAD_HEIGHT) * byte_per_pixel));
#endif
            
        gditempSize = gditempMemoryEnd -gditempMemoryStart - 2*1024;
        gditempMemoryId =  (JVM_MEM_ID) kal_adm_create(gditempMemoryStart, gditempSize, NULL, KAL_TRUE);
            
}

void* jui_widget_mvm_gditempmemory_allocate(kal_int32 size)
{
        if(gditempMemoryId)
        {
            return kal_adm_alloc_nc_align((KAL_ADM_ID) gditempMemoryId, size, 32);
        }
        return NULL;     
}

void  jui_widget_mvm_gditempmemory_free(void* buffer)
{
        if(gditempMemoryId)
        {
            kal_adm_free((KAL_ADM_ID) gditempMemoryId, buffer);
        }
}

void jui_widget_mvm_gditempmemory_deinit()
{
        gditempMemoryId = NULL;
        gditempSize = 0;
        gditempMemoryStart = NULL;
        gditempMemoryEnd = NULL;
}


#endif /* J2ME_SLIM_MEM_GDI_LAYER_BUFFER_SUPPORT  */

/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_display_properties
 * DESCRIPTION
 *  Get widget display property
 * PARAMETERS
 *  width               [IN/OUT]        Screen width
 *  height              [IN/OUT]        Screen height
 *  adornedHeight       [IN/OUT]        Displayable height
 *  fg_color            [?]             [?]             [?]             [?]
 *  erase_color         [IN/OUT]        Erase color
 *  depth               [IN/OUT]        Color format of ui buffer
 *  alphaLevels         [IN/OUT]        Alpha levels
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_get_display_properties(
        kal_int32 *width,
        kal_int32 *height,
        kal_int32 *adornedHeight,
        kal_int32 *fg_color,
        kal_int32 *erase_color,
        kal_int32 *depth,
        kal_int32 *alphaLevels,
        kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width != NULL)
        *width = jui_ui_device_width;
    if (height != NULL)
        *height = jui_widget_get_display_height_id(vm_id);
    if (adornedHeight != NULL)
    {
    #if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
        if (jui_widget_draw_softkey_by_vm)
        {
            *adornedHeight = jui_widget_get_display_height_id(vm_id);
        }
        else
        {
            *adornedHeight = jui_widget_get_display_height_id(vm_id) - MMI_button_bar_height;
        }
    #else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
        if (jui_widget_draw_softkey_by_vm)
        {
            *adornedHeight = jui_widget_get_display_height_id(vm_id) - MMI_status_bar_height;
        }
        else
        {
            *adornedHeight = jui_widget_get_display_height_id(vm_id) - MMI_button_bar_height - MMI_status_bar_height;
        }
    #endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
    }
    if (fg_color != NULL)
    {
        c = current_MMI_theme->list_selected_item_filler->c;
        *fg_color = (((kal_int32) c.alpha) << 24) |
            (((kal_int32) c.r) << 16) | (((kal_int32) c.g) << 8) | (((kal_int32) c.b));
    }

    if (erase_color != NULL)
    {
        c = current_MMI_theme->general_background_filler->c;
        *erase_color = (((kal_int32) c.alpha) << 24) |
            (((kal_int32) c.r) << 16) | (((kal_int32) c.g) << 8) | (((kal_int32) c.b));
    }

    if (depth != NULL)
        *depth = gdi_layer_get_bit_per_pixel();
    if (alphaLevels != NULL)
        *alphaLevels = 16;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_title_bar_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_get_title_bar_height()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jui_ui_title_height == 0)
    {
        jui_ui_title_height = MMI_title_height;
    }
    return jui_ui_title_height;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_display_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_get_display_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jui_ui_device_width == 0)
    {
        jui_ui_device_width = UI_device_width;
    }
    return jui_ui_device_width;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_display_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_get_display_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int32 vm_id = jam_mvm_get_current_vm_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
        if(jui_ui_device_height)
        {
            return jui_ui_device_height;
        }
        else
        {       if(!(vm_id < 0) && jam_mvm_is_vm_vk_on(vm_id))
                {
                    jui_ui_device_height =  UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT;
                }
        	else
        	{
        	    jui_ui_device_height =  UI_device_height;
        	}

                return  jui_ui_device_height;
        }
        
#else
        return  jui_ui_device_height;
#endif
}

kal_int32 jui_widget_get_display_height_id(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(display_id < 0)
    {
         return 0;
    }
    else
    {
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
         if(display_id == jui_vk_display_id)
        {
            if(jui_ui_device_height)
            {
                return jui_ui_device_height;
            }
            else
            {
                return jui_widget_get_display_height();
            }
            
        }
        else
        {
            if(jam_mvm_is_vm_vk_on(display_id))
            {
                 return  UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT;
            }
            else
            {
                return UI_device_height;
            }
        }
#else
       return jui_ui_device_height;
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_ticker_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_get_ticker_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jui_ui_ticker_height;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_status_bar_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_get_status_bar_height(void) //20110228 : added for repaint status bar
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 width = 0;
    kal_int32 height = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension((U8*) get_image(STATUS_ICON_GPRS_SERVICE), &width, &height);
    return height;
}



/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_button_bar_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_get_button_bar_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jui_ui_button_height == 0)
    {
        jui_ui_button_height = MMI_button_bar_height;
    }
    return jui_ui_button_height;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_play_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  soundType       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_play_sound(kal_int32 soundType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_id_struct id_param;
    med_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_WIDGET_PLAY_SOUND, soundType, jam_get_ring_volume_level());

    /* If mute, return directly */
    if (jam_get_ring_volume_level() == 0)
    {
        return KAL_TRUE;
    }

    if ((soundType == JUI_ALERT_WARNING) || (soundType == JUI_ALERT_ERROR) || (soundType == JUI_ALERT_ALARM))
    {
        switch (soundType)
        {
            case JUI_ALERT_WARNING:
                id_param.audio_id = (U8) TONE_WARNING1;
                break;
            case JUI_ALERT_ERROR:
                id_param.audio_id = (U8) TONE_ERROR1;
                break;
            default:
                id_param.audio_id = (U8) TONE_WARNING1;
                break;
        }

        id_param.play_style = 0;
        id_param.volume = jam_get_ring_volume_level();
        id_param.output_path = MDI_DEVICE_SPEAKER2;
        id_param.identifier = 0;
        result = (med_result_enum) media_aud_play_id(kal_get_active_module_id(), &id_param);

        kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_WIDGET_PLAY_SOUND_RESULT,result);
        return KAL_TRUE;
    }
    else
    {
        kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_WIDGET_PLAY_SOUND_RESULT,-1);
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_set_backlight
 * DESCRIPTION
 *  Set backlight on or off
 * PARAMETERS
 *  mode        [IN]        On or off
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_set_backlight(kal_bool mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode)
    {
        result = jvm_BackLightOn();
    }
    else
    {
        result = jvm_BackLightOff();
    }
    
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_WIDGET_SET_BACKLIGHT, mode,result);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_register_event_listener_void_void
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  event           [IN]        
 *  listener        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_register_event_listener_void_void(jui_event_type_enum event, void (*listener) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_event_listener_void_void_struct *pre = jui_widget_event_listener_void_void;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (listener == NULL)
        return KAL_FALSE;

    if (pre == NULL)
    {
        pre =
            (jui_widget_event_listener_void_void_struct*)
            jvm_malloc(sizeof(jui_widget_event_listener_void_void_struct));
        pre->listener = listener;
        pre->event_type = event;
        pre->next = NULL;

        jui_widget_event_listener_void_void = pre;
    }
    else
    {
        while (pre->listener != listener && pre->next != NULL)
        {
            pre = pre->next;
        }

        if (pre->listener == listener)
            return KAL_TRUE;

        pre->next =
            (jui_widget_event_listener_void_void_struct*)
            jvm_malloc(sizeof(jui_widget_event_listener_void_void_struct));
        pre->next->listener = listener;
        pre->next->event_type = event;
        pre->next->next = NULL;
    }

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_register_event_listener_void_int
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  event           [IN]        
 *  listener        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_register_event_listener_void_int(jui_event_type_enum event, void (*listener) (kal_int32))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_event_listener_void_int_struct *pre = jui_widget_event_listener_void_int;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (listener == NULL)
        return KAL_FALSE;

    if (pre == NULL)
    {
        pre =
            (jui_widget_event_listener_void_int_struct*) jvm_malloc(sizeof(jui_widget_event_listener_void_int_struct));
        pre->listener = listener;
        pre->event_type = event;
        pre->next = NULL;

        jui_widget_event_listener_void_int = pre;
    }
    else
    {
        while (pre->listener != listener && pre->next != NULL)
        {
            pre = pre->next;
        }

        if (pre->listener == listener)
            return KAL_TRUE;

        pre->next =
            (jui_widget_event_listener_void_int_struct*) jvm_malloc(sizeof(jui_widget_event_listener_void_int_struct));
        pre->next->listener = listener;
        pre->next->event_type = event;
        pre->next->next = NULL;
    }

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_register_event_listener_void_bool
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  event           [IN]        
 *  listener        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_register_event_listener_void_bool(jui_event_type_enum event, void (*listener) (kal_bool))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_event_listener_void_bool_struct *pre = jui_widget_event_listener_void_bool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (listener == NULL)
        return KAL_FALSE;

    if (pre == NULL)
    {
        pre =
            (jui_widget_event_listener_void_bool_struct*)
            jvm_malloc(sizeof(jui_widget_event_listener_void_bool_struct));
        pre->listener = listener;
        pre->event_type = event;
        pre->next = NULL;

        jui_widget_event_listener_void_bool = pre;
    }
    else
    {
        while (pre->listener != listener && pre->next != NULL)
        {
            pre = pre->next;
        }

        if (pre->listener == listener)
            return KAL_TRUE;

        pre->next =
            (jui_widget_event_listener_void_bool_struct*)
            jvm_malloc(sizeof(jui_widget_event_listener_void_bool_struct));
        pre->next->listener = listener;
        pre->next->event_type = event;
        pre->next->next = NULL;
    }

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_register_event_listener_void_int
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  event           [IN]        
 *  listener        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_mvm_register_event_listener_void_int(jui_event_type_enum event, void (*listener) (kal_int32))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_struct *pre = jui_widget_mvm_event_listener_void_int;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (listener == NULL)
        return KAL_FALSE;

    if (pre == NULL)
    {
        pre =
            (jui_widget_mvm_event_listener_void_int_struct*)
            jvm_malloc(sizeof(jui_widget_mvm_event_listener_void_int_struct));
        pre->listener = listener;
        pre->event_type = event;
        pre->next = NULL;

        jui_widget_mvm_event_listener_void_int = pre;
    }
    else
    {
        while (pre->listener != listener && pre->next != NULL)
        {
            pre = pre->next;
        }

        if (pre->listener == listener)
            return KAL_TRUE;

        pre->next =
            (jui_widget_mvm_event_listener_void_int_struct*)
            jvm_malloc(sizeof(jui_widget_mvm_event_listener_void_int_struct));
        pre->next->listener = listener;
        pre->next->event_type = event;
        pre->next->next = NULL;
    }

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_register_event_listener_void_int_int
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  event           [IN]        
 *  listener        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_mvm_register_event_listener_void_int_int(
            jui_event_type_enum event,
            void (*listener) (kal_int32, kal_int32))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_int_struct *pre = jui_widget_mvm_event_listener_void_int_int;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (listener == NULL)
        return KAL_FALSE;

    if (pre == NULL)
    {
        pre =
            (jui_widget_mvm_event_listener_void_int_int_struct*)
            jvm_malloc(sizeof(jui_widget_mvm_event_listener_void_int_int_struct));
        pre->listener = listener;
        pre->event_type = event;
        pre->next = NULL;

        jui_widget_mvm_event_listener_void_int_int = pre;
    }
    else
    {
        while (pre->listener != listener && pre->next != NULL)
        {
            pre = pre->next;
        }

        if (pre->listener == listener)
            return KAL_TRUE;

        pre->next =
            (jui_widget_mvm_event_listener_void_int_int_struct*)
            jvm_malloc(sizeof(jui_widget_mvm_event_listener_void_int_int_struct));
        pre->next->listener = listener;
        pre->next->event_type = event;
        pre->next->next = NULL;
    }

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_register_event_listener_void_int_bool
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  event           [IN]        
 *  listener        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_mvm_register_event_listener_void_int_bool(
            jui_event_type_enum event,
            void (*listener) (kal_int32, kal_bool))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_bool_struct *pre = jui_widget_mvm_event_listener_void_int_bool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (listener == NULL)
        return KAL_FALSE;

    if (pre == NULL)
    {
        pre =
            (jui_widget_mvm_event_listener_void_int_bool_struct*)
            jvm_malloc(sizeof(jui_widget_mvm_event_listener_void_int_bool_struct));
        pre->listener = listener;
        pre->event_type = event;
        pre->next = NULL;

        jui_widget_mvm_event_listener_void_int_bool = pre;
    }
    else
    {
        while (pre->listener != listener && pre->next != NULL)
        {
            pre = pre->next;
        }

        if (pre->listener == listener)
            return KAL_TRUE;

        pre->next =
            (jui_widget_mvm_event_listener_void_int_bool_struct*)
            jvm_malloc(sizeof(jui_widget_mvm_event_listener_void_int_bool_struct));
        pre->next->listener = listener;
        pre->next->event_type = event;
        pre->next->next = NULL;
    }

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_unregister_event_listener_void_void
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  void
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_unregister_event_listener_void_void()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_event_listener_void_void_struct *pre = jui_widget_event_listener_void_void;
    jui_widget_event_listener_void_void_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (pre != NULL)
    {
        next = pre->next;
        jvm_free(pre);
        pre = next;
    }

    jui_widget_event_listener_void_void = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_unregister_event_listener_void_int
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  void
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_unregister_event_listener_void_int()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_event_listener_void_int_struct *pre = jui_widget_event_listener_void_int;
    jui_widget_event_listener_void_int_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (pre != NULL)
    {
        next = pre->next;
        jvm_free(pre);
        pre = next;
    }

    jui_widget_event_listener_void_int = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_unregister_event_listener_void_bool
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  void
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_unregister_event_listener_void_bool()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_event_listener_void_bool_struct *pre = jui_widget_event_listener_void_bool;
    jui_widget_event_listener_void_bool_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (pre != NULL)
    {
        next = pre->next;
        jvm_free(pre);
        pre = next;
    }

    jui_widget_event_listener_void_bool = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_unregister_event_listener_void_int
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  void
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_unregister_event_listener_void_int()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_struct *pre = jui_widget_mvm_event_listener_void_int;
    jui_widget_mvm_event_listener_void_int_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (pre != NULL)
    {
        next = pre->next;
        jvm_free(pre);
        pre = next;
    }

    jui_widget_mvm_event_listener_void_int = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_unregister_event_listener_void_int_int
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  void
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_unregister_event_listener_void_int_int()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_int_struct *pre = jui_widget_mvm_event_listener_void_int_int;
    jui_widget_mvm_event_listener_void_int_int_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (pre != NULL)
    {
        next = pre->next;
        jvm_free(pre);
        pre = next;
    }

    jui_widget_mvm_event_listener_void_int_int = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_unregister_event_listener_void_int_bool
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  void
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_unregister_event_listener_void_int_bool()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_bool_struct *pre = jui_widget_mvm_event_listener_void_int_bool;
    jui_widget_mvm_event_listener_void_int_bool_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (pre != NULL)
    {
        next = pre->next;
        jvm_free(pre);
        pre = next;
    }

    jui_widget_mvm_event_listener_void_int_bool = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_fire_event_listener_void_void
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  display_id      [IN]        
 *  event_type      [IN]        
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_fire_event_listener_void_void(kal_int32 display_id, jui_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_struct *mp = jui_widget_mvm_event_listener_void_int;
    jui_widget_event_listener_void_void_struct *sp = jui_widget_event_listener_void_void;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (display_id == JUI_WIDGET_UNKNOWN_DISPLAY_ID)
        display_id = jui_widget_active_display_id;

    if (display_id < 0)
        display_id = JUI_WIDGET_DEFAULT_DISPLAY_ID;

    while (mp != NULL)
    {
        if (mp->event_type == event_type)
        {
            mp->listener(display_id);
        }
        mp = mp->next;
    }

    while (sp != NULL)
    {
        if (mp->event_type == event_type)
        {
            sp->listener();
        }
        sp = sp->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_fire_event_listener_void_int
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  display_id      [IN]        
 *  event_type      [IN]        
 *  data            [IN]        
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_fire_event_listener_void_int(kal_int32 display_id, jui_event_type_enum event_type, kal_int32 data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_int_struct *mp = jui_widget_mvm_event_listener_void_int_int;
    jui_widget_event_listener_void_int_struct *sp = jui_widget_event_listener_void_int;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (display_id == JUI_WIDGET_UNKNOWN_DISPLAY_ID)
        display_id = jui_widget_active_display_id;

    if (display_id < 0)
        display_id = JUI_WIDGET_DEFAULT_DISPLAY_ID;

    while (mp != NULL)
    {
        if (mp->event_type == event_type)
        {
            mp->listener(display_id, data);
        }
        mp = mp->next;
    }

    while (sp != NULL)
    {
        if (mp->event_type == event_type)
        {
            sp->listener(data);
        }
        sp = sp->next;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_fire_event_listener_void_bool
 * DESCRIPTION
 *  register listener
 * PARAMETERS
 *  display_id      [IN]        
 *  event_type      [IN]        
 *  data            [IN]        
 *  listener(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_fire_event_listener_void_bool(kal_int32 display_id, jui_event_type_enum event_type, kal_bool data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_event_listener_void_int_bool_struct *mp = jui_widget_mvm_event_listener_void_int_bool;
    jui_widget_event_listener_void_bool_struct *sp = jui_widget_event_listener_void_bool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (display_id == JUI_WIDGET_UNKNOWN_DISPLAY_ID)
        display_id = jui_widget_active_display_id;

    if (display_id < 0)
        display_id = JUI_WIDGET_DEFAULT_DISPLAY_ID;

    while (mp != NULL)
    {
        if (mp->event_type == event_type)
        {
            mp->listener(display_id, data);
        }
        mp = mp->next;
    }

    while (sp != NULL)
    {
        if (mp->event_type == event_type)
        {
            sp->listener(data);
        }
        sp = sp->next;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_set_draw_softkey_by_vm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  draw        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_set_draw_softkey_by_vm(kal_bool draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_SET_DRAW_SOFTKEY_BY_VM, draw);

    jui_widget_draw_softkey_by_vm = draw;
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_set_back_from_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  draw        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_set_back_from_mmi(kal_bool autoBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_SET_AUTOBACK_FROM_MMI, autoBack);

    jui_widget_auto_back_from_mmi = autoBack;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_is_auto_back_from_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  draw        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_is_auto_back_from_mmi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return jui_widget_auto_back_from_mmi ;
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_is_in_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jui_widget_mvm_is_in_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_is_in_fullscreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jui_widget_mvm_is_in_fullscreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_set_hardware_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        Hardware layer handle
 *  bltindex        [IN]        
 *  bltflag         [?]         [?]         [?]         [?]
 *  U32(?)          [OUT]       Hareware blt index(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_set_hardware_layer(gdi_handle handle, U32 bltindex, U32 *bltflag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gdi_handle layer0, layer1, layer2, layer3;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_SET_HARDWARE_LAYER,handle,bltindex,bltflag);
    
    jui_hardware_layer_handle = handle;

    if (handle != GDI_LAYER_EMPTY_HANDLE)
    {
        if (bltindex == GDI_LAYER_ENABLE_LAYER_3)
        {
            gdi_layer_get_blt_layer(&layer0, &layer1, &layer2, &layer3);
            ASSERT(layer3 == GDI_LAYER_EMPTY_HANDLE);
            if (bltflag)
            {
                if (layer0 != GDI_LAYER_EMPTY_HANDLE)
                    *bltflag |= GDI_LAYER_ENABLE_LAYER_0;
                if (layer1 != GDI_LAYER_EMPTY_HANDLE)
                    *bltflag |= GDI_LAYER_ENABLE_LAYER_1;
                if (layer2 != GDI_LAYER_EMPTY_HANDLE)
                    *bltflag |= GDI_LAYER_ENABLE_LAYER_2;

            }
            jui_hardware_layer_blt_index = bltindex;
            layer3 = jui_hardware_layer_handle;
            gdi_layer_set_blt_layer(layer0, layer1, layer2, layer3);
            return;
        }
    }
    else
    {
        if (jui_hardware_layer_blt_index == GDI_LAYER_ENABLE_LAYER_3)
        {
            gdi_layer_get_blt_layer(&layer0, &layer1, &layer2, &layer3);
            gdi_layer_set_blt_layer(layer0, layer1, layer2, 0);
            return;
        }
    }

    jui_hardware_layer_blt_index = bltindex;

    if (bltflag)
    {
        if (jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id))
        {
            *bltflag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;

            if (jui_icon_layer_blt_handle != GDI_LAYER_EMPTY_HANDLE)
            {
                *bltflag |= GDI_LAYER_ENABLE_LAYER_2;
            }
        }
        else
        {
            *bltflag =
                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 |
                GDI_LAYER_ENABLE_LAYER_3;
        }
    }

    /* JAL_LOCK_MUTEX */
    JAL_MVM_LOCK_MUTEX(jui_widget_active_display_id) if (jui_status_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(jui_status_icon_layer_handle);

    #if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
        if (jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, jui_widget_active_display_id) &&
            g_jui_screen_data[jui_widget_active_display_id].title_is_shown)
        {
            wgui_status_icon_bar_enable_integrated(KAL_TRUE);
            wgui_status_icon_bar_register_integrated_redraw(jui_widget_title_oem_show_normal_ex);
        }
    #endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 

        if ((jui_hardware_layer_handle == GDI_LAYER_EMPTY_HANDLE))
        {
            gdi_draw_solid_rect(
                0,
                jui_title_offset,
                jui_ui_device_width - 1,
                jui_title_offset + MMI_title_height - 1,
                GDI_COLOR_TRANSPARENT);
        }
        else
        {
            if (jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, jui_widget_active_display_id))
            {

                if (jui_double_buffer_activated)
                {
                    gdi_bitblt_resized(
                        jui_blt_handle,
                        0,
                        0,
                        jui_ui_device_width - 1,
                        MMI_title_height - 1,
                        0,
                        jui_title_offset,
                        jui_ui_device_width - 1,
                        jui_title_offset + MMI_title_height - 1);
                }
                else
                {
                    gdi_bitblt_resized(
                        jui_layer_handle,
                        0,
                        0,
                        jui_ui_device_width - 1,
                        MMI_title_height - 1,
                        0,
                        jui_title_offset,
                        jui_ui_device_width - 1,
                        jui_title_offset + MMI_title_height - 1);
                }
            }
            else
            {
                gdi_draw_solid_rect(
                    0,
                    jui_title_offset,
                    jui_ui_device_width - 1,
                    jui_title_offset + MMI_title_height - 1,
                    GDI_COLOR_TRANSPARENT);
            }
        }
        gdi_layer_pop_and_restore_active();
    }
    jui_widget_config_blt_layer();  /* 121206 blt layer */

    /* JAL_UNLOCK_MUTEX */
JAL_MVM_UNLOCK_MUTEX}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_start_double_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_start_double_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_START_DOUBLE_BUFFER,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(jui_widget_active_display_id),
        jam_mvm_get_vm_state(jui_widget_active_display_id),
        jui_double_buffer_activated,
        jui_layer_handle,
        jui_blt_handle);

    if (!jam_is_in_fg_screen(jui_widget_active_display_id))
    {
        return;
    }

#ifndef SUPPORT_CACHED_FONT_ALWAYS
    jui_deinit_cached_font();       //free screen memory for video will use screen memory
#endif /* SUPPORT_CACHED_FONT_ALWAYS */ 

    //ASSERT(jui_double_buffer_activated != KAL_TRUE);
    if (jui_double_buffer_activated)
    {
        return;
    }

    jui_double_buffer_activated = KAL_TRUE;

    if (jui_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        return;
    }

    gdi_layer_push_and_set_active(jui_layer_handle);

    /* copy whole screen data to make sure two buffer are sync */
    memcpy(gdi_act_layer->buf_ptr1, gdi_act_layer->buf_ptr, (UI_device_height * jui_ui_device_width) << 1);
	
    jui_widget_layer_set_position(jui_blt_handle);  /* 020907 */

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_stop_double_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_stop_double_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_STOP_DOUBLE_BUFFER,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(jui_widget_active_display_id),
        jam_mvm_get_vm_state(jui_widget_active_display_id),
        jui_double_buffer_activated,
        jui_layer_handle,
        jui_blt_handle);
    /* ASSERT(jui_double_buffer_activated == KAL_TRUE ); */
#if !defined(__MMI_NCENTER_SUPPORT__) || defined(J2ME_SLIM_MEMORY_SUPPORT)
    jui_double_buffer_activated = KAL_FALSE;
#endif

#ifndef SUPPORT_CACHED_FONT_ALWAYS
    if (jam_is_in_fg_screen(jui_widget_active_display_id))
        jui_init_cached_font(); /* init cached font if video free screen memory */
#endif /* SUPPORT_CACHED_FONT_ALWAYS */ 


}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_draw_status_bar0_background
 * DESCRIPTION
 *  hide function of horizontal status bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_draw_status_bar0_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!jam_is_in_fg_screen(jui_widget_active_display_id))
    {
        return;
    }
    ASSERT(current_MMI_theme->lite_disp_scr_bg_color);
    c = *current_MMI_theme->lite_disp_scr_bg_color;
    if ((GDI_HANDLE) wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR) != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR));
    }

    /* set clip region */
    gui_push_clip();
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &x1, &y1, &x2, &y2);      /* get teh clip values of bar_id */
    gui_set_clip(x1, y1, x2, y2);

    gui_fill_rectangle(x1, y1, x2, y2, c);  /* fill the icon position with grey color */

    gui_pop_clip();

    if ((GDI_HANDLE) wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR) != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_draw_status_bar0
 * DESCRIPTION
 *  update status bar, this function shoule be called when vm is in fg mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_draw_status_bar0()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();  /* don't blt data to screen */

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
#ifndef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_register_hide_callback(WGUI_STATUS_ICON_BAR_H_BAR, jui_widget_draw_status_bar0_background);
#endif
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_update();
    jui_set_blt_status_icon = KAL_TRUE;
    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_reset_vm_bg_status_audio_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_reset_vm_bg_status_audio_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_common_update_status_icon_req_struct * msg;
    module_type module_id = kal_get_active_module_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (module_id == MOD_MMI)
    {
        mmi_java_ui_common_update_status_icon_req_struct req_struct;
        msg = &req_struct;
        msg->is_display_icon = KAL_FALSE;
        msg->vm_id = 0;
        msg->is_reset = KAL_TRUE;
        mmi_java_ui_common_update_mmi_status_audio_icon(msg);
        msg = NULL;
    }
    else
    {
        msg =
            (mmi_java_ui_common_update_status_icon_req_struct*) construct_local_para(
                                                    sizeof(mmi_java_ui_common_update_status_icon_req_struct),
                                                    TD_CTRL);
        msg->is_display_icon = KAL_FALSE;
        msg->vm_id = 0;
        msg->is_reset = KAL_TRUE;
        
        java_send_msg(module_id,MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_UI_MMI_STATUS_ICON_UPDATE_RSP,msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_update_vm_bg_status_audio_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_java_bg_audio        [IN]        If Java background audio on
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_update_vm_bg_status_audio_icon(kal_bool is_java_bg_audio, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_common_update_status_icon_req_struct * msg;
    module_type module_id = kal_get_active_module_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_UPDATE_MMI_STATUS_BG_AUDIO,
        is_java_bg_audio,
        display_id,
        jam_mvm_is_minimize_mode(jui_widget_active_display_id),
        (module_id == MOD_J2ME),
        (module_id == MOD_MMI));

    if (module_id == MOD_MMI)
    {
        mmi_java_ui_common_update_status_icon_req_struct req_struct;
        msg = &req_struct;
        msg->is_display_icon = is_java_bg_audio;
        msg->vm_id = display_id;
        msg->is_reset = KAL_FALSE;
        mmi_java_ui_common_update_mmi_status_audio_icon(msg);
        msg = NULL;
    }
    else
    {
        msg =
            (mmi_java_ui_common_update_status_icon_req_struct*) construct_local_para(
                                                    sizeof(mmi_java_ui_common_update_status_icon_req_struct),
                                                    TD_CTRL);
        msg->is_display_icon = is_java_bg_audio;
        msg->vm_id = display_id;
        msg->is_reset = KAL_FALSE;
        
        java_send_msg(module_id,MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_UI_MMI_STATUS_ICON_UPDATE_RSP,msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_update_vm_bg_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_update_vm_bg_status_icon(kal_bool is_display_icon, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_common_update_status_icon_req_struct * msg;
    module_type module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_UPDATE_MMI_STATUS_BG,
        is_display_icon,
        display_id,
        jam_mvm_is_minimize_mode(display_id),
        (module_id == MOD_J2ME),
        (module_id == MOD_MMI));

    if (module_id == MOD_MMI)
    {
        mmi_java_ui_common_update_status_icon_req_struct req_struct;
        msg = &req_struct;
        msg->is_display_icon= is_display_icon;
        msg->vm_id = display_id;
        mmi_java_ui_common_update_mmi_status_icon(msg);
        msg = NULL;
    }
    else
    {
        msg =
            (mmi_java_ui_common_update_status_icon_req_struct*) construct_local_para(
                                                    sizeof(mmi_java_ui_common_update_status_icon_req_struct),
                                                    TD_CTRL);
        msg->is_display_icon = is_display_icon;
        msg->vm_id = display_id;
        
        java_send_msg(module_id,MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_UI_MMI_STATUS_ICON_UPDATE_REQ,msg);
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_draw_alpha_blending_fullscreen_status_icons
 * DESCRIPTION
 *  this function will draw status icon bar alpha-blending with java layer
 * PARAMETERS
 *  MsgStruct       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_draw_alpha_blending_fullscreen_status_icons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  x = 0;
    gdi_handle org_alpha_blending_layer_handle;
    //kal_bool need_to_update = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (jui_icon_layer_x_position <= 0 || !jui_icon_lcd_buffer || (jui_icon_layer_handle == GDI_LAYER_EMPTY_HANDLE))
    {
        return;
    }

    gdi_layer_push_and_set_active(jui_icon_layer_handle);
    gdi_layer_set_position(0, 0);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    org_alpha_blending_layer_handle = gdi_set_alpha_blending_source_layer(jui_layer_handle);

    jui_widget_fullscreen_staus_icons_update_data(&x);

    if (x > 0)
    {
        //// gdi_layer_set_position((jui_ui_device_width - x - JUI_ICON_SPACE) >> 1, 0);
        jui_widget_fullscreen_staus_icons_draw((jui_ui_device_width - x - JUI_ICON_SPACE) >> 1);
        jui_icon_layer_blt_handle = jui_icon_layer_handle;
        jui_icon_layer_x_position = x;
    }
    else
    {
        jui_icon_layer_blt_handle = GDI_LAYER_EMPTY_HANDLE;
        jui_icon_layer_x_position = 0;
    }
    
    gdi_set_alpha_blending_source_layer(org_alpha_blending_layer_handle);
    gdi_layer_pop_and_restore_active();
    
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_fullscreen_staus_icons_update_data
 * DESCRIPTION
 *  this function will check which status should be draw and the position to draw
 * PARAMETERS
 *  MsgStruct       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_fullscreen_staus_icons_update_data(kal_int32 * start_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i =0;
    kal_int32 jui_icon_ID = 0;
    kal_int32 width =0;
    kal_int32 height = 0;
    kal_int32 x = 0;
    kal_uint8 *img_ptr = NULL;
    kal_bool display_icon = KAL_FALSE;
    kal_bool need_to_update = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JUI_SUPPORT_FULLSCREEN_ICON_NUMBER; i++)
    {
        if (jui_widget_full_screen_status_icon_list[i] >= MAX_STATUS_ICONS)
        {
            continue;
        }
        jui_icon_ID = jui_widget_full_screen_status_icon_list[i];
        display_icon = wgui_status_icon_bar_whether_icon_display(jui_icon_ID);
        if(display_icon)
        {
    #if (defined __OPTR_NONE__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)) && (!defined(__COSMOS_MMI_PACKAGE__))
            img_ptr = (kal_uint8*) get_image(jui_widget_full_screen_status_icon_bmp_id[i]);
    #else 
            img_ptr = (kal_uint8*) get_image(wgui_status_icon_bar_get_icon_image_id(jui_icon_ID));
    #endif 
            if (img_ptr != NULL)
            {
                gdi_image_get_dimension(img_ptr, &width, &height);
                ////gdi_image_draw(x, 0, img_ptr);
                x += width + JUI_ICON_SPACE;
                ASSERT(x < jui_ui_device_width);
            }
        }

        if(jui_widget_full_screen_status_icon_status[i] != display_icon)
            need_to_update = KAL_TRUE;

        jui_widget_full_screen_status_icon_status[i] = display_icon;
    }

    * start_position = x;
    return need_to_update;

}



/*****************************************************************************
 * FUNCTION
 *  jui_widget_fullscreen_staus_icons_draw
 * DESCRIPTION
 *  this function will draw the status bar accordint to the position
 * PARAMETERS
 *  MsgStruct       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_fullscreen_staus_icons_draw(kal_int32 start_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i =0;
    kal_int32 jui_icon_ID = 0;
    kal_int32 width =0;
    kal_int32 height = 0;
    kal_int32 x = 0;
    kal_uint8 *img_ptr = NULL;
    kal_bool display_icon = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    x = start_position;
    
    for (i = 0; i < JUI_SUPPORT_FULLSCREEN_ICON_NUMBER; i++)
    {
        if (jui_widget_full_screen_status_icon_list[i] >= MAX_STATUS_ICONS)
        {
            continue;
        }
        jui_icon_ID = jui_widget_full_screen_status_icon_list[i];
        display_icon = wgui_status_icon_bar_whether_icon_display(jui_icon_ID);
        if(display_icon)
        {
    #if (defined __OPTR_NONE__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)) && (!defined(__COSMOS_MMI_PACKAGE__))
            img_ptr = (kal_uint8*) get_image(jui_widget_full_screen_status_icon_bmp_id[i]);
    #else 
            img_ptr = (kal_uint8*) get_image(wgui_status_icon_bar_get_icon_image_id(jui_icon_ID));
    #endif 
            if (img_ptr != NULL)
            {
                gdi_image_get_dimension(img_ptr, &width, &height);
                gdi_image_draw(x, 0, img_ptr);
                x += width + JUI_ICON_SPACE;
                ASSERT(x < jui_ui_device_width);
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_update_fullscreen_status_icons
 * DESCRIPTION
 *  The handler to handle MSG_ID_MMI_JAVA_UPDATE_STATUS_BAR_IND
 *  this function should be invoked in JAM Task
 * PARAMETERS
 *  MsgStruct       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_update_fullscreen_status_icons(void * msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 x = 0;
    kal_int32 width = 0;
    kal_int32 height = 0;
    gdi_handle org_alpha_blending_layer_handle;
    kal_bool need_to_update = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI_DEBUG,
        FUNC_J2ME_JUI_UPDATE_JAVA_STATUS_ICON,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(jui_widget_active_display_id),
        jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id),
        jui_icon_lcd_buffer,
        jui_icon_layer_handle);

    /* JAL_LOCK_MUTEX */
    jui_lcd_mutex_lock();
    if (!jam_is_in_fg_screen(jui_widget_active_display_id))     // TODO: active vm_id
    {
        jui_lcd_mutex_unlock();
        return;
    }

    if (!jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id))
    {
        /* JAL_UNLOCK_MUTEX */
        jui_lcd_mutex_unlock();
        return;
    }

    if (!jui_icon_lcd_buffer || (jui_icon_layer_handle == GDI_LAYER_EMPTY_HANDLE))
    {
        /* JAL_UNLOCK_MUTEX */
        jui_lcd_mutex_unlock();
        return;
    }

    gdi_layer_push_and_set_active(jui_icon_layer_handle);
    gdi_layer_set_position(0, 0);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    org_alpha_blending_layer_handle = gdi_set_alpha_blending_source_layer(jui_icon_layer_handle);

    need_to_update = jui_widget_fullscreen_staus_icons_update_data(&x);

    if (x > 0)
    {
        /////gdi_layer_set_position((jui_ui_device_width - x - JUI_ICON_SPACE) >> 1, 0);
        jui_widget_fullscreen_staus_icons_draw((jui_ui_device_width - x - JUI_ICON_SPACE) >> 1);
        jui_icon_layer_blt_handle = jui_icon_layer_handle;
        jui_icon_layer_x_position = x;
    }
    else
    {
        jui_icon_layer_blt_handle = GDI_LAYER_EMPTY_HANDLE;
        jui_icon_layer_x_position = 0;
    }
    gdi_set_alpha_blending_source_layer(org_alpha_blending_layer_handle);
    gdi_layer_pop_and_restore_active();

    /* JAL_UNLOCK_MUTEX */
    jui_lcd_mutex_unlock();
    kal_trace(
        JVM_TRACE_TYPE_JUI_DEBUG,
        FUNC_J2ME_JUI_UPDATE_JAVA_STATUS_ICON_2,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(jui_widget_active_display_id),
        jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id),
        jui_icon_layer_x_position,
        jui_icon_layer_blt_handle);

    if (need_to_update && jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id))
    {
        if (g_jui_screen_data[jui_widget_active_display_id].current_screen == JUI_SCREEN_TYPE_UNKNOWN)
        {
            gdi_image_get_dimension((U8*) get_image(STATUS_ICON_GPRS_SERVICE), &width, &height);
            jui_widget_mvm_refresh_lcd(0, 0, jui_ui_device_width, height, jui_widget_active_display_id);
        }
        else
        {
            jui_widget_mvm_fire_event_listener_void_void(jui_widget_active_display_id, JUI_EVENT_REPAINT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_update_fullscreen_status_icons_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_update_fullscreen_status_icons_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI_DEBUG,
        FUNC_J2ME_JUI_UPDATE_JAVA_STATUS_ICON_CB,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(jui_widget_active_display_id),
        jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id),
        module_id == MOD_J2ME,
        module_id == MOD_JAM);

    if (!jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id) ||
        !jam_is_in_fg_screen(jui_widget_active_display_id))
    {
        return;
    }

    if (module_id == /*MOD_JAM */ MOD_MMI)
    {
        jui_widget_update_fullscreen_status_icons(NULL);
    }
    else
    {
        java_send_msg(module_id,/*MOD_JAM*/ MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_UI_JAVA_STATUS_ICON_UPDATE_REQ,NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_pixel
 * DESCRIPTION
 *  get pixel data
 * PARAMETERS
 *  rgb         [IN]        
 *  gray        [IN]        
 *  isGray      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_get_pixel(kal_int32 rgb, kal_int32 gray, kal_int32 isGray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return rgb;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_asm_buffer
 * DESCRIPTION
 *  get pixel data
 * PARAMETERS
 *  void
 *  isGray(?)       [IN]
 *  gray(?)         [IN]
 *  rgb(?)          [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 *jui_widget_init_asm_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(JUI_MVM_SUPPORT_VM_NUM == 1);
    g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer =
        (kal_uint16*) applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA, UI_device_width * UI_device_height << 1);

    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_INIT_ASM_BUFFER, JUI_MVM_SUPPORT_VM_NUM, g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer);
    return g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_deinit_asm_buffer
 * DESCRIPTION
 *  get pixel data
 * PARAMETERS
 *  void
 *  isGray       [IN]
 *  gray         [IN]
 *  rgb          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_deinit_asm_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_DENIT_ASM_BUFFER, JUI_MVM_SUPPORT_VM_NUM, g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer);
    ASSERT(JUI_MVM_SUPPORT_VM_NUM == 1);
    if (g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer != NULL)
    {
        applib_mem_ap_free(g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer);
        g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_listeners
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jui_widget_init_listeners()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO)
    jui_widget_mvm_register_event_listener_void_int_bool(
        JUI_EVENT_TITLE_CHANGED,
        jma_video_player_update_is_title_displayed);
    jui_widget_mvm_register_event_listener_void_int(JUI_EVENT_SCREEN_MODE_CHANGED, jma_video_player_reconfig_layer);
#endif /* SUPPORT_MMAPI */ 
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_data
 * DESCRIPTION
 * PARAMETERS
 *  data_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_init_data(kal_int32 data_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    g_jui_screen_data[data_index].default_screen_setting[JUI_SCREEN_MODE_NORMAL] = 6;
#else 
    g_jui_screen_data[data_index].default_screen_setting[JUI_SCREEN_MODE_NORMAL] = 7;
#endif 
    g_jui_screen_data[data_index].default_screen_setting[JUI_SCREEN_MODE_FULL] = 2;

    g_jui_screen_data[data_index].available_screen_setting = 1;

    g_jui_screen_data[data_index].screen_mode = JUI_SCREEN_MODE_END;
    g_jui_screen_data[data_index].old_screen_mode = JUI_SCREEN_MODE_END;

    g_jui_screen_data[data_index].display_id = -1;

    g_jui_screen_data[data_index].ticker_is_shown = KAL_FALSE;
    g_jui_screen_data[data_index].title_is_shown = KAL_FALSE;

    g_jui_screen_data[data_index].current_screen = JUI_SCREEN_TYPE_UNKNOWN;
    g_jui_screen_data[data_index].previous_screen = JUI_SCREEN_TYPE_UNKNOWN;

    g_jui_screen_data[data_index].is_show_logo_screen = KAL_FALSE;

    memset(g_jui_screen_data[data_index].title_buffer, 0, sizeof(g_jui_screen_data[data_index].title_buffer));
    memset(g_jui_screen_data[data_index].softkey_label, 0, JUI_MAX_SOFTKEYS * JUI_SOFTKEY_STR_BUF);
    g_jui_screen_data[data_index].softkey_label_length[0] = 0;
    g_jui_screen_data[data_index].softkey_label_length[1] = 0;

    g_jui_screen_data[data_index].screen_mode_changed_in_fg_mmi = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_datas
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_init_datas(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 data_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (data_index = 0; data_index < JUI_MVM_SUPPORT_VM_NUM; data_index++)
    {
        jui_widget_init_data(data_index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_title_offset
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_init_title_offset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    jui_title_offset = 0;
#else 
    jui_title_offset = MMI_status_bar_height;
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_java_status_icon_buffer
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_init_java_status_icon_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *img_ptr = (U8*) get_image(STATUS_ICON_GPRS_SERVICE);
    kal_int32 width, height;
    //U8 *buf_ptr = NULL;
    //S32 byte_per_pixel = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((img_ptr != NULL) && jam_get_net_icon_setting())    /* create jui_icon_layer_buffer */
    {
        gdi_image_get_dimension(img_ptr, &width, &height);
        jui_icon_layer_buffer_size = (jui_ui_device_width * height) << 1;

#ifndef J2ME_SLIM_MEMORY_SUPPORT
        jui_icon_lcd_buffer = (kal_uint16*) jvm_malloc(jui_icon_layer_buffer_size);
#else
        jui_icon_lcd_buffer =(kal_uint16*) jui_widget_mvm_gditempmemory_allocate(jui_icon_layer_buffer_size);
#endif             
        ASSERT(jui_icon_lcd_buffer != NULL);
        jui_icon_layer_need_clear = KAL_TRUE;

        memset(jui_widget_full_screen_status_icon_status,0x00,JUI_SUPPORT_FULLSCREEN_ICON_NUMBER * sizeof(kal_bool));
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_title_offset
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_deinit_java_status_icon_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jui_icon_lcd_buffer)
    {
#ifndef J2ME_SLIM_MEMORY_SUPPORT
        jvm_free(jui_icon_lcd_buffer);
#endif        
        jui_icon_lcd_buffer = NULL;
        jui_icon_layer_buffer_size = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_register_extra_symbol_callback
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_register_extra_symbol_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_ime_mutex);
    /* For JTWI 5 symbols */
    if (jui_is_set_jtwi_symbol != KAL_TRUE)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        if (!mmi_imc_get_is_java_special_symbol_enabled())
        {
            mmi_imc_set_is_java_special_symbol_enabled(MMI_TRUE);
        }
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        mmi_ime_register_symbol_table_callback(mmi_java_ui_common_add_extra_symbol);
#endif
#else
        mmi_ime_register_symbol_table_callback(mmi_java_ui_common_add_extra_symbol);
#endif
        jui_is_set_jtwi_symbol = KAL_TRUE;
    }
    kal_give_mutex(g_jam_ime_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_deregister_extra_symbol_callback
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_deregister_extra_symbol_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_ime_mutex);
    /* pair with mmi_ime_register_symbol_table_callback */
    if (jui_is_set_jtwi_symbol == KAL_TRUE)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        if (mmi_imc_get_is_java_special_symbol_enabled())
        {
            mmi_imc_set_is_java_special_symbol_enabled(MMI_FALSE);
        }
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        mmi_ime_clear_symbol_table_callback();
#endif
#else
        mmi_ime_clear_symbol_table_callback();
#endif
        jui_is_set_jtwi_symbol = KAL_FALSE;
    }
    kal_give_mutex(g_jam_ime_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_layer
 * DESCRIPTION
 *  init layer data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_init_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(vm_id < 0)
        return -1; // jam engine is not ready
        
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    //jui_ui_device_height = 0;
#else
    jui_ui_device_height = UI_device_height;
#endif
    jui_widget_init_datas();
    jui_widget_init_title_offset();

    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_INIT,
        vm_id,
        jam_is_in_fg_screen(vm_id),
        jui_title_offset,
        jui_layer_handle,
        g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer,
        jui_icon_lcd_buffer,
        jui_icon_layer_handle,
        jui_soft_button_layer_handle,
        jui_status_icon_layer_handle);

    JUI_WIDGET_CHECK_DISPLAY_ID(vm_id);
    
    jui_lcd_mutex_lock();

    if (jam_is_in_fg_screen(vm_id))
    {
#ifdef J2ME_SLIM_MEMORY_SUPPORT
        //kal_prompt_trace(MOD_J2ME,"[heap alloc] before get buffer pool pointer(%x)",jui_lcd_buffer);
        jui_get_gdi_temp_buffer_pool_ptr();/*get GDI MAIN BASE layer buffer pointer*/
#endif
    
        jui_widget_register_extra_symbol_callback();

        jui_lcd_buffer_size = (jui_ui_device_width * UI_device_height) << 1;
        /* added for 128+32 */
    #ifdef J2ME_SLIM_MEMORY_SUPPORT
        /* buffer is alloced during launch */
        ASSERT(g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer != NULL);
    #else /* J2ME_SLIM_MEMORY_SUPPORT */ 
        /* JUI MVM, alloc one lcd_buffer */
        if(jui_lcd_total_buffer == NULL)
            jui_lcd_total_buffer = (kal_uint8 *) jvm_malloc(jui_lcd_buffer_size * JUI_MVM_SUPPORT_VM_NUM);
        ASSERT(jui_lcd_total_buffer != NULL);
        jui_widget_mvm_malloc_lcd_buffer(JUI_WIDGET_DEFAULT_DISPLAY_ID);
    #endif /* J2ME_SLIM_MEMORY_SUPPORT */ 
        /* added for 128+32 end */

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
        jui_vk_lcd_buffer_size = (jui_ui_device_width * JUI_VIRTUAL_KEYPAD_HEIGHT) << 1;
#ifndef __JUI_VK_SLIM__
        // do not get VK buffer when init layer
        if (jui_vk_lcd_buffer == NULL)
        {
			jui_widget_mvm_allocate_vk_buffer();
        }
#endif
       
#endif

#ifndef J2ME_SLIM_MEMORY_SUPPORT

        jui_widget_init_java_status_icon_buffer();

#endif

#ifdef SUPPORT_CACHED_FONT_ALWAYS
        jui_init_cached_font();
#endif /* SUPPORT_CACHED_FONT_ALWAYS */


        jui_widget_init_listeners();

        jui_widget_is_layer_initialized = KAL_TRUE;

        jui_lcd_mutex_unlock();

        kal_trace(
            JVM_TRACE_TYPE_JUI,
            FUNC_J2ME_JUI_INIT_2,
            vm_id,
            jui_layer_handle,
            jui_lcd_buffer_size,
            g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer,
            jui_lcd_buffer_double,
            jui_icon_lcd_buffer,
            jui_icon_layer_handle,
            0,
            jui_icon_layer_buffer_size);
        return 0;
    }
    else
    {
        jui_lcd_mutex_unlock();
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_init_layer_ext
 * DESCRIPTION
 *  init layer data ext
 * PARAMETERS
 *  jui_init_layer_trial_cb     [IN]        This function is triggered each time while init layer is failed this function should return -1 if we do not want to continue trial
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_init_layer_ext(kal_int32(*jui_init_layer_trial_cb) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VM should not progress until layer is initialized */
    while (jui_widget_init_layer() == -1)
    {
        kal_sleep_task(50);
        if (jui_init_layer_trial_cb() < 0)
        {
            ret = -1;
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_deinit_layer
 * DESCRIPTION
 *  deinit layer data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_deinit_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int16 vm_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_DEINIT,
        jui_layer_handle,
        jui_lcd_total_buffer,
        jui_lcd_buffer_double,
        jui_icon_lcd_buffer,
        jui_icon_layer_handle,
        jui_soft_button_layer_handle,
        jui_status_icon_layer_handle);

#ifdef J2ME_SLIM_MEMORY_SUPPORT
  #ifdef __JUI_SLIM_SAVE_LAYER__
        jui_widget_layer_delete_backup();
  #endif
        jui_widget_is_saved_layer = KAL_FALSE;
#endif

    for(vm_index = 0 ; vm_index < JUI_MVM_SUPPORT_VM_NUM ; vm_index ++)
    {
        if(g_jui_screen_data[vm_index].lcd_buffer != NULL)
        {
            jui_widget_mvm_release_lcd_buffer(vm_index,g_jui_screen_data[vm_index].lcd_buffer);
        }
    }
    if(jui_lcd_total_buffer != NULL)
    {
        jvm_free(jui_lcd_total_buffer);
        jui_lcd_total_buffer = NULL;
    }

    if (jui_lcd_buffer_double != NULL)
    {
        /* MAUI_02742320 */ /* lcd buffer double MUST be free in unregister lcd */
        jvm_trace_warning("[JUI]deinit_layer,jui_lcd_buffer_double=%d",jui_lcd_buffer_double);
        ////mmi_frm_scrmem_free((void*)jui_lcd_buffer_double);
        ////jui_lcd_buffer_double = NULL;
    }

#ifdef SUPPORT_CACHED_FONT_ALWAYS
    jui_deinit_cached_font();
#endif /* #ifdef SUPPORT_CACHED_FONT_ALWAYS */


#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
#ifndef __JUI_VK_SLIM__
    if (jui_vk_lcd_buffer != NULL)
    {
        jui_widget_mvm_free_vk_buffer();
    }
#endif
#endif

#ifndef J2ME_SLIM_MEMORY_SUPPORT
    jui_widget_deinit_java_status_icon_buffer();
#endif

    jui_widget_deregister_extra_symbol_callback();
	
    jui_widget_config_blt_layer();

    /* unregister listeners */
    jui_widget_unregister_event_listener_void_void();
    jui_widget_unregister_event_listener_void_int();
    jui_widget_unregister_event_listener_void_bool();
    jui_widget_mvm_unregister_event_listener_void_int();
    jui_widget_mvm_unregister_event_listener_void_int_int();
    jui_widget_mvm_unregister_event_listener_void_int_bool();

    jui_widget_is_layer_initialized = KAL_FALSE;

}

#if ((!defined(MT6223P)) && (!defined(MT6223C)) && (!defined(MT6223D)) && (!defined(MT6223)))


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_register_lcd
 * DESCRIPTION
 *  create layer in gdi
 * PARAMETERS
 *  refresh_screen      [IN]        
 *  display_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_register_lcd(kal_bool refresh_screen, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buf_ptr = NULL;
    S32 byte_per_pixel = 0;
    kal_uint32 *invalidPtr;

    kal_uint16 *lcd_buffer;
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    kal_int32 ret = J2ME_NO_ERROR;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_REGISTER_LCD,
        display_id,
        jam_is_in_fg_screen(display_id),
        jui_layer_handle,
        g_jui_screen_data[display_id].lcd_buffer,
        jui_icon_lcd_buffer,
        jui_icon_layer_handle,
        jui_soft_button_layer_handle,
        jui_status_icon_layer_handle,
        jui_widget_obj_show_status(JUI_OBJ_STATUS_BAR, display_id),
        refresh_screen);
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    /* JAL_LOCK_MUTEX */
    jui_lcd_mutex_lock();
    if (!jam_is_in_fg_screen(display_id) || jui_widget_register_lcd_done || !jui_widget_is_layer_initialized)
    {
        jui_lcd_mutex_unlock();
        return;
    }

    jui_widget_register_extra_symbol_callback();

#ifdef __MMI_SCREEN_SWITCH_EFFECT__       
    gui_screen_switch_effect_block(MMI_TRUE);                                             
#endif

#ifdef J2ME_SLIM_MEMORY_SUPPORT
        // kal_prompt_trace(MOD_J2ME,"[heap alloc] before get buffer pool pointer(%x)",jui_lcd_buffer);
        jui_get_gdi_temp_buffer_pool_ptr();/*get GDI MAIN BASE layer buffer pointer*/
#ifdef __JUI_SLIM_SAVE_LAYER__
        ret = jui_widget_layer_restore((kal_int8*)jui_lcd_buffer,jui_lcd_buffer_size);
#endif        
        jui_widget_mvm_gditempmemory_init();

#endif


    jui_widget_active_display_id = display_id;

    lcd_buffer = g_jui_screen_data[display_id].lcd_buffer;

    wgui_status_icon_bar_register_update_callback(jui_widget_update_fullscreen_status_icons_cb);

    if (lcd_buffer && (jui_layer_handle == GDI_LAYER_EMPTY_HANDLE))
    {
#ifndef J2ME_SLIM_MEMORY_SUPPORT
        /* check if jui_lcd_buffer_double is allocated */
        if (jui_lcd_buffer_double == NULL)
        {
            jui_lcd_buffer_double = (kal_uint16*) mmi_frm_scrmem_alloc_framebuffer(jui_lcd_buffer_size);
            ASSERT(jui_lcd_buffer_double);
            memcpy(jui_lcd_buffer_double, lcd_buffer, jui_lcd_buffer_size);
        }
        /* second buffer can be freed when Java is paused */
        gdi_layer_create_using_outside_memory
            (0,
             0,
             jui_ui_device_width, UI_device_height, &jui_blt_handle,
             (kal_uint8*) jui_lcd_buffer_double, jui_lcd_buffer_size);
#endif
        invalidPtr = (kal_uint32*) lcd_buffer;
#if  !defined (J2ME_SLIM_MEMORY_SUPPORT) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
        invalidPtr = jvm_l1_cache_invalidate_and_clean_region(lcd_buffer, jui_lcd_buffer_size, KAL_FALSE, KAL_FALSE, 0);
 #endif   
 
#ifndef  J2ME_SLIM_MEMORY_SUPPORT
        gdi_layer_create_cf_double_using_outside_memory
            (GDI_LCD->cf,
             0,
             0,
             jui_ui_device_width, UI_device_height, &jui_layer_handle,
             (kal_uint8*) invalidPtr, jui_lcd_buffer_size, (kal_uint8*) jui_lcd_buffer_double, jui_lcd_buffer_size);
#else   /* J2ME_SLIM_MEMORY_SUPPORT */
        gdi_layer_create_cf_using_outside_memory
            (
             GDI_LCD->cf,
             0,
             0,
             jui_ui_device_width, UI_device_height, &jui_layer_handle,
             (kal_uint8*) invalidPtr, jui_lcd_buffer_size);
        
#endif /* J2ME_SLIM_MEMORY_SUPPORT */
        jui_widget_layer_set_position(jui_layer_handle);

        gdi_layer_set_active(jui_layer_handle);
        gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);

    }

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__

#ifdef __JUI_VK_SLIM__
    jui_widget_mvm_get_vk_buffer((kal_uint8 *)invalidPtr);
#endif

    if (jui_vk_lcd_buffer && jui_vk_layer_handle == GDI_LAYER_EMPTY_HANDLE
#ifdef __JUI_VK_SLIM__
            && jam_mvm_is_vm_vk_on(display_id)
#endif
       )
    {
    #if 0
/* under construction !*/
    #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__DYNAMIC_SWITCH_CACHEABILITY__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#else
		    gdi_layer_create_using_outside_memory(
            0,
            UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT,
            jui_ui_device_width,
            JUI_VIRTUAL_KEYPAD_HEIGHT,
            &jui_vk_layer_handle,
            (U8*) jui_vk_lcd_buffer,
            jui_vk_lcd_buffer_size);
		#endif
    }
#endif

    /* create connection icon layer */
#ifdef J2ME_SLIM_MEMORY_SUPPORT

            jui_widget_init_java_status_icon_buffer();
    
#endif
    if (jui_icon_lcd_buffer && (jui_icon_layer_handle == GDI_LAYER_EMPTY_HANDLE))
    {
        U8 *img_ptr = (U8*) get_image(STATUS_ICON_GPRS_SERVICE);
        S32 width, height;

        if (img_ptr != NULL && jam_get_net_icon_setting())
        {
            gdi_image_get_dimension(img_ptr, &width, &height);
            invalidPtr = (kal_uint32*) jui_icon_lcd_buffer;
        #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined (J2ME_SLIM_MEMORY_SUPPORT)
            invalidPtr = jvm_l1_cache_invalidate_and_clean_region(
                            jui_icon_lcd_buffer,
                            jui_icon_layer_buffer_size,
                            KAL_TRUE,
                            KAL_TRUE,
                            0);
        #endif /* defined(__DYNAMIC_SWITCH_CACHEABILITY__) */ 
            gdi_layer_create_using_outside_memory(
                0,
                0,
                jui_ui_device_width,
                height,
                &jui_icon_layer_handle,
                (U8*) invalidPtr,
                jui_icon_layer_buffer_size);
            gdi_layer_push_and_set_active(jui_icon_layer_handle);
            gdi_layer_set_opacity(TRUE, 150);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            if (jui_icon_layer_need_clear)
            {
                gdi_layer_clear(GDI_COLOR_TRANSPARENT);
                jui_icon_layer_need_clear = KAL_FALSE;
            }
            else
            {
                if (jui_icon_layer_x_position > 0)
                {
                    gdi_layer_set_position((jui_ui_device_width - jui_icon_layer_x_position - JUI_ICON_SPACE) >> 1, 0);
                    jui_icon_layer_blt_handle = jui_icon_layer_handle;
                }
            }
            gdi_layer_pop_and_restore_active();
        }
        else
        {
            jui_icon_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        }
    }

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    /* 
     * We still draw status icons and softkeys on mmi base layer.
     * Instead of using mmi base layer in gdi_layer_blt, two layers
     * are created using the mmi base layer buffer.
     * The purpose is to reduce the overlap region with jui_layer_buffer
     */
    if (jui_soft_button_layer_handle == GDI_LAYER_EMPTY_HANDLE ||
        jui_status_icon_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_get_buffer_ptr(&buf_ptr);
        byte_per_pixel = (gdi_layer_get_bit_per_pixel() >> 3);
        if (jui_soft_button_layer_handle == GDI_LAYER_EMPTY_HANDLE)
        {
            /* 030607 24 bit Start */
#ifndef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
            gdi_layer_create_cf_using_outside_memory(
                __MMI_MAIN_BASE_LAYER_FORMAT__,
                0,
                UI_device_height - MMI_softkey_height,
                jui_ui_device_width,
                MMI_softkey_height,
                &jui_soft_button_layer_handle,
                buf_ptr + (jui_ui_device_width * (UI_device_height - MMI_softkey_height) * byte_per_pixel),
                jui_ui_device_width * MMI_softkey_height * byte_per_pixel);
#else
            if(jam_mvm_is_vm_vk_on(display_id))
            {
            gdi_layer_create_cf_using_outside_memory(
                __MMI_MAIN_BASE_LAYER_FORMAT__,
                0,
                UI_device_height - MMI_softkey_height - JUI_VIRTUAL_KEYPAD_HEIGHT,
                jui_ui_device_width,
                MMI_softkey_height + JUI_VIRTUAL_KEYPAD_HEIGHT,
                &jui_soft_button_layer_handle,
                buf_ptr + (jui_ui_device_width * (UI_device_height - MMI_softkey_height - JUI_VIRTUAL_KEYPAD_HEIGHT) * byte_per_pixel),
                jui_ui_device_width * (MMI_softkey_height + JUI_VIRTUAL_KEYPAD_HEIGHT) * byte_per_pixel);
            }
            else
            {
                    gdi_layer_create_cf_using_outside_memory(
                        __MMI_MAIN_BASE_LAYER_FORMAT__,
                        0,
                        UI_device_height - MMI_softkey_height,
                        jui_ui_device_width,
                        MMI_softkey_height,
                        &jui_soft_button_layer_handle,
                        buf_ptr + (jui_ui_device_width * (UI_device_height - MMI_softkey_height) * byte_per_pixel),
                        jui_ui_device_width * MMI_softkey_height * byte_per_pixel);
            }
#endif
            gdi_layer_push_and_set_active(jui_soft_button_layer_handle);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
        }
        if (jui_status_icon_layer_handle == GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_create_cf_using_outside_memory(
                __MMI_MAIN_BASE_LAYER_FORMAT__,
                0,
                0,
                jui_ui_device_width,
                MMI_title_height + jui_title_offset,
                &jui_status_icon_layer_handle,
                buf_ptr,
                jui_ui_device_width * (MMI_title_height + jui_title_offset) * byte_per_pixel);
            gdi_layer_push_and_set_active(jui_status_icon_layer_handle);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
        }
    }
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
#if !defined (J2ME_SLIM_MEMORY_SUPPORT)
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#endif
    wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    wgui_status_icon_bar_enable_integrated(KAL_FALSE);
    wgui_status_icon_bar_register_integrated_redraw(NULL);
#endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 


#ifndef SUPPORT_CACHED_FONT_ALWAYS
    if(!jui_double_buffer_activated)    //video is using screen memory,cached font will not useful
        jui_init_cached_font();
#endif /* SUPPORT_CACHED_FONT_ALWAYS */


#if defined( __MMI_NCENTER_SUPPORT__) && !defined (J2ME_SLIM_MEMORY_SUPPORT)
    jui_widget_start_double_buffer();
#endif

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    jui_vk_init(display_id);
#endif /* __SUPPORT_JAVA_VIRTUAL_KEYPAD__ */

    /* draw the status icons if necessary */
    if (jui_widget_obj_show_status(JUI_OBJ_STATUS_BAR, display_id))
    {
        jui_widget_draw_status_bar0();
    }
    else
    {
        wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
    }

    if (jui_widget_mvm_get_screen_mode(display_id) == JUI_SCREEN_MODE_NORMAL)
    {
        jui_widget_mvm_redraw_softkeybar(display_id);
    }

    /* show_softkey_background(); */

    gdi_layer_pop_and_restore_active();
    gdi_layer_multi_layer_enable();

    jui_widget_update_fullscreen_status_icons_cb();

    jui_widget_register_lcd_done = KAL_TRUE;

    jui_is_unregistered_lcd = KAL_FALSE;

#ifdef J2ME_SLIM_MEMORY_SUPPORT
    if(jui_widget_is_saved_layer)
    {   
    #ifdef __JUI_SLIM_SAVE_LAYER__
        if(ret != J2ME_NO_ERROR)
        {
            jui_widget_show_logo();
            jui_widget_mvm_fire_event_listener_void_void(display_id, JUI_EVENT_REPAINT_ALL);
        }
        //jvm_post_repaint_event();
       // jvm_send_keypad_notify_ind();
        jui_widget_is_saved_layer = KAL_FALSE;
    #else
        jui_widget_show_logo();
        jui_widget_mvm_fire_event_listener_void_void(display_id, JUI_EVENT_REPAINT_ALL);        
        jui_widget_is_saved_layer = KAL_FALSE;
    #endif
    }
#endif    

    if (refresh_screen)
    {
        jui_widget_mvm_refresh_lcd(0, 0, jui_ui_device_width, UI_device_height, display_id);
    }
    /*MAUI_03239144 start*/
    else 
        jui_widget_config_blt_layer();
    /*MAUI_03239144 end, if we do not config blt layer here, wgui status icon might blt previous layers, which is not configed by java*/


    jui_widget_mvm_fire_event_listener_void_void(display_id,JUI_EVENT_LCD_VISIBLE);

    jui_lcd_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_unregister_lcd
 * DESCRIPTION
 *  free layer in gdi
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_unregister_lcd(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_UNREGISTER_LCD,
        display_id,
        jam_is_in_fg_screen(display_id),
        jui_layer_handle,
        g_jui_screen_data[display_id].lcd_buffer,
        jui_icon_lcd_buffer,
        jui_icon_layer_handle,
        jui_soft_button_layer_handle,
        jui_status_icon_layer_handle);

        JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
        jui_is_unregistered_lcd = KAL_TRUE;  

        
            
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    #ifdef __JUI_SLIM_SAVE_LAYER__
        if(jam_mvm_get_vm_state(display_id) == JVM_TERMINATE_STATE||jam_mvm_get_vm_state(display_id) == JVM_TERMINATING_STATE)
        {
            jui_widget_layer_delete_backup();
            jui_widget_is_saved_layer = KAL_FALSE;
        }
        else
        {
            jui_widget_layer_save((kal_int8 *)jui_lcd_buffer, jui_lcd_buffer_size);
            jui_widget_is_saved_layer = KAL_TRUE;
            mmi_frm_clear_key_events();
        }
    #else
        if((jam_mvm_get_vm_state(display_id) != JVM_TERMINATE_STATE)
            && (jam_mvm_get_vm_state(display_id) != JVM_TERMINATING_STATE))
        {
            jui_widget_is_saved_layer = KAL_TRUE;
            mmi_frm_clear_key_events();
        }
    #endif
        while(jui_is_vm_drawing_lcd)
        {
            kal_sleep_task(1);
        }
        jui_free_gdi_temp_buffer_pool_ptr();

        jui_widget_mvm_gditempmemory_deinit();
#endif

    jui_lcd_mutex_lock();

    jui_widget_mvm_reset_base_layer(display_id);

    jui_widget_free_layers();

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    jui_vk_deinit(display_id);
#ifdef __JUI_VK_SLIM__
    jui_widget_mvm_release_vk_buffer();
#endif
#endif

    if (g_jui_screen_data[display_id].buffer_disposed == KAL_TRUE && g_jui_screen_data[display_id].lcd_buffer != NULL)
    {
        /*jvm_free(g_jui_screen_data[display_id].lcd_buffer);*/
        g_jui_screen_data[display_id].lcd_buffer = NULL;
        g_jui_screen_data[display_id].buffer_disposed = KAL_FALSE;
        jui_widget_init_data(display_id);
    }

    jui_widget_register_lcd_done = KAL_FALSE;

#if defined( __MMI_NCENTER_SUPPORT__) && !defined (J2ME_SLIM_MEMORY_SUPPORT)
    jui_double_buffer_activated = KAL_FALSE;
#endif


#ifndef SUPPORT_CACHED_FONT_ALWAYS
    jui_deinit_cached_font();
#endif /* SUPPORT_CACHED_FONT_ALWAYS */


    jui_widget_mvm_fire_event_listener_void_void(display_id,JUI_EVENT_LCD_UNVISIBLE);
    jui_lcd_mutex_unlock();

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_free_layers
 * DESCRIPTION
 *  free all layers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_free_layers()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* JAL_LOCK_MUTEX */
    if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(jui_layer_handle);
    }

    if (jui_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(jui_icon_layer_handle);
        jui_icon_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        jui_icon_layer_blt_handle = GDI_LAYER_EMPTY_HANDLE;
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    jui_widget_deinit_java_status_icon_buffer();
#endif
    }

    if (jui_status_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
        gdi_layer_free(jui_status_icon_layer_handle);
        jui_status_icon_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (jui_soft_button_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(jui_soft_button_layer_handle);
        jui_soft_button_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (jui_blt_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(jui_blt_handle);
        jui_blt_handle = GDI_LAYER_EMPTY_HANDLE;
    }
    if (jui_lcd_buffer_double != NULL)
    {
        mmi_frm_scrmem_free((void*)jui_lcd_buffer_double);
        jui_lcd_buffer_double = NULL;
    }
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if (jui_vk_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(jui_vk_layer_handle);
        jui_vk_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
#endif
    /* JAL_UNLOCK_MUTEX */

    wgui_status_icon_bar_reset_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
    if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_handle base_handle;

        jui_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        gdi_layer_multi_layer_disable();
        leave_full_screen();
        gdi_layer_get_base_handle(&base_handle);
        gdi_layer_set_active(base_handle);
        gdi_layer_reset_clip();
    }

    jui_widget_config_blt_layer();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_config_blt_layer
 * DESCRIPTION
 *  automatically configure the blt layers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_config_blt_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE current_base_layer_handle;
    GDI_HANDLE layer_0;
    GDI_HANDLE layer_1;
    GDI_HANDLE layer_2;
    GDI_HANDLE layer_3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!jam_is_in_fg_screen(jui_widget_active_display_id))
    {
        return;
    }

    if (jui_double_buffer_activated)
    {
        current_base_layer_handle = jui_blt_handle;
        GDI_LOCK;
    }
    else
    {
        current_base_layer_handle = jui_layer_handle;
    }

    if (jui_hardware_layer_blt_index == GDI_LAYER_ENABLE_LAYER_0)
    {
        layer_0 = jui_hardware_layer_handle;
        layer_1 = current_base_layer_handle;
    }
    else
    {
        layer_0 = current_base_layer_handle;
        layer_1 = jui_hardware_layer_handle;
    }
    layer_2 = jui_status_icon_layer_handle;

    if (jui_widget_obj_show_status(JUI_OBJ_BUTTON_BAR, jui_widget_active_display_id))
    {
        layer_3 = jui_soft_button_layer_handle;
    }
    else
    {
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
        if (jam_mvm_is_vm_vk_on(jam_mvm_get_current_vm_id())  && 
            g_jui_screen_data[jui_widget_active_display_id].screen_mode == JUI_SCREEN_MODE_FULL &&
            g_jui_screen_data[jui_widget_active_display_id].is_show_logo_screen == KAL_FALSE)
        {
            layer_3 = jui_vk_layer_handle;
        }
        else
#endif
        {
            layer_3 = GDI_LAYER_EMPTY_HANDLE;
        }
    }

    if (!jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id))
    {
        gdi_layer_set_blt_layer(layer_0, layer_1, layer_2, layer_3);

    }
    else
    {
        gdi_layer_set_blt_layer(layer_0, layer_1, jui_icon_layer_blt_handle, layer_3);

    }
    if (jui_double_buffer_activated)
        GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_refresh_lcd
 * DESCRIPTION
 *  update lcd buffer using given range.
 * PARAMETERS
 *  x1              [IN]        Start of x-coordinate
 *  y1              [IN]        Start of y-coordinate
 *  x2              [IN]        End of x-coordinate
 *  y2              [IN]        End of y-coordinate
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_refresh_lcd(kal_int32 x1, kal_int32 y1, kal_int32 x2, kal_int32 y2, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE current_base_layer_handle;
    GDI_HANDLE layer_0;
    GDI_HANDLE layer_1;
    GDI_HANDLE layer_2;
    GDI_HANDLE layer_3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_EM_MISC_JUI_DEBUG__) */ 

    jui_lcd_mutex_lock();
    if (!jam_is_in_fg_screen(display_id) || !jui_widget_register_lcd_done)
    {
        jui_lcd_mutex_unlock();
        return;
    }

    GDI_LOCK;
    //gdi_lcd_freeze(MMI_TRUE);

    if (g_jui_screen_data[display_id].lcd_buffer)
    {
        gdi_rect_struct rect;

        if (!jui_widget_mvm_is_fullscreen_mode(display_id) && g_jui_screen_data[display_id].screen_mode_changed)        /* screen mode is set to normal, but the blt layer may not be set */
        {
            rect.x1 = 0;
            rect.x2 = jui_ui_device_width - 1;
            rect.y1 = 0;
            rect.y2 = UI_device_height - 1;
            g_jui_screen_data[display_id].screen_mode_changed = KAL_FALSE;
        }
        else
        {
            rect.x1 = x1;
            rect.x2 = x2;
            rect.y1 = y1;
            rect.y2 = y2;
            if (x1 < 0)
            {
                rect.x1 = 0;
            }
            if (y1 < 0)
            {
                rect.y1 = 0;
            }
            if (x2 >= jui_ui_device_width)
            {
                rect.x2 = jui_ui_device_width - 1;
            }
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
            if(jam_mvm_is_vm_vk_on(display_id))
            {
                if (!jui_widget_mvm_is_fullscreen_mode(display_id) && y2 >= (UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT  - jui_ui_button_height - 1))
                {
                    if (x2 < jui_ui_device_width - 1)
                    {
                        rect.y2 = UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT  - jui_ui_button_height - 1;
                    }
#ifdef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT
                    else
                    {
                        rect.y2 = UI_device_height - 1;
                    }
#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */
                }
                else if (jui_widget_mvm_is_fullscreen_mode(display_id) && y2 >= UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT  - 1)
                {
                    if (x2 < jui_ui_device_width - 1)
                    {
                        rect.y2 = UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT  - 1;
                    }
                    else
                    {
                        rect.y2 = UI_device_height - 1;
                    }
                }
            }
	   else
           {
                if (y2 >= UI_device_height)
                {
                    rect.y2 = UI_device_height - 1;
                }
           }
#else
            if (y2 >= UI_device_height)
            {
                rect.y2 = UI_device_height - 1;
            }
#endif
        }

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if(jam_mvm_is_vm_vk_on(display_id))
    {
        if (!jui_widget_mvm_is_fullscreen_mode(display_id) && rect.y2 < (UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT - MMI_button_bar_height))
        {
            if (rect.y2 + MMI_softkey_height < UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT - MMI_button_bar_height)
            {
                rect.y2 += MMI_softkey_height;
            }
            else
            {
                rect.y2 += UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT - MMI_button_bar_height - 1;
            }
        }
    }
    else
    {
	if (!jui_widget_mvm_is_fullscreen_mode(display_id)) /* this code can be insert into the pre segement */
        {
            rect.y2 += MMI_softkey_height;
        }
    }
#else
        if (!jui_widget_mvm_is_fullscreen_mode(display_id)) /* this code can be insert into the pre segement */
        {
            rect.y2 += MMI_softkey_height;
        }
#endif

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined (J2ME_SLIM_MEMORY_SUPPORT)
        jvm_l1_cache_invalidate_and_clean_region(
            g_jui_screen_data[display_id].lcd_buffer,
            jui_lcd_buffer_size,
            KAL_TRUE,
            KAL_TRUE,
            0);
#endif /* defined(__DYNAMIC_SWITCH_CACHEABILITY__) */ 

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if(jam_mvm_is_vm_vk_on(display_id)){

#ifndef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT
        if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE &&
            g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_NORMAL &&
            g_jui_screen_data[display_id].is_show_logo_screen == KAL_FALSE)
        {
            if (rect.y1 <= (UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT - jui_ui_button_height) 
                    && rect.y2 >= (UI_device_height - jui_ui_button_height - 1)
                )
            {
                if (jui_widget_obj_show_status(JUI_OBJ_STATUS_BAR, display_id))
                {
                    gdi_layer_push_and_set_active(jui_soft_button_layer_handle);
                    gdi_bitblt_resized(
                        jui_vk_layer_handle,
                        0,
                        0,
                        jui_ui_device_width - 1,
                        JUI_VIRTUAL_KEYPAD_HEIGHT - 1,
                        0,
                        0,
                        jui_ui_device_width - 1,
                        JUI_VIRTUAL_KEYPAD_HEIGHT - 1);
                    gdi_layer_pop_and_restore_active();
                }
                else
                {
                    gdi_layer_push_and_set_active(jui_layer_handle);
                    gdi_bitblt_resized(
                        jui_vk_layer_handle,
                        0,
                        0,
                        jui_ui_device_width - 1,
                        JUI_VIRTUAL_KEYPAD_HEIGHT - 1,
                        0,
                        UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT - jui_ui_button_height - jui_title_offset,
                        jui_ui_device_width - 1,
                        UI_device_height - jui_ui_button_height - jui_title_offset  - 1);
                    gdi_layer_pop_and_restore_active();
                }
            }
        }
        /*else if (g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_FULL &&
                 g_jui_screen_data[display_id].is_show_logo_screen == KAL_FALSE)
        {
            if (rect.y1 <= jui_ui_device_height && rect.y2 >= jui_ui_device_height + JUI_VIRTUAL_KEYPAD_HEIGHT - 1)
            {
                gdi_layer_push_and_set_active(jui_layer_handle);
                gdi_bitblt_resized(
                    jui_vk_layer_handle,
                    0,
                    0,
                    jui_ui_device_width - 1,
                    JUI_VIRTUAL_KEYPAD_HEIGHT - 1,
                    0,
                    jui_ui_device_height,
                    jui_ui_device_width - 1,
                    jui_ui_device_height + JUI_VIRTUAL_KEYPAD_HEIGHT -1);
                gdi_layer_pop_and_restore_active();
            }
        }*/
#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */
}
#endif

        if (jui_double_buffer_activated  ||(g_jui_resume_first_screen && jui_blt_handle))
        {
            //GDI_LOCK;
            gdi_layer_push_and_set_active(jui_layer_handle);
            gdi_layer_toggle_double();
            gdi_layer_copy_double();
            jui_widget_layer_set_position(jui_blt_handle);
            current_base_layer_handle = jui_blt_handle;
        }
        else
        {
            current_base_layer_handle = jui_layer_handle;
        }

        if (jui_hardware_layer_blt_index == GDI_LAYER_ENABLE_LAYER_0)
        {
            layer_0 = jui_hardware_layer_handle;
            layer_1 = current_base_layer_handle;
        }
        else
        {
            layer_0 = current_base_layer_handle;
            layer_1 = jui_hardware_layer_handle;
        }
        layer_2 = jui_status_icon_layer_handle;

        if (jui_widget_obj_show_status(JUI_OBJ_BUTTON_BAR, display_id))
        {
            layer_3 = jui_soft_button_layer_handle;
        }
        else
        {
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
            if (jam_mvm_is_vm_vk_on(jam_mvm_get_current_vm_id())  && 
                g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_FULL &&
                g_jui_screen_data[display_id].is_show_logo_screen == KAL_FALSE)
            {
                layer_3 = jui_vk_layer_handle;
            }
            else
#endif
            {
                layer_3 = GDI_LAYER_EMPTY_HANDLE;
            }
        }

        if (!jui_widget_mvm_is_fullscreen_mode(display_id))
        {

            if (jui_set_blt_status_icon == KAL_TRUE)
            {   /* someone change screen mode, need to update status icon bar region */
                gdi_layer_blt(layer_0, layer_1, layer_2, layer_3, rect.x1, rect.y1, rect.x2, rect.y2);

                jui_set_blt_status_icon = KAL_FALSE;
            }
            else
            {
                if (jui_widget_obj_show_status(JUI_OBJ_STATUS_BAR, display_id) && (rect.y1 <= jui_widget_get_status_bar_height())) /* 021407 blt region */
                {
                    gdi_layer_blt(
                        layer_0,
                        layer_1,
                        layer_2,
                        layer_3,
                        rect.x1,
                        rect.y1 + MMI_status_bar_height,
                        rect.x2,
                        rect.y2);
                }
                else
                {
                    gdi_layer_blt(layer_0, layer_1, layer_2, layer_3, rect.x1, rect.y1, rect.x2, rect.y2);
                }

            }
        }
        else
        {
            if(rect.y1 <= jui_widget_get_status_bar_height())
            {
                if( jui_hardware_layer_handle == NULL || jui_hardware_layer_blt_index == GDI_LAYER_ENABLE_LAYER_0)
                {
                    jui_widget_draw_alpha_blending_fullscreen_status_icons();
                }
            }
            gdi_layer_blt(layer_0, layer_1, jui_icon_layer_blt_handle, layer_3, rect.x1, rect.y1, rect.x2, rect.y2);
        }
        if (jui_double_buffer_activated  ||(g_jui_resume_first_screen && jui_blt_handle))
        {
            if(g_jui_resume_first_screen)
            {
                g_jui_resume_first_screen = KAL_FALSE;
            }
            gdi_layer_toggle_double();
            gdi_layer_pop_and_restore_active();
            //GDI_UNLOCK;
        }

    }

    GDI_UNLOCK;
    jui_lcd_mutex_unlock();

}

#endif /* ((!defined(MT6223P)) && (!defined(MT6223C)) && (!defined(MT6223D))) */ 


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_refresh_screen
 * DESCRIPTION
 *  update screen using given range.
 * PARAMETERS
 *  x1              [IN]        Start of x-coordinate
 *  y1              [IN]        Start of y-coordinate
 *  x2              [IN]        End of x-coordinate
 *  y2              [IN]        End of y-coordinate
 *  display_id      [IN]        
 *  vm_id           [IN]        Which vm to refresh
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_refresh_screen(kal_int32 x1, kal_int32 y1, kal_int32 x2, kal_int32 y2, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reject invalid case */
    if (x1 > x2)
    {
        kal_int32 t = x1;

        x1 = x2;
        x2 = t;
    }

    if (y1 > y2)
    {
        kal_int32 t = y1;

        y1 = y2;
        y2 = t;
    }

    if ((x1 >= LCD_WIDTH) || (y1 >= LCD_HEIGHT))
    {
        return;
    }
    if ((x2 < 0) || (y2 < 0))
    {
        return;
    }

    if (!jui_widget_register_lcd_done)
        return;

    jui_lcd_mutex_lock();
    if (!jam_is_in_fg_screen(display_id))
    {
        jui_lcd_mutex_unlock();
        return;
    }

    if (x1 < 0)
    {
        x1 = 0;
    }
    if (y1 < 0)
    {
        y1 = 0;
    }
    if (x2 >= LCD_WIDTH)
    {
        x2 = LCD_WIDTH - 1;
    }
    if (y2 >= LCD_HEIGHT)
    {
        y2 = LCD_HEIGHT - 1;
    }

    /* to enter cs will degrade performance, however, to avoid gdi mutex assert */

    jui_widget_mvm_refresh_lcd(x1, y1, x2, y2, display_id);

    jui_lcd_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_show_logo_screen
 * DESCRIPTION
 *  show java logo screen
 * PARAMETERS
 *  x1              [IN]        Start of x-coordinate
 *  y1              [IN]        Start of y-coordinate
 *  x2              [IN]        End of x-coordinate
 *  y2              [IN]        End of y-coordinate
 *  display_id      [IN]        
 *  vm_id           [IN]        Which vm to refresh
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_show_logo_screen(kal_int32 x1, kal_int32 y1, kal_int32 x2, kal_int32 y2, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jui_screen_data[display_id].is_show_logo_screen = KAL_TRUE;
    jui_widget_mvm_refresh_screen(x1, y1, x2, y2, display_id);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_clear_screen
 * DESCRIPTION
 *  clear screen
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_clear_screen(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    if (g_jui_screen_data[display_id].lcd_buffer != NULL)
    {
        #ifdef __JUI_VK_SLIM__
        if(jam_mvm_is_vm_vk_on(display_id))
            memset(g_jui_screen_data[display_id].lcd_buffer, 
            0xff, (jui_lcd_buffer_size -((jui_ui_device_width * JUI_VIRTUAL_KEYPAD_HEIGHT)<< 1)));
        else
        #endif
        memset(g_jui_screen_data[display_id].lcd_buffer, 0xff, jui_lcd_buffer_size);
    }

    jui_lcd_mutex_lock();
    if (!jam_is_in_fg_screen(display_id))
    {
        jui_lcd_mutex_unlock();
        return;
    }

    if (jui_status_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(jui_status_icon_layer_handle);
        gdi_draw_solid_rect(
            0,
            jui_title_offset,
            jui_ui_device_width - 1,
            jui_title_offset + MMI_title_height - 1,
            GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    jui_lcd_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_active_lcd_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_uint16 *jui_widget_get_active_lcd_buffer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jui_widget_mvm_get_lcd_buffer(jui_widget_active_display_id);
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_get_lcd_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/

extern kal_uint16 *jui_widget_mvm_get_lcd_buffer(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (display_id < 0)
        return g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer;
    return g_jui_screen_data[display_id].lcd_buffer;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_set_ticker_height
 * DESCRIPTION
 *  Set ticker visible
 * PARAMETERS
 *  visible         [IN]        Display ticker or not
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_set_ticker_height(kal_int32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_ui_ticker_height = height;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_set_ticker_visible
 * DESCRIPTION
 *  Set ticker visible
 * PARAMETERS
 *  visible         [IN]        Display ticker or not
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_set_ticker_visible(kal_bool visible, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_SET_TICKER_VISIBLE,display_id,visible);
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    
    if (g_jui_screen_data[display_id].ticker_is_shown == visible)
        return;
    g_jui_screen_data[display_id].ticker_is_shown = visible;

    jui_widget_mvm_fire_event_listener_void_bool(display_id, JUI_EVENT_TICKER_CHANGED, visible);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_set_title
 * DESCRIPTION
 *  Set title
 * PARAMETERS
 *  title               [IN]        Title string buffer
 *  title_length        [IN]        Title string buffer length
 *  display_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_set_title(kal_uint16 *title, kal_int32 title_length, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_SET_TITLE,
        display_id,
        jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, display_id),
        g_jui_screen_data[display_id].title_is_shown,
        (g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_FULL),
        title);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    if (title == NULL)
    {
        jui_widget_override_mode_setting(JUI_OBJ_TITLE_BAR, KAL_FALSE, display_id);
        title_length = 0;

    #if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
        if (jam_is_in_fg_screen(display_id))
        {
            wgui_status_icon_bar_enable_integrated(KAL_FALSE);
            wgui_status_icon_bar_register_integrated_redraw(NULL);
        }
    #endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
    }
    else
    {
        jui_widget_override_mode_setting(JUI_OBJ_TITLE_BAR, KAL_TRUE, display_id);
    }

    if (title_length > JUI_MAX_TITLE_LENGTH)
    {
        title_length = JUI_MAX_TITLE_LENGTH;
    }

    for (index = 0; index < title_length; index++)
    {
        if (title[index] == '\n')
            break;
        g_jui_screen_data[display_id].title_buffer[index] = title[index];
    }

    title_length = index;
    g_jui_screen_data[display_id].title_buffer[title_length] = 0;
}

#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)


/*****************************************************************************
 * FUNCTION
 *  jui_widget_title_oem_show_normal_ex
 * DESCRIPTION
 *  Show title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jui_widget_title_oem_show_normal_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!jam_is_in_fg_screen(jui_widget_active_display_id) ||
        jui_widget_mvm_is_fullscreen_mode(jui_widget_active_display_id) ||
        !jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, jui_widget_active_display_id))
    {
        return;
    }

    gdi_layer_lock_frame_buffer();

    if ((jui_status_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE) &&
        (jui_hardware_layer_handle != GDI_LAYER_EMPTY_HANDLE))
    {
        gdi_layer_push_and_set_active(jui_status_icon_layer_handle);
    }
    gui_title_oem_show_normal_ex();
    if ((jui_status_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE) &&
        (jui_hardware_layer_handle != GDI_LAYER_EMPTY_HANDLE))
    {
        gdi_layer_pop_and_restore_active();
    }

    wgui_status_icon_bar_register_integrated_redraw(jui_widget_title_oem_show_normal_ex);
    gdi_layer_unlock_frame_buffer();
}
#endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_show_title
 * DESCRIPTION
 *  Show title
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_show_title(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle org_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    //gdi_layer_struct *base_layer = (gdi_layer_struct*) jui_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_SHOW_TITLE,
        display_id,
        jam_is_in_fg_screen(display_id),
        jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, display_id),
        g_jui_screen_data[display_id].title_is_shown,
        jui_widget_mvm_is_fullscreen_mode(display_id),
        g_jui_screen_data[display_id].title_buffer);
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    jui_lcd_mutex_lock();
    /* in case of vm is running in the background */
    if (!jam_is_in_fg_screen(display_id) || !jui_widget_register_lcd_done)
    {
        if ((!jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, display_id)) ||
            jui_widget_mvm_is_fullscreen_mode(display_id))
        {
            if (g_jui_screen_data[display_id].title_is_shown)
            {
                g_jui_screen_data[display_id].title_is_shown = KAL_FALSE;

                if (g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
                {
                    jui_widget_mvm_fire_event_listener_void_bool(
                        display_id,
                        JUI_EVENT_TITLE_CHANGED,
                        g_jui_screen_data[display_id].title_is_shown);
                }
            }
        }
        else
        {
            if (!g_jui_screen_data[display_id].title_is_shown)
            {
                g_jui_screen_data[display_id].title_is_shown = KAL_TRUE;
                jui_widget_mvm_fire_event_listener_void_bool(
                    display_id,
                    JUI_EVENT_TITLE_CHANGED,
                    g_jui_screen_data[display_id].title_is_shown);
            }
        }
        jui_lcd_mutex_unlock();
        return;
    }

    if ((!jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, display_id)) || jui_widget_mvm_is_fullscreen_mode(display_id))
    {
        if (g_jui_screen_data[display_id].title_is_shown)
        {
            g_jui_screen_data[display_id].title_is_shown = KAL_FALSE;

        #if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
            wgui_status_icon_bar_enable_integrated(KAL_FALSE);
            wgui_status_icon_bar_register_integrated_redraw(NULL);
        #endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 

            gdi_layer_push_and_set_active(jui_status_icon_layer_handle);
            gdi_draw_solid_rect(
                0,
                jui_title_offset,
                jui_ui_device_width - 1,
                jui_title_offset + MMI_title_height - 1,
                GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();

            if (!jui_widget_mvm_is_fullscreen_mode(display_id))
            {
                jui_widget_mvm_fire_event_listener_void_bool(
                    display_id,
                    JUI_EVENT_TITLE_CHANGED,
                    g_jui_screen_data[display_id].title_is_shown);
            }
        }
        jui_lcd_mutex_unlock();
        return;
    }

    jui_lcd_mutex_unlock();
    /* JAL_LOCK_MUTEX */
    JAL_MVM_LOCK_MUTEX(jui_widget_active_display_id)
#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    if (!wgui_status_icon_bar_whether_integrated_enable())
    {
        wgui_status_icon_bar_enable_integrated(KAL_TRUE);
        wgui_status_icon_bar_register_integrated_redraw(jui_widget_title_oem_show_normal_ex);
    }
#endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 

    #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined (J2ME_SLIM_MEMORY_SUPPORT)
        jvm_l1_cache_invalidate_and_clean_region(
            g_jui_screen_data[display_id].lcd_buffer,
            jui_ui_device_width * MMI_title_height * 2,
            KAL_TRUE,
            KAL_TRUE,
            0);
    #endif /* defined(__DYNAMIC_SWITCH_CACHEABILITY__) */ 

    gdi_layer_lock_frame_buffer();
    org_layer_handle = gdi_set_alpha_blending_source_layer(jui_layer_handle);
    wgui_title_set_alpha_layer(jui_layer_handle);
    ChangeTitleString((U8*) g_jui_screen_data[display_id].title_buffer);
    draw_title();
    gdi_set_alpha_blending_source_layer(org_layer_handle);
    gdi_layer_unlock_frame_buffer();

    if (jui_double_buffer_activated)
    {
        memcpy(
            ((gdi_layer_struct*) jui_blt_handle)->buf_ptr,
            ((gdi_layer_struct*) jui_layer_handle)->buf_ptr,
            jui_ui_device_width * MMI_title_height * 2);
    }

    if (jui_status_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(jui_status_icon_layer_handle);
        if ((jui_hardware_layer_handle == GDI_LAYER_EMPTY_HANDLE))
        {
            gdi_draw_solid_rect(
                0,
                jui_title_offset,
                jui_ui_device_width - 1,
                jui_title_offset + MMI_title_height - 1,
                GDI_COLOR_TRANSPARENT);
        }
        else
        {

            if(jui_double_buffer_activated)
            {
                gdi_bitblt_resized(
                    jui_blt_handle,
                    0,
                    0,
                    jui_ui_device_width - 1,
                    MMI_title_height - 1,
                    0,
                    jui_title_offset,
                    jui_ui_device_width - 1,
                    jui_title_offset + MMI_title_height - 1);
            }
            else
            {
                gdi_bitblt_resized(
                    jui_layer_handle,
                    0,
                    0,
                    jui_ui_device_width - 1,
                    MMI_title_height - 1,
                    0,
                    jui_title_offset,
                    jui_ui_device_width - 1,
                    jui_title_offset + MMI_title_height - 1);
            }
        }
        gdi_layer_pop_and_restore_active();
    }

    //TODO: why we need to do blt now? JVM will blt it auto when set title
    //gdi_layer_blt_previous(0, jui_title_offset, jui_ui_device_width - 1, jui_title_offset + MMI_title_height - 1);
    //JAL_UNLOCK_MUTEX
    JAL_MVM_UNLOCK_MUTEX if (!g_jui_screen_data[display_id].title_is_shown)
    {
        g_jui_screen_data[display_id].title_is_shown = KAL_TRUE;
        jui_widget_mvm_fire_event_listener_void_bool(
            display_id,
            JUI_EVENT_TITLE_CHANGED,
            g_jui_screen_data[display_id].title_is_shown);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_is_title_displayed
 * DESCRIPTION
 *  tell if title exists or not
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_mvm_is_title_displayed(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,
            FUNC_J2ME_JUI_IS_TITLE_DISPLAYED,
            display_id,
            jam_is_in_fg_mmi_screen(display_id),
            jui_widget_mvm_is_fullscreen_mode(display_id),
            g_jui_screen_data[display_id].title_is_shown
        );
    if (jam_is_in_fg_mmi_screen(display_id) && !jui_widget_mvm_is_fullscreen_mode(display_id))
    {
        return KAL_TRUE;
    }
    return g_jui_screen_data[display_id].title_is_shown;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_set_softkey
 * DESCRIPTION
 *  set softkey labels
 * PARAMETERS
 *  index           [IN]        Index of softkeys
 *  label           [IN]        Label of softkeys
 *  numChars        [IN]        Length of softkey labels
 *  isUpdate        [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jui_widget_mvm_set_softkey(
            kal_int32 index,
            const kal_uint16 *label,
            kal_int32 numChars,
            kal_bool isUpdate,
            kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_SET_SOFTKEY,
        display_id,
        jam_is_in_fg_screen(display_id),
        jui_widget_mvm_is_fullscreen_mode(display_id),
        0,
        index,
        label,
        numChars);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    if (label == NULL)
    {
        numChars = 0;
    }

    if (numChars * 2 >= sizeof(g_jui_screen_data[display_id].softkey_label[index]) - 2)
    {
        numChars = (sizeof(g_jui_screen_data[display_id].softkey_label[index]) - 2) / 2;
    }

    if (numChars)
    {
        memcpy(g_jui_screen_data[display_id].softkey_label[index], label, numChars * 2);
        g_jui_screen_data[display_id].softkey_label[index][numChars * 2] = 0;
        g_jui_screen_data[display_id].softkey_label[index][numChars * 2 + 1] = 0;
    }
    else
    {
        g_jui_screen_data[display_id].softkey_label[index][0] = 0;
        g_jui_screen_data[display_id].softkey_label[index][1] = 0;
    }

    g_jui_screen_data[display_id].softkey_label_length[index] = numChars;

    /* hide softkey bar only in full screen */
    if (        /* g_jui_screen_data[display_id].softkey_label[0][0] == 0 &&
                   g_jui_screen_data[display_id].softkey_label[1][0] == 0 */ jui_widget_mvm_is_fullscreen_mode(display_id))
        jui_widget_mvm_set_softkeybar_visible(KAL_FALSE, display_id);
    else
        jui_widget_mvm_set_softkeybar_visible(KAL_TRUE, display_id);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_softkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keycode         [IN]        
 *  keytype         [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_softkey_handler(kal_uint16 keycode, kal_uint16 keytype, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jui_widget_draw_softkey_by_vm)
        return;

    if(display_id == JUI_WIDGET_UNKNOWN_DISPLAY_ID)
        display_id = jui_widget_active_display_id;
        
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    if (!jam_is_in_fg_screen(display_id))       // TODO: vm_id
    {
        return;
    }

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    if (jui_widget_mvm_is_fullscreen_mode(display_id))
    {
        switch (keycode)
        {
            case KEY_LSK:
                if (MMI_softkeys[MMI_LEFT_SOFTKEY].text != NULL && MMI_softkeys[MMI_LEFT_SOFTKEY].text[0] != 0) 
                {
                    update_softkey_state_no_redraw(keycode, keytype);
                }
                break;
            case KEY_RSK:
                if (MMI_softkeys[MMI_RIGHT_SOFTKEY].text != NULL && MMI_softkeys[MMI_LEFT_SOFTKEY].text[0] != 0)
                {
                    update_softkey_state_no_redraw(keycode, keytype);
                }
                break;
            case KEY_CSK:
                break;
         }
    }
    else
    {
        switch (keycode)
        {
            case KEY_LSK:
                if (*((UI_string_type) g_jui_screen_data[display_id].softkey_label[0]) != L'\0')
                {
                    if (keytype == KEY_EVENT_DOWN)
                    {
                        left_softkey_down();
                    }
                    else if (keytype == KEY_EVENT_UP)
                    {
                        left_softkey_up();
                    }
                }
                else
                {
                    if (keytype == KEY_EVENT_DOWN)
                    {
                        MMI_softkeys[MMI_LEFT_SOFTKEY].flags |= UI_BUTTON_STATE_CLICKED;
                        MMI_softkeys[MMI_LEFT_SOFTKEY].flags |= UI_BUTTON_STATE_DOWN;
                    }
                    else if (keytype == KEY_EVENT_UP)
                    {
                        MMI_softkeys[MMI_LEFT_SOFTKEY].flags &= ~UI_BUTTON_STATE_CLICKED;
                        MMI_softkeys[MMI_LEFT_SOFTKEY].flags &= ~UI_BUTTON_STATE_DOWN;
                    }
                }
                break;

            case KEY_RSK:
                if (*((UI_string_type) g_jui_screen_data[display_id].softkey_label[1]) != L'\0')
                {
                    if (keytype == KEY_EVENT_DOWN)
                    {
                        right_softkey_down();
                    }
                    else if (keytype == KEY_EVENT_UP)
                    {
                        right_softkey_up();
                    }
                }
                else
                {
                    if (keytype == KEY_EVENT_DOWN)
                    {
                        MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |= UI_BUTTON_STATE_CLICKED;
                        MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |= UI_BUTTON_STATE_DOWN;
                    }
                    else if (keytype == KEY_EVENT_UP)
                    {
                        MMI_softkeys[MMI_RIGHT_SOFTKEY].flags &= ~UI_BUTTON_STATE_CLICKED;
                        MMI_softkeys[MMI_RIGHT_SOFTKEY].flags &= ~UI_BUTTON_STATE_DOWN;
                    }
                }
                break;

            case KEY_CSK:
                break;
        }
    }

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_set_softkeybar_visible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  visible         [IN]        
 *  display_id      [IN]        
 *  mode            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_set_softkeybar_visible(kal_bool visible, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_SET_SOFTKEY_VISIBLE, display_id,visible);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    jui_widget_override_mode_setting(JUI_OBJ_BUTTON_BAR, visible, display_id);

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_draw_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index               [IN]        
 *  label               [IN]
 *  label_length        [IN]        
 *  display_id          [IN]        
 *  mode             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_draw_softkey(int index, const kal_uint16 *label, kal_int32 label_length, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_DRAW_SOFTKEY,
        display_id,
        jam_is_in_fg_screen(display_id),
        jui_widget_mvm_is_fullscreen_mode(display_id),
        index,
        label,
        label_length);

    jui_widget_mvm_set_softkey(index, label, label_length, KAL_TRUE, display_id);

    if (jui_widget_mvm_is_fullscreen_mode(display_id))
    {
        return;
    }

    jui_lcd_mutex_lock();
    if (!jam_is_in_fg_screen(display_id))       // TODO: vm_id
    {
        jui_lcd_mutex_unlock();
        return;
    }

    if (label == NULL)
    {
        if (index == 0)
        {
            update_softkey_state_no_redraw(KEY_LSK, KEY_EVENT_UP);
        }
        else
        {
            update_softkey_state_no_redraw(KEY_RSK, KEY_EVENT_UP);
        }
    }

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    gdi_layer_lock_frame_buffer();

    if (index == 0)
    {
        ChangeLeftSoftkeyByString((UI_string_type) g_jui_screen_data[display_id].softkey_label[index], 0);
        show_left_softkey();
    }
    else
    {
        ChangeRightSoftkeyByString((UI_string_type) g_jui_screen_data[display_id].softkey_label[index], 0);
        show_right_softkey();
    }
    gdi_layer_unlock_frame_buffer();

    gdi_layer_pop_and_restore_active();

    /* JAL_UNLOCK_MUTEX */
    jui_lcd_mutex_unlock();
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_redraw_softkeybar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_mvm_softkey_is_label_same(kal_int32 index,const kal_uint16 *label,kal_int32 label_length,kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_int32 app_ucs2_wcsncmp(const kal_wchar *str_src, 
                           const kal_wchar *str_dst, 
                           kal_uint32 count);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    if(label == NULL)
        return KAL_FALSE;
    
    if( (label_length == g_jui_screen_data[display_id].softkey_label_length[index])
        && app_ucs2_wcsncmp((kal_wchar*)label,(kal_wchar*)(g_jui_screen_data[display_id].softkey_label[index]),label_length)==0)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
    
}
/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_redraw_softkeybar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_redraw_softkeybar(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_REDRAW_SOFTKEY,
        display_id,
        jam_is_in_fg_screen(display_id),
        jui_widget_mvm_is_fullscreen_mode(display_id));

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    if (jui_widget_mvm_is_fullscreen_mode(display_id))  /* don't display softkey when in fullscreen */
        return;

    jui_lcd_mutex_lock();
    if (!jam_is_in_fg_screen(display_id))       // TODO: vm_id
    {
        jui_lcd_mutex_unlock();
        return;
    }

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    gdi_layer_lock_frame_buffer();

    show_softkey_background();

    ChangeLeftSoftkeyByString((UI_string_type) g_jui_screen_data[display_id].softkey_label[0], 0);
    show_left_softkey();

    ChangeRightSoftkeyByString((UI_string_type) g_jui_screen_data[display_id].softkey_label[1], 0);
    show_right_softkey();

    gdi_layer_unlock_frame_buffer();

    gdi_layer_pop_and_restore_active();

    /* JAL_UNLOCK_MUTEX */
    jui_lcd_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_set_screen_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode            [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_set_screen_mode(jui_screen_mode_enum mode, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_SET_SCREEN_MODE,
        display_id,
        jam_is_in_fg_screen(display_id),
        g_jui_screen_data[display_id].screen_mode,
        mode);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    if (g_jui_screen_data[display_id].screen_mode == (kal_int32) mode)
    {
        return;
    }

    g_jui_screen_data[display_id].old_screen_mode = g_jui_screen_data[display_id].screen_mode;
    g_jui_screen_data[display_id].screen_mode = mode;
    g_jui_screen_data[display_id].screen_mode_changed = KAL_TRUE;

    //redraw the softkey when screen mode changed
    g_jui_screen_data[display_id].softkey_label_length[0] = 0;
    g_jui_screen_data[display_id].softkey_label_length[1] = 0;

#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    jui_widget_override_mode_setting(JUI_OBJ_STATUS_BAR, KAL_FALSE, display_id);
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
    if (mode == JUI_SCREEN_MODE_FULL)
    {
        jui_widget_override_mode_setting(JUI_OBJ_STATUS_BAR, KAL_FALSE, display_id);

    #if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
        wgui_status_icon_bar_enable_integrated(KAL_FALSE);
        wgui_status_icon_bar_register_integrated_redraw(NULL);
    #endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
    }
    else if (mode == JUI_SCREEN_MODE_NORMAL)
    {
        jui_widget_override_mode_setting(JUI_OBJ_STATUS_BAR, KAL_TRUE, display_id);
    }
    else
    {
        ASSERT(mode < JUI_SCREEN_MODE_END);
    }
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 

    jui_lcd_mutex_lock();
    if (jam_is_in_fg_screen(display_id))
    {
        if (mode == JUI_SCREEN_MODE_FULL)
        {
            jui_widget_update_fullscreen_status_icons_cb();
        }

        if (jui_widget_obj_show_status(JUI_OBJ_STATUS_BAR, display_id))
        {
            jui_widget_draw_status_bar0();
        }
        else
        {
            wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
        }

        /* when change screen mode, remove the softkey */
        if (mode == JUI_SCREEN_MODE_FULL)
        {
            jui_widget_mvm_set_softkey(0, NULL, 0, KAL_FALSE, display_id);
            jui_widget_mvm_set_softkey(1, NULL, 0, KAL_FALSE, display_id);

            update_softkey_state_no_redraw(KEY_LSK, KEY_EVENT_UP);
            update_softkey_state_no_redraw(KEY_RSK, KEY_EVENT_UP);
        }
        else
        {
            jui_widget_mvm_redraw_softkeybar(display_id);
        }

    #if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
        if (mode == JUI_SCREEN_MODE_FULL)
        {
            wgui_status_icon_bar_enable_integrated(KAL_FALSE);
            wgui_status_icon_bar_register_integrated_redraw(NULL);
        }
        else if ((mode == JUI_SCREEN_MODE_NORMAL) && jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, display_id))
        {
            wgui_status_icon_bar_enable_integrated(KAL_TRUE);
            wgui_status_icon_bar_register_integrated_redraw(jui_widget_title_oem_show_normal_ex);
        }
    #endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
    }

    if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        jui_widget_layer_set_position(jui_layer_handle);

        if (jui_double_buffer_activated)
        {
            jui_widget_layer_set_position(jui_blt_handle);
        }

    }

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if (jam_mvm_is_vm_vk_on(display_id)  && jui_vk_layer_handle != GDI_LAYER_EMPTY_HANDLE && jam_mvm_get_current_vm_id() == display_id)
    {
        gdi_layer_push_and_set_active(jui_vk_layer_handle);
        if (g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_NORMAL)
        {
           gdi_layer_set_position(0, UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT - MMI_button_bar_height);
        }
        else if (g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_FULL)
        {
           gdi_layer_set_position(0, UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT);
        }
        gdi_layer_pop_and_restore_active();
#ifndef __JUI_VK_SLIM__
        if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_push_and_set_active(jui_layer_handle);
            if (mode == JUI_SCREEN_MODE_FULL)
            {
                gdi_draw_solid_rect(0,
                                    UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT - jui_ui_button_height - jui_title_offset,
                                    jui_ui_device_width - 1,
                                    UI_device_height - jui_ui_button_height - jui_title_offset  - 1,
                                    GDI_COLOR_WHITE);
            }
            else
            {
                gdi_draw_solid_rect(0,
                                    UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT,
                                    jui_ui_device_width - 1,
                                    UI_device_height - 1,
                                    GDI_COLOR_WHITE);
            }
            gdi_layer_pop_and_restore_active();
        }
#endif
#ifdef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT
        jui_vk_prepare_blt(display_id);
#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */
    }
#endif

    jui_lcd_mutex_unlock();

#if defined (SUPPORT_MMAPI)
    /* video or video recorder is active and coordinate is changed */
    /* jma_video_player_reconfig_layer();    //replace by event listener */
#endif /* defined (SUPPORT_MMAPI) */ 

    if (!jam_is_in_fg_mmi_screen(display_id))
    {
        g_jui_screen_data[display_id].screen_mode_changed_in_fg_mmi = KAL_FALSE;
        jui_widget_mvm_fire_event_listener_void_void(display_id, JUI_EVENT_SCREEN_MODE_CHANGED);
    }
    else
    {
        g_jui_screen_data[display_id].screen_mode_changed_in_fg_mmi = KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_get_screen_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_mvm_get_screen_mode(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    return g_jui_screen_data[display_id].screen_mode;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_is_fullscreen_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_mvm_is_fullscreen_mode(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    return (g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_FULL?KAL_TRUE:KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_layer_set_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  act_layer       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_layer_set_position(GDI_HANDLE act_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 x = 0, y = 0, width = 0, height = 0;
    kal_int32 x1 = 0, y1 = 0, width1 = 0, height1 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_lcd_mutex_lock();
    if (act_layer == 0 || act_layer == GDI_ERROR_HANDLE)
    {
        jui_lcd_mutex_unlock();
        return;
    }
    gdi_layer_push_and_set_active(act_layer);
    jui_widget_get_displayable_area(&x, &y, &width, &height);

    gdi_layer_get_dimension(&width1, &height1);
    if (width != width1 || height != height1)
    {
        gdi_layer_resize(width, height);
    }
    gdi_layer_get_position(&x1, &y1);
    if (x != x1 || y != y1)
    {
        gdi_layer_set_position(x, y);
    }

    gdi_layer_pop_and_restore_active();
    jui_lcd_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_displayable_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_x           [OUT]
 *  ret_y           [OUT]
 *  ret_width       [OUT]
 *  ret_height      [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_get_displayable_area(
                kal_int32 *ret_x,
                kal_int32 *ret_y,
                kal_int32 *ret_width,
                kal_int32 *ret_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 display_id = jui_widget_active_display_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (display_id < 0)
        display_id = 0;

    if (!jui_widget_mvm_is_fullscreen_mode(display_id))
    {
    #if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
        *ret_x = 0;
        *ret_y = 0;
        *ret_width = jui_ui_device_width;
        if (jui_widget_draw_softkey_by_vm)
        {
            *ret_height = jui_widget_get_display_height_id(display_id);
        }
        else
        {
            *ret_height = jui_widget_get_display_height_id(display_id) - MMI_button_bar_height;
        }
    #else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
        *ret_x = 0;
        *ret_y = MMI_status_bar_height;
        *ret_width = jui_ui_device_width;
        if (jui_widget_draw_softkey_by_vm)
        {
            *ret_height = jui_widget_get_display_height_id(display_id) - MMI_status_bar_height;
        }
        else
        {
            *ret_height = jui_widget_get_display_height_id(display_id) - MMI_status_bar_height - MMI_button_bar_height;
        }
    #endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
    }
    else
    {
        *ret_x = 0;
        *ret_y = 0;
        *ret_width = jui_ui_device_width;
        *ret_height = jui_widget_get_display_height_id(display_id);
    }
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
#ifndef __JUI_VK_SLIM__
    if(jam_mvm_is_vm_vk_on(display_id))
    {
        *ret_height += JUI_VIRTUAL_KEYPAD_HEIGHT;
    }    
#endif
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_obj_show_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj             [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_obj_show_status(jui_obj_type_enum obj, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 working_setting =
        g_jui_screen_data[display_id].default_screen_setting[g_jui_screen_data[display_id].
                                                             screen_mode] & g_jui_screen_data[display_id].
        available_screen_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (working_setting & (1 << obj))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_override_mode_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj                 [IN]        
 *  display_status      [IN]        
 *  display_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_override_mode_setting(jui_obj_type_enum obj, kal_bool display_status, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (obj)
    {
        case JUI_OBJ_BUTTON_BAR:
            if (display_status)
            {
                g_jui_screen_data[display_id].available_screen_setting |= 4 /* 00000100 */ ;
            }
            else
            {
                g_jui_screen_data[display_id].available_screen_setting &= 3 /* 00000011 */ ;
            }

            break;

        case JUI_OBJ_TITLE_BAR:
            if (display_status)
            {
                g_jui_screen_data[display_id].available_screen_setting |= 2 /* 00000010 */ ;
            }
            else
            {
                g_jui_screen_data[display_id].available_screen_setting &= 5 /* 00000101 */ ;
            }
            break;

        case JUI_OBJ_STATUS_BAR:
            if (display_status)
            {
                g_jui_screen_data[display_id].available_screen_setting |= 1 /* 00000001 */ ;
            }
            else
            {
                g_jui_screen_data[display_id].available_screen_setting &= 6 /* 00000110 */ ;
            }
            break;

        default:
            ASSERT(0);
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_reset_base_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_reset_base_layer(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE mmi_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    GDI_HANDLE layer_3;
    //color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(current_MMI_theme->lite_disp_scr_bg_color);
    //c = *current_MMI_theme->lite_disp_scr_bg_color;

    wgui_status_icon_bar_reset_update_callback();

    jui_lcd_mutex_lock();
    gdi_layer_push_and_set_active(mmi_layer_handle);
    gui_push_clip();

    if (jui_widget_mvm_is_fullscreen_mode(display_id))
    {
        ////gui_set_clip(0, 0, jui_ui_device_width - 1, jui_ui_device_height - 1);
        ////gui_fill_rectangle(0, 0, jui_ui_device_width - 1, jui_ui_device_height - 1, c);
        ////gdi_layer_flatten_to_base(mmi_layer_handle, jui_icon_layer_blt_handle, 0, 0);
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
        if (jam_mvm_is_vm_vk_on(display_id) && g_jui_screen_data[display_id].is_show_logo_screen == KAL_FALSE)
        {
            layer_3 = jui_vk_layer_handle;
        }
        else
#endif
        {
            layer_3 = GDI_LAYER_EMPTY_HANDLE;
        }

        if (jui_double_buffer_activated)
        {
            //GDI_LOCK;
            gdi_layer_flatten_to_base(jui_blt_handle,jui_icon_layer_blt_handle,layer_3,0); 
        }
        else
        {
            gdi_layer_flatten_to_base(jui_layer_handle,jui_icon_layer_blt_handle,layer_3,0);
        }
    }
    else
    {
        ////gui_set_clip(0, jui_title_offset, jui_ui_device_width - 1, jui_ui_device_height - 1);
        ////gui_fill_rectangle(0, jui_title_offset, jui_ui_device_width - 1, jui_ui_device_height - 1, c);
        if (jui_double_buffer_activated)
        {
            //GDI_LOCK;
            gdi_layer_flatten_to_base(jui_blt_handle,jui_hardware_layer_handle,jui_status_icon_layer_handle,jui_soft_button_layer_handle);
        }
        else
        {
            gdi_layer_flatten_to_base(jui_layer_handle,jui_hardware_layer_handle,jui_status_icon_layer_handle,jui_soft_button_layer_handle);
        }
    }
    gui_pop_clip();
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    jui_lcd_mutex_unlock();
}



/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_clear_base_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_clear_base_layer(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE mmi_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(current_MMI_theme->lite_disp_scr_bg_color);
    c = *current_MMI_theme->lite_disp_scr_bg_color;

    ////wgui_status_icon_bar_reset_update_callback();

    jui_lcd_mutex_lock();
    gdi_layer_push_and_set_active(mmi_layer_handle);
    gui_push_clip();

    if (jui_widget_mvm_is_fullscreen_mode(display_id))
    {
        gui_set_clip(0, 0, jui_ui_device_width - 1, UI_device_height - 1);
        gui_fill_rectangle(0, 0, jui_ui_device_width - 1, UI_device_height - 1, c);
        gdi_layer_flatten_to_base(mmi_layer_handle, jui_icon_layer_blt_handle, 0, 0);
        ////gdi_layer_flatten_to_base(jui_layer_handle,jui_icon_layer_blt_handle,0,0);
    }
    else
    {
        gui_set_clip(0, jui_title_offset, jui_ui_device_width - 1, UI_device_height - 1);
        gui_fill_rectangle(0, jui_title_offset, jui_ui_device_width - 1, UI_device_height - 1, c);
        ////gdi_layer_flatten_to_base(jui_layer_handle,jui_hardware_layer_handle,jui_status_icon_layer_handle,jui_soft_button_layer_handle);
    }
    gui_pop_clip();
    gdi_layer_pop_and_restore_active();
    jui_lcd_mutex_unlock();
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_resume_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_resume_screen(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_RESUME_SCREEN,
        display_id,
        jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, display_id),
        g_jui_screen_data[display_id].title_is_shown,
        jui_widget_obj_show_status(JUI_OBJ_STATUS_BAR, display_id),
        jui_widget_obj_show_status(JUI_OBJ_BUTTON_BAR, display_id),
        g_jui_screen_data[display_id].screen_mode);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    wgui_status_icon_bar_register_update_callback(jui_widget_update_fullscreen_status_icons_cb);
    if (jui_widget_obj_show_status(JUI_OBJ_TITLE_BAR, display_id) && g_jui_screen_data[display_id].title_is_shown)
    {
        jui_widget_mvm_show_title(display_id);
    }
#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    else
    {
        wgui_status_icon_bar_enable_integrated(KAL_FALSE);
        wgui_status_icon_bar_register_integrated_redraw(NULL);
    }
#endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 

    if (jui_widget_obj_show_status(JUI_OBJ_STATUS_BAR, display_id))
    {
        jui_widget_draw_status_bar0();
    }
    else
    {
        wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
    }
    if (jui_widget_obj_show_status(JUI_OBJ_BUTTON_BAR, display_id))
    {
        jui_widget_mvm_redraw_softkeybar(display_id);
    }

    jui_widget_update_fullscreen_status_icons_cb();
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_reset_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_reset_screen(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_RESET_SCREEN,display_id);
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    
    g_jui_screen_data[display_id].available_screen_setting = 1;
    g_jui_screen_data[display_id].screen_mode = JUI_SCREEN_MODE_FULL;
    memset(g_jui_screen_data[display_id].title_buffer, 0, sizeof(g_jui_screen_data[display_id].title_buffer));
    memset(g_jui_screen_data[display_id].softkey_label, 0, JUI_MAX_SOFTKEYS * JUI_SOFTKEY_STR_BUF);
    g_jui_screen_data[display_id].softkey_label_length[0] = 0;
    g_jui_screen_data[display_id].softkey_label_length[1] = 0;
#if defined(J2ME_SLIM_MEMORY_SUPPORT) && defined(__JUI_SLIM_SAVE_LAYER__)
    jui_widget_layer_delete_backup();
    jui_widget_is_saved_layer = KAL_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_get_display_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_mvm_get_display_x(void)
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
 *  jui_widget_mvm_get_display_y
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_mvm_get_display_y(void)
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
 *  jui_widget_mvm_get_display_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_mvm_get_display_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jui_ui_device_width;
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_get_display_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_mvm_get_display_height(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jui_widget_get_display_height_id(display_id);
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_get_display_height_by_screen_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_mvm_get_display_height_by_screen_mode(kal_bool is_full_screen,kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
         if(display_id < 0)
        {
            return 0;
        }
        else
        {
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
            if(display_id == jui_vk_display_id)
            {
                if (!is_full_screen)
                {
                    return jui_widget_get_display_height_id(display_id) - MMI_status_bar_height;
                }
                else
                {
                    return jui_widget_get_display_height_id(display_id);
                }
            }
            else
            {
                if(jam_mvm_is_vm_vk_on(display_id))
                {
                         if(!is_full_screen)
                        {
                            return  UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT - MMI_status_bar_height;
                        }
                         else
                        {
                            return  UI_device_height - JUI_VIRTUAL_KEYPAD_HEIGHT;
                        }
                }
                 else
                {
                         if(!is_full_screen)
                        {
                             return  UI_device_height  - MMI_status_bar_height;
                        }
                        else
                        {
                             return  UI_device_height;
                        }
                }
            }
#else
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
        return jui_ui_device_height;
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
        if (!is_full_screen)
        {
            return jui_ui_device_height - MMI_status_bar_height;
        }
        else
        {
            return jui_ui_device_height;
        }

#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
#endif
	}
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_malloc_lcd_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 *jui_widget_mvm_malloc_lcd_buffer(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_MALLOC_BUFFER,
        display_id,
        g_jui_screen_data[display_id].lcd_buffer);
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    if (g_jui_screen_data[display_id].lcd_buffer == NULL)
    {
        g_jui_screen_data[display_id].lcd_buffer = (kal_uint16*) (jui_lcd_total_buffer + display_id * jui_lcd_buffer_size);
    }
    g_jui_screen_data[display_id].buffer_disposed = KAL_FALSE;

    if (g_jui_screen_data[display_id].lcd_buffer != NULL)
    {
        ////memset(g_jui_screen_data[display_id].lcd_buffer, 0xff, jui_lcd_buffer_size); //?? why don't clear scren?? logo and java first screen??
        g_jui_screen_data[display_id].display_id = display_id;
    }

    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_MALLOC_BUFFER_2,
        display_id,
        g_jui_screen_data[display_id].lcd_buffer);

    return g_jui_screen_data[display_id].lcd_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_release_lcd_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 *  lcd_buffer      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_release_lcd_buffer(kal_int32 display_id, kal_uint16 *lcd_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_RELEASE_BUFFER,
        display_id,
        g_jui_screen_data[display_id].lcd_buffer,
        g_jui_screen_data[display_id].textbox,
        g_jui_screen_data[display_id].textfield,
        g_jui_screen_data[display_id].datefield,
        g_jui_screen_data[display_id].timefield,
        g_jui_screen_data[display_id].option_menu,
        g_jui_screen_data[display_id].popup);
    
    if (lcd_buffer != NULL && g_jui_screen_data[display_id].lcd_buffer == lcd_buffer)
    {
        if (jam_is_in_fg_screen(display_id))
        {
            g_jui_screen_data[display_id].buffer_disposed = KAL_TRUE;
        }
        else
        {
            //jvm_free(g_jui_screen_data[display_id].lcd_buffer);
            //#ifndef J2ME_SLIM_MEMORY_SUPPORT    
            g_jui_screen_data[display_id].lcd_buffer = NULL;
            //#endif
            g_jui_screen_data[display_id].buffer_disposed = KAL_FALSE;
            jui_widget_init_data(display_id);
        }
    }
    else
    {
#ifndef J2ME_SLIM_MEMORY_SUPPORT 
        ASSERT(0);
#endif
    }

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_finalize_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_finalize_screen(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint16 i;

    jui_textbox_data_struct     * textbox       = NULL;
    jui_textfield_data_struct   * textfield     = NULL;
    jui_datefield_data_struct   * datefield     = NULL;
    jui_datefield_time_struct   * timefield     = NULL;
    jui_option_menu_struct      * option_menu   = NULL;
    jui_popup_struct            * popup         = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_RELEASE_BUFFER,
        display_id,
        g_jui_screen_data[display_id].lcd_buffer,
        g_jui_screen_data[display_id].textbox,
        g_jui_screen_data[display_id].textfield,
        g_jui_screen_data[display_id].datefield,
        g_jui_screen_data[display_id].timefield,
        g_jui_screen_data[display_id].option_menu,
        g_jui_screen_data[display_id].popup);

    textbox = g_jui_screen_data[display_id].textbox;

    if (textbox != NULL)
    {
        for (i = 0; i < JUI_MAX_COMMAND_SUPPORT; i++)
        {
            if (textbox->command_label[i] != NULL)
            {
                jvm_free(textbox->command_label[i]);
                textbox->command_label[i] = NULL;
            }
        }

        if (textbox->text != NULL)
            jvm_free(textbox->text);
        jvm_free(textbox);

        g_jui_screen_data[display_id].textbox = NULL;
    }

    textfield = g_jui_screen_data[display_id].textfield;
    if(textfield != NULL)
    {
        if(textfield->text != NULL)
        {
            jvm_free(textfield->text);
            textfield->text = NULL;
        }
        jvm_free(textfield);
        g_jui_screen_data[display_id].textfield = NULL;
    }

    datefield = g_jui_screen_data[display_id].datefield;
    if(datefield != NULL)
    {
        jvm_free(datefield);
        g_jui_screen_data[display_id].datefield = NULL;
    }

    timefield = g_jui_screen_data[display_id].timefield;
    if(timefield != NULL)
    {
        jvm_free(timefield);
        g_jui_screen_data[display_id].timefield = NULL;
    }

    option_menu = g_jui_screen_data[display_id].option_menu;
    if(option_menu != NULL)
    {
        jvm_free(option_menu);
        g_jui_screen_data[display_id].option_menu = NULL;
    }

    popup = g_jui_screen_data[display_id].popup;
    if(popup != NULL)
    {
        jvm_free(popup);
        g_jui_screen_data[display_id].popup = NULL;
    }

    g_jui_screen_data[display_id].screen_mode = JUI_SCREEN_MODE_NORMAL;
    g_jui_screen_data[display_id].previous_screen = JUI_SCREEN_TYPE_UNKNOWN;
    g_jui_screen_data[display_id].screen_mode_changed_in_fg_mmi = KAL_FALSE;
}


#ifdef __SUPPORT_JBT__


/*****************************************************************************
 * FUNCTION
 *  jbt_finalize_for_jvm
 * DESCRIPTION
 *  This API is used by jbt_finalize since jbt_finalize may spend over 30 seconds,
 *  we have to refresh the screen such that the UI will not display strange view.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_finalize_for_jvm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH, LCD_HEIGHT, jui_widget_active_display_id);
    jui_widget_mvm_show_title(jui_widget_active_display_id);
    jui_widget_mvm_redraw_softkeybar(jui_widget_active_display_id);
}
#endif /* __SUPPORT_JBT__ */ 

/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_ui_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  visible     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
jui_widget_ui_style_type_enum jui_widget_get_ui_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__)
#if defined(__COSMOS_MMI_PACKAGE__)
    return JUI_WIDGET_UI_STYLE_FTO;
#else
    return JUI_WIDGET_UI_STYLE_FTE;
#endif /* __COSMOS_MMI_PACKAGE__ */
#else
    return JUI_WIDGET_UI_STYLE_NORMAL;
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_item_height
 * DESCRIPTION
 *  get fte menu highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_get_item_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    kal_int32 ascent = 0;
    kal_int32 descent = 0;
    kal_int32 leading = 0;
#endif /* __MMI_FTE_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    return MMI_MENUITEM_HEIGHT;
#else /* __MMI_FTE_SUPPORT__ */ 
    //jui_string_get_default_font_info(&ascent, &descent, &leading);
    //return ascent + descent + leading;
    return 40;
#endif /* __MMI_FTE_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_get_ssp_threshold_propeties
 * DESCRIPTION
 *  get fte menu highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_get_ssp_threshold_propeties(kal_int32 * gap_to_move,kal_int32 * gap_to_ss,kal_int32 * time_to_ss)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(gap_to_move != NULL)
        *gap_to_move = GUI_SSP_FOCUS_TO_HOLD_STATE_Y_THRESHOLD;
    
    if(gap_to_ss != NULL)
        *gap_to_ss = GUI_SSP_FREE_RUN_MOVEMENT_Y_THRESOLD;
    
    if(time_to_ss != NULL)
        * time_to_ss = GUI_SSP_FREE_RUN_THRESHOLD_TIME;
}

static kal_bool jui_textbox_is_locked = KAL_FALSE;


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_is_locked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_mvm_textbox_is_locked(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jui_textbox_is_locked;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_locked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_locked(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jui_textbox_is_locked = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_release_locked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_release_locked(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_textbox_is_locked = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_bringToTop_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_bringToTop_callback(kal_int32 display_id)
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
 *  jui_widget_mvm_textbox_bringToBack_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_bringToBack_callback(kal_int32 display_id)
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
 *  jui_widget_mvm_textbox_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_init(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    jui_textbox_data_struct *textbox = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_INIT,display_id,g_jui_screen_data[display_id].textbox);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    
    if (g_jui_screen_data[display_id].textbox == NULL)
    {
        textbox = (jui_textbox_data_struct*) jvm_malloc(sizeof(jui_textbox_data_struct));
        ASSERT(textbox != NULL);
        memset(textbox, 0x00, sizeof(jui_textbox_data_struct));

        for (i = 0; i < JUI_MAX_COMMAND_SUPPORT; i++)
        {
            if (textbox->command_label[i] == NULL)
            {
                textbox->command_label[i] =
                    (kal_uint16*) jvm_malloc((JUI_MAX_COMMAND_LABLE_LENGTH + 1) * sizeof(kal_uint16));
                ASSERT(textbox->command_label[i] != NULL);
            }
            memset(textbox->command_label[i], 0x00, (JUI_MAX_COMMAND_LABLE_LENGTH + 1) * sizeof(kal_uint16));
            textbox->command_label_length[i] = 0;
        }

        textbox->command_num = -1;

        textbox->constraints = 0;
        textbox->text_length = -1;

        textbox->ticker_length = -1;    /* no ticker */
        textbox->title_length = -1;     /* no title */
        textbox->is_editable = KAL_TRUE;
        textbox->is_shown = KAL_FALSE;
		textbox->is_data_ready = KAL_FALSE;

        g_jui_screen_data[display_id].textbox = textbox;
    }
}

kal_bool jui_widget_mvm_textbox_is_data_ready(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return ((textbox != NULL && textbox->is_data_ready == KAL_TRUE)?KAL_TRUE:KAL_FALSE);
 }



/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_deinit(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_DEINIT,display_id,g_jui_screen_data[display_id].textbox);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_set_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title               [IN]
 *  title_length        [IN]        
 *  display_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_set_title(kal_uint16 *title, kal_int32 title_length, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_SET_TITLE,display_id,title,title_length,textbox);
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL);

    if (title_length > JUI_MAX_TITLE_LENGTH)
        title_length = JUI_MAX_TITLE_LENGTH;

    memset(textbox->title, 0x00, (JUI_MAX_TITLE_LENGTH + 1) * sizeof(kal_uint16));

    if (title == NULL)
    {
        textbox->title_length = -1; /* -1:indicate there is no title */
    }
    else
    {
        textbox->title_length = title_length;

        if (title_length > 0)
            memcpy(textbox->title, title, title_length * sizeof(kal_uint16));
        textbox->title[title_length] = 0;   /* end flag */
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_set_ticker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ticker              [IN]
 *  ticker_length       [IN]        
 *  display_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_set_ticker(kal_uint16 *ticker, kal_int32 ticker_length, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_SET_TICKER,ticker,ticker_length);
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL);

    if (ticker_length > JUI_MAX_TICKER_LENGTH)
        ticker_length = JUI_MAX_TICKER_LENGTH;

    memset(textbox->ticker, 0x00, (JUI_MAX_TICKER_LENGTH + 1) * sizeof(kal_uint16));
    if (ticker == NULL)
    {
        textbox->ticker_length = -1;    /* no ticker */
    }
    else
    {
        textbox->ticker_length = ticker_length;

        if (ticker_length > 0)
            memcpy(textbox->ticker, ticker, ticker_length * sizeof(kal_uint16));
        textbox->ticker[ticker_length] = 0; /* end flag */
    }

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_set_max_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  max_size        [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_set_max_size(kal_int32 max_size, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_SET_MAX_SIZE,display_id,max_size,textbox);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL);
    
    if (max_size > JUI_MAX_BUFFER_SUPPORT)
        max_size = JUI_MAX_BUFFER_SUPPORT;
    textbox->text_max_size = max_size;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_set_constraints
 * DESCRIPTION
 *  
 * PARAMETERS
 *  constraints     [IN]        
 *  is_editable     [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_set_constraints(kal_int32 constraints, kal_bool is_editable, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_SET_CONSTRAINTS,display_id,constraints,is_editable,textbox);
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL);

    textbox->is_editable = is_editable;
    textbox->constraints = constraints;

    textbox->is_constraints_changed = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_set_commands
 * DESCRIPTION
 *  
 * PARAMETERS
 *  command_label               [IN]        
 *  command_label_length        [IN]
 *  command_id                  [IN]
 *  command_num                 [IN]        
 *  display_id                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_set_commands(
        kal_uint16 **command_label,
        kal_int32 *command_label_length,
        kal_int32 *command_id,
        kal_int32 *command_type,
        kal_int32 command_num,
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 i;
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_SET_COMMANDS,display_id,command_num,textbox);
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL);

    for (i = 0; i < JUI_MAX_COMMAND_SUPPORT; i++)
    {
        memset(textbox->command_label[i], 0x00, (JUI_MAX_COMMAND_LABLE_LENGTH + 1) * sizeof(kal_uint16));
    }

    if (command_num > JUI_MAX_COMMAND_SUPPORT)
        command_num = JUI_MAX_COMMAND_SUPPORT;

    for (i = 0; i < command_num; i++)
    {
        if (command_label[i] != NULL)
        {
            if (command_label_length[i] > JUI_MAX_COMMAND_LABLE_LENGTH)
                command_label_length[i] = JUI_MAX_COMMAND_LABLE_LENGTH;

            if (command_label_length[i] > 0)
                memcpy(textbox->command_label[i], command_label[i], command_label_length[i] * sizeof(kal_uint16));

            textbox->command_label[i][command_label_length[i]] = 0;

            textbox->command_label_length[i] = command_label_length[i];
            textbox->command_id[i] = command_id[i];
            textbox->command_type[i] = command_type[i];
        }
        else
        {
            textbox->command_num = -1;  /* no command num */
        }
    }

    textbox->command_num = command_num;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_set_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [IN]
 *  text_length     [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_set_text(kal_uint16 *text, kal_int32 text_length, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_SET_TEXT,display_id,text,text_length,textbox);
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL);

    if (jui_widget_mvm_textbox_is_locked(display_id))
    {
        return;
    }

    if (textbox->text != NULL)
    {
        jvm_free(textbox->text);
        textbox->text = NULL;
    }

    if (text == NULL)
    {
        textbox->text = NULL;
        textbox->text_length = -1;
    }
    else
    {
        if (text_length > JUI_MAX_BUFFER_SUPPORT)
            text_length = JUI_MAX_BUFFER_SUPPORT;

        textbox->text = (kal_uint16*) jvm_malloc((text_length + 1) * sizeof(kal_uint16));

        if (text_length > 0)
            memcpy(textbox->text, text, text_length * sizeof(kal_uint16));

        textbox->text[text_length] = 0; /* end flag */
        textbox->text_length = text_length;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_get_text_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_mvm_textbox_get_text_length(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 text_length = 0;
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(textbox != NULL);
    for (i = 0; i < textbox->text_max_size; i++)
    {
        if (textbox->text_external[i] != 0)
        {
            text_length++;
        }
        else
        {
            break;
        }
    }
    return text_length;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_get_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [OUT]
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_mvm_textbox_get_text(kal_uint16 *text, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 text_length = 0;
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(textbox != NULL);

    if (text == NULL)
        return -1;

    for (i = 0; i < textbox->text_max_size; i++)
    {
        text[i] = textbox->text_external[i];
        if (text[i] != 0)
        {
            text_length++;
        }
        else
        {
            break;
        }
    }

    return text_length;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_backup_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_backup_text(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_BACKUP_TEXT,display_id,textbox);

    if (textbox == NULL || jui_widget_mvm_textbox_is_locked(display_id))    /* no need to backup */
        return; 
    if (textbox->text != NULL)
    {
        jvm_free(textbox->text);
        textbox->text = NULL;
    }

    textbox->text_length = jui_widget_mvm_textbox_get_text_length(display_id);
    if (textbox->text_length >= 0)
    {
        textbox->text = (kal_uint16*) jvm_malloc((textbox->text_length + 1) * sizeof(kal_uint16));
        for (i = 0; i < textbox->text_length; i++)
            textbox->text[i] = textbox->text_external[i];
        textbox->text[i] = 0;

    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_paint_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_paint_title(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;
    mmi_java_ui_textbox_show_req_struct * msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(textbox != NULL);

    if (jui_widget_active_display_id != display_id ||
        (!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id)) ||
        textbox->is_shown == KAL_FALSE)
        return;

    msg =
        (mmi_java_ui_textbox_show_req_struct*) construct_local_para(
                                                sizeof(mmi_java_ui_textbox_show_req_struct),
                                                TD_CTRL);
    
    jui_widget_mvm_textbox_locked(display_id);

    msg->title = textbox->title;
    msg->title_length = textbox->title_length;
    msg->callback = jui_widget_mvm_textbox_release_locked;
    msg->vm_id = display_id;

    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_TEXTBOX_UPDATE_TITLE_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_paint_ticker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_paint_ticker(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;
    mmi_java_ui_textbox_show_req_struct *msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(textbox != NULL);
    
    if (jui_widget_active_display_id != display_id ||
        (!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id)) ||
        textbox->is_shown == KAL_FALSE)
        return;
    msg =
        (mmi_java_ui_textbox_show_req_struct*) construct_local_para(
                                                sizeof(mmi_java_ui_textbox_show_req_struct),
                                                TD_CTRL);
    
    jui_widget_mvm_textbox_locked(display_id);

    msg->ticker = textbox->ticker;
    msg->ticker_length = textbox->ticker_length;
    msg->callback = jui_widget_mvm_textbox_release_locked;
    msg->vm_id = display_id;
    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_TEXTBOX_UPDATE_TICKER_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_paint_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_paint_command(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;
    mmi_java_ui_textbox_show_req_struct * msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(textbox != NULL);

    //MAUI_02647918,remove the vm id check(check it on mmi layer)
    // MAUI_02962812
    if (jam_mvm_midlet_is_bg_running_by_vm_id(display_id))
        return;
    
    msg =
        (mmi_java_ui_textbox_show_req_struct*) construct_local_para(
                                                sizeof(mmi_java_ui_textbox_show_req_struct),
                                                TD_CTRL);
    jui_widget_mvm_textbox_locked(display_id);

    msg->command_label = (kal_uint16 **) textbox->command_label;
    msg->command_label_lenght = textbox->command_label_length;
    msg->command_num = textbox->command_num;
    msg->command_id = textbox->command_id;
    msg->command_type = textbox->command_type;
    msg->callback = jui_widget_mvm_textbox_release_locked;
    msg->vm_id = display_id;

    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_TEXTBOX_UPDATE_COMMAND_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_paint_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_paint_text(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ime_type = -1;
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;
    mmi_java_ui_textbox_show_req_struct * msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(textbox != NULL);

    if (jui_widget_active_display_id != display_id ||
        (!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id)) ||
        textbox->is_shown == KAL_FALSE || jui_widget_mvm_textbox_is_locked(display_id))
        return;

    msg =
        (mmi_java_ui_textbox_show_req_struct*) construct_local_para(
                                                sizeof(mmi_java_ui_textbox_show_req_struct),
                                                TD_CTRL);
    jui_widget_mvm_textbox_locked(display_id);

    if (textbox->is_constraints_changed && textbox->constraints >= 0)
    {
        ime_type = jui_widget_convert_jui_type_2_mmi_type(textbox->constraints);
    }
    msg->buffer = textbox->text;
    msg->max_size = textbox->text_max_size + 1;
    msg->constraints = ime_type;
    msg->is_editable = textbox->is_editable;
    msg->callback = jui_widget_mvm_textbox_release_locked;
    msg->vm_id = display_id;

    java_send_msg(
        MOD_J2ME,
        MOD_MMI,
        MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_UI_TEXTBOX_UPDATE_TEXT_REQ  ,
        msg);

    textbox->is_constraints_changed = KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_show_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_show_callback(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jui_widget_textbox_temp_buffer)
    {
        jvm_free(jui_widget_textbox_temp_buffer);
        jui_widget_textbox_temp_buffer = NULL;
    }
    jui_widget_mvm_textbox_release_locked(display_id);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_show(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTBOX_SHOW,display_id);
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    jui_widget_mvm_textbox_show_internal(MOD_J2ME, MOD_MMI, display_id);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_show_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_module      [IN]        
 *  dst_module      [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_show_internal(module_type src_module, module_type dst_module, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ime_type = 0;
    //kal_int16 i;

    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;
    mmi_java_ui_textbox_show_req_struct * msg = NULL;
    module_type module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_TEXTBOX_SHOW_INTERNAL,
        display_id,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(display_id),
        jam_is_in_fg_mmi_screen(display_id),
        textbox->title,
        textbox->ticker,
        textbox->text_external,
        textbox->text_max_size,
        textbox->constraints,
        textbox->is_editable,
        textbox->command_num);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL);

    if (jui_widget_active_display_id != display_id ||
        (!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id)))
        return;
    
    if (module_id == MOD_MMI)
    {

        mmi_java_ui_textbox_show_req_struct req_struct;
        msg = &req_struct;
	}
	else
	{
    msg =
        (mmi_java_ui_textbox_show_req_struct*) construct_local_para(
                                                sizeof(mmi_java_ui_textbox_show_req_struct),
                                                TD_CTRL);
	}
    jui_widget_mvm_textbox_locked(display_id);

    /* copy the buffer in mmi_java_ui_textbox_show_req */
    /*for (i = 0; i < textbox->text_length; i++)
    {
        textbox->text_external[i] = textbox->text[i];
    }

    textbox->text_external[textbox->text_length] = 0;*/

    /* MAUI_02988658 */
    jui_widget_textbox_temp_buffer = (kal_uint16*) jvm_malloc((textbox->text_length + 1) * sizeof(kal_uint16));
    memcpy(jui_widget_textbox_temp_buffer, textbox->text, textbox->text_length * sizeof(kal_uint16));
    jui_widget_textbox_temp_buffer[textbox->text_length] = 0;

    ime_type = jui_widget_convert_jui_type_2_mmi_type(textbox->constraints);

    msg->title = textbox->title;
    msg->title_length = textbox->title_length;
    msg->ticker = textbox->ticker;
    msg->ticker_length = textbox->ticker_length;
    msg->buffer = textbox->text_external;
    msg->text_buffer = jui_widget_textbox_temp_buffer;
    msg->text_length = textbox->text_length;
    msg->max_size = textbox->text_max_size + 1; /* +1 indicate the last address is used as end flag */
    msg->constraints = ime_type;
    msg->callback = jui_widget_mvm_textbox_show_callback;
    msg->bring2Top_callback = jui_widget_mvm_textbox_bringToTop_callback;
    msg->bring2Back_callback = jui_widget_mvm_textbox_bringToBack_callback;
    msg->is_editable = textbox->is_editable;
    msg->command_label = (kal_uint16 **) textbox->command_label;
    msg->command_num = textbox->command_num;
    msg->command_id = textbox->command_id;
    msg->command_type = textbox->command_type;
    msg->command_label_lenght = textbox->command_label_length;
    msg->vm_id = display_id;

    textbox->is_data_ready = KAL_TRUE;
	if (module_id == MOD_MMI)
    {
        textbox->is_shown = KAL_TRUE;

        textbox->is_constraints_changed = KAL_FALSE;

        jui_widget_textbox_display_id = display_id;


        mmi_java_ui_textbox_show_req(msg);
        msg = NULL;
    }
	else
	{

    java_send_msg(src_module, dst_module, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_TEXTBOX_SHOW_REQ, msg);

    textbox->is_shown = KAL_TRUE;

    textbox->is_constraints_changed = KAL_FALSE;

    jui_widget_textbox_display_id = display_id;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_hide_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_hide_callback(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_widget_mvm_textbox_release_locked(display_id);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_hide(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct * msg = NULL;
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_TEXTBOX_HIDE,
        display_id,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(display_id),
        jam_is_in_fg_mmi_screen(display_id));

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL );
    
    if (jui_widget_active_display_id != display_id || !textbox->is_shown 
        /*||(!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id))*/ /*hide screen mayhe happen in any case */)
        return;

    msg =
        (mmi_java_ui_textbox_show_req_struct*) construct_local_para(
                                                sizeof(mmi_java_ui_textbox_show_req_struct),
                                                TD_CTRL);
    jui_widget_mvm_textbox_locked(display_id);

    msg->callback = jui_widget_mvm_textbox_hide_callback;
    msg->vm_id = display_id;

    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_TEXTBOX_HIDE_REQ, msg);

    jui_widget_mvm_textbox_backup_text(display_id); //?? why backup text? --> restore needed

    textbox->is_shown = KAL_FALSE;

	textbox->is_data_ready = KAL_FALSE;
	
    jui_widget_textbox_display_id = INVALIDE_VM_ID;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_get_cursor_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cursor_index        [OUT]
 *  display_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_get_cursor_index(kal_int32 *cursor_index, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    *cursor_index = wgui_cat2002_get_cursor_index();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_is_visible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id          [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jui_widget_mvm_textbox_is_visible(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    
    return mmi_java_ui_textbox_is_visible(display_id);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_bring_2_top
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_bring_2_top(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ime_type = 0;
    //kal_int16 i;

    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;

    mmi_java_ui_textbox_show_req_struct * msg = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_TEXTBOX_BRING_2_TOP,
        display_id,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(display_id),
        jam_is_in_fg_mmi_screen(display_id));
    
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    ASSERT(textbox != NULL);

    if (jui_widget_active_display_id != display_id ||
        (!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id)))
        return;

    msg =
        (mmi_java_ui_textbox_show_req_struct*) construct_local_para(
                                                sizeof(mmi_java_ui_textbox_show_req_struct),
                                                TD_CTRL);
    jui_widget_mvm_textbox_locked(display_id);

    if(!textbox->is_shown || (textbox->is_shown && jui_widget_textbox_display_id != display_id))
    {
        /* copy the buffer in mmi_java_ui_textbox_show_req */
        /*for (i = 0; i < textbox->text_length; i++)
        {
            textbox->text_external[i] = textbox->text[i];
        }

        textbox->text_external[textbox->text_length] = 0;*/

        /* MAUI_02988658 */
        jui_widget_textbox_temp_buffer = (kal_uint16*) jvm_malloc((textbox->text_length + 1) * sizeof(kal_uint16));
        memcpy(jui_widget_textbox_temp_buffer, textbox->text, textbox->text_length * sizeof(kal_uint16));
        jui_widget_textbox_temp_buffer[textbox->text_length] = 0;

        ime_type = jui_widget_convert_jui_type_2_mmi_type(textbox->constraints);

        msg->title = textbox->title;
        msg->title_length = textbox->title_length;
        msg->ticker = textbox->ticker;
        msg->ticker_length = textbox->ticker_length;
        msg->buffer = textbox->text_external;
        msg->text_buffer = jui_widget_textbox_temp_buffer;
        msg->text_length = textbox->text_length;
        msg->max_size = textbox->text_max_size + 1; /* +1 indicate the last address is used as end flag */
        msg->constraints = ime_type;
        msg->bring2Top_callback = jui_widget_mvm_textbox_bringToTop_callback;
        msg->bring2Back_callback = jui_widget_mvm_textbox_bringToBack_callback;
        msg->is_editable = textbox->is_editable;
        msg->command_label = (kal_uint16 **) textbox->command_label;
        msg->command_num = textbox->command_num;
        msg->command_id = textbox->command_id;
        msg->command_type = textbox->command_type;
        msg->command_label_lenght = textbox->command_label_length;

    }
    
    msg->callback = jui_widget_mvm_textbox_show_callback;
    msg->vm_id = display_id;

    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_TEXTBOX_SHOW_RSP, msg);
    
    textbox->is_shown = KAL_TRUE;
    textbox->is_constraints_changed = KAL_FALSE;
    jui_widget_textbox_display_id = display_id;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textbox_command_action_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textbox_command_action_finished(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_textbox_show_req_struct * msg = NULL;
    jui_textbox_data_struct *textbox = g_jui_screen_data[display_id].textbox;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_TEXTBOX_COMMAND_ACTION_FINISHED,
        display_id,
        jui_widget_active_display_id,
        jam_is_in_fg_screen(display_id),
        jam_is_in_fg_mmi_screen(display_id));

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    //MAUI_02646966,remove assert and replace it with warning log
    ////ASSERT(textbox != NULL );
    if(textbox == NULL)
    {
        jvm_trace_warning("[jui_widget.c]commandActionFinished,textbox=NULL");
        return;
    }

    if (!textbox->is_shown)
    {
        jvm_trace_warning("[jui_widget.c]commandActionFinished,textbox->is_shown=KAL_FALSE");
        return;
    }
    
    if (jui_widget_active_display_id != display_id 
        /*||(!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id))*/ /*hide screen mayhe happen in any case */)
        return;

    msg =
        (mmi_java_ui_textbox_show_req_struct*) construct_local_para(
                                                sizeof(mmi_java_ui_textbox_show_req_struct),
                                                TD_CTRL);
    jui_widget_mvm_textbox_locked(display_id);

    msg->callback = jui_widget_mvm_textbox_hide_callback;
    msg->vm_id = display_id;

    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_TEXTBOX_HIDE_RSP, msg);
    
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textfield_finish_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  validate        [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textfield_finish_callback(kal_bool validate, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textfield_data_struct *textfield = g_jui_screen_data[display_id].textfield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ASSERT(textfield != NULL);
    if (!textfield)
    {
        return;
    }
    
    textfield->is_finished = KAL_TRUE;
    textfield->is_validate = validate;

    if (textfield->callback != NULL)
        textfield->callback(display_id);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textfield_is_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_mvm_textfield_is_finished(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textfield_data_struct *textfield = g_jui_screen_data[display_id].textfield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ASSERT(textfield != NULL);
    if (!textfield)
    {
        return KAL_FALSE;
    }

    return textfield->is_finished;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textfield_is_validate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_mvm_textfield_is_validate(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textfield_data_struct *textfield = g_jui_screen_data[display_id].textfield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(textfield != NULL);

    return textfield->is_validate;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textfield_get_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [OUT]         
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_widget_mvm_textfield_get_text(kal_uint16 *text, kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 text_length = 0;
    jui_textfield_data_struct *textfield = g_jui_screen_data[display_id].textfield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(textfield != NULL);

    if (text == NULL)
        return -1;

    for (i = 0; i < textfield->max_size; i++)
    {
        text[i] = textfield->text[i];
        if (text[i] != 0)
        {
            text_length++;
        }
        else
        {
            break;
        }
    }

    if (textfield->text != NULL)
        jvm_free(textfield->text);
    jvm_free(textfield);
    g_jui_screen_data[display_id].textfield = NULL;

    return text_length;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textfield_show
 * DESCRIPTION
 *  enter full screen editor
 *  This function is a non-block API
 * PARAMETERS
 *  text                    [IN]         
 *  text_length             [IN]        
 *  max_size                [IN]        
 *  constraints             [IN]        
 *  callback        [IN]        
 *  display_id              [IN]        
 *  must_input(?)           [IN]        User must give some input or not
 *  text_buf_length(?)      [IN]        Length of buffer
 *  callback(?)             [IN]        
 *  text_buf(?)             [IN]        Buffer for user input
 *  input_type(?)           [IN]        Input type
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textfield_show(
        kal_uint16 *text,
        kal_int32 text_length,
        kal_int32 max_size,
        kal_int32 constraints,
        void (*callback) (kal_int32 display_id),
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      /************************************************
      IMPORTANT NOTICE:
         Before using this function, remember to pause Java VM.
      *************************************************/
    mmi_java_ui_textfield_show_req_struct *msg =
        (mmi_java_ui_textfield_show_req_struct*) construct_local_para(
                                                    sizeof(mmi_java_ui_textfield_show_req_struct),
                                                    TD_CTRL);
    jui_textfield_data_struct *textfield = g_jui_screen_data[display_id].textfield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTFIELD_SHOW,display_id,text,text_length,max_size,constraints);

    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    
    if (textfield != NULL)
    {
        if (textfield->text != NULL)
            jvm_free(textfield->text);
        jvm_free(textfield);

        textfield = NULL;
    }

    textfield = (jui_textfield_data_struct*) jvm_malloc(sizeof(jui_textfield_data_struct));
    ASSERT(textfield != NULL);

    if (max_size > JUI_MAX_BUFFER_SUPPORT)
        max_size = JUI_MAX_BUFFER_SUPPORT;

    if (text_length > max_size)
        text_length = max_size;

    if (max_size >= 0)
    {
        textfield->text = (kal_uint16*) jvm_malloc((max_size + 1) * sizeof(kal_uint16));
        ASSERT(textfield->text != NULL);
        memset(textfield->text, 0x00, (max_size + 1) * sizeof(kal_uint16));
        memcpy(textfield->text, text, text_length * sizeof(kal_uint16));
    }

    textfield->constraints = jui_widget_convert_jui_type_2_mmi_type(constraints);
    textfield->max_size = max_size;
    textfield->is_finished = KAL_FALSE;
    textfield->is_validate = KAL_FALSE;
    textfield->callback = callback;

    g_jui_screen_data[display_id].textfield = textfield;


    msg->text = textfield->text;
    msg->max_size = textfield->max_size + 1;
    msg->constraints = textfield->constraints;
    msg->callback = jui_widget_mvm_textfield_finish_callback;
    msg->vm_id = display_id;

    java_send_msg(
        MOD_J2ME,
        MOD_MMI,
        J2ME_MMI_SAP,   /* MSG_ID_MMI_JAVA_UI_TEXTFIELD_SHOW_REQ */
        MSG_ID_MMI_JAVA_UI_TEXTFIELD_SHOW_REQ,
        msg);

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textfield_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_textfield_hide(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_TEXTFIELD_HIDE,display_id);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_textfield_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_mvm_textfield_query(kal_int32 * max_size,kal_int32 * constraints,kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_textfield_data_struct *textfield = g_jui_screen_data[display_id].textfield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(textfield == NULL)
        return KAL_FALSE;

    if(max_size != NULL)
        * max_size = textfield->max_size;

    if(constraints != NULL)
        *constraints = textfield->constraints;
    return KAL_TRUE;
    

}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_finish_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  validate        [IN]        
 *  year            [IN]        
 *  month           [IN]        
 *  day             [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_datefield_calendar_finish_callback(
        kal_bool validate,
        kal_int32 year,
        kal_int32 month,
        kal_int32 day,
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_datefield_data_struct *datefield = g_jui_screen_data[display_id].datefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_DATEFIELD_DATE_FINISH,display_id,validate,year,month,day);
    //ASSERT(datefield != NULL);
    if (!datefield)
    {
        return;
    }

    datefield->year = year;
    datefield->month = month;
    datefield->day = day;

    datefield->is_finished = KAL_TRUE;
    datefield->is_validate = validate;

    if (datefield->callback != NULL)
        datefield->callback(display_id);

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_is_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_mvm_datefield_calendar_is_finished(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_datefield_data_struct *datefield = g_jui_screen_data[display_id].datefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ASSERT(datefield != NULL);
    if (!datefield)
    {
        return KAL_TRUE;
    }

    return datefield->is_finished;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_is_validate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_mvm_datefield_calendar_is_validate(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_datefield_data_struct *datefield = g_jui_screen_data[display_id].datefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ASSERT(datefield != NULL);
    if (!datefield)
    {
        return KAL_FALSE;
    }

    return datefield->is_validate;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_get_date
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year            [OUT]         
 *  month           [OUT]         
 *  day             [OUT]         
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_datefield_calendar_get_date(
        kal_int32 *year,
        kal_int32 *month,
        kal_int32 *day,
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_datefield_data_struct *datefield = g_jui_screen_data[display_id].datefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(datefield != NULL);

    *year = datefield->year;
    *month = datefield->month;
    *day = datefield->day;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_show
 * DESCRIPTION
 *  this interface is invoked by java to hide textbox screen
 * PARAMETERS
 *  year            [IN]        
 *  month           [IN]        
 *  day             [IN]        
 *  display_id      [IN]        
 *  mm(?)           [IN]        
 *  callback(?)     [IN]        Will be invoked when hide operation is finished
 *  dd(?)           [IN]        
 *  yyyy(?)         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_datefield_calendar_show(
        kal_int32 year,
        kal_int32 month,
        kal_int32 day,
        void (*callback) (kal_int32 display_id),
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_datefield_date_show_req_struct *msg =
        (mmi_java_ui_datefield_date_show_req_struct*)
        construct_local_para(sizeof(mmi_java_ui_datefield_date_show_req_struct), TD_CTRL);
    jui_datefield_data_struct *datefield = g_jui_screen_data[display_id].datefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_DATEFIELD_DATE_SHOW,display_id,year,month,day);
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);
    
    if (datefield == NULL)
    {
        datefield = (jui_datefield_data_struct*) jvm_malloc(sizeof(jui_datefield_data_struct));
        ASSERT(datefield != NULL);
        g_jui_screen_data[display_id].datefield = datefield;
    }

    datefield->year = year;
    datefield->month = month;
    datefield->day = day;
    datefield->is_finished = KAL_FALSE;
    datefield->is_validate = KAL_FALSE;
    datefield->callback = callback;

    msg->year = year;
    msg->month = month;
    msg->day = day;
    msg->callback = jui_widget_mvm_datefield_calendar_finish_callback;
    msg->vm_id = display_id;
    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_DATEFIELD_DATE_SHOW_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_hide
 * DESCRIPTION
 *  this interface is invoked by java to hide textbox screen
 * PARAMETERS
 *  display_id      [IN]        
 *  jui_editor_textbox_callback(?)      [IN]        The callback will be invoked when hide operation is finished(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_datefield_calendar_hide(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_datefield_date_show_req_struct *msg =
        (mmi_java_ui_datefield_date_show_req_struct*)
        construct_local_para(sizeof(mmi_java_ui_datefield_date_show_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->vm_id = display_id;

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_DATEFIELD_DATE_HIDE,display_id);
    
    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_DATEFIELD_DATE_HIDE_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_finish_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  validate        [IN]        
 *  year            [IN]        
 *  month           [IN]        
 *  day             [IN]        
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_datefield_time_finish_callback(
        kal_bool validate,
        kal_int32 hour,
        kal_int32 minute,
        kal_int32 second,
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_datefield_time_struct *timefiled = g_jui_screen_data[display_id].timefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_DATEFIELD_TIME_FINISH,display_id,validate,hour,minute,second);
    //ASSERT(timefiled != NULL);
    if (!timefiled)
    {
        return;
    }
    
    timefiled->hour = hour;
    timefiled->minute = minute;
    timefiled->second = second;

    timefiled->is_finished = KAL_TRUE;
    timefiled->is_validate = validate;

    if (timefiled->callback != NULL)
        timefiled->callback(display_id);

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_is_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_mvm_datefield_time_is_finished(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_datefield_time_struct *timefiled = g_jui_screen_data[display_id].timefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ASSERT(timefiled != NULL);
    if (!timefiled)
    {
        return KAL_TRUE;
    }

    return timefiled->is_finished;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_is_validate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_mvm_datefield_time_is_validate(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_datefield_time_struct *timefiled = g_jui_screen_data[display_id].timefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ASSERT(timefiled != NULL);
    if (!timefiled)
    {
        return KAL_TRUE;
    }

    return timefiled->is_validate;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_get_date
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year            [OUT]         
 *  month           [OUT]         
 *  day             [OUT]         
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_datefield_time_get_date(
        kal_int32 *hour,
        kal_int32 *minute,
        kal_int32 *second,
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_datefield_time_struct *timefiled = g_jui_screen_data[display_id].timefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(timefiled != NULL);

    *hour = timefiled->hour;
    *minute = timefiled->minute;
    *second = timefiled->second;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_show
 * DESCRIPTION
 *  this interface is invoked by java to hide textbox screen
 * PARAMETERS
 *  year            [IN]        
 *  month           [IN]        
 *  day             [IN]        
 *  display_id      [IN]        
 *  mm(?)           [IN]        
 *  callback(?)     [IN]        Will be invoked when hide operation is finished
 *  dd(?)           [IN]        
 *  yyyy(?)         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_datefield_time_show(
        kal_int32 hour,
        kal_int32 minute,
        kal_int32 second,
        void (*callback) (kal_int32 display_id),
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_datefield_time_show_req_struct *msg =
        (mmi_java_ui_datefield_time_show_req_struct*)
        construct_local_para(sizeof(mmi_java_ui_datefield_time_show_req_struct), TD_CTRL);
    jui_datefield_time_struct *timefield = g_jui_screen_data[display_id].timefield;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_DATEFIELD_TIME_SHOW,display_id,hour,minute,second);

    if (timefield == NULL)
    {
        timefield = (jui_datefield_time_struct*) jvm_malloc(sizeof(jui_datefield_time_struct));
        ASSERT(timefield != NULL);
        g_jui_screen_data[display_id].timefield = timefield;
    }

    timefield->hour = hour;
    timefield->minute = minute;
    timefield->second =second;
    timefield->is_finished = KAL_FALSE;
    timefield->is_validate = KAL_FALSE;
    timefield->callback = callback;

    msg->hour = hour;
    msg->minute = minute;
    msg->second = second;
    msg->callback = jui_widget_mvm_datefield_time_finish_callback;
    msg->vm_id = display_id;
    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_DATEFIELD_TIME_SHOW_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_datefield_calendar_hide
 * DESCRIPTION
 *  this interface is invoked by java to hide textbox screen
 * PARAMETERS
 *  display_id      [IN]        
 *  jui_editor_textbox_callback(?)      [IN]        The callback will be invoked when hide operation is finished(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_datefield_time_hide(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_ui_datefield_time_show_req_struct *msg =
        (mmi_java_ui_datefield_time_show_req_struct*)
        construct_local_para(sizeof(mmi_java_ui_datefield_time_show_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->vm_id = display_id;

    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_DATEFIELD_TIME_HIDE,display_id);
    
    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_DATEFIELD_TIME_HIDE_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                       [IN]        
 *  title_length                [IN]        
 *  command_label               [IN]        
 *  command_label_length        [IN]
 *  command_id                  [IN]
 *  command_num                 [IN]        
 *  display_id                  [IN]        
 *  menu_num                    [IN]
 *  callback                    [IN]
 *  menu_list                   [IN]
 *  menu_ids                    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_option_menu_show(
        kal_uint16 *title,
        kal_int32 title_length,
        kal_uint16 **command_label,
        kal_int32 *command_label_length,
        kal_int32 *command_id,
        kal_int32 command_num,
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 i;

    jui_option_menu_struct *option_menu = NULL;

    mmi_java_ui_option_menu_show_req_struct *msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_OPTION_MENU_SHOW, display_id,jui_widget_active_display_id,title, title_length, command_label, command_num, command_id);
    //if (!jam_is_in_fg_screen(display_id) && ! jam_is_in_fg_mmi_screen(display_id) )
    //    return;
    if (jui_widget_active_display_id != display_id)
        return;

    if (g_jui_screen_data[display_id].option_menu &&
        g_jui_screen_data[display_id].option_menu->is_processing)
    {
        return;
    }

    option_menu = (jui_option_menu_struct*) jvm_malloc(sizeof(jui_option_menu_struct));
    ASSERT(option_menu != NULL);
    memset(option_menu, 0x00, sizeof(jui_option_menu_struct));

    option_menu->is_processing = KAL_TRUE;

    if (title_length > JUI_MAX_TITLE_LENGTH)
    {
        title_length = JUI_MAX_TITLE_LENGTH;
    }

    option_menu->title_length = title_length;

    if (title != NULL && title_length > 0)
    {
        memcpy(option_menu->title, title, title_length * sizeof(kal_uint16));
    }

    option_menu->title[title_length] = 0;
    if (command_num > JUI_MAX_COMMAND_SUPPORT)
        command_num = JUI_MAX_COMMAND_SUPPORT;

    option_menu->command_num = command_num;
    for (i = 0; i < command_num; i++)
    {
        option_menu->command_label_length[i] = command_label_length[i];
        option_menu->command_label[i] = (kal_uint16*) jvm_malloc((command_label_length[i] + 1) * sizeof(kal_uint16));
        ASSERT(option_menu->command_label[i] != NULL);
        memset(option_menu->command_label[i], 0x00, (command_label_length[i] + 1) * sizeof(kal_uint16));
        memcpy(option_menu->command_label[i], command_label[i], command_label_length[i] * sizeof(kal_uint16));

        option_menu->command_id[i] = command_id[i];
    }

    if (g_jui_screen_data[display_id].option_menu != NULL)
    {
        for (i = 0; i < g_jui_screen_data[display_id].option_menu->command_num; i++)
        {
            if (g_jui_screen_data[display_id].option_menu->command_label[i] != NULL)
            {
                jvm_free(g_jui_screen_data[display_id].option_menu->command_label[i]);
            }
        }

        jvm_free(g_jui_screen_data[display_id].option_menu);

    }

    g_jui_screen_data[display_id].option_menu = option_menu;

    msg = (mmi_java_ui_option_menu_show_req_struct*)
            construct_local_para(sizeof(mmi_java_ui_option_menu_show_req_struct), TD_CTRL);

    msg->title = option_menu->title;
    msg->title_length = option_menu->title_length;
    msg->callback = jui_widget_mvm_option_menu_show_callback;
    msg->command_label = option_menu->command_label;
    msg->command_label_length = option_menu->command_label_length;
    msg->command_num = command_num;
    msg->command_id = option_menu->command_id;
    msg->screen_disppear_callback = jui_widget_mvm_option_menu_disppear_callback;
    msg->vm_id = display_id;

    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_OPTION_MENU_SHOW_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 *  callback        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_option_menu_hide(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_ui_option_menu_show_req_struct * msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_OPTION_MENU_HIDE,display_id);
    if (!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id)
#ifdef __COSMOS_MMI_PACKAGE__
        && !vapp_java_ui_is_option_menu_existed()
#endif
       )
    {
        jui_widget_mvm_option_menu_hide_callback(display_id);
        return;
    }
    
    if (g_jui_screen_data[display_id].option_menu != NULL && !g_jui_screen_data[display_id].option_menu->is_processing)
    {
        msg =
            (mmi_java_ui_option_menu_show_req_struct*)
            construct_local_para(sizeof(mmi_java_ui_option_menu_show_req_struct), TD_CTRL);
        
        g_jui_screen_data[display_id].option_menu->is_processing = KAL_TRUE;
        
        msg->callback = jui_widget_mvm_option_menu_hide_callback;
        msg->vm_id = display_id;
        java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_OPTION_MENU_HIDE_REQ, msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_hide_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_option_menu_register_disppear_callback(void (*callback)(kal_int32 display_id))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jui_widget_mvm_option_menu_disppear_callback_ptr = callback;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_show_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jui_widget_mvm_option_menu_show_callback(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jui_screen_data[display_id].option_menu)
    {
        g_jui_screen_data[display_id].option_menu->is_processing = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_hide_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jui_widget_mvm_option_menu_hide_callback(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_int32 i;
    //jui_option_menu_struct *option_menu = g_jui_screen_data[display_id].option_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    if (option_menu == NULL)
        return;

    if (option_menu->command_label != NULL)
    {
        for (i = 0; i < option_menu->command_num; i++)
            jvm_free(option_menu->command_label[i]);
    }
    jvm_free(option_menu);
    g_jui_screen_data[display_id].option_menu = NULL;
    
    */
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_disppear_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

static void jui_widget_mvm_option_menu_disppear_callback(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;    
    jui_option_menu_struct *option_menu = g_jui_screen_data[display_id].option_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( jui_widget_mvm_option_menu_disppear_callback_ptr != NULL)
    {
        if(option_menu != NULL)
        {
            if (option_menu->command_label != NULL)
            {
                for (i = 0; i < option_menu->command_num; i++)
                {
                    jvm_free(option_menu->command_label[i]);
                }
            }
            jvm_free(option_menu);
            g_jui_screen_data[display_id].option_menu = NULL;
        }
        
        jui_widget_mvm_option_menu_disppear_callback_ptr(display_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_is_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_widget_mvm_option_menu_is_finished(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jui_option_menu_struct *option_menu = g_jui_screen_data[display_id].option_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (option_menu == NULL ? KAL_TRUE:KAL_FALSE);
}

#ifdef __USE_JUI_POPUP__
/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                       [IN]        
 *  title_length                [IN]        
 *  command_label               [IN]        
 *  command_label_length        [IN]
 *  command_id                  [IN]
 *  command_num                 [IN]        
 *  display_id                  [IN]        
 *  menu_num                    [IN]
 *  callback                    [IN]
 *  menu_list                   [IN]
 *  menu_ids                    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_popup_show(
        kal_uint16 *title,
        kal_int32 title_length,
        kal_uint16 **command_label,
        kal_int32 *command_label_length,
        kal_int32 *command_id,
        kal_int32 command_num,
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 i;

    jui_popup_struct *popup = NULL;

    mmi_java_ui_popup_show_req_struct *msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_POPUP_SHOW, display_id,jui_widget_active_display_id,title, title_length, command_label, command_num, command_id);
    //if (!jam_is_in_fg_screen(display_id) && ! jam_is_in_fg_mmi_screen(display_id) )
    //    return;
    if (jui_widget_active_display_id != display_id)
        return;

    popup = (jui_popup_struct*) jvm_malloc(sizeof(jui_popup_struct));
    ASSERT(popup != NULL);
    memset(popup, 0x00, sizeof(jui_popup_struct));

    if (title_length > JUI_MAX_TITLE_LENGTH)
    {
        title_length = JUI_MAX_TITLE_LENGTH;
    }

    popup->title_length = title_length;

    if (title != NULL && title_length > 0)
    {
        memcpy(popup->title, title, title_length * sizeof(kal_uint16));
    }

    popup->title[title_length] = 0;
    if (command_num > JUI_MAX_COMMAND_SUPPORT)
        command_num = JUI_MAX_COMMAND_SUPPORT;

    popup->command_num = command_num;
    for (i = 0; i < command_num; i++)
    {
        popup->command_label_length[i] = command_label_length[i];
        popup->command_label[i] = (kal_uint16*) jvm_malloc((command_label_length[i] + 1) * sizeof(kal_uint16));
        ASSERT(popup->command_label[i] != NULL);
        memset(popup->command_label[i], 0x00, (command_label_length[i] + 1) * sizeof(kal_uint16));
        memcpy(popup->command_label[i], command_label[i], command_label_length[i] * sizeof(kal_uint16));

        popup->command_id[i] = command_id[i];
    }

    if (g_jui_screen_data[display_id].popup != NULL)
    {
        for (i = 0; i < g_jui_screen_data[display_id].popup->command_num; i++)
        {
            if (g_jui_screen_data[display_id].popup->command_label[i] != NULL)
            {
                jvm_free(g_jui_screen_data[display_id].popup->command_label[i]);
            }
        }

        jvm_free(g_jui_screen_data[display_id].popup);

    }

    g_jui_screen_data[display_id].popup = popup;
    msg = (mmi_java_ui_popup_show_req_struct*)construct_local_para(sizeof(mmi_java_ui_popup_show_req_struct), TD_CTRL);
    msg->title = popup->title;
    msg->title_length = popup->title_length;
    msg->callback = NULL;
    msg->command_label = popup->command_label;
    msg->command_label_length = popup->command_label_length;
    msg->command_num = command_num;
    msg->command_id = popup->command_id;
    msg->screen_disppear_callback = jui_widget_mvm_popup_disppear_callback;
    msg->vm_id = display_id;

    java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_POPUP_SHOW_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 *  callback        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_popup_hide(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_ui_popup_show_req_struct * msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_POPUP_HIDE,display_id);

    if (!jam_is_in_fg_screen(display_id) && !jam_is_in_fg_mmi_screen(display_id))
        return;
    
    if (g_jui_screen_data[display_id].popup != NULL)
    {
        msg =
            (mmi_java_ui_popup_show_req_struct*)
            construct_local_para(sizeof(mmi_java_ui_popup_show_req_struct), TD_CTRL);
        msg->callback = jui_widget_mvm_popup_hide_callback;
        msg->vm_id = display_id;
        java_send_msg(MOD_J2ME, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_UI_POPUP_HIDE_REQ, msg);
    }
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_hide_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void jui_widget_mvm_popup_register_disppear_callback(void (*callback)(kal_int32 display_id))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jui_widget_mvm_popup_disppear_callback_ptr = callback;
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_hide_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jui_widget_mvm_popup_hide_callback(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    jui_popup_struct *popup = g_jui_screen_data[display_id].popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (popup == NULL)
        return;

    if (popup->command_label != NULL)
    {
        for (i = 0; i < popup->command_num; i++)
            jvm_free(popup->command_label[i]);
    }
    jvm_free(popup);
    g_jui_screen_data[display_id].popup = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_option_menu_disppear_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

static void jui_widget_mvm_popup_disppear_callback(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( jui_widget_mvm_popup_disppear_callback_ptr != NULL)
        jui_widget_mvm_popup_disppear_callback_ptr(display_id);
}
#else
void jui_widget_mvm_popup_show(
        kal_uint16 *title,
        kal_int32 title_length,
        kal_uint16 **command_label,
        kal_int32 *command_label_length,
        kal_int32 *command_id,
        kal_int32 command_num,
        kal_int32 display_id)
{}
void jui_widget_mvm_popup_hide(kal_int32 display_id)
{}

void jui_widget_mvm_popup_register_disppear_callback(void (*callback)(kal_int32 display_id))
{
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_clear_mmi_screen_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_clear_mmi_screen_context(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jui_screen_data[display_id].textfield && !g_jui_screen_data[display_id].textfield->is_finished)
    {
        jui_widget_mvm_textfield_finish_callback(KAL_FALSE, display_id);
    }

    if (g_jui_screen_data[display_id].datefield && !g_jui_screen_data[display_id].datefield->is_finished)
    {
        jui_widget_mvm_datefield_calendar_finish_callback(KAL_FALSE, 0, 0, 0, display_id);
    }

    if (g_jui_screen_data[display_id].timefield && !g_jui_screen_data[display_id].timefield->is_finished)
    {
        jui_widget_mvm_datefield_time_finish_callback(KAL_FALSE, 0, 0, 0, display_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_set_current_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 *  current         [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_set_current_screen(kal_int32 display_id, jui_screen_type_enum current)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        JVM_TRACE_TYPE_JUI,
        FUNC_J2ME_JUI_SET_CURRENT_SCREEN,
        display_id,
        jui_widget_active_display_id,
        g_jui_screen_data[display_id].previous_screen,
        g_jui_screen_data[display_id].current_screen,
        current);
        
#ifdef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT
    if (g_jui_screen_data[display_id].is_show_logo_screen)
    {
        jui_vk_prepare_blt(display_id);
    }
#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */

    g_jui_screen_data[display_id].is_show_logo_screen = KAL_FALSE;        

    if (g_jui_screen_data[display_id].option_menu != NULL)  /* option menu is displayed */
        jui_widget_mvm_option_menu_hide(display_id);

#ifdef __USE_JUI_POPUP__
    if(g_jui_screen_data[display_id].popup != NULL)
        jui_widget_mvm_popup_hide(display_id);
#endif

    if (g_jui_screen_data[display_id].current_screen == current)
    {
        return;
    }

    g_jui_screen_data[display_id].previous_screen = g_jui_screen_data[display_id].current_screen;
    g_jui_screen_data[display_id].current_screen = current;

    if (jui_widget_active_display_id == display_id &&
        g_jui_screen_data[display_id].previous_screen == JUI_SCREEN_TYPE_TEXTBOX)
    {
        jui_widget_mvm_textbox_hide(display_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_get_current_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  display_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jui_screen_type_enum jui_widget_mvm_get_current_screen(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jui_screen_data[display_id].current_screen;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_convert_jui_type_2_mmi_type
 * DESCRIPTION
 *  convert jui input type to mmi input type
 * PARAMETERS
 *  input_type      [IN]        Input type
 *  must_input(?)           [IN]        User must give some input or not(?)
 *  text_buf_length(?)      [IN]        Length of buffer(?)
 *  text_buf(?)             [IN]        Buffer for user input(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jui_widget_convert_jui_type_2_mmi_type(kal_int32 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ime_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (input_type)
    {
        case JUI_INPUT_TYPE_EMAIL:
            ime_type = IMM_INPUT_TYPE_EMAIL;
            break;

        case JUI_INPUT_TYPE_EMAIL_PASSWORD:
            ime_type = IMM_INPUT_TYPE_EMAIL | IMM_INPUT_TYPE_EXT_PASSWORD;
            break;

        case JUI_INPUT_TYPE_URL:
            ime_type = IMM_INPUT_TYPE_URL;
            break;

        case JUI_INPUT_TYPE_URL_PASSWORD:
            ime_type = IMM_INPUT_TYPE_URL | IMM_INPUT_TYPE_EXT_PASSWORD;
            break;

        case JUI_INPUT_TYPE_NUMERIC:
            ime_type = IMM_INPUT_TYPE_SIGNED_NUMERIC;
            break;

        case JUI_INPUT_TYPE_NUMERIC_PASSWORD:
            ime_type = IMM_INPUT_TYPE_SIGNED_NUMERIC_PASSWORD;
            break;

        case JUI_INPUT_TYPE_PHONE_NUMBER:
            ime_type = IMM_INPUT_TYPE_PHONE_NUMBER;
            break;

        case JUI_INPUT_TYPE_PHONE_NUMBER_PASSWORD:
            ime_type = IMM_INPUT_TYPE_PHONE_NUMBER | IMM_INPUT_TYPE_EXT_PASSWORD;
            break;

        case JUI_INPUT_TYPE_ANY:
            ime_type = IMM_INPUT_TYPE_SENTENCE;
            break;

        case JUI_INPUT_TYPE_ANY_PASSWORD:
            ime_type = IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_EXT_PASSWORD;
            break;

        case JUI_INPUT_TYPE_DECIMAL_NUMERIC:
            ime_type = IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC;
            break;

        case JUI_INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD:
            ime_type = IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD;
            break;
    }
    ime_type |= INPUT_TYPE_OVERRIDE_DEFAULT;

    return ime_type;
}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_sort_commands
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [OUT]         
 *  type            [IN]         
 *  priority        [IN]         
 *  num             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_sort_commands(kal_int32 *result, kal_int32 *type, kal_int32 *priority, kal_int32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i, j, m, n;
    kal_bool exchange;

    char table[10] = 
    {
        127,    /* invalid */
        124,    /* SCREEN */
        5,      /* BACK */
        7,      /* CANCEL */
        125,    /* OK */
        126,    /* HELP */
        8,      /* STOP */
        6,      /* EXIT */
        123,    /* ITEM */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num <= 1)
        return;

    for (i = 0; i < num; i++)
        result[i] = i;

    for (i = 0; i < num - 1; i++)
    {
        exchange = KAL_FALSE;
        for (j = i; j < num; j++)
        {
            if (type[result[i]] == type[result[j]])
            {
                if (priority[result[i]] > priority[result[j]])
                {
                    result[i] ^= result[j]; /* exchange result[i] and result[j] */
                    result[j] ^= result[i];
                    result[i] ^= result[j];
                    exchange = KAL_TRUE;
                }
            }
            else
            {
                m = (type[result[i]] < 1 || type[result[i]] > 8) ? 127 : table[type[result[i]]];
                n = (type[result[j]] < 1 || type[result[j]] > 8) ? 127 : table[type[result[j]]];

                if (m < n)
                {
                    result[i] ^= result[j]; /* exchange result[i] and result[j] */
                    result[j] ^= result[i];
                    result[i] ^= result[j];
                    exchange = KAL_TRUE;
                }

            }
        }

        if (!exchange)
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_set_auto_sort_commands
 * DESCRIPTION
 *  
 * PARAMETERS
 *  autoSort          [IN]                
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_set_auto_sort_commands(kal_bool autoSort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_widget_auto_sort_commands = autoSort;
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_set_auto_sort_commands
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_is_auto_sort_commands(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jui_widget_auto_sort_commands;
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_is_support_native_permission_dialog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  TRUE: JAL provider a native permission dialog
 *****************************************************************************/
kal_bool jui_widget_is_support_native_permission_dialog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_is_support_virtual_keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  TRUE: JAL support virtual keypad
 *****************************************************************************/
kal_bool jui_widget_mvm_is_support_virtual_keypad(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if(jam_mvm_is_vm_vk_on(display_id))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }    
#else
    return KAL_FALSE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_get_virtual_keypad_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 * 
 *****************************************************************************/
kal_int32 jui_widget_mvm_get_virtual_keypad_height(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if(jam_mvm_is_vm_vk_on(display_id))
    {
        return JUI_VIRTUAL_KEYPAD_HEIGHT;
    }
    else
    {
        return 0;
    }    
#else
    return 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_firstscreen_notify
 * DESCRIPTION
 *  when first screen is displayed, this function will be called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_firstscreen_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    java_send_msg(kal_get_active_module_id(),MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_UI_LAUNCH_FINISH_IND,NULL);
    kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_LAUNCH_FINISHED);
}

/*****************************************************************************
 * FUNCTION
 *  jui_widget_touch_feedback_play
 * DESCRIPTION
 *  play touch feedback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_touch_feedback_play(jui_widget_touch_feedback_enum feedback_type)
{

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__  */

}


/*****************************************************************************
 * FUNCTION
 *  jui_widget_mvm_rotate_screen
 * DESCRIPTION
 *  rotate screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_widget_mvm_rotate_screen(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JUI_WIDGET_CHECK_DISPLAY_ID(display_id);

    jui_lcd_mutex_lock();
    jui_widget_mvm_clear_screen(display_id);
    jui_widget_mvm_unregister_lcd(display_id);
    jui_widget_deinit_java_status_icon_buffer();
    
    jui_widget_init_java_status_icon_buffer();
    jui_widget_mvm_register_lcd(KAL_FALSE,display_id);

    jui_lcd_mutex_unlock();
}

kal_wchar STR_MUSIC_WALKMAN_NAME[] ={0x97f3,0x4e50,0x968f,0x8eab,0x542c,0x0000};
kal_wchar STR_MUSIC_NAME[] = L"music";
static kal_wchar * supported_midlet[] = {STR_MUSIC_WALKMAN_NAME,STR_MUSIC_NAME};
/*****************************************************************************
 * FUNCTION
 *  jui_widget_is_support_repaint_enhancement
 * DESCRIPTION
 *  check if current midlet should support repaint enhancement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jui_widget_is_support_repaint_enhancement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool supported = KAL_FALSE;
    kal_wchar * midletName = jam_mvm_get_current_vm_mid_name();
    kal_int32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //kal_prompt_trace(MOD_J2ME,"[JUI]jui_widget_is_support_repaint_enhancement,midletName=%s\n",midletName);
    if(midletName == NULL)
        return KAL_FALSE;

    for( index = 0 ; index < sizeof(supported_midlet)/sizeof(supported_midlet[0]) ; index ++)
    {
        supported = kal_wstrncmp(midletName,supported_midlet[index],kal_wstrlen(supported_midlet[index])) == 0 ? KAL_TRUE:KAL_FALSE;

        if(supported)
            break;
    }

    //kal_prompt_trace(MOD_J2ME,"[JUI]support enhancement=%d\n",supported);
    return supported;
}
