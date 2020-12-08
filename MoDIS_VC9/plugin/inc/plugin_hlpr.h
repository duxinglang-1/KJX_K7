/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  plugin_hlpr.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This module contains the definitions for plugin_hlpr.cpp
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/
#ifndef PLUGIN_HELPER_H
#define PLUGIN_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * Share memory helper API
 *****************************************************************************/
#define SMHandle void*

//Create a Plug-in for MMI
SMHandle CreateShareMem(const char* lpszName, unsigned int uiSize);
//Destroy the Plug-in
void DestroyShareMem(SMHandle hPlugin);
//Read data from Plug-in
int Read(SMHandle hPlugin, void* lpData, unsigned int uiSize);
//Write data into Plug-in
int Write(SMHandle hPlugin, const void* lpData, unsigned int uiSize);

#ifdef __cplusplus
}
#endif

#endif 
