#include "quicksort.h"

void quicksort(vector<int> &data){
  quicksort_helper(data, 0, data.size() - 1);
}

void quicksort_helper(vector<int> &data, int head, int tail){
  if(head >= tail){
    return;
  }

#ifdef INSERTION_FOR_SMALL_PARTITION
  if(tail - head + 1 < INSERTION_THRESHOLD){
    insertionsort(data, head, tail);
    return;
  }
#endif
  
  int partition = partition_helper(data, head, tail);
  // cout << "partition: " << partition << endl;
  quicksort_helper(data, head, partition);
  quicksort_helper(data, partition + 1, tail);
}

int partition_helper(vector<int> &data, int head, int tail){
  int size = tail - head + 1;
  int pivot = data[rand() %  size + head];
  int i = head - 1, j = tail + 1;
  
  // cout << "size: " << size << endl;
  // cout << "head: " << head << endl;
  // cout << "tail: " << tail << endl;
  // cout << "pivot: " << pivot << endl;
  // cout << "pivot value: " << data[pivot] << endl;
  
  while(true){
    do{
      i++;
    }while(data[i] < pivot);

    do{
      j--;
    }while(data[j] > pivot);

    if(i >= j)
      return j;

    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }
  // cout << "quit partition_helper" << endl;
}
