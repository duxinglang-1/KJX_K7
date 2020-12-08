/*****************************************************************************
*
* Filename:
* ---------
* BgSoundSrvGprot.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file contains the BgSound utils apis
*
* Author:
* -------
 * -------
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _BG_SOUND_SRV_GPROT_H_
#define _BG_SOUND_SRV_GPROT_H_

#include "MMI_include.h"

#ifdef __MMI_BG_SOUND_EFFECT__


/*************************************************************************
* Constant values
*************************************************************************/


/*************************************************************************
* Enum values
*************************************************************************/


/*************************************************************************
* Structures
*************************************************************************/


/*************************************************************************
* External APIs
*************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_bgsnd_common_get_mo_bgs_permit_state
 * DESCRIPTION
 *  To get the status of Background sound in call.
 *
 * PARAMETERS
 *  void    
 * RETURNS
 *  Return MMI_TRUE or MMI_FALSE.
 * RETURN VALUES
 *  MMI_TRUE :      ready 
 *  MMI_FALSE:      not ready
 *****************************************************************************/
extern MMI_BOOL srv_bgsnd_common_get_mo_bgs_permit_state(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bgsnd_common_set_mo_bgs_permit_state
 * DESCRIPTION
 *  To set the status of Background sound in call.
 *
 * PARAMETERS
 *  U8 status
 * RETURNS
 *  Return MMI_TRUE or MMI_FALSE.
 * RETURN VALUES
 *  void
 *  
 *****************************************************************************/
extern void srv_bgsnd_common_set_mo_bgs_permit_state(U8 status);

/* DOM-NOT_FOR_SDK-END */

#endif /*__MMI_BG_SOUND_EFFECT__*/
#endif /* _BG_SOUND_SRV_GPROT_H_ */

