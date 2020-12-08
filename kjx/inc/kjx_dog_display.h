#ifndef KJX_DOG_DISPLAY_H
#define KJX_DOG_DISPLAY_H

#if defined(__KJX_DOG__)

#ifndef bool
#define bool unsigned char
#endif

typedef enum
{
    DATA_TYPE_NONE,
    DATA_TYPE_SECTION_INTO,/*1:区间测速起点*/
    DATA_TYPE_SECTION_LEAVE,/*2:区间测速终点*/
    DATA_TYPE_SECTION_SPEED,/*3:区间测速*/
    DATA_TYPE_FIXED_CAMERA,/*4:固定测速照相*/
    DATA_TYPE_OUSIDE_TUNNEL_CAMERA,/*5:隧道外测速照相*/
    DATA_TYPE_THE_TUNNEL_CAMERA,/*6:隧道内超速照相*/
    DATA_TYPE_ON_BRIDGE,/*7:高架上测速*/
    DATA_TYPE_UNDER_BRIDGE,/*8:高架下测速*/
    DATA_TYPE_RED_LED,/*9:闯红灯照相*/
    DATA_TYPE_UNDER_BRIDGE_LED,/*10:高架桥下红灯*/
    DATA_TYPE_SIGNAL_LED,/*11:交通信号灯*/
    DATA_TYPE_BRIDGE_CAMERA,/*12:高架上监控*/
    DATA_TYPE_BUS_LANE,/*13:公交专用道*/
    DATA_TYPE_WAY_STREET,/*14:单行道*/
    DATA_TYPE_NO_LEFT,/*15:禁止左转*/
    DATA_TYPE_NO_RIGHT,/*16:禁止右转*/
    DATA_TYPE_MOBILE_CAMERA,/*17:移动测速区*/
    DATA_TYPE_RADAR,/*18:雷达经常出没路段*/
    DATA_TYPE_NO_CROSSING,/*19:越线禁止*/
    DATA_TYPE_RADAR_SPEED,/*20:雷达测速区*/
    DATA_TYPE_RAILWAY,/*21:铁路道口*/
    DATA_TYPE_TUNNEL,/*22:隧道*/
    DATA_TYPE_ACCIDET_LOAD,/*23:易肇事路段*/
    DATA_TYPE_SCHOOL,/*24:学校*/
    DATA_TYPE_STEEP_DOWNHILL,/*25:急下坡*/
    DATA_TYPE_HIGH_SPEED_LOAD,/*26:高速出入口*/
    DATA_TYPE_TOLL_GATE,/*27:收费站*/
    DATA_TYPE_SERVICE_AREA,/*28:服务区*/
    DATA_TYPE_FILLING_STATION,/*29:加油站*/
    DATA_TYPE_WINE_TEST,/*30:酒测路段*/
    DATA_TYPE_CAMERA,/*31:电子监控*/
    DATA_TYPE_MAX
} KJX_DOG_DATA_TYPE;


typedef struct 
{
  bool sec_string;
  char play_string[64];
}kjx_dog_play_string;

#endif
#endif/*KJX_DOG_DISPLAY_H*/
