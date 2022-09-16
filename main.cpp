// add your code as appropriate 
#include <iostream>
#include "reservoir.h"

int main() {
  

  // reservoir.h tests

  // get_east_storage(std::string date) tests
  std::cout << get_east_storage("01/01/2018") << std::endl;
  // ^^ should be 59.94
  std::cout << get_east_storage("02/01/2018") << std::endl;
  // ^^ should be 65.69
  std::cout << get_east_storage("03/01/2018") << std::endl;
  // ^^ should be 75.83

  // get_min_east() and get_max_east() test

  std::cout << get_max_east() << std::endl;

  std::cout << get_min_east() << std::endl;

  // reverse_order(std::string date1, std::string date 2) 

  reverse_order("01/21/2018", "01/01/2018");

  reverse_order("03/21/2018", "03/01/2018");

  reverse_order("07/21/2018", "07/01/2018");

  return 0;
}
