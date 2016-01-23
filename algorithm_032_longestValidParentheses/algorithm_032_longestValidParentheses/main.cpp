//
//  main.cpp
//  algorithm_032_longestValidParentheses
//
//  Created by zhounanguang on 16/1/22.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
private:
	stack<int> stk;

public:
	int longestValidParentheses(string s) {
		int s_len = s.size();
		if (s_len < 2)
			return 0;
		int maxlen=0;
		for(int i=0;i<s_len;i++){
			if(s[i]=='(')
				stk.push(i);
			else{
				if(!stk.empty()&&s[stk.top()]=='('){
					stk.pop();
                    int temp =stk.empty()?(i+1):(i-stk.top());
                    maxlen = temp>maxlen?temp :maxlen;
				}
				else
					stk.push(i);
			}
		}
		return maxlen;
	}
};
int main(int argc, const char * argv[]) {
	Solution sol;
	string str = ")()())()()(";
	int ret = sol.longestValidParentheses(str);
	cout << ret << endl;
	return 0;
}
