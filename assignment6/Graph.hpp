#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


#include "Vertex.hpp"

using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<list<Edge>> adj_list; // adjacency list
    vector<Vertex> vertices;  // all vertices
    Graph(); // default constructor
    Graph(vector<list<Edge>> adjl); // constructor from adjl = adjacency list (optional)
    void buildGraph(std::string filename);  // build a graph from the adjacency list
    void displayGraph(ostream& out);  // display the graph
    bool inlist(vector<Edge> list, int vertex);
    void partition();
    void path(int a , int b);
};

#endif /* Graph_hpp */
