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
*   srv_mmvideo_interface.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IMMVideo interface
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef SRV_MMVIDEO_INTERFACE_H
#define SRV_MMVIDEO_INTERFACE_H

#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_mmvideo_interface_def.h"

#include "gs_srv_mmvideo_type.h"

/*****************************************************************************
* IMMVideo methods
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  IMMVideo_addRef
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IMMVideo_addRef(IMMVideo *obj)
{
	return obj->vt->addRef(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_release
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IMMVideo_release(IMMVideo *obj)
{
	return obj->vt->release(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_queryInterface
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
*  iid : [IN]        
*  pptr : [IN]        
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IMMVideo_queryInterface(IMMVideo *obj, S32 iid, GS_IBase **pptr)
{
	return obj->vt->queryInterface(obj, iid, pptr);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_open_file
* DESCRIPTION
*  open a video file to play
* PARAMETERS
*  obj : [IN] Pointer to object.
*  filename : [IN]  file to open     
*  open_result_callback : [IN]  callback function
*  user_data : [IN]   user data
* RETURNS
*  GS_RES_VDOPLY_SUCCESS : Succeed to open video file, need to wait callback function when open operation is finished.
*  GS_RES_VDOPLY_MEM_INSUFFICIENT : Fail to open video file due to memory is insufficient.
*  GS_RES_VDOPLY_FILE_TOO_LARGE : Fail to open video file due to file is too large.
*  GS_RES_VDOPLY_FRAME_RATE_TOO_HIGH : Fail to open video file due to framerate is too high.
*  GS_RES_VDOPLY_UNSUPPORT_DECODE_SIZE: decode size unsupported
*  GS_RES_VDOPLY_FAILED : Fail to open video file.
*****************************************************************************/
S32 __inline IMMVideo_video_ply_open_file(IMMVideo *obj,const S8* filename,gs_open_result_callback open_result_callback,void* user_data)
{
	return obj->vt->video_ply_open_file(obj,filename,open_result_callback,user_data);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_close_file
* DESCRIPTION
*  close file
* PARAMETERS
*  obj : [IN] Pointer to object. 
* RETURNS
*  GS_RES_VDOPLY_SUCCESS : Succeed to open video file, need to wait callback function when open operation is finished.
*****************************************************************************/
S32 __inline IMMVideo_video_ply_close_file(IMMVideo *obj)
{
	return obj->vt->video_ply_close_file(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_play
* DESCRIPTION
*  To play video file
* PARAMETERS
*  obj : [IN] Pointer to object.
*  pPlayStruct : [IN]  flag for blt layer, flag for play layer, Audio path
*  callback : [IN]  Callback to handle play finish indication
*  user_data : [IN]  user data
* RETURNS
*  GS_RES_VDOPLY_SUCCESS : Succeed to open video file, need to wait callback function when open operation is finished.
*  GS_RES_VDOPLY_SUCCESS : Succeed to start play.
*  GS_RES_VDOPLY_REACH_STOP_TIME : Fail to start play due to it is stopped due to stop time is reached.
*  GS_RES_VDOPLY_FAILED : Fail to start play.
*****************************************************************************/
S32 __inline IMMVideo_video_ply_play(IMMVideo *obj,gs_video_play_struct* pPlayStruct,gs_play_finish_callback callback,void* user_data)
{
	return obj->vt->video_ply_play(obj,pPlayStruct,callback,user_data);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_stop
* DESCRIPTION
*  stop play video
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  GS_RES_VDOPLY_SUCCEED : Succeed to stop player.
*  GS_RES_VDOPLY_ALREADY_FINISHED : Fail to stop player due to it is already stopped.
*****************************************************************************/
S32 __inline IMMVideo_video_ply_stop(IMMVideo *obj)
{
	return obj->vt->video_ply_stop(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_snapshot
* DESCRIPTION
*  snapshot a jpeg picture
* PARAMETERS
*  obj : [IN] Pointer to object.
*  layer_handle : [IN] player layer handle
*  file_name : [IN] filename for saving
* RETURNS
*  GS_RES_VDOPLY_SUCCEED : Succeed to snapshot.
*  GS_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL : Fail to snapshot due to disk is full.
*  GS_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION : Fail to snapshot due to the disk is in write protection mode.
*  GS_RES_VDOPLY_ERR_SNAPSHOT_FAILED : Fail to snapshot.
*****************************************************************************/
S32 __inline IMMVideo_video_ply_snapshot(IMMVideo *obj,S32 layer_handle, PS8 file_name)
{
	return obj->vt->video_ply_snapshot(obj, layer_handle,  file_name);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_get_cur_play_time
* DESCRIPTION
*  get current time
* PARAMETERS
*  obj : [IN] Pointer to object.
*  cur_play_time : [OUT]  current time 
* RETURNS
*  
*****************************************************************************/
void __inline IMMVideo_video_ply_get_cur_play_time(IMMVideo *obj,U64 *cur_play_time)
{
	obj->vt->video_ply_get_cur_play_time(obj,cur_play_time);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_seek_and_get_frame
* DESCRIPTION
*  seek and get frame
* PARAMETERS
*  obj : [IN] Pointer to object.
*  time : [IN]  time to seek
*  player_layer_handle : [IN] video player layer handle
* RETURNS
*  GS_RES_VDOPLY_SUCCEED : Succeed to seek.
*  GS_RES_VDOPLY_ERR_SEEK_FAILED : Fail to seek.
*****************************************************************************/
S32 __inline IMMVideo_video_ply_seek_and_get_frame(IMMVideo *obj,int time,S32 player_layer_handle)
{
	return obj->vt->video_ply_seek_and_get_frame( obj, time, player_layer_handle);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_non_block_seek_and_get_frame
* DESCRIPTION
*  no block seek and get frame
* PARAMETERS
*  obj : [IN] Pointer to object.
*  time : [IN] time to seek
*  player_layer_handle : [IN]   video player layer handle
*  seek_result_callback : [IN]  callback function
*  user_data : [IN]   use data
* RETURNS
*  GS_RES_VDOPLY_SUCCEED : Succeed to non-blocking seek.
*  GS_RES_VDOPLY_ERR_SEEK_FAILED : Fail to non-blocking seek.
*****************************************************************************/
S32 __inline IMMVideo_video_ply_non_block_seek_and_get_frame(IMMVideo *obj,int time,
                    S32 player_layer_handle,
                    gs_seek_result_callback seek_result_callback,
                    void *user_data)
{
	return obj->vt->video_ply_non_block_seek_and_get_frame(obj,time,player_layer_handle,seek_result_callback,user_data);
}


/*****************************************************************************
 * FUNCTION
 *	IMMVideo_video_ply_stop_non_block_seek
 * DESCRIPTION
 *	To stop non block seeking.
 * PARAMETERS
 *	obj : [IN] Pointer to object.  
 * RETURN VALUES
 *	GS_RES_VDOPLY_SUCCEED : Succeed to stop non-blocking seek.
 *	GS_RES_VDOPLY_ERR_FAILED : Fail to stop non-blocking seek.
 *****************************************************************************/
S32 __inline IMMVideo_video_ply_stop_non_block_seek(IMMVideo *obj)
{
	return obj->vt->video_ply_stop_non_block_seek(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_set_brightness
* DESCRIPTION
*  set video brightness
* PARAMETERS
*  obj : [IN] Pointer to object.
*  brightness : [IN]   please refer GS_VIDEO_BRIGHTNESS_0  in gs_srv_mmvideo_type.h
* RETURNS
*  GS_RES_VDOPLY_SUCCEED : Success
*  Other : FAILED
*****************************************************************************/
S32 __inline IMMVideo_video_ply_set_brightness(IMMVideo *obj,U16 brightness)
{
	return obj->vt->video_ply_set_brightness(obj, brightness);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_set_contrast
* DESCRIPTION
*  set video contrast
* PARAMETERS
*  obj : [IN] Pointer to object.
*  contrast : [IN]  please refer GS_VIDEO_CONTRAST_0  in gs_srv_mmvideo_type.h
* RETURNS
*  GS_RES_VDOPLY_SUCCEED : Success
*  Other : FAILED
*****************************************************************************/
S32 __inline IMMVideo_video_ply_set_contrast(IMMVideo *obj,U16 contrast)
{
	return obj->vt->video_ply_set_contrast(obj, contrast);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_check_is_able_to_play
* DESCRIPTION
*  check the file is able to play
* PARAMETERS
*  obj : [IN] Pointer to object.
*  file_name : [IN]
* RETURNS
*  GS_RES_VDOPLY_SUCCEED : This file is able to play.
*  GS_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : This file is not able to play due to memory is not enough.
*  GS_RES_VDOPLY_ERR_FAILED : This file is not able to play.
*****************************************************************************/
S32 __inline IMMVideo_video_ply_check_is_able_to_play(IMMVideo *obj,PS8 file_name)
{
	return obj->vt->video_ply_check_is_able_to_play(obj,file_name);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_is_playing
* DESCRIPTION
*  if is playing now
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  TRUE is playing, FALSE is not playing
*****************************************************************************/
BOOL __inline IMMVideo_video_is_playing(IMMVideo *obj)
{
	return obj->vt->video_is_playing(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_is_recording
* DESCRIPTION
*  if is recording now
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  TRUE is recording, FALSE is not recording
*****************************************************************************/
BOOL __inline IMMVideo_video_is_recording(IMMVideo *obj)
{
	return obj->vt->video_is_recording(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_video_ply_get_total_duration
* DESCRIPTION
*  get video total duration, not support now
* PARAMETERS
*  obj : [IN] Pointer to object.
*  filename : [IN] video file name
*  total_duration : [OUT]  video tatal duration
* RETURNS
*  
*****************************************************************************/
S32 __inline IMMVideo_video_ply_get_total_duration(IMMVideo *obj,const S8 *filename, U64* total_duration)
{
	return obj->vt->video_ply_get_total_duration(obj,filename, total_duration);
}


#endif

