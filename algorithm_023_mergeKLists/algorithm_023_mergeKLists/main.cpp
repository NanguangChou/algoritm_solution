//
//  main.cpp
//  algorithm_023_mergeKLists
//
//  Created by zhounanguang on 16/1/7.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
};
class Solution {
private:
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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) {
            return NULL;
        }

       	if(lists.size()==1){
       		return lists[0];
       	}
       	int length = lists.size();
       	int mid = (length-1)/2;
       	vector<ListNode*> left;
       	vector<ListNode*> right;

       	for(int i=0;i<mid+1;i++){
       		left.push_back(lists[i]);
       	}
       	for(int j=mid+1;j<length;j++){
       		right.push_back(lists[j]);
       	}
       	ListNode* l1 = mergeKLists(left);
       	ListNode* l2 = mergeKLists(right);

        return mergeTwoLists(l1,l2);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<ListNode*> lists;
    for(int i=0;i<5;i++){
    	ListNode* phead = new ListNode;
    	phead->val = -10;
    	phead->next = NULL;
    	ListNode* a = phead;
    	for(int j=1;j<10;j++){
    		ListNode* newDom = new ListNode;
    		newDom->val = (i+1)*(j)-5;
    		newDom->next= NULL;
    		a->next= newDom;
            a = a->next;
    	}
        
    	lists.push_back(phead);
    }

    // for(int i=0;i<lists.size();i++){
    // 	ListNode* p = lists[i];
    // 	while(p){
    // 		cout<<p->val<<"  ";
    // 		if(!p->next)
    // 			break;
    // 		p = p->next;
    // 	}
    // 	cout<<endl;
    // }
    Solution sol;
    ListNode * ret = sol.mergeKLists(lists);
    while(ret){
    	cout<<ret->val<<endl;
    	if(!ret->next)
    		break;
    	ret = ret->next;
    }
    return 0;
}
