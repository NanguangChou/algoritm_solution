//
//  main.cpp
//  algorithm_010_IsMatch
//
//  Created by zhounanguang on 15/12/25.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return matchHelper(s, p, 0, 0);
    }
     
    bool matchHelper(string& s, string& p, int i, int j){
        if(p[j]=='\0'){
            return s[i]=='\0';
        }
         
        if( p[j + 1] != '*'){
            return ((s[i] == p[j]) || (p[j] == '.' && s[i]!='\0')) && matchHelper(s, p, i + 1, j + 1);
        }
         
        while((s[i] == p[j]) || (p[j] == '.' && s[i]!='\0')){
            if(matchHelper(s, p, i, j+2)) return true;
            i++;
        }
        return matchHelper(s, p, i, j+2);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    // int b = 123;
    // const int *  a = &b;
    // cout<<&a<<*a <<endl;
    // a += 1;
    // cout<<&a<<*a<<endl;
    
    Solution sol;
	cout<<sol.isMatch("aab","c*a*b");
    return 0;
}
