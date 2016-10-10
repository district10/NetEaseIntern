#include <vector>
#include <cstdio>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

class Cube {
public:
    explicit Cube(int length) : length(length) {
        elems = vector<vector<vector<int>>>(length, vector<vector<int>>(length, vector<int>(length)));
    }
    void scanfCube() {
        for (int x = 0; x < length; ++x) {
            for (int y = 0; y < length; ++y) {
                for (int z = 0; z < length; ++z) {
                    scanf("%d", &elems[x][y][z]);
                }
            }
        }
    }
    void reset(int val = 0) {
        for (int x = 0; x < length; ++x) {
            for (int y = 0; y < length; ++y) {
                for (int z = 0; z < length; ++z) {
                    elems[x][y][z] = val;
                }
            }
        }
    }
    void print() {
        for (int x = 0; x < length; ++x) {
            for (int y = 0; y < length; ++y) {
                printf("\t");
                for (int z = 0; z < length; ++z) {
                    printf(" %d", elems[x][y][z]);
                }
            }
            printf("\n");
        }
    }
    vector<vector<vector<int>>> elems;
    int length;
};

bool empty(const Cube &vis, int length, int x, int y, int z) {
    int bl = vis.length, sl = length;
    if (x < 0 || x + sl >= bl || y < 0 || y + sl >= bl || z < 0 || z + sl >= bl) {
        return false;
    }
    if (   vis.elems[x][y][z] 
        || vis.elems[x][y][z+sl]
        || vis.elems[x][y+sl][z]
        || vis.elems[x][y+sl][z+sl]
        || vis.elems[x+sl][y][z] 
        || vis.elems[x+sl][y][z+sl]
        || vis.elems[x+sl][y+sl][z]
        || vis.elems[x+sl][y+sl][z+sl] ) { return false; }
    for (int i = 0; i < sl; ++i) {
        for (int j = 0; j < sl; ++j) {
            for (int k = 0; k < sl; ++k) {
                if (vis.elems[x + i][y + j][z + k]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool set(Cube &big, Cube &vis, const Cube &small, int x, int y, int z, int P) {
    Cube copy = big;
    int length = small.length;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            for (int k = 0; k < length; ++k) {
                copy.elems[x + i][y + j][z + k] += small.elems[i][j][k];
                if (copy.elems[x + i][y + j][z + k] % P != 0) {
                    return false;
                }
            }
        }
    }
    swap(big, copy);
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            for (int k = 0; k < length; ++k) {
                vis.elems[x + i][y + j][z + k] = 1;
            }
        }
    }
    return true;
}

void reset(Cube &big, Cube &vis, const Cube &small, int x, int y, int z) {
    int length = small.length;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            for (int k = 0; k < length; ++k) {
                big.elems[x + i][y + j][z + k] -= small.elems[i][j][k];
                vis.elems[x + i][y + j][z + k] = 0;
            }
        }
    }
}

bool valid(const Cube &big, int P) {
    int length = big.length;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            for (int k = 0; k < length; ++k) {
                if (big.elems[i][j][k] % P != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

struct Position {
    int x, y, z;
    void set(int i, int j, int k) { x = i; y = j; z = k; }
};

void dfs(Cube &big, Cube &vis, vector<Cube> &cubes, int cur, vector<Position> &pos, int P) {
    int N = cubes.size();
    if (cur == N) {
        if (valid(big, P)) {
            for (int i = 0; i < N; ++i) {
                Position &p = pos[i];
                printf("%d %d %d\n", p.x, p.y, p.z);
            }
        }
        return;
    }
    int length = big.length;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            for (int k = 0; k < length; ++k) {
                if (empty(vis, cubes[cur].length, i, j, k)) {
                    if (set(big, vis, cubes[cur], i, j, k, P)) {
                        pos[cur].set(i, j, k);
                        dfs(big, vis, cubes, cur + 1, pos, P);
                        reset(big, vis, cubes[cur], i, j, k);
                    }
                }
            }
        }
    }
}

int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file5a.txt", "r", stdin ) ) { return -1; }
#endif
    int M, N, P;
    while (3 == scanf("%d %d %d", &M, &N, &P)) {
        Cube bigCube(M);
        bigCube.scanfCube();
        vector<Cube> smallCubes;
        for (int n = 0; n < N; ++n) {
            int d;
            scanf("%d", &d);
            Cube c = Cube(d);
            c.scanfCube();
            smallCubes.push_back(c);
        }
        Cube vis(M);
        vis.reset(0);
        vector<Position> positions(N);
        dfs(bigCube, vis, smallCubes, 0, positions, P);
    }
    return 0;
}