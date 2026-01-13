// Remove Linked List Elements

// https://leetcode.com/problems/remove-linked-list-elements?envType=problem-list-v2&envId=v1lwence

/*
Constraints:
    The number of nodes in the list is in the range [0, 10^4].
    1 <= Node.val <= 50
    0 <= val <= 50
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

ListNode* removeElements(ListNode* head, int val) {
    if (!head) return nullptr;

    ListNode* newHead = new ListNode();
    ListNode* prev = newHead;

    for (ListNode* temp = head; temp; temp = temp -> next) {
        if (temp -> val != val) {
            prev -> next = temp;
            prev = temp;
        }
    }
    prev -> next = nullptr;
    return newHead -> next;
}