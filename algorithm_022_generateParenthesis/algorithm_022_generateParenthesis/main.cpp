//
//  main.cpp
//  algorithm_022_generateParenthesis
//
//  Created by zhounanguang on 16/1/6.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> ret;
	void generateUtility(int n,string s,int leftnum, int rightnum){
		if(n==leftnum){
			ret.push_back(s.append(n-rightnum,')'));
			return;
		}
		generateUtility(n,s+"(",leftnum+1,rightnum);
		if(leftnum>rightnum)
			generateUtility(n,s+")",leftnum,rightnum+1);
	}
public:
    vector<string> generateParenthesis(int n) {
        int len = 0;
        if(n==0){
        	return {};
        }
        if(n==1){
        	return {"()"};
        }
        generateUtility(n,"",0,0);
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<string> ss = sol.generateParenthesis(5);
    for(int i=0;i<ss.size();i++){
    	cout<<ss[i]<<endl;
    }
    return 0;
}
