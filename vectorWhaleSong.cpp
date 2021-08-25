#include <iostream>
#include <vector>
#include <string>

int main() {

  std::string str1 = "turpentine and turtles";
  std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  std::vector<char> result = {};

  for (int i = 0; i < str1.size(); i++) {
    for (int j = 0; j < vowels.size(); j++) {
      if (str1[i] == vowels[j]) {
        result.push_back(vowels[j]);
      }
    }
    if (str1[i] == 'e' || str1[i] == 'u') {
      result.push_back(str1[i]);
    }
  }

  for (int k = 0; k < result.size(); k++) {
    std::cout << result[k];
  }


  return 0;
}