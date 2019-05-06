#include <stack>
#include <iostream>
#include <chrono>

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

std::stack<int> sortStackRevisited(std::stack<int>& inS){
  std::stack<int> tmpS;
  int tmpV=0;

  while(!inS.empty()){
    tmpV = inS.top();
    inS.pop();
    //reverse the stack until we find the item that is smaller
      while(!tmpS.empty() && tmpS.top()>tmpV){
          inS.push(tmpS.top());
          tmpS.pop();
      }
      tmpS.push(tmpV);
    }

  return tmpS;
}
int main(){

using namespace std::chrono;
  std::stack<int> s1({1,0,123,3,5,89,23,12,1000,5,6,7,34,16,88,96,2,16,1000000});

  std::stack<int> s({1,0,123,3,5,89,23,12,1000,5,6,7,34,16,88,96,2,16,1000000});

  auto t1 = high_resolution_clock::now() ;

  std::stack<int> ordered = sortStack(s);

  auto t2 = high_resolution_clock::now() ;

  std::stack<int> ordered2 = sortStackRevisited(s1);

  auto t3 = high_resolution_clock::now() ;

  while(!ordered.empty()){
  std::cout<<ordered.top()<< " ";
  ordered.pop();
  }
  std::cout<<"\n";

  while(!ordered2.empty()){
  std::cout<<ordered2.top()<< " ";
  ordered2.pop();
  }
  std::cout<<"\n";
  std::cout<<duration_cast<nanoseconds>(t2-t1).count()<<" "<<duration_cast<nanoseconds>(t3-t2).count()<<"\n";
}

/*
9,3,2
5,1
3
*/
