class Node{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value){
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

      }

    private:
      Node* root;

};

int main(){
  
}
