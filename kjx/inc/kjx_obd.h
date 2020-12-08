/**********************************************************************************
*Filename:     kjx_obd.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/04/21
*
***********************************************************************************/
#if !defined(KJX_OBD_H)
#define KJX_OBD_H

#if defined(__KJX_OBD__)


#define  MAX_OBD_DATA_ID    67

typedef enum
{
    OBD_PARSE_NONE,/**/
    OBD_PARSE_NEXT,/**/
    OBD_PARSE_CLOSE/**/
} KJX_OBD_PARSE;


typedef enum
{
    KJX_OBD_UART_START,/*启动数据传输*/
    KJX_OBD_UART_SETTING,/*标定车系*/
    KJX_OBD_UART_CLOSE,/*关闭OBD*/
    KJX_OBD_UART_SHAKE,/*握手协议*/
    KJX_OBD_UART_MAX
} KJX_OBD_UART_COMMAND;

typedef struct 
{
     uint16    obd_sign;  	   /*起始标志*/  
     uint8      destination;  	   /*目标地址*/  
     uint8      source;  	          /*源地址*/  
     uint16    dataLen;  	          /*包长度*/  
     uint8      count;  	          /*计数器*/  
     uint16    command;  	   /*命令字*/  
     uint8      data[8];  	          /*数据区*/  
     uint8      checksum;  	   /*包校验*/  
}kjx_obd_uart_data;

typedef struct 
{
     uint8    name_string[18];   /*数据类型*/  
     uint8    lenght;  	           /*数据长度*/  
     float     value;  	           /*数据值*/  
     BOOL   status;  	           /*状态值*/  
     char     unit[16];          /*单位*/
}kjx_obd_data;


typedef struct 
{
     uint8    command[2];  	   /*命令字*/  
     uint8    lenght;  	          /*数据区长度*/  
     uint8    data[16];  	          /*数据区*/  
}kjx_obd_uart_command;

extern int obd_len;
extern kal_uint8 ObdUartBuffer[];
extern void kjx_obd_write_car_infos(S8 * recvbuf, kal_uint16 len);
extern U16 kjx_obd_parse_data(U16 dataLen);
extern void kjx_obd_open_uart(void);
extern void kjx_obd_uart_init(void);
extern void kjx_obd_status_play_tts(void);
extern void kjx_obd_uart_send(U16 command);
extern void kjx_obd_read_obd_start(void);
extern void kjx_obd_open_uart(void);
extern BOOL kjx_obd_is_working(void);
extern BOOL kjx_obd_acc_valid(void);
extern void kjx_obd_exit_uart(void);
extern BOOL kjx_obd_is_working(void);
extern void kjx_obd_alarm_with_value(void);
extern void kjx_obd_send_data_timeout(void);
#endif/*__KJX_OBD__*/
#endif/*KJX_OBD_H*/
