#include <stack>
#include <iostream>

std::stack<int> sortStack(std::stack<int>& inS){
  std::stack<int> tmpS;
  int tmpV=0;
  tmpS.push(inS.top());
  inS.pop();

  while(!inS.empty()){
    if(inS.top()>=tmpS.top()){
      tmpS.push(inS.top());
      inS.pop();
    }else{
      tmpV = inS.top();
      inS.pop();
      int count = 0;

      //reverse the stack until we find the item that is smaller
      while(!tmpS.empty()){
        if(tmpS.top()>tmpV){
          inS.push(tmpS.top());
          tmpS.pop();
          count++;
        }else{
          break;
        }
      }
      //tmpS.top is smaller (or =) than tmpV
      tmpS.push(tmpV);

      //and revert the other stack
      for(int i=0; i< count; i++){
        tmpS.push(inS.top());
        inS.pop();
      }
    }
  }

  return tmpS;
}

int main(){

  std::stack<int> s({1,0,123,3,5,89,23});

  std::stack<int> ordered = sortStack(s);

  while(!ordered.empty()){
  std::cout<<ordered.top()<< " ";
  ordered.pop();
  }
  std::cout<<"\n";
}

/*
9,3,2
5,1
3
*/
