/*Implement a function void reverse (char* str) which reverses
a null-terminating string.
*/
void reverse(char *str) {
	char* end = str;
	char tmp;
	if (str) {
		while (*end) { //find the end of a string
			++end;
		}
		--end; //set one char back, since last char is null
		
		/*swap characters from start of string with end of string,
		until the pointers meet in the middle.*/
		while(str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}