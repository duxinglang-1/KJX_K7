#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_list_int.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   List internals.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _bam_list_int_h

#define _bam_list_int_h

#ifndef _bam_list_h
#error Do not use the internal list implementation directly! Include bam_list.h instead.

#endif /* _bam_list_h */ 

/*********************************************************************
 * Singly linked list internals
 ********************************************************************/

#define BAM_LIST_GET_HEAD_S(list) ((list)->_sl_head)
#define BAM_LIST_GET_NEXT_S(elem) ((elem)->_sl_next)
#define BAM_LIST_SIZE_INCR_S(list)
#define BAM_LIST_SIZE_DECR_S(list)

#define BAM_LIST_GET_HEAD_SN(list) ((list)->_snl_head)
#define BAM_LIST_GET_NEXT_SN(elem) ((elem)->_snl_next)
#define BAM_LIST_GET_SIZE_SN(list) ((list)->_snl_size)
#define BAM_LIST_SIZE_INCR_SN(list) BAM_LIST_GET_SIZE_SN(list)++
#define BAM_LIST_SIZE_DECR_SN(list) BAM_LIST_GET_SIZE_SN(list)--

#define BAM_LIST_PUSH_HEAD_S(list, elem, sfx)                              \
    do {                                                                   \
    BAM_LIST_GET_NEXT_##sfx(elem) = BAM_LIST_GET_HEAD_##sfx(list);         \
    BAM_LIST_GET_HEAD_##sfx(list) = (elem);                                \
    BAM_LIST_SIZE_INCR_##sfx(list);                                        \
    } while (0)

#define BAM_LIST_POP_HEAD_S(list, elem, sfx)                               \
    do {                                                                   \
    (elem) = BAM_LIST_GET_HEAD_##sfx(list);                                \
    if (elem) {                                                            \
    BAM_LIST_GET_HEAD_##sfx(list) = BAM_LIST_GET_NEXT_##sfx(elem);         \
    BAM_LIST_SIZE_DECR_##sfx(list);                                        \
    }                                                                      \
    } while (0)

#define BAM_LIST_APPEND_S(list, prev, elem, sfx)                           \
    do {                                                                   \
    BAM_LIST_GET_NEXT_##sfx(elem) = BAM_LIST_GET_NEXT_##sfx(prev);         \
    BAM_LIST_GET_NEXT_##sfx(prev) = (elem);                                \
    BAM_LIST_SIZE_INCR_##sfx(list);                                        \
    } while (0)

#define BAM_LIST_REMOVE_S(list, prev, elem, sfx)                           \
    do {                                                                   \
    (elem) = BAM_LIST_GET_NEXT_##sfx(prev);                                \
    BAM_LIST_GET_NEXT_##sfx(prev) = BAM_LIST_GET_NEXT_##sfx(elem);         \
    BAM_LIST_SIZE_DECR_##sfx(list);                                        \
    } while (0)

#define BAM_LIST_COPY_S(to_list, from_list, sfx)                           \
    do {                                                                   \
    BAM_LIST_GET_HEAD_##sfx(to_list) = BAM_LIST_GET_HEAD_##sfx(from_list); \
    BAM_LIST_GET_SIZE_##sfx(to_list) = BAM_LIST_GET_SIZE_##sfx(from_list); \
    } while (0)

/*********************************************************************
 * Doubly linked list internals
 ********************************************************************/

#define BAM_LIST_GET_HEAD_D(list) ((list)->_dl_head)
#define BAM_LIST_GET_TAIL_D(list) ((list)->_dl_tail)
#define BAM_LIST_GET_PREV_D(elem) ((elem)->_dl_prev)
#define BAM_LIST_GET_NEXT_D(elem) ((elem)->_dl_next)
#define BAM_LIST_SIZE_INCR_D(list)
#define BAM_LIST_SIZE_DECR_D(list)

#define BAM_LIST_GET_SIZE_DN(list) ((list)->_dnl_size)
#define BAM_LIST_GET_HEAD_DN(list) ((list)->_dnl_head)
#define BAM_LIST_GET_TAIL_DN(list) ((list)->_dnl_tail)
#define BAM_LIST_GET_PREV_DN(elem) ((elem)->_dnl_prev)
#define BAM_LIST_GET_NEXT_DN(elem) ((elem)->_dnl_next)
#define BAM_LIST_SIZE_INCR_DN(list) BAM_LIST_GET_SIZE_DN(list)++
#define BAM_LIST_SIZE_DECR_DN(list) BAM_LIST_GET_SIZE_DN(list)--

#define BAM_LIST_PUSH_HEAD_D(list, elem, sfx)                           \
    do {                                                                \
    BAM_LIST_GET_NEXT_##sfx(elem) = BAM_LIST_GET_HEAD_##sfx(list);      \
    BAM_LIST_GET_PREV_##sfx(elem) = NULL;                               \
    if (BAM_LIST_GET_HEAD_##sfx(list))                                  \
    BAM_LIST_GET_PREV_##sfx(BAM_LIST_GET_HEAD_##sfx(list)) = (elem);    \
    else BAM_LIST_GET_TAIL_##sfx(list) = (elem);                        \
    BAM_LIST_GET_HEAD_##sfx(list) = (elem);                             \
    BAM_LIST_SIZE_INCR_##sfx(list);                                     \
    } while (0)

#define BAM_LIST_POP_HEAD_D(list, elem, sfx)                            \
    do {                                                                \
    (elem) = BAM_LIST_GET_HEAD_##sfx(list);                             \
    if (elem) {                                                         \
    BAM_LIST_GET_HEAD_##sfx(list) = BAM_LIST_GET_NEXT_##sfx(elem);      \
    if (BAM_LIST_GET_NEXT_##sfx(elem))                                  \
    BAM_LIST_GET_PREV_##sfx(BAM_LIST_GET_NEXT_##sfx(elem)) = NULL;      \
    else BAM_LIST_GET_TAIL_##sfx(list) = NULL;                          \
    BAM_LIST_SIZE_DECR_##sfx(list);                                     \
    }                                                                   \
    } while (0)

#define BAM_LIST_PUSH_TAIL_D(list, elem, sfx)                           \
    do {                                                                \
    BAM_LIST_GET_PREV_##sfx(elem) = BAM_LIST_GET_TAIL_##sfx(list);      \
    BAM_LIST_GET_NEXT_##sfx(elem) = NULL;                               \
    if (BAM_LIST_GET_TAIL_##sfx(list))                                  \
    BAM_LIST_GET_NEXT_##sfx(BAM_LIST_GET_TAIL_##sfx(list)) = (elem);    \
    else BAM_LIST_GET_HEAD_##sfx(list) = (elem);                        \
    BAM_LIST_GET_TAIL_##sfx(list) = (elem);                             \
    BAM_LIST_SIZE_INCR_##sfx(list);                                     \
    } while (0)

#define BAM_LIST_POP_TAIL_D(list, elem, sfx)                            \
    do {                                                                \
    (elem) = BAM_LIST_GET_TAIL_##sfx(list);                             \
    if (elem) {                                                         \
    BAM_LIST_GET_TAIL_##sfx(list) = BAM_LIST_GET_PREV_##sfx(elem);      \
    if (BAM_LIST_GET_PREV_##sfx(elem))                                  \
    BAM_LIST_GET_NEXT_##sfx(BAM_LIST_GET_PREV_##sfx(elem)) = NULL;      \
    else BAM_LIST_GET_HEAD_##sfx(list) = NULL;                          \
    BAM_LIST_SIZE_DECR_##sfx(list);                                     \
    }                                                                   \
    } while (0)

#define BAM_LIST_APPEND_D(list, prev, elem, sfx)                        \
    do {                                                                \
    BAM_LIST_GET_NEXT_##sfx(elem) = BAM_LIST_GET_NEXT_##sfx(prev);      \
    BAM_LIST_GET_PREV_##sfx(elem) = (prev);                             \
    if (BAM_LIST_GET_NEXT_##sfx(prev))                                  \
    BAM_LIST_GET_PREV_##sfx(BAM_LIST_GET_NEXT_##sfx(prev)) = (elem);    \
    else BAM_LIST_GET_TAIL_##sfx(list) = (elem);                        \
    BAM_LIST_GET_NEXT_##sfx(prev) = (elem);                             \
    BAM_LIST_SIZE_INCR_##sfx(list);                                     \
    } while (0)

#define BAM_LIST_PREPEND_D(list, next, elem, sfx)                       \
    do {                                                                \
    BAM_LIST_GET_PREV_##sfx(elem) = BAM_LIST_GET_PREV_##sfx(next);      \
    BAM_LIST_GET_NEXT_##sfx(elem) = (next);                             \
    if (BAM_LIST_GET_PREV_##sfx(next))                                  \
    BAM_LIST_GET_NEXT_##sfx(BAM_LIST_GET_PREV_##sfx(next)) = (elem);    \
    else BAM_LIST_GET_HEAD_##sfx(list) = (elem);                        \
    BAM_LIST_GET_PREV_##sfx(next) = (elem);                             \
    BAM_LIST_SIZE_INCR_##sfx(list);                                     \
    } while (0)

#define BAM_LIST_REMOVE_D(list, elem, sfx)                              \
    do {                                                                \
    if (BAM_LIST_GET_PREV_##sfx(elem))                                  \
    BAM_LIST_GET_NEXT_##sfx(BAM_LIST_GET_PREV_##sfx(elem)) =            \
    BAM_LIST_GET_NEXT_##sfx(elem);                                      \
    else BAM_LIST_GET_HEAD_##sfx(list) = BAM_LIST_GET_NEXT_##sfx(elem); \
    if (BAM_LIST_GET_NEXT_##sfx(elem))                                  \
    BAM_LIST_GET_PREV_##sfx(BAM_LIST_GET_NEXT_##sfx(elem)) =            \
    BAM_LIST_GET_PREV_##sfx(elem);                                      \
    else BAM_LIST_GET_TAIL_##sfx(list) = BAM_LIST_GET_PREV_##sfx(elem); \
    BAM_LIST_SIZE_DECR_##sfx(list);                                     \
    } while (0)

/*********************************************************************
 * Circularly linked list internals
 ********************************************************************/

#define BAM_LIST_GET_HEAD_C(list) ((list)->_cl_head)
#define BAM_LIST_GET_TAIL_C(list) (BAM_LIST_GET_HEAD_C(list) ? \
    BAM_LIST_GET_PREV_C(BAM_LIST_GET_HEAD_C(list)) : NULL)

#define BAM_LIST_GET_PREV_C(elem) ((elem)->_cl_prev)
#define BAM_LIST_GET_NEXT_C(elem) ((elem)->_cl_next)
#define BAM_LIST_SIZE_INCR_C(list)
#define BAM_LIST_SIZE_DECR_C(list)

#define BAM_LIST_GET_SIZE_CN(list) ((list)->_cnl_size)
#define BAM_LIST_GET_HEAD_CN(list) ((list)->_cnl_head)
#define BAM_LIST_GET_TAIL_CN(list) (BAM_LIST_GET_HEAD_CN(list) ? \
    BAM_LIST_GET_PREV_CN(BAM_LIST_GET_HEAD_CN(list)) : NULL)

#define BAM_LIST_GET_PREV_CN(elem) ((elem)->_cnl_prev)
#define BAM_LIST_GET_NEXT_CN(elem) ((elem)->_cnl_next)
#define BAM_LIST_SIZE_INCR_CN(list) BAM_LIST_GET_SIZE_CN(list)++
#define BAM_LIST_SIZE_DECR_CN(list) BAM_LIST_GET_SIZE_CN(list)--

#define BAM_LIST_PUSH_HEAD_C(list, elem, sfx)                          \
    do {                                                               \
    if (BAM_LIST_GET_HEAD_##sfx(list))                                 \
    BAM_LIST_ELEM_PREPEND_C(BAM_LIST_GET_HEAD_##sfx(list), elem, sfx); \
    else {                                                             \
    BAM_LIST_GET_PREV_##sfx(elem) = (elem);                            \
    BAM_LIST_GET_NEXT_##sfx(elem) = (elem);                            \
    }                                                                  \
    BAM_LIST_GET_HEAD_##sfx(list) = (elem);                            \
    BAM_LIST_SIZE_INCR_##sfx(list);                                    \
    } while (0)

#define BAM_LIST_POP_HEAD_C(list, elem, sfx)                           \
    do {                                                               \
    (elem) = BAM_LIST_GET_HEAD_##sfx(list);                            \
    if (elem) {                                                        \
    if (BAM_LIST_GET_NEXT_##sfx(elem) == (elem))                       \
    BAM_LIST_GET_HEAD_##sfx(list) = NULL;                              \
    else {                                                             \
    BAM_LIST_ELEM_DETACH_C(elem, sfx);                                 \
    BAM_LIST_GET_HEAD_##sfx(list) = BAM_LIST_GET_NEXT_##sfx(elem);     \
    }                                                                  \
    BAM_LIST_SIZE_DECR_##sfx(list);                                    \
    }                                                                  \
    } while (0)

#define BAM_LIST_PUSH_TAIL_C(list, elem, sfx)                          \
    do {                                                               \
    if (BAM_LIST_GET_HEAD_##sfx(list))                                 \
    BAM_LIST_ELEM_PREPEND_C(BAM_LIST_GET_HEAD_##sfx(list), elem, sfx); \
    else {                                                             \
    BAM_LIST_GET_PREV_##sfx(elem) = (elem);                            \
    BAM_LIST_GET_NEXT_##sfx(elem) = (elem);                            \
    BAM_LIST_GET_HEAD_##sfx(list) = (elem);                            \
    }                                                                  \
    BAM_LIST_SIZE_INCR_##sfx(list);                                    \
    } while (0)

#define BAM_LIST_POP_TAIL_C(list, elem, sfx)                           \
    do {                                                               \
    (elem) = BAM_LIST_GET_HEAD_##sfx(list);                            \
    if (elem) {                                                        \
    (elem) = BAM_LIST_GET_PREV_##sfx(elem);                            \
    if (BAM_LIST_GET_HEAD_##sfx(list) == (elem))                       \
    BAM_LIST_GET_HEAD_##sfx(list) = NULL;                              \
    else {                                                             \
    BAM_LIST_ELEM_DETACH_C(elem, sfx);                                 \
    BAM_LIST_GET_HEAD_##sfx(list) = BAM_LIST_GET_NEXT_##sfx(elem);     \
    }                                                                  \
    BAM_LIST_SIZE_DECR_##sfx(list);                                    \
    }                                                                  \
    } while (0)

#define BAM_LIST_APPEND_C(list, prev, elem, sfx)                       \
    do {                                                               \
    BAM_LIST_ELEM_APPEND_C(prev, elem, sfx);                           \
    BAM_LIST_SIZE_INCR_##sfx(list);                                    \
    } while (0)

#define BAM_LIST_PREPEND_C(list, next, elem, sfx)                      \
    do {                                                               \
    BAM_LIST_ELEM_PREPEND_C(next, elem, sfx);                          \
    if (BAM_LIST_GET_TAIL_##sfx(list) == (elem))                       \
    BAM_LIST_GET_HEAD_##sfx(list) = (elem);                            \
    BAM_LIST_SIZE_INCR_##sfx(list);                                    \
    } while (0)

#define BAM_LIST_REMOVE_C(list, elem, sfx)                             \
    do {                                                               \
    BAM_LIST_ELEM_DETACH_C(elem, sfx);                                 \
    if (BAM_LIST_GET_HEAD_##sfx(list) == (elem)) {                     \
    if (BAM_LIST_GET_NEXT_##sfx(elem) != (elem))                       \
    BAM_LIST_GET_HEAD_##sfx(list) = BAM_LIST_GET_NEXT_##sfx(elem);     \
    else BAM_LIST_GET_HEAD_##sfx(list) = NULL;                         \
    }                                                                  \
    BAM_LIST_SIZE_DECR_##sfx(list);                                    \
    } while (0)

#define BAM_LIST_ELEM_PREPEND_C(next, elem, sfx)                       \
    do {                                                               \
    BAM_LIST_GET_PREV_##sfx(elem) = BAM_LIST_GET_PREV_##sfx(next);     \
    BAM_LIST_GET_NEXT_##sfx(elem) = (next);                            \
    BAM_LIST_GET_NEXT_##sfx(BAM_LIST_GET_PREV_##sfx(next)) = (elem);   \
    BAM_LIST_GET_PREV_##sfx(next) = (elem);                            \
    } while (0)

#define BAM_LIST_ELEM_APPEND_C(prev, elem, sfx)                        \
    do {                                                               \
    BAM_LIST_GET_NEXT_##sfx(elem) = BAM_LIST_GET_NEXT_##sfx(prev);     \
    BAM_LIST_GET_PREV_##sfx(elem) = (prev);                            \
    BAM_LIST_GET_PREV_##sfx(BAM_LIST_GET_NEXT_##sfx(prev)) = (elem);   \
    BAM_LIST_GET_NEXT_##sfx(prev) = (elem);                            \
    } while (0)

#define BAM_LIST_ELEM_DETACH_C(elem, sfx)                              \
    do {                                                               \
    BAM_LIST_GET_PREV_##sfx(BAM_LIST_GET_NEXT_##sfx(elem)) =           \
    BAM_LIST_GET_PREV_##sfx(elem);                                     \
    BAM_LIST_GET_NEXT_##sfx(BAM_LIST_GET_PREV_##sfx(elem)) =           \
    BAM_LIST_GET_NEXT_##sfx(elem);                                     \
    } while (0)

#endif /* _bam_list_int_h */ 


#endif /*OBIGO_Q03C_BROWSER*/