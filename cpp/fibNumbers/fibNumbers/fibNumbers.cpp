//
//  fibNumbers.cpp
//  fibNumbers
//
//  Created by Sean Grimes on 9/29/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//


/**
 * Link:                https://www.codeeval.com/open_challenges/22/
 * Run Time Reported:   31 ms
 * Mem Use Reported:    4.096 KB
 * Score:               100
 * Ranking Points:      34.942 / 35 (Easy Challenge Max)
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
#include <algorithm>
using std::copy;
#include <iterator> 
using std::istream_iterator;
#include <sstream> 
using std::stringstream;

int strToInt(string &s);
int fibonacci(int x);

int main(int argc, const char * argv[]) {

    ifstream in(argv[1]);
    vector<string> lines;
    
    copy(istream_iterator<string>(in),
         istream_iterator<string>(),
         back_inserter(lines));
    
    in.close();
    
    for(int i = 0; i < lines.size(); ++i){
        cout << fibonacci(strToInt(lines[i])) << "\n";
    }
    
    return 0;
}

int strToInt(string & s){
    stringstream vert;
    int i;
    vert << s;
    vert >> i;
    return i;
}

int fibonacci(int x){
    if(x <= 1)
        return x;
    return (fibonacci(x - 1) + fibonacci(x - 2));
}
