#include <cstdio>

#include "Configs.h"

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file7a.txt", "r", stdin ) ) {
        return 0;
    }
    int n;
    char buf[20];
    while( 1 == scanf("%s", buf) ) {
        const char s[] = "CODEFESTIVAL2016";
        int count = 0;
        for (int i = 0; s[i]; ++i) {
            if (buf[i] != s[i]) {
                ++count;
            }
        }
        printf("%d\n", count);
    }
}
