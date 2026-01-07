// Middle of Linked List

// https://leetcode.com/problems/middle-of-the-linked-list?envType=problem-list-v2&envId=v1lwence

/*
Constraints:
    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100
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


ListNode* middleNode(ListNode* head) {
    if (!head || !head -> next) return head;

    ListNode* slow = head;
    ListNode* fast = head;
    
    // while (fast && fast -> next) {
    //     slow = slow -> next;
    //     fast = fast -> next -> next;
    // }


    for (; fast && fast -> next; slow = slow -> next, fast = fast -> next -> next);
    return slow;
}