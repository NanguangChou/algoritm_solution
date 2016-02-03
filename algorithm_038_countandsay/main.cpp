//
//  main.cpp
//  algorithm_038_countandsay
//
//  Created by zhounanguang on 16/2/3.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
	string handler(const string &say){
		int size = say.size();
		int count = 0;
		stringstream ss;
		char last = say[0];
		for(int i=0;i<=size;i++){
			if(say[i]==last){
				count++;
			}
			else{
				ss<<count<<last;
				count=1;
				last = say[i];
			}
		}
		return ss.str();
	}
    string countAndSay(int n) {
    	if(n<=0)
    		return "";
        string ret = "1";
        for(int i=1;i<n;i++){
        	ret = handler(ret);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
	// insert code here...
	Solution sol;
	string ret = sol.countAndSay(10);
	cout<<ret<<endl;
	getchar();
	return 0;
}
