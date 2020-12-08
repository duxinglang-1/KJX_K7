/*
 * Copyright (C) Teleca AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msm_int.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 * 
 *
 */

#ifndef _msm_int_h
#define _msm_int_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

/****************************************
 * Module status
 ****************************************/
#define MSM_MODULE_STATUS_CREATED         MODULE_STATUS_CREATED
#define MSM_MODULE_STATUS_ACTIVE          MODULE_STATUS_ACTIVE
#define MSM_MODULE_STATUS_SHUTTING_DOWN   MODULE_STATUS_SHUTTING_DOWN
#define MSM_MODULE_STATUS_TERMINATED      MODULE_STATUS_TERMINATED


void
gmms_MSMa_createTask (MSF_UINT8 modId);

void
gmms_MSMa_moduleStatus (MSF_UINT8 modId, int status);

void
gmms_MSMa_terminated (void);


/****************************************
 * Timers
 ****************************************/

void
gmms_MSMa_setTimer (MSF_UINT32 timeInterval);

void
gmms_MSMa_resetTimer (void);

int 
gmms_msf_module_isactive (int modId);


/****************************************
 * External
 ****************************************/

void
gmms_MSMa_externalGet (MSF_INT32 id, const char* path, const char* key);

#define MSMa_createTask gmms_MSMa_createTask

#define MSMa_moduleStatus gmms_MSMa_moduleStatus

#define MSMa_terminated gmms_MSMa_terminated

#define MSMa_setTimer gmms_MSMa_setTimer

#define MSMa_resetTimer gmms_MSMa_resetTimer

#define MSF_MODULE_ISACTIVE(modid) gmms_msf_module_isactive(modid)


#define MSMa_externalGet gmms_MSMa_externalGet

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/****************************************
 * Registry
 ****************************************/
void
MSMa_registryResponse (MSF_UINT8 id);
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#endif
