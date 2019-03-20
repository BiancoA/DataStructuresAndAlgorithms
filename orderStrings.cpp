#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

class compStr{
  public:
    compStr(){};
    bool operator()(const std::string& strL_in, const std::string& strR_in){
      std::string strL(strL_in);
      std::sort(strL.begin(), strL.end());
      std::string strR(strR_in);
      std::sort(strR.begin(),strR.end());
      //std::cout<<strL<<" "<<strR<<" "<<(strL < strR)<<" "<<(strL > strR)<<" "<<"\n";
      return (strL < strR);
    }
};

int main(){
  std::vector<std::string> vecStr = {"abc","edf", "as22","bca" , "asdadas", "fed"};
  for(auto &i: vecStr)
    std::cout<<i<<"\n";
  std::sort(vecStr.begin(), vecStr.end(), compStr());
  std::cout<<"\n";
  std::cout<<"ordered"<<"\n";
  std::cout<<"\n";
  for(auto &i: vecStr)
    std::cout<<i<<"\n";
  return 0;
}
