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
 *  PlstSrvpls.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  player list service
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PLAY_LIST_SERVICE_DEF_H__
#define __PLAY_LIST_SERVICE_DEF_H__

typedef enum
{
    SRV_PLST_GET_MEDIA_ID,
    SRV_PLST_GET_COUNT,
    SRV_PLST_GET_HINT_COUNT,
    SRV_PLST_GET_ACTIVE_LIST_COUNT,
    SRV_PLST_GET_ARTIST_MEDIA_COUNT_BY_ID,
    SRV_PLST_GET_DETAILS,
    SRV_PLST_GET_TITLE,
    SRV_PLST_GET_PATH,
    SRV_PLST_GET_ARTWORK,
    SRV_PLST_GET_ARTWORK_BY_ID,
    SRV_PLST_GET_DETAILS_UPDATE,
    SRV_PLST_GET_ACTIVE_CURR,
    SRV_PLST_GET_ACTIVE_PREV,
    SRV_PLST_GET_ACTIVE_NEXT,
    SRV_PLST_GET_ACTIVE_AUTO,
    SRV_PLST_GET_ITEM_ID,
    SRV_PLST_UPDATE_ARTWORK,
    SRV_PLST_GET_ARTWORK_PARSER_PATH_BY_ID,
    SRV_PLST_GET_DETAILS_BY_FILTER,
    
    SRV_PLST_GET_ENUM_END
}srv_plst_get_data_enum;

#endif /* __PLAY_LIST_SERVICE_DEF_H__ */
