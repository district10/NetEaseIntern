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

#include "Configs.h"

using namespace std;

struct dxdy {
    int dx;
    int dy;
    dxdy(int dx_, int dy_) : dx(dx_), dy(dy_) {}
};

void getout(
    int steps,
    const std::vector<std::vector<bool> > &map,
    const std::vector<dxdy> &moves,
    int x, int y,
    std::vector<int> &result )
{
    if ( steps <= 0 ) { return; }
    if ( x < 0 || y < 0 || x >= map.size() || y >= map[0].size() ) { return; }
    if ( map[x][y] == false ) { return; }
    for( int i = 0; i < moves.size(); ++i ) {
        int xx = x + moves[i].dx;
        int yy = y + moves[i].dy;
        getout( steps-1, map, moves, xx, yy, result );
    }
}

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file5.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }

    int n, m;
    while( 2 == scanf("%d %d", &n, &m) ) {
        std::vector< std::vector<bool> > dungeon(n, std::vector<bool>(m, false));
        char cell;
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                while ( scanf("%c", &cell) ) {
                    if ( '.' == cell ) {
                        dungeon[i][j] = true;
                        break;
                    } else if ( 'X' == cell ) {
                        dungeon[i][j] = false;
                        break;
                    } else {
                        continue;
                    }
                }
            }
        }

        int x0, y0;
        scanf( "%d %d", &x0, &y0 );
        int steps;
        scanf( "%d", &steps );

        std::vector<dxdy> moves;
        int dx, dy;
        while( 2 == scanf("%d %d", &dx, &dy) ) {
            moves.push_back( dxdy(dx, dy) );
        }

        /*
        std::cout << "steps are: " << steps << std::endl;
        std::cout << "x0, y0 are: " << x0 << ", " << y0 << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << "\t" << dungeon[i][j];
            }
            std::cout << "\n";
        }
        for (int i = 0; i < moves.size(); ++i) {
            std::cout << moves[i].dx << ", " << moves[i].dy << "\n";
        }
        */

        std::vector<int> result;
        getout( steps, dungeon, moves, x0, y0, result );
        if( result.size() == 0 ) {
            std::cout << -1;
        } else {
            std::sort(result.begin(), result.end());
            std::cout << result[0];
        }
    }

    string curLine;
    while ( getline( cin, curLine ) ) {
        cout << curLine << "\n";
    }
}
