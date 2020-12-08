#include "vmswitch.h"
#ifdef __MRE_SAL_AUDIO__

#include "vmmacrostub.h"
#include "vmsys.h"
#include "vmkurocore.h"


/**
* Encrypt / Decrpyt kak.dat
* 
* @param pKakDat	kak data
* @param nLength	kak data length
* @param bEncrypt	if true, encrypt, or else decrpyt
*
* Note: this API will be provided by MRE
*/
VMINT vm_encrypt_kak(VMINT8* pKakDat, VMINT nLength, VMINT8 bEncrypt)
{
	return 0;
}

VMINT vm_RegisterAlbumKey(VMINT nAlbumKey, VMINT bTemp, VMINT wValidPeriod)
{
	return 0;
}

VMINT vm_UnRegisterAlbumKey(VMINT nAlbumKey)
{
	return 0;
}

VMINT vm_GetAlbumKeyStatus(VMINT nAlbumKey)
{
	return 0;
}

#endif /* __MRE_SAL_AUDIO__ */
