#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>
#include <pthread.h>
using namespace std;
void print(vector<int> data){
  cout << "---" << endl;
  for(auto i = data.begin(); i != data.end(); ++i){
    cout << *i << endl;
  }
  cout << "---" << endl;
}

void read_data(vector<int> &data, const string file_name){
  ifstream data_file;
  data_file.open(file_name);
  string line;

  while(getline(data_file, line)){
    data.push_back(stoi(line));
  }
}

vector<int> merge(vector<int> &left, vector<int> &right){
  vector<int> res;

  auto il = left.begin();
  auto ir = right.begin();

  while(il != left.end() && ir != right.end()){
    if(*il > *ir){
      res.push_back(*ir);
      ir++;
    }else{
      res.push_back(*il);
      il++;
    }
  }

  while(il != left.end()){
    res.push_back(*il);
    il++;
  }

  while(ir != right.end()){
    res.push_back(*ir);
    ir++;
  }

  return res;
}

vector<int> merge1(vector<int> left, vector<int> right){
  vector<int> res;

  auto il = left.begin();
  auto ir = right.begin();

  while(il != left.end() && ir != right.end()){
    if(*il > *ir){
      res.push_back(*ir);
      ir++;
    }else{
      res.push_back(*il);
      il++;
    }
  }

  while(il != left.end()){
    res.push_back(*il);
    il++;
  }

  while(ir != right.end()){
    res.push_back(*ir);
    ir++;
  }

  return res;
}

vector<int> mergesort(const vector<int> &data){
  int size = data.size();
  //  print(data);

  if(size == 1){
    return data;
  }

  vector<int> &&left = mergesort(vector<int>(data.begin(), data.begin() + size / 2));
  vector<int> &&right = mergesort(vector<int>(data.begin() + size / 2, data.end()));

  return(merge(left, right));
}

vector<int> mergesort1(const vector<int> &data){
  int size = data.size();
  //  print(data);

  if(size == 1){
    return data;
  }

  vector<int> left = mergesort1(vector<int>(data.begin(), data.begin() + size / 2));
  vector<int> right = mergesort1(vector<int>(data.begin() + size / 2, data.end()));

  return(merge1(left, right));
}

void *run(void *threadid) {
  for (auto i = 0; i < 8; ++i) {
    vector<int> data;
    string file_name = "data_" + to_string(int(pow(10, i))) + ".txt";
    cout << "Process file: " << file_name << endl;
    read_data(data, file_name);

    auto start = chrono::steady_clock::now();
    vector<int> &&res = mergesort1(data);
    auto end = chrono::steady_clock::now();
    cout << "Num: " << i << endl
	 << "Mergesort: Elapsed time : "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << endl;
  }
}
 
void *run1(void *threadid){
  for (auto i = 0; i < 8; ++i) {
    vector<int> data;
    string file_name = "data_" + to_string(int(pow(10, i))) + ".txt";
    cout << "Process file: " << file_name << endl;
    read_data(data, file_name);

    auto start = chrono::steady_clock::now();
    vector<int> res = mergesort(data);
    auto end = chrono::steady_clock::now();
    cout << "Num: " << i << endl
	 << "Mergesort1: Elapsed time : "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << endl;
  }
}

void run_one() {
  vector<int> data;
  read_data(data, "data_10000.txt");

  auto start = chrono::steady_clock::now();
  vector<int> res = mergesort1(data);
  auto end = chrono::steady_clock::now();

  cout << "Mergesort: Elapsed time : "
       << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
       << endl;
  // print(res);
}

int main(){
  // vector<int> data;

  // string file_name = "data_100.txt";
  // read_data(data, file_name);
  
  // auto start = chrono::steady_clock::now();
  // vector<int> &&res = mergesort(data);
  // auto end = chrono::steady_clock::now();
  // cout << "Mergesort: Elapsed time : " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  // //print(res);
  int i =0;
  run((void *)i);
  //run_one();
  // pthread_t a, b;

  // int rc;

  // for (auto i = 0; i < 2; ++i) {
  //   if(i == 0)
  //     rc = pthread_create(&a, NULL, run, (void *)i);
  //   else
  //     rc = pthread_create(&a, NULL, run1, (void *)i);
  //   if (rc) {
  //     cout << "No" << endl;
  //     exit(-1);
  //   }
  // }
  // pthread_exit(NULL);
  return 0;
}
