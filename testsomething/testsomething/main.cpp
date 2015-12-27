//
//  main.cpp
//  testsomething
//
//  Created by zhounanguang on 15/12/9.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <string>
#include <iostream>
#include <pcre++.h>
using namespace std;
using namespace pcrepp;
int main() {
	string src("111 <title>Hello World</title> 222");
	string pattern("<title>(.*)</title>");
	cout << "String : " << src << endl;
	cout << "Pattern : " << pattern << endl;
	Pcre reg(pattern, PCRE_DOTALL);
	if (reg.search(src) == true) { //
		cout << "\nOK, has matched ...\n\n";
		for (int pos = 0; pos < reg.matches(); pos++) {
			cout << pos << ": " << reg[pos] << endl; 　
		}
	} else {
		cout << "Sorry, no match ...\n";
		return 1;	　　
	}
	return 0;
}