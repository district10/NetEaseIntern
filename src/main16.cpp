#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <climits>

#include "Configs.h"
using namespace std;

void update(vector<vector<int>> &table, vector<int> &dist, int target) {
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file16.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    string line;
    int Va, Vb; // Va -> Vb
    getline(cin, line);
    sscanf(line.c_str(), "%d %d", &Va, &Vb);
    int f, t, n;
    vector<vector<int>> tuples;
    set<int> vers;
    while (getline(cin, line) && 3 == sscanf(line.c_str(), "%d %d %d", &f, &t, &n)) {
        vector<int> tpl(3); tpl[0] = f; tpl[1] = t; tpl[2] = n;
        tuples.push_back(tpl);
        vers.insert(f);
        vers.insert(t);
        // printf("%d, %d, %d\n", f, t, n);
    }
    int nv = vers.size();
    map<int, int> v2i, i2v;
    set<int>::iterator i = vers.begin();
    int idx = 0;
    while (i != vers.end()) {
        i2v[idx] = *i;
        v2i[*i] = idx;
        ++idx;
    }
    vector<vector<int>> table(nv, vector<int>(nv, 0));
    for (int i = 0; i < tuples.size(); ++i) {
        vector<int> &t = tuples[i];
        table[v2i[t[0]]][v2i[t[1]]] = t[2];
    }
    vector<int> dist(nv, INT_MAX);
    dist[v2i[Va]] = 0;
}
