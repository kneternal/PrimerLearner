#include "Sales_item.h"

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

Sales_item &Sales_item::operator+(const Sales_item &item2) {
  number_sold += item2.get_number_sold();
  revenue += item2.get_revenue();
  return *this;
}

Sales_item &Sales_item::operator=(const Sales_item &item) {
  if (this != &item) {
    isbn = item.get_isbn();
    number_sold = item.get_number_sold();
    revenue = item.get_revenue();
  }
  return *this;
}

Sales_item &Sales_item::operator+=(const Sales_item &item2) {
  *this = *this + item2;
  return *this;
}
