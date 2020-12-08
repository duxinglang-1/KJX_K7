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

/*
 * Copyright (C) Obigo AB, 2002-2005.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */







/*******************************************************************************
 *
 * Filename:
 * ---------
 * msig.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MSIG_H
#define _MSIG_H















typedef enum
{
    M_FSM_ASYNC,              
    M_FSM_COH_GET,            
    M_FSM_COH_POST,           
    M_FSM_COH_PUSH_RECEIVE,   
    M_FSM_COH_SEND,           
    M_FSM_COH_WAP,            
    M_FSM_CORE_MAIN,          
    M_FSM_FLDR_MANAGER,       
    M_FSM_MMH_HANDLER,        
    M_FSM_MMH_FETCH,          
    M_FSM_MSR_SEND,           
    M_FSM_MSR_RECEIVE,        
    M_FSM_MSR_NOTIFY,         


    M_FSM_MAX_REGS            

} MmsStateMachine;













typedef enum
{
    
    MMS_SIG_COMMON_BASE             = 1000,

    
    MMS_SIG_COMMON_TIMER_EXPIRED    = (MMS_SIG_COMMON_BASE + 1)
} MmsSignalId;

#define M_SIGNAL_SENDTO(d, sig) \
    mSignalSendTo((d), (sig), 0L, (unsigned long)0L, (unsigned long)0L, (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_I(d, sig, i) \
    mSignalSendTo((d), (sig), (i), (unsigned long)0L, (unsigned long)0L, (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_IU(d, sig, i, u) \
    mSignalSendTo((d), (sig), (i), (u), 0L, (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_IUU(d, sig, i, u1, u2) \
    mSignalSendTo((d), (sig), (i), (u1), (u2), (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_IUUU(d, sig, i, u1, u2, u3) \
    mSignalSendTo((d), (sig), (i), (u1), (u2), (u3), NULL)


#define M_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
    mSignalSendTo((d), (sig), (i), (u), (unsigned long)0L, (unsigned long)0L, (p))

#define M_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
    mSignalSendTo((d), (sig), (i), (u1), (u2), (unsigned long)0L, (p))

#define M_SIGNAL_SENDTO_IUUUP(d, sig, i, u1, u2, u3, p) \
    mSignalSendTo((d), (sig), (i), (u1), (u2), (u3), (p))

#define M_SIGNAL_SENDTO_IP(d, sig, i, p) \
    mSignalSendTo((d), (sig), (i), (unsigned long)0L, (unsigned long)0L, (unsigned long)0L, (p))

#define M_SIGNAL_SENDTO_U(d, sig, u) \
    mSignalSendTo((d), (sig), 0L, (u), (unsigned long)0L, (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
    mSignalSendTo((d), (sig), 0L, (u1), (u2), (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_UUU(d, sig, u1, u2, u3) \
    mSignalSendTo((d), (sig), 0L, (u1), (u2), (u3), NULL)

#define M_SIGNAL_SENDTO_UUP(d, sig, u1, u2, p) \
    mSignalSendTo((d), (sig), 0L, (u1), (u2), (unsigned long)0L, (p))

#define M_SIGNAL_SENDTO_UUUP(d, sig, u1, u2, u3, p) \
    mSignalSendTo((d), (sig), 0L, (u1), (u2), (u3), (p))


#define M_SIGNAL_SENDTO_UP(d, sig, u, p) \
    mSignalSendTo((d), (sig), 0L, (u), 0L, (unsigned long)0L, (p))

#define M_SIGNAL_SENDTO_P(d, sig, p) \
    mSignalSendTo((d), (sig), 0L, (unsigned long)0L, (unsigned long)0L, (unsigned long)0L, (p))




typedef struct MmsSignalStruct 
{
    struct MmsSignalStruct *next;       
    MSF_UINT32              type;       
    long                    i_param;    
    unsigned long           u_param1;   
    unsigned long           u_param2;   
	unsigned long           u_param3;   
    void                   *p_param;    
    MmsStateMachine         dst;
} MmsSignal;




typedef void MSignalFunction (MmsSignal *);




void mSignalFlush(MmsStateMachine dst, MmsSignalId id, long i_param,
    unsigned long u_param1, unsigned long u_param2, unsigned long u_param3, const void *p_param);




void mSignalInit(void);




void mSignalTerminate(void);




void mSignalProcess(void);






int mSignalQueueIsEmpty(void);




void mSignalDelete(MmsSignal *sig);




void mSignalDeregister(MmsStateMachine dst);





void mSignalRegisterDst(MmsStateMachine dst, MSignalFunction *f);




MmsSignal *mSignalSendTo(MmsStateMachine dst, MSF_UINT32 sig, long i_param,
    unsigned long u_param1, unsigned long u_param2, unsigned long u_param3, void *p_param);


#endif 


