//
//  main.cpp
//  algorithm_020_isValid
//
//  Created by zhounanguang on 16/1/4.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;
class Solution {
private:
	stack<char> st;
	map<char,char> dict;
public:
    bool isValid(string s) {
    	createDict();
    	int len = s.length();
    	for(int i=0;i<len;i++){
    		if(s[i]=='{'||s[i]=='('||s[i]=='[')
    			st.push(s[i]);
    		else if(!st.size()||st.top()!=dict[s[i]]){
    			return false;
    		}
    		else{
            	st.pop();
    		}
    	}
    	if(st.size())
    		return false;
        return true;
    }
    void createDict(){
    	dict.clear();
    	dict[']']='[';
    	dict['}']='{';
    	dict[')']='(';
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    string s = "}";
    cout << sol.isValid(s)<<endl;
    return 0;
}
