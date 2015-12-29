//
//  main.cpp
//  algorithm_014_longestCommonPrefix
//
//  Created by zhounanguang on 15/12/29.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
	string longestCommonPrefix(vector<string>& strs){
		int len = strs.size();
		if(!len){
			return "";
		}
		int minstrlen = strs[0].size();
		int i,j;
		int temp = strs[0].size();
		string result = strs[0];
		for(i=0;i<len;i++){
			minstrlen = minstrlen < strs[i].size() ? minstrlen : strs[i].size();
		}
		for(i=0;i<len-1;i++){
			int len1 =  strs[i].size();
			int len2 = strs[i+1].size();
			int n = min(len1,len2);
			n     = min(n,temp);
			if(n==0){
				return "";
			}
			for(j=0;j<n;j++){
				if(strs[i][j]!=strs[i+1][j]){
					break;
				}
			}
			result = result.substr(0,j);
		}
		return result;
	}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<string> strs;
    strs.push_back("aaa");
    strs.push_back("aaa");
    strs.push_back("aaa");
    strs.push_back("aaa");
    cout<<sol.longestCommonPrefix(strs)<<endl;
    return 0;
}
