//
//  main.cpp
//  algorithm_027_removeElement
//
//  Created by zhounanguang on 16/1/14.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    
public:
    int removeElement(vector<int>& nums, int val) {
    	// sort(nums.begin(),nums.end());
    	int length = nums.size();
    	if(length<1)
    		return length;
    	int start = 0;
    	for(int i=0;i<length;i++){
    		if(nums[i]!=val)
    			nums[start++] = nums[i];
    	}

        return start;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    int a[] = {4,5};
    int length = sizeof(a)/sizeof(a[0]);
    vector<int> b(a,a+length);
    int ret = sol.removeElement(b,4);

    cout << ret<<endl;
    return 0;
}
