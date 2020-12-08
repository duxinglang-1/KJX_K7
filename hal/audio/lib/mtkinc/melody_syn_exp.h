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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   melody_syn_exp.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   The MIDI Synthesizer Interface
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
#ifndef _MELODY_SYN_EXP_H
#define _MELODY_SYN_EXP_H

/*
********************************************************************************
*                         INCLUDE FILES
********************************************************************************
*/
 
/*
********************************************************************************
*                         DEFINITION OF DATA TYPES
********************************************************************************
*/

typedef enum {
   SR_8K,
   SR_12K,
   SR_16K,
   SR_24K,
   SR_32K,
   SR_48K
} MELSYN_SR;

typedef enum {
   MELSYN_SUCCESS = 0,
   MELSYN_SR_ERROR,
   MELSYN_END,
   MELSYN_REQ_EVENT,
   MELSYN_OPRATION_FAIL,
   MELSYN_PARAMETER_FAIL,
   MELSYN_NOACTIVE_TONE
}MELSYN_STATUS;

typedef enum {
   MIDI_LED_ON,
   MIDI_LED_OFF,
   MIDI_VIBRATOR_ON,
   MIDI_VIBRATOR_OFF,
   MIDI_BACKLIGHT_ON,
   MIDI_BACKLIGHT_OFF
}MIDI_ExternCallBack;

/*
********************************************************************************
*                         DECLARATION OF PROTOTYPES
********************************************************************************
*/
 
/*****************************************************************************
 * FUNCTION
 *  MelSyn_GetBufferSize
 *
 * DESCRIPTION
 *  This function gets the buffers size for midi synthesizer.
 *
 * PARAMETERS
 *  InterBufSize     Internal buffer size
 *  PcmBufSize       Output PCM buffer size 
 *  sample_rate      Sample rate selection
 *  period           Period per synthesis
 *
 * RETURNS
 *  MELSYN_STATUS
 *****************************************************************************
 */
MELSYN_STATUS MelSyn_GetBufferSize(unsigned int *InterBufSize,
                                   unsigned int *PcmBufSize,
                                   MELSYN_SR    sample_rate,
                                   unsigned int period
                                   );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_Synthesis
 *
 * DESCRIPTION
 *  This function synthesizes pcm data.
 *
 * PARAMETERS
 *  hdl            Handle for Melody Synthesizer
 *  EvtBuf         MIDI Event Buffer
 *  PcmBuf         Output PCM buffer
 *  reset          0 --> Do synthesis directly; otherwise reset midi notes
 *                 before do synthesis
 *
 * RETURNS
 *  MELSYN_STATUS
 *****************************************************************************
 */
MELSYN_STATUS MelSyn_Synthesis(void *hdl,
                               char *EvtBuf,
                               char *PcmBuf,
                               int  reset
                               );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_Init
 *
 * DESCRIPTION
 *  This function initializes melody synthesizer
 *
 * PARAMETERS
 *  InterBuf         Melody Synthesizer Working Buffer
 *  sample_rate      Output Sampling Rate 
 *  maxpolyphony     The maximum polyphony of MelodySynthesizer
 *  finesynbound     When the active tones exceed the number, do coarse synthesis
 *  period           Period per synthesis        
 *  tonegain         Gain of each tone
 *  wavtab           Input Wavetable
 *  evt_hdl          Event callback handler
 *  evtcallback      Event calback function
 *  tone_hdl         Tone management handler
 *  gettone          Tone management function
 *
 * RETURNS
 *  A handle for midi synthesizer; if the parameters return (void*)0
 *****************************************************************************
 */
void* MelSyn_Init( void *InterBuf,
                   MELSYN_SR sample_rate, 
                   unsigned int maxpolyphony,
                   unsigned int finesynbound,
                   unsigned int period,
                   int tonegain,
                   unsigned char* wavtab,
                   void *evt_hdl,
                   void (*evtcallback)(void *hdl,int evt),
                   void *tone_hdl,
                   void (*gettone)(void *hdl, void *ptr, int evt)
                   );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_GetPitchTranspose
 *
 * DESCRIPTION
 *  This function returns current pitch transpose of synthesizer
 *
 * PARAMETERS
 *  None         
 *
 * RETURNS
 *  Pitch Transpose
 *****************************************************************************/

int MelSyn_GetPitchTranspose(void *hdl
                            );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_SetPitchTranspose
 *
 * DESCRIPTION
 *  This function sets pitch transpose of synthesizer
 *
 * PARAMETERS
 *  pitch     Pitch transpose (ranges from -64 ~ 64)      
 *
 * RETURNS
 *  MELSYN_STATUS
 *****************************************************************************/
MELSYN_STATUS MelSyn_SetPitchTranspose(void *hdl,
                                       signed char pitch
                                       );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_GetLevel
 *
 * DESCRIPTION
 *  This function gets volume level of synthesizer
 *
 * PARAMETERS
 *  None
 *
 * RETURNS
 *	Volume level
 *****************************************************************************/
int MelSyn_GetLevel(void *hdl
                   );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_SetLevel
 *
 * DESCRIPTION
 *  This function sets volume level of synthesizer
 *
 * PARAMETERS
 *  volume     Volume Level (ranges from 0~100)
 *
 * RETURNS
 *  MELSYN_STATUS
 *****************************************************************************/
MELSYN_STATUS MelSyn_SetLevel(void *hdl,
                              unsigned char level
                              );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_GetProgram
 *
 * DESCRIPTION
 *  This function returns the program assigned to channel
 *
 * PARAMETERS
 *  channel          Specified channel number (ranges from 0~15)
 *
 * RETURNS
 *	Instrument number / -1 if the channel number is invalid
 *****************************************************************************/
int MelSyn_GetProgram(void *hdl, 
                      unsigned char channel
                      );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_SetProgram
 *
 * DESCRIPTION
 *  This function set the program assigned to channel
 *
 * PARAMETERS
 *  channel         Specified channel number (ranges from 0~15)
 *  program         Specified Instrument (ranges from 0~127)
 *
 * RETURNS
 *	MELSYN_STATUS
 *****************************************************************************/
MELSYN_STATUS MelSyn_SetProgram(void *hdl, 
                                unsigned char channel,
                                unsigned char program);

/*****************************************************************************
 * FUNCTION
 *  MelSyn_GetVolume
 *
 * DESCRIPTION
 *  This function returns volume of a specific channel
 *
 * PARAMETERS
 *  channel          Specified channel number (ranges from 0~15)
 *
 * RETURNS
 *	Channel volume / -1 if the channel number is invalid
 *****************************************************************************/
int MelSyn_GetVolume(void *hdl, 
                     unsigned char channel
                     );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_SetVolume
 *
 * DESCRIPTION
 *  This function sets volume of a specific channel
 *
 * PARAMETERS
 *  channel          Specified channel number (ranges from 0~15)
 *  vol              Specified channel volume (ranges from 0~127)
 *
 * RETURNS
 *	MELSYN_STATUS
 *****************************************************************************/
MELSYN_STATUS MelSyn_SetVolume(void *hdl, 
                               unsigned char channel, 
                               unsigned char vol
                               );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_SetPolyphony
 *
 * DESCRIPTION
 *  This function sets maximum polyphony of melody synthesizer
 *
 * PARAMETERS
 *  polyphony            Maximum polyphony (ranges from 0~128)
 *
 * RETURNS
 *	MELSYN_STATUS
 *****************************************************************************/
MELSYN_STATUS MelSyn_SetPolyphony(void *hdl,
                                  unsigned int polyphony
                                  );

/*****************************************************************************
 * FUNCTION
 *  MelSyn_ClearEnd
 *
 * DESCRIPTION
 *  This function is used to clear EOF flag
 *
 * PARAMETERS
 *
 *
 * RETURNS
 *	None
 *****************************************************************************/
void MelSyn_ClearEnd(void *hdl 
					 );
#endif
