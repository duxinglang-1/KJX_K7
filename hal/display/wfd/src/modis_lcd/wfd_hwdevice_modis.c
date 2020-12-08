/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *    wfd_hwdevice_6268.c
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file serves as the entry point to obtain all WFD devices in MTK 
 *    MT6268 series display HW devices.
 *
 * Author:
 * -------
 * -------
 *    
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 07 26 2011 zifeng.qiu
 * removed!
 *   DDv2 On Modis Check In.
 *
 * 12 23 2010 tianshu.qiu
 * removed!
 * .
 *
 * 11 18 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 * 10 25 2010 sophie.chen
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__MTK_TARGET__)
/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/
// TODO: Move to header...
#define WFD_HWDEVICE_MODIS_LCD_ID          (0)

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "wfd\inc\wfd_hwdevice.h"
#include "wfd\inc\modis_lcd\wfd_lcd_modis.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 *  Local type definitions
 ****************************************************************************/

/*****************************************************************************
 *  Local variables
 ****************************************************************************/
static WFDHWDevicePrimitivesMTK* _wfd_hwdevices[1] = {0};
static WFDErrorCode _wfd_errorcode = WFD_ERROR_NONE;

/*****************************************************************************
 *  Local function definitions
 ****************************************************************************/
static void
_wfd_hwdevice_modis_ModuleInitialize()
{
  // MoDIS
  if (NULL == _wfd_hwdevices[0])
  {
    if (WFD_ERROR_NONE != wfd_lcd_initialize(&_wfd_hwdevices[0]))
    {
      _wfd_hwdevices[0] = NULL;
    }
  }
}

/*****************************************************************************
 *  API function definitions
 ****************************************************************************/
WFDint 
WFD_HWDevice_GetIds(
  WFDint *idsList, 
  WFDint listCapacity)
{
  WFDint devCount = 0;

  if ((NULL == idsList) || (1 > listCapacity))
    return 0;

  if (NULL == _wfd_hwdevices[0])
  {
      _wfd_hwdevice_modis_ModuleInitialize();
  }

  if (NULL != _wfd_hwdevices[0]) { devCount++; }

  if ((1 <= listCapacity) && 
      (1 <= devCount))
  {
    idsList[0] = WFD_HWDEVICE_MODIS_LCD_ID;
  }

  return (devCount <= listCapacity) ? devCount : listCapacity;
}

WFDDevice 
WFD_HWDevice_CreateDevice(
  WFDint deviceId, 
  const WFDint *attribList)
{
  if ((WFD_HWDEVICE_MODIS_LCD_ID == deviceId) && 
      (NULL != _wfd_hwdevices[0]) && 
      (NULL != _wfd_hwdevices[0]->wfdCreateDevice))
  {
    return _wfd_hwdevices[0]->wfdCreateDevice(WFD_HWDEVICE_MODIS_LCD_ID, attribList);
  }

  return WFD_INVALID_HANDLE;
}

void 
WFD_HWDevice_SetError(
  WFDErrorCode err)
{
  if (WFD_ERROR_NONE == _wfd_errorcode)
  {
    _wfd_errorcode = err;
  }
}

WFDErrorCode 
WFD_HWDevice_GetError(void)
{
  WFDErrorCode err = _wfd_errorcode;
  _wfd_errorcode = WFD_ERROR_NONE;
  return err;
}

#ifdef __cplusplus
}
#endif

#endif  // #if !defined(__MTK_TARGET__)



