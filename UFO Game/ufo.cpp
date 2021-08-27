#include <iostream>
#include "ufo_functions.hpp"

int main() {
  std::string codeword, answer;
  codeword = "codecademy";
  answer = "__________";
  int misses = 0;
  std::vector<char> incorrect = {};
  bool guess = false;
  char letter;

  greet();

  while ((answer != codeword) && (misses < 7)) {
    display_misses(misses);
    display_status(incorrect, answer);

    std::cout << "Please enter your guess: \n";
    std::cin >> letter;

    for (int k = 0; k < codeword.length(); k++) {
      if (letter == codeword[k]) {
        answer[k] = letter;
        guess = true;
      }
    }
    if (guess) {
      std::cout << "Correct! \n";
    } else {
      std::cout << "Incorrect! The tractor beam pulls the person in futher. \n";
      incorrect.push_back(letter);
      misses++;
    }

  }

  end_game(answer, codeword);

}
