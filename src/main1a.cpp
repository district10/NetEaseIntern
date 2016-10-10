#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>

#include "Configs.h"
using namespace std;

int usParent(vector<int> &u, int i) {
    if (u[i] > 0) {
        return u[i] = usParent(u, u[i]);
    } else {
        return i;
    }
}

void usUnion(vector<int> &u, int i, int j) {
    int pi = usParent(u, i);
    int pj = usParent(u, i);
    u[i] += u[j];
    u[j] = pi;
}

bool connected(vector<int> relat, const vector<int> &m1, const vector<int> &m2, const vector<int> &lost, int t1, int t2) {
    for (int i = 0; i < lost.size(); ++i) {
        if (lost[i] == 0) { 
            usUnion(relat, m1[i] - 1, m2[i] - 1);
        }
    }
    int p1 = usParent(relat, t1 - 1);
    int p2 = usParent(relat, t2 - 1);
    return p1 == p2;
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file1a.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int N, M, t1, t2;
    while (4 == scanf("%d %d %d %d", &N, &M, &t1, &t2)) {
        vector<int> m1(M), m2(M);
        vector<vector<int>> conn(N, vector<int>(N, 0));
        vector<int> relat(N, -1);
        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &m1[i], &m2[i]);
        }
        int i = 1;
        for (; i <= M; ) { // lost 1~M
            vector<int> lost(M, 0);
            fill_n(lost.begin(), i, 1);
            int valid = 0;
            do {
                if (connected(relat, m1, m2, lost, t1, t2)) { valid = 1; }
            } while (prev_permutation(lost.begin(), lost.end()) && valid == 0);
            if (valid) {
                ++i;
            } else {
                break;
            }
        }
        cout << i+1 << "\n";
    }
}