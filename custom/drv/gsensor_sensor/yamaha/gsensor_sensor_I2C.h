#ifndef _I2C_H_
#define _I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ERROR CODE */
#define I2CERR_NO_ERROR             0
#define I2CERR_PORT_OPEN_DRIVER     0x80000001
#define I2CERR_PORT_BAD_PARAMETER   0x80000002
#define I2CERR_PORT_READ            0x80000003
#define I2CERR_PORT_WRITE           0x80000004
#define I2CERR_BAD_PARAMETER        0x80000010
#define I2CERR_BUS_BUSY             0x80000005
#define I2CERR_BAD_STATUS           0x80000006
#define I2CERR_BIT_TRANSFER         0x80000007
#define I2CERR_RECEIVE_NACK         0x80000008

#define DEVTYPE_NON             0
#define DEVTYPE_PRINTER_PORT    1
#define DEVTYPE_32BIT_PC_CARD   2
#define DEVTYPE_16BIT_PC_CARD   3

#define SINT8	signed char
#define SINT16 	signed short
#define SINT32 	signed long
#define UINT8 	unsigned char
#define UINT16	unsigned short
#define UINT32 	unsigned long

#define BYTE unsigned char
#define BOOL unsigned char

	
UINT16  I2COpen();
UINT16  I2CClose();
UINT16  I2CStart();
UINT16  I2CRStart();
UINT16  I2CStop();
UINT16  I2CSetTransferMode( BYTE dwMode );
UINT16  I2CSetSlaveAddress( BYTE bSlave );
BOOL  I2CWriteData( BYTE ucData);
UINT8  I2CReadData( BYTE* pbData, BOOL bAck );
UINT16  I2CGetConnectionType( BYTE* pbType );
UINT8 SDA_Port_read(UINT8 port);


#ifdef __cplusplus
}
#endif

#endif /* _I2C_H_ */

