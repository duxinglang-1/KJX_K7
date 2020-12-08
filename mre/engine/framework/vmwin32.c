/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * vmwin32.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * permng
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef WIN32

#include "vmpromng.h"
#include "vmpromnginner.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "WTYPES.H"
#include "osc_type.h"
#include "osc_func.h"

typedef struct _vsm_node
{
	HINSTANCE hinstDLM; 
	VMINT r9;
}vsm_node;

vsm_node vm_vsm_list[10] = {0};

int g_r9[10];
int g_current = 0;

#define  MAX_LEN_FILE_NAME           			(260)


/*****************************************************************************
 * FUNCTION
 *  vm_jump_mreapp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_param_addr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_jump_vreapp(unsigned int init_param_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	typedef int (_cdecl *vm_entry_fp)(unsigned int symtab);
	char name[MAX_LEN_FILE_NAME * 2 + 1];
	int length;

	_vm_pcb_t* pcb =(_vm_pcb_t*)init_param_addr;
	
	memset(name,0,MAX_LEN_FILE_NAME * 2 + 1);
	
	wstrcpy(name,L"..\\..\\WIN32FS\\DRIVE_");
	length = wstrlen(name);
	name[length*2] = pcb->fullFileName[0];
	name[length*2+1] = 0;

	wstrcat(name,&pcb->fullFileName[2]);


	OSC_Sys_Schedule_Enable(0);
	pcb->hDll=LoadLibraryW(name);
	OSC_Sys_Schedule_Enable(1);

	if (pcb->hDll)
	{
		vm_entry_fp entry_point;
		entry_point = (vm_entry_fp)GetProcAddress (pcb->hDll,"vm_entry");
		entry_point((unsigned int)pcb->initParams[1]);
	}
}

void vm_release_app(_vm_pcb_t* pcb)
{
    if (pcb)
    {
        FreeLibrary(pcb->hDll);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_jump_vsm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vm_jump_vsm(VMWSTR fileName, unsigned int param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	typedef int (_cdecl *vm_entry_fp)(unsigned int symtab);
	char name[MAX_LEN_FILE_NAME * 2 + 1];
	int i = 0;
	int length;

	memset(name,0,MAX_LEN_FILE_NAME * 2 + 1);

	wstrcpy(name,L"..\\..\\WIN32FS\\DRIVE_");
	length = wstrlen(name);
	name[length*2] = fileName[0];
	name[length*2+1] = 0;

	wstrcat(name,&fileName[2]);

	for(i = 0; i<10; i++)
	{
		if(vm_vsm_list[i].hinstDLM == 0)
			break;
	}
	
	OSC_Sys_Schedule_Enable(0);
	vm_vsm_list[i].hinstDLM=LoadLibraryW(name);
	OSC_Sys_Schedule_Enable(1);

	if (vm_vsm_list[i].hinstDLM)
	{
		vm_entry_fp entry_point;
		vm_vsm_list[i].r9 = vm_get_sb();
		entry_point = (vm_entry_fp)GetProcAddress (vm_vsm_list[i].hinstDLM,"vm_entry");
		entry_point((unsigned int)param);
	}
}

void vm_release_vsm(VMINT r9)
{
	VMINT i;
	
    for (i =0; i<10; i++)
    {
    	if(r9 == vm_vsm_list[i].r9)
        {
        	FreeLibrary(vm_vsm_list[i].hinstDLM);
			vm_vsm_list[i].hinstDLM = 0;
			vm_vsm_list[i].r9 = 0;
			break;
    	}
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_jump_vso
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  VMINT
 *****************************************************************************/
VMINT vm_entry_vso(VMWSTR fileName, unsigned int param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	typedef int (_cdecl *vm_entry_fp)(unsigned int symtab);
	char name[MAX_LEN_FILE_NAME * 2 + 1];
	int i = 0;
	int length;
	HINSTANCE hinstDLO;

	memset(name,0,MAX_LEN_FILE_NAME * 2 + 1);
	
	wstrcpy(name,L"..\\..\\WIN32FS\\DRIVE_");
	length = wstrlen(name);
	name[length*2] = fileName[0];
	name[length*2+1] = 0;

	OSC_Sys_Schedule_Enable(0);
	hinstDLO=LoadLibraryW(name);
	OSC_Sys_Schedule_Enable(1);

	if (hinstDLO)
	{
		vm_entry_fp entry_point;
		entry_point = (vm_entry_fp)GetProcAddress (hinstDLO,"vm_entry");
		entry_point((unsigned int)param);
	}

	return hinstDLO;
	
}

void vm_unload_vso(unsigned int hinstDLO)
{
	if(hinstDLO>0)
	{
		FreeLibrary(hinstDLO);
	}
}

VMUINT vm_get_so_sym(unsigned int hinstDLO, char* name)
{
	return GetProcAddress (hinstDLO,name);
}


/*****************************************************************************
 * FUNCTION
 *  vm_restore_sb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sb      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_restore_sb(int sb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i = 0; i < 10; i++)
	{
		if(g_r9[i] = sb)
		{
			g_current = i;
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_sb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int vm_get_sb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_r9[g_current];
}


/*****************************************************************************
 * FUNCTION
 *  KURO_encrypt_kak
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pKakDat         [?]         
 *  nLength         [IN]        
 *  bEncrypt        [IN]        
 *  pChipId         [?]         
 * RETURNS
 *  
 *****************************************************************************/
int KURO_encrypt_kak(char* pKakDat, int nLength, int bEncrypt, char* pChipId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  KURO_RegisterAlbumKey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nAlbumKey           [IN]        
 *  bTemp               [IN]        
 *  wValidPeriod        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int KURO_RegisterAlbumKey(int nAlbumKey, int bTemp, int wValidPeriod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  KURO_UnRegisterAlbumKey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nAlbumKey       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int KURO_UnRegisterAlbumKey(int nAlbumKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  KURO_GetAlbumKeyStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nAlbumKey       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int KURO_GetAlbumKeyStatus(int nAlbumKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return 0;
}

#endif /* WIN32 */ 

