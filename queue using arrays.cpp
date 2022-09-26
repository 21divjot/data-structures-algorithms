#include <iostream>
#define max 5
#define garbage -1000
#define success 2124
using namespace std;

class Queue{
private:
    int arr[max];
    int front=-1; //deletion occurs from front-most index
    int back=-1; //insertion occurs from back-most index
    
public:
    
    bool isEmpty(){
        return front==back;
    }
    
    bool isFull(){
        return back==max-1;
    }
    
    int enqueue(int n){
        if (isFull())
            return garbage;
        else{
            arr[++back]=n;
            return success;
        }
    }
    
    int dequeue(){
        if (isEmpty())
            return garbage;
        else
            return arr[++front];
    }
    
    void display(){
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else{
            for(int i=front+1; i<=back; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Queue q;
    cout << "----------------MENU----------------" << endl;
    cout << "1. Enter element in queue" << endl;
    cout << "2. Remove element from queue" << endl;
    cout << "3. Check whether queue is empty" << endl;
    cout << "4. Check whether queue is full" << endl;
    cout << "5. Display queue" << endl;
    cout << "6. Exit program" << endl;
    int choice;
    int i,j;
    
    do{
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "Enter element to be entered in queue: " << endl;
                cin >> i;
                if(q.enqueue(i)==success)
                    cout << i << " entered successfully" << endl;
                else
                    cout << "Couldn't enter element as queue is full" << endl;
                break;
                
            case 2:
                j=q.dequeue();
                if(j==garbage)
                    cout << "No element present in queue" << endl;
                else
                    cout << j << " removed successfully" << endl;
                break;
            
            case 3:
                if(q.isEmpty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue isn't empty" << endl;
                break;
                
            case 4:
                if(q.isFull())
                    cout << "Queue is full" << endl;
                else
                    cout << "Queue isn't full" << endl;
                break;
            
            case 5:
                q.display();
                break;
        }
    } while(choice>=1 && choice<=5);
    
    return 0;
}
