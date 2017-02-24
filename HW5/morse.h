struct morse_char{
	int len;
	int val;
};

extern struct morse_char lookup[256];

void initmorse(void);