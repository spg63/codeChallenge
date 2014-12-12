/**
 * Dlang version of sumOfIntsFromFile.cpp
 * Author: 	Sean Grimes
 * Date:	12/11/14
 */

import std.stdio;	// Input / Output / File
import std.conv;	// to!int

void main(string[] args){
	// Checking that the filename has been supplied
	if(args.length > 1){
		// Get a file pointer (throws exception, should use try/catch)
		auto file = new File(args[1]);
		// Total of values in the file
		int total;
		// Foreach line in the file, use .conv to get an int, add to the total
		foreach(line; file.byLine()){
			total += to!int(line);
		}
		// Write the total, challenge doesn't say new line, so don't.
		write(total);
	}
	// If no arg supplied
	else{
		writeln("Where's the file?");
	}
}