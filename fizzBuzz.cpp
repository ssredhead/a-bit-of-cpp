#include <iostream>

int main() {

  for (int i = 1; i <=100; i++) {
    if (i % 3 == 0) {
      if (i % 5 == 0) {
        std::cout << "FizzBuzz \n";
      }
      else {
        std::cout << "Fizz \n";
      }
    } else if (i % 5 == 0) {
      std::cout << "Buzz \n";
    }
    else {
      std::cout << i << std::endl;
    }
  }
  return 0;
}