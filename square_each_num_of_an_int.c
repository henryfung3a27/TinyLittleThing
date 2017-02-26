/*
	input=12345   	(char type)
	output=1491625 	(int type)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int func(char inp[]) {
	char a[100] = "";
	char b[1000] = "";
	
	int i, temp;
	for (i = 0; i < strlen(inp); i++) {
		temp = inp[i] - '0';
		temp *= temp;
		sprintf(a, "%d", temp);
		strcat(b, a);
	}
	temp = 0;
	for (i = 0; i < strlen(b); i++) {
		temp *= 10;
		temp += (b[i] - '0');
	}
	return temp;
}


int main()
{
	char input[100];
	printf("Enter a num: ");
	scanf("%s", &input);
	
	printf("The output of %s is %d", input, func(input));
}
