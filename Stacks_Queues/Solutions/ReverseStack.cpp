#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size() == 1){
        return;
    }

    int x = input.top();
    input.pop();

    reverseStack(input, extra);

    while(input.size() != 0){
        int helper = input.top();
        input.pop();
        extra.push(helper);
    }

    input.push(x);

    while(extra.size() != 0){
        int helper = extra.top();
        extra.pop();
        input.push(helper);
    }
}
