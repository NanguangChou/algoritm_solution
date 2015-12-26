//
//  main.cpp
//  algorithm_011_maxArea
//
//  Created by zhounanguang on 15/12/26.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size<2){
        	return 0;
        }
        int i=0,j=size-1;
        int temp=0;
        int result = (j-i)*min(height[i],height[j]);
        for(i=0;i<j;){
        	if(height[i]<height[j]){
        		i++;
        	}
        	else{
        		j--;
        	}
        	temp = (j-i)*(min(height[i],height[j]));
        	result = result > temp ? result : temp;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[7] = {2,3,10,5,7,8,9};
    vector<int> vec(a,a+7);
    Solution sol;
    cout<<sol.maxArea(vec)<<endl;
    return 0;
}
