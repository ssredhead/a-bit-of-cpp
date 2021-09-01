#include <iostream>
using namespace std;

//utility function to get arr[] max_value
int getMax(int arr[], int n) {
	
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

//counting sort for arr[] according to the digit represented by exp.
void countSort(int arr[], int n, int exp) {
	
	int output[n]; //output array
	int i, count[10] = { 0 };
	
	//store count of occurences in count[]
	for (i = 0; i < n; i++) {
		count[(arr[i] / exp) % 10]++;
	}
	
	//Change count[i] so that it now contains actual
	//position of this digit in output[]
	for (i = 1; i < 10; i++){
		count[i] += count[i - 1];
	}
	
	//Build output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	
	//copy output array into arr[], so that arr[] now contains
	//sorted numbers according to current digit
	for (i = 0; i < n;  i++) {
		arr[i] = output[i];
	}
}
//Main function to sort arr[] of size n using Radix Sort
void radixSort(int arr[], int n) {
	
	//Find the max number to know the number of digits
	int max = getMax(arr, n);
	
	//Counting sort for every digit.
	//Instead of passing digit number, exp is passed.
	//exp is 10^i where i is the current digit number
	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSort(arr, n, exp);
	}
}

//A utility function to print the array
void print(int arr[], int n) {
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(arr) / sizeof(arr[0]); // get size of array
	
	
	radixSort(arr, n);
	print(arr, n);
	
	return 0;
}