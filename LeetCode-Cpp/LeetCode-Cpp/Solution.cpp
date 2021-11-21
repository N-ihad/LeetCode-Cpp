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
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) {
            return {nums};
        }

        vector<vector<int>> result;

        for(int i=0; i<nums.size(); ++i) {
            vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto res = permute(v);

            for(int j=0; j<res.size(); ++j) {
                vector<int> _v = res[j];
                _v.insert(_v.begin(), nums[i]);
                result.push_back(_v);
            }
        }

        return result;
    }
};

TEST_CASE("[1, 2, 3]") {
    // given
    Solution sut;
    vector<int> nums{1, 2, 3};

    // when
    vector<vector<int>> result = sut.permute(nums);

    // then
    vector<vector<int>> expectedResult = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    REQUIRE(result == expectedResult);
}

TEST_CASE("[0, 1]") {
    // given
    Solution sut;
    vector<int> nums{0, 1};

    // when
    vector<vector<int>> result = sut.permute(nums);

    // then
    vector<vector<int>> expectedResult = {{0, 1}, {1, 0}};
    REQUIRE(result == expectedResult);
}

TEST_CASE("[1]") {
    // given
    Solution sut;
    vector<int> nums{1};

    // when
    vector<vector<int>> result = sut.permute(nums);

    // then
    vector<vector<int>> expectedResult = {{1}};
    REQUIRE(result == expectedResult);
}

