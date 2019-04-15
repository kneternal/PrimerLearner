#include "mergesort.h"

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
