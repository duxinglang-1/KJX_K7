#!/usr/local/bin/perl -w

use Getopt::Std;
use File::Basename;


#############################################################################
#
# Configue
#
#############################################################################

my $g_logFileName = 'T:\venus.log';
my $g_flagOnlyLeak = 0;
my $g_flagShowUsage = 1;
my $g_filterPool = undef;


#############################################################################
#
# Functions
#
#############################################################################

sub parseCommandNewArgs
{
    my $lineNum = shift;
    shift;
    
    /([^\s]*)\s+([^\s]*)\s+([^\s]*)\s+(\d+)\s+([^\s]*)/ or
        die "Line $lineNum: Error format.\n";
        
    my $ret = 
    {
        POOL        => $1,
        PTR         => $3,
        SIZE        => $4,
        CLASS_NAME  => $5
    };    
    return $ret;
}

sub parseCommandDeleteArgs
{
    my $lineNum = shift;
    shift;
    
    /([^\s]*)/ or
        die "Line $lineNum: Error format.\n";
        
    my $ret = 
    {
        PTR         => $1,
    };    
    return $ret;
}

sub reportPool
{
    my $filterPool = shift;
    my $ptrTable = shift;
    my $classTable = shift;
    
    #
    # Report
    #    
    print "======================================================================\n";
    print "Memory pool [$filterPool]\n";
    print "======================\n";
    
    my $codePosTable = {};
    
    #print "Analyzing leak code position...\n";
    foreach (keys %{$ptrTable})
    {
        my $ptr         = $_;
        my $filename    = $ptrTable->{$ptr}->{FILENAME};
        my $lineNo      = $ptrTable->{$ptr}->{LINE_NO};
        my $pool        = $ptrTable->{$ptr}->{POOL};
        my $size        = $ptrTable->{$ptr}->{SIZE};
        my $className   = $ptrTable->{$ptr}->{CLASS_NAME};

        if ($pool ne $filterPool)
        {
            next;
        }

        if (!exists $codePosTable->{$filename}->{$lineNo})
        {
            $codePosTable->{$filename}->{$lineNo} = 
            {
                CLASS_NAME  => $className,
                LEAK_NUM    => 1,
                POOL        => $pool,
                SIZE        => $size
            };
        }
        else
        {
            $codePosTable->{$filename}->{$lineNo}->{LEAK_NUM}++;
            $codePosTable->{$filename}->{$lineNo}->{SIZE} += $size;
        }
    }

    print "List of Living object:\n";
    print "File                         Line# Count  ClassName              Total\n";
    # Output leak report
    foreach my $filename (sort keys %{$codePosTable})
    {
        foreach my $lineNo (sort {$a <=> $b} keys %{$codePosTable->{$filename}})
        {
            my $codePos     = $_;
            my $className   = $codePosTable->{$filename}->{$lineNo}->{CLASS_NAME};
            my $leakNum     = $codePosTable->{$filename}->{$lineNo}->{LEAK_NUM};
            my $size        = $codePosTable->{$filename}->{$lineNo}->{SIZE};

            printf "%-28s %-5d %4d * %-22s%6d \n",
                $filename,
                $lineNo,
                $leakNum,
                $className,
                $size;
        }
    }
    print "\n";
    
    if($g_flagShowUsage)
    {
        #
        # Object usage list
        #    
        print "List of Object usage detail:\n";
        print "Name                             Size Count(  Max)  Total(   Max)\n";
        # Output leak report
        foreach (keys %{$classTable->{$filterPool}})
        {
            my $className   = $_;
            my $size        = $classTable->{$filterPool}->{$className}->{SIZE};
            my $num         = $classTable->{$filterPool}->{$className}->{NUM};
            my $maxNum      = $classTable->{$filterPool}->{$className}->{MAX_NUM};
            my $total       = $classTable->{$filterPool}->{$className}->{TOTAL_SIZE};
            my $maxTotal    = $classTable->{$filterPool}->{$className}->{MAX_TOTAL_SIZE};
    
            if ($g_flagOnlyLeak && $num == 0)
            {
                next;
            }
    
            if (substr($className, 0, 1) eq '<')
            {
                printf "%-31s     * %5d(%5d) %6d(%6d)\n",
                    $className,
                    $num,
                    $maxNum,
                    $total,
                    $maxTotal;
            }
            else
            {
                printf "%-31s %5d %5d(%5d) %6d(%6d)\n",
                    $className,
                    $size,
                    $num,
                    $maxNum,
                    $total,
                    $maxTotal;
            }
        }
    }
    print "======================================================================\n";
    print "\n";    
}

sub findLeak
{
    print "[Check object leak]\n";
    
    open FILE, "<$g_logFileName" or
        die "Can not open log file: $g_logFileName: $!\n";

    my $profile = 
    {
        TOTAL_SIZE => 0,
        MAX_TOTAL_SIZE => 0
    };
    my $ptrTable = {};
    my $classTable = {};
    my $poolTable = {};
    my $lineNum = 0;

    print "Analyzing...\n";
    while (<FILE>)
    {
        # Trim
        s/^\s+//;
        s/\s+$//;

        # Add line number
        $lineNum++;
        
        # File name and line number
        /([^\#]*)\#(.*):(\d+)$/ or
            die "Line $lineNum: Error format.\n";
        my $filename    = basename($2);
        my $lineNo      = $3;
        $_ = $1;
        
        # Parse filter
        /^\[([^\]]*)\]\s+/ or
            die "Line $lineNum: Error format.\n";
        my $filter = $1;
        $_ = $';
        
        # Parse command
        /^([^\s]*)\s+/ or
            die "Line $lineNum: Error format.\n";
        my $command = $1;
        $_ = $';
        
        if ($command eq 'NEW')
        {
            my $args = &parseCommandNewArgs($lineNum, $_);
            my $ptr = $args->{PTR};

            if (exists $ptrTable->{$ptr})
            {
                print "Warning: new an object on an exist memory: $ptr\n";
                print "\tNote: Closing object does not be logged: $ptrTable->{$ptr}->{FILENAME}:$ptrTable->{$ptr}->{LINE_NO}\n";
            }
            
            $ptrTable->{$ptr} = 
            {
                FILENAME    => $filename,
                LINE_NO     => $lineNo,
                POOL        => $args->{POOL},
                CLASS_NAME  => $args->{CLASS_NAME},
                SIZE        => $args->{SIZE}
            };
            
            my $className = $args->{CLASS_NAME};
            my $pool = $args->{POOL};

            $poolTable->{$pool} = 1;

            if (!exists $classTable->{$pool}->{$className})
            {
                $classTable->{$pool}->{$className} =
                {
                    SIZE => $args->{SIZE},
                    TOTAL_SIZE => $args->{SIZE},
                    MAX_TOTAL_SIZE => $args->{SIZE},
                    NUM => 1,
                    MAX_NUM => 1
                };
            }
            else
            {
                $classTable->{$pool}->{$className}->{NUM}++;
                if ($classTable->{$pool}->{$className}->{NUM} > $classTable->{$pool}->{$className}->{MAX_NUM})
                {
                    $classTable->{$pool}->{$className}->{MAX_NUM} = $classTable->{$pool}->{$className}->{NUM};
                }
                $classTable->{$pool}->{$className}->{TOTAL_SIZE} += $args->{SIZE};
                if ($classTable->{$pool}->{$className}->{TOTAL_SIZE} > $classTable->{$pool}->{$className}->{MAX_TOTAL_SIZE})
                {
                    $classTable->{$pool}->{$className}->{MAX_TOTAL_SIZE} = $classTable->{$pool}->{$className}->{TOTAL_SIZE};
                }
            }
            
            $profile->{TOTAL_SIZE} += $args->{SIZE};
            if ($profile->{TOTAL_SIZE} > $profile->{MAX_TOTAL_SIZE})
            {
                $profile->{MAX_TOTAL_SIZE} = $profile->{TOTAL_SIZE};
            }
        }
        elsif ($command eq 'DELETE')
        {
            my $args = &parseCommandDeleteArgs($lineNum, $_);
            my $ptr = $args->{PTR};
            my $className = undef;
            my $size = undef;
            my $pool = undef;
            
            if (!exists $ptrTable->{$ptr})
            {
                print "Warning: delete an absence pointer: $ptr\n";
                print "\tNote: The object may has been deleted: $filename:$lineNo\n";
                
                next;
            }
            else
            {
                $className = $ptrTable->{$ptr}->{CLASS_NAME};
                $size = $ptrTable->{$ptr}->{SIZE};
                $pool = $ptrTable->{$ptr}->{POOL};
                delete $ptrTable->{$ptr};
            }

            if (defined $className)
            {
                if (!exists $classTable->{$pool}->{$className})
                {
                    print "Warning: delete a absence class: $className\n";
                    print "\tNote: $filename:$lineNo\n";
                }
                else
                {
                    $classTable->{$pool}->{$className}->{NUM}--;
                    $classTable->{$pool}->{$className}->{TOTAL_SIZE} -= $size if (defined $size);
                    if ($classTable->{$pool}->{$className}->{NUM} < 0)
                    {
                        print "Warning: delete is too much: $className\n";
                        print "\tNote: $filename:$lineNo\n";
                    }
                }
            }
            
            if (defined $size)
            {
                $profile->{TOTAL_SIZE} -= $size;
                if ($profile->{TOTAL_SIZE} < 0)
                {
                    print "Warning: delete is too much: ($profile->{TOTAL_SIZE})\n";
                }
            }
        }
        else
        {
            print "Warning: Unknown command: $command\n";
        }
    }    
    print "\n";
    

    #
    # Report
    #    
    print "[Report]\n";
    if (defined($g_filterPool))
    {
        reportPool($g_filterPool, $ptrTable, $classTable);
    }
    else
    {
        foreach (keys %{$poolTable})
        {
            my $pool = $_;
            reportPool($pool, $ptrTable, $classTable);
        }

        #
        # Memory usage list
        #    
        print "=================================================================\n";
        print "Overall memory usage:\n";
        printf "Total Size = %10d\nMax Size   = %10d\n",
            $profile->{TOTAL_SIZE},
            $profile->{MAX_TOTAL_SIZE};
        print "=================================================================\n";
    }
        
    close FILE;
}


sub help
{
    my $progName = basename($0);
    print STDERR "Venus UI memory log analyzer.\n";
    print STDERR "\nUsage:\n";
    print STDERR "\t$progName <options> <command>\n";
    print STDERR "\ncommand:\n";
    print STDERR "\tcheck, ck    \toutput object leak and usage table\n";
    print STDERR "\noptions:\n";
    print STDERR "\t-l           \tonly report leak object classes\n";
    #print STDERR "\t-l           \tonly report gloabl pool objects\n";
    print STDERR "\t-i <filename>\tread log from <filename>\n";
};


#############################################################################
#
# Main
#
#############################################################################

# Parse arguments
my %options = ();
if (!getopts('lhi:f:', \%options))
{
    help();
    exit -1;
}

$g_flagOnlyLeak = 1 if (exists $options{l});
$g_logFileName = $options{i} if (exists $options{i});
$g_filterPool = $options{f} if (exists $options{f});
$g_flagShowUsage = 0 if (exists $options{h});

my $command = shift @ARGV;
if (!$command)
{
    help();
    exit -1;
}
elsif ($command eq 'check' || $command eq 'ck')
{
    findLeak();
}
else
{
    help();
    exit -1;
}

