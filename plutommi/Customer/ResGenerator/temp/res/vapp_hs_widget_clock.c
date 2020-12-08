#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_CLOCK">
#if defined(__MMI_VUI_HOMESCREEN_CLOCK__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_CLOCK_STR_SETTING"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_DISPLAY_SETTING"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_TYPE"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_TYPE_LOCAL"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_TYPE_ECDEMIC"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_TYPE_DUAL"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_STYLE"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_STYLE_ANALOG"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_STYLE_ANALOG2"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_STYLE_DIGITAL"/>
    <STRING id="VAPP_HS_STR_CLOCK_STR_SET_WC"/>
    <STRING id="VAPP_HS_STR_WG_CLOCK"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"    
    #define CLOCK_WIDGET_PATH WIDGET_PATH"Clock\\\\"

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
#define VUI_HS_IMG_TYPE "BMP"
#else /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
#define VUI_HS_IMG_TYPE "PNG"
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    <IMAGE id="VAPP_HS_IMG_WG_ICON_CLOCK">WIDGET_PATH"Widgeticon_Clock.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_CLOCK_ANALOG">WIDGET_PATH"Widgeticon_AnalogClock.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_CLOCK_ANALOG2">WIDGET_PATH"Widgeticon_AnalogClock.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_CLOCK_DIGITAL">WIDGET_PATH"Widgeticon_DigitalClock.png"</IMAGE>
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_BG">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_MapBG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_LOCAL_BG">CLOCK_WIDGET_PATH"analog\\\\Analog1_Local_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ECDEMIC_BG">CLOCK_WIDGET_PATH"analog\\\\Analog1_Ecdemic_BG."VUI_HS_IMG_TYPE</IMAGE>    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_LOCAL_BG">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_Local_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_ECDEMIC_BG">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_Ecdemic_BG."VUI_HS_IMG_TYPE</IMAGE>    

    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_BG">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_MapBG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_LOCAL_BG">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Local_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ECDEMIC_BG">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Ecdemic_BG."VUI_HS_IMG_TYPE</IMAGE>    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_LOCAL_BG">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_Local_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_ECDEMIC_BG">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_Ecdemic_BG."VUI_HS_IMG_TYPE</IMAGE>    
    
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_L_H">CLOCK_WIDGET_PATH"analog\\\\Analog1_Local_HourHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_L_M">CLOCK_WIDGET_PATH"analog\\\\Analog1_Local_MinuteHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_L_S">CLOCK_WIDGET_PATH"analog\\\\Analog1_Local_SecondHand.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_L_CENTER">CLOCK_WIDGET_PATH"analog\\\\Analog1_Local_Center.png"</IMAGE>    
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_E_H">CLOCK_WIDGET_PATH"analog\\\\Analog1_Ecdemic_HourHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_E_M">CLOCK_WIDGET_PATH"analog\\\\Analog1_Ecdemic_MinuteHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_E_S">CLOCK_WIDGET_PATH"analog\\\\Analog1_Ecdemic_SecondHand.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_E_CENTER">CLOCK_WIDGET_PATH"analog\\\\Analog1_Ecdemic_Center.png"</IMAGE>    
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_L_H">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_L_HourHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_L_M">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_L_MinuteHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_L_S">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_L_SecondHand.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_L_CENTER">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_L_Center.png"</IMAGE>    
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_E_H">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_E_HourHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_E_M">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_E_MinuteHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_E_S">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_E_SecondHand.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_DUAL_E_CENTER">CLOCK_WIDGET_PATH"analog\\\\Analog1_L_E_E_Center.png"</IMAGE>  
    
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_L_H">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Local_HourHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_L_M">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Local_MinuteHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_L_S">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Local_SecondHand.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_L_CENTER">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Local_Center.png"</IMAGE>    
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_E_H">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Ecdemic_HourHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_E_M">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Ecdemic_MinuteHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_E_S">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Ecdemic_SecondHand.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_E_CENTER">CLOCK_WIDGET_PATH"analog2\\\\Analog2_Ecdemic_Center.png"</IMAGE>    
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_L_H">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_L_HourHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_L_M">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_L_MinuteHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_L_S">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_L_SecondHand.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_L_CENTER">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_L_Center.png"</IMAGE>    
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_E_H">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_E_HourHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_E_M">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_E_MinuteHand.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_E_S">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_E_SecondHand.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_DUAL_E_CENTER">CLOCK_WIDGET_PATH"analog2\\\\Analog2_L_E_E_Center.png"</IMAGE>   


    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_L_BG">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_Local_BG.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_L_CENTER">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_L_Center.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_L_H">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_L_Hour.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_L_M">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_L_Minute.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_L_S">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_L_Second.png"</IMAGE>  
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_E_BG">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_Ecdemic_BG.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_E_CENTER">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_E_Center.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_E_H">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_E_Hour.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_E_M">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_E_Minute.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_E_S">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_E_Second.png"</IMAGE> 

    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK_ICON_DUAL">CLOCK_WIDGET_PATH"widget_icon\\\\AClock\\\\Widgeticon_AC_Local.png"</IMAGE> 

    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_L_BG">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_Local_BG.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_L_CENTER">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_L_Center.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_L_H">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_L_Hour.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_L_M">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_L_Minute.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_L_S">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_L_Second.png"</IMAGE>  
    
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_E_BG">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_Ecdemic_BG.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_E_CENTER">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_E_Center.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_E_H">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_E_Hour.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_E_M">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_E_Minute.png"</IMAGE>   
    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_E_S">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_E_Second.png"</IMAGE> 

    <IMAGE id="VAPP_HS_IMG_WG_ACLOCK2_ICON_DUAL">CLOCK_WIDGET_PATH"widget_icon\\\\AClock2\\\\Widgeticon_AC2_Local.png"</IMAGE> 


    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_MapBG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_LOCAL_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ECDEMIC_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_0">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_1">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_2">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_3">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_4">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_5">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_6">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_7">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_8">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_9">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_NUM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_NUM_Dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_AM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_AM_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_AM">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_AM_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_PM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_PM_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_PM">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_PM_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_COLON_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_Colon_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_L_COLON">CLOCK_WIDGET_PATH"digital\\\\Digital_Local_Colon.png"</IMAGE>
    
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_0">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_1">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_2">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_3">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_4">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_5">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_6">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_7">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_8">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_9">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_NUM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_NUM_Dis.png"</IMAGE>    
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_AM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_AM_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_AM">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_AM_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_PM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_PM_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_PM">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_PM_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_COLON_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_Colon_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_E_COLON">CLOCK_WIDGET_PATH"digital\\\\Digital_Ecdemic_Colon.png"</IMAGE>

    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_BG">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_DC_Local_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_0">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_1">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_2">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_3">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_4">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_5">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_6">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_7">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_8">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_9">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_BG">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_NUM_L_gray.png"</IMAGE>    
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_COLON_BG">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_Colon_L_gray.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_L_COLON">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_L_Colon.png"</IMAGE>

    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_BG">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_DC_Ecdemic_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_0">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_1">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_2">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_3">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_4">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_5">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_6">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_7">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_8">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_9">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_BG">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_NUM_E_gray.png"</IMAGE>    
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_COLON_BG">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_Colon_E_gray.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON_E_COLON">CLOCK_WIDGET_PATH"widget_icon\\\\DClock\\\\Widgeticon_E_Colon.png"</IMAGE>


    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_LOCAL_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_ECDEMIC_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_0">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_1">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_2">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_3">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_4">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_5">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_6">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_7">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_8">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_9">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_NUM_Dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_AM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_AM_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_AM">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_AM_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_PM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_PM_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_PM">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_PM_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_COLON_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_Colon_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_L_COLON">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Local_Colon.png"</IMAGE>
    
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_0">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_1">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_2">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_3">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_4">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_5">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_6">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_7">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_8">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_9">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_NUM_Dis.png"</IMAGE>    
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_AM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_AM_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_AM">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_AM_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_PM_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_PM_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_PM">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_PM_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_COLON_BG">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_E_Colon_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_DUAL_E_COLON">CLOCK_WIDGET_PATH"digital\\\\Digital_L_E_Ecdemic_Colon.png"</IMAGE>



    <!-----------------------------------------------------Screen Resource Area------------------------------------------------------>
    <SCREEN id="VAPP_HS_SCR_CLOCK_SETTING"/>
    <SCREEN id="VAPP_HS_SCR_CLOCK_DISPLAY_SETTING"/>

#endif

</APP>

