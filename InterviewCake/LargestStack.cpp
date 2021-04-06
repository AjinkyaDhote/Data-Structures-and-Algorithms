#include<iostream>
#include<stack>

using namespace std;


class MaxStack
{
private:

    stack<int> stack_;
    stack<int> maxesStack;
    

public:


    void push( int val )
    {
        stack_.push(val);
        if (maxesStack.empty() || val >= maxesStack.top())
            maxesStack.push(val);

    }

    int pop()
    {
        int item = stack_.top();
        stack_.pop();

        if (item == maxesStack.top())
            maxesStack.pop();

        return item;
    }


    int getMax()
    {
        return maxesStack.top();
    }
};