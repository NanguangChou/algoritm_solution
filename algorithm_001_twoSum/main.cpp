//
//  main.cpp
//  test
//
//  Created by zhounanguang on 15/12/8.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int front=0,back=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    front = i;
                    back = j;
                }
            }
        }
        int temp;
        if(front>back){
            temp = front;
            front = back;
            back = temp;
        }
        vector<int> res;
        res.push_back(front+1);
        res.push_back(back+1);
        return res;
        
    }
    
};

int main(){
    Solution sol;
    int a[4] = {2,7,11,15};
    vector<int> vec (a,a+4);
    vector<int> res = sol.twoSum(vec,9);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}