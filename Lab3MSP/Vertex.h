#pragma once


class Vertex
{
	friend class Graph;
private:
	int vertexId;
	char label;
	bool wasVisited;
public:
	Vertex();
	Vertex(char label);
	Vertex(int vertexId, char label);
};

