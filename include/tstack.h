// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    T *stack;
    int top;
  public:
    TStack() {
        stack = new T[size];
        top = -1;
    }
    ~TStack() {
        delete [] stack;
    }
    void push(T data) {
        stack[++top] = data;
    }
    T pop() {
        return stack[top--];
    }
    T peek() {
        return stack[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
