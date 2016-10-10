#include <cstdio>
#include <iostream>
#include <string>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

bool equal(const string &str, int j) {
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        if (str[i] != str[(j + i) % n]) { 
            return false;
        }
    }
    return true;
}

int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file4b.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return -1;
    }
#endif

    string str;
    while ( cin >> str ) {
        int k = 0, n = str.length();
        for (int i = 0; i < n; ++i) {
            k += equal(str, i) ? 1 : 0;
        }
        cout << k << "\n";
    }
    return 0;
}