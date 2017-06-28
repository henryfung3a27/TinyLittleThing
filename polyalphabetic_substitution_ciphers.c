// Work with lowercase plaintext and pad input only

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* to_upper_case(char* inp) {
	int len = strlen(inp);
	char* ret = calloc(len + 1, sizeof(char));
	
	for (int i = 0; i < len; i++)
		ret[i] = toupper(inp[i]);
	return ret;
}

char* en(char* inp, char* _pad) {
	int i = 0, k = 0;
	char* ret = malloc(strlen(inp) + 1);
	
	char* plaintext = to_upper_case(inp);
	char* pad = to_upper_case(_pad);
	
	for (; plaintext[i]; i++) {
		if (plaintext[i] == ' ') {
			ret[i] = ' ';
			continue;
		}
		
		int c;
		c = (plaintext[i] - 'A') + (pad[k] - 'A') + 1;
		c = (c % 26) + 'A';		// 'a' for lowercase output
		
		ret[i] = c;
		k = (k + 1) % strlen(pad);
	}
	return ret;
}

char* de(char* inp, char* _pad) {
	int i = 0, k = 0;
	char* ret = malloc(strlen(inp) + 1);
	
	char* plaintext = to_upper_case(inp);
	char* pad = to_upper_case(_pad);
	
	for (; plaintext[i]; i++) {
		if (plaintext[i] == ' ') {
			ret[i] = ' ';
			continue;
		}
		
		int c;
		c = (plaintext[i] - 'A') - (pad[k] - 'A') - 1;
		if (c < 0) c += 26;		// **CRITICAL**
		c = (c % 26) + 'A';		// 'a' for lowercase output
		
		ret[i] = c;
		k = (k + 1) % strlen(pad);
	}
	return ret;
}

int main(void) {
	char* p = "apple banana cipher dounut elephant flint";
	char* pad = "QWERTY";
	
	printf("before = %s\nafter  = %s\n", p, en(p, pad));
	// before = apple banana cipher dounut elephant flint
	// after  = rmudy arkffu bzmmwl cfrsmn dcbuzumk cqahs
	
	printf("after  = %s\n", de(en(p, pad), pad));
	
	//printf("\nbefore:|%s|\nafter :|%s|\n", p, to_upper_case(p));
	
	return 0;
}
