#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Configs.h"

/*
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <numeric>
#include <vector>
#include <cstddef>
#include <cctype>
#include <new>
#include <cstdio>

#include "Utils.h"
*/

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file4.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }
    std::string curLine;

    std::vector<std::string> stuffs;
    char buf[51];
    while ( 1 == scanf("%s", buf) ) {
        stuffs.push_back( buf );
    }
    std::sort( stuffs.begin(), stuffs.end() );
    stuffs.erase( std::unique(stuffs.begin(), stuffs.end()), stuffs.end() );
    std::cout << stuffs.size() << std::endl;
}