//
//  main.cpp
//  algorithm_017_letterCombinations
//
//  Created by zhounanguang on 16/1/1.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//
// Given a digit string, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below.
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
private:
    map<char, vector<char> > dict;
    vector<string> ret;
public:
    void createDict()
    {
        dict.clear();
        dict['2'].push_back('a');
        dict['2'].push_back('b');
        dict['2'].push_back('c');
        dict['3'].push_back('d');
        dict['3'].push_back('e');
        dict['3'].push_back('f');
        dict['4'].push_back('g');
        dict['4'].push_back('h');
        dict['4'].push_back('i');
        dict['5'].push_back('j');
        dict['5'].push_back('k');
        dict['5'].push_back('l');
        dict['6'].push_back('m');
        dict['6'].push_back('n');
        dict['6'].push_back('o');
        dict['7'].push_back('p');
        dict['7'].push_back('q');
        dict['7'].push_back('r');
        dict['7'].push_back('s');
        dict['8'].push_back('t');
        dict['8'].push_back('u');
        dict['8'].push_back('v');
        dict['9'].push_back('w');
        dict['9'].push_back('x');
        dict['9'].push_back('y');
        dict['9'].push_back('z');
    }
    void dfs(int deep, int maxdeep, string &s, string ans){
    	if(deep == maxdeep){
    		ret.push_back(ans);
    		return;
    	}
    	for(int i=0;i<dict[s[deep]].size();i++){
    		dfs(deep+1,maxdeep,s,ans+dict[s[deep]][i]);
    	}
    }
    vector<string> letterCombinations(string digits) {
    	ret.clear();
    	if(digits==""){
    		return ret;
    	}
    	createDict();
    	dfs(0,digits.size(),digits,"");
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    string digits = "23";
    Solution sol;
    vector<string> vc = sol.letterCombinations(digits);
    for(int i=0;i<vc.size();i++){
    	cout<<vc[i]<<endl;
    }
    return 0;
}
