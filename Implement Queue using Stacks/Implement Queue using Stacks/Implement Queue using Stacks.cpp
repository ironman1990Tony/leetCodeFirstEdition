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
		/*如果stack1栈中的数据大于1，则将其余弹到stack2*/
		while (stack1.size() != 1)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		/*弹栈*/
		stack1.pop();
		/*将stack2中的数据再压入stack1中*/
		while (stack2.empty() == 0)
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		int elment;
		/*如果stack1栈中的数据大于1，则将其余弹到stack2*/
		while (stack1.size() != 1)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		elment = stack1.top();

		/*将stack2中的数据再压入stack1中*/
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

