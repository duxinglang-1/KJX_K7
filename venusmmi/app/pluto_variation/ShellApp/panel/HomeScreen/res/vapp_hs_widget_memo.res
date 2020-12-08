#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_MEMO">
#if defined(__MMI_VUI_HOMESCREEN_MEMO__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_MEMO"/>
    <STRING id="VAPP_HS_STR_WG_MEMO_EDIT_TITLE"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define MEMO_WIDGET_PATH WIDGET_PATH"Memo\\\\"
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    #define VUI_HS_IMG_TYPE "BMP"
#else /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    #define VUI_HS_IMG_TYPE "PNG"
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    <IMAGE id="VAPP_HS_IMG_WG_ICON_MEMO">WIDGET_PATH"Widgeticon_Memo.png"</IMAGE>
#if defined(__MMI_FTE_SUPPORT_SLIM__)
    <IMAGE id="VAPP_HS_IMG_WG_MEMO_BG">MEMO_WIDGET_PATH"Memo_BG.9slice."VUI_HS_IMG_TYPE</IMAGE>
#else /* defined(__MMI_FTE_SUPPORT_SLIM__) */
    <IMAGE id="VAPP_HS_IMG_WG_MEMO_BG">MEMO_WIDGET_PATH"Memo_BG."VUI_HS_IMG_TYPE</IMAGE>
#endif /* defined(__MMI_FTE_SUPPORT_SLIM__) */
    <IMAGE id="VAPP_HS_IMG_WG_MEMO_EDIT_TITLE">MEMO_WIDGET_PATH"TB_Memo.pbm"</IMAGE>


    <!-----------------------------------------------------Screen Resource Area------------------------------------------------------>
    <SCREEN id="VAPP_HS_SCR_WG_MEMO_EDIT"/>
    <SCREEN id="VAPP_HS_SCR_WG_MEMO_EDIT_OPTION"/>

#endif

</APP>

