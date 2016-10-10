#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <new>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
/*
*/

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

int H, W;
char pic[501][501];

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int u, d, l, r;
void bfs_udlr( int x, int y, int &px, int &py ) {
    if ( x < 0 || x >= H || y < 0 || y >= W || pic[x][y] != '#') { return; }
    pic[x][y] = 'X';
    if (x < u) { px = x; py = y; }
    l = min(l, x); r = max(r, x);
    u = min(u, x); d = max(d, x);
    bfs_udlr(x + 1, y, px, py);
    bfs_udlr(x - 1, y, px, py);
    bfs_udlr(x,    y+1, px, py);
    bfs_udlr(x,    y-1, px, py);
    bfs_udlr(x+1, y+1, px, py);
    bfs_udlr(x+1, y-1, px, py);
    bfs_udlr(x-1, y+1, px, py);
    bfs_udlr(x-1, y-1, px, py);
}

int vis[800][800];
void resetvis() {
    for (int i = 0; i < 501; ++i) {
        for (int j = 0; j < 501; ++j) {
            vis[i][j] = 100000;
        }
    }
}

int maxdist;
void bfs_endpoint(int x, int y, int dist, int &edpx, int &edpy ) {
    if ( pic[x][y] != 'X') { return; }
    if (vis[x][y] <= dist) { return; }
    vis[x][y] = dist;   // smaller
    if (dist > maxdist) { edpx = x; edpy = y; maxdist = dist; }
    bfs_endpoint(x + 1, y, dist + 1, edpx, edpy);
    bfs_endpoint(x - 1, y, dist + 1, edpx, edpy);
    bfs_endpoint(x, y+1, dist + 1, edpx, edpy);
    bfs_endpoint(x, y-1, dist + 1, edpy, edpy);
    bfs_endpoint(x + 1, y+1, dist + 2, edpx, edpy);
    bfs_endpoint(x + 1, y-1, dist + 2, edpx, edpy);
    bfs_endpoint(x - 1, y+1, dist + 2, edpx, edpy);
    bfs_endpoint(x - 1, y-1, dist + 2, edpx, edpy);
}

using namespace std;
int main()
{
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file8d.txt", "r", stdin ) ) {
        return 0;
    }
#endif
    while( 2 == scanf("%d %d", &H, &W) ) {
        for (int i = 0; i < H; ++i) {
            scanf("%s", pic[i]);
        }
        int countM = 0;
        int countS = 0;
        for (int x = 0; x < H; ++x) {
            for (int y = 0; y < W; ++y) {
                if (pic[x][y] != '#') { continue; }
                u = 5000; d = -1; l = 5000; r = -1;
                int px, py;
                bfs_udlr(x, y, px, py);
                // printf("px: %d, py: %d\n", px, py);
                int ep1x, ep1y, ep2x, ep2y;
                resetvis(); maxdist = -1;
                bfs_endpoint(px, py, 0, ep1x, ep1y);
                resetvis(); maxdist = -1;
                bfs_endpoint(ep1x, ep1y, 0, ep2x, ep2y);
                // printf("p1: (%d, %d) p2: (%d, %d)\n", ep1x, ep1y, ep2x, ep2y);
                int ep3x = (ep1x + ep2x) / 2;
                int ep3y = (ep1y + ep2y) / 2;
                int midx = (l + r) / 2;
                int midy = (u + d) / 2;
                int dx = abs(midx - ep3x);
                int dy = abs(midy - ep3y);
                if (dx + dy < (r - l) / 3) {
                    ++countS;
                } else {
                    ++countM;
                }
            }
        }
        printf("%d %d\n", countM, countS);
    }
}
