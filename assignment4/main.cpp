//Cody Williams
//will77868
//Section 508
//will77868@tamu.edu

#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int main() {
    
    ifstream file("stroustrup.txt");
    string line;
    regex pattern{R"(<a href=\"(.+)\.ppt)"}; 
    smatch matches;
    
    while(!file.eof()){
        getline(file,line);
        if(regex_search(line,matches,pattern)){
            cout << matches[1] << endl;
        }
    }
    
    
    return 0;
}
