/*
 * Copyright (C) Teleca AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_xchr.c
 * 
 * Additional Character Set Support
 *
 *
 * Place in this file all additional character set conversion
 * routines that are needed. As an example, conversions to and
 * from ISO-8859-2 (Latin2) and ISO-8859-8 (Hebrew), are included.
 * These can be removed if not required.
 * If no additional character set support is required, this
 * whole file can be left empty.
 */
#include "msf_def.h"
#include "msf_chrs.h"
#include "msf_xchr.h"
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef WAP_SUPPORT
#include "msf_int.h"
#include "widget_extension.h"
#endif 
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
 

/**********************************************************************
 * Function Declarations
 **********************************************************************/

static int
msf_xchr_latin2_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_latin2 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_hebrew_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_hebrew (const char *src, long *srcLen, char *dst, long *dstLen);

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef __MMI_CHSET_WESTERN_ISO__

static int
msf_xchr_latin1_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_latin1 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_SEURO_ISO__

static int
msf_xchr_latin3_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_latin3 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif


#ifdef __MMI_CHSET_BALTIC_ISO__
static int
msf_xchr_latin4_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_latin4 (const char *src, long *srcLen, char *dst, long *dstLen);
#endif

#ifdef __MMI_CHSET_CYRILLIC_ISO__

static int
msf_xchr_cyrillic_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_cyrillic (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_ARABIC_ISO__


static int
msf_xchr_arabic_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_arabic (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_GREEK_ISO__


static int
msf_xchr_greek_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_greek (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_TURKISH_ISO__


static int
msf_xchr_latin5_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_latin5 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_NORDIC_ISO__


static int
msf_xchr_latin6_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int
msf_xchr_utf8_to_latin6 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif


#ifdef WAP_SUPPORT

#ifdef __MMI_CHSET_BIG5__

static int 
msf_xchr_big5_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_big5 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif /* __MMI_CHSET_BIG5__ */

#ifdef __MMI_CHSET_GB2312__

static int 
msf_xchr_gb2312_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_gb2312 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif /* __MMI_CHSET_GB2312__ */

#ifdef __MMI_CHSET_HKSCS__

static int 
msf_xchr_hkscs_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_hkscs (const char *src, long *srcLen, char *dst, long *dstLen);

#endif /* __MMI_CHSET_HKSCS__ */

#ifdef __MMI_CHSET_GB18030__

static int 
msf_xchr_gb18030_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_gb18030 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif /* __MMI_CHSET_GB18030__ */

#ifdef __MMI_CHSET_ARABIC_WIN__

static int 
msf_xchr_win1256_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1256 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif /* __MMI_CHSET_ARABIC_WIN__ */


#ifdef __MMI_CHSET_CEURO_WIN__
static int 
msf_xchr_win1250_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1250 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_CYRILLIC_WIN__

static int 
msf_xchr_win1251_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1251 (const char *src, long *srcLen, char *dst, long *dstLen);
#endif

#ifdef __MMI_CHSET_WESTERN_WIN__

static int 
msf_xchr_win1252_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1252 (const char *src, long *srcLen, char *dst, long *dstLen);
#endif

#ifdef __MMI_CHSET_GREEK_WIN__

static int 
msf_xchr_win1253_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1253 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_TURKISH_WIN__

static int 
msf_xchr_win1254_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1254 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_HEBREW_WIN__

static int 
msf_xchr_win1255_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1255 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_BALTIC_WIN__

static int 
msf_xchr_win1257_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1257 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_VIETNAMESE_WIN___

static int 
msf_xchr_win1258_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_win1258 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_THAI_WINDOWS__

static int 
msf_xchr_windows874_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_windows874 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_PERSIAN_CP1097__

static int 
msf_xchr_cp1097_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_cp1097 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_PERSIAN_CP1098__

static int 
msf_xchr_cp1098_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_cp1098 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_SJIS__

static int 
msf_xchr_Shift_JIS_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_Shift_JIS (const char *src, long *srcLen, char *dst, long *dstLen);

#endif


#ifdef __MMI_CHSET_UTF7__

static int 
msf_xchr_utf7_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_utf7 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_KOI8_R__

static int 
msf_xchr_KOI8R_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_KOI8R (const char *src, long *srcLen, char *dst, long *dstLen);

#endif


#ifdef __MMI_CHSET_TIS_620__

static int 
msf_xchr_TIS620_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_TIS620 (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#ifdef __MMI_CHSET_EUCKR__

static int 
msf_xchr_EUCKR_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

static int 
msf_xchr_utf8_to_EUCKR (const char *src, long *srcLen, char *dst, long *dstLen);

#endif

#endif /* WAP_SUPPORT */
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/**********************************************************************
 * Exported Global Variable
 **********************************************************************/

/*
 * This is the table that holds information about all additional
 * character sets that are supported.
 *
 * The first field, 'character_set', should hold the IANA registered
 * number for the character set in question.
 *
 * The second field, 'preferred_name', should hold a string with
 * the preferred name that identifies this character set.
 *
 * The third field, 'aliases', should hold a string with comma-separated
 * names that are recognized as alternative names for this character set.
 * If there are no such aliases, use the empty string (""). Do not include
 * any spaces among the names.
 *
 * The fourth field, 'cvt_to_utf8, should be a pointer to the function
 * that performs the conversion from the character set in question
 * to UTF-8. If no such function is provided, set this field to NULL.
 *
 * The fifth field, 'cvt_from_utf8, should be a pointer to the function
 * that performs the conversion from UTF-8 to the character set in question.
 * If no such function is provided, set this field to NULL. At least one
 * of the fields 'cvt_to_utf8' and 'cvt_from_utf8' must be different
 * from NULL, otherwise the entry serves no purpose.
 *
 */
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
const msf_xchr_entry_t gmms_msf_xchr_table[MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS] = {
  {5, "iso-8859-2", "latin2,iso-ir-101,iso_8859-2,l2,csISOLatin2",
    msf_xchr_latin2_to_utf8, msf_xchr_utf8_to_latin2},
  {11, "iso-8859-8", "hebrew,iso-ir-138,iso_8859-8,csISOLatinHebrew",
     msf_xchr_hebrew_to_utf8, msf_xchr_utf8_to_hebrew}
};
#else
const msf_xchr_entry_t gmms_msf_xchr_table[MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS] = {
#ifdef __MMI_CHSET_WESTERN_ISO__
	{4, "iso-8859-1", "latin1,iso-ir-100,iso_8859-1,l1,csISOLatin1,IBM819,CP819",
		msf_xchr_latin1_to_utf8, msf_xchr_utf8_to_latin1},
#else
	{-1, "", "", 
	NULL, NULL},
#endif
  {5, "iso-8859-2", "latin2,iso-ir-101,iso_8859-2,l2,csISOLatin2",
    msf_xchr_latin2_to_utf8, msf_xchr_utf8_to_latin2},
#ifdef __MMI_CHSET_SEURO_ISO__
	{6, "iso-8859-3", "latin3,iso-ir-109,iso_8859-3,l3,csISOLatin3",
	msf_xchr_latin3_to_utf8, msf_xchr_utf8_to_latin3},
#else
	{-1, "", "", 
	NULL, NULL},
#endif
#ifdef __MMI_CHSET_BALTIC_ISO__
	{7, "iso-8859-4", "latin4,iso-ir-110,iso_8859-4,l4,csISOLatin4",
	msf_xchr_latin4_to_utf8, msf_xchr_utf8_to_latin4},
#else
	{-1, "", "", 
	NULL, NULL},
#endif
#ifdef __MMI_CHSET_CYRILLIC_ISO__
	{8, "iso-8859-5", "cyrillic,iso-ir-144,iso_8859-5,csISOLatinCyrillic",
	msf_xchr_cyrillic_to_utf8, msf_xchr_utf8_to_cyrillic},
#else
	{-1, "", "", 
	NULL, NULL},
#endif
#ifdef __MMI_CHSET_ARABIC_ISO__
	{9, "iso-8859-6", "arabic,iso-ir-127,iso_8859-6,csISOLatinArabic,ECMA-114,ASMO-708",
	msf_xchr_arabic_to_utf8, msf_xchr_utf8_to_arabic},
#else
	{-1, "", "", 
	NULL, NULL},
#endif
#ifdef __MMI_CHSET_GREEK_ISO__
	{10, "iso-8859-7", "greek,iso-ir-126,iso_8859-7,csISOLatinGreek,ELOT_928,ECMA_118,greek8",
	msf_xchr_greek_to_utf8, msf_xchr_utf8_to_greek},
#else
	{-1, "", "", 
	NULL, NULL},
#endif
  {11, "iso-8859-8", "hebrew,iso-ir-138,iso_8859-8,csISOLatinHebrew",
     msf_xchr_hebrew_to_utf8, msf_xchr_utf8_to_hebrew},
#ifdef __MMI_CHSET_TURKISH_ISO__
	{12, "iso-8859-9", "latin5,iso-ir-148,iso_8859-9,csISOLatin5,l5",
	msf_xchr_latin5_to_utf8, msf_xchr_utf8_to_latin5},
#else
	{-1, "", "", 
	NULL, NULL},
#endif
#ifdef __MMI_CHSET_NORDIC_ISO__
	{13, "iso-8859-10", "latin6,iso-ir-157,iso_8859-10,csISOLatin5,l6",
	msf_xchr_latin6_to_utf8, msf_xchr_utf8_to_latin6},
#else
	{-1, "", "", 
	NULL, NULL},
#endif
#ifdef __MMI_CHSET_BIG5__
  // Although we do not always have Hongkong extension
  {2026, "Big5", "Big5-HKSCS,csBig5", 
     msf_xchr_big5_to_utf8, msf_xchr_utf8_to_big5},
#else
  {-1, "", "", 
     NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_GB18030__
  {2024, "GB18030", "gb18030,gb2312,gb18030-2000,gbk,ibm1392,ibm-1392,windows-54936,csGB2312,GB_2312-80,iso-ir-58,chinese,csISO58GB231280",
     msf_xchr_gb18030_to_utf8, msf_xchr_utf8_to_gb18030},
#else
  {-1, "", "",
     NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_GB2312__
  // Although GB2312 and GB2312-80 are not exactly the same
  {2025, "GB2312", "gbk,csGB2312,GB_2312-80,iso-ir-58,chinese,csISO58GB231280",
     msf_xchr_gb2312_to_utf8, msf_xchr_utf8_to_gb2312},
#else
  {-1, "", "",
     NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_HKSCS__
  {2025, "HKSCS", "HKSCS-2004,gbk,csHKSCS,GB_2312-80,iso-ir-58,chinese,csISO58HKSCS80",
     msf_xchr_hkscs_to_utf8, msf_xchr_utf8_to_hkscs},
#else
  {-1, "", "",
     NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_ARABIC_WIN__  
  {2256, "windows-1256", "",
     msf_xchr_win1256_to_utf8, msf_xchr_utf8_to_win1256},
#else
  {-1, "", "",
     NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_CEURO_WIN__
	{2250, "windows-1250", "",
	msf_xchr_win1250_to_utf8, msf_xchr_utf8_to_win1250},
#else
	{-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_CYRILLIC_WIN__
	{2251, "windows-1251", "",
	msf_xchr_win1251_to_utf8, msf_xchr_utf8_to_win1251},
#else
	{-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_WESTERN_WIN__
	{2252, "windows-1252", "",
	msf_xchr_win1252_to_utf8, msf_xchr_utf8_to_win1252},
#else
	{-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_GREEK_WIN__
	{2253, "windows-1253", "",
	msf_xchr_win1253_to_utf8, msf_xchr_utf8_to_win1253},
#else
	{-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_TURKISH_WIN__
	{2254, "windows-1254", "",
	msf_xchr_win1254_to_utf8, msf_xchr_utf8_to_win1254},
#else
  {-1, "", "",
     NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_HEBREW_WIN__
	{2255, "windows-1255", "",
	msf_xchr_win1255_to_utf8, msf_xchr_utf8_to_win1255},
#else
	{-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_BALTIC_WIN__
	{2257, "windows-1257", "",
	msf_xchr_win1257_to_utf8, msf_xchr_utf8_to_win1257},
#else
	{-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_VIETNAMESE_WIN___
	{2258, "windows-1258", "",
	msf_xchr_win1258_to_utf8, msf_xchr_utf8_to_win1258},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_THAI_WINDOWS__
	{1974, "windows-874", "",
	msf_xchr_windows874_to_utf8, msf_xchr_utf8_to_windows874},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_PERSIAN_CP1097__
	{1097, "cp1097", "ibm-1097,1097,ibm1097",
	msf_xchr_cp1097_to_utf8, msf_xchr_utf8_to_cp1097},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_PERSIAN_CP1098__
	{1098, "cp1098", "ibm-1098,1098,ibm1098",
	msf_xchr_cp1098_to_utf8, msf_xchr_utf8_to_cp1098},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_SJIS__
	{10, "Shift_JIS", "shift-jis,shift_jis,x-sjis,ms_kanji,csShiftJIS,sjis",
	msf_xchr_Shift_JIS_to_utf8, msf_xchr_utf8_to_Shift_JIS},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_UTF7__
	{103, "utf7", "UTF-7",
	msf_xchr_utf7_to_utf8, msf_xchr_utf8_to_utf7},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_KOI8_R__
	{2084, "KOI8-R", "koi8,koi8_r,cskoi8r",
	msf_xchr_KOI8R_to_utf8, msf_xchr_utf8_to_KOI8R},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_TIS_620__
	{620, "TIS-620", "tis620.2533,tis620",
	msf_xchr_TIS620_to_utf8, msf_xchr_utf8_to_TIS620},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
#ifdef __MMI_CHSET_EUCKR__
	{949, "EUC-KR", "ksc5601,5601,ksc5601_1987,ksc_5601,ksc5601-1987,euc_kr,ks_c_5601-1987",
	msf_xchr_EUCKR_to_utf8, msf_xchr_utf8_to_EUCKR},
#else
  {-1, "", "",
	NULL, NULL}, /* reserved */
#endif
	{-1, "", "",
	NULL, NULL}, /* reserved */
	{-1, "", "",
	NULL, NULL}	 
};
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


/**********************************************************************
 * Functions
 **********************************************************************/

static int
msf_xchr_8859_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen,
                       const MSF_UINT16 *code_table)
{
  MSF_UINT32 w;
  int        sidx = 0, didx = 0;
  int        dn;
  MSF_UINT8  mask;

  for (;;) {
    /* First, translate to UCS4 */
    if (sidx + 1 > *srcLen)
      break;

    if (((unsigned char)src[sidx]) <= 127) {
      w = (unsigned char)src[sidx];
    }
    else {
      w = (MSF_UINT32)(code_table[(unsigned char)src[sidx] - 128]);
    }

    /* Determine how many UTF8-bytes are needed for this character,
     * and which bits should be set in the first byte. */
    if (w < 0x80) {
      dn = 1;
      mask = 0;
    }
    else if (w < 0x800) {
      dn = 2;
      mask = 0xc0;
    }
    else {
      dn = 3;
      mask = 0xe0;
    }

    /* Is there room for this in the destination vector? */
    if (didx + dn > *dstLen)
      break;

    /* Only write to destination vector if dst != NULL */
    if (dst != NULL) {
      switch (dn) {
      case 3:
        dst[didx + 2] = (char) ((w & 0x3f) | 0x80);
        w >>= 6;

      case 2:
        dst[didx + 1] = (char) ((w & 0x3f) | 0x80);
        w >>= 6;

      case 1:
        dst[didx] = (char) (w | mask);
      }
    }
    sidx += 1;
    didx += dn;
  }
  *srcLen = sidx;
  *dstLen = didx;

  return 0;
}


/**********************************************************************
 * Support for character set ISO-8859-2 (Latin-2)
 **********************************************************************/

static const MSF_UINT16 msf_xchr_latin2_code_table[256] = { 
  /* Not used */ 
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 
  
  /* Latin-2 */ 
  0x0a0, 0x104, 0x2d8, 0x141, 0x0a4, 0x13d, 0x15a, 0x0a7,         
  0x0a8, 0x160, 0x15e, 0x164, 0x179, 0x0ad, 0x17d, 0x17b, 
  0x0b0, 0x105, 0x2db, 0x142, 0x0b4, 0x13e, 0x15b, 0x2c7, 
  0x0b8, 0x161, 0x15f, 0x165, 0x17a, 0x2dd, 0x17e, 0x17c, 
  0x154, 0x0c1, 0x0c2, 0x102, 0x0c4, 0x139, 0x106, 0x0c7, 
  0x10c, 0x0c9, 0x118, 0x0cb, 0x11a, 0x0cd, 0x0ce, 0x10e, 
  0x110, 0x143, 0x147, 0x0d3, 0x0d4, 0x150, 0x0d6, 0x0d7, 
  0x158, 0x16e, 0x0da, 0x170, 0x0dc, 0x0dd, 0x162, 0x0df, 
  0x155, 0x0e1, 0x0e2, 0x103, 0x0e4, 0x13a, 0x107, 0x0e7, 
  0x10d, 0x0e9, 0x119, 0x0eb, 0x11b, 0x0ed, 0x0ee, 0x10f, 
  0x111, 0x144, 0x148, 0x0f3, 0x0f4, 0x151, 0x0f6, 0x0f7,     
  0x159, 0x16f, 0x0fa, 0x171, 0x0fc, 0x0fd, 0x163, 0x2d9 
}; 


/*
 * Convert from Latin-2 (ISO-8859-2) to UTF-8.
 */
static int
msf_xchr_latin2_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
  return msf_xchr_8859_to_utf8 (src, srcLen, dst, dstLen, msf_xchr_latin2_code_table);
}


/*
 * Convert from UTF-8 to Latin-2 (ISO-8859-2).
 */
static int
msf_xchr_utf8_to_latin2 (const char *src, long *srcLen, char *dst, long *dstLen)
{
  int        sidx = 0, didx = 0;
  int        sn;
  MSF_UINT32 w;
  int        hc;

  while (sidx < *srcLen) {
    /* Read one Unicode character in UTF-8 format: */
    sn = msf_charset_utf8_bytes_per_character[(unsigned char)*src >> 4];
    if (sidx + sn > *srcLen)
      break;

    w = 0;
    switch (sn) {
    case 0:
      return -1;

    case 4: w += (unsigned char)*src++; w <<= 6;
    case 3: w += (unsigned char)*src++; w <<= 6;
    case 2: w += (unsigned char)*src++; w <<= 6;
    case 1: w += (unsigned char)*src++;
    }
    w -= msf_charset_offsets_from_utf8[sn];

    /* Encode one Unicode character in Latin-2 alphabet: */
    if (w <= 0x7f) {
      hc = w;
    }
    else {
      int i;

      hc = '?';

      for (i = 0x80; i <= 0xff; i++) {
        if (msf_xchr_latin2_code_table[i] == w) {
          hc = i;
          break;
        }
      }
    }

    if (dst != NULL) {
      dst[didx] = (char)(hc);
    }
    sidx += sn;
    didx += 1;
  }
  *srcLen = sidx;
  *dstLen = didx;

  return 0;
}


/**********************************************************************
 * Support for character set ISO-8859-5 (Hebrew)
 **********************************************************************/

static const MSF_UINT16 msf_xchr_hebrew_code_table[256] = {
  /* Not used */
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,

  /* Like Latin-1 (almost) */
  0x0a0, 0x000, 0x0a2, 0x0a3, 0x0a4, 0x0a5, 0x0a6, 0x0a7,
  0x0a8, 0x0a9, 0x0d7, 0x0ab, 0x0ac, 0x0ad, 0x0ae, 0x0af,
  0x0b0, 0x0b1, 0x0b2, 0x0b3, 0x0b4, 0x0b5, 0x0b6, 0x0b7,
  0x0b8, 0x0b9, 0x0f7, 0x0bb, 0x0bc, 0x0bd, 0x0be, 0x000,

  /* Not used (except position 0xdf) */
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
  0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x2017,

  /* Hebrew letters */
  0x5d0, 0x5d1, 0x5d2, 0x5d3, 0x5d4, 0x5d5, 0x5d6, 0x5d7,
  0x5d8, 0x5d9, 0x5da, 0x5db, 0x5dc, 0x5dd, 0x5de, 0x5df,
  0x5e0, 0x5e1, 0x5e2, 0x5e3, 0x5e4, 0x5e5, 0x5e6, 0x5e7,
  0x5e8, 0x5e9, 0x5ea, 0x000, 0x000, 0x200e, 0x200f, 0x000
};


/*
 * Convert from hebrew (ISO-8859-8) to UTF-8.
 */
static int
msf_xchr_hebrew_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
  return msf_xchr_8859_to_utf8 (src, srcLen, dst, dstLen, msf_xchr_hebrew_code_table);
}


/*
 * Convert from UTF-8 to hebrew (ISO-8859-8).
 */
static int
msf_xchr_utf8_to_hebrew (const char *src, long *srcLen, char *dst, long *dstLen)
{
  int        sidx = 0, didx = 0;
  int        sn;
  MSF_UINT32 w;
  int        hc;

  while (sidx < *srcLen) {
    /* Read one Unicode character in UTF-8 format: */
    sn = msf_charset_utf8_bytes_per_character[(unsigned char)*src >> 4];
    if (sidx + sn > *srcLen)
      break;

    w = 0;
    switch (sn) {
    case 0:
      return -1;

    case 4: w += (unsigned char)*src++; w <<= 6;
    case 3: w += (unsigned char)*src++; w <<= 6;
    case 2: w += (unsigned char)*src++; w <<= 6;
    case 1: w += (unsigned char)*src++;
    }
    w -= msf_charset_offsets_from_utf8[sn];

    /* Encode one Unicode character in Hebrew alphabet: */
    if (w == 0xd7) {
      hc = 0xaa;
    }
    else if (w == 0xf7) {
      hc = 0xba;
    }
    else if (w == 0x2017) {
      hc = 0xdf;
    }
    else if (w == 0x200e) {
      hc = 0xfd;
    }
    else if (w == 0x200f) {
      hc = 0xfe;
    }
    else if ((w <= 0x7f) || ((w >= 0xa0) && (w <= 0xbe))) {
      hc = (int)w;
    }
    else if ((w >= 0x5d0) && (w <= 0x5ea)) {
      hc = (w - 0x5d0) + 0xe0;
    }
    else {
      hc = '?';
    }

    if (dst != NULL) {
      dst[didx] = (char)(hc);
    }
    sidx += sn;
    didx += 1;
  }
  *srcLen = sidx;
  *dstLen = didx;

  return 0;
}

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/**********************************************************************
 * Support for character set Big5 and GB2312
 **********************************************************************/

#ifdef WAP_SUPPORT

#ifdef __MMI_CHSET_BIG5__

static int 
msf_xchr_big5_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtBig5ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_big5 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToBig5((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

#endif /* __MMI_CHSET_BIG5__ */

#ifdef __MMI_CHSET_GB2312__

static int 
msf_xchr_gb2312_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtGB2312ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_gb2312 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToGB2312((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

#endif /* __MMI_CHSET_GB2312__ */

#ifdef __MMI_CHSET_HKSCS__

static int 
msf_xchr_hkscs_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtHKSCSToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_hkscs (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToHKSCS((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

#endif /* __MMI_CHSET_HKSCS__ */

#ifdef __MMI_CHSET_GB18030__

static int 
msf_xchr_gb18030_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtGB18030ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_gb18030 (const char *src, long *srcLen, char *dst, long *dstLen)
{
    return HDIa_widgetExtUTF8ToGB18030((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

#endif /* __MMI_CHSET_GB18030__ */

#ifdef __MMI_CHSET_ARABIC_WIN__

static int 
msf_xchr_win1256_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1256ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1256 (const char *src, long *srcLen, char *dst, long *dstLen)
{
    return HDIa_widgetExtUTF8ToWin1256((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

#endif /* __MMI_CHSET_ARABIC_WIN__ */

#ifdef __MMI_CHSET_WESTERN_ISO__
static int
msf_xchr_latin1_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtISO_8859_1ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int
msf_xchr_utf8_to_latin1 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToISO_8859_1((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_SEURO_ISO__
static int
msf_xchr_latin3_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtISO_8859_3ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int
msf_xchr_utf8_to_latin3 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToISO_8859_3((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_BALTIC_ISO__
static int
msf_xchr_latin4_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtISO_8859_4ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int
msf_xchr_utf8_to_latin4 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToISO_8859_4((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_CYRILLIC_ISO__
static int
msf_xchr_cyrillic_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtISO_8859_5ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int
msf_xchr_utf8_to_cyrillic (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToISO_8859_5((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif


#ifdef __MMI_CHSET_ARABIC_ISO__
static int
msf_xchr_arabic_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtISO_8859_6ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int
msf_xchr_utf8_to_arabic (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToISO_8859_6((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_GREEK_ISO__
static int
msf_xchr_greek_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtISO_8859_7ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int
msf_xchr_utf8_to_greek (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToISO_8859_7((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_TURKISH_ISO__
static int
msf_xchr_latin5_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtISO_8859_9ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int
msf_xchr_utf8_to_latin5 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToISO_8859_9((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif


#ifdef __MMI_CHSET_NORDIC_ISO__

static int
msf_xchr_latin6_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtISO_8859_10ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int
msf_xchr_utf8_to_latin6 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToISO_8859_10((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_CEURO_WIN__
static int 
msf_xchr_win1250_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1250ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1250 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToWin1250((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_CYRILLIC_WIN__
static int 
msf_xchr_win1251_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1251ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1251 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToWin1251((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_WESTERN_WIN__
static int 
msf_xchr_win1252_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1252ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1252 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToWin1252((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_GREEK_WIN__

static int 
msf_xchr_win1253_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1253ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1253 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToWin1253((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif


#ifdef __MMI_CHSET_TURKISH_WIN__
static int 
msf_xchr_win1254_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1254ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1254 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToWin1254((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_HEBREW_WIN__
static int 
msf_xchr_win1255_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1255ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1255 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToWin1255((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_BALTIC_WIN__
static int 
msf_xchr_win1257_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1257ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1257 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToWin1257((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_VIETNAMESE_WIN___
static int 
msf_xchr_win1258_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtWin1258ToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_win1258 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToWin1258((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_THAI_WINDOWS__
static int
msf_xchr_windows874_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtEncXToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_THAI_WIN) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_windows874 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToEncX((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_THAI_WIN) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_PERSIAN_CP1097__
static int
msf_xchr_cp1097_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtEncXToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_PERSIAN_CP1097) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_cp1097 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToEncX((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_PERSIAN_CP1097) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_PERSIAN_CP1098__
static int
msf_xchr_cp1098_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtEncXToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_PERSIAN_CP1098) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_cp1098 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToEncX((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_PERSIAN_CP1098) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_SJIS__
static int
msf_xchr_Shift_JIS_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtEncXToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_SJIS) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_Shift_JIS (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToEncX((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_SJIS) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_UTF7__
static int
msf_xchr_utf7_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtEncXToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_UTF7) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_utf7 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToEncX((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_UTF7) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_KOI8_R__
static int
msf_xchr_KOI8R_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtEncXToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_KOI8_R) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_KOI8R (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToEncX((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_KOI8_R) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_TIS_620__
static int
msf_xchr_TIS620_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtEncXToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_TIS_620) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_TIS620 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToEncX((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_TIS_620) ? 0 : -1;
}
#endif

#ifdef __MMI_CHSET_EUCKR__
static int
msf_xchr_EUCKR_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtEncXToUTF8((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_EUCKR) ? 0 : -1;
}

static int 
msf_xchr_utf8_to_EUCKR (const char *src, long *srcLen, char *dst, long *dstLen)
{
	return HDIa_widgetExtUTF8ToEncX((const kal_uint8 *)src, (kal_int32*)srcLen, (kal_uint8*) dst, (kal_int32*)dstLen, WIDGET_CHSET_EUCKR) ? 0 : -1;
}
#endif
#endif /* WAP_SUPPORT */
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


