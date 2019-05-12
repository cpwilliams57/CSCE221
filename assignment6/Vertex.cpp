#include "Vertex.hpp"

//default constructor 
Vertex:: Vertex(int vertlabel){
	label = vertlabel; 
}
// connect this vertex to a specific vertex (adding edge)
void Vertex:: connectTo(int end){
	Edge newEdge(this->label,end,1);
	edgeList.push_back(newEdge); //expected ‘,’ or ‘;’ before ‘edgeList’?
}