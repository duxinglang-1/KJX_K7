#include "vmswitch.h"
#include "string.h"

#include "vmsys.h"
#include "vmtlv.h"

#ifdef __MRE_CORE_BASE__

VMCHAR * vm_tlv_read( VMCHAR * buf, VMINT * p_type, VMINT * p_len, VMCHAR ** p_value )
{
	if( buf == NULL || p_type == NULL || p_len == NULL || p_value == NULL )
		return NULL;

	memcpy( (VMCHAR *)p_type, buf, TYPE_LEN );

	memcpy( (VMCHAR *)p_len, buf+TYPE_LEN, LEN_LEN );

	*(p_value) = buf+TYPE_LEN+LEN_LEN;

	return *(p_value) + *(p_len);
}

VMINT SearchTagByID( VMINT tag, VMCHAR * tags_buf, VMCHAR ** tag_buf )
{
	VMINT		tlv_type = 0, tlv_len = 0;
	VMCHAR *	tlv_value = NULL;

	VMCHAR *	tags = NULL, * next_tag = tags_buf;

	if( tag == 0 || tags_buf == NULL || tag_buf == NULL )
		return 0;

	do{
		tags = next_tag;

		next_tag = vm_tlv_read( tags, &tlv_type, &tlv_len, &tlv_value );
	}while( tlv_type != tag && tlv_type != 0 );

	if( tlv_len == 0 )
		return 0;
	else
		*tag_buf = tlv_value;

	return tlv_len;
}

#endif
