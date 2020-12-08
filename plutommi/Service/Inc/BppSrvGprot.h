#ifndef BPP_SERVICE_GPROT_H
#define BPP_SERVICE_GPROT_H
#include "MMI_features.h"
#ifdef __MMI_BPP_SUPPORT__

#include "BTCMSrvGprot.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* auto add by kw_check end */
/*****************************************************************
    Constant
*****************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#define MmPerInch           (25.4)
#define DefaultPPI          (100)
/* DOM-NOT_FOR_SDK-END */

/*  Notify events: Once user has invoked set_notify, specific event notify
        might be received whenever the event triggered.
        Parameter definition depends on event class. */
enum BppEvent{
    BPP_EV_JOB_UPDATE =     0x01,   /* Job updated.
                                        High-Word: update item.
                                        Low-Word: ID of updated Job */
    BPP_EV_JOB_NEW    =     0x02,   /* New job saved. 
                                        Low-Word: ID of newly saved job */
    BPP_EV_JOB_DELETE =     0x04,   /* Job deleted.
                                        Low-Word: ID of deleted Job. */
    BPP_EV_JOB_START_REQ =  0x08,   /* Job start request.
                                        High-Word: Conflict status
                                        Low-Word: ID of the job. */
    BPP_EV_JOB_REQUEST =    0x10,   /* Job data request.
                                        High-Word: Request type.
                                        Low-Word: ID of the job. */
    BPP_EV_JOB_STATUS =     0x20,   /* Job status update.
                                        High-word: status reason. 
                                        Low-Word: ID of the job. */
    BPP_EV_JOB_PROGRESS =   0x40,   /* Job ongoing progress information.
                                        Low-Word: ID of related job.
                                        High-Word: Progressing pencentage. */ 
    BPP_EV_JOB_FINISH =     0x80,   /* Job finished. Could be successfully
                                        finish or exception occurs. 
                                        High-Word: Error code.
                                        Low-Word: ID of the job */
    BPP_EV_BEARER_INFO =    0x100,  /* Bluetooth connection status.
                                        High-Word: connection status.
                                        Low-Word: connection ID */
    BPP_EV_UPDATE_FAIL =    0x200,  /* Update request fail.
                                        High-Word: Error code.
                                        Low-Word: ID of the job */
    BPP_EV_END
};

/* BPP Operations */
enum BppOp{
    BPP_OP_UPDATE,  /* Update printer attributes */
    BPP_OP_PRINT,   /* Print */
    BPP_OP_END
};

/* BPP service open mode */
enum BppOpenMode{
    BPP_MODE_RDONLY,  /* Read-Only mode, some operations will be disabled in this mode.
                        multiple instances in this mode could be exist at the same time */
    BPP_MODE_RDWRITE, /* Read-Write mode, all operations are enabled in this mode. 
                        only one instance in this mode could be exist at the same time */
    BPP_MODE_END
};

/* Notify event mask operation */ 
enum BppEvOp{
	BPP_EV_OP_NEW,    /* Reset receiving event */
	BPP_EV_OP_ADD,    /* Add specific event */
	BPP_EV_OP_DEL,    /* Delte specific event */
	BPP_EV_OP_END
};

/* Operation result */
enum BppResult{
    BPP_RESULT_SUCC, /* Operation success */
    BPP_RESULT_FAIL, /* Operation fail */
    BPP_RESULT_PENDING, /* Asynchonized operation, event will triggered when operation done */ 
    BPP_RESULT_END
};

/* Print mode */
enum BppPrintMode{
    BPP_PRINT_MODE_SIMPLE = 1, /* Simple push print mode */
    BPP_PRINT_MODE_ADVANCED, /* Job-based print mode */
    BPP_PRINT_MODE_END
};

/* Print start mode */
enum BppStartMode{
    BPP_START_MODE_CONFLICT = 1, /* Print option conflict with printer settings */
    BPP_START_MODE_NORMAL,       /* Print option can fully supported by printer setting */
    BPP_START_END
};

/* Operation error code definition */
enum BppErrCode{
    BPP_E_NONE, /* No error, success case */
    BPP_E_GENERAL,  /* General fail, no specific reason */
    BPP_E_INVALID_PARA, /* Input invalid parameters */
    BPP_E_INVALID_DATA, /* Providing invlid data when start printing */
    BPP_E_REQ_CANCELLED, /* Operation has been cancelled by remote device */
    BPP_E_USER_ABORT, /* Operation has been aborted by user request */
    BPP_E_SCO_REJECT, /* Operation fail due to SCO link limitation */
    BPP_E_LINK_BROKEN, /* Bluetooth link has been broken */
    BPP_E_OP_BUSY, /* Currently in busy state, no cucurrency opeation could be executed */
    BPP_E_END
};

/* Get info bit mask */
enum BppInfoFilter{
    BPP_INFO_PRINTER_ADDR = 0x01, /* Get printer address */
    BPP_INFO_PRINTER_ATTR = 0x02, /* Get printer attributes */
    BPP_INFO_PRINTER_VALID = 0x04, /* Get whether current printer is valid */
    BPP_INFO_PRINTER =      (BPP_INFO_PRINTER_ADDR | 
                             BPP_INFO_PRINTER_ATTR | 
                             BPP_INFO_PRINTER_VALID), /* Get printer info */
    BPP_INFO_PRINT_OPTION = 0x08, /* Get print options */
    BPP_INFO_JOB_OPTION   = 0x10, /* Get job options */
    BPP_INFO_JOB          = (BPP_INFO_PRINTER |
                             BPP_INFO_PRINT_OPTION |
                             BPP_INFO_JOB_OPTION), /* Get job info */
    BPP_INFO_END
};

/* EV_JOB_REQUEST parameter */
enum BppRequest{
    BPP_REQUEST_DATA,   /* Request print data */
    BPP_REQUEST_AUTH,   /* Request authentication response */
    BPP_REQUEST_END
};

/* EV_BEARER parameter */
enum BppBearer {
    BPP_BEARER_UP,  /* Bearer has been established */
    BPP_BEARER_FAIL, /* Bearer established fail */
    BPP_BEARER_DOWN, /* Bearer has been broken */
    BPP_BEARER_END
}; 

typedef U32 PrinterState;
/* Printer state, reference BPP spec */
enum BppPrinterState {
    BPP_PRINTER_IDLE,   /* Printer in idle state, can accept print request */
    BPP_PRINTER_PROCESSING, /* Printer processing job */
    BPP_PRINTER_STOPPED, /* Printer stop printing */
    BPP_PRINTER_UNKNOWN, /* Printer in unknown state */
    BPP_PRINTER_STATE_END
};

typedef U32 JobStatus;
/* Job status */
enum BppJobStatus {
    BPP_JOB_INVALID,                        /* Invalid job state */
    BPP_JOB_NEW,                            /* New created job */
    BPP_JOB_EDIT,                           /* Job in edit mode */
    BPP_JOB_RDONLY                          /* Job is read only */
};

typedef U32 JobState;
/* Print job state, reference BPP spec */
enum BppJobState {
    BPP_JOB_PRINTING,                       /* Printing */
    BPP_JOB_WAITING,                        /* Waiting for print */
    BPP_JOB_STOPPED,                        /* Stop printing */
    BPP_JOB_COMPLETED,                      /* Printing completed */
    BPP_JOB_ABORTED,                        /* Printing has been aborted */
    BPP_JOB_CANCELLED,                      /* Printing has been cancelled */
    BPP_JOB_UNKNOWN,                        /* Unkown print job state */
    BPP_JOB_STATE_END
};

/* Print status reason, reference BPP spec */
enum BppStatusReason{
    BPP_STATUS_REASON_NONE,                 /* No reason */
    BPP_STATUS_REASON_ATTENTION,            /* Attention required */
    BPP_STATUS_REASON_MEDIA_JAM,            /* Media jam */
    BPP_STATUS_REASON_PAUSED,               /* Pause selected */
    BPP_STATUS_REASON_DOOR_OPEND,           /* Door opened */
    BPP_STATUS_REASON_MEDIA_LOW,            /* Media low */
    BPP_STATUS_REASON_MEDIA_EMPTY,          /* Media empty */
    BPP_STATSU_REASON_OUTPUT_ALMOST_FULL,   /* Output area almost full */
    BPP_STATUS_REASON_OUTPUT_FULL,          /* Output area full */
    BPP_STATUS_REASON_MARKER_LOW,           /* Marker low */
    BPP_STATUS_REASON_MAKER_EMPTY,          /* Marker empty */
    BPP_STATUS_REASON_MARKER_FAIL,          /* Marker fail */
    BPP_STATUS_REASON_END
};

/* Print supported image type */
enum BppImageType {
    BPP_IMAGE_JPEG = 0x01,                  /* JPEG image, this is mandotory */
    BPP_IMAGE_GIF = 0x02,                   /* GIF image */
    BPP_IMAGE_BMP = 0x04,                   /* Bitmap image */
    BPP_IMAGE_WBMP = 0x08,                  /* WBMP image */
    BPP_IMAGE_PNG = 0x10,                   /* PNG image */
    BPP_IMAGE_SVG = 0x20,                   /* SVG image */
    BPP_IMAGE_END
};

/* Print supported document type */
enum BppDocType {
    BPP_DOC_XHTML_095,                      /* XHTML DTD version 0.95 */
    BPP_DOC_XHTML_100,                      /* XHTML DTD version 1.0 */
    BPP_DOC_XHTML_MULTI,                    /* XHTML Multiplexed */
    BPP_DOC_END
};

/* Print sides option */
enum BppSides {
    BPP_SIDED_ONE = 0x01,                   /* One sided */
    BPP_SIDED_TWO_LONG = 0x02,              /* Two sided with long edge */
    BPP_SIDED_TWO_SHORT = 0x04,             /* Two sided with short edge */
    BPP_SIDED_END
};

/* Orientation options */
enum BppOrientation {
    BPP_PORTRAIT = 0x01,                    /* Portrait */
    BPP_LANDSCAPE = 0x02,                   /* Landscape */
    BPP_REVERSE_PORTRAIT = 0x04,            /* Reverse portrait */
    BPP_REVERSE_LANDSCAPE = 0x08,           /* Reverse landscape */
    BPP_ORIENTATION_END
};

/* Print quality options */
enum BppQuality {
    BPP_QUALITY_DRAFT = 0x01,               /* Draft print quality */
    BPP_QUALITY_NORMAL = 0x02,              /* Normal print quality */
    BPP_QUALITY_HIGH = 0x04,                /* High print quality */
    BPP_QUALITY_END
};

/* Number up options */
enum BppNumberup {
    BPP_NUMUP_1 = 0x01,                     /* 1 page per sheet */
    BPP_NUMUP_2 = 0x02,                     /* 2 pages per sheet */
    BPP_NUMUP_4 = 0x04,                     /* 4 pages per sheet */
    BPP_NUMUP_END
};

/* Media type - Stationery */
#define BPP_MEDIA_STATIONERY               0x01
/* Media type - Stationery-Coasted */
#define BPP_MEDIA_STATIONERY_COATED        0x02
/* Media type - Stationery-Inkjet */
#define BPP_MEDIA_STATIONERY_INKJET        0x04
/* Media type - Stationery-Preprinted */
#define BPP_MEDIA_STATIONERY_PREPRINTED    0x08
/* Media type - Stationery-Letterhead */
#define BPP_MEDIA_STATIONERY_LETTERHEAD    0x10
/* Media type - Stationery-Prepunched */
#define BPP_MEDIA_STATIONERY_PREPUNCHED    0x20
/* Media type - Stationery-Fine */
#define BPP_MEDIA_STATIONERY_FINE          0x40
/* Media type - Stationery-Headvy-Weight */
#define BPP_MEDIA_STATIONERY_HEAVYWEIGHT   0x80
/* Media type - Stationery-Light-Weight */
#define BPP_MEDIA_STATIONERY_LIGHTWEIGHT   0x100
/* Media type - Transparency */
#define BPP_MEDIA_TRANSPARENCY             0x200
/* Media type - Envelope */
#define BPP_MEDIA_ENVELOPE                 0x400
/* Media type - Envelope-Plain */
#define BPP_MEDIA_ENVELOPE_PLAIN           0x800
/* Media type - Envelope-Window */
#define BPP_MEDIA_ENVELOPE_WINDOW          0x1000
/* Media type - Continuous */
#define BPP_MEDIA_CONTINUOUS               0x2000
/* Media type - Continuous-Long */
#define BPP_MEDIA_CONTINUOUS_LONG          0x4000
/* Media type - Continuous-Short */
#define BPP_MEDIA_CONTINUOUS_SHORT         0x8000
/* Media type - Tab-Stock */
#define BPP_MEDIA_TAB_STOCK                0x10000
/* Media type - Pre-Cut-Tabs */
#define BPP_MEDIA_PRE_CUT_TABS             0x20000
/* Media type - Full-Cut-Tabs */
#define BPP_MEDIA_FULL_CUT_TABS            0x40000
/* Media type - Multi-Part-Form */
#define BPP_MEDIA_MULTI_PART_FORM          0x80000
/* Media type - Labels */
#define BPP_MEDIA_LABELS                   0x100000
/* Media type - Multi-Layer */
#define BPP_MEDIA_MULTI_LAYER              0x200000
/* Media type - Screen */
#define BPP_MEDIA_SCREEN                   0x400000
/* Media type - Screen-Paged */
#define BPP_MEDIA_SCREEN_PAGED             0x800000
/* Media type - Photographic */
#define BPP_MEDIA_PHOTOGRAPHIC             0x1000000
/* Media type - Photographic-Glossy */
#define BPP_MEDIA_PHOTOGRAPHIC_GLOSSY      0x2000000
/* Media type - Photographic-High-Gloss */
#define BPP_MEDIA_PHOTOGRAPHIC_HIGH_GLOSS  0x4000000
/* Media type - Photographic-Semi-Gloss */
#define BPP_MEDIA_PHOTOGRAPHIC_SEMI_GLOSS  0x8000000
/* Media type - Photographic-Satin */
#define BPP_MEDIA_PHOTOGRAPHIC_SATIN       0x10000000
/* Media type - Photographic-Matte */
#define BPP_MEDIA_PHOTOGRAPHIC_MATTE       0x20000000
/* Media type - Photographic-Film */
#define BPP_MEDIA_PHOTOGRAPHIC_FILM        0x40000000
/* Media type - Photographic-Film */
#define BPP_MEDIA_BACK_PRINT_FILM          0x80000000
/* Media type - Cardstock */
#define BPP_MEDIA_CARDSTOCK                0x100000000
/* Media type - Roll */
#define BPP_MEDIA_ROLL                     0x200000000

/* Media size - A10 */
#define BPP_SIZE_A10           0x01
/* Media size - A9 */
#define BPP_SIZE_A9            0x02
/* Media size - A8 */
#define BPP_SIZE_A8            0x04
/* Media size - A7 */
#define BPP_SIZE_A7            0x08
/* Media size - A6 */
#define BPP_SIZE_A6            0x10
/* Media size - A5 */
#define BPP_SIZE_A5            0x20
/* Media size - A5-extra */
#define BPP_SIZE_A5_EXTRA      0x40
/* Media size - A4 */
#define BPP_SIZE_A4            0x80
/* Media size - A4-tab */
#define BPP_SIZE_A4_TAB        0x100
/* Media size - A4-extra */
#define BPP_SIZE_A4_EXTRA      0x200
/* Media size - A3 */
#define BPP_SIZE_A3            0x400
/* Media size - A2 */
#define BPP_SIZE_A2            0x800
/* Media size - A1 */
#define BPP_SIZE_A1            0x1000
/* Media size - A0 */
#define BPP_SIZE_A0            0x2000
/* Media size - 2A0 */
#define BPP_SIZE_2A0           0x4000
/* Media size - B10 */
#define BPP_SIZE_B10           0x8000
/* Media size - B9 */
#define BPP_SIZE_B9            0x10000
/* Media size - B8 */
#define BPP_SIZE_B8            0x20000
/* Media size - B7 */
#define BPP_SIZE_B7            0x40000
/* Media size - B6 */
#define BPP_SIZE_B6            0x80000
/* Media size - B6-C4 */
#define BPP_SIZE_B6_C4         0x100000
/* Media size - B5 */
#define BPP_SIZE_B5            0x200000
/* Media size - B5-extra */
#define BPP_SIZE_B5_EXTRA      0x400000
/* Media size - B4 */
#define BPP_SIZE_B4            0x800000
/* Media size - B3 */
#define BPP_SIZE_B3            0x1000000
/* Media size - B2 */
#define BPP_SIZE_B2            0x2000000
/* Media size - B1 */
#define BPP_SIZE_B1            0x4000000
/* Media size - B0 */
#define BPP_SIZE_B0            0x8000000
/* Media size - C10 */
#define BPP_SIZE_C10           0x10000000
/* Media size - C9 */
#define BPP_SIZE_C9            0x20000000
/* Media size - C8 */
#define BPP_SIZE_C8            0x40000000
/* Media size - C7 */
#define BPP_SIZE_C7            0x80000000
/* Media size - C7-C6 */
#define BPP_SIZE_C7_C6         0x100000000
/* Media size - C6 */
#define BPP_SIZE_C6            0x200000000
/* Media size - C6-C5 */
#define BPP_SIZE_C6_C5         0x400000000
/* Media size - C5 */
#define BPP_SIZE_C5            0x800000000
/* Media size - C4 */
#define BPP_SIZE_C4            0x1000000000
/* Media size - C3 */
#define BPP_SIZE_C3            0x2000000000
/* Media size - C2 */
#define BPP_SIZE_C2            0x4000000000
/* Media size - C1 */
#define BPP_SIZE_C1            0x8000000000
/* Media size - C0 */
#define BPP_SIZE_C0            0x10000000000
/* Media size - 4x6 */
#define BPP_SIZE_4X6           0x20000000000
/* Media size - Letter */
#define BPP_SIZE_LETTER        0x40000000000

/* Print data type */
enum BppDataType {
    BPP_DATA_BUFF, /* Buffer based data */
    BPP_DATA_FILE, /* File based data */
    BPP_DATA_END
};

/*****************************************************************
    Type define
*****************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
typedef srv_bt_cm_bt_addr PrinterAddr;
typedef U32 BppHandle;
/* DOM-NOT_FOR_SDK-END */


/* <GROUP CallbackFunctions>
 *
 * FUNCTION
 *  BppSrvNotify
 * DESCRIPTION
 *  BPP service event notification.
 * PARAMETERS
 *  srvHd:  [IN]    Instance handle of BPP service.
 *  event:  [IN]    Event type, See also BppEvent.
 *  param:  [IN]    Event parameter. See also BppEvent.
 * RETURNS
 *  S32: reserved for future usage.
 */
typedef S32 (*BppSrvNotify)(BppHandle srvHd, U32 event, U32 param);

/*****************************************************************
    Data structure
*****************************************************************/
/* Printer attributes */
typedef struct {
    U64 mediaSize;      /* Media size supported */
    U64 mediaType;      /* Media type supported */
    U32 textPageWidth;  /* Basic text page width, count by characters */
    U32 textPageHeight; /* Basic text page height, count by rows */
    U8 maxCopies;       /* Max copies supported */
    U8 docFormat;       /* Document type supported */
    U8 imageType;       /* Image type supported */
    U8 numberUp;        /* Page per sheet supported */
    U8 quality;         /* Print quality supported */
    U8 sides;           /* Sides supported */
    U8 orientation;     /* Orientation supported */
} PrinterAttribute;

/* Printer info */
typedef struct {
    U32 valid;          /* Whether printer has been successfully updated */
    PrinterAddr addr;   /* Printer address */
    PrinterAttribute attr;  /* Printer attributes */
} PrinterInfo;

/* Print options */
typedef struct {
    U64 mediaSize;      /* Media type */ 
    U64 mediaType;      /* Media type */
    U8 quality;         /* Print quality */
    U8 sides;           /* Sides */
    U8 orientation;     /* Orientation */
    U8 numberUp;        /* Page per sheet */
    U8 copies;          /* Copies */
} PrintOption;

/* Print options info */
typedef struct {
    U32 use_default;    /* Whether use default print option or not */
    PrintOption option; /* Print options */
} PrintOptionInfo;

/* Job info */
typedef struct {
    U32 jobID;              /* Job ID */
    PrinterInfo printer;    /* Printer info */
    PrintOptionInfo option; /* Print options info */
} JobInfo;

/* Print data */
typedef struct {
    U32 type;           /* Print data type, could be file based or buffer based */
    union {
        U8 *buff;       /* Buffer based data, buffer address */
        WCHAR *file;    /* File based data, file full path */
    } u;
    U32 size;           /* Data size */
    U32 more;           /* Indicate whether there is more data to print */
} PrintData;

/* Service configuration */
typedef struct {
   U32 storage;         /* Storage drive letter */
   U32 maxJobs;         /* Max jobs supported */
   WCHAR *jobFile;      /* Job setting storage path */
} BppSrvConfig;



#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_init
 * DESCRIPTION
 *  Initialize BPP service, should be invoked before any BPP operation.
 * PARAMETERS
 *  config:  [IN]    Service configurations
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bpp_init(BppSrvConfig *config);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_deinit
 * DESCRIPTION
 *  Deinit BPP service, after this been invoked, all BPP related resource will
 *  be released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bpp_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_open
 * DESCRIPTION
 *  Open one instance for BPP service.
 * PARAMETERS
 *  mode:  [IN]    Service open mode, See also BppOpenMode
 * RETURNS
 *  BppHandle: service instance handle. 0 indicate fail.
 *      If one RDWRITE instance has existed, following request of open RDWRITE
 *      instance will failed.
 *****************************************************************************/
BppHandle srv_bpp_open(S32 mode);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_close
 * DESCRIPTION
 *  Close one instance for BPP service.
 * PARAMETERS
 *  srvHd:  [IN]    Previously opened service, returned by srv_bpp_open.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bpp_close(BppHandle srvHd);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_set_notify
 * DESCRIPTION
 *  Config BPP service notification.
 * PARAMETERS
 *  srvHd:  [IN]     Previously opened service, returned by srv_bpp_open.
 *  notify: [IN]     Notification callback function.
 *  mask:   [IN]     Bitmask of register notify events. See also BppEvent
 *  op:     [IN]     See also BppEvOp.
 * RETURNS
 *  S32: operation result. See also BppResult.
 *****************************************************************************/
S32 srv_bpp_set_notify(BppHandle srvHd, BppSrvNotify notify, U32 mask, U8 op);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_change_mode
 * DESCRIPTION
 *  Dynamicly change service instance mode.
 * PARAMETERS
 *  srvHd:  [IN]     Previously opened service, returned by srv_bpp_open.
 *  mode:   [IN]     Service open mode, See also BppOpenMode
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *       If one RDWRITE instance has existed, following request of changing mode
 *       to RDWRITE will failed.
 *****************************************************************************/
S32 srv_bpp_change_mode(BppHandle srvHd, U32 mode);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_list
 * DESCRIPTION
 *  List print jobs. only saved job could be listed out.
 *  This API is avaliable in both Read-only and Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  index:   [IN]    List start offset. start from 0.
 *  buff:    [OUT]   List info buffer. ID of job will be filled into this buffer
 *                   if successful listed out. Pass NULL to get total job count.
 *  count:   [IN]    Count of jobs to be listed out.
 * RETURNS
 *  U32: Count of jobs listed out.
 *****************************************************************************/
U32 srv_bpp_list(BppHandle srvHd, U32 index, U32 *buff, U32 count);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_edit
 * DESCRIPTION
 *  Enter job edit mode. some operation only could be done in edit mode.
 *  This API is only avaliable in Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be enter edit mode. 
 *                   returned by previously List/Create/Save invoking.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_edit(BppHandle srvHd, U32 jobID);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_create
 * DESCRIPTION
 *  Create new job. new created job automaticly enter edit mode.
 *  This API is only avaliable in Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 * RETURNS
 *  U32: New created job ID. This is just temporary ID, formal job ID will be returned
 *       after Save invoked. 
 *****************************************************************************/
U32 srv_bpp_create(BppHandle srvHd);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_save
 * DESCRIPTION
 *  Save job. only take effect on edit mode jobs or new created jobs.
 *  EV_JOB_UPDATE/EV_JOB_NEW may be triggered after this invoked.
 *  This API is only avaliable in Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be saved.
 * RETURNS
 *  U32: Saved job ID. 
 *****************************************************************************/
U32 srv_bpp_save(BppHandle srvHd, U32 jobID);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_cancel
 * DESCRIPTION
 *  Exit edit mode and cancel modification. Only taking effect on edit mode jobs.
 *  If update is ongoing, operation will be aborted.
 *  This API is only avaliable in Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be cancelled.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_cancel(BppHandle srvHd, U32 jobID);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_delete
 * DESCRIPTION
 *  Delete specific job. both saved job or new created job could be deleted.
 *  If update or print is ongoing, operation will be aborted.
 *  EV_JOB_DELETE might be triggered after this invoked.
 *  This API is only avaliable in Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be deleted.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_delete(BppHandle srvHd, U32 jobID);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_bind
 * DESCRIPTION
 *  Bind device address to the specific job. 
 *  If current job already has device binded, new address will be replaced. all 
 *  related device attribute will become un-available.
 *  This API is only avaliable in Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be bind address to.
 *  addr:    [IN]    Device address.
 *  update:  [IN]    Whether automaticlly update device attribute after device binded.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_bind(BppHandle srvHd, U32 jobID, const PrinterAddr *addr, U32 update);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_set_option
 * DESCRIPTION
 *  Set print options to the specific job. if print options ever been set for 
 *  specific job, original options will be replaced. 
 *  This API is only avaliable in Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be set printing options.
 *  option:  [IN]    Print options.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_set_option(BppHandle srvHd, U32 jobID, const PrintOption *option);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_set_data
 * DESCRIPTION
 *  Used to provide printing data.
 *  This API is avaliable in both Read-Only and Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be set print data.
 *  data:    [IN]    Data to be printed. XHTML format is needed.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_set_data(BppHandle srvHd, U32 jobID, const PrintData *data);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_set_password
 * DESCRIPTION
 *  Used to validate password after EV_AUTH_IND is received.
 *  This API is avaliable in both Read-Only and Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be set password to.
 *  passwd:  [IN]    OBEX authentication password.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_set_password(BppHandle srvHd, U32 jobID, const CHAR *passwd);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_update
 * DESCRIPTION
 *  Update device attribute of the specific job. this is an asynchonized operation, 
 *  EV_JOB_UPDATE/EV_REQ_FAIL might be triggered after this invoked.
 *  This API is only avaliable in Read-Write mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be retrieve attributes.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_update(BppHandle srvHd, U32 jobID);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_print
 * DESCRIPTION
 *  Start print via specific job, this is an asynchonized operation.
 *  EV_JOB_START / EV_JOB_PROGRESS / EV_JOB_FINISH might be triggered in this operation.
 *  Save or Cancle must to be invoked first before print start if specific job is 
 *  in edit mode, otherwise print will failed.
 *  This API is avaliable in both Read-Write mode and Read-Only mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be print.
 *  mode:    [IN]    Simple push print of Job based print. See also BppPrintMode.
 *  data:    [IN]    Data to be printed. XHTML format is needed.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_print(BppHandle srvHd, U32 jobID, U32 mode, const PrintData *data);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_accept
 * DESCRIPTION
 *  Accept current operation. Invoked when EV_JOB_REQUEST event received.
 *  This API is avaliable in both Read-Write mode and Read-Only mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be accepted.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_accept(BppHandle srvHd, U32 jobID);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_abort
 * DESCRIPTION
 *  Abort current ongoing operation(Update or Print). 
 *  Invoked when EV_JOB_REQUEST event received or after asynchonized operation started.
 *  If printing has been aborted, EV_JOB_FINISH will be triggered with reason 
 *  USER_ABORT.
 *  This API is avaliable in both Read-Write mode and Read-Only mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job to be aborted.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_abort(BppHandle srvHd, U32 jobID);

/*****************************************************************************
 * FUNCTION
 *  srv_bpp_get_info
 * DESCRIPTION
 *  Get job related information. 
 *  This API is avaliable in both Read-Write mode and Read-Only mode.
 * PARAMETERS
 *  srvHd:   [IN]    Previously opened service, returned by srv_bpp_open.
 *  jobID:   [IN]    ID of job.
 *  info:    [OUT]   Buffer to be filled with specific infomation.
 *  filter:  [IN]    Different kinds of info filter, see also BppInfoFilter.
 * RETURNS
 *  S32: operation result. See also BppResult. 
 *****************************************************************************/
S32 srv_bpp_get_info(BppHandle srvHd, U32 jobID, void *info, U32 filter);

/* DOM-NOT_FOR_SDK-BEGIN */
U32 srv_bpp_job_status(U32 jobID);
U32 srv_bpp_is_busy(void);
S32 srv_bpp_media_size(U64 mediaSize, U32 *width, U32 *height);
/* DOM-NOT_FOR_SDK-END */

#ifdef __cplusplus
}
#endif

#endif /* __MMI_BPP_SUPPORT__ */

#endif /* BTHF_SERVICE_GPROT_H */
