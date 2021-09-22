/* A magic index in an array is an index such that A[i] = i.
Given a sorted array of distinct integers, write a method to find a
magic index, if one exists, in array A.
Follow Up: What if the values are not distinct?
*/

//Brute force! A great starting place
int magicNumber(int array[]) {
	for (int i = 0; i < array.length; i++) {
		if (array[i] == i) {
			return i;
		}
	}
	return -1;
}

/*The array is sorted, though, so we can use this condition
to implement something similar to a binary search. For binary search
find element k by comparing it to the middle index, x, and determining if 
it would land to the right or left of x.
For array:
-40 | -20 | -1 | 1 | 2 | 3 | 5 | 7 | 9 | 12 | 13
  0	|  1  | 2  | 3 | 4 | 5 | 6 | 7 | 8 | 9  | 10
 where the middle element A[5] = 3, so we know that the magic index
 is on the right side of x(5) since A[mid] < mid.
 Note: the magic index can't be on the left side because elements are
 distinct and the middle value is already too small to be the magic index.
*/
int magicIndex(int array[]) {
	return magicIndex(array, 0, array.length - 1); //array, start, end
}

int magicIndex(int array[], int start, int end) {
	if (end < start) {
		return -1;
	}
	int mid = (start + end) / 2;
	if (array[mid] == mid) {
		return mid;
	}
	else if (array[mid] > mid) {
		return magicIndex(array, start, mid - 1);
	} else {
		return magicIndex(array, mid + 1, end);
	}
}

/*Follow Up: if the elements are not distinct? They are still sorted
For Array:
-10 | -5  | 2 | 2 | 2 | 3 | 4 | 7 | 9 | 12 | 13
  0	|  1  | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9  | 10
The problem is that we cannot conclude what side the magic index would
fall on if A[mid] < mid. It could follow the rules as before, but it 
could be on the left side, too.
Could it be anywhere on the left side though? Not exactly. Since A[5] = 3,
we know that A[4]  couldn't be a magic index. A[4] would need to be the magic
index with value 4, but A[4] must be <= A[5].
Since A[5] = 3, we'll need to recursively search the right side as before.
But, to search the left side, we can skip a bunch of elements and only
recursively search elements A[0] through A[3]. A[3] is the first element that could
be a magic index.

The general pattern is that we compare midIndex and midValue for equality first.
Then if they are not equal, we recursively search the left and right side:
Left side: search indices start -> Math.min(midIndex - 1, midValue).
Right side: search indices Math.max(midIndex + 1, midValue) -> end.
*/

int magicIndex(int array[]) {
	return magicIndex(array, 0, array.length - 1);
}

int magicIndex(int array[], int start, int end) {
	if (end < start) return -1; //check if indices work
	
	int midIndex = (start + end) / 2;
	int midValue = array[midIndex];
	if (midValue == midIndex) {
		return midIndex;
	}
	
	//Search left
	int leftIndex = Math.min(midIndex - 1, midValue); // pick the minimum value between the index before mid and midValue
	int left = magicIndex(array, start, leftIndex);
	if (left >= 0) {
		return left;
	}
	
	//Search right
	int rightIndex = Math.max(midIndex + 1, midValue);
	int right = magicIndex(array, rightIndex, end);
	return right;
}