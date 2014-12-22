/*
 * For comparison sake, using bash time utility:
 *	dlang version:	0m0.002s
 *	cpp version:	0m0.003s
 */

module main;

import std.stdio;

void printOdds(int x);
void main(string[] args){
	int x = 1;
	printOdds(x);
}

void printOdds(int x){
	if(x == 99){
		// Just showing that write only prints the required output
		// Does not end line and move onto next
		// Can call writeln() without args to move onto a new line
		// 	for more output
		write(x);
		writeln();
	}
	if ((x % 2 != 0) && (x < 99)){
		write(x);
		writeln();
		printOdds(x + 2);
	}
	if((x % 2 == 0) && (x < 99)){
		printOdds(x + 1);
	}
}


/**
 * Original C++ code
 * Not very different for something simple
 * Same logic, function declarations, the main difference
 * 	is in the input/output.
 * I'll move onto something slightly more involved next. 
 * 
 * #include <iostream>                                                             
 * using std::cout;                                                                
 * 
 * void printOdds(int x);                                                          
 *
 * int main() {                                                                    
 *     int x = 1;                                                                  
 *     printOdds(x);                                                               
 *
 *     return 0;                                                                   
 * }                                                                               
 *
 * void printOdds(int x){                                                          
 *     // End the recursion                                                        
 *     if(x == 99){                                                                
 *         cout << x << "\n";                                                      
 *     }                                                                           
 *     // If odd number, print                                                     
 *     if((x % 2 != 0) && (x < 99)){                                               
 *         cout << x << "\n";                                                      
 *         printOdds(x + 2);                                                       
 *     }                                                                           
 *     // If even number, move on                                                  
 *     if((x % 2 == 0) && (x < 99)){                                               
 *         printOdds(x + 1);                                                       
 *     }                                                                           
 * }                                                                               
 * 
 */

