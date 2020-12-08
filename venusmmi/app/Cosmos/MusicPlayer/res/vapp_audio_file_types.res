#include "MMI_features.h" 
#include "GDI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<FILE_TYPES>

#if defined(__COSMOS_MMI_PACKAGE__) && defined(__COSMOS_MUSICPLY__)
    <FILE_TYPE_INC file="GlobalResDef.h"/>
    <FILE_TYPE_INC file="FileMgrServiceResDef.h"/>
    <FILE_TYPE_INC file="mmi_rp_vapp_music_player_def.h"/>
<!-- 
**************************************** App Type *****************************************
-->

    <FILE_GROUP_TYPE type_id="FMGR_GROUP_AUDIO"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_AUD"
        option="MENU_ID_VAPP_MUSIC_PLAYER_AUDIO_OPTION"
        send_option="MENU_ID_FMGR_AUD_FWD_SEND_OPTION"
        >
        <FILE_TYPE type_id="FMGR_TYPE_IMY" extension="IMY" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_MID" extension="MID" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_MIDI" extension="MIDI" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_WAV" extension="WAV" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_AMR" extension="AMR" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #ifdef AAC_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AAC" extension="AAC" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef M4A_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_M4A" extension="M4A" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #if defined(DAF_DECODE) && defined(MUSICAM_DECODE)
        <FILE_TYPE type_id="FMGR_TYPE_DAF" extension="MP3" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_MP2" extension="MP2" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #elif defined(DAF_DECODE)
        <FILE_TYPE type_id="FMGR_TYPE_DAF" extension="MP3" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        <FILE_TYPE type_id="FMGR_TYPE_VM" extension="VM" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #ifdef AMRWB_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AWB" extension="AWB" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef AIFF_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AIF" extension="AIF" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_AIFF" extension="AIFF" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_AIFC" extension="AIFC" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef AU_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_AU" extension="AU" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef SND_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_SND" extension="SND" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef YAMAHA_MA3
        <FILE_TYPE type_id="FMGR_TYPE_MMF" extension="MMF" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef WMA_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_WMA" extension="WMA" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef BSAC_DECODE
        <FILE_TYPE type_id="FMGR_TYPE_BSAC" extension="BSAC" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef __RM_DEC_SUPPORT__
        <FILE_TYPE type_id="FMGR_TYPE_RA" extension="RA" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #if !defined(MP4_DECODE) && defined(__MMI_PURE_AUDIO__)
        <FILE_TYPE type_id="FMGR_TYPE_3GP" extension="3GP" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        <FILE_TYPE type_id="FMGR_TYPE_MP4" extension="MP4" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef __APE_DECODE__
        <FILE_TYPE type_id="FMGR_TYPE_APE" extension="APE" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #if defined(__VORBIS_DECODE__) || defined(__VORBIS_ENCODE__)
        <FILE_TYPE type_id="FMGR_TYPE_OGG" extension="OGG" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        #ifdef __FLAC_DECODE__
        <FILE_TYPE type_id="FMGR_TYPE_FLAC" extension="FLAC" large_icon="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE"/>
        #endif
        <FILE_OPTION_HDLR option="MENU_ID_VAPP_MUSIC_PLAYER_AUDIO_OPEN" handler="vapp_music_player_audio_option_open_handler"/>
    </FILE_GROUP_TYPE>

#endif

</FILE_TYPES>
