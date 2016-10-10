#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

void reverse( char *s, int left, int right ) {
    char tmp;
    while( left < right ) {
        tmp       =  s[left];
        s[left]   =  s[right];
        s[right]  =  tmp;
        ++left;
        --right;
    }
}

void solve( char *s ) {
    int left = 0, right = 0, len = strlen(s);
    while( left < len && right < len ) {
        while( s[right] && s[right] != ' ' ) {
            ++right;
        }
        if( !s[right] && left < right-1 ) {
            reverse( s, left, right-1 );    // 最后一段
            break;
        }
        reverse( s, left, right-1 );
        left = right + 1;                   // 跳过连续空格
        while( s[left] == ' ' ) {
            ++left;
        }
        right = left + 1;
    }
    reverse( s, 0, len-1 );
}

int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file2c.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
#endif
    char buf[1000];
    string line;
    while( getline(cin, line)) {
        strcpy(buf, line.c_str());
        solve(buf);
        printf("%s\n", buf);
    }
}