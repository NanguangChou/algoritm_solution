//
//  main.cpp
//  algorithm_013_roman2int
//
//  Created by zhounanguang on 15/12/29.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[]     = {1000,900,500,400,100,  90, 50,  40,  10, 9,   5,  4,   1};
        int i,j=0;
        int result = 0;
        string temp1="";
        string temp2="";
        for(i=0;i<s.length();i++){
        	while(symbol[j][0]){
        		temp1 = "";
        		temp2 = "";
        		temp1 += s[i];
        		temp1 += s[i+1];
        		temp2 += s[i];
        		if((symbol[j]==temp1)){
        			result += value[j];
        			i++;
        			break;
        		}
        		else if(symbol[j]==temp2){
        			result += value[j];
        			break;
        		}
        		j++;
        	}
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    string str = "MMMIVIII";
    cout << sol.romanToInt(str)<<endl;;
    return 0;
}
