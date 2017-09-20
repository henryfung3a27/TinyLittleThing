#include <string.h>

int romanToInt(char* s) {
    const char rom[] = "IVXLCDM";
    const int num[] = {1, 5, 10, 50, 100, 500, 1000};
    
    int len = strlen(s);
    int a, max = -1;
    int ret = 0;
    
    while (len) {
        a = strchr(rom, s[len-1]) - rom;
        
        if (a < max) {
            ret -= num[a];
        }
        else {
            ret += num[a];
            max = a;
        }
        
        --len;
    }
    
    return ret;
}


int main(int argc, char* argv[]) {
	romanToInt("MMMCMXCIX"); // 3999
}

