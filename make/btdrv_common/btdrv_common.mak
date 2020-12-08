

ifneq ($(filter __BTMODULE_MT6260__ , $(strip $(MODULE_DEFS))),)
	# Define source file lists to SRC_LIST
	SRC_LIST = hal\bluetooth\mt6260\common\btdrv_common.c
	
	#  Define include path lists to INC_DIR
	INC_DIR = hal\bluetooth\mt6260\common\include \
	          btstacka\inc \
	          btstacka\inc\sys \
	          interface\hal\bluetooth
else
	# Define source file lists to SRC_LIST
	SRC_LIST = hal\bluetooth\common\btdrv_common.c
	
	#  Define include path lists to INC_DIR
	INC_DIR = hal\bluetooth\common\include \
	          btstacka\inc \
	          btstacka\inc\sys \
	          interface\hal\bluetooth
endif