#include <iostream>
#include <vector>

using namespace std;

/*Given a singly linked list, 
reverse the nodes at even indices (starting at 1)*/

int main() {
	
	vector<int> list = {7, 14, 21, 28, 9};
	LinekdListNode* list_head = LinkedList::create_linked_list(list);
	
	return 1;
}

//helper function to merge even and odd list back together
LinekdListNode* merge_alterations(LinkedListNode* list1, LinekdListNode* list2) {
	LinekdListNode* head = list1;
	
	if (list1 == nullptr) {
		return list2;
	}
	if (list2 == nullptr) {
		return list1;
	}
	
	while (list1->next != nullptr  && list2 != nullpointer) {
		LinekdListNode* temp = list2;
		list2 = list2-> next; //move list2 on to the next node
		
		temp->next = list1->next;
		list1->next = temp;
		list1 = temp->next
	}
}


