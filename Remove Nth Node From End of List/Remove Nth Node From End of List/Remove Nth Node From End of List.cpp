// Remove Nth Node From End of List.cpp : Defines the entry point for the console application.
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL)
			return NULL;
		
		ListNode* pPrev = NULL;
		ListNode* SlowIndex = head;
		ListNode* FastIndex = head;

		/*FastIndex����n-1��*/
		for (int i = 0; i < n - 1; ++i)
			FastIndex = FastIndex->next;
		
		/*��FastIndex��������β��ʱ��SlowIndex���ﵹ����n��λ��*/
		while (FastIndex->next != NULL)
		{
			pPrev = SlowIndex;
			FastIndex = FastIndex->next;
			SlowIndex = SlowIndex->next;
		}

		
		if (pPrev == NULL)/*Ҫɾ���ľ���ͷ���*/
			head = SlowIndex->next; 
		else
			pPrev->next = SlowIndex->next;


		//delete SlowIndex;

		return head;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode p2;
	p2.next = NULL;
	p2.val = 2;
	ListNode p;
	p.val = 1;
	p.next = &p2;

	Solution s;
	s.removeNthFromEnd(&p2,1);
	return 0;
}

