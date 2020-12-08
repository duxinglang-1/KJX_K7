#ifndef _VAPP_UC_GPROT_H
#define _VAPP_UC_GPROT_H

#include "MMI_features.h"
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

#ifdef __cplusplus
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_uc_include.h"


#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)

#define EMOTICON_COUNT 20
#define VAPP_UC_EMOTOCON_BTN_X  0
#define VAPP_UC_EMOTOCON_BTN_y 15

#define VAPP_UC_EMOTOCON_BTN_WIDTH 45 
#define VAPP_UC_EMOTOCON_BTN_HEIGHT 40
#define VAPP_UC_EMOTOCON_BTN_GAP 5

#define UC_EMOTICON_ICON_COUNT 20


class VappUcEmoticon:public VfxBasePopup
{
	 VFX_DECLARE_CLASS(VappUcEmoticon);
private:

	VfxU16				m_emontics_count;
	VfxU8				m_rows;
	VfxU8				m_cols;
	VcpImageButton**			m_buttons;
	VfxU32 m_BaseId;
	VfxBool m_button_pressed;
	VfxScrRotateTypeEnum m_dir ;
	const VcpIconTable  *m_strTable;
	VfxU32 getWidth();
	VfxSize getImageSize(VfxU32 imgId)
	{
		VfxImageSrc Image(imgId);
		return Image.getSize();
	}


	
protected:
	virtual void onInit();
	virtual void onEnter();
    virtual void onUpdate();
	virtual void onRotate(const VfxScreenRotateParam &param);
	void onButtonClick(VfxObject* sender, VfxId id);
	void onBtnStateChangd(VcpImageButton *obj, VcpImageButtonStateEnum state);
	VfxBool onKeyInput(VfxKeyEvent& event);
public:
	VappUcEmoticon();
	
	VappUcEmoticon(VfxU32 BaseId, VfxU16 count, const VcpIconTable *stringTable):m_rows(0),
																				 m_cols(0),
																				 m_BaseId(BaseId), 
																				 m_emontics_count(count), 
																				 m_strTable(stringTable)
	{
		VFX_ALLOC_MEM(m_buttons , (m_emontics_count + 1) * sizeof(VcpImageButton*), this);

	}
	~VappUcEmoticon()
	{
		if (m_buttons)
			VFX_FREE_MEM(m_buttons);
	}

	VfxSignal2 <VfxObject *, VfxU32> m_signalcallback;
	VfxWString getTextByIndex(VfxU32 )const;
	static VcpIconTable *getEmotionTablePointer();
	static VfxU32 getEmotionTableSize();

};
#endif /* __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__ */
extern "C"
{
#endif /* __cplusplus */
//	#include "vappucappgprot.h"
    #include "vapp_package_res.h"
	#include "UcSrvGprot.h"
//	#include "vappucappprot.h"
    #include "Custom_uc_config.h"

typedef void (*vmsgc_func_ptr) (void *);
typedef srv_uc_addr_struct* (*vmsgc_get_addr_func_ptr) (U16 index, void* user_data);
typedef struct
{
    U32 offset;                                 /* Offset in case virtual file */
    U32 size;                                   /* File size for non-text object. UTF8 size for text object */
    U16 *file_path;                             /* NULL terminator is needed. */
    U16 *file_name;                             /* File actual name */
    BOOL is_virtual_file;
    BOOL auto_delete_file;
}vapp_uc_media_info;
typedef void *(*vmsgc_get_media_func_ptr) (U16 index, vapp_uc_media_info *media_info, void* user_data);

typedef enum
{
    EVT_ID_CUI_UC_START = VCUI_MSGCOMPOSER,
    EVT_ID_CUI_UC_SMS_SENT,
    EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE,
    EVT_ID_CUI_UC_EMAILCOMPOSER_CLOSE,
    EVT_ID_CUI_UC_LEMEICOMPOSER_CLOSE,

    EVT_ID_UC_DATA_COLLECTION_CALLBACK_FINISH,
    
    EVT_ID_CUI_UC_MSGCOMPOSER_PRECLOSE,

    EVT_ID_UC_END

} cui_msgcomposer_evt_enum;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER      /* in header: evt_id, size, user_data, sender_id */
}cui_msgcomposer_evt_struct;

typedef enum
{
    UC_LAUNCH_MODE_NONE,
	UC_LAUNCH_MODE_NORMAL,
	UC_LAUNCH_MODE_INSERT,
	UC_LAUNCH_MODE_EMOTICON,
	UC_LAUNCH_MODE_TOTAL
}vappUcLaunchMode;



typedef enum
{
    UC_OPERATION_WRITE_NEW_MSG,        /* Writing new msg operation. */
    UC_OPERATION_EDIT_EXISTED_MSG,      /* Edit existing msg operation. */        
    UC_OPERATION_FORWARD,               /* Forward existing msg operation. Only for inbox and sent box msgs currently.*/
    UC_OPERATION_SEND,                  /* Send existing msg operation. Only for outbox and draft box msgs currently.*/
    UC_OPERATION_REPLY,                 /* Reply existing msg operation. New msg type controlled by UC */
    UC_OPERATION_REPLY_BY_SMS,                 /* Reply existing msg operation. New msg type controlled by caller app. */
    UC_OPERATION_REPLY_BY_MMS,                 /* Reply existing msg operation. New msg type controlled by caller app. */
    UC_OPERATION_REPLY_ALL,             /* Reply all existing msg operation. */
    UC_OPERATION_WRITE_NEW_SMS_TEMPLATE,        /* Writing new msg operation. */
    UC_OPERATION_WRITE_NEW_MMS_TEMPLATE,        /* Writing new msg operation. */
    UC_OPERATION_EDIT_SMS_TEMPLATE,        /* Writing new msg operation. */
    UC_OPERATION_EDIT_MMS_TEMPLATE,        /* Writing new msg operation. */
    UC_OPERATION_SEND_VCARD_AS_SMS,                     /* Uc send VCard as SMS. */
    UC_OPERATION_SEND_VCARD_AS_MMS,                     /* Uc send VCard as MMS. */
    UC_OPERATION_SEND_VCALENDAR_AS_SMS,                     /* Uc send VCalerdar as SMS. */
    UC_OPERATION_SEND_VCALENDAR_AS_MMS,                     /* Uc send VCalerdar as MMS. */
    UC_OPERATION_TOTAL_NUM              /* Max number of msg operations in UC. */
} vappUcMsgOperationEnum;

typedef struct
{
    S32 addr_num;                 /* Max addresses */
    S32 media_num;                /* Number of media forwarded*/
    srv_uc_addr_struct *addr;           /* Addresses linklist */
    srv_uc_msg_type_enum msg_type;      /* srv_uc_msg_type_enum */
    U8 *file_path;               /* File path */
    BOOL auto_delete_file;  /* File need auto delete or not */
    U8 *text_buffer;             /* File path */
    U16 text_num;                /* File path */
    U8 *subject;                 /* File path */
    srv_uc_info_type_enum info_type;    /* srv_uc_info_type_enum */
    void *info;                         /* Info. SMS use msg ID/Index to pass */
    vmsgc_func_ptr callback;               /* Callback function specified by caller of object forward, for calling after use of object */
    void *callback_para;                /* Input paramter to callback function above */
    srv_uc_sim_id sim_id;               /* srv_uc_sim_id */
    vmsgc_get_addr_func_ptr get_address_callback;        /* Callback function specified by caller to call if multiple addresses forwarded */
    vmsgc_get_media_func_ptr get_media_callback;

    U8 app_id;          /* Application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    U8 mode;            /* mma_app_mode_enum */
    U32 msg_id;         /* msg id */
    U8 edit_mode;       /* srv_uc_MMS_edit_mode_enum */
    U8 curr_storage;    /* message stored on? */
	U8 launch_mode;     /* message stored on? */
    srv_uc_state_enum type;
    vappUcMsgOperationEnum operation;
} VappUcEntryStruct;

extern BOOL vappUcAppLauncherPreCheck(VappUcEntryStruct *data, BOOL showErrorMsg);
extern BOOL vappUcAppLauncher(VappUcEntryStruct *data);
extern mmi_id ucGetAppBaseId(VappUcEntryStruct *data, mmi_id group_id); 
extern BOOL vappUcCuiCreatePreCheck(VappUcEntryStruct *data, BOOL showErrorMsg); 
extern mmi_id vcui_unifiedcomposer_create(mmi_id parent_id, VappUcEntryStruct *data);
extern void vcui_unifiedcomposer_run(mmi_id cui_id);
extern void vcui_unifiedcomposer_close(mmi_id cui_id);
extern srv_uc_addr_struct *vapp_uc_get_address_callback(U16 index, void* user_data);
extern void *vapp_uc_get_media_callback(U16 index, vapp_uc_media_info *media_info, void* user_data);   /* Offset in case virtual file */
extern mmi_ret vappUcHandleSmsMsgDelEvent(mmi_event_struct *event_data);
extern mmi_ret vappUcSdCardPlugInHdlr(mmi_event_struct *event_data);
extern mmi_ret vappUcSdCardPlugOutHdlr(mmi_event_struct *event_data);
extern mmi_ret vappUcForceClose(mmi_event_struct *event_data);
extern mmi_ret vappUcSimStatusInfoHdlr(mmi_event_struct *event_data);
#ifdef __MMI_EMAIL__
extern void vappUcTerminateEmailApp(void);
#endif
//#ifdef __MMI_USB_SUPPORT__
extern mmi_ret vappUcUsbMsPlugInHdlr(mmi_event_struct *event_data);
//#endif

#define VAPP_UC_ADM_MEM_SIZE ((WAP_CUSTOM_CFG_MAX_MMS_SLIDES * MMI_UC_CUSTOM_MAX_FILE_PATH_LEN * 2 * 2) + \
                                (WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT * MMI_UC_CUSTOM_MAX_FILE_PATH_LEN * 2) + \
                                (WAP_CUSTOM_CFG_MAX_MMS_ADDRESS * MMI_UC_CUSTOM_MAX_ADDR_LEN * 2) + \
                                (5 * 1024) + SRV_UC_UTF8_TEXT_BUFFER_SIZE)                                
#define VAPP_UC_SERIALIZE_ASM_MEM_SIZE (VAPP_UC_ADM_MEM_SIZE + 10240)

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* #if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */
#endif 
