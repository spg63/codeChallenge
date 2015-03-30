//
//  numDigitToText.cpp
//  numDigitToText
//
//  Created by Sean Grimes on 12/24/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

/**
 * Link:
 * Run Time Reported:
 * Mem Use Reported:
 * Score:
 * Ranking Points:
 * Unique:
 */

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <algorithm>
using std::copy;
#include <iterator>
using std::istream_iterator;

int main(int argc, const char * argv[]){
	
	/* Read the file into a vector of strings */
	ifstream in(argv[1]);
	vector<string> lines;
	copy(istream_iterator<string>(in),
		 istream_iterator<string>(),
		 back_inserter(lines));
	in.close();

	/* Vectors of strings to hold the text 'name' for numbers */
	vector<string> ones = {"one", "two", "three", "four",
								"five", "six", "seven", "eight", "nine"};
	vector<string> tens = {"twenty", "thirty", "forty", "fifty", "sixty",
						   "seventy", "eighty", "ninety"};
	
	/* Specials for the teens */
	vector<string> teens = {"ten", "eleven", "twelve", "thirteen",
							"fourteen", "fifteen", "sixteen", "seventeen",
							"eighteen", "nineteen"};


	/* Foreach element read.... */
	for(int i = 0; i < lines.size(); ++i){
		cout << lines[i] << endl;
	}


	return 0;
}
