/**********************************************************************************
*Filename:     kjx_socket_foreign.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2015/01/17
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_include.h"
extern kjx_lbs_info_struct g_kjx_lbs_info_struct;
kjx_socket_foreign kjx_socket_foreign_setting_default[kjx_max_operator]=
{
  //kjx_unknown
  {{0,0,0,0,0},10, "", "", "", "",FALSE},
     
/*======================= China start ===========================================*/
  //kjx_cmcc
  //{{80,10,0,0,172},10, "KJX GPRS", "cmwap", "", "",TRUE},
  {{80,10,0,0,172},10, "KJX GPRS", "cmnet", "", "",FALSE},
  //kjx_unicom
  //{{80,10,0,0,172},10, "KJX GPRS", "uniwap", "", "",TRUE},
  {{80,10,0,0,172},10, "KJX GPRS", "uninet", "", "",FALSE},
/*======================= China end ===========================================*/
 
/*======================= Vietna start ===========================================*/
#if defined(__KJX_VIETNAME__)
  //kjx_vn_mobifone
  {{0,0,0,0,0},10,  "KJX GPRS", "m-wap", "", "",FALSE},//net ok
  //{{4,8080,203,162,21,107},10,  "KJX GPRS", "m-wap", "", "",TRUE},//wap ok
  //kjx_vn_vinaphone
  {{0,0,0,0,0},10,  "KJX GPRS", "m3-world", "", "",FALSE},
  //kjx_vn_viettel
  {{8080,192,168,233,10},10,  "KJX GPRS", "v-wap", "", "",TRUE},//wap ok
  //{{4,0,0,0,0,0},10,  "KJX GPRS", "v-internet", "", "",FALSE},//net ok
  //kjx_vn_vietnamobile
  {{8080,10,10,128,44},10,  "KJX GPRS", "WAP", "", "",TRUE},// wap ok
  //{{4,0,0,0,0,0},10,  "KJX GPRS", "internet", "", "",FALSE},//net ok
  //kjx_vn_beeline
  {{0,0,0,0,0},10,  "KJX GPRS", "internet", "", "",FALSE},//ok
#endif
/*======================= Vietna end ===========================================*/
  
/*======================= Indonisa start ===========================================*/
#if defined(__KJX_INDONESIA__)
  //kjx_id_3
  {{3128,10,4,0,10},10,  "KJX GPRS",  "3gprs", "3gprs", "1234",TRUE},
  //kjx_id_axis
  {{8080,10,8,3,8},10,  "KJX GPRS",  "AXIS", "AXIS", "1234",TRUE},
  //kjx_id_telkomsel
  {{8000,10,1,89,130},10,  "KJX GPRS",  "telkomsel", "wap", "wap123",TRUE},
  //kjx_id_xl
  {{8080,202,152,240,50},10,  "KJX GPRS",  "www.xlgprs.net", "xlgprs", "prox1",TRUE},
  //kjx_id_indosat
  {{8080,10,19,19,19},10,  "KJX GPRS",   "indosatgprs", "", "",TRUE},
 #endif
/*======================= Indonisa end ===========================================*/

/*======================= India start ===========================================*/
 #if defined(__KJX_INDIA__)
  //kjx_in_vodafone
  {{9401,10,10,1,100},10,  "KJX GPRS",   "protalnmms", "", "",TRUE},
  //kjx_in_aircel
  {{8081,192,168,35,201},10,  "KJX GPRS",   "aircelwap", "", "",TRUE},
  //kjx_in_airtel
  {{8080,100,1,200,99},10,  "KJX GPRS",   "airtelfun.com", "", "",TRUE},
  //kjx_in_bsnl
  {{8080,10,220,67,131},10,  "KJX GPRS",   "bsnlwap", "", "",TRUE},
  //kjx_in_reliance
  {{8080,10,239,221,5},10,  "KJX GPRS",   "rcomwap", "", "",TRUE},
  //kjx_in_idea
  {{8080,10,4,42,15},10,  "KJX GPRS",   "imis", "", "",TRUE},
  //kjx_in_tata_docomo
  {{8080,10,124,94,7},10,  "KJX GPRS",   "TATA.DOCOMO.DIVE.IN", "", "",TRUE},
 #endif
/*======================= India end ===========================================*/

/*======================= Egypty start ===========================================*/
#if defined(__KJX_EGYPT__)
  //kjx_eg_mobinil
  {{8080,62,241,155,45},10,  "KJX GPRS",   "Mobinilwap", "", "",TRUE},
  //kjx_eg_vodafone
  {{0,0,0,0,0},10,  "KJX GPRS",   "internet.vodafone.net", "internet", "internet",FALSE},
  //kjx_eg_etisalat
  {{8080,10,71,130,29},10,  "KJX GPRS",   "etisalat", "", "",TRUE},
#endif
/*======================= Egypty end ===========================================*/

/*======================= Brazil start ===========================================*/
 #if defined(__KJX_BRAZIL__)
  //kjx_eg_claro
  {{0,0,0,0,0},10,  "KJX GPRS",   "claro.com.br", "claro", "claro",FALSE},
  //kjx_eg_tim
  {{0,0,0,0,0},10,  "KJX GPRS",   "tim.br", "tim", "tim",FALSE},
  //kjx_eg_vivo
  {{80,200,142,130,166},10,  "KJX GPRS",   "wap.vivo.com.br", "vivo", "vivo",TRUE},
  //kjx_eg_oi
  {{3128,200,222,108,241},10,  "KJX GPRS",   "wapgprs.oi.com.br", "oiwap", "oioioi",TRUE},
 #endif
/*======================= Brazil end ===========================================*/

/*======================= Russia start ===========================================*/
#if defined(__KJX_RUSSIA__)
  //kjx_eg_megafon
  {{8080,10,10,10,10},10,  "KJX GPRS",   "wap", "wap", "wap",TRUE},
  //kjx_eg_beeline
  {{8080,192,168,17,1},10,  "KJX GPRS",   "wap.beeline.ru", "beeline", "beeline",TRUE},
  //kjx_eg_mts
  {{8080,192,168,192,192},10,  "KJX GPRS",   "wap.mts.ru", "mts", "mts",TRUE},
  //kjx_eg_tele2
  {{8080,130,244,196,90},10,  "KJX GPRS",   "wap.tele2.ru", "", "",TRUE},
  //kjx_eg_smart
  {{0,0,0,0,0},10,  "KJX GPRS",   "", "", "",FALSE},
 #endif
/*======================= Russia end ===========================================*/

/*======================= Malaysia start ===========================================*/
#if defined(__KJX_MALAYSIA__)
  //kjx_my_digi
  {{80,203,92,128,188},10,  "KJX GPRS",   "digiwap", "digi", "digi",TRUE},
  //kjx_my_celcom
  {{8080,10,128,1,242},10,  "KJX GPRS",   "celcom", "", "",TRUE},
  //kjx_my_maxis
  {{0,0,0,0,0},10,  "KJX GPRS",   "net", "maxis", "wap",FALSE},
 #endif
/*======================= Malaysia end ===========================================*/

/*======================= Peru start ===========================================*/
#if defined(__KJX_PERU__)
  //kjx_pe_claro
  {{8080,192,168,231,30},10,  "KJX GPRS",   "wap.claro.pe", "claro", "claro",TRUE},
  //kjx_pe_movistar
  {{0,0,0,0,0},10,  "KJX GPRS",   "movistar.pe", "movistar@datos", "movistar",FALSE},
#endif
/*======================= Peru end ===========================================*/

/*======================= Mexico start ===========================================*/
#if defined(__KJX_MEXICO__)
  //kjx_mx_telcel
  {{8080,148,233,151,240},10,  "KJX GPRS",   "wap.itelcel.com", "iesgprs", "iesgprs2002",TRUE},
  //kjx_mx_movistar
  {{0,0,0,0,0},10,  "KJX GPRS",   "internet.movistar.mx", "movistar", "movistar",FALSE},
  //kjx_mx_unefon
  {{80,192,200,1,40},10,  "KJX GPRS",   "wap.iusacellgsm.mx", "iusacellgsm", "iusacellgsm",TRUE},
#endif
/*======================= Mexico end ===========================================*/

/*======================= Nigeria start ===========================================*/
#if defined(__KJX_NIGERIA__)
  //kjx_ng_mtn
  {{8080,10,199,212,2},10,  "KJX GPRS",   "web.gprs.mtnnigeria.net", "web", "web",TRUE},
  //kjx_ng_glo
  {{0,0,0,0,0},10,  "KJX GPRS",   "gloflat", "flat", "flat",FALSE},
  //kjx_ng_zain
  {{8080,172,18,254,5},10,  "KJX GPRS",   "wap.ng.zain.com", "wap", "wap",TRUE},
  //kjx_ng_etisalat
  {{8080,10,71,170,5},10,  "KJX GPRS",   "etisalat", "", "",TRUE},
#endif
/*======================= Nigeria end ===========================================*/

/*======================= Thailand start ===========================================*/
 #if defined(__KJX_THAI__)
  //kjx_th_dtac
  {{8080,203,155,200,133},10,  "KJX GPRS",   "wap.djuice.co.th", "", "",TRUE},
  //kjx_th_true
  {{8080,10,4,4,4},10,  "KJX GPRS",   "wap", "orange", "orange",TRUE},
  //kjx_th_ais
  {{8080,203,170,229,34},10,  "KJX GPRS",   "wap", "", "",TRUE},
 #endif
/*======================= Thailand end ===========================================*/

/*======================= Turkey start ===========================================*/
#if defined(__KJX_TURKEY__)
  //kjx_tr_turkcell
  {{8080,212,252,234,168},10,  "KJX GPRS",   "wap", "gprs", "",TRUE},
  //kjx_tr_vodafone
  {{9401,212,65,136,226},10,  "KJX GPRS",   "internet", "vodafone", "",TRUE},
  //kjx_tr_avea
  {{8080,213,161,151,201},10,  "KJX GPRS",   "wap", "wap", "",TRUE},
#endif
/*======================= Turkey end ===========================================*/

/*======================= South Africa start =======================================*/
#if defined(__KJX_SOUTH_AFRICA__)
  //kjx_sa_cell_c
  {{0,168,210,2,2},10,  "KJX GPRS",   "internet", "", "",TRUE},
  //kjx_sa_mtn
  {{0,196,11,240,241},10,  "KJX GPRS",   "internet", "", "",TRUE},
  //kjx_sa_vodacom
  {{0,0,0,0,0},10,  "KJX GPRS",   "internet", "", "",TRUE},
#endif
/*======================= South Africa end =======================================*/
};

kjx_operator kjx_get_operator()
{
	U8  pPLMN[6];

	memset(pPLMN, 0x00, sizeof(pPLMN));
	memcpy(pPLMN,g_kjx_lbs_info_struct.mcc,3);
	strncat(pPLMN,g_kjx_lbs_info_struct.mnc,2);
	pPLMN[6]='\0';

#if defined(__KJX_LOG_OUTPUT__)
	LOGD("pPLMN=%s", pPLMN);
#endif
	
	// China
	if((strncmp((char *)pPLMN,KJX_CMCC_HOME_NUMBER_1,KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_CMCC_HOME_NUMBER_2,KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_CMCC_HOME_NUMBER_3,KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_cmcc;
	if(strncmp((char *)pPLMN,KJX_UNICOM_HOME_NUMBER_1,KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_unicom;

	// Vietna
#if defined(__KJX_VIETNAME__)
	if(strncmp((char *)pPLMN, KJX_VN_MOBIFONE_1, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_vn_mobifone;
	if(strncmp((char *)pPLMN, KJX_VN_VINAPHONE_1, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_vn_vinaphone;
	if(strncmp((char *)pPLMN, KJX_VN_VIETTEL_1, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_vn_viettel;
	if(strncmp((char *)pPLMN, KJX_VN_VIETNAMOBILE_1, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_vn_vietnamobile;
	if(strncmp((char *)pPLMN, KJX_VN_BEELINE_1, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_vn_beeline;
#endif/*__KJX_VIETNAME__*/

	// Indonisa
#if defined(__KJX_INDONESIA__)
	if(strncmp((char *)pPLMN, KJX_ID_3, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_id_3;
	if(strncmp((char *)pPLMN, KJX_ID_AXIS, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_id_axis;
	if(strncmp((char *)pPLMN, KJX_ID_TELKOMSEL, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_id_telkomsel;
	if(strncmp((char *)pPLMN, KJX_ID_XL, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_id_xl;
	if(strncmp((char *)pPLMN, KJX_ID_INDOSAT, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_id_indosat;
#endif/*__KJX_INDONESIA__*/

	// India
#if defined(__KJX_INDIA__)
	if(strncmp((char *)pPLMN, KJX_IN_VODAFONE, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_in_vodafone;
	if(strncmp((char *)pPLMN, KJX_IN_AIRCEL, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_in_aircel;
	if(strncmp((char *)pPLMN, KJX_IN_AIRTEL, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_in_airtel;
	if(strncmp((char *)pPLMN, KJX_IN_BSNL, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_in_bsnl;
	if(strncmp((char *)pPLMN, KJX_IN_RELIANCE, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_in_reliance;
	if(strncmp((char *)pPLMN, KJX_IN_IDEA, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_in_idea;
	if(strncmp((char *)pPLMN, KJX_IN_TATA_DOCOMO, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_in_tata_docomo;
#endif/*__KJX_INDIA__*/

	// Egypty
#if defined(__KJX_EGYPT__)
	if(strncmp((char *)pPLMN, KJX_EG_MOBINIL, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_eg_mobinil;
	if(strncmp((char *)pPLMN, KJX_EG_VODAFONE, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_eg_vodafone;
	if(strncmp((char *)pPLMN, KJX_EG_ETISALAT, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_eg_etisalat;
#endif/*__KJX_EGYPT__*/

	// Brazil
#if defined(__KJX_BRAZIL__)
	if(strncmp((char *)pPLMN,KJX_BR_CLARO, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_br_claro;
	if((strncmp((char *)pPLMN,KJX_BR_TIM_1, KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_BR_TIM_2,KJX_HOME_NUMBER_LENGTH) == 0) ||
		(strncmp((char *)pPLMN,KJX_BR_TIM_3,KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_br_tim;
	if((strncmp((char *)pPLMN,KJX_BR_VIVO_1, KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_BR_VIVO_2,KJX_HOME_NUMBER_LENGTH) == 0) ||
		(strncmp((char *)pPLMN,KJX_BR_VIVO_3,KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_br_vivo;
	if((strncmp((char *)pPLMN,KJX_BR_OI_1, KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_BR_OI_2,KJX_HOME_NUMBER_LENGTH) == 0) ||
		(strncmp((char *)pPLMN,KJX_BR_OI_3,KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_br_oi;
#endif/*__KJX_BRAZIL__*/

	// Russia
#if defined(__KJX_RUSSIA__)
	if(strncmp((char *)pPLMN,KJX_RU_MEGAFON, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_ru_megafon;
	if((strncmp((char *)pPLMN,KJX_RU_BEELINE_1, KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_RU_BEELINE_2,KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_ru_beeline;
	if((strncmp((char *)pPLMN,KJX_RU_MTS, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_ru_mts;
	if((strncmp((char *)pPLMN,KJX_RU_TELE2, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_ru_tele2;
	if((strncmp((char *)pPLMN,KJX_RU_SMART_1, KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_RU_SMART_2,KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_ru_smart;
#endif/*__KJX_RUSSIA__*/

	// Malaysia
#if defined(__KJX_MALAYSIA__)
	if(strncmp((char *)pPLMN,KJX_MY_DIGI, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_my_digi;
	if((strncmp((char *)pPLMN,KJX_MY_CELCOM_1, KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_MY_CELCOM_2,KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_my_celcom;
	if((strncmp((char *)pPLMN,KJX_MY_MAXIS_1, KJX_HOME_NUMBER_LENGTH) == 0) || 
		(strncmp((char *)pPLMN,KJX_MY_MAXIS_2,KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_my_maxis;
#endif/*__KJX_MALAYSIA__*/

	// Peru
#if defined(__KJX_PERU__)
	if(strncmp((char *)pPLMN,KJX_PE_CLARO, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_pe_claro;
	if((strncmp((char *)pPLMN,KJX_PE_MOVISTAR, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_pe_movistar;
#endif/*__KJX_PERU__*/

	// Mexico
#if defined(__KJX_MEXICO__)
	if(strncmp((char *)pPLMN,KJX_MX_TELCEL, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_mx_telcel;
	if((strncmp((char *)pPLMN,KJX_MX_MOVISTAR, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_mx_movistar;
	if((strncmp((char *)pPLMN,KJX_MX_UNEFON, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_mx_unefon;
#endif/*__KJX_MEXICO__*/

	// Nigeria
#if defined(__KJX_NIGERIA__)
	if(strncmp((char *)pPLMN,KJX_NG_MTN, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_ng_mtn;
	if((strncmp((char *)pPLMN,KJX_NG_GLO, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_ng_glo;
	if((strncmp((char *)pPLMN,KJX_NG_ZAIN, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_ng_zain;
	if((strncmp((char *)pPLMN,KJX_NG_ETISALAT, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_ng_etisalat;
#endif/*__KJX_NIGERIA__*/

	// Thailand
 #if defined(__KJX_THAI__)
	if(strncmp((char *)pPLMN,KJX_TH_DTAC, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_th_dtac;
	if((strncmp((char *)pPLMN,KJX_TH_TRUE, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_th_true;
	if((strncmp((char *)pPLMN,KJX_TH_AIS, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_th_ais;
#endif/*__KJX_THAI__*/

	// Turkey
#if defined(__KJX_TURKEY__)
	if(strncmp((char *)pPLMN,KJX_TR_TURKCELL, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_tr_turkcell;
	if((strncmp((char *)pPLMN,KJX_TR_VODAFONE, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_tr_vodafone;
	if((strncmp((char *)pPLMN,KJX_TR_AVEA, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_tr_avea;
#endif/*__KJX_TURKEY__*/

	//South Africa
#if defined(__KJX_SOUTH_AFRICA__)
	if(strncmp((char *)pPLMN,KJX_SA_CELL_C, KJX_HOME_NUMBER_LENGTH) == 0)
		return kjx_sa_cell_c;
	if((strncmp((char *)pPLMN,KJX_SA_MTN, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_sa_mtn;
	if((strncmp((char *)pPLMN,KJX_SA_VODACOM, KJX_HOME_NUMBER_LENGTH) == 0))
		return kjx_sa_vodacom;
#endif/*__KJX_SOUTH_AFRICA__*/

	return kjx_unknown;
}
#endif

