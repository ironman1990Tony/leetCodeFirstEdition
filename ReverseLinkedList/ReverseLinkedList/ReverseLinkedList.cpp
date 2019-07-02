// ReverseLinkedList.cpp : Defines the entry point for the console application.
//
//Reverse Linked List, implement in recursive and iterative ways;


#include "stdafx.h"


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/* //����reverse()�ĸ�ʽ��reverse(NULL,head);
	ListNode* reverse(ListNode* prevNode, ListNode* currentNode)
	{
		if (currentNode->next == NULL)	//������β��
		{	
			currentNode->next = prevNode;	//��ǰ����nextָ������ǰһ�����
			prevNode->next = NULL;			//ǰһ�������β��
			return currentNode;

		}
		
		ListNode* p = reverse(currentNode, currentNode->next);
		if (prevNode != NULL)	
			prevNode->next = NULL;
		currentNode->next = prevNode;

		return p;
	}
	*/

	ListNode* reverseList(ListNode* head) {
		/*Solution 1: recuresive*/
		/*
		if (head == NULL || head->next == NULL)
			return head;
		return reverse(NULL, head);
		*/

		/*Solution 2: iterative*/
		if (head == NULL)
			return head;
		
		ListNode* prevNode = NULL;
		ListNode* indexNode = head;
		ListNode* nextNode = NULL;
		ListNode* pReverseHead = NULL;

		while (indexNode != NULL)
		{
			nextNode = indexNode->next;
			indexNode->next = prevNode;
			pReverseHead = indexNode;
			prevNode = indexNode;
			indexNode = nextNode;
		}

		return pReverseHead;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

