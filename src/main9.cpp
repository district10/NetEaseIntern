#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstddef>
#include <cctype>
#include <new>
#include <cstdio>

#include "Configs.h"

using namespace std;

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file6.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int n;
    while( 1 == scanf("%d", &n) ) {
        std::vector<int> students(n, 0);
        for ( int i = 0; i < n; ++i ) {
            int ability;
            scanf( "%d", &ability );
            students[i] = ability;
        }
        int k, d;
        scanf( "%d %d", &k, &d );
    }
}
