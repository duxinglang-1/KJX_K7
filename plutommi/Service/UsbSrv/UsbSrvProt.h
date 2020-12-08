#include "MMI_features.h"


#include "MMIDataType.h"
#include "USBSrvIprot.h"
#include "USBSrvGprot.h"

/* The delay time period when usb config screen is allowed to display */
#define PENDING_USBDETECTION_HDLR_TIMER_DUR  3000       /* 3 sec */

/* The display time of shutdown for mass storage notification screen */
#define USB_SHUTDOWN_SCR_TIMER_DUR  2000        /* 2 sec */


typedef struct
{
    /*
     * Bit 0: Before Power on Flag
     * Bit 1: Pending Timer Flag
     * Bit 2: Usb plug out during switch port
     */
    U32 flag;

    /* MMI usb state (previous, only use when interrupt at config page) */
    srv_usb_status_enum usb_status_prev;

    /* MMI usb state (current) */
    srv_usb_status_enum usb_status;

    /* Previous PS and TST  port setting, for restore when plug out usb device */
    //U8 ps_port_prev;
    //U8 tst_port_prev;

    U8 reset_type;
    U8 ms_config_result;
    U8 owner;
    U8 ps_port;
} SRV_USB_CONTEXT;


/***************************************************************************** 
* MMI USB context reference
*****************************************************************************/
extern SRV_USB_CONTEXT *srv_usb_ptr;

#define SRV_USB_CTX(a) srv_usb_ptr->a

/***************************************************************************** 
* SRV USB context defination and operation
*****************************************************************************/
/* srv usb context bit-wise flag defination */
#define SRVUSB_MASK_BEFORE_POWERON  0x00000001
#define SRVUSB_MASK_PENDING_TIMER   0x00000002
#define SRVUSB_MASK_PORT_SWITCHING  0x00000004
#define SRVUSB_MASK_IS_CONNECT      0x00000008
#define SRVUSB_MASK_RESERVED_1      0x00000010
#define SRVUSB_MASK_RESERVED_2      0x00000020
#define SRVUSB_MASK_RESERVED_3      0x00000040
#define SRVUSB_MASK_RESERVED_4      0x00000080

/* SRV usb context bit-wise flag operation */
#define SRVUSB_GET_FLAG(a)       ( ((srv_usb_ptr->flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define SRVUSB_SET_FLAG(a)       ( (srv_usb_ptr->flag) |=  a )
#define SRVUSB_RESET_FLAG(a)   ( (srv_usb_ptr->flag) &=  ~a )


