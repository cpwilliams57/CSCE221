#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>

#include "Graph.hpp"

using namespace std;

//default constructor
Graph::Graph(){}
//builds graph
void Graph::buildGraph(std::string filename){
	ifstream file(filename); 
	int num, dest, depart;
	int vert = 0; 
	file >> depart >> dest; 
	while(!file.eof()){ 
			list<Edge> tempEdgeList;
			int ds; 
			Vertex tempVert(vert);
			vertices.push_back(tempVert);
			file >> ds;
			while(ds != -1){
				Edge tempEdge(vert,ds,1);
				tempEdgeList.push_back(tempEdge);
				file >> ds;
			}
			adj_list.push_back(tempEdgeList); 
			vert = vert + 1;
	}
	adj_list.pop_back();
	file.close();
}
//prints graph 
void Graph::displayGraph(ostream& out){
// 	//print graph 
	for(int i = 0; i < adj_list.size(); ++i){
		out << i << ": "; 
		for(Edge e: adj_list[i])
			out << e.end << " "; 
		out << endl; 
	}
}

bool Graph::inlist(vector<Edge> list, int vertex){
	for(Edge edge: list){
		if(edge.end == vertex)
			return true; 
	}
	return false; 
}

void Graph::partition(){
	vector<Edge> list1, list2; 
	for(int i = 0; i < adj_list.size(); ++i){
		//check to see if vertex is in the list 
		if((inlist(list1, i)) == true){
			for(Edge e: adj_list[i])
				list2.push_back(e);
		}
		else{
			for(Edge e: adj_list[i])
				list1.push_back(e);
		}
	}

	bool duplicate = false;

	for(int i = 0; i < list1.size(); ++i){
		for(int j = 0; j< list2.size(); ++j){
			if(list1[i].end == list2[j].end)
				duplicate = true;  
		}
	}

	if (duplicate == true){
		std::cout <<"NO GROUPING POSSIBLE" << endl; 
	}
	else{
		std:: cout << "List 1 (with duplicates): ";
		for(Edge e: list1){
			std::cout << e.end << " "; 
		}

		std::cout << endl; 

		std:: cout << "List 2 (with duplicates): ";
		for(Edge e: list2)
			std::cout << e.end << " "; 
	}
	//need to figure out how to remove duplicates 
}

void Graph::path(int a, int b){
	bool found = false; 
	while(found == false){
		//check adjacent nodes
		//compare number of edges between node paths
		//determine the shortest path
	}
	//print the shortest path 
}

