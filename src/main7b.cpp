#include <cstdio>

using namespace std;

#include "Configs.h"

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file7b.txt", "r", stdin ) ) {
        return 0;
    }
    int N, A, B;
    char buf[100001];
    while( 3 == scanf("%d %d %d", &N, &A, &B ) ) {
        printf("\n\n");
        scanf("%s", buf);
        int no = 0;
        int passed = 0;
        for (int i = 0; i < N; ++i) {
            bool pass = false;
            if (buf[i] == 'a') { // jap
                if (passed < A + B) { pass = true; ++passed; }
            } else if (buf[i] == 'b') { // overseas
                if (passed < A+B && ++no <= B) {
                    pass = true;
                    ++passed;
                }
            }
            if (pass) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
