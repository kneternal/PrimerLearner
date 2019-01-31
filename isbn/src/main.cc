#include "Sales/Sales_item.h"

int main (int argc, char** argv) {
  Sales_item book1;
  Sales_item book2;
  
  std::cin >> book1 >> book2;
  //std::cout << book1 << book2 << std::endl;
  std::cout << book1.get_isbn() << std::endl;
  return 0;
}
