//
//  evenNumbers.cpp
//  evenNumbers
//
//  Created by Sean Grimes on 8/2/15.
//  Copyright © 2015 Sean Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/100/
 * Run Time Reported:   3ms
 * Mem Use Reported:    20.049 KB
 * Score:               100
 * Ranking Points:      34.997 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <fstream>
using std::ifstream;
#include <sstream>
using std::stringstream;

string isEven(const string &line);
int strToInt(const string &num);

int main(int argc, const char * argv[]) {
    ifstream in(argv[1]);
    string line;
    while(std::getline(in, line)){
        cout << isEven(line) << endl;
    }
    
    in.close();
    
    return 0;
}

string isEven(const string &line){
    if(strToInt(line) % 2 == 0)
        return "1";
    else
        return "0";
}

int strToInt(const string &num){
    stringstream vert;
    vert << num;
    int i;
    vert >> i;
    return i;
}



