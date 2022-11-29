//? Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards
//? in your hands. The array is virtually split into a sorted and an unsorted part. 
//? Values from the unsorted part are picked and placed at the correct position in the sorted part.


#include<iostream>
using namespace std;

int main(){
    
    int arr[20];
    int i, j,n;

    cout<<"\nEnter size of array :";
    cin>>n;


    for(int i=0; i<n; i++){
        cout<<"\nEnter data : ";
        cin>>arr[i];
    }

    for(i=1; i<n ; i++){
        int temp = arr[i];

        for(j=i-1; j>=0; j--){
            if(arr[j] > temp){
                //shift
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }

        arr[j+1] = temp;

    }


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}