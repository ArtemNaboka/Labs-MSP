// Lab3MSP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Graph.h"
#include <iostream>

int main()
{
	Graph g(5);

	g.addVertex('A');
	g.addVertex('B');
	g.addVertex('C');
	g.addVertex('D');
	g.addVertex('E');

	g.addEdge('A', 'B');
	g.addEdge('B', 'E');
	g.addEdge('E', 'D');
	g.addEdge('D', 'C');
	g.addEdge('A', 'C');
	g.addEdge('B', 'D');
	g.addEdge('C', 'E');

	std::cout << "Visits:" << std::endl;
	g.mst();
	std::cout << std::endl;

    return 0;
}

