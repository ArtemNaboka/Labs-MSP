#include "stdafx.h"
#include "Stack.h"


Stack::Stack(int stackSize) : size(stackSize)
{
	stackArr = new int[size];
	top = -1;
}


Stack::~Stack()
{
	delete[] stackArr;
}


void Stack::push(int vertexId)
{
	stackArr[++top] = vertexId;
}


int Stack::pop()
{
	return stackArr[top--];
}


int Stack::peek()
{
	return stackArr[top];
}


bool Stack::isEmpty()
{
	return top == -1;
}