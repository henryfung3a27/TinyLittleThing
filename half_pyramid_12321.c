/*
	input = greatest num (i.e. 3)
	*
	**
	***
	**
	*
*/

#include <stdio.h>
#include <math.h>

main(int argc, char *argv[]) {
	int i, j;
	
	int num = atoi(argv[1]);
	
	for (i = -num+1; i <= num-1; i++) {
		j = abs(i);
		while ( j-num < 0) {
			printf("*");
			j++;
		}
		printf("\n");
	}
}
