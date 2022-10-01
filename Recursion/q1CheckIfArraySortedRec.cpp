// Check if Array is Sorted using Recursion

#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){

    // Base case 
    if(size == 1 || size == 0){
        return true;
    }

    
    if( arr[0] > arr[1] ){
        return false;
    } else{
        bool ans = isSorted(arr++, size-1);
        return ans;
    }

}

int main(){
    int arr[10] = {2,3,1,5,6,2,5,9,3,4};

    cout<<isSorted(arr, 10)<<endl;


    return 0;
}