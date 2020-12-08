/*  Copyright Statement:
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_fmgr_cp.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_fmgr.h"
#include "app_str.h"
//#include "mmi_rp_app_venus_filemanager_def.h"
#include "vapp_fmgr_cp.h"
#include "mmi_rp_all_defs.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "fs_gprot.h"
#include "FileMgrSrvGProt.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappFileNameEditorPopup", VappFileNameEditorPopup, VcpInputPopup);

void VappFileNameEditorPopup::onInit()
{
	VcpInputPopup::onInit();

    m_path = NULL;
	m_ext = NULL;
	m_isVolumeLabel = VFX_FALSE;
    
	setAutoDestory(VFX_FALSE);
	
	/* Set characters filter */
	VsrvInputBinding inputBinding(
		IMM_INPUT_TYPE_SENTENCE,
		IME_DISABLE_NEW_LINE_SYMBOL,
		IME_INPUT_STYLE_NONE,
		getInputbox()->m_editing
		);
	inputBinding.setDisabledChars(VFX_WSTR_MEM((VfxWChar*)srv_fmgr_path_get_invalid_chars()));
	getInputbox()->setIME(inputBinding);
}

void VappFileNameEditorPopup::onDeinit()
{
    if (m_ext != NULL)
    {
        VFX_FREE_MEM(m_ext);
    }

    if (m_path != NULL)
    {
        VFX_FREE_MEM(m_path);
    }

    VcpInputPopup::onDeinit();
}

void VappFileNameEditorPopup::setPath(VfxWString &path)
{
    if (path.isNull() || path.isEmpty())
    {
        return;
    }

    if (m_path == NULL)
    {
        VFX_ALLOC_MEM(m_path, VAPP_FMGR_FILE_PATH_LEN, this);
        memset(m_path, 0, VAPP_FMGR_FILE_PATH_LEN);
    }

    app_ucs2_strncpy((kal_int8*)m_path, (const kal_int8*)path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
}

void VappFileNameEditorPopup::setExt(VfxS8 *extension_name)
{
    if (extension_name == NULL)
    {
        return;
    }
    
    VfxS32 ext_buffer_size = (SRV_FMGR_PATH_MAX_FILE_EXT_LEN+1)*ENCODING_LENGTH;
    if (m_ext == NULL)
    {
        VFX_ALLOC_MEM(m_ext, ext_buffer_size, this);
        memset(m_ext, 0, ext_buffer_size);
    }

    app_ucs2_strncpy((kal_int8*)m_ext, (const kal_int8*)extension_name, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
}

void VappFileNameEditorPopup::setIsVolumeLabel(VfxBool isVolumeLabel)
{
    m_isVolumeLabel = isVolumeLabel;
}

VfxS32 VappFileNameEditorPopup::isValidFilePath()
{
    VfxS8 *buffer = NULL;
	VfxS8 *tmp_buffer = NULL;
	VfxS32 len = 0, i = 0;
	VfxS32 fs_ret = 0;
	VfxS32 maxLen = getInputbox()->getMaxLength();
	VfxWChar *input_buffer = NULL, *ptr_src = NULL, *ptr_trg = NULL;
	VfxWString name = getText();

	do {
		if (name.isNull() && name.isEmpty())
		{
			fs_ret = FS_INVALID_FILENAME;
			break;
		}
		
		VFX_ALLOC_MEM(tmp_buffer, VENUS_FMGR_FILENAME_BUF_LEN, this);
		memset(tmp_buffer, 0, VENUS_FMGR_FILENAME_BUF_LEN);
		input_buffer = (VfxWChar*)tmp_buffer;
		app_ucs2_strncpy((kal_int8*)input_buffer, (const kal_int8*) name.getBuf(), SRV_FMGR_PATH_MAX_FILE_NAME_LEN);

        ptr_src = NULL;				
		len = name.getLength();
		i = 0;
        if (m_isVolumeLabel)
        {
            /* Remove starting "." */
            while (i < len && input_buffer[i] == '.')
    		{
    		    fs_ret = FS_INVALID_FILENAME;
    			i++;
    		}
        }
        else
        {
    		/* Remove starting "." and " " */
    		while (i < len &&
    			  (input_buffer[i] == '.' ||
    			   input_buffer[i] == ' '))
    		{
    		    if (input_buffer[i] == '.')
                {
                    fs_ret = FS_INVALID_FILENAME;
                }
    			i++;
    		}
        }
        
		if (i > 0)
		{
			if (i == len)
			{
			    fs_ret = FS_INVALID_FILENAME;
				input_buffer[0]	= 0;				
				break;
			}
			else
			{
				ptr_trg = input_buffer;
				ptr_src = input_buffer + i;
				/* Update the buffer */
				while (*ptr_src)
				{
					*ptr_trg = *ptr_src;
					ptr_trg++;
					ptr_src++;
				}
				*ptr_trg = 0;

				setText(VfxWString().loadFromMem((VfxWChar*)input_buffer), maxLen);
				getInputbox()->setCursorIndex(app_ucs2_strlen((const kal_int8*)input_buffer));
				
                if (fs_ret < 0)
                {
                    break;
                }
			}
		}

		/* Remove trailing space */
        if (m_ext == NULL)
        {
		    i = len = app_ucs2_strlen((const kal_int8*)input_buffer);
		    while (i > 0 && (input_buffer[(i-1)] == ' ' || input_buffer[(i-1)] == '.'))
            {
                i--;
            }

            if (i != len && i >= 0)
            {
                input_buffer[i] = 0;                    

                setText(VfxWString().loadFromMem((VfxWChar*)input_buffer), maxLen);
				getInputbox()->setCursorIndex(app_ucs2_strlen((const kal_int8*)input_buffer));
            }
        }
		/* Check for empty */
        if (!input_buffer[0])
        {
            if (m_isVolumeLabel)
            {
                fs_ret = FS_INVALID_FILENAME;
            }
            break;
        }

		/* Check for file name validation */
        VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
        memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);

        MMI_BOOL isValid = MMI_TRUE;
        
        if (m_ext != NULL)
        {
            app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)input_buffer, SRV_FMGR_PATH_MAX_LEN);
            len = SRV_FMGR_PATH_MAX_LEN - app_ucs2_strlen((const kal_int8*)buffer);
            if (len > 0)
            {
                app_ucs2_strncat((kal_int8*)buffer, (const kal_int8*)L".", (len));
    		    app_ucs2_strncat((kal_int8*)buffer, (const kal_int8*)m_ext, (len-1));
            }

            isValid = srv_fmgr_path_is_filename_valid((const WCHAR*)buffer);
        }
        else
        {
            if (m_isVolumeLabel)
            {
                if (FS_CheckVolumeLabel((WCHAR*)input_buffer) != FS_NO_ERROR)
                {
                    isValid = MMI_FALSE;
                }
            }
            else
            {
                isValid = srv_fmgr_path_is_filename_valid((const WCHAR*)input_buffer);
            }
        }
        
        if (!isValid)
        {
            fs_ret = FS_INVALID_FILENAME;
            break;
        }

		if (m_path != NULL)
		{
			len = 0;

			len += app_ucs2_strlen(m_path);
			len += getText().getLength();
			if (m_ext != NULL)
			{
				len += (app_ucs2_strlen((const kal_int8*)m_ext)+1); /* add one for "." */
			}

            /* In order to let user can enter created folder, the len limitation set 258.
               Let file len and folder len is the same as here */
			if (len > (SRV_FMGR_PATH_MAX_LEN-1))
			{
				fs_ret = FS_PATH_OVER_LEN_ERROR;
				break;
			}

            memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
			app_ucs2_strcpy(buffer, (const kal_int8*)m_path);
			app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)input_buffer);
            if (m_ext != NULL)
            {
                app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)L".");
			    app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)m_ext);
            }
			if (srv_fmgr_fs_path_exist((const WCHAR*)buffer) == 0)
			{
				fs_ret = FS_FILE_EXISTS;
				break;
			}
		}
		else if (m_isVolumeLabel)
        {
        	VfxBool isUCS2 = VFX_FALSE;
			
        	len = app_ucs2_strlen((const kal_int8*)input_buffer);
			
			for (i = 0; i < len; i++)
			{
				if (!VCP_TEXT_IS_ASCII_CHAR(input_buffer[i]))
				{
					isUCS2 = VFX_TRUE;
					break;
				}
			}

			VfxS32 maxLen = 0;
			
			if (isUCS2)
			{
				/* Max length is (SRV_FMGR_DRV_MAX_VOLUME_SIZE - 1)/2 */
				maxLen = (SRV_FMGR_DRV_MAX_VOLUME_SIZE - 1)/2;
			}
			else
			{
				maxLen = (SRV_FMGR_DRV_MAX_VOLUME_SIZE - 1);
			}

			if (len > maxLen)
			{
				fs_ret = FS_PATH_OVER_LEN_ERROR;
			}
        }
	} while(0);

    if (buffer != NULL)
    {
    	VFX_FREE_MEM(buffer);
    }
    
    if (tmp_buffer != NULL)
    {
	    VFX_FREE_MEM(tmp_buffer);
    }

	return fs_ret;
}
