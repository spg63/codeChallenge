//
//  simpleSorting.cpp
//  simpleSorting
//
//  Created by Sean Grimes on 8/3/15.
//  Copyright © 2015 Sean Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/91/
 * Run Time Reported:   13ms
 * Mem Use Reported:    399.95 KB
 * Score:               100
 * Ranking Points:      34.642 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */

#include <iostream>
using std::cout;
using std::string;
using std::getline;
#include <sstream>
using std::stringstream;
using std::istringstream;
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <iterator>
#include <iomanip>
using std::setprecision;
using std::fixed;

float stringToFloat(const string &number);
string sortedInput(const string &file_line);
vector<string> splitStringIntoVector(const string &line);
string floatVectorToString(const vector<float> &float_vec);
string floatToString(float num);

int main(int argc, const char * argv[]) {
    if(argc != 2)
        exit(-1);
    
    ifstream in(argv[1]);
    string line;
    while(getline(in, line)){
        cout << sortedInput(line) << std::endl;
    }
    return 0;
}

string sortedInput(const string &file_line){
    vector<string> splits = splitStringIntoVector(file_line);
    vector<float> nums;
    for(int i = (int)splits.size() - 1; i >= 0; --i){
        nums.emplace_back(stringToFloat(splits[i]));
    }
    
    sort(nums.begin(), nums.end());
    
    return floatVectorToString(nums);
}

vector<string> splitStringIntoVector(const string &line){
    istringstream ss(line);
    std::istream_iterator<string> begin(ss), end;
    vector<string> splits(begin, end);
    return splits;
}

string floatVectorToString(const vector<float> &float_vec){
    string re = "";
    for(int i = 0; i < (int)float_vec.size(); ++i){
        re += floatToString(float_vec[i]);
        if(i < float_vec.size() - 1)
            re += " ";
    }
    return re;
}

float stringToFloat(const string &number){
    stringstream vert;
    vert << number;
    float f;
    vert >> f;
    return f;
}

string floatToString(float num){
    stringstream vert;
    vert << std::fixed << setprecision(3) <<num;
    string s;
    vert >> s;
    return s;
}