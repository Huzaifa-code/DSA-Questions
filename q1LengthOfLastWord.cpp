// 

//     To Compile your C++ code use:-

//     g++ file_name.cpp -o executable_file_name

//          (i) -o option is used to show error in the code 
//          (ii) if there is no error in the code_file, then it will generate an executable file.

//     Now execute the generated executable file:

//     ./executable_file_name

 

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