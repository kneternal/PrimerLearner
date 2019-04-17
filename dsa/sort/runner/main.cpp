#include "headers.h"

void *run(void *threadid) {
  for (auto i = 0; i < 8; ++i) {
    vector<int> data;
    string file_name = "data_" + to_string(int(pow(10, i))) + ".txt";
    cout << "Process file: " << file_name << endl;
    read_data(data, file_name);

    auto start = chrono::steady_clock::now();
    if(i == 1)
      print(data);
    insertionsort(data);
    if(i == 1)
      print(data);
    auto end = chrono::steady_clock::now();
    cout << "Num: " << i << endl
         << "Insertion sort: Elapsed time : "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << endl;
  }
}

void run_once_quick_sort() {
  vector<int> data;
  string file_name = "data_100.txt";
  read_data(data, file_name);

  print(data);
  
  auto start = chrono::steady_clock::now();
  quicksort(data);
  auto end = chrono::steady_clock::now();

  print(data);
  
  cout << "Quicksort: Elapsed time : "
       << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
       << endl;
}

int main() {
  // int i = 0;
  // run((void *)i);
  unsigned seed = time(NULL);
  srand(seed);
  cout << "seed: " << seed << endl;;
  run_once_quick_sort();
  return 0;
}
