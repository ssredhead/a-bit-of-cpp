/*Determine whether a string is one or zero edits (insert, remove, replace) 
from another string. 
Ex. pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bae -> false
*/

/*Think about the meaning of these actions. What does it mean for two stringstream
to be one insertion, replacement, or removal away from each other?

Replacement: For two strings (bale and pale) that are one replacement
away, they are only different in one place.

Insertion: (apple, aple) If you compare these string, they would be
identical except for a shift at some point in the string.

Removal: (apple, aple) is the inverse of insertion. Because of this
we can merge insertion and removal functionality.
*/

boolean oneEditAway(String first, String second) {
	if (first.length() == second.length()) {
		return oneEditReplace(first, second); // length will be the same 
	} else if (first.length() + 1 == second.length()) {
		return oneEditInsert(first, second)
	} else if (first.length() - 1 == second.length()) {
		return oneEditInsert(second, first) //removal inverse of insert
	}
	return false;
}

boolean oneEditReplace(String s1, String s2) {
	boolean foundDifference = false;
	for (int i = 0; i < s1.length(); i++) {
		if (s1.charAt(i) != s2.charAt(i)) {
			if (foundDifference) {
				return false;
			}
			foundDifference = true;
		}
	}
	return true;
}

//Check if you can insert a character into s1 to make s2
boolean oneEditInsert(String s1, String s2) {
	int index1 = 0;
	int index2 = 0;
	while(index2 < s2.length() && index1 < s1.length()) {
		if (s1.charAt(index1) != s2.charAt(index2)) {
			if (index1 != index2) {
				return false;
			}
		index2++;
		else {
			index1++;
			index2++
		}
	}
	return true;
}

//Time complexity: O(n) which is tricky for bigger strings.
//This can be made more efficient by first comparing the sizes of the strings