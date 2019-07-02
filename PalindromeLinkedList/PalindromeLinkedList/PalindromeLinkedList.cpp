// PalindromeLinkedList.cpp : Defines the entry point for the console application.
//

/*�жϵ������Ƿ��ǻ�������Ҫ��ʱ�临�Ӷ�O(k),�ռ临�Ӷ�O(1)*/
#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL)
			return true;
		if (head->next == NULL)	//ֻ��һ�����
			return true;

		/*���м�ڵ�*/
		//ListNode* midNode = head;
		ListNode* fast_p = head->next;//�����ߵ�ĩβ��ʱ���ߵ�����ָ��slow_p������������м�
		ListNode* slow_p = head;
		ListNode* FirstPartEndNode = head;
		
		while (fast_p != NULL && fast_p->next != NULL)
		{
			fast_p = fast_p->next->next;

			FirstPartEndNode = slow_p;
			slow_p = slow_p->next;
		}

		ListNode* SecondPartStartNode = slow_p->next;
		
		if (fast_p != NULL)//ż����㣬ǰ�벿�ֵ�β���Ϊ�м���
			FirstPartEndNode = slow_p;
		FirstPartEndNode->next = NULL;
		
		/*����벿�ַ�ת*/
		ListNode* pReverseHead = reverseNode(SecondPartStartNode);

		/*ǰ�벿�ֺͺ�벿������Ƚ�*/
		ListNode* pFirstHead = head;
		while (pReverseHead != NULL && pFirstHead != NULL)
		{
			if (pReverseHead->val != pFirstHead->val)
				return false;
			pFirstHead = pFirstHead->next;
			pReverseHead = pReverseHead->next;
		}

		return true;
	}
	ListNode* reverseNode(ListNode* head)
	{
		if (head == NULL)
			return head;

		ListNode* prev = NULL;
		ListNode* index = head;
		ListNode* nextNode;

		while (index)
		{
			nextNode = index->next;
			index->next = prev;
			prev = index;
			index = nextNode;
		}
		return prev;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	struct ListNode Third;
	Third.next = NULL;
	Third.val = 0;

	struct ListNode Second;
	Second.next = &Third;
	Second.val = 0;

	struct ListNode First;
	First.next = &Third;
	First.val = 1;

	Solution s;
	cout << s.isPalindrome(&First) << endl;
	getchar();
	return 0;
}

