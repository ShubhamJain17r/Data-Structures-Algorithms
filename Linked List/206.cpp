// Reverse Linked List

// https://leetcode.com/problems/reverse-linked-list?envType=problem-list-v2&envId=v1lwence

/*
Constraints:
    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;  // edge cases

    ListNode* prev = head;                  // previous node
    ListNode* curr = prev -> next;          // curr's next points to prev in reversed
    ListNode* ahead = curr -> next;         // where current will move after reversal
    head -> next = nullptr;             // move its next to null as it will be the last node of Linked List
    while (curr) {
        curr->next = prev;
        prev = curr;
        curr = ahead;
        if (ahead)
            ahead = ahead->next;
    }
    return prev;
}

int main() {
    vector<int> ll = {1,2,3,4,5,6,7,8,9,10,11,1,2,1,3,1,4,1,5};

    ListNode* dummy = new ListNode();
    ListNode* head = dummy;

    for (int i = 0; i < ll.size(); ++i) {
        dummy -> next = new ListNode(ll[i]);
        dummy = dummy -> next;
    }

    for (ListNode* temp = head->next; temp; temp = temp->next)
        cout<<temp->val<<" -> ";
    cout<<"NULL";

    cout<<"\n\nReversed\n\n";

    ListNode* reversed = reverseList(head->next);
    for (ListNode* temp = reversed; temp; temp = temp->next)
        cout<<temp->val<<" -> ";
    cout<<"NULL";
}
 