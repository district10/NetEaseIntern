#include <algorithm>
#include <vector>
#include <cstdio>

#include "Configs.h"
using namespace std;

void dfs(vector<int> &nums, int cur, int got, int goal, int &counter ) {
    if (got == goal) { ++counter; return; }
    int n = nums.size();
    if (got > goal || cur >= n ) { return; }
    dfs(nums, cur + 1, got, goal, counter);

    int gap = goal - got;
    if ((n - cur)*nums[cur] < gap) { return; }
    dfs(nums, cur + 1, got + nums[cur], goal, counter);
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file1c.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int n, sum;
    while (2 == scanf("%d %d", &n, &sum)) {
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        sort(nums.begin(), nums.end());
        int counter = 0;
        dfs(nums, 0, 0, sum, counter);
        printf("%d\n", counter);
    }
}