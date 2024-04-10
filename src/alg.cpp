// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    std::string post;
    TStack<char, 100> stack;
    for (char &c : inf) {
        if (c >= '0' && c <= '9') {
            post += c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.isEmpty() && 
                ((stack.peek() == '*' || stack.peek() == '/') && 
                (c == '+' || c == '-'))) {
                post += stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.isEmpty()) {
        post += stack.pop();
    }
    return post;
}

int eval(std::string post) {
TStack<int, 100> stack;
    for (char &c : post) {
        if (c >= '0' && c <= '9') {
            stack.push(c - '0');
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            if (c == '+') {
                stack.push(operand1 + operand2);
            } else if (c == '-') {
                stack.push(operand1 - operand2);
            } else if (c == '*') {
                stack.push(operand1 * operand2);
            } else if (c == '/') {
                stack.push(operand1 / operand2);
            }
        }
    }
    return stack.pop();
}
