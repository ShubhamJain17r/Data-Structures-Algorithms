// Merge Two Sorted Lists

// https://leetcode.com/problems/merge-two-sorted-lists?envType=problem-list-v2&envId=v1lwence

/*
Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode* dummy_temp = dummy;

    ListNode* temp1 = list1;
    ListNode* temp2 = list2;

    while (temp1 && temp2) {
        if (temp1 -> val < temp2 -> val) {
            dummy_temp -> next = temp1;
            temp1 = temp1 -> next;
        }
        else {
            dummy_temp -> next = temp2;
            temp2 = temp2 -> next;
        }
        dummy_temp = dummy_temp -> next;
    }
    if (temp1) {
        dummy_temp -> next = temp1;
    }
    else {
        dummy_temp -> next = temp2;
    }
    return dummy -> next;
}