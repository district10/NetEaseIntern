#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstddef>
#include <cctype>
#include <new>
#include <cstdio>

using namespace std;

void parsePlayground( int m, int n, vector<vector<int> > &pg);

int getStatus()
{
    char c;
    while ( cin >> c ) {
        if ( c == '.' ) {
            return -1;
        }
        if ( 'A' <= c && c <= 'Z' ) {
            return c - 'A';
        }
    }
}

void printPG( vector<vector<int> > &pg )
{
    int m = pg.size();
    int n = pg[0].size();
    for ( int j = 0; j < n; ++j ) {
        for ( int i = 0; i < m; ++i ) {
            cout << "\t" << (char)(pg[i][j]+'A');
        }
        cout << "\n";
    }
}

int main()
{
    if (freopen("D:/tzx/OJ/file3.txt", "r", stdin) == NULL) {
        perror("freopen() failed");
        return EXIT_FAILURE;
    }

    int s, m, n;
    cin >> s;
    while ( s-- > 0 ) {
        cin >> m >> n;
        vector<vector<int> > pg(m, vector<int>(n, -1));
        parsePlayground( m, n, pg );
        printPG( pg );
    }

    fclose(stdin);

    return 0;
}

void parsePlayground( int m, int n, vector<vector<int> > &pg)
{
    for ( int i = 0; i < m; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            pg[i][j] = getStatus();
        }
    }
}