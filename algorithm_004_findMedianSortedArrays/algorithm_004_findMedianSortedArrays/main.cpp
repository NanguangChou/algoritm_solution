//
//  main.cpp
//  algorithm_004_findMedianSortedArrays
//
//  Created by zhounanguang on 15/12/16.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		float size_n1 = nums1.size();
		float size_n2 = nums2.size();
		float median = (size_n1 + size_n2 + 1) / 2;
		bool isOdd = true;;
		if (median - (int)median == 0) {
			isOdd = false;
		}
		median = int(median);
		int i = 0, j = 0, k = 0;
		float temp1=0, temp2=0;
		double result;
		while (k <= median) {
			temp1 = temp2;

			if (size_n1&&((!size_n2)||(j>=size_n2)||((nums1[i] <= nums2[j]) && i<size_n1))) {
				temp2 = nums1[i];
				i++;
			}
			else {
				temp2 = nums2[j];
				j++;
			}
			k++;
		}
		if(isOdd){
			result = (temp1+temp2)/2;
		}
		else{
			result = temp1;
		}
		return result;
	}
};
int main(int argc, const char * argv[]) {
	// insert code here...
	int* a = new int[3];
	a[0] = 10001;
	a[1] = 20000;
	a[2] = 50000;
	int* b = new int[3];
	b[0] = 1;
	b[1] = 20000;
	b[2] = 50000;
	vector<int> n1(a, a + 0);
	vector<int> n2(b, b + 1);
	Solution sol;
	cout << sol.findMedianSortedArrays(n1, n2) << endl;

	return 0;
}
