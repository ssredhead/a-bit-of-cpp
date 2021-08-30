void merge (int array[], int helper[], int low, int middle, int high) {
	//copy array into helper for sorting
	for (int i = low; i <= high; i++) {
		helper[i] = array[i];
	}
	
	int helperLeft = low;
	int helperRight = middle + 1;
	int current = low;
	
	//Iterate through helper array. Compare the left and right halves.
	//Copy back the smaller element of the halves into the original array.
	while (helperLeft <= middle && helperRight <= high) {
		if (helper[helperLeft] <= helper[helperRight]) {
			array[current] = helper[helperLeft];
			helperLeft++;
		} else { //If right element is smaller
			array[current] = helper[helperRight];
			helperRight++;
		} 
	current++;
	}
	
	//Copy the rest of the left side into the array and return the target array
	int remaining = middle - helperLeft;
	for (int j = 0; j <= remaining; j++) {
		array[current + 1] = helper[helperLeft + 1];
	}
}


void mergesort(int array[], int helper[], int low, int high) {
	if (low < high) {
		int middle = (low + high) / 2;
		mergesort(array, helper, low, middle); //sort left side
		mergesort(array, helper, middle + 1, high); //sort right side
		merge(array, helper, low, middle, high); //merge them
	}
	
}



void mergesort(int array[]) {
	int[] helper = new int[array.length];
	mergesort(array, helper, 0, array.length - 1);
}