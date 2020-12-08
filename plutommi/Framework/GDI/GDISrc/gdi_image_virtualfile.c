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
 *	 gdi_image_virtualfile.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Virtual file image
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "fs_type.h"
#include "string.h"
#include "fs_func.h"

#include "MMIDataType.h"

#include "gdi_image.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_animate.h"
#include "gdi_image_virtualfile.h"

S32 gdi_image_get_virtual_filename_with_filesize(S8* image_buffer, S8* virtual_fname, U8 file_size)
{
	S32	fs_result;
	U32 image_file_size=0;
	U32 image_offset=0;
	S32	theme_file_handle;
	
	/* if file_size is 0, use the image_file_size in resource 8-byte header. */
    if (file_size == 0)
    {
	image_file_size = (U8)image_buffer[4];
	image_file_size = (image_file_size << 8) | (U8)image_buffer[3];
	image_file_size = (image_file_size << 8) | (U8)image_buffer[2];
    }
    else
    {
        image_file_size = file_size;
    }

	image_offset = (U8)image_buffer[11];
	image_offset = (image_offset << 8) | (U8)image_buffer[10];
	image_offset = (image_offset << 8) | (U8)image_buffer[9];
	image_offset = (image_offset << 8) | (U8)image_buffer[8];
	
	theme_file_handle = image_buffer[15];
	theme_file_handle = (theme_file_handle << 8) | image_buffer[14];
	theme_file_handle = (theme_file_handle << 8) | image_buffer[13];
	theme_file_handle = (theme_file_handle << 8) | image_buffer[12];

	fs_result = FS_GenVirtualFileName( theme_file_handle, (U16*)virtual_fname, 
		(unsigned int)FS_GenVFN_SIZE, image_offset+8, image_file_size);

	mmi_ucs2cat((S8*)virtual_fname,(const S8*)gdi_image_ext_name[image_buffer[0]]);
	
	return fs_result;
}

GDI_RESULT gdi_image_virtualfile_draw_handler(U32 flag,U32 frame_pos,S32 x,S32 y,S32 w,S32 h,U8* data_ptr,U32 img_size)
{
	U16 fname[FS_GenVFN_SIZE+8];//extra 8 bytes for file extension
	S32 fs_result;
	U8 img_type = GDI_IMAGE_TYPE_INVALID;
	memset(fname, 0, sizeof(fname));
	fs_result = gdi_image_get_virtual_filename((S8*)data_ptr,(S8*)fname);
	if(fs_result<0) return GDI_IMAGE_ERR_OPEN_FILE_FAILED;

	switch(data_ptr[0])
	{
	case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_BMP_FILE;
		break;
	case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_GIF_FILE;
		break;
    case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_JPG_FILE;
		break;
    case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_PNG_FILE;
		break;
    case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_BMP_FILE;
		break;
    case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_WBMP_FILE;
		break;
    case GDI_IMAGE_TYPE_M3D_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_M3D_FILE;
		break;
    case GDI_IMAGE_TYPE_SVG_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_SVG_FILE;
		break;
    case GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_SWFLASH_FILE;
		break;
    case GDI_IMAGE_TYPE_ABM_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_ABM_FILE;
        break;
    case GDI_IMAGE_TYPE_AB2_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_AB2_FILE;
        break;
    case GDI_IMAGE_TYPE_9SLICE_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_9SLICE_FILE;
        break;
    default:
        return GDI_FAILED;
	}
    
	return gdi_image_codec_draw(
				GDI_IMAGE_SRC_FROM_FILE,
				(U8*)fname,img_type,0,
				x,y,w,h,flag,frame_pos);
}

S32 gdi_image_get_virtual_filename(S8* image_buffer, S8* virtual_fname)
{
    return gdi_image_get_virtual_filename_with_filesize(image_buffer, virtual_fname, 0);
}

GDI_RESULT gdi_image_virtualfile_get_dimension_handler(U32 flag,U8* data_ptr,U32 img_size,S32 *width,S32 *height)
{
    *width 		  = (S32)(( ((U32)data_ptr[7])     <<4) | (((U32)data_ptr[6]&0xF0)>>4));
	*height		  = (S32)(((((U32)data_ptr[6])&0xF)<<8) |  ((U32)data_ptr[5]         ));

	//*width =  ((data_ptr[6] & 0x00F0)>>4) | ((data_ptr[5])<<4);
	//*height = ((data_ptr[6] & 0x000F)<<8) | (data_ptr[7]);
	return GDI_SUCCEED;
}
GDI_RESULT gdi_image_virtualfile_get_frame_count_handler(U32 flag,U8* data_ptr,U32 img_size,S32 *frame_count)
{
	gdi_anim_pos_type_enum temp;
	return gdi_image_virtualfile_get_pos_info_handler(flag,data_ptr,img_size,FALSE, frame_count,&temp);
}

GDI_RESULT gdi_image_virtualfile_get_pos_info_handler(U32 flag,U8* data_ptr,U32 img_size,BOOL quick_mode, S32 *total_pos,gdi_anim_pos_type_enum *pos_type)
{
	U16 fname[FS_GenVFN_SIZE+8];//extra 8 bytes for file extension
	S32 fs_result;
	U8 img_type = GDI_IMAGE_TYPE_INVALID;
	memset(fname, 0, sizeof(fname));
	fs_result = gdi_image_get_virtual_filename((S8*)data_ptr,(S8*)fname);
	if(fs_result<0) return GDI_IMAGE_ERR_OPEN_FILE_FAILED;

	switch(data_ptr[0])
	{
	case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_BMP_FILE;
		break;
	case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
		img_type = GDI_IMAGE_TYPE_GIF_FILE;
		break;
    case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_JPG_FILE;
        break;
    case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_PNG_FILE;
        break;
    case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_BMP_FILE;
        break;
    case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_WBMP_FILE;
        break;
    case GDI_IMAGE_TYPE_M3D_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_M3D_FILE;
        break;
    case GDI_IMAGE_TYPE_SVG_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_SVG_FILE;
        break;
    case GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_SWFLASH_FILE;
        break;
    case GDI_IMAGE_TYPE_ABM_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_ABM_FILE;
        break;        
    case GDI_IMAGE_TYPE_AB2_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_AB2_FILE;
        break;        
    case GDI_IMAGE_TYPE_9SLICE_FILE_OFFSET:
        img_type = GDI_IMAGE_TYPE_9SLICE_FILE;
        break;
    default:
        return GDI_FAILED;
	}

	*pos_type = GDI_ANIM_POS_TYPE_INDEX;

	return gdi_image_codec_get_frame_count(
				GDI_IMAGE_SRC_FROM_FILE,
				(U8*)fname,img_type,0,
				total_pos,flag);
}


static GDI_RESULT gdi_image_virtualfile_sequence_get_frame_vitrualfile_data(
                    U8 *sequence_data,
                    U32 frame_pos,
                    U8 *frame_data)
{
    U32 image_offset = 0, imgoffset, anim_delay, frame_sum, read_size;
    S32 fs_result;
    FS_HANDLE file_handle;
    U8 buf[12];
    U16 fname[FS_GenVFN_SIZE+8];    /* extra 8 bytes for file extension */
    
    image_offset = sequence_data[11];
	image_offset = (image_offset << 8) | sequence_data[10];
	image_offset = (image_offset << 8) | sequence_data[9];
	image_offset = (image_offset << 8) | sequence_data[8];

    /* file handle */
	frame_data[15] = sequence_data[15];
	frame_data[14] = sequence_data[14];
	frame_data[13] = sequence_data[13];
	frame_data[12] = sequence_data[12];

    /* check frame_sum */
    /* sequence_data[0] is image_type */
    frame_sum = sequence_data[1];
	if (frame_pos >= frame_sum)
    {
		return GDI_FAILED;
    }

    /* get virtual name */
    /* Resource 8-byte header of image sequence doesn't contain image_size information, it's occupyed by anim_iteration_count */
    /* And we only need the 12-byte image sequence headers here. So get virtual filename with filesize=12*frame_sum */
    memset(fname, 0, sizeof(fname));
	fs_result = gdi_image_get_virtual_filename_with_filesize
                ((S8*)sequence_data,(S8*)fname, (12 * frame_sum));
	if (fs_result < 0)
    {
        return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
    }
    
    /* open virtual file */
    file_handle = FS_Open(fname, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED);
    if (file_handle < 0)
    {
        return GDI_FAILED;
    }
    
    /* skip image headers of other frames */
    if (FS_Seek(file_handle, 12 * frame_pos, FS_FILE_CURRENT) < 0)
    {
        FS_Close(file_handle);
        return GDI_FAILED;
    }
    
    /* read the image of sequence 12 byte header */
    /* first 4 byte is image offset */
    if (((fs_result = FS_Read(file_handle, buf, 4, &read_size)) < 0) || (read_size < 4) )
    {
        FS_Close(file_handle);
        return GDI_FAILED;
    }
	imgoffset = (buf[3]<<24) | (buf[2]<<16) |(buf[1]<<8)|(buf[0]);
    imgoffset += 12 * frame_sum;
    imgoffset += image_offset;
    imgoffset -= 8; /* need to do this because next gdi_image_get_virtual_filename will add 8 */

    frame_data[11] = imgoffset >> 24;
    frame_data[10] = (imgoffset << 8) >> 24;
    frame_data[9] = (imgoffset << 16) >> 24;
    frame_data[8] = (imgoffset << 24) >> 24;

    /* second 4 byte is image size */
	if (((fs_result = FS_Read(file_handle, buf, 4, &read_size)) < 0) || (read_size < 4) )
    {
        FS_Close(file_handle);
        return GDI_FAILED;
    }
    frame_data[4] = buf[2];
    frame_data[3] = buf[1];
    frame_data[2] = buf[0];

    /* third 4 byte is anim_delay */
    if (((fs_result = FS_Read(file_handle, buf, 4, &read_size)) < 0) || (read_size < 4) )
    {
        FS_Close(file_handle);
        return GDI_FAILED;
    }
    anim_delay = (buf[3]<<24) | (buf[2]<<16) |(buf[1]<<8)|(buf[0]);
    gdi_anim_set_frame_delay(anim_delay);

    FS_Close(file_handle);

    /* transfer image type */
    switch (sequence_data[0])
	{
	case GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET:
		frame_data[0] = GDI_IMAGE_TYPE_BMP_FILE_OFFSET;
		break;
    case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET:
		frame_data[0] = GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET;
		break;
    case GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET:
		frame_data[0] = GDI_IMAGE_TYPE_JPG_FILE_OFFSET;
		break;
	case GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET:
		frame_data[0] = GDI_IMAGE_TYPE_PNG_FILE_OFFSET;
		break;
	case GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET:
		frame_data[0] = GDI_IMAGE_TYPE_ABM_FILE_OFFSET;
		break;
    case GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET:
		frame_data[0] = GDI_IMAGE_TYPE_AB2_FILE_OFFSET;
		break;
    default:
        return GDI_FAILED;
	}
    return GDI_SUCCEED;
}


GDI_RESULT gdi_image_virtualfile_sequence_draw_handler(
            U32 flag,
            U32 frame_pos,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U8* data_ptr,
            U32 img_size)
{
    GDI_RESULT ret;
    U8 virtual_file_data[16] = {0}; /* MAX_THEME_IMAGE_HEADER_LENGTH */

    do
    {
    	ret = gdi_image_virtualfile_sequence_get_frame_vitrualfile_data(
    	        data_ptr,
    	        frame_pos,
    	        virtual_file_data);
    	if (ret < 0)
        {
            break;
        }   
        ret = gdi_image_virtualfile_draw_handler(
                flag,
                0,  /* frame pos */
                x,
                y,
                w,
                h,
                virtual_file_data,
                0   /* image size */);
    } while(0);
    return ret;
}


GDI_RESULT gdi_image_virtualfile_sequence_get_dimension_handler(
            U32 flag,
            U8* data_ptr,
            U32 img_size,
            S32 *width,
            S32 *height)
{
    GDI_RESULT ret;
    U8 virtual_file_data[16] = {0}; /* MAX_THEME_IMAGE_HEADER_LENGTH */

    do
    {
    	ret = gdi_image_virtualfile_sequence_get_frame_vitrualfile_data(
    	        data_ptr,
    	        0,  /* frame pos */
    	        virtual_file_data);
    	if (ret < 0)
        {
            break;
        }
        ret = gdi_image_virtualfile_get_dimension_handler(
                flag,
                virtual_file_data,
                0,  /* image size */
                width,
                height);
    } while(0);
    return ret;
}


GDI_RESULT gdi_image_virtualfile_sequence_get_pos_info_handler(
            U32 flag,
            U8* data_ptr,
            U32 img_size,
            BOOL quick_mode, 
            S32 *total_pos,
            gdi_anim_pos_type_enum *pos_type)
{
    *total_pos = (data_ptr[1]);
	*pos_type = GDI_ANIM_POS_TYPE_INDEX;
	return GDI_SUCCEED;
}

GDI_RESULT gdi_image_virtualfile_sequence_get_image_size(
            U8 *data_ptr,
            U32 *image_file_size)
{
    S32 fs_result, file_handle;
    U32 image_type, frame_sum;
    U16 fname[FS_GenVFN_SIZE+8];    /* extra 8 bytes for file extension */

    //image_offset = (data_ptr[11]<<24) | (data_ptr[10]<<16) |(data_ptr[9]<<8)|(data_ptr[8]);
	file_handle = (data_ptr[15]<<24) | (data_ptr[14]<<16) |(data_ptr[13]<<8)|(data_ptr[12]);

    image_type = data_ptr[0];
    frame_sum = data_ptr[1];
    
    if (image_type == GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET ||
        image_type == GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET ||
        image_type == GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET ||
        image_type == GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET ||
        image_type == GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET ||
        image_type == GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET)
    {
        U32 imgoffset, imgsz;
        U32 read_size;
        U8 buf[12];
        
        memset(fname, 0, sizeof(fname));
    	fs_result = gdi_image_get_virtual_filename_with_filesize
                    ((S8*)data_ptr,(S8*)fname, (U8)(12 * frame_sum));
        if (fs_result < 0)
        {
            return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
        }
        /* open virtual file */
        file_handle = FS_Open(fname, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED);
        if (file_handle < 0)
        {
            return GDI_FAILED;
        }
        
        /* skip image headers of other frames */
        if (FS_Seek(file_handle, 12 * (frame_sum - 1), FS_FILE_CURRENT) < 0)
        {
            FS_Close(file_handle);
            return GDI_FAILED;
        }
        
        /* read the image of sequence 12 byte header */
        /* first 4 byte is image offset */
        if ((FS_Read(file_handle, buf, 4, &read_size) < 0) || (read_size < 4) )
        {
            FS_Close(file_handle);
            return GDI_FAILED;
        }
    	imgoffset = (buf[3]<<24) | (buf[2]<<16) |(buf[1]<<8)|(buf[0]);

        /* second 4 byte is image size */
    	if ((FS_Read(file_handle, buf, 4, &read_size) < 0) || (read_size < 4) )
        {
            FS_Close(file_handle);
            return GDI_FAILED;
        }
        imgsz = (buf[3]<<24) | (buf[2]<<16) |(buf[1]<<8)|(buf[0]);
        /* the imgoffset include 8 byte header, so need to -8 */
        *image_file_size = (12 * frame_sum) + imgoffset + imgsz - 8;
        FS_Close(file_handle);
    }
    else
    {        
        *image_file_size = (U8) data_ptr[4];
        *image_file_size = (*image_file_size << 8) | (U8) data_ptr[3];
        *image_file_size = (*image_file_size << 8) | (U8) data_ptr[2];
    }
    return GDI_SUCCEED;
}


