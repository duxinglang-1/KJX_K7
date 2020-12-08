# Define source file lists to SRC_LIST
SRC_LIST = hal\postproc\postproc_if\src\pp_main.c \
           hal\postproc\postproc_if\src\pp_scenario_ctrl.c \
           hal\postproc\postproc_if\src\pp_feature_ctrl.c \
           hal\postproc\postproc_if\src\pp_scenario_ctrl.c \
           hal\postproc\face_detect\src\fd_main.c \
           hal\postproc\smile_detect\src\sd_main.c \
           hal\postproc\hdr\src\hdr_main.c \
           hal\postproc\utility\utility_feature_ctrl.c \
           hal\postproc\autocap\src\autocap_main.c \
           hal\postproc\asd\src\asd_main.c \
           hal\postproc\mavcap\src\mavcap_main.c \
           hal\postproc\mav\src\mav_main.c

ifneq ($(filter __AUTOCAP_PANORAMA_SUPPORT__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\postproc\autopano\src\pano_main.c
else
	SRC_LIST += hal\postproc\panorama\src\pano_main.c
endif

#  Define include path lists to INC_DIR
INC_DIR = interface\hal\camera \
          interface\hal\postproc \
          interface\hal\graphics \
          hal\postproc\postproc_if\inc \
          hal\postproc\utility \
          hal\postproc\face_detect\inc \
          hal\postproc\smile_detect\inc \
          hal\postproc\hdr\inc \
       	  hal\postproc\autocap\inc \
          hal\postproc\asd\inc \
          hal\postproc\mavcap\inc \
          hal\postproc\mav\inc \
          hal\postproc\postproc_sec\fd_core\inc \
          hal\postproc\postproc_sec\sd_core\inc \
          hal\postproc\postproc_sec\hdr_core\inc \
          hal\postproc\postproc_sec\autocap_core\inc \
          hal\postproc\postproc_sec\asd_core\inc \
          hal\postproc\postproc_sec\mavcap_core\inc \
          hal\postproc\postproc_sec\mav_core\inc \
          hal\postproc\postproc_sec\utility_core\inc
ifneq ($(filter __AUTOCAP_PANORAMA_SUPPORT__, $(strip $(MODULE_DEFS))),)
	INC_DIR += hal\postproc\autopano\inc \
			   hal\postproc\postproc_sec\autopano_core\inc
else
	INC_DIR += hal\postproc\panorama\inc \
			   hal\postproc\postproc_sec\pano_core\inc
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS =

