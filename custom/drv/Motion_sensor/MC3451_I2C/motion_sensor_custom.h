#ifndef _MOTION_SENSOR_CUSTOM_H_
#define _MOTION_SENSOR_CUSTOM_H_
//#define MS_SLAVE_ADDR       0x98 //0x4C << 1 
#define MS_SLAVE_ADDR       0x5A    //0x2d << 1 

//#define MS_SLAVE_ADDR       0xD8 //0x6C << 1 //for MC3433 VPP high level
//#define MCUBE_CHIP_IS_MC3230 //for  MC3230, MC3430 
//#define MCUBE_CHIP_IS_MC3210 //forr MC3210，MC3410，MC3250,mc3256
//#define MCUBE_CHIP_IS_MC3433
#define MCUBE_CHIP_IS_MC3451

//Register define start
#define MS_REG_XOUT 0x00
#define MS_REG_YOUT 0x01
#define MS_REG_ZOUT 0x02
#define MS_REG_TILT 0x03
#define MS_REG_OPSTAT 0x04
#define MS_REG_SC 0x05

#define MS_REG_INTEN 0x06
#define MS_REG_MODE 0x07
#define MS_REG_SAMPR 0x08
#define MS_REG_TAPEN 0x09
#define MS_REG_TAPP 0x0A

#define MS_REG_DROP 0x0B
#define MS_REG_SHDB 0x0C
//0x0D~0x17 Reserved
#define MS_REG_CHIPID 0x18
//0x19~0x20 Reserved

#define MS_REG_XOFFL 0x21
#define MS_REG_XOFFH 0x22
#define MS_REG_YOFFL 0x23
#define MS_REG_YOFFH 0x24
#define MS_REG_ZOFFL 0x25
#define MS_REG_ZOFFH 0x26

#define MS_REG_XGAIN 0x27
#define MS_REG_YGAIN 0x28
#define MS_REG_ZGAIN 0x29
//0x2A RESERVED

#define MS_REG_SHAKE_TH 0x2B
#define MS_REG_UD_Z_TH 0x2C
#define MS_REG_UD_X_TH 0x2D
#define MS_REG_RL_Z_TH 0x2E
#define MS_REG_RL_Y_TH 0x2F
#define MS_REG_FB_Z_TH 0x30
#define MS_REG_DROP_TH 0x31
#define MS_REG_TAP_TH 0x32
//0x33~0x3A RESERVED

#define MS_REG_PCODE 0x3B
//0x3C~0x3F RESERVED

#define MOTION_THM 0x11
#define MOTION_DUM 0x12
#define MOTION_THS 0x13
#define MOTION_DUS 0x14
#define STEPS_WAITING  0x15
#define THRETH_DYN 0x16
#define MINCOUNT_CON 0x17
#define TIMEOUT_CON 0x18
#define WRITE_PEDOCOUNT 0x19



#define MOTION_THM_VALUE    80   // 50
#define MOTION_DUM_VALUE    4    //  4
#define MOTION_THS_VALUE    100    //  100
#define MOTION_DUS_VALUE    3    //  3
#define STEPS_WAITING_VALUE    6  //  4         建议可以尝试调大
#define THRETH_DYN_VALUE    50    //  29       
#define MINCOUNT_CON_VALUE    3    //  10
#define TIMEOUT_CON_VALUE    50    //  50
/*
MOTION_THM寄存器（anymotion），默认数据是50，单位是1mg。代表这一次和上次的差值门限设置，大于条件检测运动. 配置越大越难触发
MOTION_DUM寄存器（anymotion）, 默认是4，每一个单位是25ms，默认4表示连续运动100ms才会触发中断，配置越大越难触发
MOTION_THS 寄存器（anymotion）默认数据是100，单位是1mg。代表这一次和上次的差值门限设置，小雨条件检测静止. 配置越大约难重置中断
MOTION_DUS寄存器（anymotion）, 默认是3，每一个单位是25ms，默认3表示连续静止75ms才会重置中断，配置越大越难重置
STEPS_WAITING 寄存器（计步器），默认是4，单位是25ms ,这个参数是设置步数最小触发间隔，4表示100ms 之后才会触发下一次计步。建议可以尝试调大
THRETH_DYN 寄存器（计步器），默认是29, 单位是10mg, 其表示动态门限的最小值，建议不要修改。如果觉得太容易计步器可以尝试改大。
MINCOUNT_CON寄存器（计步器）,默认是10，单位是步数，其用来配置连续走有效门限，连续超过10步的步数才会统计在内（之前的版本是3，最小值所以容易触发）
TIMEOUT_CON 寄存器（计步器）默认是50，单位是200ms，50表示10秒没有计步，则会重置计步器连续统计状态。
WRITE_PEDOCOUNT 寄存器（计步器），复写计步器步数。连续写入4个字节，顺序是
（uint8_t）count
（uint8_t）(count >>8)
（uint8_t）(count >>16)
（uint8_t）(count >>24)
*/

#define MS_STANDBY_MODE 0x03
#define MS_WAKE_MODE 0x01    //0x59
#define MS_SNIFF_MODE 0x02 

//Tilt Status
#define TILT_STATUS_BAFR_MASK    0x03
#define TILT_STATUS_BAFR_UNKNOWN 0x00
#define TILT_STATUS_BAFR_FRONT   0x01
#define TILT_STATUS_BAFR_BACK    0x02

#define TILT_STATUS_POLA_MASK    0x1C
#define TILT_STATUS_POLA_UNKNOWN 0x00
#define TILT_STATUS_POLA_LEFT    0x04
#define TILT_STATUS_POLA_RIGHT   0x08
#define TILT_STATUS_POLA_DOWN    0x14
#define TILT_STATUS_POLA_UP      0x18

#define TILT_STATUS_TAP_EVENT    0x20
#define TILT_STATUS_DROP_EVENT   0x40
#define TILT_STATUS_SHAKE_EVENT  0x80

//Sleep Count
#define SLEEP_COUNT 0

//INT Enable
/** Front/Back Interrupt Enable */
#define FRONT_BACK           0x0001u
/** Portrait/Landscape Interrupt Enable */
#define PORTRAIT_LANDSCAPE   0x0002u
/** Tap Interrupt Enable */
#define TAP                  0x0004u
/** Sniff Exit Transition Interrupt Enable */
#define SNIFF_EXIT           0x0008u
/** Accelerometer Measurement Interrupt Enable */
#define MEASUREMENT          0x0010u
/** Accelerometer Shake X-axis Interrupt Enable */
#define SHAKE_X              0x0080u
/** Accelerometer Shake Y-axis Interrupt Enable */
#define SHAKE_Y              0x0040u
/** Accelerometer Shake Z-axis Interrupt Enable */
#define SHAKE_Z              0x0020u
/** Accelerometer Drop Interrupt Enable */
#define DROP                 0x0100u

/* MC3230 interrupt defaults */
#define MC3230_DFLT_INTS   (FRONT_BACK | PORTRAIT_LANDSCAPE | TAP | \
                            SNIFF_EXIT | MEASUREMENT | SHAKE_X | \
                            SHAKE_Y | SHAKE_Z | DROP)

//Mode
#define AUTO_WAKE_ENABLE 0x08
#define AUTO_SNIFF_ENABLE 0x10

//TAP
#define TAP_X_ENABLE 0x20
#define TAP_Y_ENABLE 0x40
#define TAP_Z_ENABLE 0x80
#define TAP_PULSE_COUNT 0x0F //This value sets the number of samples for which a tap pulse must exceed the TAP_TH threshold before it is rejected as not a tap event. If the values detected by the sensor exceed the TAP_TH threshold for longer than the reject count, no tap event is detected and the interrupt is not set.
#define TAP_THRESHOLD 0x20

//Drop
#define DROP_DEBOUNCE   0x05 // 0~255
#define DROP_INTERRUPT  0x40  //bit6: 0: disable ; 1: enable
#define DROP_MODE  0x00 //bit7: 0: mode_A; 1: mode_B
#define DROP_THRESHOLD 0x7F //~2.9mg/LSB

//Shake
#define SHAKE_DEBOUNCE 0x0a  //0~63
#define SHAKE_THRESHOLD 0x0  //offset value:mag(X/Y/Z) > 1.3g + SHAKE_TH, ~2.9mg/LSB

typedef enum
{
   MCUBE_DROP_MODE_A,
   MCUBE_DROP_MODE_B
} mCubeAccelDropMode_t;

#define TAP_DETECT_X   0x20
	/** Enable Tap Detection on Y-axis */
#define TAP_DETECT_Y   0x40
	/** Enable Tap Detection on Z-axis */
#define TAP_DETECT_Z   0x80

/* Calibration parameters for gesture event triggering */
#define MC3230_DFLT_UDZ_THRESH           0x0
#define MC3230_DFLT_UDX_THRESH           0x0
#define MC3230_DFLT_RLZ_THRESH           0x0
#define MC3230_DFLT_RLY_THRESH           0x0
#define MC3230_DFLT_FBZ_THRESH           0x0
#define MC3230_DFLT_DROP_THRESH          0x0
#define MC3230_DFLT_TAP_THRESH           0x0
#define MC3230_DFLT_SHAKE_DEBOUNCE       0x0
#define MC3230_DFLT_SHAKE_THESH_OFFSET   0x0
#define MC3230_DFLT_DROP_DEBOUNCE        0x0
#define MC3230_DFLT_DROP_MODE            MCUBE_DROP_MODE_A
#define MC3230_DFLT_TAP_AXES             TAP_DETECT_Z
#define MC3230_DFLT_TAP_DETECT_SAMP      0x0

#if defined MCUBE_CHIP_IS_MC3210
/* acceleration 10-Bits,+/-4g */
#define ACC_0G_X      512
#define ACC_1G_X      512+127
#define ACC_MINUS1G_X 512-128
#define ACC_0G_Y      512
#define ACC_1G_Y      512+127
#define ACC_MINUS1G_Y 512-128
#define ACC_0G_Z      512     
#define ACC_1G_Z      512+127
#define ACC_MINUS1G_Z 512-128
#elif defined MCUBE_CHIP_IS_MC3433
#define ACC_0G_X      256
#define ACC_1G_X      256+63
#define ACC_MINUS1G_X 256-64
#define ACC_0G_Y      256
#define ACC_1G_Y      256+63
#define ACC_MINUS1G_Y 256-64
#define ACC_0G_Z      256     
#define ACC_1G_Z      256+63
#define ACC_MINUS1G_Z 512-64
#elif defined MCUBE_CHIP_IS_MC3451
#define ACC_0G_X      256
#define ACC_1G_X      256+63
#define ACC_MINUS1G_X 256-64
#define ACC_0G_Y      256
#define ACC_1G_Y      256+63
#define ACC_MINUS1G_Y 256-64
#define ACC_0G_Z      256     
#define ACC_1G_Z      256+63
#define ACC_MINUS1G_Z 512-64
#else
/* acceleration 8-Bits,+/-1.5g */
#define ACC_0G_X      127
#define ACC_1G_X      212
#define ACC_MINUS1G_X 43
#define ACC_0G_Y      127   
#define ACC_1G_Y      212
#define ACC_MINUS1G_Y 43
#define ACC_0G_Z      127       
#define ACC_1G_Z      212
#define ACC_MINUS1G_Z 43
#endif

extern MotionSensor_customize_function_struct *ms_GetFunc(void);
extern MotionSensor_custom_data_struct *ms_get_data(void);

//char sram_binxxx[] = {};


#endif //_MOTION_SENSOR_CUSTOM_H_

