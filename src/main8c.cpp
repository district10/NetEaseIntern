#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <new>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
/*
*/

#define LOCAL 1
// #define LOCAL 0

#if LOCAL
#include "Configs.h"
#endif

using namespace std;
int main()
{
#if LOCAL
    if ( !freopen( CMAKE_SOURCE_DIR "/file8a.txt", "r", stdin ) ) {
        return 0;
    }
#endif
    int n;
    while( 1 == scanf("%d", &n) && n ) {
        printf("%d", n);
    }
}
