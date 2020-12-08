#ifndef VAPP_EMAIL_GPROT_H
#define VAPP_EMAIL_GPROT_H

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "vfx_datatype.h"
extern "C"{
#include "EmailSrvGprot.h"
#include "customer_email_num.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* for more Email micro, please refer to customer_email_num.h */
#define MMI_EMAIL_MAX_CONT_LEN                     (MMI_EMAIL_MAX_CONT_LEN_BY_K * 1024)
#define MMI_EMAIL_MAX_SUBJ_LEN                     (50)

#endif /* VAPP_EMAIL_GPROT_H */
