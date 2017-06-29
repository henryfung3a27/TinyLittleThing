/*******

 Date: 28/6/2017
 This program is written for fun only. 
 It accepts a text string and a pad as arguments. It outputs both cases when the user wants
 to encrypt or decrypt the text string with the pad.
 
 Further dev.: accept a file as an argument and output a new file with all characters encryped
 					or decryped with the pad provided.
 
 *******/

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
		if (!isalpha(plaintext[i])) {
			ret[i] = plaintext[i];
			continue;
		}
		
		int c;
		c = (plaintext[i] - 'A') + (pad[k] - 'A') + 1;
		c = (c % 26) + 'A';		// 'a' for lowercase output
		
		ret[i] = c;
		k = (k + 1) % strlen(pad);
	}
	
	free(plaintext);
	free(pad);
	return ret;
}

char* de(char* inp, char* _pad) {
	int i = 0, k = 0;
	char* ret = malloc(strlen(inp) + 1);
	
	char* plaintext = to_upper_case(inp);
	char* pad = to_upper_case(_pad);
	
	for (; plaintext[i]; i++) {
		if (!isalpha(plaintext[i])) {
			ret[i] = plaintext[i];
			continue;
		}
		
		int c;
		c = (plaintext[i] - 'A') - (pad[k] - 'A') - 1;
		if (c < 0) c += 26;		// **CRITICAL**
		c = (c % 26) + 'A';		// 'a' for lowercase output
		
		ret[i] = c;
		k = (k + 1) % strlen(pad);
	}
	
	free(plaintext);
	free(pad);
	return ret;
}

void display_msg() {
	printf("Usage: polyalphabetic_substitution_ciphers_file <filename> <pad>\n");
	printf("e.g.\n$ polyalphabetic_substitution_ciphers \"C:\\users\\Tom\\Desktop\\test.txt\" \"pad\"\n");
}

int main(int argc, char* argv[]) {
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	
	if (argc == 1) {
		display_msg();
		exit(1);
	}
	
	if (argc != 3) {
		printf("You did not input enough information or you inputted too much.\n");
		exit(1);
	}
	
	FILE *fp = fopen(argv[1], "r");
	if (!fp) {
		printf("The file cannot be opened.\n");
		exit(1);
	}
	
	return 0;
}
