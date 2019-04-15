#include "shellsort.h"

int gen_intervals(int size){
  int cur = 1;
  while(cur < size / 3){
    cur = cur * 3 + 1;
  }
  return cur;
}

void shellsort(vector<int> &data){
  int size = data.size();

  int interval = gen_intervals(size);

  int tmp;

  while(interval > 0){
    //cout << "interval change: " << interval << endl;
    for(auto i = interval; i < size ; ++i){
      int j = i;
      //cout << "outer: " << i << endl;
      while(j - interval >= 0){
	//cout << "inner: " << j << endl;
	if(data[j - interval] > data[j]){
	  //cout << "swap: " << i << " " << j << endl;
	  tmp = data[j];
	  data[j] = data[j - interval];
	  data[j - interval] = tmp;
	}

	j -= interval;
      }
    }

    //cout << "interval: " << interval << endl;
    interval = (interval - 1) / 3;

  }
}
