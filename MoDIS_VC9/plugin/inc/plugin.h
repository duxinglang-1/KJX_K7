#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#ifdef __cplusplus
extern "C" {
#endif

extern const char* PLUG_IN_INFO /*= "pluginame"*/;
extern const char* PLUGIN_NAME_MTE /*= "mte"*/;
extern const char* PLUGIN_EVENT_MTE /*= "mte_event"*/;

#define MAX_PLUG_IN_NAME_LENGTH 32
#define MIN_PLUG_IN_NAME_LENGTH	1
#define MAX_PLUG_IN_CMD_LENGTH	32
#define MIN_PLUG_IN_CMD_LENGTH	1

/*****************************************************************************
 * Enum
 *****************************************************************************/
/* Plug-in type */
typedef enum
{
	PLUG_IN_TYPE_MMI,   /* MMI plug-in */
	PLUG_IN_TYPE_PS,	/* Protocal stack plug-in */
	//Add more here...

	PLUG_IN_TYPE_END
} plugin_type_enum;

/* MMI plug-in message*/
typedef enum
{
	PLUG_IN_MSG_MTE,			/* MTE */	
	//Add more here...

	PLUG_IN_MSG_END
} plugin_msg_enum;

/*****************************************************************************
* Structure
*****************************************************************************/
/* Plug-in information which triggering a interrupt */
typedef struct  
{
	char name[32];
	plugin_type_enum emType;
	plugin_msg_enum emMsgID;
}	plugin_information;

/* data structure for MSG_ID_PLUG_IN_IND */
typedef struct
{
	plugin_information info;
} mmi_plug_in_msg_struct; 

/* data structure for MMI_PLUG_IN_MSG_MTE */
typedef enum _MTE_CMD
{
	MTE_CMD_NONE,
	MTE_CMD_GET_LCD_SIZE,
	MTE_CMD_GET_MAUI_VERSION,
	MTE_CMD_GET_API,
	MTE_CMD_GET_MMI_CLOSE_FLAG,
	MTE_CMD_IS_DISABLED,
}	MTE_CMD;	

typedef struct _mte_data_struct
{
	MTE_CMD cmd;
	int nDataLength;
	char data[1024];
}	mte_data_struct;

/*Add more structures here...*/
//...

#ifdef __cplusplus
}
#endif

#endif