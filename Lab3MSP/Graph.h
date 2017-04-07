#pragma once
#include "Vertex.h"
#include "Stack.h"
#include "Queue.h"

class Graph
{
private:
	const int vertexAmount;
	Vertex* vertices;
	int nVerts;
	int** adjMatrix;
	void displayVertex(int vertexId) const;
	int getAdjUnvisitedVertex(int vertexId);
	Stack* stack;
	Queue* queue;
public:
	Graph(int vertexAmount);
	~Graph();
	void addVertex(char label);
	void addEdge(int startVertId, int endVertId);
	void addEdge(char startVertLabel, char endVertLabel);
	void dfs();
	void bfs();
	virtual void mst();
	void resetFlags();
};

