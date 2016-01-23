//
//  main.cpp
//  algorithm_033_search
//
//  Created by zhounanguang on 16/1/23.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int len = nums.size();
    	int ret = -1;
    	if(len<1)
    		return ret;
    	for(int i=0;i<len;i++){
    		if(nums[i]==target)
    			return i;
    	}
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    int a[] = {1,2,3,4,5,6,7,-1,-2};
    int length = sizeof(a)/sizeof(a[0]);
    int target = -1;
    vector<int> nums(a,a+length);
    cout<<sol.search(nums,target)<<endl;
    return 0;
}
