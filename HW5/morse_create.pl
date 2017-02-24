#!/usr/bin/perl

open($morsedata, 'morse.txt') 
	or die "Could not open file morse.txt";
$i = 0;
%hash;
while ($row = <$morsedata>) {
	chomp $row;
	@encode = split(' ', $row, 2);
	$encode[1] =~ s/\*/1/g;
	$encode[1] =~ s/ /0/g;
	$encode[1] =~ s/\-/1/g;
	$encode[1] = reverse $encode[1];
	$encode[1] = "0b" . $encode[1];
	print $encode[0] . ": ";
	print $encode[1] . "\n";
	$hash{$encode[0]} = $encode[1];
}
open($h, '>', 'morse.h') or die "Could not open file 'morse.h'";
print $h "struct morse_char{\n\tint len;\n\tint val;\n};\n\n";
print $h "extern struct morse_char lookup[256];\n\n";
print $h "void initmorse(void);";
close $h;

open($c, '>', 'morse.c') or die "Could not open file 'morse.c'";
print $c "#include \"morse.h\"\n\n";
print $c "struct morse_char lookup[256];\n\n";
print $c "void initmorse(void){\n";
print $c "\tint i = 0;\n";
print $c "\tfor(i=0; i<256; i++){\n\t\tlookup[i].val = 0;\n\t\tlookup[i].len = 0;\n\t}\n";

while (($key, $value) = each(%hash)) { 
	$len = length $value;
	$num = ord($key);
	print $c "\tlookup[$num].val = $value; lookup[$num].len = $len;\n";
}
print $c "}";

