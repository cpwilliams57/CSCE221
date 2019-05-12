#include <iostream>
#include <string>

#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    try{
        if (argc != 2) throw invalid_argument("Usage: ./main <file name>");
        ifstream in(argv[1]);
        if (!in) throw invalid_argument("Invalid file name or unable to open file.");
        Graph g;
        g.buildGraph(argv[1]);
        g.displayGraph(cout);
        std::cout << endl;
        g.partition();
        return 0;
    }
    catch (exception& error){
        cerr << "Error: " << error.what() << endl;
    }
}

