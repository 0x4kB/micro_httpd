#!/bin/perl -w
#

open F,shift or die;


foreach my $l ( <F> ){
	$l =~ /^([^,]*),([^,]*),([^,]*),([^,]*)/;
	our @a = ( $1,$2,$3,$4 );
	$a[1] =~ s/[\/\-]/_/g;
	chomp $a[3];
	
	print "   _MIME( $a[0], $a[1], \"$a[2]\" )  /* $a[3] */ \\\n"


}



