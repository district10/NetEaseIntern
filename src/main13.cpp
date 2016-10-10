#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdio>

#include "Configs.h"
using namespace std;

bool inside(vector<vector<char>> &table, int x, int y) {
    return x >= 0 && x < table.size() && y >= 0 && y < table[0].size();
}
void printtable(vector<vector<char>> &table) {
    cout << "table:\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << table[i][j];
        }
        cout << "\n";
    }
}

void count(vector<vector<char> > &table, int &nb, int &nw) {
    nb = nw = 0;
    for (int i = 0; i < table.size(); ++i) {
        for (int j = 0; j < table[0].size(); ++j) {
            if (table[i][j] == '*') {
                ++nb;
            } else if (table[i][j] == 'o') {
                ++nw;
            }
        }
    }
}

void expand(vector<vector<char> > &table, const int x, const int y, const int t) {
    if ( !inside(table, x, y) || table[x][y] != '.' ) { return; }
    char t0 = t == 0 ? '*' : 'o';
    char t1 = t == 0 ? 'o' : '*';
    table[x][y] = t0;
    // 0->(0,1), 1->(-1,1), 2->(-1,0), 3->(-1,-1)
    // 4->(1,-1), 5->(1,0), 6->(-1,0), 7->(1,1)
    int dx[8] = { 0, -1, -1, -1, 1, 1, -1, 1};
    int dy[8] = { 1, 1, 0, -1, -1, 0, 0, 1};
    for (int i = 0; i < sizeof(dx)/sizeof(dx[0]); ++i) {
        int xx = x, yy = y;
        while (inside(table, xx + dx[i], yy + dy[i]) && table[xx+dx[i]][yy+dy[i]] == t1 ) {
            xx += dx[i];
            yy += dy[i];
        }
        if (!inside(table, xx, yy)) {
            continue;
        } else if ( xx != x && yy != y && table[xx][yy] == t0 ) {
            // merge
            xx -= dx[i];
            yy -= dy[i];
            while (xx != x && yy != y) {
                table[xx][yy] = t0;
                xx -= dx[i];
                yy -= dy[i];
            }
        }
    }
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file13.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int S;
    scanf("%d", &S);
    cout << "S is " << S << "\n";
    vector<vector<char> > table(8, vector<char>(8));
    while (S--) {
        int i = 0;
        while (i < 64) {
            char c = getchar();
            if (c != '*' && c != 'o' && c != '.') { continue; }
            table[i / 8][i % 8] = c;
            ++i;
        }
        int N;
        scanf("%d", &N);
        while (N--) {
            int x, y, t;
            scanf("%d %d %d", &x, &y, &t);
            expand(table, x, y, t);
            printtable(table);
            // printf("%d %d %d\n", x, y, t);
        }
        int nb, nw;
        count(table, nb, nw);
        printf("%d %d\n", nb, nw);
        // printtable(table);
    }
}