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
 *  gdi_image_wbmp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  WBMP image decoder
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "gdi_internal.h"


#include "drm_gprot.h"

#include "kal_release.h"
#include "kal_general_types.h"
#include "wchar.h"
#include "setjmp.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "MMIDataType.h"

#include "gdi_mutex.h"
#include "gdi_lfs.h"
#include "gdi_bytestream.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_primitive.h"

#include "gdi_imgdec_bytestream.h"
#include "gdi_imgdec_resizer.h"
#include "gdi_imgdec_wbmp.h"


#define GDI_WBMP_MAX_WIDTH  (8192)
#define GDI_WBMP_MAX_HEIGHT (8192)



/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  frame_pos       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  w               [IN]        
 *  h               [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    #if defined(GDI_USING_WBMP)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_imgdec_wbmp_struct dec;
    GDI_RESULT ret;
    BOOL aborted = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_imgdec_wbmp_init(&dec, (gdi_handle)gdi_act_layer, &aborted, flag);
    gdi_imgdec_bytestream_init(&dec.bs, data_ptr, img_size);    
    
    ret = gdi_image_wbmp_draw_internal(&dec, x, y, w, h, 0);
    
    gdi_imgdec_bytestream_deinit(&dec.bs);    
    gdi_imgdec_wbmp_deinit(&dec);

    return ret;
    #else
    return GDI_FAILED;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_get_dimension_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 *  width           [?]         
 *  height          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{

    gdi_imgdec_wbmp_get_dimension(data_ptr, img_size, width, height);
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_wbmp_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_is_wbmp_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    U8 buf[2];
    U32 len;
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file(
                 (U16*)file_name,
                 FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED,
                 DRM_PERMISSION_DISPLAY);
    if (handle < 0) return GDI_IMAGE_ERR_INVALID_FILE;

    result = DRM_read_file(handle, buf, 2, &len);

    DRM_close_file(handle);

    if (result == FS_NO_ERROR)
        if (len == 2)
            if (buf[0] == 0 && buf[1] == 0)
            {
                return GDI_SUCCEED;
            }
    return GDI_FAILED;
}



