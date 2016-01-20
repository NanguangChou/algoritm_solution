//
//  main.cpp
//  algorithm_031_nextPermutation
//
//  Created by zhounanguang on 16/1/20.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if(length<1)
        	return;
        for(int i=length-1;i>0;i--){
        	if(nums[i]>nums[i-1]){
        		for(int j = length-1;j>i-1;j--){
        			if(nums[j]>nums[i-1]){
        				int temp = nums[j];
        				nums[j] = nums[i-1];
        				nums[i-1] = temp;
        				break;
        			}
        		}
        		sort(nums.begin()+i,nums.end());
        		break;
        	}
        	if(i==1)
        		sort(nums.begin(),nums.end());
        }
    }
};

int main(int argc, const char * argv[]) {
	int a[]={3,2,1};
	int length = sizeof(a)/sizeof(a[0]);

    vector<int> nums(a,a+length);
   	Solution sol;
   	sol.nextPermutation(nums);
   	for(int i=0;i<nums.size();i++){
   		cout<<nums[i]<<endl;
   	}
    return 0;
}
