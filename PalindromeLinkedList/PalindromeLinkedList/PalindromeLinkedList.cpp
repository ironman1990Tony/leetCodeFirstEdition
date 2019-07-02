// PalindromeLinkedList.cpp : Defines the entry point for the console application.
//

/*判断单链表是否是回文链表，要求时间复杂度O(k),空间复杂度O(1)*/
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
		if (head->next == NULL)	//只有一个结点
			return true;

		/*找中间节点*/
		//ListNode* midNode = head;
		ListNode* fast_p = head->next;//当它走到末尾的时候，走得慢的指针slow_p正好是链表的中间
		ListNode* slow_p = head;
		ListNode* FirstPartEndNode = head;
		
		while (fast_p != NULL && fast_p->next != NULL)
		{
			fast_p = fast_p->next->next;

			FirstPartEndNode = slow_p;
			slow_p = slow_p->next;
		}

		ListNode* SecondPartStartNode = slow_p->next;
		
		if (fast_p != NULL)//偶数结点，前半部分的尾结点为中间结点
			FirstPartEndNode = slow_p;
		FirstPartEndNode->next = NULL;
		
		/*将后半部分翻转*/
		ListNode* pReverseHead = reverseNode(SecondPartStartNode);

		/*前半部分和后半部分逐个比较*/
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

