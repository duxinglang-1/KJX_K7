/*
 * CONFIDENTIAL
 *
 * Copyright (c) 2010 Yamaha Corporation
 */

#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
#include "yas.h"
#define _USE_MATH_DEFINES
#include <math.h>

static float
calc_intensity(float x, float y, float z)
{
    return (float)sqrt(x*x + y*y + z*z);
}

static int
get_rotation_matrix(struct yas_vector *acc, struct yas_vector *mag, struct yas_matrix *matrix)
{
    float m_intensity, g_intensity, a_intensity, b_intensity;
    float gsdata[3], msdata[3];
    float gdata[3], mdata[3], adata[3], bdata[3];
    int i;

    if (acc == NULL || mag == NULL || matrix == NULL) {
        return YAS_ERROR_ARG;
    }

    for (i = 0; i < 3; i++) {
        gsdata[i] = (float)(acc->v[i] / 1000000.0);
        msdata[i] = (float)(mag->v[i] / 1000000.0);
    }

    g_intensity = calc_intensity(gsdata[0], gsdata[1], gsdata[2]);
    m_intensity = calc_intensity(msdata[0], msdata[1], msdata[2]);
    if (g_intensity == 0 || m_intensity == 0) {
        return YAS_ERROR_ARG;
    }
    for (i = 0; i < 3; i++) {
        gdata[i] = -gsdata[i] / g_intensity;
        mdata[i] = msdata[i] / m_intensity;
    }

    adata[0] = (gdata[1] * mdata[2] - gdata[2] * mdata[1]);
    adata[1] = (gdata[2] * mdata[0] - gdata[0] * mdata[2]);
    adata[2] = (gdata[0] * mdata[1] - gdata[1] * mdata[0]);
    a_intensity = calc_intensity(adata[0], adata[1], adata[2]);
    if (a_intensity == 0) {
        return YAS_ERROR_ARG;
    }
    for (i = 0; i < 3; i++) {
        adata[i] /= a_intensity;
    }

    bdata[0] = (adata[1] * gdata[2] - adata[2] * gdata[1]);
    bdata[1] = (adata[2] * gdata[0] - adata[0] * gdata[2]);
    bdata[2] = (adata[0] * gdata[1] - adata[1] * gdata[0]);
    b_intensity = calc_intensity(bdata[0], bdata[1], bdata[2]);
    if (b_intensity == 0) {
        return YAS_ERROR_ARG;
    }
    for (i = 0; i < 3; i++) {
        bdata[i] /= b_intensity;
    }

    matrix->matrix[0] = (int32_t)(adata[0] * 4096.0);
    matrix->matrix[1] = (int32_t)(adata[1] * 4096.0);
    matrix->matrix[2] = (int32_t)(adata[2] * 4096.0);
    matrix->matrix[3] = (int32_t)(bdata[0] * 4096.0);
    matrix->matrix[4] = (int32_t)(bdata[1] * 4096.0);
    matrix->matrix[5] = (int32_t)(bdata[2] * 4096.0);
    matrix->matrix[6] = (int32_t)(-gdata[0] * 4096.0);
    matrix->matrix[7] = (int32_t)(-gdata[1] * 4096.0);
    matrix->matrix[8] = (int32_t)(-gdata[2] * 4096.0);

    return YAS_NO_ERROR;
}

static int
get_euler(struct yas_matrix *matrix, struct yas_vector *euler)
{
    float m11, m12;
    float m21, m22;
    float m31, m32, m33;
    float yaw = 0, roll = 0, pitch = 0;

    if (matrix == NULL || euler == NULL) {
        return YAS_ERROR_ARG;
    }

    m11 = (float)(matrix->matrix[0] / 4096.0);
    m12 = (float)(matrix->matrix[1] / 4096.0);
    m21 = (float)(matrix->matrix[3] / 4096.0);
    m22 = (float)(matrix->matrix[4] / 4096.0);
    m31 = (float)(matrix->matrix[6] / 4096.0);
    m32 = (float)(matrix->matrix[7] / 4096.0);
    m33 = (float)(matrix->matrix[8] / 4096.0);

    yaw     = (float)atan2(m12-m21, m11+m22);
    pitch   = (float)-asin(m32);
    roll    = (float)asin(m31);

    yaw     *= (float)(180.0 / M_PI);
    pitch   *= (float)(180.0 / M_PI);
    roll    *= (float)(180.0 / M_PI);

    if (m33 < 0) {
        pitch = -180 - pitch;
        if (pitch < -180) {
            pitch += 360;
        }
    }
    if (yaw < 0) {
        yaw += 360.0f;
    }

    euler->v[0] = (int)yaw;    /* yaw */
    euler->v[1] = (int)pitch;  /* pitch */
    euler->v[2] = (int)roll;   /* roll */

    return YAS_NO_ERROR;
}

int
yas_utility_init(struct yas_utility *f)
{
    if (f == NULL) {
        return YAS_ERROR_ARG;
    }

    f->get_rotation_matrix = get_rotation_matrix;
    f->get_euler = get_euler;

    return YAS_NO_ERROR;
}
#endif
