# Define source file lists to SRC_LIST
SRC_LIST = MoDIS_VC9\comm\cShare.cpp

#  Define include path lists to INC_DIR
INC_DIR = MoDIS_VC9\comm

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

ifeq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
  COMP_DEFS += GEN_FOR_PC __UCS2_ENCODING
endif


ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  MODIS_DIS_OPTION += STDC_HEADERS
endif
