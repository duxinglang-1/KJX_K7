//@ Programmer: Lizx
/******************************************************************************
 ** File Name:    kurtypedef.h                                                    *
 ** Author:       cmzs                                                 *
 ** DATE:         10/25/2007                                                    *
 ** Description:                                                              *
 ******************************************************************************/
/******************************************************************************
 **                   Edit    History                                         *
 **---------------------------------------------------------------------------* 
 ** DATE          NAME            DESCRIPTION                                 * 
 ** 10/25/2007     cmzs     Create.                                     *
 ******************************************************************************/

#ifndef KURDATATYPE_H_
#define KURDATATYPE_H_

#include "MMIDataType.h"

#ifdef   __cplusplus
extern   "C" 
{
#endif
	
#ifndef PUBLIC
#define PUBLIC
#endif

#ifndef LOCAL	
#define	LOCAL	
#endif

#ifndef	CONST	
#define	CONST	
#endif

#ifndef	PNULL		
#define PNULL		0
#endif

#ifndef NULL
#define NULL 0
#endif

#define TRUE   1   /* Boolean true value. */
#define FALSE  0   /* Boolean false value. */

typedef unsigned char		kuro_uint8;
typedef unsigned short		kuro_uint16;
typedef unsigned long int	kuro_uint32;
	
typedef signed char			kuro_int8;	
typedef signed short		kuro_int16;
typedef signed long int		kuro_int32;

typedef char				kuro_char;	
typedef unsigned char		kuro_bool;

typedef kuro_uint16			kuro_wchar;	
	
#define KURO_TRUE			1   /* Boolean true value. */
#define KURO_FALSE			0   /* Boolean false value. */
	
//@ Programmer: Libz  2008.8.7
typedef kuro_int32			KURO_MMIFILE_HANDLE;
//@ Programmer: 

#ifdef   __cplusplus
    }
#endif

#endif 
//@ Programmer:
