#include "stdafx.h"
#include "Queue.h"


Queue::Queue(int queueSize) : size(queueSize)
{
	queArray = new int[size];
	front = 0;
	rear = -1;
}


Queue::~Queue()
{
	delete[] queArray;
}

void Queue::insert(int vertexId)
{
	if (rear == size - 1)
		rear = -1;
	queArray[++rear] = vertexId;
}

int Queue::remove()
{
	int temp = queArray[front++];
	if (front == size)
		front = 0;
	return temp;
}

bool Queue::isEmpty()
{
	return rear + 1 == front || front + size - 1 == rear;
}
