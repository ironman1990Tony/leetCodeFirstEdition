// Remove Linked List Elements.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)
			return head;
		
		ListNode* indexNode = head;

		ListNode* pNewListHead = NULL;
		
		/*删除链表前面和含有val的结点*/
		while (indexNode != NULL && indexNode->val == val)
			indexNode = indexNode->next;
		pNewListHead = indexNode;

		ListNode* Node = pNewListHead;
		while (indexNode != NULL)
		{	
			indexNode = indexNode->next;
			if (indexNode != NULL && indexNode->val != val)
			{
				Node->next = indexNode;
				Node = Node->next;
			}
			
		}

		if (Node != NULL)
			Node->next = NULL;

		return pNewListHead;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode p;
	p.next = NULL;
	p.val = 1;

	Solution s;
	s.removeElements(&p, 2);
	getchar();
	return 0;
}

