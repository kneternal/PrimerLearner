#include "Sales_item.h"

// Sales_item::Sales_item(std::string info) {
//   isbn = "";

//   for(auto it=info.begin(); *it != ' '; ++it){
//     isbn.append(*it);
//   }

//   std::string tmp = "";
//   for(it = it + 1; *it != ' '; ++it){
//     tmp.append(*it);
//   }
//   number_sold = tmp.stoi();
//   it++;

//   tmp = "";
//   for(it = it + 1; *it != info.end(); ++it){
//     tmp.append(*it);
//   }
//   revenue = tmp.stod() * number_sold;
// }

std::istream &operator>>(std::istream &in, Sales_item &item) {
  std::string isbn;
  int number_sold;
  double revenue;

  std::cout << "Please enter isbn: " << std::endl;
  in >> isbn;

  std::cout << "Please enter number sold: " << std::endl;
  in >> number_sold;

  std::cout << "Please enter unit price: " << std::endl;
  in >> revenue;

  revenue = revenue * number_sold;

  item.set_isbn(isbn);
  item.set_number_sold(number_sold);
  item.set_revenue(revenue);

  return in;
}

std::ostream &operator<<(std::ostream &out, const Sales_item &item) {
  out << item.get_isbn() << " " << item.get_number_sold() << " "
      << item.get_revenue() << std::endl;
  return out;
}
