/* Write a function to shuffle a deck of cards. It has to begin
a perfect shuffle--in other words, each of the 52! permutations
of the deck has to be equally likely. Assume that you are given a
random number generator which is perfect.
*/
//Work with a small example first array = [1, 2, 3, 4, 5]
/*Use a base-case, listed above, and build approach off of that.
Question: suppose we had a method shuffle(...) that worked on n-1 elements
Could we use this to shuffle n elements?
1) Shuffle n - 1 elements
2) Take the nth element and randomy swap it with an array element
*/

//Recursive Approach

//Random number between lower and higher, inclusive
int rand(int lower, int higher) {
	return lower + (int)(Math.random() * (higher - lower + 1));
}

int[] shuffleArrayRecursively(int cards[], int i) {
	if (i == 0) return cards;
	
	shuffleArrayRecursively(cards, i - 1); //Shuffle earlier part
	int k = rand(0, 1); //Pick random index to swap with
	
	//Swap element k and i
	int temp = cards[k];
	cards[k] = cards[i];
	cards[i] = temp;
	
	//return shuffled array
	return cards;
}

//This is actually a simple algorithm to implement iteratively
void shuffleArrayIteratively(int[] cards) {
	for (int i = 0; i < cards.length; i++) {
		int k = rand(0, i);
		int temp = cards[k];
		cards[k] = cards[i];
		cards[i] = temp;
	}
}