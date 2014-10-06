//
//  primeNumbers.cpp
//  primeNumbers
//
//  Created by Sean Grimes on 10/1/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/46/
 * Run Time Reported:   34 ms
 * Mem Use Reported:    4.096 KB
 * Score:               100
 * Ranking Points:      64.882 / 65 (Moderate Challenge Max)
 * Unique:              Yes
 */


#include <iostream>
using std::cout;
#include <vector> 
using std::vector;
#include <fstream> 
using std::ifstream;
#include <string> 
using std::string;
#include <algorithm>
using std::copy;
#include <sstream> 
using std::stringstream;
#include <iterator> 
using std::istream_iterator;

int strToInt(string &s);
void markElements(vector<bool> &vec, int a, int n);
vector<int> sieve(int n);

int main(int argc, const char * argv[]) {
    
    // Open in the file argument
    ifstream in(argv[1]);
    // Create vector to hold lines from arg
    vector<string> lines;
    
    // Copy file to lines
    copy(istream_iterator<string>(in),
         istream_iterator<string>(),
         back_inserter(lines));
    
    // Close file
    in.close();
    
    // Convert read in strings to ints and store in vector<int>
    vector<int> nums(lines.size());
    for(int i = 0; i < lines.size(); ++i){
        nums[i] = strToInt(lines[i]);
    }
    
    vector<int> printPrimes;
    
    // Find and print all primes from ints using Sieve of Eratosthenes
    for(int i = 0; i < nums.size(); ++i){
        int n = nums[i];
        cout << "\n";
        printPrimes = sieve(n);
        for(int i = 0; i < printPrimes.size(); ++i){
            if(i != printPrimes.size() - 1){
                cout << printPrimes[i] << ",";
            }
            else{
                cout << printPrimes[i];
            }
        }
    }
    return 0;
}

// Convert strings to ints using stringstream
int strToInt(string &s){
    stringstream vert;
    int i;
    vert << s;
    vert >> i;
    return i;
}

void markElements(vector<bool> & vec, int a, int n){
    int i = 2,
    num;
    while ((num = i*a) <= n){
        // If not a prime, set to false
        vec[num-1] = false; // minus 1 because index starts from 0.
        ++i;
    }
}

vector<int> sieve(int n){
    vector<int> primes;
    // There are no prime numbers smaller than 2
    if (n >= 2){
        // vector<bool>, specialized type, all bits, defaults to false, so set
        //      all bits to true to begin with.
        vector<bool> vec(n, true);
        for (int i=1; i<n; ++i){
            // If element has been set to true, print.
            if ( vec[i] == true ){
                //(i+1) is prime, print it and mark its multiples
                primes.push_back(i + 1);
                //cout << i + 1 << ",";
                // Marking more
                markElements(vec, i+1, n);
            }
        }
    }
    return primes;
}


















