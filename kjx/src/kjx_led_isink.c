/**********************************************************************************
*Filename:     kjx_led_isink.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/01/13
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_include.h"
#include "Gpio_sw.h"

U16 start_timer_red_id = 0;
U16 start_timer_green_id = 0;
U16 start_timer_blue_id = 0;
U16 start_timer_yellow_id = 0;

U16 timer_red_total = 0;
U16 timer_green_total = 0;
U16 timer_blue_total = 0;
U16 timer_yellow_total = 0;

int timerRedDelayOn = 0;
int timerRedDelayOff = 0;
int timerGreenDelayOn = 0;
int timerGreenDelayOff = 0;
int timerBlueDelayOn = 0;
int timerBlueDelayOff = 0;
int timerYellowDelayOn = 0;
int timerYellowDelayOff = 0;

led_func g_led_func_red_on;
led_func g_led_func_red_off;
led_func g_led_func_green_on;
led_func g_led_func_green_off;
led_func g_led_func_blue_on;
led_func g_led_func_blue_off;
led_func g_led_func_yellow_on;
led_func g_led_func_yellow_off;

#ifdef __KJX_BAT_STATUS_LED_SHOW__
#define GPIO_LED_RED_PIN		47
#define GPIO_LED_GREEN_PIN		48
#define GPIO_LED_BLUE_PIN		49
#define GPIO_LED_YELLOW_PIN		50
#endif

#define kjx_led_red_on()        kjx_set_led_status(ISINK_SET_LED_RED, TRUE)
#define kjx_led_green_on()    kjx_set_led_status(ISINK_SET_LED_GREEN, TRUE)
#define kjx_led_blue_on()       kjx_set_led_status(ISINK_SET_LED_BLUE, TRUE)
#define kjx_led_yellow_on()   kjx_set_led_status(ISINK_SET_LED_YELLOW, TRUE)

#define kjx_led_red_off()       kjx_set_led_status(ISINK_SET_LED_RED, FALSE)
#define kjx_led_green_off()   kjx_set_led_status(ISINK_SET_LED_GREEN, FALSE)
#define kjx_led_blue_off()      kjx_set_led_status(ISINK_SET_LED_BLUE, FALSE)
#define kjx_led_yellow_off()  kjx_set_led_status(ISINK_SET_LED_YELLOW, FALSE)


#ifdef __KJX_BAT_STATUS_LED_SHOW__
void kjx_set_gpio_led(U8 index, BOOL is_high)
{
	GPIO_ModeSetup(index,0);
	GPIO_InitIO(1, index);
	if(is_high)
		GPIO_WriteIO(1,index);
	else
		GPIO_WriteIO(0,index);
}
#endif

void kjx_set_led_status(kjx_led_id index,BOOL status)
{
	switch(index)
	{  
	case ISINK_SET_LED_RED:
	#ifdef __KJX_BAT_STATUS_LED_SHOW__
		kjx_set_gpio_led(GPIO_LED_RED_PIN, status);
	#else
		custom_isink_control(status,ISINK2);//ISINK0);//GPS,GSM对换显示 20140625
	#endif
		break;

	case ISINK_SET_LED_GREEN:
	#ifdef __KJX_BAT_STATUS_LED_SHOW__
		kjx_set_gpio_led(GPIO_LED_GREEN_PIN, status);
	#else
		custom_isink_control(status,ISINK1);
	#endif
		break;

	case ISINK_SET_LED_BLUE:
	#ifdef __KJX_BAT_STATUS_LED_SHOW__
		kjx_set_gpio_led(GPIO_LED_BLUE_PIN, status);
	#else
		custom_isink_control(status,ISINK0);//ISINK0);//GPS,GSM对换显示 20140625
	#endif
		break;

	case ISINK_SET_LED_YELLOW:
	#ifdef __KJX_BAT_STATUS_LED_SHOW__
		kjx_set_gpio_led(GPIO_LED_YELLOW_PIN, status);
	#else
		custom_isink_control(status,ISINK3);
	#endif
		break;

	default:
		break;
	}
}

/******* Delay a lTime uSec ********/
void kjx_delay_uSec(int delay)
{
   kal_uint32 curr_frc, latest_us;
   
   curr_frc = ust_get_current_time();//unit: micro second (us)
   do{
      latest_us = ust_get_current_time();;
   }while(delay > ust_get_duration(curr_frc, latest_us));
}

void kjx_led_red_on_only(void)
{
	StopTimer(start_timer_red_id);
	kjx_led_red_on();
}

void kjx_led_green_on_only(void)
{
	StopTimer(start_timer_green_id);
	kjx_led_green_on();
}

void kjx_led_blue_on_only(void)
{
	StopTimer(start_timer_blue_id);
	kjx_led_blue_on();
}

void kjx_led_yellow_on_only(void)
{
	StopTimer(start_timer_yellow_id);
	kjx_led_yellow_on();
}

void kjx_led_red_off_only(void)
{
	StopTimer(start_timer_red_id);
	kjx_led_red_off();
}

void kjx_led_green_off_only(void)
{
	StopTimer(start_timer_green_id);
	kjx_led_green_off();
}

void kjx_led_blue_off_only(void)
{
	StopTimer(start_timer_blue_id);
	kjx_led_blue_off();
}

void kjx_led_yellow_off_only(void)
{
	StopTimer(start_timer_yellow_id);
	kjx_led_yellow_off();
}

void kjx_timer_led_red_on(void)
{
    StopTimer(start_timer_red_id);
    kjx_set_led_status(ISINK_SET_LED_RED, TRUE);
    StartTimer(start_timer_red_id,timerRedDelayOn,g_led_func_red_off);
}

void kjx_timer_led_red_off(void)
{
    static U16 timerTotal = 0;
	
    timerTotal++;
    StopTimer(start_timer_red_id);
    kjx_set_led_status(ISINK_SET_LED_RED, FALSE);
 
    if(timerTotal>timer_red_total)
    {
        timerTotal = 0;
	 if(timer_red_total != LED_BLINK_ALWAYS)
	 {
	 	return;
	 }
    }
	
    StartTimer(start_timer_red_id,timerRedDelayOff,g_led_func_red_on);
}

void kjx_timer_led_blue_on(void)
{
    StopTimer(start_timer_blue_id);
    kjx_set_led_status(ISINK_SET_LED_BLUE, TRUE);
    StartTimer(start_timer_blue_id,timerBlueDelayOn,g_led_func_blue_off);
}

void kjx_timer_led_blue_off(void)
{
    static U16 timerTotal = 0;
	
    timerTotal++;
    StopTimer(start_timer_blue_id);
    kjx_set_led_status(ISINK_SET_LED_BLUE, FALSE);

    if(timerTotal>timer_blue_total)
    {
        timerTotal = 0;
	 if(timer_blue_total != LED_BLINK_ALWAYS)
	 {
	 	return;
	 }
    }
	
    StartTimer(start_timer_blue_id,timerBlueDelayOff,g_led_func_blue_on);
}

void kjx_timer_led_green_on(void)
{
    StopTimer(start_timer_green_id);
    kjx_set_led_status(ISINK_SET_LED_GREEN, TRUE);
    StartTimer(start_timer_green_id,timerGreenDelayOn,g_led_func_green_off);
}

void kjx_timer_led_green_off(void)
{
    static U16 timerTotal = 0;
	
    timerTotal++;
    StopTimer(start_timer_green_id);
    kjx_set_led_status(ISINK_SET_LED_GREEN, FALSE);

    if(timerTotal>timer_green_total)
    {
        timerTotal = 0;
	 if(timer_green_total != LED_BLINK_ALWAYS)
	 {
	 	return;
	 }
    }
	
    StartTimer(start_timer_green_id,timerGreenDelayOff,g_led_func_green_on);
}

void kjx_timer_led_yellow_on(void)
{
    StopTimer(start_timer_yellow_id);
    kjx_set_led_status(ISINK_SET_LED_YELLOW, TRUE);
    StartTimer(start_timer_yellow_id,timerYellowDelayOn,g_led_func_yellow_off);
}

void kjx_timer_led_yellow_off(void)
{
    static U16 timerTotal = 0;
	
    timerTotal++;
    StopTimer(start_timer_yellow_id);
    kjx_set_led_status(ISINK_SET_LED_YELLOW, FALSE);

    if(timerTotal>timer_yellow_total)
    {
        timerTotal = 0;
	 if(timer_yellow_total != LED_BLINK_ALWAYS)
	 {
	 	return;
	 }
    }
	
    StartTimer(start_timer_yellow_id,timerYellowDelayOff,g_led_func_yellow_on);
}

void kjx_led_red_blink(U16 total,int delayOn,int delayOff)
{
    start_timer_red_id = KJX_TIMER_ID_LED_RED;
    timerRedDelayOn = delayOn;
    timerRedDelayOff = delayOff;
    timer_red_total = total;
    g_led_func_red_on = kjx_timer_led_red_on;
    g_led_func_red_off = kjx_timer_led_red_off;
    g_led_func_red_on();	
}

void kjx_led_blue_blink(U16 total,int delayOn,int delayOff)
{
    start_timer_blue_id = KJX_TIMER_ID_LED_BLUE;
    timerBlueDelayOn = delayOn;
    timerBlueDelayOff = delayOff;
    timer_blue_total = total;
    g_led_func_blue_on = kjx_timer_led_blue_on;
    g_led_func_blue_off = kjx_timer_led_blue_off;
    g_led_func_blue_on();	
}

void kjx_led_green_blink(U16 total,int delayOn,int delayOff)
{
    start_timer_green_id = KJX_TIMER_ID_LED_GREEN;
    timerGreenDelayOn = delayOn;
    timerGreenDelayOff = delayOff;
    timer_green_total = total;
    g_led_func_green_on = kjx_timer_led_green_on;
    g_led_func_green_off = kjx_timer_led_green_off;
    g_led_func_green_on();	
}

void kjx_led_yellow_blink(U16 total,int delayOn,int delayOff)
{
    start_timer_yellow_id = KJX_TIMER_ID_LED_YELLOW;
    timerYellowDelayOn = delayOn;
    timerYellowDelayOff = delayOff;
    timer_yellow_total = total;
    g_led_func_yellow_on = kjx_timer_led_yellow_on;
    g_led_func_yellow_off = kjx_timer_led_yellow_off;
    g_led_func_yellow_on();	
}
#endif
