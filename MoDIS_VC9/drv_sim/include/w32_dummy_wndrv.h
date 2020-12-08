#ifndef W32_DUMMY_WNDRV_H
#define W32_DUMMY_WNDRV_H

typedef kal_uint64 u64;
typedef kal_uint32 u32;
typedef kal_uint16 u16;
typedef kal_uint8 u8;
//typedef int64_t s64;
typedef kal_int32 s32;
typedef kal_int16 s16;
typedef kal_int8 s8;
typedef kal_uint16 wpa_size_t;
typedef kal_uint32 size_t;

#define BIT(x) (1 << (x))

/*eap dummy structure*/

/*eapol dummy structure*/
typedef enum { FALSE = 0, TRUE = 1 } Boolean;
typedef enum { Unauthorized, Authorized } PortStatus;
typedef enum { Auto, ForceUnauthorized, ForceAuthorized } PortControl;

struct eapol_config {
	int accept_802_1x_keys;
#define EAPOL_REQUIRE_KEY_UNICAST BIT(0)
#define EAPOL_REQUIRE_KEY_BROADCAST BIT(1)
	int required_keys; /* which EAPOL-Key packets are required before
			    * marking connection authenticated */
	int fast_reauth; /* whether fast EAP reauthentication is enabled */
	int workaround; /* whether EAP workarounds are enabled */
};

/* IEEE 802.1aa/D6.1 - Supplicant */

struct eapol_sm {
	/* Timers */
      eventid   event_id;
	unsigned int authWhile;
	unsigned int heldWhile;
	unsigned int startWhen;
	unsigned int idleWhile; /* for EAP state machine */

	/* Global variables */
	Boolean eapFail;
	Boolean eapolEap;
	Boolean eapSuccess;
	Boolean initialize;
	Boolean keyDone;
	Boolean keyRun;
	PortControl portControl;
	Boolean portEnabled;
	PortStatus suppPortStatus;  /* dot1xSuppControlledPortStatus */
	Boolean portValid;
	Boolean suppAbort;
	Boolean suppFail;
	Boolean suppStart;
	Boolean suppSuccess;
	Boolean suppTimeout;

	/* Supplicant PAE state machine */
	enum {
		SUPP_PAE_UNKNOWN = 0,
		SUPP_PAE_DISCONNECTED = 1,
		SUPP_PAE_LOGOFF = 2,
		SUPP_PAE_CONNECTING = 3,
		SUPP_PAE_AUTHENTICATING = 4,
		SUPP_PAE_AUTHENTICATED = 5,
		/* unused(6) */
		SUPP_PAE_HELD = 7,
		SUPP_PAE_RESTART = 8,
		SUPP_PAE_S_FORCE_AUTH = 9,
		SUPP_PAE_S_FORCE_UNAUTH = 10
	} SUPP_PAE_state; /* dot1xSuppPaeState */
	/* Variables */
	Boolean userLogoff;
	Boolean logoffSent;
	unsigned int startCount;
	Boolean eapRestart;
	PortControl sPortMode;
	/* Constants */
	unsigned int heldPeriod; /* dot1xSuppHeldPeriod */
	unsigned int startPeriod; /* dot1xSuppStartPeriod */
	unsigned int maxStart; /* dot1xSuppMaxStart */

	/* Key Receive state machine */
	enum {
		KEY_RX_UNKNOWN = 0,
		KEY_RX_NO_KEY_RECEIVE, KEY_RX_KEY_RECEIVE
	} KEY_RX_state;
	/* Variables */
	Boolean rxKey;

	/* Supplicant Backend state machine */
	enum {
		SUPP_BE_UNKNOWN = 0,
		SUPP_BE_INITIALIZE = 1,
		SUPP_BE_IDLE = 2,
		SUPP_BE_REQUEST = 3,
		SUPP_BE_RECEIVE = 4,
		SUPP_BE_RESPONSE = 5,
		SUPP_BE_FAIL = 6,
		SUPP_BE_TIMEOUT = 7, 
		SUPP_BE_SUCCESS = 8
	} SUPP_BE_state; /* dot1xSuppBackendPaeState */
	/* Variables */
	Boolean eapNoResp;
	Boolean eapReq;
	Boolean eapResp;
	/* Constants */
	unsigned int authPeriod; /* dot1xSuppAuthPeriod */

#ifdef WIFI_PORT_TIMER
	/* Port Timer state machine */
	enum {
		PORT_TIMER_UNKNOWN = 0,
		PORT_TIMER_ONE_SECOND = 1,
		PORT_TIMER_TICK = 2
	} PORT_TIMER_state; /* dot1xSuppPortTimerState */
	/* Variables */
	Boolean tick;
#endif

	/* Statistics */
	unsigned int dot1xSuppEapolFramesRx;
	unsigned int dot1xSuppEapolFramesTx;
	unsigned int dot1xSuppEapolStartFramesTx;
	unsigned int dot1xSuppEapolLogoffFramesTx;
	unsigned int dot1xSuppEapolRespFramesTx;
	unsigned int dot1xSuppEapolReqIdFramesRx;
	unsigned int dot1xSuppEapolReqFramesRx;
	unsigned int dot1xSuppInvalidEapolFramesRx;
	unsigned int dot1xSuppEapLengthErrorFramesRx;
	unsigned int dot1xSuppLastEapolFrameVersion;
	unsigned char dot1xSuppLastEapolFrameSource[6];

	/* Miscellaneous variables (not defined in IEEE 802.1aa/D6.1) */
	Boolean changed;
	void* eap_dummy;
	void* wpa_ssid_config_dummy;
	Boolean initial_req;
	u8 *last_rx_key;
	wpa_size_t last_rx_key_len;
	u8 *eapReqData; /* for EAP */
	wpa_size_t eapReqDataLen; /* for EAP */
	Boolean altAccept; /* for EAP */
	Boolean altReject; /* for EAP */
	Boolean replay_counter_valid;
	u8 last_replay_counter[16];
	struct eapol_config conf;
	struct eapol_ctx *ctx;
	enum { EAPOL_CB_IN_PROGRESS = 0, EAPOL_CB_SUCCESS, EAPOL_CB_FAILURE }
		cb_status;
	Boolean cached_pmk;
#ifdef WIFI_PORT_TIMER
	Boolean txStart_enable; // Kinki change for the port timer
#endif

	Boolean unicast_key_received, broadcast_key_received;
};

struct eapol_ctx {
	void *ctx; /* pointer to arbitrary upper level context */
	int preauth; /* This EAPOL state machine is used for IEEE 802.11i/RSN
		      * pre-authentication */
	void (*cb)(struct eapol_sm *eapol, int success, void *ctx);
	void *cb_ctx, *msg_ctx, *scard_ctx;
	void (*eapol_done_cb)(void *ctx);
	int (*eapol_send)(void *ctx, int type, u8 *buf, wpa_size_t len);
	int (*set_wep_key)(void *ctx, int unicast, int keyidx,
			   u8 *key, wpa_size_t keylen
			   );
	/**
	 * wps - WPS context data
	 *
	 * This is only used by EAP-WSC and can be left %NULL if not available.
	 */
	struct wps_context *wps;
};
/*WPS DEFS*/
#define WPS_VERSION_V1 0x10
#define WPS_VERSION_V2 0x20

/* Diffie-Hellman 1536-bit MODP Group; RFC 3526, Group 5 */
#define WPS_DH_GROUP 5

#define WPS_UUID_LEN 16
#define WPS_NONCE_LEN 16
#define WPS_AUTHENTICATOR_LEN 8
#define WPS_AUTHKEY_LEN 32
#define WPS_KEYWRAPKEY_LEN 16
#define WPS_EMSK_LEN 32
#define WPS_PSK_LEN 16
#define WPS_SECRET_NONCE_LEN 16
#define WPS_HASH_LEN 32
#define WPS_KWA_LEN 8
#define WPS_MGMTAUTHKEY_LEN 32
#define WPS_MGMTENCKEY_LEN 16
#define WPS_MGMT_KEY_ID_LEN 16

/* Attribute Types */
 enum wps_attribute {
	ATTR_AP_CHANNEL = 0x1001,
	ATTR_ASSOC_STATE = 0x1002,
	ATTR_AUTH_TYPE = 0x1003,
	ATTR_AUTH_TYPE_FLAGS = 0x1004,
	ATTR_AUTHENTICATOR = 0x1005,
	ATTR_CONFIG_METHODS = 0x1008,
	ATTR_CONFIG_ERROR = 0x1009,
	ATTR_CONFIRM_URL4 = 0x100a,
	ATTR_CONFIRM_URL6 = 0x100b,
	ATTR_CONN_TYPE = 0x100c,
	ATTR_CONN_TYPE_FLAGS = 0x100d,
	ATTR_CRED = 0x100e,
	ATTR_ENCR_TYPE = 0x100f,
	ATTR_ENCR_TYPE_FLAGS = 0x1010,
	ATTR_DEV_NAME = 0x1011,
	ATTR_DEV_PASSWORD_ID = 0x1012,
	ATTR_E_HASH1 = 0x1014,
	ATTR_E_HASH2 = 0x1015,
	ATTR_E_SNONCE1 = 0x1016,
	ATTR_E_SNONCE2 = 0x1017,
	ATTR_ENCR_SETTINGS = 0x1018,
	ATTR_ENROLLEE_NONCE = 0x101a,
	ATTR_FEATURE_ID = 0x101b,
	ATTR_IDENTITY = 0x101c,
	ATTR_IDENTITY_PROOF = 0x101d,
	ATTR_KEY_WRAP_AUTH = 0x101e,
	ATTR_KEY_ID = 0x101f,
	ATTR_MAC_ADDR = 0x1020,
	ATTR_MANUFACTURER = 0x1021,
	ATTR_MSG_TYPE = 0x1022,
	ATTR_MODEL_NAME = 0x1023,
	ATTR_MODEL_NUMBER = 0x1024,
	ATTR_NETWORK_INDEX = 0x1026,
	ATTR_NETWORK_KEY = 0x1027,
	ATTR_NETWORK_KEY_INDEX = 0x1028,
	ATTR_NEW_DEVICE_NAME = 0x1029,
	ATTR_NEW_PASSWORD = 0x102a,
	ATTR_OOB_DEVICE_PASSWORD = 0x102c,
	ATTR_OS_VERSION = 0x102d,
	ATTR_POWER_LEVEL = 0x102f,
	ATTR_PSK_CURRENT = 0x1030,
	ATTR_PSK_MAX = 0x1031,
	ATTR_PUBLIC_KEY = 0x1032,
	ATTR_RADIO_ENABLE = 0x1033,
	ATTR_REBOOT = 0x1034,
	ATTR_REGISTRAR_CURRENT = 0x1035,
	ATTR_REGISTRAR_ESTABLISHED = 0x1036,
	ATTR_REGISTRAR_LIST = 0x1037,
	ATTR_REGISTRAR_MAX = 0x1038,
	ATTR_REGISTRAR_NONCE = 0x1039,
	ATTR_REQUEST_TYPE = 0x103a,
	ATTR_RESPONSE_TYPE = 0x103b,
	ATTR_RF_BANDS = 0x103c,
	ATTR_R_HASH1 = 0x103d,
	ATTR_R_HASH2 = 0x103e,
	ATTR_R_SNONCE1 = 0x103f,
	ATTR_R_SNONCE2 = 0x1040,
	ATTR_SELECTED_REGISTRAR = 0x1041,
	ATTR_SERIAL_NUMBER = 0x1042,
	ATTR_WPS_STATE = 0x1044,
	ATTR_SSID = 0x1045,
	ATTR_TOTAL_NETWORKS = 0x1046,
	ATTR_UUID_E = 0x1047,
	ATTR_UUID_R = 0x1048,
	ATTR_VENDOR_EXT = 0x1049,
	ATTR_VERSION = 0x104a,
	ATTR_X509_CERT_REQ = 0x104b,
	ATTR_X509_CERT = 0x104c,
	ATTR_EAP_IDENTITY = 0x104d,
	ATTR_MSG_COUNTER = 0x104e,
	ATTR_PUBKEY_HASH = 0x104f,
	ATTR_REKEY_KEY = 0x1050,
	ATTR_KEY_LIFETIME = 0x1051,
	ATTR_PERMITTED_CFG_METHODS = 0x1052,
	ATTR_SELECTED_REGISTRAR_CONFIG_METHODS = 0x1053,
	ATTR_PRIMARY_DEV_TYPE = 0x1054,
	ATTR_SECONDARY_DEV_TYP_ELIST = 0x1055,
	ATTR_PORTABLE_DEV = 0x1056,
	ATTR_AP_SETUP_LOCKED = 0x1057,
	ATTR_APPLICATION_EXT = 0x1058,
	ATTR_EAP_TYPE = 0x1059,
	ATTR_IV = 0x1060,
	ATTR_KEY_PROVIDED_AUTO = 0x1061,
	ATTR_802_1X_ENABLED = 0x1062,
	ATTR_APPSESSIONKEY = 0x1063,
	ATTR_WEPTRANSMITKEY = 0x1064
} ;

/* Device Password ID */
 enum wps_dev_password_id {
	DEV_PW_DEFAULT = 0x0000,
	DEV_PW_USER_SPECIFIED = 0x0001,
	DEV_PW_MACHINE_SPECIFIED = 0x0002,
	DEV_PW_REKEY = 0x0003,
	DEV_PW_PUSHBUTTON = 0x0004,
	DEV_PW_REGISTRAR_SPECIFIED = 0x0005
} ;

/* Message Type */
enum wps_msg_type {
	WPS_Beacon = 0x01,
	WPS_ProbeRequest = 0x02,
	WPS_ProbeResponse = 0x03,
	WPS_M1 = 0x04,
	WPS_M2 = 0x05,
	WPS_M2D = 0x06,
	WPS_M3 = 0x07,
	WPS_M4 = 0x08,
	WPS_M5 = 0x09,
	WPS_M6 = 0x0a,
	WPS_M7 = 0x0b,
	WPS_M8 = 0x0c,
	WPS_WSC_ACK = 0x0d,
	WPS_WSC_NACK = 0x0e,
	WPS_WSC_DONE = 0x0f
};

/* Authentication Type Flags */
#define WPS_AUTH_OPEN 0x0001
#define WPS_AUTH_WPAPSK 0x0002
#define WPS_AUTH_SHARED 0x0004
#define WPS_AUTH_WPA 0x0008
#define WPS_AUTH_WPA2 0x0010
#define WPS_AUTH_WPA2PSK 0x0020
#define WPS_AUTH_TYPES (WPS_AUTH_OPEN | WPS_AUTH_WPAPSK | WPS_AUTH_SHARED | \
			WPS_AUTH_WPA | WPS_AUTH_WPA2 | WPS_AUTH_WPA2PSK)

/* Encryption Type Flags */
#define WPS_ENCR_NONE 0x0001
#define WPS_ENCR_WEP 0x0002
#define WPS_ENCR_TKIP 0x0004
#define WPS_ENCR_AES 0x0008
#define WPS_ENCR_TYPES (WPS_ENCR_NONE | WPS_ENCR_WEP | WPS_ENCR_TKIP | \
			WPS_ENCR_AES)

/* Configuration Error */
 enum wps_config_error {
	WPS_CFG_NO_ERROR = 0,
	WPS_CFG_OOB_IFACE_READ_ERROR = 1,
	WPS_CFG_DECRYPTION_CRC_FAILURE = 2,
	WPS_CFG_24_CHAN_NOT_SUPPORTED = 3,
	WPS_CFG_50_CHAN_NOT_SUPPORTED = 4,
	WPS_CFG_SIGNAL_TOO_WEAK = 5,
	WPS_CFG_NETWORK_AUTH_FAILURE = 6,
	WPS_CFG_NETWORK_ASSOC_FAILURE = 7,
	WPS_CFG_NO_DHCP_RESPONSE = 8,
	WPS_CFG_FAILED_DHCP_CONFIG = 9,
	WPS_CFG_IP_ADDR_CONFLICT = 10,
	WPS_CFG_NO_CONN_TO_REGISTRAR = 11,
	WPS_CFG_MULTIPLE_PBC_DETECTED = 12,
	WPS_CFG_ROGUE_SUSPECTED = 13,
	WPS_CFG_DEVICE_BUSY = 14,
	WPS_CFG_SETUP_LOCKED = 15,
	WPS_CFG_MSG_TIMEOUT = 16,
	WPS_CFG_REG_SESS_TIMEOUT = 17,
	WPS_CFG_DEV_PASSWORD_AUTH_FAILURE = 18
} ;

/* RF Bands */
#define WPS_RF_24GHZ 0x01
#define WPS_RF_50GHZ 0x02

/* Config Methods */
#define WPS_CONFIG_USBA 0x0001
#define WPS_CONFIG_ETHERNET 0x0002
#define WPS_CONFIG_LABEL 0x0004
#define WPS_CONFIG_DISPLAY 0x0008
#define WPS_CONFIG_EXT_NFC_TOKEN 0x0010
#define WPS_CONFIG_INT_NFC_TOKEN 0x0020
#define WPS_CONFIG_NFC_INTERFACE 0x0040
#define WPS_CONFIG_PUSHBUTTON 0x0080
#define WPS_CONFIG_KEYPAD 0x0100
/*add for wps 2.0*/
#define WPS_CONFIG_V_PUSHBUTTON  0x0280
#define WPS_CONFIG_PHY_PUSHBUTTON  0x0480
#define WPS_CONFIG_V_DISP_PIN  0x2008
#define WPS_CONFIG_PHY_DISP_PIN  0x4008

/* Connection Type Flags */
#define WPS_CONN_ESS 0x01
#define WPS_CONN_IBSS 0x02

/* Wi-Fi Protected Setup State */
 enum wps_state {
	WPS_STATE_NOT_CONFIGURED = 1,
	WPS_STATE_CONFIGURED = 2
} ;

/* Association State */
 enum wps_assoc_state {
	WPS_ASSOC_NOT_ASSOC = 0,
	WPS_ASSOC_CONN_SUCCESS = 1,
	WPS_ASSOC_CFG_FAILURE = 2,
	WPS_ASSOC_FAILURE = 3,
	WPS_ASSOC_IP_FAILURE = 4
} ;


/* Primary Device Type */
typedef struct wps_dev_type {
	u8 categ_id[2];
	u8 oui[4];
	u8 sub_categ_id[2];
} wps_dev_type;

#define WPS_DEV_OUI_WFA 0x0050f204
#define WPS_DEV_OUI_MTK 0x000ce700

 enum wps_dev_categ {
	WPS_DEV_COMPUTER = 1,
	WPS_DEV_INPUT = 2,
	WPS_DEV_PRINTER = 3,
	WPS_DEV_CAMERA = 4,
	WPS_DEV_STORAGE = 5,
	WPS_DEV_NETWORK_INFRA = 6,
	WPS_DEV_DISPLAY = 7,
	WPS_DEV_MULTIMEDIA = 8,
	WPS_DEV_GAMING = 9,
	WPS_DEV_PHONE = 10
} ;

 enum wps_dev_subcateg {
	WPS_DEV_COMPUTER_PC = 1,
	WPS_DEV_COMPUTER_SERVER = 2,
	WPS_DEV_COMPUTER_MEDIA_CENTER = 3,
	WPS_DEV_PRINTER_PRINTER = 1,
	WPS_DEV_PRINTER_SCANNER = 2,
	WPS_DEV_CAMERA_DIGITAL_STILL_CAMERA = 1,
	WPS_DEV_STORAGE_NAS = 1,
	WPS_DEV_NETWORK_INFRA_AP = 1,
	WPS_DEV_NETWORK_INFRA_ROUTER = 2,
	WPS_DEV_NETWORK_INFRA_SWITCH = 3,
	WPS_DEV_DISPLAY_TV = 1,
	WPS_DEV_DISPLAY_PICTURE_FRAME = 2,
	WPS_DEV_DISPLAY_PROJECTOR = 3,
	WPS_DEV_MULTIMEDIA_DAR = 1,
	WPS_DEV_MULTIMEDIA_PVR = 2,
	WPS_DEV_MULTIMEDIA_MCX = 3,
	WPS_DEV_GAMING_XBOX = 1,
	WPS_DEV_GAMING_XBOX360 = 2,
	WPS_DEV_GAMING_PLAYSTATION = 3,
	WPS_DEV_PHONE_WINDOWS_MOBILE = 1,
	/*add for wps 2.0*/
	WPS_DEV_PHONE_FEATURE_SINGLE = 2,
	WPS_DEV_PHONE_FEATURE_DUAL = 3,
	WPS_DEV_PHONE_SMART_SINGLE = 4,
	WPS_DEV_PHONE_SMART_DUAL = 5
	
} ;


/* Request Type */
 enum wps_request_type {
	WPS_REQ_ENROLLEE_INFO = 0,
	WPS_REQ_ENROLLEE = 1,
	WPS_REQ_REGISTRAR = 2,
	WPS_REQ_WLAN_MANAGER_REGISTRAR = 3
} ;

/* Response Type */
 enum wps_response_type {
	WPS_RESP_ENROLLEE_INFO = 0,
	WPS_RESP_ENROLLEE = 1,
	WPS_RESP_REGISTRAR = 2,
	WPS_RESP_AP = 3
} ;

/* Walk Time for push button configuration (in seconds) */
#define WPS_PBC_WALK_TIME 120
#define WPS_SCAN_INTERVAL  8

/*device name*/
#define WPS_DEVICE_NAME "mediatek_wps_phone"
#define WPS_MANUFACTURER "mediatek"
#define WPS_MODEL_NAME "mt5921"
#define WPS_MODEL_NUM "5921"
#define WPS_SERIAL_NUM "2.0"

#define WPS_PROBE_IE_LEN 200
#define WPS_ASSOC_IE_LEN 200

#define WPS_TYPE_PBC  1
#define WPS_TYPE_PIN  2

#define WPA_IE_VENDOR_TYPE 0x0050f201
#define WPS_IE_VENDOR_TYPE 0x0050f204

/** WPS overlap detected in PBC mode */
#define WPS_EVENT_OVERLAP "WPS-OVERLAP-DETECTED "
/** Available WPS AP with active PBC found in scan results */
#define WPS_EVENT_AP_AVAILABLE_PBC "WPS-AP-AVAILABLE-PBC "
/** Available WPS AP with recently selected PIN registrar found in scan results
 */
#define WPS_EVENT_AP_AVAILABLE_PIN "WPS-AP-AVAILABLE-PIN "
/** Available WPS AP found in scan results */
#define WPS_EVENT_AP_AVAILABLE "WPS-AP-AVAILABLE "
/** A new credential received */
#define WPS_EVENT_CRED_RECEIVED "WPS-CRED-RECEIVED "
/** M2D received */
#define WPS_EVENT_M2D "WPS-M2D "
/** WPS registration failed after M2/M2D */
#define WPS_EVENT_FAIL "WPS-FAIL "
/** WPS registration completed successfully */
#define WPS_EVENT_SUCCESS "WPS-SUCCESS "
/** WPS enrollment attempt timed out and was terminated */
#define WPS_EVENT_TIMEOUT "WPS-TIMEOUT "

/* hostapd control interface - fixed message prefixes */
#define WPS_EVENT_PIN_NEEDED "WPS-PIN-NEEDED "
#define WPS_EVENT_NEW_AP_SETTINGS "WPS-NEW-AP-SETTINGS "
#define WPS_EVENT_REG_SUCCESS "WPS-REG-SUCCESS "
#define WPS_EVENT_AP_SETUP_LOCKED "WPS-AP-SETUP-LOCKED "

#endif /* W32_DUMMY_WNDRV_H */ 