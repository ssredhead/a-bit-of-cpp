// Write a function that adds two numbers. You should not use + or any arithmetic operators
/*
This requires bit manipulation, essentially what the computer to actually add numbers
1) Add two binary numbers but forget to carry (this is XOR)
2) Add two binary numbers but only carry the 1 ( Bit AND)
3) Add the result
*/
int add(int a, int b) {
	if (b == 0) return a; // base case
	int sum = a ^ b; // add without carrying (XOR)
	int carry = (a & b) << 1; // carry, but don't add
	return add(sum, carry); // recurse with sum + carry
}

// this can also be done iteratively to cut down on space complexity
int add(int a, int b) {
	while (b != 0) {
		int sum = a ^ b; // add without carrying
		int carry = (a & b) << 1; // carry but don't add
		a = sum;
		b = carry;
	}
	return a; // b = 0
}