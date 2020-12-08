#include "MMI_features.h"
#include "GDI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<FILE_TYPES>

#ifdef __COSMOS_MMI_PACKAGE__
    <FILE_TYPE_INC file="GlobalResDef.h"/>
    <FILE_TYPE_INC file="FileMgrServiceResDef.h"/>
    <FILE_TYPE_INC file="mmi_rp_vapp_gallery_def.h"/>
<!--
**************************************** App Type *****************************************
-->

    <FILE_GROUP_TYPE type_id="FMGR_GROUP_IMAGE"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_IMG"
        option="MENU_ID_VAPP_GALLERY_IMAGE_OPTION"
        send_option="MENU_ID_VAPP_GALLERY_IMAGE_SEND_OPTION"
        >

        <FILE_TYPE type_id="FMGR_TYPE_BMP" extension="BMP" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_GIF" extension="GIF" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_WBMP" extension="WBMP" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_WBM" extension="WBM" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>

        #ifdef JPG_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_JPG" extension="JPG" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_JPEG" extension="JPEG" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        #endif

        #ifdef GDI_USING_PNG
        <FILE_TYPE type_id="FMGR_TYPE_PNG" extension="PNG" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        #endif

        #ifdef M3D_MMI_SUPPORT
        <FILE_TYPE type_id="FMGR_TYPE_M3D" extension="M3D" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        #endif

        #ifdef __MMI_SVG__
        <FILE_TYPE type_id="FMGR_TYPE_SVG" extension="SVG" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        #endif

        #ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_MAV" extension="MAV" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_IMAGE"/>
        #endif

        <FILE_OPTION_HDLR option="MENU_ID_VAPP_GALLERY_IMAGE_OPEN" handler="vapp_gallery_image_option_open_handler"/>

    </FILE_GROUP_TYPE>

    <FILE_GROUP_TYPE type_id="FMGR_GROUP_VIDEO"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_VDO"
        option="MENU_ID_VAPP_GALLERY_VIDEO_OPTION"
        >
        #if defined(MP4_DECODE)
        <FILE_TYPE type_id="FMGR_TYPE_3GP" extension="3GP" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        <FILE_TYPE type_id="FMGR_TYPE_MP4" extension="MP4" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif
        #ifdef MP4_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_3G2" extension="3G2" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif
        #ifdef MJPG_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AVI" extension="AVI" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif
        #ifdef __RM_DEC_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_RV" extension="RV" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        <FILE_TYPE type_id="FMGR_TYPE_RM" extension="RM" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        <FILE_TYPE type_id="FMGR_TYPE_RMVB" extension="RMVB" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif
        #ifdef __FLV_FILE_FORMAT_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_FLV" extension="FLV" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        <FILE_TYPE type_id="FMGR_TYPE_F4V" extension="F4V" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif
        #ifdef __MKV_FILE_FORMAT_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_MKV" extension="MKV" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        <FILE_TYPE type_id="FMGR_TYPE_WEBM" extension="WEBM" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif
        #if defined(__MKV_FILE_FORMAT_SUPPORT__) && defined(__VIDEO_3D_SIDE_BY_SIDE__)
        <FILE_TYPE type_id="FMGR_TYPE_MK3D" extension="MK3D" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif

        #ifdef __MOT_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_MOT" extension="MOT" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif
        
        #ifdef __KMV_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_KMV" extension="KMV" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        <FILE_TYPE type_id="FMGR_TYPE_QKMV" extension="QKMV" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO"/>
        #endif
        <FILE_OPTION_HDLR option="MENU_ID_VAPP_GALLERY_VIDEO_OPEN" handler="vapp_gallery_video_option_open_handler"/>
    </FILE_GROUP_TYPE>

    #ifdef __MMI_VIDEO_STREAM__
    <FILE_GROUP_TYPE type_id="FMGR_GROUP_STREAM"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_VDO"
        option="MENU_ID_VAPP_GALLERY_STREAM_OPTION"
        >
        <FILE_TYPE type_id="FMGR_TYPE_SDP" extension="SDP" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO" />
        <FILE_TYPE type_id="FMGR_TYPE_RAM" extension="RAM" large_icon="IMG_ID_VAPP_GALLERY_ID_FILE_TYPE_VIDEO" />

        <FILE_OPTION_HDLR option="MENU_ID_VAPP_GALLERY_STREAM_OPEN" handler="vapp_gallery_stream_option_open_handler"/>
    </FILE_GROUP_TYPE>
    #endif

#endif

</FILE_TYPES>
