//
//  main.cpp
//  algorithm_003_lengthOfLongestSubstring
//
//  Created by zhounanguang on 15/12/13.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int pos = 0;
		int start = 0;
		int cur_length = 0;
		char cur_char  = s[0];
		string cur_string = "";
        int max_length=0;
        int temp =0;
		if (!cur_char) {
			return 0;
		}
		while (cur_char) {

			if (cur_string.find(cur_char, 0) == string::npos) {
				cur_string.push_back(cur_char);
				cur_length++;
				pos++;
			}
			else {
                temp = cur_string.find(cur_char, 0) + 1;
				pos = start + temp;
                start = pos;
				max_length = max_length > cur_length? max_length:cur_length;
				cur_length = 0;
				cur_string = "";
			}
			cur_char = s[pos];
			if (!cur_char) {
				max_length = max_length > cur_length? max_length:cur_length;
			}
		}
		return max_length;
	}
};

int main(int argc, const char * argv[]) {
	// insert code here...

	Solution sol;
	string str = "cdd";
	cout << sol.lengthOfLongestSubstring(str) << endl;
	return 0;
}
