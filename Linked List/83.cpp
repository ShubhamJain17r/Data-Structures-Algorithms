// Remove Duplicates from Linked List

// https://leetcode.com/problems/remove-duplicates-from-sorted-list?envType=problem-list-v2&envId=v1lwence

/*
Constraints:
    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order
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

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head -> next) return head;
    int curr = -101;
    ListNode* temp = head;
    ListNode* dummy = new ListNode();
    ListNode* temp2 = dummy;
    while (temp) {
        if (temp -> val != curr) {
            curr = temp -> val;
            temp2 -> next = temp;
            temp2 = temp;
        }
        temp = temp -> next;
    }
    temp2 -> next = nullptr;
    return dummy -> next;
}