//
//  longestWord.cpp
//  longestWord
//
//  Created by Sean Grimes on 8/9/15.
//  Copyright © 2015 Sean Grimes. All rights reserved.
//

/**
 * Link:                https://www.codeeval.com/open_challenges/111/
 * Run Time Reported:   4ms
 * Mem Use Reported:    34.914 KB
 * Score:               100
 * Ranking Points:      34.963 / 35 (Easy Challenge Max)
 * Unique:              Yes
 */

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <sstream>
using std::stringstream;

class LongestWord{
public:
    // Defaults to delim = ' ' --> split on spaces
    LongestWord(string &line_of_file)
    : _line{line_of_file}{}
    
    LongestWord(string &line_of_file, char delim)
    : _line{line_of_file}, _delim{delim}{}
    
    void split_line(){
        stringstream ss{_line};
        string tmp_line;
        while(getline(ss, tmp_line, _delim)){
            _words_from_line.push_back(tmp_line);
        }
    }
    
    void find_longest_word(){
        for(int i = 0; i < _words_from_line.size(); ++i){
            if(_words_from_line[i].size() > _cur_longest_len){
                _cur_longest_len = (int)_words_from_line[i].size();
                _longest_word = i;
            }
        }
    }
    
    void print_logest_word(){
        cout << _words_from_line[_longest_word] << "\n";
    }
    
    void do_it(){
        split_line();
        find_longest_word();
        print_logest_word();
    }
    
private:
    char _delim{' '};
    string _line;
    vector<string> _words_from_line;
    int _longest_word{};
    int _cur_longest_len{};
};

int main(int argc, const char * argv[]) {
    if(argc != 2)
        exit(-1);
    
    ifstream in(argv[1]);
    string line;
    vector<string> file_lines;
    while(getline(in, line)){
        file_lines.push_back(line);
    }
    
    for(int i = 0; i < file_lines.size(); ++i){
        LongestWord lw(file_lines[i]);
        lw.do_it();
    }
    
    return 0;
}
