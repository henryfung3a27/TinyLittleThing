/*
	input = num of row (i.e. 5)
	    *
	   ***
	  *****
	 *******
	*********
*/

#include <stdio.h>

main(int argc, char *argv[]) {
	int i, j, k;
	
	int num = atoi(argv[1]);
	for (i = 1; i <= 2*num; i+=2) {
		for (j = 0; j < 2*num-1; j++) {
			if (j == (num * 2 - 1 - i) / 2) {
				for (k = 0; k < i; k++) {
					printf("*");
				}
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
