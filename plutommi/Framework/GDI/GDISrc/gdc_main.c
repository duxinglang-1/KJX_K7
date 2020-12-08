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
 * gdc_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is entry point of GDI Command Executor
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
 *============================================================================
 ****************************************************************************/
/* KAL - RTOS Abstraction Layer */
#include "MMI_features.h"
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

#include "stack_config.h"
#include "task_main_func.h"
#include "syscomp_config.h"

#include "gdi_internal.h"
#include "gdc_include.h"

#include "mmi_frm_gprot.h"

#ifdef __MMI_TVOUT__
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"

#include "gdi_include.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gdi_ipp.h"
#include "gdi_features.h"
#include "gdi_mutex.h"
#include "gdi_primitive.h"
#include "gdi_animate.h"
#include "gdi_imgdec.h"


typedef struct gdc_job_struct
{
    U32                 flag;
    U32                 serial;
    
    gdi_image_src_enum  src_type;
    U8*                 img_src; /* file_handle or point to data */
    #if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
    U8*                 img_handle;	 
    #endif
    U16                 img_filename[SRV_FMGR_PATH_MAX_LEN + 1];
    S32                 img_size;
    U32                 img_flag;/* used for image codec */
    U32                 frame_pos;
    gdi_handle          layer_handle;/* output layer*/
    gdi_handle          lcd_handle;  /* output lcd*/ 
    gdi_handle          anim_handle; /* remember anim handler */
    S32                 x,y;
    S32                 width,height; /* output size , or 0 = original size */
    S32                 clipx1,clipy1,clipx2,clipy2;
    S32                 anim_count;

    void                (*before_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*after_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*last_frame)(GDI_RESULT result);
    void                (*before_frame)(GDI_RESULT result);
    void                (*after_frame)(GDI_RESULT result);
    void                (*done)(GDI_RESULT result,gdi_handle handle);
    void                (*anim_handle_query)(gdi_handle anim_handle,gdi_handle job_handle);

    gdi_handle          source_layer;
    
    /* used only when running nb ipp */
    U32                 effect_id;  
    GDI_IPP_CALLBACK_FUNC ipp_done_callback;
    U8                  img_type;
} gdc_job_struct;

struct
{
    U32 current_serial;
    kal_mutexid mutex;
    
    gdc_job_struct job[GDC_MAX_JOB];
    U32 job_sum;
    
    /* predefine parameters */
    U32                 job_flag;
    S32                 anim_count;
    void                (*before_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*after_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*last_frame)(GDI_RESULT result);
    void                (*before_frame)(GDI_RESULT result);
    void                (*after_frame)(GDI_RESULT result);
    void                (*done)(GDI_RESULT result,gdi_handle handle);
    void                (*anim_handle_query)(gdi_handle anim_handle,gdi_handle job_handle);
} gdc_context;
kal_taskid gdc_thread_id;

static U32  gdc_force_abort_count;

typedef void (*GDC_CALLBACK_FUNC)(GDI_RESULT result,gdi_handle handle);
typedef struct
{
    LOCAL_PARA_HDR
    void* callback;
    GDI_RESULT result;
    gdi_handle handle;
} gdc_msg_dispatch_struct;

#define WAIT_JOB_EVENT()    do{\
                                kal_uint32 event;\
                                kal_retrieve_eg_events(gdi_event_group, GDC_CODEC_EVENT_JOB_DONE,KAL_OR_CONSUME, &event, KAL_SUSPEND);\
                            } while(0)

#define SET_JOB_EVENT()     do{\
                                kal_set_eg_events(gdi_event_group, GDC_CODEC_EVENT_JOB_DONE,KAL_OR);\
                            } while(0)

/*
 * IMGDEC GDC
 */

/* MAX GDC JOB num */
#if defined(__LOW_COST_SUPPORT_COMMON__)
#define GDC_IMGDEC_JOB_NUM  2
#else
#define GDC_IMGDEC_JOB_NUM  2
#endif

#define GDC_IMGDEC_JOB_IS_USED          (1 << 0)
#define GDC_IMGDEC_JOB_IS_RUNNING       (1 << 1)
#define GDC_IMGDEC_JOB_IS_TO_BE_DELETED (1 << 2)
#define GDC_IMGDEC_JOB_IS_CANCELLED     (1 << 3)
#define GDC_IMGDEC_JOB_NONE             0

#define GDC_IMGDEC_LOCK()   kal_take_mutex(gdc_imgdec_p->mutex)
#define GDC_IMGDEC_UNLOCK() kal_give_mutex(gdc_imgdec_p->mutex)

#define GDC_IMGDEC_WAIT_EVENT(event_flag) do \
            { \
                kal_uint32 event; \
                kal_retrieve_eg_events(gdi_event_group, event_flag, KAL_OR_CONSUME, &event, KAL_SUSPEND); \
            } while (0)

#define GDC_IMGDEC_SET_EVENT(event_flag) kal_set_eg_events(gdi_event_group, event_flag, KAL_OR)
#define GDC_IMGDEC_CLEAR_EVENT(event_flag) kal_set_eg_events(gdi_event_group, ~(event_flag), KAL_AND)

typedef struct
{
    U32                 flag;
    U32                 serial;
    
    U8*                 img_src; /* file_handle or point to data */
    U16                 img_filename[SRV_FMGR_PATH_MAX_LEN + 1];
    S32                 img_size;
    
    U32                 frame_pos;
    gdi_handle          layer_handle;/* output layer*/
    gdi_handle          lcd_handle;  /* output lcd */
    gdi_handle          anim_handle; /* remember anim handler */
    S32                 x, y;
    S32                 width, height; /* output size , or 0 = original size */

    S32                 anim_count;

    void                (*before_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*after_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*last_frame)(GDI_RESULT result);
    void                (*done)(GDI_RESULT result,gdi_handle handle);

    gdi_handle          source_layer;

    BOOL                is_aborted; /* aborted flag */
    
    gdi_image_src_enum  src_type;
    U8                  img_type;
    U32                 img_flag;/* used for image codec */
    U32                     aspect_flag;
} gdc_imgdec_job_struct;

typedef struct
{
    U32 job_num;    /* number of jobs in queue */
    kal_mutexid mutex;
    U32 current_serial;
   
    gdc_imgdec_job_struct job[GDC_IMGDEC_JOB_NUM];    

    BOOL force_stop;
} gdc_imgdec_context_struct;

static gdc_imgdec_context_struct g_gdc_imgdec_context;
static gdc_imgdec_context_struct *const gdc_imgdec_p = &g_gdc_imgdec_context;

static gdc_imgdec_delete_job_internal(gdi_handle job, BOOL is_force_delete);
static void gdc_process_imgdec_job(void);


/*****************************************************************************
 * FUNCTION
 *  gdc_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool gdc_init(task_indx_type task_indx)
{
    memset(&gdc_context,0,sizeof(gdc_context));
    gdc_context.anim_count = -1;
    
    gdc_context.mutex = kal_create_mutex("GDC");

    /* init GDC IMGDEC context */
    memset(gdc_imgdec_p, 0, sizeof(gdc_imgdec_context_struct));
    /* create GDC IMGDEC mutex */
    gdc_imgdec_p->mutex = kal_create_mutex("GDC IMGDEC");
    /* create GDC IMGDEC event */
    if (gdi_event_group == NULL)
    {
        gdi_event_group = kal_create_event_group("gdi_event_group");
    }
    return KAL_TRUE;
}   /* end of gdc_reset */


/*****************************************************************************
 * FUNCTION
 *  gdc_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool gdc_reset(task_indx_type task_indx)
{
    return KAL_TRUE;
}   /* end of gdc_reset */


/*****************************************************************************
 * FUNCTION
 *  gdc_reach_max_force_abort_count
 * DESCRIPTION
 *  When gdc nb decoding reaches the max force abort count, gdi mutex won't force abort nb decoding.
 *  It's to prevent nb decoding being always aborted (ex. FMGR, Image Viewer)
 *  when another task uses gdi in background (ex. Java).
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool gdc_reach_max_force_abort_count(void)
{
    if (gdc_force_abort_count >= GDI_NB_FORCE_ABORT_COUNT_MAX)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


static gdc_job_struct *gdc_job_get_by_flag(U32 flag, U32 flag_check_value)
{
    int i;
    gdc_job_struct *job = NULL;
    
    if(gdc_context.job_sum || flag_check_value == 0)
    for(i=0;i<GDC_MAX_JOB;i++)
        if((gdc_context.job[i].flag & flag) == flag_check_value)
        {
            //kal_prompt_trace(MOD_MMI, "[GDC]gdc_job_get_by_flag. retidx=%d, flag=%d, check value=%d", i, flag, flag_check_value);
            job = &(gdc_context.job[i]);
            break;
        }
        
    return job;
}


static gdc_job_struct *gdc_job_get_by_serial(U32 serial)
{
    int i;
    gdc_job_struct *job = NULL;

    if(gdc_context.job_sum)
    for(i=0;i<GDC_MAX_JOB;i++)
        if(gdc_context.job[i].serial == serial)
        {
            //kal_prompt_trace(MOD_MMI, "[GDC]gdc_job_get_by_serial. retidx=%d, serial=%d", i, serial);
            job = &(gdc_context.job[i]);
            break;
        }
        
    return job;
}


/*****************************************************************************
 * FUNCTION
 *  gdc_job_set_parameter
 * DESCRIPTION
 *
 *****************************************************************************/
void gdc_job_set_parameter(
                            U32 job_flag,
                            S32 anim_count,
                            void (*before_draw)(GDI_RESULT result,gdi_handle handle),
                            void (*after_draw)(GDI_RESULT result,gdi_handle handle),
                            void (*last_frame)(GDI_RESULT result),
                            void (*before_frame)(GDI_RESULT result),
                            void (*after_frame)(GDI_RESULT result),
                            void (*done)(GDI_RESULT result,gdi_handle handle),
                            void (*anim_handle_query)(gdi_handle anim_handle,gdi_handle job_handle))
{
    GDI_ENTER_CRITICAL_SECTION(gdc_job_set_parameter);
    gdc_context.job_flag        |= job_flag;
    if(anim_count >0 )  gdc_context.anim_count      = anim_count;
    if(before_draw)     gdc_context.before_draw     = before_draw;
    if(after_draw)      gdc_context.after_draw      = after_draw;
    if(last_frame)      gdc_context.last_frame      = last_frame;
    if(before_frame)    gdc_context.before_frame    = before_frame;
    if(after_frame)      gdc_context.after_frame      = after_frame;
    if(done)            gdc_context.done            = done;
    if(anim_handle_query) gdc_context.anim_handle_query = anim_handle_query;
    GDI_EXIT_CRITICAL_SECTION(gdc_job_set_parameter);
}

/*****************************************************************************
 * FUNCTION
 *  gdc_job_add_ipp
 * DESCRIPTION
 *
 *****************************************************************************/
GDI_RESULT gdc_job_add_ipp(
                gdi_handle layer_handle,
                gdi_ipp_effect_enum effect_id,
                GDI_IPP_CALLBACK_FUNC ipp_done_callback,
                gdi_handle *job_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdc_job_struct *job;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdc_job_add_ipp);

    if(job_handle)  *job_handle = 0;
   
    job = gdc_job_get_by_flag(GDC_JOB_IS_USED,0);
    if(job == NULL) /* no free job item can be insert */
    {
        GDI_RETURN(GDI_FAILED);
    }
    memset(job, 0, sizeof(gdc_job_struct));

    /* generate non-zero serial number */
    gdc_context.current_serial++; 
    if(gdc_context.current_serial==0) 
    {
        gdc_context.current_serial++;
    }

    job->serial             = gdc_context.current_serial;
    job->flag               = GDC_JOB_IS_IPP | GDC_JOB_IS_USED | GDC_JOB_IS_WAIT_PROCESS;
    job->layer_handle       = layer_handle;
    job->effect_id          = (U32)effect_id;
    job->ipp_done_callback  = ipp_done_callback;

    gdc_context.job_sum++;

    if(job_handle)  
    {
        *job_handle = gdc_context.current_serial;
    }

    SET_JOB_EVENT();

    GDI_EXIT_CRITICAL_SECTION(gdc_job_add_ipp);
    return GDI_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  gdc_job_add_image
 * DESCRIPTION
 *
 *****************************************************************************/
GDI_RESULT gdc_job_add_image(
                            gdi_image_src_enum src_type,
                            U8 *img_src,
                            U8 img_type,
                            S32 img_size,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            U32 img_flag,
                            U32 frame_pos,
                            gdc_job_flag_enum job_flag,
                            gdi_handle *job_handle)
{
    GDI_RESULT ret= GDI_FAILED;
    gdc_job_struct *job;
        
    GDI_ENTER_CRITICAL_SECTION(gdc_job_add_image)
	{
            
        if(job_handle)  *job_handle = 0;

        do
        {
            // filename is large than FS_MAX_PATH chars
            if(src_type == GDI_IMAGE_SRC_FROM_FILE && (mmi_ucs2strlen((S8*) img_src) > SRV_FMGR_PATH_MAX_LEN))
                break;
            
            job = gdc_job_get_by_flag(GDC_JOB_IS_USED,0);
            if(job==NULL) 
				break; // no free job item can be insert

            memset(job,0,sizeof(gdc_job_struct));

            // generate non-zero serial number
            gdc_context.current_serial++; 
            if(gdc_context.current_serial==0) gdc_context.current_serial++;
            
            job->serial         = gdc_context.current_serial;
            job->src_type       = src_type;

            if(src_type == GDI_IMAGE_SRC_FROM_FILE)
            {
                job->img_src    = (U8*)job->img_filename;
                mmi_ucs2ncpy((S8*)job->img_src,(S8*)img_src, SRV_FMGR_PATH_MAX_LEN);
            }
            else
            {
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	if(CheckIsImageBufferPtr(img_src))
            job->img_src = img_src;
        else
            job->img_src =(PU8)GetImageData(img_src);
#else
         job->img_src    = img_src;
#endif

                job->img_src    = img_src;
            }
            job->img_size       = img_size;
            job->img_type       = img_type;
            job->img_flag       = img_flag;
            job->frame_pos      = frame_pos;
            job->x              = x;
            job->y              = y;
            job->width          = w;
            job->height         = h;
            job->clipx1         = gdi_act_layer->clipx1;
            job->clipy1         = gdi_act_layer->clipy1;
            job->clipx2         = gdi_act_layer->clipx2;
            job->clipy2         = gdi_act_layer->clipy2;
            job->anim_count     = gdc_context.anim_count;
            gdi_lcd_get_active(&job->lcd_handle);
            gdi_layer_get_active(&job->layer_handle);

            job->flag           = gdc_context.job_flag | job_flag | GDC_JOB_IS_USED | GDC_JOB_IS_WAIT_PROCESS;
            gdc_context.job_sum++;
            
            job->before_draw    = gdc_context.before_draw;
            job->after_draw     = gdc_context.after_draw;
            job->last_frame     = gdc_context.last_frame;
            job->before_frame     = gdc_context.before_frame;
            job->after_frame     = gdc_context.after_frame;
            job->done           = gdc_context.done;
            job->anim_handle_query = gdc_context.anim_handle_query;
            gdi_get_alpha_blending_source_layer(&(job->source_layer));
            
            ret = GDI_SUCCEED;
            
            if(job_handle)  *job_handle = gdc_context.current_serial;

            SET_JOB_EVENT();
        }while(0);

        gdc_context.job_flag    = 0;
        gdc_context.before_draw = NULL;
        gdc_context.after_draw  = NULL;
        gdc_context.last_frame  = NULL;
        gdc_context.before_frame  = NULL;
        gdc_context.after_frame  = NULL;
        gdc_context.done        = NULL;
        gdc_context.anim_handle_query = NULL;
        gdc_context.anim_count = -1;

        //kal_prompt_trace(MOD_MMI, "[GDC]gdc add job. job=%d, ret=%d", *job_handle, ret);
	}
    ASSERT(gdc_context.job_sum <= GDC_MAX_JOB);
    GDI_EXIT_CRITICAL_SECTION(gdc_job_add_image)
    return ret;
}

static void gdc_progress_blt_callback(void *arg, S32 x1,S32 y1,S32 x2,S32 y2)
{
    gdc_job_struct *job = (gdc_job_struct*) arg;
    if(job == NULL) return;
    
    if(gdi_fast_mutex_is_owner())
        gdi_lcd_repaint(x1,y1,x2,y2);
    else
        job = NULL;
}

static void gdc_process_ipp_job(gdc_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdc_process_ipp_job)

    /* If job is already aborted before process, delete it directly, won't do callback function */
    if (gdi_ipp_get_flag(GDI_IPP_FLAG_ABORTING))
    {
        /* clear all flag */
        gdi_ipp_reset_flag();

        /* delete job without calling done callback */
        job->flag =0;
        GDI_ASSERT(gdc_context.job_sum > 0);
        gdc_context.job_sum--;
        GDI_RETURN_VOID;
    }

    /* process  */
    gdi_ipp_set_flag(GDI_IPP_FLAG_NONBLOCK);
    ret = gdi_ipp_process(
            job->layer_handle,
            (gdi_ipp_effect_enum)job->effect_id);
    gdi_ipp_clear_flag(GDI_IPP_FLAG_NONBLOCK);

    if(ret != GDI_ERR_NB_ABORT) /* non-blocking abort should not remove this job */
    {
        if(job->ipp_done_callback)
        {
            /* if job has done callback, delete it after calling the done callback */
            /* clear GDC_JOB_IS_WAIT_PROCESS flag, to prevent the job decode again. */
            job->flag &= ~GDC_JOB_IS_WAIT_PROCESS;
            gdc_msg_send_callback_req((void*)job->ipp_done_callback,ret,(gdi_handle)job->serial);
        }
        else
        {
            //kal_prompt_trace(MOD_MMI, "[GDC]delete gdc job in gdc_process_ipp_job.");
            /* if job has no done callback, delete it directly. */
            job->flag =0;
            GDI_ASSERT(gdc_context.job_sum > 0);
            gdc_context.job_sum--;
        }
    }
    GDI_EXIT_CRITICAL_SECTION(gdc_process_ipp_job)
}


static void gdc_process_job(void)
{
    GDI_RESULT ret = GDI_FAILED;
    GDI_ENTER_CRITICAL_SECTION(gdc_process_job)
    do
    {
        gdi_handle old_lcd_handle, old_layer_handle;
        gdc_job_struct *job = gdc_job_get_by_flag(GDC_JOB_IS_USED | GDC_JOB_IS_WAIT_PROCESS, GDC_JOB_IS_USED | GDC_JOB_IS_WAIT_PROCESS);
        
        if(job==NULL) break; /* no job are waiting */

        /* use gdc_process_ipp_job to process ipp job */
        if (job->flag & GDC_JOB_IS_IPP)
        {
            gdc_process_ipp_job(job);
            break;
        }

        /* The following code are for non-blocking image decoding */
        
        // push current LCD , and set to new LCD
        gdi_lcd_get_active(&old_lcd_handle);
        gdi_lcd_set_active(job->lcd_handle);
        
        //push the current layer of the new LCD 
        gdi_layer_get_active(&old_layer_handle);
        #ifdef __MMI_TVOUT__
        if (GDI_LCD->lcd_type == GDI_LCD_TYPE_TVOUT)
            gdi_layer_set_active(mdi_tvout_get_and_dupe_active_layer());
        else
        #endif
            gdi_layer_set_active(job->layer_handle);

        if((job->flag & GDC_JOB_IS_PROGRESS_BLT))
            gdi_image_set_progress_callback(gdc_progress_blt_callback,(void*)job);

        // set the clipping area
        gdi_layer_push_clip();
        gdi_layer_set_clip( job->clipx1,job->clipy1,job->clipx2,job->clipy2);

        gdi_push_and_set_alpha_blending_source_layer(job->source_layer);

        if(job->before_draw)
            job->before_draw(GDI_SUCCEED,(gdi_handle) job->serial);
            //gdc_msg_send_callback_req((void*)job->before_draw,GDI_SUCCEED,(gdi_handle)job->serial);
        
        if(job->flag& GDC_JOB_IS_ANIM) // call animate API
        {
            if(job->last_frame)
            {
                gdi_anim_set_last_frame_callback(job->last_frame);
            }
            if(job->before_frame)
            {
                gdi_anim_set_draw_before_callback(job->before_frame);
            }
            if(job->after_frame)
            {
                gdi_anim_set_draw_after_callback(job->after_frame);
            }
            ret = gdi_anim_codec_draw_internal(
                                job->src_type,
                                job->img_src,job->img_type,job->img_size,
                                job->x,job->y,
                                job->width,job->height,
                                job->img_flag,
                                &job->anim_handle,
                                job->frame_pos,
                                job->anim_count);
            if (job->anim_handle_query && (ret >= 0))
            {
                job->anim_handle_query(job->anim_handle, (gdi_handle)job->serial);
            }
            gdi_anim_set_nb_job_handle(job->anim_handle,(gdi_handle)job->serial);
        }
        else// call  image API
        {
            ret = gdi_image_codec_draw(
                                job->src_type,
                                job->img_src,job->img_type,job->img_size,
                                job->x,job->y,
                                job->width,job->height,
                                job->img_flag,
                                job->frame_pos);
        }
        
        if(job->after_draw)
            job->after_draw(ret,(gdi_handle) job->serial);
            //gdc_msg_send_callback_req((void*)job->after_draw,ret,(gdi_handle)job->serial);
        
        // output to lcd if need
        if(ret >= GDI_SUCCEED)
        if((job->flag & GDC_JOB_IS_NO_BLT)==0)
        {
            S32 x1,y1,x2,y2;
            gdi_image_get_update_area(&x1,&y1,&x2,&y2);
            gdi_lcd_repaint(x1,y1,x2,y2);
        }

        gdi_pop_and_restore_alpha_blending_source_layer();
        
        gdi_layer_pop_clip(); // restore old clip
        gdi_layer_set_active(old_layer_handle); // restore layer of this new LCD
        gdi_lcd_set_active(old_lcd_handle); // restore to old LCD

        if(ret != GDI_ERR_NB_ABORT) // non-blocking abort should not remove this job.
        {
            gdc_force_abort_count = 0;
            if(job->done)
            {
                /* if job has done callback, delete it after calling the done callback */
                /* clear GDC_JOB_IS_WAIT_PROCESS flag, to prevent the job decode again. */
                job->flag &= ~GDC_JOB_IS_WAIT_PROCESS;
                gdc_msg_send_callback_req((void*)job->done,ret,(gdi_handle)job->serial);
            }
            else
            {
                //kal_prompt_trace(MOD_MMI, "[GDC]delete gdc job in gdc_process_job.");
                /* if job has no done callback, delete it directly. */
                job->flag =0;
                GDI_ASSERT(gdc_context.job_sum > 0);
                gdc_context.job_sum--;
            }
            #if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
            SetImageFlushable(job->img_handle);
            #endif
        }
        else
        {
            /* count the number that this image abort */
            gdc_force_abort_count++;
        }
    } while(0);
    GDI_EXIT_CRITICAL_SECTION(gdc_process_job)
}

MMI_BOOL gdc_job_is_ipp(gdi_handle job_handle)
{
    gdc_job_struct *job;
    job = gdc_job_get_by_serial(job_handle);
    if ((job != NULL) &&
        (job->flag & GDC_JOB_IS_IPP) && 
        (job->flag & GDC_JOB_IS_USED))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

GDI_RESULT gdc_job_del_one(gdi_handle job_handle)
{
    GDI_RESULT ret = GDI_FAILED;
    
    /* Must reset gdc_force_abort_count before GDI_ENTER_CRITICAL_SECTION
     * to make the gdi_fast_mutex_lock abort the decoding immediately
     */
    gdc_force_abort_count = 0;

    GDI_ENTER_CRITICAL_SECTION(gdc_job_del_one)
    if(job_handle)
    {
        gdc_job_struct *item;
        item = gdc_job_get_by_serial((U32)job_handle);
        if(item && (item->flag&GDC_JOB_IS_USED))
        {
            GDI_ASSERT(gdc_context.job_sum > 0);
            item->flag = 0;
            gdc_context.job_sum--;
            /* we also need to stop animate with this job_handle */
            gdi_anim_stop_by_job_handle((gdi_handle)item->serial);
            
            ret = GDI_SUCCEED;
        }
    }
    //kal_prompt_trace(MOD_MMI, "[GDC]gdc delete job. job=%d, ret=%d", job_handle, ret);
    GDI_EXIT_CRITICAL_SECTION(gdc_job_del_one)
    return ret;
}


GDI_RESULT gdc_job_del_all_decoding(void)
{
    /* Must reset gdc_force_abort_count before GDI_ENTER_CRITICAL_SECTION
     * to make the gdi_fast_mutex_lock abort the decoding immediately
     */
    gdc_force_abort_count = 0;

    GDI_ENTER_CRITICAL_SECTION(gdc_job_del_all_decoding)
    int i;
    for(i=0;i<GDC_MAX_JOB;i++)
    {
        if ((gdc_context.job[i].flag & GDC_JOB_IS_IPP) && 
            (gdc_context.job[i].flag & GDC_JOB_IS_USED))
        {
            continue;
        }
        else if(gdc_context.job[i].flag & GDC_JOB_IS_USED)
        {
            gdc_context.job[i].flag = 0;
            GDI_ASSERT(gdc_context.job_sum > 0);
            gdc_context.job_sum--;
        }
    }
    //gdc_context.job_sum=0;
    
    gdi_anim_stop_by_all_job_handle();
    //kal_prompt_trace(MOD_MMI, "[GDC]gdc delete job all.");
    GDI_EXIT_CRITICAL_SECTION(gdc_job_del_all_decoding)
    return GDI_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  gdc_job_is_empty
 * DESCRIPTION
 *  query if the command queue of GDC is empty
 * PARAMETERS
 *  is_empty       [OUT]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdc_job_get_job_sum(U32 *job_sum)
{
    *job_sum = gdc_context.job_sum;
    
    return GDI_SUCCEED;
}

void gdc_msg_dispatch(void *data, U8 scr_mod)
{
    gdc_job_struct *item;
    gdc_msg_dispatch_struct *msg = (gdc_msg_dispatch_struct*) data;
    U32 tmp_flag;

    if (scr_mod != MOD_GDC)
    {
        return;
    }
    /* This function run on MMI task */
    GDI_DEBUG_ASSERT(msg->callback != NULL);

    /* if the job is already delete, won't call the done callback. */
    //kal_prompt_trace(MOD_MMI, "[GDC]gdc_msg_dispatch");
    item = gdc_job_get_by_serial((U32)msg->handle);
    
    if (item && (item->flag & GDC_JOB_IS_USED))
    {
        GDI_ASSERT(!(item->flag & GDC_JOB_IS_WAIT_PROCESS));
        tmp_flag = item->flag;
        
        /* delete the job */
        /* Do this before calling done callback, because the done callback may call gdc_job_del_one. */
        //kal_prompt_trace(MOD_MMI, "[GDC]delete gdc job in gdc_msg_dispatch.");
        GDI_ASSERT(gdc_context.job_sum > 0);
        item->flag = 0;
        gdc_context.job_sum--;

        //kal_prompt_trace(MOD_MMI, "[GDC]gdc call done callback");
        if (tmp_flag & GDC_JOB_IS_IPP)
        {
            if (gdi_ipp_get_flag(GDI_IPP_FLAG_ABORTING))
            {
                /* clear all flag */
                gdi_ipp_reset_flag();
            }
            else
            {
                GDI_IPP_CALLBACK_FUNC ippcallback = (GDI_IPP_CALLBACK_FUNC)msg->callback;
                (*ippcallback)(msg->result, msg->handle);
            }
        }
        else
        {
            GDC_CALLBACK_FUNC gdccallback = (GDC_CALLBACK_FUNC)msg->callback;
            (*gdccallback)(msg->result, msg->handle);
        }
        
    }
}


void gdc_msg_send_callback_req(void* callback,GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdc_msg_dispatch_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ind_p = (gdc_msg_dispatch_struct*)
        construct_local_para((U16)(sizeof(gdc_msg_dispatch_struct)), TD_CTRL);

    ind_p->callback = callback;
    ind_p->result = result;
    ind_p->handle = handle;

    ilm_ptr = allocate_ilm(MOD_GDC);
    ilm_ptr->src_mod_id = MOD_GDC;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = GDC_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_GDC_IMG_CODEC_CALLBACK_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    //kal_prompt_trace(MOD_MMI, "[GDC]gdc send msg MSG_ID_MMI_GDC_IMG_CODEC_CALLBACK_IND, gdc handle=%d", handle);
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  gdc_task_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdc_task_main(task_entry_struct *task_entry_ptr)
{
	kal_uint32 my_index;

	kal_get_my_task_index(&my_index);
    stack_set_active_module_id( my_index, MOD_GDC);
    gdc_thread_id = kal_get_current_thread_ID();
    while (1)
    {
        /* run IMGDEC NB jobs */
        while (gdc_imgdec_p->job_num || gdc_context.job_sum)
        {
            if (gdc_context.job_sum)
            {
                gdc_process_job();
                kal_sleep_task(1);
            }
            
            if (gdc_imgdec_p->job_num)
            {
                gdc_process_imgdec_job();
                /* give some time to low priority tasks */
                kal_sleep_task(1);  
            }
        }
        WAIT_JOB_EVENT();        
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdc_create
 * DESCRIPTION
 *
 *****************************************************************************/
kal_bool gdc_create(comptask_handler_struct **handle)
{
    static comptask_handler_struct gdc_handler_info = 
    {
        gdc_task_main, /* task entry function */
        gdc_init,      /* task initialization function */
        NULL,           /* task configuration function */
        gdc_reset,     /* task reset handler */
        NULL,           /* task termination handler */
    };
    *handle = (comptask_handler_struct*) & gdc_handler_info;
    return KAL_TRUE;
}


/*
 *  IMGDEC JOB QUEUE for nonblocking IMGDEC
 */
void gdc_imgdec_callback_dispatch(void *data, U8 scr_mod)
{
    S32 i;
    gdc_imgdec_job_struct *j;

    gdc_msg_dispatch_struct *msg = (gdc_msg_dispatch_struct*)data;
    GDC_CALLBACK_FUNC done_callback = (GDC_CALLBACK_FUNC)msg->callback;

    if (scr_mod != MOD_GDC)
    {
        return;
    }
    /* This function run on MMI task */
    GDI_DEBUG_ASSERT(msg->callback != NULL);

    GDC_IMGDEC_LOCK();
    for (i = 0; i < GDC_IMGDEC_JOB_NUM; i++)
    {
        j = &gdc_imgdec_p->job[i];

        /* if the job is cancelled, simply delete and return */
        if ((j->serial == (U32)msg->handle) && (j->flag & GDC_IMGDEC_JOB_IS_CANCELLED))
        {
            gdc_imgdec_delete_job_internal(msg->handle, TRUE);

            GDC_IMGDEC_UNLOCK();

            return;
        }
    }
    GDC_IMGDEC_UNLOCK();
    
    done_callback(msg->result, msg->handle);
        
    GDC_IMGDEC_LOCK();
    gdc_imgdec_delete_job_internal(msg->handle, TRUE);
    GDC_IMGDEC_UNLOCK();
}


static void gdc_imgdec_send_callback_req(void* callback, GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdc_msg_dispatch_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: this is not thread safe, and the callback msg id must be changed
    
    ind_p = (gdc_msg_dispatch_struct*)
        construct_local_para((U16)(sizeof(gdc_msg_dispatch_struct)), TD_CTRL);

    ind_p->callback = callback;
    ind_p->result = result;
    ind_p->handle = handle;

    ilm_ptr = allocate_ilm(MOD_GDC);
    ilm_ptr->src_mod_id = MOD_GDC;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = GDC_SAP;

    ilm_ptr->msg_id = (msg_type)MSG_ID_MMI_GDC_IMGDEC_CALLBACK_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    //kal_prompt_trace(MOD_MMI, "[GDC]gdc send msg MSG_ID_MMI_GDC_IMG_CODEC_CALLBACK_IND, gdc handle=%d", handle);
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  gdc_imgdec_add_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  output_layer        [IN]
 *  src_type            [IN]
 *  img_src             [IN]
 *  img_type            [IN]
 *  img_size            [IN]
 *  x                   [IN]
 *  y                   [IN]
 *  w                   [IN]
 *  h                   [IN]
 *  done_callback       [IN]
 *  img_flag            [IN]
 *  job                 [IN]
 * RETURNS
 *  
 *****************************************************************************/
static GDI_RESULT gdc_imgdec_add_job(
            gdi_handle output_layer,
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U32 frame_index,
            gdi_imgdec_nb_done_callback_funcptr done_callback,
            U32 img_flag,
            U32 aspect_flag,
            gdi_handle *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    S32 i;

    gdc_imgdec_job_struct *j;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* NULL returned handle */
    if (!job)
    {
        return GDI_FAILED;
    }
    
    GDC_IMGDEC_LOCK();

    *job = NULL;

    for (i = 0; i < GDC_IMGDEC_JOB_NUM; i++)
    {
        j = &gdc_imgdec_p->job[i];

        /* find an empty job slot to fill it */
        if (!(j->flag & GDC_IMGDEC_JOB_IS_USED))
        {
            // TODO: SET JOB CONTENT HERE
            memset(j, 0, sizeof(gdc_imgdec_job_struct));

            j->layer_handle = output_layer;
            j->src_type = src_type;

            /* copy file name for the file source since the filename might come from the stack */
            if (src_type == GDI_IMAGE_SRC_FROM_FILE)
            {
                mmi_ucs2ncpy((S8*)j->img_filename, (S8*)img_src, SRV_FMGR_PATH_MAX_LEN);
                j->img_src = (U8*)j->img_filename;
            }
            else
            {
                j->img_src = img_src;
            }
            
            j->img_type = img_type;
            j->img_size = img_size;
            j->x = x;
            j->y = y;
            j->width = w;
            j->height = h;
            j->done = done_callback;
            j->img_flag = img_flag;            
            j->aspect_flag = aspect_flag;
            j->img_type = img_type;
            j->frame_pos = frame_index;
                        
            /* generate non-zero serial number */
            if(gdc_imgdec_p->current_serial==0)
            {
                gdc_imgdec_p->current_serial++;
            }

            j->serial = gdc_imgdec_p->current_serial++;

            *job = (gdi_handle)j->serial;

            /* mark as ready to go */
            j->flag = GDC_IMGDEC_JOB_IS_USED;

            gdc_imgdec_p->job_num++;
            
            ret = GDI_SUCCEED;

            /* inform GDC to start */
            SET_JOB_EVENT();
            
            break;
        }
    }

    ASSERT(gdc_imgdec_p->job_num <= GDC_IMGDEC_JOB_NUM);
    GDC_IMGDEC_UNLOCK();    

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdc_imgdec_delete_job_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job       [IN]
 * RETURNS
 *  
 *****************************************************************************/
static gdc_imgdec_delete_job_internal(gdi_handle job, BOOL is_force_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    S32 i;

    gdc_imgdec_job_struct *j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < GDC_IMGDEC_JOB_NUM; i++)
    {
        j = &gdc_imgdec_p->job[i];
        if ((j->flag & GDC_IMGDEC_JOB_IS_USED) && (j->serial == (U32)job))
        {
            /* must block wait for the running job to stop */
            if (is_force_delete)
            {
                j->flag = GDC_IMGDEC_JOB_NONE;
            }
            else if (j->flag & GDC_IMGDEC_JOB_IS_RUNNING)
            {
                /* abort the current running job, the job will be deleted by GDC */
				if (!j->is_aborted)
				{
					j->is_aborted = TRUE;
					GDI_TRACE(GDC_TRC, GDI_IMGDEC_ABORT);//[gdc_imgdec_delete_job_internal]: Abort

					/* wait until the job is aborted */
					// TODO: MIGHT CAUSE DEADLOCK???
					GDC_IMGDEC_WAIT_EVENT(GDC_IMGDEC_EVENT_JOB_DONE);
				}
            }
            else if (j->flag & GDC_IMGDEC_JOB_IS_TO_BE_DELETED)
            {
                /* this job will be deleted at the caller side */
                j->flag |= GDC_IMGDEC_JOB_IS_CANCELLED;
            }
            else
            {
                /* not yet started or not running */
                j->flag = GDC_IMGDEC_JOB_NONE;
            }
 
            if (j->flag == GDC_IMGDEC_JOB_NONE)
            {
                GDI_ASSERT(gdc_imgdec_p->job_num != 0);
                gdc_imgdec_p->job_num--;
            }
            
            ret = GDI_SUCCEED;
            
            break;
        }
    }    

    return ret;    
}


/*****************************************************************************
 * FUNCTION
 *  gdc_imgdec_delete_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job       [IN]
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdc_imgdec_delete_job(gdi_handle job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDC_IMGDEC_LOCK();
    ret = gdc_imgdec_delete_job_internal(job, FALSE);
    GDC_IMGDEC_UNLOCK();    

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdc_imgdec_delete_all_jobs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdc_imgdec_delete_all_jobs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    gdc_imgdec_job_struct *j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDC_IMGDEC_LOCK();

    for (i = 0; i < GDC_IMGDEC_JOB_NUM; i++)
    {
        j = &gdc_imgdec_p->job[i];
        if (j->flag & GDC_IMGDEC_JOB_IS_USED)
        {
            gdc_imgdec_delete_job_internal((gdi_handle)j->serial, FALSE);
        }
    }

    GDC_IMGDEC_UNLOCK();    

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdc_imgdec_get_job_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_num       [IN]
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdc_imgdec_get_job_num(U32 *job_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job_num)
    {
        GDC_IMGDEC_LOCK();
        *job_num = gdc_imgdec_p->job_num;
        GDC_IMGDEC_UNLOCK();        
    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdc_process_imgdec_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gdc_process_imgdec_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    GDI_RESULT ret;

    gdc_imgdec_job_struct *j;
    gdc_imgdec_job_struct *job_to_go;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_to_go = NULL;
    ret = GDI_FAILED;

    GDC_IMGDEC_LOCK();
    
    for (i = 0; i < GDC_IMGDEC_JOB_NUM; i++)
    {
        j = &gdc_imgdec_p->job[i];
         /* find the first job ready to run */
        if ((j->flag & GDC_IMGDEC_JOB_IS_USED) && !(j->flag & GDC_IMGDEC_JOB_IS_TO_BE_DELETED) && !(j->flag & GDC_IMGDEC_JOB_IS_CANCELLED))
        {
            j->flag |= GDC_IMGDEC_JOB_IS_RUNNING;
            job_to_go = j;            
            
            break;
        }
    }

    /* no job, simply return */
    if (!job_to_go)
    {
        GDC_IMGDEC_UNLOCK();

        return;
    }
    
    GDC_IMGDEC_UNLOCK();

    /* run the job */
    ret = gdi_imgdec_draw_internal(
            job_to_go->layer_handle,
            job_to_go->source_layer,
            job_to_go->src_type,
            job_to_go->img_src,
            job_to_go->img_type,
            job_to_go->img_size,        
            job_to_go->x,
            job_to_go->y,
            job_to_go->width,
            job_to_go->height,
            job_to_go->frame_pos,
            &job_to_go->is_aborted,
            job_to_go->img_flag,
            job_to_go->aspect_flag);

    GDC_IMGDEC_SET_EVENT(GDC_IMGDEC_EVENT_JOB_DONE);

    /* finish the job */
    GDC_IMGDEC_LOCK();   

	GDC_IMGDEC_CLEAR_EVENT(GDC_IMGDEC_EVENT_JOB_DONE);

    job_to_go->flag &= ~GDC_IMGDEC_JOB_IS_RUNNING;
        
    /* call done callback, this job will be deleted in the callback */
    if (job_to_go->done && !job_to_go->is_aborted)
    {
        job_to_go->flag |= GDC_IMGDEC_JOB_IS_TO_BE_DELETED;

        /* send done callback RPC */
        gdc_imgdec_send_callback_req((void*)j->done, ret, (gdi_handle)j->serial);
    }
    else
    {
        /* no done callback or aborted, simply remove it */
        gdc_imgdec_delete_job_internal((gdi_handle)job_to_go->serial, FALSE);
    }
    
    GDC_IMGDEC_UNLOCK();
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_nb_draw_internal
 * DESCRIPTION
 *  Starts a IMGDEC nonblocking draw image job.
 * PARAMETERS
 *  output_layer       [IN] output layer handle
 *  src_type           [IN] image source type
 *  img_src            [IN] image pointer
 *  img_type           [IN] image type
 *  img_size           [IN] image size
 *  x                  [IN] x
 *  y                  [IN] y
 *  w                  [IN] resized width
 *  h                  [IN] resized height
 *  img_flag           [IN] flag
 * RETURNS
 *  Job handle.
 *****************************************************************************/
gdi_handle gdi_imgdec_nb_draw_internal(
            gdi_handle output_layer,
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U32 frame_index,
            gdi_imgdec_nb_done_callback_funcptr done_callback,
            U32 img_flag,
            U32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle job_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdc_imgdec_add_job(
        output_layer,
        src_type,
        img_src,
        img_type,
        img_size,
        x,
        y,
        w,
        h,
        frame_index,
        done_callback,
        img_flag,
        aspect_flag,
        &job_handle);
 
    return job_handle;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_nb_stop
 * DESCRIPTION
 *  Stops an IMGDEC nonblocking job.
 * PARAMETERS
 *  job       [IN]  job handle
 * RETURNS
 *  GDI_SUCCEED if the job is stopped; otherwise, GDI_FAILED.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_nb_stop(gdi_handle job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdc_imgdec_delete_job(job);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_nb_stop_all
 * DESCRIPTION
 *  Stops all IMGDEC nonblocking jobs.
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_SUCCEED
 *****************************************************************************/
GDI_RESULT gdi_imgdec_nb_stop_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return gdc_imgdec_delete_all_jobs();
}



