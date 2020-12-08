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
#ifndef _VRE4RES_H_
#define	_VRE4RES_H_
/* Resource Module SDK header file */
#include "vm4res_sdk.h"

/*****************************************************************************
 * FUNCTION
 *  vm_res_extract_images
 * DESCRIPTION
 *  extract image from file with begin id, and put into image_filepath
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_begin_id :       [IN]     begin id to extract
 *  image_filepath:               [IN]     file path to put image, like e:\\image\\
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_extract_images (VMWSTR filename, VMUINT32 image_begin_id, VMWSTR image_filepath);


/*****************************************************************************
 * FUNCTION
 *  vm_res_extract_audios
 * DESCRIPTION
 *  extract audio from file with begin id, and put into audio_filepath
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_begin_id :       [IN]     begin id to extract
 *  image_filepath:               [IN]     file path to put image, like e:\\audio\\
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_extract_audios (VMWSTR filename, VMUINT32 audio_begin_id,VMWSTR audio_filepath);


/*****************************************************************************
 * FUNCTION
 *  vm_res_generate_image_filename
 * DESCRIPTION
 *  generate image file name, example: if filename is E:\helloworld.vxp, image_id is 20000, and image type is gif, it will generate image_filename is helloworld.20000.gif
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_begin_id :       [IN]     image id
 *  image_filepath:               [OUT]    image filename
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_generate_image_filename(VMWSTR filename, VMUINT32 image_id, VMWSTR image_filename);


/*****************************************************************************
 * FUNCTION
 *  vm_res_generate_audio_filename
 * DESCRIPTION
 *  generate audio file name, example: if filename is E:\helloworld.vxp, image_id is 30000, it will generate audio_filename is helloworld.30000.wav
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_begin_id :       [IN]     audio id
 *  image_filepath:               [OUT]    audio filename
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_generate_audio_filename(VMWSTR filename, VMUINT32 audio_id, VMWSTR audio_filename);


/*****************************************************************************
 * FUNCTION
 *  vm_res_delete_images
 * DESCRIPTION
 *  delete images
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_begin_id :       [IN]     begin id to delete
 *  image_filepath:               [IN]     file path to put image, like e:\\image\\
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_delete_images (VMWSTR filename, VMUINT32 image_begin_id, VMWSTR image_filepath);


/*****************************************************************************
 * FUNCTION
 *  vm_res_delete_audios
 * DESCRIPTION
 *  delete audios
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_begin_id :       [IN]     begin id to delete
 *  image_filepath:               [IN]     file path to put image, like e:\\audio\\
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_delete_audios (VMWSTR filename, VMUINT32 audio_begin_id,VMWSTR audio_filepath);

#endif /* _VRE4RES_H_ */

