#!/usr/bin/perl

use warnings;
$\ = "\n";

while (<STDIN>){

	$dateere = qr/(\d{4}-\d{2}-\d{2} (\d{2}:\d{2}:\d{2}) [A-Z]{3}):/;
	$pathere = qr/(.+)/;
	$dataere = qr/\/.+h([\d]{4}\.[\d]{2}[NS])\/([\d]{5}\.[\d]{2}[EW]).+/;
	
	 
	if (/$dateere $pathere:$dataere/){
		$date = $1;
		$time = $2;
		$path = $3;
		$lat = $4;
		$long = $5;
	}
	print $long;
}



