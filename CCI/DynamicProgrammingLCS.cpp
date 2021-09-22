/*
Dynamic Programming approach to Longest Common Substring problem
*/

#include <iostream>
#include <string.h>
using namespace std;

//Return length of LCM from X[0..m-1] and Y[0..n-1]
int LCSubStr(char * X, char* Y, int m, int n) {
	/*
	Create table to store lengths of
	longest common suffixes of substrings.
	LCSuff[i][j] contains length of longest common suffix
	of X[0..i-1] and Y[0..j-1].
	*/
	
	int LCSuff[m + 1][n + 1];
	int result = 0; //Store length of LCSubStr
	
	//Build LCSuff[m+1][n+1] in bottom-up dynamic programming fashion
	for (int i = 0; i <= m; i++) { //O(n)
		for (int j = 0; j <= n; j++) { //O(n)
			//First row & column are just stub data
			if (i == 0 || j == 0) {
				LCSuff[i][j] = 0;
			} else if (X[i - 1] == Y[j - 1]) {
				LCSuff[i][j] = LCSuff[i - 1][j -1] + 1;
				result = max(result, LCSuff[i][j]);
			} else {
				LCSuff[i][j] = 0;
			}
		}
	}
	return result;
}

int main() {
	
	char X[] = "GilearIsTheBestLunchLad";
	char Y[] = "IGuessGilearIsMyDadToo";
	
	int m = strlen(X); //equivalent to array length;
	int n = strlen(Y); 
	
	cout << "Length of the Longest Common Substring is: "
		<< LCSubStr(X, Y, m, n);
		
	return 0;
}