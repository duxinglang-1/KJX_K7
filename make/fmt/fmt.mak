# Define source file lists to SRC_LIST
SRC_LIST = fmt\src\fmt_main.c

ifneq ($(filter PLUTO_MMI, $(strip $(MODULE_DEFS))),)
    SRC_LIST += fmt\src\fmt_adv.c
endif

#  Define include path lists to INC_DIR
INC_DIR = fmt\include \
          interface\hwdrv \
          drv\include \
          plutommi\mtkapp\filemgr\filemgrinc \
          interface\ps

# Define the specified compile options to COMP_DEFS
COMP_DEFS = SMG_REL_97 \
            __MOD_UEM__ \
            UART_ENABLE \
            __MOD_CSM__ \
            __MOD_SMU__ \
            __MOD_NVRAM__ \
            __MOD_PHB__ \
            __MOD_SMSAL__ \
            __MOD_L4C__ \
            __SMS_PDU_MODE__ \
            __SMS_ME_STORAGE__


