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

std::string trim( std::string s )
{
    if ( s.empty() ) {
        return s;
    }

    s.erase( 0, s.find_first_not_of(" ") );
    s.erase( s.find_last_not_of(" ") + 1 );
    return s;
}

void split( std::string s, std::string &delim, std::vector< std::string > &ret )
{  
    size_t last = 0;  
    size_t index = s.find_first_of( delim, last );
    while ( index != std::string::npos ) {  
        ret.push_back( s.substr(last,index-last) );
        last = index+1;  
        index = s.find_first_of( delim, last );
    }  
    if ( index-last>0 ) {  
        ret.push_back( s.substr(last,index-last) );  
    }  
}  

void line2vec( const std::string &s, std::vector< std::string > &ret )
{  
    size_t left, right;
    left = s.find_first_of( std::string("[["), 0 );
    if ( left == std::string::npos ) {
        return;
    }
    
    left  = s.find_first_of( std::string("["), left+1 );
    right = s.find_first_of( std::string("]"), left );
    while ( left != std::string::npos && right != std::string::npos ) {  
        std::string p = s.substr( left+1, right-left-1 );
        ret.push_back( p );
        left  = s.find_first_of( std::string("["), right ); 
        right = s.find_first_of( std::string("]"), left  );
    }  
}

void str2ints( const std::string &s, std::vector<int> &ret )
{
    int i;
    if ( 1 != sscanf(s.c_str(), "%d", &i) ) {
        return;
    }
    ret.push_back(i);

    size_t left;
    left = s.find_first_of( std::string(","), 0 );
    while( left != std::string::npos ) {
        if ( 1 == sscanf(s.substr(left).c_str(), "%*c%d", &i) ) {
            ret.push_back(i);
        }
        left = s.find_first_of(std::string(","), left+1);
    }
}