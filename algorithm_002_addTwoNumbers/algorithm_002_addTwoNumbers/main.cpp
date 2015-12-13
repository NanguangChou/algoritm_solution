//
//  main.cpp
//  algorithm_002_addTwoNumbers
//
//  Created by zhounanguang on 15/12/9.
//  Copyright © 2015年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        
        int  n1,n2,n3,jw=0;
        while(a||b||jw){
            n1 = a? a->val : 0;
            n2 = b? b->val : 0;
            n3 = n1 + n2 + jw;
            jw = 0;
            if(n3 >=10){
                jw = 1;
            }
            
            head->val  = n3%10;
            head->next = new ListNode(0);
            a = ((a==0||a->next ==0) ?0:a->next);
            b = ((b==0||b->next ==0) ?0:b->next);
            if(a||b||jw){
                head = head->next;
            }
        }
        head -> next = 0;
        return result;
    }
    
};

int main(int argc, const char * argv[]) {
    
    ListNode* a = new ListNode(9);
    a->next = 0;
    //        a->next->next = new ListNode(3);
    ListNode* b = new ListNode(1);
    b->next = new ListNode(9);
    b->next->next = new ListNode(9);
    b->next->next->next = new ListNode(9);
    b->next->next->next->next = 0;
    Solution sol;
    ListNode* result = sol.addTwoNumbers(a,b);
    while(result){
        cout<<result->val<<endl;
        result= result->next;
    }
    return 0;
}
