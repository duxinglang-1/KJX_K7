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
 *   melody_par_exp.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   The Melody Parser Interface
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MELODY_PAR_EXP_H
#define _MELODY_PAR_EXP_H

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
   FORMAT_SMF = 0,
   FORMAT_IMY,
   FORMAT_JTS,
   FORMAT_CMI,
   FORMAT_DEV
} MIDI_Format;

typedef enum {
   MELPAR_SUCCESS = 0,
   MELPAR_BADFORMAT,
   MELPAR_EOF,
   MELPAR_OPRATION_FAIL,
   MELPAR_PARAMETER_FAIL,
   MELPAR_NONSEEKABLE,
   MELPAR_TIMEUP,
   MELPAR_GETCH_FAIL
}MELPAR_STATUS;

typedef enum {
   MELPAR_FSREAD = 0,
   MELPAR_FSSKIP,
   MELPAR_FSSEEK
} MELPAR_FSREQUEST;


typedef enum{
   BUFFER_MODE = 0,
   FS_MODE
} MELPAR_INPUTMODE;
/*
********************************************************************************
*                         DECLARATION OF PROTOTYPES
********************************************************************************
*/
 
/*****************************************************************************
 * FUNCTION
 *  MelPar_GetBufferSize
 *
 * DESCRIPTION
 *  This function gets the buffers size for midi synthesizer.
 *
 * PARAMETERS
 *  InterBufSize     Internal buffer size
 *  OuputBufSize     Output Midi event buffer size 
 *
 * RETURNS
 *  MELPAR_STATUS
 *****************************************************************************
 */
MELPAR_STATUS MelPar_GetBufferSize(int *InterBufSize, 
                                   int *OuputBufSize
                                   );

/*****************************************************************************
 * FUNCTION
 *  MelPar_Init
 *
 * DESCRIPTION
 *  This function initializes midi synthesizer
 *
 * PARAMETERS
 *  InterBuf          Internal working buffer
 *  MelodyBuf         Input melody file buffer
 *  filelen           Input melody file length
 *  mode              Input melody mode
 *  inst              Default instrument for jts/imy
 *  maxpolyphony      The maximum polyphony of Melody Parser (for sp-midi)
 *  data_hdl          Data handle (used in FS_MODE)
 *  getdata           Callback function to get melody data (used in FS_MODE)
 *  channel_hdl       Channel handle
 *  getchannel        Callback function to get the permission of a channel
 *
 * RETURNS
 *  A handle for melody parser; if the parameters or the file contents 
 *  are invalid, return (void*)0
 *****************************************************************************
 */
void* MelPar_Init( void* InterBuf,
                   unsigned char* InputBuf,
                   unsigned int filelen, 
                   MELPAR_INPUTMODE mode, 
                   unsigned int inst,
                   unsigned int maxpolyphony,
                   void* data_hdl,
                   void (*getdata)(void *hdl,int evt, unsigned char* ptr, unsigned int len),
                   void* channel_hdl,
                   void (*getchannel)(void *hdl, unsigned char* chid, unsigned char per)
                   );
/*****************************************************************************
 * FUNCTION
 *  MelPar_Parse
 *
 * DESCRIPTION
 *  This function parses melody data into midi events
 *
 * PARAMETERS
 *  period        Block period to parse
 *  delta_ms      Parsed period 
 *  evtbuf        Parsed midi event buffer
 *  evtlen        Parsed midi event length in bytes
 *
 * RETURNS
 *  MELPAR_STATUS
 *****************************************************************************
 */
MELPAR_STATUS MelPar_Parse( void *hdl,
                            int period,
                            int *delta_ms,
                            char* evtbuf,
                            int *evtlen
                            );

/*****************************************************************************
 * FUNCTION
 *  MelPar_Seek
 *
 * DESCRIPTION
 *  This function seeks source file to desired play time
 *
 * PARAMETERS
 *  start_time         desired seek time
 *
 * RETURNS
 *  MELPAR_STATUS
 *****************************************************************************
 */
MELPAR_STATUS MelPar_Seek(void *hdl, 
                          unsigned int start_time
                          );

/*****************************************************************************
 * FUNCTION
 *  MelPar_GetDuration
 *
 * DESCRIPTION
 *  This function gets the duration of source file
 *
 * PARAMETERS
 *  None
 *
 * RETURNS
 *  Duration of source file
 *****************************************************************************
 */
int MelPar_GetDuration( void *hdl
                        );

/*****************************************************************************
 * FUNCTION
 *  MelPar_GetParsedTime
 *
 * DESCRIPTION
 *  This function gets parsed time (parser view) of playback
 *
 * PARAMETERS
 *  None
 *
 * RETURNS
 *  Current parsed time
 *****************************************************************************/
int MelPar_GetParsedTime( void *hdl
                          );

/*****************************************************************************
 * FUNCTION
 *  MelPar_SetStopTime
 *
 * DESCRIPTION
 *  This function sets stop time of playback
 *
 * PARAMETERS
 *  stoptime     Stopped time of MIDI playback         
 *
 * RETURNS
 *  MELPAR_STATUS
 *****************************************************************************/
MELPAR_STATUS MelPar_SetStopTime( void *hdl,
                                  unsigned int stoptime
                                  );

/*****************************************************************************
 * FUNCTION
 *  MelPar_GetPlayRate
 *
 * DESCRIPTION
 *  This function gets play rate of parser
 *
 * PARAMETERS
 *  None
 *
 * RETURNS
 *   Play rate
 *****************************************************************************/
int MelPar_GetPlayRate( void *hdl
                        );

/*****************************************************************************
 * FUNCTION
 *  MelPar_SetPlayRate
 *
 * DESCRIPTION
 *  This function sets play rate of parser
 *
 * PARAMETERS
 *  Rate         Play rate         
 *
 * RETURNS
 *   MELPAR_STATUS
 *****************************************************************************/
MELPAR_STATUS MelPar_SetPlayRate( void *hdl,
                                  int  rate
                                  );

/*****************************************************************************
 * FUNCTION
 *  MelPar_GetTsRate
 *
 * DESCRIPTION
 *  This function sets time-stretch rate of parser
 *
 * PARAMETERS
 *  Rate         Play rate         
 *
 * RETURNS
 *   MELPAR_STATUS
 *****************************************************************************/
int MelPar_GetTsRate( void *hdl
                      );

/*****************************************************************************
 * FUNCTION
 *  MelPar_SetTsRate
 *
 * DESCRIPTION
 *  This function sets time stretch rate of parser
 *
 * PARAMETERS
 *  Rate         Time stretch rate
 *
 * RETURNS
 *   MELPAR_STATUS
 *****************************************************************************/
MELPAR_STATUS MelPar_SetTsRate(void *hdl,
                               int  rate
                               );

/*****************************************************************************
 * FUNCTION
 *  MelPar_GetTempo
 *
 * DESCRIPTION
 *  This function gets tempo of parser
 *
 * PARAMETERS
 *  None         
 *
 * RETURNS
 *   Tempo of parser
 *****************************************************************************/
int MelPar_GetTempo( void *hdl
                     );

/*****************************************************************************
 * FUNCTION
 *  MelPar_SetTempo
 *
 * DESCRIPTION
 *  This function sets tempo of parser
 *
 * PARAMETERS
 *  tempo     Tempo of synthesizer         
 *
 * RETURNS
 *   MELPAR_STATUS
 *****************************************************************************/
MELPAR_STATUS MelPar_SetTempo( void *hdl,
                               int  tempo
                               );

/*****************************************************************************
 * FUNCTION
 *  MelPar_isSpMidi
 *
 * DESCRIPTION
 *  This function checks if the smf file contains sp-midi contents
 *
 * PARAMETERS
 *  None
 *
 * RETURNS
 *  1 - Ture / 0 - False
 *****************************************************************************/
int MelPar_isSpMidi( void *hdl
                    );

/*****************************************************************************
 * FUNCTION
 *  MelPar_QueryFormat
 *
 * DESCRIPTION
 *  This function returns the melody format
 *
 * PARAMETERS
 *  None
 *
 * RETURNS
 *  melody format
 *****************************************************************************/
MIDI_Format MelPar_QueryFormat(void *hdl
                               );

/*****************************************************************************
 * FUNCTION
 *  MelPar_ResetSynthChannel
 *
 * DESCRIPTION
 *  This function resets synthesizer channel for multiple parser, 
 *  single synthesizer framework
 *
 * PARAMETERS
 *  None
 *
 * RETURNS
 *  None
 *****************************************************************************/
void MelPar_ResetSynthChannel(void *hdl
                               );

/*****************************************************************************
 * FUNCTION
 *  MelPar_SetVolumeLevel
 *
 * DESCRIPTION
 * PARAMETERS
 *  volume level
 *
 * RETURNS
 *  MELPAR_STATUS
 *****************************************************************************/
MELPAR_STATUS MelPar_SetVolumeLevel(void *hdl,
                                    unsigned char vol
                                    );

/*****************************************************************************
 * FUNCTION
 *  MelPar_GetVolumeLevel
 *
 * DESCRIPTION
 * PARAMETERS
 *  None
 *
 * RETURNS
 *  Volume level
 *****************************************************************************/
unsigned char MelPar_GetVolumeLevel(void *hdl
                                    );
#endif
