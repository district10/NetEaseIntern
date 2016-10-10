#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>

#include "Configs.h"
using namespace std;

bool symmetry(char pad[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << pad[i][j] << "\t";
        }
        cout << "\n";
    }
    return pad[0][0] == pad[2][2] 
        && pad[0][1] == pad[2][1] 
        && pad[0][2] == pad[2][0] 
        && pad[1][0] == pad[1][2];
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            if (pad[i][j] != pad[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file18.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    char pad[3][3];
    int cnt = 0;
    char c;
    while (1 == scanf("%c", &c)) {
        if (c != '.' && c != 'X') { continue; }
        pad[cnt / 3][cnt % 3] = c;
        ++cnt;
        if (cnt == 9) {
            if (symmetry(pad)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            cnt = 0;
        }
    }
}