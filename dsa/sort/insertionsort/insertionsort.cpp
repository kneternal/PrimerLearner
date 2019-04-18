#include "insertionsort.h"

void insertionsort(vector<int> &data) {
  int size = data.size();
  for (auto i = 1; i < size; ++i) {
    int j = i;
    while (j > 0 && data[j - 1] > data[j]) {
      int tmp = data[j - 1];
      data[j - 1] = data[j];
      data[j] = tmp;
      j--;
    }
  }
}

void insertionsort(vector<int> &data, int head, int tail){
  for(auto i = head + 1; i <= tail; ++i){
    int j = i;
    while(j > head && data[j - 1] > data[j]){
      int tmp = data[j - 1];
      data[j - 1] = data[j];
      data[j] = tmp;
      j--;
    }
  }
}
