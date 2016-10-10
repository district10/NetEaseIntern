#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstddef>
using namespace std;

#include "Configs.h"

int W, H;
int P[100000], Q[100000];
const int MAX_NV = 100000000;

struct graph_t {
    int nv, ne;
    int matrix[MAX_NV][MAX_NV];
};

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file7c.txt", "r", stdin ) ) {
        return 0;
    }
    while( 2 == scanf("%d %d", &W, &H) ) {
        for (int i = 0; i < W; ++i) { scanf("%d", &P[i]); }
        for (int i = 0; i < H; ++i) { scanf("%d", &Q[i]); }
    }
}
