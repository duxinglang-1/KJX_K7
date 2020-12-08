use strict;
use warnings;
use Cwd;
if ($#ARGV != 1)
{
	die "modisDepend.pl <Debug|Release> <reduce_header_depth>\n";
}

my $release = shift @ARGV;
my $reduce_header_depth = shift @ARGV;
my $MoDISLogDir = "_BUILD_LOG";
my $MoDISDepDir = "_BUILD_DEP";
my $MoDISMcuDir = "..";
my $MoDISVc9Dir = "..\\..\\MoDIS_VC9";

my $get_log_modis;
if ($reduce_header_depth =~ /TRUE/i)
{
	$get_log_modis = 1;
}
else
{
	$get_log_modis = 0;
}
my $flag_showinclude = 0;
my $num_process = $ENV{NUMBER_OF_PROCESSORS};
my $max_process = 8;
$num_process = int($num_process/2);
if ($num_process >= $max_process)
{
	$num_process = $max_process;
}
elsif ($num_process <= 0)
{
	$num_process = 1;
}

my $current = getcwd();
#$current =~ s/^(.*\/)(\S+?)$/$1/;
$current .= "\\" . $MoDISMcuDir . "\\";
$current =~ s/[\/\\]+/\\/g;
while ($current =~ /\w+\\\.\.\\/)
{
	$current =~ s/\w+\\\.\.\\//;
}
$current =~ s/[\/\\]+/\\\\/g;

mkdir($MoDISDepDir) if (! -d $MoDISDepDir);

my @lib_list;
my @err_list;
my %child_list;

if ((-e "lib_list") && (open(LOGF, "<lib_list")))
{
	while (my $module = <LOGF>)
	{
		chomp($module);
		next if (!-e "$module\\${module}.ini");
		next if (!-e "$module\\${module}.vcproj");
		if (($module eq "cosmos_app") || ($module eq "mmi_app"))
		{
			# let large modules be ahead of others
			unshift(@lib_list, "$module");
		}
		else
		{
			push(@lib_list, "$module");
		}
	}
	close(LOGF);
}

# Workaround: mspdbsrv.exe will stay alive for 10 min after build, cause bsub wait to exit
if ((defined $ENV{"LSB_JOBID"}) && ($ENV{"LSB_JOBID"} ne ""))
{
	my $pid = fork();
	die "Cannot fork:$!" if (! defined $pid);
	if ($pid == 0)
	{
		# child
		exec("mspdbsrv.exe -start -spawn -shutdowntime -1");
		exit 1;
	}
}

foreach my $module (@lib_list)
{
	while (scalar (keys %child_list) > $num_process)
	{
		&wait_child();
	}
	my $pid = fork();
	die "Cannot fork:$!" if (! defined $pid);
	if ($pid == 0)
	{
		#child
		my ($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
		my $timeStr = sprintf("%4.4d/%2.2d/%2.2d %2.2d:%2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
		print("$timeStr vcbuild \"$module\\${module}.vcproj\" \"$release|Win32\" /logfile:\"_BUILD_LOG\\${module}.log\"\n\n");
		if ($flag_showinclude)
		{
			system("vcbuild /override:$MoDISVc9Dir\\depend.vsprops \"$module\\${module}.vcproj\" \"$release|Win32\" /logfile:\"_BUILD_LOG\\${module}.log\" >nul");
			&ParseLog($module);
		}
		else
		{
			system("vcbuild /nologo \"$module\\${module}.vcproj\" \"$release|Win32\" /logfile:\"_BUILD_LOG\\${module}.log\" >nul");
		}
		exit 1;
	}
	else
	{
		# parent
		$child_list{$pid} = $module;
	}
}

while (scalar (keys %child_list) > 0)
{
	&wait_child();
}
my ($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
my $timeStr = sprintf("%4.4d/%2.2d/%2.2d %2.2d:%2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
print("$timeStr vcbuild \"MoDIS.sln\" \"$release|Win32\" /logfile:\"_BUILD_LOG\\MoDIS.log\"\n\n");
my $res;
if ($flag_showinclude)
{
	$res = system("vcbuild /override:$MoDISVc9Dir\\depend.vsprops \"MoDIS.sln\" \"$release|Win32\" >nul");
	&ParseLog("MoDIS");
}
else
{
	$res = system("vcbuild /nologo \"MoDIS.sln\" \"$release|Win32\" /logfile:\"_BUILD_LOG\\MoDIS.log\" >nul");
}

if ((defined $ENV{"LSB_JOBID"}) && ($ENV{"LSB_JOBID"} ne ""))
{
	system("mspdbsrv.exe -stop");
}

foreach my $module (@lib_list)
{
	if (-e "$module\\$release\\$module.lib")
	{
		print("	$module	==> [Pass]\n");
	}
	else
	{
		push(@err_list, "$module");
	}
}
if (($res == 0) && (-e "MoDIS\\$release\\MoDIS.exe"))
{
	print("	MoDIS	==> [Pass]\n");
}
else
{
	push(@err_list, "MoDIS");
}
foreach my $module (@err_list)
{
	print("	$module	==> [Fail]\n");
}
if ($#err_list == -1)
{
	exit 0;
}
else
{
	exit 1;
}

sub wait_child
{
	my $pid = wait();
	return 0 if ($pid == -1);
	delete $child_list{$pid};
	return 1;
}

sub ParseLog
{
	my $module = shift @_;
	my $moduleLog = "$MoDISLogDir\\$module.log";
	unlink("$MoDISDepDir\\$module.dep") if (-e "$MoDISDepDir\\$module.dep");
	if ($module eq "MoDIS")
	{
		#$moduleLog = "$MoDISLogDir\\${module}_1.log";
	}
	unlink($moduleLog) if (-e $moduleLog);
	if (!-e "$module\\$release\\BuildLog.htm")
	{
		warn "Not found $module\\$release\\BuildLog.htm\n";
		return 1;
	}
	open INPUTLOG, "<:raw:encoding(UTF16):crlf:utf8", "$module\\$release\\BuildLog.htm" or return 1;
	open OUTPUTLOG, ">$moduleLog" or return 0;
	my $boolDep = 0;
	my $line;
	my $fileObj = "";
	while ($line=<INPUTLOG>)
	{
		if ($line =~ /^Output Window$/)
		{
			$boolDep = 1;
			next;
		}
		elsif ($line =~ /^Results$/)
		{
			$boolDep = 1;
			next;
		}
		if ($boolDep)
		{
			chomp($line);
			$line =~ s/\<.*?\>//g;
			$line =~ s/\&nbsp\;//g;
			$line =~ s/^\d+\>//;
			if ($line =~ /^(\w+)\.(c|cpp|s)$/i)
			{
				print OUTPUTLOG "$line\n";
				if ($fileObj ne "")
				{
					close OUTPUTDEP;
				}
				$fileObj = $1;
				if ($fileObj eq "")
				{
					die "Filename = $fileObj\n";
				}
				open OUTPUTDEP, ">$module\\$release\\$fileObj.d";
				next;
			}
			elsif ($line =~ /Note: including file:\s*(.*)$/i)
			{
				my $fileInc = $1;
				next if ($fileInc =~ /C:\\/i);
				next if ($fileInc =~ /auto_header\.h/i);
				$fileInc =~ s/^$current//i;
				print OUTPUTDEP "$fileObj.obj:	$fileInc\n";
			}
			else
			{
				print OUTPUTLOG "$line\n";
			}
		}
	}
	close OUTPUTDEP;
	close OUTPUTLOG;
	close INPUTLOG;

	opendir DIRHANDLE, "$module\\$release";
	my @fileDep = readdir DIRHANDLE;
	closedir DIRHANDLE;
	foreach my $dep (@fileDep)
	{
		next if ($dep !~ /^\w+\.d$/);
		#system("(perl ..\\tools\\pack_dep.pl $module\\$release\\$dep ..\\tools\\copy_mmi_include_h.bat >> $MoDISDepDir\\$module.dep) && (del $module\\$release\\$dep)");
		system("perl $MoDISMcuDir\\tools\\pack_dep.pl $module\\$release\\$dep $MoDISMcuDir\\tools\\copy_mmi_include_h.bat >>$MoDISDepDir\\$module.dep");
		unlink("$module\\$release\\$dep");
	}
	if ($get_log_modis)
	{
		system("perl $MoDISMcuDir\\tools\\get_log_modis.pl $moduleLog $MoDISMcuDir\\tools\\copy_mmi_include_h.bat");
	}
	if ((lc($module) ne "modis") && (-e "$module\\$release\\$module.lib"))
	{
		#print("	$module	==> [Pass]\n");
		return 0;
	}
	elsif ((lc($module) eq "modis") && (-e "$module\\$release\\$module.exe"))
	{
		#print("	$module	==> [Pass]\n");
		return 0;
	}
	else
	{
		#print("	$module	==> [Fail]\n");
		return 1;
	}
}
