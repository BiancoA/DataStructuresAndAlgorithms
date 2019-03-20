#include<vector>
#include<iostream>

template<typename T>
size_t binary_search(const std::vector<T> &v, T item, size_t first, size_t last){
  size_t middle = (first+last)/2;
  //std::cout<<middle<<"\n";
  if(v.at(middle)==item){
    return middle;
  }else if(v.at(middle)>item){
    return binary_search(v, item, first, middle-1);
  }else{
    return binary_search(v, item, middle+1, last);
  }
}

template<typename T>
size_t binary_iterative(const std::vector<T> &v, T item, size_t first, size_t last){
  size_t middle = 0;
  while(first<=last){
    middle = (first+last)/2;
    if(v[middle]==item){
      return middle;
    }else if(v[middle]>item){
      last = middle -1;
    }else{
      first=middle+1;
    }
  }
  return -1;
}

int main(){
  std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
  for(int i=0; i<v.size();i++){
    std::cout<< binary_search(v,v.at(i),0, v.size()-1)<<"\n";
    std::cout<< binary_iterative(v,v.at(i),0, v.size()-1)<<"\n";
  }




}
