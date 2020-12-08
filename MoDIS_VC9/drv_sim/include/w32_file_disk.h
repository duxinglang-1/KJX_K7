#ifndef __W32_FILE_DISK_H__
#define __W32_FILE_DISK_H__


typedef enum
{
	NOR_DISK = 0, 

    NAND_DISK,
    NAND_DISK1,
    NAND_DISK2,
    NAND_DISK3,
    NAND_DISK4,
    NAND_DISK5,
    NAND_DISK6,
    NAND_DISK7,

	CARD_DISK,
	CARD_DISK1,
	/* The number of supported OTG devices is not configurable */
	OTG_DISK,
	OTG_DISK1,
	OTG_DISK2,
	OTG_DISK3,
	OTG_DISK4,
	OTG_DISK5,
	OTG_DISK6,
	OTG_DISK7,

	MAX_FILE_DISK
} FILE_DISK_ENUM;

typedef struct FILE_DISK_INFO_STRUCT
{
	kal_char name[32];
	kal_char drive;    /* drive name (single character) */
    kal_uint32 dev;
    kal_uint32 bytespersector;
    kal_uint32 totalsectors; /* assign value for disk total space */
 	FILE *file_handle;
	kal_char dir_name[520];   /* the current directory in the drive (Real Path) */
	kal_bool is_plug_out;
} FILE_DISK_INFO_T;

typedef kal_int32 (*ReadSectors)(void *DriveData, kal_uint32 Sector, kal_uint32 Sectors, void *Buffer);
typedef kal_int32 (*WriteSectors)(void *DriveData, kal_uint32 Sector, kal_uint32 Sectors, void *Buffer);


#endif


