//
//  main.cpp
//  algorithm_026_removeDuplicates
//
//  Created by zhounanguang on 16/1/13.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size();
        }
        vector<int>::iterator it=nums.begin()+1;
        while(it!=nums.end()){
        	if(*it == *(it-1)){
        		nums.erase(it);
        	}
        	else{
        		it++;
        	}
        }
        return nums.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {1,1,1,2,2,3,4,5,6,7};
    int length = sizeof(a)/sizeof(a[0]);
    vector<int> b(a,a+length);
    Solution sol;
    int ret = sol.removeDuplicates(b);
    cout<<ret<<endl;
    
    return 0;
}
