/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   l1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6260
 *
 * Description:
 * ------------
 *   MT6260 RF constance definition
 *
 * Author:
 * -------
 *
 *
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */

#if !defined(MT6260RF_RF)
   #error "rf files mismatch with compile option!"
#endif

/*MT6260RF*/
/*MT6260RF*/ /*--------------------------------------------------------*/
/*MT6260RF*/ /*   Event Timing Define                                  */
/*MT6260RF*/ /*--------------------------------------------------------*/
/*MT6260RF*/ #define  QB_SR0                     213 /* QB_PR1 and QB_PR2 should be larger than (QB_SR0 - 30) */
/*MT6260RF*/ #define  QB_SR1                     140
/*MT6260RF*/ #define  QB_SR2                      70 /* QB_RX_FENA_2_FSYNC should be <= (QB_SR2 -12) */
/*MT6260RF*/ #define  QB_SR3                       4 /* QB_RX_FSYNC_2_FENA should be <= (QB_SR3    ) */
/*MT6260RF*/ #define  QB_SR2M                     44
/*MT6260RF*/ #define  QB_PR1                     188 /* QB_PR1 should be larger than (QB_SR0 - 30) */
/*MT6260RF*/ #define  QB_PR2                     185 /* QB_PR2 should be larger than (QB_SR0 - 30) */
/*MT6260RF*/ #define  QB_PR3                       6
/*MT6260RF*/
/*MT6260RF*/ #define  QB_ST0                     325
/*MT6260RF*/ #define  QB_ST1                     280
/*MT6260RF*/ #define  QB_ST2B                     52 /* QB_TX_FENA_2_FSYNC should be <= (QB_ST2B-12) */ /* QB_ST2B should be < 75 */
/*MT6260RF*/ #define  QB_ST3                      38 /* QB_TX_FSYNC_2_FENA should be <= (QB_ST3 -11) */
/*MT6260RF*/ #define  QB_PT1                     245
/*MT6260RF*/ #define  QB_PT2                      20
/*MT6260RF*/ #define  QB_PT2B                      0   ///4
/*MT6260RF*/ #define  QB_PT3                      34   //28
/*MT6260RF*/
/*MT6260RF*/ #define  QB_APCON                    18
/*MT6260RF*/ #define  QB_APCMID                   26
/*MT6260RF*/ #define  QB_APCOFF                   15   //13
/*MT6260RF*/ #define  QB_APCDACON                 20
/*MT6260RF*/ #define  TX_PROPAGATION_DELAY        49
/*MT6260RF*/
/*MT6260RF*/ /*--------------------------------------------------------*/
/*MT6260RF*/ /*   define BPI data for MT6260                           */
/*MT6260RF*/ /*--------------------------------------------------------*/
/*MT6260RF*/ /*    PRCB : bit   pin                                    */
/*MT6260RF*/ /*            0    BANDSW   - RF7176 GpCtrl0              */
/*MT6260RF*/ /*            1    not used                               */
/*MT6260RF*/ /*            2    TX_EN    - RF7176 TX ENABLE            */
/*MT6260RF*/ /*            3    TR_SW_EN - RF7176 GpCtrl1              */
/*MT6260RF*/ /*            4    not used                               */
/*MT6260RF*/ /*            5    not used                               */
/*MT6260RF*/ /*            6    not used                               */
/*MT6260RF*/ /*            7    not used                               */
/*MT6260RF*/ /*            8    not used                               */
/*MT6260RF*/ /*            9    not used                               */
/*MT6260RF*/ /*--------------------------------------------------------*/
/*MT6260RF*/
/*MT6260RF*/ #define  PDATA_GSM850_PR1          0x000
/*MT6260RF*/ #define  PDATA_GSM850_PR2          0x008  //0x009
/*MT6260RF*/ #define  PDATA_GSM850_PR3          0x000
/*MT6260RF*/ #define  PDATA_GSM850_PT1          0x000
/*MT6260RF*/ #define  PDATA_GSM850_PT2          0x000
/*MT6260RF*/ #define  PDATA_GSM850_PT2B         0x00C
/*MT6260RF*/ #define  PDATA_GSM850_PT3          0x000
/*MT6260RF*/
/*MT6260RF*/ #define  PDATA_GSM_PR1             0x000
/*MT6260RF*/ #define  PDATA_GSM_PR2             0x008  //0x009
/*MT6260RF*/ #define  PDATA_GSM_PR3             0x000
/*MT6260RF*/ #define  PDATA_GSM_PT1             0x000
/*MT6260RF*/ #define  PDATA_GSM_PT2             0x000
/*MT6260RF*/ #define  PDATA_GSM_PT2B            0x00C
/*MT6260RF*/ #define  PDATA_GSM_PT3             0x000
/*MT6260RF*/
/*MT6260RF*/ #define  PDATA_DCS_PR1             0x000
/*MT6260RF*/ #define  PDATA_DCS_PR2             0x009  //0x008
/*MT6260RF*/ #define  PDATA_DCS_PR3             0x000
/*MT6260RF*/ #define  PDATA_DCS_PT1             0x000
/*MT6260RF*/ #define  PDATA_DCS_PT2             0x000
/*MT6260RF*/ #define  PDATA_DCS_PT2B            0x00D
/*MT6260RF*/ #define  PDATA_DCS_PT3             0x000
/*MT6260RF*/
/*MT6260RF*/ #define  PDATA_PCS_PR1             0x000
/*MT6260RF*/ #define  PDATA_PCS_PR2             0x009  //0x008
/*MT6260RF*/ #define  PDATA_PCS_PR3             0x000
/*MT6260RF*/ #define  PDATA_PCS_PT1             0x000
/*MT6260RF*/ #define  PDATA_PCS_PT2             0x000
/*MT6260RF*/ #define  PDATA_PCS_PT2B            0x00D
/*MT6260RF*/ #define  PDATA_PCS_PT3             0x000
/*MT6260RF*/
/*MT6260RF*/ #define  PDATA_INIT                0x000
/*MT6260RF*/ #define  PDATA_IDLE                0x000
/*MT6260RF*/
/*MT6260RF*/ /*----------------------------------------------*/
/*MT6260RF*/ /*   APC Compensate Thresholds                  */
/*MT6260RF*/ /*----------------------------------------------*/
/*MT6260RF*/
/*MT6260RF*/ #define    SECONDS2FRAME(n)                     ((int)((n)*1000/4.615))
/*MT6260RF*/ #define    VOLT2UVOLT(n)                        ((int)((n)*1000000))
/*MT6260RF*/ #define    TEMP2MTEMP(n)                        ((int)((n)*1000))
/*MT6260RF*/
/*MT6260RF*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*MT6260RF*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6260RF*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*MT6260RF*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*MT6260RF*/
/*MT6260RF*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*MT6260RF*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6260RF*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*MT6260RF*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*MT6260RF*/
/*MT6260RF*/ /*----------------------------------------------*/
/*MT6260RF*/ /*   Crystal parameter                          */
/*MT6260RF*/ /*----------------------------------------------*/
#ifdef __KJX_FUN__
/*MT6260RF*/ #define Custom_RF_XO_CapID      150 // 171
#else
/*MT6260RF*/ #define Custom_RF_XO_CapID      171
#endif
/*MT6260RF*/
/*MT6260RF*/ /*------------------------------------------------------------------------------------*/
/*MT6260RF*/ /*   0: GSM850 Signal go through GSM850, GSM900 Signal go through GSM900  (default)   */
/*MT6260RF*/ /*   1: GSM850 Signal go through GSM900, GSM900 Signal go through GSM850  (default)   */
/*MT6260RF*/ /*------------------------------------------------------------------------------------*/
/*MT6260RF*/ #define GSM850_GSM900_SWAP      0
/*MT6260RF*/ /*------------------------------------------------------------------------------------*/
/*MT6260RF*/ /*   0: DCS1800 Signal go through DCS1800, PCS1900 Signal go through PCS1900(default) */
/*MT6260RF*/ /*   1: DCS1800 Signal go through PCS1900, PCS1900 Signal go through DCS1800          */
/*MT6260RF*/ /*------------------------------------------------------------------------------------*/
/*MT6260RF*/ #define DCS1800_PCS1900_SWAP    0
/*MT6260RF*/ /*------------------------------------------------------------------------------------*/
/*MT6260RF*/
/*MT6260RF*/ /*----------------------------------------------*/
/*MT6260RF*/ /*   TX power rollback parameter                */
/*MT6260RF*/ /*----------------------------------------------*/
/*MT6260RF*/ /*Unit: 1/8 dB*/
/*MT6260RF*/ /*GSM850 GMSK*/
/*MT6260RF*/ #define GSM850_TX_ROLLBACK_2T_GMSK 8   /* 1dBm*/
/*MT6260RF*/ #define GSM850_TX_ROLLBACK_3T_GMSK 24  /* 3dBm*/
/*MT6260RF*/ #define GSM850_TX_ROLLBACK_4T_GMSK 32  /* 4dBm*/
/*MT6260RF*/ #define GSM850_TX_ROLLBACK_5T_GMSK 40  /* 5dBm*/
/*MT6260RF*/
/*MT6260RF*/ /*GSM GMSK*/
/*MT6260RF*/ #define GSM_TX_ROLLBACK_2T_GMSK 8      /* 1dBm*/
/*MT6260RF*/ #define GSM_TX_ROLLBACK_3T_GMSK 24     /* 3dBm*/
/*MT6260RF*/ #define GSM_TX_ROLLBACK_4T_GMSK 32     /* 4dBm*/
/*MT6260RF*/ #define GSM_TX_ROLLBACK_5T_GMSK 40     /* 5dBm*/
/*MT6260RF*/
/*MT6260RF*/ /*DCS GMSK*/
/*MT6260RF*/ #define DCS_TX_ROLLBACK_2T_GMSK 8      /* 1dBm*/
/*MT6260RF*/ #define DCS_TX_ROLLBACK_3T_GMSK 24     /* 3dBm*/
/*MT6260RF*/ #define DCS_TX_ROLLBACK_4T_GMSK 32     /* 4dBm*/
/*MT6260RF*/ #define DCS_TX_ROLLBACK_5T_GMSK 40     /* 5dBm*/
/*MT6260RF*/
/*MT6260RF*/ /*PCS GMSK*/
/*MT6260RF*/ #define PCS_TX_ROLLBACK_2T_GMSK 8      /* 1dBm*/
/*MT6260RF*/ #define PCS_TX_ROLLBACK_3T_GMSK 24     /* 3dBm*/
/*MT6260RF*/ #define PCS_TX_ROLLBACK_4T_GMSK 32     /* 4dBm*/
/*MT6260RF*/ #define PCS_TX_ROLLBACK_5T_GMSK 40     /* 5dBm*/

/*MT6260RF*/ /*----------------------------------------------*/
/*MT6260RF*/ /*   DCXO LPM parameter                         */
/*MT6260RF*/ /*----------------------------------------------*/
/*MT6260RF*/ #define CUSTOM_CLOAD_FREQ_OFFSET   144000 /*in unit of Hz*/
//*============================================================================== */
/*MT6260RF*/ /* If you want to use calibration data in m12193.c, please DO NOT define __SLIM_CALIBRATION_DATA__ in l1d_custom_rf.h */
/*MT6260RF*/ //#define __SLIM_CALIBRATION_DATA__

#endif

