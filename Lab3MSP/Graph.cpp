#include "stdafx.h"
#include "Graph.h"
#include <iostream>


Graph::Graph(int vertexCount) : vertexAmount(vertexCount)
{
	vertices = new Vertex[vertexAmount];
	adjMatrix = new int*[vertexAmount];
	stack = new Stack(vertexAmount);
	queue = new Queue(vertexAmount);
	nVerts = 0;

	for (int i = 0; i < vertexAmount; i++)
	{
		adjMatrix[i] = new int[vertexAmount];
		for (int j = 0; j < vertexAmount; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph()
{
	delete[] vertices;
	delete[] adjMatrix;
	delete stack;
	delete queue;
}

void Graph::addVertex(char label)
{
	Vertex vertex(nVerts, label);
	vertices[nVerts++] = vertex;
}

void Graph::addEdge(int startVertId, int endVertId)
{
	adjMatrix[startVertId][endVertId] = 1;
	adjMatrix[endVertId][startVertId] = 1;
}

void Graph::addEdge(char startVertLabel, char endVertLabel)
{
	int startVertId = -1;
	int endVertId = -1;
	for (int i = 0; i < nVerts; i++)
	{
		if (vertices[i].label == startVertLabel)
			startVertId = i;
		else if (vertices[i].label == endVertLabel)
			endVertId = i;
	}

	addEdge(startVertId, endVertId);
}


void Graph::displayVertex(int vertexId) const
{
	std::cout << vertices[vertexId].label;
}


void Graph::dfs()
{
	int startIndex = 0;
	vertices[startIndex].wasVisited = true;
	displayVertex(startIndex);
	(*stack).push(startIndex);


	while (!(*stack).isEmpty())
	{
		int peek = (*stack).peek();
		int nextVertId = getAdjUnvisitedVertex(peek);

		if (nextVertId == -1)
		{
			(*stack).pop();
		}
		else
		{
			vertices[nextVertId].wasVisited = true;
			displayVertex(nextVertId);
			(*stack).push(nextVertId);
		}		
	}
	resetFlags();
}


int Graph::getAdjUnvisitedVertex(int vertexId)
{
	for (int i = 0; i < nVerts; i++)
	{
		if (adjMatrix[vertexId][i] == 1 && !vertices[i].wasVisited)
			return i;
	}
	return -1;
}


void Graph::bfs()
{
	int startPointId = 0;
	vertices[startPointId].wasVisited = true;
	displayVertex(startPointId);
	(*queue).insert(startPointId);
	int nextVertId;

	while (!(*queue).isEmpty())
	{
		int currentVertexId = (*queue).remove();

		while ((nextVertId = getAdjUnvisitedVertex(currentVertexId)) != -1)
		{
			vertices[nextVertId].wasVisited = true;
			displayVertex(nextVertId);
			(*queue).insert(nextVertId);
		}
	}

	resetFlags();
}


void Graph::mst()
{
	int startPoint = 0;
	vertices[startPoint].wasVisited = true;
	(*stack).push(startPoint);

	while (!(*stack).isEmpty())
	{
		int currentVertexId = (*stack).peek();

		int nextVertId = getAdjUnvisitedVertex(currentVertexId);
		if (nextVertId == -1)
		{
			(*stack).pop();
		}
		else
		{
			vertices[nextVertId].wasVisited = true;
			(*stack).push(nextVertId);

			displayVertex(currentVertexId);
			displayVertex(nextVertId);
			std::cout << std::endl;
		}
	}

	resetFlags();
}


void Graph::resetFlags()
{
	for (int i = 0; i < nVerts; i++)
	{
		vertices[i].wasVisited = false;
	}
}
