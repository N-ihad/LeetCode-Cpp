//
//  Solution.cpp
//  LeetCode-Cpp
//
//  Created by Nihad on 11/21/21.
//

#define CATCH_CONFIG_MAIN

#include <vector>
#include "catch.hpp"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0; i<s.size() / 2; ++i) {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};

TEST_CASE("hello") {
    // given
    Solution sut;
    vector<char> str{'h', 'e', 'l', 'l', 'o'};

    // when
    sut.reverseString(str);

    // then
    vector<char> expectedResult{'o', 'l', 'l', 'e', 'h'};
    REQUIRE(str == expectedResult);
}

TEST_CASE("Hannah") {
    // given
    Solution sut;
    vector<char> str{'H', 'a', 'n', 'n', 'a', 'h'};

    // when
    sut.reverseString(str);

    // then
    vector<char> expectedResult{'h', 'a', 'n', 'n', 'a', 'H'};
    REQUIRE(str == expectedResult);
}
