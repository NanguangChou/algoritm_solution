//
//  main.cpp
//  algorithm_018_4sum
//
//  Created by zhounanguang on 16/1/2.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class Solution {
private:
	vector<vector<int>> ret;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	ret.clear();
    	int len = nums.size();
    	if(len<4){
    		return ret;
    	}
    	sort(nums.begin(),nums.end());
    	int i,j,k,l;
    	for(i=0;i<len-2;i++){
    		if(i>0&&nums[i-1]==nums[i]){
    			continue;
    		}
    		for(j=i+1;j<len-2;j++){
    			if(j>i+1&&nums[j]==nums[j-1]){
    				continue;
    			}
    			k=j+1;
    			l=len-1;
    			while(k<l){
    				if(k>j+1&&nums[k]==nums[k-1]){
    					k++;
    					continue;
    				}
    				if(l<len-1&&nums[l]==nums[l+1]){
    					l--;
    					continue;
    				}
    				int sum = nums[i]+nums[j]+nums[k]+nums[l];
    				if(sum==target){
    					int temp[] = {nums[i],nums[j],nums[k],nums[l]};
    					vector<int> v(temp,temp+4);
    					ret.push_back(v);
    					k++;
    					l--;
    				}
    				else if(sum<target){
    					k++;
    				}
    				else{
    					l--;
    				}
    			}
    		}
    	}
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {-1,0,1,2,-1,-4};
    int len = sizeof(a)/sizeof(a[0]);
    int target = -1;
    vector<int> nums(a,a+len);
    Solution sol;
    vector<vector<int>> vc = sol.fourSum(nums,target);
    for(int i=0;i<vc.size();i++){
    	for(int j =0;j<vc[i].size();j++){
    		cout<<vc[i][j]<<"  ";
    	}
    	cout<<endl;
    }
    return 0;
}
