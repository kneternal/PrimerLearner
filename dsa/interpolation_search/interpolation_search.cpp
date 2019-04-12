#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

bool inter_search(const vector<int> &data, const int target, int &pos){
  int size = data.size();

  int low = 0;
  int mid = -1;
  int high = size - 1;

  cout << "size: " << size << endl;
  cout << "mid: " << mid << endl;
  cout << "high: " << high << endl;
  cout << "low: " << low << endl;
  cout << "target: " << target << endl;
  
  if(data[mid] == target){
    pos = mid;
    return true;
  }

  while(low <= high){
    if(low == high || data[low] == data[high]){
      return false;
    }

    mid = low + (((double)((high - low) / (data[high] - data[low]))) * (target - data[low]));
    
    if(data[mid] == target){
      pos = mid;
      return true;
    }else{
      if(data[mid] < target){
	low = mid + 1;
      }else if(data[mid] > target){
	high = mid - 1;
      }
    }

    // cout << "update mid: " << mid << endl;
    // cout << "update low: " << low << endl;
    // cout << "update high: " << high << endl;
  }

  return false;
}

void read_data(vector<int> &data, const string file_name){
  ifstream data_file;
  data_file.open(file_name);
  string line;
  while(getline(data_file, line)){
    data.push_back(stoi(line));
  }
}

int main(){
  vector<int> data = {};
  string file_name = "data_1000000.txt";
  read_data(data, file_name);
  
  int pos = -1;
  int target = 1973;
  bool res;

  auto start = chrono::steady_clock::now();
  
  res = inter_search(data, target, pos);

  auto end = chrono::steady_clock::now();

  cout << "Elapsed time in milli: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  if(res){
    cout << pos << endl;
  }else{
    cout << "no" << endl;
  }

  return 0;
}
