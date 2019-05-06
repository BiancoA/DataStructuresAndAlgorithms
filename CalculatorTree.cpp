#include <iostream>
#include <exception>

// compiled with g++ --std=c++11 CalculatorTree.cpp -o a.out
// this version is stil prototypal, it lacks a lot of features: smart pointers,
// better tought constructors, logic to handle the return value if the operation
// is between two different types, and I guess many other things.


//Virtual class of node
template <typename T>
class MetaNode {
  public:
    virtual T value() = 0;  // Return the value of this node.
};

//Node containing a number (int or double in our case)
template <typename T>
class NumberNode : public MetaNode<T> {

  private:
    T n;  // The value of the node

  public:

    NumberNode(T val ): n(val) {
    }

    //returns the value of this node
    T value() {
       return n;
    }

 };

// Node containgin an operator (binary)
// supported operator are + and -, but further can be added.
// for semplicity I save the operator as a character, but if more complex
// beahviour is needed it is worth to create a separate class(es)
template <typename T, typename K>
 class OperatorNode : public MetaNode<T> {

    char oper; //operator, + or * storede as a char
    MetaNode<T> *left; //Node on the left
    MetaNode<K> *right; //node on the right

  public:

    /* constructor
    \param char, Operator
    \param leftNode, node on the left (type int or double)
    \param rightNode, node on the left (type int or double)
    */

    OperatorNode( char oper, MetaNode<T> *left, MetaNode<K> *right ) {
       this->oper = oper;
       this->left = left;
       this->right = right;
    }

    /* Value function, returns the result of the operation
    returns the value of the first typename in the <typename, typename>
    declaration.
    */
    T value() {

        T leftVal = left->value();
        K rightVal = right->value();
        switch ( oper ) {
            case '*':  return leftVal * rightVal;
            case '+':  return leftVal + rightVal;
            default: throw std::runtime_error("Unsupported operand");;
         }
    }

 };

 int main(){
   /* building first tree:
        *
      /   \
     5     +
          /  \
        2     7

  */

   OperatorNode<int, int>* firstLevel = new OperatorNode<int, int>('+',
                                              new NumberNode<int>(2),
                                              new NumberNode<int>(7));
   OperatorNode<int, int>* tree = new OperatorNode<int, int>('*',
                                              new NumberNode<int>(5),
                                        firstLevel);

   int tmpFirstTreeValue = tree->value();
   if(tmpFirstTreeValue == 45){
        std::cout<<"the value of the first three is correct: "<<
                    tmpFirstTreeValue<<"\n";
    }else{
        std::cout<<"the value of the first three is WRONG: "<<
                    tmpFirstTreeValue<<"\n";
    }

   /* building second tree:
        *
      /   \
  2,5      +
          /  \
        10   31

  */

   OperatorNode<int, int>* firstLevel2 = new OperatorNode<int, int>('+',
                                              new NumberNode<int>(31),
                                              new NumberNode<int>(10));
   OperatorNode<double, int>* tree2 = new OperatorNode<double, int>('*',
                                        new NumberNode<double>(2.5),
                                      firstLevel2);


    double tmpSecondTreeValue = tree2->value();
    if(tmpSecondTreeValue == 102.5){
            std::cout<<"the value of the first three is correct: "<<
                        tmpSecondTreeValue<<"\n";
    }else{
            std::cout<<"the value of the first three is WRONG: "<<
                        tmpSecondTreeValue<<"\n";
    }
 }
