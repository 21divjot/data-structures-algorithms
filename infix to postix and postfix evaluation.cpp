#include <iostream>
using namespace std;
template <typename Temp>

class Stack{
    Temp *S;
    int top=-1;
    int size;
public:
    Stack(int s){
        size=s;
        S=new Temp[size];
    }
    bool isEmpty(){
        return top==-1;
    }
    
    bool isFull(){
        return top==size-1;
    }
    
    void push(Temp x){
        if (isFull()){
            cout << "Stack overflow" << endl;
            return;
        }
        S[++top] = x;
    }
    
    Temp pop(){
        return S[top--];
    }
    
    Temp topEl(){
        return S[top];
    }
};

bool isOperator(char c){
    return(c=='+' || c=='-' || c=='/' || c=='*');
}

bool precedenceCheck(char a, char b){
    //precedence of a is higher or equal to b
    if(a=='/' && ( b == '/' ||  b=='*' || b=='+' || b=='-'))
        return true;
    else if(a=='*' && (b == '/' || b=='*' || b=='+' || b=='-'))
        return true;
    else if(a=='+' && (b=='+' || b=='-'))
        return true;
    else if(a=='-' && (b=='+' || b=='-'))
        return true;
    else
        return false;
}

string infixToPostfix(string infix){
    string postfix="";
    int n = infix.size();
    Stack <char> mystack(n);
    
    for(int i=0; i<n; i++){
        // case of operand
        if(!isOperator(infix[i]))
            postfix+=infix[i];
        // case : infix[i] is an operator
        else{
            while(!mystack.isEmpty() && precedenceCheck(mystack.topEl(), infix[i])){
                postfix+=mystack.pop();
            }
            mystack.push(infix[i]);
        }
    }
    while(!mystack.isEmpty()){
        postfix+=mystack.pop();
    }
    return postfix;
}

int evaluation(int a, int b, char c){
    if(c=='*')
        return a*b;
    else if(c=='/')
        return a/b;
    else if(c=='+')
        return a+b;
    else if(c=='-')
        return a-b;
    else
        return 0;
}

int postfixEvaluation(string postfix){
    int n = postfix.size();
    Stack <int> mystack(n);
    
    for(int i=0; i<n; i++){
        if(!isOperator(postfix[i]))
            mystack.push(postfix[i]-'0');
        else{
            int m = mystack.pop();
            int n = mystack.pop();
            int a=evaluation(n, m, postfix[i]);
            mystack.push(a);
        }
    }
    return mystack.topEl();
}

int main(){
    string s;
    cout << "Enter the infix expression: ";
    cin >> s;
    string pf=infixToPostfix(s);
    cout << "Postfix expression of " << s << " is " << pf << endl;
    int a=postfixEvaluation(pf);
    cout << "Postfix evaluation of " << pf << " is " << a << endl;
    return 0;
}
