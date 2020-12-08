#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   config_MemSegment.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/
package memConfig;
use strict;
#use warnings;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysgenUtility;                 #pm file name without case sensitivity
use FileInfoParser;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $CONFIGMEMSEGMENT_VERNO   = " v0.05";
                               # v0.05 , 2012/10/31,  Move is_NOR() from sysGenUtility to FileInfoParser to support general query
                               # v0.04 , 2012/07/26,  Add some error handling
                               # v0.03 , 2012/07/10,  Support EWS via tools::pack_dep_gen
                               # v0.02 , 2012/05/29,  Provide Get_bin_comp_value() to support MBA with compression
                               # v0.01 , 2012/05/14,  Initial revision
     
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  Get_SDS_total_size: To get the SDS total size according to the block size
# input: 	     $block_size : the block size for SDS
#              $feature_config_ref : a hash reference to query defined values in custom_FeatureConfig.h
#              $feature_option_ref : a hash reference to query feature options in projec.mak
# return:      $sds_total_size
#****************************************************************************
sub Get_SDS_total_size
{
    
    my ($block_size, $feature_config_ref, $feature_option_ref) = @_;
    my $sds_data_size  = 0;
    my $sds_spare_size = 0;
    my $sds_total_size = 0;
    if(&FileInfo::is_NOR($feature_option_ref) != 1)
    {
        $sds_data_size  = (defined $feature_config_ref->{'SDS_MAX_SIZE'}) ? hex($feature_config_ref->{'SDS_MAX_SIZE'}) : 256*1024;
        $sds_spare_size = (defined $feature_config_ref->{'SDS_RESERVED_SIZE_FOR_BBM'}) ? hex($feature_config_ref->{'SDS_RESERVED_SIZE_FOR_BBM'}) : 256*1024;
    }
    else
    {
        my $mode = $feature_option_ref->{'MODE'};
        my $two_blocks_size = 2 * $block_size; #the number of blocks for SDS need to be 2N
        
        if(defined $feature_config_ref->{'SDS_MAX_SIZE'})
        {
            $sds_data_size = hex($feature_config_ref->{'SDS_MAX_SIZE'});
        }
        elsif(($mode eq 'GSM') or ($mode eq 'GPRS'))
        {
            my $sds_temp_size = 0;
            &config_die("Input parameter: Block Size($block_size) can't be less than 1",__FILE__, __LINE__) 
                if(!defined $block_size or $block_size <= 0);
            while($sds_temp_size < 32*1024)
            {
                $sds_temp_size += $two_blocks_size;
            }
            $sds_data_size = ($block_size <=  12*1024) ? $sds_temp_size : $two_blocks_size;
        }
        else
        {
            my $sds_temp_size = 0;
            &config_die("Input parameter: Block Size($block_size) can't be less than 1",__FILE__, __LINE__) 
                if(!defined $block_size or $block_size <= 0);
            while($sds_temp_size < 128*1024)
            {
                $sds_temp_size += $two_blocks_size;
            }
            $sds_data_size = ($block_size <=  64*1024) ? $sds_temp_size : $two_blocks_size;
        }
    }
    
    $sds_total_size = $sds_data_size + $sds_spare_size;
    
    return $sds_total_size;
}

#****************************************************************************
# subroutine:  Get_bin_comp_value: To get bin size defined in custom_FeatureConfig.h
# input:       $feature_config_href : the hash reference of custom_FeatureConfig.h
#              $strBIN_name : the binary name
# return:      $nBIN_configSize : the compressed size of the input binary name in custom_Featureconfig.h                                  
#****************************************************************************
sub Get_bin_comp_value
{
    my ($feature_config_href, $strBIN_name) = @_;
    my $nBIN_configSize = undef;
    my $strBIN_configName;
    my $strBIN_compNAME;

    $strBIN_configName = 'CONFIG_'.$strBIN_name.'_MAX_COMPRESSED_SIZE';
    $strBIN_compNAME = $strBIN_name.'_COMPRESS';
    my $need_comp = $feature_config_href->{$strBIN_compNAME};
    $nBIN_configSize   = hex($feature_config_href->{$strBIN_configName}) if ($need_comp);

    return $nBIN_configSize;
}

#****************************************************************************
# subroutine:  config_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub config_die
{
    my ($error_msg, $file, $line_no) = @_;
    &sysUtil::error_handler($error_msg, $file, $line_no, 'config_MemSegment');
}
