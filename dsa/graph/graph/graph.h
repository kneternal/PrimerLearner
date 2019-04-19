#include <deque>
#include <iostream>
#include <vector>

#include "edge/edge.h"
#include "node/node.h"

using namespace std;

class Graph {
private:
  deque<Node *> nodes;
  deque<Node *> edges;

public:
  Graph();
  ~Graph();
  bool add_node(Node *);
  bool add_edge(Node *, Node *);
};
