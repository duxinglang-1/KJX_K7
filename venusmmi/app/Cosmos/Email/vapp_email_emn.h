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
 *  vapp_email_emn.h
 *
 * Project:
 * --------
 *  COSMOS Email EMN
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_EMAIL_EMN_H
#define VAPP_EMAIL_EMN_H

typedef enum
{
    VAPP_EMAIL_EMN_STATE_NONE,
    VAPP_EMAIL_EMN_STATE_PENDING,
    VAPP_EMAIL_EMN_STATE_RUNNING
} VappEmailEmnItemStateEnum;

typedef struct
{
    EMAIL_ACCT_ID acctId;
    VappEmailEmnItemStateEnum state; 
} VappEmailEmnRecItemStruct;

typedef struct
{
    VfxU32 acctNum;
    VappEmailEmnRecItemStruct acctList[MMI_EMAIL_MAX_ACCTS];
} VappEmailEmnRecTableStruct;

typedef enum
{
    VAPP_EMAIL_EMN_TYPE_NONE = 0x00,
    VAPP_EMAIL_EMN_TYPE_AUTO_CHECK = 0x01,
    VAPP_EMAIL_EMN_TYPE_EMN = 0x02,
    VAPP_EMAIL_EMN_TYPE_TOTAL
} VappEmailEmnTypeEnum;

typedef struct
{
    EMAIL_ACCT_ID acctId;
    VfxU8 type;
} VappEmailEmnReqItemStruct;

typedef struct
{
    VappEmailEmnReqItemStruct reqList[MMI_EMAIL_MAX_ACCTS];
    VfxU32 reqNum;
} VappEmailEmnReqTableStruct;

typedef struct
{
    VappEmailEmnRecTableStruct recTable;
    VappEmailEmnReqTableStruct reqTable;
} VappEmailEmnCntxStruct;


class VappEmailEmn : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappEmailEmn);

private:
    static VappEmailEmnCntxStruct vappEmnCntx;
    VappEmailEmnCntxStruct *emnCntx;

private:
    VappEmailEmn();
    virtual void onInit();

    void readRecordFile(void);
    void updateRecordFile(void);
    void addRecord(EMAIL_ACCT_ID acctId);
    void removeRecord(EMAIL_ACCT_ID acctId);

    void setRecordState(EMAIL_ACCT_ID acctId, VappEmailEmnItemStateEnum state);
    VappEmailEmnItemStateEnum getRecordState(EMAIL_ACCT_ID acctId);

    void addReq(EMAIL_ACCT_ID acctId, VappEmailEmnTypeEnum type);
    void removeReq(EMAIL_ACCT_ID acctId);

    void emnSchlRun(void);

    static void autoCheckNotifyCbFunc(EMAIL_ACCT_ID acctId);
    static void emnNotifyCbFunc(EMAIL_ACCT_ID acctId);

    static void emnSchlCbFunc(void);

    void onAcctNwkDone(EMAIL_ACCT_ID acctId, VappEmailNwkDoneEnum nwkType, VappEmailResStruct result);
    void onAcctNwkStop(VappEmailMgrStopCauseEnum stopCause);
    void onAcctDelete(EMAIL_ACCT_ID acctId);

public:
    void startService(void);
    void stopService(void);
};

#endif /* VAPP_EMAIL_EMN_H */
