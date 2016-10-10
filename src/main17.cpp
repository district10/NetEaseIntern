 #include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>

#include "Configs.h"

using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2, YELLOW = 3, PURPLE = 4, BLANK = 5;

bool inside(int x, int y) {
    return 0 <= x && x < 10 && 0 <= y && y < 10;
}

void drop(int table[][10], int col, int r0, int r1, int len ) {
    for (int i = 0; i < len; ++i) {
        table[r0 - i][col] = inside(r1 - i, col) ? table[r1 - i][col] : BLANK;
    }
}

void drop( int table[][10]) {
    for (int c = 0; c < 10; ++c) {
        int r1, r0 = 9;
        while (inside(r0, c) && table[r0][c] != BLANK) { --r0; }
        if (!inside(r0, c)) { continue; }
        r1 = r0;
        while ( inside(r1-1,c) && table[r1-1][c] == BLANK) { --r0; }
        int len = r1 - r0;
        if (len > 0) {
            drop(table, c, r0, r1, len);
        }
    }
}

void shift(int table[][10]) {
    // TODO
}

// const int RED = 0, GREEN = 1, BLUE = 2, YELLOW = 3, PURPLE = 4, BLANK = 5;
void count(int table[][10], int &nred, int &ngreen, int &nblue, int &nyellow, int &npurple) {
    nred = ngreen = nblue = nyellow = npurple = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (table[i][j] == RED) { ++nred; }
            else if (table[i][j] == GREEN) { ++ngreen; }
            else if (table[i][j] == BLUE) { ++nblue; }
            else if (table[i][j] == YELLOW) { ++nyellow; }
            else if (table[i][j] == PURPLE) { ++npurple; }
        }
    }
}

void dfs(int table[][10], int x, int y, int t) {
    if (!inside(x, y) || table[x][y] != t || table[x][y] == BLANK) { return; }
    table[x][y] = BLANK;
    dfs(table, x+1, y, t);
    dfs(table, x-1, y, t);
    dfs(table, x, y+1, t);
    dfs(table, x, y-1, t);
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file17.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    string line;
    while (getline(cin, line)) {
        int p[10][10] = {
            {RED,RED,BLUE,BLUE,GREEN,YELLOW,BLUE,YELLOW,RED,PURPLE},
            {GREEN,GREEN,GREEN,BLUE,RED,PURPLE,RED,YELLOW,YELLOW,BLUE},
            {BLUE,RED,RED,YELLOW,YELLOW,PURPLE,BLUE,GREEN,GREEN,BLUE},
            {YELLOW,RED,BLUE,YELLOW,BLUE,RED,PURPLE,GREEN,GREEN,RED},
            {YELLOW,RED,BLUE,BLUE,PURPLE,GREEN,PURPLE,RED,YELLOW,BLUE},
            {PURPLE,YELLOW,RED,RED,YELLOW,RED,PURPLE,YELLOW,RED,RED},
            {YELLOW,YELLOW,GREEN,PURPLE,GREEN,RED,BLUE,YELLOW,BLUE,GREEN},
            {RED,YELLOW,BLUE,BLUE,YELLOW,GREEN,PURPLE,RED,BLUE,GREEN},
            {GREEN,GREEN,YELLOW,YELLOW,RED,RED,PURPLE,BLUE,BLUE,GREEN},
            {PURPLE,BLUE,RED,RED,PURPLE,YELLOW,BLUE,RED,RED,GREEN} };
        istringstream ss(line);
        int pos;
        while (ss >> pos) {
            int x = (pos - 1) / 10;
            int y = (pos - 1) % 10;
            dfs(p, x, y, p[x][y]); // ÏûÈ¥
            drop(p); // ½µÂä
            shift(p); // ×óÒÆ
        }
        int nr, ng, nb, ny, np;
        count(p, nr, ng, nb, ny, np);
        printf("%d %d %d %d %d\n", nr, ng, nb, ny, np);
    }
}
