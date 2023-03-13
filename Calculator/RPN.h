//
// Created by minau on 2/15/2023.
//

#ifndef SFML_PROJECT_RPN_H
#define SFML_PROJECT_RPN_H
#include <string>
#include <stack>
#include <queue>
#include <iostream>

class RPN {
private:
    static int basicOperation(const char& sign, const int& num1, const int& num2);
    static bool isOperator(const char& element);
    static bool isHigherPresidence(const char& element, const char& previousElement);
    //power function for integers
    static int pow(const int& base, const int& exponent);
public:
    //shunting yard - convert an infix expression to a postfix expression
    static std::string infixToPostfix(const std::string& infix);
    //reverse polish notation - read postfix expression
    static int readPostfix(const std::string& postfix);

    static void testRPN();
};


#endif //SFML_PROJECT_RPN_H
