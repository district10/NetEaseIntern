#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdio>

#include "Configs.h"
using namespace std;

bool validIP(vector<int> &ip) {
    // 四类网络地址，每个字段已经满足 <=255 了
    return true;
}

void dp( const string &ipstr, int cur, vector<vector<int> > &ret, vector<int> &ip ) {

    int ns = ipstr.size();      // IP 字符的长度
    int ni = ip.size();         // 已经配好的 IP 字段
    int part;                   // 存储当前 ip 段的数字

    // 终点
    if ( ni == 4 ) {
        if ( validIP(ip) ) { ret.push_back(ip); }
        return;
    }
    
    if ( ni == 3 ) {
        if ( cur>=ns || ns-cur > 3 || (part = atoi(ipstr.substr(cur).c_str())) > 255 ) { return; }
        ip.push_back( part );
        dp( ipstr, ns, ret, ip );
        ip.pop_back();
        return;
    }

    // 截取 1~3 个字符
    for ( int i = 3; i >= 1; --i ) {
        int last = cur + i;
        if ( last > ns || ns-last < 4-(ni+1) || (part = atoi(ipstr.substr(cur,i).c_str())) > 255 ) {
            continue;
        }
        ip.push_back( part );
        dp( ipstr, last, ret, ip );
        ip.pop_back();
    }
}

int main() {
    if ( !freopen( CMAKE_SOURCE_DIR "/file12.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    string ipstr;
    while( cin >> ipstr ) {
        vector<vector<int>> ret;
        vector<int> ip; ip.reserve(4);
        dp(ipstr, 0, ret, ip);
        cout << "String: " << ipstr << "\n" << ret.size();
        for (int i = 0; i < ret.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << ret[i][j] << ".";
            }
            cout << ret[i][3] << "\n";
        }
    }
}

/*
vector<vector<int> > table;
void calc(vector<vector<int>> &table) {
    for ( int i = 4; i < table.size(); ++i) {
        for (int j = i - 1; j > 1; --j) {
            if (i%j == 0) {
                table[i].push_back(j);
            }
        }
    }
}

int jump(vector<vector<int> > &table, int i, int a, int b) {
    if (a > b || i >= table[a].size() ) { return 1000000; }
    if (a == b) { return 0; }
    // try every possible way

    if (i + 1 >= table[a].size()) { return jump(table, i + 1, a + table[a][i], b); }
    else {
        min(
            jump(table, i + 1, a + table[a][i], b),
            jump(table, i + 2, a + table[a][i+1], b)
        );
    }
}

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file12.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    int N, M;
    while( 2 == scanf("%d %d", &N, &M) ) {
        vector<vector<int> > table(M + 1, vector<int>());
        calc(table);
        cout << jump(table, 0, N, M) << "\n";
    }
}
*/
