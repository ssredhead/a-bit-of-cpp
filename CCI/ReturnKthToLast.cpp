/*Approach 1: Recursive Function
* Pass node values by reference. We can retunr the node value_comp
* and update the counter by passing a pointer to it.
*/
node * nthToLast(node* head, int k, int& i) {
	if (head == NULL) return NULL;
	node* nd = nthToLast(head->next, k, i);
	i++;
	if(i == k) return head;
	return nd;
} 
node* nthToLast(node* head, int k) { //Polymorphism
	int i = 0;
	return nthToLast(head, k, i);
}

/*Approach 2: Iterative Function
* Using two pointers, p1 & p2. Place them k nodes apart in the 
* linked list by putting p2 at the beginning and moving p1 k nodes
* into the list. Then move them at the same place. p1 will hit the end of the
* linked list after LENGTH - k steps. At that point, p2 will be 
* LENGTH - k nodes into the list, or k nodes from the end.
* This algorithm takes O(n) time and O(1) space.
*/
LinkedListNode nthToLast(LikedListNode head, int k) {
	LinkedListNode p1 = head;
	LinkedListNode p2 = head;
	
	//Move p1 k nodes into the list
	for (int i = 0; i < k; i++) {
		if (p1 == null) return null; //Out of bounds
		p1 = p1.next;
	}
	
	//Move elements at the same pace. When p1 hits the end,
	//p2 will be at the kth elements
	while (p1 != null) {
		p1 = p1.next;
		p2 = p2.next;
	}
	return p2;
}