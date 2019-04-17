#include "quicksort.h"

void quicksort(vector<int> &data){
  quicksort_helper(data, 0, data.size() - 1);
}

void quicksort_helper(vector<int> &data, int head, int tail){
  if(head >= tail){
    return;
  }
  int partition = partition_helper(data, head, tail);
  cout << "partition: " << partition << endl;
  quicksort_helper(data, head, partition);
  quicksort_helper(data, partition + 1, tail);
}

int partition_helper(vector<int> &data, int head, int tail){
  int size = tail - head + 1;
  cout << "size: " << size << endl;
  cout << "head: " << head << endl;
  cout << "tail: " << tail << endl;
  int pivot = rand() %  size + head;
  cout << "pivot: " << pivot << endl;
  int i = head, j = tail;
  
  while(true){
    while(data[i] < data[pivot]){
      i++;
    }

    while(data[j] > data[pivot]){
      j--;
    }

    if(i >= j)
      return j;

    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }
}
