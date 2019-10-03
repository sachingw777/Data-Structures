#include <stack>
bool checkBalanced(char *exp) {
    stack<char> s;
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '['){
            s.push(exp[i]);
        }
        else if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']'){
            if(s.empty()){
                return false;
            }

            char a = s.top();
            s.pop();
            if(a == '{' && exp[i] == '}'){
                continue;
            }else if(a == '[' && exp[i] == ']'){
                continue;
            }else if(a == '(' && exp[i] == ')'){
                continue;
            }else{
                return false;
        }
    }
}

    if(s.empty()){
        return true;
    }else{
        return false;
    }
}