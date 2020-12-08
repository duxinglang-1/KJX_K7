/*
 * CONFIDENTIAL
 *
 * Copyright (c) 2010 Yamaha Corporation
 */
#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
#include "yas.h"

struct yas_acc_calibration_module {
	struct yas_acc_calibration_callback callback;
	struct yas_vector data[YAS_DEFAULT_ACCCALIB_LENGTH];
	struct yas_vector offset;
	int32_t variation;
	int init;
	int index;
	int num;
};
static struct yas_acc_calibration_module this_module;

static int
yas_lock(void)
{
	struct yas_acc_calibration_callback *cbk = &this_module.callback;
	int err;

	if (cbk->lock != NULL && cbk->unlock != NULL)
		err = cbk->lock();
	else
		err = YAS_NO_ERROR;

	return err;
}

static int
yas_unlock(void)
{
	struct yas_acc_calibration_callback *cbk = &this_module.callback;
	int err;

	if (cbk->lock != NULL && cbk->unlock != NULL)
		err = cbk->unlock();
	else
		err = YAS_NO_ERROR;

	return err;
}

static int32_t
square(int32_t data)
{
	return data * data;
}

static int
get_offset(struct yas_vector *calib_offset)
{
	int i;

	yas_lock();

	if (this_module.init != 1) {
		yas_unlock();
		return YAS_ERROR_NOT_INITIALIZED;
	}

	if (calib_offset == NULL) {
		yas_unlock();
		return YAS_ERROR_ARG;
	}
	for (i = 0; i < 3; i++)
		calib_offset->v[i] = this_module.offset.v[i];

	yas_unlock();

	return YAS_NO_ERROR;
}

static int
get_threshold(struct yas_acc_calibration_threshold *threshold)
{
	yas_lock();

	if (this_module.init != 1) {
		yas_unlock();
		return YAS_ERROR_NOT_INITIALIZED;
	}

	if (threshold == NULL) {
		yas_unlock();
		return YAS_ERROR_ARG;
	}
	threshold->variation = this_module.variation;

	yas_unlock();

	return YAS_NO_ERROR;
}

static int
set_threshold(struct yas_acc_calibration_threshold *threshold)
{
	yas_lock();

	if (this_module.init != 1) {
		yas_unlock();
		return YAS_ERROR_NOT_INITIALIZED;
	}

	if (threshold == NULL || threshold->variation < 0) {
		yas_unlock();
		return YAS_ERROR_ARG;
	}
	this_module.variation = threshold->variation;

	yas_unlock();

	return YAS_NO_ERROR;
}

static int
update(struct yas_vector *v)
{
	struct yas_vector avg, sum;
	struct yas_vector gravity = { {0, 0, 9806000} };
	int i, j;

	yas_lock();

	if (this_module.init != 1) {
		yas_unlock();
		return YAS_ERROR_NOT_INITIALIZED;
	}

	if (v == NULL) {
		yas_unlock();
		return YAS_ERROR_ARG;
	}
	for (i = 0; i < 3; i++)
		this_module.data[this_module.index].v[i] = v->v[i] / 1000;
	this_module.index++;
	this_module.num++;

	if (this_module.index >= YAS_DEFAULT_ACCCALIB_LENGTH)
		this_module.index = 0;
	if (this_module.num < YAS_DEFAULT_ACCCALIB_LENGTH) {
		yas_unlock();
		return 0;
	} else {
		this_module.num = YAS_DEFAULT_ACCCALIB_LENGTH;
	}

	for (i = 0; i < 3; i++)
		avg.v[i] = 0;
	for (i = 0; i < YAS_DEFAULT_ACCCALIB_LENGTH; i++) {
		for (j = 0; j < 3; j++)
			avg.v[j] += this_module.data[i].v[j];
	}
	for (i = 0; i < 3; i++)
		avg.v[i] /= YAS_DEFAULT_ACCCALIB_LENGTH;

	for (i = 0; i < 3; i++)
		sum.v[i] = 0;
	for (i = 0; i < YAS_DEFAULT_ACCCALIB_LENGTH; i++) {
		for (j = 0; j < 3; j++)
			sum.v[j] += square(this_module.data[i].v[j] - avg.v[j]);
	}
	for (i = 0; i < 3; i++)
		sum.v[i] /= YAS_DEFAULT_ACCCALIB_LENGTH;
	YLOGD(("variance [%d][%d][%d]\n", sum.v[0], sum.v[1], sum.v[2]));
	for (i = 0; i < 3; i++) {
		if (sum.v[i] > this_module.variation) {
			yas_unlock();
			return 0;
		}
	}
	for (i = 0; i < 3; i++) {
		this_module.offset.v[i] = avg.v[i] * 1000;
		this_module.offset.v[i] -= gravity.v[i];
	}
	YLOGD(("offset [%d][%d][%d]\n",
				this_module.offset.v[0],
				this_module.offset.v[1],
				this_module.offset.v[2]));

	yas_unlock();

	return 1;
}

static int
init(void)
{
	int i;

	yas_lock();

	if (this_module.init != 0) {
		yas_unlock();
		return YAS_ERROR_NOT_INITIALIZED;
	}

	this_module.variation = YAS_DEFAULT_ACCCALIB_DISTORTION;
	this_module.index = 0;
	this_module.num = 0;
	for (i = 0; i < 3; i++)
		this_module.offset.v[i] = 0;

	this_module.init = 1;

	yas_unlock();

	return YAS_NO_ERROR;
}

static int
term(void)
{
	yas_lock();

	if (this_module.init != 1) {
		yas_unlock();
		return YAS_ERROR_NOT_INITIALIZED;
	}

	this_module.init = 0;

	yas_unlock();
	return YAS_NO_ERROR;
}

int
yas_acc_calibration_init(struct yas_acc_calibration *funcs)
{
	if (funcs == NULL)
		return YAS_ERROR_ARG;

	/* Set callback interface */
	this_module.callback = funcs->callback;

	funcs->init = init;
	funcs->term = term;
	funcs->update = update;
	funcs->get_offset = get_offset;
	funcs->get_threshold = get_threshold;
	funcs->set_threshold = set_threshold;

	this_module.init = 0;

	return YAS_NO_ERROR;
}

#endif/*__MOTION_SENSOR_MMA8452Q_SUPPORT__*/
