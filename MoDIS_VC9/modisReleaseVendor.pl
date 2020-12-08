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

use strict;
use createMoDIS;

(($#ARGV < 0) || ($#ARGV > 1)) && &Usage;
my $releaseAs;
my $thefile;
while ($#ARGV != -1) {
  if (lc($ARGV[0]) eq "-release") {
    $releaseAs = "Release";
  } elsif (lc($ARGV[0]) eq "-debug") {
    $releaseAs = "Debug";
  } else {
    ($#ARGV != 0) && &Usage;
    $thefile = $ARGV[0];
    last;
  }
  shift(@ARGV);
}

die "$thefile does NOT exist\n" if (!-e $thefile);
($thefile =~ /make\\(\w+)_(\w+).mak/i) || die "The Makefile format should be ..\\make\\custom_proj.mak\n";
my $customer = uc($1);
my $mode = uc($2);
my $level= "VENDOR";
($customer = "MTK") if ($customer =~ /^MT\d\d\d\d\w?$/i);
###############################################################
# Read from Makefile
###############################################################
my %feature;
open (FILE_HANDLE, "<$thefile") or die "cannot open $thefile\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    my $keyname = $1;
    defined($feature{$keyname}) && warn "$1 redefined in $thefile!\n";
    $feature{$keyname} = $2;
  }
}
close FILE_HANDLE;

my $project;
if($thefile =~ /.+_(.+).mak/) {
  $project = $1;
}

my %release;
my $optMake = "..\\make\\info_custom_release.log";
open (FILE_HANDLE, "<$optMake") or die "cannot open $optMake\n";
while (<FILE_HANDLE>) {
  chomp;
  s/\s+/ /g;
  s/\s+$//g;
  if (/^(\S+)\s*=\s*(.+)$/) {
    my $keyname = $1;
    defined($release{$keyname}) && warn "$1 redefined in $optMake!\n";
    $release{$keyname} = $2;
  }
}
close FILE_HANDLE;

my $relDir = $release{'RELEASE_DIR'};
(!-d $relDir) && die "RELEASE_DIR $relDir in $optMake does NOT exist\n";

###############################################################
# Read ALIAS settings
###############################################################
my %alias;
open ALIAS_FILE, "<..\\make\\ALIAS.mak" || die "Cannot open ..\\make\\ALIAS.mak:$!";
while (<ALIAS_FILE>) {
  #next if ((/^\s*$/) || (/^\s*#/));
  if (/^\s*(\S+)\s*=\s*(\S+)/) {
    my $keyname = $1;
    defined($alias{$keyname}) && warn "$1 redefined in ALIAS.mak!\n";
    $alias{$keyname} = $2;
  }
}
close ALIAS_FILE;

my %infomake;
$optMake = "..\\build\\$customer\\log\\infomake_modis.log";
open (FILE_HANDLE, "<$optMake") or die "cannot open ${optMake}\n";
while (<FILE_HANDLE>) {
  chomp;
  s/\s+/ /g;
  s/\s+$//g;
  if (/^(\S+)\s*=\s*(.+)$/) {
    my $keyname = $1;
    defined($infomake{$keyname}) && warn "$1 redefined in $optMake!\n";
    $infomake{$keyname} = $2;
  }
}

if (!defined($releaseAs)) {
  $releaseAs = $release{'MODIS_MODE'};
}

my $REL_MoDIS_LIB = $release{'CUS_MTK_LIB'};
$REL_MoDIS_LIB =~ s/\bmtk_lib\b/MoDIS_LIB/i;
my $MoDIS_LIB = $infomake{'CUS_MODIS_LIB'};
my @lib_modules = ();

#print "MoDIS_LIB=$MoDIS_LIB\n";
#print "REL_MoDIS_LIB=$relDir\\MoDIS_VC9\\$REL_MoDIS_LIB\n";

if(!-e "$relDir\\MoDIS_VC9\\$REL_MoDIS_LIB") {
	system("md $relDir\\MoDIS_VC9\\$REL_MoDIS_LIB");
}

my %WIN32_LIB;
my %UN_WIN32_LIB;

foreach my $a (split('\s+', $release{'MODIS_DIS_LIBS'})) {
	$UN_WIN32_LIB{$a} = 1;
}

foreach my $a (split('\s+', $release{'MODIS_MTK_LIBS'})) {
	$UN_WIN32_LIB{$a} = 2;
}

foreach my $b (split('\s+', $release{'MODIS_EN_LIBS'})) {
	if (defined($UN_WIN32_LIB{$b}) && ($UN_WIN32_LIB{$b} >= 1)) {
		warn "Duplicated define $b in enable and disable library!!\n";
	} else {
		if ((uc($level) ne "LEVEL2_SRC") && (lc($b) ne "modis")) {
			push(@lib_modules, $b);
			next;
		}
		else
		{
			$WIN32_LIB{$b} = 1;
		}
	}
}

my @basics = qw(WIN32FS
MoDIS\\InfoMonitor.ini
MoDIS\\mtk_icon.ICO
MoDIS\\mtk_simulator.ICO
MoDIS\\Debug\\AVLib.dll
MoDIS\\Debug\\AVLib.lib
MoDIS\\Debug\\MFCO42D.DLL
MoDIS\\Debug\\MODIS_UI.dll
MoDIS\\Debug\\MODIS_UI.lib
MoDIS\\Debug\\MODIS_UI_MSLT.dll
MoDIS\\Debug\\MODIS_UI_MSLT.lib
MoDIS\\Debug\\MUXCOM.sys
MoDIS\\Debug\\MoDIS.ini
MoDIS\\Debug\\VComConsole.exe
MoDIS\\Debug\\non.bmp
MoDIS\\Debug\\TC.txt
MoDIS\\Debug\\TH.txt
MoDIS\\Debug\\themeug.doc
MoDIS\\Debug\\midisyn.exe
MoDIS\\Debug\\wavtab.bin
MoDIS\\Debug\\AVLibDefaultFilter.txt
MoDIS\\Debug\\SimEditor.dll
MoDIS\\Release\\AVLib.dll
MoDIS\\Release\\AVLib.lib
MoDIS\\Release\\MODIS_UI.dll
MoDIS\\Release\\MODIS_UI.lib
MoDIS\\Release\\MODIS_UI_MSLT.dll
MoDIS\\Release\\MODIS_UI_MSLT.lib
MoDIS\\Release\\MFCO42D.DLL
MoDIS\\Release\\MUXCOM.sys
MoDIS\\Release\\MoDIS.ini
MoDIS\\Release\\VComConsole.exe
MoDIS\\Release\\MFC42.DLL
MoDIS\\Release\\MSVCRT.DLL
MoDIS\\Release\\Msvcp60.dll
MoDIS\\Release\\non.bmp
MoDIS\\Release\\TC.txt
MoDIS\\Release\\TH.txt
MoDIS\\Release\\themeug.doc
MoDIS\\Release\\midisyn.exe
MoDIS\\Release\\wavtab.bin
MoDIS\\Release\\AVLibDefaultFilter.txt
MoDIS\\Release\\SimEditor.dll
MoDIS\\picture
MoDIS\\Skin
MoDIS\\database\\MRE_structure.lst
MoDIS_UI\\SimEditor.h
MoDIS_UI\\SimEditor.lib
plugin\\dll
plugin\\inc
plugin\\MTE
MoDIS\\plugin
.\\modisReleaseL1.pl
.\\createMSLT.bat
.\\modisDepend.pl
.\\modisAutoTest.pl
.\\depend.vsprops
.\\auto_header.h
..\\kal\\oscar\\include oscar\\oscar.dll
..\\tst\\database_modis\\BPGUInfoCustomApp_pc
..\\tst\\database_modis\\mcddll.dll
);

my @level2s = qw(
createMoDIS.pl createMoDIS.pm MoDISReleaseCustom.pl modisReleaseVendor.pl ANSI.pm
MoDIS.sln MoDIS\\MoDIS.vcproj
MoDIS\\resource.h MoDIS\\StdAfx.h MoDIS\\w32_dspl.h
oscar\\include
drv_sim\\include
);

my @level2o = qw(
MoDIS\\resource.h MoDIS\\StdAfx.h MoDIS\\w32_dspl.h
oscar\\include
drv_sim\\include
..\\tst\\database_modis\\pstrace_db\\ps_trace.h
);

my @level_v = qw(
createMoDIS.pl createMoDIS.pm
MoDIS\\resource.h MoDIS\\StdAfx.h MoDIS\\w32_dspl.h
oscar\\include
drv_sim\\include
..\\tst\\database_modis\\pstrace_db\\ps_trace.h
NetSIM
.\\NetSimScript.msc
);

my @removeDirs = qw(MoDIS_VC9 kal\\oscar interface);
my @level2;
my @levels;
if (uc($level) ne "LEVEL2_SRC") {
  if ($feature{'MMI_VERSION'} =~ /PLUTO_MMI/) {
    push(@level2, "conn_app\\conn_app.ini");
  } elsif ($feature{'MMI_VERSION'} =~ /COSMOS_MMI/) {
    push(@level2, "cosmos_conn_app\\cosmos_conn_app.ini");
  } else {
    push(@level2, "lcmmi\\lcmmi.ini");
  }
}

if (($feature{'SSL_SUPPORT'} =~ /SSL_CIC_LIB/) || ($feature{'SSL_SUPPORT'} =~ /MTK_SSL_CIC/)){
  push(@lib_modules, "sb51");
  push(@lib_modules, "sbpki2");
  push(@lib_modules, "sslplus5");
}

if ($feature{'NAND_FLASH_BOOTING'} ne "NONE") {
  push(@level2, "MoDIS\\CustENFBImgData") if (-e "MoDIS\\CustENFBImgData");
  push(@level2, "MoDIS\\CustENFBStrData") if (-e "MoDIS\\CustENFBStrData");
}

if ($feature{'WIFI_SUPPORT'} ne "NONE") {
    push(@level2, "..\\wifi\\lib\\MoDIS\\supc.lib") if (-e "..\\wifi\\lib\\MoDIS\\supc.lib");
}

if (uc($level) eq "LEVEL2_SRC") {
  @levels = (@basics, @level2, @level2s);
} elsif (uc($level) eq "LEVEL2_OBJ") {
  @levels = (@basics, @level2, @level2o);
} elsif (uc($level) eq "VENDOR") {
  @levels = (@basics, @level2, @level_v);
}

if (!defined $release{'SINGLEMODULE'}){
  foreach my $f (@levels) {
    next if ((!-e "$f") && ($f =~ /MFCO42D/i));
    ($f =~ s/Debug/Release/i) if ((lc($releaseAs) eq "release") && (($f =~ /MODIS_UI\.dll/i) || ($f =~ /MODIS_UI_MSLT\.dll/i)));
    print "MoDIS_VC9\\$f\n";
    if (-d $f)
    {
      system("xcopy /q /e /y $f $relDir\\MoDIS_VC9\\$f\\*.* > nul");
    }
    elsif (-e $f)
    {
      my $dest = $f;
      if ($dest =~ /\\[^\\]*$/) {
        $dest =~ s/\\[^\\]*$//;
        system("xcopy /q /y $f $relDir\\MoDIS_VC9\\$dest\\ > nul");
        if (($f =~ /MODIS_UI\.dll/i) || ($f =~ /MODIS_UI_MSLT\.dll/i)) {
          if (lc($releaseAs) eq "release") {
            $dest =~ s/Release/Debug/i;
          } else {
            $dest =~ s/Debug/Release/i;
          }
          system("xcopy /q /y $f $relDir\\MoDIS_VC9\\$dest\\ > nul");
        }
      } else {
        system("xcopy /q /y $f $relDir\\MoDIS_VC9\\ > nul");
      }
    }
    else
    {
      die "Could not find $f\n";
    }
  }
}

push(@lib_modules, split('\s+',$release{'CUS_REL_MTK_COMP'}));
push(@lib_modules, split('\s+',$release{'CUS_REL_PAR_SRC_COMP'}));
push(@lib_modules, split('\s+',$release{'MODIS_MTK_LIBS'}));

my %saw;
@lib_modules = sort grep (!$saw{$_}++, @lib_modules);
my $l2olib;
foreach my $module (@lib_modules) {
    next if ($UN_WIN32_LIB{$module} == 1);
    my $compdef;
    if (-e "${module}\\${releaseAs}\\${module}.lib")
    {
        $compdef = "${module}\\${releaseAs}\\${module}.lib";
    }
    elsif (-e "$MoDIS_LIB\\${module}.lib")
    {
        $compdef = "$MoDIS_LIB\\${module}.lib";
    }
    else {
        warn "***** ${module}.lib does NOT exist\n";
        next;
    }
    if ($module eq "image_sensor_sec") {
        print("MoDIS_VC9\\$REL_MoDIS_LIB\\$feature{'CMOS_SENSOR'}\\${module}.lib\n");
        system("xcopy /q /y $compdef $relDir\\MoDIS_VC9\\$REL_MoDIS_LIB\\$feature{'CMOS_SENSOR'}\\ > nul");
        $l2olib .= "..\\$REL_MoDIS_LIB\\$feature{'CMOS_SENSOR'}\\${module}.lib\n";
    } else {
        print("MoDIS_VC9\\$REL_MoDIS_LIB\\${module}.lib\n");
        system("xcopy /q /y $compdef $relDir\\MoDIS_VC9\\$REL_MoDIS_LIB\\ > nul");
        $l2olib .= "..\\$REL_MoDIS_LIB\\${module}.lib\n";
    }
}

my @src_modules = split('\s+',$release{'CUS_REL_SRC_COMP'});
my @modis_modules = sort keys %WIN32_LIB;
my @l2osrc;
push (@src_modules, @modis_modules);

foreach my $lib (@src_modules)
{
    next if ($UN_WIN32_LIB{$lib} >= 1);
    if ((uc($level) ne "LEVEL2_SRC") && ((-e "${lib}\\${releaseAs}\\${lib}.lib") || ($lib eq "modis") || ($lib eq "jdummy"))) {
      push(@l2osrc, $lib);
      system("xcopy /q /y ${lib}\\${lib}.ini $relDir\\MoDIS_VC9\\${lib}\\ > nul");
      system("xcopy /q /y ${lib}\\${lib}.vcproj $relDir\\MoDIS_VC9\\${lib}\\ > nul");
    }
    my $thefile;
    if (defined $alias{$lib}) {
      $thefile = "build\\$customer\\module\\modis\\$alias{$lib}\\$lib\\${lib}.lis";
      if (! -d "$relDir\\make\\$alias{$lib}\\$lib")
      {
        system("xcopy /q /e /y ..\\make\\$alias{$lib}\\$lib $relDir\\make\\$alias{$lib}\\$lib\\*.* > nul");
      }
    }
    else {
      $thefile = "build\\$customer\\module\\modis\\$lib\\${lib}.lis";
      if (! -d "$relDir\\make\\$lib")
      {
        system("xcopy /q /e /y ..\\make\\$lib $relDir\\make\\$lib\\*.* > nul");
      }
    }
    open (FILE_HANDLE, "<..\\$thefile") or die "cannot open ${lib}.lis\n";
    while (<FILE_HANDLE>)
    {
      next if (m/^\s*$/);
      chomp;
      s/\s+//g;
      my $src = $_;
      my $dest = $_;
      $dest =~ s/\\([^\\]*)$//;
      my $file = $1;
      if (! -e "$relDir\\$dest\\$file")
      {
        print("$dest\\$file\n");
        system("xcopy /q /y ..\\$src $relDir\\$dest\\ > nul");
        push @removeDirs, "$dest";
      }
    }
    close FILE_HANDLE;
    my $thedep = "MoDIS_VC9\\_BUILD_DEP";
    chdir("..\\");
    system("perl tools\\copySrcComp.pl $thefile $thedep make \"$relDir\"") && die "Release modis only module error!\n";
    chdir("MoDIS_VC9\\");
}

###############################################################
#  Release modis codegen
###############################################################
$thefile = "MoDIS_VC9\\MoDIS\\codegen.lis";
open (FILE_HANDLE, ">..\\$thefile") or die "cannot write $thefile\n";
print FILE_HANDLE "tst\\database\\msglog_db\\custom_parse_db.c\n";
close FILE_HANDLE;
my $thedep = "MoDIS_VC9\\_BUILD_DEP";
chdir("..\\");
system("perl tools\\copySrcComp.pl $thefile $thedep make \"$relDir\"") && die "Release modis only module error!\n";
chdir("MoDIS_VC9\\");
unlink $thefile;
###############################################################

if (uc($level) ne "LEVEL2_SRC") {
  my %src_lib_GUID;
  open LIB_LIST, ">${relDir}\\MoDIS_VC9\\lib_list";
  foreach my $srcLib (@l2osrc)
  {
    $src_lib_GUID{$srcLib} = createMoDIS::generate($srcLib, $srcLib, $srcLib);
    print LIB_LIST "$srcLib\n";
  }
  close LIB_LIST;
  createMoDIS::update_lib_project(
    "MoDIS/MoDIS.vcproj",
    "MoDIS/MoDIS1.vcproj",
    $REL_MoDIS_LIB,
    $l2olib,
    "TRUE");
  my $GUID_modis_L2ORel = createMoDIS::generate("MoDIS", "L2OBJ", "Release");
  createMoDIS::create_solution(
    $GUID_modis_L2ORel,
    "REDUCE.sln",
    \@l2osrc,
    \%src_lib_GUID
  );
  print("MoDIS_VC9\\MoDIS.sln\n");
  system("del /f /q ${relDir}\\MoDIS_VC9\\MoDIS.sln > nul") if (-e "${relDir}\\MoDIS_VC9\\MoDIS.sln");
  system("xcopy /q /y REDUCE.sln $relDir\\MoDIS_VC9\\ > nul");
  system("rename ${relDir}\\MoDIS_VC9\\REDUCE.sln MoDIS.sln");
  print("MoDIS_VC9\\MoDIS\\MoDIS.vcproj\n");
  system("del /f /q ${relDir}\\MoDIS_VC9\\MoDIS\\MoDIS.vcproj > nul") if (-e "${relDir}\\MoDIS_VC9\\MoDIS\\MoDIS.vcproj");
  system("xcopy /q /y MoDIS\\MoDIS1.vcproj $relDir\\MoDIS_VC9\\MoDIS\\ > nul");
  system("rename ${relDir}\\MoDIS_VC9\\MoDIS\\MoDIS1.vcproj MoDIS.vcproj");
}

system "copy /y nul ${relDir}\\MoDIS_VC9\\MoDIS.ncb > nul";
system("attrib +r ${relDir}\\MoDIS_VC9\\MoDIS.ncb > nul");

# Copy codegen database for SWITCHABLE_FEATURE and SWITCHABLE_FEATURE_2ND
if (defined $feature{'SWITCHABLE_FEATURE'}){
  my $REL_MoDIS_TST = "tst\\database_modis";
  if ((defined $release{'SWITCH_FOLDER'}))
  {
    $REL_MoDIS_TST .= "\\".$release{'SWITCH_FOLDER'};
  }
  print "$REL_MoDIS_TST\\BPGUInfoCustomApp_pc\n";
  system "xcopy /y ${relDir}\\tst\\database_modis\\BPGUInfoCustomApp_pc ${relDir}\\$REL_MoDIS_TST\\";
  system "xcopy /y ${relDir}\\tst\\database_modis\\mcddll.dll ${relDir}\\$REL_MoDIS_TST\\";
}

if (uc($level) eq "VENDOR")
{
  if ($release{'CUSTOM_RELEASE'} eq "TRUE")
  {
    print("copy $MoDIS_LIB\\*.lib to MoDIS_VC9\\$REL_MoDIS_LIB\n");
    system("xcopy /q /y $MoDIS_LIB\\*.lib $relDir\\MoDIS_VC9\\$REL_MoDIS_LIB\\ > nul");
  }
  system("xcopy /e /y \"..\\tst\\database_modis\\pstrace_db\\*.h\" \"${relDir}\\tst\\database_modis\\pstrace_db\\\"");
}

# remove WIN32FS\DRIVE_C
system("rd /s /q ${relDir}\\MoDIS_VC9\\WIN32FS\\DRIVE_C > nul") if (-d "${relDir}\\MoDIS_VC9\\WIN32FS\\DRIVE_C");

chdir("..");

my @nonRelFilesList = split('\s+',$release{'NON_REL_FILES_LIST'});
my @nonRelDirsList = split('\s+',$release{'NON_REL_DIRS_LIST'});

for my $eachNonRel(@nonRelFilesList,@nonRelDirsList){
  if(-e "${relDir}\\$eachNonRel"){
    if(-d "${relDir}\\$eachNonRel"){
      print "rd /s /q ${relDir}\\$eachNonRel\n";
      system "rd /s /q ${relDir}\\$eachNonRel";
    }
    else{
      print "unlink ${relDir}\\$eachNonRel\n";
      unlink "${relDir}\\$eachNonRel";
    }
  }
}

%saw = ();
@removeDirs = sort grep (!$saw{$_}++, @removeDirs);
foreach my $rmdir (@removeDirs) {
  if ($release{'CUSTOM_RELEASE'} eq "TRUE")
  {
    system("perl tools\\traverseDir_modis.pl $relDir\\$rmdir $release{'EN_DEF_FILE'} $release{'DIS_DEF_FILE'} $release{'CUS_REL_OPTION_FILTER'} $release{'CUS_REL_HISTORY_FILTER'}");
  }
  else
  {
    system("perl mtk_tools\\traverseDir_modis.pl $relDir\\$rmdir $release{'EN_DEF_FILE'} $release{'DIS_DEF_FILE'} $release{'CUS_REL_OPTION_FILTER'} $release{'CUS_REL_HISTORY_FILTER'}");
  }
}

print "MoDIS Release Finished.\n";
exit 0;


sub Usage {
  warn << "__END_OF_USAGE";
Usage:
  modisReleaseL2src [-release|-debug] ..\\make\\custom_mode.mak
__END_OF_USAGE
  exit 1;
}
