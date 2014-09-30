//
//  main.cpp
//  uglyNumberChallenge
//
//  Created by Sean Grimes on 9/29/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector> 
#include <fstream> 
#include "sgNumUtils.h"

using namespace std;

const bool TESTING = true;

int numOfExpressions(const string &s);
bool isUglyNum (int number);

int main(int argc, const char * argv[]) {
    
    /**
     * An ugly number is a number divisible by a one-digit prime number
     *  That is 2, 3, 5, or 7.
     *  14 is ugly, but 13 is not. 39 is ugly, but 121 is not.
     *  0 is also ugly, and negative numbers can be ugly too (-14, -39)
     */
    
    /** Looking at a string of numbers, 123456, you can put a plus, minus, or no
     *  sign between two adjacent digits. 
     * Therefore, starting with D digits, there are 3^(D-1) possible expressions
     * Leading 0 is okay (01023) 0+1-02+3
     *
     * TASK: Amoung the 3^(D-1) expressions, count how many of them evaluate to
     *       an ugly number.
     * Program should accept a filename as first argument, each line in the file
     *  is one test case, each test case will be a single line containing a 
     *  non-empty string of decimal digits. 
     *      The string will be no longer than 13 characters.
     */
    
    // read in arg file name: ifstream in(argv[1]);
    
    vector<string> nums;
    nums.push_back("5248");
    nums.push_back("23");
    nums.push_back("29213");
    nums.push_back("348");
    nums.push_back("1");
/*
    for(auto i = 0; i < nums.size(); ++i){
        int x = numOfExpressions(nums[i]);
        cout << "x: " << x << endl;
    }
*/
    for(auto i = 0; i < nums.size(); ++i){
        int x = numUtils::strToInt(nums[i]);
        if(isUglyNum(x)){
            cout << "Ugly" << endl;
        }
        else{
            cout << "Not Ugly" << endl;
        }
    }
    return 0;
}

int numOfExpressions(const string &s){

    size_t s_len = s.length();
    int total_expressions = pow(3, (s_len - 1));
    
    return total_expressions;
}

bool isUglyNum(int x){
    if(x == 0){
        if(TESTING){
            cout << "Ugly, It's zero\n";
        }
        return true;
    }
    else if((x % 2) == 0){
        if(TESTING){
            cout << "Ugly, Over 2\n";
        }
        return true;
    }
    else if((x % 3) == 0){
        if(TESTING){
            cout << "Ugly, Over 3\n";
        }
        return true;
    }
    else if((x % 5) == 0){
        if(TESTING){
            cout << "Ugly, Over 5\n";
        }
        return true;
    }
    else if((x % 7) == 0){
        if(TESTING){
            cout << "Ugly, Over 7\n";
        }
        return true;
    }
    else{
        return false;
    }
}










