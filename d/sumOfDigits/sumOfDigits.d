/*
 * For comparison sake, using bash time utility:
 *	dlang version:	0m0.003s
 *	cpp version:	0m0.001s
 */

module main;

import std.stdio;	//input / output
import std.conv;	//string to int
import std.file;	//file operations
import std.string;	//splitLines

void main(string[] args) {
	string fileName = args[1];
	if(exists(fileName)){
		foreach(line; readText(fileName).splitLines()){
			int x = stringToInt(line);
			int sum = sumOfDigits(x);
			writeln(sum);
		}
	}
	else{
		writeln("Can't find the file");
	}
}

int stringToInt(string s){
	// Converting string to int
	string clean = strip(s);
	int i = to!int(clean);
	return i;
}

int sumOfDigits(int i){
	// Catch negatives
	if(i < 0){
		return -sumOfDigits(-i);
	}
	if(i < 10){
		return i;
	}
	return(i % 10 + sumOfDigits(i / 10));
}

/**
 * Original C++ Code
 * 
 * #include <iostream>
 * using std::cout;
 * #include <string>
 * using std::string;
 * #include <fstream>
 * using std::ifstream;
 * #include <vector>
 * using std::vector;
 * #include <algorithm>
 * using std::copy;
 * #include <iterator>
 * using std::istream_iterator;
 * #include <sstream>
 * using std::stringstream;
 *
 * int strToInt(string &s);
 * int sumOfDigits(const int &x);
 * 
 * int main(int argc, const char * argv[]) {
 *     
 *     ifstream in(argv[1]);
 *     vector<string> lines;
 *     
 *     copy(istream_iterator<string>(in),
 *          istream_iterator<string>(),
 *          back_inserter(lines));
 *     
 *     in.close();
 *     
 *     for(int i = 0; i < lines.size(); ++i){
 *         cout << sumOfDigits(strToInt(lines[i])) << "\n";
 *     }
 *     
 *     return 0;
 * }
 * 
 * int strToInt(string &s){
 *     stringstream vert;
 *     int i;
 *     vert << s;
 *     vert >> i;
 *     return i;
 * }
 * 
 * // Pass by reference to avoid time, memory penalities (small as they would be)
 * int sumOfDigits(const int &x){
 *     // Catch negatives?
 *    if(x < 0)
 *         return -sumOfDigits(-x);
 *     if(x < 10)
 *         return x;
 *     return(x % 10 + sumOfDigits(x / 10));
 * }
 */
