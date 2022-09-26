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
    int binarySearch(Temp a){
        int low = 0;
        int high = size-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(a==arr[mid])
                return mid;
            else if (mid <= a)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};

int main(){
    int n;
    cout << "Enter number of elements in list: ";
    cin >> n;
    List <int> mylist(n);
    cout << "Enter elements of sorted list: ";
    mylist.input();
    int c;
    cout << "Enter element to be searched: ";
    cin >> c;
    cout << "Performing binary search: " << endl;
    int d=mylist.binarySearch(c);
    if(d==-1)
        cout << c << " not found in list" << endl;
    else
        cout << c << " found at index " << d << endl;
    return 0;
}
