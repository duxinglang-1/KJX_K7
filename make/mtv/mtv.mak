# Define source file lists to SRC_LIST
SRC_LIST = media\mtv\src\mtv_bits.c \
           media\mtv\src\mtv_main.c \
           media\mtv\src\mtv_sm.c \
           media\mtv\src\mtv_buffer_engine.c \
           media\mtv\src\mtv_cached_io.c \
           media\mtv\src\mtv_async_io.c \
           media\mtv\src\mtv_concealment.c

ifneq ($(filter __CMMB_SUPPORT__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += media\mtv\src\mtv_recorder.c \
                media\mtv\src\mtv_streaming_player_v2.c \
                media\mtv\src\mtv_output_mp4.c \
                media\mtv\src\mtv_output_mp2.c \
                media\mtv\src\mtv_output_wav.c \
                media\mtv\src\mtv_src_stat.c \
                media\mtv\src\cmmb_esg_parser.c \
                media\mtv\src\cmmb_sp_mbbms.c \
                media\mtv\src\cmmb_rx.c \
                media\mtv\src\cmmb_sp.c \
                media\mtv\src\cmmb_esg.c \
                media\mtv\src\cmmb_mfs_demod.c \
                media\mtv\src\cmmb_demux.c \
                media\mtv\src\cmmb_eb.c \
                media\mtv\src\cmmb_ca_nagra.c \
                media\mtv\src\cmmb_ca_nagra_debug.c \
                media\mtv\src\cmmb_ca_card.c \
                media\mtv\src\cmmb_ca_mmc.c
endif

ifneq ($(filter __ATV_SUPPORT__,$(strip $(MODULE_DEFS))),)
    SRC_LIST += media\mtv\src\atv_sp.c \
                media\mtv\src\camera_sp.c \
                media\mtv\src\atv_play_ctrl.c
endif

ifneq ($(filter __CMMB_CAS_MBBMS_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += media\mtv\src\mbbms_main.c \
                media\mtv\src\mbbms_sg.c \
                media\mtv\src\mbbms_sg_parser.c
endif

ifneq ($(filter __MBBMS_V30__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += media\mtv\src\mbbms_imd.c
endif

#  Define include path lists to INC_DIR
INC_DIR = drv\include \
          interface\media \
          interface\hal\graphics \
          interface\hal\video \
          interface\hal\camera \
          media\common\include \
          media\audio\include \
          media\mtv\include \
          xmlp\include \
          plutommi\Framework\GDI\gdiinc \
          hal\system\dcmgr\inc \
          hal\video\decoder\include \
          hal\video\common\include

ifneq ($(filter __CMMB_SUPPORT__,$(strip $(MODULE_DEFS))),)
INC_DIR += cmmb\hal \
           applib\sqlite3\inc \
           vendor\cmmb\nagra\inc
endif

ifneq ($(filter __ATV_SUPPORT__,$(strip $(MODULE_DEFS))),)
INC_DIR += matv\inc
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


