//
//  nModM.cpp
//  nModM
//
//  Created by Sean Grimes on 8/10/15.
//  Copyright © 2015 Sean Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/browse/62/
 * Run Time Reported:   4ms
 * Mem Use Reported:    16.246 KB
 * Score:               100
 * Ranking Points:      34.978 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;
#include <string>
using std::string;

class modOperator{
public:
    modOperator(string mod_input) : _n_mod_m{mod_input} {
        split_string_and_setup();
    }
    
    modOperator(int n, int m) : _num{n}, _mod{m} {}
 
    void do_mod(){
        _mod_result = _num - (_num / _mod * _mod);
    }
    
    void print_mod(){
        cout << _mod_result << "\n";
    }
    
    
private:
    string _n_mod_m;
    int _num{};
    int _mod{};
    char _delim{','};
    int _mod_result{};
    
    void split_string_and_setup(){
        stringstream ss{_n_mod_m};
        vector<string> elems;
        string tmp_line;
        // split the num and mod.... 20,6 --> push 20 and 6 into vector
        while(getline(ss, tmp_line, _delim)){
            elems.push_back(tmp_line);
        }
        
        if(elems.size() != 2)
            cout << "serious errors here bro\n";
        
        stringstream vert_num{elems[0]};
        stringstream vert_mod{elems[1]};
        
        vert_num >> _num;
        vert_mod >> _mod;
        
        cout << "Real Mod: " << _num % _mod << endl;
    }
    
};


int main(int argc, const char * argv[]) {
    if(argc != 2)
        exit(-1);
    
    ifstream in(argv[1]);
    string line;
    
    while(getline(in, line)){
        modOperator mod(line);
        mod.do_mod();
        mod.print_mod();
    }
    
    return 0;
}

