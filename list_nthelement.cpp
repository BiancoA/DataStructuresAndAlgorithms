// write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

void partition_list(std::list<int>& list, int value){
  auto endIt = list.end();
  for(auto it = list.begin(); it!= endIt; it++){
    std::cout<<*it<<" ";
      if(*it<value){
        list.push_front(*it);
        list.erase(it);
      }else{
        list.push_back(*it);
        list.erase(it);
      }
  }
}

int main(){
  std::list<int> list = {1,4,6,8,9,3,1,0};
  for(auto& l: list){
    std::cout<<l<<"\n";
  }

  partition_list(list,8);
  for(auto& l: list){
    std::cout<<l<<"\n";
  }
}
