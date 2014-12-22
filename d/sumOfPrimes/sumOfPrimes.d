/**
 * dlang version of sumOfPrimes.cpp
 * Author:	Sean Grimes
 * Date:	12/11/14
 *
 * For comparison sake, using bash time utility:
 *	dlang version:
 *	cpp version:
 */

import std.stdio;	// Input / Output / File
import std.array;	// Dynamic Array
import std.conv;	// to!int

void main(string[] args){
	auto file = new File(args[1]);

	int[] printPrimes;
	foreach(line; file.byLine()){
		int n = to!int(line);
		writeln();
		printPrimes = sieve(n);
		for(int i = 0; i < printPrimes.length; ++i){
			if(i != printPrimes.length - 1){
				write(printPrimes[i], ",");
			}
			else{
				write(printPrimes[i]);
			}
		}
	}
}

void markElements(bool[] arr, int a, int n){
	int i = 2;
	int num;
	while ((num = i * a) <= n){
		arr[num - 1] = false;
		++i;
	}
}

int[] sieve(int n){
	int[] primes;
	if(n >= n){
		bool[] bools(n, 1);
		for(int i = 1; i < n; ++i){
			if(bools[i] == true){
				primes ~= (i + 1);
				markElements(bools, i + 1, n);
			}
		}
	}
	return primes;
}

