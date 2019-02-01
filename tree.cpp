#include <iostream>

class Node
{
    public:
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
        BinaryTree():
        lastNode(nullptr){};

        void Add(double Value){
            if(lastNode==nullptr){
                lastNode = new Node(Value);
            }else if(lastNode->left == nullptr){
                lastNode->left = new Node(Value);
            }else if(lastNode->right == nullptr){
                lastNode->right = new Node(Value);
            }
        }
        Node *lastNode;

};

int main(){
    Node *root = new Node(19.1);
    Node *left = new Node(10.1);
    Node *right = new Node(20.3);
    root->left = left;
    root->right = right;
    std::cout<<root<<"\n";

    delete root;
    delete left;
    delete right;

}
