#include "MMI_features.h" 
#include "GDI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<FILE_TYPES>
    <FILE_TYPE_INC file="GlobalResDef.h"/>
    <FILE_TYPE_INC file="FileMgrServiceResDef.h"/>
    <FILE_TYPE_INC file="ImageViewerResDef.h"/>
    <FILE_TYPE_INC file="ABRepeaterResDef.h"/>
    <FILE_TYPE_INC file="VdoPlyResDef.h"/>
    <FILE_TYPE_INC file="CatScreenBrowserResDef.h"/>
    #ifndef __COSMOS_MMI_PACKAGE__
    <FILE_TYPE_INC file="mmi_rp_app_profiles_def.h"/>
    #endif
    <FILE_TYPE_INC file="mmi_rp_app_font_manager_def.h"/>
<!-- 
**************************************** App Type *****************************************
-->

#ifndef __COSMOS_MMI_PACKAGE__
    <FILE_GROUP_TYPE type_id="FMGR_GROUP_IMAGE"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_IMG"
        option="MENU_ID_FMGR_IMG_TYPE_OPTIONS"
        use_option="MENU_ID_FMGR_IMG_FWD_USE_OPTION"
        send_option="MENU_ID_FMGR_IMG_FWD_SEND_OPTION"
        >
        <FILE_TYPE type_id="FMGR_TYPE_BMP" extension="BMP" large_icon="IMG_ID_FMGR_FILE_TYPE_BMP"/>
        #ifdef JPG_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_JPG" extension="JPG" large_icon="IMG_ID_FMGR_FILE_TYPE_JPG"/>
        <FILE_TYPE type_id="FMGR_TYPE_JPEG" extension="JPEG" large_icon="IMG_ID_FMGR_FILE_TYPE_JPG"/>
        #endif
        #ifdef GDI_USING_GIF
        <FILE_TYPE type_id="FMGR_TYPE_GIF" extension="GIF" large_icon="IMG_ID_FMGR_FILE_TYPE_GIF"/>
        #endif
        #ifdef GDI_USING_PNG
        <FILE_TYPE type_id="FMGR_TYPE_PNG" extension="PNG" large_icon="IMG_ID_FMGR_FILE_TYPE_PNG"/>
        #endif
        #ifdef GDI_USING_WBMP
        <FILE_TYPE type_id="FMGR_TYPE_WBMP" extension="WBMP" large_icon="IMG_ID_FMGR_FILE_TYPE_WBMP"/>
        <FILE_TYPE type_id="FMGR_TYPE_WBM" extension="WBM" large_icon="IMG_ID_FMGR_FILE_TYPE_WBMP"/>
        #endif
        #ifdef M3D_MMI_SUPPORT
        <FILE_TYPE type_id="FMGR_TYPE_M3D" extension="M3D" large_icon="IMG_ID_FMGR_FILE_TYPE_M3D"/>
        #endif
        <FILE_TYPE type_id="FMGR_TYPE_EMS" extension="EMS" large_icon="IMG_ID_FMGR_FILE_TYPE_EMS"/>
        <FILE_TYPE type_id="FMGR_TYPE_ANM" extension="ANM" large_icon="IMG_ID_FMGR_FILE_TYPE_ANM"/>
        #ifdef __MMI_SVG__
        <FILE_TYPE type_id="FMGR_TYPE_SVG" extension="SVG" large_icon="IMG_ID_FMGR_FILE_TYPE_SVG"/>
        #endif
        #ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_MAV" extension="MAV" large_icon="IMG_ID_FMGR_FILE_TYPE_MAV"/>
        #endif
    </FILE_GROUP_TYPE>

    <FILE_GROUP_TYPE type_id="FMGR_GROUP_AUDIO"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_AUD"
        option="MENU_ID_FMGR_AUD_TYPE_OPTIONS"
        use_option="MENU_ID_FMGR_AUD_FWD_USE_OPTION"
        send_option="MENU_ID_FMGR_AUD_FWD_SEND_OPTION"
        >
        <FILE_TYPE type_id="FMGR_TYPE_IMY" extension="IMY" large_icon="IMG_ID_FMGR_FILE_TYPE_IMY"/>
        <FILE_TYPE type_id="FMGR_TYPE_MID" extension="MID" large_icon="IMG_ID_FMGR_FILE_TYPE_MID"/>
        <FILE_TYPE type_id="FMGR_TYPE_MIDI" extension="MIDI" large_icon="IMG_ID_FMGR_FILE_TYPE_MID"/>
        <FILE_TYPE type_id="FMGR_TYPE_WAV" extension="WAV" large_icon="IMG_ID_FMGR_FILE_TYPE_WAV"/>
        <FILE_TYPE type_id="FMGR_TYPE_AMR" extension="AMR" large_icon="IMG_ID_FMGR_FILE_TYPE_AMR"/>
        #ifdef AAC_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AAC" extension="AAC" large_icon="IMG_ID_FMGR_FILE_TYPE_AAC"/>
        #endif
        #ifdef M4A_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_M4A" extension="M4A" large_icon="IMG_ID_FMGR_FILE_TYPE_M4A"/>
        #endif
        #if defined(DAF_DECODE) && defined(MUSICAM_DECODE)
        <FILE_TYPE type_id="FMGR_TYPE_DAF" extension="MP3" large_icon="IMG_ID_FMGR_FILE_TYPE_DAF"/>
        <FILE_TYPE type_id="FMGR_TYPE_MP2" extension="MP2" large_icon="IMG_ID_FMGR_FILE_TYPE_DAF"/>
        #elif defined(DAF_DECODE)
        <FILE_TYPE type_id="FMGR_TYPE_DAF" extension="MP3" large_icon="IMG_ID_FMGR_FILE_TYPE_DAF"/>
        #endif
        #ifdef __VM_CODEC_SUPPORT__        
        <FILE_TYPE type_id="FMGR_TYPE_VM" extension="VM" large_icon="IMG_ID_FMGR_FILE_TYPE_VM"/>
        #endif
        #ifdef AMRWB_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AWB" extension="AWB" large_icon="IMG_ID_FMGR_FILE_TYPE_AWB"/>
        #endif
        #ifdef AIFF_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AIF" extension="AIF" large_icon="IMG_ID_FMGR_FILE_TYPE_AIF"/>
        <FILE_TYPE type_id="FMGR_TYPE_AIFF" extension="AIFF" large_icon="IMG_ID_FMGR_FILE_TYPE_AIF"/>
        <FILE_TYPE type_id="FMGR_TYPE_AIFC" extension="AIFC" large_icon="IMG_ID_FMGR_FILE_TYPE_AIF"/>
        #endif
        #ifdef AU_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AU" extension="AU" large_icon="IMG_ID_FMGR_FILE_TYPE_AU"/>
        #endif
        #ifdef SND_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_SND" extension="SND" large_icon="IMG_ID_FMGR_FILE_TYPE_SND"/>
        #endif
        #ifdef YAMAHA_MA3
        <FILE_TYPE type_id="FMGR_TYPE_MMF" extension="MMF" large_icon="IMG_ID_FMGR_FILE_TYPE_DAF"/>
        #endif
        #ifdef WMA_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_WMA" extension="WMA" large_icon="IMG_ID_FMGR_FILE_TYPE_WMA"/>
        #endif
        #ifdef BSAC_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_BSAC" extension="BSAC" large_icon="IMG_ID_FMGR_FILE_TYPE_BSAC"/>
        #endif
        #ifdef KUR_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_KUR" extension="KUR" large_icon="IMG_ID_FMGR_FILE_TYPE_KUR"/>
        #endif
        #ifdef __RM_DEC_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_RA" extension="RA" large_icon="IMG_ID_FMGR_FILE_TYPE_RA"/>
        #endif
        #if !defined(MP4_DECODE) && defined(__MMI_PURE_AUDIO__)
        <FILE_TYPE type_id="FMGR_TYPE_3GP" extension="3GP" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_3G2" extension="3G2" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_MP4" extension="MP4" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_MPG" extension="MPG" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #endif
        #ifdef __APE_DECODE__
        <FILE_TYPE type_id="FMGR_TYPE_APE" extension="APE" large_icon="IMG_ID_FMGR_FILE_TYPE_APE"/>
        #endif
        #ifdef __VORBIS_DECODE__
        <FILE_TYPE type_id="FMGR_TYPE_OGG" extension="OGG" large_icon="IMG_ID_FMGR_FILE_TYPE_OGG"/>
        #endif
        #ifdef __FLAC_DECODE__
        <FILE_TYPE type_id="FMGR_TYPE_FLAC" extension="FLAC" large_icon="IMG_ID_FMGR_FILE_TYPE_FLAC"/>
        #endif
    </FILE_GROUP_TYPE>

    <FILE_GROUP_TYPE type_id="FMGR_GROUP_VIDEO"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_VDO"
        option="MENU_ID_FMGR_VID_TYPE_OPTIONS"
        use_option="MENU_ID_FMGR_VID_FWD_USE_OPTION"
        send_option="MENU_ID_FMGR_VID_FWD_SEND_OPTION"
        >
        #if defined(MP4_DECODE) 
        <FILE_TYPE type_id="FMGR_TYPE_3GP" extension="3GP" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_MP4" extension="MP4" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #endif
        #ifdef MP4_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_3G2" extension="3G2" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #endif
        #ifdef MJPG_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AVI" extension="AVI" large_icon="IMG_ID_FMGR_FILE_TYPE_AVI"/>
        #endif
        #ifdef __RM_DEC_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_RV" extension="RV" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_RM" extension="RM" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_RMVB" extension="RMVB" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #endif
        #ifdef __FLV_FILE_FORMAT_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_FLV" extension="FLV" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_F4V" extension="F4V" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #endif
        #ifdef __MKV_FILE_FORMAT_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_MKV" extension="MKV" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_WEBM" extension="WEBM" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #ifdef __VIDEO_3D_SIDE_BY_SIDE__
        <FILE_TYPE type_id="FMGR_TYPE_MK3D" extension="MK3D" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #endif
        #endif
        #ifdef __MOT_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_MOT" extension="MOT" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #endif
        #ifdef __KMV_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_KMV" extension="KMV" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        <FILE_TYPE type_id="FMGR_TYPE_QKMV" extension="QKMV" large_icon="IMG_ID_FMGR_FILE_TYPE_MP4"/>
        #endif
    </FILE_GROUP_TYPE>
    
    #ifdef __MMI_VIDEO_STREAM__
    <FILE_GROUP_TYPE type_id="FMGR_GROUP_STREAM"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_VDO"
        option="MENU_ID_FMGR_VID_TYPE_OPTIONS"
        send_option="MENU_ID_FMGR_VID_FWD_SEND_OPTION"
        >
        <FILE_TYPE type_id="FMGR_TYPE_SDP" extension="SDP" large_icon="IMG_ID_FMGR_FILE_TYPE_SDP" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_SDP" />
        <FILE_TYPE type_id="FMGR_TYPE_RAM" extension="RAM" large_icon="IMG_ID_FMGR_FILE_TYPE_RAM" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_RAM" />
    </FILE_GROUP_TYPE>
    #endif
#endif

#ifndef __COSMOS_MMI_PACKAGE__ 
    #ifdef __CERTMAN_SUPPORT__
    <FILE_GROUP_TYPE type_id="FMGR_GROUP_CERT"
        small_icon="IMG_ID_FMGR_FILE_TYPE_CER"
        option="MENU_ID_FMGR_CERT_TYPE_OPTIONS"
        >
        <FILE_TYPE type_id="FMGR_TYPE_P12" extension="P12" large_icon="IMG_ID_FMGR_CER_P12_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_CER" extension="CER" large_icon="IMG_ID_FMGR_CER_CER_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_PFX" extension="PFX" large_icon="IMG_ID_FMGR_CER_PFX_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_DER" extension="DER" large_icon="IMG_ID_FMGR_CER_DER_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_PEM" extension="PEM" large_icon="IMG_ID_FMGR_CER_PEM_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_P7B" extension="P7B" large_icon="IMG_ID_FMGR_CER_P7B_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_CRT" extension="CRT" large_icon="IMG_ID_FMGR_CER_CRT_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_SPC" extension="SPC" large_icon="IMG_ID_FMGR_CER_SPC_LARGE_TYPE"/>
    </FILE_GROUP_TYPE>
    #endif
#endif
        
#if defined (MRE_VERSION) && !defined(__MMI_EBOOK_READER__)
    <FILE_GROUP_TYPE type_id="FMGR_GROUP_MRE_TXT">
        <FILE_TYPE type_id="FMGR_TYPE_MRE_TXT" extension="TXT"/>
    </FILE_GROUP_TYPE>
#endif

#if (defined (__J2ME__)&& defined (__PLUTO_MMI_PACKAGE__) )
    <FILE_TYPE type_id="FMGR_TYPE_JAD" extension="JAD" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_JAVA" large_icon="IMG_ID_FMGR_FILE_TYPE_JAD" option="MENU_ID_FMGR_JAD_TYPE_OPTIONS"/>
    <FILE_TYPE type_id="FMGR_TYPE_JAR" extension="JAR" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_JAVA" large_icon="IMG_ID_FMGR_FILE_TYPE_JAR" option="MENU_ID_FMGR_JAR_TYPE_OPTIONS"/>
    #endif
#ifndef __COSMOS_MMI_PACKAGE__
    #ifdef __MMI_VCARD__
    <FILE_TYPE type_id="FMGR_TYPE_VCF" extension="VCF" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_VCF" large_icon="IMG_ID_FMGR_FILE_TYPE_VCF" use_option="MENU_ID_FMGR_VCARD_FWD_USE_OPTION" send_option="MENU_ID_FMGR_VCARD_FWD_SEND_OPTION"/>
    #endif

    #ifdef __MMI_VCALENDAR__
    <FILE_TYPE type_id="FMGR_TYPE_VCS" extension="VCS" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_VCS" large_icon="IMG_ID_FMGR_FILE_TYPE_VCS" use_option="MENU_ID_FMGR_VCAL_FWD_USE_OPTION" send_option="MENU_ID_FMGR_VCAL_FWD_SEND_OPTION"/>
    #endif
#endif

    <FILE_TYPE type_id="FMGR_TYPE_LRC" extension="LRC"/>
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    <FILE_TYPE type_id="FMGR_TYPE_THEME" extension="MED" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_THEME" large_icon="IMG_ID_FMGR_FILE_TYPE_THEME" option="MENU_ID_FMGR_THEME_TYPE_OPTIONS"/>
    #endif
    #ifdef __MMI_EBOOK_READER__
    <FILE_TYPE_INC file="mmi_rp_app_ebook_def.h"/>
    #endif
    #ifdef __MMI_EM_MISC_FOTA_DEBUG__
    <FILE_TYPE type_id="FMGR_TYPE_FOTA_FULL" extension=""/>
    #endif
    <FILE_TYPE type_id="FMGR_TYPE_DCF" extension="DCF"/>
    <FILE_TYPE type_id="FMGR_TYPE_DM" extension="DM"/>
    #if defined(__MMI_OP00_BARCODEREADER__)
    <FILE_TYPE type_id="FMGR_TYPE_MBC" extension="MBC" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_MBC" large_icon="IMG_ID_FMGR_FILE_TYPE_MBC" option="MENU_ID_BARCODEREADER_FILE_OPTION"/>
    #elif defined(__MMI_OP01_BARCODEREADER__)
    <FILE_TYPE type_id="FMGR_TYPE_MBC" extension="MBC" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_MBC" large_icon="IMG_ID_FMGR_FILE_TYPE_MBC"/>
    #endif
    #ifdef __MMI_UDX_SUPPORT__
    <FILE_TYPE type_id="FMGR_TYPE_UDX" extension="UDX" small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_UDX" large_icon="IMG_ID_FMGR_FILE_TYPE_UDX" use_option="MENU_ID_FMGR_UDX_FWD_USE_OPTION" send_option="MENU_ID_FMGR_UDX_FWD_SEND_OPTION"/>
    #endif
    #ifdef __MMI_IMPS__
    <FILE_TYPE type_id="FMGR_TYPE_IMPS_IM" extension="IM" small_icon="IMG_IMPS_FMGR_IM_SMALL_TYPE" large_icon="IMG_IMPS_FMGR_IM_LARGE_TYPE" option="MENU_ID_FMGR_IMPS_TYPE_OPTIONS"/>
    #endif
    #if defined (OBIGO_Q03C_MMS_V01) && !defined(__MMI_EBOOK_READER__)
    <FILE_TYPE type_id="FMGR_TYPE_MMS_TXT" extension="TXT"/>
    #endif
    #ifdef __QQMOVIE_SUPPORT__
    <FILE_TYPE type_id="FMGR_TYPE_3GQ" extension="3GQ" small_icon="0"/>
    #endif
    #ifdef __MMI_139_PUSH_MAIL__
    <FILE_TYPE type_id="FMGR_TYPE_HTM" extension="HTM" small_icon="0"/>
    <FILE_TYPE type_id="FMGR_TYPE_HTML" extension="HTML" small_icon="0"/>
    #endif
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__     
    <FILE_TYPE type_id="FMGR_TYPE_APPICON" extension="ACO" small_icon="0" option="MENU_ID_FMGR_APPICON_TYPE_OPTIONS"/>
#endif    
    <FILE_TYPE_DEC type_ids="FMGR_TYPE_BMP,FMGR_TYPE_JPG,FMGR_TYPE_JPEG,FMGR_TYPE_GIF,FMGR_TYPE_PNG,FMGR_TYPE_WBMP,FMGR_TYPE_WBM,FMGR_TYPE_M3D,FMGR_TYPE_EMS,FMGR_TYPE_ANM,FMGR_TYPE_SVG,FMGR_TYPE_IMY,FMGR_TYPE_MID,FMGR_TYPE_MIDI,FMGR_TYPE_WAV,FMGR_TYPE_AMR,FMGR_TYPE_AAC,FMGR_TYPE_DAF,FMGR_TYPE_MP2,FMGR_TYPE_VM,FMGR_TYPE_AWB,FMGR_TYPE_AIF,FMGR_TYPE_AIFF,FMGR_TYPE_AIFC,FMGR_TYPE_AU,FMGR_TYPE_SND,FMGR_TYPE_M4A,FMGR_TYPE_MMF,FMGR_TYPE_WMA,FMGR_TYPE_BSAC,FMGR_TYPE_KUR,FMGR_TYPE_3GP,FMGR_TYPE_MP4,FMGR_TYPE_APE,FMGR_TYPE_OGG,FMGR_TYPE_MPG,FMGR_TYPE_AVI,FMGR_TYPE_3G2,FMGR_TYPE_SDP,FMGR_TYPE_RAM,FMGR_TYPE_RA,FMGR_TYPE_RV,FMGR_TYPE_RM,FMGR_TYPE_RMVB,FMGR_TYPE_P12,FMGR_TYPE_CER,FMGR_TYPE_PFX,FMGR_TYPE_DER,FMGR_TYPE_PEM,FMGR_TYPE_P7B,FMGR_TYPE_CRT,FMGR_TYPE_SPC,FMGR_TYPE_WML,FMGR_TYPE_HTML,FMGR_TYPE_HTM,FMGR_TYPE_XHTML,FMGR_TYPE_WMLC,FMGR_TYPE_JAD,FMGR_TYPE_JAR,FMGR_TYPE_VCF,FMGR_TYPE_VCS,FMGR_TYPE_LRC,FMGR_TYPE_THEME,FMGR_TYPE_EBOOK_TXT,FMGR_TYPE_EBOOK_PDB,FMGR_TYPE_EBOOK_TXZ,FMGR_TYPE_EBOOK_PBZ,FMGR_TYPE_EBOOK_NF1,FMGR_TYPE_EBOOK_NF2,FMGR_TYPE_EBOOK_LTS,FMGR_TYPE_EBOOK_LTM,FMGR_TYPE_EBOOK_LTL,FMGR_TYPE_EBOOK_LPS,FMGR_TYPE_EBOOK_LPM,FMGR_TYPE_EBOOK_LPL,FMGR_TYPE_FOTA_FULL,FMGR_TYPE_DCF,FMGR_TYPE_VXP,FMGR_TYPE_DM,FMGR_TYPE_URL,FMGR_TYPE_VBM,FMGR_TYPE_MBC,FMGR_TYPE_UDX,FMGR_TYPE_3GQ,FMGR_TYPE_IMPS_IM,FMGR_TYPE_MMS_TXT,FMGR_TYPE_HTM,FMGR_TYPE_HTML,FMGR_TYPE_APPICON"/>
</FILE_TYPES>
