//
//  main.cpp
//  algorithm_009_isPalindrome
//
//  Created by zhounanguang on 15/12/21.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
    	if(x<0){
    		return false;
    	}
    	int len = 1;
    	while(x/len>=10){
    		len *= 10;
    	}
    	while(x){
    		int left = x/len;
    		int right = x%10;
    		if(left!=right){
    			return false;
    		}
    		x = (x%len)/10;
    		len /=100;
    	}
        return true;
    }
};
int main(int argc, const char * argv[]) {

	Solution sol;
	cout<<sol.isPalindrome(10000000001)<<endl;

    return 0;
}
