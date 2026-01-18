// Delete Node in a Linked List

// https://leetcode.com/problems/delete-node-in-a-linked-list?envType=problem-list-v2&envId=v1lwence

/*
Constraints:
    The number of the nodes in the given list is in the range [2, 1000].
    -1000 <= Node.val <= 1000
    The value of each node in the list is unique.
    The node to be deleted is in the list and is not a tail node
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    ListNode* temp = node;
    ListNode* ahead = node -> next;

    while (ahead) {
        temp -> val = ahead -> val;
        if (ahead -> next)
            temp = ahead;
        ahead = ahead -> next;
    }
    ahead = temp -> next;
    delete ahead;
    temp -> next = nullptr;
}