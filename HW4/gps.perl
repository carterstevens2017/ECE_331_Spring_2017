#!/usr/bin/perl

use warnings;
$\ = "\n";
$, = "\n";

while (<STDIN>){

	$dateere = qr/(\d{4}-\d{2}-\d{2} (\d{2}:\d{2}:\d{2}) [A-Z]{3}):/;
	$pathere = qr/(.+):/;
	$dataere = qr/ /;
	
	 
	print $3 if (/$dateere $pathere/)
}



