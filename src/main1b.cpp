#include <iostream>
#include <stack>
#include <cstdio>

#include "Configs.h"
using namespace std;

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file1b.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }

    int M, N;
    while (2 == scanf("%d %d", &M, &N)) {
        if( N < 2 || N > 16 ) { continue; }
        stack<int> s;
        int sign = 1;
        if( M < 0 ) { sign = -1; M = -M; }
        while (M) {
            s.push(M%N);
            M /= N;
        }
        if( s.empty() ) { printf("0"); }
        if( sign < 0 ) { printf("-"); }
        while (!s.empty()) {
            char c = s.top() > 9 ? 'A' + s.top() - 10 : '0' + s.top();
            printf("%c", c);
            s.pop();
        }
        printf("\n");
    }
}