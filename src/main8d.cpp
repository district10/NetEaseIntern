#include <queue>
#include <cstdio>
#include <unordered_set>

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 501
#define DOT '#'
#define CLR 'X'
#define BEG '@'
#define END '@'
#define MID '@'

int H, W;
char pic[MAXN][MAXN];
const int dx[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
const int dy[] = { 1,-1, 0,  1, -1,  0, 1,-1 };

struct Point {
    int x, y;
    Point( int x = 0, int y = 0 ) : x(x), y(y) { }
    bool valid() const {
        return 0 <= x && x < H && 0 <= y && y < W;
    }
    bool operator==( const Point &rhs ) const {
        return x == rhs.x && y == rhs.y;
    }
};

namespace std {
    template<> struct hash<Point> {
        size_t operator()( const Point &p ) const {
            return p.x * MAXN + p.y;
        }
    };
}

void coloring( Point sp, Point &hp, int &u, int &d, int &l, int &r ) {
    if ( !sp.valid() || pic[sp.x][sp.y] != DOT ) { return; }
    pic[sp.x][sp.y] = CLR;
    if( sp.x < u ) { hp = sp; }
    u = min(u, sp.x); d = max(d, sp.x);
    l = min(l, sp.y); r = max(r, sp.y);
    for( int i = 0; i < sizeof(dx)/sizeof(dx[0]); ++i ) {
        coloring( Point(sp.x+dx[i],sp.y+dy[i]), hp, u, d, l, r );
    }
}

void reachingout( Point sp, Point &ep ) {
    unordered_set<Point> s;
    queue<Point> q;
    q.push( sp );
    while( !q.empty() ) {
        Point p = q.front(); q.pop();
        for( int i = 0; i < sizeof(dx)/sizeof(dx[0]); ++i ) {
            Point np(p.x+dx[i], p.y+dy[i]);
            if( np.valid() && pic[np.x][np.y] == CLR && !s.count(np) ) {
                s.insert( np );
                q.push( np );
            }
        }
        ep = p;
    }
}

using namespace std;
int main()
{
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file8d.txt", "r", stdin ) ) {
        return 0;
    }
#endif
    while( 2 == scanf("%d %d", &H, &W) ) {
        for( int i = 0; i < H; ++i ) {
            scanf( "%s", pic[i] );
        }
        int countM = 0;
        int countS = 0;
        for( int x = 0; x < H; ++x ) {
            for( int y = 0; y < W; ++y ) {
                if( pic[x][y] != DOT ) { continue; }
                int u = H, d = 0, l = W, r = 0;
                Point sp( x, y ), hp( x, y );
                coloring( sp, hp, u, d, l, r );
                Point center( (u+d)/2, (l+r)/2 );
                Point ep1, ep2, mid;
                reachingout( hp,  ep1 );
                reachingout( ep1, ep2 );
                mid = Point( (ep1.x+ep2.x)/2, (ep1.y+ep2.y)/2 );
                pic[mid.x][mid.y] = MID;
                pic[ep1.x][ep1.y] = BEG;
                pic[ep2.x][ep2.y] = END;
                Point &m = mid;
                Point &c = center;
                if( abs(m.x-c.x)+abs(m.y-c.y) < ((r-l)+(d-u)) / 4 ) {
                    ++countS;
                } else {
                    ++countM;
                }
            }
        }
        for( int i = 0; i < H; ++i ) {
            fprintf( stderr, "%s\n", pic[i] );
        }
        printf("%d %d\n", countM, countS);
    }
}
