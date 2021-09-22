/*Delete the middle node (not the first or the last node) in abort
linked list. Given only access to that node.
Ex: input: the node c in the linked list a->b->c->d->e->fabs
result: nothing returned, linked list looks like a->b->d->e->f
*/

/*You aren't given access to the head of this linked list, only
the node to be deleted.
1)Copy the data from the next node to the current one
2)then delete the next node
*/
boolean deleteNode(LinkedListNode n) { //n = c
	if (n == null || n.next == null) {
		return false; //cannot be last node or not present in list
	}
	LinkedListNode next = n.next; //next = d
	n.data = next.data; //c becomes d
	n.next = next.next; //"delete" next by bypassing the next node with n.pointer
	return true;
}

//Note this problem can't be solved if the node is the last node.
//This could be bypassed by making that node a dummy node (so that
//the real last node becomes the second to last)