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

void printMat( vector<vector<int> > &img );
void printDebug( vector<vector<int> > &img ){
    return;
    int r = img.size();
    int c = img[0].size();
    cout << "\n";
    for ( int i = 0; i < r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            cout << "\t" << img[i][j];
        }
        cout << "\n";
    }
}

// clockwise rotation
void action1( vector<vector<int> > &img );

// counterclockwise rotation
void action2( vector<vector<int> > &img );

// mirror rows
void action3( vector<vector<int> > &img );

// mirror cols
void action4( vector<vector<int> > &img );

// roi inc
void action5( vector<vector<int> > &img, int x0, int y0, int x1, int y1, int inc );

// roi dec
void action6( vector<vector<int> > &img, int x0, int y0, int x1, int y1, int dec );

// roi select
void action7( vector<vector<int> > &img, int x0, int y0, int x1, int y1 );

int main()
{
    if (freopen( CMAKE_SOURCE_DIR "file1.txt", "r", stdin) == NULL) {
        perror("freopen() failed");
        return EXIT_FAILURE;
    }

    int s, row, col, t;
    cin >> s;
    while ( s-- > 0 ) {
        cin >> row >> col;
        vector<vector<int> > img(row, vector<int>(col, 0));
        for ( int r = 0; r < row; ++r ) {
            for ( int c = 0; c < col; ++c ) {
                cin >> img[r][c];
            }
        }

        cin >> t;
        while ( t-- > 0 ) {
            int type;
            cin >> type;
            if ( false ) {
            } else if ( 1 == type ) {
                action1( img );
            } else if ( 2 == type ) {
                action2( img );
            } else if ( 3 == type ) {
                action3( img );
            } else if ( 4 == type ) {
                action4( img );
            } else if ( 5 == type ) {
                int x0, y0, x1, y1, value;
                cin >> x0 >> y0 >> x1 >> y1 >> value;
                action5( img, x0, y0, x1, y1, value );
            } else if ( 6 == type ) {
                int x0, y0, x1, y1, value;
                cin >> x0 >> y0 >> x1 >> y1 >> value;
                action6( img, x0, y0, x1, y1, value );
            } else if ( 7 == type ) {
                int x0, y0, x1, y1;
                cin >> x0 >> y0 >> x1 >> y1;
                action7( img, x0, y0, x1, y1 );
            } else {
            }
        }
        printMat( img );
    }

    fclose(stdin);

    return 0;
}

void action1( vector<vector<int> > &img )
{
    int r = img.size();
    int c = img[0].size();
    int n = r * c;
    vector<vector<int> > out(c, vector<int>(r, 0));

    for ( int ii = 0; ii < c; ++ii ) {
        for ( int jj = 0; jj < r; ++jj ) {
            out[ii][jj] = img[jj][ii];
        }
    }
    action4( out );

    img = out;
}

void action2( vector<vector<int> > &img )
{
    action1( img );
    action3( img );
    action4( img );
}

void action3( vector<vector<int> > &img )
{
    int r = img.size();
    int c = img[0].size();
    for ( int ii = 0; ii < r/2; ++ii ) {
        for ( int jj = 0; jj < c; ++jj ) {
            swap(img[r-1-ii][jj], img[ii][jj]);
        }
    }
}

// mirror cols
void action4( vector<vector<int> > &img )
{
    int r = img.size();
    int c = img[0].size();
    for ( int ii = 0; ii < r; ++ii ) {
        for ( int jj = 0; jj < c/2; ++jj ) {
            swap(img[ii][c-1-jj], img[ii][jj]);
        }
    }
}

// roi inc
void action5( vector<vector<int> > &img, int x0, int y0, int x1, int y1, int inc )
{
    for ( int ii = x0; ii <= x1; ++ii ) {
        for ( int jj = y0; jj <= y1; ++jj ) {
            img[ii][jj] += inc;
            if ( img[ii][jj] > 255 ) { img[ii][jj] = 255; }
            if ( img[ii][jj] < 0 ) { img[ii][jj] = 0; }
        }
    }
}

// roi dec
void action6( vector<vector<int> > &img, int x0, int y0, int x1, int y1, int dec )
{
    action5( img, x0, y0, x1, y1, -dec );
}

// roi select
void action7( vector<vector<int> > &img, int x0, int y0, int x1, int y1 )
{
    int dx = x1 - x0 + 1;
    int dy = y1 - y0 + 1;
    vector<vector<int> > out(dx, vector<int>(dy, 0));
    for ( int ii = 0; ii < dx; ++ii ) {
        for ( int jj = 0; jj < dy; ++jj ) {
            out[ii][jj] = img[ii+x0][jj+y0];
        }
    }
    img = out;
}

void printMat( vector<vector<int> > &img )
{
    int r = img.size();
    int c = img[0].size();

    int sum = 0;
    for ( int i = 0; i < r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            sum += img[i][j];
        }
    }
    cout << r << " " << c  << " " << img[0][0] << " " << sum << endl;
}
