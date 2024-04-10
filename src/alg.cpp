// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack;
    std::string post = "";
    for (char& c : inf) {
        if (isdigit(c)) {
            post += c;
            continue;
        }
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                post += stack.pop();
            }
            stack.pop();
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && getPriority(c) <= getPriority(stack.get())) {
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
