#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_sig.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Internal signal queue.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_sig.h
 *
 * Description:
 *   Internal signal queue.
 *
 */
#ifndef _bam_sig_h

#define _bam_sig_h

/*********************************************
 * Signal destinations.
 *********************************************/

#define BAM_SIG_DEST_MAIN 0
#define BAM_SIG_DEST_REGISTRY 1

#define BAM_SIG_NUM_OF_DESTINATIONS 2

/**************************************************
 * Macros
 **************************************************/

#define BAM_SIGNAL_SENDTO(d, sig)                    \
    bam_signal_sendto ((d), (sig), 0, 0, 0, 0, NULL)

#define BAM_SIGNAL_SENDTO_I(d, sig, i)               \
    bam_signal_sendto ((d), (sig), i, 0, 0, 0, NULL)

#define BAM_SIGNAL_SENDTO_U(d, sig, u)               \
    bam_signal_sendto ((d), (sig), 0, 0, (u), 0, NULL)

#define BAM_SIGNAL_SENDTO_II(d, sig, i1, i2)         \
    bam_signal_sendto ((d), (sig), (i1), (i2), 0, 0, NULL)

#define BAM_SIGNAL_SENDTO_IU(d, sig, i, u)           \
    bam_signal_sendto ((d), (sig), (i), 0, (u), 0, NULL)

#define BAM_SIGNAL_SENDTO_UU(d, sig, u1, u2)         \
    bam_signal_sendto ((d), (sig), 0, 0, (u1), (u2), NULL)

#define BAM_SIGNAL_SENDTO_IUU(d, sig, i, u1, u2)     \
    bam_signal_sendto ((d), (sig), (i), 0, (u1), (u2), NULL)

#define BAM_SIGNAL_SENDTO_P(d, sig, p)               \
    bam_signal_sendto ((d), (sig), 0, 0, 0, 0, (p))

#define BAM_SIGNAL_SENDTO_IP(d, sig, i, p)           \
    bam_signal_sendto ((d), (sig), (i), 0, 0, 0, (p))

#define BAM_SIGNAL_SENDTO_IUP(d, sig, i, u, p)       \
    bam_signal_sendto ((d), (sig), (i), 0, (u), 0, (p))

#define BAM_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
    bam_signal_sendto ((d), (sig), (i), 0, (u1), (u2), (p))

/****************************************
 * Type definitions:
 ****************************************/

typedef struct _bam_signal_struct
{
    struct _bam_signal_struct *next;
    int dst;            /* The destination for this signal */
    int type;           /* Which signal it is */
    long int i_param1;  /* Parameters: */
    long int i_param2;
    unsigned long int u_param1;
    unsigned long int u_param2;
    void *p_param;
} bam_signal_struct;

/*
 * This kind of function is called when a signal is delivered.
 */
typedef void bam_signal_function_t(bam_signal_struct *);

/****************************************
 * Exported functions:
 ****************************************/

/*
 * Initialize the signal module.
 */
extern void bam_signal_init(void);

/*
 * Terminate the signal module.
 */
extern void bam_signal_terminate(void);

/*
 * Process the first signal in the signal queue.
 */
extern void bam_signal_process(void);

/*
 * Return TRUE if the global signal queue is empty,
 * FALSE otherwise.
 */
extern int bam_signal_queue_is_empty(void);

/*
 * Delete a signal and its parameters.
 */
extern void bam_signal_delete(bam_signal_struct *sig);

/*
 * Register the function "f" to be called when a signal
 * is delivered to destination "dst".
 */
extern void bam_signal_register_dst(int dst, bam_signal_function_t *f);

/*
 * Remove the registered function for destination "dst".
 */
extern void bam_signal_deregister(int dst);

/*
 * Add a new signal to the end of the global queue.
 */
extern void
bam_signal_sendto(
    int dst,
    int sig,
    long int i_param1,
    long int i_param2,
    unsigned long int u_param1,
    unsigned long int u_param2,
    void *p_param);

/*
 * Add an old signal to the beginning of the queue.
 */
extern void bam_signal_prepend(bam_signal_struct *sig);

#endif /* _bam_sig_h */


#endif /*OBIGO_Q03C_BROWSER*/