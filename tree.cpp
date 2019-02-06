#include <iostream>
#include <vector>
#include <iterator>

struct Node
{
        Node(double value) :
                left(nullptr),
                right(nullptr),
                nodeValue(value)
        {
                //std::cout<<"node value: "<<nodeValue<<"\n";
        };
        friend std::ostream& operator << (std::ostream& os, Node* node){
                if(node->left == nullptr && node->right == nullptr) {
                        os<<"("<<node->nodeValue<<"("<<"..."<<"("<<"..."<<"))";
                }else if (node->left == nullptr) {
                        os<<"("<<node->nodeValue<<"("<<"..."<<"("<<node->right->nodeValue<<"))";
                }else if (node->right == nullptr) {
                        os<<"("<<node->nodeValue<<"("<<node->left->nodeValue<<"("<<"..."<<"))";
                }else{
                      os<<"("<<node->nodeValue<<"("<<node->left->nodeValue<<"("<<node->right->nodeValue<<"))";
                }
                return os;

        };

        Node *left;
        Node *right;
        double nodeValue;
};

class BinaryTree
{
public:
BinaryTree(double Value) :
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
        if(root==nullptr) {
                std::cout<<"Not found"<<"\n";
                return false;
        }else if(root->nodeValue == Value) {
                std::cout<<"found! at node "<< root<<"\n";
                return true;
        }else if(root->nodeValue < Value) {
                return InternalSearch(root->left, Value);
        }else if(root->nodeValue > Value) {
                return InternalSearch(root->right, Value);
        }
        return false;
}

Node* InternalAdd(Node*& root, double Value){
        //we found a leaf
        if(root==nullptr) {
                root = new Node(Value);
        }else if(root->nodeValue < Value) {
                root->left = InternalAdd(root->left, Value);
        }else if(root->nodeValue > Value) {
                root->right = InternalAdd(root->right, Value);
        }
        return root;
}

Node *originalRoot;

};

int main(){
        std::vector<double> v = {1,42,32.01,123.3,45.5,12,34,342.01,13.3,455.5,-12,8};
        BinaryTree tree(19.1);

        for(std::vector<double>::iterator it=v.begin(); it<v.end(); it++) {
                tree.Add(*it);
        }
        tree.Search(42);
        tree.Search(8);
        tree.Search(19.1);
        tree.Search(12);
        tree.Search(1);

}
