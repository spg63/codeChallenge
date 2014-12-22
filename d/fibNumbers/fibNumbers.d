/**
 * Author:	Sean Grimes
 * Date:	12/12/14
 * License:	None
 *
 * Link:	https://www.codeeval.com/open_challenges/22/
 *
 * D version of my fibNumbers.cpp file, can't actually submit
 *
 * For comparison sake, using bash time utility:
 *	dlang version:	user: 0m0.011s
 *	cpp version:	user: 0m0.008s
 */

import std.stdio;	// Input / Output / File Pointer
import std.conv;	// to!int

void main(string[] args){
	if(args.length > 1){
		auto file = new File(args[1]);
		foreach(line; file.byLine()){
			num = to!int(line);
			writeln(fibonacci(num));
		}
	}
	else{
		writeln("Where's the file?");
	}
}

int fibonacci(int x){
	if (x <= 1)
		return x;
	return (fibonacci(x - 1) + fibonacci(x - 2));
}
