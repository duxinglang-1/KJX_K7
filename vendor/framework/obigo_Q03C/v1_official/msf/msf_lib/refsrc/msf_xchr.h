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
 * msf_xchr.h
 * 
 * Additional Character Set Support
 *
 */
#ifndef _msf_xchr_h
#define _msf_xchr_h

#ifndef _msf_def_h 
#include "msf_def.h"
#endif

#ifndef _msf_chrs_h 
#include "msf_chrs.h"
#endif
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "Conversions.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/*
 * Define this constant to be the number of additional character sets
 * that are supported, or 0 if none are supported.
 */
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#define MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS   2
#else
#define MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS   33
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

typedef struct {
  int                    character_set;
  const char            *preferred_name;
  const char            *aliases;
  msf_charset_convert_t *cvt_to_utf8;  
  msf_charset_convert_t *cvt_from_utf8;  
} msf_xchr_entry_t;

#if MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS > 0
extern const msf_xchr_entry_t gmms_msf_xchr_table[MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS];
#endif

#define msf_xchr_table gmms_msf_xchr_table

#endif
