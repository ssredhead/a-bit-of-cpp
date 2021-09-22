/*
given an integer array, move all 0s to the left while maintaining
the order of the other elements in the array. In place modification
(no merge-sort).
*/

#include <iostream>

using namespace std;

/*
Use read index to traverse array backwards (start at last index) 
because we want to move zeros to left.
Use write index to replicate the array without zeros (to preserve order)
*/

void move_zeros_to_left(int arr[], int size) {
	if (size < 1) return; //empty array;
	
	int read_index = size - 1; //set to last index
	int write_index = size - 1; 
	
	while (read_index >= 0) { 
		if (arr[read_index] != 0) {
			arr[write_index] = arr[read_index]; //continue
			write_index--; //move write one index left
		}
		read_index--; //move read one index left
	}
	
	//array has been traversed for non-zero numbers
	//now append zeros to remaining indexes left.
	while(write_index >= 0) {
		arr[write_index] = 0;
		write_index--;
	}
}

int main() {
	  int v[] = {1, 10, 20, 0, 59, 63, 0, 88, 0};
  int n = sizeof(v) / sizeof(v[0]);

  cout << "Original Array" <<endl;
  
  for(int x=0 ; x<n; x++) {
    cout << v[x];
    cout << ", ";
  }  
  
  move_zeros_to_left(v, n);
  
  cout << endl<< "After Moving Zeroes to Left"<< endl;
  for(int i=0 ; i<n; i++) {
    cout << v[i];
    cout << ", ";
  }  
	
	
	
	return 0;
}