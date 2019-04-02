#include <set>
#include <unordered_map>
#include <string>
#include <iostream>

int main(){
  std::unordered_multimap<int, std::wstring> agenda;

  agenda.insert(std::make_pair(48, L"Pino Pini"));
  agenda.insert({50, L"Pina Pini"});
  agenda.insert({3, L"Pinino Pini"});
  agenda.insert({3, L"Pinino Pini"});
  agenda.insert({3, L"Pininu Pini"});
  agenda.insert({3, L"Pinina Pini"});


  std::set<int> bst;
  for(auto& e: agenda){
    bst.insert(e.first);
  }
  for(std::set<int>::iterator it = bst.begin(); it!=bst.end(); it++){
    std::cout<< *it<<" ";
  }
  std::cout<<"\n";

  for(auto it = bst.begin(); it!=bst.end(); it++){
    std::cout<< *it<<" ";
  }
  std::cout<<"\n";
  auto results=agenda.find(3);
  for( auto i = 0; i< agenda.count(3); i++){
        std::wcout<<results->second<<"\n";
        results++;
      }
}
