#ifndef	_VM_TLV_
#define	_VM_TLV_

#include "vmsys.h"

#define		TYPE_LEN		sizeof(VMINT)
#define		LEN_LEN			sizeof(VMINT)

VMCHAR * vm_tlv_read( VMCHAR * buf, VMINT * p_type, VMINT * p_len, VMCHAR ** p_value );
VMINT SearchTagByID( VMINT tag, VMCHAR * tags_buf, VMCHAR ** tag_buf );
#endif
