#include "morse.h"

struct morse_char lookup[256];

void initmorse(void){
	int i = 0;
	for(i=0; i<256; i++){
		lookup[i].val = 0;
		lookup[i].len = 0;
	}
	lookup[68].val = 0b1010111; lookup[68].len = 9;
	lookup[69].val = 0b1; lookup[69].len = 3;
	lookup[54].val = 0b10101010111; lookup[54].len = 13;
	lookup[51].val = 0b1110111010101; lookup[51].len = 15;
	lookup[82].val = 0b1011101; lookup[82].len = 9;
	lookup[76].val = 0b101011101; lookup[76].len = 11;
	lookup[88].val = 0b11101010111; lookup[88].len = 13;
	lookup[87].val = 0b111011101; lookup[87].len = 11;
	lookup[84].val = 0b111; lookup[84].len = 5;
	lookup[70].val = 0b101110101; lookup[70].len = 11;
	lookup[77].val = 0b1110111; lookup[77].len = 9;
	lookup[79].val = 0b11101110111; lookup[79].len = 13;
	lookup[89].val = 0b1110111010111; lookup[89].len = 15;
	lookup[66].val = 0b101010111; lookup[66].len = 11;
	lookup[74].val = 0b1110111011101; lookup[74].len = 15;
	lookup[80].val = 0b10111011101; lookup[80].len = 13;
	lookup[73].val = 0b101; lookup[73].len = 5;
	lookup[67].val = 0b10111010111; lookup[67].len = 13;
	lookup[83].val = 0b10101; lookup[83].len = 7;
	lookup[56].val = 0b101011101110111; lookup[56].len = 17;
	lookup[55].val = 0b1010101110111; lookup[55].len = 15;
	lookup[65].val = 0b11101; lookup[65].len = 7;
	lookup[57].val = 0b10111011101110111; lookup[57].len = 19;
	lookup[85].val = 0b1110101; lookup[85].len = 9;
	lookup[53].val = 0b101010101; lookup[53].len = 11;
	lookup[49].val = 0b11101110111011101; lookup[49].len = 19;
	lookup[78].val = 0b10111; lookup[78].len = 7;
	lookup[86].val = 0b111010101; lookup[86].len = 11;
	lookup[48].val = 0b1110111011101110111; lookup[48].len = 21;
	lookup[50].val = 0b111011101110101; lookup[50].len = 17;
	lookup[81].val = 0b1110101110111; lookup[81].len = 15;
	lookup[90].val = 0b10101110111; lookup[90].len = 13;
	lookup[71].val = 0b101110111; lookup[71].len = 11;
	lookup[75].val = 0b111010111; lookup[75].len = 11;
	lookup[52].val = 0b11101010101; lookup[52].len = 13;
	lookup[72].val = 0b1010101; lookup[72].len = 9;
}