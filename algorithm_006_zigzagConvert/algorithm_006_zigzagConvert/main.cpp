//
//  main.cpp
//  algorithm_006_zigzagConvert
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


//  Created by zhounanguang on 15/12/17.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if(numRows == 1){
            return s;
        }
        int temp = numRows*2 -2;
        int len = s.length();
        string* arr = new string[numRows];
        for(int i=0;i<len;i++){
            int index = i % temp;
            if(index>numRows-1){
                index = numRows - 2 - index%numRows;
            }

            arr[index] += s[i];
        }
        for(int j=0;j<numRows;j++){
            result += arr[j];
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s = "ABCD";
    Solution sol;
    cout<<sol.convert(s,2);
    return 0;
}