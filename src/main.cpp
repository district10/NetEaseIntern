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
#include <ctime>

#include "Configs.h"

using namespace std;

int main()
{
    if (!freopen(CMAKE_SOURCE_DIR "/file.txt", "r", stdin)) {
        perror("freopen() failed");
        return EXIT_FAILURE;
    }
    int n;
    cin >> n;
    int a = 0, b = 1;
    int dist = min(n, n-1);
    for ( ;; ) {
        b = a + b;
        a = b - a;
        if (abs(b-n) > dist) {
            break;
        }
        dist = abs(b - n);
    }
    cout << dist << "\n";
}

using namespace std;

/*
int main()
{
    if (!freopen(CMAKE_SOURCE_DIR "/file.txt", "r", stdin)) {
        perror("freopen() failed");
        return EXIT_FAILURE;
    }

    int n;
    bool bylength, bylex;
    while (cin >> n && n) {
        bylength = bylex = true;
        string cur, prev;
        cin >> prev;
        while (--n) {
            cin >> cur;
            if (cur.length() < prev.length()) { bylength = false; }
            if (cur < prev) { bylex = false; }
            swap(prev, cur);
        }
        if (bylength && bylex) {
            cout << "both\n";
        }
        else if (bylength) {
            cout << "length\n";
        }
        else if (bylex) {
            cout << "lexicographically\n";
        }
        else {
            cout << "none\n";
        }
    }
}

int main()
{
    if (!freopen(CMAKE_SOURCE_DIR "/file.txt", "r", stdin)) {
        perror("freopen() failed");
        return EXIT_FAILURE;
    }

    int n;
    while (cin >> n && n) {
        vector<int> trap(n);
        int tmp;
        for (int i = 0; i < n; ++i) { scanf("%d", &trap[i]); }
        for (int i = 0; i < n; ++i) { scanf("%d", &tmp); trap[i] += tmp; }
        std::vector<int>::iterator dist;
        dist = std::min_element(trap.begin(), trap.end());
        if (dist != trap.end()) {
            cout << (*dist - 2) << endl;
        }
    }
    return 0;
}

template<class T, class Compare>
std::pair<const T&, const T&> minmax( const T& a, const T& b, Compare comp )
{
    return comp(b, a) ? std::pair<const T&, const T&>(b, a)
                      : std::pair<const T&, const T&>(a, b);
}

int main()
{
    if ( !freopen( CMAKE_SOURCE_DIR "/file.txt", "r", stdin ) ) {
        perror( "freopen() failed" );
        return EXIT_FAILURE;
    }

    string curLine;
    while ( getline( cin, curLine ) ) {
        cout << curLine << "\n";
    }

    std::string s = "Hello, world";
    std::reverse_iterator<std::string::iterator> r = s.rbegin();
    *r = 'x'; // replaces 'o' with 'O'
    r += 7; // iterator now points at 'O'
    std::string rev(r, s.rend());
    std::cout << rev << '\n'; // "OlleH"

    std::cout << std::max(1, 9999);
    std::cout << std::max('a', 'b');
    std::cout << std::max({ "foo", "bar", "hello" }, [](const std::string& s1, const std::string& s2) {
        return s1.size() < s2.size();
    });

    std::vector<int> v {3, 1, 4, 1, 5, 9, 2, 6};
    std::srand(std::time(0));
    std::pair<int, int> bounds = std::minmax(std::rand() % v.size(),
                                             std::rand() % v.size());

    std::cout << "v[" << bounds.first << "," << bounds.second << "]: ";
    for (int i = bounds.first; i < bounds.second; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';

    std::istringstream str("0.1 0.2 0.3 0.4");
    std::partial_sum(std::istream_iterator<double>(str),
                      std::istream_iterator<double>(),
                      std::ostream_iterator<double>(std::cout, " "));

    std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };

    auto lower = std::lower_bound(data.begin(), data.end(), 4);
    auto upper = std::upper_bound(data.begin(), data.end(), 5);

    std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));

    {
        std::string s("hello");
        // std::transform(s.begin(), s.end(), s.begin(), ::toupper );
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::toupper(c); });
        std::cout << s;
    }

    {
        std::vector<int> v{ 3, 1, 4 };
        std::cout << "distance(first, last) = "
            << std::distance(v.begin(), v.end()) << '\n'
            << "distance(last, first) = "
            << std::distance(v.end(), v.begin()) << '\n';
    }

    {
        std::string str1 = "Text with some   spaces";
        str1.erase(std::remove(str1.begin(), str1.end(), ' '),
            str1.end());
        std::cout << str1 << '\n';

        std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
        str2.erase(std::remove_if(str2.begin(),
            str2.end(),
            [](char x) {return std::isspace(x);}),
            str2.end());
        std::cout << str2 << '\n';
    }

    std::cout << "\n-----------------------\n";
    {
        // remove duplicate elements (normal use)
        std::vector<int> v{ 1,2,3,1,2,3,3,4,5,4,5,6,7 };
        std::sort(v.begin(), v.end()); // 1 1 2 2 3 3 3 4 4 5 5 6 7
        auto last = std::unique(v.begin(), v.end());
        // v now holds {1 2 3 4 5 6 7 x x x x x x}, where 'x' is indeterminate
        v.erase(last, v.end());
        for (int i : v)
            std::cout << i << " ";
        std::cout << "\n";

        // remove consecutive spaces
        std::string s = "wanna go    to      space?";
        auto end = std::unique(s.begin(), s.end(), [](char l, char r) {
            return std::isspace(l) && std::isspace(r) && l == r;
        });
        // s now holds "wanna go to space?xxxxxxxx", where 'x' is indeterminate
        std::cout << std::string(s.begin(), end) << '\n';
    }
}
*/
