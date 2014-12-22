/**
 * Dland version of romanNumerals.cpp
 * Author:	Sean Grimes
 * Date:	12/11/14
 *
 * For comparison sake, using bash time utility:
 *	dlang version:	0m0.002s
 *	cpp version:	0m0.003s
 */

import std.stdio;	// Input / Output / File
import std.conv;	// to!int

void main(string[] args){
	if(args.length > 1){
		auto file = new File(args[1]);
		string thousands;
		string hundreds;
		string tens;
		string ones;
		foreach(line; file.byLine()){
			int num = to!int(line);
			if(num > 999 && num < 4000){
				thousands = intToRoman((num / 1000), "M", "", "");
				num = num % 1000;
			}
			else{
				thousands = "";
			}
			if (num > 99 && num < 1000){
				hundreds = intToRoman((num / 100), "C", "D", "M");
				num = num % 100;
			}
			else{
				hundreds = "";
			}
			if(num > 9 && num < 100){
				tens = intToRoman((num / 10), "X", "L", "X");
				num = num % 10;
			}
			else{
				tens = "";
			}
			if(num > 0 && num < 10){
				ones = intToRoman(num, "I", "V", "X");
			}
			else{
				ones = "";
			}
			writeln(thousands ~ hundreds ~ tens ~ ones);
		}
	}
}

string intToRoman(int n, 
				  string one, 
				  string five, 
				  string ten){
	if(n == 1)
		return one;
	if(n == 2)
		return (one ~ one);
	if(n == 3)
		return (one ~ one ~ one);
	if(n == 4)
		return (one ~ five);
	if(n == 5)
		return five;
	if(n == 6)
		return (five ~ one);
	if(n == 7)
		return (five ~ one ~ one);
	if(n == 8)
		return (five ~ one ~ one ~ one);
	if(n == 9)
		return (one ~ ten);
	return "";
}
