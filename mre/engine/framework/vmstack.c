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

/*******************************************************************************
* Filename:
* ---------
*  vmstack.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "vmswitch.h"
#include <string.h>
#include <stdio.h>

#include "vmsys.h"
#include "vmstdlib.h"
#include "vmmod.h"

#ifdef __MRE_CORE_BASE__

#define MAX_STACK_SIZE				5

#define LINKED_STACK				1
#define ARRAY_STACK					2

typedef struct stack_management_item_t {
    VMUINT nitem;
    VMUINT capability;
    VMUINT8 type;
    VMUINT8 used;
    void* stack;
} stack_management_item_t;

typedef struct array_stack_item_t {
    void* item_ptr;
} array_stack_item_t;

typedef struct linked_stack_item_t {
    void* item_ptr;
    struct linked_stack_item_t* next;
} linked_stack_item;

static stack_management_item_t management[MAX_STACK_SIZE];


/*****************************************************************************
 * FUNCTION
 *  vm_create_array_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  capability      [IN]        
 *  handle          [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_create_array_stack(VMINT capability, VMINT* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    stack_management_item_t * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (capability <= 0)
        return STACK_PARAM_ERROR;

    for (i = 0; i < MAX_STACK_SIZE; i++)
    {
        ptr = &management[i];
        if (!ptr->used)
        {
            if ((ptr->stack = vm_calloc(capability * sizeof(array_stack_item_t))) != NULL)
            {
                ptr->used = TRUE;
                ptr->capability = capability;
                ptr->nitem = 0;
                ptr->type = ARRAY_STACK;

                *handle = i;
                return STACK_OPERATE_SUCCESS;
            }
            else
            {
                return STACK_LEAK_RESOUCE;
            }	
        }
    }

    return STACK_LEAK_RESOUCE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_is_empty_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stackHandle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_is_empty_stack(VMINT stackHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_management_item_t * ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = &management[stackHandle];
    if (stackHandle >= 0 && stackHandle < MAX_STACK_SIZE 
        && ptr->used)
    {
        if (ptr->nitem > 0)
            return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_push_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stackHandle     [IN]        
 *  ptr             [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_push_stack(VMINT stackHandle, void* ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_management_item_t * p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = &management[stackHandle];
    if (stackHandle >=0 && stackHandle < MAX_STACK_SIZE 
        && p->used)
    {
        if (p->type == ARRAY_STACK)
        {
            if (p->nitem 
                < p->capability)
            {
                array_stack_item_t* items = (array_stack_item_t*)p->stack;

                (items + p->nitem)->item_ptr = ptr;
                ++(p->nitem);

                return STACK_OPERATE_SUCCESS;
            }
            else
                return STACK_PUSH_OVERFLOW;	
        }	
        else
        {
            linked_stack_item *sptr = (linked_stack_item*)p->stack;
            while (sptr)
            {
                if (!sptr->item_ptr)
                {
                    sptr->item_ptr = ptr;
                    ++(p->nitem);
                    return STACK_OPERATE_SUCCESS;
                }
                sptr = sptr->next;
            }

            if ((sptr = vm_calloc(sizeof(linked_stack_item))) == NULL)
                return STACK_LEAK_RESOUCE;
            sptr->item_ptr = ptr;
            sptr->next = p->stack;
            p->stack = sptr;
            ++(p->nitem);
            ++(p->capability);
            return STACK_OPERATE_SUCCESS;
        }	
    }

    return STACK_HANDLE_ERROR;	
}


/*****************************************************************************
 * FUNCTION
 *  vm_popup_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stackHandle     [IN]        
 *  ptr             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_popup_stack(VMINT stackHandle, void** ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_management_item_t * p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = &management[stackHandle];
    if (stackHandle < 0 || stackHandle > MAX_STACK_SIZE || !p->used)
        return STACK_HANDLE_ERROR;

    if (!vm_is_empty_stack(stackHandle))
    {
        //stack_management_item_t* item = management + stackHandle;

        if (p->type == ARRAY_STACK)
        {
            *ptr = (((array_stack_item_t*)p->stack) + p->nitem -1)->item_ptr;
            --(p->nitem);
            return STACK_OPERATE_SUCCESS;
        }
        else
        {
            linked_stack_item* lptr = (linked_stack_item*)p->stack;

            while (lptr)
            {
                if (lptr->item_ptr)
                {
                    --(p->nitem);
                    *ptr = lptr->item_ptr;
                    lptr->item_ptr = NULL;
                    break;
                }

                lptr = lptr->next;
            }

            return STACK_OPERATE_SUCCESS;
        }	
    }
    else
    {
        return STACK_OPERATE_EMPTY_STACK;
    }	
}


/*****************************************************************************
 * FUNCTION
 *  vm_peek_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stackHandle     [IN]        
 *  ptr             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_peek_stack(VMINT stackHandle, void** ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_management_item_t * p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = &management[stackHandle];
    if (stackHandle < 0 || stackHandle > MAX_STACK_SIZE || !p->used)
        return STACK_HANDLE_ERROR;

    if (!vm_is_empty_stack(stackHandle))
    {
        //stack_management_item_t item = management[stackHandle];

        if (p->type == ARRAY_STACK)
        {
            *ptr = (((array_stack_item_t*)p->stack) + p->nitem - 1)->item_ptr;
            return STACK_OPERATE_SUCCESS;
        }
        else
        {
            linked_stack_item* peek = (linked_stack_item*)(p->stack);

            while (peek)
            {
                if (peek->item_ptr)
                {
                    *ptr = peek->item_ptr;
                    return STACK_OPERATE_SUCCESS;
                }

                peek = peek->next;
            }

            /* assigned 0 to the one which has not found yet */
            p->nitem = 0;
            return STACK_OPERATE_EMPTY_STACK;
        }	
    }
    else
    {
        return STACK_OPERATE_EMPTY_STACK;
    }	

	//return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_reset_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stackHandle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_reset_stack(VMINT stackHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_management_item_t * ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = &management[stackHandle];
    if (stackHandle >= 0 && stackHandle < MAX_STACK_SIZE 
        && ptr->used)
    {
        if (ptr->type == ARRAY_STACK)
        {
            ptr->nitem = 0;
            memset(ptr->stack, 0x00, 
                ptr->capability * sizeof(array_stack_item_t));
            return STACK_OPERATE_SUCCESS;
        }
        else
        {
            linked_stack_item *p = (linked_stack_item *)ptr->stack;

            while (p)
            {
                p->item_ptr = NULL;
                p = p->next;
            }

            ptr->nitem = 0;
            return STACK_OPERATE_SUCCESS;	
        }	
    }

    return STACK_HANDLE_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  vm_is_exist_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stackHandle     [IN]        
 *  ptr             [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_is_exist_stack(VMINT stackHandle, void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_management_item_t * p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = &management[stackHandle];
    if (!vm_is_empty_stack(stackHandle))
    {
        if (p->type == ARRAY_STACK)
        {
            int idx = 0;
            for (idx = p->nitem - 1; idx >= 0; idx++)
            {
                if (ptr == (((array_stack_item_t*)p->stack) + idx)->item_ptr)
                    return TRUE;
            }
        }
        else
        {
            linked_stack_item* lptr = (linked_stack_item*)p->stack;

            while (lptr)
            {
                if (lptr->item_ptr == ptr)
                    return TRUE;
                lptr = lptr->next;
            }	
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_destroy_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stackHandle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_destroy_stack(VMINT stackHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_management_item_t * ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = &management[stackHandle];
    if (stackHandle >= 0 && stackHandle < MAX_STACK_SIZE 
        && ptr->used)
    {
        if (ptr->type == ARRAY_STACK)
        {
            memset(ptr->stack, 0x00, 
                sizeof(array_stack_item_t) * ptr->nitem);
            ptr->capability = 0;
            ptr->nitem = 0;
            vm_free(ptr->stack);
            ptr->used = 0;
            ptr->stack = NULL;
        }
        else
        {
            linked_stack_item *p_1 = (linked_stack_item*)ptr->stack, *p_2 = NULL;

            while (p_1)
            {
                p_2 = p_1->next;
                vm_free(p_1);
                p_1 = p_2;
            }

            ptr->capability = 0;
            ptr->nitem = 0;
            ptr->used = 0;
            ptr->stack = NULL;
        }	
    }
    else
        return STACK_HANDLE_ERROR;

    return STACK_OPERATE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_create_linked_stack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  capability      [IN]        
 *  handle          [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_create_linked_stack(VMINT capability, VMINT* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    linked_stack_item *ptr = NULL, *oldPtr = NULL;
    int i = 0, j = 0;
    stack_management_item_t * p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (capability <= 0)
        return STACK_PARAM_ERROR;

    for (i = 0; i < MAX_STACK_SIZE; i++)
    {
        p = &management[i];
        if (!p->used)
        {
            p->used = TRUE;
            p->capability = 0;
            p->nitem = 0;
            p->type = LINKED_STACK;
            p->stack = NULL;

            for (j = 0; j < capability; j++)
            {
                if ((ptr = (linked_stack_item*)vm_calloc(sizeof(linked_stack_item))) == NULL)
                {
                    vm_destroy_stack(i);
                    return STACK_LEAK_RESOUCE;
                }	

                if (j == 0)
                {	
                    p->stack = ptr;
                    oldPtr = ptr;
                }
                else
                {
                    oldPtr->next = ptr;
                }
                p->capability++;
            }

            *handle = i;
            return STACK_OPERATE_SUCCESS;	
        }
    }

    return STACK_LEAK_RESOUCE;
}

#endif /* __MRE_CORE_BASE__ */

