#include <iostream>
using namespace std;

#define max 10

class Stack{
    int S[max];
    int top=-1;
public:
    
    bool isEmpty(){
        if(top==-1)
            return true;
        
        else
            return false;
    }
    
    bool isFull(){
        if(top==max-1)
            return true;
        else
            return false;
    }
    
    int push(int x){
        if (!isFull()){
            top++;
            S[top]=x;
            return 0;
        }
        else
            return -1;
    }
    
    int pop(){
        if (!isEmpty()){
            top--;
            return 0;
        }
        else
            return -1;
    }
    
    int topEl(){
        if (!isEmpty())
            return S[top];
        else
            return -1;
    }
    
    void display(){
        cout << "Elements of the stack are: ";
        if(!isEmpty()){
            for(int i=top; i>=0; i--){
                cout << S[i] << ", ";
            }
            cout << endl;
        }
        else
            cout << "Stack is empty" << endl;
    }
};

int main(){
    cout << "---------------MENU---------------" << endl;
    cout << "1. Push element" << endl;
    cout << "2. Pop element" << endl;
    cout << "3. Top element" << endl;
    cout << "4. Is stack empty?" << endl;
    cout << "5. Is stack full?" << endl;
    cout << "6. Display stack" << endl;
    Stack stk;
    int choice;
    bool a=true;
    while(a){
        cout << "Enter your choice: " << endl;
        cin >> choice;
        
        if(choice==1){
            int e;
            cout << "Enter element to be pushed: ";
            cin >> e;
            if(stk.push(e)==0)
                cout << "Element pushed successfully" << endl;
            else
                cout << "Stack overflow" << endl;
        }
        
        else if(choice==2){
            if (stk.pop()==-1)
                cout << "Stack underflow" << endl;
            else
                cout << "Element popped successfully" << endl;
        }
        
        else if(choice==3){
            int tp=stk.topEl();
            if(tp==-1)
                cout << "Stack is empty" << endl;
            else
                cout << "Topmost element: " << tp << endl;
        }
        
        else if(choice==4){
            if(stk.isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
        }
        
        else if(choice==5){
            if(stk.isFull())
                cout << "Stack is full" << endl;
            else
                cout << "Stack is not full" << endl;
        }
        
        else if(choice==6){
            stk.display();
        }
        
        else{
            cout << "Program ended" << endl;
            a=false;
        }
        
    }
    
    return 0;
}
