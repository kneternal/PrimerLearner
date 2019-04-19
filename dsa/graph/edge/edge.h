#include <iostream>

#include "node/node.h"

using namespace std;

class Edge {
private:
  Node *first;
  Node *second;

public:
  Edge(Node *first, Node *second) : first(first), second(second){};
  ~Edge();
};
