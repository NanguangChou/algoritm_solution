//
//  main.cpp
//  algorithm_016_threeSumClosest
//
//  Created by zhounanguang on 16/1/1.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int len = nums.size();
    	if(len<3){
    		return 0;
    	}
    	sort(nums.begin(),nums.end());
    	int i,j,k=0;
    	bool isfirst = true;
    	int result;
    	for(i=0;i<len-2;i++){
    		j = i+1;
    		k = len-1;
    		while(j<k){
    			if(j>i+1&&nums[j-1]==nums[j]){
    				j++;
    				continue;
    			}
    			if((k<len-1&&nums[k]==nums[k+1])){
    				k--;
    				continue;
    			}
    			int sum = nums[i]+nums[j]+nums[k];
    			if(isfirst){
    				result = sum;
    				isfirst = false;
    			}
    			else{
    				if(abs(sum-target)<abs(result-target)){
    					result = sum;
    				}
    			}
    			if(result == target){
    				return result;
    			}
    			if(sum<target){
    				j++;
    			}
    			else{
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
    int a[]={1,2,4,8,16,32,64,128};
    int length = sizeof(a)/sizeof(a[0]);
    vector<int> v(a,a+length);
    int target = 82;
    cout << sol.threeSumClosest(v,target);
    return 0;
}
