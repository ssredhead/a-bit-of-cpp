/*Write a function to find the frequence of occurences of any
given word in a book. What if we were running this algorithm
multiple times?
*/
//We will do this on an example basis
//Solution 1: Single query
/*We go through the book, word by word, and count the number
of times that a word appears. This will take O(n) time. We know
we can't do better than that since we must look at every word.
*/
int getFrequency(String book[], String word) {
	word = word.trim().toLowerCase() //this is an assumption that capitalization doesn't matter
	int count = 0;
	for (String w : book) {
		if (w.trim().toLowerCase().equals(word)) {
			count++;
		}
	}
	return count;
}

//Solution 2: Repetitive Queries
//We can create a hash table to pre-process the book because of repetitive operations
//Lookup for hash tables is O(1) 
HashMap<String, Integer> setupDictionary(String book[]) {
	HashMap<String, Integer> table = new HashMap<String, Integer>();
	for (String word : book) {
		word = word.toLowerCase();
		if (word.trim() != "") {
			if (!table.containsKey(word)) {
				table.put(word, 0);
			}
			table.put(word, table.get(word) + 1);
		}
	}
	return table;
}

int getFrequency(HashMap<String, Integer> table, String word) {
	if (table == null || word == null) return -1;
	word = word.toLowerCase();
	if (table.containsKey(word)) {
		return table.get(word);
	}
	return 0;
}

//Be mindful of error cases!