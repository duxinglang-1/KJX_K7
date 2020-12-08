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
* BppCuiGprot.h
*
* Project:
* --------
*   Maui
*
* Description:
* ------------
*   This file is for BT BPP common UI external interface declaration.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
*============================================================================
****************************************************************************/

#ifndef BPP_CUI_GPROT_H
#define BPP_CUI_GPROT_H

#include "MMI_features.h"
#ifdef __MMI_BPP_SUPPORT__

#include "mmi_rp_app_bluetooth_def.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* RHR add end */
/***************************************************************************** 
* Constant definition
*****************************************************************************/

/* BPP xhtml file path length */
#define BPP_MAX_FILE_PATH   (32)
/* BPP xhtml file storage folder */
#define BPP_MEM_DRV         "bpp_mem/"

/* BPP print event */
enum evt_bt_print_event_enum
{
    EVT_BT_PRINT_START = SCR_BPP_DUMMY,    /* start printing */
    EVT_BT_PRINT_DATA_REQ,                 /* request for printing data */
    EVT_BT_PRINT_COMPLETE,                 /* printing complete */
    EVT_BT_PRINT_MAX
};

/* printing app type */
typedef U32 PrintClass;

/* printing app type enum */
enum bt_print_class_enum
{
    BT_PRINT_IMAGE =    'imag',            /* image */
    BT_PRINT_TEXT =     'text',            /* ebook */
    BT_PRINT_CONTACT =  'cnta',            /* vcard */
    BT_PRINT_CALENDAR = 'clnd',            /* vcalendar */
    BT_PRINT_MESSAGE =  'msag',            /* message */
    BT_PRINT_EMAIL =    'mail',            /* mail */
    BT_PRINT_RAW_DATA = 'raw'
};

/* printing data type */
typedef U32 PrintDataType;

/* printing data type enum */
enum bt_print_data_type_enum
{
    BT_PRINT_DATA_FILE = 'file',           /* print a file */
    BT_PRINT_DATA_BUFF = 'buff',           /* print a buffer */
    BT_PRINT_DATA_NONE = 'none',           /* nothing */
    PRINT_DATA_END
};

/* print content type */
typedef U32 PrintContent;

/* print content type enum*/
enum bt_print_content_enum
{
    BT_PRINT_CONTENT_IMAGE = 'cimg',          /* imapge */
    BT_PRINT_CONTENT_TEXT_PLAIN = 'ctxt',     /* ebook */
    BT_PRINT_CONTENT_XHTML = 'cxml',          /* xml */
    BT_PRINT_CONTENT_END
};

/* print result event */
enum bpp_print_result_enum
{
    BPP_E_OK,                    /* print ok */
    BPP_E_FAIL,                  /* print fail */
    BPP_E_PENDING,               /* print pending */
    BPP_E_EXIT,                  /* print exit */
    BPP_E_BUSY,                  /* service busy */
    BPP_E_CANCEL,                /* printing cancelled */
    BPP_E_LINK_DISC,             /* link disconnected */
    BPP_E_DISK_FULL,             /* disk full */
    BPP_ERROR_END
};

/* print data struct */
typedef struct {
    U32 content_type;            /* print content type */
    U32 type;                    /* print data type, file or buffer */
    union {
        U8 *buff;                /* print buffer pointer */
        WCHAR *file;             /* print file pointer */
    } u;
    U32 size;                    /* print data size */
    MMI_BOOL more;               /* if there is more data */
} bt_print_data_struct;

/* print page margin struct */
typedef struct {
    S32 top;                     /* the top margin of print page */
    S32 bottom;                  /* the bottom margin of print page */
    S32 left;                    /* the left margin of print page */
    S32 right;                   /* the right margin of print page */
} bt_print_margin_struct;

/* print page struct */
typedef struct {
    S32 width;                         /* print page width */
    S32 height;                        /* print page height */
    bt_print_margin_struct margin;     /* print page margin */
    U32 rotate;                        /* if rotate the page */
} bt_print_page_struct;

/* request for print data struct */
typedef struct {
    MMI_EVT_GROUP_PARAM_HEADER         /* normal event struct header */
    U32 inst;                          /* printing instance */
    bt_print_data_struct storage;      /* printing data */
} evt_bt_print_data_req_struct;

/* start printing event struct */
typedef struct {
    MMI_EVT_GROUP_PARAM_HEADER         /* normal event struct header */
    U32 inst;                          /* printing instance */
    bt_print_page_struct page_info;    /* print page info */
} evt_bt_print_start_struct;

/* print complete event struct */
typedef struct {
    MMI_EVT_GROUP_PARAM_HEADER         /* normal event struct header */
    U32 inst;                          /* printing instance */
    U32 result;                        /* printing result */
    U32 cause;                         /* reason of printing result */
} evt_bt_print_complete_struct;

/***************************************************************************** 
* External interface declaration
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_launch
 * DESCRIPTION
 *  BT printing CUI launch.
 * PARAMETERS
 *  parent:  [IN]     parent group id of bt printing CUI.
 *  type:     [IN]     app type.
 *  data:     [IN]     printing data
 *  option:   [IN]     print option
 * RETURNS
 *  U32: launch result. 0 for fail.
 *****************************************************************************/
U32 cui_bt_printing_launch(MMI_ID parent, U32 type, bt_print_data_struct *data, U32 option);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  It is used to set print data.
 * PARAMETERS
 *  inst:      [IN]     BT printing instance.
 *  data:     [IN]     printing data
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_printing_set_data(U32 inst, bt_print_data_struct *data);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_style_rules
 * DESCRIPTION
 *  It is used to compose the style of the xhtml document.
 * PARAMETERS
 *  inst:      [IN]     BT printing instance.
 *  xhtml:    [OUT]    the printing xhtml document.
 * RETURNS
 *  S32:  compose result, 0 for fail.
 *****************************************************************************/
S32 cui_bt_printing_style_rules(U32 inst, void *xhtml);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_xhtml_version
 * DESCRIPTION
 *  It is used to get the version of xhtml document.
 * PARAMETERS
 *  inst:      [IN]     BT printing instance.
 * RETURNS
 *  CHAR*:  the version of xhtml document.
 *****************************************************************************/
CHAR *cui_bt_printing_xhtml_version(U32 inst);

/*****************************************************************************
 * FUNCTION
 *  bpp_pixel_to_mm
 * DESCRIPTION
 *  It is used to change pixel to inch.
 * PARAMETERS
 *  px:      [IN]     pixel count.
 * RETURNS
 *  U32:  inch count.
 *****************************************************************************/
U32 bpp_pixel_to_mm(U32 px);

/*****************************************************************************
 * FUNCTION
 *  bpp_mm_to_pixel
 * DESCRIPTION
 *  It is used to change inch to pixel.
 * PARAMETERS
 *  mm:      [IN]     inch count.
 * RETURNS
 *  U32:  pixel count.
 *****************************************************************************/
U32 bpp_mm_to_pixel(U32 mm);


#endif /* __MMI_BPP_SUPPORT__ */

#endif /* BPP_CUI_GPROT_H */

