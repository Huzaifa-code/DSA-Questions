// P15. Given an expression string S, write a program to examine whether the pairs
// and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

// Example:
// Input: S = “[()]{}{[()()]()}”
// Output: Balanced
// Explanation: all the brackets are well-formed
// Input: S = “[(])”
// Output: Not Balanced
// Explanation: 1 and 4 brackets are not balanced because there is a closing ‘]’ before the
// closing ‘(‘



#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string ex){
    stack<char> s;

    for(int i = 0; i<ex.length(); i++){
        char ch = ex[i];

        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch); //Pushing(adding) opening brackets to the stack s
        }else{
            // runs for closing brackets. i.e. when ch has a closing bracket

            if(!s.empty()){

                char top = s.top();   //last bracket pushed to stack i.e. on top
                if( (ch==')' && top=='(' ) || ( ch=='}' && top=='{' ) || ( ch==']' && top=='[' )){
                    s.pop();
                }else{
                    return false;
                }

            }else{ //if stack s is empty i.e. no opening brackets --> return false
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

int main(){

    string str = "[{()}]";
    bool x = isValidParenthesis(str);
    if( x == true ){
        cout<<"Balanced \n";
    }else{
        cout<<"Unbalanced \n";
    }

    return 0;
}