//
//  main.cpp
//  algorithm_029_divide
//
//  Created by zhounanguang on 16/1/16.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <math.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) {
			return MAX_INT;
		}
		int res = 0 ;
		if (divisor == 1) {
			return dividend;
		}
		if (dividend == MIN_INT)
		{
			if(divisor==-1){
				return MAX_INT;
			}
			res = 1;
			dividend += abs(divisor);
		}
		if (divisor == MIN_INT)
			return res;

		bool isNeg = (dividend ^ divisor) >> 31 == -1 ? true : false;
		int digit = 0 ;
		long long temp = abs(dividend);
		long long temp2 = abs(divisor);
		while (temp2 <= (temp >> 1)) {
			digit ++;
			temp2 <<= 1;
		}

		while (digit >= 0)
		{
			if (temp >= temp2)
			{
				temp -= temp2;
				res += 1 << digit;
			}
			temp2 >>= 1;
			digit--;
		}
		return isNeg ? -res : res;
	}
};
int main(int argc, const char * argv[]) {
	// insert code here...
	int divisor  = -1;
	int dividend = MIN_INT;
	Solution sol;

	int ret = sol.divide(dividend, divisor);
	cout << (dividend^divisor>>31) << endl;
	cout << (dividend <<= 4) << endl;
	return 0;
}
