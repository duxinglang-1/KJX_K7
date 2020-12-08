########################################################################
# Please notice that this script is for MoDIS on VS2008 (VC9)
# NOT suitable for MoDIS on VC6
########################################################################

package createMoDIS;
use strict;
use DirHandle;
use File::Basename;
use File::Copy;
use File::Path;
use Exporter;
use vars qw(@ISA @EXPORT @EXPORT_OK);
@ISA = qw(Exporter);
@EXPORT = qw(CheckIfFolder CopyFolder CopyFile);
@EXPORT_OK = qw(CheckIfFolder CopyFolder CopyFile);

#######################################################################################################################
#######################################################################################################################
#######################################################################################################################

sub create_vcproj_header
{
	my $lib_GUID = shift;
	my $lib = shift;
	my $result = <<__STRING__
<?xml version="1.0" encoding="utf-8"?>
<VisualStudioProject
	ProjectType="Visual C++"
	Version="9.00"
	Name="$lib"
	ProjectGUID="{$lib_GUID}"
	Keyword="Win32Proj"
	TargetFrameworkVersion="0"
	>
	<Platforms>
		<Platform
			Name="Win32"
		/>
	</Platforms>
	<ToolFiles>
	</ToolFiles>
__STRING__
;
	return $result;
}

sub create_vcproj_foot
{
	return <<__STRING__
	<Globals>
	</Globals>
</VisualStudioProject>
__STRING__
;
}
#######################################################################################################################
#######################################################################################################################
#######################################################################################################################

sub create_vcproj_configuration
{
	my $lib = shift;
	my $compile_option = shift;
	my $include_path = shift;
	my $mmi_version = shift;
	my $modis_suffix = shift;

	my $option_set = "";

	foreach my $option (split("\n", $include_path))
	{
		$option = short_path($option);
		$option_set .= "$option\n";
	}
	my $option_in_ini = ""; # these options will be written into vcproj file
	foreach my $option2 (split("\n", $compile_option))
	{
		$option2 =~ /\"(.*)\"/;
		$option_in_ini .= "$1;";
	}

	if ($lib =~ /modis_ui_mslt|modis_ui_all/i)
	{
		open H,">MoDIS_UI/$lib.ini";
		print H $option_set;
		close H;
	}
	else
	{
		open H,">$lib/${lib}${modis_suffix}.ini";
		print H $option_set;
		close H;
	}

	my $lib_ini = $lib . $modis_suffix . ".ini";
	my $result = <<__STRING__
	<Configurations>
		<Configuration
			Name="Debug|Win32"
			OutputDirectory=".\\Debug${modis_suffix}"
			IntermediateDirectory=".\\Debug${modis_suffix}"
			ConfigurationType="4"
			UseOfMFC="0"
			ATLMinimizesCRunTimeLibraryUsage="false"
			CharacterSet="2"
			>
			<Tool
				Name="VCPreBuildEventTool"
			/>
			<Tool
				Name="VCCustomBuildTool"
			/>
			<Tool
				Name="VCXMLDataGeneratorTool"
			/>
			<Tool
				Name="VCWebServiceProxyGeneratorTool"
			/>
			<Tool
				Name="VCMIDLTool"
			/>
			<Tool
				Name="VCCLCompilerTool"
				AdditionalOptions="@&quot;$lib_ini&quot; /MP"
				ForcedIncludeFiles="auto_header.h"
				Optimization="0"
				PreprocessorDefinitions="WIN32;_DEBUG;_CONSOLE;$option_in_ini"
				MinimalRebuild="false"
				BasicRuntimeChecks="3"
				RuntimeLibrary="3"
				UsePrecompiledHeader="0"
				PrecompiledHeaderFile=".\\Debug${modis_suffix}\\$lib.pch"
				AssemblerListingLocation=".\\Debug${modis_suffix}\\"
				ObjectFile=".\\Debug${modis_suffix}\\"
				ProgramDataBaseFileName=".\\Debug${modis_suffix}\\"
				WarningLevel="3"
				SuppressStartupBanner="true"
				DebugInformationFormat="3"
				DisableSpecificWarnings="4996"
				DefaultCharIsUnsigned="true"
			/>
			<Tool
				Name="VCManagedResourceCompilerTool"
			/>
			<Tool
				Name="VCResourceCompilerTool"
				PreprocessorDefinitions="_DEBUG"
			/>
			<Tool
				Name="VCPreLinkEventTool"
			/>
			<Tool
				Name="VCLibrarianTool"
				OutputFile=".\\Debug${modis_suffix}\\$lib.lib"
				SuppressStartupBanner="true"
			/>
			<Tool
				Name="VCLinkerTool"
				AdditionalDependencies=""
				OutputFile=".\\Debug${modis_suffix}\\$lib.lib"
				LinkIncremental="2"
				SuppressStartupBanner="true"
				GenerateDebugInformation="true"
				ProgramDatabaseFile=".\\Debug${modis_suffix}\\$lib.pdb"
				SubSystem="2"
				RandomizedBaseAddress="1"
				DataExecutionPrevention="0"
				TargetMachine="1"
			/>
			<Tool
				Name="VCALinkTool"
			/>
			<Tool
				Name="VCManifestTool"
			/>
			<Tool
				Name="VCXDCMakeTool"
			/>
			<Tool
				Name="VCBscMakeTool"
			/>
			<Tool
				Name="VCFxCopTool"
			/>
			<Tool
				Name="VCAppVerifierTool"
			/>
			<Tool
				Name="VCPostBuildEventTool"
			/>
		</Configuration>
		<Configuration
			Name="Release|Win32"
			OutputDirectory=".\\Release${modis_suffix}"
			IntermediateDirectory=".\\Release${modis_suffix}"
			ConfigurationType="4"
			UseOfMFC="0"
			ATLMinimizesCRunTimeLibraryUsage="false"
			CharacterSet="2"
			>
			<Tool
				Name="VCPreBuildEventTool"
			/>
			<Tool
				Name="VCCustomBuildTool"
			/>
			<Tool
				Name="VCXMLDataGeneratorTool"
			/>
			<Tool
				Name="VCWebServiceProxyGeneratorTool"
			/>
			<Tool
				Name="VCMIDLTool"
			/>
			<Tool
				Name="VCCLCompilerTool"
				AdditionalOptions="@&quot;$lib_ini&quot; /MP"
				ForcedIncludeFiles="auto_header.h"
				Optimization="0"
				PreprocessorDefinitions="WIN32;NDEBUG;_CONSOLE;$option_in_ini"
				MinimalRebuild="false"
				RuntimeLibrary="2"
				BufferSecurityCheck="false"
				PrecompiledHeaderFile=".\\Release${modis_suffix}\\$lib.pch"
				AssemblerListingLocation=".\\Release${modis_suffix}\\"
				ObjectFile=".\\Release${modis_suffix}\\"
				ProgramDataBaseFileName=".\\Release${modis_suffix}\\"
				WarningLevel="3"
				DebugInformationFormat="3"
				DisableSpecificWarnings="4996"
				DefaultCharIsUnsigned="true"
			/>
			<Tool
				Name="VCManagedResourceCompilerTool"
			/>
			<Tool
				Name="VCResourceCompilerTool"
				PreprocessorDefinitions="NDEBUG"
			/>
			<Tool
				Name="VCPreLinkEventTool"
			/>
			<Tool
				Name="VCLibrarianTool"
				OutputFile=".\\Release${modis_suffix}\\$lib.lib"
				SuppressStartupBanner="true"
			/>
			<Tool
				Name="VCLinkerTool"
				AdditionalDependencies=""
				OutputFile=".\\Release${modis_suffix}\\$lib.lib"
				LinkIncremental="1"
				SuppressStartupBanner="true"
				GenerateDebugInformation="true"
				ProgramDatabaseFile=".\\Release${modis_suffix}\\$lib.pdb"
				SubSystem="1"
				RandomizedBaseAddress="1"
				DataExecutionPrevention="0"
				TargetMachine="1"
			/>
			<Tool
				Name="VCALinkTool"
			/>
			<Tool
				Name="VCManifestTool"
			/>
			<Tool
				Name="VCXDCMakeTool"
			/>
			<Tool
				Name="VCBscMakeTool"
			/>
			<Tool
				Name="VCFxCopTool"
			/>
			<Tool
				Name="VCAppVerifierTool"
			/>
			<Tool
				Name="VCPostBuildEventTool"
			/>
		</Configuration>
	</Configurations>
	<References>
	</References>
__STRING__
;
	return $result;
}
#######################################################################################################################
#======================================================================================================================
my %file_list_table;
my %added_file_list_table;
my $added_file_list_table_cnt;

sub output_Source_File
{
	my $lib = shift;
	my $fullpath = shift;
	my $node = shift;
	my $WIN32_COMPILE_OPTION = shift;
	my $PreprocessorDefs ="";
	if(defined($$WIN32_COMPILE_OPTION{lc("$fullpath\\$node")}))
	{
		$PreprocessorDefs .= $$WIN32_COMPILE_OPTION{lc("$fullpath\\$node")};
	}
	elsif(defined($$WIN32_COMPILE_OPTION{lc($node)}))
	{
		$PreprocessorDefs .= $$WIN32_COMPILE_OPTION{lc($node)};
	}

	my $result = "				<File\n					RelativePath=\"$fullpath\\$node\"\n					>\n";
	if ($node =~ /(\.c)|(\.cpp)$/)
	{
		$result .= "					<FileConfiguration\n						Name=\"Release|Win32\"\n						>\n";
		$result .= "						<Tool\n							Name=\"VCCLCompilerTool\"\n							PreprocessorDefinitions=\"$PreprocessorDefs\"\n						\/>\n";
		$result .= "					<\/FileConfiguration>\n					<FileConfiguration\n						Name=\"Debug|Win32\"\n						>\n";
		$result .= "						<Tool\n							Name=\"VCCLCompilerTool\"\n							PreprocessorDefinitions=\"$PreprocessorDefs\"\n						\/>\n";
		$result .= "					<\/FileConfiguration>\n";
	}

	if(lc($node)=~ /\.asm$/) # Assembler file
	{
		$result .= "					<FileConfiguration\n						Name=\"Debug|Win32\"\n						>\n";
		$result .= "						<Tool\n							Name=\"VCCustomBuildTool\"\n							CommandLine=\"&quot;\$(VCInstallDir)\\bin\\ml.exe&quot; /nologo /c /coff /Zi /FR -Fo\$(OutDir)\\\$(InputName).obj \$(InputDir)\\\$(InputName).asm\"\n 							Outputs=\"\$(OutDir)\\\$(InputName).obj\"\/>\n";
		$result .= "					<\/FileConfiguration>\n					<FileConfiguration\n						Name=\"Release|Win32\"\n						>\n";
		$result .= "						<Tool\n							Name=\"VCCustomBuildTool\"\n							CommandLine=\"&quot;\$(VCInstallDir)\\bin\\ml.exe&quot; /nologo /c /coff /Zi /FR -Fo\$(OutDir)\\\$(InputName).obj \$(InputDir)\\\$(InputName).asm\" \n						Outputs=\"\$(OutDir)\\\$(InputName).obj\"\/>\n";
		$result .= "					<\/FileConfiguration>\n";
	}

	$result .= "				</File>\n";
	return $result;
}

sub create_filter_tree
{
	my $level = shift;
	my $lib = shift;
	my $fullpath = shift;
	my $path = shift;
	my $WIN32_COMPILE_OPTION = shift;

	my $dir = new DirHandle();
	my $result = "";

	$level++;

	$result .= "		<Filter\n			Name=\"$path\"\n			>\n" if($level>1);
	opendir $dir,"$lib/$fullpath";
	foreach my $node (sort readdir($dir))
	{
		next if($node eq '.');
		next if($node eq '..');
		if (CheckIfFolder("$lib/$fullpath/$node"))
		{
			my $file_counter = $added_file_list_table_cnt;
			my $content = create_filter_tree($level,$lib,"$fullpath\\$node",$node,$WIN32_COMPILE_OPTION);
			$result .= $content if($file_counter < $added_file_list_table_cnt);
		}
		else
		{
			next if(($file_list_table{lc("$fullpath\\$node")} != 1));
			next if($node =~ /\.c$/ && !defined($file_list_table{lc("$fullpath\\$node")}));
			next if($node =~ /\.cpp$/ && !defined($file_list_table{lc("$fullpath\\$node")}));
			next if(defined($added_file_list_table{lc("$fullpath\\$node")}));

			if($node =~ /\.h$/i
			|| $node =~ /\.hpp$/i
			|| $node =~ /\.c$/i
			|| $node =~ /\.cpp$/i
			|| $node =~ /\.asm$/i
			|| $node =~ /\.txt$/i
			|| $node =~ /\.bat$/i)
			{
				$added_file_list_table{lc("$fullpath\\$node")} = 1;
				$result .= output_Source_File($lib, $fullpath,$node,$WIN32_COMPILE_OPTION);
				$added_file_list_table_cnt ++;
			}
		}
	}
	closedir $dir;
	$result .= "		<\/Filter>\n" if($level>1);

	$level--;
	return $result;
}

sub create_Files_List
{
	my $lib = shift;
	my $file_list = lc(shift);
	my $WIN32_COMPILE_OPTION = shift;
	my $par_lib = shift;

	my $list_set = "";
	my @unsort;

	undef %file_list_table;
	undef %added_file_list_table;
	$added_file_list_table_cnt=0;

	foreach my $file (split("\n",$file_list))
	{
		$file = short_path($file);
		$file_list_table{lc($file)} = 1;
	}

	foreach my $file (sort keys %file_list_table)
	{
		warn "[Warning] $lib => $file does NOT exist!\n" if (! -e "$lib/$file");
		next if(defined($added_file_list_table{lc($file)}));

		if($file =~ /^(.*?\\$lib)\\/i)
		{
			my $root = $1;
			$list_set .= create_filter_tree(0,$lib,$root,$lib,$WIN32_COMPILE_OPTION);
		}
		else
		{
			push @unsort,$file;
		}
	}

	foreach my $file (sort @unsort)
	{
		$list_set .= output_Source_File($lib, dirname($file),basename($file),$WIN32_COMPILE_OPTION);
	}
	if ($par_lib)
	{
		$list_set .= "		<Filter\n			Name=\"libs\"\n			>\n";
		$list_set .= "			<File\n				RelativePath=\"PSRC_lib\\${lib}_par\.lib\"\n				>\n";
		$list_set .= "			</File>\n";
		$list_set .= "		</Filter>\n";
	}
	my $result = "	<Files>\n" . $list_set . "	</Files>\n";
	return $result;
}

#======================================================================================================================
#######################################################################################################################
#######################################################################################################################
#######################################################################################################################

sub create_lib_vcproj
{
	my $lib_GUID = shift;
	my $lib = shift;
	my $vcproj_filename = shift;
	my $compile_option = shift;
	my $include_path = shift;
	my $file_list = shift;
	my $mmi_version = shift;
	my $par_lib = shift;
	my $WIN32_COMPILE_OPTION = shift;

	my $result = '';
	my $modis_suffix = '';
	if ($vcproj_filename =~ /uesim\.vcproj/i)
	{
		$modis_suffix = '_uesim';
	}
	$result .= create_vcproj_header($lib_GUID,$lib);
	$result .= create_vcproj_configuration($lib,$compile_option,$include_path,$mmi_version,$modis_suffix);
	$result .= create_Files_List($lib,$file_list,$WIN32_COMPILE_OPTION,$par_lib);
	$result .= create_vcproj_foot();
	$result = checkVcprojFile($result);
	my $result_last;
	if ((-e $vcproj_filename) && (open F,"<$vcproj_filename"))
	{
		my $saved_sep = $/;
		undef $/;
		$result_last = <F>;
		$/ = $saved_sep;
		close F;
	}
	if ($result ne $result_last)
	{
		print "Write $vcproj_filename\n";
		open F, ">$vcproj_filename" or die "Fail to write $vcproj_filename";
		print F $result;
		close F;
	}
	else
	{
		print "No need to update $vcproj_filename\n";
	}
}

#######################################################################################################################
#######################################################################################################################
#######################################################################################################################
sub create_solution_header
{
	my $modis_GUID = shift;
	my $solution_filename = shift;
	my $vcproj_filename = $solution_filename;
	$vcproj_filename =~ s/\.sln$/.vcproj/i;
	return <<__STRING__
Microsoft Visual Studio Solution File, Format Version 10.00
# Visual Studio 2008
Project("{$modis_GUID}") = "MoDIS", "MoDIS\\$vcproj_filename", "{$modis_GUID}"
__STRING__
;
}

sub create_solution_dependency
{
	my $lib_list = shift;
	my $lib_GUID_list = shift;
	my $modis_suffix = shift;

	my $result = "	ProjectSection(ProjectDependencies) = postProject\n";
	foreach my $lib(@$lib_list)
	{
		my $lib_GUID = $lib_GUID_list->{$lib};
		$result .= "	{$lib_GUID} = {$lib_GUID}\n"
	}
	$result .= "	EndProjectSection\nEndProject\n";
	foreach my $lib(@$lib_list)
	{
		my $lib_GUID = $lib_GUID_list->{$lib};
		$result .= "Project(\"{$lib_GUID}\") = \"$lib\", \"$lib\\${lib}${modis_suffix}.vcproj\", \"{$lib_GUID}\"\nEndProject\n";
	}
	return $result;
}

sub create_solution_projectConfigurationPlatforms
{
	my $modis_GUID = shift;
	my $lib_list = shift;
	my $lib_GUID_list = shift;
	my $result = '';
	$result .= "	GlobalSection(ProjectConfigurationPlatforms) = postSolution\n";
	$result .= "		{$modis_GUID}.Debug|Win32.ActiveCfg = Debug|Win32\n";
	$result .= "		{$modis_GUID}.Debug|Win32.Build.0 = Debug|Win32\n";
	$result .= "		{$modis_GUID}.Release|Win32.ActiveCfg = Release|Win32\n";
	$result .= "		{$modis_GUID}.Release|Win32.Build.0 = Release|Win32\n";
	foreach my $lib(@$lib_list)
	{
		my $lib_GUID = $lib_GUID_list->{$lib};
		$result .= "		{$lib_GUID}.Debug|Win32.ActiveCfg = Debug|Win32\n";
		$result .= "		{$lib_GUID}.Debug|Win32.Build.0 = Debug|Win32\n";
		$result .= "		{$lib_GUID}.Release|Win32.ActiveCfg = Release|Win32\n";
		$result .= "		{$lib_GUID}.Release|Win32.Build.0 = Release|Win32\n";
	}
	$result .= "	EndGlobalSection\n";
	return $result;
}

sub create_solution_Global_header
{
	return <<__STRING__
Global
	GlobalSection(SolutionConfigurationPlatforms) = preSolution
		Debug|Win32 = Debug|Win32
		Release|Win32 = Release|Win32
	EndGlobalSection
__STRING__
;
}

sub create_solution_Global_foot
{
	return <<__STRING__
	GlobalSection(SolutionProperties) = preSolution
		HideSolutionNode = FALSE
	EndGlobalSection
EndGlobal
__STRING__
;
}

sub create_solution
{
	my $modis_GUID = shift;
	my $solution_filename = shift;
	my $lib_list = shift;
	my $lib_GUID = shift;

	my $modis_suffix = '';
	if ($solution_filename =~ /uesim/i)
	{
		$modis_suffix = '_uesim';
	}
	my $result = '';
	$result .= create_solution_header($modis_GUID, $solution_filename);
	$result .= create_solution_dependency($lib_list, $lib_GUID, $modis_suffix);
	$result .= create_solution_Global_header();
	$result .= create_solution_projectConfigurationPlatforms($modis_GUID, $lib_list, $lib_GUID);
	$result .= create_solution_Global_foot();

	print "Write $solution_filename\n";
	open F, ">$solution_filename" or die "Fail to write $solution_filename";
	print F $result;
	close F;
}

sub create_main_lib_vcproj
{
	my $lib_GUID = shift;
	my $modis_uesim = shift;
	my $compile_option = shift;
	my $include_path = shift;
	my $file_list = shift;
	my $mmi_version = shift;
	my $modis_mode = shift;
	my $lib_list = shift;
	my $WIN32_COMPILE_OPTION = shift;

	my $result = '';
	my $modis_suffix = '';
	if ($modis_uesim =~ /uesim/i)
	{
		$modis_suffix = '_uesim';
	}
	my $lib = $modis_uesim;
	my $vcproj_filename = "MoDIS/$lib.vcproj";
	print "Write $vcproj_filename\n";
	$result .= create_vcproj_header($lib_GUID,$lib);
	$result .= create_main_vcproj_configuration($lib,$compile_option,$include_path,$mmi_version,$modis_suffix,$modis_mode);
	$result .= create_main_Files_List($lib,$file_list,$WIN32_COMPILE_OPTION,$lib_list);
	$result .= create_vcproj_foot();

	open F, ">$vcproj_filename" or die "Fail to write $vcproj_filename";
	print F $result;
	close F;
}

sub create_main_vcproj_configuration
{
	my $lib = shift;
	my $compile_option = shift;
	my $include_path = shift;
	my $mmi_version = shift;
	my $modis_suffix = shift;
	my $modis_mode = shift;

	my $option_set = "";
	foreach my $option (split("\n", $include_path))
	{
		$option = short_path($option);
		$option_set .= "$option\n";
	}

	my $option_in_ini = ""; # these options will be written into vcproj file
	foreach my $option2 (split("\n", $compile_option))
	{
		$option2 =~ /\"(.*)\"/;
		$option_in_ini .= "$1;";
	}

	my $lib_ini = $lib . ".ini";
	open H,">MoDIS/${lib}.ini";
	print H $option_set;
	close H;

	my $lib_dep_debug = '';
	my $lib_dep_release = '';
	if (($mmi_version ne "EMPTY_MMI") && ($mmi_version ne "EXTERNAL_MMI")) {
		$lib_dep_debug = "Debug\\MoDis_UI.lib";
		$lib_dep_release = "Release\\MoDis_UI.lib";
	} else {
		# Do not link MoDis_UI.lib when MMI_VERSION is EMPTY_MMI or EXTERNAL_MMI.
	}
	my $ignoreDefaultLib_debug;
	if (lc($modis_mode) eq "debug") {
		$ignoreDefaultLib_debug = "libc.lib;libcp.lib;libcd.lib;libcmt.lib;msvcrt.lib";
	} else {
		$ignoreDefaultLib_debug = "libc.lib;libcp.lib;libcd.lib;libcmt.lib";
	}
	my $result = <<__STRING__
	<Configurations>
		<Configuration
			Name="Debug|Win32"
			OutputDirectory=".\\Debug${modis_suffix}"
			IntermediateDirectory=".\\Debug${modis_suffix}"
			ConfigurationType="1"
			UseOfMFC="0"
			ATLMinimizesCRunTimeLibraryUsage="false"
			CharacterSet="2"
			>
			<Tool
				Name="VCPreBuildEventTool"
			/>
			<Tool
				Name="VCCustomBuildTool"
			/>
			<Tool
				Name="VCXMLDataGeneratorTool"
			/>
			<Tool
				Name="VCWebServiceProxyGeneratorTool"
			/>
			<Tool
				Name="VCMIDLTool"
				TypeLibraryName=".\\Debug${modis_suffix}\\MoDIS.tlb"
				HeaderFileName=""
			/>
			<Tool
				Name="VCCLCompilerTool"
				AdditionalOptions="@&quot;$lib_ini&quot; /MP"
				Optimization="0"
				PreprocessorDefinitions="WIN32;_DEBUG;_CONSOLE;$option_in_ini"
				MinimalRebuild="false"
				RuntimeLibrary="3"
				PrecompiledHeaderFile=".\\Debug${modis_suffix}\\MoDIS.pch"
				AssemblerListingLocation=".\\Debug${modis_suffix}\\"
				ObjectFile=".\\Debug${modis_suffix}\\"
				ProgramDataBaseFileName=".\\Debug${modis_suffix}\\"
				BrowseInformation="1"
				WarningLevel="3"
				SuppressStartupBanner="true"
				DebugInformationFormat="3"
				ForcedIncludeFiles="auto_header.h"
				DisableSpecificWarnings="4996"
				DefaultCharIsUnsigned="true"
			/>
			<Tool
				Name="VCManagedResourceCompilerTool"
			/>
			<Tool
				Name="VCResourceCompilerTool"
				PreprocessorDefinitions="_DEBUG"
				Culture="1028"
			/>
			<Tool
				Name="VCPreLinkEventTool"
			/>
			<Tool
				Name="VCLinkerTool"
				AdditionalDependencies="winmm.lib odbc32.lib odbccp32.lib ws2_32.lib Msimg32.lib $lib_dep_debug"
				OutputFile=".\\Debug${modis_suffix}\\MoDIS.exe"
				LinkIncremental="2"
				SuppressStartupBanner="true"
				UACExecutionLevel="2"
				IgnoreDefaultLibraryNames="${ignoreDefaultLib_debug}"
				GenerateDebugInformation="true"
				ProgramDatabaseFile=".\\Debug${modis_suffix}\\MoDIS.pdb"
				GenerateMapFile="true"
				MapFileName=".\\Debug${modis_suffix}\\MoDIS.map"
				SubSystem="1"
				RandomizedBaseAddress="1"
				DataExecutionPrevention="0"
				TargetMachine="1"
			/>
			<Tool
				Name="VCALinkTool"
			/>
			<Tool
				Name="VCManifestTool"
				EmbedManifest="false"
			/>
			<Tool
				Name="VCXDCMakeTool"
			/>
			<Tool
				Name="VCBscMakeTool"
				SuppressStartupBanner="true"
				OutputFile=".\\Debug${modis_suffix}\\MoDIS.bsc"
			/>
			<Tool
				Name="VCFxCopTool"
			/>
			<Tool
				Name="VCAppVerifierTool"
			/>
			<Tool
				Name="VCPostBuildEventTool"
			/>
		</Configuration>
		<Configuration
			Name="Release|Win32"
			OutputDirectory=".\\Release${modis_suffix}"
			IntermediateDirectory=".\\Release${modis_suffix}"
			ConfigurationType="1"
			UseOfMFC="0"
			ATLMinimizesCRunTimeLibraryUsage="false"
			CharacterSet="2"
			>
			<Tool
				Name="VCPreBuildEventTool"
			/>
			<Tool
				Name="VCCustomBuildTool"
			/>
			<Tool
				Name="VCXMLDataGeneratorTool"
			/>
			<Tool
				Name="VCWebServiceProxyGeneratorTool"
			/>
			<Tool
				Name="VCMIDLTool"
				TypeLibraryName=".\\Release${modis_suffix}\\MoDIS.tlb"
				HeaderFileName=""
			/>
			<Tool
				Name="VCCLCompilerTool"
				AdditionalOptions="@&quot;$lib_ini&quot; /MP"
				Optimization="0"
				PreprocessorDefinitions="WIN32;NDEBUG;_CONSOLE;$option_in_ini"
				MinimalRebuild="false"
				RuntimeLibrary="2"
				BufferSecurityCheck="false"
				PrecompiledHeaderFile=".\\Release${modis_suffix}\\MoDIS.pch"
				AssemblerListingLocation=".\\Release${modis_suffix}\\"
				ObjectFile=".\\Release${modis_suffix}\\"
				ProgramDataBaseFileName=".\\Release${modis_suffix}\\"
				WarningLevel="3"
				SuppressStartupBanner="true"
				DebugInformationFormat="3"
				ForcedIncludeFiles="auto_header.h"
				DisableSpecificWarnings="4996"
				DefaultCharIsUnsigned="true"
			/>
			<Tool
				Name="VCManagedResourceCompilerTool"
			/>
			<Tool
				Name="VCResourceCompilerTool"
				PreprocessorDefinitions="NDEBUG"
				Culture="1028"
			/>
			<Tool
				Name="VCPreLinkEventTool"
			/>
			<Tool
				Name="VCLinkerTool"
				AdditionalDependencies="Gdi32.lib ole32.lib user32.lib winmm.lib odbc32.lib odbccp32.lib ws2_32.lib Msimg32.lib $lib_dep_release"
				OutputFile=".\\Release${modis_suffix}\\MoDIS.exe"
				LinkIncremental="1"
				SuppressStartupBanner="true"
				UACExecutionLevel="2"
				IgnoreDefaultLibraryNames="LIBCD.lib;LIBC.lib"
				ProgramDatabaseFile=".\\Release${modis_suffix}\\MoDIS.pdb"
				SubSystem="1"
				RandomizedBaseAddress="1"
				DataExecutionPrevention="0"
				TargetMachine="1"
			/>
			<Tool
				Name="VCALinkTool"
			/>
			<Tool
				Name="VCManifestTool"
				EmbedManifest="false"
			/>
			<Tool
				Name="VCXDCMakeTool"
			/>
			<Tool
				Name="VCBscMakeTool"
				SuppressStartupBanner="true"
				OutputFile=".\\Release${modis_suffix}\\MoDIS.bsc"
			/>
			<Tool
				Name="VCFxCopTool"
			/>
			<Tool
				Name="VCAppVerifierTool"
			/>
			<Tool
				Name="VCPostBuildEventTool"
			/>
		</Configuration>
	</Configurations>
	<References>
	</References>
__STRING__
;
	return $result;
}

sub create_main_Files_List
{
	my $lib = shift;
	my $file_list = shift;
	my $WIN32_COMPILE_OPTION = shift;
	my $lib_list = shift;

	my @file_src;
	my @file_inc;
	my @file_pic;
	my @file_res;
	foreach my $file (split("\n",$file_list))
	{
		chomp($file);
		$file = short_path($file);
		#$file =~ s/^\.\.\\\.\.\\MoDIS_VC9\\MoDIS\\//i;
		if ($file =~ /\.c(pp|xx)?$/i)
		{
			push(@file_src, $file);
		}
		elsif ($file =~ /\.h(pp|xx)?$/i)
		{
			push(@file_inc, $file);
		}
		elsif ($file =~ /\.(rc)$/i)
		{
			push(@file_res, $file);
		}
		else
		{
			push(@file_pic, $file);
		}
	}

	my $result_src = "		<Filter\n			Name=\"Source Files\"\n			Filter=\"cpp;c;cxx;rc;def;r;odl;idl;hpj;bat\"\n			>\n";
	foreach my $file (@file_src)
	{
		$result_src .= "			<File\n				RelativePath=\"$file\"\n				>\n";
		$result_src .= "				<FileConfiguration\n					Name=\"Debug|Win32\"\n					>\n";
		$result_src .= "					<Tool\n						Name=\"VCCLCompilerTool\"\n						PreprocessorDefinitions=\"\"\n";
		$result_src .= "					/>\n				</FileConfiguration>\n";
		$result_src .= "				<FileConfiguration\n					Name=\"Release|Win32\"\n					>\n";
		$result_src .= "					<Tool\n						Name=\"VCCLCompilerTool\"\n						PreprocessorDefinitions=\"\"\n";
		$result_src .= "					/>\n				</FileConfiguration>\n";
		$result_src .= "			</File>\n";
	}
	$result_src .= "		</Filter>\n";

	my $result_inc = "		<Filter\n			Name=\"Header Files\"\n			Filter=\"h;hpp;hxx;hm;inl\"\n			>\n";
	foreach my $file (@file_inc)
	{
		$result_inc .= "			<File\n				RelativePath=\"$file\"\n				>\n			</File>\n";
	}
	$result_inc .= "		</Filter>\n";

	my $result_res = "		<Filter\n			Name=\"Resource Files\"\n			Filter=\"ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe\"\n			>\n";
	foreach my $file (@file_pic)
	{
		$result_res .= "			<File\n				RelativePath=\"$file\"\n				>\n			</File>\n";
	}
	foreach my $file (@file_res)
	{
		$result_res .= "			<File\n				RelativePath=\"$file\"\n				>\n";
		$result_res .= "				<FileConfiguration\n					Name=\"Debug|Win32\"\n					>\n";
		$result_res .= "					<Tool\n						Name=\"VCResourceCompilerTool\"\n						PreprocessorDefinitions=\"\"\n";
		$result_res .= "					/>\n				</FileConfiguration>\n";
		$result_res .= "				<FileConfiguration\n					Name=\"Release|Win32\"\n					>\n";
		$result_res .= "					<Tool\n						Name=\"VCResourceCompilerTool\"\n						PreprocessorDefinitions=\"\"\n";
		$result_res .= "					/>\n				</FileConfiguration>\n";
		$result_res .= "			</File>\n";
	}
	$result_res .= "		</Filter>\n";

	my $result_lib = "		<Filter\n			Name=\"libs\"\n			>\n";
	foreach my $file (@$lib_list)
	{
		$file = short_path($file);
		$result_lib .= "			<File\n				RelativePath=\"$file\"\n				>\n			<\/File>\n";
	}
	$result_lib .= "		</Filter>\n";

	my $result = "	<Files>\n";
	$result .= $result_src;
	$result .= $result_inc;
	$result .= $result_res;
	$result .= $result_lib;
	$result .= "	</Files>\n";

	return $result;
}

# =================================================================
# VS2008 cannot parse .vcproj files in which there are 2 or more <FILTER> section with the same name
# The function here is to parse generated .vcproj files
# and rename the duplicated section name to ORGINNAME_1/2/3...
# E.g.: "src" => "src_1" or "src_2", etc.
sub checkVcprojFile
{
	my $inputVcproj = shift;
	my $filterFlag = 0;
	my $filterCount = 0;
	my @filter;
	my $content = "";
	my $count = 0;
	foreach (split(/\n/,$inputVcproj)) {
		$_ .= "\n";
		if (/<Filter/) {
			$filterCount = $filterCount + 1; $filterFlag = 1; $content .= $_;
			next;
		}
		if (/<\/Filter>/) {
			$filterCount = $filterCount - 1; $content .= $_;
			next;
		}
		if (($filterFlag == 1) && ($filterCount == 1)) {
			if (/Name\s*=\s*\"([a-zA-Z0-9]+)\"/) {
				if (grep (/\b$1\b/, @filter)) {
					$count = $count + 1;
					$_ =~ s/\"([a-zA-Z0-9]+)\"/\"$1_$count\"/;
				} else {
					push @filter, $1;
				}
			}
			if (/^\s*$/) { #empty line
				next;
			}
			$filterFlag = 0;
		}
		$content .= $_;
	}
	return $content;
}

sub update_lib_project
{
	my $old_project = shift;
	my $new_project = shift;
	my $release_MoDIS_lib = shift;
	my $list = shift;
	my $cleanRoomLibRemoval = shift;

	open F,"<$old_project" or die "Can't open $old_project";
	my $content = join('',<F>);
	close F;
	my $content1 = $content;
	my $path_MoDIS_lib = $release_MoDIS_lib;
	$path_MoDIS_lib =~ s/(\\+)/\\\\/g;
	if ($content1 !~ /$path_MoDIS_lib/i)
	{
		$content1 =~ s/\bMoDIS_lib\b/$release_MoDIS_lib/gi;
	}
	#$content =~ /(<File\s*RelativePath=.*supc.*\s+>\s+<\/File>)/ig;
	#my $cleanRoomLib = $1;
	my $cleanRoomLib = "";

	if ($content1 =~ /<Filter\s*Name=\"libs\"(.*?)<\/Filter>/is) {
		my $t;
		foreach my $line (split('\n',$list))
		{
			$t .= "\n			<File\n				RelativePath=\"$line\"\n				>\n			</File>";
		}
		$content1 =~ s/(\s*<\/Filter>\s*<\/Files>)/$t$1/;
	} else {
		my $t = "		<Filter\n			Name=\"libs\"\n			>\n";
		foreach my $line (split('\n',$list))
		{
			$t .= "\n			<File\n				RelativePath=\"$line\"\n				>\n			</File>";
		}
		if ($cleanRoomLibRemoval eq "FALSE")
		{
			$t .= $cleanRoomLib;
		}
		$t .= "\n		</Filter>\n";
		$content1 =~ s/<\/Files>/$t<\/Files>/;
	}
	if ($new_project =~ /MoDIS_Custom/i) # the output of MoDIS_Custom.sln should be MoDIS_Custom.exe
	{
		$content1 =~ s/\bMoDIS\.exe\b/MoDIS_Custom\.exe/gi;
		$content1 =~ s/\bMoDIS\.pdb\b/MoDIS_Custom\.pdb/gi;
	}
	open F,">$new_project" or die "Can't write $new_project";
	print F $content1;
	close F;
}

sub generate
{
  my($out, $in, $cwd) = @_;
  my $chash = hash($cwd);
  my $nhash = hash($out);
  my $ihash = hash($in);
  my $val   = 0xfeca1bad;

  return sprintf("%08X-%04X-%04X-%04X-%04X%08X",
                 $nhash & 0xffffffff, ($val >> 16) & 0xffff,
                 ($val & 0xffff), ($ihash >> 16) & 0xffff,
                 $ihash & 0xffff, $chash & 0xffffffff);
}

sub hash
{
  my $str   = shift;
  my $value = 0;

  if (defined $str) {
    my $length = length($str);
    for(my $i = 0; $i < $length; $i++) {
      $value = (($value << 4) & 0xffffffff) ^ ($value >> 28)
        ^ ord(substr($str, $i, 1));
    }
  }

  return $value;
}

sub short_path
{
	my $input = shift;
	$input =~ s/[\\\/]+/\\/g;
	$input =~ s/^\s*\\I\b/\/I/;
	while ($input =~ /\\\.\\/)
	{
		$input =~ s/\\\.\\/\\/g;
	}
	while ($input =~ /\w+\\\.\.\\/)
	{
		$input =~ s/\w+\\\.\.\\//;
	}
	return $input;
}

sub CheckIfFolder
{
	my $name = shift;
	if (opendir DH, $name)
	{
		closedir DH;
		#print "$name => 1\n";
		return 1;
	}
	#print "$name => 0\n";
	return 0;
}

sub CopyFolder
{
	my $src = shift;
	my $target = shift;
	my $flag = shift;
	my $DIRHANDLE;
	mkpath($target) if (! -e $target);
	opendir $DIRHANDLE, $src or die "Can't Open $src, Information:$!!\n";
	my @dirs = readdir $DIRHANDLE;
	closedir $DIRHANDLE;
	foreach my $fd (@dirs)
	{
		next if ($fd =~ /^(\.|\.\.)$/);
		my $input2 = "$src\\$fd";
		my $output3 = "$target\\$fd";
		if (CheckIfFolder($input2))
		{
			# directory
			next if ($flag);
			CopyFolder($input2, $output3);
		}
		elsif (-e $input2)
		{
			# file, copy directly
			next if (($flag) && ($fd =~ /^(MoDIS|vc90)\.(pdb|idb|bsc|ilk)$/i));
			copy($input2, $output3) or die "Fail to copy $src\\$fd: $!\n";
		}
		else
		{
			die "Fail to find $src\\$fd: $!\n";
		}
	}
}

sub CopyFile
{
	my $src = shift;
	my $target = shift;
	my $dest = dirname($target);
	mkpath($dest) if (! CheckIfFolder($dest));
	copy($src, $target) or die "Fail to copy $src";
}

sub auto_header
{
	# working dir is mcu
	my $ref_str_out = shift;
	my $ref_hash_out = shift;
	my $ref_str_in = shift;
	my $str_prefix = shift;
	my $flag_target = shift;
	my %file_header = ("lib_list"=>"");
	my @path_list = split(/\s+/, $$ref_str_in);
	my %saw;
	@path_list = grep (!$saw{$_}++, @path_list);
	foreach my $dir (@path_list)
	{
		next if (($dir eq "") || (!-d $dir));
		#print "auto_header for " . $dir . "\n";
		my $DIR_HANDLE;
		opendir $DIR_HANDLE, $dir or die "Fail to opendir " . $dir;
		my @file_list = readdir $DIR_HANDLE;
		close $DIR_HANDLE;
		foreach my $file (@file_list)
		{
			next if (($file eq ".") || ($file eq ".."));
			next if ((lc($file) eq "readme.txt") || (lc($file) eq "dummy.txt") || (lc($file) eq "temp.txt") || (lc($file) eq "makefile"));
			next if ($file =~ /\.(vcproj|rar|pch|dll)$/i);
			if (-d "$dir/$file")
			{
			}
			elsif (-e "$dir/$file")
			{
				if (exists $file_header{lc($file)})
				{
					$ref_hash_out->{$dir} .= $file . " ";
					$ref_hash_out->{$file_header{lc($file)}} .= $file . " ";
				}
				else
				{
					$file_header{lc($file)} = $dir;
				}
			}
		}
	}
	my $key;
	my $value;
	while (($key, $value) = each %file_header)
	{
		if (! exists $ref_hash_out->{$value})
		{
			my $full_path;
			$full_path = short_path("$str_prefix/$value/$key");
			if ($flag_target == 0)
			{
				$$ref_str_out .= "#pragma include_alias(\"" . $key . "\", \"" . $full_path . "\")\n";
			}
			else
			{
				if ($^O eq "MSWin32")
				{
					$$ref_str_out .= "copy /y " . $full_path . " %1\n";
				}
				else
				{
				}
			}
		}
	}
	return 1;
}

return 1;

