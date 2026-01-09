// Linked List Cycle

// https://leetcode.com/problems/linked-list-cycle?envType=problem-list-v2&envId=v1lwence

/*
Constraints:
    The number of the nodes in the list is in the range [0, 10^4].
    -10^5 <= Node.val <= 10^5
    pos is -1 or a valid index in the linked-list.

Important:
    Return true if there is a cycle in the linked list. Otherwise, return false
    pos is not passed as a parameter
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if (slow == fast)           // contains cycle
            return true;
    }
    return false;                   // fast ptr can reach the nullptr, so it is not cyclic
}