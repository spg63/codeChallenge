//
//  wordToDigit.cpp
//  wordToDigit
//
//  Created by Sean Grimes on 8/2/15.
//  Copyright © 2015 Sean Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/113/
 * Run Time Reported:   12ms
 * Mem Use Reported:    407.82 KB
 * Score:               100
 * Ranking Points:      34.638 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <cstdlib>
#include <sstream>
using std::istringstream;
using std::stringstream;
#include <algorithm>
using std::reverse;
#include <iterator>

string doWork(const string &line_of_file);
void splitStringOnPipe(const string &orig, string &left_side, string &right_side);
void sideToVector(const string &side, vector<int> &vec_side);
void stringToIntNumbers(const vector<string> &strings, vector<int> &ints);
string multiplyTwoVectorsElementByElement(vector<int> &left, vector<int> &right);
int stringToInt(string number);
string intToString(int number);

int main(int argc, const char * argv[]) {
    
    if(argc != 2)
        exit(-1);
    
    ifstream in(argv[1]);
    string line, result;
    // Foreach line in the file, split the left and right on the pipe
    // place each string number in a vector 'cell'
    // convert those string numbers to ints
    // do matrix multiplication on them
    while(std::getline(in, line)){
        cout << doWork(line) << endl;
    }
    
    in.close();
    
    return 0;
}

string doWork(const string &line_of_file){
    string left_side, right_side;
    vector<int> left_side_vec, right_side_vec;
    
    splitStringOnPipe(line_of_file, left_side, right_side);
    
    sideToVector(left_side, left_side_vec);
    sideToVector(right_side, right_side_vec);
    
    return multiplyTwoVectorsElementByElement(left_side_vec, right_side_vec);
}

                                              
void splitStringOnPipe(const string &orig, string &left_side, string &right_side){
    vector<string> bullshit;
    string tmp;
    char delim = '|';
    istringstream ss(orig);
    while(std::getline(ss, tmp, delim)){
        bullshit.emplace_back(tmp);
    }
    
    if(bullshit.size() == 2){
        left_side = bullshit[0];
        right_side = bullshit[1];
    }
}

void sideToVector(const string &side, vector<int> &vec_side){
    istringstream ss(side);
    std::istream_iterator<string> begin(ss), end;
    vector<string> str_vec(begin, end);
    stringToIntNumbers(str_vec, vec_side);
}

void stringToIntNumbers(const vector<string> &strings, vector<int> &ints){
    for(int i = 0; i < strings.size(); ++i){
        ints.emplace_back(stringToInt(strings[i]));
    }
    reverse(ints.begin(), ints.end());
}

string multiplyTwoVectorsElementByElement(vector<int> &left, vector<int> &right){
    vector<int> int_results;
    for(int i = 0; i < left.size(); ++i){
        int_results.emplace_back(left[i] * right[i]);
    }
    reverse(int_results.begin(), int_results.end());
    
    string result = "";
    
    for(int i = 0; i < int_results.size(); ++i){
        result += intToString(int_results[i]);
        if(i < int_results.size() - 1)
            result += " ";
    }
    
    return result;
}

int stringToInt(string number){
    stringstream vert;
    vert << number;
    int i;
    vert >> i;
    return i;
}

string intToString(int number){
    stringstream vert;
    vert << number;
    string str;
    vert >> str;
    return str;
}