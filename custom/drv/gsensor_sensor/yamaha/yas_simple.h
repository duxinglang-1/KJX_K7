/*
 * Copyright (c) 2010 Yamaha Corporation
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef __YAS_SIMPLE_H__
#define __YAS_SIMPLE_H__

#include "yas.h"

#define YAS_SIMPLE_LOG_ENABLE                   (0)

#define YAS_SIMPLE_MEASURE_INTERVAL             (50)

struct yas_acc_machdep {
	int (*device_open)(void);
	int (*device_close)(void);
	int (*device_write)(uint8_t addr, const uint8_t *buf, int len);
	int (*device_read)(uint8_t addr, uint8_t *buf, int len);
	void (*msleep)(int msec);
};

struct yas_mag_machdep {
	int (*device_open)(void);
	int (*device_close)(void);
#if YAS_MAG_DRIVER == YAS_MAG_DRIVER_YAS529
	int (*device_write)(const uint8_t *buf, int len);
	int (*device_read)(uint8_t *buf, int len);
#else
	int (*device_write)(uint8_t addr, const uint8_t *buf, int len);
	int (*device_read)(uint8_t addr, uint8_t *buf, int len);
#endif
	void (*msleep)(int msec);
};

struct yas_gyro_machdep {
	int (*device_open)(void);
	int (*device_close)(void);
	int (*device_write)(uint8_t addr, const uint8_t *buf, int len);
	int (*device_read)(uint8_t addr, uint8_t *buf, int len);
	void (*msleep)(int msec);
};

#if YAS_SIMPLE_LOG_ENABLE
struct yas_log {
	int (*log_open)(void);
	int (*log_close)(void);
	int (*log_write)(const char *buf, int len);
};
#endif

struct yas_machdep {
	struct yas_mag_machdep mag;
	struct yas_acc_machdep acc;
	struct yas_gyro_machdep gyro;
#if YAS_SIMPLE_LOG_ENABLE
	struct yas_log log;
#endif
	void (*current_time)(int32_t *sec, int32_t *msec);
};

int yas_simple_init(struct yas_machdep *func);
int yas_simple_term(void);
int yas_simple_get_calib_enable(int *enable);
int yas_simple_set_calib_enable(int enable);
int yas_simple_get_calib_mode(int *mode, int *num_samples);
int yas_simple_set_calib_mode(int mode, int num_samples);
int yas_simple_get_calib_static_matrix(struct yas_matrix *matrix);
int yas_simple_set_calib_static_matrix(struct yas_matrix *matrix);
int yas_simple_get_enable(int *enable_acc, int *enable_mag, int *enabled_gyro);
int yas_simple_set_enable(int enable_acc, int enable_mag, int enable_gyro);
#if 1
//int yas_simple_measure(int *data);
int yas_simple_measure(void);
#else
int yas_simple_measure(struct yas_acc_data *acc, struct yas_mag_data *mag,
		struct yas_gyro_data *gyro, struct yas_vector *swgyro,
		struct yas_vector *ori, struct yas_matrix *matrix,
		struct yas_quaternion *q, struct yas_vector *grav,
		struct yas_vector *lacc, struct yas_vector *rotvec,
		struct yas_mag_calibration_result *r);
#endif
#if YAS_SUPPORT_FUSION_DRIVER
int yas_simple_get_fusion_enable(int *enable);
int yas_simple_set_fusion_enable(int enable);
#endif
#if YAS_SUPPORT_SOFTWARE_GYROSCOPE
int yas_simple_get_swgyro_enable(int *enable);
int yas_simple_set_swgyro_enable(int enable);
#endif

int yas_simple_get_position(int *position_acc, int *position_mag,
		int *position_gyro);
int yas_simple_set_position(int position_acc, int position_mag,
		int position_gyro);
int yas_simple_get_offset(struct yas_offset *offset);
int yas_simple_set_offset(struct yas_offset *offset);
int yas_simple_get_filter_enable(int *filter_acc, int *filter_mag,
		int *filter_gyro);
int yas_simple_set_filter_enable(int filter_acc, int filter_mag,
		int filter_gyro);
int yas_simple_get_shape(int *shape);
int yas_simple_set_shape(int shape);
int yas_simple_get_delay(int *delay);
int yas_simple_set_delay(int delay);
#if YAS_MAG_DRIVER == YAS_MAG_DRIVER_YAS529
int yas_simple_read_reg(uint8_t *buf, int len);
int yas_simple_write_reg(const uint8_t *buf, int len);
#else
int yas_simple_read_reg(uint8_t addr, uint8_t *buf, int len);
int yas_simple_write_reg(uint8_t addr, const uint8_t *buf, int len);
#endif
#if YAS_SIMPLE_LOG_ENABLE
int yas_simple_get_log_enable(int *enable);
int yas_simple_set_log_enable(int enable);
#endif

#endif
