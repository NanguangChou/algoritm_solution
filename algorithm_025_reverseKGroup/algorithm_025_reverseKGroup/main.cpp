//
//  main.cpp
//  algorithm_025_reverseKGroup
//
//  Created by zhounanguang on 16/1/12.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
	stack<ListNode*> lists;
	bool isEnoughNode(ListNode* p, int k) {
		while (lists.empty() == false)
			lists.pop();
		for (int i = 0; i < k; i++) {
			if (!p) {
				return false;
			}
			lists.push(p);
			p = p->next;
		}
		return true;
	}

public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if(!head || k==1){
			return head;
		}
		ListNode* phead = new ListNode(0);

		ListNode* p = phead;
		ListNode* current = head;
		while (isEnoughNode(current, k)) {
			for (int i = 0; i < k; i++) {
				ListNode* newNode = new ListNode(0);
				ListNode* temp = lists.top();
				lists.pop();
				newNode->val = temp->val;
				temp = lists.empty() ? NULL : lists.top();
				newNode -> next = temp;
				p->next = newNode;
				p = p->next;
				current = current->next;
			}
		}
		p->next = current;

		return phead->next;
	}
};
int main(int argc, const char * argv[]) {

	ListNode* head = new ListNode(0);
	head->val = 0;
	ListNode* p    = head;
	for (int i = 0; i < 10; i++) {
		ListNode* newNode = new ListNode(0);
		newNode->val = i + 1;
		newNode->next = NULL;
		p->next = newNode;
		p = newNode;
	}
	Solution sol;

	p = sol.reverseKGroup(head, 3);
	while (p) {
		cout << p->val << endl;
		if (!p->next) {
			break;
		}
		p = p->next;
	}
	return 0;
}
