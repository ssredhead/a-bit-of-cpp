#include <iostream>

// Define is_palindrome() here:
bool is_palindrome(std::string text) {
  int size = text.length();
  for (int i = 0; i < size / 2; i++) { //you only need to go through half because your comparing the sides
    if (text[i] != text[size - i - 1]) { // num - 1 because of zero indexing
      return false;
    }
    return true;
  }
}


int main() {
  
  std::cout << is_palindrome("madam") << "\n";
  std::cout << is_palindrome("ada") << "\n";
  std::cout << is_palindrome("lovelace") << "\n";
  
}