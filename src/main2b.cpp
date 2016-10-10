#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <limits>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

int height(int root, vector<int> &lch, vector<int> &rch) {
    int n = lch.size();
    if (root < 0 || root >= n) { return -1; }
    if (lch[root] < 0 && rch[root] < 0) { return 1; }
    if (lch[root] < 0 || rch[root] < 0) {
        if (lch[root] >= 0) { return 1+height(lch[root], lch, rch); }
        if (rch[root] >= 0) { return 1+height(rch[root], lch, rch); }
    }
    return max(height(lch[root], lch, rch), height(rch[root], lch, rch)) + 1;
}

int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file2b.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
#endif
    int n;
    while (1 == scanf("%d", &n)) {
        vector<int> lch(n, -1), rch(n, -1);
        set<int> ps, cs;
        for (int i = 0; i < n - 1; ++i) {
            int p, c;
            scanf("%d %d", &p, &c);
            ps.insert(p); cs.insert(c);
            if (lch[p] < 0) { lch[p] = c; continue; }
            if (rch[p] < 0) { rch[p] = c; continue; }
        }

        int root = -1;
        for (auto p : ps) {
            if (!cs.count(p)) {
                root = p;
                break;
            }
        }
        cout << height(root, lch, rch) << "\n";
    }

}