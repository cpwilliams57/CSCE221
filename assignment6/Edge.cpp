#include "Edge.hpp"
#include <iostream>

//default constructor 
Edge::Edge(int edgestart, int edgeend,int endgeweight){
	start = edgestart;
	end = edgeend;
	weight = endgeweight;
}