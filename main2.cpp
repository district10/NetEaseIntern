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

bool hasDigit(  long long int n, int d ) {
    while ( n ) {
        int r = n % 10;
        if ( r == d ) {
            return true;
        }
        n /= 10;
    }
    return false;
}

bool has18( long long int n ) {
    while ( n ) {
        int r = n % 10;
        if ( r == 8 ) {
            n /= 10;
            if ( n  && n % 10 == 1) {
                return true;
            } else {
                return false;
            }
        }
        n /= 10;
    }
    return false;
}

bool divide7 ( long long int n ) {
    return 0 == n % 7;
}

bool isMagical( int n )
{
    if ( !hasDigit(n, 2) &&
         !hasDigit(n, 3) &&
         !hasDigit(n, 5) ) { return false; }

    if ( has18(n) ) { return false; }
    if ( divide7(n) ) { return true; }

    return false;
}

int main()
{
    if (freopen( CMAKE_SOURCE_DIR "file2.txt", "r", stdin) == NULL) {
        perror("freopen() failed");
        return EXIT_FAILURE;
    }

    int s, m, n;
    cin >> s;
    while ( s-- > 0 ) {
        cin >> m >> n;
        int count = 0;
        for ( int i = m; i <= n; ++i ) {
            if ( isMagical(i) ) { ++count; }
        }
        cout << count << endl;
    }

    fclose(stdin);

    return 0;
}
