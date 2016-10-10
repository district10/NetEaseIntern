#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <climits>
#include <cstdio>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

void dfs(const vector<int> &hotels, int cur, int gap, int step, int &minstep) {
    int num = hotels.size();
    if (cur == num && gap > 0 ) { return; }
    if (gap == 0) {
        minstep = min(minstep, step);
        return;
    }
    int lo = 0, hi = gap / hotels[cur];
    for (int i = lo; i <= hi; ++i) {
        dfs(hotels, cur + 1, gap - i*hotels[cur], step + i, minstep);
    }
}

int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file3a.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
#endif
    string line;
    while (getline(cin, line)) {
        istringstream ss(line);
        vector<int> hotels;
        int total;
        while (ss >> total) {
            hotels.push_back(total);
        }
        hotels.pop_back();
        sort(hotels.begin(), hotels.end());
        reverse(hotels.begin(), hotels.end());
        int minstep = INT_MAX;
        dfs(hotels, 0, total, 0, minstep);
        if (minstep == INT_MAX) { minstep = -1; }
        cout << minstep << "\n";
    }
}