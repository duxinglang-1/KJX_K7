/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vtst_rt_archive.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Archive
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

extern "C" {
#include "kal_public_api.h"
}

#include "vtst_rt_main.h"
#include "stdlib.h"

#include "vfx_datatype.h"
#include "vfx_archive.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "string.h"
#include "vfx_basic_type.h"
#include "vfx_app_cat_scr.h"

#define VTST_DATA_SIZE  (10000)
typedef VfxU16 TestDataType;

/***************************************************************************** 
 * ArchiveTest Implementation
 *****************************************************************************/

class VtstRtArchive : public VtstRtScr
{
// Variable
private:
    VfxU8 *m_archivePtr;        // archived data
    VfxU32 m_archiveSize;       // archived data size
    VfxMemArchiveSource *m_archiveSrc;  // archive source
    TestDataType *m_dataArray;  // data for archive read/write test

// Constructor / Destructor
public:
    VtstRtArchive() : m_archivePtr(NULL), m_archiveSize(0) 
    {
    }

    ~VtstRtArchive()
    {
        if (m_dataArray)
        {
            VFX_FREE_MEM(m_dataArray);
        }
        if (m_archivePtr)
        {
            VFX_FREE_MEM(m_archivePtr);
        }
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Archive Test"));

        int i;
        VFX_ALLOC_MEM(m_dataArray, sizeof(TestDataType)*VTST_DATA_SIZE, this);
        for (i=0; i<VTST_DATA_SIZE; i++)
        {
            m_dataArray[i] = i;
        }        
    }

    virtual int start()
    {
        return 5; // no phase
    }

    VfxArchive * createArchive(void)
    {
        VfxArchive *ar;
        VFX_OBJ_CREATE(ar, VfxArchive, this);
        VFX_OBJ_CREATE(m_archiveSrc, VfxMemArchiveSource, ar);
        ar->setSource(m_archiveSrc);
        return ar;
    }
    
    void closeArchive(VfxArchive *ar)
    {
        VFX_OBJ_CLOSE(ar);            
    }
    
    void detachBuffer(void)
    {
        m_archiveSrc->detachBuffer(&m_archivePtr, &m_archiveSize);
    }
    
    void attachBuffer(void)
    {
        m_archiveSrc->attachBuffer(m_archivePtr, m_archiveSize);
        m_archivePtr = NULL;   
    }

    void singleWrite()
    {
        setTitle(VFX_WSTR("single write"));

        VfxArchive *ar = createArchive();

        VfxU32 idx = getRand(VTST_DATA_SIZE);
        ar->write((VfxU8 *)m_dataArray, sizeof(TestDataType));
        detachBuffer();
        check(m_archiveSize == sizeof(TestDataType), VFX_WSTR("single write fail"));
        
        closeArchive(ar);
    }

    void singleRead()
    {
        setTitle(VFX_WSTR("single read"));

        VfxArchive *ar = createArchive();
        attachBuffer();

        VfxU16 *tmp;
        VFX_ALLOC_MEM(tmp, m_archiveSize, this);
        ar->read((VfxU8*)tmp, m_archiveSize);
        check(!memcmp(tmp, m_dataArray, m_archiveSize), VFX_WSTR("single read : read != written"));
        VFX_FREE_MEM(tmp);        
        
        closeArchive(ar);
    }

    void loopWrite()
    {
        setTitle(VFX_WSTR("loop write"));

        VfxArchive *ar = createArchive();

        int i;
        for (i=0; i<VTST_DATA_SIZE; i++)
        {
            ar->write((VfxU8 *)&m_dataArray[i], sizeof(TestDataType));
        }
        detachBuffer();
        check(m_archiveSize == sizeof(TestDataType)*VTST_DATA_SIZE, VFX_WSTR("loop write fail"));
        
        closeArchive(ar);
    }


    void loopRead()
    {
        setTitle(VFX_WSTR("loop read"));

        VfxArchive *ar = createArchive();
        attachBuffer();

        VfxU16 *tmp;
        VFX_ALLOC_MEM(tmp, m_archiveSize, this);

        int i, iMax = m_archiveSize/sizeof(TestDataType);
        for (i=0; i<iMax; i++)
        {
            ar->read((VfxU8*)&tmp[i], sizeof(TestDataType));
        }
        check(!memcmp(tmp, m_dataArray, m_archiveSize), VFX_WSTR("loop read : read != written"));
        VFX_FREE_MEM(tmp);        
        
        closeArchive(ar);
    }       

    void basicType()
    {
        setTitle(VFX_WSTR("basic type"));

        // write basic type
        VfxArchive *ar = createArchive();

        VfxPoint pt(123, 456), pt2;
        ar->writePoint(pt);

        VfxFPoint fpt(78.0, 90.0), fpt2;
        ar->writeFPoint(fpt);

        VfxSize sz(240, 320), sz2;
        ar->writeSize(sz);

        VfxRect rect(pt, sz), rect2;
        ar->writeRect(rect);
        
        VfxColor clr(111), clr2;
        ar->writeColor(clr);

        detachBuffer();
        closeArchive(ar);

        // read basic type
        ar = createArchive();
        attachBuffer();

        ar->readPoint(pt2);
        check(pt2 == pt, VFX_WSTR("VfxPoint"));

        ar->readFPoint(fpt2);
        check(fpt2 == fpt, VFX_WSTR("VfxFPoint"));

        ar->readSize(sz2);
        check(sz2 == sz, VFX_WSTR("VfxSize"));

        ar->readRect(rect2);
        check(rect2 == rect, VFX_WSTR("VfxRect"));

        ar->readColor(clr2);
        check(clr2 == clr, VFX_WSTR("VfxColor"));

        closeArchive(ar);       
    }       
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
            case 0:
                singleWrite();
                break;

            case 1:
                singleRead();
                break;

            case 2:
                loopWrite();
                break;

            case 3:
                loopRead();
                break;

            case 4:
                basicType();
                break;
               
            default:
                return VTST_RT_END_TESTCASE;

        }
               
        return 100;
    }

    VfxU32 getRand(VfxU32 normalizeTo)
    {
        VfxU32 tick;
        kal_get_time(&tick);
        srand(tick);
        return rand() % normalizeTo;
    }
};


VtstTestResultEnum vtst_rt_archive(VfxU32 param)
{
    VTST_START_SCRN(VtstRtArchive);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__


