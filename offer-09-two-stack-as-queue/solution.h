#include <stack>
#include <stdexcept>
#include <utility>
template <typename T> class StackQueue {
public:
  StackQueue() {}

  ~StackQueue() = default;

  void appendTail(T &&value) { stack_in.push(std::forward<T>(value)); }

  T &deleteHead() {
    if (!stack_out.empty()) {
      auto &e = stack_out.top();
      stack_out.pop();
      return e;
    } else if (!stack_in.empty()) {
      while (!stack_in.empty()) {
        stack_out.push(stack_in.top());
        stack_in.pop();
      }
      auto &e = stack_out.top();
      stack_out.pop();
      return e;
    } else {
      throw std::runtime_error{"Calling deleteHead on empty queue"};
    }
  }

private:
  std::stack<T> stack_in;
  std::stack<T> stack_out;
};

class CQueue {
public:
  CQueue() {}

  ~CQueue() = default;

  void appendTail(int value) { stack_queue.appendTail(std::move(value)); }

  int deleteHead() {
    try {
      auto v = stack_queue.deleteHead();
      return v;
    } catch (std::runtime_error &e) {
      return -1;
    }
  }

private:
  StackQueue<int> stack_queue;
};