// Work with lowercase plaintext and pad only

#include <stdio.h>

char* en(char* inp, char* pad) {
	int i = 0, k = 0;
	char* ret = malloc(strlen(inp) + 1);
	
	for (; inp[i]; i++) {
		if (inp[i] == ' ') {
			ret[i] = ' ';
			continue;
		}
		
		int a, b, c;
		c = (inp[i] - 'a') + (pad[k] - 'a') + 1;
		c %= 26;
		c += 'a';
		
		ret[i] = c;
		k = (k + 1) % strlen(pad);
	}
	return ret;
}

int main(void) {
	char* p = "apple banana cipher dounut elephant flint";
	char* pad = "qwerty";
	
	printf("\nbefore = %s\nafter  = %s\n", p, en(p, pad));
	// before = apple banana cipher dounut elephant flint
	// after  = rmudy arkffu bzmmwl cfrsmn dcbuzumk cqahs
	
	return 0;
}
