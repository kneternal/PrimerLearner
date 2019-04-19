#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cmath>
#include <string>
#include <assert.h>
#include <ctime>

using namespace std;

void print(vector<int> data){
  cout << "---" << endl;
  for(auto i = data.begin(); i != data.end(); ++i){
    cout << *i << endl;
  }
  cout << "---" << endl;
}

void read_data(vector<int> &data, const string file_name){
  ifstream data_file("data/" + file_name);

  assert(!data_file.fail());
  
  string line;
  while(getline(data_file, line)){
    data.push_back(stoi(line));
  }
}
