/*To make a tree of minimal height, the left and right subtree
* must be as equal as possible. The root node should be the middle
* of the array, with all smaller numbers (this is a sorted array)
* are the left subtree and all greater are the right subtree
* Accomplish this with recursion and by making a binary search tree*/

TreeNode createMinimalBST(int[] array) {
	return createMinimalBST(array, 0, array.length - 1);
}
TreeNode createMinimalBST(int[] arr, int start, int end) {
	if (end < start) return null;
	int mid = (start + end) / 2; //make root the middle of the array
	TreeNode n = new TreeNode(arr[mid]);
	n->left = createMinimalBST(arr, start, mid - 1);
	n->right = createMinimalBST(arr, mid + 1, end);
	return n;
}