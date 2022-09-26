#include <iostream>
using namespace std;

template <typename Temp>

class List {
    Temp *arr;
    int size;
public:
    List(int s){
        arr = new Temp[s];
        size=s;
    }
    
    void input(){
        Temp b;
        for(int j=0; j<size; j++){
            cin >> b;
            arr[j]=b;
        }
    }
    int linearSearch(Temp a){
        for(int i=0; i<size; i++){
            if(arr[i]==a)
                return i;
        }
        return -1;
    }
};

int main(){
    int n;
    cout << "Enter number of elements in list: ";
    cin >> n;
    List <char> mylist(n);
    cout << "Enter elements of list: ";
    mylist.input();
    char c;
    cout << "Enter element to be searched: ";
    cin >> c;
    cout << "Performing linear search: " << endl;
    int d=mylist.linearSearch(c);
    if(d==-1)
        cout << c << " not found in list" << endl;
    else
        cout << c << " found at index " << d << endl;
    return 0;
}
