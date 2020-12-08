use strict;
use Cwd;
use Win32::Process;
use Win32::OLE;
use Win32;
use File::Basename;
use Net::SMTP;
use constant STILL_ACTIVE => 259;

if ((-e "mtk_tools\\Perl") && ($] >= 5.008006)){
  Parse::CSV->import() if (eval "require Parse::CSV");
  MIME::Lite->import() if (eval "require MIME::Lite");
}

my $test_action = shift @ARGV or &usage();
my $modisDir = shift @ARGV or &usage();

chdir("..") if ($test_action eq "reset_modis");

if (lc($modisDir) eq "undef")
{
	$modisDir = "Release" if (-e "MoDIS\\Release\\MoDIS.exe");
	$modisDir = "Debug" if (-e "MoDIS\\Debug\\MoDIS.exe");
}

if (! -e "MoDIS\\$modisDir\\MoDIS.exe")
{
	die "Cannot find MoDIS\\$modisDir\\MoDIS.exe\n";
}
else
{
	print "start $test_action for MoDIS\\$modisDir\\MoDIS.exe\n";
	mkdir "_BUILD_LOG" if (! -d "_BUILD_LOG");
}
my $MoDIS_poweron_result = 0;
my $cwd = getcwd();
$cwd =~ s/\//\\/g;
$cwd =~ s/\\$//;
my ($theMF, $theVerno);
my ($custom, $project);

if ($test_action eq "ap_modis")
{
	$MoDIS_poweron_result = &MoDIS_auto_power_on_test();
	if ($MoDIS_poweron_result) {
		exit 0;
	} else {
		exit 1;
	}
}
elsif ($test_action eq "reset_modis")
{
	&terminate_process('^(modis.exe)$');
	&win32fs_copy("restore");
	&MoDIS_ini_modify("$cwd\\MoDIS\\$modisDir\\MoDIS.ini");
	chdir("$cwd\\MoDIS\\$modisDir");
	system("$cwd\\MoDIS\\$modisDir\\MoDIS.exe");
}
else
{
	$theMF = shift @ARGV or &usage();
	if (!-e "$theMF")
	{
		die "Fail to open makefile $theMF\n";
	}
	elsif ($theMF =~ /make\\(\w+)_(\w+?)\.mak/i)
	{
		$custom = uc($1);
		$project = uc($2);
	}
	else
	{
		die "The Makefile format should be make\\custom_proj.mak\n";
	}
	if ($test_action eq "rel_at_modis")
	{
		&rel_atMoDIS();
	}
	elsif ($test_action eq "at_modis")
	{
		$theVerno = shift @ARGV or &usage();
		die "Fail to open makefile $theVerno\n" if (!-e "$theVerno");
		&at_MoDIS();
	}
	else
	{
		die "Unknown action: $test_action\n";
	}
}

sub MoDIS_auto_power_on_test
{
	my $modis_env_backup = $ENV{"MoDIS"};
	$ENV{"MoDIS"} = 'AutoPower';
	my $result = 0;
	my $modis_power_log = "_BUILD_LOG\\_PowerOn.log";
	unlink("$modis_power_log") if (-e "$modis_power_log");

	&win32fs_copy();
	print "\n";
	system("perl ../tools/time.pl");
	print("MoDIS Auto PowerOn Test\n");
	chdir("MoDIS\\$modisDir");
	my $MoDIS_Process;
	if ($ENV{"LSF_remote"}) {
		system("call start MoDIS.exe");
	} else {
		Win32::Process::Create($MoDIS_Process,
								"$cwd\\MoDIS\\$modisDir\\MoDIS.exe",
								"MoDIS.exe",
								0,
								CREATE_NEW_CONSOLE,
								"$cwd\\MoDIS\\$modisDir") || assert(Win32::FormatMessage( Win32::GetLastError() ));
	}
	chdir($cwd);

	for (my $i=0; $i<7; $i++)
	{
		sleep 20;
		if (-e "$modis_power_log") {
			open MoDIS_AutoPower, "<$modis_power_log" or assert("Cannot open $modis_power_log\n");
			my $backup = $/;
			undef $/;
			my $MoDIS_AutoPower_Result = <MoDIS_AutoPower>;
			$/ = $backup;
			close MoDIS_AutoPower;
			if ($MoDIS_AutoPower_Result =~ /MoDIS UI Auto Power On succeed/i)
			{
				if ($MoDIS_AutoPower_Result =~ /Target Auto Power On succeed/i)
				{
					$result = 1;
					last;
				}
			}
		}
		else
		{
			last if ($i >= 2);
		}
	}

	unless ($result) {
		# MoDIS auto poweron fail, kill its process
		if ($ENV{"LSF_remote"}) {
			&terminate_process('^(modis.exe)$');
		} else {
			$MoDIS_Process->Kill(STILL_ACTIVE);
		}
		print("      ==> [Fail]\n\n");
	}
	else
	{
		if ($ENV{"LSF_remote"}) {
			&terminate_process('^(modis.exe)$', 20);
		} else {
			$MoDIS_Process->Wait(20000);
			$MoDIS_Process->Kill(STILL_ACTIVE);
		}
		print("      ==> [P]\n\n");
	}
	$ENV{"MoDIS"} = $modis_env_backup;
	return $result;# 0 for fail, 1 for pass
}

sub at_MoDIS
{
  unless ($] >= 5.008006){
    assert("Perl package doesn't exist or Perl version is less then 5.008006. Your Perl version is $]\n");
  }

  # for VS2008, cwd = mcu\MoDIS_VC9
  #chomp(my $cwd = `cd`);

  my $exec_time      = time;
  my $curr_usr       = lc(getlogin()) or assert("can't get your login name\n$!\n");
  my $computerName   = $ENV{"COMPUTERNAME"};
  my $notify_list    = "\\\\glbfs14\\sw_releases\\3rd_party\\Scripts\\BM_conf.ini";
  my $NetSim         = "$cwd\\NetSim\\NetSim.exe";
  my $Catcher        = "$cwd\\Catcher\\Catcher.exe";
  my $MoDIS          = "$cwd\\MoDIS\\${modisDir}\\MoDIS.exe";
  my $MSC_log        = "$cwd\\Catcher\\report.csv";
  my $MoDIS_database = "$cwd\\..\\tst\\database_modis\\BPGUInfoCustomApp_pc";
  my $MoDIS_iniFILE  = "$cwd\\MoDIS\\${modisDir}\\MoDIS.ini";
  my $catcher_source = '';
  my $autotest_init  = "$cwd\\atMoDIS_autotest_init.tcl";
  my $autotest_init2 = "$cwd\\Catcher\\autotest_init.tcl";
  my $info_log       = "$cwd\\..\\build\\$custom\\log\\info.log";
  my $info_log2      = "$cwd\\Catcher\\info.log";
  my $mmi_fea_log    = "$cwd\\..\\build\\$custom\\log\\MMI_features.log";
  my $mmi_fea_log2   = "$cwd\\Catcher\\MMI_features.log";
  my $email_notify   = "$cwd\\atMoDIS_email_notify.pl";
  my $MSC_workspace  = "$cwd\\MSC_TestCase\\${custom}_${project}.msc";
     $MSC_workspace  = "$cwd\\MSC_TestCase\\MoDIS.msc" unless (-e $MSC_workspace);

  my %feature;
		open FILEHANDLE, "<$theMF" or die "Fail to open $theMF\n";
		while (my $line=<FILEHANDLE>)
		{
			$line =~ s/\#.*//;
			if ($line =~ /^\s*(FLAVOR|MMI_VERSION)\s*=\s*(\w+)\s*$/)
			{
				my $key = lc($1);
				$feature{$key} = $2;
			}
		}
		close FILEHANDLE;
  my $flavor = $feature{'flavor'};
  my $mmi_version = $feature{'mmi_version'};

  my $CustMenuTree   = "$cwd\\..\\" . (($mmi_version eq 'NEPTUNE_MMI')?'lcmmi':'plutommi')
                       . "\\Customer\\CustResource\\CustMenuTree_Out.c";

  assert("$NetSim not exist !!\n")         unless (-e $NetSim);
  assert("$MoDIS not exist !!\n")          unless (-e $MoDIS);
  assert("$MoDIS_database not exist !!\n") unless (-e $MoDIS_database);
  assert("$MoDIS_iniFILE not exist !!\n")  unless (-e $MoDIS_iniFILE);
  assert("$autotest_init not exist !!\n")  unless (-e $autotest_init);
  assert("$info_log not exist !!\n")       unless (-e $info_log);
  assert("$mmi_fea_log not exist !!\n")    unless (-e $mmi_fea_log);
  assert("$email_notify not exist !!\n")   unless (-e $email_notify);
  assert("$MSC_workspace not exist !!\n")  unless (-e $MSC_workspace);
  assert("$CustMenuTree not exist !!\n")   unless (-e $CustMenuTree);

  #*----------------------------------------------------------------------------*
  #* Parsing the network path name
  #*----------------------------------------------------------------------------*
  my $full_path = &get_net_path();
  my $temp_cwd = $cwd;
  my $MSC_workspace_full_path = $MSC_workspace;
  $temp_cwd =~ s/\\/\\\\/gi;
  $MSC_workspace_full_path =~ s/$temp_cwd/$full_path/i;

  #*----------------------------------------------------------------------------*
  #* Get Catcher source path
  #*----------------------------------------------------------------------------*
  my $catcher_source;
  unless (-e $Catcher)
  {
    my @catcher_srcs = qw(
      \\\\glbfs14\\sw_releases\\Wireless_Global_Tools\\Tool_Release_MTKHQ_only\\Catcher
      \\\\glbfs14\\WCP\\MBJ\\tool_release\\Catcher
      \\\\glbfs14\\WCP\\MSZ\\tool_release\\Catcher
      \\\\glbfs14\\WCP\\PMT\\tool_release\\Catcher
    );

    foreach (@catcher_srcs)
    {
      next if (!-d $_);
      $catcher_source = $_;
      last;
    }

    assert("Could NOT find Catcher source\n") if ($catcher_source eq '');
  }

  #*----------------------------------------------------------------------------*
  #* Before MoDIS auto test, be sure MoDIS auto power on is success
  #*----------------------------------------------------------------------------*
  if ((!$MoDIS_poweron_result) && (-e $MoDIS))
  {
    $ENV{"MoDIS"} = 'AutoPower';
    $MoDIS_poweron_result = &MoDIS_auto_power_on_test;
    $ENV{"MoDIS"} = 'Null';
  }

  #*----------------------------------------------------------------------------*
  #* Start MoDIS auto test procedure
  #*----------------------------------------------------------------------------*
  if (!$MoDIS_poweron_result)
  {
    print "\nMoDIS auto power on fail, stop MoDIS auto test procedure !!\n\n";
    exit 1;
  }
  else
  {
    #*----------------------------------------------------------------------------*
    #* Getting latest Catcher, if Catcher not exist
    #*----------------------------------------------------------------------------*
    unless (-e $Catcher)
    {
      my $catcher_ver = 0;
      my $catcher_source_path = '';

      if (opendir(CATCHER_SOURCE, $catcher_source))
      {
        foreach (sort readdir(CATCHER_SOURCE))
        {
          if (/^\[(\d+)\.(\d+)\.(\d+)\]Catcher$/i) # match [X.X.XX]Catcher
          { 
            # compare catcher version, to get the latest one
            if (("$1$2$3") > $catcher_ver)
            {
              $catcher_ver = "$1$2$3";
              $catcher_source_path = "$catcher_source\\$_"; # The latest catcher source path
            }
          }
        }
        closedir(CATCHER_SOURCE);
      }
      else
      {
        assert("Could not open $catcher_source !!\n");
      }

      # Mirror catcher source to local
      if (-e $catcher_source_path)
      {
        print ("\nGetting Catcher from $catcher_source_path ...\n");
        system("call robocopy $catcher_source_path " . dirname($Catcher) . " /MIR /NP /LOG:_BUILD_LOG\\robo_catcher.log");

        # add personal handling
        print ("\ncall copy /Y $autotest_init $autotest_init2\n");
        system("call copy /Y $autotest_init $autotest_init2 >NUL");
        assert("$autotest_init2 not exist !!\n") unless (-e $autotest_init2);

        print ("\ncall copy /Y $info_log $info_log2\n");
        system("call copy /Y $info_log $info_log2 >NUL");
        assert("$info_log2 not exist !!\n") unless (-e $info_log2);

        print ("\ncall copy /Y $mmi_fea_log $mmi_fea_log2\n");
        system("call copy /Y $mmi_fea_log $mmi_fea_log2 >NUL");
        assert("$mmi_fea_log2 not exist !!\n") unless (-e $mmi_fea_log2);
      }
      else
      {
        assert("Unknow path : $catcher_source_path\n");
      }
    }
    #*----------------------------------------------------------------------------*
    #* End of Getting latest Catcher, if Catcher not exist
    #*----------------------------------------------------------------------------*

    #*----------------------------------------------------------------------------*
    #* Replace MoDIS.ini to support auto power on
    #*----------------------------------------------------------------------------*
    &MoDIS_ini_modify($MoDIS_iniFILE);
    #*----------------------------------------------------------------------------*
    #* End of Replace MoDIS.ini to support auto power on
    #*----------------------------------------------------------------------------*

    #*----------------------------------------------------------------------------*
    #* Starting auto test
    #*----------------------------------------------------------------------------*
    print "\n";
    system("perl ../tools/time.pl");
    print("MoDIS Auto Test\n");

    my $MoDIS_Process;
    my $Catcher_Process;
    my $NetSim_Process;
    if ($ENV{"LSF_remote"})
    {
      # Start MoDIS
      chdir(dirname($MoDIS));
      system("start $MoDIS");

      # Start Catcher
      chdir(dirname($Catcher));
      system("start $Catcher \"$MoDIS_database\"");

      sleep 30;

      # Start NetSim
      chdir(dirname($NetSim));
      system("start $NetSim \"$MSC_workspace\" Modis \"" . dirname($MSC_workspace) . "\" $CustMenuTree run");
      
      chdir($cwd);
    }
    else
    {
      # Start MoDIS
      Win32::Process::Create($MoDIS_Process,
                             $MoDIS,
                             "MoDIS.exe",
                             0,
                             CREATE_NEW_CONSOLE,
                             dirname($MoDIS)) || assert(Win32::FormatMessage( Win32::GetLastError() ));

      # Start Catcher
      Win32::Process::Create($Catcher_Process,
                             $Catcher,
                             "Catcher.exe \"$MoDIS_database\"",
                             0,
                             CREATE_NEW_CONSOLE,
                             dirname($Catcher)) || assert(Win32::FormatMessage( Win32::GetLastError() ));

      # wait for MoDIS initial
      sleep 30;

      # Start NetSim
      Win32::Process::Create($NetSim_Process,
                             $NetSim,
                             "NetSim.exe \"$MSC_workspace\" Modis \"" . dirname($MSC_workspace) . "\" $CustMenuTree run",
                             0,
                             CREATE_NEW_CONSOLE,
                             dirname($NetSim)) || assert(Win32::FormatMessage( Win32::GetLastError() ));
    }

    # Waiting for test case finish
    sleep 60;
    while(!(rename($MSC_log, "${MSC_log}.tmp"))) {
      sleep 30;
    }
    rename("${MSC_log}.tmp", $MSC_log);
    $exec_time = time - $exec_time;
    #*----------------------------------------------------------------------------*
    #* End of Starting auto test
    #*----------------------------------------------------------------------------*

    #*----------------------------------------------------------------------------*
    #* Parsing MSC report
    #*----------------------------------------------------------------------------*
    # Transform every row into one line
    my $temp_csv = '';
    open CSV_FILE, "<$MSC_log" or assert("\ncannot open $MSC_log\n\n");
    while (<CSV_FILE>)
    {
      my $line = $_;
      unless ($line =~ /\"\s$/i)
      {
        $line =~ s/\s$//i;
        chomp($line);
        $line .= '<br>';
      }
      $temp_csv .= $line;
    }
    close CSV_FILE;

    open TEMP_CSV, ">MSC_report.csv" or assert("\ncannot open MSC_report.csv\n\n");
    print TEMP_CSV $temp_csv;
    close TEMP_CSV;

    # Parse CSV file
    my $parser = Parse::CSV->new(
      file     => 'MSC_report.csv',
      csv_attr => {
        sep_char   => ',',
        quote_char => '"',
      },
    );

    my $is_fail = 0;
    my $html_output = '';
    my $ci_output = "# Test Result\n\n";

    while ( my $value = $parser->fetch )
    {
      # @$value[0]: MSC
      # @$value[1]: PASS
      # @$value[2]: FAIL
      # @$value[3]: N/A
      # @$value[4]: REASON
      print "@$value[0]\n";
      unless(@$value[1])
      {
        $is_fail = 1;
      }
      if ((@$value[0] eq 'Total') && (@$value[4]) eq '')
      {
        $is_fail = 0 if (@$value[2] == 0);
      }

      # Generating CI output
      if (lc(@$value[0]) ne 'msc' && lc(@$value[0]) ne 'total')
      {
        $ci_output .= "MSC:    @$value[0]\n";
        $ci_output .= "PASS:   @$value[1]\n";
        $ci_output .= "FAIL:   @$value[2]\n";
        $ci_output .= "NA:     @$value[3]\n";
        $ci_output .= "REASON: @$value[4]\n";
        $ci_output .= "\n";
      }

      # Generating HTML format output
      @$value[0] = (@$value[0])?@$value[0]:'&nbsp;';
      @$value[1] = (@$value[1])?@$value[1]:'&nbsp;';
      @$value[2] = (@$value[2])?@$value[2]:'&nbsp;';
      @$value[3] = (@$value[3])?@$value[3]:'&nbsp;';
      @$value[4] = (@$value[4])?@$value[4]:'&nbsp;';
      $html_output .= "<TR>
                         <td class=my_td align=left>
                           @$value[0]
                         </td>
                         <td class=my_td width=80 align=center>
                           @$value[1]
                         </td>
                         <td class=my_td width=80 align=center>
                           @$value[2]
                         </td>
                         <td class=my_td width=80 align=center>
                           @$value[3]
                         </td>
                         <td class=my_td width=100>
                           @$value[4]
                         </td>
                       </TR>\n";
    }

    undef $parser;
    unlink('MSC_report.csv');
    #*----------------------------------------------------------------------------*
    #* End of Parsing MSC report
    #*----------------------------------------------------------------------------*


    #*----------------------------------------------------------------------------*
    #* Send MSC report
    #*----------------------------------------------------------------------------*
    my %BM_conf = iniToHash($notify_list) if (-e $notify_list);

    unless ($ENV{"CI_BUILD"} && !(($is_fail) || ($html_output eq '')))
    {
      my $email_list;
      my $msg;
      if (-e $notify_list)
      {
        if ($ENV{"CI_BUILD"})
        {
          $email_list = $BM_conf{'atMoDIS'}->{'CI_NOTIFY_LIST'};
        }
        else
        {
          $email_list = $BM_conf{'atMoDIS'}->{'EMAIL_NOTIFY_LIST'} . ",$curr_usr";
        }
      }
      else
      {
        $email_list = $curr_usr;
      }

      MIME::Lite->send('smtp', 'smtp.mediatek.inc', Timeout=>60);
      $msg = MIME::Lite->new(
        From     => $curr_usr,
        To       => $email_list,
        subject  => "[Script Notify][$custom] MoDIS auto test result - ".((($is_fail) || ($html_output eq ''))?'FAIL':'PASS'),
        Type     => 'multipart/related',
        Datestamp=> 0
      );
      $msg->attach(Type => 'text/html',
        Data => qq{
          <FONT face=Verdana size=2>
          <B>PROJECT:</B> $custom<br>
          <B>MODEM:</B> $project<br>
          <B>EXEC_MACHINE:</B> $computerName<br>
          <B>EXEC_PATH:</B> $cwd<br>
          <B>EXEC_TIME:</B> $exec_time<br>
          <B>CODEBASE:</B> $full_path<br>
          <B>MSC PATH:</B> $MSC_workspace_full_path<br>
          </FONT>
          <br>
          <br>
          <style>
            .my_td
            {
              border: 1px solid #ddd;
              vertical-align: middle;
              font-family: Verdana;
              font-size: 12px;
            }
          </style>
          <table style="border: 1px solid #ddd;">
            $html_output
          </table>
        }
      );
      $msg->send();
    }
    #*----------------------------------------------------------------------------*
    #* End of Send MSC report
    #*----------------------------------------------------------------------------*

    #*----------------------------------------------------------------------------*
    #* Send MSC report for CI
    #*----------------------------------------------------------------------------*
    if (-e $BM_conf{'atMoDIS'}->{'CI_LOG_PATH'})
    {
      my $ci_log = $BM_conf{'atMoDIS'}->{'CI_LOG_PATH'} . "\\" . time . ".log";
      my $verno;
      my $branch;
      my $hw_ver;
      if (-e "..\\$theVerno")
      {
        open(VERNO, "..\\$theVerno") || die "Can not open verno file!";
        while (<VERNO>)
        {
          chomp;
          $verno  = $1 if (/VERNO\s*=\s*([^\s]*)/i);
          $branch = $1 if (/BRANCH\s*=\s*([^\s]*)/i);
          $hw_ver = $1 if (/HW_VER\s*=\s*([^\s]*)/i);
        }
        close(VERNO);
      }

      my $ci_output_header = "# Project Information\n\n";

      $ci_output_header .= "PROJECT:      $custom\n";
      $ci_output_header .= "FLAVOR:       $flavor\n";
      $ci_output_header .= "MODEM:        $project\n";
      $ci_output_header .= "BRANCH:       $branch\n";
      $ci_output_header .= "VERNO:        $verno\n";
      $ci_output_header .= "HW_VER:       $hw_ver\n";
      $ci_output_header .= "EXEC_TIME:    $exec_time\n";
      $ci_output_header .= "EXEC_MACHINE: $computerName\n";
      $ci_output_header .= "EXEC_PATH:    $cwd\n";
      $ci_output_header .= "CODEBASE:     $full_path\n";
      $ci_output_header .= "MSC_PATH:     $MSC_workspace_full_path\n";
      $ci_output_header .= "\n";
      $ci_output_header .= "\n";

      $ci_output = $ci_output_header . $ci_output;

      open CI_LOG, ">$ci_log" or die "\nCannot open $ci_log\n\n";
      print CI_LOG $ci_output;
      close CI_LOG;
    }
    #*----------------------------------------------------------------------------*
    #* End of Send MSC report for CI
    #*----------------------------------------------------------------------------*

    #*----------------------------------------------------------------------------*
    #* Terminate processes
    #*----------------------------------------------------------------------------*
    unless (($is_fail) || ($html_output eq '') || $ENV{"LSF_remote"})
    {
      $MoDIS_Process->Kill(STILL_ACTIVE);
      $Catcher_Process->Kill(STILL_ACTIVE);
      $NetSim_Process->Kill(STILL_ACTIVE);
    }

    if ($ENV{"LSF_remote"} || $ENV{"CI_BUILD"})
    {
      &terminate_process('^(modis\.exe|catcher\.exe|netsim\.exe)$');
    }

    # Recover file system
    &win32fs_copy("restore");

    #*----------------------------------------------------------------------------*
    #* End of Terminate processes
    #*----------------------------------------------------------------------------*

    print ((($is_fail) || ($html_output eq ''))?"      ==> [Fail]\n\n":"      ==> [P]\n\n");
  }

}

sub rel_atMoDIS {
	my @script_path = qw(
		\\\\mtkrs12\\Software_Management_Material\\Script\\3rd_party\\Scripts\\MoDIS_AutoTest\\rel_atMoDIS.pl
		\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\MoDIS_AutoTest\\rel_atMoDIS.pl
		\\\\glbfs14\\WCP\\sw_releases\\3rd_party\\Scripts\\MoDIS_AutoTest\\rel_atMoDIS.pl
		);

	foreach (@script_path)
	{
		next if (!-e);
		print("perl $_ $theMF\n");
		system("perl $_ $theMF");
		last;
	}
}

sub assert
{
	if ($ENV{"LSF_remote"})
	{
		&terminate_process('^(modis.exe|catcher.exe|netsim.exe)$');
	}
	# Recover file system
	&win32fs_copy("restore");
	print $_[0];
	exit 1;
}

sub terminate_process
{
	my $reg_exp = $_[0] or die;
	my $timeout_limit = 0;
	if (defined $_[1])
	{
		$timeout_limit = $_[1];
	}
	my $timeout_start = 0;

	while ($timeout_start <= $timeout_limit)
	{
		my $is_found = 0;
		my $objWMI = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2');
		my $colProcesses = $objWMI->InstancesOf('Win32_Process');
		foreach my $objProcess (in $colProcesses)
		{
			if ($objProcess->Name =~ /$reg_exp/i)
			{
				if ($timeout_start < $timeout_limit)
				{
					$is_found = 1;
				}
				else
				{
					my $objName = $objProcess->Name;
					my $objPID = $objProcess->ProcessID;
					my $objWMIProcess = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2:Win32_Process.Handle=\'' . $objPID . '\'');
					my $intRC = $objWMIProcess->Terminate();
					if ($intRC)
					{
						print "Could not kill process \"$objName\" (PID=$objPID). Error code: " . $intRC, "\n";
					}
				}
			}
		}
		$timeout_start++;
		if ($is_found == 0)
		{
			last;
		}
		sleep 1;
	}
}

sub win32fs_copy
{
	my $win32fs_flag = shift @_;
	my $win32fs_dst = "WIN32FS";
	my $win32fs_src = "WIN32FS_BAK";

	if ((-e "$win32fs_src") && ($win32fs_flag ne "backup"))
	{
		# Restore file system
		print ("robocopy $win32fs_src $win32fs_dst /LOG:_BUILD_LOG\\robo_win32fs.log\n");
		system("robocopy $win32fs_src $win32fs_dst /MIR /R:3 /W:3 /LOG:_BUILD_LOG\\robo_win32fs.log /NP >NUL");
	}
	elsif ((-e "$win32fs_dst") && ($win32fs_flag ne "restore"))
	{
		# Backup file system
		print ("robocopy $win32fs_dst $win32fs_src /LOG:_BUILD_LOG\\robo_win32fs.log\n");
		system("robocopy $win32fs_dst $win32fs_src /MIR /LOG:_BUILD_LOG\\robo_win32fs.log /NP >NUL");
	}
}

sub MoDIS_ini_modify
{
	my $MoDIS_iniFILE = shift @_;
	my $ini_flag = 0;
	my $ini_output = '';
	open FILE, "<$MoDIS_iniFILE" or assert("\nCannot open $MoDIS_iniFILE\n\n");
	while (<FILE>)
	{
		$ini_flag = 1 if (/^\s*\[AutoTest\]\s*/i);
		if ($ini_flag && /^\s*MoDIS\s*=\s*(\w+)\s*/i) # match MoDIS = XXXX
		{
			$ini_output .= "MoDIS = Reboot\n";
		}
		else
		{
			$ini_output .= $_;
		}
	}
	close FILE;

	if (!$ini_flag)
	{
		$ini_output .= "[AutoTest]\nMoDIS = Reboot\n\n";
	}

	open OUTPUT_FILE, ">$MoDIS_iniFILE";
	print OUTPUT_FILE $ini_output;
	close OUTPUT_FILE;
}

sub iniToHash {
  open(MYINI, $_[0]);
  my %hash;
  my $hashref;

  while(<MYINI>)
  {
    next if ((/^\s*$/) || (/^\s*#/));
    if (/^\s*\[(.+)\]/)
    {
      $hashref = $hash{$1} ||= {};
    }
    elsif (/^\s*(\S+)\s*=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $2;
    }
    elsif (/^\s*(\S+)\s*\+=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $hashref->{$1} . " $2";
    }
  }

  close MYINI;
  return %hash;
}

sub get_net_path
{
	my $full_path;
	if ($ENV{"LSF_remote"})
	{
		$full_path = $ENV{"LSF_remote"} . "\\MoDIS_VC9";
	}
	else
	{
		my $device_name = substr($cwd, 0, 2);
		my $path_name = substr($cwd, 2);
		my @net_use_result = `net use $device_name 2>&1`;
		($full_path) = ($net_use_result[1] =~ /\s+(\\\\.*)\s*$/);
		$full_path = ($full_path)?($full_path.$path_name):$cwd;
	}
	return $full_path;
}

sub usage
{
	warn << "__END_OF_USAGE";
Usage:
modisAutoTest.pl ap_modis Debug|Release
                 reset_modis Debug|Release
                 email_notify Debug|Release
                 rel_at_modis Debug|Release custom_project.mak
                 at_modis Debug|Release custom_project.mak verno.bld

__END_OF_USAGE

	exit 1;
}