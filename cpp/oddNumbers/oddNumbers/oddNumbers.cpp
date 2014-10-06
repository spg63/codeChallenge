//
//  oddNumbers.cpp
//  oddNumbers
//
//  Created by Sean Grimes on 9/29/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/25/
 * Run Time Reported:   31 ms
 * Mem Use Reported:    4.096 KB
 * Score:               100
 * Ranking Points:      34.942 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */


#include <iostream>
using std::cout;

void printOdds(int x);

int main() {
    int x = 1;
    printOdds(x);
    
    return 0;
}

void printOdds(int x){
    // End the recursion
    if(x == 99){
        cout << x << "\n";
    }
    // If odd number, print
    if((x % 2 != 0) && (x < 99)){
        cout << x << "\n";
        printOdds(x + 2);
    }
    // If even number, move on
    if((x % 2 == 0) && (x < 99)){
        printOdds(x + 1);
    }
}