#!/usr/bin/perluse strict;
use warnings;
use File::Find;
my @dir;
push @dir, '.';
for my $additional_directory (@ARGV) 
{ if (-e $additional_directory and -d _) 
	  {        
		push @dir, $additional_directory;    
		}    
	else {        
		warn "$additional_directory not exist or not a directory, skip.\n";
		    }
}
find(\&change, @dir);

sub change
	{ if (/(.+)\.pbm$/i) 
	 {  
	 			  rename "$1.pbm","$1.bmp";
	 	}
	 }
	 	
#	 		print "---------------\n";
#	 		print "$1\n";
#	 		my $filename = "$File::Find::dir/$1.cpp"; 
#	 		print "###############\n";
#	 		print "$1\n";
#	 		print "File::Find::name\t$File::Find::name\n";
#	 		print "filename\t$filename\n";
#		  print "rename $File::Find::name to $filename\n";
#		  rename "./abc/dfg.c","./abc/dfg.cpp";
#		  rename "./abc/1.c","./abc/1.cpp";

#		  if(! rename $File::Find::name, $filename)
#		  {
#		  	print "ERROR!!\n";
#			}		  
#		}
#	}