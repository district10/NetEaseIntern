#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>

#include "Configs.h"
using namespace std;

vector<vector<int>> split(vector<int> &arr, int beg, int len ) {
    vector<vector<int>> nums;
    vector<int> num;
    for (int i = 0; i < beg; ++i) {
        num.push_back(arr[i] );
    }
    if (!num.empty()) {
        nums.push_back(num);
    }
    num.clear();
    int n = arr.size();
    int cnt = 0;
    while (beg < n) {
        num.push_back(arr[beg]);
        if (++cnt == len) {
            cnt = 0;
            if (!num.empty()) {
                nums.push_back(num);
                num.clear();
            }
        }
        ++beg;
    }
    if (!num.empty()) {
        nums.push_back(num);
    }
    return nums;
}

bool validnums(vector<vector<int>> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        set<int> s;
        for (int j = 0; j < nums[i].size(); ++j) {
            if (s.count(nums[i][j])) {
                return false;
            }
            s.insert(nums[i][j]);
        }
    }
    return true;
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file15.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int S;
    scanf("%d", &S);
    while (S--) {
        int N, L;
        scanf("%d %d", &N, &L);
        vector<int> Ls(L);
        for (int i = 0; i < L; ++i) {
            int num;
            scanf("%d", &num);
            Ls[i] = num;
        }
        bool valid = false;
        for (int i = 0; i < N - 1; ++i) {
            vector<vector<int>> nums = split(Ls, i, N);
            if (validnums(nums)) {
                valid = true;
                break;
            }
        }
        if (valid) {
            printf("CAN'T DECIDE\n");
        } else {
            printf("B\n");
        }
    }
}