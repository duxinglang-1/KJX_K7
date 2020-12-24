#!/usr/local/bin/perl

$custom = "";
$custom_ = "";
$customer_name = "";
$sub_customer_name = "";
$project = "GPRS";
$ini = "make.ini";
$bld_name = "";
$mak_name = "";
$chip_ver = "";
$VERNO = "";
$release_dir = "build";
$db_file = "";
$bin_folder = "";
$elf_file = "";
$sym_file = "";
$dbginfo_file = "";
$mail_body = ".\\$release_dir\\mail_body.txt";
$version_dir = "";
$mail_flag = 0;
#映射到本地的盘符，可根据实际情况修改
#$server_path = "M:\\外放版软件";
$server_path = "Z:\\量产软件版本\\A62";
if ($#ARGV == 1) {
    if ($ARGV[0] =~ /-mail/i) {
    	$mail_flag = 1;
    	$custom = $ARGV[1];
    } else {	
       $custom = $ARGV[0];
    }
} elsif ($#ARGV == 0) {
    if ($ARGV[0] =~ /-mail/i) {
    	$mail_flag = 1;
    } else {	
       $custom = $ARGV[0];
    }
}
if ($mail_flag == 1){
    my $flat_set = "d:\\flatsetting\\flat.ini";
    if (!-e $flat_set) {
    	CheckMailSet();
    	exit 1;
    }
}
if (($custom eq "")&&(-e $ini)) {
   	   open (FILE_HANDLE, "<$ini") or die "cannot open $ini\n>>>可能您还没有完整编译过项目<<<\n";
   	   while (<FILE_HANDLE>) {
            if (/^(\S+)\s*=\s*(\S+)/) {
              $keyname = $1;
              $${keyname} = $2;
              chomp($${keyname});
            }
        }
        close FILE_HANDLE;
}
$bld_name = "make\\Verno_${custom}.bld";
$mak_name = "make\\${custom}_${project}.mak";
if (-e "$mak_name") {
   my $flash_size = GetFeature($mak_name, "SIP_SERIAL_FLASH_SIZE");
   my $plat = GetFeature($mak_name, "PLATFORM");
   $customer_name = GetFeature($mak_name, "CUSTOMER_NAME");
   $sub_customer_name = GetFeature($mak_name, "SUB_CUSTOMER_NAME");
   if ($plat eq "MT6260") {
       if ($flash_size eq "NONE") {
          $chip_ver = "MT6260";
       } elsif ($flash_size eq "32M_BITS") {
          $chip_ver = "MT6260D";
       } elsif ($flash_size eq "24M_BITS") {
          $chip_ver = "MT6260M";
       } 
   }
} else{
	print(">>>您还没有创建和编译该项目<<<\n");
	exit 1;
}

if (-e "$bld_name") {
   open (FILE_HANDLE, "<$bld_name") or die "cannot open $bld_name\n";
   while (<FILE_HANDLE>) {
        if (/^(\S+)\s*=\s*(\S+)/) {
          $keyname = $1;
          $${keyname} = $2;
          chomp($${keyname});
          last;
        }
    }
    close FILE_HANDLE;
} else{
	print(">>>您还没有创建和编译该项目<<<\n");
	exit 1;
}

if (!-d $release_dir) {
   mkdir("$release_dir");
}
my $build_date = getTime();
my $build_date = $build_date->{date};
$version_dir = "${VERNO}_${build_date}";
#$version_dir = "${VERNO}";
if (-e "$release_dir\\$version_dir") {
    use File::Path;
    -d $_?rmtree($_):unlink $_ foreach (<$release_dir/$version_dir/*>);
} else {
	print "create dir $version_dir\n";
	mkdir("$release_dir\\$version_dir");
}

my $db_dir = "./tst/database_classb";
my $file;
my @dir;
my $verno_ = $VERNO;
$verno_ =~ s/\./_/g;
opendir(DIR, $db_dir) or die "can't open the directory ${db_dir}!";
@dir = readdir DIR;
closedir(DIR);
foreach $file (@dir) {
  if ($file =~ /^BPLGUInfoCustomAppSrcP.*$verno_$/i) {
    $db_file = $file;
    last;
  }
}
if ($db_file eq ""){
   print "\ndatabase文件${db_dir}/${db_file}不存在，请检查是否成功编译该项目!\n\n";
   exit 1;
}
use File::Copy;
my $dest_file = "$release_dir/$version_dir";
print "copy database: ${db_dir}/${db_file}\n";
copy("${db_dir}/${db_file}",$dest_file) or die "无法拷贝database文件 ${db_dir}/${db_file}，请检查是否成功编译该项目!\n";

my $build_dir = "build/${custom}";
my $file;
my @dir;
my $custom_ex = "${custom}_PCB01";
opendir(DIR, $build_dir) or die "无法打开目录 ${build_dir}，请检查是否成功编译该项目!\n";
@dir = readdir DIR;
closedir(DIR);
foreach $file (@dir) {
  #if ($file =~ /^$custom_ex.*$verno_\.bin$/i) {
  if ($file =~ /^$custom_ex.*\.bin$/i) {
    $bin_folder = $file;
  }
  if ($file =~ /^$custom_ex.*\.elf$/i) {
    $elf_file = $file;
  }
  if ($file =~ /^$custom_ex.*\.sym$/i) {
    $sym_file = $file;
  }
  if ($file =~ /^DbgInfo_.*${verno_}.*/i)
  {
    $dbginfo_file = $file;
  }
  if (($bin_folder ne "") && ($elf_file ne "") && ($sym_file ne "") && ($dbginfo_file ne "")){
     last;
  }
}
if ($bin_folder eq ""){
   print "\n无法打开BIN档所在目录，请检查是否成功编译该项目!\n\n";
   exit 1;
}
use File::Copy;
print "copy sym: ${build_dir}/${sym_file}\n";
copy("${build_dir}/${sym_file}",$dest_file) or die "无法拷贝sym文件 ${build_dir}/${sym_file}，请检查是否成功编译该项目!\n";
print "copy elf: ${build_dir}/${elf_file}\n";
copy("${build_dir}/${elf_file}",$dest_file) or die "无法拷贝elf文件 ${build_dir}/${elf_file}，请检查是否成功编译该项目!\n";
print "copy DbgInfo: ${build_dir}/${dbginfo_file}\n";
copy("${build_dir}/${dbginfo_file}",$dest_file) or die "无法拷贝DbgInfo文件 ${build_dir}/${dbginfo_file}，请检查是否成功编译该项目!\n";

my $file;
my @dir;
my $bin_dir = "${build_dir}/${bin_folder}";
my $zip_path = "./plutommi/Customer/ResGenerator/7za";
if (-e "${dest_file}\\${VERNO}") {
	system("rmdir /S /Q ${dest_file}\\${VERNO}");
}
mkdir("${dest_file}\\${VERNO}");
opendir(DIR, $bin_dir) or die "无法打开目录 ${bin_dir}，请检查是否成功编译该项目!\n";
@dir = readdir DIR;
closedir(DIR);
use File::Copy;
foreach $file (@dir) {
  if (($file eq "ROM") ||($file eq "VIVA")||($file eq "EXT_BOOTLOADER")) {
    copy("${bin_dir}/${file}","${dest_file}\\${VERNO}") or die "could not copy files :${bin_dir}/${file}!";
  } elsif ($file =~ /^scat$custom.*\.txt$/i) {
    copy("${bin_dir}/${file}","${dest_file}\\${VERNO}") or die "could not copy files :${bin_dir}/${file}!";
  } elsif ($file =~ /.*\.cfg$/) {
    copy("${bin_dir}/${file}","${dest_file}\\${VERNO}") or die "could not copy files :${bin_dir}/${file}!";
  } elsif ($file =~ /^$custom.*$verno_\.bin$/i) {
    copy("${bin_dir}/${file}","${dest_file}\\${VERNO}") or die "could not copy files :${bin_dir}/${file}!";
  }
}

chdir("${dest_file}");
system("../../${zip_path} a -tzip ${VERNO}\.zip ${VERNO}\\*");
system("../../${zip_path} a -tzip ${VERNO}\.zip ${db_file}");

if (-e $VERNO) {
	system("rmdir /S /Q ${VERNO}");
}
if (-e $db_file) {
	system("del /F /Q $db_file");
}
chdir("../");
if ($customer_name ne "")
{
  $custom_ = $customer_name;
} else {
  $custom_ = $custom;
}
if ($chip_ver ne "") {
   $custom_ = "${custom_}_${chip_ver}";
}
if (!-d "${server_path}\\${custom_}") {
   mkdir("${server_path}\\$custom_") or die "创建目录 ${server_path}\\$custom_ 失败!";
}
if ($sub_customer_name ne "")
{
  $custom_ = $custom_."\\${sub_customer_name}";
  if (!-d "${server_path}\\${custom_}") {
   mkdir("${server_path}\\$custom_") or die "创建目录 ${server_path}\\$custom_ 失败!";
  }
}
if (!-d "${server_path}\\${custom_}\\${version_dir}") {
   mkdir("${server_path}\\$custom_\\${version_dir}") or die "创建目录 ${server_path}\\$custom_\\${version_dir} 失败!";
}
my $result = system("xcopy /S /Y ${version_dir} ${server_path}\\${custom_}\\${version_dir}");
if ($result !=0) {
  print "\n软件拷贝到服务器时失败!\n请确认是否可以访问\"\\\\192.168.1.102\\项目软件发布目录\",\n并且已将该共享目录映射为本地M盘\n\n";
} else  {
  print "\n恭喜：已成功将软件打包发布到服务器^_^\n\n";
  if ($mail_flag == 1) {
    #print "是否发送邮件通知中试和项目先关人员？(Y\/N):";
    #my $input= <STDIN> ;
    #chomp($input);
    #if (uc($input) eq "Y") {
      chdir("../");
      SetMailBody();
      SendMail();
    #} else {
    #	print "\n:):软件发布后记得通知中试和项目哦！\n\n";
    #}
  } else {
      print "\n:):软件发布后记得通知中试和项目哦！\n\n";
  }
}
sub getTime
{
    my $time = shift || time();
    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime($time);
    
    $year += 1900;
    $mon ++;
    
    $min  = '0'.$min  if length($min)  < 2;
    $sec  = '0'.$sec  if length($sec)  < 2;
    $mon  = '0'.$mon  if length($mon)  < 2;
    $mday = '0'.$mday if length($mday) < 2;
    $hour = '0'.$hour if length($hour) < 2;
    
    my $weekday = ('Sun','Mon','Tue','Wed','Thu','Fri','Sat')[$wday];
    
    return { 'second' => $sec,
             'minute' => $min,
             'hour'   => $hour,
             'day'    => $mday,
             'month'  => $mon,
             'year'   => $year,
             'weekNo' => $wday,
             'wday'   => $weekday,
             'yday'   => $yday,
             'date'   => "$year-$mon-$mday"
          };
}

sub SendMail{
    my $sendto = ".\\sendto.txt";
    my $copyto = ".\\copyto.txt";
    my $flat_set = "d:\\flatsetting\\flat.ini";
    my $sendto_flag = "";
    my $copyto_flag = "";
    my $debug = "-debug -log blat.log -timestamp";
    
    if (-e $sendto) {
    	$sendto_flag = "-tf ${sendto}";
    } else {
    	my $sendto_list = GetFeature($flat_set, "SENDTO");
    	$sendto_flag = "-to ".$sendto_list;
    }
    if (-e $copyto) {
    	$copyto_flag = "-cf ${copyto}";
    } else {
    	my $copyto_list = GetFeature($flat_set, "COPYTO");
    	$copyto_flag = "-cc ".$copyto_list;
    }
    my $from= GetFeature($flat_set, "FROM");
    my $username=GetFeature($flat_set, "USER");
    my $password = GetFeature($flat_set, "PASSWD");
    my $subj = $VERNO;
    my $server = GetFeature($flat_set, "SERVER");
    print "\n邮件发送中...\n";
    system("blat ${mail_body} $sendto_flag ${copyto_flag} -base64 -charset Gb2312 -subject ${subj} -server ${server} -f ${from} -u ${username} -pw ${password} ${debug}");
    print "\n邮件发送完成！\n";
}

sub SetMailBody{
   open(FILE, ">${mail_body}");
   print FILE "Dear All：\n\n";
   print FILE "    ${custom}项目软件版本${VERNO}已发，下载地址如下：\n\n";
   print FILE "\\\\192.168.1.102\\项目软件发布目录\\${custom_}\\${version_dir}\n\n";
   print FILE "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   close FILE;
}

sub CheckMailSet {
    my $flat_set = "d:\\flatsetting\\flat.ini";
    if (!-e $flat_set) {
       if (!-d "d:\\flatsetting") {
          mkdir("d:\\flatsetting") or die "创建目录 d:\\flatsetting 失败!\n";
       }
       open(FILE, ">$flat_set");
       print FILE "#邮箱地址\nFROM = wancheng\@far-sightedmobile.com\n#邮箱账户\nUSER = wancheng\@far-sightedmobile.com\n#邮箱密码\nPASSWD = XXXX123456\n";
       print FILE "#发送服务器(不用改)\nSERVER = smtp.far-sightedmobile.com\n#收件人(多个收件人用逗号隔开)\nSENDTO = \"renyuxuan\@far-sightedmobile.com,chenxia\@far-sightedmobile.com\"\n";
       print FILE "#抄送(多个用逗号隔开)\nCOPYTO = \"zhouzhipeng\@far-sightedmobile.com,xiaoyue\@far-sightedmobile.com\"\n";
       close FILE;
       print "第一次使用邮件功能请先打开\"${flat_set}\"进行设置\n\n";
       print "是否现在编辑？(Y\/N):";
       my $input= <STDIN> ;
       chomp($input);
       if (uc($input) eq "Y") {
         system("notepad.exe ${flat_set}");
         print "\n确认邮件设置正确后重新运行脚本\n";
       } else {   
          print "\n请先打开\"${flat_set}\"进行设置，然后重新运行脚本！\n";
       }
    }
}
sub GetFeature {
	  open (FILE_HANDLE, "<$_[0]") or die "can't open $_[0]\n";
  	  while (<FILE_HANDLE>) {
         if (/^(\S+)\s*=\s*(\S+)/) {
           if ($1 eq $_[1]) {
             close FILE_HANDLE;
             return $2;
           }
          }
       }
       close FILE_HANDLE;
       return "";
}
