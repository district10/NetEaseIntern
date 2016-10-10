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
#include <map>

#include "Configs.h"

using namespace std;

struct comp {
    bool operator()( const pair<string, int> &a, const pair<string, int> &b ) {
        return a.second < b.second;
    }
};

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file8.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int n, m;
    while( 2 == scanf("%d %d", &n, &m) && n && m ) {
        vector<int> ns(n, 0);
        for ( int i = 0; i < n; ++i ) { scanf( "%d", &ns[i] ); }
        sort( ns.begin(), ns.end() );
        map<string, int> ms;
        for ( int i = 0; i < m; ++i ) { 
            string fruit;
            cin >> fruit; 
            if( ms.count(fruit) ) { ++ms[fruit]; } else { ms[fruit] = 1; }
        }
        vector<pair<string, int> > ms2( ms.size() );

        int i = 0;
        for ( map<string, int>::iterator it = ms.begin(); it != ms.end(); ++it ) {
            ms2[i++] = pair<string,int>(it->first, it->second);
        }
        sort( ms2.begin(), ms2.end(), comp() );

        int hi = 0, lo = 0;
        int ms2size = ms2.size();
        for( int i = 0; i < ms2size; ++i ) {
            hi += ns[n-1-i]*ms2[ms2size-1-i].second;
            lo += ns[i]* ms2[i].second;
        }
        printf( "%d, %d", lo, hi );
        // copy( ns.begin(), ns.end(), ostream_iterator<int>(cout, " ") ); cout << "\n";
        // copy( ms.begin(), ms.end(), ostream_iterator<string>(cout, " ") ); cout << "\n";
    }
}
