# Define source file lists to SRC_LIST
SRC_LIST = 

SRC_LIST += hal\video\demuxer\provider\src\source_provider_component.c \
            hal\video\demuxer\provider\src\source_provider_isolation.c \
            hal\video\demuxer\provider\src\provider_utility.c \
            hal\video\demuxer\provider\src\avi_provider.c

ifneq ($(filter __VIDEO_ARCHI_V2__,$(strip $(MODULE_DEFS))),)
    ifneq ($(filter __M3GPMP4_FILE_FORMAT_SUPPORT__,$(strip $(MODULE_DEFS))),)
        SRC_LIST += hal\video\demuxer\provider\src\mp4_provider.c
    endif
    ifneq ($(filter MJPG_DECODE,$(strip $(MODULE_DEFS))),)
        #SRC_LIST += hal\video\demuxer\provider\src\avi_media_provider.c
    endif
endif

#
# MP4 Parser
#
ifneq ($(filter __M3GPMP4_FILE_FORMAT_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\video\demuxer\mp4_parser\src\mp4_parser.c \
              hal\video\demuxer\mp4_parser\src\mp4_parser_audio.c \
              hal\video\demuxer\mp4_parser\src\mp4_parser_stbl.c \
              hal\video\demuxer\mp4_parser\src\mp4_parser_udat.c \
              hal\video\demuxer\mp4_parser\src\mp4_parser_video.c 
endif

#
# FLV File Format
#
# ifneq ($(filter __FLV_FILE_FORMAT_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\video\demuxer\provider\src\flv_provider.c \
            hal\video\demuxer\provider\src\flv_parser.c
# endif            

#
# MKV File Format
#
# ifneq ($(filter __MKV_FILE_FORMAT_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\video\demuxer\provider\src\mkv_provider.c \
            hal\video\demuxer\provider\src\mkv_parser.c
# endif  

# Define include path lists to INC_DIR
INC_DIR = interface\hal\video \
          hal\video\mpl\inc \
          hal\video\custom \
          hal\video\decoder\include \
          hal\video\demuxer\provider\inc \
          hal\video\demuxer\mp4_parser\inc \
          media\common\include \
          custom\video \
          hal\video\fluency\include \
          hal\system\dcmgr\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


