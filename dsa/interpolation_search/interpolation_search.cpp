#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

bool bin_search(const vector<int> &data, const int target, int &pos){

  int size = data.size();

  cout << "size: " << size << endl;
  int mid = size / 2;
  int low = 0;
  int high = size - 1;
  int comp = 0;
  
  while(data[mid] != target){
    comp++;
    if(low == high){
      cout << "comp: " << comp << endl;
      return false;
    }
    if(target > data[mid]){
      low = mid + 1;
      mid = (low + high) / 2;
    }else{
      high = mid - 1;
      mid = (low + high) / 2;
    }
  }
  cout << "comp: " << comp << endl;
  pos = mid;
  return true;
}

// bool inter_search(const vector<int> &data, const int target, int &pos){
//   int size = data.size();
//   cout << "size: " << size << endl;
//   int low = 0;
//   int mid = -1;
//   int high = size - 1;
//   int comp = 0;
//   // cout << "size: " << size << endl;
//   // cout << "mid: " << mid << endl;
//   // cout << "high: " << high << endl;
//   // cout << "low: " << low << endl;
//   // cout << "target: " << target << endl;
  
//   if(data[mid] == target){
//     pos = mid;
//     return true;
//   }

//   while(low <= high){
//     if(low == high || data[low] == data[high]){
//           cout << "comp: " << comp << endl;
//       return false;
//     }

//     comp++;
//     //mid = low + (((double)((high - low) / (data[high] - data[low]) * (target - data[low])));
//     mid = low + ((target - data[low]) * (high - low) / (data[high] - data[low]));
//     cout << "update mid: " << mid << endl;
    
//     if(data[mid] == target){
//       pos = mid;
//       cout << "comp: " << comp << endl;
//       return true;
//     }else{
//       if(data[mid] < target){
// 	low = mid + 1;
//       }else if(data[mid] > target){
// 	high = mid - 1;
//       }
//     }

//     // cout << "update mid: " << mid << endl;
//     // cout << "update low: " << low << endl;
//     // cout << "update high: " << high << endl;
//   }
//     cout << "comp: " << comp << endl;
//   return false;
// }

bool inter_search(const vector<int> &data, const int target, int &pos){
  int size = data.size();
  int low = 0, high = size - 1, mid;

  while(data[high] != data[low] && target >= data[low] && target <= data[high]){
    mid = low + ((target - data[low]) * (high - low) / (data[high] - data[low]));
    
    if (target == data[mid]){
      pos = mid;
      return true;
    }else if(target < data[mid]){
      high = mid - 1;
    }else{
      low = mid + 1;
    }
    
  }
  
  if(target == data[low]){
    pos = low;
    return true;
  }else{
    return false;
  }
    
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
  int target = 377;
  bool res;

  auto start = chrono::steady_clock::now();
  res = inter_search(data, target, pos);
  auto end = chrono::steady_clock::now();
  cout << "Inter: Elapsed time : " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  if(res){
    cout << "pos: " << pos << endl;
  }else{
    cout << "no" << endl;
  }

  pos = -1;
  start = chrono::steady_clock::now();
  res = bin_search(data, target, pos);
  end = chrono::steady_clock::now();
  cout << "Binary: Elapsed time : " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
  if(res){
    cout << "pos: " << pos << endl;
  }else{
    cout << "no" << endl;
  }


  
  return 0;
}
