/*Given a sorted array (a good clue that it is binary search)
of n integers that has been rotated an unknown number of times, write
code to find an element in the array. You can assume that the array
was originally sorted in increasing order.
Ex. Input: Find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
Output: 8 (the index of 5 in the array)
*/

/*Typically in binary search, we compare x with the midpoint to figure out
if x belongs on the left or the right side. The complication here is that
the array is rotated and may have an inflection point.
Ex: 
Array1: {10, 15, 20, 0, 5}
Array2: {50, 5, 20, 30, 40}

Both arrays have a midpoint of 20, but 5 appears on the left side of 
one and the right side of the other. Therefore, comparing x with the midpoint
is insufficient.

Looking deeper, we can see that one half of the array must be ordered normally
(ascending order). We can look at the normally ordered half to determine
whether we should search the left or right half.

For example, if we are searching for 5 in Array1, we can look at the left element(10)
and the middle element(20). Since 10 < 20, the left half must be ordered normally. And
since 5 is not between those, we know that we must search the right half (out of order)

In Array2, we can see that since 50 > 20, the right half is ordered normally. We turn 
to the middle (20) and the right (40) element to check if 5 would fall between them.
The value 5 would not. Therefore we search the left half.

Tricky condition: if the left and middle are identical: {2, 2, 2, 3, 4, 2}.
In this case, we can check if the rightmost element is different. If it is,
we can search just the right side. Otherwise, we have no choice but to search 
both halves.
*/

int search(int a[], int left, int right, int x) {
	int mid = (left + right) / 2;
	if (x == a[mid]) { // FOund element
		return mid;
	}
	if (right < left) {
		return -1;
	}
	
	/*Either the left or right half must be normally ordered. Find out
	which side is normally ordered, and then use the normally ordered half
	to figure out which side to search to find x.
	*/
	if (a[left] < a[mid]) { //Left is ordered normally
		if (x >= a[left] && x < a[mid]) {
			return search(a, mid + 1, right, x); //Search right
		} else {
			return search(a, left, mid - 1, x); //Search left
		}
	} else if (a[mid] < a[left]) { //Right is ordered normally
		if (x >= a[left] && x < a[mid]) {
			return search(a, mid + 1, right, x); //Search right
		} else {
			return search(a, left, mid - 1, x); //Search left
		}
	} else if (a[left] == a[mid]) { //Left or right half is all repeats
		if (a[mid] != a[right]) { //If right is different, search it
			return search(a, mid + 1, right, x); //search right
		} else { //We have to search both halves
			int result = search(a, left, mid - 1, x); //search left
			if (result == -1) {
				return search(a, mid + 1, right, x); //search right
			} else {
				return result;
			}
		}
	}
	return -1;
}

/*This code will run in O(log n) if all elements are unique. With many 
duplicates, though, the algorithm is actually O(n). This is because with many duplicates,
we will often have to search both the left and right sides of the array (or subarrays).
*/
