//
//  sumOfDigits.cpp
//  sumOfDigits
//
//  Created by Sean Grimes on 9/30/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/21/
 * Run Time Reported:   31 ms
 * Mem Use Reported:    4.096 KB
 * Score:               100
 * Ranking Points:      34.941 / 35 (Easy Challenge Max)
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
int sumOfDigits(const int &x);

int main(int argc, const char * argv[]) {
    
    ifstream in(argv[1]);
    vector<string> lines;
    
    copy(istream_iterator<string>(in),
         istream_iterator<string>(),
         back_inserter(lines));
    
    in.close();
    
    for(int i = 0; i < lines.size(); ++i){
        cout << sumOfDigits(strToInt(lines[i])) << "\n";
    }
    
    return 0;
}

int strToInt(string &s){
    stringstream vert;
    int i;
    vert << s;
    vert >> i;
    return i;
}

// Pass by reference to avoid time, memory penalities (small as they would be)
int sumOfDigits(const int &x){
    // Catch negatives?
    if(x < 0)
        return -sumOfDigits(-x);
    if(x < 10)
        return x;
    return(x % 10 + sumOfDigits(x / 10));
}
