#include "mmi_features.h"
#include "vfx_config.h"
#include "mmi_features_mtv_player.h"

<?xml version="1.0" encoding="UTF-8"?>


<APP id = "VAPP_PACKAGE_CONCURRENT">
#if defined(__MMI_VIDEO_PDL_YOUTUBE__)
    <APPCONCURRENT concurrent_w_order="APP_OPERA, VAPP_GALLERY_YOUTUBE_PGDL_PLAYER"/>
    #ifdef __LOW_COST_SUPPORT_COMMON__
    <APPCONCURRENT concurrent_w_order="VAPP_BROWSER_LOW_MEM, VAPP_GALLERY_YOUTUBE_PGDL_PLAYER"/>
    #else
    <APPCONCURRENT concurrent_w_order="VAPP_BROWSER, VAPP_GALLERY_YOUTUBE_PGDL_PLAYER"/>
    #endif

#endif
#if defined(__MMI_CAMCORDER__)
    #ifdef __LOW_COST_SUPPORT_COMMON__
    <APPCONCURRENT concurrent_w_order="VAPP_CAMCO_D, VAPP_GALLERY_IMAGE_VIEWER"/>
    <APPCONCURRENT concurrent_w_order="VAPP_CAMCO_D, VAPP_GALLERY_VIDEO_PLAYER"/>
    #else
    <APPCONCURRENT concurrent_w_order="VAPP_CAMCO, VAPP_GALLERY_IMAGE_VIEWER"/>
    <APPCONCURRENT concurrent_w_order="VAPP_CAMCO, VAPP_GALLERY_VIDEO_PLAYER"/>
    #endif
#endif
#if defined(__MMI_ATV_SUPPORT__) && defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_THUMBNAIL__)
    <APPCONCURRENT concurrent_w_order="VAPP_ATV, VAPP_GALLERY_VIDEO_PLAYER"/>
#endif
#if defined(__MMI_COSMOS_MOVIE_THEATER__)
    <APPCONCURRENT concurrent_w_order="VAPP_MOVIE_THEATER, VAPP_GALLERY_VIDEO_PLAYER"/>
#endif
#ifdef __LOW_COST_SUPPORT_COMMON__
    <APPCONCURRENT concurrent_w_order="VCUI_FMGR, VAPP_GALLERY_IMAGE_VIEWER"/>
    <APPCONCURRENT concurrent_w_order="VCUI_FMGR, VAPP_GALLERY_VIDEO_PLAYER"/>
#else
    <APPCONCURRENT concurrent_w_order="VAPP_FMGR, VAPP_GALLERY_IMAGE_VIEWER"/>
    <APPCONCURRENT concurrent_w_order="VAPP_FMGR, VAPP_GALLERY_VIDEO_PLAYER"/>
#endif
#if defined(__OP02__)
    <APPCONCURRENT concurrent_w_order="APP_OPERA, VAPP_GALLERY_STREAM_PLAYER"/>
#endif

#ifdef __AFX_RT_TEST__
    <APPCONCURRENT concurrent="FW_TEST2, FW_TEST3"/>
#endif

#ifdef __MMI_3D_MEDIA_CENTER__
    <APPCONCURRENT concurrent_w_order="VAPP_MEDIA_CENTER, VAPP_GALLERY"/>
    <APPCONCURRENT concurrent_w_order="VAPP_MEDIA_CENTER, VAPP_CAMCO"/>
    <APPCONCURRENT concurrent_w_order="VAPP_MEDIA_CENTER, VAPP_MUSIC_PLAYER"/>
    <APPCONCURRENT concurrent_w_order="VAPP_MEDIA_CENTER, VAPP_SOUNDREC"/>
    <APPCONCURRENT concurrent_w_order="VAPP_MEDIA_CENTER, VAPP_FM_RADIO"/>
#endif
</APP>
