//
//  main.cpp
//  algorithm_035_searchInsert
//
//  Created by zhounanguang on 16/1/24.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int length = nums.size();
    	if(length<1||target<=nums[0])
    		return 0;
    	for(int i=0;i<length-1;i++){
    		if(target>nums[i]&&target<=nums[i+1])
    			return i+1;
    	}
        return length;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {1,1,2};
    int length = sizeof(a)/sizeof(a[0]);
   	vector<int> nums(a,a+length);
   	Solution sol;
   	int ret = sol.searchInsert(nums,2);
   	cout<<ret<<endl;
    return 0;
}
