#include <cstdio>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

#define max(a, b) ((a)>(b)?(a):(b))

int A[1000000];
int f[1000000];

void dp(int n) {
    f[0] = 0;
    f[1] = 0;
    f[2] = (A[0] + A[1]) & 1 ? 2 : 0;
    for (int i = 3; i <= n; ++i) {
        if ((A[i - 1] + A[i - 2]) & 1) {
            int f1 = f[i - 1];
            int f2 = f[i - 2] + 2;
            int f3 = f[i - 3] + ((A[i - 2] + A[i - 3]) & 1 ? 2 : 0);
            if (f1 > f2) { f2 = f3; }
            if (f1 < f2) { f1 = f2; }
            f[i] = f1;
        } else {
            f[i] = f[i - 1];
        }
    }
}

int main()
{
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file8a.txt", "r", stdin ) ) {
        return 0;
    }
#endif
    int N;
    while( 1 == scanf("%d", &N) && N ) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        dp(N);
        printf("%d\n", N-f[N]);
    }
}