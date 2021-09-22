// computes the nth fibonacci number

#include <iostream>

using namespace std;

int fib(int i, int memo[]) {//overloaded because of new parameters
	if (i == 0 || i == 1) return i;
	
	if (memo[i] == 0) {//start of fib sequence
		memo[i] = fib( i - 1, memo) + fib( i - 2, memo);
	}
	return memo[i];
}

int fib(int n) {
	return fib(n, new int[n+1]);
} 


int main () {
	
	int n = 0;
	
	cout << "Input the fib number you want to find \n";
	cin >> n;
	
	cout << fib(n) << " is the " << n << "th fib value \n";
	
	return 0;
}
