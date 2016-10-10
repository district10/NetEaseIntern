#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdio>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;

vector<vector<int>> numpad(10);

int mi_realnum(int i) {
    static int lookup[] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 1 };
    return lookup[i];
}

void mi_remove(string &s, const string &num ) {
    for (int i = 0; i < num.size(); ++i) {
        s.erase(remove(s.begin(), s.end(), num[i]), s.end());
    }
}

bool mi_remove1(string &s, char c, int i, string str, vector<int> &nums) {
    auto hit = s.find_first_of(c);
    if (hit != string::npos ) {
        nums.push_back(i);
        mi_remove(s, str);
    }
    return s.find_first_of(c) == string::npos;
}

struct State {
    int hist[26];
    void init() {
        memset(hist, 0, sizeof(int) * 26);
    }
};

State str2state(const string &str) {
    State s; s.init();
    int n = str.size();
    for (int i = 0; i < n; ++i) {
        ++s.hist[i - 'A'];
    }
    return s;
}

bool rip(State &s, const string &str) {
    State ret = s;
    bool valid = true;
    int n = str.size();
    for (int i = 0; i < n; ++i) {
       if (--s.hist[i - 'A'] < 0 ) {
           valid = false;
           break;
       }
    }
    if (!valid) {
        return false;
    } else {
        swap(ret, s);
        return true;
    }
}

bool rip(State &s, vector<int> &pad) {
    bool valid = true;
    for (int i = 0; i < pad.size(); ++i) {
       if (--s.hist[pad[i]] < 0 ) {
           valid = false;
           break;
       }
    }
    return valid;
}

bool fin(const State &s) {
    for (int i = 0; i < 26; ++i) {
        if (s.hist[i] != 0) {
            return false;
        }
    }
    return true;
}

void dfs( State s, vector<int> &nums ) {
    if (fin(s)) { return; }
    for (int i = 0; i < numpad.size(); ++i) {
        cout << "hit\n";
        State ss = s;
        if (rip(ss, numpad[i])) {
            nums.push_back(i);
            dfs(ss, nums);
            nums.pop_back();
        }
    }
}

void mi_proc(string &s, vector<int> &nums) {
    while (mi_remove1(s, 'G', 8, "EIGHT", nums));
    while (mi_remove1(s, 'U', 4, "FOUR", nums));
    while (mi_remove1(s, 'W', 2, "TWO", nums));
    while (mi_remove1(s, 'X', 6, "SIX", nums));
    while (mi_remove1(s, 'Z', 0, "ZERO", nums));
    if (s.empty()) { return; }
    State init = str2state(s);
    dfs( init, nums );
}

int main() {
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file2a.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
#endif
    vector<vector<int>> numpad(10);
    const char *numpadstr[] = {
        "ZERO", "ONE", "TWO", "THREE", "FOUR",
        "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };
    for (int i = 0; i < 10; ++i) {
        int len = strlen(numpadstr[i]);
        for (int j = 0; j < len; ++j) {
            numpad[i].push_back(numpadstr[i][j] - 'A');
        }
    }

    int T;
    while (1 == scanf("%d", &T)) {
        vector<string> cases(T);
        for (int i = 0; i < T; ++i) {
            cin >> cases[i];
            cout << cases[i] << "\n"; 
            vector<int> nums;
            mi_proc(cases[i], nums);
            cout << "hithithit\n"; 
            for (int i = 0; i < nums.size(); ++i) {
                nums[i] = mi_realnum(nums[i]);
            }
            cout << "hithithit\n"; 
            sort(nums.begin(), nums.end());
            cout << "hithithit\n"; 
            copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, "")); cout << "\n";
            cout << "hithithit\n"; 
        }
    }
}