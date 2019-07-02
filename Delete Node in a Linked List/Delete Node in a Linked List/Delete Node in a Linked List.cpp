// Delete Node in a Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Supposed the linked list is 1 -> 2 -> 3 -> 4 
and you are given the third node with value 3, the linked list
should become 1 -> 2 -> 4 after calling your function.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node == NULL || node->next == NULL)
			return;
		node->val = node->next->val;
		node->next = node->next->next;
		
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

