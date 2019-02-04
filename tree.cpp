#include <iostream>

struct Node
{
        Node(double value):
        left(nullptr),
        right(nullptr),
        nodeValue(value)
        {
         std::cout<<"node value: "<<nodeValue<<"\n";
        };
        friend std::ostream& operator << (std::ostream& os, Node* node){
            os<<"("<<node->nodeValue<<"("<<node->left->nodeValue<<"("<<node->right->nodeValue<<"))";
            return os;
        };

        Node *left;
        Node *right;
        double nodeValue;
};

class BinaryTree
{
  public:
        BinaryTree(double Value):
        originalRoot(nullptr){
          originalRoot = InternalAdd(originalRoot, Value);
        };

        void Add(double Value){
          InternalAdd(originalRoot, Value);
        }

        void Search(double Value){
          InternalSearch(originalRoot, Value);
        }

      private:
        bool InternalSearch(Node* root, double Value){
            if(root->nodeValue == Value){
                std::cout<<"found! at node "<< root<<"\n";
                return true;
            }else if(root->nodeValue < Value){
                return InternalSearch(root->left, Value);
            }else if(root->nodeValue > Value){
                return InternalSearch(root->right, Value);
            }else{
              std::cout<<"Not found"<<"\n";
              return false;
            }
        }

        Node* InternalAdd(Node* root, double Value){
            //we found a leaf
            if(root==nullptr){
                root = new Node(Value);
            }else if(root->nodeValue < Value){
                root->left = InternalAdd(root->left, Value);
            }else if(root->nodeValue > Value){
                root->right = InternalAdd(root->right, Value);
            }
            return root;
        }

        Node *originalRoot;

};

int main(){
    BinaryTree tree(19.1);

    tree.Add(10);
    tree.Add(1.0);
    tree.Add(42);
    tree.Add(12.9);
    tree.Add(89.999);
    tree.Add(32.0);

    tree.Search(42);
}
