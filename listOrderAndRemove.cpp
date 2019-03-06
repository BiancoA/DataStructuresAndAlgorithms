#include <iostream>
class Node{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int Value){
      value = Value;
      prev = nullptr;
      next = nullptr;
    }
    Node& operator=(const Node& nodeptr){
      value = nodeptr.value;
      prev = nodeptr.prev;
      next = nodeptr.next;
      return *this;
    }
};

class List{
    public:
      List(int value){
        root = new Node(value);
      }
      void Add(int value){
        Node* last = root;
        while(last->next!=nullptr){
          last=last->next;
        }
        last->next = new Node(value);
        last->next->prev = last;
      }
      void Remove(int value){
        Node* last = root;
        if(last->value == value){
          root = last->next;
          return;
        }
        
        while(last->value!=value){
          last=last->next;
        }
        Node* tmp = last;
        last->prev->next = tmp->next;
        if(tmp->next != nullptr)
          last->next->prev = tmp->prev;
      }
      void Print(){
        Node* last = root;
        std::cout<<"("<<last->value<<") -> (";
        while(last->next!=nullptr){
          last=last->next;
          std::cout<<last->value<<") -> (";
        }
        std::cout<<"null )\n";
      }

    private:
      Node* root;

};

int main(){
  List l(10);
  l.Print();
  l.Add(1);
  l.Print();
  l.Add(4);l.Add(5);l.Add(9);l.Add(2);l.Add(0);
  l.Print();
  l.Remove(4);
  l.Print();
  l.Remove(0);
  l.Print();
  l.Remove(10);
  l.Print();


}
