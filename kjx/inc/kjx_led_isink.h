/**********************************************************************************
*Filename:     kjx_led_isink.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/01/13
*
***********************************************************************************/
#if !defined(KJX_LED_ISINK_H)
#define KJX_LED_ISINK_H

typedef enum 
{
    ISINK_SET_LED_RED = 0,  
    ISINK_SET_LED_GREEN, 
    ISINK_SET_LED_BLUE , 
    ISINK_SET_LED_YELLOW, 
}kjx_led_id;

typedef enum 
{
    LED_FAST = 0,  
    LED_SLOW, 
    LED_ON, 
    LED_OFF, 
    LED_NONE, 
}kjx_led_type;

#define  DELAY_MS_100		100
#define  DELAY_MS_200		200
#define  DELAY_MS_500		500
#define  DELAY_MS_1000		1000
#define  DELAY_MS_5000		1000*5
#define  DELAY_MS_1MIN		1000*60
#define  DELAY_MS_2MIN		1000*120
#define  DELAY_MS_3MIN		1000*180

#define  LED_BLINK_ALWAYS		360

typedef void (*led_func) (void);

extern void kjx_set_led_status(kjx_led_id index,BOOL status);

#endif
