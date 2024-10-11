
//To implement a stack there are 4 main operations: Insert, Pop, Peek/Top, Empty and Size.
//Is easly implemented using a vector.

#include <stdexcept>
#include <vector>
// Function template
using namespace std;
template <typename T>

class Stack{
    public:
    vector<T> stack;

    void insert(T n){
        stack.push_back(n);
    }

    T pop() {
        if (!isEmpty()) {
            T val = stack.back();
            stack.pop_back();
            return val;
        }
        throw out_of_range("Stack is empty"); 
    }

    bool isEmpty(){
        return stack.empty();
    }

    int stackSize(){
        return stack.size();
    }

    T peek(){
        if (!isEmpty()) {
            return stack.back();
        }
        throw out_of_range("Stack is empty");
    }

};