#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>

#include "Configs.h"
using namespace std;

void populate( string s, map<int, int> &m, int &n) {
    if (s.size() > 9) { return; }
    int a = atoi(s.c_str());
    int ret;
    if (!m.count(a)) {
        sscanf(s.c_str(), "%d", &ret);
        m[a] = n++;
    }
    populate(s + "0", m, n);
    populate(s + "1", m, n);
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file19.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int count = 1;
    map<int, int> m;
    populate("1", m, count);
    vector<int> nums;
    nums.reserve(m.size());
    for (pair<int, int> p : m) {
        nums.push_back(p.first);
    }
    sort(nums.begin(), nums.end());
    int n;
    while (1 == scanf("%d", &n)) {
        // cout << n << "\t" << 1+distance(nums.begin(), lower_bound(nums.begin(), nums.end(), n)) << "\n";
        int i = 0;
        while (i < nums.size() && nums[i] < n) {
            ++i;
        }
        cout << m[i] << "\n";
    }
}