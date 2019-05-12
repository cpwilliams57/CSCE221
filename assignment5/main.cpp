#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "HashMap.h"
using namespace std;

string parseRosterLine(string line,HashTable* table){
    //finds UIN
    regex UINpattern{R"(\d{9}\)"};
    smatch UINmatches;
    regex_search(line,UINmatches,UINpattern);
    string key = UINmatches[0];
    //finds score
    return table->Search(key);
}

//parses each linefrom input.csv
void parseLineInput(string line, HashTable* table){
    //finds UIN
    regex UINpattern{R"(\d{9}\)"};
    smatch UINmatches;
    regex_search(line,UINmatches,UINpattern);
    string key = UINmatches[0];
    //finds score
    regex scorepattern{R"((\d{2}$)|(\d{2}\s))"};
    smatch scorematches;
    regex_search(line,scorematches,scorepattern);
    string value = scorematches[0];
    table->InsertItem(key, value);
}

//goes through each line of file, parses file, puts in hash table
void readFile(string inputfile, HashTable* table){
    ifstream file(inputfile);
    string line;
    while(!file.eof()){
        getline(file,line);
        parseLineInput(line, table);
    }
    file.close();
}

int main() {
    //read input.csv store scores and UINs in hash table
    HashTable* myTable = new HashTable();
    readFile("input.csv", myTable);
    
    //fill output.csv with names from roster.csv, look for grade and store in output.csv
    ifstream rosterfile("roster.csv");
    string line;
    ofstream outputfile;
    outputfile.open("output.csv");
    while(!rosterfile.eof()){
        getline(rosterfile, line);
        outputfile << line;
        string scoreVal = parseRosterLine(line, myTable);
        outputfile << scoreVal;
    }
    
    //close output.csv
    outputfile.close();
    
    return 0;
    
}
