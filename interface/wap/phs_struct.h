#ifndef _PHS_STRUCT_H
#define _PHS_STRUCT_H 

#define WAP_PHS_MAX_ADDR_CHARS    128
#define WAP_PHS_ADDR_PHONE_SEP	  ('/')

typedef enum
{
    WAP_PHS_ADDR_NULL,
    WAP_PHS_ADDR_PHONE,
    WAP_PHS_ADDR_IP,
    WAP_PHS_ADDR_TEXT
} wap_phs_addr_type_enum;

typedef struct 
{
    kal_uint8 type;  /* wap_phs_addr_type_enum */
    kal_uint16 addr[WAP_PHS_MAX_ADDR_CHARS + 1]; /* UCS2 encoding */
} wap_phs_addr_struct;

#endif  /* _PHS_STRUCT_H */
