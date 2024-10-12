// The approach to solve this problem is:
// Use two stacks in the same time
// First is the entire stack
// 2nd is a stack with the sorted values where top is the minimum value.

#include <vector>

using namespace std;
class MinStack {
public:
    vector<int> stack;
    vector<int> min;

    MinStack() {
    }

    void push(int val) {
        if (min.empty() || val <= min.back()) {
            min.push_back(val);
        }
        stack.push_back(val);
    }

    void pop() {
        if (stack.empty()) {
            return;
        }
        if (stack.back() == min.back()) {
            min.pop_back();
        }
        stack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min.back();
    }
};

int main(){



    return 0;
}



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
