int partition(int arr[], int left, int right) {
	int pivot = arr[(left + right) / 2];
	while (left <= right) {
		//Find element on left that should be on the right
		while (arr[left] < pivot) left++;
		
		//Find element on right that should be on the left
		while (arr[right] > pivot) right --;
		
		//swap elements, and move left and right indices
		if (left <= right) {
			swap (arr, left, right); //temp = arr[left]; arr[left] = arr[right]; arr[right] = temp;
			left++;
			right--;
		}
	}
	return left;
}

void quickSort(int arr[], int left, int right) {
	int index = partition(arr, left, right);
	if (left < index - 1) { //sort the left half
		quickSort(arr, left, index - 1);
	}
	if (index < right) { //sort the right half
		quickSort(arr, index, right);
	}
	return -1;
}