/*
 * CONFIDENTIAL
 * Copyright (c) 2010-2011 Yamaha Corporation
 */

#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
#include "yas_simple.h"

#if YAS_SIMPLE_LOG_ENABLE
#include <stdio.h>
#include <string.h>
#endif

struct yas_simple_driver {
	int initialized;
	struct yas_mag_offset offset[YAS_MAGCALIB_SHAPE_NUM];
	struct yas_matrix dynamic_matrix[YAS_MAGCALIB_SHAPE_NUM];
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	struct yas_mag_driver mag;
	struct yas_mag_calibration magcalib;
#endif
#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	struct yas_acc_driver acc;
#endif
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	struct yas_gyro_driver gyro;
#endif
	struct yas_utility util;
#if YAS_SUPPORT_SOFTWARE_GYROSCOPE
	struct yas_swgyro swgyro;
#endif
#if YAS_SUPPORT_FUSION_DRIVER
	struct yas_fusion fusion;
#endif
	int calib_enable;
	int calib_mode;
	int calib_samples;
	int fusion_enable;
	int swgyro_enable;
	int shape;
	int32_t delay;
	int32_t time_sec;
	int32_t time_msec;
#if YAS_SIMPLE_LOG_ENABLE
	struct yas_log log;
	int log_enable;
#endif
	struct yas_matrix static_matrix;
	void (*current_time)(int32_t *sec, int32_t *msec);
};
static struct yas_simple_driver this_driver;

static void
current_time(int32_t *sec, int32_t *msec)
{
	*sec = this_driver.time_sec;
	*msec = this_driver.time_msec;
}

int
yas_simple_get_calib_enable(int *enable)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (enable == NULL)
		return YAS_ERROR_ARG;
	*enable = this_driver.calib_enable;

	return YAS_NO_ERROR;
}

int
yas_simple_set_calib_enable(int enable)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	this_driver.calib_enable = !!enable;

	return YAS_NO_ERROR;
}

int
yas_simple_get_calib_mode(int *mode, int *num_samples)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (mode == NULL || num_samples == NULL)
		return YAS_ERROR_ARG;
	*mode = this_driver.calib_mode;
	*num_samples = this_driver.calib_samples;

	return YAS_NO_ERROR;
}

int
yas_simple_set_calib_mode(int mode, int num_samples)
{
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	int mode_save = this_driver.calib_mode;
	int rt;
#endif

	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.magcalib.set_mode(mode);
	if (rt < 0)
		return rt;
	rt = this_driver.magcalib.set_max_sample(num_samples);
	if (rt < 0)
		this_driver.magcalib.set_mode(mode_save);
#endif
	this_driver.calib_mode = mode;
	this_driver.calib_samples = num_samples;

	return YAS_NO_ERROR;
}

int
yas_simple_get_calib_static_matrix(struct yas_matrix *matrix)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	if (matrix == NULL)
		return YAS_ERROR_ARG;
	*matrix = this_driver.static_matrix;
#endif

	return YAS_NO_ERROR;
}

int
yas_simple_set_calib_static_matrix(struct yas_matrix *matrix)
{
	int rt;

	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.mag.set_static_matrix(matrix);
	if (rt < 0)
		return rt;
#endif
	this_driver.static_matrix = *matrix;

	return YAS_NO_ERROR;
}

int
yas_simple_get_enable(int *enable_acc, int *enable_mag, int *enable_gyro)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (0
#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
			|| enable_acc == NULL
#endif
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
			|| enable_mag == NULL
#endif
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
			|| enable_gyro == NULL
#endif
			) {
		return YAS_ERROR_ARG;
	}
	if (enable_acc != NULL) {
#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
		*enable_acc = this_driver.acc.get_enable();
#else
		*enable_acc = 0;
#endif
	}
	if (enable_mag != NULL) {
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
		*enable_mag = this_driver.mag.get_enable();
#else
		*enable_mag = 0;
#endif
	}
	if (enable_gyro != NULL) {
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
		*enable_gyro = this_driver.gyro.get_enable();
#else
		*enable_gyro = 0;
#endif
	}

	return YAS_NO_ERROR;
}

int
yas_simple_set_enable(int enable_acc, int enable_mag, int enable_gyro)
{
	int rt, result = YAS_NO_ERROR;

	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	rt = this_driver.acc.set_enable(!!enable_acc);
	if (rt < 0)
		result = rt;
#else
	(void) enable_acc;
#endif
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.mag.set_enable(!!enable_mag);
	if (rt < 0)
		result = rt;
#else
	(void) enable_mag;
#endif
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	rt = this_driver.gyro.set_enable(!!enable_gyro);
	if (rt < 0)
		result = rt;
#else
	(void) enable_gyro;
#endif

	return result;
}

int
yas_simple_get_position(int *position_acc, int *position_mag,
		int *position_gyro)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (0
#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
			|| position_acc == NULL
#endif
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
			|| position_mag == NULL
#endif
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
			|| position_gyro == NULL
#endif
			) {
		return YAS_ERROR_ARG;
	}
	if (position_acc != NULL) {
#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
		*position_acc = this_driver.acc.get_position();
#else
		*position_acc = 0;
#endif
	}
	if (position_mag != NULL) {
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
		*position_mag = this_driver.mag.get_position();
#else
		*position_mag = 0;
#endif
	}
	if (position_gyro != NULL) {
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
		*position_gyro = this_driver.gyro.get_position();
#else
		*position_gyro = 0;
#endif
	}

	return YAS_NO_ERROR;
}

int
yas_simple_set_position(int position_acc, int position_mag, int position_gyro)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	this_driver.acc.set_position(position_acc);
#else
	(void) position_acc;
#endif
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	this_driver.mag.set_position(position_mag);
#else
	(void) position_mag;
#endif
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	this_driver.gyro.set_position(position_gyro);
#else
	(void) position_gyro;
#endif

	return YAS_NO_ERROR;
}

int
yas_simple_get_offset(struct yas_offset *offset)
{
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	int shape = 0;
	int i;
#endif

	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (offset == NULL)
		return YAS_ERROR_ARG;

#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	shape = this_driver.magcalib.get_shape();
	for (i = 0; i < YAS_MAGCALIB_SHAPE_NUM; i++) {
		this_driver.magcalib.set_shape(i);
		offset->mag[i].offset = this_driver.offset[i];
		offset->mag[i].accuracy = this_driver.magcalib.get_accuracy();
		offset->mag[i].dynamic_matrix = this_driver.dynamic_matrix[i];
	}
	this_driver.magcalib.set_shape(shape);
#endif

	return YAS_NO_ERROR;
}

int
yas_simple_set_offset(struct yas_offset *offset)
{
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	int shape = 0, i;
#endif
	int rt = YAS_NO_ERROR;

	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (offset == NULL)
		return YAS_ERROR_ARG;

#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	shape = this_driver.magcalib.get_shape();
	for (i = 0; i < YAS_MAGCALIB_SHAPE_NUM; i++) {
		this_driver.magcalib.set_shape(i);
		this_driver.magcalib.set_accuracy(offset->mag[i].accuracy);
		this_driver.offset[i] = offset->mag[i].offset;
		this_driver.dynamic_matrix[i] = offset->mag[i].dynamic_matrix;
	}
	this_driver.magcalib.set_shape(shape);
	this_driver.mag.set_dynamic_matrix(
			&this_driver.dynamic_matrix[this_driver.shape]);
	rt = this_driver.mag.set_offset(&this_driver.offset[this_driver.shape]);
#endif

	return rt;
}

int
yas_simple_get_filter_enable(int *filter_acc, int *filter_mag, int *filter_gyro)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (0
#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
			|| filter_acc == NULL
#endif
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
			|| filter_mag == NULL
#endif
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
			|| filter_gyro == NULL
#endif
			) {
		return YAS_ERROR_ARG;
	}
	if (filter_acc != NULL) {
#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
		*filter_acc = this_driver.acc.get_filter_enable();
#else
		*filter_acc = 0;
#endif
	}
	if (filter_mag != NULL) {
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
		*filter_mag = this_driver.mag.get_filter_enable();
#else
		*filter_mag = 0;
#endif
	}
	if (filter_gyro != NULL) {
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
		*filter_gyro = this_driver.gyro.get_filter_enable();
#else
		*filter_gyro = 0;
#endif
	}

	return YAS_NO_ERROR;
}

int
yas_simple_set_filter_enable(int filter_acc, int filter_mag, int filter_gyro)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	this_driver.acc.set_filter_enable(!!filter_acc);
#else
	(void) filter_acc;
#endif
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	this_driver.mag.set_filter_enable(!!filter_mag);
#else
	(void) filter_mag;
#endif
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	this_driver.gyro.set_filter_enable(!!filter_gyro);
#else
	(void) filter_gyro;
#endif

	return YAS_NO_ERROR;
}

int
yas_simple_get_shape(int *shape)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (shape == NULL)
		return YAS_ERROR_ARG;
	*shape = this_driver.shape;

	return YAS_NO_ERROR;
}

int
yas_simple_set_shape(int shape)
{
	int rt = YAS_NO_ERROR;

	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (YAS_MAGCALIB_SHAPE_NUM - 1 < shape)
		return YAS_ERROR_ARG;
	this_driver.shape = shape;
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	this_driver.magcalib.set_shape(shape);
	this_driver.mag.set_dynamic_matrix(
			&this_driver.dynamic_matrix[this_driver.shape]);
	rt = this_driver.mag.set_offset(&this_driver.offset[this_driver.shape]);
#endif
	return rt;
}

#if YAS_MAG_DRIVER == YAS_MAG_DRIVER_YAS529

int
yas_simple_read_reg(uint8_t *buf, int len)
{
	int rt = YAS_NO_ERROR;

	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (buf == NULL || len <= 0)
		return YAS_ERROR_ARG;
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.mag.read_reg(buf, len);
#endif
	return rt;
}

int
yas_simple_write_reg(const uint8_t *buf, int len)
{
	int rt = YAS_NO_ERROR;
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (buf == NULL || len <= 0)
		return YAS_ERROR_ARG;
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.mag.write_reg(buf, len);
#endif
	return rt;
}

#else

int
yas_simple_read_reg(uint8_t addr, uint8_t *buf, int len)
{
	int rt = YAS_NO_ERROR;
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (buf == NULL || len <= 0)
		return YAS_ERROR_ARG;
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.mag.read_reg(addr, buf, len);
#else
	(void) addr;
#endif
	return rt;
}

int
yas_simple_write_reg(uint8_t addr, const uint8_t *buf, int len)
{
	int rt = YAS_NO_ERROR;
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (buf == NULL || len <= 0)
		return YAS_ERROR_ARG;
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.mag.write_reg(addr, buf, len);
#else
	(void) addr;
#endif
	return rt;
}

#endif

#if YAS_SUPPORT_FUSION_DRIVER

int
yas_simple_get_fusion_enable(int *enable)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (enable == NULL)
		return YAS_ERROR_ARG;
	*enable = this_driver.fusion_enable;

	return YAS_NO_ERROR;
}

int
yas_simple_set_fusion_enable(int enable)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	this_driver.fusion_enable = !!enable;

	return YAS_NO_ERROR;
}

#endif

#if YAS_SUPPORT_SOFTWARE_GYROSCOPE

int
yas_simple_get_swgyro_enable(int *enable)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (enable == NULL)
		return YAS_ERROR_ARG;
	*enable = this_driver.swgyro_enable;

	return YAS_NO_ERROR;
}

int
yas_simple_set_swgyro_enable(int enable)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	this_driver.swgyro_enable = !!enable;

	return YAS_NO_ERROR;
}

#endif

int
yas_simple_get_delay(int *delay)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (delay == NULL)
		return YAS_ERROR_ARG;
	*delay = this_driver.delay;

	return YAS_NO_ERROR;
}

int
yas_simple_set_delay(int delay)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	this_driver.delay = delay;
#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	this_driver.acc.set_delay(this_driver.delay);
#endif
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	this_driver.mag.set_delay(this_driver.delay);
#endif
#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	this_driver.gyro.set_delay(this_driver.delay);
#endif
#if YAS_SUPPORT_SOFTWARE_GYROSCOPE
	this_driver.swgyro.set_delay(this_driver.delay);
#endif

	return YAS_NO_ERROR;
}

#if 1
int yas_simple_measure(void)  //(int *data)
{
   //this_driver.acc.measure(data);
   this_driver.acc.measure();
}
#else
int
yas_simple_measure(struct yas_acc_data *acc, struct yas_mag_data *mag,
		struct yas_gyro_data *gyro, struct yas_vector *swgyro,
		struct yas_vector *ori, struct yas_matrix *matrix,
		struct yas_quaternion *q, struct yas_vector *grav,
		struct yas_vector *lacc, struct yas_vector *rotvec,
		struct yas_mag_calibration_result *r)
{
	int i, state = 0, event = 0;
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	int delay, shape, rt;
#else
	(void)r;
#endif


	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (acc != NULL) {
#if YAS_ACC_DRIVER == YAS_ACC_DRIVER_NONE
		for (i = 0; i < 3; i++) {
			acc->raw.v[i] = 0;
			acc->xyz.v[i] = 0;
		}
		acc = NULL;
#else
		this_driver.acc.measure(acc);
#endif
	}

	if (gyro != NULL) {
#if YAS_GYRO_DRIVER == YAS_GYRO_DRIVER_NONE
		for (i = 0; i < 3; i++) {
			gyro->raw.v[i] = 0;
			gyro->xyz.v[i] = 0;
		}
		gyro = NULL;
#else
		this_driver.gyro.measure(gyro, 1);
#endif
	}

	if (mag != NULL) {
#if YAS_MAG_DRIVER == YAS_MAG_DRIVER_NONE
		for (i = 0; i < 3; i++) {
			mag->raw.v[i] = 0;
			mag->xyz.v[i] = 0;
		}
		mag = NULL;
#else
		if (r != NULL) {
			r->spread = 0;
			r->variation = 0;
			r->radius = 0;
			r->axis = 0;
			r->level = 0;
			r->accuracy = 0;
		}
		rt = this_driver.mag.measure(mag, &delay);
		if (rt & YAS_REPORT_OVERFLOW_OCCURED) {
			shape = this_driver.magcalib.get_shape();
			for (i = 0; i < YAS_MAGCALIB_SHAPE_NUM; i++) {
				this_driver.magcalib.set_shape(i);
				this_driver.magcalib.set_accuracy(0);
			}
			this_driver.magcalib.set_shape(shape);
			event = 1;
		}
		if ((rt & YAS_REPORT_HARD_OFFSET_CHANGED)
				|| (rt & YAS_REPORT_CALIB_OFFSET_CHANGED)) {
			this_driver.mag.get_offset(
					&this_driver.offset[this_driver.shape]);
			event = 1;
		}
		if (this_driver.calib_enable) {
#ifdef YAS_MAGCALIB_WITH_GYRO
			int32_t sec, msec, t;
			if (gyro == NULL)
				return YAS_ERROR_ARG;
			this_driver.current_time(&sec, &msec);
			t = sec * 1000 + msec;
			t = t < 0 ? 0 : t;
			state = this_driver.magcalib.update(&mag->raw,
					&gyro->xyz, t, r);
#else
			state = this_driver.magcalib.update(&mag->raw, r);
#endif
			if (state > 0) {
				this_driver.magcalib.get_offset(
						&this_driver.offset[
						this_driver.shape].calib_offset
						);
				this_driver.mag.set_offset(
						&this_driver.offset[
						this_driver.shape]);
				this_driver.magcalib.get_dynamic_matrix(
						&this_driver.dynamic_matrix[
						this_driver.shape]);
				this_driver.mag.set_dynamic_matrix(
						&this_driver.dynamic_matrix[
						this_driver.shape]);
			}
		}
#endif
	}

	if (q != NULL)
		for (i = 0; i < 4; i++)
			q->q[i] = 0;
	if (matrix != NULL)
		for (i = 0; i < 9; i++)
			matrix->matrix[i] = 0;
	for (i = 0; i < 3; i++) {
		if (grav != NULL)
			grav->v[i] = 0;
		if (lacc != NULL)
			lacc->v[i] = 0;
		if (rotvec != NULL)
			rotvec->v[i] = 0;
		if (swgyro != NULL)
			swgyro->v[i] = 0;
	}


#if YAS_SUPPORT_SOFTWARE_GYROSCOPE
	if (this_driver.swgyro_enable) {
		if (swgyro != NULL && acc != NULL && mag != NULL)
			this_driver.swgyro.update(&acc->xyz, &mag->xyz, swgyro);
	}
#else
	(void) swgyro;
#endif

	if (acc != NULL && mag != NULL && matrix != NULL) {
		this_driver.util.get_rotation_matrix(&acc->xyz, &mag->xyz,
				matrix);
	}
	if (matrix != NULL && ori != NULL)
		this_driver.util.get_euler(matrix, ori);


#if YAS_SUPPORT_FUSION_DRIVER
	if (this_driver.fusion_enable) {
		if (acc != NULL && mag != NULL && gyro != NULL && q != NULL
				&& grav != NULL && lacc != NULL
				&& rotvec != NULL) {
			/*
			 * FIXME mag should not be filtered by adaptive filter?
			 */
			this_driver.fusion.update(&acc->xyz, &mag->xyz,
					&gyro->xyz);
			this_driver.fusion.get_quaternion(q);
			this_driver.fusion.get_fusion(q, &acc->xyz, grav, lacc,
					rotvec);
			if (matrix != NULL) {
				this_driver.util.q_to_matrix(q, matrix);
				if (ori != NULL)
					this_driver.util.get_euler(matrix, ori);
			}
		}
	}
#endif

	this_driver.time_msec += this_driver.delay;
	if (1000 <= this_driver.time_msec) {
		this_driver.time_sec += this_driver.time_msec / 1000;
		this_driver.time_msec = this_driver.time_msec % 1000;
	}

#if YAS_SIMPLE_LOG_ENABLE
	if (this_driver.log_enable && this_driver.log.log_write != NULL) {
		static char logbuf[sizeof("-2147483647")*56 + 1];
		sprintf(logbuf,
			"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,"
			"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,"
			"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,"
			"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,"
			"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,"
			"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
			this_driver.offset[this_driver.shape].hard_offset[0],
			this_driver.offset[this_driver.shape].hard_offset[1],
			this_driver.offset[this_driver.shape].hard_offset[2],
			mag == NULL ? 0 : mag->xy1y2.v[0],
			mag == NULL ? 0 : mag->xy1y2.v[1],
			mag == NULL ? 0 : mag->xy1y2.v[2],
			mag == NULL ? 0 : mag->temperature,
			acc == NULL ? 0 : acc->raw.v[0],
			acc == NULL ? 0 : acc->raw.v[1],
			acc == NULL ? 0 : acc->raw.v[2],
			gyro == NULL ? 0 : gyro->raw.v[0],
			gyro == NULL ? 0 : gyro->raw.v[1],
			gyro == NULL ? 0 : gyro->raw.v[2],
			mag == NULL ? 0 : mag->raw.v[0],
			mag == NULL ? 0 : mag->raw.v[1],
			mag == NULL ? 0 : mag->raw.v[2],
			this_driver.offset[this_driver.shape].calib_offset.v[0],
			this_driver.offset[this_driver.shape].calib_offset.v[1],
			this_driver.offset[this_driver.shape].calib_offset.v[2],
			r == NULL ? 0 : r->dynamic_matrix.matrix[0],
			r == NULL ? 0 : r->dynamic_matrix.matrix[1],
			r == NULL ? 0 : r->dynamic_matrix.matrix[2],
			r == NULL ? 0 : r->dynamic_matrix.matrix[3],
			r == NULL ? 0 : r->dynamic_matrix.matrix[4],
			r == NULL ? 0 : r->dynamic_matrix.matrix[5],
			r == NULL ? 0 : r->dynamic_matrix.matrix[6],
			r == NULL ? 0 : r->dynamic_matrix.matrix[7],
			r == NULL ? 0 : r->dynamic_matrix.matrix[8],
			mag == NULL ? 0 : mag->xyz.v[0],
			mag == NULL ? 0 : mag->xyz.v[1],
			mag == NULL ? 0 : mag->xyz.v[2],
			acc == NULL ? 0 : acc->xyz.v[0],
			acc == NULL ? 0 : acc->xyz.v[1],
			acc == NULL ? 0 : acc->xyz.v[2],
			gyro == NULL ? 0 : gyro->xyz.v[0],
			gyro == NULL ? 0 : gyro->xyz.v[1],
			gyro == NULL ? 0 : gyro->xyz.v[2],
			state,
			r == NULL ? 0 : r->spread,
			r == NULL ? 0 : r->variation,
			r == NULL ? 0 : r->level,
			r == NULL ? 0 : r->accuracy,
			r == NULL ? 0 : r->radius,
			r == NULL ? 0 : r->axis,
			ori == NULL ? 0 : ori->v[0],
			ori == NULL ? 0 : ori->v[1],
			ori == NULL ? 0 : ori->v[2],
			grav == NULL ? 0 : grav->v[0],
			grav == NULL ? 0 : grav->v[1],
			grav == NULL ? 0 : grav->v[2],
			lacc == NULL ? 0 : lacc->v[0],
			lacc == NULL ? 0 : lacc->v[1],
			lacc == NULL ? 0 : lacc->v[2],
			rotvec == NULL ? 0 : rotvec->v[0],
			rotvec == NULL ? 0 : rotvec->v[1],
			rotvec == NULL ? 0 : rotvec->v[2],
			swgyro == NULL ? 0 : swgyro->v[0],
			swgyro == NULL ? 0 : swgyro->v[1],
			swgyro == NULL ? 0 : swgyro->v[2]);
		this_driver.log.log_write(logbuf, (int)strlen(logbuf));
	}
#endif
	return event | state;
}
#endif

#if YAS_SIMPLE_LOG_ENABLE
int
yas_simple_get_log_enable(int *enable)
{
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (enable == NULL)
		return YAS_ERROR_ARG;
	*enable = this_driver.log_enable;

	return YAS_NO_ERROR;
}

int
yas_simple_set_log_enable(int enable)
{
	const char *header
		= "hox,hoy1,hoy2,x,y1,y2,t,a1,a2,a3,"
		"g1,g2,g3,mxn,myn,mzn,mox,moy,moz,p11,"
		"p12,p13,p21,p22,p23,p31,p32,p33,mrx,mry,"
		"mrz,arx,ary,arz,grx,gry,grz,update,spread,variation,"
		"level,acc,radius,axis,azimuth,pitch,roll,vrx,vry,vrz,"
		"lrx,lry,lrz,rrx,rry,rrz,sgx,sgy,sgz\n";
	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (!this_driver.log_enable && enable) {
		if (this_driver.log.log_open != NULL) {
			if (this_driver.log.log_open() < 0)
				return YAS_ERROR_ERROR;
		}
		if (this_driver.log.log_write != NULL)
			this_driver.log.log_write(header, (int)strlen(header));
	}
	if (this_driver.log_enable && !enable) {
		if (this_driver.log.log_close != NULL) {
			if (this_driver.log.log_close() < 0)
				return YAS_ERROR_ERROR;
		}
	}

	this_driver.log_enable = !!enable;

	return YAS_NO_ERROR;
}
#endif

int
yas_simple_init(struct yas_machdep *func)
{
	static const struct yas_matrix no_conversion
		= { {10000, 0, 0, 0, 10000, 0, 0, 0, 10000} };
	int rt;
	int i, j;

	if (this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

	if (func->current_time == NULL)
		this_driver.current_time = current_time;
	else
		this_driver.current_time = func->current_time;

	this_driver.delay = YAS_SIMPLE_MEASURE_INTERVAL;
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	this_driver.mag.callback.lock = NULL;
	this_driver.mag.callback.unlock = NULL;
	this_driver.mag.callback.device_open = func->mag.device_open;
	this_driver.mag.callback.device_close = func->mag.device_close;
	this_driver.mag.callback.device_write = func->mag.device_write;
	this_driver.mag.callback.device_read = func->mag.device_read;
	this_driver.mag.callback.msleep = func->mag.msleep;
	this_driver.mag.callback.current_time = this_driver.current_time;

	this_driver.magcalib.callback.lock = NULL;
	this_driver.magcalib.callback.unlock = NULL;
#endif

#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	this_driver.acc.callback.lock = NULL;
	this_driver.acc.callback.unlock = NULL;
	this_driver.acc.callback.device_open = func->acc.device_open;
	this_driver.acc.callback.device_close = func->acc.device_close;
	this_driver.acc.callback.device_write = func->acc.device_write;
	this_driver.acc.callback.device_read = func->acc.device_read;
	this_driver.acc.callback.msleep = func->acc.msleep;
#endif

#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	this_driver.gyro.callback.lock = NULL;
	this_driver.gyro.callback.unlock = NULL;
	this_driver.gyro.callback.device_open = func->gyro.device_open;
	this_driver.gyro.callback.device_close = func->gyro.device_close;
	this_driver.gyro.callback.device_write = func->gyro.device_write;
	this_driver.gyro.callback.device_read = func->gyro.device_read;
	this_driver.gyro.callback.msleep = func->gyro.msleep;
#endif

#if YAS_SUPPORT_SOFTWARE_GYROSCOPE
	this_driver.swgyro.callback.current_time = this_driver.current_time;
	this_driver.swgyro.callback.lock = NULL;
	this_driver.swgyro.callback.unlock = NULL;
#endif

#if YAS_SUPPORT_FUSION_DRIVER
	this_driver.fusion.callback.lock = NULL;
	this_driver.fusion.callback.unlock = NULL;
	this_driver.fusion.callback.current_time = this_driver.current_time;
#endif

#if YAS_SIMPLE_LOG_ENABLE
	this_driver.log.log_open = func->log.log_open;
	this_driver.log.log_close = func->log.log_close;
	this_driver.log.log_write = func->log.log_write;
#endif
 
#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	yas_mag_driver_init(&this_driver.mag);
	yas_mag_calibration_init(&this_driver.magcalib);
#endif

#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	yas_acc_driver_init(&this_driver.acc);
#endif

#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	yas_gyro_driver_init(&this_driver.gyro, 0);
#endif

#if YAS_SUPPORT_SOFTWARE_GYROSCOPE
	yas_swgyro_init(&this_driver.swgyro);
#endif

#if YAS_SUPPORT_FUSION_DRIVER
	yas_fusion_init(&this_driver.fusion);
#endif

	yas_utility_init(&this_driver.util);

	for (i = 0; i < YAS_MAGCALIB_SHAPE_NUM; i++) {
		for (j = 0; j < 3; j++) {
			this_driver.offset[i].hard_offset[j] = 0x7f;
			this_driver.offset[i].calib_offset.v[j] = 0x7fffffff;
		}
		this_driver.dynamic_matrix[i] = no_conversion;
	}

#if YAS_SIMPLE_LOG_ENABLE
	this_driver.log_enable = 0;
#endif
	this_driver.calib_enable = 0;
	this_driver.shape = 0;
	this_driver.time_sec = 0;
	this_driver.time_msec = 0;
	this_driver.calib_mode = 0;
	this_driver.calib_samples = 0;
	this_driver.fusion_enable = 0;
	this_driver.swgyro_enable = 0;

#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	rt = this_driver.acc.init();
	if (rt < 0)
		return rt;
	rt = this_driver.acc.set_delay(this_driver.delay);
	if (rt < 0)
		return rt;
#endif

#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.mag.init();
	if (rt < 0)
		return rt;
	rt = this_driver.magcalib.init();
	if (rt < 0)
		return rt;
	rt = this_driver.mag.set_delay(this_driver.delay);
	if (rt < 0)
		return rt;
	rt = this_driver.mag.get_static_matrix(&this_driver.static_matrix);
	if (rt < 0)
		return rt;
	rt = this_driver.magcalib.get_mode();
	if (rt < 0)
		return rt;
	this_driver.calib_mode = rt;
	rt = this_driver.magcalib.get_max_sample();
	if (rt < 0)
		return rt;
	this_driver.calib_samples = rt;
#endif

#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	rt = this_driver.gyro.init();
	if (rt < 0)
		return rt;
	rt = this_driver.gyro.set_delay(this_driver.delay);
	if (rt < 0)
		return rt;
#endif

#if YAS_SUPPORT_SOFTWARE_GYROSCOPE
	rt = this_driver.swgyro.init();
	if (rt < 0)
		return rt;
	rt = this_driver.swgyro.set_delay(this_driver.delay);
	if (rt < 0)
		return rt;
#endif

#if YAS_SUPPORT_FUSION_DRIVER
	rt = this_driver.fusion.init();
	if (rt < 0)
		return rt;
#endif

	this_driver.initialized = 1;

	return YAS_NO_ERROR;
}

int
yas_simple_term(void)
{
	int rt, result = YAS_NO_ERROR;

	if (!this_driver.initialized)
		return YAS_ERROR_NOT_INITIALIZED;

#if YAS_SIMPLE_LOG_ENABLE
	if (this_driver.log_enable) {
		if (this_driver.log.log_close != NULL)
			this_driver.log.log_close();
	}
#endif

#if YAS_ACC_DRIVER != YAS_ACC_DRIVER_NONE
	rt = this_driver.acc.term();
	if (rt < 0)
		result = rt;
#endif

#if YAS_MAG_DRIVER != YAS_MAG_DRIVER_NONE
	rt = this_driver.mag.term();
	if (rt < 0)
		result = rt;
	rt = this_driver.magcalib.term();
	if (rt < 0)
		result = rt;
#endif

#if YAS_GYRO_DRIVER != YAS_GYRO_DRIVER_NONE
	rt = this_driver.gyro.term();
	if (rt < 0)
		result = rt;
#endif

#if YAS_SUPPORT_SOFTWARE_GYROSCOPE
	rt = this_driver.swgyro.term();
	if (rt < 0)
		result = rt;
#endif

#if YAS_SUPPORT_FUSION_DRIVER
	rt = this_driver.fusion.term();
	if (rt < 0)
		result = rt;
#endif

	this_driver.initialized = 0;

	return result;
}
#endif
