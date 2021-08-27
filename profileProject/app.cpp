#include <iostream>
#include "profile.hpp"

int main() {

  Profile sam("Sam Drakkila", 30, "NYC", "he/him");
  sam.add_hobby("Hiking");
  sam.add_hobby("Cooking");
  std::cout << sam.view_profile();

}