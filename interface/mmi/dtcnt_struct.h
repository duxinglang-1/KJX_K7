#ifndef __DTCNT_STRUCT_H__
#define __DTCNT_STRUCT_H__

typedef enum
{
    SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_ADD_PROF = 0x01,   /* Add specified wlan profile by specified SSID */
    SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_CONN_PROF = 0x02,  /* connect specified wlan profile by specified SSID */
    SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_DEL_PROF = 0x08,   /* delete specified wlan profile by specified SSID */    
    SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_TOTAL = 0xFF
} srv_dtcnt_wlan_atcmd_opcode_enum;

/* this structure is designed for wifi chip verification for factory setting */
typedef struct
{
    U8      ref_count;  /* reference count */
    U16     msg_len;    /* message length */ 
    srv_dtcnt_wlan_atcmd_opcode_enum opcode;        
    U16     cmd_length; /* command length*/
    U8      cmd_buf[256]; /* command string */
} srv_dtcnt_wlan_atcmd_req_struct;


#endif