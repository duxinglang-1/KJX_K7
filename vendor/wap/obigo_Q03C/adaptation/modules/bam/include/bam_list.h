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
 *   bam_list.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   A generic list implementation.
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

#ifndef _bam_list_h

#define _bam_list_h

#include "bam_list_int.h"

/*********************************************************************
 * Singly linked list
 ********************************************************************/

/**
 *  Declare a list type.
 *  @param type  The type of the data to be carried.
 */
#define BAM_SLIST_TYPE(type) \
    struct {                 \
        type *_sl_head;      \
    }

/**
 *  Declare list element members.
 *  @param type  The type of the data to be carried.
 */
#define BAM_SLIST_LINK(type) type *_sl_next

/**
 *  Static list initializer.
 */
#define BAM_SLIST_STATIC_INIT {NULL}

/**
 *  Initialize the list dynamically.
 *  @param list  A pointer to the list.
 */
#define BAM_SLIST_INIT(list)                \
    do {                                    \
        BAM_SLIST_GET_HEAD(list) = NULL;    \
    } while (0)

/**
 *  Initialize an array of lists.
 *  @param list_vec  The list array.
 *  @param len       The size of the array.
 */
#define BAM_SLIST_VEC_INIT(list_vec, len) \
    memset(list_vec, 0, (len)*sizeof(*(list_vec)))

/**
 *  Get the list head
 */
#define BAM_SLIST_GET_HEAD(list) BAM_LIST_GET_HEAD_S(list)

/**
 *  Get the next list element
 */
#define BAM_SLIST_GET_NEXT(elem) BAM_LIST_GET_NEXT_S(elem)

/**
 *  Push a new element onto the head of the list
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_SLIST_PUSH_HEAD(list, elem) BAM_LIST_PUSH_HEAD_S(list, elem, S)

/**
 *  Pop the head of the list
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_SLIST_POP_HEAD(list, elem) BAM_LIST_POP_HEAD_S(list, elem, S)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the previous element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_SLIST_APPEND(list, prev, elem) BAM_LIST_APPEND_S(list, prev, elem, S)

/**
 *  Remove an element from an arbitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the previous element.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_SLIST_REMOVE(list, prev, elem) BAM_LIST_REMOVE_S(list, prev, elem, S)

/*********************************************************************
 * Singly linked list with counter
 ********************************************************************/

/**
 *  Declare a list type.
 *  @param type  The type of the data to be carried.
 */
#define BAM_SNLIST_TYPE(type)   \
    struct {                    \
        type *_snl_head;        \
        int   _snl_size;        \
    }

/**
 *  Declare list element members.
 *  @param type  The type of the data to be carried.
 */
#define BAM_SNLIST_LINK(type) type *_snl_next

/**
 *  Static list initializer.
 */
#define BAM_SNLIST_STATIC_INIT {NULL, 0}

/**
 *  Initialize the list dynamically.
 *  @param list  A pointer to the list.
 */
#define BAM_SNLIST_INIT(list)               \
    do {                                    \
        BAM_SNLIST_GET_HEAD(list) = NULL;   \
        BAM_SNLIST_GET_SIZE(list) = 0;      \
    } while (0)

/**
 *  Initialize an array of lists.
 *  @param list_vec  The list array.
 *  @param len       The size of the array.
 */
#define BAM_SNLIST_VEC_INIT(list_vec, len) BAM_SLIST_VEC_INIT(list_vec, len)

/**
 *  Get the number of elements in the list.
 *  If BAM_SLIST_SIZE_ENABLE is undefined, 0 is returned.
 */
#define BAM_SNLIST_GET_SIZE(list) BAM_LIST_GET_SIZE_SN(list)

/**
 *  Get the list head
 */
#define BAM_SNLIST_GET_HEAD(list) BAM_LIST_GET_HEAD_SN(list)

/**
 *  Get the next list element
 */
#define BAM_SNLIST_GET_NEXT(elem) BAM_LIST_GET_NEXT_SN(elem)

/**
 *  Push a new element onto the head of the list
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_SNLIST_PUSH_HEAD(list, elem) BAM_LIST_PUSH_HEAD_S(list, elem, SN)

/**
 *  Pop the head of the list
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_SNLIST_POP_HEAD(list, elem) BAM_LIST_POP_HEAD_S(list, elem, SN)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the previous element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_SNLIST_APPEND(list, prev, elem) BAM_LIST_APPEND_S(list, prev, elem, SN)

/**
 *  Remove an element from an arbitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the previous element.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_SNLIST_REMOVE(list, prev, elem) BAM_LIST_REMOVE_S(list, prev, elem, SN)

/**
 *  Copy list head and list size.
 *  @param to_list    A pointer to the list to copy to.
 *  @param from_list  A pointer to the list to copy from.
 */
#define BAM_SNLIST_COPY(to_list, from_list) BAM_LIST_COPY_S(to_list, from_list, SN)

/*********************************************************************
 * Doubly linked list
 ********************************************************************/

/**
 *  Declare a list type.
 *  @param type  The type of the data to be carried.
 */
#define BAM_DLIST_TYPE(type)    \
    struct {                    \
        type *_dl_head;         \
        type *_dl_tail;         \
    }

/**
 *  Declare list element members.
 *  @param type  The type of the data to be carried.
 */
#define BAM_DLIST_LINK(type) type *_dl_prev; \
    type *_dl_next

/**
 *  Static initializer
 */
#define BAM_DLIST_STATIC_INIT {NULL, NULL}

/**
 *  Initialize the list dynamically.
 *  @param list  A pointer to the list.
 */
#define BAM_DLIST_INIT(list)                \
    do {                                    \
        BAM_DLIST_GET_HEAD(list) = NULL;    \
        BAM_DLIST_GET_TAIL(list) = NULL;    \
    } while (0)

/**
 *  Initialize an array of lists.
 *  @param list_vec  The list array.
 *  @param len       The size of the array.
 */
#define BAM_DLIST_VEC_INIT(list_vec, len) BAM_SLIST_VEC_INIT(list_vec, len)

/**
 *  Get the list head
 */
#define BAM_DLIST_GET_HEAD(list) BAM_LIST_GET_HEAD_D(list)

/**
 *  Get the list tail
 */
#define BAM_DLIST_GET_TAIL(list) BAM_LIST_GET_TAIL_D(list)

/**
 *  Get the previous list element
 */
#define BAM_DLIST_GET_PREV(elem) BAM_LIST_GET_PREV_D(elem)

/**
 *  Get the next list element
 */
#define BAM_DLIST_GET_NEXT(elem) BAM_LIST_GET_NEXT_D(elem)

/**
 *  Push a new element onto the head of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_DLIST_PUSH_HEAD(list, elem) BAM_LIST_PUSH_HEAD_D(list, elem, D)

/**
 *  Pop the head of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_DLIST_POP_HEAD(list, elem) BAM_LIST_POP_HEAD_D(list, elem, D)

/**
 *  Push a new element onto the tail of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_DLIST_PUSH_TAIL(list, elem) BAM_LIST_PUSH_TAIL_D(list, elem, D)

/**
 *  Pop the tail of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_DLIST_POP_TAIL(list, elem) BAM_LIST_POP_TAIL_D(list, elem, D)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the previous element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_DLIST_APPEND(list, prev, elem) BAM_LIST_APPEND_D(list, prev, elem, D)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param next  A pointer to the next element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_DLIST_PREPEND(list, next, elem) BAM_LIST_PREPEND_D(list, next, elem, D)

/**
 *  Remove an element from an arbitrary position.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be removed.
 */
#define BAM_DLIST_REMOVE(list, elem) BAM_LIST_REMOVE_D(list, elem, D)

/*********************************************************************
 * Doubly linked list with counter
 ********************************************************************/

/**
 *  Declare a list type.
 *  @param type  The type of the data to be carried.
 */
#define BAM_DNLIST_TYPE(type)   \
    struct {                    \
        type *_dnl_head;        \
        type *_dnl_tail;        \
        int   _dnl_size;        \
    }

/**
 *  Declare list element members.
 *  @param type  The type of the data to be carried.
 */
#define BAM_DNLIST_LINK(type) type *_dnl_prev; \
    type *_dnl_next
/**
 *  Static initializer
 */
#define BAM_DNLIST_STATIC_INIT {NULL, NULL, 0}

/**
 *  Initialize the list dynamically.
 *  @param list  A pointer to the list.
 */
#define BAM_DNLIST_INIT(list)               \
    do {                                    \
        BAM_DNLIST_GET_HEAD(list) = NULL;   \
        BAM_DNLIST_GET_TAIL(list) = NULL;   \
        BAM_DNLIST_GET_SIZE(list) = 0;      \
    } while (0)

/**
 *  Initialize an array of lists.
 *  @param list_vec  The list array.
 *  @param len       The size of the array.
 */
#define BAM_DNLIST_VEC_INIT(list_vec, len) BAM_SLIST_VEC_INIT(list_vec, len)

/**
 *  Get the number of elements in the list.
 */
#define BAM_DNLIST_GET_SIZE(list) BAM_LIST_GET_SIZE_DN(list)

/**
 *  Get the list head
 */
#define BAM_DNLIST_GET_HEAD(list) BAM_LIST_GET_HEAD_DN(list)

/**
 *  Get the list tail
 */
#define BAM_DNLIST_GET_TAIL(list) BAM_LIST_GET_TAIL_DN(list)

/**
 *  Get the previous list element
 */
#define BAM_DNLIST_GET_PREV(elem) BAM_LIST_GET_PREV_DN(elem)

/**
 *  Get the next list element
 */
#define BAM_DNLIST_GET_NEXT(elem) BAM_LIST_GET_NEXT_DN(elem)

/**
 *  Push a new element onto the head of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_DNLIST_PUSH_HEAD(list, elem) BAM_LIST_PUSH_HEAD_D(list, elem, DN)

/**
 *  Pop the head of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_DNLIST_POP_HEAD(list, elem) BAM_LIST_POP_HEAD_D(list, elem, DN)

/**
 *  Push a new element onto the tail of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_DNLIST_PUSH_TAIL(list, elem) BAM_LIST_PUSH_TAIL_D(list, elem, DN)

/**
 *  Pop the tail of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_DNLIST_POP_TAIL(list, elem) BAM_LIST_POP_TAIL_D(list, elem, DN)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the previous element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_DNLIST_APPEND(list, prev, elem) BAM_LIST_APPEND_D(list, prev, elem, DN)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param next  A pointer to the next element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_DNLIST_PREPEND(list, next, elem) BAM_LIST_PREPEND_D(list, next, elem, DN)

/**
 *  Remove an element from an arbitrary position.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be removed.
 */
#define BAM_DNLIST_REMOVE(list, elem) BAM_LIST_REMOVE_D(list, elem, DN)

/*********************************************************************
 * Circularly linked list
 ********************************************************************/

/**
 *  Declare a list type.
 *  @param type  The type of the data to be carried.
 */
#define BAM_CLIST_TYPE(type)    \
    struct {                    \
        type *_cl_head;         \
    }

/**
 *  Declare list element members.
 *  @param type  The type of the data to be carried.
 */
#define BAM_CLIST_LINK(type) type *_cl_prev; \
    type *_cl_next
/**
 *  Static initializer
 */
#define BAM_CLIST_STATIC_INIT {NULL}

/**
 *  Initialize the list dynamically.
 *  @param list  A pointer to the list.
 */
#define BAM_CLIST_INIT(list)            \
    do {                                \
        BAM_CLIST_GET_HEAD(list) = NULL;\
    } while (0)

/**
 *  Initialize an array of lists.
 *  @param list_vec  The list array.
 *  @param len       The size of the array.
 */
#define BAM_CLIST_VEC_INIT(list_vec, len) BAM_SLIST_VEC_INIT(list_vec, len)

/**
 *  Get the list head
 */
#define BAM_CLIST_GET_HEAD(list) BAM_LIST_GET_HEAD_C(list)

/**
 *  Get the list tail
 */
#define BAM_CLIST_GET_TAIL(list) BAM_LIST_GET_TAIL_C(list)

/**
 *  Get the previous list element
 */
#define BAM_CLIST_GET_PREV(elem) BAM_LIST_GET_PREV_C(elem)

/**
 *  Get the next list element
 */
#define BAM_CLIST_GET_NEXT(elem) BAM_LIST_GET_NEXT_C(elem)

/**
 *  Push a new element onto the head of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_CLIST_PUSH_HEAD(list, elem) BAM_LIST_PUSH_HEAD_C(list, elem, C)

/**
 *  Pop the head of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_CLIST_POP_HEAD(list, elem) BAM_LIST_POP_HEAD_C(list, elem, C)

/**
 *  Push a new element onto the tail of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_CLIST_PUSH_TAIL(list, elem) BAM_LIST_PUSH_TAIL_C(list, elem, C)

/**
 *  Pop the tail of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_CLIST_POP_TAIL(list, elem) BAM_LIST_POP_TAIL_C(list, elem, C)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the previous element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_CLIST_APPEND(list, prev, elem) BAM_LIST_APPEND_C(list, prev, elem, C)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the next element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_CLIST_PREPEND(list, next, elem) BAM_LIST_PREPEND_C(list, next, elem, C)

/**
 *  Remove an element from an arbitrary position.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be removed.
 */
#define BAM_CLIST_REMOVE(list, elem) BAM_LIST_REMOVE_C(list, elem, C)

/*********************************************************************
 * Circularly linked list with counter
 ********************************************************************/

/**
 *  Declare a list type.
 *  @param type  The type of the data to be carried.
 */
#define BAM_CNLIST_TYPE(type)   \
    struct {                    \
        type *_cnl_head;        \
        int   _cnl_size;        \
    }

/**
 *  Declare list element members.
 *  @param type  The type of the data to be carried.
 */
#define BAM_CNLIST_LINK(type) type *_cnl_prev; \
    type *_cnl_next
/**
 *  Static initializer
 */
#define BAM_CNLIST_STATIC_INIT {NULL, 0}

/**
 *  Initialize the list dynamically.
 *  @param list  A pointer to the list.
 */
#define BAM_CNLIST_INIT(list)               \
    do {                                    \
        BAM_CNLIST_GET_HEAD(list) = NULL;   \
        BAM_CNLIST_GET_SIZE(list) = 0;      \
    } while (0)

/**
 *  Initialize an array of lists.
 *  @param list_vec  The list array.
 *  @param len       The size of the array.
 */
#define BAM_CNLIST_VEC_INIT(list_vec, len) BAM_SLIST_VEC_INIT(list_vec, len)

/**
 *  Get the number of elements in the list.
 */
#define BAM_CNLIST_GET_SIZE(list) BAM_LIST_GET_SIZE_CN(list)

/**
 *  Get the list head
 */
#define BAM_CNLIST_GET_HEAD(list) BAM_LIST_GET_HEAD_CN(list)

/**
 *  Get the list tail
 */
#define BAM_CNLIST_GET_TAIL(list) BAM_LIST_GET_TAIL_CN(list)
/**
 *  Get the previous list element
 */
#define BAM_CNLIST_GET_PREV(elem) BAM_LIST_GET_PREV_CN(elem)

/**
 *  Get the next list element
 */
#define BAM_CNLIST_GET_NEXT(elem) BAM_LIST_GET_NEXT_CN(elem)

/**
 *  Push a new element onto the head of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_CNLIST_PUSH_HEAD(list, elem) BAM_LIST_PUSH_HEAD_C(list, elem, CN)

/**
 *  Pop the head of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_CNLIST_POP_HEAD(list, elem) BAM_LIST_POP_HEAD_C(list, elem, CN)

/**
 *  Push a new element onto the tail of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_CNLIST_PUSH_TAIL(list, elem) BAM_LIST_PUSH_TAIL_C(list, elem, CN)

/**
 *  Pop the tail of the list.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element that was removed.
 */
#define BAM_CNLIST_POP_TAIL(list, elem) BAM_LIST_POP_TAIL_C(list, elem, CN)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param prev  A pointer to the previous element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_CNLIST_APPEND(list, prev, elem) BAM_LIST_APPEND_C(list, prev, elem, CN)

/**
 *  Insert an element in an abitrary position.
 *  @param list  A pointer to the list.
 *  @param next  A pointer to the previous element.
 *  @param elem  A pointer to the element to be inserted.
 */
#define BAM_CNLIST_PREPEND(list, next, elem) BAM_LIST_PREPEND_C(list, next, elem, CN)

/**
 *  Remove an element from an arbitrary position.
 *  @param list  A pointer to the list.
 *  @param elem  A pointer to the element to be removed.
 */
#define BAM_CNLIST_REMOVE(list, elem) BAM_LIST_REMOVE_C(list, elem, CN)

#endif /* _bam_list_h */ 


#endif /*OBIGO_Q03C_BROWSER*/