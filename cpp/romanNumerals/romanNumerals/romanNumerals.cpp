//
//  romanNumerals.cpp
//  romanNumerals
//
//  Created by Sean Grimes on 10/6/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenge/106/
 * Run Time Reported:   31 ms
 * Mem Use Reported:    4.096 KB
 * Score:               100
 * Ranking Points:      34.942 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */

#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <algorithm> 
using std::copy;
#include <sstream> 
using std::stringstream;
#include <iterator> 
using std::istream_iterator;
#include <string> 
using std::string;


int strToInt(string &s);
string intToRoman(int n, string one, string five, string ten);

int main(int argc, const char * argv[]) {
   
    // Open the file argument
    ifstream in(argv[1]);
    // Create vector to hold lines from arg
    vector<string> lines;
    // Copy file to lines
    copy(istream_iterator<string>(in),
         istream_iterator<string>(),
         back_inserter(lines));
    // Close file
    in.close();
    // Convert strings to ints and store in vector
    vector<int> nums(lines.size());
    for(int i = 0; i < lines.size(); ++i){
        nums[i] = strToInt(lines[i]);
    }
    string thousands, hundreds, tens, ones;
    for(int i = 0; i < nums.size(); ++i){
        // thousands
        if(nums[i] > 999 && nums[i] < 4000){
            thousands = intToRoman((nums[i] / 1000), "M", "", "");
            nums[i] = nums[i] % 1000; //how much is left over
        }
        else{
            thousands = "";
        }
        // hundreds
        if(nums[i] > 99 && nums[i] < 1000){
            hundreds = intToRoman((nums[i] / 100), "C", "D", "M");
            nums[i] = nums[i] % 100;
        }
        else{
            hundreds = "";
        }
        if(nums[i] > 9 && nums[i] < 100){
            tens = intToRoman((nums[i] / 10), "X", "L", "C");
            nums[i] = nums[i] % 10;
        }
        else{
            tens = "";
        }
        if(nums[i] > 0 && nums[i] < 10){
            ones = intToRoman(nums[i], "I", "V", "X");
        }
        else{
            ones = "";
        }
        cout << thousands+hundreds+tens+ones << "\n";
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

string intToRoman(int n, string one, string five, string ten){
   	if (n==1)
        return (one);
    if (n==2)
        return (one+one);
    if (n==3)
        return (one+one+one);
    if (n==4)
        return (one+five);
    if (n==5)
        return (five);
    if (n==6)
        return (five+one);
    if (n==7)
        return (five+one+one);
    if (n==8)
        return (five+one+one+one);
    if (n==9)
        return (one+ten);
    //otherwise, if n is not a digit 1 to 9
    return "";
}

