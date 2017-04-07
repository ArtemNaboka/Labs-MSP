#pragma once
class Stack
{
private:
	const int size;
	int* stackArr;
	int top;
public:
	Stack(int stackSize);
	~Stack();
	void push(int vertexId);
	int pop();
	int peek();
	bool isEmpty();
};

