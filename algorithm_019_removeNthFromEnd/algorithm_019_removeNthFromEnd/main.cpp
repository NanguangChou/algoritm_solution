//
//  main.cpp
//  algorithm_019_removeNthFromEnd
//
//  Created by zhounanguang on 16/1/3.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* next;
		ListNode* prev = NULL;
		next = head;
		int len = 0;
		while (next) {
			len++;
			if (!next->next) {
				break;
			}
			next = next->next;
		}
		if (n > len) {
			return head;
		}
		else if (n == len) {
			head = head->next;
			return head;
		}
		int pos = len - n;
		next = head;
		len = 0;
		while (next) {
			if (len == pos) {
				prev->next = next->next;
				break;
			}
			else {
				if (!next->next) {
					break;
				}
				len++;
				prev = next;
				next = next->next;
			}
		}
		return head;
	}
};


int main(int argc, const char * argv[]) {
	// insert code here...
	Solution sol;
	ListNode* pHead = NULL;
	pHead = new ListNode;
	pHead->val = 0;
	ListNode*p = pHead;
	// for(int i=0;i<10;i++){
	// 	ListNode* newNode = new ListNode;
	// 	newNode->val = i+1;
	// 	newNode->next = NULL;
	// 	p->next = newNode;
	//     p = newNode;
	// }
	ListNode* result = sol.removeNthFromEnd(pHead, 1);
	while (result) {
        cout << result->val << endl;
        if (!result->next) {
            break;
        }
		result = result->next;
	}
	return 0;
}
