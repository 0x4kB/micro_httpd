#!/bin/perl -w
#

open F,shift or die;

our %h = ( "application"=>1, 'audio'=>3, 'image'=>4, 'video'=>5, 'text'=>6 );
#print $h{"application"};
#exit;


foreach my $l ( <F> ){
	$l =~ /^([^,]*),([^,]*),([^,]*),([^,]*)/;
	our @a = ( $1,$2,$3,$4 );
	$a[1] =~ /^([^\/]*)/;
	$class = $1;
	$a[1] =~ s/[\/\-]/_/g;
	chomp $a[3];

	
	print "   _MIME( $a[0], $a[1], \"\\$h{$class}$a[2]\" )  /* $a[3] */ \\\n"


}



