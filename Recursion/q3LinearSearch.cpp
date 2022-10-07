// Linear search using recursion 

#include<iostream>
using namespace std;

bool linearSearch(int a[], int size, int key){

    // Base Case
    if(size == 0){
        return false;
    }

    if(a[0] == key){
        return true;
    }else {
        return linearSearch(a+1, size-1, key);
    }

}

int main(){

    int a[5]= {2,9,4,1,5};
    int key = 0;

    bool ans = linearSearch(a, 5, key);

    if(ans){
        cout<<"Present"<<endl;
    }else {
        cout<<"Absent"<<endl;
    }

    return 0;
}