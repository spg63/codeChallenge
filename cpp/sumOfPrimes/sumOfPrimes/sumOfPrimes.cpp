//
//  main.cpp
//  sumOfPrimes
//
//  Created by Sean Grimes on 10/2/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/4/
 * Run Time Reported:   4ms
 * Mem Use Reported:    9.180 KB
 * Score:               100
 * Ranking Points:      34.985 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */


#include <iostream>
using std::cout;
#include <vector>
using std::vector;

void markElements(vector<bool> &vec, int a, int n);
vector<int> sieve (int n);

int main(int argc, const char * argv[]) {
    int n = 7920;
    vector<int> printPrimes;
    printPrimes = sieve(n);
    //int total_sum = 0;
    int total_sum_new = 0;
    
    for(int i: printPrimes){
        total_sum_new = total_sum_new + i;
    }
   
    /*
    for(int i = 0; i < printPrimes.size(); ++i){
        total_sum = total_sum + printPrimes[i];
    }
    */
    
    //cout << total_sum << "\n";
    cout << total_sum_new;
    return 0;
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
                primes.emplace_back(i + 1);
                //cout << i + 1 << ",";
                // Marking more
                markElements(vec, i+1, n);
            }
        }
    }
    return primes;
}