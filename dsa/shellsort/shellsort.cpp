#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>
//#include <pthread.h>
using namespace std;

void print(vector<int> data){
  cout << "---" << endl;
  int count = 0;
  for(auto i = data.begin(); i != data.end(); ++i){
    cout << count++ << " : ";
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
void run(){
  for (auto i = 0; i < 8; ++i) {
    vector<int> data;
    string file_name = "data_" + to_string(int(pow(10, i))) + ".txt";
    cout << "Process file: " << file_name << endl;
    read_data(data, file_name);

    auto start = chrono::steady_clock::now();
    shellsort(data);
    auto end = chrono::steady_clock::now();
    cout << "Num: " << i << endl
	 << "Shellsort: Elapsed time : "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << endl;
  }
}

void run_one() {
  vector<int> data;
  read_data(data, "data_10000.txt");

  //cout << "Input data: " << endl;
  //print(data);
  //cout << "=====================" << endl;

  auto start = chrono::steady_clock::now();
  shellsort(data);
  auto end = chrono::steady_clock::now();

  cout << "Shell: Elapsed time : "
       << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
       << endl;

  //cout << "Out data: " << endl;
  //print(data);
  //cout << "=====================" << endl;
}

int main(){

  run();
  
  return 0;
}
