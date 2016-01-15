//
//  main.cpp
//  algorithm_028_strStr
//
//  Created by zhounanguang on 16/1/15.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle.length()==0)
    		return 0;
    	if(haystack.length()==0)
    		return -1;
    	for(int i=0;;i++){
    		for(int j=0;j<needle.length()+1;j++){
    			if(j==needle.length())
    				return i;
    			if(i+j==haystack.length())
    				return -1;
    			if(needle[j]!=haystack[i+j])
    				break;
    		}
    	}
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    string haystack = "misisipi";
    string needle = "a";
    Solution sol;
    int ret = sol.strStr(haystack,needle);
    cout<<ret<<endl;
    return 0;
}
