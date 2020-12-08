#!/usr/local/bin/perl -w

use Getopt::Std;
use File::Basename;
use File::Find;
use File::Path;
use File::Spec;


my $configLargeSizeCriteria = 5 * 1024;

my $outputVenusmmiLibCode = 0;
my $outputVenusmmiLibIncData = 0;
my $outputVenusmmiLibRO = 0;
my $outputVenusmmiLibRW = 0;
my $outputVenusmmiLibZI = 0;

my $outputVrtLibCode = 0;
my $outputVrtLibIncData = 0;
my $outputVrtLibRO = 0;
my $outputVrtLibRW = 0;
my $outputVrtLibZI = 0;

my $outputVrt16LibCode = 0;
my $outputVrt16LibIncData = 0;
my $outputVrt16LibRO = 0;
my $outputVrt16LibRW = 0;
my $outputVrt16LibZI = 0;

my $outputSystemGlobalMemory = 0;
my $outputVrtContextPool = 0;
my $outputVrtCacheOnGlobal = 0;
my $outputFlatformContext = 0;
my $outputMemoryProfilingPool = 0;
my $outputUIBufferSize = 0;

my @outputAllData;


#############################################################################
#
# Functions
#
#############################################################################

sub printFootprint
{
    my $lisFileName = shift;

    die ".lis file is not exist: $lisFileName\n" 
        if !-e $lisFileName;

    # Read from file
    open INFILE, "<$lisFileName" or 
        die "Can not open input file: $lisFileName: $!\n";
        
    while (<INFILE>)
    {
        if (/^\s*(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+venusmmi.lib/)
        {
            $outputVenusmmiLibCode = $1;
            $outputVenusmmiLibIncData = $2;
            $outputVenusmmiLibRO = $3;
            $outputVenusmmiLibRW = $4;
            $outputVenusmmiLibZI = $5;
        }
        elsif (/^\s*(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+vrt.lib/)
        {
            $outputVrtLibCode = $1;
            $outputVrtLibIncData = $2;
            $outputVrtLibRO = $3;
            $outputVrtLibRW = $4;
            $outputVrtLibZI = $5;
        }
        elsif (/^\s*(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+vrt16.lib/)
        {
            $outputVrt16LibCode = $1;
            $outputVrt16LibIncData = $2;
            $outputVrt16LibRO = $3;
            $outputVrt16LibRW = $4;
            $outputVrt16LibZI = $5;
        }
        elsif (/^\s*g_vfx_sys_mem_global_mem_buf\s+.*Data\s+(\d+)/)
        {
            $outputSystemGlobalMemory = $1;            
        }
        elsif (/^\s*g_vfx_sys_vrt_context_heap\s+.*Data\s+(\d+)/)
        {
            $outputVrtContextPool = $1;
        }
        elsif (/^\s*g_vrt_cache_memory\s+.*Data\s+(\d+)/)
        {
            $outputVrtCacheOnGlobal = $1;
        }
        elsif (/^\s*s_vappPlatformBuffer\s+.*Data\s+(\d+)/)
        {
            $outputFlatformContext = $1;
        }
        elsif (/^\s*g_snapshotData\s+.*Data\s+(\d+)/)
        {
            $outputMemoryProfilingPool = $1;
        }
        elsif (/^\s*g_ui_buffer\s+.*Data\s+(\d+)/)
        {
            $outputUIBufferSize = $1;
        }
        
        if (/^\s*[^\s]+\s+([^\s]+)\s+(Data|Zero)\s+[^\s]+\s+[^\s]+\s+[^\s]+\s+([^\s]+)\(venusmmi.lib\)/)
        {
            my ($size, $name) = (hex($1), $3);
            if ($size >= $configLargeSizeCriteria)
            {
                push 
                    @outputAllData, 
                    { NAME => $name, SIZE => $size };                    
            }
        }
    }   
    
    close INFILE;

    print "[venusmmi.lib]\n";
    print " (Code+Data+RO) = ($outputVenusmmiLibCode+$outputVenusmmiLibIncData+$outputVenusmmiLibRO) = ", $outputVenusmmiLibCode + $outputVenusmmiLibIncData + $outputVenusmmiLibRO, " \n";
    print "        (RW+ZI) = ($outputVenusmmiLibRW+$outputVenusmmiLibZI) = ", $outputVenusmmiLibRW + $outputVenusmmiLibZI, "\n";
    print "[vrt.lib]\n";
    print " (Code+Data+RO) = ($outputVrtLibCode+$outputVrtLibIncData+$outputVrtLibRO) = ", $outputVrtLibCode + $outputVrtLibIncData + $outputVrtLibRO, " \n";
    print "        (RW+ZI) = ($outputVrtLibRW+$outputVrtLibZI) = ", $outputVrtLibRW + $outputVrtLibZI, "\n";
    print "[vrt16.lib]\n";
    print " (Code+Data+RO) = ($outputVrt16LibCode+$outputVrt16LibIncData+$outputVrt16LibRO) = ", $outputVrt16LibCode + $outputVrt16LibIncData + $outputVrt16LibRO, " \n";
    print "        (RW+ZI) = ($outputVrt16LibRW+$outputVrt16LibZI) = ", $outputVrt16LibRW + $outputVrt16LibZI, "\n";
    print "\n";
    
    print "[Special Pools]\n";
    print "  System Global Memory = $outputSystemGlobalMemory\n";
    print "      VRT Context Pool = $outputVrtContextPool\n";
    print " VRT Cache (on global) = $outputVrtCacheOnGlobal\n";
    print "      Platform Context = $outputFlatformContext\n";
    print " Memory Profiling Pool = $outputMemoryProfilingPool\n";
    print " UI Buffer Pool Size   = $outputUIBufferSize\n";
    print "\n";

    print "[Large Memory in venusmmi.lib (>=$configLargeSizeCriteria)]\n";
    for $x (@outputAllData)
    {
        print " ", $x->{NAME}, ": ", $x->{SIZE}, "\n";
    }
    print "\n";
}


sub help
{
    my $progName = basename($0);
    print "Print Venus UI Engine footprint.\n\n";
    print "Usage:\n";
    print "\t$progName <.lis file>\n";
};


#############################################################################
#
# Main
#
#############################################################################
my %option = ();
getopts("", \%option);

my $argc = $#ARGV + 1;
if ($argc < 1)
{
    help();
    exit -1;
}

printFootprint($ARGV[0], $ARGV[1]);

print "done.\n";


