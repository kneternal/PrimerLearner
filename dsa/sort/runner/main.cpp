#include "headers.h"

void *run(void *threadid) {
  for (auto i = 0; i < 8; ++i) {
    vector<int> data;
    string file_name = "data_" + to_string(int(pow(10, i))) + ".txt";
    cout << "Process file: " << file_name << endl;
    read_data(data, file_name);
    print(data);
    auto start = chrono::steady_clock::now();
    vector<int> &&res = mergesort1(data);
    auto end = chrono::steady_clock::now();
    cout << "Num: " << i << endl
         << "Mergesort: Elapsed time : "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << endl;
  }
}

int main() {
  int i = 0;
  run((void *)i);
  return 0;
}
