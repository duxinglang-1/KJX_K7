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
*  ShareMemory.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This module contains the definitions for ShareMemory.cpp
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
#ifndef SHARE_MEMORY_H
#define SHARE_MEMORY_H

#pragma warning (disable:4786)

#include <windows.h>

class CShareMapping
{
private:
	HANDLE	m_hMap;
	char	*m_pSharedData;
	int		m_size;
public:
	CShareMapping();
	~CShareMapping();

	bool CreateShare(const char* ID, const int &size);
	void DestroyShare();
	int Write(const void *data, const int &size);
	int Read(void *data, const int &size);
};

#endif
