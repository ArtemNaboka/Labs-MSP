#pragma once
class Queue
{
private:
	const int size;
	int* queArray;
	int front;
	int rear;
public:
	Queue(int queueSize);
	~Queue();
	void insert(int vertexId);
	int remove();
	bool isEmpty();
};

