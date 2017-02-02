#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int func(char inp[]) {
	char a[100] = "";
	char b[100] = "";
	
	int i, temp;
	for (i = 0; i < strlen(inp); i++) {
		temp = inp[i] - '0';
		temp *= temp;
		sprintf(a, "%d", temp);
		strcat(b, a);
	}
	printf("\noutput={%s}", b);
}


int main()
{
	char input[20];
	printf("Enter a num: ");
	scanf("%s", &input);
	
	func(input);
}
