#include <memory>

template <typedef T>
struct tNode{
    tNode(T fValue):value(fValue){};
    T value;
    std::unique_ptr next;
    std::unique_ptr prev;
}

template <typedef T>
class tQueue{
    tQueue(T fValue): first(new tNode(fValue)), last(nullptr);

    void Add(T Value){
        Node* tmpLast = last.release();
        last.reset(new tNode(Value));
        last->prev.reset(tmpLast);
    }
    T Get(){
        T tmpFirst = first->value;
        first->swap(first->;


        return tmp; 
    }
    std::unique_ptr first;
    std::unique_ptr last;
}
