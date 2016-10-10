#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>

#include "Configs.h"

using namespace std;

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file11.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int n;
    while( 1 == scanf("%d", &n) ) {
        int hi = sqrt(n);
        // if (hi*hi != n) { cout << "0"; continue; }
        vector<int> xs, ys;
        for (int i = hi; i >= hi / 2; --i) {
            int rr = n - i*i;
            int sr = sqrt(rr);
            if (sr*sr == rr && sr <= i ) {
                xs.push_back(sr);   // 0 3 2  
                ys.push_back(i);    // 5 4 2
            }
        }
        int ret = xs.size() * 8;
        if (!xs.empty() && xs[0] == 0) { ret -= 4; }
        if (!xs.empty() && xs.back() == ys.back() ) { ret -= 4; }
        copy(xs.begin(), xs.end(), ostream_iterator<int>(cout, " ")); cout << "\n";
        copy(ys.begin(), ys.end(), ostream_iterator<int>(cout, " ")); cout << "\n";
        cout << ret << "\n";
    }
}
