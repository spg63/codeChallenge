//
//  morseCodeToASCII.cpp
//  morseCodeToASCII
//
//  Created by Sean Grimes on 10/12/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

/**
 * Link:
 * Run Time Reported:   https://www.codeeval.com/open_challenges/116/
 * Mem Use Reported:
 * Score:
 * Ranking Points:      X / 35 (Easy Challenge Max)
 * Unique:
 */


#include <iostream>
using std::cout;
using std::ios;
#include <vector>
using std::vector;
#include <sstream> 
using std::stringstream;
#include <map>
using std::map;
#include <string> 
using std::string;
#include <fstream> 
using std::ifstream;
#include <algorithm> 
using std::copy;
#include <iterator>
using std::istream_iterator;


vector<string> &stringSplit(const string &s, char delim, vector<string> &elems){
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
vector<string> stringSplit(const string &s, char delim) {
    vector<string> elems;
    stringSplit(s, delim, elems);
    return elems;
}

int main(int argc, const char * argv[]) {
    ifstream in(argv[1]);
    
    // need to read in full line, so getline
    int num_lines = 0;
    string lines;
    if(in.is_open()){
        while(getline(in, lines)){
            num_lines++;
        }
    }
    
    //reset read position
    in.clear();
    in.seekg(0, ios::beg);
    vector<string> morseCode(num_lines);
    if(in.is_open()){
        for(int i = 0; i < num_lines; ++i){
            getline(in, morseCode[i], '\n');
        }
    }
    in.close();
   
    vector<string> work = stringSplit(morseCode[0], '  ');
    for(int i = 0; i < work.size(); ++i){
        cout << "work: " << work[i] << "\n";
    }
    

    map<string, string> ww2;
    ww2[".-"]       = "A";
    ww2["-..."]     = "B";
    ww2["-.-."]     = "C";
    ww2["-.."]      = "D";
    ww2["."]        = "E";
    ww2["..-."]     = "F";
    ww2["--."]      = "G";
    ww2["...."]     = "H";
    ww2[".."]       = "I";
    ww2[".---"]     = "J";
    ww2["-.-"]      = "K";
    ww2[".-.."]     = "L";
    ww2["--"]       = "M";
    ww2["-."]       = "N";
    ww2["---"]      = "O";
    ww2[".--."]     = "P";
    ww2["--.-"]     = "Q";
    ww2[".-."]      = "R";
    ww2["..."]      = "S";
    ww2["-"]        = "T";
    ww2["..-"]      = "U";
    ww2["...-"]     = "V";
    ww2[".--"]      = "W";
    ww2["-..-"]     = "X";
    ww2["-.--"]     = "Y";
    ww2["--.."]     = "Z";
    ww2["-----"]    = "0";
    ww2[".----"]    = "1";
    ww2["..---"]    = "2";
    ww2["...--"]    = "3";
    ww2["....-"]    = "4";
    ww2["....."]    = "5";
    ww2["-...."]    = "6";
    ww2["--..."]    = "7";
    ww2["---.."]    = "8";
    ww2["----."]    = "9";
    
    for(int i = 0; i < morseCode.size(); ++i){
        cout << ww2[morseCode[i]] << "\n";
    }
    return 0;
}
