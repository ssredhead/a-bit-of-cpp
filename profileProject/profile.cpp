#include <iostream>
#include "profile.hpp"

Profile::Profile(std::string new_name, int new_age, std::string new_city, std::string new_pronouns) {
  name = new_name;
  age = new_age;
  city = new_city;
  pronouns = new_pronouns;
}

std::string Profile::view_profile() {
  std::string profile = "Name: " + name;
  profile += "\nage: " + std::to_string(age);
  profile += "\nPronouns: " + pronouns;
  profile += "\nHobbies: ";
  for (int i = 0; i < hobbies.size(); i++) {
    profile += "\n" + hobbies[i];
  }

  return profile;
}

void Profile::add_hobby(std::string new_hobby) {
  hobbies.push_back(new_hobby);
}