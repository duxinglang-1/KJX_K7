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
 * ImgEdtSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Image Edit Service internal data type definitions
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __IMG_EDT_SRV_H__
#define __IMG_EDT_SRV_H__

#include "MMI_include.h"
#include "kal_release.h"
#include "ImgEdtSrvGprot.h"
#include "stack_common.h"
#include "custom_events_notify.h"

#define DCHAR S_DCHAR
#include "scalado_adapt.h"
#undef DCHAR S_DCHAR

#include "FileMgrSrvGProt.h"

/*******************************************************************************************************
 * LOG MECHANISM FOR DEBUGGING
 *******************************************************************************************************/
#define SRV_IES_LOG_MAX_LOG_COUNT       (512)               // Maximum log info count for tracking
 
typedef enum SRV_IES_OP_ENUM
{
    // Util related
    SRV_IES_UTIL_ERROR_GET_RESULT,
    SRV_IES_UTIL_ERROR_GET_STRING,
    SRV_IES_UTIL_IS_SUFFIX_SUPPORTED,
    SRV_IES_UTIL_IS_FILE_SUPPRRTED,

    // App session
    SRV_IES_APP_SESSION_CREATE,
    SRV_IES_APP_SESSION_DESTROY,

    // Job related
    SRV_IES_JOB_CANCEL,
    SRV_IES_JOB_HANDLE_START,
    SRV_IES_JOB_HANDLE_RESPONSE,
    SRV_IES_JOB_HANDLE_CANCEL,

    // Image related
    SRV_IES_IMAGE_CREATE_FROM_FILE,
    SRV_IES_IMAGE_SET_META_INFO,
    SRV_IES_IMAGE_GET_SOURCE_SIZE,
    SRV_IES_IMAGE_GET_CURRENT_SIZE,
    SRV_IES_IMAGE_RENDER_BUFFER_ASYNC,
    SRV_IES_IMAGE_RENDER_FILE_ASYNC,
    SRV_IES_IMAGE_DESTROY,

    // Crop operation
    SRV_IES_IMAGE_CROP,

    // Rotate related
    SRV_IES_IMAGE_ROTATE_BEGIN,
    SRV_IES_IMAGE_ROTATE_ADJUST,
    SRV_IES_IMAGE_ROTATE_CANCEL,
    SRV_IES_IMAGE_ROTATE_END,

    // Flip related
    SRV_IES_IMAGE_FLIP_BEGIN,
    SRV_IES_IMAGE_FLIP_ADJUST,
    SRV_IES_IMAGE_FLIP_CANCEL,
    SRV_IES_IMAGE_FLIP_END,

    // Frame related
    SRV_IES_FRAME_BEGIN_FROM_ID,
    SRV_IES_FRAME_CANCEL,
    SRV_IES_FRAME_END,

    // Undo operation
    SRV_IES_IMAGE_UNDO,

    // Preview related
    SRV_IES_PREVIEW_CREATE,
    SRV_IES_PREVIEW_SET_ZOOM_LEVEL,
    SRV_IES_PREVIEW_SET_ZOOM_RECT,
    SRV_IES_PREVIEW_SET_PAN_DELTA,
    SRV_IES_PREVIEW_SET_ZOOM_AND_PAN,
    SRV_IES_PREVIEW_GET_ZOOM_AND_PAN,
    SRV_IES_PREVIEW_GET_SCREEN_RECT,
    SRV_IES_PREVIEW_GET_CANVAS_RECT,
    SRV_IES_PREVIEW_GET_CURRENT_SIZE,
    SRV_IES_PREVIEW_GET_CURRENT_RECT,
    SRV_IES_PREVIEW_RENDER_ASYNC,
    SRV_IES_PREVIEW_RENDER,
    SRV_IES_PREVIEW_DESTROY,

    // Icon related
    SRV_IES_ICON_BEGIN_FROM_FILE,
    SRV_IES_ICON_BEGIN_FROM_BUFFER,
    SRV_IES_ICON_BEGIN_FROM_ID,
    SRV_IES_ICON_GET_CURRENT_SIZE,
    SRV_IES_ICON_GET_MIN_MAX_SIZE,
    SRV_IES_ICON_ADJUST_POS,
    SRV_IES_ICON_ADJUST_ROTATION,
    SRV_IES_ICON_ADJUST,
    SRV_IES_ICON_CANCEL,
    SRV_IES_ICON_END,

    // Effect related
    SRV_IES_EFFECT_BEGIN_ADJUST,
    SRV_IES_EFFECT_SET_PARAM_INT,
    SRV_IES_EFFECT_CANCEL_ADJUST,
    SRV_IES_EFFECT_END_ADJUST,

    // Doodle related
    SRV_IES_DOODLE_CREATE,
    SRV_IES_DOODLE_SET_COLOR,
    SRV_IES_DOODLE_SET_LINE_WIDTH,
    SRV_IES_DOODLE_ADD_LINE,
    SRV_IES_DOODLE_ERASE_LINE,
    SRV_IES_DOODLE_CANCEL_AND_DESTROY,
    SRV_IES_DOODLE_COMMIT_AND_DESTROY,
    SRV_IES_DOODLE_DESTROY,

    // Meta related
    SRV_IES_META_CREATE_FROM_FILE,
    SRV_IES_META_CREATE_FROM_FILE_ASYNC,
    SRV_IES_META_CREATE_FROM_BUFFER,
    SRV_IES_META_QUERY_DATA,
    SRV_IES_META_DESTROY
} SRV_IES_OP_ENUM;

typedef struct srv_ies_log_struct
{
    kal_uint32                          callIndex;
    SRV_IES_OP_ENUM                     operation;
    kal_uint32                          arguments[11];
    kal_uint32                          duration;
    srv_ies_result                      IESResult;
} srv_ies_log_struct;

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && !defined(__SCALADO_DBG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    #define IES_LOG_SETUP()
    #define IES_LOG_BEGIN(op, args, arg1, ...)
    #define IES_LOG_FAIL(error)
    #define IES_LOG_END(result)
#endif  // __MTK_TARGET__


/*******************************************************************************************************
 * BASIC CONTROL STRUCTURE
 *******************************************************************************************************/
#define IES_RET_IF_FAIL(result)                                                                         \
do {                                                                                                    \
    if(CFAILED(result))                                                                                 \
    {                                                                                                   \
        kal_trace(MOD_IES, TRACE_GROUP_2,                                                               \
            "CAPS error %d at %s:%d", result, __FUNCTION__, __LINE__);                                  \
        return srv_ies_util_error_get_result(result);                                                   \
    }                                                                                                   \
} while (0);


#define IES_RET_FAIL(result)                                                                            \
do {                                                                                                    \
    kal_trace(MOD_IES, TRACE_GROUP_2,                                                                   \
        "CAPS error %d at %s:%d", result, __FUNCTION__, __LINE__);                                      \
    return srv_ies_util_error_get_result(result);                                                       \
} while (0);


// Check if an image is valid and not being rendered.
#define IES_CHECK_IMAGE(hImage)                                                                         \
do {                                                                                                    \
    ASSERT((NULL != hImage) && (NULL != hImage->session));                                              \
                                                                                                        \
    if (NULL != hImage->jobInfo.pCurrJob)                                                               \
    {                                                                                                   \
        kal_trace(MOD_IES, TRACE_GROUP_2,                                                               \
            "Current job != NULL at%s:%d", __FUNCTION__, __LINE__);                                     \
        ASSERT(0);                                                                                      \
    }                                                                                                   \
} while (0);


#define IES_CHECK_PREVIEW(hPreview)                                                                     \
do {                                                                                                    \
    srv_ies_image *pImage;                                                                              \
                                                                                                        \
    ASSERT(NULL != hPreview);                                                                           \
    ASSERT(NULL != hPreview->screen);                                                                   \
    ASSERT(NULL != hPreview->pParent);                                                                  \
                                                                                                        \
    pImage = hPreview->pParent;                                                                         \
                                                                                                        \
    ASSERT(NULL != pImage->session);                                                                    \
    if (NULL != pImage->jobInfo.pCurrJob)                                                               \
    {                                                                                                   \
        kal_trace(MOD_IES, TRACE_GROUP_2,                                                               \
            "Current job != NULL at%s:%d", __FUNCTION__, __LINE__);                                     \
        ASSERT(0);                                                                                      \
    }                                                                                                   \
} while(0);


#define IES_CHECK_DOODLE(hDoodle)                                                                       \
do {                                                                                                    \
    ASSERT(NULL != hDoodle);                                                                            \
    ASSERT(NULL != hDoodle->screen);                                                                    \
    ASSERT(NULL != hDoodle->scribble);                                                                  \
    ASSERT(NULL != hDoodle->pParent);                                                                   \
} while(0);

typedef struct srv_ies_job              srv_ies_job;

typedef struct srv_ies_effect_interface srv_ies_effect_interface;

typedef struct srv_ies_job_control
{
    srv_ies_job                         *pCurrJob;
} srv_ies_job_control;

typedef struct srv_ies_meta
{
    srv_ies_app_session_handle          pParent;
    srv_ies_job_control                 jobInfo;
    CTSpmoOptions                       *pOption;
    CTStream                            *pSource;
    CTSpmo                              *pSPMO;
} srv_ies_meta;

typedef enum SRV_IES_APP_STATE_ENUM
{
    SRV_IES_APP_STATE_META_INITED = 0x01,                   // The meta sub-module has been inited
    SRV_IES_APP_STATE_JOB_INITED  = 0x02                    // The job sub-module has been inited
} SRV_IES_APP_STATE_ENUM;

#define SRV_IES_APP_SESSION_PATTERN     (('I' << 24) | ('E' << 16) | ('S' << 8) | ('A'))

typedef struct srv_ies_app_session
{
    kal_uint32                          guard;              // Pattern for integrity
    MMI_ID                              appID;              // Application ID number
    SRV_IES_APP_STATE_ENUM              appState;           // Application internal state
    srv_ies_feature_enum                feature;            // Application feature ID
    MMI_BOOL                            bufOwner;           // The real buffer owner
    void                                *pBuf;              // Buffer for Scalado heap
    kal_uint32                          bufSize;            // The heap buffer size
} srv_ies_app_session;

typedef struct srv_ies_image
{
    srv_ies_job_control                 jobInfo;
    srv_ies_app_session_handle          pParent;            // Parent application session
    S32                                 userCount;          // Reference count for booking
    CTSession                           session;            // Scalado CAPS engine session
    CTStream                            *pStream;           // Underlying JPEG bitstraem
    CTuint32                            fileSize;           // Source file size in bytes
    srv_ies_meta_handle                 hMeta;              // Meta info for fast decoding
    kal_bool                            ownMeta;            // Meta instance is owned by self
    CTBuffer                            buffer;             // Render buffer information
    srv_ies_rot_enum                    orientation;        // Current orientation of image
    CAPS_CLIPART                        clipArt;            // Current adjusting icon/clipart
    CTBuffer                            clipArtBuf;         // Active clipart input buffer

    srv_ies_effect_interface            *pEffect;           // Current adjusting effect
    srv_ies_rot_enum                    rotation;           // Current rotation angle

    kal_bool                            switchXY;           // The XY have been switched
                                                            // (i.e. EXIF orientation = 90 or 270)

    kal_uint32                          extraMargin;        // Extra margin for saving file
} srv_ies_image;

typedef struct srv_ies_preview
{
    kal_bool                            switched;           // Is switched to cachable
    srv_ies_image                       *pParent;           // The parent image handle
    CTScreen                            *screen;            // Corresponding CAPS screen
    CTint32                             width1X;            // Preview zoom 1x width
    CTint32                             height1X;           // Preview zoom 1x height
    CTBuffer                            buffer;             // Corresponding CAPS buffer
    CTAnimation                         *pAnim;             // Animation object for pan/zoom
    CTfloat                             animDst;            // Current animation destination
    CTfloat                             animLevel;          // Current animation level
    CTPoint                             animCenter;         // Current antimation center
    CTfloat                             animProg;           // Foreground render for each frame
    CTfloat                             animStep;           // Background render for final frame
    CTIterator                          *pAnimItr;          // For create animation object
    CTImage                             *pDoodleBuf;        // The doodle raw buffer
} srv_ies_preview;


typedef struct srv_ies_frame_info
{
    kal_uint32                          frameSize;
    srv_ies_image_handle                hImage;
} srv_ies_frame_info;

typedef struct srv_ies_doodle_info
{
    srv_ies_image                       *pParent;           // Doodle parent image handle
	CTScreen                            *screen;            // Screen buffer for doodle
    CAPS_SCRIBBLE                       scribble;           // Underlying doodle instance
    U32                                 lineRadius;         // 1 equals to 3X3 pixel radius
} srv_ies_doodle_info;

/*****************************************************************************
 * INTER-TASK JOB COMMUNICATION
 *****************************************************************************/

typedef enum SRV_IES_JOB_TYPE_ENUM
{
    SRV_IES_JOB_TYPE_RENDER_PREVIEW,
    SRV_IES_JOB_TYPE_RENDER_BUFFER,
    SRV_IES_JOB_TYPE_RENDER_FILE,
    SRV_IES_JOB_TYPE_CREATE_META
} SRV_IES_JOB_TYPE_ENUM;

typedef enum SRV_IES_JOB_STATE_ENUM
{
    SRV_IES_JOB_STATE_INVALID,
    SRV_IES_JOB_STATE_CREATED,
    SRV_IES_JOB_STATE_PENDING,
    SRV_IES_JOB_STATE_RUNNING,
    SRV_IES_JOB_STATE_CANCELLED,
    SRV_IES_JOB_STATE_FINISHED
} SRV_IES_JOB_STATE_ENUM;

typedef struct srv_ies_list_head_struct
{
    struct srv_ies_list_head_struct *pNext;
    struct srv_ies_list_head_struct *pPrev;
} srv_ies_list_head_struct;

typedef kal_uint32                      srv_ies_job_id;

typedef struct srv_ies_job
{
    srv_ies_list_head_struct            list;
    srv_ies_app_session                 *pParent;
    kal_eventgrpid                      event;
    module_type                         modID;
    SRV_IES_JOB_STATE_ENUM              state;
    srv_ies_job_id                      jobID;
    kal_uint32                          seqNum;
    SRV_IES_JOB_TYPE_ENUM               jobType;
    void                                *pOwner;
    void                                *pInput;
    CTIterator                          *pItr;
    void                                *pOutput;
    kal_uint32                          maxStep;
    srv_ies_async_callback_func_ptr     callback;
    void                                *pData;
    WCHAR                               filePath[SRV_FMGR_PATH_MAX_LEN + 1];
} srv_ies_job, *srv_ies_job_handle;

typedef enum SRV_IES_JOB_REQUEST_ENUM
{
    SRV_IES_JOB_REQUEST_START,
    SRV_IES_JOB_REQUEST_CANCEL,
} SRV_IES_JOB_REQUEST_ENUM;

typedef struct srv_ies_ilm_job_request
{
    LOCAL_PARA_HDR
    SRV_IES_JOB_REQUEST_ENUM            type;
    srv_ies_job                         *pJob;
    kal_uint32                          seqNum;          // Since *job is a pointer, we store job_uid to ensure identity
} srv_ies_ilm_job_request;

// Sent from IES task, the execution result of a job.
typedef struct srv_ies_ilm_job_response
{
    LOCAL_PARA_HDR
    srv_ies_result                      result;
    srv_ies_job                         *pJob;
    kal_uint32                          seqNum;          // Since *job is a pointer, we store job_uid to ensure identity
} srv_ies_ilm_job_response;

static __inline void LIST_INIT(srv_ies_list_head_struct *pList)                                         \
{                                                                                                       \
    pList->pNext = pList;                                                                               \
    pList->pPrev = pList;                                                                               \
}

static __inline void _list_add(srv_ies_list_head_struct *pPrev,                                         \
                               srv_ies_list_head_struct *pNew,                                          \
                               srv_ies_list_head_struct *pNext)                                         \
{                                                                                                       \
    pNext->pPrev = pNew;                                                                                \
    pNew->pNext  = pNext;                                                                               \
    pNew->pPrev  = pPrev;                                                                               \
    pPrev->pNext = pNew;                                                                                \
}

#define LIST_ADD_HEAD(pHead, pNew)                                                                      \
    _list_add((pHead), (pNew), (pHead)->pNext);


#define LIST_ADD_TAIL(pHead, pNew)                                                                      \
    _list_add((pHead)->pPrev, (pNew), (pHead));

static __inline void _list_del(srv_ies_list_head_struct *pPrev,                                         \
                               srv_ies_list_head_struct *pNext)                                         \
{                                                                                                       \
    pNext->pPrev = pPrev;                                                                               \
    pPrev->pNext = pNext;                                                                               \
}

#define LIST_DEL(pEntry)                                                                                \
    _list_del((pEntry)->pPrev, (pEntry)->pNext);

static __inline MMI_BOOL LIST_EMPTY(srv_ies_list_head_struct *pList)                                    \
{                                                                                                       \
    return (MMI_BOOL)(pList->pNext == pList);                                                           \
}


/*******************************************************************************************************
 * GLOBAL DATA AND CONTEXT FOR OBJECT ALLOCATORS DECLARATION
 *******************************************************************************************************/
// This macro is used to decalre a static array of global objects.
// These objects can be "alloacted" by TYPED_ALLOC() macro
#define DECLARE_STATIC_RESERVE_SLOT(_type, _elemCount)                                                  \
    static const S32    g_##_type##_count = _elemCount;                                                 \
    static _type        g_##_type##_pool[_elemCount];                                                   \
    static MMI_BOOL     g_##_type##_used[_elemCount] = { MMI_FALSE };


#define IS_ANY_ALLOCATED(_owner, _type)                                                                 \
{                                                                                                       \
    S32     index;                                                                                      \
    _type   *pObj;                                                                                      \
                                                                                                        \
    for (index = 0; index < g_##_type##_count; index++)                                                 \
    {                                                                                                   \
        if (KAL_TRUE == g_##_type##_used[index])                                                        \
        {                                                                                               \
            pObj = &g_##_type##_pool[index];                                                            \
            if (pObj->pParent == _owner)                                                                \
            {                                                                                           \
                ASSERT(0);                                                                              \
            }                                                                                           \
        }                                                                                               \
    }                                                                                                   \
}

// Allocate a object of _type. The _type must be pre-allocated
// in global static memory with DECLARE_STATIC_RESERVE_SLOT() macro.
#define TYPED_ALLOC(_output, _type)                                                                     \
do {                                                                                                    \
    S32 index;                                                                                          \
                                                                                                        \
    for (index = 0; index < g_##_type##_count; index++)                                                 \
    {                                                                                                   \
        if (MMI_FALSE == g_##_type##_used[index])                                                       \
        {                                                                                               \
            break;                                                                                      \
        }                                                                                               \
    }                                                                                                   \
                                                                                                        \
    if(g_##_type##_count == index)                                                                      \
    {                                                                                                   \
        _output = NULL;                                                                                 \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
        _output = &g_##_type##_pool[index];                                                             \
        g_##_type##_used[index] = MMI_TRUE;                                                             \
    }                                                                                                   \
} while(0);


// Free an object allocated by TYPED_ALLOC() macro
#define TYPED_FREE(_alloc_, _type)                                                                      \
do {                                                                                                    \
    S32 index;                                                                                          \
    U8  *pObj;                                                                                          \
                                                                                                        \
    pObj = (U8*)g_##_type##_pool;                                                                       \
    for(index = 0; index < g_##_type##_count; ++index)                                                  \
    {                                                                                                   \
        if(pObj == (U8*)_alloc_)                                                                        \
        {                                                                                               \
            break;                                                                                      \
        }                                                                                               \
        pObj += sizeof(_type);                                                                          \
    }                                                                                                   \
                                                                                                        \
    ASSERT(index < g_##_type##_count);                                                                  \
                                                                                                        \
    g_##_type##_used[index] = MMI_FALSE;                                                                \
} while(0);


/*******************************************************************************************************
     Timing measure & high-resolution counter
     define __SCALADO_DBG_MEASURE__ if you need to measure
 *******************************************************************************************************/
#if 0 //defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__SCALADO_DBG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif 0 //defined(__SCALADO_DBG_MEASURE__) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

    #define MEASURE_SETUP()
    #define MEASURE_BEGIN()
    #define MEASURE_END(_func_name)

#endif


/*******************************************************************************************************
 * INTER SUB-MODULE FUNCTIONS
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

srv_ies_result srv_ies_util_error_get_result(CRESULT result);

srv_ies_result srv_ies_job_init(srv_ies_app_session_handle hApp);

srv_ies_job_handle srv_ies_job_create(srv_ies_app_session_handle        hApp,
                                      module_type                       modID,
                                      SRV_IES_JOB_TYPE_ENUM             jobType,
                                      void                              *pOwner,
                                      void                              *pInput,
                                      CTIterator                        *pItr,
                                      void                              *pOutput,
                                      kal_uint32                        maxStep,
                                      srv_ies_async_callback_func_ptr   callback,
                                      void                              *pData);

kal_bool srv_ies_job_send_request(srv_ies_job_handle hJob);

srv_ies_result srv_ies_job_destroy(srv_ies_job_handle hJob);

srv_ies_result srv_ies_job_deinit(srv_ies_app_session_handle hApp);

srv_ies_result srv_ies_meta_init(srv_ies_app_session_handle hApp);

srv_ies_result srv_ies_meta_deinit(srv_ies_app_session_handle hApp);

#ifdef __cplusplus
}
#endif

#endif /* __IMG_EDT_SRV_H__ */
