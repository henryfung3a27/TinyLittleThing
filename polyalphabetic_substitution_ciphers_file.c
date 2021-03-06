/*******

 Date: 29/6/2017
 This program is written for fun only.
 It accepts a text file and a pad as arguments. It outputs a new file with all characters
 encrypted or decrypted with the pad provided. Encryption and decryption are done in the
 same program, decided by the parameter. The output of the program will be in the format
 of <input_file_name>_output(.<file_extension>).
 Only encrypt and decrypt English alphabets.
 
 Usage: polyalphabetic_substitution_ciphers_file <file_name> <pad> <e/d>
        e -> encryption   d -> decryption

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
	printf("Usage: polyalphabetic_substitution_ciphers_file <filename> <pad> <e/d>\n");
	printf("e -> encrypt\td -> decrypt\n");
	printf("e.g.\n$ polyalphabetic_substitution_ciphers_file ~/Documents/test myPad e\n");
}

int main(int argc, char* argv[]) {
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	
	if (argc == 1) {
		display_msg();
		exit(1);
	}
	
	if (argc != 4) {
		printf("You did not input enough information or you inputted too much.\n");
		printf("For more information, run without parameters\n");
		exit(1);
	}
	
	// Create output file name //
	char output_path[256] = "";
	char ext[256] = "";
	strcpy(output_path, argv[1]);
	if (strchr(output_path, '.')) {		// If the file has file extension
		char* token = strtok(output_path, ".");
		sprintf(output_path, "%s", token);
		token = strtok(NULL, ".");
		strcpy(ext, token);
		strcat(output_path, "_output");
		strcat(output_path, ".");
		strcat(output_path, ext);
		free(token);
	}
	else
		sprintf(output_path, "%s_output", argv[1]);
	/*************************/
	
	FILE *fp = fopen(argv[1], "r");
	FILE *op = fopen(output_path, "w");
	
	if (!fp) {
		printf("The file cannot be opened.\n");
		exit(1);
	}
	if (!op) {
		printf("The output file cannot be created.\n");
		exit(1);
	}
	
	char* get = malloc(1024 * sizeof(char));
	
	if (argv[3][0] == 'e') {
		while (fgets(get, 1024, fp))
			fprintf(op, "%s", en(get, argv[2]));
		printf("Encryption success.\n");
		printf("Output: %s\n", output_path);
	}
	else if (argv[3][0] == 'd') {
		while (fgets(get, 1024, fp))
			fprintf(op, "%s", de(get, argv[2]));
		printf("Decryption success.\n");
		printf("Output: %s\n", output_path);
	}
	else
		printf("Please enter 'e' for encryption or 'd' for decryption.\n");
	
	free(get);
	fclose(fp);
	fclose(op);
	
	return 0;
}
