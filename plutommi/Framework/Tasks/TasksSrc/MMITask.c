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
 * MMITask.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Protocol task functionality.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : MMItask.c

   PURPOSE     : Protocol task functionality 

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma

   DATE     : Dec' 28, 2002

**************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "MMI_features.h"

#include "mmi_frm_queue_gprot.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "app_ltlcom.h"
#include "gui_inputs.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "mmi_frm_input.h"
#include "fix_size_mem.h"
#include "mmi_frm_event_flag_prot.h"
#include "mmi_frm_scenario_gprot.h"
#include "PixcomFontEngine.h"
#include "stack_ltlcom.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "stack_msgs.h"
#include "task_config.h"
#include "mmi_frm_event_flag_gprot.h"
#include "mmi_msg_struct.h"
#include "device.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events.h"
#include "mmi_frm_at_util_prot.h"
#include "mmi_frm_history.h"
#include "nvram_common_defs.h"
#include "custom_nvram_config.h"
#include "PhoneSetup.h"
#include "GpioSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "Mmi_frm_prot.h"
#include "app_datetime.h"
#include "CharBatSrvGprot.h"
#include "Mmi_cache_table.h"
#include "BootupSrvGprot.h"
#include "FlightModeGProt.h"
#include "CallManagementGprot.h"
#include "PhoneSetupGprots.h"
#include "DateTimeGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
#include "ProtocolEvents.h"
#include "ShutdownSrvGprot.h"
#include "PowerOnChargerProt.h"
#include "Wgui_categories_util.h"
#include "mmi_frm_mem_prot.h"
#include "ps_public_enum.h"

/*****************************************************************************
* Define                                                                      
*****************************************************************************/

/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/
oslMsgqid mmi_ext_qid = KAL_NILQ_ID;
MMI_BOOL g_keypad_flag = MMI_FALSE;
MMI_BOOL g_pen_flag = MMI_FALSE;
U8 g_input_msg_in_queue = 0;
MMI_BOOL framework_initialized = MMI_FALSE;


extern kal_mutexid mmi_mutex_trace;
#ifdef __FLIGHT_MODE_SUPPORT__
extern PHNSET_CNTX g_phnset_cntx;
#endif /* __FLIGHT_MODE_SUPPORT__ */


/*****************************************************************************
* Local Function                                                              
*****************************************************************************/
static void InitEventHandlersBeforePowerOn(void);
static U8 mmi_frm_check_is_valid_msg(MYQUEUE *base, MYQUEUE *msg);
/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/
extern void applib_mime_init(void);
extern void InitializeChargingScr(void);
extern void QuitSystemOperation(void);
extern void setup_UI_wrappers(void);
extern void SetDateTime(void *t);
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
extern void gui_inputs_cache_init_mutex(void);
#endif
#ifdef __VENUS_UI_ENGINE__
extern void vfx_mmi_sys_init(void);
extern void vfx_mmi_onidle(void);
extern void vfx_mmi_before_process_msg(void);
extern void vfx_mmi_check_update(void);
#endif
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__    
void mmi_frm_scr_mgm_init(void);
#endif /* __MMI_LCM_PRIMITIVE_FLUSH__ */
extern void mmi_frm_nvram_cache_validate(void);

extern int vm_appcomm_queue_is_empty(void);
extern void vm_appcomm_dispatch_msg(void);

extern void gdi_anim_mmi_init(void);
extern void gdc_imgdec_callback_dispatch(void *data, U8 scr_mod);
extern void gdc_msg_dispatch(void *data, U8 scr_mod);
extern void srv_fmgri_device_ready_hdlr(void *msg_ptr);
extern void mmi_frm_pen_handle(void);

#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
extern void gui_sse_init(void);
#endif

#if defined(__KJX_AT_APP__)	//xb add 2016-12-23
extern void custom_cmd_send(char* cmd, kal_bool bCheckRes, kal_uint16 delay_time);
extern void ATCommand_Set_Handler(void *msg);
#endif/*__KJX_AT_APP__*/

#include "fs_gprot.h"
#include "Conversions.h"

void InitFileSystem() 
{
    fs_config_encoding_api_struct fs_cfg;

    fs_cfg.ucs_to_wchar_func = &UCS2_TO_WCHAR;
    fs_cfg.get_default_encoding_length_func = &mmi_chset_get_char_size_of_default_charset;

    FS_Config(FS_CONFIG_UTILITY_FUNC, &fs_cfg);
}

/*****************************************************************************
 * FUNCTION
 *  MMI_Init
 * DESCRIPTION
 *  MMI Init Function
 * PARAMETERS
 *  task_indx       [IN]        Index of task
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL MMI_Init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __DRM_SUPPORT__
    mmi_mutex_trace = kal_create_mutex("mmi_trace");
	#endif

    InitFileSystem();
    applib_mime_init();
    mmi_frm_init_key_event();
    mmi_frm_fix_mem_init();
    mmi_frm_event_flag_create();
    mmi_frm_init_scenario();

    mmi_frm_appmem_stage1_init();

    /* 
     * initial the system service timer 
     */
    L4InitTimer();
    setup_UI_wrappers();

    mmi_fe_init();
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    /* init the editor cache mutext */
    gui_inputs_cache_init_mutex();
#endif /* GUI_INPUT_BOX_CACHE_SUPPORT */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_check_wait_to_run
 * DESCRIPTION
 *  This function checks how many jobs want to run in MMI task
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_STATUS_NONE_WANT_TO_RUN     - there is nothing in MMI task.
 *  MMI_STATUS_ONE_WANT_TO_RUN      - there is one job wants to run.
 *  MMI_STATUS_FEW_WANT_TO_RUN      - there are few jobs want to run.
 *  MMI_STATUS_MEDIUM_WANT_TO_RUN   - there are meidum jobs want to run.
 *  MMI_STATUS_MANY_WANT_TO_RUN     - there are many jobs want to run.
 *****************************************************************************/
mmi_status_enum mmi_frm_check_wait_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 external_queue_node_number = 0;
    U32 circular_queue_node_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_fetch_msg_from_extQ_to_circularQ();
    external_queue_node_number = msg_get_extq_messages();
    circular_queue_node_number = (U32)OslNumOfCircularQMsgs();

    if (IsBitSet(g_input_msg_in_queue, MMI_DEVICE_KEY) || 
        IsBitSet(g_input_msg_in_queue, MMI_DEVICE_PEN))
    {
        return MMI_STATUS_INPUT_EVENTS_WANT_TO_RUN;
    }

    if (IsInNVRAMProcedure() == MMI_FALSE)
    {   /* general case */
        if (external_queue_node_number  == 0)
        {
            if (circular_queue_node_number == 0)
            {
                return MMI_STATUS_NONE_WANT_TO_RUN;
            }
            else if (circular_queue_node_number > (CIRCQ_NO_OF_NODES/4))
            {
                return MMI_STATUS_MANY_WANT_TO_RUN;
            }
            else if (circular_queue_node_number > (CIRCQ_NO_OF_NODES/16))
            {
                return MMI_STATUS_MEDIUM_WANT_TO_RUN;
            }
            else if (circular_queue_node_number > 1)
            {
                return MMI_STATUS_FEW_WANT_TO_RUN;
            }
            else
            {    /* circular_queue_node_number = 1 */
                return MMI_STATUS_ONE_WANT_TO_RUN;
            }
        }
        else
        {
            return MMI_STATUS_MANY_WANT_TO_RUN;
        }
    }
    else
    {   /* In NVRAM procedure */
        return MMI_STATUS_MANY_WANT_TO_RUN;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fetch_msg_from_extQ_to_circularQ
 * DESCRIPTION
 *  fetch the message from external queue and put
 *  in the circular queue.
 *  (*) Need to set my_index & mmi_ext_qid before using
 *  this function
 * PARAMETERS
 *  void
 * RETURNS
 *  1 - the message is invalid, and discard the message
 *  0 - the message is vaild
 *****************************************************************************/
void mmi_frm_fetch_msg_from_extQ_to_circularQ(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U32 queue_node_number = 0;
    MYQUEUE checkBaseNode;
    U8 flag = 0;
    //ilm_struct ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsInNVRAMProcedure() == MMI_FALSE)
    {
        /*
         * If not in NVRAM access procedure,
         * receive the message from MMI queue and put in circular queue 
         */
        queue_node_number = msg_get_extq_messages();
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_TASK_COPY_EXTERNAL_Q_TO_CIRCULAR_Q, queue_node_number);
        while ((queue_node_number > 0) && !OslIsCircularQFull())
        {
            OslReceiveMsgExtQ(mmi_ext_qid, &Message);
            kal_set_active_module_id(MOD_MMI);
            OslLookUpLastCircularQMsg((void*)&checkBaseNode);

            if (mmi_frm_check_is_valid_msg(&checkBaseNode, &Message) == 1)
            {
                /* put Message in circular queue */
                //ilm_ptr.src_mod_id = Message.src_mod_id;
                //ilm_ptr.dest_mod_id = Message.dest_mod_id;
                //ilm_ptr.msg_id = Message.msg_id;
                //ilm_ptr.sap_id = Message.sap_id;
                //ilm_ptr.local_para_ptr = Message.local_para_ptr;
                //ilm_ptr.peer_buff_ptr = Message.peer_buff_ptr;

                flag = OslWriteCircularQ(&Message);

                /* Check if the input message */
                if (Message.msg_id == MSG_ID_MMI_EQ_KEYPAD_DETECT_IND)
                {
                    SetBit(g_input_msg_in_queue, MMI_DEVICE_KEY);
                }
                if (Message.msg_id == MSG_ID_TP_EVENT_IND)
                {
                    SetBit(g_input_msg_in_queue, MMI_DEVICE_PEN);
                }

                MMI_ASSERT(flag == 1);
                /* TIMER use special data in the local_para_ptr field. Can NOT treat as general ILM */
                //if (Message.src_mod_id != MOD_TIMER)
                //{
                //    hold_local_para(ilm_ptr.local_para_ptr);
                //    hold_peer_buff(ilm_ptr.peer_buff_ptr);
                //}
            }
            //OslFreeInterTaskMsg(&Message);

            queue_node_number = msg_get_extq_messages();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_mmi_task_started
 * DESCRIPTION
 *  To judge MMI task is start or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  - Has entered MMI task entry function
 *  MMI_FALSE - Has not entered MMI task entry function
 *****************************************************************************/
MMI_BOOL mmi_frm_is_mmi_task_started(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_ext_qid != KAL_NILQ_ID) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  MMI_task
 * DESCRIPTION
 *  Entry function for Protocol task
 *  
 *  This receives protocol task events from the stack and forwards it to
 *  MMI task.
 * PARAMETERS
 *  entry_param     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_task(oslEntryType *entry_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    oslMsgqid qid;

    U32 count = 0;
    U32 queue_node_number = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    qid = task_info_g[entry_param->task_indx].task_ext_qid;
    mmi_ext_qid = qid;
    mmi_frm_nvram_cache_validate();
    InitEventHandlersBeforePowerOn();
    mmi_frm_set_event_flag(MMI_EVT_F_NOT_IN_NVRAM);
    mmi_frm_set_event_flag(MMI_EVT_F_NOT_IN_GDD);
    mmi_frm_set_event_flag(MMI_EVT_F_SCRM_ALLOC);

    while (1)
    {
        {

            if (g_keypad_flag == MMI_TRUE)
            {
                mmi_frm_key_handle(NULL);
            //#ifdef __VENUS_UI_ENGINE__
            //    vfx_mmi_check_update();
            //#endif  

            //#if defined(__MMI_TOUCH_SCREEN__) && defined(__MTK_TARGET__)
                /* MAUI_01901848
                 * END key down->mmi_pen_disable
                 * so during the END key down, mmi_frm_pen_flush_queue will always return MMI_FALSE
                 * g_has_switch_screen will not has the opportunity to reset to MMI_FALSE;
                 * If the END key's up event is handle here(the upper function) and the Message
                 * MSG_ID_TP_EVENT_IND is in the MMI external queue and it is the first message in the queue
                 * that need to be handled and the first pen event is pen down in the pen event buffer.
                 * After pen down is handled in the protocol event handler, pen abort will be generated
                 * The behavior is not right, so we add reset_context_for_new_screen here.
                 */
                /* Make sure there should be a new start for pen event when entering new screen */
            //#ifdef __MMI_VUI_3D_CUBE_APP__
            //    if (!vadp_p2v_uc_is_in_venus())
            //#endif
            //    {
            //        mmi_frm_pen_reset_context_for_new_screen();
            //    }
            //#endif                
                              
            }
            
            if (g_pen_flag == MMI_TRUE)
            {
            #ifdef __MMI_TOUCH_SCREEN__
                mmi_frm_pen_handle();
            #endif
            //#if defined(__MMI_TOUCH_SCREEN__) && defined(__MTK_TARGET__)
            //#ifdef __MMI_VUI_3D_CUBE_APP__
            //    if (!vadp_p2v_uc_is_in_venus())
            //#endif
            //    {
            //        /* Make sure there should be a new start for pen event when entering new screen */
            //        mmi_frm_pen_reset_context_for_new_screen();
            //    }                
            //#endif
            }

            /* Get Total count in external queue */
            queue_node_number = msg_get_extq_messages();

            if ((g_pen_flag == MMI_FALSE) && (queue_node_number == 0) && (OslNumOfCircularQMsgs() == 0) && (g_keypad_flag == MMI_FALSE)&& vm_appcomm_queue_is_empty())
            {
                U8 flag = 0;
                //ilm_struct ilm_ptr;

                /* MMI task suspends for the queue */
            #ifdef __VENUS_UI_ENGINE__
                vfx_mmi_onidle();
            #endif
				if((g_pen_flag == MMI_FALSE) && (queue_node_number == 0) && (OslNumOfCircularQMsgs() == 0) && (g_keypad_flag == MMI_FALSE) && vm_appcomm_queue_is_empty())
				{
					MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_TASK_SUSPEND_EXTERNAL_Q);
                	OslReceiveMsgExtQ(mmi_ext_qid, &Message);
                	kal_set_active_module_id(MOD_MMI);

                /* put Message in circular queue */
                //ilm_ptr.src_mod_id = Message.src_mod_id;
                //ilm_ptr.dest_mod_id = Message.dest_mod_id;
                //ilm_ptr.msg_id = Message.msg_id;
                //ilm_ptr.sap_id = Message.sap_id;
                //ilm_ptr.local_para_ptr = Message.local_para_ptr;
                //ilm_ptr.peer_buff_ptr = Message.peer_buff_ptr;

                	flag = OslWriteCircularQ(&Message);
                	MMI_ASSERT(flag == 1);
				}
				else
				{
					mmi_frm_invoke_post_event();
					mmi_frm_fetch_msg_from_extQ_to_circularQ();
				}
                /* TIMER use special data in the local_para_ptr field. Can NOT treat as general ILM */
                //if (Message.src_mod_id != MOD_TIMER)
                //{
                //    hold_local_para(ilm_ptr.local_para_ptr);
                //    hold_peer_buff(ilm_ptr.peer_buff_ptr);
                //    OslFreeInterTaskMsg(&Message);
                //}
            }
            else
            {
                mmi_frm_fetch_msg_from_extQ_to_circularQ();
            }

            count = OslNumOfCircularQMsgs();
            while (count > 0)
            {
                /* 
                 * Notify Venus UI in each message done 
                 */
                #ifdef __VENUS_UI_ENGINE__
                vfx_mmi_before_process_msg();
                #endif                
            
                kal_set_active_module_id(MOD_MMI);

                if (OslReadCircularQ(&Message))
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TASK_MSG_HANDLE_BEGIN, Message.msg_id, Message.oslSrcId, Message.oslDestId);

					#if defined(OBIGO_Q05A)
                    if (Message.dest_mod_id == MOD_WAP)
                    {
                    //#if defined(OBIGO_Q05A)
                        extern void mmi_wap_handle_msg(void *msgPtr);

                        mmi_wap_handle_msg((void*)&Message);
                    //#endif /* OBIGO_Q05A */ 
                    }
                    //#if defined(OBIGO_Q05A)
                    else if (Message.dest_mod_id == MOD_MMS)
                    {
                        extern void mmi_wap_handle_msg(void *msgPtr);
                        mmi_wap_handle_msg((void*)&Message);
                    }
                    //#endif /* OBIGO_Q05A */ 
                    //else
                    #endif
                    {
                        switch (Message.msg_id)
                        {
                            case MSG_ID_TIMER_EXPIRY:
                            {
                                //kal_uint16 msg_len;

                                //EvshedMMITimerHandler(get_local_para_ptr(Message.oslDataPtr, &msg_len));
                                EvshedMMITimerHandler(&Message);
                            }
                                break;

                            case MSG_ID_MMI_EQ_POWER_ON_IND:
                            {
                                mmi_eq_power_on_ind_struct *p = (mmi_eq_power_on_ind_struct*) Message.oslDataPtr;

                                srv_bootup_set_mode(p);
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
                                if(p->poweron_mode == POWER_ON_PRECHARGE || p->poweron_mode == POWER_ON_CHARGER_IN ||
                                /*  p->poweron_mode == POWER_ON_ALARM || */ p->poweron_mode == POWER_ON_EXCEPTION
                            #ifdef __MMI_USB_SUPPORT__
                                    || p->poweron_mode == POWER_ON_USB
                            #endif
                                    )
                                {
                                    mmi_fe_reset_font_boot_mode();
                                }
#endif

                                /* To initialize data/time */
                                SetDateTime((void*)&(p->rtc_time));
                                gdi_init();
                            #ifdef __VENUS_UI_ENGINE__
                                vfx_mmi_sys_init();
                            #endif

                                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TASK_POWER_PROC_BEGIN, p->poweron_mode);
								mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
                                switch (p->poweron_mode)
                                {
                                    case POWER_ON_KEYPAD:
                                        //mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
                                    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                                        PhnsetSetUARTConfig((rmmi_sim_uart_setting_enum)p->dual_sim_uart_setting); 
                                    #endif

                                        g_charbat_context.PowerOnCharger = 0;

                                        /* disk check */
                                #ifdef __FLIGHT_MODE_SUPPORT__
                                        g_phnset_cntx.curFlightMode = p->flightmode_state;
                                #endif 

                                        break;

                                    case POWER_ON_PRECHARGE:
                                    case POWER_ON_CHARGER_IN:
                           /************************************** 
                            * Always send charger-in indication
                            * to avoid fast repeating charger 
                            * in-out b4 power-on completes
                            * Lisen 04/13/2004
                           ***************************************/
                                        //mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
                                        InitializeChargingScr();
                                        if (!srv_charbat_is_charger_connect())
                                        {
                                            //QuitSystemOperation();
                                        #ifdef __COSMOS_MMI_PACKAGE__    
                                            srv_shutdown_exit_system(VAPP_DEVICE);
                                        #else
                                            srv_shutdown_exit_system(APP_CHARGER);
                                        #endif
                                        }
                                        break;

                                    case POWER_ON_ALARM:
                                    #ifdef __MMI_SUBLCD__
                                        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
                                        gdi_layer_clear(GDI_COLOR_BLACK);
                                        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
                                    #endif /* __MMI_SUBLCD__ */ 
                                        gdi_layer_clear(GDI_COLOR_BLACK);
                                        //mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);

                                        srv_reminder_pwr_on_hdlr(p);
                                        
                                        break;
                                    case POWER_ON_EXCEPTION:

                                    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                                        PhnsetSetUARTConfig((rmmi_sim_uart_setting_enum)p->dual_sim_uart_setting); 
                                    #endif
                                        break;
   
                                    #ifdef __MMI_USB_SUPPORT__
                                    case POWER_ON_USB:
                           /***************************************
                            * Because Aux task will not init in USB boot mode 
                            * Interrupt service routine for clam detection CLAM_EINT_HISR() 
                            * is not register, force the clam state to open 
                            * If Aux task is necessary in USB mode, this tircky could be removed 
                            * Robin 1209 
                            ***************************************/
                                        //mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);      
						
                                    #if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_USB_SUPPORT__)
                                    {
                                        extern void vapp_usb_launch_usbmode(void);
                                        vapp_usb_launch_usbmode();
                                    }
                                    #else
                                        #ifdef __MMI_USB_SUPPORT__
                                            mmi_usb_boot_init();
                                        #endif
                                    #endif
                           /***************************************
                            * To disable keypad tone state 
                            ***************************************/
                                        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
                                        break;
                                    #endif /* __MMI_USB_SUPPORT__ */ 

                                    default:
                                        break;
                                }

                            #ifdef __FLIGHT_MODE_SUPPORT__
                                mmi_flight_mode_power_on_ind_hdlr(p);
                            #endif

                                srv_bootup_power_on_ind_hdlr(p);
                                
                                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TASK_POWER_PROC_END, p->poweron_mode);
                            }
                                break;

                            default:
                            #ifdef __MULTI_VCARD_SUPPORT__
                                {
                                extern void vcard_app_common_hdlr(void *ilm);
                                vcard_app_common_hdlr((void*)&Message);
                                }
                            #endif
                                mmi_frm_execute_current_protocol_handler(
                                    (U16) Message.oslMsgId,
                                    (void*)Message.oslDataPtr,
                                    (int)Message.oslSrcId,
                                    (void*)&Message);
                                break;
                        }

                    }

                    OslFreeInterTaskMsg(&Message);
                    mmi_frm_invoke_post_event();
                    //#ifdef __COSMOS_MMI_PACKAGE__
                    //mmi_frm_temp_check_all_free();
                    //#endif
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TASK_MSG_HANDLE_END, Message.oslMsgId, Message.oslSrcId, Message.oslDestId);
                }   /* OslReadCircularQ(&Message) */
                //queue_node_number = msg_get_extq_messages();
                count--;
                
            /* for MRE message dispatcher */
                vm_appcomm_dispatch_msg();
            //#if defined(__MMI_TOUCH_SCREEN__) && defined(__MTK_TARGET__)
            //#ifdef __MMI_VUI_3D_CUBE_APP__
            //    if (!vadp_p2v_uc_is_in_venus())
            //#endif
            //    {
            //        /* Make sure there should be a new start for pen event when entering new screen */
            //        mmi_frm_pen_reset_context_for_new_screen();
            //    }                
            //#endif
            }
            /* for MRE message dispatcher */
            vm_appcomm_dispatch_msg();
        }     
    }
}

/*****************************************************************************
 * FUNCTION
 *  InitFramework
 * DESCRIPTION
 *  To Initialize framework,
 *  
 *  This is used to To Initialize framework,.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitFramework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (framework_initialized)
    {
        return;
    }
    framework_initialized = MMI_TRUE;
    /* 
     * Initialize events handler  
     */
    InitEvents();
    mmi_frm_init_inject_string();
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    mmi_frm_init_dump_screen_string();
#endif
    
#ifdef __MMI_FRM_HISTORY__
    /* 
     * Initialize history 
     */
    InitHistory(NULL, NULL);
#endif

    /* init the scenario(screen group) mech.  */
    mmi_frm_shell_init();

    /* initialize screen management service. (for anti-blink mechanism)*/
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__    
    mmi_frm_scr_mgm_init();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ProtocolEventHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eventID         [IN]        
 *  MsgStruct       [IN]         
 *  mod_src         [IN]        
 *  peerBuf         [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void ProtocolEventHandler(U16 eventID, void *MsgStruct, int mod_src, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ExecuteCurrProtocolHandler((U16) eventID, MsgStruct, mod_src, Message);
}


/*****************************************************************************
 * FUNCTION
 *  InitUnicodeSupport
 * DESCRIPTION
 *  Initalizes string functions for UCS2 support
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitUnicodeSupport(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This function will be invoked in charger/alarm power on, too */

#if defined (__MMI_FRAMEWORK_BACKWARD_COMPATIBLE__) || defined (__MMI_FRAMEWORK_BACKWARD_COMPATIBLE_SPEC__)
    pfnUnicodeToEncodingScheme = mmi_wc_to_ucs2;
    pfnEncodingSchemeToUnicode = mmi_ucs2_to_wc;
    pfnUnicodeStrlen = mmi_ucs2strlen;
    pfnUnicodeStrcpy = mmi_ucs2cpy;
    pfnUnicodeStrcmp = mmi_ucs2cmp;
    pfnUnicodeStrncpy = mmi_ucs2ncpy;
    pfnUnicodeStrncmp = mmi_ucs2ncmp;
    pfnUnicodeStrcat = mmi_ucs2cat;
    pfnUnicodeStrncat = mmi_ucs2ncat;
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
}


/*****************************************************************************
 * FUNCTION
 *  InitNvramData
 * DESCRIPTION
 *  Allows the applications to read their NVRAM data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitNvramData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* make sure the cache buffer is large enough */
    MMI_ASSERT((mmi_rp_mmi_cache_get_byte_number() * DS_BYTE) <= NVRAM_CACHE_SIZE);
    MMI_ASSERT((mmi_rp_mmi_cache_get_short_number() * DS_SHORT) <= NVRAM_CACHE_SIZE);
    MMI_ASSERT((mmi_rp_mmi_cache_get_double_number() * DS_DOUBLE) <= NVRAM_CACHE_SIZE);
}



/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  InitEventHandlersBeforePowerOn
 * DESCRIPTION
 *  Init event handlers before power on indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void InitEventHandlersBeforePowerOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitEvents();
    SetProtocolEventHandler(srv_fmgri_device_ready_hdlr, MSG_ID_MMI_FMT_CARD_READY_IND);
    SetProtocolEventHandler(srv_gpio_detect_ind_hdlr, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    SetProtocolEventHandler(srv_charbat_status_ind_hdlr, MSG_ID_MMI_EQ_BATTERY_STATUS_IND);
#ifdef __MMI_USB_SUPPORT__
    SetProtocolEventHandler(srv_usb_detect_ind_hdlr, MSG_ID_MMI_EQ_USBDETECT_IND);
#endif 
   // srv_reminder_init(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_check_is_valid_msg
 * DESCRIPTION
 *  Check if the follow message is useful
 *  If the successive messages are MSG_ID_TIMER_EXPIRY,
 *  only one message will be usegful. We will keep only one
 *  MSG_ID_TIMER_EXPIRY in the queue
 * PARAMETERS
 *  base        [IN]     
 *  msg         [IN]     
 * RETURNS
 *  0 - the message is invalid, and discard the message
 *  1 - the message is vaild
 *****************************************************************************/
static U8 mmi_frm_check_is_valid_msg(MYQUEUE *base, MYQUEUE *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((base != NULL) && (msg != NULL) && (base->msg_id == msg->msg_id))
    {
        switch (base->msg_id)
        {
            case MSG_ID_TIMER_EXPIRY:
            {
                kal_uint16 msg_len = 0;
                stack_timer_struct *base_timer_ptr;
                stack_timer_struct *timer_ptr;

                base_timer_ptr = (stack_timer_struct*) get_local_para_ptr(base->oslDataPtr, &msg_len);
                timer_ptr = (stack_timer_struct*) get_local_para_ptr(msg->oslDataPtr, &msg_len);
                if (base_timer_ptr == timer_ptr)
                {
                    stack_is_time_out_valid(base_timer_ptr);
                    stack_process_time_out(base_timer_ptr);
                    /* msg is invalid, can discard it */
                    return 0;
                }
            }
                break;
                
            case MSG_ID_SUPC_MMI_WIFI_CURR_AP_INFO_IND:
            {
                return 0;
            }

            default:
                break;
        }
    }
    /* msg is valid, can't discard */
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  InitHardwareEvents
 * DESCRIPTION
 *  Initialize the ProtocolEvents
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitHardwareEvents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_key_handle, MSG_ID_MMI_EQ_KEYPAD_DETECT_IND);
    SetProtocolEventHandler(mmi_frm_key_evt_report_ind, MSG_ID_MMI_AT_KEYPAD_EVENT_ACT_IND);

    SetProtocolEventHandler(L4SetClockRSP, MSG_ID_MMI_EQ_SET_RTC_TIME_RSP);
    SetProtocolEventHandler(L4GetClockTimeRSP, MSG_ID_MMI_EQ_GET_RTC_TIME_RSP);
    SetProtocolEventHandler(DateTimerIndication, MSG_ID_MMI_EQ_CLOCK_TICK_IND);
   
#ifdef __MMI_USB_SUPPORT__
    SetProtocolEventHandler(srv_usb_detect_ind_hdlr, MSG_ID_MMI_EQ_USBDETECT_IND);
#endif 
   
    /* volume change indication from L4 */
    /* SetProtocolEventHandler( VolumeChangeIndication, MSG_ID_MMI_EQ_VOLUME_CHANGE_IND); */

#ifdef __MMI_IRDA_SUPPORT__
    mmi_irda_init_protocol_event();
#endif 

	srv_gpio_set_event_hdlr();

    SetProtocolEventHandler((PsFuncPtr)gdc_msg_dispatch, MSG_ID_MMI_GDC_IMG_CODEC_CALLBACK_IND);
    SetProtocolEventHandler((PsFuncPtr)gdc_imgdec_callback_dispatch, MSG_ID_MMI_GDC_IMGDEC_CALLBACK_IND);

#if defined(__KJX_AT_APP__)
	rmmi_write_to_uart((kal_uint8*)"PowerOn", strlen("PowerOn"), KAL_TRUE);
	SetProtocolEventHandler(ATCommand_Set_Handler, MSG_ID_MMI_AT_COMMAND_SET_REQ);
#endif/*__KJX_AT_APP__*/

    gdi_anim_mmi_init();
}


/*****************************************************************************
 * FUNCTION
 *  initialize_UI_demo
 * DESCRIPTION
 *  Initialize UI environment
 *
 *  Remark: this function may be executed more than one times for special poweron
 *          mode (e.g. Alarm poweron, Charger poweron, USB poweron)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_UI_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL ui_initialized = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ui_initialized)
    {
		return;
    }
    ui_initialized = MMI_TRUE;

    mmi_frm_appmem_init();
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_temp_mem_init();
#endif

#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    gui_sse_init();
#endif

    dm_init();
    wgui_init();
    initialize_category_screens();

#ifndef __MTK_TARGET__
    {
        extern void mmi_res_otf_init(void);
#ifdef __MODIS_PLUGIN__
        extern void mmi_plug_in_init(void);
#endif /*__MODIS_PLUGIN__*/

        mmi_res_otf_init();
#ifdef __MODIS_PLUGIN__
        mmi_plug_in_init();
#endif /*__MODIS_PLUGIN__*/
    }
#endif /* __MTK_TARGET__ */

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_PRECHARGE)
    {
        mmi_pen_init();
        mmi_pen_enable();
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

    wgui_status_icon_bar_set_icon_display(STATUS_ICON_BATTERY_STRENGTH);
#ifdef __MMI_SUBLCD__
    if (mmi_charbat_show_sublcd_battery_status_icon())
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
#endif
    
    wgui_status_icon_bar_update();

#if defined(__GGT_TASK__)
{      
    #include "..\ggt\inc\GGT_host.h"
    extern void GT_WRT_main(void);
    StartTimer(GGT_TIMER_ID_BOOTUP, 8000, GT_WRT_main);
}
#endif
#if defined(__CITY_WRITE_UART_PORT1__)||defined(__CITY_EASY_OBD__)
{
   extern void city_obd_uart_init(void);
   city_obd_uart_init();
}
#endif

}


/*****************************************************************************
 * FUNCTION
 *  terminate_UI_demo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void terminate_UI_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ExitCategoryFunction != NULL)
    {
        ExitCategoryFunction();
    }
    if (SUBLCD_ExitCategoryFunction != NULL)
    {
        SUBLCD_ExitCategoryFunction();
    }
    gui_hide_animations();
}


