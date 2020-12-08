#ifndef _VAPP_GALLERY_GPROT_H_
#define _VAPP_GALLERY_GPROT_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#include "mmi_features.h"
#include "gdi_include.h"
#include "mdi_include.h"
#include "mdi_video.h"
#include "MediaCacheSrvMem.h"
#include "CameraGyroSrvGport.h"
#ifdef __MMI_VIDEO_PDL__
#include "DLAgentSrvGProt.h"
#endif

/*****************************************************************************
 * Color format configurations (RGB565 <---> RGB888)
 * Gallery RGB888 requires MDI support
 * Also, MoDIS + OpenGL does not support RGB888 format (requires GL_BGR_EXT support)
 *****************************************************************************/
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && \
    defined(__MDI_DISPLAY_RGB888_SUPPORT__) && \
    !(defined(__VENUS_3D_UI_ENGINE__) && !defined(__MTK_TARGET__))
#define VAPP_GALLERY_IMG_VIEWER_BPP (MAIN_MEDIA_LAYER_BITS_PER_PIXEL >> 3)
#define VAPP_GALLERY_THUMB_BPP VAPP_GALLERY_IMG_VIEWER_BPP      // Thumbnail BPP may use 2 (RGB565), can reduce CUI memory footprint.
#define VAPP_GALLERY_3D_VRT_MEM_FACTOR 26
#else
#define VAPP_GALLERY_IMG_VIEWER_BPP 2
#define VAPP_GALLERY_THUMB_BPP VAPP_GALLERY_IMG_VIEWER_BPP
#define VAPP_GALLERY_3D_VRT_MEM_FACTOR 14
#endif

#ifdef __LOW_COST_SUPPORT_COMMON__
    // VAPP_GALLERY_DB_L1_BUF_SIZE
    #define VAPP_GALLERY_DB_L1_BUF_SIZE (1 * GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP + 320 * 1024)
    // VAPP_GALLERY_IMGAGE_VIEWER_REDUCE_PREVIEW_L1_CACHE
    // reduce buffer while image viewer dose not show preview image of prev and  next image
    #define VAPP_GALLERY_IMAGE_VIEWER_REDUCE_PREVIEW_L1_CACHE (2 * GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP)
    // VAPP_GALLERY_IMAGE_VIEWER_REDUCE_ENHANCE_BUFF
    // instead of preserving detail image buffer,
    // image viewer decodes detail image and clip it to shop evert time
    #define VAPP_GALLERY_IMAGE_VIEWER_REDUCE_ENHANCE_BUFF (3 * GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP)
#else
	#define __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    // VAPP_GALLERY_DB_L1_BUF_SIZE
    #if (VAPP_GALLERY_IMG_VIEWER_BPP == 3)
    #define VAPP_GALLERY_DB_L1_BUF_SIZE SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_DEFAULT_24BIT
    #else
    #define VAPP_GALLERY_DB_L1_BUF_SIZE SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_DEFAULT
    #endif
    // VAPP_GALLERY_IMGAGE_VIEWER_REDUCE_PREVIEW_L1_CACHE
    #define VAPP_GALLERY_IMGAGE_VIEWER_REDUCE_PREVIEW_L1_CACHE (0)
    // VAPP_GALLERY_IMAGE_VIEWER_REDUCE_ENHANCE_BUFF
    #define VAPP_GALLERY_IMAGE_VIEWER_REDUCE_ENHANCE_BUFF (0)
#endif /*__LOW_COST_SUPPORT_COMMON__*/

//ImageViewer Zoom in/out compile option 2012-11-19
#ifndef __MMI_GALLERY_SLIM__
#define __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
#endif

/*****************************************************************************
 * preserved offset for 32 byte align and address in Image Viewer
 *****************************************************************************/
// in order to accelerate SW LT calculation, Image Viewer will offset L1 to 32-byte aligned address and size,
// since MoDIS does not return 32-byte aligned address,  we need to preserve 32-byte to avoid insufficient cache caused by offseting ptr
#if defined(__MTK_TARGET__)
#define VAPP_GALLERY_IMG_VIEWER_32_BYTE_ALIGNED_PRESERVED_OFFSET 0
#else
#define VAPP_GALLERY_IMG_VIEWER_32_BYTE_ALIGNED_PRESERVED_OFFSET 32
#endif

/*****************************************************************************
 * Video Subtitle Memory config
 *****************************************************************************/
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
#define VAPP_GALLERY_VIDEO_SUBTITLE_DISPLAY_WIDTH  MDI_VDOPLY_MAX_SUBTITLE_LAYER_WIDTH
#define VAPP_GALLERY_VIDEO_SUBTITLE_DISPLAY_HEIGHT MDI_VDOPLY_MAX_SUBTITLE_LAYER_HEIGHT
#define VAPP_GALLERY_VIDEO_SUBTITLE_BUF (VAPP_GALLERY_VIDEO_SUBTITLE_DISPLAY_WIDTH * VAPP_GALLERY_VIDEO_SUBTITLE_DISPLAY_HEIGHT * 4)
#else
#define VAPP_GALLERY_VIDEO_SUBTITLE_DISPLAY_WIDTH  0
#define VAPP_GALLERY_VIDEO_SUBTITLE_DISPLAY_HEIGHT 0
#define VAPP_GALLERY_VIDEO_SUBTITLE_BUF (0)
#endif

/*****************************************************************************
 * MAV Memory config
 *****************************************************************************/
#if !defined(MOTION_SENSOR_SUPPORT) && defined(__CAMERA_GYRO_SUPPORT__) && defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
#define VAPP_GALLERY_CAMERA_SENSOR_MEM (CAMERA_GYRO_SENSOR_EXT_MEM)
#else
#define VAPP_GALLERY_CAMERA_SENSOR_MEM (0)
#endif

/*****************************************************************************
 * preserved offset for header of ADM memory allocation
 *****************************************************************************/
#define VAPP_GALLERY_ADM_PRESERVED_OFFSET (100 * 1024)

/*****************************************************************************
 * Memory configurations
 *****************************************************************************/
#ifdef __MMI_GALLERY_SLIM__
#define VAPP_GALLERY_VRT_RENDER_CMD_EXTRA_SIZE (0)
#else
#define VAPP_GALLERY_VRT_RENDER_CMD_EXTRA_SIZE (100 * 1024)     // extra size for VRT render commands.
#endif

/* no db memory config */
#ifdef __MMI_GALLERY_SLIM__
#define VAPP_GALLERY_DB_WORKING_BUF (0)
#else
#define VAPP_GALLERY_DB_WORKING_BUF (400 * 1024)                // for VappGalleryDB working size (SQLite + IO Buf of IVD)
#endif

#define VAPP_GALLERY_IMG_VIEWER_PREVIEW_CACHE_COUNT (3)         // for store next/previous/current preview

#ifdef __LOW_COST_SUPPORT_COMMON__
#define VAPP_GALLERY_MEDIA_GRID_FG_SIZE_FACTOR (2)
#else
#define VAPP_GALLERY_MEDIA_GRID_FG_SIZE_FACTOR (1)
#endif /*__LOW_COST_SUPPORT_COMMON__*/

// define enhance buffer ratio
#ifdef __VENUS_3D_UI_ENGINE__
    #define VAPP_GALLERY_IMG_VIEWER_ENHANCE_BUFFER_RATIO (4)
#else
    #if defined(__MMI_COSMOS_GALLERY_IMAGE_VIEWER_MAGNIFICATION_SLIM__) || defined(__LOW_COST_SUPPORT_COMMON__)
    #define VAPP_GALLERY_IMG_VIEWER_ENHANCE_BUFFER_RATIO (4)
    #else
    #define VAPP_GALLERY_IMG_VIEWER_ENHANCE_BUFFER_RATIO (9)
    #endif
#endif

/* no enhance buffer config when there is no image zoom in/out support */
#if (defined(__MMI_GALLERY_SLIM__) && defined(__VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__)) || !defined(__MMI_GALLERY_SLIM__)
// define enhance buf size
#define VAPP_GALLERY_IMG_VIEWER_ENHANCE_FG_SIZE  (GDI_LCD_WIDTH * GDI_LCD_HEIGHT\
                                                  * VAPP_GALLERY_IMG_VIEWER_BPP\
                                                  * VAPP_GALLERY_IMG_VIEWER_ENHANCE_BUFFER_RATIO)
#else
#define VAPP_GALLERY_IMG_VIEWER_ENHANCE_FG_SIZE  (0)
#endif

// Preview media grid cell buffer size
#ifdef __MMI_GALLERY_SLIM__
// Preview(L1) cell buf size
#define VAPP_GALLERY_IMG_VIEWER_PREVIEW_FG_SIZE (GDI_LCD_WIDTH * GDI_LCD_HEIGHT\
                                         * VAPP_GALLERY_IMG_VIEWER_BPP\
                                         * VAPP_GALLERY_IMG_VIEWER_PREVIEW_CACHE_COUNT\
                                         + VAPP_GALLERY_IMG_VIEWER_32_BYTE_ALIGNED_PRESERVED_OFFSET\
                                         + VAPP_GALLERY_ADM_PRESERVED_OFFSET)

#define VAPP_GALLERY_MEDIA_GRID_FG_SIZE(N) (GDI_LCD_WIDTH * GDI_LCD_HEIGHT\
                                         * VAPP_GALLERY_IMG_VIEWER_BPP\
                                         * N\
                                         / VAPP_GALLERY_MEDIA_GRID_FG_SIZE_FACTOR\
                                         + VAPP_GALLERY_IMG_VIEWER_32_BYTE_ALIGNED_PRESERVED_OFFSET)

#define VAPP_GALLERY_MEDIA_GRID_FG_SIZE_EX(N, M) (GDI_LCD_WIDTH * GDI_LCD_HEIGHT\
                                         * VAPP_GALLERY_IMG_VIEWER_BPP\
                                         * N\
                                         / M\
                                         + VAPP_GALLERY_IMG_VIEWER_32_BYTE_ALIGNED_PRESERVED_OFFSET)
#else
// Preview(L1) cell buf size
#define VAPP_GALLERY_IMG_VIEWER_PREVIEW_FG_SIZE (GDI_LCD_WIDTH * GDI_LCD_HEIGHT\
                                         * VAPP_GALLERY_IMG_VIEWER_BPP\
                                         * VAPP_GALLERY_IMG_VIEWER_PREVIEW_CACHE_COUNT\
                                         + VAPP_GALLERY_DB_L1_BUF_SIZE\
                                         + VAPP_GALLERY_IMG_VIEWER_32_BYTE_ALIGNED_PRESERVED_OFFSET\
                                         + SRV_MEDIACACHE_RUN_BUF_SIZE(VAPP_GALLERY_IMG_VIEWER_PREVIEW_CACHE_COUNT))

#define VAPP_GALLERY_MEDIA_GRID_FG_SIZE(N) (GDI_LCD_WIDTH * GDI_LCD_HEIGHT\
                                         * VAPP_GALLERY_IMG_VIEWER_BPP\
                                         * N\
                                         / VAPP_GALLERY_MEDIA_GRID_FG_SIZE_FACTOR\
                                         + SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_DEFAULT\
                                         + VAPP_GALLERY_IMG_VIEWER_32_BYTE_ALIGNED_PRESERVED_OFFSET\
                                         + SRV_MEDIACACHE_RUN_BUF_SIZE(N))

#define VAPP_GALLERY_MEDIA_GRID_FG_SIZE_EX(N, M) (GDI_LCD_WIDTH * GDI_LCD_HEIGHT\
                                         * VAPP_GALLERY_IMG_VIEWER_BPP\
                                         * N\
                                         / M\
                                         + SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_DEFAULT\
                                         + VAPP_GALLERY_IMG_VIEWER_32_BYTE_ALIGNED_PRESERVED_OFFSET\
                                         + SRV_MEDIACACHE_RUN_BUF_SIZE(N))

#endif

// memory config for Image Viewer
// VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE for project enable decode full enhance image
// VAPP_GALLERY_IMG_VIEWER_SLIM_FG_SIZE and VAPP_GALLERY_IMG_VIEWER_SLIM_LITE_FG_SIZE for project support partial enhance decode

/* no enhance buffer config when there is no image zoom in/out support */
#define VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_ENHANCE_FG_SIZE + VAPP_GALLERY_IMG_VIEWER_PREVIEW_FG_SIZE)
#if defined(__MMI_GALLERY_SLIM__) && !defined(__VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__)
#define VAPP_GALLERY_IMG_VIEWER_SLIM_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_PREVIEW_FG_SIZE)
#define VAPP_GALLERY_IMG_VIEWER_SLIM_LITE_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_PREVIEW_FG_SIZE)
#elif defined(__MMI_GALLERY_SLIM__) && defined(__VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__)
#define VAPP_GALLERY_IMG_VIEWER_SLIM_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE\
                                             - VAPP_GALLERY_IMAGE_VIEWER_REDUCE_ENHANCE_BUFF)
#define VAPP_GALLERY_IMG_VIEWER_SLIM_LITE_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE\
                                                   - VAPP_GALLERY_IMAGE_VIEWER_REDUCE_ENHANCE_BUFF)
#else
#define VAPP_GALLERY_IMG_VIEWER_SLIM_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE\
                                             - VAPP_GALLERY_IMAGE_VIEWER_REDUCE_ENHANCE_BUFF)
#define VAPP_GALLERY_IMG_VIEWER_SLIM_LITE_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE\
                                                   - VAPP_GALLERY_IMAGE_VIEWER_REDUCE_PREVIEW_L1_CACHE\
                                                   - VAPP_GALLERY_IMAGE_VIEWER_REDUCE_ENHANCE_BUFF)
#endif

// memory config for CUI
#define VCUI_GALLERY_IMG_VIEWER_FG_SIZE (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP)
#define VCUI_GALLERY_WALLPAPER_PICKER_FG_SIZE (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP)
// image viewer cp with async content provider FG
#define VAPP_GALLERY_ASYNC_MEDIALIST_L1_PREVIEW_FG_SIZE  (3 * GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_IMG_VIEWER_BPP\
                                                          + VAPP_GALLERY_ADM_PRESERVED_OFFSET)
// media grid cp with async content provider FG
#define VAPP_GALLERY_ASYNC_MEDIALIST_THUMB_FG_SIZE  (2 * GDI_LCD_WIDTH * GDI_LCD_HEIGHT * VAPP_GALLERY_THUMB_BPP)
// extra base size for index page
#define VAPP_GALLERY_INDEX_PAGE_MAX_THUMB_DIM 80

#ifdef __MMI_GALLERY_SLIM__
#define VAPP_GALLERY_INDEX_PAGE_EXTRA_BASE 0
#else
#define VAPP_GALLERY_INDEX_PAGE_EXTRA_BASE (VAPP_GALLERY_INDEX_PAGE_MAX_THUMB_DIM * VAPP_GALLERY_INDEX_PAGE_MAX_THUMB_DIM * VAPP_GALLERY_THUMB_BPP * 3)
#endif

// memory config for Cosmos SLIM project
// in Cosmos SLIM projects, Gallery Image Viewer supports partial enhance decode except 5M projects
#ifdef __LOW_COST_SUPPORT_COMMON__
#define VAPP_GALLERY_VID_PICKER_MEDIA_GRID_FG_SIZE (VAPP_GALLERY_MEDIA_GRID_FG_SIZE_EX(1, 1))
#define VAPP_GALLERY_IMG_PICKER_FG_SIZE (VAPP_GALLERY_MEDIA_GRID_FG_SIZE_EX(3, 2))
#define VAPP_GALLERY_SHOOTING_GRID_FG_SIZE (VAPP_GALLERY_MEDIA_GRID_FG_SIZE(3))
    #if defined(__MMI_COSMOS_GALLERY_SLIM_PROFILE_5M__)
    #define VAPP_GALLERY_IMG_VIEWER_FG_SIZE      (VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE)
    #define VAPP_GALLERY_IMG_VIEWER_CONC_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE)
    #else
    #define VAPP_GALLERY_IMG_VIEWER_FG_SIZE      (VAPP_GALLERY_IMG_VIEWER_SLIM_FG_SIZE)
    #define VAPP_GALLERY_IMG_VIEWER_CONC_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_SLIM_LITE_FG_SIZE)
    #endif
#else
#define VAPP_GALLERY_VID_PICKER_MEDIA_GRID_FG_SIZE (VAPP_GALLERY_MEDIA_GRID_FG_SIZE(2))
#define VAPP_GALLERY_IMG_PICKER_FG_SIZE (VAPP_GALLERY_MEDIA_GRID_FG_SIZE_EX(3, 1))
#define VAPP_GALLERY_IMG_VIEWER_FG_SIZE      (VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE)
#define VAPP_GALLERY_IMG_VIEWER_CONC_FG_SIZE (VAPP_GALLERY_IMG_VIEWER_FULL_FG_SIZE)
#endif /*__LOW_COST_SUPPORT_COMMON__*/

/*****************************************************************************
 * Launch functions
 *****************************************************************************/
typedef struct vapp_gallery_image_viewer_launch_option_struct
{
    const WCHAR *title_string;  /* overrides image viewer page title bar text. This string is copied. */
    MMI_BOOL content_is_image;  /* MMI_TRUE if file is image */
    MMI_BOOL show_blank_page;   /* allow file_path to be empty and display a blank page */
    MMI_BOOL disable_SSE;       /* disable SSE */
    MMI_BOOL confirm_scenario;  /* only show ok and delete button. While user confirm the preview result, exist viewer*/
    FMGR_FILTER *filter;        /* specify file type filter*/
} vapp_gallery_image_viewer_launch_option_struct;

/*
Init vapp_gallery_image_viewer_launch_option_struct
*/
extern void vapp_gallery_image_viewer_launch_option_init(vapp_gallery_image_viewer_launch_option_struct *);

/*
Launches Gallery Image Viewer with a single file
PARAM
file_path       [IN]: path of the media file to be opened. NULL-terminated. This string is copied.
option          [IN]: OPTIONAL, may be NULL.
*/
extern MMI_ID vapp_gallery_image_viewer_launch(const WCHAR* file_path, const vapp_gallery_image_viewer_launch_option_struct *option);

/*
Launches Gallery Image Viewer, viewing a folder (only images in the folder)
PARAM
folder_path     [IN]: path of folder_path. NULL-terminated. This string is copied.
option          [IN]: OPTIONAL, may be NULL.
*/
extern MMI_ID vapp_gallery_image_viewer_folder_launch(const WCHAR* folder_path, const vapp_gallery_image_viewer_launch_option_struct *option);

/*
Struct uses to notify Apps which launchs video player about video play result info 
*/
typedef struct vapp_gallery_last_play_struct
{
    const WCHAR *file_path;
    U64 last_play_time;
}vapp_gallery_last_play_struct;

extern void vapp_gallery_last_play_struct_init(vapp_gallery_last_play_struct *);

typedef void (*PFN_VAPP_GALLERY_LAST_PLAY_TIME_PROC)(vapp_gallery_last_play_struct*, void*);

typedef struct vapp_gallery_video_player_launch_option_struct
{
    const WCHAR *title_string;  /* overrides video player page title bar text. This string is copied. */
    MMI_BOOL disable_SSE;       /* disable SSE */
    U64 start_time_hint;        /* specify video start time */
    PFN_VAPP_GALLERY_LAST_PLAY_TIME_PROC user_proc; /* callback for App which launchs video player to update/process video play result*/
    void* user_data;
} vapp_gallery_video_player_launch_option_struct;

/*
Init vapp_gallery_video_player_launch_option_struct
*/
extern void vapp_gallery_video_player_launch_option_init(vapp_gallery_video_player_launch_option_struct *);

/*
Launches Gallery Video Player with a single file
PARAM
file_path       [IN]: path of the media file to be opened. NULL-terminated. This string is copied.
option          [IN]: OPTIONAL, may be NULL.
*/
extern MMI_ID vapp_gallery_video_player_launch(const WCHAR* file_path, const vapp_gallery_video_player_launch_option_struct *option);

/*
Progressive download support
*/
#ifdef __MMI_VIDEO_PDL__
extern void vapp_gallery_pdl_da_notify_video_file(
        	S32	session_id,
        	S32	mime_type,                  
        	S32	mime_subtype, 
        	S32 action,
        	U32	filesize,
        	CHAR *url,                        
        	CHAR *mime_type_string,           
        	U32	content_len,
        	CHAR *content,
        	srv_da_setting_struct *settings_p);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifdef __cplusplus
class VappGalleryStreamingSetting
{
public:
    VappGalleryStreamingSetting();
    ~VappGalleryStreamingSetting();

    // simCardIndex ranges from 0 ~ (MMI_MAX_SIM_NUM - 1)
    VfxU32 getSimAccount(VfxS32 simCardIndex) const;
    void setSimAccount(VfxS32 simCardIndex, VfxU32 dataAccountId);

    VfxU32 getActiveAccountId()const;

    // Mark an account id as "invalid", if we're currently using it,
    // reset to use default account (automatic)
    void invalidateAccountId(U32 accountId);

protected:
    void readFromNVRAM();
    void flushToNVRAM();

    // re-encode account id with run-time appid
    VfxU32 verifyAccountId(VfxS32 simCardIdx, VfxU32 dataAccountId) const;

    // maps SIM card index to MMI Cache item id
    U16 getCacheIdFromSimIndex(VfxS32 simCardIndex);

private:
    VfxU32 m_simDataAccountId[MMI_MAX_SIM_NUM];
};
#endif /* __cplusplus */

#endif /* _VAPP_GALLERY_GPROT_H_ */
