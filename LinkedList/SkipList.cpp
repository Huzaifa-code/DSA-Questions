// Write a complete program in C++ to implement SkipList. An example SkipList is
// illustrated in the following figure. In SkipList a next pointer is stored on each node as
// well as one additional pointer to locate the next fourth element ( if any present) in the
// list. Implement function to
// a) Insert an element at the beginning of the SkipList
// b) Traverse and display all elements of the SkipList
// c) Traverse and display SkipList using skip pointers

#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *nfourth;
};

class SkipList{

    public:
        node *first;

        SkipList(){
            first = NULL;
        }

        void addAtBeg(int d){

            node *t = new node;
            t->data = d;

            if(first == NULL){
                t->next = NULL;
                t->nfourth = NULL;

                first = t;
                return;
            }

            t->next = first;
            first = t;

            int count = 0;
            node *temp = first;
            while(temp->next != NULL && count <=4){
                temp = temp->next;
                count++;
            }
            if(count == 4){
                t->nfourth = temp;
            }else{
                t->nfourth = NULL;
            }


        }


        void display(){
            if(first == NULL){
                cout<<"List is Empty";
                return;
            }

            node *temp = first;
            while (temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            
        }
       
        void displaySkip(){
            if(first == NULL){
                cout<<"List is Empty";
                return;
            }

            node *temp = first;
            while (temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->nfourth;
            }
            
        }
};

int main(){

    SkipList s;

    s.addAtBeg(5);
    s.addAtBeg(4);
    s.addAtBeg(3);
    s.addAtBeg(2);
    s.addAtBeg(1);

    cout<<"\nList : \n";
    s.display();

    cout<<"\nSkip List : \n";
    s.displaySkip();


    return 0;
}