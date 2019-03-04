#include <string>
#include <iostream>

void reverse(char* str){
  size_t strsize = std::strlen(str);
  for(size_t i=0; i<strsize/2;i++){
    std::swap(str[i], str[strsize - 1 - i]);
  }
}
int main(){
  char str[] = "somthing here";
  std::cout<<str<<"\n";
  reverse(str);
  std::cout<<str<<"\n";
  return 1;
}
