//
//  main.cpp
//  algorithm_012_int2Roman
//
//  Created by zhounanguang on 15/12/26.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string result="";
        string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[]     = {1000,900,500,400,100,  90, 50,  40,  10, 9,   5,  4,   1};
        for(int i=0;num!=0;i++){
        	while(num>=value[i]){
        		num -= value[i];
        		result += symbol[i];
        	}
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution sol;
    string a = "1";
    // cout<< pow(1,5)<<endl;
   	cout<<sol.intToRoman(3999)<<endl;
    return 0;
}
