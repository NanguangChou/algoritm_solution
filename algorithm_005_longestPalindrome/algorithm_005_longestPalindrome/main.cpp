//
//  main.cpp
//  algorithm_005_longestPalindrome
//
//  Created by zhounanguang on 15/12/17.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	unsigned long len = s.length();
    	if(!len){
    		return "";
    	}
    	int i;
    	int left,right;
    	int max = 0;
    	int start = 0;
    	string curlongest;
    	string result;
    	for(i=0; i<2*len; i++){
    		left = i/2;
    		right = i/2;
    		if(i%2==1){
    			right++;
    			
    		}
    		curlongest = this->palindrome(s,left,right);
    		if(max < curlongest.length()){
    			start = i;
    			result = curlongest;
    			max = curlongest.length();
    		}
    	}
        return result;
    }
    string palindrome(string s1, int left, int right){
    	while( left>=0 && right<=s1.length() && s1[left]==s1[right] ){
    		left --;
    		right ++;
    	}
    	left++;
    	right--;
    	return s1.substr(left,right-left+1);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "a";
    Solution sol;
    cout<<sol.longestPalindrome(s)<<endl;


    return 0;
}
