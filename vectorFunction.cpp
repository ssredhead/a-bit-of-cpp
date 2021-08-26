#include <iostream>
#include <vector>

// Define first_three_multiples() here:
std::vector<int> first_three_multiples(int num) {
  std::vector<int> multiples = {};
  for (int i = 1; i <=3; i++) {
    multiples.push_back(num * i);
  }
  return multiples;
}


int main() {
  
  for (int element : first_three_multiples(8)) {
    std::cout << element << "\n";
  }
  
}