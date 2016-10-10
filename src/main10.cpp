#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdio>

#include "Configs.h"

using namespace std;

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file10.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int n;
    while( 1 == scanf("%d", &n) ) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int ret = i;
            while( ret&1 == 0 ) { ret /= 2; }
            sum += ret;
        }
        cout << sum << "\n";
    }
}
