/**
 * Link:				https://www.codeeval.com/browse/24/
 * Run Time Reported:	32
 * Mem Use Reported:	4.096KB
 * Score:				100
 * Ranking Points:		34.939 / 35 (Easy Challenge Max)
 * Unique:				Yes
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
#include<sstream>
using std::stringstream;
#include <iterator>
using std::istream_iterator;

int strToInt(string &s);

int main(int argc, const char * argv[]) {
    
    // Open the file
    ifstream in(argv[1]);
    // Create vector to hold lines from arg
    vector<string> lines;
    
    // Copy file to lines
    copy(istream_iterator<string>(in),
         istream_iterator<string>(),
         back_inserter(lines));
    
    in.close();
    
    // Convert string to ints and place in new vector
    // Add each new int to the total
    //vector<int> nums(lines.size());
    int total = 0;
    for(int i = 0; i < lines.size(); ++i){
        //nums[i] = strToInt(lines[i]);
        //total += nums[i];
		total += strToInt(lines[i]);
    }
    
    cout << total;
    
    return 0;
}

int strToInt(string &s){
    stringstream vert;
    int i;
    vert << s;
    vert >> i;
    return i;
}







