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
 * msm.h
 *
 * Created by Ingmar Persson
 *
 * Revision history:
 *
 */
/* Mobile Suite Manager core functionality. */

#ifndef _msm_h
#define _msm_h

#ifndef _msf_lib_h
#include "msf_lib.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif

/************************************************************
 * Internal signals used in the manager.
 ************************************************************/

#define MSM_MAIN_SIG_START_MODULE       MSM_SIG_DST_MSM_MAIN + 1
#define MSM_MAIN_SIG_TERMINATE_MODULE   MSM_SIG_DST_MSM_MAIN + 2
#define MSM_MAIN_SIG_TERMINATE          MSM_SIG_DST_MSM_MAIN + 3
#define MSM_MAIN_SIG_MODULE_STATUS      MSM_SIG_DST_MSM_MAIN + 4
#ifdef MSF_REGISTRY_SUPPORT
#define MSM_MAIN_SIG_REG_RESPONSE       MSM_SIG_DST_MSM_MAIN + 5
#endif /*MSF_REGISTRY_SUPPPORT*/
#define MSM_MAIN_SIG_CONTENT_SEND       MSM_SIG_DST_MSM_MAIN + 6
#define MSM_MAIN_SIG_AFI_FINISHED       MSM_SIG_DST_MSM_MAIN + 7
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#define MSM_MAIN_SIG_COMPLETE_TERMINATED     MSM_SIG_DST_MSM_MAIN + 8
#else
#ifdef MSF_REGISTRY_SUPPORT
#define MSM_MAIN_SIG_REG_TERMINATED     MSM_SIG_DST_MSM_MAIN + 8
#else /*MSF_REGISTRY_SUPPPORT*/
#define MSM_MAIN_SIG_COMPLETE_TERMINATED     MSM_SIG_DST_MSM_MAIN + 8
#endif /*MSF_REGISTRY_SUPPPORT*/
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
#define MSM_MAIN_SIG_FILE_MOVE               MSM_SIG_DST_MSM_MAIN+9
#define MSM_MAIN_SIG_FILE_MOVE_RESPONSE               MSM_SIG_DST_MSM_MAIN+10
#define MSM_MAIN_MMS_SIG_FILE_MOVE     MSM_SIG_DST_MSM_MAIN+11
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */
#define MSM_MAIN_SIG_REGISTER_CONTENT_ROUTING_DATA			MSM_SIG_DST_MSM_MAIN+12


/************************************************************
 * Memory Macro
 ************************************************************/

#define MSM_ALLOC(s)      MSF_MEM_ALLOC(MSF_MODID_MSM,s)
#define MSM_ALLOCTYPE(t)  MSF_MEM_ALLOCTYPE(MSF_MODID_MSM,t)
#define MSM_FREE(p)       MSF_MEM_FREE(MSF_MODID_MSM,p)


/*********************************************
 * Global variables
 *********************************************/

extern mtk_jmpbuf gmms_msm_jmpbuf;      /* Used by the setjmp/longjmp commands. */
extern int     gmms_msm_inside_run;  /* Used to decide if the manager is inside the Run
                                   function, or not. */


/************************************************************ 
 * Exported functions
 ************************************************************/

/*
 * Start and initialise MSM.
 */
void
gmms_msm_start (const char* options);

/* 
 * Starts the the modules configured as static.
 */
void
gmms_msm_init_done (void);

/*
 * Returns the module id in an integer format,
 * given in a string format. If no match return -1.
 */
int
gmms_msm_modid_str2int (const char* string_modId);

/*
 * Find out the first sub path in src and copy the
 * result to dst.
 */
char*
gmms_msm_get_sub_path (char* src, char* dst);

/*
 * Return the current status of the module. modId must have a
 * valid value, from 0 to MSF_NUMBER_OF_MODULES - 1.
 */
int
gmms_msm_get_module_status (MSF_UINT8 modId);

/*
 * Same as MSMc_objectAction but with the additional parameter
 * cleanup. The cleanup parameter indicates wether the 
 * passed in content is deleted or not in the case of no
 * matching actions for the given mime type.
 */
void
msm_object_action (const char           *mime_type,
                   MsfResourceType       data_type,
                   const unsigned char  *data,
                   MSF_INT32             data_len,
                   const char           *src_path,
                   const char           *file_name,
                   const char*           excl_act_strings[],
                   MSF_INT32             excl_act_strings_cnt,
                   MSF_BOOL              cleanup,
                   MSF_UINT8             ack_dest_modid,
                   MSF_UINT8             ack_id);

/**********************************************************************
 * Package handling
 **********************************************************************/
/*
 * Checks if any of the package AFI handles the signal. 
 * Returns TRUE if handled FALSE otherwise
 */
int
msm_handle_package_signal(MSF_UINT16 signal, void *p);


#define msm_jmpbuf gmms_msm_jmpbuf

#define msm_inside_run gmms_msm_inside_run

#define msm_start gmms_msm_start

#define msm_init_done gmms_msm_init_done

#define msm_modid_str2int gmms_msm_modid_str2int

#define msm_get_sub_path gmms_msm_get_sub_path

#define msm_get_module_status gmms_msm_get_module_status
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
typedef void (*msf_start_call_back_t) (void);
#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/

#endif
