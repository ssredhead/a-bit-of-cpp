int binarySearch(int a[], int x) {
	int low = 0;
	int high = a.size() - 1;
	int mid;
	
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] < x) //search right, reassign low to be +1 to mid
			low = mid + 1;
		else if (a[mid] > x) //search left
			high = mid - 1;
		else {
			return mid; //mid is the x
		}
	}
	return -1; //Error
}