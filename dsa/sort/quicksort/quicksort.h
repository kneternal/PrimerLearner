#include <vector>
#include <cstdlib>
#include <iostream>

#include "insertionsort/insertionsort.h"

#define INSERTION_FOR_SMALL_PARTITION
#define INSERTION_THRESHOLD 20

using namespace std;

void quicksort(vector<int> &);
void quicksort_helper(vector<int> &, int, int);
int partition_helper(vector<int> &, int, int);
