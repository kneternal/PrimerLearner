#include <iostream>
#include <string>
class Sales_item {
private:
  std::string isbn;
  int number_sold;
  double revenue;

public:
  Sales_item() {}
  // Sales_item(std::string info);
  ~Sales_item() {}
  void set_isbn(std::string in) { isbn = in; }
  std::string get_isbn() const { return isbn; }
  void set_number_sold(int ns) { number_sold = ns; }
  int get_number_sold() const { return number_sold; }
  void set_revenue(double r) { revenue = r; }
  double get_revenue() const { return revenue; }

  Sales_item &operator+(const Sales_item &item2);
  Sales_item &operator=(const Sales_item &item);
};

std::ostream &operator<<(std::ostream &out, const Sales_item &item);
std::istream &operator>>(std::istream &in, Sales_item &item);
