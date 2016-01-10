//
//  main.cpp
//  algorithm_024_swapPairs
//
//  Created by zhounanguang on 16/1/9.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
};

class Solution {
private:

public:
	ListNode* swapPairs(ListNode* head) {
		if (!head||!head->next) {
			return head;
		}
		ListNode* pointer = head->next;
		ListNode* prev    = head;
		ListNode* next;
		head = pointer;
		ListNode* temp = pointer->next;
		pointer->next = prev;
		prev->next = temp;
		prev = prev;

		pointer = prev->next;
		if(!pointer)
			return head;
		next = pointer->next;
		while(next){
			prev->next = next;
			temp = next->next;
			next->next = pointer;
			pointer->next = temp;
			prev = pointer;

			if(!prev->next)
				break;
			pointer = prev->next;
			next = pointer->next;
		}

		return head;
	}
};

int main(int argc, const char * argv[]) {
	ListNode* head = new ListNode;
	head->val = 0;
	ListNode* p = head;

	for (int i = 0; i < 10; i++) {
		ListNode* newDom = new ListNode;
		newDom->val = i + 1;
		newDom->next = NULL;
		p -> next = newDom;
		p =  p->next;

	}
	Solution sol;
	p = sol.swapPairs(head);
	while (p) {
		cout << p->val << endl;
		if (!p->next)
			break;
		p = p->next;
	}

}