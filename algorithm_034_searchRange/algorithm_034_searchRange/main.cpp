//
//  main.cpp
//  algorithm_034_searchRange
//
//  Created by zhounanguang on 16/1/23.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		int len = nums.size();
		int temp[] = { -1, -1};
		vector<int> none(temp, temp + 2);
		if (len < 1)
			return none;
		for (int i = 0; i < len; i++) {
			if (nums[i] == target && ret.size() == 0) {
				ret.push_back(i);
			}

			if (i + 1 < len && nums[i + 1] != target && nums[i] == target) {
				ret.push_back(i);
				return ret;
			}
		}
		if (ret.size() == 0)
			return none;
		if (ret.size() == 1)
		{
			ret.push_back(len - 1);
		}
		return ret;
	}
};
int main(int argc, const char * argv[]) {
	// insert code here...
	int a[] = {2,2,3};
	int length = sizeof(a) / sizeof(a[0]);
	vector<int> nums(a, a + length);
	Solution sol;
	vector<int> ret = sol.searchRange(nums, 1);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}
	return 0;
}
