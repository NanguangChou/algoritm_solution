//
//  main.cpp
//  algorithm_008_myAtoi
//
// Implement atoi to convert a string to an integer.
// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
//  Created by zhounanguang on 15/12/21.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int len = str.length();
		int temp;
		int result = 0;
		int flag = 1;
		bool isfirst = true;
		for (int i = 0; i < len; i++) {
			if (str[i] == ' ' && isfirst) {
				continue;
			}
			if (isfirst && len > 1) {
				if (str[i] == '+')
				{
					isfirst = false;
					flag = 1;
					continue;
				}
				else if (str[i] == '-') {
					isfirst = false;
					flag = -1;
					continue;
				}
			}
			if (str[i] > '9' || str[i] < '0') {
				return result * flag;
			}
			isfirst = false;
			temp = result;
			result = result * 10 + (int)(str[i] - '0');
			if ((result) / 10 != temp) {
				if (flag == 1) {
					return INT_MAX;
				}
				else {
					return INT_MIN;
				}
			}
		}
		return result * flag;
	}
};
int main(int argc, const char * argv[]) {
	// insert code here...
	Solution sol;
	cout << sol.myAtoi("2147483649") << endl;
	return 0;
}
