//
//  main.cpp
//  algorithm_021_mergeTwoLists
//
//  Created by zhounanguang on 16/1/5.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1==NULL){
    		return l2;
    	}
    	if(l2==NULL){
    		return l1;
    	}
	    ListNode *start, *cur;
	    if(l1->val<l2->val){
	    	start = cur = l1;
	    	l1 = l1->next;
	    }
	    else{
	    	start = cur = l2;
	    	l2 = l2->next;
	    }
        while(l1&&l2){
        	if(l1->val<l2->val){
        		cur->next = l1;
        		cur = l1;
        		l1 = l1->next;
        	}
        	else{
        		cur->next = l2;
        		cur = l2;
        		l2 = l2->next;
        	}
        }
        if(l1){
        	cur->next = l1;
        }
        else{
        	cur->next = l2;
        }
        return start;
    }
};
int main(int argc, const char * argv[]) {
	// int a[] = {-29,-29,-25,-20,-20,-16,-14,-13,-12,-2,4,6,14,19,21,27,29,29};
	// int b[] = {-30,-30,-30,-29,-29,-28,-27,-27,-26,-22,-21,-20,-18,-16,-16,-14,-14,-13,-12,-11,-9,-7,-6,-5,-5,-4,-3,-2,-2,-1,-1,2,3,6,8,16,17,18,20,20,23,24};
	int a[]={2};
	int b[]={1};
	int len1 = sizeof(a)/sizeof(a[0]);
	int len2 = sizeof(b)/sizeof(b[0]);
	ListNode* head1 = new ListNode;
	ListNode* head2 = new ListNode;
	head1->val = 2;
	head2->val = 1;
	ListNode* p = head1;
	for(int i=1;i<len1;i++){
		ListNode* newNode = new ListNode;
		newNode->val = a[i];
		newNode->next = NULL;
		p->next = newNode;
		p = p->next;
	}
	p = head2;
	for(int i=1;i<len2;i++){
		ListNode* newNode = new ListNode;
		newNode->val = b[i];
		newNode->next = NULL;
		p->next = newNode;
		p = p->next;
	}
	Solution sol;
	ListNode* result = sol.mergeTwoLists(head1,head2);
	while(result){
		cout<<result->val<<endl;
		if(!result->next){
			break;
		}
		result = result->next;
	}
    return 0;
}
