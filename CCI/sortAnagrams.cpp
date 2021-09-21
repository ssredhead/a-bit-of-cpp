/*Write a method to sort an array of strings so that all the 
* anagrams are next to each other.
Requirement: determine if two strings are anagrams of each other
meaning they use the same characters in different orders.
*/

/*Approach 1: Apply a normal sorting algorithm (merge or quick sort)
and alter the comparator.
We can sort the strings prior to comparing them, and then just
check if the strings are equal.
*/
class AnagramComparator implements Comparator<String> {
	public String sortChars(String s) {
		char[] content = s.toCharArray();
		Arrays.sort(content);
		return new String(content);
	}
	
	public int compare(String s1, String s2) {
		return sortChars(s1).compareTo(sortChars(s2));
	}
}

//now just sort the arrays using this compareTo method instead of the normal one
Array.sort(array, new AnagramComparator());

//Time Complexity: O(n log(n)) just like the best case for a 
//typical sorting algorithm. To do better though, we can use a hash table!

/*A hash table that maps the sorted versions of a word to a list
of its anagrams can speed this up. ex. 
hash[acre] = {acre, race, care}. Once we've grouped all the 
words into these lists by anagrams, we put them back into the array.*/

void sort(String[] array) {
	HashMapList<String, String> mapList = new HashMapList<String, String>();
	
	//Group words by anagram
	for (String s : array) {
		String key = sortChars(s);
		mapList.put(key, s);
	}
	
	//Convert hash table to array
	int index = 0;
	for (String key : mapList.keySet()) {
		ArrayList<String> list = mapList.get(key);
		for (String t : list) {
			array[index] = t;
			index++;
		}
	}
}

String sortChars(String s) {
	char[] content = s.toCharArray();
	Arrays.sort(content);
	return new String(content);
}

/*HashMapList<String, Integer> is a HashMap that maps from Strings
to ArrayList<Integer>
*/

