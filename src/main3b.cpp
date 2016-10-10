#include <cstdio>

bool power(int num) {
    if (num) {
        return 0 == (num&(num - 1));
    }
    return false;
}

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif


int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file3b.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return -1;
    }
#endif

    int num;
    while ( 1 == scanf("%d", &num) ) {
        printf("%s\n", power(num) ? "true" : "false");
    }
    return 0;
}