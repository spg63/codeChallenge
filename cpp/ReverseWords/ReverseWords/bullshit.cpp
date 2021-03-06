//
//  main.cpp
//  ReverseWords
//
//  Created by Sean Grimes on 7/30/15.
//  Copyright © 2015 Sean Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/8/
 * Run Time Reported:   3ms
 * Mem Use Reported:    23.506 KB
 * Score:               100
 * Ranking Points:      34.973 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */

#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <iterator>
using std::istream_iterator;
#include <sstream>
using std::istringstream;

void putLinesIntoVector(vector<string> &vec, ifstream &stream);
string reverseString(string &s);
vector<string> splitString(string &lineOfFile);

int main(int argc, const char * argv[]) {
    
    ifstream in(argv[1]);
    vector<string>lines;

    // NOTE: Works on reference, side effects and all...my kinda function
    putLinesIntoVector(lines, in);

    in.close();
    
    for(auto i = 0; i < lines.size(); ++i){
        // This passes a string, reverses it, then gives it back for printing
        cout << reverseString(lines[i]) << "\n";
    }
    
}

void putLinesIntoVector(vector<string> &vec, ifstream &stream){
    string line;
    while(std::getline(stream, line)){
        vec.push_back(line);
    }
}

// Get a forward string, pass it to split, get the vector back, print in reverse
string reverseString(string &s){
    // Get a copy of the string
    string original = s;
    
    // Split it up for reversing
    vector<string> splits = splitString(original);
    
    // String to be returned
    string reversed = "";
    for(int i = (int)splits.size() - 1; i >= 0; --i){
        reversed += splits[i];
        
        // Don't print a space after the last word
        if(i > 0){
            reversed += " ";
        }
    }
    return reversed;
}

/*
    Takes a file line in original format
    Puts it into a stringstream
    Splits the stringstream on whitespace and puts the words into a vector
    Returns the vector
*/
vector<string> splitString(string &lineOfFile){
    istringstream ss(lineOfFile);
    istream_iterator<string> begin(ss), end;
    vector<string> re(begin, end);
    return re;
}