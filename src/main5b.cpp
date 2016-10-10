#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

int grab(const vector<int> &satis, const vector<int> &mask, const vector<vector<int>> &adj) {
    int n = satis.size();
    int score = 0;
    static vector<int> vis(n);
    fill(vis.begin(), vis.end(), 0);
    for (int i = 0; i < n; ++i) {
        if (!mask[i]) { continue; }
        vis[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (adj[i][j]) { vis[j] = 1; }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            score += satis[i];
        }
    }
    return score;
}

int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file5b.txt", "r", stdin ) ) { return -1; }
#endif
    int N, M;
    while (2 == scanf("%d %d", &N, &M)) {
        vector<int> satis(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &satis[i]);
        }
        vector<vector<int>> adj(N, vector<int>(N, 0));
        for (int i = 0; i < N - 1; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a - 1][b - 1] = adj[b - 1][a - 1] = 1;
        }
        vector<int> mask(N);
        for (int i = 0; i < M; ++i) {
            mask[i] = 1;
        }
        int max_score = 0;
        while (prev_permutation(mask.begin(), mask.end())) {
            int score = grab(satis, mask, adj);
            max_score = max(score, max_score);
        }
        printf("%d\n", max_score);
    }
    return 0;
}