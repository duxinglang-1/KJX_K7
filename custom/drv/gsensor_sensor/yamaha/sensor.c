#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
#include "mmi_platform.h"
#include "em_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "TimerEvents.h"
//#include "QueueGprot_Int.h "
#include "App2soc_struct.h"
#include "drv_comm.h"
#include "yas_simple.h"
#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"
#include "yas.h"

#include "kjx_sensor.h"
extern kjx_sensor_func g_kjx_sensor_func;

//#define   GGT_DUB    
   
//#include  <windows.h>
#define  enable_mag  1   /*使能mag   1： able  0: disable*/
#define  enable_acc  1   /*使能acc   1： able  0: disable*/
#define  calib_enable  1  /*使能 calib */
#define  filter_acc  1  /*使能 acc filter*/
#define  filter_mag  1  /*使能 mag filter*/
#define position_acc  1 /*acc 坐标定义*/
#define position_mag  3 /*mag  坐标定义*/
kal_uint16 cycle_timer =0;
kal_uint32 g_init_v = 0;
//extern void alert_send_sms(void);

#define DSP_BIN_MAX_SIZE (500)
int iDSPDrvLetter;    
WCHAR DSPFilename[32];
kal_uint8 dsp_buffer[DSP_BIN_MAX_SIZE];
static FS_HANDLE hDSPHandle = -1;  /* nonvol file handle */
kal_uint8 result_setting = 1;
extern int x_data;
extern int y_data;
extern int z_data;
int move_count=0;
int g_sensor_status=0;

// 注意 ：Sleep（1） ，指延时1ms ,可用系统延时函数来代替 。
void sensor_delayms(kal_uint16 data)
{
#if defined(__UBL__)
	kal_uint32 time1=0, diff=0;
	
	time1=drv_get_current_time();

	while(drv_get_duration_ms(time1) < data);
#else
	kal_uint32 i;
	while(data--)
	{
		for(i=0;i<220000;i++){}// 1ms=220000 TIMES	
	}
#endif
}

int acc_mag_sensor_init(void)
{
   struct yas_machdep func;
  struct yas_vector ori;
  struct yas_offset offset;
  int ret;  //1 :初始化 ：   memset(&offset,0,sizeof(offset));
   memset(&func,1,sizeof(func));
   ret = yas_simple_init( &func);
	if(ret == YAS_NO_ERROR)	
	{
       ret = yas_simple_set_enable( enable_acc,  enable_mag,0) ;
	}
	else
	{
      return;
	}

	if(ret == YAS_NO_ERROR)
	{
     ret =  yas_simple_set_calib_enable(0) ;
	}
	else
	{
       return;
	}
	
   ret = yas_simple_set_filter_enable(filter_acc,filter_mag,0) ;
   ret = yas_simple_set_position( position_acc, position_mag,0);
	 
	cycle_timer = 0;
	g_init_v = 0xffffffff;
    return ret;
}
 
#if 0//defined(__KJX_EASY_MOVE_ALERT__)
#include "..\ggt\inc\GGT_lib.h"
#include "..\ggt\inc\GGT_wrt_lbs_gps.h"
extern S8 old_lat[9];
extern S8 old_lng[10];
extern GT_SuperInfo GTSuperInfo;
extern wrt_pos_gps_info_struct g_wrt_cur_gps_info;
#endif

void g_sensor_game_cb(BOOL result)
{
   //dbg_print("g_sensor_game_sample: x: %d,%d\r\n", *result,move_count);
#if 0//defined(__KJXEASY_STATIC_ALARM__)
	if(result == KAL_FALSE)
	{
		move_count++;
	}
	else 
	{
		move_count=0;
		kjxeasy_static_alarm_reset_state();
		if((gps_state == 0)&&(mmi_bootup_is_sim_valid()))
		{ 
			gps_turn_on_gps();
		}		
	}
	if(move_count >= SENSOR_TIME_COUNT_MIN*60)
	{
		kjxeasy_static_alarm_req();
		if(move_count >= (SENSOR_TIME_COUNT_MIN+1)*60)
		{
			move_count = (SENSOR_TIME_COUNT_MIN+1)*60;
			if(gps_state == 1)
			{
				gps_turn_off_gps();
			}
		}
	}
#else /*__KJXEASY_STATIC_ALARM__*/
   if(result == 0)
   {
        move_count++;
   }
   else 
   {
        move_count=0;
	 //if(( gps_state == 0)&&(mmi_bootup_is_sim_valid()))
	 { 
           //gps_turn_on_gps();
#if 0//defined(__KJX_EASY_WEB_DOG__)
	#if defined(__KJX_EASY_OBD__)
		kjx_obd_uart_init();
	#endif /* __KJX_EASY_OBD__ */
		kjx_dog_radar_open();
		g_idle_sleep = 0;
#endif /* __KJX_EASY_WEB_DOG__ */
  	   #if 0//defined(__KJX_EASY_MODEL_W__)
	     g_gps_status=1;
	     #ifdef GGT_DUB
	        GT_TRACE("g_sensor_game_sample get_sensor_status:KAL_TRUE\r\n");
	     #endif
	     GT_LBS_update_with_sensor_status(KAL_TRUE);
  	   #endif

	 }
   }

#if 0//def GGT_DUB
   if(gps_state)
   {
       GT_TRACE("g_sensor_game_cb: move_count: %d\r\n", move_count);
   }
#endif
   
    if((move_count == 3*60)/*&&( gps_state == 1)*/)
    { 
	  move_count = 0;
         //gps_turn_off_gps();
#if 0//defined(__KJX_EASY_WEB_DOG__)
#if defined(__KJX_EASY_OBD__)
		kjx_obd_uart_set_sleep(KAL_FALSE);
#endif /* __KJX_EASY_OBD__ */
		kjx_dog_radar_close();
		g_idle_sleep = 1;
#endif /* __KJX_EASY_WEB_DOG__ */
		 
	#if 0//defined(__KJX_EASY_MODEL_W__)
	  g_gps_status=0;
	  #ifdef GGT_DUB
	     GT_TRACE("g_sensor_game_sample get_sensor_status:KAL_FALSE\r\n");
	  #endif
	  GT_LBS_update_with_sensor_status(KAL_FALSE);
	#endif

    }
    else if((move_count == 3*60)/*&&( gps_state == 0)*/)
    {
        move_count = 0;
    }
#endif /* __KJXEASY_STATIC_ALARM__ */
}
 
extern int out_data[3];	
extern int yas_mma8452q_measure(void);
void acc_mag_sensor_cycle(void)
{
  //int acc[16]={0};
   StopTimer(KJX_TIMER_ID_SENSOR);
   memset(out_data, 0x00, sizeof(out_data));
   //yas_simple_measure(acc) ;/*yas_mma8452q_measure*/
   yas_simple_measure() ;/*yas_mma8452q_measure*/

   if((out_data[0]==1)||(out_data[1]==1)||(out_data[2]==1))
   {
      g_kjx_sensor_func.g_sensor_game_cb(TRUE);
   }
   else
   {
      g_kjx_sensor_func.g_sensor_game_cb(FALSE);
   }
       
   StartTimer(KJX_TIMER_ID_SENSOR, 1000, g_kjx_sensor_func.acc_mag_sensor_cycle);
}
 

void acc_mag_sensor_start(void)
{
   int ret;

   x_data=0;
   y_data=0;
   z_data=0;
//dbg_print("%s:%d\r\n",__FILE__,__LINE__);

  if(g_sensor_status)
  { 
     //dbg_print("%s:%d\r\n",__FILE__,__LINE__);
     return;
  }
  
   //dbg_print("%s:%d\r\n",__FILE__,__LINE__);
   g_sensor_status=1;
   
   ret = acc_mag_sensor_init();
   if(ret == YAS_NO_ERROR)
   {
      g_kjx_sensor_func.acc_mag_sensor_cycle();
   }
}

void acc_mag_sensor_stop(void)
{
   int ret;
   
   g_sensor_status=0;
   
   StopTimer(KJX_TIMER_ID_SENSOR);
   yas_simple_term();
}
#endif
