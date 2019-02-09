#include <vector>
#include <iostream>
#include <algorithm>

template <class T>
void printArray(T &A){
  for(auto c: A){
    std::cout<<c<<" ";
  }
  std::cout<<"\n";
}

template <class T>
int partitionLomuto(T &A, int lo, int high){
  auto pivot = A[high];
  int i = lo;
  for (int j = lo; j<high;j++){
    if(A[j]<pivot){
      std::swap(A[i],A[j]);
      i++;
    }
  }
  std::swap(A[i],A[high]);
  return i;
}

template <class T>
void quicksortLomuto(T& A, int lo, int high){
    if(lo<high){
      int p = partitionLomuto(A, lo, high);
      quicksortLomuto(A, lo, p-1);
      quicksortLomuto(A, p+1, high);
    }
}
template <class T>
int partitionHoare(T &A, int lo, int high){
  auto pivot = A[(high-lo)/2];
  int i = lo;
  int j = high;
  while (i<j){
    while(A[i]<pivot) i++;
    while(A[j]>pivot) j--;
    std::swap(A[i],A[j]);
  }
  return j;

}

template <class T>
void quicksortHoare(T& A, int lo, int high){
    if(lo<high){
      int p = partitionLomuto(A, lo, high);
      quicksortHoare(A, lo, p-1);
      quicksortHoare(A, p+1, high);
    }
}


int main(){
  std::vector<double> v = {1,54,3,45.4,-1,-44,-5,42,10,0,-2};
  std::vector<double> c(v);
  std::vector<double> d= {1,54,3,8,45.4,-14,-44,-5,42,11,0,-2};
  quicksortLomuto(v,0,v.size()-1);
  std::sort(c.begin(),c.end());
  quicksortHoare(d,0,d.size()-1);

  printArray(v);
  printArray(c);
  printArray(d);

}
