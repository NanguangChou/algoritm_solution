//
//  main.cpp
//  algorithm_015_threeSum
//
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

//  Created by zhounanguang on 15/12/30.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if(nums.size()<3){
            return {};
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-2; i++) {
			if(i>0&&nums[i]==nums[i-1]){
				continue;
			}
			int j = i+1, k =nums.size()-1;
			while(j<k){
				if(j>i+1 &&nums[j]==nums[j-1]){
					j++;
					continue;
				}
				if(k<nums.size()-1 &&nums[k]==nums[k+1]){
					k--;
					continue;
				}
				if(nums[i]+nums[j]+nums[k]<0){
					j++;
				}
				else if(nums[i]+nums[j]+nums[k]>0){
					k--;
				}
				else{
					int arr[] = {nums[i],nums[j],nums[k]};
					vector<int> v(arr,arr+3);
					result.push_back(v);
                    j++;
                    k--;
				}

			}
		}
		return result;
	}
};

int main(int argc, const char * argv[]) {
	// insert code here...
	Solution sol;
	int a[] = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
	int len = sizeof(a) / sizeof(a[0]);
	vector<int> nums(a, a + len);
	vector<vector<int>> result = sol.threeSum(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
