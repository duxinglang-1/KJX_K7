/**********************************************************************************
*Filename:     kjx_socket_foreign.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2015/01/17
*
***********************************************************************************/
#if !defined(KJX_SOCKET_FOREIGN_H)
#define KJX_SOCKET_FOREIGN_H

#if defined(__KJX_FUN__)

#define KJX_RS_MAX_SOCK_ADDR_LEN 28
  
#if defined(__KJX_FOREIGN__)
#define __KJX_VIETNAME__		/*越南*/
#define __KJX_INDONESIA__		/*印尼*/
#define __KJX_INDIA__			/*印度*/
#define __KJX_EGYPT__			/*埃及*/
#define __KJX_BRAZIL__			/*巴西*/
#define __KJX_RUSSIA__			/*俄罗斯*/
#define __KJX_MALAYSIA__		/*马来西亚*/
#define __KJX_PERU__			/*秘鲁*/
#define __KJX_MEXICO__			/*墨西哥*/
#define __KJX_NIGERIA__		/*尼日利亚*/
#define __KJX_THAI__			/*泰国*/
#define __KJX_TURKEY__			/*土耳其*/
#define __KJX_SOUTH_AFRICA__	/*南非*/


#define __KJX_ARGENTINA__	//阿根廷
#define __KJX_COLOMBIA__	//哥伦比亚
#define __KJX_KAZAKHSTAN__	//哈萨克斯坦
#define __KJX_SOUTHAFRICA__	//南非
#define __KJX_SAUDIARABIA__	//沙特阿拉伯
#define __KJX_VENEZUELA__	//委内瑞拉
#define __KJX_UKRAINE__	//乌克兰
#define __KJX_IRAQ__	//伊拉克
#define __KJX_CHILE__	//智利
#define __KJX_CHINA__
#endif

#define KJX_HOME_NUMBER_LENGTH			5
// China
#define KJX_CMCC_HOME_NUMBER_1			"46000"
#define KJX_CMCC_HOME_NUMBER_2			"46002"
#define KJX_CMCC_HOME_NUMBER_3			"46007"
#define KJX_UNICOM_HOME_NUMBER_1		"46001"
// Vietna
#if defined(__KJX_VIETNAME__)
#define KJX_VN_MOBIFONE_1					"45201"
#define KJX_VN_VINAPHONE_1				"45202"
#define KJX_VN_VIETTEL_1					"45204"
#define KJX_VN_VIETNAMOBILE_1				"45205"
#define KJX_VN_BEELINE_1					"45207"
#endif
// Indonisa
#if defined(__KJX_INDONESIA__)
#define KJX_ID_3								"51021"
#define KJX_ID_AXIS							"51008"
#define KJX_ID_TELKOMSEL					"51020"
#define KJX_ID_XL							"51011"
#define KJX_ID_INDOSAT						"51001"
 #endif
// India
 #if defined(__KJX_INDIA__)
#define KJX_IN_VODAFONE					"40484"
#define KJX_IN_AIRCEL						"40428"
#define KJX_IN_AIRTEL						"40431"
#define KJX_IN_BSNL							"40480"
#define KJX_IN_RELIANCE						"40409"
#define KJX_IN_IDEA							"40422"
#define KJX_IN_TATA_DOCOMO				"40525"
 #endif
// Egypty
#if defined(__KJX_EGYPT__)
#define KJX_EG_MOBINIL						"60201"
#define KJX_EG_VODAFONE					"60202"
#define KJX_EG_ETISALAT						"60203"
#endif
// Brazil
 #if defined(__KJX_BRAZIL__)
#define KJX_BR_CLARO						"72405"
#define KJX_BR_TIM_1						"72402"
#define KJX_BR_TIM_2						"72403"
#define KJX_BR_TIM_3						"72404"
#define KJX_BR_VIVO_1						"72406"
#define KJX_BR_VIVO_2						"72410"
#define KJX_BR_VIVO_3						"72411"
#define KJX_BR_OI_1							"72416"
#define KJX_BR_OI_2							"72424"
#define KJX_BR_OI_3							"72431"
 #endif
// Russia
#if defined(__KJX_RUSSIA__)
#define KJX_RU_MEGAFON						"25002"
#define KJX_RU_BEELINE_1					"25028"
#define KJX_RU_BEELINE_2					"25099"
#define KJX_RU_MTS							"25001"
#define KJX_RU_TELE2						"25020"
#define KJX_RU_SMART_1						"25007"
#define KJX_RU_SMART_2						"25015"
 #endif
// Malaysia
#if defined(__KJX_MALAYSIA__)
#define KJX_MY_DIGI							"50216"
#define KJX_MY_CELCOM_1					"50213"
#define KJX_MY_CELCOM_2					"50219"
#define KJX_MY_MAXIS_1						"50212"
#define KJX_MY_MAXIS_2						"50217"
 #endif
// Peru
#if defined(__KJX_PERU__)
#define KJX_PE_CLARO						"71610"
#define KJX_PE_MOVISTAR					"71606"
#endif
// Mexico
#if defined(__KJX_MEXICO__)
#define KJX_MX_TELCEL						"25002"
#define KJX_MX_MOVISTAR					"25028"
#define KJX_MX_UNEFON						"25099"
#endif
// Nigeria
#if defined(__KJX_NIGERIA__)
#define KJX_NG_MTN							"62130"
#define KJX_NG_GLO							"62150"
#define KJX_NG_ZAIN							"62120"
#define KJX_NG_ETISALAT						"62160"
#endif
// Thailand
 #if defined(__KJX_THAI__)
#define KJX_TH_DTAC							"52018"
#define KJX_TH_TRUE							"52099"
#define KJX_TH_AIS							"52023"
 #endif
// Turkey
#if defined(__KJX_TURKEY__)
#define KJX_TR_TURKCELL					"28601"
#define KJX_TR_VODAFONE					"28602"
#define KJX_TR_AVEA							"28603"
#endif

//South Africa
#if defined(__KJX_SOUTH_AFRICA__)
#define KJX_SA_CELL_C						"65507"
#define KJX_SA_MTN							"65510"
#define KJX_SA_VODACOM					"65501"
#endif

typedef struct 
{
    uint16	port;
    uint8	addr[KJX_RS_MAX_SOCK_ADDR_LEN];
} kjx_socket_sockaddr_struct;


typedef struct 
{
  kjx_socket_sockaddr_struct kjxaddr;
  uint8 contextID;
  char * netName;
  char * apnMode;
  char* userName;
  char* password;
  BOOL socket_type_is_wap;
} kjx_socket_foreign;

//卡通信商
typedef enum
{
	kjx_unknown,			/*!< 未知的 */
	// China
	kjx_cmcc,				/*!< 中国移动 */
	kjx_unicom,				/*!< 中国联通 */
	// Vietna
#if defined(__KJX_VIETNAME__)
	kjx_vn_mobifone,
	kjx_vn_vinaphone,
	kjx_vn_viettel,
	kjx_vn_vietnamobile,
	kjx_vn_beeline,
#endif/*__KJX_VIETNAME__*/
	// Indonisa
#if defined(__KJX_INDONESIA__)
	kjx_id_3,
	kjx_id_axis,
	kjx_id_telkomsel,
	kjx_id_xl,
	kjx_id_indosat,
#endif/*__KJX_INDONESIA__*/
	// India
 #if defined(__KJX_INDIA__)
	kjx_in_vodafone,
	kjx_in_aircel,
	kjx_in_airtel,
	kjx_in_bsnl,
	kjx_in_reliance,
	kjx_in_idea,
	kjx_in_tata_docomo,
#endif/*__KJX_INDIA__*/
	// Egypty
#if defined(__KJX_EGYPT__)
	kjx_eg_mobinil,
	kjx_eg_vodafone,
	kjx_eg_etisalat,
#endif/*__KJX_EGYPT__*/
	// Brazil
#if defined(__KJX_BRAZIL__)
	kjx_br_claro,
	kjx_br_tim,
	kjx_br_vivo,
	kjx_br_oi,
#endif/*__KJX_BRAZIL__*/
	// Russia
#if defined(__KJX_RUSSIA__)
	kjx_ru_megafon,
	kjx_ru_beeline,
	kjx_ru_mts,
	kjx_ru_tele2,
	kjx_ru_smart,
#endif/*__KJX_RUSSIA__*/
	// Malaysia
#if defined(__KJX_MALAYSIA__)
	kjx_my_digi,
	kjx_my_celcom,
	kjx_my_maxis,
#endif/*__KJX_MALAYSIA__*/
	// Peru
#if defined(__KJX_PERU__)
	kjx_pe_claro,
	kjx_pe_movistar,
#endif/*__KJX_PERU__*/
	// Mexico
#if defined(__KJX_MEXICO__)
	kjx_mx_telcel,
	kjx_mx_movistar,
	kjx_mx_unefon,
#endif/*__KJX_MEXICO__*/
	// Nigeria
#if defined(__KJX_NIGERIA__)
	kjx_ng_mtn,
	kjx_ng_glo,
	kjx_ng_zain,
	kjx_ng_etisalat,
#endif/*__KJX_NIGERIA__*/
	// Thailand
 #if defined(__KJX_THAI__)
	kjx_th_dtac,
	kjx_th_true,
	kjx_th_ais,
#endif/*__KJX_THAI__*/
	// Turkey
#if defined(__KJX_TURKEY__)
	kjx_tr_turkcell,
	kjx_tr_vodafone,
	kjx_tr_avea,
#endif/*__KJX_TURKEY__*/

#if defined(__KJX_SOUTH_AFRICA__)
	kjx_sa_cell_c,
	kjx_sa_mtn,
	kjx_sa_vodacom,
#endif/*__KJX_TURKEY__*/

	kjx_max_operator
}kjx_operator;

#endif
#endif
