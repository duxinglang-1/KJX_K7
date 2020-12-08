#!/usr/local/bin/perl

# 
# Copyright Statement:
# --------------------
# This software is protected by Copyright and the information contained
# herein is confidential. The software may not be copied and the information
# contained herein may not be used or disclosed except with the written
# permission of MediaTek Inc. (C) 2005
# 
# BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
# NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
# SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
# 
# BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
# LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
# 
# THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
# WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
# LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
# RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
# THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
# 

########################################################################
# Please notice that this script is for MoDIS on VS2008 (VC9)
# NOT suitable for MoDIS on VC6 
########################################################################

$relMode = 1;
(($#ARGV < 0) || ($#ARGV > 1)) && &Usage;

while ($#ARGV != -1) {
  if (lc($ARGV[0]) eq "-release") {
    $relMode = 1;
  } elsif (lc($ARGV[0]) eq "-debug") {
    $relMode = 0;
  } else {
    $relDir = $ARGV[0];
    last;
  }
  shift(@ARGV);
}

($relDir eq "") && &Usage;

@basics = qw(WIN32FS
MoDIS\\InfoMonitor.ini
MoDIS\\mtk_icon.ICO
MoDIS\\mtk_simulator.ICO
MoDIS\\picture
MoDIS\\Skin
MoDIS\\plugin
NetSim
..\\tst\\database_modis);

@level1s = qw(MoDIS\\CustMMI3rdROM
MoDIS\\CustEnfbVenusThemeData
MoDIS\\CustEnfbVenusAppIconData
MoDIS\\hw_data.gbd
MoDIS\\CustENFBFontData
.\\NetSimScript.msc
MoDIS\\Release
);

if (-d "MSLT") {
  push(@basics,"MSLT");
}

 foreach $f (@basics) {
    die "Could not find $f\n" if (!-e "$f");
    print "Copying $f ...\n";
    if (-d $f) {
      system("xcopy /q /e /y $f $relDir\\MoDIS_VC9\\$f\\*.* > nul");
    } elsif (-e $f) {
      $dest = $f;
      $dest =~ s/\\[^\\]*$//;
      system("xcopy /q /y $f $relDir\\MoDIS_VC9\\$dest\\ > nul");
    }
 }

 foreach $f (@level1s) {
    next if (($f =~ /(MFC42.DLL|MSVCRT.DLL|Msvcp60.dll)/i) && ($relMode == 0));
    ($f =~ s/Release/Debug/) if ($relMode == 0);
	if ((!-e "$f") && ($f !~ /CustENFB(.*)Data/i) && ($f !~ /CustMMI3rdROM/i) && ($f !~ /hw_data\.gbd/i)) {
		die "Could not find $f\n";
	}
    print "Copying $f ...\n";
    if (-d $f) {
      system("xcopy /q /e /y $f $relDir\\MoDIS_VC9\\$f\\*.* > nul");
    } elsif (-e $f) {
      $dest = $f;
      $dest =~ s/\\[^\\]*$//;
      system("xcopy /q /y $f $relDir\\MoDIS_VC9\\$dest\\ > nul");
    }
 }


if (-d "$relDir\\tst") {
  system("move /Y $relDir\\tst $relDir\\MoDIS_VC9\\tst");
}

# For TDMB_SUPPORT
if (-e "MoDIS\\Release\\SDL.dll") {
  system("copy /y MoDIS\\Release\\SDL.dll $relDir\\MoDIS_VC9\\MoDIS\\Release\\SDL.dll");
}
if (-e "MoDIS\\Debug\\SDL.dll") {
  system("copy /y MoDIS\\Debug\\SDL.dll $relDir\\MoDIS_VC9\\MoDIS\\Debug\\SDL.dll");
}

# For MSLT_INFO
if (-d "MoDIS\\MSLT_INFO") {
  system("xcopy /q /y MoDIS\\MSLT_INFO $relDir\\MoDIS_VC9\\MoDIS\\MSLT_INFO\\");
}

# For Opera
if (-e "MoDIS\\Release\\libopera.dll") {
  system("copy /y MoDIS\\Release\\libopera.dll $relDir\\MoDIS_VC9\\MoDIS\\Release\\libopera.dll");
}
if (-e "MoDIS\\Debug\\libopera.dll") {
  system("copy /y MoDIS\\Debug\\libopera.dll $relDir\\MoDIS_VC9\\MoDIS\\Debug\\libopera.dll");
}

system("xcopy /q /y MoDIS\\Debug\\*.manifest $relDir\\MoDIS_VC9\\MoDIS\\Debug\\");

if (-e "$relDir\\MoDIS_VC9\\MoDIS\\Debug\\MODIS_UI_ALL.lib") {
  system("del /q $relDir\\MoDIS_VC9\\MoDIS\\Debug\\MODIS_UI_ALL.lib");
}

if (-e "$relDir\\MoDIS_VC9\\MoDIS\\Debug\\MODIS_UI_ALL.dll") {
  system("del /q $relDir\\MoDIS_VC9\\MoDIS\\Debug\\MODIS_UI_ALL.dll");
}

if (-e "$relDir\\MoDIS_VC9\\MoDIS\\Release\\MODIS_UI_ALL.lib") {
  system("del /q $relDir\\MoDIS_VC9\\MoDIS\\Release\\MODIS_UI_ALL.lib");
}

if (-e "$relDir\\MoDIS_VC9\\MoDIS\\Release\\MODIS_UI_ALL.dll") {
  system("del /q $relDir\\MoDIS_VC9\\MoDIS\\Release\\MODIS_UI_ALL.dll");
}

exit 0;

sub Usage {
  warn << "__END_OF_USAGE";
Usage:
  modisReleaseL1 [-release|-debug] release_directory
__END_OF_USAGE
  exit 1;
}
