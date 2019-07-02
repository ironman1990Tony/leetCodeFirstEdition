// implement stack using queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
using namespace std;
class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		dataqueue1.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if (dataqueue1.empty())
			return;
		while (dataqueue1.size() > 1)
		{
			dataqueue2.push(dataqueue1.front());
			dataqueue1.pop();
		}
		dataqueue1.pop(); //µ¯Õ»
		while (!dataqueue2.empty())
		{
			dataqueue1.push(dataqueue2.front());
			dataqueue2.pop();
		}
	}

	// Get the top element.
	int top() {
		int ans = 0;
		while (dataqueue1.size() > 1)
		{
			dataqueue2.push(dataqueue1.front());
			dataqueue1.pop();
		}
		ans = dataqueue1.front();
		dataqueue2.push(dataqueue1.front());
		dataqueue1.pop();
		while (!dataqueue2.empty())
		{
			dataqueue1.push(dataqueue2.front());
			dataqueue2.pop();
		}
		return ans;
	}

	// Return whether the stack is empty.
	bool empty() {
		return dataqueue1.empty();
	}
private:
	queue<int> dataqueue1;
	queue<int> dataqueue2;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Stack s1;
	s1.push(1);
	s1.push(2);
	cout << s1.top() << endl;
	s1.pop();
	s1.pop();
	cout << s1.empty() << endl;
	return 0;
}

