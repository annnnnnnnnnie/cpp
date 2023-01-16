#include <stack>
#include <algorithm>
#include <cassert>

class MinStack {
private:
  std::stack<int> stack;
  std::stack<int> mins;
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    stack.push(x);
    if(mins.empty()){
      mins.push(x);
    }else{
      mins.push(std::min(mins.top(), x));
    }
  }

  void pop() {
    auto i = stack.top();
    stack.pop();
    mins.pop();
  }

  int top() {
    return stack.top();
  }

  int min() {
    assert(!mins.empty());
    return mins.top();
  }
};