#include <cstdio>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

struct Comp {
    bool operator()(int a, int b)  const {
        int da = 1, db = 1;
        while (a / da >= 10) { da *= 10; }
        while (b / db >= 10) { db *= 10; }
        while (a > 0 && b > 0) {
            int qa = a / da;
            int qb = b / db;
            if (qa != qb) {
                return qa < qb;
            }
            a %= da;
            b %= db;
            da /= 10;
            db /= 10;
        }
        return a == 0;
    }
};

int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file4a.txt", "r", stdin ) ) { return -1; }
#endif

    int n, k;
    while ( 2 == scanf("%d %d", &n, &k) ) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        sort(nums.begin(), nums.end(), Comp());
        // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " ")); cout << "\n";
        cout << nums[k - 1] << "\n";
    }
    return 0;
}
