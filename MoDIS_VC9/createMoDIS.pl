########################################################################
# Please notice that this script is for MoDIS on VS2008 (VC9)
# NOT suitable for MoDIS on VC6
########################################################################
#!/usr/bin/perl

my $myname = "createMoDIS";
use strict;
use File::Basename;
use createMoDIS;

&Usage if ($#ARGV == -1);

my $thefile = $ARGV[0];
my $customer;
my $modem;
my $flavor = "NONE";

die "$thefile does NOT exist" if (!-e $thefile);
if ($thefile =~ /make[\\\/](\w+)_(\w+)(?:\((\w+)\))?\.mak/i)
{
	$customer = uc($1);
	$modem = uc($2);
	if ($3 ne "")
	{
		$flavor = uc($3);
	}
}
else
{
	die "The Makefile format should be make\\custom_proj.mak";
}
print "customer=$customer\nmodem=$modem\n";

my $PROJDIR = "build/${customer}";
my $SLN_ROOT = ".";
my $LOG_ROOT = "_BUILD_LOG";
my $MCU_ROOT = "..\\..";

# Enable UE Simulator
my $modis_uesim = "MoDIS";
my $modis_suffix = '';
if (lc($ARGV[1]) eq "uesim")
{
	$modis_uesim = "UESim";
	$modis_suffix = '_uesim';
}

mkdir($LOG_ROOT) if (! -d $LOG_ROOT);

my $LOG_HANDLE;
my $WRITE_HANDLE;
my $flag_error = 0;
open $LOG_HANDLE, ">$LOG_ROOT/gen_${modis_uesim}.log" or die "Fail to write $LOG_ROOT/gen_${modis_uesim}.log";

# Read from project makefile
my %feature;
if (open FILE_HANDLE, "<$thefile")
{
	while (<FILE_HANDLE>)
	{
		if (/^(\w+)\s*=\s*(\w+)/)
		{
			my $keyname = $1;
			defined($feature{$keyname}) && warn "$1 redefined in $thefile!\n";
			$feature{$keyname} = $2;
		}
	}
	close FILE_HANDLE;
}
else
{
	&error_handle("Fail to read $thefile");
	die;
}

# Read from infomake_modis.log
my %infomake;
my $optMake = "..\\build\\$customer\\log\\infomake_${modis_uesim}.log";
if (open FILE_HANDLE, "<$optMake")
{
	while (<FILE_HANDLE>)
	{
		chomp;
		s/\s+/ /g;
		s/\s+$//g;
		if (/^(\S+)\s*=\s*(.+)$/)
		{
			my $keyname = $1;
			defined($infomake{$keyname}) && warn "$1 redefined in $optMake!\n";
			$infomake{$keyname} = $2;
		}
	}
	close FILE_HANDLE;
}
else
{
	&error_handle("Fail to read $optMake");
	die;
}

# Read ALIAS settings
my %alias;
if (open FILE_HANDLE, "<..\\make\\ALIAS.mak")
{
	while (<FILE_HANDLE>)
	{
		if (/^\s*(\S+)\s*=\s*(\S+)/)
		{
			my $keyname = $1;
			defined($alias{$keyname}) && warn "$1 redefined in ALIAS.mak!\n";
			$alias{$keyname} = $2;
		}
	}
	close FILE_HANDLE;
}
else
{
	&error_handle("Fail to read make/ALIAS.mak");
	die;
}

# Define MoDIS linking library folder
my $LIB_ROOT = $infomake{'CUS_MODIS_LIB'};
my $MODULE_PATH = "..\\build\\${customer}\\module\\${modis_uesim}";
my $lib_tool = "lib.exe";


###############################################################
# Define MoDIS linking module list
my @listLink;
my %UN_WIN32_LIB;
my @mtk_comp = split('\s+', $infomake{'MODIS_MTK_LIBS'});
if ($infomake{'CUSTOM_RELEASE'} eq "TRUE")
{
	push @mtk_comp, split('\s+', $infomake{'CUS_REL_MTK_COMP'});
}
foreach my $lib (@mtk_comp)
{
	$UN_WIN32_LIB{$lib} = 1;
	if (($lib eq "image_sensor_sec") && ($infomake{'CUSTOM_RELEASE'} eq "TRUE"))
	{
		push @listLink, "$MCU_ROOT\\MoDIS_VC9\\$LIB_ROOT\\$feature{'CMOS_SENSOR'}\\${lib}.lib";
		if (! -e "$LIB_ROOT\\$feature{'CMOS_SENSOR'}\\${lib}.lib") {
			&error_handle("Not find $LIB_ROOT\\$feature{'CMOS_SENSOR'}\\${lib}.lib");
		}
	}
	else
	{
		if (-e "$LIB_ROOT\\${lib}.lib")
		{
			push @listLink, "$MCU_ROOT\\MoDIS_VC9\\$LIB_ROOT\\${lib}.lib";
		}
		elsif (-e "MoDIS_LIB\\${lib}.lib")
		{
			push @listLink, "$MCU_ROOT\\MoDIS_VC9\\MoDIS_LIB\\${lib}.lib";
		}
		else
		{
			&error_handle("Not find $LIB_ROOT\\${lib}.lib");
		}
	}
}
foreach my $lib (split('\s+',$infomake{'MODIS_EN_OBJS'}))
{
	if ($lib =~ /\.txt/i)
	{
		if (open FILE_HANDLE, "<..\\$lib")
		{
			while(my $line = <FILE_HANDLE>)
			{
				chomp($line);
				if (-e "..\\$line") {
					push @listLink, "$MCU_ROOT\\$line";
				} else {
					&error_handle("Not find $line");
				}
			}
			close FILE_HANDLE;
		}
		else
		{
			&error_handle("Fail to read $lib");
		}
	}
	else
	{
		push @listLink, "$MCU_ROOT\\$lib";
	}
}
my %saw = ();
@listLink = grep (!$saw{$_}++, @listLink);

###############################################################
# Define MoDIS build module list (write in MoDIS.sln)
my @lib_SLN;
my %ENABLE_OPTION;
my %DISABLE_OPTION;
my %ENABLE_INC_PATH;
my %DISABLE_INC_PATH;
my %ENABLE_FILE;
my %DISABLE_FILE;
my %lib_define;
my %lib_include;
my %lib_source;
my %lib_GUID;

###############################################################
# Read all modules' def
my $lib_all_define = '';
my $lib_all_include = '';
my $modis_GUID = createMoDIS::generate($modis_uesim, $modis_uesim, $modis_uesim);
if (open $WRITE_HANDLE, ">$SLN_ROOT/lib_list${modis_suffix}")
{
	foreach my $lib (split('\s+', $infomake{'COMPLIST'}))
	{
		print $WRITE_HANDLE "$lib\n" if ($lib ne "modis");
		&error_handle("$lib redefined in COMPLIST and MODIS_DIS_LIB") if (defined($UN_WIN32_LIB{lc($lib)}));
		my $GUID_input = $lib;
		my $GUID_count = 0;
		my $GUID_value;
		do
		{
			$GUID_value = createMoDIS::generate($GUID_input, $GUID_input, $GUID_input);
			$GUID_input .= "2";
			$GUID_count++;
			if ($GUID_count > 10)
			{
				die "Too many try times from $lib to $GUID_input: $GUID_count";
			}
		} while (is_in_list1($GUID_value, join(' ', values %lib_GUID)));
		$lib_GUID{$lib} = $GUID_value;
		if ($lib ne "modis") {
			push(@lib_SLN, $lib);
		}
		my $compfolder;
		if ((defined $alias{$lib}) && (-e "$MODULE_PATH/$alias{$lib}/${lib}/${lib}.def")) {
			$compfolder = "$MODULE_PATH/$alias{$lib}/${lib}";
		} else {
			$compfolder = "$MODULE_PATH/${lib}";
		}
		my $compdef = "${compfolder}/${lib}.def";
		if (open FILE_HANDLE, "<$compdef")
		{
			my $a;
			while ($a = <FILE_HANDLE>)
			{
				chomp($a);
				next if ($a eq "");
				$lib_define{$lib} .= " " if ($lib_define{$lib} ne "");
				$lib_define{$lib} .= $a;
				$lib_all_define .= " " if ($lib_all_define ne "");
				$lib_all_define .= $a;
			}
			close FILE_HANDLE;
		}
		else
		{
			&error_handle("Fail to read $compdef");
		}
		my $compinc = "${compfolder}/${lib}.inc";
		if (open FILE_HANDLE, "<$compinc")
		{
			my $b;
			while ($b = <FILE_HANDLE>)
			{
				chomp($b);
				$b =~ s/[\\\/]+/\//g;
				$b =~ s/^\.[\\\/]//;
				$b =~ s/[\\\/]$//;
				next if ($b eq "");
				$lib_include{$lib} .= " " if ($lib_include{$lib} ne "");
				$lib_include{$lib} .= $b;
				$lib_all_include .= " " if ($lib_all_include ne "");
				$lib_all_include .= $b;
			}
			close FILE_HANDLE;
		}
		else
		{
			&error_handle("Fail to read $compinc");
		}
		my $complis = "${compfolder}/${lib}.lis";
		if (open FILE_HANDLE, "<$complis")
		{
			my $line;
			while ($line = <FILE_HANDLE>)
			{
				chomp($line);
				$line =~ s/[\\\/]+/\//g;
				$line =~ s/^\.[\\\/]//;
				next if ($line eq "");
				$lib_source{$lib} .= " " if ($lib_source{$lib} ne "");
				$lib_source{$lib} .= $line;
				$lib_all_include .= " " if ($lib_all_include ne "");
				$lib_all_include .= dirname($line);
			}
			close FILE_HANDLE;
		}
		else
		{
			&error_handle("Fail to read $complis");
		}
	}
	close $WRITE_HANDLE;
}
else
{
	&error_handle("Fail to write $SLN_ROOT/lib_list${modis_suffix}");
	die;
}
$ENABLE_OPTION{'comm'} = $lib_all_define;
$DISABLE_OPTION{'comm'} = "STDC_HEADERS";

# To do for auto_header.h
chdir("..");
if ($^O eq "MSWin32")
{
	$lib_all_include = lc($lib_all_include);
}
my %path_conflict;
my $auto_header_write;
my $result_include = createMoDIS::auto_header(\$auto_header_write, \%path_conflict, \$lib_all_include, "MoDIS/$MCU_ROOT", 0);
print $LOG_HANDLE "[Info] Check conflict .h for auto_header\n";
foreach my $key (keys %path_conflict)
{
	next if (($key eq "") || ($key eq $SLN_ROOT));
	print $LOG_HANDLE "[Info] " . $key . "=>" . $path_conflict{$key} . "\n";
}
chdir("MoDIS_VC9");

###############################################################
# Generate each library
print "Generate project file ......\n";
# Define MoDIS gen vcproj list (write to .vcproj)
my @listVcproj;
if ($ARGV[2] ne "")
{
	foreach my $lis (split(/\s+/, $ARGV[2]))
	{
		$lis =~ s/\.(lis|lib)$//i;
		push(@listVcproj, $lis);
	}
}
if ($#listVcproj == -1)
{
	@listVcproj = split('\s+', $infomake{'COMPLIST'});
}


chdir($SLN_ROOT);
foreach my $lib (@listVcproj)
{
	my $par_lib_flag = 0;
	my $FILE_HANDLE;
	if (! -d $lib)
	{
		mkdir($lib) or &error_handle("Fail to mkdir $lib");
	}
	###############################################################
	# read filelist
	my $source_list;
	my @list_set = split('\s+', $lib_source{$lib});
	push @list_set, split('\s+', $ENABLE_FILE{'global'}) if(defined($ENABLE_FILE{'global'}));
	push @list_set, split('\s+', $ENABLE_FILE{$lib}) if(defined($ENABLE_FILE{$lib}));

	my %list_hash;
	foreach my $file (@list_set)
	{
		$file =~ s/^\s+//gs;
		$file =~ s/\s+$//gs;
		next if ($file !~ /\S+/);
		next if ($list_hash{lc($file)});
		if (-e "$lib\\$MCU_ROOT\\$file")
		{
			$source_list .= $MCU_ROOT . "\\" . $file ."\n";
		}
		else
		{
			print $LOG_HANDLE "[Warning] Source file $file is not found in $lib\n";
		}
		$list_hash{lc($file)} = 1;
	}
	$source_list = join("\n", sort(split('\s+', $source_list))) . "\n";

	###############################################################
	# read compile option
	my $compile_option = "";
	my @compile_option_set = split('\s+', $lib_define{$lib});
	push @compile_option_set, split('\s+', $ENABLE_OPTION{'global'}) if(defined($ENABLE_OPTION{'global'}));
	push @compile_option_set, split('\s+', $ENABLE_OPTION{$lib}) if(defined($ENABLE_OPTION{$lib}));

	%saw = ();
	@compile_option_set = sort grep (!$saw{$_}++, @compile_option_set);

	foreach my $flag (@compile_option_set)
	{
		if ($flag =~ /^\d+$/) {
			print $LOG_HANDLE "[Warning] Compile option only define number $flag in $lib\n";
			next;
		}
		if ((!is_in_list1($flag,$DISABLE_OPTION{'global'}) && !is_in_list1($flag,$DISABLE_OPTION{$lib})) || $ENABLE_OPTION{$lib} =~ /\b$flag\b/ || $ENABLE_OPTION{$lib} =~ /\s?$flag\s?/) {
			if ($flag =~ /^\//) {
				$compile_option .= $flag . "\n";
			} else {
				$compile_option .= "/D \"$flag\"\n";
			}
		}
	}

	########################################################################################################
	# read include path
	my $include_path = "";
	my @include_set = split('\s+', $lib_include{$lib});
	push @include_set, split('\s+', $ENABLE_INC_PATH{'global'}) if(defined($ENABLE_INC_PATH{'global'}));
	push @include_set, split('\s+', $ENABLE_INC_PATH{$lib}) if(defined($ENABLE_INC_PATH{$lib}));

	# remove duplicated include path
	%saw = ();
	@include_set = grep (!$saw{$_}++, @include_set);

	foreach my $path (@include_set)
	{
		if ((! exists $path_conflict{lc($path)}) && ($path =~ /^\s*plutommi\b/i))
		{
			next;
		}
		# remove non-existing include path
		if ((-d "$lib\\$MCU_ROOT\\$path") || ($path =~ /header_temp/i) || ($path =~ /\btst\b/i) || ($path =~ /verno/i))
		{
			$include_path .= "/I \"$MCU_ROOT\\$path\"\n";
		}
		else
		{
			print $LOG_HANDLE "[Warning] Include path $path is not found in $lib\n";
		}
	}

	########################################################################################################
	# write .vcproj file
	if ($lib ne "modis")
	{
		createMoDIS::create_lib_vcproj(
			$lib_GUID{$lib},
			$lib,
			"$lib\\${lib}${modis_suffix}.vcproj",
			$compile_option,
			$include_path,
			$source_list,
			$feature{'MMI_VERSION'},
			$par_lib_flag,
			\%ENABLE_OPTION
			);
	}
	else
	{
		createMoDIS::create_main_lib_vcproj(
			$modis_GUID,
			$modis_uesim,
			$compile_option,
			$include_path,
			$source_list,
			$feature{'MMI_VERSION'},
			$infomake{'MODIS_MODE_DEFAULT'},
			\@listLink,
			\%ENABLE_OPTION
			);
	}
}

###############################################################
# Generate main solution
createMoDIS::create_solution(
	$modis_GUID,
	$modis_uesim . ".sln",
	\@lib_SLN,
	\%lib_GUID
	);


###############################################################
# Generate auto_header.h
print "Generating auto_header.h for MAUI\n";

my $auto_header_read = "#error";

if (-e "auto_header.h")
{
	my $saved_sep = $/;
	undef $/;
	open FILE_HANDLE, "<auto_header.h";
	$auto_header_read = <FILE_HANDLE>;
	close FILE_HANDLE;
	$/ = $saved_sep;
}
if ($auto_header_read ne $auto_header_write)
{
	open $WRITE_HANDLE, ">auto_header.h" or &error_handle("Fail to write auto_header.h");
	print $WRITE_HANDLE $auto_header_write;
	close $WRITE_HANDLE;
}
else
{
	print "No need to update auto_header.h\n";
}

&update_modis_ini("MoDIS\\Debug\\MoDIS.ini", "MoDIS\\Debug\\MoDIS.ini");
&update_modis_ini("MoDIS\\Release\\MoDIS.ini", "MoDIS\\Release\\MoDIS.ini");

if ($flag_error)
{
	print STDERR "See gen_modis.log for detail\n";
	die;
}
else
{
	print "createMoDIS.pl done\n";
	exit 0;
}


sub Usage {
  warn << "__USAGE";
Usage:
     ${myname}.pl  MAKEFILE  MoDIS|UESim  [MODULE_LIST]
__USAGE

  exit 1;
}

sub is_in_list1 {
  my $item = shift;
  my $list = shift;

  return 0 if(!defined($list));

  while( $list =~ /(\S+)/g) {
    my $i=$1;
    $i =~ s/\\/\\\\/g;
    return 1 if( $item =~ /^$i\W/is);
    return 1 if( $item =~ /^$i$/is);
    return 1 if( $item =~ /\W$i$/si);
    return 1 if( $item =~ /\W$i\W/si);
  }
  return 0;
}

sub update_modis_ini
{
	my $input = shift;
	my $output = shift;
	if (open FILE_HANDLE, "<$input")
	{
		my $text;
		my $line;
		my $flag;
		while ($line = <FILE_HANDLE>)
		{
			if ($line =~ /^\s*\[(\w+)\]\s*$/)
			{
				if ($1 eq "FeatureOptions")
				{
					$flag = 1;
				}
				else
				{
					$flag = 0;
				}
				$text .= $line;
			}
			elsif ($flag)
			{
				if ($line =~ /^\s*(\w+)\s*=\s*(\w*)\s*$/)
				{
					my $key = uc($1);
					$text .= $key . "=" . $feature{$key} . "\n";
				}
				else
				{
					$text .= $line;
				}
			}
			else
			{
				$text .= $line;
			}
		}
		close FILE_HANDLE;
		if (open FILE_HANDLE, ">$output")
		{
			print FILE_HANDLE $text;
			close FILE_HANDLE;
		}
		else
		{
		}
	}
	else
	{
	}
}


sub error_handle
{
	my $msg = shift;
	print $LOG_HANDLE "[ERROR] " . $msg . "\n";
	close $LOG_HANDLE;
	$flag_error = 1;
	print STDERR $msg . "\n";
}

