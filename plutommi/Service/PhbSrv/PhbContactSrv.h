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
 *  PhbContactSrv.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef PHBCONTACTSRV_H
#define PHBCONTACTSRV_H


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "Phbsrv.h"
#include "Phbsrvgprot.h"


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/****************************************************/
/*                                                  */
/*               Enum                               */
/*                                                  */
/****************************************************/


/****************************************************/
/*                                                  */
/*               Struct                             */
/*                                                  */
/****************************************************/

typedef struct
{
    srv_phb_node_struct* head;
    srv_phb_node_struct* tail;
    srv_phb_node_struct* alloc_head;
    srv_phb_node_struct* alloc_tail;
    U16 count;
} srv_phb_link_struct;


typedef struct
{
    MMI_BOOL is_reset;
    MMI_BOOL dynamic_field;
    void* field;
} srv_phb_contact_field_struct;


typedef struct
{
    WCHAR fname[MMI_PHB_NAME_FIELD_LENGTH + 1];
    WCHAR lname[MMI_PHB_NAME_FIELD_LENGTH + 1];
    WCHAR name[MMI_PHB_NAME_LENGTH + 1];
} srv_phb_contact_name_struct;

typedef struct _srv_phb_number_node_struct
{
    struct _srv_phb_number_node_struct* next;
    srv_phb_number_struct data;
} srv_phb_number_node_struct;


typedef struct
{
    srv_phb_number_node_struct* head;
    srv_phb_number_node_struct* tail;
    srv_phb_number_node_struct* alloc_head;
    srv_phb_number_node_struct* alloc_tail;
    U16 count;
} srv_phb_contact_number_struct;


typedef struct _srv_phb_email_node_struct
{
    struct _srv_phb_email_node_struct* next;
    srv_phb_email_struct data;
} srv_phb_email_node_struct;


typedef struct
{
    srv_phb_email_node_struct* head;
    srv_phb_email_node_struct* tail;
    srv_phb_email_node_struct* alloc_head;
    srv_phb_email_node_struct* alloc_tail;
    U16 count;
} srv_phb_contact_email_struct;


typedef struct _srv_phb_address_node_struct
{
    struct _srv_phb_address_node_struct* next;
    srv_phb_address_struct data;
} srv_phb_address_node_struct;


typedef struct
{
    srv_phb_address_node_struct* head;
    srv_phb_address_node_struct* tail;
    srv_phb_address_node_struct* alloc_head;
    srv_phb_address_node_struct* alloc_tail;
    U16 count;
} srv_phb_contact_address_struct;


typedef struct _srv_phb_url_node_struct
{
    struct _srv_phb_url_node_struct* next;
    srv_phb_url_struct data;
} srv_phb_url_node_struct;


typedef struct
{
    srv_phb_url_node_struct* head;
    srv_phb_url_node_struct* tail;
    srv_phb_url_node_struct* alloc_head;
    srv_phb_url_node_struct* alloc_tail;
    U16 count;
} srv_phb_contact_url_struct;


typedef struct _srv_phb_note_node_struct
{
    struct _srv_phb_note_node_struct* next;
    srv_phb_note_struct data;
} srv_phb_note_node_struct;


typedef struct
{
    srv_phb_note_node_struct* head;
    srv_phb_note_node_struct* tail;
    srv_phb_note_node_struct* alloc_head;
    srv_phb_note_node_struct* alloc_tail;
    U16 count;
} srv_phb_contact_note_struct;


/* phonebook contact field data struct */
typedef struct
{
    srv_phb_contact_field_struct fileds_point[MMI_PHB_CONTACT_FIELD_DATA_TOTAL];
} srv_phb_contact_struct;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/* Define your local variable here */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/



/***************************************************************************** 
 * Global Function
 *****************************************************************************/


#endif /* PHBCONTACTSRV_H */ 
