#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex()
{
	
}


Vertex::Vertex(char label)
{
	this->label = label;
	this->wasVisited = false;
}


Vertex::Vertex(int vertexId, char label) 
{
	this->vertexId = vertexId;
	this->label = label;
	this->wasVisited = false;
}
