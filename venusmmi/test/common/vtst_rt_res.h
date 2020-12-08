/***************************************************************************** 
 Definition 
*****************************************************************************/

#undef VTST_RES_DECLARE
#define VTST_RES_DECLARE(_app, _range, _path)    MMI_RES_DECLARE(_app, _range, "..\\venusmmi\\test\\" _path)

/***************************************************************************** 
 RT resource declaration
*****************************************************************************/

VTST_RES_DECLARE(FW_TEST1, 10, "common\\res\\")
VTST_RES_DECLARE(FW_TEST2, 10, "common\\res\\")
VTST_RES_DECLARE(FW_TEST3, 10, "common\\res\\")
VTST_RES_DECLARE(FW_TEST4, 10, "common\\res\\")
VTST_RES_DECLARE(VTST_SAMPLE, 100, "app\\res\\")
VTST_RES_DECLARE(TEMP_MEM_APP1, 5, "framework\\res\\")
VTST_RES_DECLARE(TEMP_MEM_APP2, 5, "framework\\res\\")
VTST_RES_DECLARE(TEMP_MEM_APP3, 5, "framework\\res\\")
VTST_RES_DECLARE(TEMP_MEM_APP4, 5, "framework\\res\\")
