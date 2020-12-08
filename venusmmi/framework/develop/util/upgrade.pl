#!/usr/local/bin/perl -w

use Getopt::Std;
use File::Basename;
use File::Find;
use File::Path;
use File::Spec;


#############################################################################
#
# Functions
#
#############################################################################

# add rule here
sub processRules
{
	$_ = shift;

	# Exceptions (for Home Screen)
	s/m_propertyNetname/m_netname/mg;
	s/m_propertyNetstat/m_netstat/mg;
	
	# m_propertyXxx.get() -> getXxx()
	s/m_property([\w\d_]+)\.get\(\)/get$1()/mg;
	# m_propertyXxx = Ooo; -> setXxx(Ooo);
	s/m_property([\w\d_]+)\s*=\s*([^;]*);/set$1($2);/mg;
	# m_propertyXxx.set -> setXxx
	s/m_property([\w\d_]+)\.set/set$1/mg;
	# m_propertyXxx.forceSet -> setXxx
	s/m_property([\w\d_]+)\.forceSet/set$1/mg;
	# m_propertyXxx.init -> setXxx
	s/m_property([\w\d_]+)\.init/set$1/mg;
	# m_propertyXxx) -> getXxx())
	s/m_property([\w\d_]+)\s*\)/get$1\(\)\)/mg;

	# VfxSlotRetEnum -> void 
	s/VfxSlotRetEnum/void/mg;
	# return VFX_SIGNAL_RET_OK; } -> }
	s/\s*return\s+VFX_SIGNAL_RET_OK\s*;\s*^\}/\n\}/mg;
	# return VFX_SIGNAL_RET_OK -> return
	s/return\s+VFX_SIGNAL_RET_OK/return/mg;
	
	return $_;
}


sub processFile
{
	my $inputFileName = shift;
	my $outputFileName = shift;

	die "Input file is not exist: $inputFileName\n" 
		if !-e $inputFileName;

	# Read from file
	print "Revise $inputFileName\n";

	open INFILE, "<$inputFileName" or 
		die "Can not open input file: $inputFileName: $!\n";
	my $text = do { local $/; <INFILE>;	};
	close INFILE;

	# Prepare output path
	my ($outputVolume, $outputPath, $outputFile) = 
		File::Spec->splitpath($outputFileName);
	mkpath "$outputVolume$outputPath";

	#
	# process all rules
	#
	$text = &processRules($text);

	# Write to file
	print "=====> $outputFileName\n";

	open OUTFILE, ">$outputFileName" or 
		die "Can not create output file: $inputFileName: $!\n";
	print OUTFILE $text;
	close OUTFILE;
}


sub processDir
{
	local $inputPath = shift;
	local $outputPath = shift;

    sub processHelper
    {
        # Ignore path
        return if -d $File::Find::name;
        
        my $relativePathName	= File::Spec->abs2rel($File::Find::name, $inputPath);
        my $inputPathName		= $File::Find::name;
        my $outputPathName 		= File::Spec->catfile($outputPath, $relativePathName);        

        &processFile($inputPathName, $outputPathName);
    }

    sub checkPath
    {
        my @ret = @_;
        my $path = $File::Find::dir;

		# Ignore .svn folder
        return () if ($path =~ '/.svn');
        
        return @ret;
    }    
    
	die "Input path is not exist: $inputPath\n"
		if !-e $inputPath;

	die "Not a path: $inputPath\n"
		if !-d $inputPath;
	
    find
        {
            wanted => \&processHelper, 
            preprocess => \&checkPath,
            no_chdir => 1
        },
        $inputPath;
}


sub help
{
    my $progName = basename($0);
    print "Upgrade Venus UI source code from 09A to 09B.\n\n";
    print "Usage:\n";
    print "\t$progName <inputFile> <outputFile>\n";
    print "\t$progName -d <inputPath> <outputPath>\n";
};


#############################################################################
#
# Main
#
#############################################################################
my %option = ();
getopts("d", \%option);

my $argc = $#ARGV + 1;
if ($argc < 2)
{
	help();
	exit -1;
}

if ($option{d})
{
	processDir($ARGV[0], $ARGV[1]);
}
else
{
	processFile($ARGV[0], $ARGV[1]);
}

print "done.\n";
