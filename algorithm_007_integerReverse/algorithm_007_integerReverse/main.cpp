//
//  main.cpp
//  algorithm_007_integerReverse

//Reverse digits of an integer.
// Example1: x = 123, return 321
// Example2: x = -123, return -321

//  Created by zhounanguang on 15/12/21.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    	if(!x){
    		return 0;
    	}
    	int temp = x;
    	int result =0 ;
    	int times =10;
    	while(temp){
    		int flag = result;
    		result = result*times + temp%10;
    		temp /= 10;
    		if(result/10 !=flag){
    			return 0;
    		}
    	}
    	return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    cout<<sol.reverse(1000000005)<<endl;
    return 0;
}
