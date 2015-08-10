//
//  arrayAbsuridity.cpp
//  arrayAbsuridity
//
//  Created by Sean Grimes on 8/5/15.
//  Copyright © 2015 Sean Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/browse/41/
 * Run Time Reported:
 * Mem Use Reported:
 * Score:
 * Ranking Points:
 * Unique:  
 */

#include <iostream>
using std::cout;
using std::string;
#include <string>
//using std::getline;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <iterator>
#include <thread>
#include <cstdlib>
#include <unordered_set>
using std::unordered_set;
#include <algorithm>
using std::replace;
using std::istream_iterator;


/* 
    Going to play with a class on this one...not sure why, just thought it'd 
    make things a bit more interesting for me
*/

class arrPlay{
public:
    arrPlay(string &line_of_file)
    :_line{line_of_file}, _num_elements{0}
    {}
    
    void check_and_insert_element(int num){
        if(_set.find(num) != _set.end())
            cout << num << "\n";
        else
            _set.insert(num);
    }
    
    void split_first_element(){
        stringstream vert;
        vert << _line[0];
        vert >> _num_elements;
        // erase the length of the arr and the first semi-colon
        _line.erase(0, 2);
    }
    
    void split_elements_and_insert_into_hash(){
        // replace commas with space
        replace(_line.begin(), _line.end(), ',', ' ');
        
        stringstream ss(_line);
        
        istream_iterator<string>begin(ss), end;
        
        vector<string> v(begin, end);
        
        for(int i = 0; i < v.size(); ++i){
            stringstream vert;
            vert << v[i];
            int number;
            vert >> number;
            check_and_insert_element(number);
        }
    }
    
    
    
    
private:
    string _line;
    int _num_elements;
    unordered_set<int> _set;
};


// Read in file
// Split into lines of file
// CLASS TIME -- Thread per line
// Grab first number and remove following semi-colon
// Split the remaining numbers on comma [vector]
// Put each number into a map, check if exists on entry, if so we have num
// Print num when we find dup


int main(int argc, const char * argv[]) {
    if(argc != 2)
        exit(-1);
    
    ifstream in(argv[1]);
    string line;
    vector<string> file_lines;
    while(getline(in, line)){
        file_lines.push_back(line);
    }
    
    for(int i = 0; i < file_lines.size(); ++i){
        if(file_lines[i].size() < 1)
            continue;
        arrPlay a(file_lines[i]);
        a.split_first_element();
        a.split_elements_and_insert_into_hash();
    }
    
    return 0;
}


