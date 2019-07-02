// Implement Queue using Stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;
class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		stack1.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (stack1.empty())
			return;
		/*���stack1ջ�е����ݴ���1�������൯��stack2*/
		while (stack1.size() != 1)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		/*��ջ*/
		stack1.pop();
		/*��stack2�е�������ѹ��stack1��*/
		while (stack2.empty() == 0)
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		int elment;
		/*���stack1ջ�е����ݴ���1�������൯��stack2*/
		while (stack1.size() != 1)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		elment = stack1.top();

		/*��stack2�е�������ѹ��stack1��*/
		while (stack2.empty() == 0)
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return elment;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return stack1.empty() && stack2.empty();
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

