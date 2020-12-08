# Define source file lists to SRC_LIST
ifeq ($(strip $(FM_RADIO_CHIP)),MT6188A1)
  SRC_LIST += fm_drv\MT6188A1_drv.c
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6189A1)
  SRC_LIST += fm_drv\MT6189A1_drv.c
endif
ifeq ($(strip $(FM_RADIO_CHIP)),AR1000)
  SRC_LIST += fm_drv\AR1000_drv.c
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT5192FM)
  SRC_LIST += fm_drv\MT5192FM_drv.c
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT5193FM)
  SRC_LIST += fm_drv\MT5193FM_drv.c
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6616)
  SRC_LIST += fm_drv\MT6616_drv.c
  ifneq ($(filter __FM_RADIO_RDS_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += fm_drv\MT6616_rds.c
  endif
endif    
ifeq ($(strip $(FM_RADIO_CHIP)),MT6251FM)
  SRC_LIST += fm_drv\MT6251_drv.c
  ifneq ($(filter __FM_RADIO_RDS_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += fm_drv\MT6251_rds.c
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6256FM)
#  SRC_LIST += fm_drv\MT6256_drv.c
  SRC_LIST += fm_drv\MTSOC_drv.c
  ifneq ($(filter __FM_RADIO_RDS_SUPPORT__, $(strip $(MODULE_DEFS))),)
#    SRC_LIST += fm_drv\MT6256_rds.c
    SRC_LIST += fm_drv\MTSOC_rds.c
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6255FM)
  SRC_LIST += fm_drv\MTSOC_drv.c
  ifneq ($(filter __FM_RADIO_RDS_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += fm_drv\MTSOC_rds.c
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6276FM)
  SRC_LIST += fm_drv\MT6276_drv.c
  ifneq ($(filter __FM_RADIO_RDS_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += fm_drv\MT6276_rds.c
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6250FM)
  SRC_LIST += fm_drv\MT6250FM_drv.c
  ifneq ($(filter __FM_RADIO_RDS_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += fm_drv\MT6250FM_rds.c
  endif
endif
ifeq ($(strip $(FM_RADIO_CHIP)),MT6260FM)
  SRC_LIST += fm_drv\MT6250FM_drv.c
  ifneq ($(filter __FM_RADIO_RDS_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += fm_drv\MT6250FM_rds.c
  endif
endif

SRC_LIST += fm_drv\MT6626_drv.c
SRC_LIST += fm_drv\MT6626_rds.c

#  Define include path lists to INC_DIR
INC_DIR = fmr\src \
          fmr\inc \
          hal\audio\src\v1\inc \
          wmt\inc

# if any component needs to interwork with other ARM mode components, it should
# add "APCS_INTWORK" into its .def
COMP_DEFS = APCS_INTWORK
