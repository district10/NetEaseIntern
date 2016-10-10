#include <unordered_set>
#include <cstdio>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

char b[100001];
char f[100001];
char p[26*26][3];
unordered_set<int> s;

int p2i(const char &a, const char &b) {
    char aa = a < b ? a : b;
    char bb = a < b ? b : a;
    return (aa - 'a') * 100 + bb;
}

void dp( int N ) {
    f[0] = 0;
    f[1] = 0;
    f[2] = s.count(p2i(b[0], b[1])) ? 2 : 0;
    for (int i = 3; i <= N; ++i) {
        if (s.count(p2i(b[i - 1], b[i - 2]))) {
            int f1 = f[i - 1]; 
            int f2 = f[i - 2]+2;
            f[i] = f1 < f2 ? f1 : f2;
        } else {
            f[i] = f[i - 1];
        }
    }
}

int main()
{
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file8b.txt", "r", stdin ) ) {
        return 0;
    }
#endif
    int N, M;
    while( 1 == scanf("%d", &N) && N ) {
        scanf("%s", b);
        scanf("%d", &M);
        s.clear();
        for (int i = 0; i < M; ++i) {
            scanf("%s", p[i]);
            s.insert(p2i(p[i][0], p[i][1]));
        }
        dp(N);
        printf("%d\n", f[N]);
    }
}
