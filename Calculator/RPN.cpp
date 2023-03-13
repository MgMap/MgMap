//
// Created by minau on 2/15/2023.
//

#include "RPN.h"

int RPN::basicOperation(const char &sign, const int &num1, const int &num2)
{
    switch(sign) {
        case '+': return (num1 + num2);
        case '-': return (num1 - num2);
        case '*': return (num1 * num2);
        case '/': return (num1 / num2);
        case '^': return (pow(num1, num2));
        default: return 0;
    }
}

bool RPN::isOperator(const char &element)
{
    if((element >= 40 && element <= 47) || element == 94)
    {
        return true;
    }
    return false;
}

bool RPN::isHigherPresidence(const char &element, const char& previousElement)
{
    bool temp = false;
    if(element == '-')
    {
        temp = true;
    }
    if(element == '+'&& previousElement == '-')
    {
        temp = true;
    }
    if(element == '/' && (previousElement == '-' || previousElement=='+'))
    {
        temp = true;
    }
    if(element == '*' && (previousElement == '-' || previousElement=='+'|| previousElement =='/'))
    {
        temp = true;
    }
    if(element == '^' && (previousElement == '*' || previousElement == '-' || previousElement=='+'|| previousElement =='/'))
    {
        temp = true;
    }
        return temp;
}


int RPN::pow(const int &base, const int &exponent)
{
    int result = base;
    for(int i=0; i<exponent-1; ++i) {
        result *= base;
    }
    return result;
}

std::string RPN::infixToPostfix(const std::string &infix)
{
    std::stack<char> s;
    std::queue<char> q;
    std::string postfix;

    for(int i = 0; i <= infix.size(); ++i)
    {
        if(infix[i] == '(')
            s.push(infix[i]);
        else if(isOperator(infix[i]))
        {
            //check presidence
            if(!s.empty())
            {
                while (!isHigherPresidence(infix[i], s.top())) {
                    char temp = s.top();
                    s.pop();
                    q.push(temp);
                }
            }
            s.push(infix[i]);
        }
        else if(infix[i] ==')')
        {
            while(s.top() != '(')
            {
                char temp = s.top();
                s.pop();
                q.push(temp);
            }
            if(s.top()== '(')
                s.pop();
        }
        else if (infix[i] >= 48 && infix[i] <= 57)
        {
            q.push(infix[i]);
        }
    }

    while(!s.empty())
    {
        //std::cout << s.top() <<std::endl;
        q.push(s.top());
        s.pop();
    }
    //std::cout << q.front() <<std::endl;

    while(!q.empty())
    {
        postfix += q.front();
        q.pop();
    }
    //std::cout << 21;
    return postfix;
}

int RPN::readPostfix(const std::string &postfix)
{
    std::stack<int> element;
    int rhs, lhs, result;
    for(char i : postfix)
    {
        //if it's a number, push to stack
        if(!isOperator(i))
        {
            //convert to int and push to stack
            element.push(int(i)-48);
        }
        else
        {
            //pop stack and place to the right of the operator
            rhs = element.top();
            element.pop();
            //pop stack and place to the left of the operator
            lhs = element.top();
            element.pop();
            //evaluate those numbers and push the result to the stack
            result = basicOperation(i, lhs, rhs);
            element.push(result);
        }
    }
    //after the loop is done, the answer will be on top of the stack
    return element.top();
}

void RPN::testRPN()
{
    int ans = RPN::readPostfix("4572+-*");
    std::cout << ans << std::endl;

    int ans2 = RPN::readPostfix("34+5*");
    std::cout << ans2 << std::endl;

    int ans3 = RPN::readPostfix("345*+");
    std::cout << ans3 << std::endl;

    std::string test = RPN::infixToPostfix("(3+4)*5");
    std::cout << test;
}
