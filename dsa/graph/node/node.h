#include <deque>
#include <iostream>

using namespace std;

class Node {
private:
  int value;

public:
  Node(int value) : value(value){};
  ~Node();
};
