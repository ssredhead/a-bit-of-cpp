// computes the nth fibonacci number with bottom up dynamic programming

#include <iostream>

using namespace std;

int fib(int n) {
	if (n == 0) return 0;
	int a = 0; //assign base cases
	int b = 1;
	
	for (int i = 2; i < n; i++) {
		//compute the next fib number and reassign a, b to increment
		int c = a + b;
		a = b; 
		b = c;
	}
	
	return a + b;
}


int main () {
	
	int n = 12;
	
	cout << "Input the fib number you want to find: \n";
	cin >> n;
	
	cout << fib(n) << " is the " << n << "th fib value. \n";
	
	return 0;
}