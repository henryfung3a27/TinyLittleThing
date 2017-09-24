/* The Knuth-Morris-Pratt Algorithm */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* pmt(char* inp) {        // partial match table
    int i;
    int len = strlen(inp);
    int* arr = calloc(len, sizeof(int));
	
    char* temp = malloc(len + 1);
    char** pre = (char**)calloc(len, sizeof(char*));
    char** suf = (char**)calloc(len, sizeof(char*));
    
    for (i = 2; i <= len; i++) {
        strncpy(temp, inp, i);
        
        // prefix and suffix
        for (int j = 1; j < i; j++) {
            pre[j-1] = realloc(pre[j-1], i - j);
            suf[j-1] = realloc(suf[j-1], i - j);
            strncpy(pre[j-1], temp, i - j);
            strncpy(suf[j-1], temp + j, i - j);
            pre[j-1][i-j] = 0;
            suf[j-1][i-j] = 0;
        }
        
        // compare
        for (int j = 0; j < i - 1; j++)
            if (!strcmp(pre[j], suf[j])) {
                arr[i-1] = strlen(pre[j]);
                break;        // since string length of pre[] is in decending order,
                              // the first match must be the longest
            }
    }
    
    free(temp);
    free(pre);
    free(suf);
    return arr;
}

char* kmp(char* str, int* table) {
	
	
	
	
}



int main(void) {
    char* str = "bacbababaabcbab";
    char* word = "abababca";
    int *a;
    
    a = pmt(word);
    
    for (int i = 0; i < strlen(word); i++)
        printf("arr[%d] = %d\n", i, a[i]);
    return 0;
}
