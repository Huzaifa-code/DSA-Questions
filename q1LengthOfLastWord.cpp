#include<iostream>
using namespace std;

int main(){

    int count = 0;
    string str = "Hello world ";
    int l = str.length();

    int i = 0;
    while(i<l){

        if(str[i] != ' ' ){
            count++;
            i++;
        }else{
            while(i<n && str[i] == " "){
                i++;
            }
            count = 0;
        }
    }
    


    return 0;
}