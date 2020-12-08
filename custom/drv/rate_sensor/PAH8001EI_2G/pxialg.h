#ifndef WIN32
#ifndef PXIALG_H__
#define PXIALG_H__
#include "stdint.h"
#include "kal_release.h"
#include "custom_config.h"
#include "gpio_sw.h"
#include "drv_comm.h"
#include "eint.h"
#include "motion_sensor.h"
#include "rate_sensor_custom.h"
#include "rate_sensor_I2C.h"
#include "motion_sensor_hw_define.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "dcl.h"
#include "us_timer.h"

#define PXIALG_API

typedef enum {
	FLAG_DATA_READY = 0,
	FLAG_DATA_NOT_READY,
	FLAG_DATA_LOSS,
	FLAG_NO_TOUCH,
	FLAG_DATA_ERROR,
	FLAG_POOR_SIGNAL,
	FLAG_FIFO_ERROR, //FIFO is not enough
	FLAG_TIMING_ERROR,
} PXI_STATUS_FLAG;

/**
 * @brief When HRD and MEMS data are ready, call this function to do the algorithm processing
 *
 * @param[in] HRD_Data   Pointer to the buffer where HRD data (13 Bytes) is stored.
 * @param[in] MEMS_Data  Pointer to the buffer where MEMS data (3*sizeof(float) Bytes) is stored.
 *
 * @return Return one of the PXI_STATUS_FLAG types.
 */
PXIALG_API int32_t PxiAlg_Process(unsigned char *HRD_Data, float *MEMS_Data);

/**
 * @brief Call this function to get Heart Rate
 *
 * @param[out] hr   Pointer to a float variable where heart rate is stored
 *
 * @return None
 */
PXIALG_API void PxiAlg_HrGet(float *hr);

/**
 * @brief Call this function to determine the version of the algorithm
 *
 *
 * @return Version of the algorithm
 */
PXIALG_API int32_t PxiAlg_Version(void);

/**
 * @brief Call this funtion to get Ready_Flag
 *
 * @return Return Ready_Flag
 */
PXIALG_API unsigned char PxiAlg_GetReadyFlag(void);

/**
 * @brief Call this funtion to get Motion_Flag
 *
 * @return Return Motion_Flag
 */
PXIALG_API unsigned char PxiAlg_GetMotionFlag(void);

/**
 * @brief Call this function to notify algorithm the MEMS Scale of Motion Sensor
 *
 * @param[in] scale The MEMS Scale of Motion Sensor. Only 0(2G),1(4G~16G) are supported.
 *
 * @return 1 for success. 0 for failure.
 */
PXIALG_API uint8_t PxiAlg_SetMemsScale(int scale);

/**
 * @brief Call this function to get PPG Signal Grade
 *
 * @param[out] grade	Pointer to a float variable where signal grade is stored.
 *
 * @return  Return 1 when Signal Grade is ready. Otherwise, return 0.
 */
PXIALG_API uint8_t PxiAlg_GetSigGrade(float *grade);

/**
 * @brief Call this function to set PPG Signal Grade Threshold
 *
 * @param[in] threshold	The PPG Signal Grade Threshold. Its value ranges from 0 to 100.
 *
 * @return 1 for success. 0 for failure.
 */
PXIALG_API uint8_t PxiAlg_SetSigGradeThrd(float thrd);

/**
 * @brief Call this function to enable or disable fast output mode
 *
 * @param[in] en The flag of fast output mode.
 */
PXIALG_API void PxiAlg_EnableFastOutput(uint8_t en);

/**
 * @brief Call this function to enable or disable motion mode
 *
 * @param[in] en The flag of motion mode.
 */
PXIALG_API void PxiAlg_EnableMotionMode(uint8_t en);

/**
 * @brief Call this function to enable or disable auto mode
 * @param[in] enable The flag of auto mode.
 */
PXIALG_API void PxiAlg_EnableAutoMode(uint8_t en);

/**
 * @brief Call this function to open algorithm
 */
PXIALG_API void PxiAlg_Open(void);

/**
 * @brief Call this function to close/reset algorithm
 */
PXIALG_API void PxiAlg_Close(void);

/**
 * @brief Call this function to get the alarm flag of fast output
* @param[out] get the alarm flag of fast output
 * @return  Return 1 when the flag is set. Otherwise, return 0.
 */
PXIALG_API uint8_t PxiAlg_GetFastOutAlarmFlag(void);

/**
 * @brief Call this function to enable or disable mems0 signal grade mode
 * @param[in] 1 : enable. 0 : disable.
 */
PXIALG_API void PxiAlg_EnableMEMS0SigGrade(uint8_t en);


/**
 * @brief Call this function to get the alarm flag of signal bad
 * @param[out] get the alarm flag of bad signal
 * @return  Return 1 when the flag is set. Otherwise, return 0.
 */
PXIALG_API uint8_t PxiAlg_GetSignalBadAlarm();


#endif /* PXIALG_H__ */
#endif