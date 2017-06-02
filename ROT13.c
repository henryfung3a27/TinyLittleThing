/*******
The ROT13 function is to shift the characters 13 to the left. i.e. ROT13('a') => 'n'
Apply the function twice to revert back to plaintext.
*******/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* ROT13(char* plainText) {
	char* ptr = calloc(strlen(plainText), sizeof(char));
	int is_cap;
	size_t len = strlen(plainText);
	
	while (*plainText != '\0') {
		if (isalpha(*plainText)) {
			is_cap = 0;
			if (*plainText >= 'A' && *plainText <= 'Z')
				is_cap = 1;
			*ptr = *plainText + 13;
			if ((is_cap && *ptr >= 'a') || !(isalpha(*ptr)))
				*ptr -= 26;
		}
		else
			*ptr = *plainText;
		plainText++;
		ptr++;
	}
	
	ptr -= len;
	return ptr;
}

int main(int argc, char *argv[]) {
	char* text = "Good Morning!";
	printf("%s\n", text);
	printf("%s\n", ROT13(text));
	printf("%s\n", ROT13(ROT13(text)));
	return 0;
}
