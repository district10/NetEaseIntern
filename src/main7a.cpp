#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstddef>
using namespace std;

int main()
{
    /*  
    if ( !freopen( CMAKE_SOURCE_DIR "/file7.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    */
    int n;
    while( 1 == scanf("%d", &n) && n ) {
        std::vector<int> h(n, 0);
        for ( int i = 0; i < n; ++i ) {
            scanf( "%d", &h[i] );
        }
        int allcnt = 0;
        for( int i = 0; i < n; ++i ) {
            double hi = std::numeric_limits<double>::min;
            double lo = std::numeric_limits<double>::max;
            int &cur = h[i];
            int cnt = 0;
            for( int j = 1; j < n; ++j ) {
                int &hh = h[(i + j) % n];
                if( (hh - cur) > hi * j ) {
                    hi = (double)(hh - cur) / j;
                    ++cnt;
                } else if( (hh - cur) < lo * j ) { 
                    lo = (double)(hh - cur) / j; 
                    ++cnt;
                }
            }
            allcnt += cnt;
        }
        printf( "%d\n", allcnt/2 );
    }
}
